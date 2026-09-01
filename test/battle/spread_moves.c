#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Spread Moves: Ability and Item effects activate correctly after a multi target move")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        ASSUME(gItemsInfo[ITEM_COVERT_CLOAK].holdEffect == HOLD_EFFECT_COVERT_CLOAK);
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_COVERT_CLOAK); }
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(260); HP(131); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PIKACHU);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_HEAT_WAVE);
            MOVE(playerLeft, MOVE_HYPER_VOICE);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        MESSAGE("2 sent out Pikachu!");
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_EMERGENCY_EXIT);
            MESSAGE("2 sent out Wynaut!");
        }
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: No damage will be dealt to a mon in an invulnerable position")
{
    u32 attackingMove = 0, invulMove = 0;
    PARAMETRIZE { attackingMove = MOVE_HYPER_VOICE; invulMove = MOVE_FLY; }
    PARAMETRIZE { attackingMove = MOVE_LAVA_PLUME;  invulMove = MOVE_FLY; }
    PARAMETRIZE { attackingMove = MOVE_HYPER_VOICE; invulMove = MOVE_DIVE; }
    PARAMETRIZE { attackingMove = MOVE_LAVA_PLUME;  invulMove = MOVE_DIVE; }
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        ASSUME(GetMoveTarget(MOVE_LAVA_PLUME) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ZAPDOS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, invulMove, target: playerLeft); MOVE(playerLeft, attackingMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, attackingMove, playerLeft);
        NOT HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A spread move attack will activate both resist berries")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_RAICHU) { Item(ITEM_CHILAN_BERRY); }
        OPPONENT(SPECIES_SANDSLASH) { Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE); // effective against both
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        MESSAGE("The opposing Raichu's Chilan Berry lessened the damage it took!");
        MESSAGE("The opposing Sandslash's Chilan Berry lessened the damage it took!");


        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE); // effective against both
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_MUL_EQ(opponentLeftDmg[1], Q_4_12(0.5), opponentLeftDmg[0]);
        EXPECT_MUL_EQ(opponentRightDmg[1], Q_4_12(0.5), opponentRightDmg[0]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: If a spread move attack will activate a resist berries on one Pokémon, only the damage for that mon will be reduced")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_RAICHU)
        OPPONENT(SPECIES_SANDSLASH) { Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        MESSAGE("The opposing Sandslash's Chilan Berry lessened the damage it took!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_EQ(opponentLeftDmg[1], opponentLeftDmg[0]);
        EXPECT_MUL_EQ(opponentRightDmg[1], Q_4_12(0.5), opponentRightDmg[0]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A spread move attack will be weakened by strong winds on both targets")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_AIR_LOCK); }
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_ZAPDOS);
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { SWITCH(playerRight, 2); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_SUPER_EFFECTIVE); // SE on rayquaza
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_MUL_EQ(opponentLeftDmg[0], Q_4_12(0.5), opponentLeftDmg[1]);
        EXPECT_MUL_EQ(opponentRightDmg[0], Q_4_12(0.5), opponentRightDmg[1]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A spread move attack will be weakened by strong winds on one of the targets")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_AIR_LOCK); }
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_DONPHAN)
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { SWITCH(playerRight, 2); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_EQ(opponentLeftDmg[1], opponentLeftDmg[0]);
        EXPECT_MUL_EQ(opponentRightDmg[0], Q_4_12(0.5), opponentRightDmg[1]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE move vs Disguise, Volt Absorb (right) and Lightning Rod (left)")
{
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_LIGHTNING_ROD);
        ABILITY_POPUP(opponentRight, ABILITY_VOLT_ABSORB);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_DISGUISE);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE move vs Disguise, Volt Absorb (left) and Lightning Rod (right)")
{
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); HP(1); }
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_VOLT_ABSORB);
        ABILITY_POPUP(opponentRight, ABILITY_LIGHTNING_ROD);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_DISGUISE);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE move vs Eiscue and Mimikyu (Based on vanilla games)")
{
    s16 disguiseDamage;

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_EISCUE) { Ability(ABILITY_ICE_FACE); }
        OPPONENT(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_EISCUE) { Ability(ABILITY_ICE_FACE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DISGUISE);
        HP_BAR(opponentLeft, captureDamage: &disguiseDamage);
        ABILITY_POPUP(playerRight, ABILITY_ICE_FACE);
        ABILITY_POPUP(opponentRight, ABILITY_ICE_FACE);
        NONE_OF {
            HP_BAR(playerRight);
            HP_BAR(opponentRight);
        }
    } THEN {
        EXPECT_EQ(disguiseDamage, opponentLeft->maxHP / 8);
        EXPECT_EQ(opponentLeft->species, SPECIES_MIMIKYU_BUSTED);
        EXPECT_EQ(playerRight->species, SPECIES_EISCUE_NOICE);
        EXPECT_EQ(opponentRight->species, SPECIES_EISCUE_NOICE);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move, Gem Boosted, vs Resist Berries")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        ASSUME(gItemsInfo[ITEM_NORMAL_GEM].holdEffect == HOLD_EFFECT_GEMS);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); Item(ITEM_NORMAL_GEM); }
        PLAYER(SPECIES_WYNAUT) { Speed(30); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_CHILAN_BERRY); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        MESSAGE("The Normal Gem strengthened Wobbuffet's power!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("The opposing Wobbuffet's Chilan Berry lessened the damage it took!");
        MESSAGE("The opposing Wynaut's Chilan Berry lessened the damage it took!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Explosion, Gem Boosted, vs Resist Berries")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
        ASSUME(gItemsInfo[ITEM_NORMAL_GEM].holdEffect == HOLD_EFFECT_GEMS);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); Item(ITEM_NORMAL_GEM); }
        PLAYER(SPECIES_MISDREAVUS) { Speed(30); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_CHILAN_BERRY); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPLOSION); }
    } SCENE {
        MESSAGE("It doesn't affect Misdreavus…");
        MESSAGE("The Normal Gem strengthened Wobbuffet's power!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);

        MESSAGE("The opposing Wobbuffet's Chilan Berry lessened the damage it took!");
        MESSAGE("The opposing Wynaut's Chilan Berry lessened the damage it took!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move vs Eiscue and Mimikyu with 1 Eject Button")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_RAZOR_LEAF) == TARGET_BOTH);
        ASSUME(GetMoveCategory(MOVE_RAZOR_LEAF) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); }
        PLAYER(SPECIES_WYNAUT) { Speed(30); }
        OPPONENT(SPECIES_MIMIKYU) { Speed(20); Ability(ABILITY_DISGUISE); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_EISCUE) { Speed(10); Ability(ABILITY_ICE_FACE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_RAZOR_LEAF); SEND_OUT(opponentLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_LEAF, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DISGUISE);
        ABILITY_POPUP(opponentRight, ABILITY_ICE_FACE);
        MESSAGE("The opposing Mimikyu is switched out with the Eject Button!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move vs Wide Guard")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); }
        PLAYER(SPECIES_WYNAUT) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WIDE_GUARD); MOVE(opponentLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, playerLeft);
        MESSAGE("Wide Guard now protects your side!");
        MESSAGE("The opposing Wobbuffet used Hyper Voice!");
        MESSAGE("Wobbuffet protected itself!");
        MESSAGE("Wynaut protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move vs one protecting mon")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PROTECT); MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Protect!");
        MESSAGE("Wobbuffet used Hyper Voice!");
        MESSAGE("The opposing Wobbuffet protected itself!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Super Effective Message on both opposing mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GOLEM);
        OPPONENT(SPECIES_ONIX);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_SUPER_EFFECTIVE);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("It's super effective on the opposing Golem and Onix!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Super Effective Message on both player mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_GOLEM);
        PLAYER(SPECIES_ONIX);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        MESSAGE("It's super effective on Golem and Onix!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Not very effective Message on both opposing mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CHIKORITA);
        OPPONENT(SPECIES_TREECKO);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("It's not very effective on the opposing Chikorita and Treecko.");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Not very effective message on both player mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_CHIKORITA);
        PLAYER(SPECIES_TREECKO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        MESSAGE("It's not very effective on Chikorita and Treecko.");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Doesn't affect any target")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_PIDGEY);
        OPPONENT(SPECIES_HOOTHOOT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("It doesn't affect Pidgey…");
        MESSAGE("It doesn't affect the opposing Pidgey…");
        MESSAGE("It doesn't affect the opposing Hoothoot…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Unless move hits every target user will not include partner in the target count")
{
    GIVEN {
        PLAYER(SPECIES_SANDSLASH);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_TORKOAL);
        OPPONENT(SPECIES_TORKOAL);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ICY_WIND); MOVE(playerLeft, MOVE_ROCK_SLIDE); SEND_OUT(playerRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICY_WIND, opponentRight);
        EFFECTIVENESS_SE(playerLeft, SE_SUPER_EFFECTIVE); // SE against sandslash
        HP_BAR(playerLeft);
        HP_BAR(playerRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_SUPER_EFFECTIVE); // se against torkoal
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("It's super effective on the opposing Torkoal and Torkoal!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Focus Sash activates correctly")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(2); MaxHP(2); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(2); MaxHP(2); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { HP(2); MaxHP(2); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_HYPER_VOICE); MOVE(playerLeft, MOVE_EXPLOSION); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerRight);
        MESSAGE("The opposing Wobbuffet hung on using its Focus Sash!");
        MESSAGE("The opposing Wynaut hung on using its Focus Sash!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Wynaut hung on using its Focus Sash!");
        MESSAGE("The opposing Wynaut fainted!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE ground type move vs Levitate and Air Balloon")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_FLYGON) { Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_LEVITATE);
        MESSAGE("It doesn't affect the opposing Wynaut…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Earthquake fails in order of ally, left foe, right foe")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_FLYGON) { Speed(1); Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_FLYGON) { Speed(2); Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_FLYGON) { Speed(3); Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_LEVITATE);
        ABILITY_POPUP(opponentLeft, ABILITY_LEVITATE);
        ABILITY_POPUP(opponentRight, ABILITY_LEVITATE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Earthquake fails due to accuracy in order of ally, left foe, right foe")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); Item(ITEM_BRIGHTPOWDER); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_BRIGHTPOWDER); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE, hit: FALSE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        MESSAGE("Wynaut avoided the attack!");
        MESSAGE("The opposing Wobbuffet avoided the attack!");
        MESSAGE("The opposing Wynaut avoided the attack!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A missed multi-target stat move names the missed battler")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_STRING_SHOT) == TARGET_BOTH);
        PLAYER(SPECIES_CATERPIE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STRING_SHOT, hit: FALSE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet avoided the attack!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Results aren't printed for battlers not present on the field")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveTarget(MOVE_COTTON_SPORE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        PLAYER(SPECIES_WHIMSICOTT) { Speed(3); Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_AGGRON) { Defense(1); Speed(4); }
        OPPONENT(SPECIES_HERACROSS) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_MEMENTO, target: playerRight);
            MOVE(playerLeft, MOVE_EARTHQUAKE);
        }
        TURN {
            MOVE(playerRight, MOVE_COTTON_SPORE);
            MOVE(playerLeft, MOVE_PSYCHIC_TERRAIN);
        }
        TURN {
            MOVE(playerRight, MOVE_COTTON_SPORE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        NONE_OF {
            EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE);
            HP_BAR(opponentLeft);
            MESSAGE("It's extremely effective on the opposing Aggron!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COTTON_SPORE, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Aggron's Speed harshly fell!");
        }
        MESSAGE("Whimsicott used Cotton Spore!");
        NONE_OF {
            MESSAGE("The opposing Aggron is protected by the Psychic Terrain!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Aggron's Speed harshly fell!");
            MESSAGE("But it failed!");
        }
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Results aren't printed for battlers not present on the field (Unseen Fist)")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_BRUTAL_SWING) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_URSHIFU) { Attack(1); Speed(4); Ability(ABILITY_UNSEEN_FIST); }
        PLAYER(SPECIES_URSHIFU) { Attack(1); Speed(3); Ability(ABILITY_UNSEEN_FIST); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_PROTECT);
            MOVE(opponentRight, MOVE_PROTECT);
            MOVE(playerLeft, MOVE_BRUTAL_SWING);
            MOVE(playerRight, MOVE_BRUTAL_SWING);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BRUTAL_SWING, playerRight);
        NOT MESSAGE("It's super effective on the opposing Wobbuffet and Wynaut!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Results aren't printed for battlers not present on the field (Absorb Abilities)")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET) { Attack(1); Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Attack(1); Speed(3); }
        OPPONENT(SPECIES_GASTRODON) { HP(1); Speed(2); Ability(ABILITY_STORM_DRAIN); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
            MOVE(playerRight, MOVE_SURF);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerRight);
        NOT ABILITY_POPUP(opponentLeft, ABILITY_STORM_DRAIN);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Results aren't printed for battlers not present on the field (Missing Moves)")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Item(ITEM_BRIGHTPOWDER); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(1); Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
            MOVE(playerRight, MOVE_EARTHQUAKE, hit: FALSE);
        }
    } SCENE {
        MESSAGE("Wobbuffet avoided the attack!");
        NOT MESSAGE("The opposing Wobbuffet avoided the attack!");
        MESSAGE("The opposing Wynaut avoided the attack!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Results aren't printed for battlers not present on the field (Magic Bounce)")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_GROWL) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Attack(1); Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Attack(1); Speed(3); }
        OPPONENT(SPECIES_HATTERENE) { HP(1); Speed(2); Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
            MOVE(playerRight, MOVE_GROWL);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, playerRight);
        NOT ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}
