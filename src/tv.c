
// Includes
#include "global.h"
#include "rng.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "field_message_box.h"
#include "easy_chat.h"
#include "species.h"
#include "moves.h"
#include "battle.h"
#include "battle_tower.h"
#include "contest.h"
#include "items.h"
#include "link.h"
#include "main.h"
#include "event_scripts.h"
#include "shop.h"
#include "lilycove_lady.h"
#include "rom6.h"
#include "pokedex.h"
#include "tv.h"

// Static type declarations

// Static RAM declarations

s8 sCurTVShowSlot;
u16 sTV_SecretBaseVisitMovesTemp[8];
u8 sTV_DecorationsBuffer[16];
struct {
    u8 level;
    u16 species;
    u16 move;
} sTV_SecretBaseVisitMonsTemp[10];

IWRAM_DATA u8 gUnknown_03001174;
IWRAM_DATA u8 gUnknown_03001175;
IWRAM_DATA u8 gUnknown_03001176;

EWRAM_DATA u16 gUnknown_0203A024 = 0;
EWRAM_DATA u16 gUnknown_0203A026 = 0;
EWRAM_DATA u16 gUnknown_0203A028 = 0;
EWRAM_DATA bool8 gUnknown_0203A02A = FALSE;
EWRAM_DATA struct {
    u8 unk_00;
} gUnknown_0203A02C = {};
EWRAM_DATA u8 sTVShowState = 0;
EWRAM_DATA u8 gUnknown_0203A031 = 0;

// Static ROM declarations

extern const u8 *const gTVBravoTrainerTextGroup[];
extern const u8 *const gTVBravoTrainerBattleTowerTextGroup[];

void ClearPokemonNews(void);
u8 GetTVChannelByShowType(u8);
void CopyContestCategoryToStringVar(u8, u8);
void CopyContestRankToStringVar(u8, u8);
void TV_ConvertNumberToOrdinal(u8, u32);
static u8 FindFirstActiveTVShowThatIsNotAMassOutbreak(void);
u8 CheckForBigMovieOrEmergencyNewsOnTV(void);
static void SetTVMetatilesOnMap(int, int, u16);
u8 FindAnyTVNewsOnTheAir(void);
static bool8 IsTVShowInSearchOfTrainersAiring(void);
void TakeTVShowInSearchOfTrainersOffTheAir(void);

bool8 TV_BernoulliTrial(u16);
s8 FindEmptyTVSlotBeyondFirstFiveShowsOfArray(TVShow *);
bool8 sub_80EF46C(u8, u8);
void tv_store_id_3x(TVShow *);
void DeleteTVShowInArrayByIdx(TVShow *, u8);
s8 FindEmptyTVSlotWithinFirstFiveShowsOfArray(TVShow *);
void FindActiveBroadcastByShowType_SetScriptResult(u8);
void sub_80EF7B4(void);
void sub_80EF7A8(void);
u16 sub_80EFA24(u16);
void sub_80EFA88(void);

void TVShowDone(void);

// .rodata

const struct {
    u16 species;
    u16 moves[4];
    u8 level;
    u8 location;
} gPokeOutbreakSpeciesList[] = {
    {
        SPECIES_SEEDOT,
        {MOVE_BIDE, MOVE_HARDEN, MOVE_LEECH_SEED},
        3, 0x11 // Route 102
    },
    {
        SPECIES_NUZLEAF,
        {MOVE_HARDEN, MOVE_GROWTH, MOVE_NATURE_POWER, MOVE_LEECH_SEED},
        15, 0x1D // Route 114
    },
    {
        SPECIES_SEEDOT,
        {MOVE_HARDEN, MOVE_GROWTH, MOVE_NATURE_POWER, MOVE_LEECH_SEED},
        13, 0x20 // Route 117
    },
    {
        SPECIES_SEEDOT,
        {MOVE_GIGA_DRAIN, MOVE_FRUSTRATION, MOVE_SOLAR_BEAM, MOVE_LEECH_SEED},
        25, 0x23 // Route 110
    },
    {
        SPECIES_SKITTY,
        {MOVE_GROWL, MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_ATTRACT},
        8, 0x1F // Route 116
    }
};

// TODO: Figure out what these are, and define constants in include/flags.h
const u16 gUnknown_0858D0D0[] = {
    CODE_FLAGS + 0x65,
    CODE_FLAGS + 0x67,
    CODE_FLAGS + 0x69,
    CODE_FLAGS + 0x6B,
    CODE_FLAGS + 0x6D,
    CODE_FLAGS + 0x6F,
    CODE_FLAGS + 0x71
};

const u16 gUnknown_0858D0DE[] = {
    CODE_FLAGS + 0x64,
    CODE_FLAGS + 0x66,
    CODE_FLAGS + 0x68,
    CODE_FLAGS + 0x6A,
    CODE_FLAGS + 0x6C,
    CODE_FLAGS + 0x6E,
    CODE_FLAGS + 0x70
};

// TODO: Figure out what these are, and define constants in include/vars.h
const u16 gUnknown_0858D0EC[][2] = {
    {0x40E6, 100},
    {0x40EB,  50},
    {0x40E7, 100},
    {0x40E8,  20},
    {0x40E9,  20},
    {0x40EA,  20},
    {0x40F1,  30}
};

const u8 *const gUnknown_0858D108[] = {
    NULL,
    gUnknown_0828D0F8,
    gUnknown_0828D571,
    gUnknown_0828D875,
    gUnknown_0828DBEC
};

const u8 *const gUnknown_0858D11C[] = {
    NULL,
    gUnknown_0828D2A1,
    gUnknown_0828D66F,
    gUnknown_0828D994,
    gUnknown_0828DD9E
};

const u8 *const gUnknown_0858D130[] = {
    NULL,
    gUnknown_0828D3F5,
    gUnknown_0828D768,
    gUnknown_0828DAC0,
    gUnknown_0828DF05
};

const u8 *const gUnknown_0858D144[] = {
    gStringVar1,
    gStringVar2,
    gStringVar3
};

const u8 *const gUnknown_0858D150[] = {
    gUnknown_08280DEE,
    gUnknown_08280F69,
    gUnknown_08280F88,
    gUnknown_08280FA9,
    gUnknown_08280FD5,
    gUnknown_08281040,
    gUnknown_08281073,
    gUnknown_082810E7
};

const u8 *const gUnknown_0858D170[] = {
    gUnknown_0828149E,
    gUnknown_082815AF,
    gUnknown_08281636,
    gUnknown_08281666,
    gUnknown_082816BA,
    gUnknown_082816EB
};

const u8 *const gUnknown_0858D188[] = {
    gUnknown_08280886,
    gUnknown_08280A44,
    gUnknown_08280AFC,
    gUnknown_08280BC4,
    gUnknown_08280C7A
};

const u8 *const gUnknown_0858D19C[] = {
    gUnknown_0828178A
};

const u8 *const gUnknown_0858D1A0[] = {
    gUnknown_082834A0,
    gUnknown_08283552,
    gUnknown_082835AE,
    gUnknown_0828361F,
    gUnknown_08283685,
    gUnknown_0828370C,
    gUnknown_082837C2,
    gUnknown_08283848,
    gUnknown_082838C2,
    gUnknown_0828394A,
    gUnknown_082839EA,
    gUnknown_08283A5F
};

const u8 *const gUnknown_0858D1D0[] = {
    gUnknown_08283B05,
    gUnknown_08283BAF,
    gUnknown_08283C81,
    gUnknown_08283D32,
    gUnknown_08283D99,
    gUnknown_08283E28,
    gUnknown_08283F01,
    gUnknown_08283F72,
    gUnknown_08283FA9,
    gUnknown_08283FE7,
    gUnknown_0828409E,
    gUnknown_082840CE,
    gUnknown_082842E6
};

const u8 *const gTVBravoTrainerTextGroup[] = {
    gUnknown_0827F275,
    gUnknown_0827F304,
    gUnknown_0827F361,
    gUnknown_0827F3E4,
    gUnknown_0827F49F,
    gUnknown_0827F565,
    gUnknown_0827F624,
    gUnknown_0827F65C,
    gUnknown_0827F6E6
};

const u8 *const gUnknown_0858D228[] = {
    gUnknown_082818F4,
    gUnknown_082819C7,
    gUnknown_08281A2F,
    gUnknown_08281AAC,
    gUnknown_08281B28,
    gUnknown_08281B93
};

const u8 *const gTVBravoTrainerBattleTowerTextGroup[] = {
    gUnknown_0827FB20,
    gUnknown_0827FBB3,
    gUnknown_0827FC04,
    gUnknown_0827FCD1,
    gUnknown_0827FD91,
    gUnknown_0827FE93,
    gUnknown_0827FF89,
    gUnknown_0828009C,
    gUnknown_082800A1,
    gUnknown_082800A6,
    gUnknown_082800AB,
    gUnknown_082800B0,
    gUnknown_082800B6,
    gUnknown_0828013D,
    gUnknown_082801E6
};

const u8 *const gUnknown_0858D27C[] = {
    gUnknown_08289DD6,
    gUnknown_08289F53,
    gUnknown_08289FB0,
    gUnknown_0828A047,
    gUnknown_0828A0C6,
    gUnknown_0828A132,
    gUnknown_0828A1BE,
    gUnknown_0828A202,
    gUnknown_0828A24E,
    gUnknown_0828A288,
    gUnknown_0828A29B,
    gUnknown_0828A2B3,
    gUnknown_0828A2C6,
    gUnknown_0828A2DA,
    gUnknown_0828A2EE,
    gUnknown_0828A32E,
    gUnknown_0828A350,
    gUnknown_0828A36F,
    gUnknown_0828A38D,
    gUnknown_0828A3B6,
    gUnknown_0828A3DC,
    gUnknown_0828A455,
    gUnknown_0828A4CF,
    gUnknown_0828A51C,
    gUnknown_0828A5AC,
    gUnknown_0828A638,
    gUnknown_0828A6CF,
    gUnknown_0828A797,
    gUnknown_0828A86D,
    gUnknown_0828A920,
    gUnknown_0828A9CC,
    gUnknown_0828AA74,
    gUnknown_0828AB01
};

const u8 *const gUnknown_0858D300[] = {
    gUnknown_0828ABCC,
    gUnknown_0828AC22,
    gUnknown_0828AC7E,
    gUnknown_0828ACB6,
    gUnknown_0828ACE3,
    gUnknown_0828AD80,
    gUnknown_0828ADE2,
    gUnknown_0828AE26
};

const u8 *const gUnknown_0858D320[] = {
    gUnknown_08281DFB,
    gUnknown_08281F90,
    gUnknown_08281FFA,
    gUnknown_08282052,
    gUnknown_082820B2,
    gUnknown_0828210E
};

const u8 *const gUnknown_0858D338[] = {
    gUnknown_0828218A,
    gUnknown_0828229E,
    gUnknown_08282317,
    gUnknown_0828239D,
    gUnknown_08282418,
    gUnknown_082824A6,
    gUnknown_08282522,
    gUnknown_082825A1,
    gUnknown_08282623,
    gUnknown_082826B4,
    gUnknown_0828274D,
    gUnknown_082827CB,
    gUnknown_08282849,
    gUnknown_08282883,
    gUnknown_082828E4,
    gUnknown_08282912,
    gUnknown_0828296C,
    gUnknown_08282996,
    gUnknown_08282A36
};

const u8 *const gUnknown_0858D384[] = {
    gUnknown_0828C137,
    gUnknown_0828C28C,
    gUnknown_0828C45B,
    gUnknown_0828C662
};

const u8 *const gUnknown_0858D394[] = {
    gUnknown_08282F9B,
    gUnknown_0828304D,
    gUnknown_08283135,
    gUnknown_082831DF,
    gUnknown_08283294,
    gUnknown_08283337,
    gUnknown_082833C6
};

const u8 *const gUnknown_0858D3B0[] = {
    gUnknown_08282ACF,
    gUnknown_08282D7C
};

const u8 *const gUnknown_0858D3B8[] = {
    gUnknown_082843BA,
    gUnknown_082844FD,
    gUnknown_0828455B
};

const u8 *const gUnknown_0858D3C4[] = {
    gUnknown_08284641,
    gUnknown_0828485F,
    gUnknown_0828489A,
    gUnknown_082848CC,
    gUnknown_0828490B,
    gUnknown_0828496B,
    gUnknown_082849AE,
    gUnknown_082846D2,
    gUnknown_08284738,
    gUnknown_082847A5,
    gUnknown_082847F7
};

const u8 *const gUnknown_0858D3F0[] = {
    gUnknown_08284A3E,
    gUnknown_08284C55,
    gUnknown_08284C9B,
    gUnknown_08284CE1,
    gUnknown_08284DB6,
    gUnknown_08284DF5,
    gUnknown_08284E34
};

const u8 *const gUnknown_0858D40C[] = {
    gUnknown_08284EDF,
    gUnknown_08284FA1,
    gUnknown_082850F5
};

const u8 *const gUnknown_0858D418[] = {
    gUnknown_08285240,
    gUnknown_082852F4,
    gUnknown_08285463,
    gUnknown_08285500
};

const u8 *const gUnknown_0858D428[] = {
    gUnknown_082855BF,
    gUnknown_082855D1,
    gUnknown_0828563C,
    gUnknown_08285682,
    gUnknown_08285705,
    gUnknown_082857B0,
    gUnknown_08285824,
    gUnknown_0828586A,
    gUnknown_0828596F,
    gUnknown_082859AC,
    gUnknown_08285A50,
    gUnknown_08285AB3,
    gUnknown_082858D0
};

const u8 *const gUnknown_0858D45C[] = {
    gUnknown_08285B27,
    gUnknown_08285BCA,
    gUnknown_08285C13,
    gUnknown_08285CFF,
    gUnknown_08285D5D,
    gUnknown_08285DE0,
    gUnknown_08285E3B,
    gUnknown_08285E9D,
    gUnknown_08285EFE,
    gUnknown_08285F46,
    gUnknown_08286049,
    gUnknown_0828613A,
    gUnknown_08286248,
    gUnknown_08286340
};

const u8 *const gUnknown_0858D494[] = {
    gUnknown_082863CC
};

const u8 *const gUnknown_0858D498[] = {
    gUnknown_08286616,
    gUnknown_082866B6,
    gUnknown_08286700,
    gUnknown_0828673B,
    gUnknown_08286755,
    gUnknown_0828676A,
    gUnknown_08286777
};

const u8 *const gUnknown_0858D4B4[] = {
    gUnknown_08286866,
    gUnknown_0828695E,
    gUnknown_0828698B,
    gUnknown_082869B0,
    gUnknown_082869ED,
    gUnknown_08286A17,
    gUnknown_08286A48,
    gUnknown_08286A7C,
    gUnknown_08286AAE,
    gUnknown_08286AE6,
    gUnknown_08286B23,
    gUnknown_08286B4F
};

const u8 *const gUnknown_0858D4E4[] = {
    gUnknown_08286D8F,
    gUnknown_08286E9D,
    gUnknown_08286EFC,
    gUnknown_08286F54,
    gUnknown_08286FAA,
    gUnknown_08286FE4,
    gUnknown_082870A3,
    gUnknown_0828715A,
    gUnknown_08287215,
    gUnknown_082872CC,
    gUnknown_08287387,
    gUnknown_08287442,
    gUnknown_08287508,
    gUnknown_082875D9,
    gUnknown_082876A1,
    gUnknown_08287779
};

const u8 *const gUnknown_0858D524[] = {
    gUnknown_082877DE,
    gUnknown_0828783D,
    gUnknown_082878B3,
    gUnknown_08287929,
    gUnknown_0828799E,
    gUnknown_08287A18,
    gUnknown_08287A97,
    gUnknown_08287B16,
    gUnknown_08287B8E,
    gUnknown_08287C06,
    gUnknown_08287C7D,
    gUnknown_08287CF3,
    gUnknown_08287D6A,
    gUnknown_08287DE1,
    gUnknown_08287E5B,
    gUnknown_08287EBB,
    gUnknown_08287F14,
    gUnknown_08287F39,
    gUnknown_08287F77
};

const u8 *const gUnknown_0858D570[] = {
    gUnknown_08287FE0,
    gUnknown_082880C0,
    gUnknown_0828815F,
    gUnknown_0828821A,
    gUnknown_082882BE,
    gUnknown_08288355,
    gUnknown_0828842B,
    gUnknown_082884A5,
    gUnknown_0828858B
};

const u8 *const gUnknown_0858D594[] = {
    gUnknown_08288608,
    gUnknown_082886C8,
    gUnknown_082886DE,
    gUnknown_082886F8,
    gUnknown_08288739,
    gUnknown_08288777,
    gUnknown_082887AF,
    gUnknown_082887E9,
    gUnknown_08288868,
    gUnknown_082888CA,
    gUnknown_08288930,
    gUnknown_082889C0,
    gUnknown_08288A3A,
    gUnknown_08288ACA,
    gUnknown_08288B1E,
    gUnknown_08288B7A,
    gUnknown_08288BC9,
    gUnknown_08288C40,
    gUnknown_08288C88,
    gUnknown_08288CC8,
    gUnknown_08288D7F,
    gUnknown_08288DA0,
    gUnknown_08288DDA,
    gUnknown_08288E1E,
    gUnknown_08288EC9,
    gUnknown_08288F58,
    gUnknown_08289011,
    gUnknown_082890A4,
    gUnknown_082890F0,
    gUnknown_08289193,
    gUnknown_08289204,
    gUnknown_0828927C,
    gUnknown_08289313,
    gUnknown_08289375,
    gUnknown_082893FF,
    gUnknown_08289465,
    gUnknown_082894F2,
    gUnknown_08289564,
    gUnknown_082895EB,
    gUnknown_08289645,
    gUnknown_0828967E,
    gUnknown_082896FC,
    gUnknown_0828977D
};

const u8 *const gUnknown_0858D640[] = {
    gUnknown_08289813,
    gUnknown_0828992F,
    gUnknown_0828999D,
    gUnknown_082899DC,
    gUnknown_08289A29,
    gUnknown_08289AC2,
    gUnknown_08289B42,
    gUnknown_08289BC5,
    gUnknown_08289C3B,
    gUnknown_08289C99,
    gUnknown_08289D33
};

const u8 *const gUnknown_0858D66C[] = {
    gUnknown_0828B92C,
    gUnknown_0828BA20,
    gUnknown_0828BAC8,
    gUnknown_0828BC18,
    gUnknown_0828BD20,
    gUnknown_0828BE01,
    gUnknown_0828BEEE,
    gUnknown_0828BF50,
    gUnknown_0828C011
};

const u8 gUnknown_0858D690[] = {
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x17,
    0x18,
    0x19,
    0x1a,
    0x1b,
    0x1c,
    0x1d,
    0x1e,
    0x1f,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2a,
    0x2b
};

// .text

void ClearTVShowData(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows); i ++)
    {
        gSaveBlock1Ptr->tvShows[i].common.kind = 0;
        gSaveBlock1Ptr->tvShows[i].common.active = 0;
        for (j = 0; j < sizeof(TVShow) - 2; j ++)
        {
            gSaveBlock1Ptr->tvShows[i].common.pad02[j] = 0;
        }
    }
    ClearPokemonNews();
}

u8 special_0x44(void)
{
    u8 i;
    u8 j;
    u8 selIdx;
    TVShow *show;

    for (i = 5; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 1; i ++)
    {
        if (gSaveBlock1Ptr->tvShows[i].common.kind == 0)
        {
            break;
        }
    }
    j = Random() % i;
    selIdx = j;
    do
    {
        if (GetTVChannelByShowType(gSaveBlock1Ptr->tvShows[j].common.kind) != 4)
        {
            if (gSaveBlock1Ptr->tvShows[j].common.active == TRUE)
            {
                return j;
            }
        }
        else
        {
            show = &gSaveBlock1Ptr->tvShows[j];
            if (show->massOutbreak.daysLeft == 0 && show->massOutbreak.active == TRUE)
            {
                return j;
            }
        }
        if (j == 0)
        {
            j = ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 2;
        }
        else
        {
            j --;
        }
    } while (j != selIdx);
    return 0xFF;
}

static u8 FindAnyTVShowOnTheAir(void)
{
    u8 response;

    response = special_0x44();
    if (response == 0xFF)
    {
        return 0xFF;
    }
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE && gSaveBlock1Ptr->tvShows[response].common.kind == TVSHOW_MASS_OUTBREAK)
    {
        return FindFirstActiveTVShowThatIsNotAMassOutbreak();
    }
    return response;
}

void UpdateTVScreensOnMap(int width, int height)
{
    FlagSet(SYS_TV_WATCH);
    switch (CheckForBigMovieOrEmergencyNewsOnTV())
    {
        case 1:
            SetTVMetatilesOnMap(width, height, 0x3);
            break;
        case 2:
            break;
        default:
            if (gSaveBlock1Ptr->location.mapGroup == 0x0d && gSaveBlock1Ptr->location.mapNum == 0x00)
            {
                SetTVMetatilesOnMap(width, height, 0x3);
            }
            else if (FlagGet(SYS_TV_START) && (FindAnyTVShowOnTheAir() != 0xff || FindAnyTVNewsOnTheAir() != 0xff || IsTVShowInSearchOfTrainersAiring()))
            {
                FlagReset(SYS_TV_WATCH);
                SetTVMetatilesOnMap(width, height, 0x3);
            }
            break;
    }
}

static void SetTVMetatilesOnMap(int width, int height, u16 tileId)
{
    int x;
    int y;

    for (y = 0; y < height; y ++)
    {
        for (x = 0; x < width; x ++)
        {
            if (MapGridGetMetatileBehaviorAt(x, y) == 0x86) // is this tile a TV?
            {
                MapGridSetMetatileIdAt(x, y, tileId | 0xc00);
            }
        }
    }
}

void TurnOffTVScreen(void)
{
    SetTVMetatilesOnMap(gUnknown_03005DC0.width, gUnknown_03005DC0.height, 0x0002);
    DrawWholeMapView();
}

void TurnOnTVScreen(void)
{
    SetTVMetatilesOnMap(gUnknown_03005DC0.width, gUnknown_03005DC0.height, 0x0003);
    DrawWholeMapView();
}

u8 special_0x45(void)
{
    return gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].common.kind;
}

static u8 FindFirstActiveTVShowThatIsNotAMassOutbreak(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 1; i ++)
    {
        if (gSaveBlock1Ptr->tvShows[i].common.kind != 0 && gSaveBlock1Ptr->tvShows[i].common.kind != TVSHOW_MASS_OUTBREAK && gSaveBlock1Ptr->tvShows[i].common.active == TRUE)
        {
            return i;
        }
    }
    return 0xFF;
}

u8 special_0x4a(void)
{
    TVShow *tvShow;

    tvShow = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004];
    if (tvShow->common.kind == TVSHOW_MASS_OUTBREAK && gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE)
    {
        return FindFirstActiveTVShowThatIsNotAMassOutbreak();
    }
    return gSpecialVar_0x8004;
}

// IN SEARCH OF TRAINERS

void ResetGabbyAndTy(void)
{
    gSaveBlock1Ptr->gabbyAndTyData.mon1 = SPECIES_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.mon2 = SPECIES_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.lastMove = MOVE_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.quote[0] = -1;
    gSaveBlock1Ptr->gabbyAndTyData.valA_0 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.not_total_victory = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_2 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_3 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.onAir = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_5 = 0;
    gSaveBlock1Ptr->gabbyAndTyData.valB_0 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_1 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_2 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_3 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_4 = 0;
    gSaveBlock1Ptr->gabbyAndTyData.mapnum = 0;
    gSaveBlock1Ptr->gabbyAndTyData.battleNum = 0;
}

void GabbyAndTyBeforeInterview(void)
{
    u8 i;

    gSaveBlock1Ptr->gabbyAndTyData.mon1 = gBattleResults.poke1Species;
    gSaveBlock1Ptr->gabbyAndTyData.mon2 = gBattleResults.opponentSpecies;
    gSaveBlock1Ptr->gabbyAndTyData.lastMove = gBattleResults.lastUsedMove;
    if (gSaveBlock1Ptr->gabbyAndTyData.battleNum != 0xFF)
    {
        gSaveBlock1Ptr->gabbyAndTyData.battleNum ++;
    }
    gSaveBlock1Ptr->gabbyAndTyData.valA_0 = gBattleResults.unk5_0;
    if (gBattleResults.playerFaintCounter != 0)
    {
        gSaveBlock1Ptr->gabbyAndTyData.not_total_victory = TRUE;
    }
    else
    {
        gSaveBlock1Ptr->gabbyAndTyData.not_total_victory = FALSE;
    }
    if (gBattleResults.unk3 != 0)
    {
        gSaveBlock1Ptr->gabbyAndTyData.valA_2 = TRUE;
    }
    else
    {
        gSaveBlock1Ptr->gabbyAndTyData.valA_2 = FALSE;
    }
    if (!gBattleResults.usedMasterBall)
    {
        for (i = 0; i < 11; i ++)
        {
            if (gBattleResults.catchAttempts[i])
            {
                gSaveBlock1Ptr->gabbyAndTyData.valA_3 = TRUE;
                break;
            }
        }
    }
    else
    {
        gSaveBlock1Ptr->gabbyAndTyData.valA_3 = TRUE;
    }
    TakeTVShowInSearchOfTrainersOffTheAir();
    if (gSaveBlock1Ptr->gabbyAndTyData.lastMove == MOVE_NONE)
    {
        FlagSet(0x0001);
    }
}

void GabbyAndTyAfterInterview(void)
{
    gSaveBlock1Ptr->gabbyAndTyData.valB_0 = gSaveBlock1Ptr->gabbyAndTyData.valA_0;
    gSaveBlock1Ptr->gabbyAndTyData.valB_1 = gSaveBlock1Ptr->gabbyAndTyData.not_total_victory;
    gSaveBlock1Ptr->gabbyAndTyData.valB_2 = gSaveBlock1Ptr->gabbyAndTyData.valA_2;
    gSaveBlock1Ptr->gabbyAndTyData.valB_3 = gSaveBlock1Ptr->gabbyAndTyData.valA_3;
    gSaveBlock1Ptr->gabbyAndTyData.onAir = TRUE;
    gSaveBlock1Ptr->gabbyAndTyData.mapnum = gMapHeader.regionMapSectionId;
    IncrementGameStat(GAME_STAT_GOT_INTERVIEWED);
}

void TakeTVShowInSearchOfTrainersOffTheAir(void)
{
    gSaveBlock1Ptr->gabbyAndTyData.onAir = FALSE;
}

u8 GabbyAndTyGetBattleNum(void)
{
    if (gSaveBlock1Ptr->gabbyAndTyData.battleNum > 5)
    {
        return (gSaveBlock1Ptr->gabbyAndTyData.battleNum % 3) + 6;
    }
    return gSaveBlock1Ptr->gabbyAndTyData.battleNum;
}

static bool8 IsTVShowInSearchOfTrainersAiring(void)
{
    return gSaveBlock1Ptr->gabbyAndTyData.onAir;
}

bool8 GabbyAndTyGetLastQuote(void)
{
    if (gSaveBlock1Ptr->gabbyAndTyData.quote[0] == 0xFFFF)
    {
        return FALSE;
    }
    CopyEasyChatWord(gStringVar1, gSaveBlock1Ptr->gabbyAndTyData.quote[0]);
    gSaveBlock1Ptr->gabbyAndTyData.quote[0] = -1;
    return TRUE;
}

u8 GabbyAndTyGetLastBattleTrivia(void)
{
    if (!gSaveBlock1Ptr->gabbyAndTyData.valB_0)
    {
        return 1;
    }
    if (gSaveBlock1Ptr->gabbyAndTyData.valB_3)
    {
        return 2;
    }
    if (gSaveBlock1Ptr->gabbyAndTyData.valB_2)
    {
        return 3;
    }
    if (gSaveBlock1Ptr->gabbyAndTyData.valB_1)
    {
        return 4;
    }
    return 0;
}

void GabbyAndTySetScriptVarsToFieldObjectLocalIds(void)
{
    switch (GabbyAndTyGetBattleNum())
    {
        case 1:
            gSpecialVar_0x8004 = 14;
            gSpecialVar_0x8005 = 13;
            break;
        case 2:
            gSpecialVar_0x8004 = 5;
            gSpecialVar_0x8005 = 6;
            break;
        case 3:
            gSpecialVar_0x8004 = 18;
            gSpecialVar_0x8005 = 17;
            break;
        case 4:
            gSpecialVar_0x8004 = 21;
            gSpecialVar_0x8005 = 22;
            break;
        case 5:
            gSpecialVar_0x8004 = 8;
            gSpecialVar_0x8005 = 9;
            break;
        case 6:
            gSpecialVar_0x8004 = 19;
            gSpecialVar_0x8005 = 20;
            break;
        case 7:
            gSpecialVar_0x8004 = 23;
            gSpecialVar_0x8005 = 24;
            break;
        case 8:
            gSpecialVar_0x8004 = 10;
            gSpecialVar_0x8005 = 11;
            break;
    }
}

void InterviewAfter(void)
{
    static void InterviewAfter_FanClubLetter(void);
    static void InterviewAfter_RecentHappenings(void);
    static void InterviewAfter_PkmnFanClubOpinions(void);
    static void InterviewAfter_DummyShow4(void);
    static void InterviewAfter_BravoTrainerPokemonProfile(void);
    static void InterviewAfter_BravoTrainerBattleTowerProfile(void);
    static void InterviewAfter_ContestLiveUpdates(void);

    switch (gSpecialVar_0x8005)
    {
        case TVSHOW_FAN_CLUB_LETTER:
            InterviewAfter_FanClubLetter();
            break;
        case TVSHOW_RECENT_HAPPENINGS:
            InterviewAfter_RecentHappenings();
            break;
        case TVSHOW_PKMN_FAN_CLUB_OPINIONS:
            InterviewAfter_PkmnFanClubOpinions();
            break;
        case TVSHOW_UNKN_SHOWTYPE_04:
            InterviewAfter_DummyShow4();
            break;
        case TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE:
            InterviewAfter_BravoTrainerPokemonProfile();
            break;
        case TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE:
            InterviewAfter_BravoTrainerBattleTowerProfile();
            break;
        case TVSHOW_CONTEST_LIVE_UPDATES:
            InterviewAfter_ContestLiveUpdates();
            break;
    }
}

void PutPokemonTodayCaughtOnAir(void)
{
    static void UpdateWorldOfMastersAndPutItOnTheAir(void);
    static void PutPokemonTodayFailedOnTheAir(void);
    static void sub_80ED718(void);
    void sub_80EED88(void);
    u8 i;
    u16 ct;
    TVShow *show;
    u32 language2;
    u16 itemLastUsed;

    ct = 0;
    sub_80EED88();
    sub_80ED718();
    if (gBattleResults.caughtMonSpecies == SPECIES_NONE)
    {
        PutPokemonTodayFailedOnTheAir();
    }
    else
    {
        UpdateWorldOfMastersAndPutItOnTheAir();
        if (!TV_BernoulliTrial(-1) && StringCompare(gSpeciesNames[gBattleResults.caughtMonSpecies], gBattleResults.caughtMonNick))
        {
            sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
            if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_POKEMON_TODAY_CAUGHT, 0) != TRUE)
            {
                for (i = 0; i < 11; i ++)
                {
                    ct += gBattleResults.catchAttempts[i];
                }
                if (ct != 0 || gBattleResults.usedMasterBall)
                {
                    ct = 0;
                    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
                    show->pokemonToday.kind = TVSHOW_POKEMON_TODAY_CAUGHT;
                    show->pokemonToday.active = FALSE;
                    if (gBattleResults.usedMasterBall)
                    {
                        ct = 1;
                        itemLastUsed = ITEM_MASTER_BALL;
                    }
                    else
                    {
                        for (i = 0; i < 11; i ++)
                        {
                            ct += gBattleResults.catchAttempts[i];
                        }
                        if (ct > 0xFF)
                        {
                            ct = 0xFF;
                        }
                        itemLastUsed = gLastUsedItem;
                    }
                    show->pokemonToday.var12 = ct;
                    show->pokemonToday.ball = itemLastUsed;
                    StringCopy(show->pokemonToday.playerName, gSaveBlock2Ptr->playerName);
                    StringCopy(show->pokemonToday.nickname, gBattleResults.caughtMonNick);
                    language2 = sub_81DB604(show->pokemonToday.nickname);
                    StripExtCtrlCodes(show->pokemonToday.nickname);
                    show->pokemonToday.species = gBattleResults.caughtMonSpecies;
                    tv_store_id_3x(show);
                    show->pokemonToday.language = gGameLanguage;
                    show->pokemonToday.language2 = language2;
                }
            }
        }
    }
}

static void UpdateWorldOfMastersAndPutItOnTheAir(void)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (show->worldOfMasters.kind != TVSHOW_WORLD_OF_MASTERS)
    {
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
        show->worldOfMasters.steps = GetGameStat(GAME_STAT_STEPS);
        show->worldOfMasters.kind = TVSHOW_WORLD_OF_MASTERS;
    }
    show->worldOfMasters.var02 ++;
    show->worldOfMasters.caughtPoke = gBattleResults.caughtMonSpecies;
    show->worldOfMasters.species = gBattleResults.poke1Species;
    show->worldOfMasters.location = gMapHeader.regionMapSectionId;
}

static void PutPokemonTodayFailedOnTheAir(void)
{
    u16 ct;
    u8 i;
    TVShow *show;

    if (!TV_BernoulliTrial(-1))
    {
        for (i = 0, ct = 0; i < 11; i ++)
        {
            ct += gBattleResults.catchAttempts[i];
        }
        if (ct > 0xFF)
        {
            ct = 0xFF;
        }
        if (ct > 2 && (gBattleOutcome == BATTLE_POKE_FLED || gBattleOutcome == BATTLE_WON))
        {
            sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
            if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_POKEMON_TODAY_FAILED, 0) != TRUE)
            {
                show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
                show->pokemonTodayFailed.kind = TVSHOW_POKEMON_TODAY_FAILED;
                show->pokemonTodayFailed.active = FALSE;
                show->pokemonTodayFailed.species = gBattleResults.poke1Species;
                show->pokemonTodayFailed.species2 = gBattleResults.lastOpponentSpecies;
                show->pokemonTodayFailed.var10 = ct;
                show->pokemonTodayFailed.var11 = gBattleOutcome;
                show->pokemonTodayFailed.var12 = gMapHeader.regionMapSectionId;
                StringCopy(show->pokemonTodayFailed.playerName, gSaveBlock2Ptr->playerName);
                tv_store_id_3x(show);
                show->pokemonTodayFailed.language = gGameLanguage;
            }
        }
    }
}

void tv_store_id_3x(TVShow *show)
{
    u32 id;

    id = player_id_to_dword();
    show->common.srcTrainerId2Lo = id;
    show->common.srcTrainerId2Hi = id >> 8;
    show->common.srcTrainerIdLo = id;
    show->common.srcTrainerIdHi = id >> 8;
    show->common.trainerIdLo = id;
    show->common.trainerIdHi = id >> 8;
}

void tv_store_id_2x(TVShow *show)
{
    u32 id;

    id = player_id_to_dword();
    show->common.srcTrainerIdLo = id;
    show->common.srcTrainerIdHi = id >> 8;
    show->common.trainerIdLo = id;
    show->common.trainerIdHi = id >> 8;
}

static void InterviewAfter_ContestLiveUpdates(void)
{
    TVShow *show;
    TVShow *show2;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (show->contestLiveUpdates.kind == TVSHOW_CONTEST_LIVE_UPDATES)
    {
        show2 = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show2->contestLiveUpdates.kind = TVSHOW_CONTEST_LIVE_UPDATES;
        show2->contestLiveUpdates.active = TRUE;
        StringCopy(show2->contestLiveUpdates.playerName, gSaveBlock2Ptr->playerName);
        show2->contestLiveUpdates.unk_1c = gUnknown_02039F2C;
        show2->contestLiveUpdates.species = GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_SPECIES, NULL);
        show2->contestLiveUpdates.unk_02 = show->contestLiveUpdates.unk_02;
        show2->contestLiveUpdates.unk_0c = show->contestLiveUpdates.unk_0c;
        show2->contestLiveUpdates.unk_0d = show->contestLiveUpdates.unk_0d;
        show2->contestLiveUpdates.unk_0e = show->contestLiveUpdates.unk_0e;
        show2->contestLiveUpdates.unk_10 = show->contestLiveUpdates.unk_10;
        show2->contestLiveUpdates.unk_0f = show->contestLiveUpdates.unk_0f;
        StringCopy(show2->contestLiveUpdates.unk_04, show->contestLiveUpdates.unk_04);
        tv_store_id_2x(show2);
        show2->contestLiveUpdates.language = gGameLanguage;
        show2->contestLiveUpdates.unk_1e = show->contestLiveUpdates.unk_1e;
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
    }
}

void PutBattleUpdateOnTheAir(u8 a0, u16 a1, u16 a2, u16 a3)
{
    TVShow *show;
    u8 name[32];

    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        FindActiveBroadcastByShowType_SetScriptResult(TVSHOW_BATTLE_UPDATE);
        if (gScriptResult != 1)
        {
            show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
            show->battleUpdate.kind = TVSHOW_BATTLE_UPDATE;
            show->battleUpdate.active = TRUE;
            StringCopy(show->battleUpdate.playerName, gSaveBlock2Ptr->playerName);
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                show->battleUpdate.battleType = 2;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                show->battleUpdate.battleType = 1;
            }
            else
            {
                show->battleUpdate.battleType = 0;
            }
            show->battleUpdate.unk_14 = a1;
            show->battleUpdate.unk_16 = a2;
            show->battleUpdate.unk_02 = a3;
            StringCopy(name, gLinkPlayers[a0].name);
            StripExtCtrlCodes(name);
            StringCopy(show->battleUpdate.linkOpponentName, name);
            tv_store_id_2x(show);
            show->battleUpdate.language = gGameLanguage;
            if (show->battleUpdate.language == LANGUAGE_JAPANESE || gLinkPlayers[a0].language == LANGUAGE_JAPANESE)
            {
                show->battleUpdate.unk_1a = LANGUAGE_JAPANESE;
            }
            else
            {
                show->battleUpdate.unk_1a = gLinkPlayers[a0].language;
            }
        }
    }
}

bool8 Put3CheersForPokeblocksOnTheAir(const u8 *a0, u8 a1, u8 a2, u8 a3, u8 language)
{
    TVShow *show;
    u8 name[32];

    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot == -1)
    {
        return FALSE;
    }
    FindActiveBroadcastByShowType_SetScriptResult(TVSHOW_3_CHEERS_FOR_POKEBLOCKS);
    if (gScriptResult == 1)
    {
        return FALSE;
    }
    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
    show->threeCheers.kind = TVSHOW_3_CHEERS_FOR_POKEBLOCKS;
    show->threeCheers.active = TRUE;
    StringCopy(show->threeCheers.playerName, gSaveBlock2Ptr->playerName);
    StringCopy(name, a0);
    StripExtCtrlCodes(name);
    StringCopy(show->threeCheers.unk_04, name);
    show->threeCheers.unk_03_0 = a1;
    show->threeCheers.unk_03_3 = a2;
    show->threeCheers.unk_02 = a3;
    tv_store_id_2x(show);
    show->threeCheers.language = gGameLanguage;
    if (show->threeCheers.language == LANGUAGE_JAPANESE || language == LANGUAGE_JAPANESE)
    {
        show->threeCheers.unk_15 = LANGUAGE_JAPANESE;
    }
    else
    {
        show->threeCheers.unk_15 = language;
    }
    return TRUE;
}

void PutFanClubSpecialOnTheAir(void)
{
    TVShow *show;
    u8 name[32];
    u32 id;

    show = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8006];
    show->fanClubSpecial.unk_16 = gSpecialVar_0x8005 * 10;
    StringCopy(show->fanClubSpecial.playerName, gSaveBlock2Ptr->playerName);
    show->fanClubSpecial.kind = TVSHOW_FAN_CLUB_SPECIAL;
    show->fanClubSpecial.active = TRUE;
    id = player_id_to_dword();
    show->fanClubSpecial.idLo = id;
    show->fanClubSpecial.idHi = id >> 8;
    StringCopy(name, gStringVar1);
    StripExtCtrlCodes(name);
    StringCopy(show->fanClubSpecial.unk_0c, name);
    tv_store_id_2x(show);
    show->fanClubSpecial.language = gGameLanguage;
    if (show->fanClubSpecial.language == LANGUAGE_JAPANESE || gSaveBlock1Ptr->unk_31A0 == LANGUAGE_JAPANESE)
    {
        show->fanClubSpecial.unk_18 = LANGUAGE_JAPANESE;
    }
    else
    {
        show->fanClubSpecial.unk_18 = gSaveBlock1Ptr->unk_31A0;
    }
}

void ContestLiveUpdates_BeforeInterview_1(u8 a0)
{
    TVShow *show;

    DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show = &gSaveBlock1Ptr->tvShows[24];
        show->contestLiveUpdates.unk_0d = a0;
        show->contestLiveUpdates.kind = TVSHOW_CONTEST_LIVE_UPDATES;
    }
}

void ContestLiveUpdates_BeforeInterview_2(u8 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_0e = a0;
    }
}

void ContestLiveUpdates_BeforeInterview_3(u8 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_0f = a0;
    }
}

void ContestLiveUpdates_BeforeInterview_4(u16 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_10 = a0;
    }
}

void ContestLiveUpdates_BeforeInterview_5(u8 a0, u8 a1)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_02 = gUnknown_02039E00[a1].unk_00;
        StringCopy(show->contestLiveUpdates.unk_04, gUnknown_02039E00[a1].unk_0d);
        StripExtCtrlCodes(show->contestLiveUpdates.unk_04);
        show->contestLiveUpdates.unk_0c = a0;
        if (a1 + 1 > gUnknown_02039F30)
        {
            show->contestLiveUpdates.unk_1e = gLinkPlayers[0].language;
        }
        else if (gGameLanguage == LANGUAGE_JAPANESE || gLinkPlayers[a1].language == LANGUAGE_JAPANESE)
        {
            show->contestLiveUpdates.unk_1e = LANGUAGE_JAPANESE;
        }
        else
        {
            show->contestLiveUpdates.unk_1e = gLinkPlayers[a1].language;
        }
    }
}

static void InterviewAfter_BravoTrainerPokemonProfile(void)
{
    TVShow *show;
    TVShow *show2;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (show->bravoTrainer.kind == TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE)
    {
        show2 = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show2->bravoTrainer.kind = TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE;
        show2->bravoTrainer.active = TRUE;
        show2->bravoTrainer.species = show->bravoTrainer.species;
        StringCopy(show2->bravoTrainer.playerName, gSaveBlock2Ptr->playerName);
        StringCopy(show2->bravoTrainer.pokemonNickname, show->bravoTrainer.pokemonNickname);
        show2->bravoTrainer.contestCategory = show->bravoTrainer.contestCategory;
        show2->bravoTrainer.contestRank = show->bravoTrainer.contestRank;
        show2->bravoTrainer.move = show->bravoTrainer.move;
        show2->bravoTrainer.contestResult = show->bravoTrainer.contestResult;
        show2->bravoTrainer.contestCategory = show->bravoTrainer.contestCategory;
        tv_store_id_2x(show2);
        show2->bravoTrainer.language = gGameLanguage;
        if (show2->bravoTrainer.language == LANGUAGE_JAPANESE || show->bravoTrainer.pokemonNameLanguage == LANGUAGE_JAPANESE)
        {
            show2->bravoTrainer.pokemonNameLanguage = LANGUAGE_JAPANESE;
        }
        else
        {
            show2->bravoTrainer.pokemonNameLanguage = show->bravoTrainer.pokemonNameLanguage;
        }
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
    }
}

void BravoTrainerPokemonProfile_BeforeInterview1(u16 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sub_80EF7B4();
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
        show->bravoTrainer.move = a0;
        show->bravoTrainer.kind = TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE;
    }
}

void BravoTrainerPokemonProfile_BeforeInterview2(u8 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->bravoTrainer.contestResult = a0;
        show->bravoTrainer.contestCategory = gUnknown_02039F2C;
        show->bravoTrainer.contestRank = gUnknown_02039F2E;
        show->bravoTrainer.species = GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_SPECIES, NULL);
        GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_NICKNAME, show->bravoTrainer.pokemonNickname);
        StripExtCtrlCodes(show->bravoTrainer.pokemonNickname);
        show->bravoTrainer.pokemonNameLanguage = GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_LANGUAGE);
    }
}

static void InterviewAfter_BravoTrainerBattleTowerProfile(void)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
    show->bravoTrainerTower.kind = TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE;
    show->bravoTrainerTower.active = TRUE;
    StringCopy(show->bravoTrainerTower.trainerName, gSaveBlock2Ptr->playerName);
    StringCopy(show->bravoTrainerTower.pokemonName, gSaveBlock2Ptr->field_BD8);
    show->bravoTrainerTower.species = gSaveBlock2Ptr->field_BD4;
    show->bravoTrainerTower.defeatedSpecies = gSaveBlock2Ptr->field_BD6;
    show->bravoTrainerTower.numFights = sub_8164FCC(gSaveBlock2Ptr->field_D07, 0);
    show->bravoTrainerTower.var1c = gSaveBlock2Ptr->field_D06;
    if (gSaveBlock2Ptr->field_D07 == 0)
    {
        show->bravoTrainerTower.btLevel = 50;
    }
    else
    {
        show->bravoTrainerTower.btLevel = 100;
    }
    show->bravoTrainerTower.var1b = gSpecialVar_0x8004;
    tv_store_id_2x(show);
    show->bravoTrainerTower.language = gGameLanguage;
    if (show->bravoTrainerTower.language == LANGUAGE_JAPANESE || gSaveBlock2Ptr->field_BEB == LANGUAGE_JAPANESE)
    {
        show->bravoTrainerTower.pokemonNameLanguage = LANGUAGE_JAPANESE;
    }
    else
    {
        show->bravoTrainerTower.pokemonNameLanguage = gSaveBlock2Ptr->field_BEB;
    }
}

void SaveRecordedItemPurchasesForTVShow(void)
{
    void sub_80EF500(void);
    TVShow *show;
    u8 i;

    if (!(gSaveBlock1Ptr->location.mapGroup == 0x1a && gSaveBlock1Ptr->location.mapNum == 0x3c) && !(gSaveBlock1Ptr->location.mapGroup == 0x1a && gSaveBlock1Ptr->location.mapNum == 0x37) && !TV_BernoulliTrial(0x5555))
    {
        sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
        if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_SMART_SHOPPER, 0) != TRUE)
        {
            sub_80EF500();
            if (gUnknown_02039F80[0].quantity >= 20)
            {
                show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
                show->smartshopperShow.kind = TVSHOW_SMART_SHOPPER;
                show->smartshopperShow.active = FALSE;
                show->smartshopperShow.shopLocation = gMapHeader.regionMapSectionId;
                for (i = 0; i < 3; i ++)
                {
                    show->smartshopperShow.itemIds[i] = gUnknown_02039F80[i].itemId;
                    show->smartshopperShow.itemAmounts[i] = gUnknown_02039F80[i].quantity;
                }
                show->smartshopperShow.priceReduced = GetPriceReduction(1);
                StringCopy(show->smartshopperShow.playerName, gSaveBlock2Ptr->playerName);
                tv_store_id_3x(show);
                show->smartshopperShow.language = gGameLanguage;
            }
        }
    }
}

void PutNameRaterShowOnTheAir(void)
{
    TVShow *show;

    sub_80EF7A8();
    if (gScriptResult != 1)
    {
        GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_NICKNAME, gStringVar1);
        if (StringLength(gSaveBlock2Ptr->playerName) > 1 && StringLength(gStringVar1) > 1)
        {
            show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
            show->nameRaterShow.kind = TVSHOW_NAME_RATER_SHOW;
            show->nameRaterShow.active = TRUE;
            show->nameRaterShow.species = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES, NULL);
            show->nameRaterShow.random = Random() % 3;
            show->nameRaterShow.random2 = Random() % 2;
            show->nameRaterShow.var1C = sub_80EFA24(show->nameRaterShow.species);
            StringCopy(show->nameRaterShow.trainerName, gSaveBlock2Ptr->playerName);
            GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_NICKNAME, show->nameRaterShow.pokemonName);
            StripExtCtrlCodes(show->nameRaterShow.pokemonName);
            tv_store_id_2x(show);
            show->nameRaterShow.language = gGameLanguage;
            show->nameRaterShow.pokemonNameLanguage = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LANGUAGE);
        }
    }
}

void StartMassOutbreak(void)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004];
    gSaveBlock1Ptr->outbreakPokemonSpecies = show->massOutbreak.species;
    gSaveBlock1Ptr->outbreakLocationMapNum = show->massOutbreak.locationMapNum;
    gSaveBlock1Ptr->outbreakLocationMapGroup = show->massOutbreak.locationMapGroup;
    gSaveBlock1Ptr->outbreakPokemonLevel = show->massOutbreak.level;
    gSaveBlock1Ptr->outbreakUnk1 = show->massOutbreak.var02;
    gSaveBlock1Ptr->outbreakUnk2 = show->massOutbreak.var0E;
    gSaveBlock1Ptr->outbreakPokemonMoves[0] = show->massOutbreak.moves[0];
    gSaveBlock1Ptr->outbreakPokemonMoves[1] = show->massOutbreak.moves[1];
    gSaveBlock1Ptr->outbreakPokemonMoves[2] = show->massOutbreak.moves[2];
    gSaveBlock1Ptr->outbreakPokemonMoves[3] = show->massOutbreak.moves[3];
    gSaveBlock1Ptr->outbreakUnk4 = show->massOutbreak.var03;
    gSaveBlock1Ptr->outbreakPokemonProbability = show->massOutbreak.probability;
    gSaveBlock1Ptr->outbreakDaysLeft = 2;
}

void PutLilycoveContestLadyShowOnTheAir(void)
{
    TVShow *show;

    sub_80EFA88();
    if (gScriptResult != TRUE)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        sub_818E848(&show->contestLiveUpdates2.language);
        show->contestLiveUpdates2.unk_18 = 2;
        show->contestLiveUpdates2.kind = TVSHOW_CONTEST_LIVE_UPDATES_2;
        show->contestLiveUpdates2.active = TRUE;
        sub_818E81C(show->contestLiveUpdates2.playerName);
        sub_818E7E0(&show->contestLiveUpdates2.contestCategory, show->contestLiveUpdates2.categoryName);
        show->contestLiveUpdates2.pokeblockState = sub_818E880();
        tv_store_id_2x(show);
    }
}

static void InterviewAfter_FanClubLetter(void)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
    show->fanclubLetter.kind = TVSHOW_FAN_CLUB_LETTER;
    show->fanclubLetter.active = TRUE;
    StringCopy(show->fanclubLetter.playerName, gSaveBlock2Ptr->playerName);
    show->fanclubLetter.species = GetMonData(&gPlayerParty[sub_8139688()], MON_DATA_SPECIES, NULL);
    tv_store_id_2x(show);
    show->fanclubLetter.language = gGameLanguage;
}

static void InterviewAfter_RecentHappenings(void)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
    show->recentHappenings.kind = TVSHOW_RECENT_HAPPENINGS;
    show->recentHappenings.active = TRUE;
    StringCopy(show->recentHappenings.playerName, gSaveBlock2Ptr->playerName);
    show->recentHappenings.var02 = 0;
    tv_store_id_2x(show);
    show->recentHappenings.language = gGameLanguage;
}

static void InterviewAfter_PkmnFanClubOpinions(void)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
    show->fanclubOpinions.kind = TVSHOW_PKMN_FAN_CLUB_OPINIONS;
    show->fanclubOpinions.active = TRUE;
    show->fanclubOpinions.friendshipHighNybble = GetMonData(&gPlayerParty[sub_8139688()], MON_DATA_FRIENDSHIP, NULL) >> 4;
    show->fanclubOpinions.var04B = gSpecialVar_0x8007;
    StringCopy(show->fanclubOpinions.playerName, gSaveBlock2Ptr->playerName);
    GetMonData(&gPlayerParty[sub_8139688()], MON_DATA_NICKNAME, show->fanclubOpinions.nickname);
    StripExtCtrlCodes(show->fanclubOpinions.nickname);
    show->fanclubOpinions.species = GetMonData(&gPlayerParty[sub_8139688()], MON_DATA_SPECIES, NULL);
    tv_store_id_2x(show);
    show->fanclubOpinions.language = gGameLanguage;
    if (gGameLanguage == LANGUAGE_JAPANESE || GetMonData(&gPlayerParty[sub_8139688()], MON_DATA_LANGUAGE) == LANGUAGE_JAPANESE)
    {
        show->fanclubOpinions.var0E = LANGUAGE_JAPANESE;
    }
    else
    {
        show->fanclubOpinions.var0E = GetMonData(&gPlayerParty[sub_8139688()], MON_DATA_LANGUAGE);
    }
}

static void InterviewAfter_DummyShow4()
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
}

static void sub_80ED718(void)
{
    u8 i;
    u16 outbreakIdx;
    TVShow *show;

    if (FlagGet(SYS_GAME_CLEAR))
    {
        for (i = 0; i < 24; i ++)
        {
            if (gSaveBlock1Ptr->tvShows[i].common.kind == TVSHOW_MASS_OUTBREAK)
            {
                return;
            }
        }
        if (!TV_BernoulliTrial(0x0147))
        {
            sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
            if (sCurTVShowSlot != -1)
            {
                outbreakIdx = Random() % ARRAY_COUNT(gPokeOutbreakSpeciesList);
                show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
                show->massOutbreak.kind = TVSHOW_MASS_OUTBREAK;
                show->massOutbreak.active = TRUE;
                show->massOutbreak.level = gPokeOutbreakSpeciesList[outbreakIdx].level;
                show->massOutbreak.var02 = 0;
                show->massOutbreak.var03 = 0;
                show->massOutbreak.species = gPokeOutbreakSpeciesList[outbreakIdx].species;
                show->massOutbreak.var0E = 0;
                show->massOutbreak.moves[0] = gPokeOutbreakSpeciesList[outbreakIdx].moves[0];
                show->massOutbreak.moves[1] = gPokeOutbreakSpeciesList[outbreakIdx].moves[1];
                show->massOutbreak.moves[2] = gPokeOutbreakSpeciesList[outbreakIdx].moves[2];
                show->massOutbreak.moves[3] = gPokeOutbreakSpeciesList[outbreakIdx].moves[3];
                show->massOutbreak.locationMapNum = gPokeOutbreakSpeciesList[outbreakIdx].location;
                show->massOutbreak.locationMapGroup = 0;
                show->massOutbreak.var12 = 0;
                show->massOutbreak.probability = 50;
                show->massOutbreak.var15 = 0;
                show->massOutbreak.daysLeft = 1;
                tv_store_id_2x(show);
                show->massOutbreak.language = gGameLanguage;
            }
        }
    }
}

void EndMassOutbreak(void)
{
    gSaveBlock1Ptr->outbreakPokemonSpecies = SPECIES_NONE;
    gSaveBlock1Ptr->outbreakLocationMapNum = 0;
    gSaveBlock1Ptr->outbreakLocationMapGroup = 0;
    gSaveBlock1Ptr->outbreakPokemonLevel = 0;
    gSaveBlock1Ptr->outbreakUnk1 = 0;
    gSaveBlock1Ptr->outbreakUnk2 = 0;
    gSaveBlock1Ptr->outbreakPokemonMoves[0] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakPokemonMoves[1] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakPokemonMoves[2] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakPokemonMoves[3] = MOVE_NONE;
    gSaveBlock1Ptr->outbreakUnk4 = 0;
    gSaveBlock1Ptr->outbreakPokemonProbability = 0;
    gSaveBlock1Ptr->outbreakDaysLeft = 0;
}

void sub_80ED888(u16 days)
{
    static void sub_80ED8B4(u16);
    static void UpdateMassOutbreakTimeLeft(u16);
    void sub_80EF120(u16);
    static void sub_80EDA48(u16);
    void sub_80EEB98(u16);

    sub_80ED8B4(days);
    UpdateMassOutbreakTimeLeft(days);
    sub_80EF120(days);
    sub_80EDA48(days);
    sub_80EEB98(days);
}

void sub_80ED8B4(u16 days)
{
    u8 i;
    TVShow *show;

    if (gSaveBlock1Ptr->outbreakPokemonSpecies == SPECIES_NONE)
    {
        for (i = 0; i < 24; i ++)
        {
            if (gSaveBlock1Ptr->tvShows[i].massOutbreak.kind == TVSHOW_MASS_OUTBREAK && gSaveBlock1Ptr->tvShows[i].massOutbreak.active == TRUE)
            {
                show = &gSaveBlock1Ptr->tvShows[i];
                if (show->massOutbreak.daysLeft < days)
                {
                    show->massOutbreak.daysLeft = 0;
                }
                else
                {
                    show->massOutbreak.daysLeft -= days;
                }
                break;
            }
        }
    }
}

void UpdateMassOutbreakTimeLeft(u16 days)
{
    if (gSaveBlock1Ptr->outbreakDaysLeft <= days)
    {
        EndMassOutbreak();
    }
    else
    {
        gSaveBlock1Ptr->outbreakDaysLeft -= days;
    }
}

void sub_80ED950(bool8 flag)
{
    static void PutFishingAdviceShowOnTheAir(void);

    if (flag)
    {
        if (gUnknown_0203A026 >> 8 > 4)
        {
            PutFishingAdviceShowOnTheAir();
        }
        gUnknown_0203A026 &= 0xFF;
        if (gUnknown_0203A026 != 0xFF)
        {
            gUnknown_0203A026 += 0x01;
        }
    }
    else
    {
        if ((u8)gUnknown_0203A026 > 4)
        {
            PutFishingAdviceShowOnTheAir();
        }
        gUnknown_0203A026 &= 0xFF00;
        if (gUnknown_0203A026 >> 8 != 0xFF)
        {
            gUnknown_0203A026 += 0x0100;
        }
    }
}

static void PutFishingAdviceShowOnTheAir(void)
{
    TVShow *show;

     sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_FISHING_ADVICE, 0) != TRUE)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->pokemonAngler.kind = TVSHOW_FISHING_ADVICE;
        show->pokemonAngler.active = FALSE;
        show->pokemonAngler.var02 = gUnknown_0203A026;
        show->pokemonAngler.var03 = gUnknown_0203A026 >> 8;
        show->pokemonAngler.species = gUnknown_0203A024;
        StringCopy(show->pokemonAngler.playerName, gSaveBlock2Ptr->playerName);
        tv_store_id_3x(show);
        show->pokemonAngler.language = gGameLanguage;
    }
}

void sub_80EDA3C(u16 species)
{
    gUnknown_0203A024 = species;
}

static void sub_80EDA48(u16 days)
{
    static void sub_80EDA80(void);
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (show->worldOfMasters.kind == TVSHOW_WORLD_OF_MASTERS)
    {
        if (show->worldOfMasters.var02 >= 20)
        {
            sub_80EDA80();
        }
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
    }
}

static void sub_80EDA80(void)
{
    TVShow *show;
    TVShow *show2;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (!TV_BernoulliTrial(0xFFFF))
    {
        sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
        if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_WORLD_OF_MASTERS, 0) != TRUE)
        {
            show2 = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
            show2->worldOfMasters.kind = TVSHOW_WORLD_OF_MASTERS;
            show2->worldOfMasters.active = FALSE;
            show2->worldOfMasters.var02 = show->worldOfMasters.var02;
            show2->worldOfMasters.steps = GetGameStat(GAME_STAT_STEPS) - show->worldOfMasters.steps;
            show2->worldOfMasters.caughtPoke = show->worldOfMasters.caughtPoke;
            show2->worldOfMasters.species = show->worldOfMasters.species;
            show2->worldOfMasters.location = show->worldOfMasters.location;
            StringCopy(show2->worldOfMasters.playerName, gSaveBlock2Ptr->playerName);
            tv_store_id_3x(show2);
            show2->worldOfMasters.language = gGameLanguage;
            DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
        }
    }
}

void sub_80EDB44(void)
{
    TVShow *show;
    u32 i;
    u8 nBadges;

    sub_80EF46C(TVSHOW_TODAYS_RIVAL_TRAINER, 1);
    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->rivalTrainer.kind = TVSHOW_TODAYS_RIVAL_TRAINER;
        show->rivalTrainer.active = FALSE;
        for (i = BADGE01_GET, nBadges = 0; i < BADGE01_GET + 8; i ++)
        {
            if (FlagGet(i))
            {
                nBadges ++;
            }
        }
        show->rivalTrainer.badgeCount = nBadges;
        if (IsNationalPokedexEnabled())
        {
            show->rivalTrainer.dexCount = pokedex_count(0x01);
        }
        else
        {
            show->rivalTrainer.dexCount = sub_80C0844(0x01);
        }
        show->rivalTrainer.location = gMapHeader.regionMapSectionId;
        show->rivalTrainer.mapDataId = gMapHeader.mapDataId;
        show->rivalTrainer.unk05 = 0;
        show->rivalTrainer.unk06 = 0;
        for (i = 0; i < 7; i ++)
        {
            if (FlagGet(gUnknown_0858D0DE[i]) == TRUE)
            {
                show->rivalTrainer.unk05 ++;
            }
            if (FlagGet(gUnknown_0858D0D0[i]) == TRUE)
            {
                show->rivalTrainer.unk06 ++;
            }
        }
        show->rivalTrainer.battlePoints = gSaveBlock2Ptr->frontierBattlePoints;
        StringCopy(show->rivalTrainer.playerName, gSaveBlock2Ptr->playerName);
        tv_store_id_3x(show);
        show->rivalTrainer.language = gGameLanguage;
    }
}

void sub_80EDC60(const u16 *words)
{
    TVShow *show;

    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_TREND_WATCHER, 0) != TRUE)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->trendWatcher.kind = TVSHOW_TREND_WATCHER;
        show->trendWatcher.active = FALSE;
        show->trendWatcher.gender = gSaveBlock2Ptr->playerGender;
        show->trendWatcher.words[0] = words[0];
        show->trendWatcher.words[1] = words[1];
        StringCopy(show->trendWatcher.playerName, gSaveBlock2Ptr->playerName);
        tv_store_id_3x(show);
        show->trendWatcher.language = gGameLanguage;
    }
}

void sub_80EDCE8(void)
{
    TVShow *show;

    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_TREASURE_INVESTIGATORS, 0) != TRUE)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->treasureInvestigators.kind = TVSHOW_TREASURE_INVESTIGATORS;
        show->treasureInvestigators.active = FALSE;
        show->treasureInvestigators.unk02 = gSpecialVar_0x8005;
        show->treasureInvestigators.location = gMapHeader.regionMapSectionId;
        show->treasureInvestigators.mapDataId = gMapHeader.mapDataId;
        StringCopy(show->treasureInvestigators.playerName, gSaveBlock2Ptr->playerName);
        tv_store_id_3x(show);
        show->treasureInvestigators.language = gGameLanguage;
    }
}

void sub_80EDD78(u16 a0)
{
    TVShow *show;
    bool8 flag;
    u16 v0;

    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_FIND_THAT_GAMER, 0) != TRUE)
    {
        flag = FALSE;
        switch (gUnknown_0203A02A)
        {
            case FALSE:
                if (a0 >= gUnknown_0203A028 + 200)
                {
                    flag = TRUE;
                    v0 = a0 - gUnknown_0203A028;
                    break;
                }
                if (gUnknown_0203A028 >= 100 && a0 <= gUnknown_0203A028 - 100)
                {
                    v0 = gUnknown_0203A028 - a0;
                    break;
                }
                return;
            case TRUE:
                if (a0 >= gUnknown_0203A028 + 50)
                {
                    flag = TRUE;
                    v0 = a0 - gUnknown_0203A028;
                    break;
                }
                if (gUnknown_0203A028 >= 50 && a0 <= gUnknown_0203A028 - 50)
                {
                    v0 = gUnknown_0203A028 - a0;
                    break;
                }
                return;
            default:
                return;
        }
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->findThatGamer.kind = TVSHOW_FIND_THAT_GAMER;
        show->findThatGamer.active = FALSE;
        show->findThatGamer.unk04 = v0;
        show->findThatGamer.unk03 = gUnknown_0203A02A;
        show->findThatGamer.unk02 = flag;
        StringCopy(show->findThatGamer.playerName, gSaveBlock2Ptr->playerName);
        tv_store_id_3x(show);
        show->findThatGamer.language = gGameLanguage;
    }
}

void sub_80EDE70(u16 a0)
{
    gUnknown_0203A02A = FALSE;
    gUnknown_0203A028 = a0;
}

void sub_80EDE84(u16 a0)
{
    gUnknown_0203A02A = TRUE;
    gUnknown_0203A028 = a0;
}

#ifdef NONMATCHING // Register allocation shenanigans
void sub_80EDE98(TVShow *show)
{
    u8 i;
    u8 j;
    u16 k;
    u8 n;
    u8 deco;
    u8 x;

    for (i = 0; i < 16; i ++)
    {
        sTV_DecorationsBuffer[i] = 0;
    }
    for (i = 0, n = 0; i < 16; i ++)
    {
        deco = gSaveBlock1Ptr->secretBases[0].decorations[i];
        if (deco)
        {
            for (j = 0; j < 16; j ++)
            {
                if (sTV_DecorationsBuffer[j] == 0)
                {
                    sTV_DecorationsBuffer[j] = deco;
                    n ++;
                    break;
                }
                if (sTV_DecorationsBuffer[j] == deco)
                {
                    break;
                }
            }
        }
    }
    if (n > 4)
    {
        show->secretBaseVisit.nDecorations = 4;
    }
    else
    {
        show->secretBaseVisit.nDecorations = n;
    }
    switch (show->secretBaseVisit.nDecorations)
    {
        case 0:
            break;
        case 1:
            show->secretBaseVisit.decorations[0] = sTV_DecorationsBuffer[0];
            break;
        default:
            for (k = 0; k < n * n; k ++)
            {
                i = Random() % n;
                j = Random() % n;
                x = sTV_DecorationsBuffer[i];
                sTV_DecorationsBuffer[i] = sTV_DecorationsBuffer[j];
                sTV_DecorationsBuffer[j] = x;
            }
            for (i = 0; i < show->secretBaseVisit.nDecorations; i ++)
            {
                show->secretBaseVisit.decorations[i] = sTV_DecorationsBuffer[i];
            }
            break;
    }
}
#else
__attribute__((naked))
void sub_80EDE98(TVShow *show)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r9\n"
                    "\tmov r6, r8\n"
                    "\tpush {r6,r7}\n"
                    "\tmov r8, r0\n"
                    "\tmovs r3, 0\n"
                    "\tldr r6, =sTV_DecorationsBuffer\n"
                    "\tldr r7, =gSaveBlock1Ptr\n"
                    "\tadds r2, r6, 0\n"
                    "\tmovs r1, 0\n"
                    "_080EDEAC:\n"
                    "\tadds r0, r3, r2\n"
                    "\tstrb r1, [r0]\n"
                    "\tadds r0, r3, 0x1\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r3, r0, 24\n"
                    "\tcmp r3, 0xF\n"
                    "\tbls _080EDEAC\n"
                    "\tmovs r3, 0\n"
                    "\tmovs r5, 0\n"
                    "_080EDEBE:\n"
                    "\tldr r0, [r7]\n"
                    "\tldr r1, =0x00001aae\n"
                    "\tadds r0, r1\n"
                    "\tadds r0, r3\n"
                    "\tldrb r4, [r0]\n"
                    "\tadds r3, 0x1\n"
                    "\tcmp r4, 0\n"
                    "\tbeq _080EDF0A\n"
                    "\tmovs r1, 0\n"
                    "\tldrb r0, [r6]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080EDEE8\n"
                    "\tstrb r4, [r6]\n"
                    "\tb _080EDF04\n"
                    "\t.pool\n"
                    "_080EDEE8:\n"
                    "\tadds r0, r1, r6\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, r4\n"
                    "\tbeq _080EDF0A\n"
                    "\tadds r0, r1, 0x1\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r1, r0, 24\n"
                    "\tcmp r1, 0xF\n"
                    "\tbhi _080EDF0A\n"
                    "\tadds r2, r1, r6\n"
                    "\tldrb r0, [r2]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080EDEE8\n"
                    "\tstrb r4, [r2]\n"
                    "_080EDF04:\n"
                    "\tadds r0, r5, 0x1\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r5, r0, 24\n"
                    "_080EDF0A:\n"
                    "\tlsls r0, r3, 24\n"
                    "\tlsrs r3, r0, 24\n"
                    "\tcmp r3, 0xF\n"
                    "\tbls _080EDEBE\n"
                    "\tcmp r5, 0x4\n"
                    "\tbls _080EDF1E\n"
                    "\tmovs r0, 0x4\n"
                    "\tmov r1, r8\n"
                    "\tstrb r0, [r1, 0x3]\n"
                    "\tb _080EDF22\n"
                    "_080EDF1E:\n"
                    "\tmov r0, r8\n"
                    "\tstrb r5, [r0, 0x3]\n"
                    "_080EDF22:\n"
                    "\tmov r1, r8\n"
                    "\tldrb r0, [r1, 0x3]\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080EDFA4\n"
                    "\tcmp r0, 0x1\n"
                    "\tbne _080EDF34\n"
                    "\tldrb r0, [r6]\n"
                    "\tstrb r0, [r1, 0x4]\n"
                    "\tb _080EDFA4\n"
                    "_080EDF34:\n"
                    "\tmovs r6, 0\n"
                    "\tadds r7, r5, 0\n"
                    "\tmuls r7, r5\n"
                    "\tcmp r6, r7\n"
                    "\tbge _080EDF7E\n"
                    "\tldr r0, =sTV_DecorationsBuffer\n"
                    "\tmov r9, r0\n"
                    "_080EDF42:\n"
                    "\tbl Random\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tadds r1, r5, 0\n"
                    "\tbl __modsi3\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r4, r0, 24\n"
                    "\tbl Random\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tadds r1, r5, 0\n"
                    "\tbl __modsi3\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r1, r0, 24\n"
                    "\tmov r0, r9\n"
                    "\tadds r2, r4, r0\n"
                    "\tldrb r3, [r2]\n"
                    "\tadd r1, r9\n"
                    "\tldrb r0, [r1]\n"
                    "\tstrb r0, [r2]\n"
                    "\tstrb r3, [r1]\n"
                    "\tadds r0, r6, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "\tcmp r6, r7\n"
                    "\tblt _080EDF42\n"
                    "_080EDF7E:\n"
                    "\tmovs r3, 0\n"
                    "\tmov r1, r8\n"
                    "\tldrb r1, [r1, 0x3]\n"
                    "\tcmp r3, r1\n"
                    "\tbcs _080EDFA4\n"
                    "\tmov r2, r8\n"
                    "\tadds r2, 0x4\n"
                    "\tldr r4, =sTV_DecorationsBuffer\n"
                    "_080EDF8E:\n"
                    "\tadds r1, r2, r3\n"
                    "\tadds r0, r3, r4\n"
                    "\tldrb r0, [r0]\n"
                    "\tstrb r0, [r1]\n"
                    "\tadds r0, r3, 0x1\n"
                    "\tlsls r0, 24\n"
                    "\tlsrs r3, r0, 24\n"
                    "\tmov r0, r8\n"
                    "\tldrb r0, [r0, 0x3]\n"
                    "\tcmp r3, r0\n"
                    "\tbcc _080EDF8E\n"
                    "_080EDFA4:\n"
                    "\tpop {r3,r4}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif

void sub_80EDFB4(TVShow *show)
{
    u8 i;
    u16 move;
    u16 j;
    u8 nMoves;
    u8 nPokemon;
    u16 sum;

    for (i = 0, nPokemon = 0; i < PARTY_SIZE; i ++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            sTV_SecretBaseVisitMonsTemp[nPokemon].level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            sTV_SecretBaseVisitMonsTemp[nPokemon].species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
            nMoves = 0;
            move = GetMonData(&gPlayerParty[i], MON_DATA_MOVE1);
            if (move != MOVE_NONE)
            {
                sTV_SecretBaseVisitMovesTemp[nMoves] = move;
                nMoves ++;
            }
            move = GetMonData(&gPlayerParty[i], MON_DATA_MOVE2);
            if (move != MOVE_NONE)
            {
                sTV_SecretBaseVisitMovesTemp[nMoves] = move;
                nMoves ++;
            }
            move = GetMonData(&gPlayerParty[i], MON_DATA_MOVE3);
            if (move != MOVE_NONE)
            {
                sTV_SecretBaseVisitMovesTemp[nMoves] = move;
                nMoves ++;
            }
            move = GetMonData(&gPlayerParty[i], MON_DATA_MOVE4);
            if (move != MOVE_NONE)
            {
                sTV_SecretBaseVisitMovesTemp[nMoves] = move;
                nMoves ++;
            }
            sTV_SecretBaseVisitMonsTemp[nPokemon].move = sTV_SecretBaseVisitMovesTemp[Random() % nMoves];
            nPokemon ++;
        }
    }
    for (i = 0, sum = 0; i < nPokemon; i ++)
    {
        sum += sTV_SecretBaseVisitMonsTemp[i].level;
    }
    show->secretBaseVisit.unk02 = sum / nPokemon;
    j = Random() % nPokemon;
    show->secretBaseVisit.species = sTV_SecretBaseVisitMonsTemp[j].species;
    show->secretBaseVisit.move = sTV_SecretBaseVisitMonsTemp[j].move;
}

void sub_80EE104(void)
{
    TVShow *show;

    sub_80EF46C(TVSHOW_SECRET_BASE_VISIT, 1);
    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->secretBaseVisit.kind = TVSHOW_SECRET_BASE_VISIT;
        show->secretBaseVisit.active = FALSE;
        StringCopy(show->secretBaseVisit.playerName, gSaveBlock2Ptr->playerName);
        sub_80EDE98(show);
        sub_80EDFB4(show);
        tv_store_id_3x(show);
        show->secretBaseVisit.language = gGameLanguage;
    }
}

void sub_80EE184(void)
{
    TVShow *show;
    u8 i;
    u16 balls;

    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_BREAKING_NEWS, 0) != TRUE)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->breakingNews.kind = TVSHOW_BREAKING_NEWS;
        show->breakingNews.active = FALSE;
        balls = 0;
        for (i = 0; i < 11; i ++)
        {
            balls += gBattleResults.catchAttempts[i];
        }
        if (gBattleResults.usedMasterBall)
        {
            balls ++;
        }
        show->breakingNews.location = gMapHeader.regionMapSectionId;
        StringCopy(show->breakingNews.playerName, gSaveBlock2Ptr->playerName);
        show->breakingNews.poke1Species = gBattleResults.poke1Species;
        switch (gBattleOutcome)
        {
            case BATTLE_LOST:
            case BATTLE_DREW:
                show->breakingNews.kind = TVSHOW_OFF_AIR;
                return;
            case BATTLE_CAUGHT:
                show->breakingNews.outcome = 0;
                break;
            case BATTLE_WON:
                show->breakingNews.outcome = 1;
                break;
            case BATTLE_RAN:
            case BATTLE_PLAYER_TELEPORTED:
            case BATTLE_SAFARI_OUT_OF_BALLS:
                show->breakingNews.outcome = 2;
                break;
            case BATTLE_POKE_FLED:
            case BATTLE_OPPONENT_TELEPORTED:
                show->breakingNews.outcome = 3;
                break;
        }
        show->breakingNews.lastOpponentSpecies = gBattleResults.lastOpponentSpecies;
        switch (show->breakingNews.outcome)
        {
            case 0:
                if (gBattleResults.usedMasterBall)
                {
                    show->breakingNews.caughtMonBall = ITEM_MASTER_BALL;
                }
                else
                {
                    show->breakingNews.caughtMonBall = gBattleResults.caughtMonBall;
                }
                show->breakingNews.balls = balls;
                break;
            case 1:
                show->breakingNews.lastUsedMove = gBattleResults.lastUsedMove;
                break;
            case 2:
                break;
            case 3:
                break;
        }
        tv_store_id_3x(show);
        show->breakingNews.language = gGameLanguage;
    }
}

void sub_80EE2CC(void)
{
    TVShow *show;

    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_LOTTO_WINNER, 0) != 1)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->lottoWinner.kind = TVSHOW_LOTTO_WINNER;
        show->lottoWinner.active = FALSE;
        StringCopy(show->lottoWinner.playerName, gSaveBlock2Ptr->playerName);
        show->lottoWinner.unk04 = 4 - gSpecialVar_0x8004;
        show->lottoWinner.unk02 = gSpecialVar_0x8005;
        tv_store_id_3x(show);
        show->lottoWinner.language = gGameLanguage;
    }
}

void sub_80EE35C(u16 a0, u16 a1, u8 a2, const u16 *a3, u16 a4)
{
    TVShow *show;
    u8 i;
    u8 j;

    sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_BATTLE_SEMINAR, 0) != 1)
    {
        show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show->battleSeminar.kind = TVSHOW_BATTLE_SEMINAR;
        show->battleSeminar.active = FALSE;
        StringCopy(show->battleSeminar.playerName, gSaveBlock2Ptr->playerName);
        show->battleSeminar.unk04 = a0;
        show->battleSeminar.unk06 = a1;
        show->battleSeminar.unk02 = a3[a2];
        for (i = 0, j = 0; i < 4; i ++)
        {
            if (i != a2 && a3[i])
            {
                show->battleSeminar.unk08[j] = a3[i];
                j ++;
            }
        }
        show->battleSeminar.unk10 = j;
        show->battleSeminar.unk0e = a4;
        tv_store_id_3x(show);
        show->battleSeminar.language = gGameLanguage;
    }
}

asm(".section .text.dotvshow");

void DoTVShow(void)
{
    void DoTVShowPokemonFanClubLetter(void);
    void DoTVShowRecentHappenings(void);
    void DoTVShowPokemonFanClubOpinions(void);
    void DoTVShowDummiedOut(void);
    void DoTVShowPokemonNewsMassOutbreak(void);
    void DoTVShowBravoTrainerPokemonProfile(void);
    void DoTVShowBravoTrainerBattleTower(void);
    void DoTVShowPokemonTodaySuccessfulCapture(void);
    void DoTVShowTodaysSmartShopper(void);
    void DoTVShowTheNameRaterShow(void);
    void DoTVShowPokemonContestLiveUpdates(void);
    void DoTVShowPokemonBattleUpdate(void);
    void DoTVShow3CheersForPokeblocks(void);
    void DoTVShowPokemonTodayFailedCapture(void);
    void DoTVShowPokemonAngler(void);
    void DoTVShowTheWorldOfMasters(void);
    void DoTVShowTodaysRivalTrainer(void);
    void DoTVShowDewfordTrendWatcherNetwork(void);
    void DoTVShowHoennTreasureInvestigators(void);
    void DoTVShowFindThatGamer(void);
    void DoTVShowBreakingNewsTV(void);
    void DoTVShowSecretBaseVisit(void);
    void DoTVShowPokemonLotterWinnerFlashReport(void);
    void DoTVShowThePokemonBattleSeminar(void);
    void DoTVShowTrainerFanClubSpecial(void);
    void DoTVShowTrainerFanClub(void);
    void DoTVShowSpotTheCuties(void);
    void DoTVShowPokemonNewsBattleFrontier(void);
    void DoTVShowWhatsNo1InHoennToday(void);
    void DoTVShowSecretBaseSecrets(void);
    void DoTVShowSafariFanClub(void);
    void DoTVShowPokemonContestLiveUpdates2(void);

    if (gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].common.active)
    {
        switch (gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].common.kind)
        {
            case TVSHOW_FAN_CLUB_LETTER:
                DoTVShowPokemonFanClubLetter();
                break;
            case TVSHOW_RECENT_HAPPENINGS:
                DoTVShowRecentHappenings();
                break;
            case TVSHOW_PKMN_FAN_CLUB_OPINIONS:
                DoTVShowPokemonFanClubOpinions();
                break;
            case TVSHOW_UNKN_SHOWTYPE_04:
                DoTVShowDummiedOut();
                break;
            case TVSHOW_MASS_OUTBREAK:
                DoTVShowPokemonNewsMassOutbreak();
                break;
            case TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE:
                DoTVShowBravoTrainerPokemonProfile();
                break;
            case TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE:
                DoTVShowBravoTrainerBattleTower();
                break;
            case TVSHOW_POKEMON_TODAY_CAUGHT:
                DoTVShowPokemonTodaySuccessfulCapture();
                break;
            case TVSHOW_SMART_SHOPPER:
                DoTVShowTodaysSmartShopper();
                break;
            case TVSHOW_NAME_RATER_SHOW:
                DoTVShowTheNameRaterShow();
                break;
            case TVSHOW_CONTEST_LIVE_UPDATES:
                DoTVShowPokemonContestLiveUpdates();
                break;
            case TVSHOW_BATTLE_UPDATE:
                DoTVShowPokemonBattleUpdate();
                break;
            case TVSHOW_3_CHEERS_FOR_POKEBLOCKS:
                DoTVShow3CheersForPokeblocks();
                break;
            case TVSHOW_POKEMON_TODAY_FAILED:
                DoTVShowPokemonTodayFailedCapture();
                break;
            case TVSHOW_FISHING_ADVICE:
                DoTVShowPokemonAngler();
                break;
            case TVSHOW_WORLD_OF_MASTERS:
                DoTVShowTheWorldOfMasters();
                break;
            case TVSHOW_TODAYS_RIVAL_TRAINER:
                DoTVShowTodaysRivalTrainer();
                break;
            case TVSHOW_TREND_WATCHER:
                DoTVShowDewfordTrendWatcherNetwork();
                break;
            case TVSHOW_TREASURE_INVESTIGATORS:
                DoTVShowHoennTreasureInvestigators();
                break;
            case TVSHOW_FIND_THAT_GAMER:
                DoTVShowFindThatGamer();
                break;
            case TVSHOW_BREAKING_NEWS:
                DoTVShowBreakingNewsTV();
                break;
            case TVSHOW_SECRET_BASE_VISIT:
                DoTVShowSecretBaseVisit();
                break;
            case TVSHOW_LOTTO_WINNER:
                DoTVShowPokemonLotterWinnerFlashReport();
                break;
            case TVSHOW_BATTLE_SEMINAR:
                DoTVShowThePokemonBattleSeminar();
                break;
            case TVSHOW_FAN_CLUB_SPECIAL:
                DoTVShowTrainerFanClubSpecial();
                break;
            case TVSHOW_TRAINER_FAN_CLUB:
                DoTVShowTrainerFanClub();
                break;
            case TVSHOW_CUTIES:
                DoTVShowSpotTheCuties();
                break;
            case TVSHOW_FRONTIER:
                DoTVShowPokemonNewsBattleFrontier();
                break;
            case TVSHOW_NUMBER_ONE:
                DoTVShowWhatsNo1InHoennToday();
                break;
            case TVSHOW_SECRET_BASE_SECRETS:
                DoTVShowSecretBaseSecrets();
                break;
            case TVSHOW_SAFARI_FAN_CLUB:
                DoTVShowSafariFanClub();
                break;
            case TVSHOW_CONTEST_LIVE_UPDATES_2:
                DoTVShowPokemonContestLiveUpdates2();
                break;
        }
    }
}

void DoTVShowBravoTrainerPokemonProfile(void)
{
    TVShow *show;
    u8 state;

    show = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004];
    gScriptResult = 0;
    state = sTVShowState;
    switch (state)
    {
        case 0:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyContestCategoryToStringVar(1, show->bravoTrainer.contestCategory);
            CopyContestRankToStringVar(2, show->bravoTrainer.contestRank);
            if (!StringCompare(gSpeciesNames[show->bravoTrainer.species], show->bravoTrainer.pokemonNickname))
                sTVShowState = 8;
            else
                sTVShowState = 1;
            break;
        case 1:
            StringCopy(gStringVar1, gSpeciesNames[show->bravoTrainer.species]);
            TVShowConvertInternationalString(gStringVar2, show->bravoTrainer.pokemonNickname, show->bravoTrainer.pokemonNameLanguage);
            CopyContestCategoryToStringVar(2, show->bravoTrainer.contestCategory);
            sTVShowState = 2;
            break;
        case 2:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            if (show->bravoTrainer.contestResult == 0) // placed first
                sTVShowState = 3;
            else
                sTVShowState = 4;
            break;
        case 3:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyEasyChatWord(gStringVar2, show->bravoTrainer.ecWords[0]);
            TV_ConvertNumberToOrdinal(2, show->bravoTrainer.contestResult + 1);
            sTVShowState = 5;
            break;
        case 4:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyEasyChatWord(gStringVar2, show->bravoTrainer.ecWords[0]);
            TV_ConvertNumberToOrdinal(2, show->bravoTrainer.contestResult + 1);
            sTVShowState = 5;
            break;
        case 5:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyContestCategoryToStringVar(1, show->bravoTrainer.contestCategory);
            CopyEasyChatWord(gStringVar3, show->bravoTrainer.ecWords[1]);
            if (show->bravoTrainer.move)
                sTVShowState = 6;
            else
                sTVShowState = 7;
            break;
        case 6:
            StringCopy(gStringVar1, gSpeciesNames[show->bravoTrainer.species]);
            StringCopy(gStringVar2, gMoveNames[show->bravoTrainer.move]);
            CopyEasyChatWord(gStringVar3, show->bravoTrainer.ecWords[1]);
            sTVShowState = 7;
            break;
        case 7:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainer.species]);
            TVShowDone();
            break;
        case 8:
            StringCopy(gStringVar1, gSpeciesNames[show->bravoTrainer.species]);
            sTVShowState = 2;
            break;
    }
    ShowFieldMessage(gTVBravoTrainerTextGroup[state]);
}

void DoTVShowBravoTrainerBattleTower(void)
{
    TVShow *show;
    u8 state;

    show = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004];
    gScriptResult = 0;
    state = sTVShowState;
    switch(state)
    {
        case 0:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.species]);
            if (show->bravoTrainerTower.numFights >= 7)
                sTVShowState = 1;
            else
                sTVShowState = 2;
            break;
        case 1:
            if (show->bravoTrainerTower.btLevel == 50)
            {
                StringCopy(gStringVar1, gText_Lv50);
            }
            else
            {
                StringCopy(gStringVar1, gText_OpenLevel);
            }
            TV_ConvertNumberToOrdinal(1, show->bravoTrainerTower.numFights);
            if (show->bravoTrainerTower.var1c == 1)
                sTVShowState = 3;
            else
                sTVShowState = 4;
            break;
        case 2:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            TV_ConvertNumberToOrdinal(1, show->bravoTrainerTower.numFights + 1);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 3:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.defeatedSpecies]);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 4:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.defeatedSpecies]);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 5:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            sTVShowState = 11;
            break;
        case 6:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            sTVShowState = 11;
            break;
        case 7:
            sTVShowState = 11;
            break;
        case 8:
        case 9:
        case 10:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            sTVShowState = 11;
            break;
        case 11:
            CopyEasyChatWord(gStringVar1, show->bravoTrainerTower.var18[0]);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 12;
            else
                sTVShowState = 13;
            break;
        case 12:
        case 13:
            CopyEasyChatWord(gStringVar1, show->bravoTrainerTower.var18[0]);
            TVShowConvertInternationalString(gStringVar2, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            TVShowConvertInternationalString(gStringVar3, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            sTVShowState = 14;
            break;
        case 14:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.species]);
            TVShowDone();
            break;
    }
    ShowFieldMessage(gTVBravoTrainerBattleTowerTextGroup[state]);
}
