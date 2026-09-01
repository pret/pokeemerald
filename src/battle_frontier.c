#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_frontier.h"
#include "battle_setup.h"
#include "battle_dome.h"
#include "battle_factory.h"
#include "battle_partner.h"
#include "battle_tower.h"
#include "battle_transition.h"
#include "event_data.h"
#include "frontier_util.h"
#include "overworld.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trainer_util.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"

static void FillTrainerParty(u16 trainerId, enum BattleTrainer trainer, u8 monCount);

// EWRAM vars.
EWRAM_DATA const struct BattleFrontierTrainer *gFacilityTrainers = NULL;
EWRAM_DATA const struct TrainerMon *gFacilityTrainerMons = NULL;

// IWRAM common
COMMON_DATA u16 gFrontierTempParty[MAX_FRONTIER_PARTY_SIZE] = {0};

static void HandleFacilityTrainerBattleEnd(void)
{
    u8 facility = gBattleScripting.specialTrainerBattleType;
    switch (facility)
    {
    case FACILITY_BATTLE_TOWER:
    case FACILITY_BATTLE_DOME:
    case FACILITY_BATTLE_PALACE:
    case FACILITY_BATTLE_ARENA:
    case FACILITY_BATTLE_FACTORY:
    case FACILITY_BATTLE_PIKE_SINGLE:
    case FACILITY_BATTLE_PIKE_DOUBLE:
    case FACILITY_BATTLE_PYRAMID:
        if (gSaveBlock2Ptr->frontier.battlesCount < 0xFFFFFF)
        {
            gSaveBlock2Ptr->frontier.battlesCount++;
            if (gSaveBlock2Ptr->frontier.battlesCount % 20 == 0)
                UpdateGymLeaderRematch();
        }
        else
        {
            gSaveBlock2Ptr->frontier.battlesCount = 0xFFFFFF;
        }
        break;
    case FACILITY_BATTLE_TRAINER_HILL:
    default:
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static void Task_StartBattleAfterTransition(u8 taskId)
{
    if (IsBattleTransitionDone() == TRUE)
    {
        gMain.savedCallback = HandleFacilityTrainerBattleEnd;
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

static void DoFacilityTrainerBattleInternal(u8 facility)
{
    gBattleScripting.specialTrainerBattleType = facility;

    switch (facility)
    {
    case FACILITY_BATTLE_TOWER:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        switch (VarGet(VAR_FRONTIER_BATTLE_MODE))
        {
        case FRONTIER_MODE_SINGLES:
            FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
            break;
        case FRONTIER_MODE_DOUBLES:
            FillFrontierTrainerParty(FRONTIER_DOUBLES_PARTY_SIZE);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
            break;
        case FRONTIER_MODE_MULTIS:
            FillFrontierTrainersParties(FRONTIER_MULTI_PARTY_SIZE);
            gPartnerTrainerId = gSaveBlock2Ptr->frontier.trainerIds[17];
            FillPartnerParty(gPartnerTrainerId);
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS;
            break;
        case FRONTIER_MODE_LINK_MULTIS:
            gBattleTypeFlags |= BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_MULTI | BATTLE_TYPE_TOWER_LINK_MULTI;
            FillFrontierTrainersParties(FRONTIER_MULTI_PARTY_SIZE);
            break;
        }
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_TOWER));
        break;
    case FACILITY_BATTLE_DOME:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOME;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
        FillFrontierTrainerParty(DOME_BATTLE_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        CreateTask_PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_DOME));
        break;
    case FACILITY_BATTLE_PALACE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        else
        FillTentTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PALACE));
        break;
    case FACILITY_BATTLE_ARENA:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_ARENA;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        else
        FillTentTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_ARENA));
        break;
    case FACILITY_BATTLE_FACTORY:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_FACTORY;
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        gBattleTypeFlags |= BATTLE_TYPE_DOUBLE;
        FillFactoryTrainerParty();
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_FACTORY));
        break;
    case FACILITY_BATTLE_PIKE_SINGLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PIKE));
        break;
    case FACILITY_BATTLE_PIKE_DOUBLE:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS;
        FillFrontierTrainersParties(1);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PIKE));
        break;
    case FACILITY_BATTLE_PYRAMID:
        gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_PYRAMID;
        FillFrontierTrainerParty(FRONTIER_PARTY_SIZE);
        CreateTask(Task_StartBattleAfterTransition, 1);
        PlayMapChosenOrBattleBGM(0);
        BattleTransition_StartOnField(GetSpecialBattleTransition(B_TRANSITION_GROUP_B_PYRAMID));
        break;
    case FACILITY_BATTLE_TRAINER_HILL:
    default:
        break;
    }
}

void DoFacilityTrainerBattle(struct ScriptContext *ctx)
{
    u8 facility = ScriptReadByte(ctx);

    DoFacilityTrainerBattleInternal(facility);
}

void FacilityTrainerBattle(struct ScriptContext *ctx)
{
    u8 facility = ScriptReadByte(ctx);

    ConfigureFacilityTrainerBattle(facility, ctx->scriptPtr);
}

void FillFrontierTrainerParty(u8 monsCount)
{
    ZeroEnemyPartyMons();
    FillTrainerParty(TRAINER_BATTLE_PARAM.opponentA, B_TRAINER_OPPONENT_A, monsCount);
}

void FillFrontierTrainersParties(u8 monsCount)
{
    ZeroEnemyPartyMons();
    FillTrainerParty(TRAINER_BATTLE_PARAM.opponentA, B_TRAINER_OPPONENT_A, monsCount);
    FillTrainerParty(TRAINER_BATTLE_PARAM.opponentB, B_TRAINER_OPPONENT_B, monsCount);
}

static void FillTrainerParty(u16 trainerId, enum BattleTrainer trainer, u8 monCount)
{
    s32 i, j;
    u16 chosenMonIndices[MAX_FRONTIER_PARTY_SIZE];
    u8 level = SetFacilityPtrsGetLevel();
    u8 fixedIV = 0;
    u8 bfMonCount;
    const u16 *monSet = NULL;
    u32 otID = 0;

    if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        // Normal battle frontier trainer.
        fixedIV = GetFrontierTrainerFixedIvs(trainerId);
        monSet = gFacilityTrainers[trainerId].monSet;
    }
    else if (trainerId == TRAINER_EREADER)
    {
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            CreateBattleTowerMon(&gParties[trainer][i], &gSaveBlock2Ptr->frontier.ereaderTrainer.party[i]);
    #endif //FREE_BATTLE_TOWER_E_READER
        return;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CreateFrontierBrainPokemon();
        return;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        // Record mixed player.
        for (j = 0, i = 0; i < monCount; j++, i++)
        {
            if (gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j].species != SPECIES_NONE
                && gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j].level <= level)
            {
                CreateBattleTowerMon_HandleLevel(&gParties[trainer][i], &gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].party[j], FALSE);
            }
        }
        return;
    }
    else
    {
        // Apprentice.
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
            CreateApprenticeMon(&gParties[trainer][i], &gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE], i);
        return;
    }

    // Regular battle frontier trainer.
    // Attempt to fill the trainer's party with random Pokémon until 3 have been
    // successfully chosen. The trainer's party may not have duplicate Pokémon species
    // or duplicate held items.
    for (bfMonCount = 0; monSet[bfMonCount] != 0xFFFF; bfMonCount++)
        ;
    i = 0;
    otID = Random32();
    while (i != monCount)
    {
        u16 monId = monSet[Random() % bfMonCount];

        // "High tier" Pokémon are only allowed on open level mode
        // 20 is not a possible value for level here
        if ((level == FRONTIER_MAX_LEVEL_50 || level == 20) && monId > FRONTIER_MONS_HIGH_TIER)
            continue;

        // Ensure this Pokémon species isn't a duplicate.
        for (j = 0; j < i; j++)
        {
            if (GetMonData(&gParties[trainer][j], MON_DATA_SPECIES) == gFacilityTrainerMons[monId].species)
                break;
        }
        if (j != i)
            continue;

        // Ensure this Pokemon's held item isn't a duplicate.
        for (j = 0; j < i; j++)
        {
            if (GetMonData(&gParties[trainer][j], MON_DATA_HELD_ITEM) != ITEM_NONE
             && GetMonData(&gParties[trainer][j], MON_DATA_HELD_ITEM) == gFacilityTrainerMons[monId].heldItem)
                break;
        }
        if (j != i)
            continue;

        // Ensure this exact Pokémon index isn't a duplicate. This check doesn't seem necessary
        // because the species and held items were already checked directly above.
        for (j = 0; j < i; j++)
        {
            if (chosenMonIndices[j] == monId)
                break;
        }
        if (j != i)
            continue;

        chosenMonIndices[i] = monId;

        // Place the chosen Pokémon into the trainer's party.
        CreateFacilityMon(&gFacilityTrainerMons[monId], level, fixedIV, otID, 0, &gParties[trainer][i]);

        // The Pokémon was successfully added to the trainer's party, so it's safe to move on to
        // the next party slot.
        i++;
    }
}

void CreateFacilityMon(const struct TrainerMon *fmon, u16 level, u8 fixedIV, u32 otID, u32 flags, struct Pokemon *dst)
{
    enum PokeBall ball = (fmon->ball == 0xFF) ? Random() % POKEBALL_COUNT : fmon->ball;
    enum Move move;
    u32 personality = 0, friendship, j;
    enum Ability ability;

    if (fmon->gender == TRAINER_MON_MALE)
    {
        personality = GeneratePersonalityForGender(MON_MALE, fmon->species);
    }
    else if (fmon->gender == TRAINER_MON_FEMALE)
    {
        personality = GeneratePersonalityForGender(MON_FEMALE, fmon->species);
    }

    ModifyPersonalityForNature(&personality, fmon->nature);
    CreateMonWithIVs(dst, fmon->species, level, personality, OTID_STRUCT_PRESET(otID), fixedIV);

    friendship = MAX_FRIENDSHIP;
    // Give the chosen Pokémon its specified moves.
    for (j = 0; j < MAX_MON_MOVES; j++)
    {
        move = fmon->moves[j];
        if (flags & FLAG_FRONTIER_MON_FACTORY && move == MOVE_RETURN)
            move = MOVE_FRUSTRATION;

        SetMonMoveSlot(dst, move, j);
        if (GetMoveEffect(move) == EFFECT_FRUSTRATION)
            friendship = 0;  // Frustration is more powerful the lower the Pokémon's friendship is.
    }

    SetMonData(dst, MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(dst, MON_DATA_HELD_ITEM, &fmon->heldItem);

    // try to set ability. Otherwise, random of non-hidden as per vanilla
    if (fmon->ability != ABILITY_NONE)
    {
        const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[fmon->species];
        u32 maxAbilities = ARRAY_COUNT(speciesInfo->abilities);
        for (ability = 0; ability < maxAbilities; ++ability)
        {
            if (speciesInfo->abilities[ability] == fmon->ability)
                break;
        }
        if (ability >= maxAbilities)
            ability = 0;
        SetMonData(dst, MON_DATA_ABILITY_NUM, &ability);
    }

    if (fmon->ev != NULL)
    {
        SetMonData(dst, MON_DATA_HP_EV, &(fmon->ev[0]));
        SetMonData(dst, MON_DATA_ATK_EV, &(fmon->ev[1]));
        SetMonData(dst, MON_DATA_DEF_EV, &(fmon->ev[2]));
        SetMonData(dst, MON_DATA_SPATK_EV, &(fmon->ev[3]));
        SetMonData(dst, MON_DATA_SPDEF_EV, &(fmon->ev[4]));
        SetMonData(dst, MON_DATA_SPEED_EV, &(fmon->ev[5]));
    }

    if (fmon->iv)
        SetMonData(dst, MON_DATA_IVS, &(fmon->iv));

    if (fmon->isShiny)
    {
        u32 data = TRUE;
        SetMonData(dst, MON_DATA_IS_SHINY, &data);
    }
    if (fmon->dynamaxLevel > 0)
    {
        u32 data = fmon->dynamaxLevel;
        SetMonData(dst, MON_DATA_DYNAMAX_LEVEL, &data);
    }
    if (fmon->gigantamaxFactor)
    {
        u32 data = fmon->gigantamaxFactor;
        SetMonData(dst, MON_DATA_GIGANTAMAX_FACTOR, &data);
    }
    if (fmon->teraType)
    {
        u32 data = fmon->teraType;
        SetMonData(dst, MON_DATA_TERA_TYPE, &data);
    }


    SetMonData(dst, MON_DATA_POKEBALL, &ball);
    CalculateMonStats(dst);
}
