#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "event_scripts.h"
#include "random.h"
#include "string_util.h"
#include "strings.h"
#include "constants/characters.h"
#include "constants/trainer_fan_club.h"

struct TrainerFanClub
{
    u8 timer:7;
    u8 gotInitialFans:1;
    u8 fanFlags;
};

#define TRAINER_FAN_CLUB ((struct TrainerFanClub *)GetVarPointer(VAR_FANCLUB_FAN_COUNTER))

#define GET_TRAINER_FAN_CLUB_FLAG(flag) (fanClub->fanFlags >> (flag) & 1)
#define SET_TRAINER_FAN_CLUB_FLAG(flag) (fanClub->fanFlags |= 1 << (flag))
#define FLIP_TRAINER_FAN_CLUB_FLAG(flag)(fanClub->fanFlags ^= 1 << (flag))

static void TryLoseFansFromPlayTimeAfterLinkBattle(struct TrainerFanClub *);
static void UpdateTrainerFanClubGameClear(struct TrainerFanClub *);
static u8 PlayerGainRandomTrainerFan(struct TrainerFanClub *);
static u16 GetNumFansOfPlayerInTrainerFanClub(struct TrainerFanClub *);
static void TryLoseFansFromPlayTime(struct TrainerFanClub *);
static bool16 IsFanClubMemberFanOfPlayer(struct TrainerFanClub *);
static void SetInitialFansOfPlayer(struct TrainerFanClub *);
#if FREE_LINK_BATTLE_RECORDS == FALSE
static void BufferFanClubTrainerName(struct LinkBattleRecords *, u8, u8);
#else
static void BufferFanClubTrainerName(u8 whichLinkTrainer, u8 whichNPCTrainer);
#endif //FREE_LINK_BATTLE_RECORDS
static bool8 DidPlayerGetFirstFans(struct TrainerFanClub * );
static void SetPlayerGotFirstFans(struct TrainerFanClub *);

void Script_TryLoseFansFromPlayTimeAfterLinkBattle(void)
{
    TryLoseFansFromPlayTimeAfterLinkBattle(TRAINER_FAN_CLUB);
}

static void TryLoseFansFromPlayTimeAfterLinkBattle(struct TrainerFanClub *fanClub)
{
    if (DidPlayerGetFirstFans(fanClub))
    {
        TryLoseFansFromPlayTime(fanClub);
        VarSet(VAR_FANCLUB_LOSE_FAN_TIMER, gSaveBlock2Ptr->playTimeHours);
    }
}

void Script_UpdateTrainerFanClubGameClear(void)
{
    UpdateTrainerFanClubGameClear(TRAINER_FAN_CLUB);
}

static void UpdateTrainerFanClubGameClear(struct TrainerFanClub *fanClub)
{
    if (!fanClub->gotInitialFans)
    {
        SetPlayerGotFirstFans(fanClub);
        SetInitialFansOfPlayer(fanClub);
        VarSet(VAR_FANCLUB_LOSE_FAN_TIMER, gSaveBlock2Ptr->playTimeHours);
        FlagClear(FLAG_HIDE_SAFFRON_FAN_CLUB_BLACKBELT);
        FlagClear(FLAG_HIDE_SAFFRON_FAN_CLUB_ROCKER);
        FlagClear(FLAG_HIDE_SAFFRON_FAN_CLUB_WOMAN);
        FlagClear(FLAG_HIDE_SAFFRON_FAN_CLUB_BEAUTY);
        VarSet(VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1);
    }
}

ALIGNED(4) const u8 sCounterIncrements[] = {2, 1, 2, 1};

static u8 TryGainNewFanFromCounter(struct TrainerFanClub *fanClub, u8 a1)
{
    if (VarGet(VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB) == 2)
    {
        if (fanClub->timer + sCounterIncrements[a1] >= 20)
        {
            if (GetNumFansOfPlayerInTrainerFanClub(fanClub) < 3)
            {
                PlayerGainRandomTrainerFan(fanClub);
                fanClub->timer = 0;
            }
            else
                fanClub->timer = 20;
        }
        else
            fanClub->timer += sCounterIncrements[a1];
    }

    return fanClub->timer;
}


static u8 PlayerGainRandomTrainerFan(struct TrainerFanClub *fanClub)
{
    static const u8 sFanClubMemberIds[] = {
            FANCLUB_MEMBER2,
            FANCLUB_MEMBER4,
            FANCLUB_MEMBER6,
            FANCLUB_MEMBER1,
            FANCLUB_MEMBER8,
            FANCLUB_MEMBER7,
            FANCLUB_MEMBER5,
            FANCLUB_MEMBER3
        };

    u8 i;
    u8 idx = 0;

    for (i = 0; i < NUM_TRAINER_FAN_CLUB_MEMBERS; i++)
    {
        if (!(GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[i])))
        {
            idx = i;
            if (Random() % 2)
            {
                SET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[i]);
                return sFanClubMemberIds[i];
            }
        }
    }

    SET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);
    return sFanClubMemberIds[idx];
}

static u8 PlayerLoseRandomTrainerFan(struct TrainerFanClub *fanClub)
{
    static const u8 sFanClubMemberIds[] =
        {
            FANCLUB_MEMBER6,
            FANCLUB_MEMBER7,
            FANCLUB_MEMBER4,
            FANCLUB_MEMBER8,
            FANCLUB_MEMBER5,
            FANCLUB_MEMBER2,
            FANCLUB_MEMBER1,
            FANCLUB_MEMBER3
        };

    u8 i;
    u8 idx = 0;

    if (GetNumFansOfPlayerInTrainerFanClub(fanClub) == 1)
        return 0;

    for (i = 0; i < NUM_TRAINER_FAN_CLUB_MEMBERS; i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[i]))
        {
            idx = i;
            if (Random() % 2)
            {
                FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[i]);
                return sFanClubMemberIds[i];
            }
        }
    }

    if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]))
        FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubMemberIds[idx]);

    return sFanClubMemberIds[idx];
}

u16 Script_GetNumFansOfPlayerInTrainerFanClub(void)
{
    return GetNumFansOfPlayerInTrainerFanClub(TRAINER_FAN_CLUB);
}

static u16 GetNumFansOfPlayerInTrainerFanClub(struct TrainerFanClub *fanClub)
{
    u8 count = 0;
    u8 i;

    for (i = 0; i < NUM_TRAINER_FAN_CLUB_MEMBERS; i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(i))
            count++;
    }

    return count;
}

void Script_TryLoseFansFromPlayTime(void)
{
    TryLoseFansFromPlayTime(TRAINER_FAN_CLUB);
}

static void TryLoseFansFromPlayTime(struct TrainerFanClub *fanClub)
{
    u8 i = 0;
    u16 timer;

    if (gSaveBlock2Ptr->playTimeHours < 999)
    {
        while (1)
        {
            if (GetNumFansOfPlayerInTrainerFanClub(fanClub) < 5)
            {
                VarSet(VAR_FANCLUB_LOSE_FAN_TIMER, gSaveBlock2Ptr->playTimeHours);
                break;
            }
            if (i == NUM_TRAINER_FAN_CLUB_MEMBERS)
                break;

            timer = VarGet(VAR_FANCLUB_LOSE_FAN_TIMER);
            if (gSaveBlock2Ptr->playTimeHours - timer < 12)
                break;

            PlayerLoseRandomTrainerFan(fanClub);
            timer = VarGet(VAR_FANCLUB_LOSE_FAN_TIMER);
            VarSet(VAR_FANCLUB_LOSE_FAN_TIMER, timer + 12);
            i++;
        }
    }
}

bool16 Script_IsFanClubMemberFanOfPlayer(void)
{
    return IsFanClubMemberFanOfPlayer(TRAINER_FAN_CLUB);
}

static bool16 IsFanClubMemberFanOfPlayer(struct TrainerFanClub *fanClub)
{
    return GET_TRAINER_FAN_CLUB_FLAG(gSpecialVar_0x8004);
}

static void SetInitialFansOfPlayer(struct TrainerFanClub *fanClub)
{
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER1);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER2);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER3);
}

void Script_BufferFanClubTrainerName(void)
{
    u8 whichLinkTrainer = 0;
    u8 whichNPCTrainer = 0;

    switch (gSpecialVar_0x8004)
    {
    case FANCLUB_MEMBER1:
        whichNPCTrainer = 0;
        whichLinkTrainer = 0;
        break;
    case FANCLUB_MEMBER2:
    case FANCLUB_MEMBER3:
    case FANCLUB_MEMBER4:
    case FANCLUB_MEMBER8:
        break;
    case FANCLUB_MEMBER5:
        whichNPCTrainer = 1;
        whichLinkTrainer = 0;
        break;
    case FANCLUB_MEMBER6:
        whichNPCTrainer = 0;
        whichLinkTrainer = 1;
        break;
    case FANCLUB_MEMBER7:
        whichNPCTrainer = 2;
        whichLinkTrainer = 1;
        break;
    }
#if FREE_LINK_BATTLE_RECORDS == FALSE
    BufferFanClubTrainerName(&gSaveBlock1Ptr->linkBattleRecords, whichLinkTrainer, whichNPCTrainer);
#else
    BufferFanClubTrainerName(whichLinkTrainer, whichNPCTrainer);
#endif //FREE_LINK_BATTLE_RECORDS
}

static const u8 sText_LtSurge[] = _("LT. SURGE");
static const u8 sText_Koga[] = _("KOGA");

#if FREE_LINK_BATTLE_RECORDS == FALSE
static void BufferFanClubTrainerName(struct LinkBattleRecords *linkRecords, u8 whichLinkTrainer, u8 whichNPCTrainer)
{
    u8 *str;
    const u8 *linkTrainerName = linkRecords->entries[whichLinkTrainer].name;
    if (linkTrainerName[0] == EOS)
    {
        switch (whichNPCTrainer)
        {
        case 0:
#if IS_FRLG
            StringCopy(gStringVar1, gSaveBlock1Ptr->rivalName);
#else
            if (gSaveBlock2Ptr->playerGender == MALE)
                StringCopy(gStringVar1, gText_ExpandedPlaceholder_May);
            else
                StringCopy(gStringVar1, gText_ExpandedPlaceholder_Brendan);
#endif
            break;
        case 1:
            StringCopy(gStringVar1, sText_LtSurge);
            break;
        case 2:
            StringCopy(gStringVar1, sText_Koga);
            break;
        default:
#if IS_FRLG
                StringCopy(gStringVar1, gSaveBlock1Ptr->rivalName);
#else
            if (gSaveBlock2Ptr->playerGender == MALE)
                StringCopy(gStringVar1, gText_ExpandedPlaceholder_May);
            else
                StringCopy(gStringVar1, gText_ExpandedPlaceholder_Brendan);
#endif
            break;
        }
    }
    else
    {
        str = gStringVar1;
        StringCopyN(str, linkTrainerName, PLAYER_NAME_LENGTH);
        str[PLAYER_NAME_LENGTH] = EOS;
        if (   str[0] == EXT_CTRL_CODE_BEGIN
               && str[1] == EXT_CTRL_CODE_JPN)
        {
            str += 2;
            while (*str != EOS)
                str++;
            *str++ = EXT_CTRL_CODE_BEGIN;
            *str++ = EXT_CTRL_CODE_ENG;
            *str++ = EOS;
        }
    }
}
#else
static void BufferFanClubTrainerName(u8 whichLinkTrainer, u8 whichNPCTrainer)
{
    switch (whichNPCTrainer)
    {
    case 0:
    default:
#if IS_FRLG
        StringCopy(gStringVar1, gSaveBlock1Ptr->rivalName);
        break;
#endif
    case 1:
        StringCopy(gStringVar1, sText_LtSurge);
        break;
    case 2:
        StringCopy(gStringVar1, sText_Koga);
        break;
    }
}
#endif //FREE_LINK_BATTLE_RECORDS

static bool8 DidPlayerGetFirstFans(struct TrainerFanClub *fanClub)
{
    return fanClub->gotInitialFans;
}

void Script_SetPlayerGotFirstFans(void)
{
    SetPlayerGotFirstFans(TRAINER_FAN_CLUB);
}

static void SetPlayerGotFirstFans(struct TrainerFanClub *fanClub)
{
    fanClub->gotInitialFans = TRUE;
}

u8 Script_TryGainNewFanFromCounterFrlg(void)
{
    return TryGainNewFanFromCounter(TRAINER_FAN_CLUB, gSpecialVar_0x8004);
}
