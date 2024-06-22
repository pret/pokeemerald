#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_TRI_ATTACK].category == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Download raises Attack if player has lower Def than Sp. Def", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TRACE; }
    PARAMETRIZE { ability = ABILITY_DOWNLOAD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Defense(100); SpDefense(200); }
        OPPONENT(SPECIES_PORYGON) { Ability(ability); Attack(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_DOWNLOAD)
        {
            ABILITY_POPUP(opponent, ABILITY_DOWNLOAD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Porygon's Download raised its Attack!");
        }
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Download raises Sp.Attack if enemy has lower Sp. Def than Def", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_TRACE; }
    PARAMETRIZE { ability = ABILITY_DOWNLOAD; }
    GIVEN {
        PLAYER(SPECIES_PORYGON) { Ability(ability); SpAttack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(200); SpDefense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRI_ATTACK); }
    } SCENE {
        if (ability == ABILITY_DOWNLOAD)
        {
            ABILITY_POPUP(player, ABILITY_DOWNLOAD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Porygon's Download raised its Sp. Atk!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Download doesn't activate if target hasn't been sent out yet", s16 damagePhysical, s16 damageSpecial)
{
    u32 ability;
    KNOWN_FAILING;
    PARAMETRIZE { ability = ABILITY_TRACE; }
    PARAMETRIZE { ability = ABILITY_DOWNLOAD; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EXPLOSION].effect == EFFECT_EXPLOSION);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_PORYGON) { Ability(ability); Defense(400); SpDefense(300); Speed(300); Attack(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
        OPPONENT(SPECIES_PORYGON2) { Ability(ability); Defense(100); SpDefense(200); Speed(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TRI_ATTACK); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        // Everyone faints.

        MESSAGE("Go! Porygon!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_DOWNLOAD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Porygon's Download raised its Attack!");
        }
        MESSAGE("2 sent out Porygon2!");

        if (ability == ABILITY_DOWNLOAD)
        {
            ABILITY_POPUP(opponent, ABILITY_DOWNLOAD);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Porygon2's Download raised its Sp. Atk!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRI_ATTACK, opponent);
        HP_BAR(player, captureDamage: &results[i].damageSpecial);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damageSpecial, Q_4_12(1.5), results[1].damageSpecial);
    }
}
