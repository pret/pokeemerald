#include "global.h"
#include "test/battle.h"

#if B_UPDATED_MOVE_DATA >= GEN_6
    #define FUTURE_SIGHT_EQUIVALENT MOVE_SEED_FLARE /* 120 power */
#elif B_UPDATED_MOVE_DATA >= GEN_5
    #define FUTURE_SIGHT_EQUIVALENT MOVE_DYNAMAX_CANNON /* 100 power */
#else
    #define FUTURE_SIGHT_EQUIVALENT MOVE_EXTRASENSORY /* 80 power */
#endif

ASSUMPTIONS
{
    ASSUME(GetMovePower(FUTURE_SIGHT_EQUIVALENT) == GetMovePower(MOVE_FUTURE_SIGHT));
    ASSUME(GetMoveCategory(FUTURE_SIGHT_EQUIVALENT) == GetMoveCategory(MOVE_FUTURE_SIGHT));
    ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
    ASSUME(GetMovePower(MOVE_FUTURE_SIGHT) > 0);
}

SINGLE_BATTLE_TEST("Future Sight uses Sp. Atk stat of the original user without modifiers")
{
    enum Item item;
    s16 seedFlareDmg;
    s16 futureSightDmg;

    PARAMETRIZE { item = ITEM_TWISTED_SPOON; }
    PARAMETRIZE { item = ITEM_PSYCHIC_GEM; }

    GIVEN {
        PLAYER(SPECIES_PIKACHU) { Item(item); }
        PLAYER(SPECIES_RAICHU) { Item(item); }
        OPPONENT(SPECIES_REGICE);
    } WHEN {
        TURN { MOVE(player, FUTURE_SIGHT_EQUIVALENT, WITH_RNG(RNG_SECONDARY_EFFECT, FALSE)); }
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, FUTURE_SIGHT_EQUIVALENT, player);
        HP_BAR(opponent, captureDamage: &seedFlareDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Regice took the Future Sight attack!");
        HP_BAR(opponent, captureDamage: &futureSightDmg);
    } THEN {
        EXPECT_EQ(seedFlareDmg, futureSightDmg);
    }
}

SINGLE_BATTLE_TEST("Future Sight is not boosted by Life Orb is original user if not on the field")
{
    s16 seedFlareDmg;
    s16 futureSightDmg;

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_LIFE_ORB) == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_PIKACHU);
        PLAYER(SPECIES_RAICHU) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_REGICE);
    } WHEN {
        TURN { MOVE(player, FUTURE_SIGHT_EQUIVALENT, WITH_RNG(RNG_SECONDARY_EFFECT, FALSE)); }
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, FUTURE_SIGHT_EQUIVALENT, player);
        HP_BAR(opponent, captureDamage: &seedFlareDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Regice took the Future Sight attack!");
        HP_BAR(opponent, captureDamage: &futureSightDmg);
        NOT HP_BAR(player);
    } THEN {
        EXPECT_EQ(seedFlareDmg, futureSightDmg);
    }
}

TO_DO_BATTLE_TEST("Future Sight does not receive STAB from party mon (Gen 2-4)")
SINGLE_BATTLE_TEST("Future Sight receives STAB from party mon (Gen 5+)")
{
    s16 seedFlareDmg;
    s16 futureSightDmg;

    GIVEN {
        PLAYER(SPECIES_RALTS);
        PLAYER(SPECIES_RAICHU);
        OPPONENT(SPECIES_REGICE);
    } WHEN {
        TURN { MOVE(player, FUTURE_SIGHT_EQUIVALENT, WITH_RNG(RNG_SECONDARY_EFFECT, FALSE)); }
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, FUTURE_SIGHT_EQUIVALENT, player);
        HP_BAR(opponent, captureDamage: &seedFlareDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        HP_BAR(opponent, captureDamage: &futureSightDmg);
    } THEN {
        EXPECT_MUL_EQ(seedFlareDmg, Q_4_12(1.5), futureSightDmg);
    }
}

TO_DO_BATTLE_TEST("Future Sight is not affected by type effectiveness (Gen 2-4)")
SINGLE_BATTLE_TEST("Future Sight is affected by type effectiveness (Gen 5+)")
{
    GIVEN {
        PLAYER(SPECIES_PIKACHU);
        PLAYER(SPECIES_RAICHU);
        OPPONENT(SPECIES_HOUNDOOM);
    } WHEN {
        TURN { MOVE(player, FUTURE_SIGHT_EQUIVALENT, WITH_RNG(RNG_SECONDARY_EFFECT, FALSE)); }
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, FUTURE_SIGHT_EQUIVALENT, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Houndoom took the Future Sight attack!");
        MESSAGE("It doesn't affect the opposing Houndoom…");
        NOT HP_BAR(opponent);
    }
}

TO_DO_BATTLE_TEST("Future Sight ignores Wonder Guard (Gen 2-4)")
SINGLE_BATTLE_TEST("Future Sight doesn't ignore Wonder Guard (Gen 5+)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        ABILITY_POPUP(opponent, ABILITY_WONDER_GUARD);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Future Sight will miss timing if target faints before it is about to get hit")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MEMENTO) == EFFECT_MEMENTO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_MEMENTO); SEND_OUT(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponent);
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("2 sent out Wynaut!");
        NOT MESSAGE("The opposing Wynaut took the Future Sight attack!");
    }
}

SINGLE_BATTLE_TEST("Future Sight will miss timing if target faints by residual damage")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_WRAP, MOVE_EFFECT_WRAP));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(10); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_WRAP); SEND_OUT(opponent, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WRAP, player);
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("2 sent out Wynaut!");
        NOT MESSAGE("The opposing Wynaut took the Future Sight attack!");
    }
}

SINGLE_BATTLE_TEST("Future Sight breaks Focus Sash and doesn't make the holder endure another move")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_PSYCHIC) > 0);
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Level(1); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
        TURN { MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        MESSAGE("The opposing Pidgey hung on using its Focus Sash!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC, player);
        MESSAGE("The opposing Pidgey fainted!");
    }
}

SINGLE_BATTLE_TEST("Future Sight does not trigger Protean")
{
    GIVEN {
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
    } SCENE {
        NOT ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
    }
}

SINGLE_BATTLE_TEST("Future Sight set up is not blocked by Protect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_FUTURE_SIGHT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
    }
}

SINGLE_BATTLE_TEST("Future Sight does not trigger Red Card")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_RED_CARD);
    }
}

SINGLE_BATTLE_TEST("Future Sight does not trigger Eject Button")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_EJECT_BUTTON);
    }
}

SINGLE_BATTLE_TEST("Future Sight does not trigger Rowap Berry")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ROWAP_BERRY].holdEffect == HOLD_EFFECT_ROWAP_BERRY);
        ASSUME(GetMoveCategory(MOVE_FUTURE_SIGHT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_ROWAP_BERRY);
    }
}

SINGLE_BATTLE_TEST("Future Sight does not trigger Cursed Body")
{
    PASSES_RANDOMLY(10, 10, RNG_CURSED_BODY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_FRILLISH) { Ability(ABILITY_CURSED_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        NOT ABILITY_POPUP(opponent, ABILITY_CURSED_BODY);
    } THEN {
        u32 disabledMove = player->volatiles.disabledMove;
        EXPECT_EQ(disabledMove, MOVE_NONE);
    }
}

SINGLE_BATTLE_TEST("Future Sight flying type attacker in party receives no boost from Psychic Terrain", s16 damage)
{
    bool32 terrain;
    enum Species species;

    PARAMETRIZE { species = SPECIES_PIDGEY; terrain = FALSE; }
    PARAMETRIZE { species = SPECIES_PIDGEY; terrain = TRUE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; terrain = FALSE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; terrain = TRUE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_PSYCHIC_TERRAIN) == B_TERRAIN_PSYCHIC);
        ASSUME(gSpeciesInfo[SPECIES_PIDGEY].types[0] == TYPE_FLYING || gSpeciesInfo[SPECIES_PIDGEY].types[1] == TYPE_FLYING);
        PLAYER(species);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        enum Move move = terrain ? MOVE_PSYCHIC_TERRAIN : MOVE_CELEBRATE;
        TURN { MOVE(opponent, move); MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        if (B_TERRAIN_TYPE_BOOST >= GEN_8) {
            EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.3), results[3].damage);
        } else {
            EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[3].damage);
        }
    }
}

SINGLE_BATTLE_TEST("Future Sight is affected by Beads of Ruin on the original slot")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.33), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain can inflict bad poison from Future Sight if the user is still on the field")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Wobbuffet took the Future Sight attack!");
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, badPoison: TRUE);
    } THEN {
        EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
    }
}

SINGLE_BATTLE_TEST("Toxic Chain does not trigger from Future Sight if the user is not on the field")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_OKIDOGI) { Ability(ABILITY_TOXIC_CHAIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FUTURE_SIGHT, player);
        MESSAGE("The opposing Wobbuffet took the Future Sight attack!");
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_TOXIC_CHAIN);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, badPoison: TRUE);
        }
    } THEN {
        EXPECT(opponent->status1 == 0);
    }
}
