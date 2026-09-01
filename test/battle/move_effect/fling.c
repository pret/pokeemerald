#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FLING) == EFFECT_FLING);
}

SINGLE_BATTLE_TEST("Fling fails if Pokémon holds no item")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_RAZOR_CLAW; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("Wobbuffet used Fling!");
        if (item != ITEM_NONE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("But it failed!");
        }
    }
}

SINGLE_BATTLE_TEST("Fling fails if Pokémon is under the effects of Embargo or Magic Room")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_EMBARGO; }
    PARAMETRIZE { move = MOVE_MAGIC_ROOM; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
        ASSUME(GetMoveEffect(MOVE_MAGIC_ROOM) == EFFECT_MAGIC_ROOM);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RAZOR_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("Wobbuffet used Fling!");
        if (move == MOVE_CELEBRATE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("But it failed!");
        }
    }
}

SINGLE_BATTLE_TEST("Fling fails for Pokémon with Klutz ability (Gen5+)")
{
    enum Ability ability;
    u32 config;

    PARAMETRIZE { ability = ABILITY_RUN_AWAY; config = GEN_4; }
    PARAMETRIZE { ability = ABILITY_KLUTZ;    config = GEN_4; }
    PARAMETRIZE { ability = ABILITY_KLUTZ;    config = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_KLUTZ_FLING_INTERACTION, config);
        PLAYER(SPECIES_BUNEARY) { Item(ITEM_RAZOR_CLAW); Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("Buneary used Fling!");
        if (ability != ABILITY_KLUTZ || config == GEN_4) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("But it failed!");
        }
    }
}

SINGLE_BATTLE_TEST("Fling fails if the item changes the Pokémon's form")
{
    GIVEN {
        PLAYER(SPECIES_GIRATINA_ORIGIN) { Item(ITEM_GRISEOUS_CORE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_GRISEOUS_CORE);
    }
}

SINGLE_BATTLE_TEST("Fling works if the item changes a Pokémon's form but not the one holding it")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_BLASTOISINITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        NOT MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Fling's thrown item can be regained with Recycle")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RAZOR_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
        TURN { MOVE(player, MOVE_RECYCLE); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("Wobbuffet used Fling!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        MESSAGE("Wobbuffet used Recycle!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECYCLE, player);
        MESSAGE("Wobbuffet found one Razor Claw!");
        MESSAGE("Wobbuffet used Fling!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Fling - Item is lost even when there is no target")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_SELF_DESTRUCT));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RAZOR_CLAW); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SELF_DESTRUCT); MOVE(player, MOVE_FLING); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Self-Destruct!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SELF_DESTRUCT, opponent);
        HP_BAR(player);
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Wobbuffet used Fling!");
        MESSAGE("But it failed!");

        MESSAGE("Wobbuffet used Fling!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Fling - Item is lost when target protects itself")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RAZOR_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_FLING); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Protect!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        MESSAGE("Wobbuffet used Fling!");
        MESSAGE("The opposing Wobbuffet protected itself!");

        MESSAGE("Wobbuffet used Fling!");
        MESSAGE("But it failed!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Fling - Item does not get blocked by Unnerve if it isn't a berry")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_CALYREX) { Item(ITEM_MENTAL_HERB); Ability(ABILITY_UNNERVE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAUNT); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_FLING); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet shook off the taunt!");
    }
}

SINGLE_BATTLE_TEST("Fling doesn't consume the item if the user is asleep/frozen/paralyzed")
{
    u32 status;
    enum Item item;

    PARAMETRIZE { status = STATUS1_SLEEP_TURN(2); item = ITEM_RAZOR_CLAW; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; item = ITEM_RAZOR_CLAW; }
    PARAMETRIZE { status = STATUS1_FREEZE; item = ITEM_RAZOR_CLAW; }
    PARAMETRIZE { status = STATUS1_SLEEP_TURN(2); item = ITEM_NONE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; item = ITEM_NONE; }
    PARAMETRIZE { status = STATUS1_FREEZE; item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(item); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (status == STATUS1_FREEZE) {
            TURN { MOVE(player, MOVE_FLING, WITH_RNG(RNG_FROZEN, FALSE)); }
            TURN { MOVE(player, MOVE_FLING, WITH_RNG(RNG_FROZEN, TRUE)); }
        } else if (status == STATUS1_PARALYSIS) {
            TURN { MOVE(player, MOVE_FLING, WITH_RNG(RNG_PARALYSIS, TRUE)); }
            TURN { MOVE(player, MOVE_FLING, WITH_RNG(RNG_PARALYSIS, FALSE)); }
        } else {
            TURN { MOVE(player, MOVE_FLING); }
            TURN { MOVE(player, MOVE_FLING); }
        }
    } SCENE {
        if (status == STATUS1_FREEZE) {
            MESSAGE("Wobbuffet is frozen solid!");
            MESSAGE("Wobbuffet thawed out!");
        }
        else if (status == STATUS1_PARALYSIS) {
            MESSAGE("Wobbuffet couldn't move because it's paralyzed!");
        }
        else {
            MESSAGE("Wobbuffet is fast asleep.");
            MESSAGE("Wobbuffet woke up!");
        }
        MESSAGE("Wobbuffet used Fling!");
        if (item != ITEM_NONE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
            HP_BAR(opponent);
        } else {
            MESSAGE("But it failed!");
        }

    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Fling applies special effects when throwing specific Items")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_FLAME_ORB; }
    PARAMETRIZE { item = ITEM_LIGHT_BALL; }
    PARAMETRIZE { item = ITEM_POISON_BARB; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; }
    PARAMETRIZE { item = ITEM_RAZOR_FANG; }
    PARAMETRIZE { item = ITEM_KINGS_ROCK; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("Wobbuffet used Fling!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        switch (item)
        {
        case ITEM_FLAME_ORB:
            {
                MESSAGE("The opposing Wobbuffet was burned!");
                STATUS_ICON(opponent, STATUS1_BURN);
            }
            break;
        case ITEM_LIGHT_BALL:
            {
                MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
                STATUS_ICON(opponent, STATUS1_PARALYSIS);
            }
            break;
        case ITEM_POISON_BARB:
            {
                MESSAGE("The opposing Wobbuffet was poisoned!");
                STATUS_ICON(opponent, STATUS1_POISON);
            }
            break;
        case ITEM_TOXIC_ORB:
            {
                MESSAGE("The opposing Wobbuffet was badly poisoned!");
                STATUS_ICON(opponent, STATUS1_TOXIC_POISON);
            }
            break;
        case ITEM_RAZOR_FANG:
        case ITEM_KINGS_ROCK:
            {
                MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
            }
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Fling's secondary effects are blocked by Shield Dust")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_FLAME_ORB; }
    PARAMETRIZE { item = ITEM_LIGHT_BALL; }
    PARAMETRIZE { item = ITEM_POISON_BARB; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; }
    PARAMETRIZE { item = ITEM_RAZOR_FANG; }
    PARAMETRIZE { item = ITEM_KINGS_ROCK; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("Wobbuffet used Fling!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        switch (item)
        {
        case ITEM_FLAME_ORB:
            {
                NONE_OF {
                    MESSAGE("The opposing Wobbuffet was burned!");
                    STATUS_ICON(opponent, STATUS1_BURN);
                }
                MESSAGE("The Flame Orb was used up…");
            }
            break;
        case ITEM_LIGHT_BALL:
            {
                NONE_OF {
                    MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
                    STATUS_ICON(opponent, STATUS1_PARALYSIS);
                }
                MESSAGE("The Light Ball was used up…");
            }
            break;
        case ITEM_POISON_BARB:
            {
                NONE_OF {
                    MESSAGE("The opposing Wobbuffet was poisoned!");
                    STATUS_ICON(opponent, STATUS1_POISON);
                }
                MESSAGE("The Poison Barb was used up…");
            }
            break;
        case ITEM_TOXIC_ORB:
            {
                NONE_OF {
                    MESSAGE("The opposing Wobbuffet was badly poisoned!");
                    STATUS_ICON(opponent, STATUS1_TOXIC_POISON);
                }
                MESSAGE("The Toxic Orb was used up…");
            }
            break;
        case ITEM_RAZOR_FANG:
        case ITEM_KINGS_ROCK:
            {
                NONE_OF {
                    MESSAGE("The opposing Wobbuffet flinched and couldn't move!");
                }
                switch (item)
                {
                    case ITEM_RAZOR_FANG:
                        MESSAGE("The Razor Fang was used up…");
                        break;
                    case ITEM_KINGS_ROCK:
                        MESSAGE("The King's Rock was used up…");
                        break;
                    default:
                        break;
                }
            }
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Fling's berry effects are blocked by Shield Dust")
{
    enum Item item;
    u32 status1 = STATUS1_NONE;

    PARAMETRIZE { item = ITEM_CHERI_BERRY;  status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { item = ITEM_LIECHI_BERRY; status1 = STATUS1_NONE; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_CHERI_BERRY) == HOLD_EFFECT_CURE_PAR);
        ASSUME(GetItemHoldEffect(ITEM_LIECHI_BERRY) == HOLD_EFFECT_ATTACK_UP);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); Status1(status1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        if (status1 != STATUS1_NONE)
            EXPECT_EQ(opponent->status1, status1);
        else
            EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Fling's berry effects are blocked by Covert Cloak")
{
    enum Item item;
    u32 status1 = STATUS1_NONE;

    PARAMETRIZE { item = ITEM_CHERI_BERRY;  status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { item = ITEM_LIECHI_BERRY; status1 = STATUS1_NONE; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_CHERI_BERRY) == HOLD_EFFECT_CURE_PAR);
        ASSUME(GetItemHoldEffect(ITEM_LIECHI_BERRY) == HOLD_EFFECT_ATTACK_UP);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_COVERT_CLOAK); Status1(status1); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        if (status1 != STATUS1_NONE)
            EXPECT_EQ(opponent->status1, status1);
        else
            EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Fling - thrown berry's effect activates for the target even if the trigger conditions are not met")
{
    enum Item item;
    enum HoldEffect effect;
    enum Stat statId = STAT_HP;
    u32 status1 = STATUS1_NONE;

    PARAMETRIZE { item = ITEM_ORAN_BERRY; effect = HOLD_EFFECT_RESTORE_HP; }
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; effect = HOLD_EFFECT_RESTORE_HP; }
    PARAMETRIZE { item = ITEM_ENIGMA_BERRY; effect = HOLD_EFFECT_ENIGMA_BERRY; }
    PARAMETRIZE { item = ITEM_LEPPA_BERRY; effect = HOLD_EFFECT_RESTORE_PP; }
    PARAMETRIZE { item = ITEM_CHESTO_BERRY; effect = HOLD_EFFECT_CURE_SLP; status1 = STATUS1_SLEEP; }
    PARAMETRIZE { item = ITEM_CHERI_BERRY; effect = HOLD_EFFECT_CURE_PAR; status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { item = ITEM_PECHA_BERRY; effect = HOLD_EFFECT_CURE_PSN; status1 = STATUS1_POISON; }
    PARAMETRIZE { item = ITEM_PECHA_BERRY; effect = HOLD_EFFECT_CURE_PSN; status1 = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { item = ITEM_RAWST_BERRY; effect = HOLD_EFFECT_CURE_BRN; status1 = STATUS1_BURN; }
    PARAMETRIZE { item = ITEM_ASPEAR_BERRY; effect = HOLD_EFFECT_CURE_FRZ; status1 = STATUS1_FREEZE; }
    PARAMETRIZE { item = ITEM_ASPEAR_BERRY; effect = HOLD_EFFECT_CURE_FRZ; status1 = STATUS1_FROSTBITE; }
    PARAMETRIZE { item = ITEM_APICOT_BERRY; effect = HOLD_EFFECT_SP_DEFENSE_UP; statId = STAT_SPDEF; }
    PARAMETRIZE { item = ITEM_MARANGA_BERRY; effect = HOLD_EFFECT_MARANGA_BERRY; statId = STAT_SPDEF; }
    PARAMETRIZE { item = ITEM_GANLON_BERRY; effect = HOLD_EFFECT_DEFENSE_UP; statId = STAT_DEF; }
    PARAMETRIZE { item = ITEM_KEE_BERRY; effect = HOLD_EFFECT_KEE_BERRY; statId = STAT_DEF; }
    PARAMETRIZE { item = ITEM_LIECHI_BERRY; effect = HOLD_EFFECT_ATTACK_UP; statId = STAT_ATK; }
    PARAMETRIZE { item = ITEM_PETAYA_BERRY; effect = HOLD_EFFECT_SP_ATTACK_UP; statId = STAT_SPATK; }
    PARAMETRIZE { item = ITEM_SALAC_BERRY; effect = HOLD_EFFECT_SPEED_UP; statId = STAT_SPEED; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_FLING) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); Attack(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status1); HP(399); MaxHP(400); MovesWithPP({MOVE_CELEBRATE, 35}); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("Wobbuffet used Fling!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        if (effect == HOLD_EFFECT_RESTORE_HP) {
            HP_BAR(opponent);
        }
        else if (effect == HOLD_EFFECT_RESTORE_PP) {
            MESSAGE("The opposing Wobbuffet restored PP to its move Celebrate using its Leppa Berry!");
        }
        else if (status1 != STATUS1_NONE) {
            if (status1 == STATUS1_BURN) {
                MESSAGE("The opposing Wobbuffet's Rawst Berry cured its burn!");
            } else if (status1 == STATUS1_SLEEP) {
                MESSAGE("The opposing Wobbuffet's Chesto Berry woke it up!");
            } else if (status1 == STATUS1_FREEZE) {
                MESSAGE("The opposing Wobbuffet's Aspear Berry defrosted it!");
            } else if (status1 == STATUS1_FROSTBITE) {
                MESSAGE("The opposing Wobbuffet's Aspear Berry cured its frostbite!");
            } else if (status1 == STATUS1_PARALYSIS) {
                MESSAGE("The opposing Wobbuffet's Cheri Berry cured its paralysis!");
            } else if (status1 == STATUS1_TOXIC_POISON || status1 == STATUS1_POISON) {
                MESSAGE("The opposing Wobbuffet's Pecha Berry cured its poison!");
            }
            NOT STATUS_ICON(opponent, status1);
        }
        else if (statId != 0) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            if (statId == STAT_ATK) {
                MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
            } else if (statId == STAT_DEF) {
                if (item == ITEM_GANLON_BERRY) {
                    MESSAGE("The Ganlon Berry boosted the opposing Wobbuffet's Defense!");
                } else {
                    MESSAGE("The Kee Berry boosted the opposing Wobbuffet's Defense!");
                }
            } else if (statId == STAT_SPDEF) {
                if (item == ITEM_APICOT_BERRY) {
                    MESSAGE("The Apicot Berry boosted the opposing Wobbuffet's Sp. Def!");
                } else {
                    MESSAGE("The Maranga Berry boosted the opposing Wobbuffet's Sp. Def!");
                }
            } else if (statId == STAT_SPEED) {
                MESSAGE("The Salac Berry boosted the opposing Wobbuffet's Speed!");
            } else if (statId == STAT_SPATK) {
                MESSAGE("The Petaya Berry boosted the opposing Wobbuffet's Sp. Atk!");
            }
        }
    } THEN {
        if (effect == HOLD_EFFECT_RESTORE_HP) {
            EXPECT_EQ(opponent->hp, opponent->maxHP);
        } else if (effect == HOLD_EFFECT_RESTORE_PP) {
            EXPECT_EQ(opponent->pp[0], 39); // Not 40, because Celebrate was used.
        }  else if (status1 != STATUS1_NONE) {
            EXPECT_EQ(opponent->status1, STATUS1_NONE);
        }
        else if (statId != 0) {
            EXPECT_EQ(opponent->statStages[statId], DEFAULT_STAT_STAGE + 1);
        }
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Fling deals damage based on items fling power")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMovePower(MOVE_CRUNCH) == 80);
        ASSUME(gItemsInfo[ITEM_VENUSAURITE].flingPower == 80);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_VENUSAURITE); }
        OPPONENT(SPECIES_REGIROCK);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
        TURN { MOVE(player, MOVE_CRUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Fling deals damage based on a TM's move power if reusable or fails if breakable")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMovePower(MOVE_EARTHQUAKE) == GetMovePower(MOVE_EGG_BOMB));
        ASSUME(!IsSpeciesOfType(SPECIES_WOBBUFFET, TYPE_DARK));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_TM_EARTHQUAKE); }
        OPPONENT(SPECIES_HIPPOWDON);
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
        TURN { MOVE(player, MOVE_EGG_BOMB); }
    } SCENE {
        if (GetItemImportance(ITEM_TM_EARTHQUAKE) == 0) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
            HP_BAR(opponent, captureDamage: &damage[0]);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
            MESSAGE("But it failed!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EGG_BOMB, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        if (GetItemImportance(ITEM_TM_EARTHQUAKE) == 0)
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Fling fails when a Paradox mon holds a Booster Energy")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_BOOSTER_ENERGY) == HOLD_EFFECT_BOOSTER_ENERGY);
        ASSUME(gSpeciesInfo[SPECIES_RAGING_BOLT].isParadox == TRUE);
        PLAYER(SPECIES_RAGING_BOLT) { Item(ITEM_BOOSTER_ENERGY); Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(player->item == ITEM_BOOSTER_ENERGY);
    }
}

SINGLE_BATTLE_TEST("Fling doesn't fail when holding a Booster Energy and the target is a Paradox mon")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_BOOSTER_ENERGY) == HOLD_EFFECT_BOOSTER_ENERGY);
        ASSUME(gSpeciesInfo[SPECIES_RAGING_BOLT].isParadox == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_RAGING_BOLT) { Ability(ABILITY_PROTOSYNTHESIS); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Fling reveals the user's item before dealing damage")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_FLING, MOVE_EFFECT_ITEM_MESSAGE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLING); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet flung its Potion!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Fling doesn't reveal the user's item if it failed to use the move")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_FLING, MOVE_EFFECT_ITEM_MESSAGE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); Status1(STATUS1_SLEEP); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLING); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Wobbuffet flung its Potion!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, opponent);
            HP_BAR(player);
        };
    }
}

SINGLE_BATTLE_TEST("Fling doesn't reveal the user's item if it missed")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_FLING, MOVE_EFFECT_ITEM_MESSAGE));
        ASSUME(GetItemHoldEffect(ITEM_BRIGHT_POWDER) == HOLD_EFFECT_EVASION_UP);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHT_POWDER); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLING, hit: FALSE); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Wobbuffet flung its Potion!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, opponent);
            HP_BAR(player);
        };
    }
}

SINGLE_BATTLE_TEST("Fling - Mental Herb effect should not remove the target's held item")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        ASSUME(GetItemHoldEffect(ITEM_MENTAL_HERB) == HOLD_EFFECT_MENTAL_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RAZOR_CLAW); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAUNT); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_FLING); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_RAZOR_CLAW);
    }
}

SINGLE_BATTLE_TEST("Fling - White Herb effect should not remove the target's held item")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        ASSUME(GetItemHoldEffect(ITEM_WHITE_HERB) == HOLD_EFFECT_WHITE_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RAZOR_CLAW); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->item, ITEM_RAZOR_CLAW);
    }
}
