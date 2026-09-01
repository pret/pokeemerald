#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
}

SINGLE_BATTLE_TEST("OHKO moves can hit semi-invulnerable mons when the user has No-Guard")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLY); }
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
        HP_BAR(opponent, hp: 0);
    }
}

SINGLE_BATTLE_TEST("OHKO moves can not hit semi-invulnerable")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLY); MOVE(player, MOVE_FISSURE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
    }
}

SINGLE_BATTLE_TEST("OHKO moves can can be endured by Focus Sash")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
        HP_BAR(opponent, hp: 1);
        MESSAGE("The opposing Wobbuffet hung on using its Focus Sash!");
    }
}

SINGLE_BATTLE_TEST("OHKO moves can can be endured by Sturdy")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); }
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
        ABILITY_POPUP(opponent, ABILITY_STURDY);
    }
}

SINGLE_BATTLE_TEST("OHKO moves always fails if the target has a higher level than the user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
    }
}

SINGLE_BATTLE_TEST("OHKO moves fail by level before checking Sturdy")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(1); }
        OPPONENT(SPECIES_GEODUDE) { Level(2); Ability(ABILITY_STURDY); }
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
            ABILITY_POPUP(opponent, ABILITY_STURDY);
        }
    }
}

SINGLE_BATTLE_TEST("OHKO moves fail if target protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_FISSURE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
    }
}

SINGLE_BATTLE_TEST("Sheer Cold can hit semi-invulnerable mons when the user has No-Guard")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLY); }
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        HP_BAR(opponent, hp: 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Cold can be endured by Focus Sash")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        HP_BAR(opponent, hp: 1);
        MESSAGE("The opposing Wobbuffet hung on using its Focus Sash!");
    }
}

SINGLE_BATTLE_TEST("Sheer Cold can be endured by Sturdy")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        ABILITY_POPUP(opponent, ABILITY_STURDY);
    }
}

SINGLE_BATTLE_TEST("Sheer Cold doesn't affect Ice-type Pokémon (Gen3-6)")
{
    GIVEN {
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_6);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT MESSAGE("It doesn't affect the opposing Glalie…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        HP_BAR(opponent, hp: 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Cold doesn't affect Ice-type Pokémon (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        MESSAGE("It doesn't affect the opposing Glalie…");
    }
}

SINGLE_BATTLE_TEST("Sheer Cold's accuracy decreasaes by 10% if the user is not Ice type")
{
    PASSES_RANDOMLY(20, 100, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ICE);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ICE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        HP_BAR(opponent);
    }
}

TO_DO_BATTLE_TEST("OHKO moves faints the target, skipping regular damage calculations")
TO_DO_BATTLE_TEST("OHKO moves's accuracy increases by 1% for every level the user has over the target")
TO_DO_BATTLE_TEST("OHKO moves's ignores non-stage accuracy modifiers") // Gravity, Wide Lens, Compound Eyes
TO_DO_BATTLE_TEST("OHKO moves ignore non-stage accuracy modifiers") // Gravity, Wide Lens, Compound Eyes
