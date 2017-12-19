#include "global.h"
#include "battle.h"
#include "recorded_battle.h"
#include "main.h"
#include "pokemon.h"
#include "random.h"
#include "event_data.h"
#include "link.h"
#include "string_util.h"
#include "palette.h"
#include "save.h"
#include "malloc.h"
#include "util.h"
#include "task.h"
#include "text.h"

#define BANK_RECORD_SIZE 664
#define ILLEGAL_BATTLE_TYPES ((BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_FIRST_BATTLE                  \
                              | BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_ROAMER | BATTLE_TYPE_EREADER_TRAINER   \
                              | BATTLE_TYPE_KYOGRE_GROUDON | BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_REGI           \
                              | BATTLE_TYPE_RECORDED | BATTLE_TYPE_x4000000 | BATTLE_TYPE_SECRET_BASE           \
                              | BATTLE_TYPE_GROUDON | BATTLE_TYPE_KYOGRE | BATTLE_TYPE_RAYQUAZA))

extern u32 gBattleTypeFlags;
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern u16 gPartnerTrainerId;
extern u8 gActiveBank;
extern u8 gNoOfAllBanks;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern u16 gChosenMovesByBanks[BATTLE_BANKS_COUNT];
extern u8 gUnknown_03001278;
extern u8 gUnknown_03001279;

struct PlayerInfo
{
    u32 trainerId;
    u8 name[PLAYER_NAME_LENGTH];
    u8 gender;
    u16 bank;
    u16 language;
};

struct MovePp
{
    u16 moves[4];
    u8 pp[4];
};

struct RecordedBattleSave
{
    struct Pokemon playerParty[PARTY_SIZE];
    struct Pokemon opponentParty[PARTY_SIZE];
    u8 playersName[BATTLE_BANKS_COUNT][PLAYER_NAME_LENGTH];
    u8 playersGender[BATTLE_BANKS_COUNT];
    u32 playersTrainerId[BATTLE_BANKS_COUNT];
    u8 playersLanguage[BATTLE_BANKS_COUNT];
    u32 rngSeed;
    u32 battleFlags;
    u8 playersBank[BATTLE_BANKS_COUNT];
    u16 opponentA;
    u16 opponentB;
    u16 partnerId;
    u16 field_4FA;
    u8 field_4FC;
    u8 field_4FD;
    u8 field_4FE;
    u8 battleStyle : 1;
    u8 textSpeed : 3;
    u32 AI_scripts;
    u8 field_504[8];
    u8 field_50C;
    u8 field_50D;
    u16 field_50E[6];
    u8 field_51A;
    u8 field_51B;
    u8 battleRecord[BATTLE_BANKS_COUNT][BANK_RECORD_SIZE];
    u32 checksum;
};

EWRAM_DATA u32 gRecordedBattleRngSeed = 0;
EWRAM_DATA u32 gBattlePalaceMoveSelectionRngValue = 0;
EWRAM_DATA static u8 sBattleRecords[BATTLE_BANKS_COUNT][BANK_RECORD_SIZE] = {0};
EWRAM_DATA static u16 sRecordedBytesNo[BATTLE_BANKS_COUNT] = {0};
EWRAM_DATA static u16 sUnknown_0203C79C[4] = {0};
EWRAM_DATA static u16 sUnknown_0203C7A4[4] = {0};
EWRAM_DATA static u8 sUnknown_0203C7AC = 0;
EWRAM_DATA static u8 sUnknown_0203C7AD = 0;
EWRAM_DATA static u8 sUnknown_0203C7AE = 0;
EWRAM_DATA static u8 sUnknown_0203C7AF = 0;
EWRAM_DATA static MainCallback sCallback2_AfterRecordedBattle = NULL;
EWRAM_DATA u8 gUnknown_0203C7B4 = 0;
EWRAM_DATA static u8 sUnknown_0203C7B5 = 0;
EWRAM_DATA static u8 sRecordedBattle_BattleStyle = 0;
EWRAM_DATA static u8 sRecordedBattle_TextSpeed = 0;
EWRAM_DATA static u32 sRecordedBattle_BattleFlags = 0;
EWRAM_DATA static u32 sRecordedBattle_AI_Scripts = 0;
EWRAM_DATA static struct Pokemon sSavedPlayerParty[PARTY_SIZE] = {0};
EWRAM_DATA static struct Pokemon sSavedOpponentParty[PARTY_SIZE] = {0};
EWRAM_DATA static u16 sRecordedBattle_PlayerMonMoves[2][4] = {0};
EWRAM_DATA static struct PlayerInfo sRecordedBattle_Players[BATTLE_BANKS_COUNT] = {0};
EWRAM_DATA static u8 sUnknown_0203CCD0 = 0;
EWRAM_DATA static u8 sUnknown_0203CCD1[8] = {0};
EWRAM_DATA static u8 sUnknown_0203CCD9 = 0;
EWRAM_DATA static u8 sUnknown_0203CCDA = 0;
EWRAM_DATA static u16 sUnknown_0203CCDC[6] = {0};
EWRAM_DATA static u8 sUnknown_0203CCE8 = 0;

extern u32 sub_81A513C(void);
extern void PlayMapChosenOrBattleBGM(bool8);

// this file's functions
static u8 sub_8185278(u8 *arg0, u8 *arg1, u8 *arg2);
static bool32 AllocTryCopyRecordedBattleSaveData(struct RecordedBattleSave *dst);
static void RecordedBattle_RestoreSavedParties(void);
static void CB2_RecordedBattle(void);

void sub_8184DA4(u8 arg0)
{
    s32 i, j;

    sUnknown_0203C7AC = arg0;
    sUnknown_0203CCD0 = 0;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        sRecordedBytesNo[i] = 0;
        sUnknown_0203C79C[i] = 0;
        sUnknown_0203C7A4[i] = 0;

        if (arg0 == 1)
        {
            for (j = 0; j < BANK_RECORD_SIZE; j++)
            {
                sBattleRecords[i][j] |= 0xFF;
            }
            sRecordedBattle_BattleFlags = gBattleTypeFlags;
            sRecordedBattle_AI_Scripts = gBattleResources->ai->aiFlags;
        }
    }
}

void sub_8184E58(void)
{
    s32 i, j;

    if (sUnknown_0203C7AC == 1)
    {
        gRecordedBattleRngSeed = gRngValue;
        sUnknown_0203C7AE = VarGet(VAR_FRONTIER_FACILITY);
        sUnknown_0203C7AF = sub_81A513C();
    }
    else if (sUnknown_0203C7AC == 2)
    {
        gRngValue = gRecordedBattleRngSeed;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 linkPlayersCount;
        u8 text[30];

        gUnknown_0203C7B4 = GetMultiplayerId();
        linkPlayersCount = GetLinkPlayerCount();

        for (i = 0; i < BATTLE_BANKS_COUNT; i++)
        {
            sRecordedBattle_Players[i].trainerId = gLinkPlayers[i].trainerId;
            sRecordedBattle_Players[i].gender = gLinkPlayers[i].gender;
            sRecordedBattle_Players[i].bank = gLinkPlayers[i].lp_field_18;
            sRecordedBattle_Players[i].language = gLinkPlayers[i].language;

            if (i < linkPlayersCount)
            {
                StringCopy(text, gLinkPlayers[i].name);
                StripExtCtrlCodes(text);
                StringCopy(sRecordedBattle_Players[i].name, text);
            }
            else
            {
                for (j = 0; j < PLAYER_NAME_LENGTH; j++)
                    sRecordedBattle_Players[i].name[j] = gLinkPlayers[i].name[j];
            }
        }
    }
    else
    {
        sRecordedBattle_Players[0].trainerId = (gSaveBlock2Ptr->playerTrainerId[0])
                                    | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
                                    | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
                                    | (gSaveBlock2Ptr->playerTrainerId[3] << 24);

        sRecordedBattle_Players[0].gender = gSaveBlock2Ptr->playerGender;
        sRecordedBattle_Players[0].bank = 0;
        sRecordedBattle_Players[0].language = gGameLanguage;

        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            sRecordedBattle_Players[0].name[i] = gSaveBlock2Ptr->playerName[i];
    }
}

void RecordedBattle_SetBankAction(u8 bank, u8 action)
{
    if (sRecordedBytesNo[bank] < BANK_RECORD_SIZE && sUnknown_0203C7AC != 2)
    {
        sBattleRecords[bank][sRecordedBytesNo[bank]++] = action;
    }
}

void RecordedBattle_ClearBankAction(u8 bank, u8 bytesToClear)
{
    s32 i;

    for (i = 0; i < bytesToClear; i++)
    {
        sRecordedBytesNo[bank]--;
        sBattleRecords[bank][sRecordedBytesNo[bank]] |= 0xFF;
        if (sRecordedBytesNo[bank] == 0)
            break;
    }
}

u8 RecordedBattle_ReadBankAction(u8 bank)
{
    // trying to read past array or invalid action byte, battle is over
    if (sRecordedBytesNo[bank] >= BANK_RECORD_SIZE || sBattleRecords[bank][sRecordedBytesNo[bank]] == 0xFF)
    {
        gSpecialVar_Result = gBattleOutcome = BATTLE_PLAYER_TELEPORTED; // hah
        ResetPaletteFadeControl();
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        SetMainCallback2(CB2_QuitRecordedBattle);
        return -1;
    }
    else
    {
        return sBattleRecords[bank][sRecordedBytesNo[bank]++];
    }
}

u8 sub_81850D0(void)
{
    return sUnknown_0203C7AC;
}

u8 sub_81850DC(u8 *arg0)
{
    u8 i, j;
    u8 ret = 0;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        if (sRecordedBytesNo[i] != sUnknown_0203C79C[i])
        {
            arg0[ret++] = i;
            arg0[ret++] = sRecordedBytesNo[i] - sUnknown_0203C79C[i];

            for (j = 0; j < sRecordedBytesNo[i] - sUnknown_0203C79C[i]; j++)
            {
                arg0[ret++] = sBattleRecords[i][sUnknown_0203C79C[i] + j];
            }

            sUnknown_0203C79C[i] = sRecordedBytesNo[i];
        }
    }

    return ret;
}

void sub_81851A8(u8 *arg0)
{
    s32 i;
    u8 var1 = 2;
    u8 var2;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        if ((gLinkPlayers[i].version & 0xFF) != VERSION_EMERALD)
            return;
    }

    if (!(gBattleTypeFlags & BATTLE_TYPE_WILD))
    {
        for (var2 = *arg0; var2 != 0;)
        {
            u8 unkVar = sub_8185278(arg0, &var1, &var2);
            u8 unkVar2 = sub_8185278(arg0, &var1, &var2);

            for (i = 0; i < unkVar2; i++)
            {
                sBattleRecords[unkVar][sUnknown_0203C7A4[unkVar]++] = sub_8185278(arg0, &var1, &var2);
            }
        }
    }
}

static u8 sub_8185278(u8 *arg0, u8 *arg1, u8 *arg2)
{
    (*arg2)--;
    return arg0[(*arg1)++];
}

bool32 CanCopyRecordedBattleSaveData(void)
{
    struct RecordedBattleSave *dst = AllocZeroed(sizeof(struct RecordedBattleSave));
    bool32 ret = AllocTryCopyRecordedBattleSaveData(dst);
    Free(dst);
    return ret;
}

static bool32 IsRecordedBattleSaveValid(struct RecordedBattleSave *save)
{
    if (save->battleFlags == 0)
        return FALSE;
    if (save->battleFlags & ILLEGAL_BATTLE_TYPES)
        return FALSE;
    if (CalcByteArraySum((void*)(save), sizeof(*save) - 4) != save->checksum)
        return FALSE;

    return TRUE;
}

static bool32 sub_81852F0(struct RecordedBattleSave *battleSave, struct RecordedBattleSave *saveSection)
{
    memset(saveSection, 0, sizeof(struct SaveSection));
    memcpy(saveSection, battleSave, sizeof(*battleSave));

    saveSection->checksum = CalcByteArraySum((void*)(saveSection), sizeof(*saveSection) - 4);

    if (sub_8153634(31, (void*)(saveSection)) != 1)
        return FALSE;

    return TRUE;
}

#ifdef NONMATCHING
u32 MoveRecordedBattleToSaveData(void)
{
    s32 i, j;
    u8 var = 0;
    struct RecordedBattleSave *battleSave = AllocZeroed(sizeof(struct RecordedBattleSave));
    struct SaveSection *savSection = AllocZeroed(sizeof(struct SaveSection));

    for (i = 0; i < PARTY_SIZE; i++)
    {
        battleSave->playerParty[i] = sSavedPlayerParty[i];
        battleSave->opponentParty[i] = sSavedOpponentParty[i];
    }

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        for (j = 0; j < PLAYER_NAME_LENGTH; j++)
        {
            battleSave->playersName[i][j] = sRecordedBattle_Players[i].name[j];
        }
        battleSave->playersGender[i] = sRecordedBattle_Players[i].gender;
        battleSave->playersLanguage[i] = sRecordedBattle_Players[i].language;
        battleSave->playersBank[i] = sRecordedBattle_Players[i].bank;
        battleSave->playersTrainerId[i] = sRecordedBattle_Players[i].trainerId;
    }

    battleSave->rngSeed = gRecordedBattleRngSeed;

    if (sRecordedBattle_BattleFlags & BATTLE_TYPE_LINK)
    {
        battleSave->battleFlags = (sRecordedBattle_BattleFlags & ~(BATTLE_TYPE_LINK | BATTLE_TYPE_20));
        battleSave->battleFlags |= BATTLE_TYPE_x2000000;

        if (sRecordedBattle_BattleFlags & BATTLE_TYPE_WILD)
        {
            battleSave->battleFlags |= BATTLE_TYPE_x80000000;
        }
        else if (sRecordedBattle_BattleFlags & BATTLE_TYPE_MULTI)
        {
            switch (sRecordedBattle_Players[0].bank)
            {
            case 0:
            case 2:
                if (!(sRecordedBattle_Players[gUnknown_0203C7B4].bank & 1))
                    battleSave->battleFlags |= BATTLE_TYPE_x80000000;
                break;
            case 1:
            case 3:
                if ((sRecordedBattle_Players[gUnknown_0203C7B4].bank & 1))
                    battleSave->battleFlags |= BATTLE_TYPE_x80000000;
                break;
            }
        }
    }
    else
    {
        battleSave->battleFlags = sRecordedBattle_BattleFlags;
    }

    battleSave->opponentA = gTrainerBattleOpponent_A;
    battleSave->opponentB = gTrainerBattleOpponent_B;
    battleSave->partnerId = gPartnerTrainerId;
    battleSave->field_4FA = gUnknown_0203C7B4;
    battleSave->field_4FC = gSaveBlock2Ptr->field_CA9_b;
    battleSave->field_4FD = sUnknown_0203C7AE;
    battleSave->field_4FE = sUnknown_0203C7AF;
    battleSave->battleStyle = gSaveBlock2Ptr->optionsBattleStyle;
    battleSave->textSpeed = gSaveBlock2Ptr->optionsTextSpeed;
    battleSave->AI_scripts = sRecordedBattle_AI_Scripts;

    /* Can't match it without proper knowledge of the Saveblock 2.
    if (gTrainerBattleOpponent_A >= 300 && gTrainerBattleOpponent_A <= 399)
    {
        for (i = 0; i < 8; i++)
        {
            battleSave->field_504[i] = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_A - 300].field_4[i];
        }
        battleSave->field_50C = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_A - 300].field_1;

        if (sUnknown_0203CCE8 == 1)
        {
            for (i = 0; i < 6; i++)
            {
                battleSave->field_50E[i] = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_A - 300].field_28[i];
            }
        }
        else
        {
            for (i = 0; i < 6; i++)
            {
                battleSave->field_50E[i] = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_A - 300].field_1C[i];
            }
        }
        battleSave->field_51A = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_A - 300].field_E4;
    }
    else if (gTrainerBattleOpponent_B >= 300 && gTrainerBattleOpponent_B <= 399)
    {
        for (i = 0; i < 8; i++)
        {
            battleSave->field_504[i] = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_B - 300].field_4[i];
        }
        battleSave->field_50C = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_B - 300].field_1;

        if (sUnknown_0203CCE8 == 1)
        {
            for (i = 0; i < 6; i++)
            {
                battleSave->field_50E[i] = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_B - 300].field_28[i];
            }
        }
        else
        {
            for (i = 0; i < 6; i++)
            {
                battleSave->field_50E[i] = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_B - 300].field_1C[i];
            }
        }
        battleSave->field_51A = gSaveBlock2Ptr->field_738[gTrainerBattleOpponent_B - 300].field_E4;
    }
    else if (gPartnerTrainerId >= 300 && gPartnerTrainerId <= 399)
    {
        for (i = 0; i < 8; i++)
        {
            battleSave->field_504[i] = gSaveBlock2Ptr->field_738[gPartnerTrainerId - 300].field_4[i];
        }
        battleSave->field_50C = gSaveBlock2Ptr->field_738[gPartnerTrainerId - 300].field_1;

        if (sUnknown_0203CCE8 == 1)
        {
            for (i = 0; i < 6; i++)
            {
                battleSave->field_50E[i] = gSaveBlock2Ptr->field_738[gPartnerTrainerId - 300].field_28[i];
            }
        }
        else
        {
            for (i = 0; i < 6; i++)
            {
                battleSave->field_50E[i] = gSaveBlock2Ptr->field_738[gPartnerTrainerId - 300].field_1C[i];
            }
        }
        battleSave->field_51A = gSaveBlock2Ptr->field_738[gPartnerTrainerId - 300].field_E4;
    }

    */
}

#else
__attribute__((naked))
u32 MoveRecordedBattleToSaveData(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0xC\n\
	movs r0, 0\n\
	str r0, [sp, 0x4]\n\
	movs r0, 0xF8\n\
	lsls r0, 4\n\
	bl AllocZeroed\n\
	adds r7, r0, 0\n\
	movs r0, 0x80\n\
	lsls r0, 5\n\
	bl AllocZeroed\n\
	str r0, [sp]\n\
	movs r6, 0\n\
_0818535E:\n\
	movs r0, 0x64\n\
	adds r4, r6, 0\n\
	muls r4, r0\n\
	adds r5, r7, r4\n\
	ldr r1, =sSavedPlayerParty\n\
	adds r1, r4, r1\n\
	adds r0, r5, 0\n\
	movs r2, 0x64\n\
	bl memcpy\n\
	movs r1, 0x96\n\
	lsls r1, 2\n\
	adds r5, r1\n\
	ldr r0, =sSavedOpponentParty\n\
	adds r4, r0\n\
	adds r0, r5, 0\n\
	adds r1, r4, 0\n\
	movs r2, 0x64\n\
	bl memcpy\n\
	adds r6, 0x1\n\
	cmp r6, 0x5\n\
	ble _0818535E\n\
	movs r6, 0\n\
	ldr r2, =gSaveBlock2Ptr\n\
	mov r9, r2\n\
	movs r3, 0x9A\n\
	lsls r3, 3\n\
	adds r3, r7, r3\n\
	str r3, [sp, 0x8]\n\
	ldr r5, =sRecordedBattle_Players\n\
	mov r8, r6\n\
	mov r12, r6\n\
	movs r4, 0x96\n\
	lsls r4, 3\n\
	adds r4, r7\n\
	mov r10, r4\n\
	ldr r0, =0x000004e4\n\
	adds r4, r7, r0\n\
_081853AC:\n\
	lsls r1, r6, 3\n\
	ldr r0, =sRecordedBattle_Players\n\
	adds r0, 0x4\n\
	mov r3, r8\n\
	adds r2, r3, r0\n\
	add r1, r10\n\
	movs r3, 0x7\n\
_081853BA:\n\
	ldrb r0, [r2]\n\
	strb r0, [r1]\n\
	adds r2, 0x1\n\
	adds r1, 0x1\n\
	subs r3, 0x1\n\
	cmp r3, 0\n\
	bge _081853BA\n\
	ldr r0, [sp, 0x8]\n\
	adds r1, r0, r6\n\
	ldrb r0, [r5, 0xC]\n\
	strb r0, [r1]\n\
	ldrh r0, [r5, 0x10]\n\
	strb r0, [r4]\n\
	ldrh r0, [r5, 0xE]\n\
	strb r0, [r4, 0xC]\n\
	ldr r1, =0x000004d4\n\
	adds r0, r7, r1\n\
	add r0, r12\n\
	ldr r1, [r5]\n\
	str r1, [r0]\n\
	adds r5, 0x14\n\
	movs r2, 0x14\n\
	add r8, r2\n\
	movs r3, 0x4\n\
	add r12, r3\n\
	adds r4, 0x1\n\
	adds r6, 0x1\n\
	cmp r6, 0x3\n\
	ble _081853AC\n\
	movs r4, 0x9D\n\
	lsls r4, 3\n\
	adds r1, r7, r4\n\
	ldr r5, =gRecordedBattleRngSeed\n\
	ldr r0, [r5]\n\
	str r0, [r1]\n\
	ldr r0, =sRecordedBattle_BattleFlags\n\
	ldr r2, [r0]\n\
	movs r0, 0x2\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	beq _081854DC\n\
	ldr r1, =0x000004ec\n\
	adds r3, r7, r1\n\
	movs r1, 0x23\n\
	negs r1, r1\n\
	ands r1, r2\n\
	movs r0, 0x80\n\
	lsls r0, 18\n\
	orrs r1, r0\n\
	str r1, [r3]\n\
	movs r0, 0x4\n\
	ands r0, r2\n\
	cmp r0, 0\n\
	beq _08185454\n\
	movs r0, 0x80\n\
	lsls r0, 24\n\
	orrs r1, r0\n\
	str r1, [r3]\n\
	b _081854E2\n\
	.pool\n\
_08185454:\n\
	movs r0, 0x40\n\
	ands r2, r0\n\
	cmp r2, 0\n\
	beq _081854E2\n\
	ldr r2, =sRecordedBattle_Players\n\
	ldrh r0, [r2, 0xE]\n\
	cmp r0, 0x1\n\
	beq _081854A8\n\
	cmp r0, 0x1\n\
	bgt _08185474\n\
	cmp r0, 0\n\
	beq _0818547E\n\
	b _081854E2\n\
	.pool\n\
_08185474:\n\
	cmp r0, 0x2\n\
	beq _0818547E\n\
	cmp r0, 0x3\n\
	beq _081854A8\n\
	b _081854E2\n\
_0818547E:\n\
	ldr r3, =gUnknown_0203C7B4\n\
	ldrb r1, [r3]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	ldr r4, =sRecordedBattle_Players\n\
	adds r0, r4\n\
	ldrh r1, [r0, 0xE]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _081854E2\n\
	ldr r5, =0x000004ec\n\
	adds r0, r7, r5\n\
	b _081854C4\n\
	.pool\n\
_081854A8:\n\
	ldr r0, =gUnknown_0203C7B4\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	ldr r1, =sRecordedBattle_Players\n\
	adds r0, r1\n\
	ldrh r1, [r0, 0xE]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _081854E2\n\
	ldr r2, =0x000004ec\n\
	adds r0, r7, r2\n\
_081854C4:\n\
	ldr r1, [r0]\n\
	movs r2, 0x80\n\
	lsls r2, 24\n\
	orrs r1, r2\n\
	str r1, [r0]\n\
	b _081854E2\n\
	.pool\n\
_081854DC:\n\
	ldr r3, =0x000004ec\n\
	adds r0, r7, r3\n\
	str r2, [r0]\n\
_081854E2:\n\
	ldr r4, =gTrainerBattleOpponent_A\n\
	ldrh r1, [r4]\n\
	ldr r5, =0x000004f4\n\
	adds r0, r7, r5\n\
	strh r1, [r0]\n\
	ldr r0, =gTrainerBattleOpponent_B\n\
	ldrh r1, [r0]\n\
	ldr r2, =0x000004f6\n\
	adds r0, r7, r2\n\
	strh r1, [r0]\n\
	ldr r3, =gPartnerTrainerId\n\
	ldrh r1, [r3]\n\
	movs r4, 0x9F\n\
	lsls r4, 3\n\
	adds r0, r7, r4\n\
	strh r1, [r0]\n\
	ldr r5, =gUnknown_0203C7B4\n\
	ldrb r1, [r5]\n\
	adds r2, 0x4\n\
	adds r0, r7, r2\n\
	strh r1, [r0]\n\
	mov r3, r9\n\
	ldr r0, [r3]\n\
	ldr r4, =0x00000ca9\n\
	adds r0, r4\n\
	ldrb r0, [r0]\n\
	lsls r0, 30\n\
	lsrs r0, 30\n\
	ldr r5, =0x000004fc\n\
	adds r1, r7, r5\n\
	strb r0, [r1]\n\
	ldr r0, =sUnknown_0203C7AE\n\
	ldrb r1, [r0]\n\
	adds r2, 0x3\n\
	adds r0, r7, r2\n\
	strb r1, [r0]\n\
	ldr r3, =sUnknown_0203C7AF\n\
	ldrb r1, [r3]\n\
	ldr r4, =0x000004fe\n\
	adds r0, r7, r4\n\
	strb r1, [r0]\n\
	mov r5, r9\n\
	ldr r0, [r5]\n\
	ldrb r1, [r0, 0x15]\n\
	lsls r1, 29\n\
	ldr r0, =0x000004ff\n\
	adds r3, r7, r0\n\
	lsrs r1, 31\n\
	ldrb r2, [r3]\n\
	movs r0, 0x2\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	ldr r1, [r5]\n\
	ldrb r1, [r1, 0x14]\n\
	lsls r1, 29\n\
	lsrs r1, 28\n\
	movs r2, 0xF\n\
	negs r2, r2\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3]\n\
	movs r2, 0xA0\n\
	lsls r2, 3\n\
	adds r1, r7, r2\n\
	ldr r3, =sRecordedBattle_AI_Scripts\n\
	ldr r0, [r3]\n\
	str r0, [r1]\n\
	ldr r4, =0xfffffed4\n\
	adds r1, r4, 0\n\
	ldr r5, =gTrainerBattleOpponent_A\n\
	ldrh r5, [r5]\n\
	adds r0, r1, r5\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	cmp r0, 0x63\n\
	bls _08185580\n\
	b _081856C4\n\
_08185580:\n\
	movs r6, 0\n\
	ldr r0, =0x00000504\n\
	adds r3, r7, r0\n\
	mov r10, r9\n\
	ldr r1, =gTrainerBattleOpponent_A\n\
	mov r12, r1\n\
	adds r2, r4, 0\n\
	mov r8, r2\n\
	ldr r4, =0x0000073c\n\
_08185592:\n\
	adds r2, r3, r6\n\
	mov r5, r10\n\
	ldr r1, [r5]\n\
	mov r5, r12\n\
	ldrh r0, [r5]\n\
	add r0, r8\n\
	movs r5, 0xEC\n\
	muls r0, r5\n\
	adds r0, r6, r0\n\
	adds r1, r4\n\
	adds r1, r0\n\
	ldrb r0, [r1]\n\
	strb r0, [r2]\n\
	adds r6, 0x1\n\
	cmp r6, 0x7\n\
	ble _08185592\n\
	mov r0, r9\n\
	ldr r2, [r0]\n\
	ldr r1, =gTrainerBattleOpponent_A\n\
	ldrh r0, [r1]\n\
	ldr r3, =0xfffffed4\n\
	adds r0, r3\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r2, r0\n\
	ldr r4, =0x00000739\n\
	adds r2, r4\n\
	ldrb r1, [r2]\n\
	ldr r5, =0x0000050c\n\
	adds r0, r7, r5\n\
	strb r1, [r0]\n\
	ldr r1, =sUnknown_0203CCE8\n\
	ldrb r0, [r1]\n\
	cmp r0, 0x1\n\
	bne _08185664\n\
	movs r6, 0\n\
	ldr r2, =0x0000050e\n\
	adds r4, r7, r2\n\
	mov r10, r9\n\
	ldr r5, =gTrainerBattleOpponent_A\n\
	mov r8, r5\n\
	adds r5, r3, 0\n\
_081855E6:\n\
	lsls r3, r6, 1\n\
	mov r0, r10\n\
	ldr r2, [r0]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	adds r0, r5\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r3, r0\n\
	movs r0, 0xEC\n\
	lsls r0, 3\n\
	adds r2, r0\n\
	adds r2, r3\n\
	ldrh r0, [r2]\n\
	strh r0, [r4]\n\
	adds r4, 0x2\n\
	adds r6, 0x1\n\
	cmp r6, 0x5\n\
	ble _081855E6\n\
	b _08185696\n\
	.pool\n\
_08185664:\n\
	movs r6, 0\n\
	ldr r1, =0x0000050e\n\
	adds r4, r7, r1\n\
	mov r10, r9\n\
	ldr r2, =gTrainerBattleOpponent_A\n\
	mov r8, r2\n\
	adds r5, r3, 0\n\
_08185672:\n\
	lsls r3, r6, 1\n\
	mov r0, r10\n\
	ldr r2, [r0]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	adds r0, r5\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r3, r0\n\
	ldr r0, =0x00000754\n\
	adds r2, r0\n\
	adds r2, r3\n\
	ldrh r0, [r2]\n\
	strh r0, [r4]\n\
	adds r4, 0x2\n\
	adds r6, 0x1\n\
	cmp r6, 0x5\n\
	ble _08185672\n\
_08185696:\n\
	mov r1, r9\n\
	ldr r2, [r1]\n\
	ldr r3, =gTrainerBattleOpponent_A\n\
	ldrh r0, [r3]\n\
	ldr r4, =0xfffffed4\n\
	adds r0, r4\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r2, r0\n\
	ldr r5, =0x0000081c\n\
	adds r2, r5\n\
	ldrb r1, [r2]\n\
	b _08185856\n\
	.pool\n\
_081856C4:\n\
	ldr r3, =gTrainerBattleOpponent_B\n\
	ldrh r3, [r3]\n\
	adds r0, r1, r3\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	cmp r0, 0x63\n\
	bls _081856D4\n\
	b _081857E4\n\
_081856D4:\n\
	movs r6, 0\n\
	ldr r4, =0x00000504\n\
	adds r3, r7, r4\n\
	mov r10, r9\n\
	ldr r5, =gTrainerBattleOpponent_B\n\
	mov r12, r5\n\
	ldr r0, =0xfffffed4\n\
	mov r8, r0\n\
	ldr r4, =0x0000073c\n\
_081856E6:\n\
	adds r2, r3, r6\n\
	mov r5, r10\n\
	ldr r1, [r5]\n\
	mov r5, r12\n\
	ldrh r0, [r5]\n\
	add r0, r8\n\
	movs r5, 0xEC\n\
	muls r0, r5\n\
	adds r0, r6, r0\n\
	adds r1, r4\n\
	adds r1, r0\n\
	ldrb r0, [r1]\n\
	strb r0, [r2]\n\
	adds r6, 0x1\n\
	cmp r6, 0x7\n\
	ble _081856E6\n\
	mov r0, r9\n\
	ldr r2, [r0]\n\
	ldr r1, =gTrainerBattleOpponent_B\n\
	ldrh r0, [r1]\n\
	ldr r3, =0xfffffed4\n\
	adds r0, r3\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r2, r0\n\
	ldr r4, =0x00000739\n\
	adds r2, r4\n\
	ldrb r1, [r2]\n\
	ldr r5, =0x0000050c\n\
	adds r0, r7, r5\n\
	strb r1, [r0]\n\
	ldr r1, =sUnknown_0203CCE8\n\
	ldrb r0, [r1]\n\
	cmp r0, 0x1\n\
	bne _08185784\n\
	movs r6, 0\n\
	ldr r2, =0x0000050e\n\
	adds r4, r7, r2\n\
	mov r10, r9\n\
	ldr r5, =gTrainerBattleOpponent_B\n\
	mov r8, r5\n\
	adds r5, r3, 0\n\
_0818573A:\n\
	lsls r3, r6, 1\n\
	mov r0, r10\n\
	ldr r2, [r0]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	adds r0, r5\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r3, r0\n\
	movs r0, 0xEC\n\
	lsls r0, 3\n\
	adds r2, r0\n\
	adds r2, r3\n\
	ldrh r0, [r2]\n\
	strh r0, [r4]\n\
	adds r4, 0x2\n\
	adds r6, 0x1\n\
	cmp r6, 0x5\n\
	ble _0818573A\n\
	b _081857B6\n\
	.pool\n\
_08185784:\n\
	movs r6, 0\n\
	ldr r1, =0x0000050e\n\
	adds r4, r7, r1\n\
	mov r10, r9\n\
	ldr r2, =gTrainerBattleOpponent_B\n\
	mov r8, r2\n\
	adds r5, r3, 0\n\
_08185792:\n\
	lsls r3, r6, 1\n\
	mov r0, r10\n\
	ldr r2, [r0]\n\
	mov r1, r8\n\
	ldrh r0, [r1]\n\
	adds r0, r5\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r3, r0\n\
	ldr r0, =0x00000754\n\
	adds r2, r0\n\
	adds r2, r3\n\
	ldrh r0, [r2]\n\
	strh r0, [r4]\n\
	adds r4, 0x2\n\
	adds r6, 0x1\n\
	cmp r6, 0x5\n\
	ble _08185792\n\
_081857B6:\n\
	mov r1, r9\n\
	ldr r2, [r1]\n\
	ldr r3, =gTrainerBattleOpponent_B\n\
	ldrh r0, [r3]\n\
	ldr r4, =0xfffffed4\n\
	adds r0, r4\n\
	movs r1, 0xEC\n\
	muls r0, r1\n\
	adds r2, r0\n\
	ldr r5, =0x0000081c\n\
	adds r2, r5\n\
	ldrb r1, [r2]\n\
	b _08185856\n\
	.pool\n\
_081857E4:\n\
	ldr r3, =gPartnerTrainerId\n\
	ldrh r3, [r3]\n\
	adds r0, r1, r3\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	cmp r0, 0x63\n\
	bhi _0818585C\n\
	movs r6, 0\n\
	ldr r4, =0x00000504\n\
	adds r3, r7, r4\n\
	mov r10, r9\n\
	ldr r5, =gPartnerTrainerId\n\
	mov r12, r5\n\
	ldr r0, =0xfffffed4\n\
	mov r8, r0\n\
	ldr r4, =0x0000073c\n\
_08185804:\n\
	adds r2, r3, r6\n\
	mov r5, r10\n\
	ldr r1, [r5]\n\
	mov r5, r12\n\
	ldrh r0, [r5]\n\
	add r0, r8\n\
	movs r5, 0xEC\n\
	muls r0, r5\n\
	adds r0, r6, r0\n\
	adds r1, r4\n\
	adds r1, r0\n\
	ldrb r0, [r1]\n\
	strb r0, [r2]\n\
	adds r6, 0x1\n\
	cmp r6, 0x7\n\
	ble _08185804\n\
	mov r0, r9\n\
	ldr r1, [r0]\n\
	ldr r2, =gPartnerTrainerId\n\
	ldrh r0, [r2]\n\
	ldr r3, =0xfffffed4\n\
	adds r0, r3\n\
	movs r2, 0xEC\n\
	muls r0, r2\n\
	adds r1, r0\n\
	ldr r4, =0x00000739\n\
	adds r1, r4\n\
	ldrb r1, [r1]\n\
	ldr r5, =0x0000050c\n\
	adds r0, r7, r5\n\
	strb r1, [r0]\n\
	mov r0, r9\n\
	ldr r1, [r0]\n\
	ldr r4, =gPartnerTrainerId\n\
	ldrh r0, [r4]\n\
	adds r0, r3\n\
	muls r0, r2\n\
	adds r1, r0\n\
	ldr r5, =0x0000081c\n\
	adds r1, r5\n\
	ldrb r1, [r1]\n\
_08185856:\n\
	ldr r2, =0x0000051a\n\
	adds r0, r7, r2\n\
	strb r1, [r0]\n\
_0818585C:\n\
	ldr r3, =gTrainerBattleOpponent_A\n\
	ldrh r0, [r3]\n\
	ldr r1, =0x0000018f\n\
	cmp r0, r1\n\
	bls _08185900\n\
	mov r4, r9\n\
	ldr r2, [r4]\n\
	adds r1, r0, 0\n\
	ldr r3, =0xfffffe70\n\
	adds r1, r3\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r2, r0\n\
	adds r2, 0xDC\n\
	ldrb r0, [r2]\n\
	lsls r0, 27\n\
	lsrs r0, 27\n\
	ldr r5, =0x0000050d\n\
	adds r1, r7, r5\n\
	strb r0, [r1]\n\
	movs r6, 0\n\
	ldr r0, =0x0000050e\n\
	adds r4, r7, r0\n\
	mov r10, r9\n\
	ldr r1, =gTrainerBattleOpponent_A\n\
	mov r8, r1\n\
	adds r5, r3, 0\n\
_08185894:\n\
	lsls r3, r6, 1\n\
	mov r0, r10\n\
	ldr r2, [r0]\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	adds r1, r5\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r3, r0\n\
	movs r1, 0x82\n\
	lsls r1, 1\n\
	adds r2, r1\n\
	adds r2, r3\n\
	ldrh r0, [r2]\n\
	strh r0, [r4]\n\
	adds r4, 0x2\n\
	adds r6, 0x1\n\
	cmp r6, 0x5\n\
	ble _08185894\n\
	mov r3, r9\n\
	ldr r2, [r3]\n\
	ldr r4, =gTrainerBattleOpponent_A\n\
	ldrh r1, [r4]\n\
	ldr r5, =0xfffffe70\n\
	adds r1, r5\n\
	b _081859AC\n\
	.pool\n\
_08185900:\n\
	ldr r3, =gTrainerBattleOpponent_B\n\
	ldrh r0, [r3]\n\
	cmp r0, r1\n\
	bls _0818597C\n\
	mov r4, r9\n\
	ldr r2, [r4]\n\
	adds r1, r0, 0\n\
	ldr r3, =0xfffffe70\n\
	adds r1, r3\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r2, r0\n\
	adds r2, 0xDC\n\
	ldrb r0, [r2]\n\
	lsls r0, 27\n\
	lsrs r0, 27\n\
	ldr r5, =0x0000050d\n\
	adds r1, r7, r5\n\
	strb r0, [r1]\n\
	movs r6, 0\n\
	ldr r0, =0x0000050e\n\
	adds r4, r7, r0\n\
	mov r10, r9\n\
	ldr r1, =gTrainerBattleOpponent_B\n\
	mov r8, r1\n\
	adds r5, r3, 0\n\
_08185936:\n\
	lsls r3, r6, 1\n\
	mov r0, r10\n\
	ldr r2, [r0]\n\
	mov r0, r8\n\
	ldrh r1, [r0]\n\
	adds r1, r5\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r3, r0\n\
	movs r1, 0x82\n\
	lsls r1, 1\n\
	adds r2, r1\n\
	adds r2, r3\n\
	ldrh r0, [r2]\n\
	strh r0, [r4]\n\
	adds r4, 0x2\n\
	adds r6, 0x1\n\
	cmp r6, 0x5\n\
	ble _08185936\n\
	mov r3, r9\n\
	ldr r2, [r3]\n\
	ldr r4, =gTrainerBattleOpponent_B\n\
	ldrh r1, [r4]\n\
	ldr r5, =0xfffffe70\n\
	adds r1, r5\n\
	b _081859AC\n\
	.pool\n\
_0818597C:\n\
	ldr r3, =gPartnerTrainerId\n\
	ldrh r0, [r3]\n\
	cmp r0, r1\n\
	bls _081859C0\n\
	mov r4, r9\n\
	ldr r2, [r4]\n\
	adds r1, r0, 0\n\
	ldr r3, =0xfffffe70\n\
	adds r1, r3\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r2, r0\n\
	adds r2, 0xDC\n\
	ldrb r0, [r2]\n\
	lsls r0, 27\n\
	lsrs r0, 27\n\
	ldr r5, =0x0000050d\n\
	adds r1, r7, r5\n\
	strb r0, [r1]\n\
	ldr r2, [r4]\n\
	ldr r0, =gPartnerTrainerId\n\
	ldrh r1, [r0]\n\
	adds r1, r3\n\
_081859AC:\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r2, r0\n\
	ldr r1, =0x0000011b\n\
	adds r0, r2, r1\n\
	ldrb r1, [r0]\n\
	ldr r2, =0x0000051b\n\
	adds r0, r7, r2\n\
	strb r1, [r0]\n\
_081859C0:\n\
	movs r6, 0\n\
	ldr r3, =0x00000297\n\
	mov r10, r3\n\
	ldr r4, =sBattleRecords\n\
	mov r9, r4\n\
	movs r5, 0xA6\n\
	lsls r5, 2\n\
	mov r8, r5\n\
	ldr r0, =0x0000051c\n\
	adds r5, r7, r0\n\
_081859D4:\n\
	adds r4, r6, 0x1\n\
	mov r0, r8\n\
	muls r0, r6\n\
	mov r1, r9\n\
	adds r2, r0, r1\n\
	adds r1, r0, r5\n\
	mov r3, r10\n\
	adds r3, 0x1\n\
_081859E4:\n\
	ldrb r0, [r2]\n\
	strb r0, [r1]\n\
	adds r2, 0x1\n\
	adds r1, 0x1\n\
	subs r3, 0x1\n\
	cmp r3, 0\n\
	bne _081859E4\n\
	adds r6, r4, 0\n\
	cmp r6, 0x3\n\
	ble _081859D4\n\
_081859F8:\n\
	adds r0, r7, 0\n\
	ldr r1, [sp]\n\
	bl sub_81852F0\n\
	adds r4, r0, 0\n\
	cmp r4, 0x1\n\
	beq _08185A14\n\
	ldr r0, [sp, 0x4]\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	str r0, [sp, 0x4]\n\
	cmp r0, 0x2\n\
	bls _081859F8\n\
_08185A14:\n\
	adds r0, r7, 0\n\
	bl Free\n\
	ldr r0, [sp]\n\
	bl Free\n\
	adds r0, r4, 0\n\
	add sp, 0xC\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
	.pool\n\
        .syntax divided");
}
#endif // NONMATCHING

static bool32 TryCopyRecordedBattleSaveData(struct RecordedBattleSave *dst, struct SaveSection *saveBuffer)
{
    if (TryCopySpecialSaveSection(SECTION_ID_RECORDED_BATTLE, (void*)(saveBuffer)) != 1)
        return FALSE;

    memcpy(dst, saveBuffer, sizeof(struct RecordedBattleSave));

    if (!IsRecordedBattleSaveValid(dst))
        return FALSE;

    return TRUE;
}

static bool32 AllocTryCopyRecordedBattleSaveData(struct RecordedBattleSave *dst)
{
    struct SaveSection *savBuffer = AllocZeroed(sizeof(struct SaveSection));
    bool32 ret = TryCopyRecordedBattleSaveData(dst, savBuffer);
    Free(savBuffer);

    return ret;
}

static void CB2_RecordedBattleEnd(void)
{
    gSaveBlock2Ptr->frontierChosenLvl = sUnknown_0203C7AD;
    gBattleOutcome = 0;
    gBattleTypeFlags = 0;
    gTrainerBattleOpponent_A = 0;
    gTrainerBattleOpponent_B = 0;
    gPartnerTrainerId = 0;

    RecordedBattle_RestoreSavedParties();
    SetMainCallback2(sCallback2_AfterRecordedBattle);
}

#define tFramesToWait data[0]

static void Task_StartAfterCountdown(u8 taskId)
{
    if (--gTasks[taskId].tFramesToWait == 0)
    {
        gMain.savedCallback = CB2_RecordedBattleEnd;
        SetMainCallback2(CB2_InitBattle);
        DestroyTask(taskId);
    }
}

static void SetRecordedBattleVarsFromSave(struct RecordedBattleSave *src)
{
    bool8 var;
    s32 i, j;

    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gPlayerParty[i] = src->playerParty[i];
        gEnemyParty[i] = src->opponentParty[i];
    }

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        for (var = FALSE, j = 0; j < PLAYER_NAME_LENGTH; j++)
        {
            gLinkPlayers[i].name[j] = src->playersName[i][j];
            if (src->playersName[i][j] == EOS)
                var = TRUE;
        }
        gLinkPlayers[i].gender = src->playersGender[i];
        gLinkPlayers[i].language = src->playersLanguage[i];
        gLinkPlayers[i].lp_field_18 = src->playersBank[i];
        gLinkPlayers[i].trainerId = src->playersTrainerId[i];

        if (var)
            ConvertInternationalString(gLinkPlayers[i].name, gLinkPlayers[i].language);
    }

    gRecordedBattleRngSeed = src->rngSeed;
    gBattleTypeFlags = src->battleFlags | BATTLE_TYPE_RECORDED;
    gTrainerBattleOpponent_A = src->opponentA;
    gTrainerBattleOpponent_B = src->opponentB;
    gPartnerTrainerId = src->partnerId;
    gUnknown_0203C7B4 = src->field_4FA;
    sUnknown_0203C7AD = gSaveBlock2Ptr->frontierChosenLvl;
    sUnknown_0203C7AE = src->field_4FD;
    sUnknown_0203C7AF = src->field_4FE;
    sRecordedBattle_BattleStyle = src->battleStyle;
    sRecordedBattle_TextSpeed = src->textSpeed;
    sRecordedBattle_AI_Scripts = src->AI_scripts;

    for (i = 0; i < 8; i++)
    {
        sUnknown_0203CCD1[i] = src->field_504[i];
    }

    sUnknown_0203CCD9 = src->field_50C;
    sUnknown_0203CCDA = src->field_50D;
    gUnknown_03001278 = src->field_51A;
    gUnknown_03001279 = src->field_51B;

    for (i = 0; i < 6; i++)
    {
        sUnknown_0203CCDC[i] = src->field_50E[i];
    }

    gSaveBlock2Ptr->frontierChosenLvl = src->field_4FC;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        for (j = 0; j < BANK_RECORD_SIZE; j++)
        {
            sBattleRecords[i][j] = src->battleRecord[i][j];
        }
    }
}

void PlayRecordedBattle(void (*CB2_After)(void))
{
    struct RecordedBattleSave *battleSave = AllocZeroed(sizeof(struct RecordedBattleSave));
    if (AllocTryCopyRecordedBattleSaveData(battleSave) == TRUE)
    {
        u8 taskId;

        RecordedBattle_SaveParties();
        SetRecordedBattleVarsFromSave(battleSave);

        taskId = CreateTask(Task_StartAfterCountdown, 1);
        gTasks[taskId].tFramesToWait = 128;

        sCallback2_AfterRecordedBattle = CB2_After;
        PlayMapChosenOrBattleBGM(FALSE);
        SetMainCallback2(CB2_RecordedBattle);
    }
    Free(battleSave);
}

#undef tFramesToWait

static void CB2_RecordedBattle(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTasks();
}

u8 sub_8185EA0(void)
{
    return sUnknown_0203C7AE;
}

u8 sub_8185EAC(void)
{
    return sUnknown_0203C7AF;
}

void RecordedBattle_SaveParties(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        sSavedPlayerParty[i] = gPlayerParty[i];
        sSavedOpponentParty[i] = gEnemyParty[i];
    }
}

static void RecordedBattle_RestoreSavedParties(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gPlayerParty[i] = sSavedPlayerParty[i];
        gEnemyParty[i] = sSavedOpponentParty[i];
    }
}

u8 GetActiveBankLinkPlayerGender(void)
{
    s32 i;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayers[i].lp_field_18 == gActiveBank)
            break;
    }

    if (i != MAX_LINK_PLAYERS)
        return gLinkPlayers[i].gender;

    return 0;
}

void sub_8185F84(void)
{
    sUnknown_0203C7B5 = 0;
}

void sub_8185F90(u16 arg0)
{
    sUnknown_0203C7B5 |= (arg0 & 0x8000) >> 0xF;
}

u8 sub_8185FAC(void)
{
    return sUnknown_0203C7B5;
}

u8 GetBattleStyleInRecordedBattle(void)
{
    return sRecordedBattle_BattleStyle;
}

u8 GetTextSpeedInRecordedBattle(void)
{
    return sRecordedBattle_TextSpeed;
}

void RecordedBattle_CopyBankMoves(void)
{
    s32 i;

    if (GetBankSide(gActiveBank) == SIDE_OPPONENT)
        return;
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        return;
    if (sUnknown_0203C7AC == 2)
        return;

    for (i = 0; i < 4; i++)
    {
        sRecordedBattle_PlayerMonMoves[gActiveBank / 2][i] = gBattleMons[gActiveBank].moves[i];
    }
}

#define ACTION_MOVE_CHANGE 6

void sub_818603C(u8 arg0)
{
    s32 bank, j, k;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        return;

    for (bank = 0; bank < gNoOfAllBanks; bank++)
    {
        if (GetBankSide(bank) != SIDE_OPPONENT) // player's side only
        {
            if (arg0 == 1)
            {
                for (j = 0; j < 4; j++)
                {
                    if (gBattleMons[bank].moves[j] != sRecordedBattle_PlayerMonMoves[bank / 2][j])
                        break;
                }
                if (j != 4) // player's mon's move has been changed
                {
                    RecordedBattle_SetBankAction(bank, ACTION_MOVE_CHANGE);
                    for (j = 0; j < 4; j++)
                    {
                        for (k = 0; k < 4; k++)
                        {
                            if (gBattleMons[bank].moves[j] == sRecordedBattle_PlayerMonMoves[bank / 2][k])
                            {
                                RecordedBattle_SetBankAction(bank, k);
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                if (sBattleRecords[bank][sRecordedBytesNo[bank]] == ACTION_MOVE_CHANGE)
                {
                    u8 ppBonuses[4];
                    u8 array1[4];
                    u8 array2[4];
                    struct MovePp movePp;
                    u8 array3[8];
                    u8 var;

                    RecordedBattle_ReadBankAction(bank);
                    for (j = 0; j < 4; j++)
                    {
                        ppBonuses[j] = ((gBattleMons[bank].ppBonuses & ((3 << (j << 1)))) >> (j << 1));
                    }
                    for (j = 0; j < 4; j++)
                    {
                        array1[j] = RecordedBattle_ReadBankAction(bank);
                        movePp.moves[j] = gBattleMons[bank].moves[array1[j]];
                        movePp.pp[j] = gBattleMons[bank].pp[array1[j]];
                        array3[j] = ppBonuses[array1[j]];
                        array2[j] = (gDisableStructs[bank].unk18_b & gBitTable[j]) >> j;
                    }
                    for (j = 0; j < 4; j++)
                    {
                        gBattleMons[bank].moves[j] = movePp.moves[j];
                        gBattleMons[bank].pp[j] = movePp.pp[j];
                    }
                    gBattleMons[bank].ppBonuses = 0;
                    gDisableStructs[bank].unk18_b = 0;
                    for (j = 0; j < 4; j++)
                    {
                        gBattleMons[bank].ppBonuses |= (array3[j]) << (j << 1);
                        gDisableStructs[bank].unk18_b |= (array2[j]) << (j);
                    }

                    if (!(gBattleMons[bank].status2 & STATUS2_TRANSFORMED))
                    {
                        for (j = 0; j < 4; j++)
                        {
                            ppBonuses[j] = ((GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_PP_BONUSES, NULL) & ((3 << (j << 1)))) >> (j << 1));
                        }
                        for (j = 0; j < 4; j++)
                        {
                            movePp.moves[j] = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_MOVE1 + array1[j], NULL);
                            movePp.pp[j] = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_PP1 + array1[j], NULL);
                            array3[j] = ppBonuses[array1[j]];
                        }
                        for (j = 0; j < 4; j++)
                        {
                            SetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_MOVE1 + j, &movePp.moves[j]);
                            SetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_PP1 + j, &movePp.pp[j]);
                        }
                        var = 0;
                        for (j = 0; j < 4; j++)
                        {
                            var |= (array3[j]) << (j << 1);
                        }
                        SetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_PP_BONUSES, &var);
                    }

                    gChosenMovesByBanks[bank] = gBattleMons[bank].moves[*(gBattleStruct->chosenMovePositions + bank)];
                }
            }
        }
    }
}

u32 GetAiScriptsInRecordedBattle(void)
{
    return sRecordedBattle_AI_Scripts;
}

void sub_8186444(void)
{
    sUnknown_0203CCD0 = 1;
}

bool8 sub_8186450(void)
{
    return (sUnknown_0203CCD0 == 0);
}

void sub_8186468(u8 *dst)
{
    s32 i;

    for (i = 0; i < 8; i++)
        dst[i] = sUnknown_0203CCD1[i];

    dst[7] = EOS;
    ConvertInternationalString(dst, gUnknown_03001278);
}

u8 sub_818649C(void)
{
    return sUnknown_0203CCD9;
}

u8 sub_81864A8(void)
{
    return sUnknown_0203CCDA;
}

u8 sub_81864B4(void)
{
    return gUnknown_03001278;
}

u8 sub_81864C0(void)
{
    return gUnknown_03001279;
}

void sub_81864CC(void)
{
    sUnknown_0203CCE8 = gBattleOutcome;
}

u16 *sub_81864E0(void)
{
    return sUnknown_0203CCDC;
}
