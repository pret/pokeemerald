#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Parental Bond converts Tackle into a two-strike move")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].split != SPLIT_STATUS);
        ASSUME(gBattleMoves[MOVE_TACKLE].strikeCount < 2);
        ASSUME(gBattleMoves[MOVE_TACKLE].effect == EFFECT_HIT);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, megaEvolve: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not convert a move with three or more strikes to a two-strike move")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TRIPLE_KICK].split != SPLIT_STATUS);
        ASSUME(gBattleMoves[MOVE_TRIPLE_KICK].strikeCount == 3);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_KICK, megaEvolve: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond converts multi-target moves into a two-strike move in Single Battles")
{
    u16 move;
    PARAMETRIZE { move = MOVE_EARTHQUAKE; }
    PARAMETRIZE { move = MOVE_ICY_WIND; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_EARTHQUAKE].strikeCount < 2);
        ASSUME(gBattleMoves[MOVE_EARTHQUAKE].target == MOVE_TARGET_FOES_AND_ALLY);
        ASSUME(gBattleMoves[MOVE_ICY_WIND].strikeCount < 2);
        ASSUME(gBattleMoves[MOVE_ICY_WIND].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move, megaEvolve: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

DOUBLE_BATTLE_TEST("Parental Bond does not convert multi-target moves into a two-strike move in Double Battles, even if it only damages one")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_EARTHQUAKE].strikeCount < 2);
        ASSUME(gBattleMoves[MOVE_EARTHQUAKE].target == MOVE_TARGET_FOES_AND_ALLY);
        ASSUME(gSpeciesInfo[SPECIES_PIDGEY].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE, megaEvolve: TRUE); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentLeft, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("It doesn't affect Pidgey…");
        MESSAGE("It doesn't affect Foe Pidgey…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond-converted moves only hit once on Lightning Rod/Storm Drain mons")
{
    u16 move, species, ability, type;
    PARAMETRIZE { move = MOVE_THUNDERBOLT; ability = ABILITY_LIGHTNING_ROD; species = SPECIES_RAICHU; type = TYPE_ELECTRIC; }
    PARAMETRIZE { move = MOVE_SURF; ability = ABILITY_STORM_DRAIN; species = SPECIES_LILEEP; type = TYPE_WATER; }
    GIVEN {
        ASSUME(gBattleMoves[move].strikeCount < 2);
        ASSUME(gBattleMoves[move].type == type);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move, megaEvolve: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ABILITY_POPUP(opponent, ability);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            HP_BAR(opponent);
            ABILITY_POPUP(opponent, ability);
        };
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

TO_DO_BATTLE_TEST("Parental Bond tests");

// Temporary TODO: Convert Bulbapedia description into tests.
/*
In battle

Since Parental Bond turns moves into two-hit multi-strike moves, each strike has a separate chance to be a critical hit, items and Abilities that trigger upon strike or contact such as Cursed Body and Rocky Helmet occur for each strike, and Spiky Shield and King's Shield only damage and decrease Attack (respectively) once if they protect a Pokémon from a contact move used by a Pokémon with Parental Bond. Additionally, there is only one accuracy check, so either both strikes hit or both strikes miss.

Any attack which has a secondary effect (except Secret Power) has the same secondary effect on both strikes (such as Power-Up Punch); if a secondary effect has a certain chance of occurring, each strike has an independent chance of activating that effect. Even if the Pokémon's Ability is changed to Mummy after the first strike, it will continue to make a second strike regardless. Pay Day scatters coins after the first strike only. Incinerate destroys applicable held items after each strike.

Unlike other secondary effects, Secret Power's secondary effect can only occur after the final strike. If a move has recoil damage, the recoil will be based on the damage dealt by both strikes, but will be taken after the final strike; Struggle will inflict recoil damage equal to half the user's maximum HP (after the final strike). Moves that switch the target out and moves that switch the user out strike twice, then force a Pokémon to switch out after both strikes are conducted. Thief, Covet, Bug Bite, and Pluck do not steal or eat the target's held item until after the final strike, so if the target could use its item after the first strike (e.g. due to low HP), it will use it before the attacker can steal or eat it. Smelling Salts, Wake-Up Slap, and Knock Off do not cure the target's status condition or remove its held item (respectively) until after the final strike, so both strikes get the increased power. Fire-type moves, Scald, and Steam Eruption thaw a frozen target after the final strike (so a frozen target cannot be thawed and then burned by the same move). Smack Down and Thousand Arrows only cause the target to fall to the ground after the final strike. If Meloetta has Parental Bond and uses Relic Song, it will change Forme only once, after the final strike. Burn Up does not remove the user's Fire type until after the second strike (so both strikes receive same-type attack bonus).

If Present heals the target it will only strike once, but if it damages the target it will strike twice (the second strike will always damage the target). Fixed-damage moves (such as Seismic Toss and Dragon Rage) deal the full amount of damage for both strikes. The damage dealt by Psywave is generated separately for each strike, and the second strike's damage is not halved. Each strike of Super Fang halves the target's HP (effectively quartering it if HP is not changed between strikes). Counter, Mirror Coat, Metal Burst, and Bide deal the full amount of damage for both strikes. The first strike of Assurance counts as previously taking damage for the second strike, giving it increased power. Fury Cutter and Echoed Voice only consider uses of the move rather than hits, so the second strike's power is not boosted by the first strike. Grass Pledge, Fire Pledge, and Water Pledge strike twice, even when used as a combination move. Natural Gift and Spit Up strike twice. Moves that require recharging after use strike twice, but the user only needs to recharge for one turn.

One-hit knockout moves, Fling, Self-Destruct, Explosion, Final Gambit, Uproar, Rollout, and Ice Ball only strike once. (Other consecutively executed moves, such as Outrage, can strike twice.) Moves with a charging turn (such as Fly and Solar Beam) only strike once, even if the Pokémon becomes fully charged in one turn (such as with a Power Herb). Endeavor also only strikes once, even if the user or target's HP is changed after it strikes (such as by Iron Barbs or the Sitrus Berry). Confusion damage only occurs once.

Spirit Shackle and Anchor Shot only trap the target after the final strike.

Generation VI
The second strike has its damage halved (unless it is a set-damage move)

Generation VII onward
The second strike now deals 25% of its usual damage (unless it is a set-damage move).

Parental Bond does not affect Z-Moves or Max Moves.
*/
// TONS OF TESTS NEEDED. FOR NOW, THIS SINGLE TEST IS MADE TO MAKE SURE AN ISSUE WAS FIXED.
