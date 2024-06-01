#include "global.h"
#include "test/battle.h"

// General
TO_DO_BATTLE_TEST("Beat Up hits the target for each non-fainted, non-statused member in the party");
TO_DO_BATTLE_TEST("Beat Up's strikes have each an independent chance of a critical hit");

// B_BEAT_UP Gen2-4
TO_DO_BATTLE_TEST("Beat Up lists each party member's name");
TO_DO_BATTLE_TEST("Beat Up's damage is typeless");
TO_DO_BATTLE_TEST("Beat Up's damage doesn't consider STAB");
TO_DO_BATTLE_TEST("Beat Up's last strike-only can trigger King's Rock");
TO_DO_BATTLE_TEST("Beat Up's base power is the same for each strike");
TO_DO_BATTLE_TEST("Beat Up's damage is determined by each striking Pokémon's base attack and level and the target's defense");
TO_DO_BATTLE_TEST("Beat Up ignores stat stage changes"); //eg. Swords Dance
TO_DO_BATTLE_TEST("Beat Up ignores Huge Power");
TO_DO_BATTLE_TEST("Beat Up ignores Choice Band");

// B_BEAT_UP Gen5+
TO_DO_BATTLE_TEST("Beat Up doesn't list party member's name");
TO_DO_BATTLE_TEST("Beat Up's damage is Dark-typed");
TO_DO_BATTLE_TEST("Beat Up's damage receives STAB");
TO_DO_BATTLE_TEST("Beat Up's can trigger King's Rock on all strikes");
TO_DO_BATTLE_TEST("Beat Up's base power is determined by each striking Pokémon");
TO_DO_BATTLE_TEST("Beat Up's damage is determined by the user's attack and the target's defense");
TO_DO_BATTLE_TEST("Beat Up's damage considers stat stage changes"); //eg. Swords Dance
TO_DO_BATTLE_TEST("Beat Up's damage considers Huge Power");
TO_DO_BATTLE_TEST("Beat Up's damage considers Choice Band");

// Unconfirmed by Bulbapedia
// - Technician interacion
