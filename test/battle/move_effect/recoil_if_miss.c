#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_JUMP_KICK].effect == EFFECT_RECOIL_IF_MISS);
}

SINGLE_BATTLE_TEST("Jump Kick has 50% recoil on miss")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_JUMP_KICK, hit: FALSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        MESSAGE("Wobbuffet used Jump Kick!");
        MESSAGE("Wobbuffet's attack missed!");
        MESSAGE("Wobbuffet kept going and crashed!");
        HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Jump Kick has 50% recoil on protect")
{
    GIVEN {
        ASSUME(!gMovesInfo[MOVE_JUMP_KICK].ignoresProtect);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_JUMP_KICK, player);
        HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Jump Kick has no recoil if no target")
{
    GIVEN {
        ASSUME(B_HEALING_WISH_SWITCH >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEALING_WISH); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); SEND_OUT(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        NOT HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Jump Kick's recoil happens after Spiky Shield damage and Pokemon can faint from either of these")
{
    s16 hp, maxHp = 256;
    bool32 faintOnSpiky = FALSE, faintOnJumpKick = FALSE;

    PARAMETRIZE { hp = maxHp; }
    PARAMETRIZE { hp = maxHp / 2; faintOnJumpKick = TRUE; } // Faints after Jump Kick's recoil
    PARAMETRIZE { hp = maxHp / 8; faintOnSpiky = TRUE; } // Faints after Spiky Shield's recoil

    GIVEN {
        ASSUME(gMovesInfo[MOVE_SPIKY_SHIELD].effect == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); MaxHP(maxHp); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (!faintOnJumpKick && !faintOnSpiky) {
            TURN { MOVE(opponent, MOVE_SPIKY_SHIELD); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); }
        } else {
            TURN { MOVE(opponent, MOVE_SPIKY_SHIELD); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); SEND_OUT(player, 1); }
        }
        TURN { ; }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKY_SHIELD, opponent);
        MESSAGE("Wobbuffet used Jump Kick!");
        MESSAGE("Foe Wobbuffet protected itself!");
        HP_BAR(player, damage: maxHp / 8);
        MESSAGE("Wobbuffet was hurt by Foe Wobbuffet's Spiky Shield!");
        if (faintOnSpiky){
            MESSAGE("Wobbuffet fainted!");
            MESSAGE("Go! Wynaut!");
            NONE_OF {
                MESSAGE("Wobbuffet kept going and crashed!");
                HP_BAR(player);
            }
        } else {
            MESSAGE("Wobbuffet kept going and crashed!");
            HP_BAR(player);
            if (faintOnJumpKick) {
                MESSAGE("Wobbuffet fainted!");
                MESSAGE("Go! Wynaut!");
            }
        }
    }
}
