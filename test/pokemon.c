#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "pokemon.h"
#include "test/overworld_script.h"
#include "test/test.h"

TEST("Nature independent from Hidden Nature")
{
    u32 i, j, nature = 0, hiddenNature = 0;
    struct Pokemon mon;
    for (i = 0; i < NUM_NATURES; i++)
    {
        for (j = 0; j < NUM_NATURES; j++)
        {
            PARAMETRIZE { nature = i; hiddenNature = j; }
        }
    }
    CreateMonWithNature(&mon, SPECIES_WOBBUFFET, 100, 0, nature);
    SetMonData(&mon, MON_DATA_HIDDEN_NATURE, &hiddenNature);
    EXPECT_EQ(GetNature(&mon), nature);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HIDDEN_NATURE), hiddenNature);
}

TEST("Terastallization type defaults to primary or secondary type")
{
    u32 i, teraType;
    struct Pokemon mon;
    for (i = 0; i < 128; i++) PARAMETRIZE {}
    CreateMon(&mon, SPECIES_PIDGEY, 100, 0, FALSE, 0, OT_ID_PRESET, 0);
    teraType = GetMonData(&mon, MON_DATA_TERA_TYPE);
    EXPECT(teraType == gSpeciesInfo[SPECIES_PIDGEY].types[0]
        || teraType == gSpeciesInfo[SPECIES_PIDGEY].types[1]);
}

TEST("Terastallization type can be set to any type")
{
    u32 i, teraType;
    struct Pokemon mon;
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        PARAMETRIZE { teraType = i; }
    }
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, FALSE, 0, OT_ID_PRESET, 0);
    SetMonData(&mon, MON_DATA_TERA_TYPE, &teraType);
    EXPECT_EQ(teraType, GetMonData(&mon, MON_DATA_TERA_TYPE));
}

TEST("Shininess independent from PID and OTID")
{
    u32 pid, otId, data;
    bool32 isShiny;
    struct Pokemon mon;
    PARAMETRIZE { pid = 0; otId = 0; }
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 0, TRUE, pid, OT_ID_PRESET, otId);
    isShiny = IsMonShiny(&mon);
    data = !isShiny;
    SetMonData(&mon, MON_DATA_IS_SHINY, &data);
    EXPECT_EQ(pid, GetMonData(&mon, MON_DATA_PERSONALITY));
    EXPECT_EQ(otId, GetMonData(&mon, MON_DATA_OT_ID));
    EXPECT_EQ(!isShiny, GetMonData(&mon, MON_DATA_IS_SHINY));
}

TEST("Hyper Training increases stats without affecting IVs")
{
    u32 data, hp, atk, def, speed, spatk, spdef;
    struct Pokemon mon;
    CreateMon(&mon, SPECIES_WOBBUFFET, 100, 3, TRUE, 0, OT_ID_PRESET, 0);

    hp = GetMonData(&mon, MON_DATA_HP);
    atk = GetMonData(&mon, MON_DATA_ATK);
    def = GetMonData(&mon, MON_DATA_DEF);
    speed = GetMonData(&mon, MON_DATA_SPEED);
    spatk = GetMonData(&mon, MON_DATA_SPATK);
    spdef = GetMonData(&mon, MON_DATA_SPDEF);

    data = TRUE;
    SetMonData(&mon, MON_DATA_HYPER_TRAINED_HP, &data);
    SetMonData(&mon, MON_DATA_HYPER_TRAINED_ATK, &data);
    SetMonData(&mon, MON_DATA_HYPER_TRAINED_DEF, &data);
    SetMonData(&mon, MON_DATA_HYPER_TRAINED_SPEED, &data);
    SetMonData(&mon, MON_DATA_HYPER_TRAINED_SPATK, &data);
    SetMonData(&mon, MON_DATA_HYPER_TRAINED_SPDEF, &data);
    CalculateMonStats(&mon);

    EXPECT_EQ(GetMonData(&mon, MON_DATA_HP_IV), 3);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_ATK_IV), 3);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_DEF_IV), 3);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SPEED_IV), 3);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SPATK_IV), 3);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SPDEF_IV), 3);
    EXPECT_EQ(GetMonData(&mon, MON_DATA_SPEED_IV), 3);

    EXPECT_EQ(hp - 3 + MAX_PER_STAT_IVS, GetMonData(&mon, MON_DATA_HP));
    EXPECT_EQ(atk - 3 + MAX_PER_STAT_IVS, GetMonData(&mon, MON_DATA_ATK));
    EXPECT_EQ(def - 3 + MAX_PER_STAT_IVS, GetMonData(&mon, MON_DATA_DEF));
    EXPECT_EQ(speed - 3 + MAX_PER_STAT_IVS, GetMonData(&mon, MON_DATA_SPEED));
    EXPECT_EQ(spatk - 3 + MAX_PER_STAT_IVS, GetMonData(&mon, MON_DATA_SPATK));
    EXPECT_EQ(spdef - 3 + MAX_PER_STAT_IVS, GetMonData(&mon, MON_DATA_SPDEF));
}

TEST("Status1 round-trips through BoxPokemon")
{
    u32 status1;
    struct Pokemon mon1, mon2;
    PARAMETRIZE { status1 = STATUS1_NONE; }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(1); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(2); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(3); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(4); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(5); }
    PARAMETRIZE { status1 = STATUS1_POISON; }
    PARAMETRIZE { status1 = STATUS1_BURN; }
    PARAMETRIZE { status1 = STATUS1_FREEZE; }
    PARAMETRIZE { status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { status1 = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status1 = STATUS1_FROSTBITE; }
    CreateMon(&mon1, SPECIES_WOBBUFFET, 100, 0, FALSE, 0, OT_ID_PRESET, 0);
    SetMonData(&mon1, MON_DATA_STATUS, &status1);
    BoxMonToMon(&mon1.box, &mon2);
    EXPECT_EQ(GetMonData(&mon2, MON_DATA_STATUS), status1);
}

TEST("canhypertrain/hypertrain affect MON_DATA_HYPER_TRAINED_* and recalculate stats")
{
    u32 atk;
    CreateMon(&gPlayerParty[0], SPECIES_WOBBUFFET, 100, 0, FALSE, 0, OT_ID_PRESET, 0);
    atk = GetMonData(&gPlayerParty[0], MON_DATA_ATK);

    RUN_OVERWORLD_SCRIPT(
        canhypertrain STAT_ATK, 0;
    );
    EXPECT(VarGet(VAR_RESULT));

    RUN_OVERWORLD_SCRIPT(
        hypertrain STAT_ATK, 0;
        canhypertrain STAT_ATK, 0;
    );
    EXPECT(GetMonData(&gPlayerParty[0], MON_DATA_HYPER_TRAINED_ATK));
    EXPECT_EQ(atk + 31, GetMonData(&gPlayerParty[0], MON_DATA_ATK));
    EXPECT(!VarGet(VAR_RESULT));
}

TEST("hasgigantamaxfactor/togglegigantamaxfactor affect MON_DATA_GIGANTAMAX_FACTOR")
{
    CreateMon(&gPlayerParty[0], SPECIES_WOBBUFFET, 100, 0, FALSE, 0, OT_ID_PRESET, 0);

    RUN_OVERWORLD_SCRIPT(
        hasgigantamaxfactor 0;
    );
    EXPECT(!VarGet(VAR_RESULT));

    RUN_OVERWORLD_SCRIPT(
        togglegigantamaxfactor 0;
        hasgigantamaxfactor 0;
    );
    EXPECT(VarGet(VAR_RESULT));
    EXPECT(GetMonData(&gPlayerParty[0], MON_DATA_GIGANTAMAX_FACTOR));

    RUN_OVERWORLD_SCRIPT(
        togglegigantamaxfactor 0;
        hasgigantamaxfactor 0;
    );
    EXPECT(!VarGet(VAR_RESULT));
    EXPECT(!GetMonData(&gPlayerParty[0], MON_DATA_GIGANTAMAX_FACTOR));
}

TEST("togglegigantamaxfactor fails for Melmetal")
{
    CreateMon(&gPlayerParty[0], SPECIES_MELMETAL, 100, 0, FALSE, 0, OT_ID_PRESET, 0);

    RUN_OVERWORLD_SCRIPT(
        hasgigantamaxfactor 0;
    );
    EXPECT(!VarGet(VAR_RESULT));

    RUN_OVERWORLD_SCRIPT(
        togglegigantamaxfactor 0;
    );
    EXPECT(!VarGet(VAR_RESULT));
    EXPECT(!GetMonData(&gPlayerParty[0], MON_DATA_GIGANTAMAX_FACTOR));
}

TEST("givemon [simple]")
{
    ZeroPlayerPartyMons();

    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_WOBBUFFET, 100;
    );

    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_WOBBUFFET);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_LEVEL), 100);
}

TEST("givemon [all]")
{
    ZeroPlayerPartyMons();

    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_WOBBUFFET, 100, item=ITEM_LEFTOVERS, ball=ITEM_MASTER_BALL, nature=NATURE_BOLD, abilityNum=2, gender=MON_MALE, hpEv=1, atkEv=2, defEv=3, speedEv=4, spAtkEv=5, spDefEv=6, hpIv=7, atkIv=8, defIv=9, speedIv=10, spAtkIv=11, spDefIv=12, move1=MOVE_TACKLE, move2=MOVE_SPLASH, move3=MOVE_CELEBRATE, move4=MOVE_EXPLOSION, isShiny=TRUE, ggMaxFactor=TRUE, teraType=TYPE_FIRE;
    );

    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_WOBBUFFET);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_LEVEL), 100);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM), ITEM_LEFTOVERS);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_POKEBALL), ITEM_MASTER_BALL);
    EXPECT_EQ(GetNature(&gPlayerParty[0]), NATURE_BOLD);
    EXPECT_EQ(GetMonAbility(&gPlayerParty[0]), gSpeciesInfo[SPECIES_WOBBUFFET].abilities[2]);
    EXPECT_EQ(GetMonGender(&gPlayerParty[0]), MON_MALE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HP_EV), 1);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_ATK_EV), 2);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_DEF_EV), 3);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPEED_EV), 4);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPATK_EV), 5);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPDEF_EV), 6);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HP_IV), 7);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_ATK_IV), 8);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_DEF_IV), 9);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPEED_IV), 10);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPATK_IV), 11);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPDEF_IV), 12);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE1), MOVE_TACKLE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE2), MOVE_SPLASH);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE3), MOVE_CELEBRATE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE4), MOVE_EXPLOSION);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_IS_SHINY), TRUE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_GIGANTAMAX_FACTOR), TRUE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_TERA_TYPE), TYPE_FIRE);
}

TEST("givemon [vars]")
{
    ZeroPlayerPartyMons();

    VarSet(VAR_TEMP_C, SPECIES_WOBBUFFET);
    VarSet(VAR_TEMP_D, 100);
    VarSet(VAR_0x8000, ITEM_LEFTOVERS);
    VarSet(VAR_0x8001, ITEM_MASTER_BALL);
    VarSet(VAR_0x8002, NATURE_BOLD);
    VarSet(VAR_0x8003, 2);
    VarSet(VAR_0x8004, MON_MALE);
    VarSet(VAR_0x8005, 1);
    VarSet(VAR_0x8006, 2);
    VarSet(VAR_0x8007, 3);
    VarSet(VAR_0x8008, 4);
    VarSet(VAR_0x8009, 5);
    VarSet(VAR_0x800A, 6);
    VarSet(VAR_0x800B, 7);
    VarSet(VAR_TEMP_0, 8);
    VarSet(VAR_TEMP_1, 9);
    VarSet(VAR_TEMP_2, 10);
    VarSet(VAR_TEMP_3, 11);
    VarSet(VAR_TEMP_4, 12);
    VarSet(VAR_TEMP_5, MOVE_TACKLE);
    VarSet(VAR_TEMP_6, MOVE_SPLASH);
    VarSet(VAR_TEMP_7, MOVE_CELEBRATE);
    VarSet(VAR_TEMP_8, MOVE_EXPLOSION);
    VarSet(VAR_TEMP_9, TRUE);
    VarSet(VAR_TEMP_A, TRUE);
    VarSet(VAR_TEMP_B, TYPE_FIRE);

    RUN_OVERWORLD_SCRIPT(
        givemon VAR_TEMP_C, VAR_TEMP_D, item=VAR_0x8000, ball=VAR_0x8001, nature=VAR_0x8002, abilityNum=VAR_0x8003, gender=VAR_0x8004, hpEv=VAR_0x8005, atkEv=VAR_0x8006, defEv=VAR_0x8007, speedEv=VAR_0x8008, spAtkEv=VAR_0x8009, spDefEv=VAR_0x800A, hpIv=VAR_0x800B, atkIv=VAR_TEMP_0, defIv=VAR_TEMP_1, speedIv=VAR_TEMP_2, spAtkIv=VAR_TEMP_3, spDefIv=VAR_TEMP_4, move1=VAR_TEMP_5, move2=VAR_TEMP_6, move3=VAR_TEMP_7, move4=VAR_TEMP_8, isShiny=VAR_TEMP_9, ggMaxFactor=VAR_TEMP_A, teraType=VAR_TEMP_B;
    );

    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_WOBBUFFET);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_LEVEL), 100);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM), ITEM_LEFTOVERS);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_POKEBALL), ITEM_MASTER_BALL);
    EXPECT_EQ(GetNature(&gPlayerParty[0]), NATURE_BOLD);
    EXPECT_EQ(GetMonAbility(&gPlayerParty[0]), gSpeciesInfo[SPECIES_WOBBUFFET].abilities[2]);
    EXPECT_EQ(GetMonGender(&gPlayerParty[0]), MON_MALE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HP_EV), 1);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_ATK_EV), 2);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_DEF_EV), 3);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPEED_EV), 4);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPATK_EV), 5);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPDEF_EV), 6);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_HP_IV), 7);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_ATK_IV), 8);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_DEF_IV), 9);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPEED_IV), 10);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPATK_IV), 11);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPDEF_IV), 12);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE1), MOVE_TACKLE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE2), MOVE_SPLASH);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE3), MOVE_CELEBRATE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_MOVE4), MOVE_EXPLOSION);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_IS_SHINY), TRUE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_GIGANTAMAX_FACTOR), TRUE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_TERA_TYPE), TYPE_FIRE);
}
