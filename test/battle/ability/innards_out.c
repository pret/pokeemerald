#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Innards Out deal dmg on fainting equal to the amount of dmg inflicted on the Innards Out mon")
{
    u16 hp = 0;
    PARAMETRIZE { hp = 5; }
    PARAMETRIZE { hp = 15; }
    PARAMETRIZE { hp = 50; }
    PARAMETRIZE { hp = 100; } // This takes out Wobbuffet.

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_PYUKUMUKU) { HP(hp); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(70); SpAttack(1000); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC); SEND_OUT(player, 1); if (hp == 100) { SEND_OUT(opponent, 1); } }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, opponent);
        HP_BAR(player, hp);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent, hp);
    }
}

SINGLE_BATTLE_TEST("Innards Out counters accumulated multihit damage after all strikes even if fainting on first hit")
{
    s16 captured;

    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_DOUBLE_KICK) == 2);
        ASSUME(GetMoveCategory(MOVE_DOUBLE_KICK) != DAMAGE_CATEGORY_STATUS);
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_PYUKUMUKU) { HP(2); MaxHP(2); Ability(ABILITY_INNARDS_OUT); Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DOUBLE_KICK); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent, captureDamage: &captured);
    } THEN {
        EXPECT_EQ(captured, 2);
    }
}

SINGLE_BATTLE_TEST("Innards Out counters accumulated multihit damage for Parental Bond strikes even if fainting on first hit")
{
    s16 captured;

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_PYUKUMUKU) { HP(2); MaxHP(2); Ability(ABILITY_INNARDS_OUT); Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_MEGA); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent, captureDamage: &captured);
    } THEN {
        EXPECT_EQ(captured, 2);
    }
}

SINGLE_BATTLE_TEST("Innards Out includes mid-move Sitrus Berry recovery in accumulated multihit total")
{
    s16 captured;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
        PLAYER(SPECIES_PYUKUMUKU) { HP(30); MaxHP(40); Ability(ABILITY_INNARDS_OUT); Item(ITEM_SITRUS_BERRY); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KANGASKHAN) { Level(20); Item(ITEM_KANGASKHANITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS, gimmick: GIMMICK_MEGA); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponent);
        HP_BAR(player);
        HP_BAR(player);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent, captureDamage: &captured);
    } THEN {
        EXPECT_EQ(captured, 40);
    }
}

SINGLE_BATTLE_TEST("Innards Out should not include Substitute damage in accumulated multihit total")
{
    s16 captured;

    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_DOUBLE_KICK) == 2);
        ASSUME(GetMoveCategory(MOVE_DOUBLE_KICK) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_PYUKUMUKU) { HP(4); MaxHP(4); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_DOUBLE_KICK); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, opponent);
        SUB_HIT(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent, captureDamage: &captured);
    } THEN {
        EXPECT_EQ(captured, 3);
    }
}

SINGLE_BATTLE_TEST("Innards Out does not trigger when Core Enforcer suppresses it after target has acted")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_CORE_ENFORCER, MOVE_EFFECT_CORE_ENFORCER));
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); Speed(3); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CORE_ENFORCER); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CORE_ENFORCER, opponent);
        HP_BAR(player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Innards Out does not trigger after Gastro Acid has been used")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_PSYCHIC); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, opponent);
        HP_BAR(player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
            HP_BAR(opponent);
        }
    }
}

// According to Showdown Innards Out triggers, but does nothing.
SINGLE_BATTLE_TEST("Innards Out does not damage Magic Guard Pokemon")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Innards Out uses correct damage amount for Future Sight")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN { SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, opponent);
        MESSAGE("Pyukumuku took the Future Sight attack!");
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent, damage: 1);
    }
}

SINGLE_BATTLE_TEST("Innards Out doesn't trigger if Future Sight user is not on field")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(opponent, 1); }
        TURN { SEND_OUT(player, 1); } //SEND_OUT(opponent, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, opponent);
        MESSAGE("Pyukumuku took the Future Sight attack!");
        HP_BAR(player);
        NONE_OF {
         ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
         HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Innards Out triggers if Future Sight user is back on the field")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, opponent);
        MESSAGE("Pyukumuku took the Future Sight attack!");
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent);
    }
}
