#include "global.h"
#include "battle_dome.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "frontier_util.h"
#include "battle_message.h"
#include "event_data.h"
#include "overworld.h"
#include "util.h"
#include "alloc.h"
#include "string_util.h"
#include "random.h"
#include "task.h"
#include "main.h"
#include "gpu_regs.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "strings.h"
#include "palette.h"
#include "decompress.h"
#include "party_menu.h"
#include "menu.h"
#include "sound.h"
#include "pokemon_icon.h"
#include "data.h"
#include "international_string_util.h"
#include "trainer_pokemon_sprites.h"
#include "scanline_effect.h"
#include "script_pokemon_util_80F87D8.h"
#include "graphics.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/abilities.h"
#include "constants/songs.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"

#define DOME_ROUND1 0
#define DOME_ROUND2 1
#define DOME_QUARTERFINAL 1 // Different name for the same round.
#define DOME_SEMIFINAL 2
#define DOME_FINAL 3
#define DOME_ROUNDS_COUNT 4

struct BattleDomeStruct
{
    u8 arr[DOME_TOURNAMENT_TRAINERS_COUNT];
    u8 unk_10;
    u8 unk_11[3];
};

struct UnkStruct_860DD10
{
    u8 x;
    u8 y;
    u16 src;
};

// This file's functions.
static u8 GetDomeTrainerMonIvs(u16 trainerId);
static void SwapDomeTrainers(int id1, int id2, u16 *statsArray);
static void CalcDomeMonStats(u16 species, int level, int ivs, u8 evBits, u8 nature, int *stats);
static void CreateDomeOpponentMons(u16 tournamentTrainerId);
static int sub_818FCBC(u16 tournamentTrainerId, bool8 arg1);
static int sub_818FDB8(u16 tournamentTrainerId, bool8 arg1);
static int GetTypeEffectivenessPoints(int move, int species, int arg2);
static int sub_818FEB4(int *arr, bool8 arg1);
static void Task_ShowOpponentInfo(u8 taskId);
static void sub_8190CD4(u8 taskId);
static u8 sub_819221C(u8 taskId);
static void InitDomeFacilityTrainersAndMons(void);
static int TrainerIdToTournamentId(u16 trainerId);
static u16 TrainerIdOfPlayerOpponent(void);
static void Task_ShowTourneyTree(u8 taskId);
static void sub_8194950(u8 taskId);
static void CB2_BattleDome(void);
static void VblankCb0_BattleDome(void);
static void DisplayMatchInfoOnCard(u8 flags, u8 matchNo);
static void DisplayTrainerInfoOnCard(u8 flags, u8 trainerTournamentId);
static int sub_8192F08(u8, u8*);
static u8 GetDomeBrainTrainerPicId(void);
static u8 GetDomeBrainTrainerClass(void);
static void CopyDomeBrainTrainerName(u8 *str);
static void CopyDomeTrainerName(u8 *str, u16 trainerId);
static void HblankCb_BattleDome(void);
static void VblankCb1_BattleDome(void);
static u8 UpdateTourneyTreeCursor(u8 taskId);
static void DecideRoundWinners(u8 roundId);
static u8 sub_81953E8(u8 tournamentId, u8);
static void sub_81948EC(u8, u8);
static void sub_8190B40(struct Sprite *sprite);
static void sub_8190C6C(struct Sprite *sprite);
static void InitDomeChallenge(void);
static void GetDomeData(void);
static void SetDomeData(void);
static void BufferDomeRoundText(void);
static void BufferDomeOpponentName(void);
static void InitDomeOpponentParty(void);
static void ShowDomeOpponentInfo(void);
static void ShowDomeTourneyTree(void);
static void ShowPreviousDomeResultsTourneyTree(void);
static void SetDomeOpponentId(void);
static void SetDomeOpponentGraphicsId(void);
static void ShowNonInteractiveDomeTourneyTree(void);
static void ResolveDomeRoundWinners(void);
static void sub_81902F8(void);
static void UpdateDomeStreaks(void);
static void RestoreDomePlayerParty(void);
static void RestoreDomePlayerPartyHeldItems(void);
static void ReduceDomePlayerPartyTo3Mons(void);
static void GetPlayerSeededBeforeOpponent(void);
static void BufferLastDomeWinnerName(void);
static void sub_8194F58(void);
static void InitDomeTrainers(void);

// EWRAM variables.
EWRAM_DATA u32 gUnknown_0203CD70 = 0;
static EWRAM_DATA u32 gUnknown_0203CD74 = 0;
static EWRAM_DATA struct BattleDomeStruct *sBattleDomeStruct = {0};
static EWRAM_DATA u8 *sTilemapBuffer = NULL;

// Const rom data.
static const u8 sMovePointsForDomeTrainers[MOVES_COUNT][DOME_TOURNAMENT_TRAINERS_COUNT] =
{
    [MOVE_NONE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_POUND] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_KARATE_CHOP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_DOUBLE_SLAP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_COMET_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_MEGA_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_PAY_DAY] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_FIRE_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_ICE_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_THUNDER_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SCRATCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_VICE_GRIP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_GUILLOTINE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_RAZOR_WIND] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SWORDS_DANCE] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    [MOVE_CUT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_GUST] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_WING_ATTACK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_WHIRLWIND] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FLY] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BIND] = {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SLAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_VINE_WHIP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_STOMP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_DOUBLE_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_MEGA_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_JUMP_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ROLLING_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SAND_ATTACK] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_HEADBUTT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_HORN_ATTACK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FURY_ATTACK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_HORN_DRILL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_TACKLE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BODY_SLAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_WRAP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_TAKE_DOWN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_THRASH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_DOUBLE_EDGE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_TAIL_WHIP] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_POISON_STING] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_TWINEEDLE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_PIN_MISSILE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_LEER] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_BITE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_GROWL] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ROAR] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SING] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SUPERSONIC] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SONIC_BOOM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_DISABLE] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ACID] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_EMBER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_FLAMETHROWER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    [MOVE_MIST] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_WATER_GUN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_HYDRO_PUMP] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
    [MOVE_SURF] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
    [MOVE_ICE_BEAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    [MOVE_BLIZZARD] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1},
    [MOVE_PSYBEAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_BUBBLE_BEAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_AURORA_BEAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_HYPER_BEAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0},
    [MOVE_PECK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_DRILL_PECK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SUBMISSION] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_LOW_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_COUNTER] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    [MOVE_SEISMIC_TOSS] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_STRENGTH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ABSORB] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_MEGA_DRAIN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_LEECH_SEED] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_GROWTH] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_RAZOR_LEAF] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SOLAR_BEAM] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    [MOVE_POISON_POWDER] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_STUN_SPORE] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SLEEP_POWDER] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_PETAL_DANCE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_STRING_SHOT] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_DRAGON_RAGE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FIRE_SPIN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_THUNDER_SHOCK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_THUNDERBOLT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    [MOVE_THUNDER_WAVE] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_THUNDER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
    [MOVE_ROCK_THROW] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_EARTHQUAKE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    [MOVE_FISSURE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
    [MOVE_DIG] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_TOXIC] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_CONFUSION] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_PSYCHIC] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    [MOVE_HYPNOSIS] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_MEDITATE] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_AGILITY] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_QUICK_ATTACK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_RAGE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_TELEPORT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_NIGHT_SHADE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_MIMIC] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SCREECH] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_DOUBLE_TEAM] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_RECOVER] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_HARDEN] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_MINIMIZE] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SMOKESCREEN] = {0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_CONFUSE_RAY] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_WITHDRAW] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_DEFENSE_CURL] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BARRIER] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_LIGHT_SCREEN] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_HAZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_REFLECT] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_FOCUS_ENERGY] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BIDE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_METRONOME] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    [MOVE_MIRROR_MOVE] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    [MOVE_SELF_DESTRUCT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0},
    [MOVE_EGG_BOMB] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
    [MOVE_LICK] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SMOG] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SLUDGE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_BONE_CLUB] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_FIRE_BLAST] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1},
    [MOVE_WATERFALL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_CLAMP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SWIFT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SKULL_BASH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    [MOVE_SPIKE_CANNON] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_CONSTRICT] = {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_AMNESIA] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_KINESIS] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SOFT_BOILED] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_HI_JUMP_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_GLARE] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_DREAM_EATER] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    [MOVE_POISON_GAS] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BARRAGE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_LEECH_LIFE] = {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_LOVELY_KISS] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SKY_ATTACK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1},
    [MOVE_TRANSFORM] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BUBBLE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_DIZZY_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SPORE] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FLASH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_PSYWAVE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SPLASH] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ACID_ARMOR] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_CRABHAMMER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    [MOVE_EXPLOSION] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
    [MOVE_FURY_SWIPES] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BONEMERANG] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_REST] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ROCK_SLIDE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_HYPER_FANG] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SHARPEN] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_CONVERSION] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_TRI_ATTACK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SUPER_FANG] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SLASH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SUBSTITUTE] = {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_STRUGGLE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_SKETCH] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    [MOVE_TRIPLE_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_THIEF] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SPIDER_WEB] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_MIND_READER] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_NIGHTMARE] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FLAME_WHEEL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SNORE] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_CURSE] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_FLAIL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_CONVERSION_2] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_AEROBLAST] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    [MOVE_COTTON_SPORE] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_REVERSAL] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SPITE] = {0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_POWDER_SNOW] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_PROTECT] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    [MOVE_MACH_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SCARY_FACE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_FAINT_ATTACK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SWEET_KISS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BELLY_DRUM] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SLUDGE_BOMB] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    [MOVE_MUD_SLAP] = {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_OCTAZOOKA] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SPIKES] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ZAP_CANNON] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1},
    [MOVE_FORESIGHT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_DESTINY_BOND] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_PERISH_SONG] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_ICY_WIND] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_DETECT] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_BONE_RUSH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_LOCK_ON] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_OUTRAGE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    [MOVE_SANDSTORM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_GIGA_DRAIN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_ENDURE] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_CHARM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ROLLOUT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_FALSE_SWIPE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SWAGGER] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_MILK_DRINK] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SPARK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_FURY_CUTTER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_STEEL_WING] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_MEAN_LOOK] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_ATTRACT] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SLEEP_TALK] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    [MOVE_HEAL_BELL] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_RETURN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_PRESENT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    [MOVE_FRUSTRATION] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SAFEGUARD] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_PAIN_SPLIT] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SACRED_FIRE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
    [MOVE_MAGNITUDE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_DYNAMIC_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
    [MOVE_MEGAHORN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    [MOVE_DRAGON_BREATH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_BATON_PASS] = {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ENCORE] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_PURSUIT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_RAPID_SPIN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SWEET_SCENT] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_IRON_TAIL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    [MOVE_METAL_CLAW] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_VITAL_THROW] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_MORNING_SUN] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_SYNTHESIS] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_MOONLIGHT] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_HIDDEN_POWER] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_CROSS_CHOP] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    [MOVE_TWISTER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_RAIN_DANCE] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_SUNNY_DAY] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_CRUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_MIRROR_COAT] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_PSYCH_UP] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_EXTREME_SPEED] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_ANCIENT_POWER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
    [MOVE_SHADOW_BALL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_FUTURE_SIGHT] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ROCK_SMASH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_WHIRLPOOL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_BEAT_UP] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FAKE_OUT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_UPROAR] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_STOCKPILE] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SPIT_UP] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    [MOVE_SWALLOW] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_HEAT_WAVE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    [MOVE_HAIL] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_TORMENT] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FLATTER] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_WILL_O_WISP] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_MEMENTO] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FACADE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FOCUS_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    [MOVE_SMELLING_SALT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FOLLOW_ME] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_NATURE_POWER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_CHARGE] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_TAUNT] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_HELPING_HAND] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_TRICK] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ROLE_PLAY] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_WISH] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ASSIST] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    [MOVE_INGRAIN] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_SUPERPOWER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0},
    [MOVE_MAGIC_COAT] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
    [MOVE_RECYCLE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_REVENGE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0},
    [MOVE_BRICK_BREAK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_YAWN] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_KNOCK_OFF] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_ENDEAVOR] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_ERUPTION] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0},
    [MOVE_SKILL_SWAP] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_IMPRISON] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    [MOVE_REFRESH] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_GRUDGE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_SNATCH] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    [MOVE_SECRET_POWER] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_DIVE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ARM_THRUST] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_CAMOUFLAGE] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_TAIL_GLOW] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_LUSTER_PURGE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
    [MOVE_MIST_BALL] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
    [MOVE_FEATHER_DANCE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_TEETER_DANCE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_BLAZE_KICK] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_MUD_SPORT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ICE_BALL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_NEEDLE_ARM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SLACK_OFF] = {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_HYPER_VOICE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
    [MOVE_POISON_FANG] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_CRUSH_CLAW] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_BLAST_BURN] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    [MOVE_HYDRO_CANNON] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    [MOVE_METEOR_MASH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
    [MOVE_ASTONISH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_WEATHER_BALL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_AROMATHERAPY] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    [MOVE_FAKE_TEARS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_AIR_CUTTER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_OVERHEAT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
    [MOVE_ODOR_SLEUTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_ROCK_TOMB] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SILVER_WIND] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
    [MOVE_METAL_SOUND] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_GRASS_WHISTLE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_TICKLE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_COSMIC_POWER] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_WATER_SPOUT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0},
    [MOVE_SIGNAL_BEAM] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SHADOW_PUNCH] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_EXTRASENSORY] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_SKY_UPPERCUT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SAND_TOMB] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_SHEER_COLD] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
    [MOVE_MUDDY_WATER] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    [MOVE_BULLET_SEED] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_AERIAL_ACE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ICICLE_SPEAR] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_IRON_DEFENSE] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BLOCK] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    [MOVE_HOWL] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_DRAGON_CLAW] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_FRENZY_PLANT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    [MOVE_BULK_UP] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_BOUNCE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    [MOVE_MUD_SHOT] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    [MOVE_POISON_TAIL] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_COVET] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_VOLT_TACKLE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0},
    [MOVE_MAGICAL_LEAF] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_WATER_SPORT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_CALM_MIND] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_LEAF_BLADE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    [MOVE_DRAGON_DANCE] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_ROCK_BLAST] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_SHOCK_WAVE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    [MOVE_WATER_PULSE] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    [MOVE_DOOM_DESIRE] = {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    [MOVE_PSYCHO_BOOST] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1},
};

static const u8 gUnknown_0860C988[][DOME_TOURNAMENT_TRAINERS_COUNT] =
{
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0},
    {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 4, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
static const u8 sUnusedArray[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0,
    0, 0, 3, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
    0, 2, 253, 0, 0, 0, 0, 0, 253, 0, 0, 0, 0, 0, 253, 0,
    0, 0, 0, 0, 253, 0, 0, 0, 0, 0, 253, 254, 0, 0, 0, 0,
    0, 254, 0, 0, 0, 0, 0, 254, 0, 0, 0, 0, 0, 254, 0, 0,
    0, 0, 0, 254, 0, 0, 0, 0, 0,
};

static const u8 sTourneyTreeCursorMovementMap[][5][4]=
{
    {{0x07, 0x01, 0x08, 0x10}, {0x07, 0x01, 0x08, 0x10}, {0x07, 0x01, 0x08, 0x10}, {0x07, 0x01, 0x08, 0x10}, {0x07, 0x01, 0x08, 0x10}},
    {{0x00, 0x02, 0x09, 0x10}, {0x00, 0x02, 0x09, 0x10}, {0x00, 0x02, 0x09, 0x10}, {0x00, 0x02, 0x09, 0x10}, {0x00, 0x02, 0x09, 0x10}},
    {{0x01, 0x03, 0x0a, 0x11}, {0x01, 0x03, 0x0a, 0x11}, {0x01, 0x03, 0x0a, 0x11}, {0x01, 0x03, 0x0a, 0x11}, {0x01, 0x03, 0x0a, 0x11}},
    {{0x02, 0x04, 0x0b, 0x11}, {0x02, 0x04, 0x0b, 0x11}, {0x02, 0x04, 0x0b, 0x11}, {0x02, 0x04, 0x0b, 0x11}, {0x02, 0x04, 0x0b, 0x11}},
    {{0x03, 0x05, 0x0c, 0x12}, {0x03, 0x05, 0x0c, 0x12}, {0x03, 0x05, 0x0c, 0x12}, {0x03, 0x05, 0x0c, 0x12}, {0x03, 0x05, 0x0c, 0x12}},
    {{0x04, 0x06, 0x0d, 0x12}, {0x04, 0x06, 0x0d, 0x12}, {0x04, 0x06, 0x0d, 0x12}, {0x04, 0x06, 0x0d, 0x12}, {0x04, 0x06, 0x0d, 0x12}},
    {{0x05, 0x07, 0x0e, 0x13}, {0x05, 0x07, 0x0e, 0x13}, {0x05, 0x07, 0x0e, 0x13}, {0x05, 0x07, 0x0e, 0x13}, {0x05, 0x07, 0x0e, 0x13}},
    {{0x06, 0x00, 0x0f, 0x13}, {0x06, 0x00, 0x0f, 0x13}, {0x06, 0x00, 0x0f, 0x13}, {0x06, 0x00, 0x0f, 0x13}, {0x06, 0x00, 0x0f, 0x13}},
    {{0x1f, 0x09, 0x14, 0x1f}, {0x1f, 0x09, 0x14, 0x1f}, {0x1f, 0x09, 0x14, 0x1f}, {0x1f, 0x09, 0x14, 0x1f}, {0x1f, 0x09, 0x14, 0x1f}},
    {{0x08, 0x0a, 0x14, 0x01}, {0x08, 0x0a, 0x14, 0x01}, {0x08, 0x0a, 0x14, 0x01}, {0x08, 0x0a, 0x14, 0x01}, {0x08, 0x0a, 0x14, 0x01}},
    {{0x09, 0x0b, 0x15, 0x02}, {0x09, 0x0b, 0x15, 0x02}, {0x09, 0x0b, 0x15, 0x02}, {0x09, 0x0b, 0x15, 0x02}, {0x09, 0x0b, 0x15, 0x02}},
    {{0x0a, 0x0c, 0x15, 0x03}, {0x0a, 0x0c, 0x15, 0x03}, {0x0a, 0x0c, 0x15, 0x03}, {0x0a, 0x0c, 0x15, 0x03}, {0x0a, 0x0c, 0x15, 0x03}},
    {{0x0b, 0x0d, 0x16, 0x04}, {0x0b, 0x0d, 0x16, 0x04}, {0x0b, 0x0d, 0x16, 0x04}, {0x0b, 0x0d, 0x16, 0x04}, {0x0b, 0x0d, 0x16, 0x04}},
    {{0x0c, 0x0e, 0x16, 0x05}, {0x0c, 0x0e, 0x16, 0x05}, {0x0c, 0x0e, 0x16, 0x05}, {0x0c, 0x0e, 0x16, 0x05}, {0x0c, 0x0e, 0x16, 0x05}},
    {{0x0d, 0x0f, 0x17, 0x06}, {0x0d, 0x0f, 0x17, 0x06}, {0x0d, 0x0f, 0x17, 0x06}, {0x0d, 0x0f, 0x17, 0x06}, {0x0d, 0x0f, 0x17, 0x06}},
    {{0x0e, 0x1f, 0x17, 0x07}, {0x0e, 0x1f, 0x17, 0x07}, {0x0e, 0x1f, 0x17, 0x07}, {0x0e, 0x1f, 0x17, 0x07}, {0x0e, 0x1f, 0x17, 0x07}},
    {{0x13, 0x11, 0x00, 0x14}, {0x13, 0x11, 0x00, 0x18}, {0x13, 0x11, 0x00, 0x18}, {0x13, 0x11, 0x00, 0x18}, {0x13, 0x11, 0x00, 0x18}},
    {{0x10, 0x12, 0x02, 0x15}, {0x10, 0x12, 0x02, 0x18}, {0x10, 0x12, 0x02, 0x18}, {0x10, 0x12, 0x02, 0x18}, {0x10, 0x12, 0x02, 0x18}},
    {{0x11, 0x13, 0x04, 0x16}, {0x11, 0x13, 0x04, 0x19}, {0x11, 0x13, 0x04, 0x19}, {0x11, 0x13, 0x04, 0x19}, {0x11, 0x13, 0x04, 0x19}},
    {{0x12, 0x10, 0x06, 0x17}, {0x12, 0x10, 0x06, 0x19}, {0x12, 0x10, 0x06, 0x19}, {0x12, 0x10, 0x06, 0x19}, {0x12, 0x10, 0x06, 0x19}},
    {{0x17, 0x15, 0x10, 0x08}, {0x17, 0x15, 0x1a, 0x08}, {0x17, 0x15, 0x1a, 0x08}, {0x17, 0x15, 0x1a, 0x08}, {0x17, 0x15, 0x1a, 0x08}},
    {{0x14, 0x16, 0x11, 0x0a}, {0x14, 0x16, 0x1a, 0x0a}, {0x14, 0x16, 0x1a, 0x0a}, {0x14, 0x16, 0x1a, 0x0a}, {0x14, 0x16, 0x1a, 0x0a}},
    {{0x15, 0x17, 0x12, 0x0c}, {0x15, 0x17, 0x1b, 0x0c}, {0x15, 0x17, 0x1b, 0x0c}, {0x15, 0x17, 0x1b, 0x0c}, {0x15, 0x17, 0x1b, 0x0c}},
    {{0x16, 0x14, 0x13, 0x0e}, {0x16, 0x14, 0x1b, 0x0e}, {0x16, 0x14, 0x1b, 0x0e}, {0x16, 0x14, 0x1b, 0x0e}, {0x16, 0x14, 0x1b, 0x0e}},
    {{0xff, 0xff, 0xff, 0xff}, {0x19, 0x19, 0x10, 0x1a}, {0x19, 0x19, 0x10, 0x1c}, {0x19, 0x19, 0x10, 0x1c}, {0x19, 0x19, 0x10, 0x1c}},
    {{0xff, 0xff, 0xff, 0xff}, {0x18, 0x18, 0x12, 0x1b}, {0x18, 0x18, 0x12, 0x1c}, {0x18, 0x18, 0x12, 0x1c}, {0x18, 0x18, 0x12, 0x1c}},
    {{0xff, 0xff, 0xff, 0xff}, {0x1b, 0x1b, 0x18, 0x14}, {0x1b, 0x1b, 0x1d, 0x14}, {0x1b, 0x1b, 0x1d, 0x14}, {0x1b, 0x1b, 0x1d, 0x14}},
    {{0xff, 0xff, 0xff, 0xff}, {0x1a, 0x1a, 0x19, 0x16}, {0x1a, 0x1a, 0x1d, 0x16}, {0x1a, 0x1a, 0x1d, 0x16}, {0x1a, 0x1a, 0x1d, 0x16}},
    {{0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0x18, 0x1d}, {0xff, 0xff, 0x18, 0x1e}, {0xff, 0xff, 0x18, 0x1e}},
    {{0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0x1c, 0x1a}, {0xff, 0xff, 0x1e, 0x1a}, {0xff, 0xff, 0x1e, 0x1a}},
    {{0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0xff, 0xff}, {0xff, 0xff, 0x1c, 0x1d}, {0xff, 0xff, 0x1c, 0x1d}},
    {{0x0f, 0x08, 0x08, 0x00}, {0x0f, 0x08, 0x08, 0x00}, {0x0f, 0x08, 0x08, 0x00}, {0x0f, 0x08, 0x08, 0x00}, {0x0f, 0x08, 0x08, 0x00}},
};

static const struct BgTemplate gUnknown_0860CE74[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const struct BgTemplate gUnknown_0860CE84[4] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 20,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 24,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const struct WindowTemplate gUnknown_0860CE94[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 3,
        .width = 8,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 16,
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 3,
        .width = 8,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 144,
    },
    {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 1,
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 272,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate gUnknown_0860CEB4[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 53,
    },
    {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 7,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 69,
    },
    {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 96,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 12,
        .width = 26,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 112,
    },
    {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 23,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 294,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 340,
    },
    {
        .bg = 0,
        .tilemapLeft = 20,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 356,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 16,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 372,
    },
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 1,
        .tilemapLeft = 16,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 53,
    },
    {
        .bg = 1,
        .tilemapLeft = 19,
        .tilemapTop = 7,
        .width = 9,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 69,
    },
    {
        .bg = 1,
        .tilemapLeft = 16,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 96,
    },
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 12,
        .width = 26,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 112,
    },
    {
        .bg = 1,
        .tilemapLeft = 5,
        .tilemapTop = 2,
        .width = 23,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 294,
    },
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 340,
    },
    {
        .bg = 1,
        .tilemapLeft = 20,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 356,
    },
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 16,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 372,
    },
    // UB: No DUMMY_WIN_TEMPLATE at the array's end.
};

static const struct ScanlineEffectParams sTourneyTreeScanlineEffectParams =
{
    .dmaDest = (void *)REG_ADDR_BG3CNT,
    .dmaControl = SCANLINE_EFFECT_DMACNT_16BIT,
    .initState = 1,
};

static const struct CompressedSpriteSheet sDomeOptionsSpriteSheet[] =
{
    {gBattleFrontierGfx_DomeOptions, 0x0600, 0x0000},
    {},
};

static const struct CompressedSpritePalette gUnknown_0860CF60[] =
{
    {gUnknown_08D85444, 0x0000},
    {},
};

static const struct OamData gUnknown_0860CF70 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gUnknown_0860CF78 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 1,
    .affineParam = 0,
};

static const struct OamData gUnknown_0860CF80 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 2,
    .affineParam = 0,
};

static const struct OamData gUnknown_0860CF88 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 2,
    .affineParam = 0,
};

static const union AnimCmd gUnknown_0860CF90[] =
{
    ANIMCMD_FRAME(20, 1),
    ANIMCMD_END,
};
static const union AnimCmd gUnknown_0860CF98[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END,
};

static const union AnimCmd * const gUnknown_0860CFA0[] =
{
    gUnknown_0860CF90,
    gUnknown_0860CF98,
};

static const struct SpriteTemplate gUnknown_0860CFA8 =
{
    .tileTag = 0x0000,
    .paletteTag = 0xffff,
    .oam = &gUnknown_0860CF70,
    .anims = gUnknown_0860CFA0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
   .callback = SpriteCallbackDummy
};

static const union AnimCmd gUnknown_0860CFC0[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0860CFC8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd * const gUnknown_0860CFD0[] =
{
    gUnknown_0860CFC0,
    gUnknown_0860CFC8,
};

static const struct SpriteTemplate gUnknown_0860CFD8 =
{
    .tileTag = 0x0000,
    .paletteTag = 0xffff,
    .oam = &gUnknown_0860CF78,
    .anims = gUnknown_0860CFD0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const union AnimCmd gUnknown_0860CFF0[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0860CFF8[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
 };

static const union AnimCmd * const gUnknown_0860D000[] =
{
    gUnknown_0860CFF0,
    gUnknown_0860CFF8,
};

static const struct SpriteTemplate gUnknown_0860D008 =
{
    .tileTag = 0x0000,
    .paletteTag = 0xffff,
    .oam = &gUnknown_0860CF78,
    .anims = gUnknown_0860D000,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const union AnimCmd gUnknown_0860D020[] =
{
    ANIMCMD_FRAME(18, 1),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0860D028[] =
{
    ANIMCMD_FRAME(18, 129, .vFlip = TRUE),
    ANIMCMD_END,
 };

static const union AnimCmd gUnknown_0860D030[] =
{
    ANIMCMD_FRAME(16, 65, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_0860D038[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END,
};

static const union AnimCmd * const gUnknown_0860D040[] =
{
    gUnknown_0860D020,
    gUnknown_0860D028,
};

static const union AnimCmd * const gUnknown_0860D048[] =
{
    gUnknown_0860D030,
    gUnknown_0860D038,
};

static const struct SpriteTemplate gUnknown_0860D050 =
{
    .tileTag = 0x0000,
    .paletteTag = 0xffff,
    .oam = &gUnknown_0860CF88,
    .anims = gUnknown_0860D048,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8190B40
};

static const struct SpriteTemplate gUnknown_0860D068 =
{
    .tileTag = 0x0000,
    .paletteTag = 0xffff,
    .oam = &gUnknown_0860CF80,
    .anims = gUnknown_0860D040,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8190C6C
};

static const u8 sTourneyTreeTrainerIds[] = {0, 8, 12, 4, 7, 15, 11, 3, 2, 10, 14, 6, 5, 13, 9, 1};

static void (* const sBattleDomeFunctions[])(void) =
{
    InitDomeChallenge,
    GetDomeData,
    SetDomeData,
    BufferDomeRoundText,
    BufferDomeOpponentName,
    InitDomeOpponentParty,
    ShowDomeOpponentInfo,
    ShowDomeTourneyTree,
    ShowPreviousDomeResultsTourneyTree,
    SetDomeOpponentId,
    SetDomeOpponentGraphicsId,
    ShowNonInteractiveDomeTourneyTree,
    ResolveDomeRoundWinners,
    sub_81902F8,
    UpdateDomeStreaks,
    InitDomeFacilityTrainersAndMons,
    RestoreDomePlayerParty,
    RestoreDomePlayerPartyHeldItems,
    ReduceDomePlayerPartyTo3Mons,
    GetPlayerSeededBeforeOpponent,
    BufferLastDomeWinnerName,
    sub_8194F58,
    InitDomeTrainers,
};

static const u32 gUnknown_0860D0EC[][2] =
{
    {0x00000004, 0x00000008},
    {0x00100000, 0x00200000},
};

static const u32 gUnknown_0860D0FC[][2] =
{
    {0xfffffffb, 0xfffffff7},
    {0xffefffff, 0xffdfffff},
};

static const u8 sIdToOpponentId[DOME_TOURNAMENT_TRAINERS_COUNT][DOME_ROUNDS_COUNT] =
{
    [0]  = {8,  0,  4, 8},
    [1]  = {9,  12, 8, 0},
    [2]  = {10, 8,  12, 0},
    [3]  = {11, 4,  0, 8},
    [4]  = {12, 0,  4, 8},
    [5]  = {13, 12, 8, 0},
    [6]  = {14, 8,  12, 0},
    [7]  = {15, 4,  0, 8},
    [8]  = {0,  0,  4, 8},
    [9]  = {1,  12, 8, 0},
    [10] = {2,  8,  12, 0},
    [11] = {3,  4,  0, 8},
    [12] = {4,  0,  4, 8},
    [13] = {5,  12, 8, 0},
    [14] = {6,  8,  12, 0},
    [15] = {7,  4,  0, 8},
};

static const u8 gUnknown_0860D14C[] = {0x00, 0x08, 0x04, 0x0c, 0x07, 0x0f, 0x03, 0x0b, 0x02, 0x0a, 0x06, 0x0e, 0x05, 0x0d, 0x01, 0x09};

static const u8 gUnknown_0860D15C[][4] =
{
    {0x00, 0x08, 0x0c, 0x0e},
    {0x00, 0x08, 0x0c, 0x0e},
    {0x01, 0x08, 0x0c, 0x0e},
    {0x01, 0x08, 0x0c, 0x0e},
    {0x02, 0x09, 0x0c, 0x0e},
    {0x02, 0x09, 0x0c, 0x0e},
    {0x03, 0x09, 0x0c, 0x0e},
    {0x03, 0x09, 0x0c, 0x0e},
    {0x04, 0x0a, 0x0d, 0x0e},
    {0x04, 0x0a, 0x0d, 0x0e},
    {0x05, 0x0a, 0x0d, 0x0e},
    {0x05, 0x0a, 0x0d, 0x0e},
    {0x06, 0x0b, 0x0d, 0x0e},
    {0x06, 0x0b, 0x0d, 0x0e},
    {0x07, 0x0b, 0x0d, 0x0e},
    {0x07, 0x0b, 0x0d, 0x0e},
};

static const u8 gUnknown_0860D19C[] = {0x17, 0x1b, 0x1d, 0x1e};

static const u8 gUnknown_0860D1A0[][4] =
{
    {0x10, 0x18, 0x1c, 0x1e},
    {0x11, 0x18, 0x1c, 0x1e},
    {0x12, 0x19, 0x1c, 0x1e},
    {0x13, 0x19, 0x1c, 0x1e},
    {0x14, 0x1a, 0x1d, 0x1e},
    {0x15, 0x1a, 0x1d, 0x1e},
    {0x16, 0x1b, 0x1d, 0x1e},
    {0x17, 0x1b, 0x1d, 0x1e},
};

static const u8 gUnknown_0860D1C0[] = {0x00, 0x0f, 0x08, 0x07, 0x03, 0x0c, 0x0b, 0x04, 0x01, 0x0e, 0x09, 0x06, 0x02, 0x0d, 0x0a, 0x05};

static const u8 *const sBattleDomePotentialTexts[] =
{
    gBattleDomeOpponentPotentialText1,
    gBattleDomeOpponentPotentialText2,
    gBattleDomeOpponentPotentialText3,
    gBattleDomeOpponentPotentialText4,
    gBattleDomeOpponentPotentialText5,
    gBattleDomeOpponentPotentialText6,
    gBattleDomeOpponentPotentialText7,
    gBattleDomeOpponentPotentialText8,
    gBattleDomeOpponentPotentialText9,
    gBattleDomeOpponentPotentialText10,
    gBattleDomeOpponentPotentialText11,
    gBattleDomeOpponentPotentialText12,
    gBattleDomeOpponentPotentialText13,
    gBattleDomeOpponentPotentialText14,
    gBattleDomeOpponentPotentialText15,
    gBattleDomeOpponentPotentialText16,
    gBattleDomeOpponentPotentialText17,
};

static const u8 *const sBattleDomeOpponentStyleTexts[] =
{
    gBattleDomeOpponentStyleText1,
    gBattleDomeOpponentStyleText2,
    gBattleDomeOpponentStyleText3,
    gBattleDomeOpponentStyleText4,
    gBattleDomeOpponentStyleText5,
    gBattleDomeOpponentStyleText6,
    gBattleDomeOpponentStyleText7,
    gBattleDomeOpponentStyleText8,
    gBattleDomeOpponentStyleText9,
    gBattleDomeOpponentStyleText10,
    gBattleDomeOpponentStyleText11,
    gBattleDomeOpponentStyleText12,
    gBattleDomeOpponentStyleText13,
    gBattleDomeOpponentStyleText14,
    gBattleDomeOpponentStyleText15,
    gBattleDomeOpponentStyleText16,
    gBattleDomeOpponentStyleText17,
    gBattleDomeOpponentStyleText18,
    gBattleDomeOpponentStyleText19,
    gBattleDomeOpponentStyleText20,
    gBattleDomeOpponentStyleText21,
    gBattleDomeOpponentStyleText22,
    gBattleDomeOpponentStyleText23,
    gBattleDomeOpponentStyleText24,
    gBattleDomeOpponentStyleText25,
    gBattleDomeOpponentStyleText26,
    gBattleDomeOpponentStyleText27,
    gBattleDomeOpponentStyleText28,
    gBattleDomeOpponentStyleTextUnused1,
    gBattleDomeOpponentStyleTextUnused2,
    gBattleDomeOpponentStyleTextUnused3,
    gBattleDomeOpponentStyleTextUnused4,
};

static const u8 *const sBattleDomeOpponentStatsTexts[] =
{
    gBattleDomeOpponentStatsText1,
    gBattleDomeOpponentStatsText2,
    gBattleDomeOpponentStatsText3,
    gBattleDomeOpponentStatsText4,
    gBattleDomeOpponentStatsText5,
    gBattleDomeOpponentStatsText6,
    gBattleDomeOpponentStatsText7,
    gBattleDomeOpponentStatsText8,
    gBattleDomeOpponentStatsText9,
    gBattleDomeOpponentStatsText10,
    gBattleDomeOpponentStatsText11,
    gBattleDomeOpponentStatsText12,
    gBattleDomeOpponentStatsText13,
    gBattleDomeOpponentStatsText14,
    gBattleDomeOpponentStatsText15,
    gBattleDomeOpponentStatsText16,
    gBattleDomeOpponentStatsText17,
    gBattleDomeOpponentStatsText18,
    gBattleDomeOpponentStatsText19,
    gBattleDomeOpponentStatsText20,
    gBattleDomeOpponentStatsText21,
    gBattleDomeOpponentStatsText22,
    gBattleDomeOpponentStatsText23,
    gBattleDomeOpponentStatsText24,
    gBattleDomeOpponentStatsText25,
    gBattleDomeOpponentStatsText26,
    gBattleDomeOpponentStatsText27,
    gBattleDomeOpponentStatsText28,
    gBattleDomeOpponentStatsText29,
    gBattleDomeOpponentStatsText30,
    gBattleDomeOpponentStatsText31,
    gBattleDomeOpponentStatsText32,
    gBattleDomeOpponentStatsText33,
    gBattleDomeOpponentStatsText34,
    gBattleDomeOpponentStatsText35,
    gBattleDomeOpponentStatsText36,
    gBattleDomeOpponentStatsText37,
    gBattleDomeOpponentStatsText38,
    gBattleDomeOpponentStatsText39,
    gBattleDomeOpponentStatsText40,
    gBattleDomeOpponentStatsText41,
    gBattleDomeOpponentStatsText42,
    gBattleDomeOpponentStatsText43,
};

static const u8 sInfoTrainerMonX[] = {0x68, 0x88, 0x68};
static const u8 sInfoTrainerMonY[] = {0x26, 0x3e, 0x4e};
static const u8 gUnknown_0860D346[] = {0x00, 0x04, 0x00};

static const u8 gUnknown_0860D349[] = {0x00, 0x05, 0x09, 0x0c, 0x0e, 0x00, 0x00};

static const u8 *const sBattleDomeMatchNumberTexts[] =
{
    gBattleDomeMatchNumberText1,
    gBattleDomeMatchNumberText2,
    gBattleDomeMatchNumberText3,
    gBattleDomeMatchNumberText4,
    gBattleDomeMatchNumberText5,
    gBattleDomeMatchNumberText6,
    gBattleDomeMatchNumberText7,
    gBattleDomeMatchNumberText8,
    gBattleDomeMatchNumberText9,
    gBattleDomeMatchNumberText10,
    gBattleDomeMatchNumberText11,
    gBattleDomeMatchNumberText12,
    gBattleDomeMatchNumberText13,
    gBattleDomeMatchNumberText14,
    gBattleDomeMatchNumberText15,
};

static const u8 *const sBattleDomeWinTexts[] =
{
    gBattleDomeWinText1,
    gBattleDomeWinText2,
    gBattleDomeWinText3,
    gBattleDomeWinText4,
    gBattleDomeWinText5,
    gBattleDomeWinText6,
    gBattleDomeWinText7,
};

static const u8 sFirstTrainerMonX[] = {0x60, 0x60, 0x60};
static const u8 sFirstTrainerMonY[] = {0x38, 0x50, 0x68};
static const u8 sSecondTrainerMonX[] = {0x90, 0x90, 0x90};
static const u8 sSecondTrainerMonY[] = {0x38, 0x50, 0x68};

static const u8 gUnknown_0860D3B4[] = {0x00, 0x08, 0x0c, 0x04, 0x07, 0x0f, 0x0b, 0x03, 0x02, 0x0a, 0x0e, 0x06, 0x05, 0x0d, 0x09, 0x01};

static const u8 gUnknown_0860D3C4[][3] =
{
    {0x00, 0x02, 0x00},
    {0x02, 0x02, 0x00},
    {0x04, 0x02, 0x00},
    {0x06, 0x02, 0x00},
    {0x08, 0x02, 0x00},
    {0x0a, 0x02, 0x00},
    {0x0c, 0x02, 0x00},
    {0x0e, 0x02, 0x00},
    {0x00, 0x04, 0x01},
    {0x04, 0x04, 0x01},
    {0x08, 0x04, 0x01},
    {0x0c, 0x04, 0x01},
    {0x00, 0x08, 0x02},
    {0x08, 0x08, 0x02},
    {0x00, 0x10, 0x03},
};

static const u8 gUnknown_0860D3F1[][2] =
{
    {0x00, 0x00},
    {0x01, 0x70},
    {0x01, 0x00},
    {0x00, 0x70},
    {0x00, 0x30},
    {0x01, 0x40},
    {0x01, 0x30},
    {0x00, 0x40},
    {0x00, 0x10},
    {0x01, 0x60},
    {0x01, 0x10},
    {0x00, 0x60},
    {0x00, 0x20},
    {0x01, 0x50},
    {0x01, 0x20},
    {0x00, 0x50},
};

static const u8 gUnknown_0860D411[][2] =
{
    {0x44, 0x21},
    {0x44, 0x31},
    {0x44, 0x41},
    {0x44, 0x51},
    {0x44, 0x61},
    {0x44, 0x71},
    {0x44, 0x81},
    {0x44, 0x91},
    {0xac, 0x21},
    {0xac, 0x31},
    {0xac, 0x41},
    {0xac, 0x51},
    {0xac, 0x61},
    {0xac, 0x71},
    {0xac, 0x81},
    {0xac, 0x91},
    {0x57, 0x29},
    {0x57, 0x49},
    {0x57, 0x69},
    {0x57, 0x89},
    {0x99, 0x29},
    {0x99, 0x49},
    {0x99, 0x69},
    {0x99, 0x89},
    {0x5f, 0x39},
    {0x5f, 0x79},
    {0x91, 0x39},
    {0x91, 0x79},
    {0x67, 0x59},
    {0x89, 0x59},
    {0x78, 0x59},
};

static const struct UnkStruct_860DD10 gUnknown_0860d450[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x09},
    {.src = 0x6023, .y = 0x04, .x = 0x0a},
    {.src = 0x6047, .y = 0x05, .x = 0x0a},
    {.src = 0x6043, .y = 0x05, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d460[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x09},
    {.src = 0x6023, .y = 0x04, .x = 0x0a},
    {.src = 0x6047, .y = 0x05, .x = 0x0a},
    {.src = 0x6023, .y = 0x05, .x = 0x0b},
    {.src = 0x6027, .y = 0x06, .x = 0x0b},
    {.src = 0x6047, .y = 0x07, .x = 0x0b},
    {.src = 0x6043, .y = 0x07, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d47c[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x09},
    {.src = 0x6023, .y = 0x04, .x = 0x0a},
    {.src = 0x6047, .y = 0x05, .x = 0x0a},
    {.src = 0x6023, .y = 0x05, .x = 0x0b},
    {.src = 0x6027, .y = 0x06, .x = 0x0b},
    {.src = 0x6047, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d4a8[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x09},
    {.src = 0x6023, .y = 0x04, .x = 0x0a},
    {.src = 0x6047, .y = 0x05, .x = 0x0a},
    {.src = 0x6023, .y = 0x05, .x = 0x0b},
    {.src = 0x6027, .y = 0x06, .x = 0x0b},
    {.src = 0x6047, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d4dc[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x09},
    {.src = 0x6021, .y = 0x06, .x = 0x0a},
    {.src = 0x6027, .y = 0x05, .x = 0x0a},
    {.src = 0x6043, .y = 0x05, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d4ec[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x09},
    {.src = 0x6021, .y = 0x06, .x = 0x0a},
    {.src = 0x6027, .y = 0x05, .x = 0x0a},
    {.src = 0x6023, .y = 0x05, .x = 0x0b},
    {.src = 0x6027, .y = 0x06, .x = 0x0b},
    {.src = 0x6047, .y = 0x07, .x = 0x0b},
    {.src = 0x6043, .y = 0x07, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d508[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x09},
    {.src = 0x6021, .y = 0x06, .x = 0x0a},
    {.src = 0x6027, .y = 0x05, .x = 0x0a},
    {.src = 0x6023, .y = 0x05, .x = 0x0b},
    {.src = 0x6027, .y = 0x06, .x = 0x0b},
    {.src = 0x6047, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d534[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x09},
    {.src = 0x6021, .y = 0x06, .x = 0x0a},
    {.src = 0x6027, .y = 0x05, .x = 0x0a},
    {.src = 0x6023, .y = 0x05, .x = 0x0b},
    {.src = 0x6027, .y = 0x06, .x = 0x0b},
    {.src = 0x6047, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d568[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x09},
    {.src = 0x6023, .y = 0x08, .x = 0x0a},
    {.src = 0x6047, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d578[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x09},
    {.src = 0x6023, .y = 0x08, .x = 0x0a},
    {.src = 0x6047, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
    {.src = 0x6027, .y = 0x08, .x = 0x0b},
    {.src = 0x6027, .y = 0x07, .x = 0x0b},
    {.src = 0x6043, .y = 0x07, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d594[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x09},
    {.src = 0x6023, .y = 0x08, .x = 0x0a},
    {.src = 0x6047, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
    {.src = 0x6027, .y = 0x08, .x = 0x0b},
    {.src = 0x6027, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d5c0[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x09},
    {.src = 0x6023, .y = 0x08, .x = 0x0a},
    {.src = 0x6047, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
    {.src = 0x6027, .y = 0x08, .x = 0x0b},
    {.src = 0x6027, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d5f4[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x09},
    {.src = 0x6021, .y = 0x0a, .x = 0x0a},
    {.src = 0x6027, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d604[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x09},
    {.src = 0x6021, .y = 0x0a, .x = 0x0a},
    {.src = 0x6027, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
    {.src = 0x6027, .y = 0x08, .x = 0x0b},
    {.src = 0x6027, .y = 0x07, .x = 0x0b},
    {.src = 0x6043, .y = 0x07, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d620[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x09},
    {.src = 0x6021, .y = 0x0a, .x = 0x0a},
    {.src = 0x6027, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
    {.src = 0x6027, .y = 0x08, .x = 0x0b},
    {.src = 0x6027, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d64c[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x09},
    {.src = 0x6021, .y = 0x0a, .x = 0x0a},
    {.src = 0x6027, .y = 0x09, .x = 0x0a},
    {.src = 0x6021, .y = 0x09, .x = 0x0b},
    {.src = 0x6027, .y = 0x08, .x = 0x0b},
    {.src = 0x6027, .y = 0x07, .x = 0x0b},
    {.src = 0x6023, .y = 0x07, .x = 0x0c},
    {.src = 0x6027, .y = 0x08, .x = 0x0c},
    {.src = 0x6027, .y = 0x09, .x = 0x0c},
    {.src = 0x6027, .y = 0x0a, .x = 0x0c},
    {.src = 0x603b, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d680[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x09},
    {.src = 0x6023, .y = 0x0c, .x = 0x0a},
    {.src = 0x6047, .y = 0x0d, .x = 0x0a},
    {.src = 0x6043, .y = 0x0d, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d690[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x09},
    {.src = 0x6023, .y = 0x0c, .x = 0x0a},
    {.src = 0x6047, .y = 0x0d, .x = 0x0a},
    {.src = 0x6023, .y = 0x0d, .x = 0x0b},
    {.src = 0x6027, .y = 0x0e, .x = 0x0b},
    {.src = 0x6047, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d6ac[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x09},
    {.src = 0x6023, .y = 0x0c, .x = 0x0a},
    {.src = 0x6047, .y = 0x0d, .x = 0x0a},
    {.src = 0x6023, .y = 0x0d, .x = 0x0b},
    {.src = 0x6027, .y = 0x0e, .x = 0x0b},
    {.src = 0x6047, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d6d8[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x09},
    {.src = 0x6023, .y = 0x0c, .x = 0x0a},
    {.src = 0x6047, .y = 0x0d, .x = 0x0a},
    {.src = 0x6023, .y = 0x0d, .x = 0x0b},
    {.src = 0x6027, .y = 0x0e, .x = 0x0b},
    {.src = 0x6047, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d70c[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x09},
    {.src = 0x6021, .y = 0x0e, .x = 0x0a},
    {.src = 0x6027, .y = 0x0d, .x = 0x0a},
    {.src = 0x6043, .y = 0x0d, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d71c[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x09},
    {.src = 0x6021, .y = 0x0e, .x = 0x0a},
    {.src = 0x6027, .y = 0x0d, .x = 0x0a},
    {.src = 0x6023, .y = 0x0d, .x = 0x0b},
    {.src = 0x6027, .y = 0x0e, .x = 0x0b},
    {.src = 0x6047, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d738[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x09},
    {.src = 0x6021, .y = 0x0e, .x = 0x0a},
    {.src = 0x6027, .y = 0x0d, .x = 0x0a},
    {.src = 0x6023, .y = 0x0d, .x = 0x0b},
    {.src = 0x6027, .y = 0x0e, .x = 0x0b},
    {.src = 0x6047, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d764[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x09},
    {.src = 0x6021, .y = 0x0e, .x = 0x0a},
    {.src = 0x6027, .y = 0x0d, .x = 0x0a},
    {.src = 0x6023, .y = 0x0d, .x = 0x0b},
    {.src = 0x6027, .y = 0x0e, .x = 0x0b},
    {.src = 0x6047, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d798[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x09},
    {.src = 0x6023, .y = 0x10, .x = 0x0a},
    {.src = 0x6047, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d7a8[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x09},
    {.src = 0x6023, .y = 0x10, .x = 0x0a},
    {.src = 0x6047, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
    {.src = 0x6027, .y = 0x10, .x = 0x0b},
    {.src = 0x6027, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d7c4[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x09},
    {.src = 0x6023, .y = 0x10, .x = 0x0a},
    {.src = 0x6047, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
    {.src = 0x6027, .y = 0x10, .x = 0x0b},
    {.src = 0x6027, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d7f0[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x09},
    {.src = 0x6023, .y = 0x10, .x = 0x0a},
    {.src = 0x6047, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
    {.src = 0x6027, .y = 0x10, .x = 0x0b},
    {.src = 0x6027, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d824[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x09},
    {.src = 0x602b, .y = 0x12, .x = 0x0a},
    {.src = 0x6027, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
};

static const struct UnkStruct_860DD10 gUnknown_0860d834[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x09},
    {.src = 0x602b, .y = 0x12, .x = 0x0a},
    {.src = 0x6027, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
    {.src = 0x6027, .y = 0x10, .x = 0x0b},
    {.src = 0x6027, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d850[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x09},
    {.src = 0x602b, .y = 0x12, .x = 0x0a},
    {.src = 0x6027, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
    {.src = 0x6027, .y = 0x10, .x = 0x0b},
    {.src = 0x6027, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
};

static const struct UnkStruct_860DD10 gUnknown_0860d87c[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x09},
    {.src = 0x602b, .y = 0x12, .x = 0x0a},
    {.src = 0x6027, .y = 0x11, .x = 0x0a},
    {.src = 0x6021, .y = 0x11, .x = 0x0b},
    {.src = 0x6027, .y = 0x10, .x = 0x0b},
    {.src = 0x6027, .y = 0x0f, .x = 0x0b},
    {.src = 0x6021, .y = 0x0f, .x = 0x0c},
    {.src = 0x6033, .y = 0x0e, .x = 0x0c},
    {.src = 0x6032, .y = 0x0d, .x = 0x0c},
    {.src = 0x6031, .y = 0x0c, .x = 0x0c},
    {.src = 0x6030, .y = 0x0b, .x = 0x0c},
    {.src = 0x602c, .y = 0x0b, .x = 0x0d},
    {.src = 0x602d, .y = 0x0b, .x = 0x0e},
};

static const struct UnkStruct_860DD10 gUnknown_0860d8b0[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x14},
    {.src = 0x6025, .y = 0x04, .x = 0x13},
    {.src = 0x6049, .y = 0x05, .x = 0x13},
    {.src = 0x6045, .y = 0x05, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860d8c0[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x14},
    {.src = 0x6025, .y = 0x04, .x = 0x13},
    {.src = 0x6049, .y = 0x05, .x = 0x13},
    {.src = 0x6025, .y = 0x05, .x = 0x12},
    {.src = 0x6029, .y = 0x06, .x = 0x12},
    {.src = 0x6049, .y = 0x07, .x = 0x12},
    {.src = 0x6045, .y = 0x07, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860d8dc[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x14},
    {.src = 0x6025, .y = 0x04, .x = 0x13},
    {.src = 0x6049, .y = 0x05, .x = 0x13},
    {.src = 0x6025, .y = 0x05, .x = 0x12},
    {.src = 0x6029, .y = 0x06, .x = 0x12},
    {.src = 0x6049, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860d908[] =
{
    {.src = 0x6021, .y = 0x04, .x = 0x14},
    {.src = 0x6025, .y = 0x04, .x = 0x13},
    {.src = 0x6049, .y = 0x05, .x = 0x13},
    {.src = 0x6025, .y = 0x05, .x = 0x12},
    {.src = 0x6029, .y = 0x06, .x = 0x12},
    {.src = 0x6049, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 gUnknown_0860d93c[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x14},
    {.src = 0x6021, .y = 0x06, .x = 0x13},
    {.src = 0x6029, .y = 0x05, .x = 0x13},
    {.src = 0x6045, .y = 0x05, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860d94c[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x14},
    {.src = 0x6021, .y = 0x06, .x = 0x13},
    {.src = 0x6029, .y = 0x05, .x = 0x13},
    {.src = 0x6025, .y = 0x05, .x = 0x12},
    {.src = 0x6029, .y = 0x06, .x = 0x12},
    {.src = 0x6049, .y = 0x07, .x = 0x12},
    {.src = 0x6045, .y = 0x07, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860d968[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x14},
    {.src = 0x6021, .y = 0x06, .x = 0x13},
    {.src = 0x6029, .y = 0x05, .x = 0x13},
    {.src = 0x6025, .y = 0x05, .x = 0x12},
    {.src = 0x6029, .y = 0x06, .x = 0x12},
    {.src = 0x6049, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860d994[] =
{
    {.src = 0x6021, .y = 0x06, .x = 0x14},
    {.src = 0x6021, .y = 0x06, .x = 0x13},
    {.src = 0x6029, .y = 0x05, .x = 0x13},
    {.src = 0x6025, .y = 0x05, .x = 0x12},
    {.src = 0x6029, .y = 0x06, .x = 0x12},
    {.src = 0x6049, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 gUnknown_0860d9c8[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x14},
    {.src = 0x6025, .y = 0x08, .x = 0x13},
    {.src = 0x6049, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860d9d8[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x14},
    {.src = 0x6025, .y = 0x08, .x = 0x13},
    {.src = 0x6049, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
    {.src = 0x6029, .y = 0x08, .x = 0x12},
    {.src = 0x6029, .y = 0x07, .x = 0x12},
    {.src = 0x6045, .y = 0x07, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860d9f4[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x14},
    {.src = 0x6025, .y = 0x08, .x = 0x13},
    {.src = 0x6049, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
    {.src = 0x6029, .y = 0x08, .x = 0x12},
    {.src = 0x6029, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860da20[] =
{
    {.src = 0x6021, .y = 0x08, .x = 0x14},
    {.src = 0x6025, .y = 0x08, .x = 0x13},
    {.src = 0x6049, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
    {.src = 0x6029, .y = 0x08, .x = 0x12},
    {.src = 0x6029, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 gUnknown_0860da54[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x14},
    {.src = 0x6021, .y = 0x0a, .x = 0x13},
    {.src = 0x6029, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860da64[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x14},
    {.src = 0x6021, .y = 0x0a, .x = 0x13},
    {.src = 0x6029, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
    {.src = 0x6029, .y = 0x08, .x = 0x12},
    {.src = 0x6029, .y = 0x07, .x = 0x12},
    {.src = 0x6045, .y = 0x07, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860da80[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x14},
    {.src = 0x6021, .y = 0x0a, .x = 0x13},
    {.src = 0x6029, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
    {.src = 0x6029, .y = 0x08, .x = 0x12},
    {.src = 0x6029, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860daac[] =
{
    {.src = 0x6021, .y = 0x0a, .x = 0x14},
    {.src = 0x6021, .y = 0x0a, .x = 0x13},
    {.src = 0x6029, .y = 0x09, .x = 0x13},
    {.src = 0x6021, .y = 0x09, .x = 0x12},
    {.src = 0x6029, .y = 0x08, .x = 0x12},
    {.src = 0x6029, .y = 0x07, .x = 0x12},
    {.src = 0x6025, .y = 0x07, .x = 0x11},
    {.src = 0x6029, .y = 0x08, .x = 0x11},
    {.src = 0x6029, .y = 0x09, .x = 0x11},
    {.src = 0x6029, .y = 0x0a, .x = 0x11},
    {.src = 0x603c, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 gUnknown_0860dae0[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x14},
    {.src = 0x6025, .y = 0x0c, .x = 0x13},
    {.src = 0x6049, .y = 0x0d, .x = 0x13},
    {.src = 0x6045, .y = 0x0d, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860daf0[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x14},
    {.src = 0x6025, .y = 0x0c, .x = 0x13},
    {.src = 0x6049, .y = 0x0d, .x = 0x13},
    {.src = 0x6025, .y = 0x0d, .x = 0x12},
    {.src = 0x6029, .y = 0x0e, .x = 0x12},
    {.src = 0x6049, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860db0c[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x14},
    {.src = 0x6025, .y = 0x0c, .x = 0x13},
    {.src = 0x6049, .y = 0x0d, .x = 0x13},
    {.src = 0x6025, .y = 0x0d, .x = 0x12},
    {.src = 0x6029, .y = 0x0e, .x = 0x12},
    {.src = 0x6049, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860db38[] =
{
    {.src = 0x6021, .y = 0x0c, .x = 0x14},
    {.src = 0x6025, .y = 0x0c, .x = 0x13},
    {.src = 0x6049, .y = 0x0d, .x = 0x13},
    {.src = 0x6025, .y = 0x0d, .x = 0x12},
    {.src = 0x6029, .y = 0x0e, .x = 0x12},
    {.src = 0x6049, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 gUnknown_0860db6c[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x14},
    {.src = 0x6021, .y = 0x0e, .x = 0x13},
    {.src = 0x6029, .y = 0x0d, .x = 0x13},
    {.src = 0x6045, .y = 0x0d, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860db7c[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x14},
    {.src = 0x6021, .y = 0x0e, .x = 0x13},
    {.src = 0x6029, .y = 0x0d, .x = 0x13},
    {.src = 0x6025, .y = 0x0d, .x = 0x12},
    {.src = 0x6029, .y = 0x0e, .x = 0x12},
    {.src = 0x6049, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860db98[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x14},
    {.src = 0x6021, .y = 0x0e, .x = 0x13},
    {.src = 0x6029, .y = 0x0d, .x = 0x13},
    {.src = 0x6025, .y = 0x0d, .x = 0x12},
    {.src = 0x6029, .y = 0x0e, .x = 0x12},
    {.src = 0x6049, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860dbc4[] =
{
    {.src = 0x6021, .y = 0x0e, .x = 0x14},
    {.src = 0x6021, .y = 0x0e, .x = 0x13},
    {.src = 0x6029, .y = 0x0d, .x = 0x13},
    {.src = 0x6025, .y = 0x0d, .x = 0x12},
    {.src = 0x6029, .y = 0x0e, .x = 0x12},
    {.src = 0x6049, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 gUnknown_0860dbf8[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x14},
    {.src = 0x6025, .y = 0x10, .x = 0x13},
    {.src = 0x6049, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860dc08[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x14},
    {.src = 0x6025, .y = 0x10, .x = 0x13},
    {.src = 0x6049, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
    {.src = 0x6029, .y = 0x10, .x = 0x12},
    {.src = 0x6029, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860dc24[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x14},
    {.src = 0x6025, .y = 0x10, .x = 0x13},
    {.src = 0x6049, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
    {.src = 0x6029, .y = 0x10, .x = 0x12},
    {.src = 0x6029, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860dc50[] =
{
    {.src = 0x6021, .y = 0x10, .x = 0x14},
    {.src = 0x6025, .y = 0x10, .x = 0x13},
    {.src = 0x6049, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
    {.src = 0x6029, .y = 0x10, .x = 0x12},
    {.src = 0x6029, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 gUnknown_0860dc84[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x14},
    {.src = 0x602b, .y = 0x12, .x = 0x13},
    {.src = 0x6029, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
};

static const struct UnkStruct_860DD10 gUnknown_0860dc94[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x14},
    {.src = 0x602b, .y = 0x12, .x = 0x13},
    {.src = 0x6029, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
    {.src = 0x6029, .y = 0x10, .x = 0x12},
    {.src = 0x6029, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860dcb0[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x14},
    {.src = 0x602b, .y = 0x12, .x = 0x13},
    {.src = 0x6029, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
    {.src = 0x6029, .y = 0x10, .x = 0x12},
    {.src = 0x6029, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
};

static const struct UnkStruct_860DD10 gUnknown_0860dcdc[] =
{
    {.src = 0x602b, .y = 0x12, .x = 0x14},
    {.src = 0x602b, .y = 0x12, .x = 0x13},
    {.src = 0x6029, .y = 0x11, .x = 0x13},
    {.src = 0x6021, .y = 0x11, .x = 0x12},
    {.src = 0x6029, .y = 0x10, .x = 0x12},
    {.src = 0x6029, .y = 0x0f, .x = 0x12},
    {.src = 0x6021, .y = 0x0f, .x = 0x11},
    {.src = 0x6038, .y = 0x0e, .x = 0x11},
    {.src = 0x6037, .y = 0x0d, .x = 0x11},
    {.src = 0x6036, .y = 0x0c, .x = 0x11},
    {.src = 0x6035, .y = 0x0b, .x = 0x11},
    {.src = 0x602f, .y = 0x0b, .x = 0x10},
    {.src = 0x602e, .y = 0x0b, .x = 0x0f},
};

static const struct UnkStruct_860DD10 * const gUnknown_0860DD10[DOME_TOURNAMENT_TRAINERS_COUNT][4] =
{
    {gUnknown_0860d450, gUnknown_0860d460, gUnknown_0860d47c, gUnknown_0860d4a8},
    {gUnknown_0860dc84, gUnknown_0860dc94, gUnknown_0860dcb0, gUnknown_0860dcdc},
    {gUnknown_0860d8b0, gUnknown_0860d8c0, gUnknown_0860d8dc, gUnknown_0860d908},
    {gUnknown_0860d824, gUnknown_0860d834, gUnknown_0860d850, gUnknown_0860d87c},
    {gUnknown_0860d5f4, gUnknown_0860d604, gUnknown_0860d620, gUnknown_0860d64c},
    {gUnknown_0860dae0, gUnknown_0860daf0, gUnknown_0860db0c, gUnknown_0860db38},
    {gUnknown_0860da54, gUnknown_0860da64, gUnknown_0860da80, gUnknown_0860daac},
    {gUnknown_0860d680, gUnknown_0860d690, gUnknown_0860d6ac, gUnknown_0860d6d8},
    {gUnknown_0860d4dc, gUnknown_0860d4ec, gUnknown_0860d508, gUnknown_0860d534},
    {gUnknown_0860dbf8, gUnknown_0860dc08, gUnknown_0860dc24, gUnknown_0860dc50},
    {gUnknown_0860d93c, gUnknown_0860d94c, gUnknown_0860d968, gUnknown_0860d994},
    {gUnknown_0860d798, gUnknown_0860d7a8, gUnknown_0860d7c4, gUnknown_0860d7f0},
    {gUnknown_0860d568, gUnknown_0860d578, gUnknown_0860d594, gUnknown_0860d5c0},
    {gUnknown_0860db6c, gUnknown_0860db7c, gUnknown_0860db98, gUnknown_0860dbc4},
    {gUnknown_0860d9c8, gUnknown_0860d9d8, gUnknown_0860d9f4, gUnknown_0860da20},
    {gUnknown_0860d70c, gUnknown_0860d71c, gUnknown_0860d738, gUnknown_0860d764},
};

static const u8 gUnknown_0860DE10[DOME_TOURNAMENT_TRAINERS_COUNT][4] =
{
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
    {0x04, 0x07, 0x0b, 0x0d},
};

// code
void CallBattleDomeFunction(void)
{
    sBattleDomeFunctions[gSpecialVar_0x8004]();
}

static void InitDomeChallenge(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860D0EC[battleMode][lvlMode]))
        gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

static void GetDomeData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
        break;
    case 1:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860D0EC[battleMode][lvlMode]) != 0);
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_0;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_1;
        break;
    case 4:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_2;
        break;
    case 5:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_3;
        break;
    case 6:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_5;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_4;
        }
        else
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_1;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_0;
        }
        break;
    case 7:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_7;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_6;
        }
        else
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_3;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_2;
        }
        break;
    case 8:
        sub_81B8558();
        gSelectedOrderFromParty[0] = gSaveBlock2Ptr->frontier.field_CB0;
        gSelectedOrderFromParty[1] = gSaveBlock2Ptr->frontier.field_CB0 >> 8;
        break;
    case 9:
        gSpecialVar_Result = (gSaveBlock2Ptr->frontier.field_D0A * 2) - 3 + gSaveBlock2Ptr->frontier.field_D0B;
        break;
    }
}

static void SetDomeData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case 1:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_0860D0EC[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_0860D0FC[battleMode][lvlMode];
        break;
    case 2:
        gSaveBlock2Ptr->frontier.field_D08_0 = gSpecialVar_0x8006;
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D08_1 = gSpecialVar_0x8006;
        break;
    case 4:
        gSaveBlock2Ptr->frontier.field_D08_2 = gSpecialVar_0x8006;
        break;
    case 5:
        gSaveBlock2Ptr->frontier.field_D08_3 = gSpecialVar_0x8006;
        break;
    case 6:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_5 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_4 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_1 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_0 = gSpecialVar_0x8006;
        }
        break;
    case 7:
        if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_7 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_6 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_3 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_2 = gSpecialVar_0x8006;
        }
        break;
    case 8:
        gSaveBlock2Ptr->frontier.field_CB0 = T1_READ_16(gSelectedOrderFromParty);
        break;
    }
}

static void InitDomeTrainers(void)
{
    int i, j, k;
    int monLevel;
    int species[3];
    int monTypesBits, monTypesCount;
    int trainerId;
    int monSetId;
    u16 *statSums;
    int *statValues;
    u8 ivs = 0;

    species[0] = 0;
    species[1] = 0;
    species[2] = 0;
    statSums = AllocZeroed(sizeof(u16) * DOME_TOURNAMENT_TRAINERS_COUNT);
    statValues = AllocZeroed(sizeof(int) * 6);

    gSaveBlock2Ptr->frontier.field_D0A = gSaveBlock2Ptr->frontier.lvlMode + 1;
    gSaveBlock2Ptr->frontier.field_D0B = VarGet(VAR_FRONTIER_BATTLE_MODE) + 1;
    gSaveBlock2Ptr->frontier.domeTrainers[0].trainerId = TRAINER_PLAYER;
    gSaveBlock2Ptr->frontier.domeTrainers[0].isEliminated = 0;
    gSaveBlock2Ptr->frontier.domeTrainers[0].eliminatedAt = 0;
    gSaveBlock2Ptr->frontier.domeTrainers[0].unk3 = 0;

    for (i = 0; i < 3; i++)
    {
        gSaveBlock2Ptr->frontier.domeMonIds[0][i] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_SPECIES, NULL);
        for (j = 0; j < MAX_MON_MOVES; j++)
            gSaveBlock2Ptr->frontier.field_EFC[i].moves[j] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_MOVE1 + j, NULL);
        for (j = 0; j < 6; j++)
            gSaveBlock2Ptr->frontier.field_EFC[i].evs[j] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_HP_EV + j, NULL);

        gSaveBlock2Ptr->frontier.field_EFC[i].nature = GetNature(&gPlayerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1]);
    }

    for (i = 1; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (i > 5)
        {
            do
            {
                trainerId = sub_8162548(GetCurrentFacilityWinStreak(), 0);
                for (j = 1; j < i; j++)
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId == trainerId)
                        break;
                }
            } while (j != i);
            gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId = trainerId;
        }
        else
        {
            do
            {
                trainerId = sub_8162548(GetCurrentFacilityWinStreak() + 1, 0);
                for (j = 1; j < i; j++)
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId == trainerId)
                        break;
                }
            } while (j != i);
            gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId = trainerId;
        }

        for (j = 0; j < 3; j++)
        {
            // Make sure the mon is valid.
            do
            {
                monSetId = RandomizeFacilityTrainerMonSet(trainerId);
                for (k = 0; k < j; k++)
                {
                    int checkingMonSetId = gSaveBlock2Ptr->frontier.domeMonIds[i][k];
                    if (checkingMonSetId == monSetId
                        || species[0] == gFacilityTrainerMons[monSetId].species
                        || species[1] == gFacilityTrainerMons[monSetId].species
                        || gFacilityTrainerMons[checkingMonSetId].itemTableId == gFacilityTrainerMons[monSetId].itemTableId)
                        break;
                }
            } while (k != j);

            gSaveBlock2Ptr->frontier.domeMonIds[i][j] = monSetId;
            species[j] = gFacilityTrainerMons[monSetId].species;
        }

        gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated = 0;
        gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt = 0;
        gSaveBlock2Ptr->frontier.domeTrainers[i].unk3 = 0;
    }

    monTypesBits = 0;
    statSums[0] = 0;
    for (i = 0; i < 3; i++)
    {
        trainerId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1; // Great variable choice, gamefreak.
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_ATK, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_DEF, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_SPATK, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_SPDEF, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_SPEED, NULL);
        statSums[0] += GetMonData(&gPlayerParty[trainerId], MON_DATA_MAX_HP, NULL);
        monTypesBits |= gBitTable[gBaseStats[GetMonData(&gPlayerParty[trainerId], MON_DATA_SPECIES, NULL)].type1];
        monTypesBits |= gBitTable[gBaseStats[GetMonData(&gPlayerParty[trainerId], MON_DATA_SPECIES, NULL)].type2];
    }

    for (monTypesCount = 0, j = 0; j < 32; j++)
    {
        if (monTypesBits & 1)
            monTypesCount++;
        monTypesBits >>= 1;
    }

    monLevel = SetFacilityPtrsGetLevel();
    statSums[0] += (monTypesCount * monLevel) / 20;

    for (i = 1; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        monTypesBits = 0;
        statSums[i] = 0;
        ivs = GetDomeTrainerMonIvs(gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId);
        for (j = 0; j < 3; j++)
        {
            CalcDomeMonStats(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].species,
                             monLevel, ivs,
                             gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].evSpread,
                             gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].nature,
                             statValues);

            statSums[i] += statValues[STAT_ATK];
            statSums[i] += statValues[STAT_DEF];
            statSums[i] += statValues[STAT_SPATK];
            statSums[i] += statValues[STAT_SPDEF];
            statSums[i] += statValues[STAT_SPEED];
            statSums[i] += statValues[STAT_HP];
            monTypesBits |= gBitTable[gBaseStats[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].species].type1];
            monTypesBits |= gBitTable[gBaseStats[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].species].type2];
        }

        for (monTypesCount = 0, j = 0; j < 32; j++)
        {
            if (monTypesBits & 1)
                monTypesCount++;
            monTypesBits >>= 1;
        }
        statSums[i] += (monTypesCount * monLevel) / 20;
    }

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT - 1; i++)
    {
        for (j = i + 1; j < DOME_TOURNAMENT_TRAINERS_COUNT; j++)
        {
            if (statSums[i] < statSums[j])
            {
                SwapDomeTrainers(i, j, statSums);
            }
            else
            {
                if (statSums[i] == statSums[j])
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId == TRAINER_PLAYER)
                        SwapDomeTrainers(i, j, statSums);
                    else if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId > gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId)
                        SwapDomeTrainers(i, j, statSums);
                }
            }
        }
    }

    if (sub_81A3610())
    {
        for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
        {
            if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == TRAINER_PLAYER)
                break;
        }

        if (gUnknown_0860D3F1[i][0] != 0)
        {
            j = 0;
            gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId = TRAINER_FRONTIER_BRAIN;
        }
        else
        {
            j = 1;
            gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId = TRAINER_FRONTIER_BRAIN;
        }

        for (i = 0; i < 3; i++)
            gSaveBlock2Ptr->frontier.domeMonIds[j][i] = GetFrontierBrainMonSpecies(i);
    }

    Free(statSums);
    Free(statValues);
}

#define CALC_STAT(base, statIndex)                                                          \
{                                                                                           \
    u8 baseStat = gBaseStats[species].base;                                                 \
    stats[statIndex] = (((2 * baseStat + ivs + evs[statIndex] / 4) * level) / 100) + 5;     \
    stats[statIndex] = (u8) ModifyStatByNature(nature, stats[statIndex], statIndex);        \
}

static void CalcDomeMonStats(u16 species, int level, int ivs, u8 evBits, u8 nature, int *stats)
{
    int i, count;
    u8 bits;
    u16 resultingEvs;
    int evs[NUM_STATS];

    count = 0, bits = evBits;
    for (i = 0; i < NUM_STATS; bits >>= 1, i++)
    {
        if (bits & 1)
            count++;
    }

    resultingEvs = MAX_TOTAL_EVS / count;
    for (i = 0; i < NUM_STATS; bits <<= 1, i++)
    {
        evs[i] = 0;
        if (evBits & bits)
            evs[i] = resultingEvs;
    }

    if (species == SPECIES_SHEDINJA)
    {
        stats[STAT_HP] = 1;
    }
    else
    {
        int n = 2 * gBaseStats[species].baseHP;
        stats[STAT_HP] = (((n + ivs + evs[STAT_HP] / 4) * level) / 100) + level + 10;
    }

    CALC_STAT(baseAttack, STAT_ATK);
    CALC_STAT(baseDefense, STAT_DEF);
    CALC_STAT(baseSpeed, STAT_SPEED);
    CALC_STAT(baseSpAttack, STAT_SPATK);
    CALC_STAT(baseSpDefense, STAT_SPDEF);
}

static void SwapDomeTrainers(int id1, int id2, u16 *statsArray)
{
    int i;
    u16 temp;

    SWAP(statsArray[id1], statsArray[id2], temp);
    SWAP(gSaveBlock2Ptr->frontier.domeTrainers[id1].trainerId, gSaveBlock2Ptr->frontier.domeTrainers[id2].trainerId, temp);

    for (i = 0; i < 3; i++)
        SWAP(gSaveBlock2Ptr->frontier.domeMonIds[id1][i], gSaveBlock2Ptr->frontier.domeMonIds[id2][i], temp);
}

static void BufferDomeRoundText(void)
{
    StringCopy(gStringVar1, gRoundsStringTable[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
}

static void BufferDomeOpponentName(void)
{
    StringCopy(gStringVar1, gRoundsStringTable[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
    CopyDomeTrainerName(gStringVar2, gTrainerBattleOpponent_A);
}

static void InitDomeOpponentParty(void)
{
    gUnknown_0203CD70 = 0;
    gUnknown_0203CD74 =  GetMonData(&gPlayerParty[0], MON_DATA_MAX_HP, NULL);
    gUnknown_0203CD74 += GetMonData(&gPlayerParty[1], MON_DATA_MAX_HP, NULL);
    CalculatePlayerPartyCount();
    CreateDomeOpponentMons(TrainerIdToTournamentId(gTrainerBattleOpponent_A));
}

static void CreateDomeOpponentMon(u8 monPartyId, u16 tournamentTrainerId, u8 tournamentMonId, u32 otId)
{
    int i;
    u8 happiness = 0xFF;
    u8 fixedIv = GetDomeTrainerMonIvs(tournamentTrainerId); // BUG: Should be using trainerId instead of tournamentTrainerId. As a result, all Pokemon have ivs of 3.
    u8 level = SetFacilityPtrsGetLevel();
    CreateMonWithEVSpreadNatureOTID(&gEnemyParty[monPartyId],
                                         gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][tournamentMonId]].species,
                                         level,
                                         gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][tournamentMonId]].nature,
                                         fixedIv,
                                         gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][tournamentMonId]].evSpread, otId);

    happiness = 0xFF;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        SetMonMoveSlot(&gEnemyParty[monPartyId],
                       gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][tournamentMonId]].moves[i], i);
        if (gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][tournamentMonId]].moves[i] == MOVE_FRUSTRATION)
            happiness = 0;
    }

    SetMonData(&gEnemyParty[monPartyId], MON_DATA_FRIENDSHIP, &happiness);
    SetMonData(&gEnemyParty[monPartyId], MON_DATA_HELD_ITEM,
               &gBattleFrontierHeldItems[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][tournamentMonId]].itemTableId]);
}

static void CreateDomeOpponentMons(u16 tournamentTrainerId)
{
    u8 monsCount = 0;
    u32 otId = 0;
    int i, bits;

    ZeroEnemyPartyMons();
    bits = GetDomeTrainerMonCountInBits(tournamentTrainerId);
    otId = Random32();
    if (Random() % 10 > 5)
    {
        for (i = 0; i < 3; i++)
        {
            if (bits & 1)
            {
                CreateDomeOpponentMon(monsCount, tournamentTrainerId, i, otId);
                monsCount++;
            }
            bits >>= 1;
        }
    }
    else
    {
        for (i = 2; i >= 0; i--)
        {
            if (bits & 4)
            {
                CreateDomeOpponentMon(monsCount, tournamentTrainerId, i, otId);
                monsCount++;
            }
            bits <<= 1;
        }
    }
}

int GetDomeTrainerMonCountInBits(u16 tournamentTrainerId)
{
    int bits;
    if (Random() & 1)
    {
        bits = sub_818FCBC(tournamentTrainerId, FALSE);
        if (bits == 0)
            bits = sub_818FDB8(tournamentTrainerId, TRUE);
    }
    else
    {
        bits = sub_818FDB8(tournamentTrainerId, FALSE);
        if (bits == 0)
            bits = sub_818FCBC(tournamentTrainerId, TRUE);
    }

    return bits;
}

static int sub_818FCBC(u16 tournamentTrainerId, bool8 arg1)
{
    int i, moveId, playerMonId;
    int array[3];

    for (i = 0; i < 3; i++)
    {
        array[i] = 0;
        for (moveId = 0; moveId < MAX_MON_MOVES; moveId++)
        {
            for (playerMonId = 0; playerMonId < 3; playerMonId++)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentTrainerId].trainerId == TRAINER_FRONTIER_BRAIN)
                {
                    array[i] += GetTypeEffectivenessPoints(GetFrontierBrainMonMove(i, moveId),
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 0);
                }
                else
                {
                    array[i] += GetTypeEffectivenessPoints(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][i]].moves[moveId],
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 0);
                }
            }
        }
    }
    return sub_818FEB4(array, arg1);
}

static int sub_818FDB8(u16 tournamentTrainerId, bool8 arg1)
{
    int i, moveId, playerMonId;
    int array[3];

    for (i = 0; i < 3; i++)
    {
        array[i] = 0;
        for (moveId = 0; moveId < MAX_MON_MOVES; moveId++)
        {
            for (playerMonId = 0; playerMonId < 3; playerMonId++)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentTrainerId].trainerId == TRAINER_FRONTIER_BRAIN)
                {
                    array[i] += GetTypeEffectivenessPoints(GetFrontierBrainMonMove(i, moveId),
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 1);
                }
                else
                {
                    array[i] += GetTypeEffectivenessPoints(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentTrainerId][i]].moves[moveId],
                                            GetMonData(&gPlayerParty[playerMonId], MON_DATA_SPECIES, NULL), 1);
                }
            }
        }
    }
    return sub_818FEB4(array, arg1);
}

static int sub_818FEB4(int *arr, bool8 arg1)
{
    int i, j;
    int bits = 0;
    int array[3];

    for (i = 0; i < 3; i++)
        array[i] = i;

    if (arr[0] == arr[1] && arr[0] == arr[2])
    {
        if (arg1)
        {
            i = 0;
            while (i != 2)
            {
                u32 rand = Random() & 3;
                if (rand != 3 && !(bits & gBitTable[rand]))
                {
                    bits |= gBitTable[rand];
                    i++;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            for (j = i + 1; j < 3; j++)
            {
                int temp;

                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }

                if (arr[i] == arr[j] && (Random() & 1))
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;

                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }

        for (i = 0; i < 2; i++)
        {
            bits |= gBitTable[array[i]];
        }
    }

    return bits;
}

#define TYPE_x0     0
#define TYPE_x0_25  5
#define TYPE_x0_50  10
#define TYPE_x1     20
#define TYPE_x2     40
#define TYPE_x4     80

static int GetTypeEffectivenessPoints(int move, int targetSpecies, int arg2)
{
    int defType1, defType2, defAbility, moveType;
    int i = 0;
    int typePower = TYPE_x1;

    if (move == MOVE_NONE || move == 0xFFFF || gBattleMoves[move].power == 0)
        return 0;

    defType1 = gBaseStats[targetSpecies].type1;
    defType2 = gBaseStats[targetSpecies].type2;
    defAbility = gBaseStats[targetSpecies].ability1;
    moveType = gBattleMoves[move].type;

    if (defAbility == ABILITY_LEVITATE && moveType == TYPE_GROUND)
    {
        if (arg2 == 1)
            typePower = 8;
    }
    else
    {
        u32 typeEffectiveness1 = UQ_4_12_TO_INT(GetTypeModifier(moveType, defType1) * 2) * 5;
        u32 typeEffectiveness2 = UQ_4_12_TO_INT(GetTypeModifier(moveType, defType2) * 2) * 5;

        typePower = (typeEffectiveness1 * typePower) / 10;
        if (defType2 != defType1)
            typePower = (typeEffectiveness2 * typePower) / 10;

        if (defAbility == ABILITY_WONDER_GUARD && typeEffectiveness1 != 20 && typeEffectiveness2 != 20)
            typePower = 0;
    }

    switch (arg2)
    {
    case 0:
        switch (typePower)
        {
        case 10:
        case 5:
        case 0:
        default:
            typePower = 0;
            break;
        case 20:
            typePower = 2;
            break;
        case 40:
            typePower = 4;
            break;
        case 80:
            typePower = 8;
            break;
        }
        break;
    case 1:
        switch (typePower)
        {
        default:
        case 20:
            typePower = 0;
            break;
        case 5:
            typePower = 4;
            break;
        case 0:
            typePower = 8;
            break;
        case 10:
            typePower = 2;
            break;
        case 40:
            typePower = -2;
            break;
        case 80:
            typePower = -4;
            break;
        }
        break;
    case 2:
        switch (typePower)
        {
        case TYPE_x0:
            typePower = -16;
            break;
        case TYPE_x0_25:
            typePower = -8;
            break;
        case TYPE_x0_50:
        default:
            typePower = 0;
            break;
        case TYPE_x1:
            typePower = 4;
            break;
        case TYPE_x2:
            typePower = 12;
            break;
        case TYPE_x4:
            typePower = 20;
            break;
        }
        break;
    }

    return typePower;
}

static u8 GetDomeTrainerMonIvs(u16 trainerId)
{
    u8 fixedIv;
    if (trainerId <= 99)
        fixedIv = 3;
    else if (trainerId <= 119)
        fixedIv = 6;
    else if (trainerId <= 139)
        fixedIv = 9;
    else if (trainerId <= 159)
        fixedIv = 12;
    else if (trainerId <= 179)
        fixedIv = 15;
    else if (trainerId <= 199)
        fixedIv = 18;
    else if (trainerId <= 219)
        fixedIv = 21;
    else
        fixedIv = 31;

    return fixedIv;
}

static int TournamentIdOfOpponent(int roundId, int trainerId)
{
    int i, j, val;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == trainerId)
            break;
    }

    if (roundId != DOME_ROUND1)
    {
        if (roundId == DOME_FINAL)
            val = sIdToOpponentId[i][roundId] + 8;
        else
            val = sIdToOpponentId[i][roundId] + 4;

        for (j = sIdToOpponentId[i][roundId]; j < val; j++)
        {
            if (gUnknown_0860D14C[j] != i && !gSaveBlock2Ptr->frontier.domeTrainers[gUnknown_0860D14C[j]].isEliminated)
                break;
        }

        if (j != val)
            return gUnknown_0860D14C[j];
        else
            return 0xFF;
    }
    else
    {
        if (!gSaveBlock2Ptr->frontier.domeTrainers[sIdToOpponentId[i][roundId]].isEliminated)
            return sIdToOpponentId[i][roundId];
        else
            return 0xFF;
    }
}

static void SetDomeOpponentId(void)
{
    gTrainerBattleOpponent_A = TrainerIdOfPlayerOpponent();
}

static u16 TrainerIdOfPlayerOpponent(void)
{
    return gSaveBlock2Ptr->frontier.domeTrainers[TournamentIdOfOpponent(gSaveBlock2Ptr->frontier.curChallengeBattleNum, TRAINER_PLAYER)].trainerId;
}

static void SetDomeOpponentGraphicsId(void)
{
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void sub_81902F8(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    sub_81A4C30();
}

static void UpdateDomeStreaks(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] < 999)
        gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode]++;
    if (gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode] < 999)
        gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode]++;

    if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode])
        gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
}

static void ShowDomeOpponentInfo(void)
{
    u8 taskId = CreateTask(Task_ShowOpponentInfo, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = TrainerIdToTournamentId(TrainerIdOfPlayerOpponent());
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;

    SetMainCallback2(CB2_BattleDome);
}

static void Task_ShowOpponentInfo(u8 taskId)
{
    int i;
    int r5 = gTasks[taskId].data[1];
    int r9 = gTasks[taskId].data[2];
    int r7 = gTasks[taskId].data[3];

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        EnableInterrupts(INTR_FLAG_VBLANK);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_0860CE84, ARRAY_COUNT(gUnknown_0860CE84));
        InitWindows(gUnknown_0860CEB4);
        DeactivateAllTextPrinters();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;
        if (r9 == 2)
            gBattle_BG2_X = 0, gBattle_BG2_Y = 0;
        else
            gBattle_BG2_X = 0, gBattle_BG2_Y = 160;

        gTasks[taskId].data[0]++;
        break;
    case 1:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        DecompressAndLoadBgGfxUsingHeap(2, gUnknown_08D83D50, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, gUnknown_08D84970, 0x2000, 0, 1);
        DecompressAndLoadBgGfxUsingHeap(3, gUnknown_08D84F00, 0x800, 0, 1);
        LoadCompressedSpriteSheet(sDomeOptionsSpriteSheet);
        LoadCompressedPalette(gUnknown_08D85358, 0, 0x200);
        LoadCompressedPalette(gUnknown_08D85444, 0x100, 0x200);
        LoadCompressedPalette(gUnknown_08D85600, 0xF0, 0x20);
        if (r9 == 2)
            LoadCompressedPalette(gUnknown_08D854C8, 0x50, 0x20);
        CpuFill32(0, gPlttBufferFaded, 0x400);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        SetVBlankCallback(VblankCb0_BattleDome);
        sBattleDomeStruct = AllocZeroed(sizeof(*sBattleDomeStruct));
        for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            sBattleDomeStruct->arr[i] = 0xFF;
        LoadMonIconPalettes();
        i = CreateTask(sub_8190CD4, 0);
        gTasks[i].data[0] = 0;
        gTasks[i].data[2] = 0;
        gTasks[i].data[3] = r9;
        gTasks[i].data[4] = r7;
        if (r9 == 2)
        {
            DisplayMatchInfoOnCard(0, r5);
            sBattleDomeStruct->unk_10 = 1;
        }
        else
        {
            DisplayTrainerInfoOnCard(0, r5);
        }
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
        if (r9 != 0)
        {
            r7 = CreateSprite(&gUnknown_0860D068, 120, 4, 0);
            StartSpriteAnim(&gSprites[r7], 0);
            gSprites[r7].data[0] = i;

            r7 = CreateSprite(&gUnknown_0860D068, 120, 156, 0);
            StartSpriteAnim(&gSprites[r7], 1);
            gSprites[r7].data[0] = i;

            r7 = CreateSprite(&gUnknown_0860D050, 6, 80, 0);
            StartSpriteAnim(&gSprites[r7], 0);
            gSprites[r7].data[0] = i;
            gSprites[r7].data[1] = 0;
            if (r9 == 1)
                gSprites[r7].invisible = TRUE;

            r7 = CreateSprite(&gUnknown_0860D050, 234, 80, 0);
            StartSpriteAnim(&gSprites[r7], 1);
            gSprites[r7].data[0] = i;
            gSprites[r7].data[1] = 1;
        }
        DestroyTask(taskId);
        break;
    }
}

// Note: Card scrolling up means the current card goes down and another one appears from top.
// The same is true for scrolling left.
// That means that the sprite needs to move with the moving card in the opposite scrolling direction.

static void SpriteCb_TrainerIconCardScrollUp(struct Sprite *sprite)
{
    sprite->pos1.y += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y >= -32)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.y >= 192)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

static void SpriteCb_TrainerIconCardScrollDown(struct Sprite *sprite)
{
    sprite->pos1.y -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y <= 192)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.y <= -32)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

static void SpriteCb_TrainerIconCardScrollLeft(struct Sprite *sprite)
{
    sprite->pos1.x += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x >= -32)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.x >= 272)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

static void SpriteCb_TrainerIconCardScrollRight(struct Sprite *sprite)
{
    sprite->pos1.x -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x <= 272)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (sprite->pos1.x <= -32)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            FreeAndDestroyTrainerPicSprite(sprite->data[3]);
        }
    }
}

#define sMonIconStill data[3]

static void SpriteCb_MonIcon(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
}

static void SpriteCb_MonIconCardScrollUp(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->pos1.y += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y >= -16)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCb_MonIcon;
    }
    else
    {
        if (sprite->pos1.y >= 176)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

static void SpriteCb_MonIconCardScrollDown(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->pos1.y -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.y <= 176)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 40)
            sprite->callback = SpriteCb_MonIcon;
    }
    else
    {
        if (sprite->pos1.y <= -16)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

static void SpriteCb_MonIconCardScrollLeft(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->pos1.x += 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x >= -16)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCb_MonIcon;
    }
    else
    {
        if (sprite->pos1.x >= 256)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

static void SpriteCb_MonIconCardScrollRight(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
    sprite->pos1.x -= 4;
    if (sprite->data[0] != 0)
    {
        if (sprite->pos1.x <= 256)
            sprite->invisible = FALSE;
        if (++sprite->data[1] == 64)
            sprite->callback = SpriteCb_MonIcon;
    }
    else
    {
        if (sprite->pos1.x <= -16)
        {
            sBattleDomeStruct->arr[sprite->data[2]] = 0xFF;
            sub_80D2EF8(sprite);
        }
    }
}

static void sub_8190B40(struct Sprite *sprite)
{
    int taskId1 = sprite->data[0];
    int arrId = gTasks[gTasks[taskId1].data[4]].data[1];
    int tournmanetTrainerId = sTourneyTreeTrainerIds[arrId];
    int roundId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;

    if (gTasks[taskId1].data[3] == 1)
    {
        if (sprite->data[1])
        {
            if ((gSaveBlock2Ptr->frontier.domeTrainers[tournmanetTrainerId].isEliminated
                && sBattleDomeStruct->unk_10 - 1 < gSaveBlock2Ptr->frontier.domeTrainers[tournmanetTrainerId].eliminatedAt))
            {
                sprite->invisible = FALSE;
            }
            else if (!gSaveBlock2Ptr->frontier.domeTrainers[tournmanetTrainerId].isEliminated
                     && sBattleDomeStruct->unk_10 - 1 < roundId)
            {
                sprite->invisible = FALSE;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
        }
        else
        {
            if (sBattleDomeStruct->unk_10 != 0)
            {
                sprite->invisible = FALSE;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
        }
    }
    else
    {
        if (sprite->data[1])
        {
            if (sBattleDomeStruct->unk_10 > 1)
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
            else
            {
                sprite->invisible = FALSE;
            }
        }
        else
        {
            if (sBattleDomeStruct->unk_10 != 0)
            {
                sprite->invisible = FALSE;
            }
            else
            {
                if (gTasks[taskId1].data[0] == 2)
                    sprite->invisible = TRUE;
            }
        }
    }
}

static void sub_8190C6C(struct Sprite *sprite)
{
    int taskId1 = sprite->data[0];

    if (gTasks[taskId1].data[3] == 1)
    {
        if (sBattleDomeStruct->unk_10 != 0)
        {
            if (gTasks[taskId1].data[0] == 2)
                sprite->invisible = TRUE;
        }
        else
        {
            sprite->invisible = FALSE;
        }
    }
    else
    {
        if (sBattleDomeStruct->unk_10 != 1)
        {
            if (gTasks[taskId1].data[0] == 2)
                sprite->invisible = TRUE;
        }
        else
        {
            sprite->invisible = FALSE;
        }
    }
}

static void sub_8190CD4(u8 taskId)
{
    int i;
    int windowId = 0;
    int r9 = gTasks[taskId].data[3];
    int taskId2 = gTasks[taskId].data[4];
    int trainerTournamentId = 0;
    int matchNo = 0;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            gTasks[taskId].data[0] = 1;
        }
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        i = sub_819221C(taskId);
        switch (i)
        {
        case 9:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = 8;
            break;
        case 1 ... 8:
            gTasks[taskId].data[5] = i;
            if (gTasks[taskId].data[2] != 0)
                windowId = 9;
            else
                windowId = 0;

            for (i = windowId; i < windowId + 9; i++)
            {
                CopyWindowToVram(i, 2);
                FillWindowPixelBuffer(i, PIXEL_FILL(0));
            }
            gTasks[taskId].data[0] = 3;
            break;
        case 0:
            break;
        }
        break;
    case 3:
        i = gTasks[taskId].data[5];
        switch (i)
        {
        case 1:
        case 5:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 160;
            }
            else
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 160;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (i == 1)
            {
                if (sBattleDomeStruct->unk_10 == 0)
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 320;
                    trainerTournamentId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 0x10, trainerTournamentId);
                }
                else
                {
                    gBattle_BG2_X = 256;
                    gBattle_BG2_Y = 0;
                    trainerTournamentId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 0x10, trainerTournamentId);
                    sBattleDomeStruct->unk_10 = 0;
                }
            }
            else
            {
                if (sBattleDomeStruct->unk_10 == 0)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(matchNo, sBattleDomeStruct->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 320;
                    trainerTournamentId = sBattleDomeStruct->unk_11[0];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 0x10, trainerTournamentId);
                }
                else if (sBattleDomeStruct->unk_10 == 2)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(matchNo, sBattleDomeStruct->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 320;
                    trainerTournamentId = sBattleDomeStruct->unk_11[1];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 0x10, trainerTournamentId);
                }
                else
                {
                    gBattle_BG2_X = 256;
                    gBattle_BG2_Y = 160;
                    matchNo = gTasks[taskId2].data[1] - 16;
                    DisplayMatchInfoOnCard(gTasks[taskId].data[2] | 0x10, matchNo);
                }
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollUp;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollUp;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollUp;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollUp;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 4;
            gTasks[taskId].data[5] = 0;
            break;
        case 2:
        case 6:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = -160;
            }
            else
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = -160;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (i == 2)
            {
                if (sBattleDomeStruct->unk_10 == 0)
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 160;
                    trainerTournamentId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 4, trainerTournamentId);
                }
                else
                {
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 0;
                    trainerTournamentId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 4, trainerTournamentId);
                    sBattleDomeStruct->unk_10 = 0;
                }
            }
            else
            {
                if (sBattleDomeStruct->unk_10 == 0)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(matchNo, sBattleDomeStruct->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 160;
                    trainerTournamentId = sBattleDomeStruct->unk_11[0];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 4, trainerTournamentId);
                }
                else if (sBattleDomeStruct->unk_10 == 2)
                {
                    matchNo = gTasks[taskId2].data[1] - 16;
                    sub_8192F08(matchNo, sBattleDomeStruct->unk_11);
                    gBattle_BG2_X = 0;
                    gBattle_BG2_Y = 160;
                    trainerTournamentId = sBattleDomeStruct->unk_11[1];
                    DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 4, trainerTournamentId);
                }
                else
                {
                    gBattle_BG2_X = 256;
                    gBattle_BG2_Y = 0;
                    matchNo = gTasks[taskId2].data[1] - 16;
                    DisplayMatchInfoOnCard(gTasks[taskId].data[2] | 4, matchNo);
                }
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollDown;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollDown;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollDown;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollDown;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 5;
            gTasks[taskId].data[5] = 0;
            break;
        case 3:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = 256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sBattleDomeStruct->unk_10 == 0)
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 160;
                trainerTournamentId = sTourneyTreeTrainerIds[gTasks[taskId2].data[1]];
                DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 8, trainerTournamentId);
            }
            else
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 0;
                matchNo = gUnknown_0860D15C[gTasks[taskId2].data[1]][sBattleDomeStruct->unk_10 - 1];
                DisplayMatchInfoOnCard(gTasks[taskId].data[2] | 8, matchNo);
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 6;
            gTasks[taskId].data[5] = 0;
            break;
        case 7:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = 256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sBattleDomeStruct->unk_10 == 0)
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 160;
                trainerTournamentId = sBattleDomeStruct->unk_11[0];
                DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 8, trainerTournamentId);
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 160;
                matchNo = gTasks[taskId2].data[1] - 16;
                DisplayMatchInfoOnCard(gTasks[taskId].data[2] | 8, matchNo);
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollLeft;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 6;
            gTasks[taskId].data[5] = 0;
            break;
        case 4:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = -256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = -256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sBattleDomeStruct->unk_10 == 1)
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 160;
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 0;
            }
            matchNo = gUnknown_0860D15C[gTasks[taskId2].data[1]][sBattleDomeStruct->unk_10 - 1];
            DisplayMatchInfoOnCard(gTasks[taskId].data[2] | 2, matchNo);

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 7;
            gTasks[taskId].data[5] = 0;
            break;
        case 8:
            if (gTasks[taskId].data[2])
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = -256;
                gBattle_BG1_Y = 0;
            }
            else
            {
                gBattle_BG0_X = -256;
                gBattle_BG0_Y = 0;
                gBattle_BG1_X = 0;
                gBattle_BG1_Y = 0;
            }

            if (sBattleDomeStruct->unk_10 == 2)
            {
                gBattle_BG2_X = 256;
                gBattle_BG2_Y = 160;
                trainerTournamentId = sBattleDomeStruct->unk_11[1];
                DisplayTrainerInfoOnCard(gTasks[taskId].data[2] | 2, trainerTournamentId);
            }
            else
            {
                gBattle_BG2_X = 0;
                gBattle_BG2_Y = 160;
                matchNo = gTasks[taskId2].data[1] - 16;
                DisplayMatchInfoOnCard(gTasks[taskId].data[2] | 2, matchNo);
            }

            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2] ^ 1;
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_TrainerIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                        gSprites[sBattleDomeStruct->arr[i]].data[3] = sBattleDomeStruct->arr[i];
                    }
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                    {
                        gSprites[sBattleDomeStruct->arr[i]].callback = SpriteCb_MonIconCardScrollRight;
                        gSprites[sBattleDomeStruct->arr[i]].data[0] = gTasks[taskId].data[2];
                        gSprites[sBattleDomeStruct->arr[i]].data[1] = 0;
                        gSprites[sBattleDomeStruct->arr[i]].data[2] = i;
                    }
                }
            }

            gTasks[taskId].data[0] = 7;
            gTasks[taskId].data[5] = 0;
            break;
        }
        break;
    case 4:
        if (++gTasks[taskId].data[5] != 41)
        {
            gBattle_BG0_Y -= 4;
            gBattle_BG1_Y -= 4;
            gBattle_BG2_Y -= 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 5:
        if (++gTasks[taskId].data[5] != 41)
        {
            gBattle_BG0_Y += 4;
            gBattle_BG1_Y += 4;
            gBattle_BG2_Y += 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 6:
        if (++gTasks[taskId].data[5] != 65)
        {
            gBattle_BG0_X -= 4;
            gBattle_BG1_X -= 4;
            gBattle_BG2_X -= 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 7:
        if (++gTasks[taskId].data[5] != 65)
        {
            gBattle_BG0_X += 4;
            gBattle_BG1_X += 4;
            gBattle_BG2_X += 4;
        }
        else
        {
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 8:
        if (!gPaletteFade.active)
        {
            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT / 2; i++)
            {
                if (i < 2)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                        FreeAndDestroyTrainerPicSprite(sBattleDomeStruct->arr[i]);
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                        sub_80D2EF8(&gSprites[sBattleDomeStruct->arr[i]]);
                }
            }
            for (i = DOME_TOURNAMENT_TRAINERS_COUNT / 2; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                if (i < 10)
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                        FreeAndDestroyTrainerPicSprite(sBattleDomeStruct->arr[i]);
                }
                else
                {
                    if (sBattleDomeStruct->arr[i] != 0xFF)
                        sub_80D2EF8(&gSprites[sBattleDomeStruct->arr[i]]);
                }
            }

            FreeMonIconPalettes();
            FREE_AND_SET_NULL(sBattleDomeStruct);
            FreeAllWindowBuffers();
            if (r9 == 0)
            {
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            }
            else
            {
                i = CreateTask(Task_ShowTourneyTree, 0);
                gTasks[i].data[0] = 0;
                gTasks[i].data[1] = 0;
                gTasks[i].data[2] = 3;
                gTasks[i].data[3] = gTasks[taskId].data[4];
                gTasks[i].data[4] = gTasks[taskId2].data[6];
            }
            DestroyTask(taskId);
        }
        break;
    }
}

static u8 sub_819221C(u8 taskId)
{
    u8 retVal = 0;
    int taskId2 = gTasks[taskId].data[4];
    int r5 = gTasks[taskId2].data[1];
    u8 r10 = sTourneyTreeTrainerIds[r5];
    u16 roundId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        retVal = 9;

    if (gTasks[taskId].data[3] == 0)
        return retVal;

    if (gTasks[taskId].data[3] == 1)
    {
        if (gMain.newKeys & DPAD_UP && sBattleDomeStruct->unk_10 == 0)
        {
            if (r5 == 0)
                r5 = 15;
            else
                r5--;
            retVal = 1;
        }
        else if (gMain.newKeys & DPAD_DOWN && sBattleDomeStruct->unk_10 == 0)
        {
            if (r5 == 15)
                r5 = 0;
            else
                r5++;
            retVal = 2;
        }
        else if (gMain.newKeys & DPAD_LEFT && sBattleDomeStruct->unk_10 != 0)
        {
            sBattleDomeStruct->unk_10--;
            retVal = 3;
        }
        else if (gMain.newKeys & DPAD_RIGHT)
        {
            if (gSaveBlock2Ptr->frontier.domeTrainers[r10].isEliminated && sBattleDomeStruct->unk_10 - 1 < gSaveBlock2Ptr->frontier.domeTrainers[r10].eliminatedAt)
            {
                sBattleDomeStruct->unk_10++;
                retVal = 4;
            }
            if (!gSaveBlock2Ptr->frontier.domeTrainers[r10].isEliminated && sBattleDomeStruct->unk_10 - 1 < roundId)
            {
                sBattleDomeStruct->unk_10++;
                retVal = 4;
            }
        }

        if (retVal == 9)
        {
            if (sBattleDomeStruct->unk_10 != 0)
                gTasks[taskId2].data[1] = gUnknown_0860D1A0[r5 / 2][sBattleDomeStruct->unk_10 - 1];
            else
                gTasks[taskId2].data[1] = r5;
        }
    }
    else
    {
        if (gMain.newKeys & DPAD_UP && sBattleDomeStruct->unk_10 == 1)
        {
            if (r5 == 16)
                r5 = gUnknown_0860D19C[roundId];
            else
                r5--;
            retVal = 5;
        }
        else if (gMain.newKeys & DPAD_DOWN && sBattleDomeStruct->unk_10 == 1)
        {
            if (r5 == gUnknown_0860D19C[roundId])
                r5 = 16;
            else
                r5++;
            retVal = 6;
        }
        else if (gMain.newKeys & DPAD_LEFT && sBattleDomeStruct->unk_10 != 0)
        {
            retVal = 7;
            sBattleDomeStruct->unk_10--;
        }
        else if (gMain.newKeys & DPAD_RIGHT && (sBattleDomeStruct->unk_10 == 0 || sBattleDomeStruct->unk_10 == 1))
        {
            retVal = 8;
            sBattleDomeStruct->unk_10++;
        }

        if (retVal == 9)
        {
            if (sBattleDomeStruct->unk_10 == 0)
                gTasks[taskId2].data[1] = gUnknown_0860D1C0[sBattleDomeStruct->unk_11[0]];
            else if (sBattleDomeStruct->unk_10 == 2)
                gTasks[taskId2].data[1] = gUnknown_0860D1C0[sBattleDomeStruct->unk_11[1]];
            else
                gTasks[taskId2].data[1] = r5;
        }
    }

    if (retVal != 0 && retVal != 9)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId2].data[1] = r5;
        gTasks[taskId].data[2] ^= 1;
    }

    return retVal;
}

static void DisplayTrainerInfoOnCard(u8 flags, u8 trainerTournamentId)
{
    struct TextPrinterTemplate textPrinter;
    int i, j, k;
    int trainerId = 0;
    u8 nature = 0;
    int arrId = 0;
    int windowId = 0;
    int x = 0, y = 0;
    u8 palSlot = 0;
    s16 *allocatedArray = AllocZeroed(sizeof(s16) * 18);
    trainerId = gSaveBlock2Ptr->frontier.domeTrainers[trainerTournamentId].trainerId;

    if (flags & 1)
        arrId = 8, windowId = 9, palSlot = 2;
    if (flags & 2)
        x = 256;
    if (flags & 4)
        y = 160;
    if (flags & 8)
        x = -256;
    if (flags & 0x10)
        y = -160;

    if (trainerId == TRAINER_PLAYER)
        sBattleDomeStruct->arr[arrId] = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), TRUE, x + 48, y + 64, palSlot + 12, 0xFFFF);
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        sBattleDomeStruct->arr[arrId] = CreateTrainerPicSprite(GetDomeBrainTrainerPicId(), TRUE, x + 48, y + 64, palSlot + 12, 0xFFFF);
    else
        sBattleDomeStruct->arr[arrId] = CreateTrainerPicSprite(GetFrontierTrainerFrontSpriteId(trainerId), TRUE, x + 48, y + 64, palSlot + 12, 0xFFFF);

    if (flags & 0x1E)
        gSprites[sBattleDomeStruct->arr[arrId]].invisible = TRUE;

    for (i = 0; i < 3; i++)
    {
        if (trainerId == TRAINER_PLAYER)
        {
            sBattleDomeStruct->arr[2 + i + arrId] = CreateMonIcon(gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i],
                                                                  SpriteCb_MonIcon,
                                                                  x | sInfoTrainerMonX[i],
                                                                  y + sInfoTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].oam.priority = 0;
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            sBattleDomeStruct->arr[2 + i + arrId] = CreateMonIcon(gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i],
                                                                  SpriteCb_MonIcon,
                                                                  x | sInfoTrainerMonX[i],
                                                                  y + sInfoTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].oam.priority = 0;
        }
        else
        {
            sBattleDomeStruct->arr[2 + i + arrId] = CreateMonIcon(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]].species,
                                                                  SpriteCb_MonIcon,
                                                                  x | sInfoTrainerMonX[i],
                                                                  y + sInfoTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].oam.priority = 0;
        }

        if (flags & 0x1E)
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].invisible = TRUE;
    }
    textPrinter.fontId = 2;
    textPrinter.x = 0;
    textPrinter.y = 0;
    textPrinter.currentX = textPrinter.x;
    textPrinter.currentY = textPrinter.y;
    textPrinter.letterSpacing = 2;
    textPrinter.lineSpacing = 0;
    textPrinter.unk = 0;
    textPrinter.fgColor = 14;
    textPrinter.bgColor = 0;
    textPrinter.shadowColor = 13;

    i = 0;
    if (trainerId == TRAINER_PLAYER)
        j = gFacilityClassToTrainerClass[FACILITY_CLASS_BRENDAN];
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        j = GetDomeBrainTrainerClass();
    else
        j = GetFrontierOpponentClass(trainerId);

    for (;gTrainerClassNames[j][i] != EOS; i++)
        gStringVar1[i] = gTrainerClassNames[j][i];
    gStringVar1[i] = CHAR_SPACE;
    gStringVar1[i + 1] = EOS;

    if (trainerId == TRAINER_PLAYER)
    {
        StringAppend(gStringVar1, gSaveBlock2Ptr->playerName);
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyDomeBrainTrainerName(gStringVar2);
        StringAppend(gStringVar1, gStringVar2);
    }
    else
    {
        CopyDomeTrainerName(gStringVar2, trainerId);
        StringAppend(gStringVar1, gStringVar2);
    }

    textPrinter.currentX = GetStringCenterAlignXOffsetWithLetterSpacing(textPrinter.fontId, gStringVar1, 0xD0, textPrinter.letterSpacing);
    textPrinter.currentChar = gStringVar1;
    textPrinter.windowId = windowId;
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
    AddTextPrinter(&textPrinter, 0, NULL);
    textPrinter.letterSpacing = 0;

    for (i = 0; i < 3; i++)
    {
        textPrinter.currentY = gUnknown_0860D346[i];
        if (trainerId == TRAINER_PLAYER)
            textPrinter.currentChar = gSpeciesNames[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]];
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
            textPrinter.currentChar = gSpeciesNames[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]];
        else
            textPrinter.currentChar = gSpeciesNames[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]].species];

        textPrinter.windowId = 1 + i + windowId;
        if (i == 1)
            textPrinter.currentX = 7;
        else
            textPrinter.currentX = 0;

        PutWindowTilemap(1 + i + windowId);
        CopyWindowToVram(1 + i + windowId, 3);
        AddTextPrinter(&textPrinter, 0, NULL);
    }

    PutWindowTilemap(windowId + 4);
    CopyWindowToVram(windowId + 4, 3);
    if (trainerId == TRAINER_FRONTIER_BRAIN)
        textPrinter.currentChar = sBattleDomePotentialTexts[16];
    else
        textPrinter.currentChar = sBattleDomePotentialTexts[trainerTournamentId];

    textPrinter.fontId = 1;
    textPrinter.windowId = windowId + 4;
    textPrinter.currentX = 0;
    textPrinter.y = 4;
    textPrinter.currentY = 4;
    AddTextPrinter(&textPrinter, 0, NULL);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            for (k = 0; k < DOME_TOURNAMENT_TRAINERS_COUNT; k++)
            {
                if (trainerId == TRAINER_FRONTIER_BRAIN)
                    allocatedArray[k] += sMovePointsForDomeTrainers[GetFrontierBrainMonMove(i, j)][k];
                else if (trainerId == TRAINER_PLAYER)
                    allocatedArray[k] += sMovePointsForDomeTrainers[gSaveBlock2Ptr->frontier.field_EFC[i].moves[j]][k];
                else
                    allocatedArray[k] += sMovePointsForDomeTrainers[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]].moves[j]][k];
            }
        }
    }

    for (i = 0; i < ARRAY_COUNT(gUnknown_0860C988); i++)
    {
        int r4 = 0;

        for (k = 0, j = 0; j < DOME_TOURNAMENT_TRAINERS_COUNT; j++)
        {
            if (gUnknown_0860C988[i][j] != 0)
            {
                r4++;
                if (allocatedArray[j] != 0 && allocatedArray[j] >= gUnknown_0860C988[i][j])
                    k++;
            }
        }
        if (r4 == k)
            break;
    }

    textPrinter.currentChar = sBattleDomeOpponentStyleTexts[i];
    textPrinter.y = 20;
    textPrinter.currentY = 20;
    AddTextPrinter(&textPrinter, 0, NULL);

    for (i = 0; i < 18; i++)
        allocatedArray[i] = 0;

    if (trainerId == TRAINER_FRONTIER_BRAIN || trainerId == TRAINER_PLAYER)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (trainerId == TRAINER_FRONTIER_BRAIN)
                    allocatedArray[j] = GetFrontierBrainMonEvs(i, j);
                else
                    allocatedArray[j] = gSaveBlock2Ptr->frontier.field_EFC[i].evs[j];
            }
            allocatedArray[6] += allocatedArray[0];
            for (j = 0; j < 5; j++)
            {
                if (trainerId == TRAINER_FRONTIER_BRAIN)
                    nature = GetFrontierBrainMonNature(i);
                else
                    nature = gSaveBlock2Ptr->frontier.field_EFC[i].nature;

                if (gNatureStatTable[nature][j] > 0)
                {
                    allocatedArray[j + 7] += (allocatedArray[j + 1] * 110) / 100;
                }
                else if (gNatureStatTable[nature][j] < 0)
                {
                    allocatedArray[j + 7] += (allocatedArray[j + 1] * 90) / 100;
                    allocatedArray[j + 13]++;
                }
                else
                {
                    allocatedArray[j + 7] += allocatedArray[j + 1];
                }
            }
        }
        for (j = 0, i = 0; i < 6; i++)
            j += allocatedArray[6 + i];
        for (i = 0; i < 6; i++)
            allocatedArray[i] = (allocatedArray[6 + i] * 100) / j;
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            int evBits = gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]].evSpread;
            for (k = 0, j = 0; j < NUM_STATS; j++)
            {
                allocatedArray[j] = 0;
                if (evBits & 1)
                    k++;
                evBits >>= 1;
            }
            k = MAX_TOTAL_EVS / k;
            evBits = gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]].evSpread;
            for (j = 0; j < NUM_STATS; j++)
            {
                if (evBits & 1)
                    allocatedArray[j] = k;
                evBits >>= 1;
            }

            allocatedArray[6] += allocatedArray[0];
            for (j = 0; j < 5; j++)
            {
                nature = gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[trainerTournamentId][i]].nature;
                if (gNatureStatTable[nature][j] > 0)
                {
                    allocatedArray[j + 7] += (allocatedArray[j + 1] * 110) / 100;
                }
                else if (gNatureStatTable[nature][j] < 0)
                {
                    allocatedArray[j + 7] += (allocatedArray[j + 1] * 90) / 100;
                    allocatedArray[j + 13]++;
                }
                else
                {
                    allocatedArray[j + 7] += allocatedArray[j + 1];
                }
            }
        }
        for (j = 0, i = 0; i < 6; i++)
            j += allocatedArray[i + 6];
        for (i = 0; i < 6; i++)
            allocatedArray[i] = (allocatedArray[6 + i] * 100) / j;
    }

    for (i = 0, j = 0, k = 0; k < 6; k++)
    {
        if (allocatedArray[k] > 29)
        {
            if (i == 2)
            {
                if (allocatedArray[6] < allocatedArray[k])
                {
                    if (allocatedArray[7] < allocatedArray[k])
                    {
                        if (allocatedArray[6] < allocatedArray[7])
                        {
                            allocatedArray[6] = allocatedArray[7];
                            allocatedArray[7] = k;
                        }
                        else
                        {
                            allocatedArray[7] = k;
                        }
                    }
                    else
                    {
                        allocatedArray[6] = allocatedArray[7];
                        allocatedArray[7] = k;
                    }
                }
                else
                {
                    if (allocatedArray[7] < allocatedArray[k])
                        allocatedArray[7] = k;
                }
            }
            else
            {
                allocatedArray[i + 6] = k;
                i++;
            }
        }
        if (allocatedArray[k] == 0)
        {
            if (j == 2)
            {
                if (allocatedArray[k + 12] >= 2
                    || ((allocatedArray[k + 12] == 1 && allocatedArray[12 + allocatedArray[8]] == 0 && allocatedArray[12 + allocatedArray[9]] == 0)
                       )
                    )
                {
                    allocatedArray[8] = allocatedArray[9];
                    allocatedArray[9] = k;
                }
                else if (allocatedArray[k + 12] == 1 && allocatedArray[12 + allocatedArray[8]] == 0)
                {
                    allocatedArray[8] = allocatedArray[9];
                    allocatedArray[9] = k;
                }
                else if (allocatedArray[k + 12] == 1 && allocatedArray[12 + allocatedArray[9]] == 0)
                {
                    allocatedArray[9] = k;
                }
            }
            else
            {
                allocatedArray[j + 8] = k;
                j++;
            }
        }
    }

    if (i == 2)
        i = gUnknown_0860D349[allocatedArray[6]] + (allocatedArray[7] - (allocatedArray[6] + 1));
    else if (i == 1)
        i = allocatedArray[6] + 15;
    else if (j == 2)
        i = gUnknown_0860D349[allocatedArray[8]] + (allocatedArray[9] - (allocatedArray[8] + 1)) + 21;
    else if (j == 1)
        i = allocatedArray[8] + 36;
    else
        i = 42;

    textPrinter.currentChar = sBattleDomeOpponentStatsTexts[i];
    textPrinter.y = 36;
    textPrinter.currentY = 36;
    AddTextPrinter(&textPrinter, 0, NULL);
    Free(allocatedArray);
}

static int sub_8192F08(u8 arg0, u8 *arg1)
{
    int i;
    u8 tournamentId;
    int retVal = 0;
    int count = 0;

    for (i = gUnknown_0860D3C4[arg0][0]; i < gUnknown_0860D3C4[arg0][0] + gUnknown_0860D3C4[arg0][1]; i++)
    {
        tournamentId = gUnknown_0860D3B4[i];
        if (!gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].isEliminated)
        {
            arg1[count] = tournamentId;
            if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].trainerId == TRAINER_PLAYER)
                StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
            else if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].trainerId == TRAINER_FRONTIER_BRAIN)
                CopyDomeBrainTrainerName(gStringVar1);
            else
                CopyDomeTrainerName(gStringVar1, gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].trainerId);
            count++;
        }
    }

    if (count == 2)
        return 0;

    for (i = gUnknown_0860D3C4[arg0][0]; i < gUnknown_0860D3C4[arg0][0] + gUnknown_0860D3C4[arg0][1]; i++)
    {
        tournamentId = gUnknown_0860D3B4[i];
        if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].isEliminated
            && gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].eliminatedAt >= gUnknown_0860D3C4[arg0][2])
        {
            arg1[count] = tournamentId;
            count++;
            if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].eliminatedAt == gUnknown_0860D3C4[arg0][2])
            {
                StringCopy(gStringVar2, gMoveNames[gSaveBlock2Ptr->frontier.field_EC0[tournamentId]]);
                retVal = gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].unk3 * 2;
                if (gSaveBlock2Ptr->frontier.field_EC0[tournamentId] == 0 && gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].unk3 == 0)
                    retVal = 4;
            }
            else
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].trainerId == TRAINER_PLAYER)
                    StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
                else if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].trainerId == TRAINER_FRONTIER_BRAIN)
                    CopyDomeBrainTrainerName(gStringVar1);
                else
                    CopyDomeTrainerName(gStringVar1, gSaveBlock2Ptr->frontier.domeTrainers[tournamentId].trainerId);
            }
        }

        if (count == 2)
            break;
    }

    if (arg0 == 14)
        return retVal + 2;
    else
        return retVal + 1;
}

static void DisplayMatchInfoOnCard(u8 flags, u8 matchNo)
{
    struct TextPrinterTemplate textPrinter;
    int tournamentIds[2];
    int trainerIds[2];
    bool32 lost[2];
    int i;
    int winStringId = 0;
    int arrId = 0;
    int windowId = 0;
    int x = 0, y = 0;
    u8 palSlot = 0;

    if (flags & 1)
        arrId = 8, windowId = 9, palSlot = 2;
    if (flags & 2)
        x = 256;
    if (flags & 4)
        y = 160;
    if (flags & 8)
        x = -256;
    if (flags & 0x10)
        y = -160;

    // Copy trainers information to handy arrays.
    winStringId = sub_8192F08(matchNo, sBattleDomeStruct->unk_11);
    for (i = 0; i < 2; i++)
    {
        tournamentIds[i] = sBattleDomeStruct->unk_11[i];
        trainerIds[i] = gSaveBlock2Ptr->frontier.domeTrainers[tournamentIds[i]].trainerId;
        if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentIds[i]].eliminatedAt <= gUnknown_0860D3C4[matchNo][2]
            && gSaveBlock2Ptr->frontier.domeTrainers[tournamentIds[i]].isEliminated)
            lost[i] = TRUE;
        else
            lost[i] = FALSE;
    }

    // Draw first trainer sprite.
    if (trainerIds[0] == TRAINER_PLAYER)
        sBattleDomeStruct->arr[arrId] = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), TRUE, x + 48, y + 88, palSlot + 12, 0xFFFF);
    else if (trainerIds[0] == TRAINER_FRONTIER_BRAIN)
        sBattleDomeStruct->arr[arrId] = CreateTrainerPicSprite(GetDomeBrainTrainerPicId(), TRUE, x + 48, y + 88, palSlot + 12, 0xFFFF);
    else
        sBattleDomeStruct->arr[arrId] = CreateTrainerPicSprite(GetFrontierTrainerFrontSpriteId(trainerIds[0]), TRUE, x + 48, y + 88, palSlot + 12, 0xFFFF);

    if (flags & 0x1E)
        gSprites[sBattleDomeStruct->arr[arrId]].invisible = TRUE;
    if (lost[0])
        gSprites[sBattleDomeStruct->arr[arrId]].oam.paletteNum = 3;

    // Draw second trainer sprite.
    if (trainerIds[1] == TRAINER_PLAYER)
        sBattleDomeStruct->arr[1 + arrId] = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), TRUE, x + 192, y + 88, palSlot + 13, 0xFFFF);
    else if (trainerIds[1] == TRAINER_FRONTIER_BRAIN)
        sBattleDomeStruct->arr[1 + arrId] = CreateTrainerPicSprite(GetDomeBrainTrainerPicId(), TRUE, x + 192, y + 88, palSlot + 13, 0xFFFF);
    else
        sBattleDomeStruct->arr[1 + arrId] = CreateTrainerPicSprite(GetFrontierTrainerFrontSpriteId(trainerIds[1]), TRUE, x + 192, y + 88, palSlot + 13, 0xFFFF);

    if (flags & 0x1E)
        gSprites[sBattleDomeStruct->arr[1 + arrId]].invisible = TRUE;
    if (lost[1])
        gSprites[sBattleDomeStruct->arr[1 + arrId]].oam.paletteNum = 3;

    // Draw first trainer's pokemon icons.
    for (i = 0; i < 3; i++)
    {
        if (trainerIds[0] == TRAINER_PLAYER)
        {
            sBattleDomeStruct->arr[2 + i + arrId] = CreateMonIcon(gSaveBlock2Ptr->frontier.domeMonIds[tournamentIds[0]][i],
                                                                  SpriteCb_MonIcon,
                                                                  x | sFirstTrainerMonX[i],
                                                                  y + sFirstTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].oam.priority = 0;
        }
        else if (trainerIds[0] == TRAINER_FRONTIER_BRAIN)
        {
            sBattleDomeStruct->arr[2 + i + arrId] = CreateMonIcon(gSaveBlock2Ptr->frontier.domeMonIds[tournamentIds[0]][i],
                                                                  SpriteCb_MonIcon,
                                                                  x | sFirstTrainerMonX[i],
                                                                  y + sFirstTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].oam.priority = 0;
        }
        else
        {
            sBattleDomeStruct->arr[2 + i + arrId] = CreateMonIcon(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentIds[0]][i]].species,
                                                                  SpriteCb_MonIcon,
                                                                  x | sFirstTrainerMonX[i],
                                                                  y + sFirstTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].oam.priority = 0;
        }

        if (flags & 0x1E)
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].invisible = TRUE;
        if (lost[0])
        {
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].oam.paletteNum = 3;
            gSprites[sBattleDomeStruct->arr[2 + i + arrId]].sMonIconStill = TRUE;
        }
    }

    // Draw second trainer's pokemon icons.
    for (i = 0; i < 3; i++)
    {
        if (trainerIds[1] == TRAINER_PLAYER)
        {
            sBattleDomeStruct->arr[5 + i + arrId] = CreateMonIcon(gSaveBlock2Ptr->frontier.domeMonIds[tournamentIds[1]][i],
                                                                  SpriteCb_MonIcon,
                                                                  x | sSecondTrainerMonX[i],
                                                                  y + sSecondTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[5 + i + arrId]].oam.priority = 0;
        }
        else if (trainerIds[1] == TRAINER_FRONTIER_BRAIN)
        {
            sBattleDomeStruct->arr[5 + i + arrId] = CreateMonIcon(gSaveBlock2Ptr->frontier.domeMonIds[tournamentIds[1]][i],
                                                                  SpriteCb_MonIcon,
                                                                  x | sSecondTrainerMonX[i],
                                                                  y + sSecondTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[5 + i + arrId]].oam.priority = 0;
        }
        else
        {
            sBattleDomeStruct->arr[5 + i + arrId] = CreateMonIcon(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentIds[1]][i]].species,
                                                                  SpriteCb_MonIcon,
                                                                  x | sSecondTrainerMonX[i],
                                                                  y + sSecondTrainerMonY[i],
                                                                  0, 0, TRUE);
            gSprites[sBattleDomeStruct->arr[5 + i + arrId]].oam.priority = 0;
        }

        if (flags & 0x1E)
            gSprites[sBattleDomeStruct->arr[5 + i + arrId]].invisible = TRUE;
        if (lost[1])
        {
            gSprites[sBattleDomeStruct->arr[5 + i + arrId]].oam.paletteNum = 3;
            gSprites[sBattleDomeStruct->arr[5 + i + arrId]].sMonIconStill = TRUE;
        }
    }

    // Print the win string (or 'Let the battle begin!' one).
    textPrinter.x = 0;
    textPrinter.y = 2;
    textPrinter.currentX = textPrinter.x;
    textPrinter.currentY = textPrinter.y;
    textPrinter.letterSpacing = 0;
    textPrinter.lineSpacing = 0;
    textPrinter.unk = 0;
    textPrinter.fgColor = 14;
    textPrinter.bgColor = 0;
    textPrinter.shadowColor = 13;
    StringExpandPlaceholders(gStringVar4, sBattleDomeWinTexts[winStringId]);
    textPrinter.currentChar = gStringVar4;
    textPrinter.windowId = windowId + 8;
    textPrinter.fontId = 1;
    PutWindowTilemap(windowId + 8);
    CopyWindowToVram(windowId + 8, 3);
    textPrinter.currentX = 0;
    textPrinter.currentY = textPrinter.y = 0;
    AddTextPrinter(&textPrinter, 0, NULL);

    // Print first trainer's name.
    if (trainerIds[0] == TRAINER_PLAYER)
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    else if (trainerIds[0] == TRAINER_FRONTIER_BRAIN)
        CopyDomeBrainTrainerName(gStringVar1);
    else
        CopyDomeTrainerName(gStringVar1, trainerIds[0]);

    textPrinter.fontId = 2;
    textPrinter.letterSpacing = 2;
    textPrinter.currentChar = gStringVar1;
    textPrinter.windowId = windowId + 6;
    textPrinter.currentX = GetStringCenterAlignXOffsetWithLetterSpacing(textPrinter.fontId, textPrinter.currentChar, 0x40, textPrinter.letterSpacing);
    textPrinter.currentY = textPrinter.y = 2;
    PutWindowTilemap(windowId + 6);
    CopyWindowToVram(windowId + 6, 3);
    AddTextPrinter(&textPrinter, 0, NULL);

    // Print second trainer's name.
    if (trainerIds[1] == TRAINER_PLAYER)
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    else if (trainerIds[1] == TRAINER_FRONTIER_BRAIN)
        CopyDomeBrainTrainerName(gStringVar1);
    else
        CopyDomeTrainerName(gStringVar1, trainerIds[1]);

    textPrinter.currentChar = gStringVar1;
    textPrinter.windowId = windowId + 7;
    textPrinter.currentX = GetStringCenterAlignXOffsetWithLetterSpacing(textPrinter.fontId, textPrinter.currentChar, 0x40, textPrinter.letterSpacing);
    textPrinter.currentY = textPrinter.y = 2;
    PutWindowTilemap(windowId + 7);
    CopyWindowToVram(windowId + 7, 3);
    AddTextPrinter(&textPrinter, 0, NULL);

    // Print match number.
    textPrinter.letterSpacing = 0;
    textPrinter.currentChar = sBattleDomeMatchNumberTexts[matchNo];
    textPrinter.windowId = windowId + 5;
    textPrinter.currentX = GetStringCenterAlignXOffsetWithLetterSpacing(textPrinter.fontId, textPrinter.currentChar, 0xA0, textPrinter.letterSpacing);
    textPrinter.currentY = textPrinter.y = 2;
    PutWindowTilemap(windowId + 5);
    CopyWindowToVram(windowId + 5, 3);
    AddTextPrinter(&textPrinter, 0, NULL);
}

static void ShowDomeTourneyTree(void)
{
    u8 taskId = CreateTask(Task_ShowTourneyTree, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 2;
    gTasks[taskId].data[4] = 0;
    SetMainCallback2(CB2_BattleDome);
}

static void ShowPreviousDomeResultsTourneyTree(void)
{
    u8 taskId;

    InitDomeFacilityTrainersAndMons();
    gSaveBlock2Ptr->frontier.lvlMode = gSaveBlock2Ptr->frontier.field_D0A - 1;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 3;
    taskId = CreateTask(Task_ShowTourneyTree, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 2;
    gTasks[taskId].data[4] = 1;
    SetMainCallback2(CB2_BattleDome);
}

static void sub_819395C(u8 taskId)
{
    u8 newTaskId = 0;
    int spriteId = gTasks[taskId].data[1];

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            gTasks[taskId].data[0] = 1;
            StartSpriteAnim(&gSprites[spriteId], 1);
        }
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        switch (UpdateTourneyTreeCursor(taskId))
        {
        case 0:
        default:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = 7;
            break;
        case 1:
            break;
        case 2:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = 3;
            break;
        case 3:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = 5;
            break;
        }
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            ScanlineEffect_Stop();
            FREE_AND_SET_NULL(sTilemapBuffer);
            newTaskId = CreateTask(Task_ShowOpponentInfo, 0);
            gTasks[newTaskId].data[0] = 0;
            gTasks[newTaskId].data[1] = sTourneyTreeTrainerIds[spriteId];
            gTasks[newTaskId].data[2] = 1;
            gTasks[newTaskId].data[3] = taskId;

            gTasks[taskId].data[0] = 4;
            sBattleDomeStruct->unk_10 = 0;
        }
        break;
    case 4:
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            ScanlineEffect_Stop();
            FREE_AND_SET_NULL(sTilemapBuffer);
            newTaskId = CreateTask(Task_ShowOpponentInfo, 0);
            gTasks[newTaskId].data[0] = 0;
            gTasks[newTaskId].data[1] = spriteId - 16;
            gTasks[newTaskId].data[2] = 2;
            gTasks[newTaskId].data[3] = taskId;

            gTasks[taskId].data[0] = 6;
        }
        break;
    case 6:
        break;
    case 7:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            ScanlineEffect_Stop();
            FREE_AND_SET_NULL(sTilemapBuffer);
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            DestroyTask(gTasks[taskId].data[7]);
            DestroyTask(taskId);
        }
        break;
    }
}

static u8 UpdateTourneyTreeCursor(u8 taskId)
{
    u8 retVal = 1;
    int direction = 4;
    int tourneyTreeCursorSpriteId = gTasks[taskId].data[1];
    int roundId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;

    if (gMain.newKeys == B_BUTTON || (gMain.newKeys & A_BUTTON && tourneyTreeCursorSpriteId == 31))
    {
        PlaySE(SE_SELECT);
        retVal = 0;
    }
    else if (gMain.newKeys & A_BUTTON)
    {
        if (tourneyTreeCursorSpriteId < 16)
        {
            PlaySE(SE_SELECT);
            retVal = 2;
        }
        else
        {
            PlaySE(SE_SELECT);
            retVal = 3;
        }
    }
    else
    {
        if (gMain.newKeys == DPAD_UP && sTourneyTreeCursorMovementMap[tourneyTreeCursorSpriteId][roundId][0] != 0xFF)
            direction = 0;
        else if (gMain.newKeys == DPAD_DOWN && sTourneyTreeCursorMovementMap[tourneyTreeCursorSpriteId][roundId][1] != 0xFF)
            direction = 1;
        else if (gMain.newKeys == DPAD_LEFT && sTourneyTreeCursorMovementMap[tourneyTreeCursorSpriteId][roundId][2] != 0xFF)
            direction = 2;
        else if (gMain.newKeys == DPAD_RIGHT && sTourneyTreeCursorMovementMap[tourneyTreeCursorSpriteId][roundId][3] != 0xFF)
            direction = 3;
    }

    if (direction != 4)
    {
        PlaySE(SE_SELECT);
        StartSpriteAnim(&gSprites[tourneyTreeCursorSpriteId], 0);
        tourneyTreeCursorSpriteId = sTourneyTreeCursorMovementMap[tourneyTreeCursorSpriteId][roundId][direction];
        StartSpriteAnim(&gSprites[tourneyTreeCursorSpriteId], 1);
        gTasks[taskId].data[1] = tourneyTreeCursorSpriteId;
    }

    return retVal;
}

static void ShowNonInteractiveDomeTourneyTree(void)
{
    u8 taskId = CreateTask(Task_ShowTourneyTree, 0);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 1;
    gTasks[taskId].data[2] = 2;
    gTasks[taskId].data[4] = 0;
    SetMainCallback2(CB2_BattleDome);
}

static void ResolveDomeRoundWinners(void)
{
    int i;

    if (gSpecialVar_0x8005 == 1)
    {
        gSaveBlock2Ptr->frontier.domeTrainers[TrainerIdToTournamentId(gTrainerBattleOpponent_A)].isEliminated = 1;
        gSaveBlock2Ptr->frontier.domeTrainers[TrainerIdToTournamentId(gTrainerBattleOpponent_A)].eliminatedAt = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
        gSaveBlock2Ptr->frontier.field_EC0[TrainerIdToTournamentId(gTrainerBattleOpponent_A)] = gBattleResults.lastUsedMovePlayer;
        if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < DOME_FINAL)
            DecideRoundWinners(gSaveBlock2Ptr->frontier.curChallengeBattleNum);
    }
    else
    {
        gSaveBlock2Ptr->frontier.domeTrainers[TrainerIdToTournamentId(TRAINER_PLAYER)].isEliminated = 1;
        gSaveBlock2Ptr->frontier.domeTrainers[TrainerIdToTournamentId(TRAINER_PLAYER)].eliminatedAt = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
        gSaveBlock2Ptr->frontier.field_EC0[TrainerIdToTournamentId(TRAINER_PLAYER)] = gBattleResults.lastUsedMoveOpponent;
        if (gBattleOutcome == B_OUTCOME_FORFEITED || gSpecialVar_0x8005 == 9)
            gSaveBlock2Ptr->frontier.domeTrainers[TrainerIdToTournamentId(TRAINER_PLAYER)].unk3 = 1;
        for (i = gSaveBlock2Ptr->frontier.curChallengeBattleNum; i < DOME_ROUNDS_COUNT; i++)
            DecideRoundWinners(i);
    }
}

static u16 GetWinningMove(int winnerTournamentId, int loserTournamentId, u8 roundId)
{
    int i, j, k;
    int moveScores[4 * 3];
    u16 moveIds[4 * 3];
    u16 bestScore = 0;
    u16 bestId = 0;
    int movePower = 0;
    SetFacilityPtrsGetLevel();

    // Calc move points of all 4 moves for all 3 pokemon hitting all 3 target mons.
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            // TODO: Clean this up, looks like a different data structure
            moveScores[i * 4 + j] = 0;
            if (gSaveBlock2Ptr->frontier.domeTrainers[winnerTournamentId].trainerId == TRAINER_FRONTIER_BRAIN)
                moveIds[i * 4 + j] = GetFrontierBrainMonMove(i, j);
            else
                moveIds[i * 4 + j] = gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[winnerTournamentId][i]].moves[j];

            movePower = gBattleMoves[moveIds[i * 4 + j]].power;
            if (movePower == 0)
                movePower = 40;
            else if (movePower == 1)
                movePower = 60;
            else if (moveIds[i * 4 + j] == MOVE_SELF_DESTRUCT || moveIds[i * 4 + j] == MOVE_EXPLOSION)
                movePower /= 2;

            for (k = 0; k < 3; k++)
            {
                u32 personality = 0;
                u32 targetSpecies = 0;
                u32 targetAbility = 0;
                u32 typeMultiplier = 0;
                do
                {
                    personality = Random32();
                } while (gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[loserTournamentId][k]].nature != GetNatureFromPersonality(personality));

                targetSpecies = gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[loserTournamentId][k]].species;
                if (personality & 1)
                    targetAbility = gBaseStats[targetSpecies].ability2;
                else
                    targetAbility = gBaseStats[targetSpecies].ability1;

                typeMultiplier = CalcPartyMonTypeEffectivenessMultiplier(moveIds[i * 4 + j], targetSpecies, targetAbility);
                if (typeMultiplier == UQ_4_12(0))
                    moveScores[i * 4 + j] += 0;
                else if (typeMultiplier >= UQ_4_12(2))
                    moveScores[i * 4 + j] += movePower * 2;
                else if (typeMultiplier <= UQ_4_12(0.5))
                    moveScores[i * 4 + j] += movePower / 2;
                else
                    moveScores[i * 4 + j] += movePower;
            }

            if (bestScore < moveScores[i * 4 + j])
            {
                bestId = i * 4 + j;
                bestScore = moveScores[i * 4 + j];
            }
            else if (bestScore == moveScores[i * 4 + j])
            {
                if (moveIds[bestId] < moveIds[i * 4 + j]) // Why not use (Random() & 1) instead of promoting moves with a higher id?
                    bestId = i * 4 + j;
            }
        }
    }

    j = bestId;
    goto LABEL;
    while (j != 0)
    {
        for (j = 0, k = 0; k < MAX_MON_MOVES * 3; k++)
        {
            if (bestScore < moveScores[k])
            {
                j = k;
                bestScore = moveScores[k];
            }
            else if (bestScore == moveScores[k] && moveIds[j] < moveIds[k])
            {
                j = k;
            }
        }
        if (i == roundId - 1)
            break;
        LABEL:
        {
            for (i = 0; i < roundId - 1; i++)
            {
                if (gSaveBlock2Ptr->frontier.field_EC0[sub_81953E8(winnerTournamentId, i)] == moveIds[j])
                    break;
            }
            if (i == roundId - 1)
                break;

            moveScores[j] = 0;
            bestScore = 0;
            j = 0;
            for (k = 0; k < MAX_MON_MOVES * 3; k++)
                j += moveScores[k];
        }
    }

    if (moveScores[j] == 0)
        j = bestId;

    return moveIds[j];
}

static void Task_ShowTourneyTree(u8 taskId)
{
    int i;
    struct TextPrinterTemplate textPrinter;
    int r10 = gTasks[taskId].data[1];
    int r4 = gTasks[taskId].data[2];

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        EnableInterrupts(INTR_FLAG_HBLANK | INTR_FLAG_VBLANK);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_0860CE74, ARRAY_COUNT(gUnknown_0860CE74));
        InitWindows(gUnknown_0860CE94);
        DeactivateAllTextPrinters();
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0xB00, 0);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0x5860);
        SetGpuReg(REG_OFFSET_WIN0V, 0x9F);
        SetGpuReg(REG_OFFSET_WIN1H, 0x9098);
        SetGpuReg(REG_OFFSET_WIN1V, 0x9F);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0x3F);
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gTasks[taskId].data[0]++;
        break;
    case 2:
        sTilemapBuffer = AllocZeroed(0x800);
        LZDecompressWram(gUnknown_08D83900, sTilemapBuffer);
        SetBgTilemapBuffer(1, sTilemapBuffer);
        CopyBgTilemapBufferToVram(1);
        DecompressAndLoadBgGfxUsingHeap(1, gUnknown_08D82F10, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, gUnknown_08D834FC, 0x2000, 0, 0);
        DecompressAndLoadBgGfxUsingHeap(2, gUnknown_08D83B2C, 0x2000, 0, 1);
        DecompressAndLoadBgGfxUsingHeap(3, gUnknown_08D83C3C, 0x2000, 0, 1);
        LoadCompressedPalette(gUnknown_08D85358, 0, 0x200);
        LoadCompressedPalette(gUnknown_08D85444, 0x100, 0x200);
        LoadCompressedPalette(gUnknown_08D85600, 0xF0, 0x20);
        CpuFill32(0, gPlttBufferFaded, 0x400);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gTasks[taskId].data[0]++;
        break;
    case 3:
        LoadCompressedSpriteSheet(sDomeOptionsSpriteSheet);
        if (r10 == 0)
        {
            for (i = 0; i < (unsigned) 31; i++)
                CreateSprite(&gUnknown_0860CFA8, gUnknown_0860D411[i][0], gUnknown_0860D411[i][1], 0);
            if (gTasks[taskId].data[4])
                CreateSprite(&gUnknown_0860D008, 218, 12, 0);
            else
                CreateSprite(&gUnknown_0860CFD8, 218, 12, 0);
        }

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_1D_MAP);
        gTasks[taskId].data[0]++;
        break;
    case 4:
        textPrinter.fontId = 2;
        textPrinter.currentChar = gText_BattleTourney;
        textPrinter.windowId = 2;
        textPrinter.x = 0;
        textPrinter.y = 0;
        textPrinter.letterSpacing = 2;
        textPrinter.lineSpacing = 0;
        textPrinter.currentX = GetStringCenterAlignXOffsetWithLetterSpacing(textPrinter.fontId, textPrinter.currentChar, 0x70, textPrinter.letterSpacing);
        textPrinter.currentY = 1;
        textPrinter.unk = 0;
        textPrinter.fgColor = 14;
        textPrinter.bgColor = 0;
        textPrinter.shadowColor = 13;
        AddTextPrinter(&textPrinter, 0, NULL);
        for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
        {
            int roundId, var2;

            CopyDomeTrainerName(gDisplayedStringBattle, gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId);
            if (r10 == 1)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated)
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt != 0)
                    {
                        var2 = gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt - 1;
                        sub_81948EC(i, var2);
                    }
                }
                else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum != DOME_ROUND2)
                {
                    sub_81948EC(i, gSaveBlock2Ptr->frontier.curChallengeBattleNum - 2);
                }
            }
            else if (r10 == 0)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated)
                {
                    if (gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt != 0)
                    {
                        var2 = gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt - 1;
                        sub_81948EC(i, var2);
                    }
                }
                else if (gSaveBlock2Ptr->frontier.curChallengeBattleNum != DOME_ROUND1)
                {
                    if (gTasks[taskId].data[4])
                        var2 = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
                    else
                        var2 = gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1;
                    sub_81948EC(i, var2);
                }
            }

            if (gTasks[taskId].data[4])
                roundId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            else
                roundId = gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1;

            if (    ((r10 == 1 && gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt < gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1)
                  || (r10 == 0 && gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt <= roundId))
                && gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == TRAINER_PLAYER)
                {
                    textPrinter.fgColor = 3;
                    textPrinter.shadowColor = 4;
                }
                else
                {
                    textPrinter.fgColor = 11;
                    textPrinter.shadowColor = 13;
                }
            }
            else
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == TRAINER_PLAYER)
                {
                    textPrinter.fgColor = 3;
                    textPrinter.shadowColor = 4;
                }
                else
                {
                    textPrinter.fgColor = 14;
                    textPrinter.shadowColor = 13;
                }
            }

            if (gUnknown_0860D3F1[i][0] == 0)
                textPrinter.currentX = GetStringWidthDifference(textPrinter.fontId, gDisplayedStringBattle, 0x3D, textPrinter.letterSpacing);
            else
                textPrinter.currentX = 3;
            textPrinter.currentChar = gDisplayedStringBattle;
            textPrinter.windowId = gUnknown_0860D3F1[i][0];
            textPrinter.currentY = gUnknown_0860D3F1[i][1];
            AddTextPrinter(&textPrinter, 0, NULL);
        }
        gTasks[taskId].data[0]++;
        break;
    case 5:
        PutWindowTilemap(0);
        PutWindowTilemap(1);
        PutWindowTilemap(2);
        CopyWindowToVram(0, 3);
        CopyWindowToVram(1, 3);
        CopyWindowToVram(2, 3);
        SetHBlankCallback(HblankCb_BattleDome);
        SetVBlankCallback(VblankCb1_BattleDome);
        if (r4 == 2)
        {
            if (r10 == 0)
            {
                i = CreateTask(sub_819395C, 0);
                gTasks[i].data[0] = r10;
                gTasks[i].data[1] = r10;
                gTasks[i].data[6] = gTasks[taskId].data[4];
            }
            else
            {
                i = CreateTask(sub_8194950, 0);
                gTasks[i].data[0] = 0;
            }
        }
        else
        {
            i = gTasks[taskId].data[3];
            gTasks[i].data[0] = 0;
        }
        ScanlineEffect_Clear();

        i = 0;
        while (i < 91)
        {
            gScanlineEffectRegBuffers[0][i] = BGCNT_PRIORITY(2) | BGCNT_SCREENBASE(31) | BGCNT_16COLOR | BGCNT_CHARBASE(2) | BGCNT_TXT256x256;
            gScanlineEffectRegBuffers[1][i] = BGCNT_PRIORITY(2) | BGCNT_SCREENBASE(31) | BGCNT_16COLOR | BGCNT_CHARBASE(2) | BGCNT_TXT256x256;
            i++;
        }

        while (i < 160)
        {
            gScanlineEffectRegBuffers[0][i] =  BGCNT_PRIORITY(1) | BGCNT_SCREENBASE(31) | BGCNT_16COLOR | BGCNT_CHARBASE(2) | BGCNT_TXT256x256;
            gScanlineEffectRegBuffers[1][i] =  BGCNT_PRIORITY(1) | BGCNT_SCREENBASE(31) | BGCNT_16COLOR | BGCNT_CHARBASE(2) | BGCNT_TXT256x256;
            i++;
        }

        ScanlineEffect_SetParams(sTourneyTreeScanlineEffectParams);
        DestroyTask(taskId);
        break;
    }
}

static void sub_81948EC(u8 tournamentId, u8 arg1)
{
    int i;
    const struct UnkStruct_860DD10 *structPtr = gUnknown_0860DD10[tournamentId][arg1];

    for (i = 0; i < gUnknown_0860DE10[tournamentId][arg1]; i++)
        CopyToBgTilemapBufferRect_ChangePalette(1, &structPtr[i].src, structPtr[i].x, structPtr[i].y, 1, 1, 0x11);

    CopyBgTilemapBufferToVram(1);
}

static void sub_8194950(u8 taskId)
{
    int i;
    struct TextPrinterTemplate textPrinter;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].data[0] = 2;
            gTasks[taskId].data[3] = 64;
            textPrinter.fontId = 2;
            textPrinter.x = 0;
            textPrinter.y = 0;
            textPrinter.letterSpacing = 2;
            textPrinter.lineSpacing = 0;
            textPrinter.unk = 0;
            textPrinter.fgColor = 11;
            textPrinter.bgColor = 0;
            textPrinter.shadowColor = 13;
            for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
            {
                CopyDomeTrainerName(gDisplayedStringBattle, gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId);
                if (gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt == gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1
                    && gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated)
                {
                    if (gUnknown_0860D3F1[i][0] == 0)
                        textPrinter.currentX = GetStringWidthDifference(textPrinter.fontId, gDisplayedStringBattle, 0x3D, textPrinter.letterSpacing);
                    else
                        textPrinter.currentX = 3;

                    textPrinter.currentChar = gDisplayedStringBattle;
                    textPrinter.windowId = gUnknown_0860D3F1[i][0];
                    textPrinter.currentY = gUnknown_0860D3F1[i][1];
                    AddTextPrinter(&textPrinter, 0, NULL);
                }
                if (!gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated)
                {
                    int roundId = gSaveBlock2Ptr->frontier.curChallengeBattleNum - 1;
                    sub_81948EC(i, roundId);
                }
            }
        }
        break;
    case 2:
        if (--gTasks[taskId].data[3] == 0)
            gTasks[taskId].data[0] = 3;
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].data[0] = 4;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            DestroyTask(taskId);
        }
        break;
    }
}

static void CB2_BattleDome(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void VblankCb0_BattleDome(void)
{
    ChangeBgX(3, 0x80, 1);
    ChangeBgY(3, 0x80, 2);
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define SET_WIN0H_WIN1H(win0H, win1H)                       \
{                                                           \
    *(vu32*)(REG_ADDR_WIN0H) = ((win0H << 16) | (win1H));   \
}

static void HblankCb_BattleDome(void)
{
    register u32 vCount asm("r0") = REG_VCOUNT;
    register u32 vCount_ asm("r1") = vCount;
    if (vCount > 41)
    {
        if (vCount < 50)
        {
            REG_WININ = WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG3 | WININ_WIN1_OBJ | WININ_WIN1_CLR;
            SET_WIN0H_WIN1H(WIN_RANGE(152, 155), WIN_RANGE(85, 88));
            return;
        }
        else if (vCount > 57)
        {
            if (vCount < 75)
            {
                REG_WININ = WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG3 | WININ_WIN1_OBJ | WININ_WIN1_CLR;
                SET_WIN0H_WIN1H(WIN_RANGE(144, 152), WIN_RANGE(88, 96));
                return;
            }
            else if (vCount < 82)
            {
                REG_WININ = WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG3 | WININ_WIN1_OBJ | WININ_WIN1_CLR;
                SET_WIN0H_WIN1H(WIN_RANGE(152, 155), WIN_RANGE(85, 88));
                return;
            }
            else if (vCount > 94)
            {
                if (vCount < 103)
                {
                    REG_WININ = WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG2 | WININ_WIN1_OBJ | WININ_WIN1_CLR;
                    SET_WIN0H_WIN1H(WIN_RANGE(152, 155), WIN_RANGE(85, 88));
                    return;
                }
                else if (vCount < 119)
                {
                    REG_WININ = WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG2 | WININ_WIN1_OBJ | WININ_WIN1_CLR;
                    SET_WIN0H_WIN1H(WIN_RANGE(144, 152), WIN_RANGE(88, 96));
                    return;
                }
                else if (vCount > 126)
                {
                    if (vCount_ < 135)
                    {
                        REG_WININ = WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG2 | WININ_WIN1_OBJ | WININ_WIN1_CLR;
                        SET_WIN0H_WIN1H(WIN_RANGE(152, 155), WIN_RANGE(85, 88));
                        return;
                    }
                }
            }
        }
    }

    REG_WININ = WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_CLR | WININ_WIN1_OBJ;
    SET_WIN0H_WIN1H(0, 0);
}

static void VblankCb1_BattleDome(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    ChangeBgY(2, 0x80, 2);
    ChangeBgY(3, 0x80, 1);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void InitDomeFacilityTrainersAndMons(void)
{
    gFacilityTrainerMons = gBattleFrontierMons;
    gFacilityTrainers = gBattleFrontierTrainers;
}

static void RestoreDomePlayerParty(void)
{
    int i, moveSlot;

    for (i = 0; i < 2; i++)
    {
        int playerMonId = gSaveBlock2Ptr->frontier.selectedPartyMons[gSelectedOrderFromParty[i] - 1] - 1;
        int count;

        for (moveSlot = 0; moveSlot < MAX_MON_MOVES; moveSlot++)
        {
            count = 0;
            while (count < MAX_MON_MOVES)
            {
                if (GetMonData(&gSaveBlock1Ptr->playerParty[playerMonId], MON_DATA_MOVE1 + count, NULL) == GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + moveSlot, NULL))
                    break;
                count++;
            }
            if (count == MAX_MON_MOVES)
                SetMonMoveSlot(&gPlayerParty[i], MOVE_SKETCH, moveSlot);
        }

        gSaveBlock1Ptr->playerParty[playerMonId] = gPlayerParty[i];
    }
}

static void RestoreDomePlayerPartyHeldItems(void)
{
    int i;

    for (i = 0; i < 2; i++)
    {
        int playerMonId = gSaveBlock2Ptr->frontier.selectedPartyMons[gSelectedOrderFromParty[i] - 1] - 1;
        u16 item = GetMonData(&gSaveBlock1Ptr->playerParty[playerMonId], MON_DATA_HELD_ITEM, NULL);
        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
    }
}

static void ReduceDomePlayerPartyTo3Mons(void)
{
    ReducePlayerPartyToSelectedMons();
}

static void GetPlayerSeededBeforeOpponent(void)
{
    if (TrainerIdToTournamentId(gTrainerBattleOpponent_A) > TrainerIdToTournamentId(TRAINER_PLAYER))
        gSpecialVar_Result = 1;
    else
        gSpecialVar_Result = 2;
}

static void BufferLastDomeWinnerName(void)
{
    int i;

    InitDomeFacilityTrainersAndMons();
    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (!gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated)
            break;
    }
    CopyDomeTrainerName(gStringVar1, gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId);
}

static void sub_8194F58(void)
{
    int i, j, k;
    int monLevel;
    int species[3];
    int monTypesBits;
    int trainerId;
    int monSetId;
    u8 lvlMode;
    u16 *statSums;
    int *statValues;
    u8 ivs = 0;

    species[0] = 0;
    species[1] = 0;
    species[2] = 0;
    if ((gSaveBlock2Ptr->frontier.field_D0A != -gSaveBlock2Ptr->frontier.field_D0B) && gSaveBlock2Ptr->frontier.field_CA8 != 1)
        return;

    statSums = AllocZeroed(sizeof(u16) * DOME_TOURNAMENT_TRAINERS_COUNT);
    statValues = AllocZeroed(sizeof(int) * 6);
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    gSaveBlock2Ptr->frontier.lvlMode = 0;
    // This one, I'd like to call a 'C fakematching'.
    {
        u8 one;
        gSaveBlock2Ptr->frontier.field_D0A = (one = 1);
        gSaveBlock2Ptr->frontier.field_D0B = one;
    }

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        do
        {
            if (i < 5)
                trainerId = Random() % 10;
            else if (i < 15)
                trainerId = Random() % 20 + 10;
            else
                trainerId = Random() % 10 + 30;

            for (j = 0; j < i; j++)
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId == trainerId)
                    break;
            }
        } while (j != i);

        gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId = trainerId;
        for (j = 0; j < 3; j++)
        {
            // Make sure the mon is valid.
            do
            {
                monSetId = RandomizeFacilityTrainerMonSet(trainerId);
                for (k = 0; k < j; k++)
                {
                    int checkingMonId = gSaveBlock2Ptr->frontier.domeMonIds[i][k];
                    if (checkingMonId == monSetId
                        || species[0] == gFacilityTrainerMons[monSetId].species
                        || species[1] == gFacilityTrainerMons[monSetId].species
                        || gFacilityTrainerMons[checkingMonId].itemTableId == gFacilityTrainerMons[monSetId].itemTableId)
                        break;
                }
            } while (k != j);

            gSaveBlock2Ptr->frontier.domeMonIds[i][j] = monSetId;
            species[j] = gFacilityTrainerMons[monSetId].species;
        }
        gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated = 0;
        gSaveBlock2Ptr->frontier.domeTrainers[i].eliminatedAt = 0;
        gSaveBlock2Ptr->frontier.domeTrainers[i].unk3 = 0;
    }

    monLevel = 50;
    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        monTypesBits = 0;
        statSums[i] = 0;
        ivs = GetDomeTrainerMonIvs(gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId);
        for (j = 0; j < 3; j++)
        {
            CalcDomeMonStats(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].species,
                             monLevel, ivs,
                             gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].evSpread,
                             gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].nature,
                             statValues);

            statSums[i] += statValues[STAT_ATK];
            statSums[i] += statValues[STAT_DEF];
            statSums[i] += statValues[STAT_SPATK];
            statSums[i] += statValues[STAT_SPDEF];
            statSums[i] += statValues[STAT_SPEED];
            statSums[i] += statValues[STAT_HP];
            monTypesBits |= gBitTable[gBaseStats[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].species].type1];
            monTypesBits |= gBitTable[gBaseStats[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[i][j]].species].type2];
        }

        // Because GF hates temporary vars, trainerId acts like monTypesCount here.
        for (trainerId = 0, j = 0; j < 32; j++)
        {
            if (monTypesBits & 1)
                trainerId++;
            monTypesBits >>= 1;
        }
        statSums[i] += (trainerId * monLevel) / 20;
    }

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT - 1; i++)
    {
        for (j = i + 1; j < DOME_TOURNAMENT_TRAINERS_COUNT; j++)
        {
            if (statSums[i] < statSums[j])
            {
                SwapDomeTrainers(i, j, statSums);
            }
            else if (statSums[i] == statSums[j])
            {
                if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId > gSaveBlock2Ptr->frontier.domeTrainers[j].trainerId)
                    SwapDomeTrainers(i, j, statSums);
            }
        }
    }

    Free(statSums);
    Free(statValues);

    for (i = 0; i < 4; i++)
        DecideRoundWinners(i);

    gSaveBlock2Ptr->frontier.lvlMode = lvlMode;
}

static int TrainerIdToTournamentId(u16 trainerId)
{
    int i;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == trainerId)
            break;
    }

    return i;
}

// The same as the above one, but has global scope.
int TrainerIdToDomeTournamentId(u16 trainerId)
{
    int i;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == trainerId)
            break;
    }

    return i;
}

static u8 sub_81953E8(u8 tournamentId, u8 round)
{
    u8 arr[2];
    sub_8192F08(gUnknown_0860D1A0[gUnknown_0860D1C0[tournamentId] / 2][round] - 16, arr);
    if (tournamentId == arr[0])
        return arr[1];
    else
        return arr[0];
}

static void DecideRoundWinners(u8 roundId)
{
    int i;
    int moveSlot, monId1, monId2;
    int tournamentId1, tournamentId2;
    int species;
    int points1 = 0, points2 = 0;

    for (i = 0; i < DOME_TOURNAMENT_TRAINERS_COUNT; i++)
    {
        if (gSaveBlock2Ptr->frontier.domeTrainers[i].isEliminated || gSaveBlock2Ptr->frontier.domeTrainers[i].trainerId == TRAINER_PLAYER)
            continue;

        tournamentId1 = i;
        tournamentId2 = TournamentIdOfOpponent(roundId, gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].trainerId);
        // Frontier Brain always wins, check tournamentId1.
        if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].trainerId == TRAINER_FRONTIER_BRAIN && tournamentId2 != 0xFF)
        {
            gSaveBlock2Ptr->frontier.domeTrainers[tournamentId2].isEliminated = 1;
            gSaveBlock2Ptr->frontier.domeTrainers[tournamentId2].eliminatedAt = roundId;
            gSaveBlock2Ptr->frontier.field_EC0[tournamentId2] = GetWinningMove(tournamentId1, tournamentId2, roundId);
        }
        // Frontier Brain always wins, check tournamentId2.
        else if (gSaveBlock2Ptr->frontier.domeTrainers[tournamentId2].trainerId == TRAINER_FRONTIER_BRAIN && tournamentId1 != 0xFF)
        {
            gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].isEliminated = 1;
            gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].eliminatedAt = roundId;
            gSaveBlock2Ptr->frontier.field_EC0[tournamentId1] = GetWinningMove(tournamentId2, tournamentId1, roundId);
        }
        // Decide which one of two trainers wins!
        else if (tournamentId2 != 0xFF)
        {
            // BUG: points1 and points2 are not cleared at the beginning of the loop resulting in not fair results.

            // Calculate points for both trainers.
            for (monId1 = 0; monId1 < 3; monId1++)
            {
                for (moveSlot = 0; moveSlot < MAX_MON_MOVES; moveSlot++)
                {
                    for (monId2 = 0; monId2 < 3; monId2++)
                    {
                        points1 += GetTypeEffectivenessPoints(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentId1][monId1]].moves[moveSlot],
                                                gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentId2][monId2]].species, 2);
                    }
                }
                species = gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentId1][monId1]].species;
                points1 += ( gBaseStats[species].baseHP
                           + gBaseStats[species].baseAttack
                           + gBaseStats[species].baseDefense
                           + gBaseStats[species].baseSpeed
                           + gBaseStats[species].baseSpAttack
                           + gBaseStats[species].baseSpDefense) / 10;
            }
            // Random part of the formula.
            points1 += (Random() & 0x1F);
            // Favor trainers with higher id;
            points1 += tournamentId1;

            for (monId1 = 0; monId1 < 3; monId1++)
            {
                for (moveSlot = 0; moveSlot < MAX_MON_MOVES; moveSlot++)
                {
                    for (monId2 = 0; monId2 < 3; monId2++)
                    {
                        points2 += GetTypeEffectivenessPoints(gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentId2][monId1]].moves[moveSlot],
                                                gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentId1][monId2]].species, 2);
                    }
                }
                species = gFacilityTrainerMons[gSaveBlock2Ptr->frontier.domeMonIds[tournamentId2][monId1]].species;
                points2 += ( gBaseStats[species].baseHP
                           + gBaseStats[species].baseAttack
                           + gBaseStats[species].baseDefense
                           + gBaseStats[species].baseSpeed
                           + gBaseStats[species].baseSpAttack
                           + gBaseStats[species].baseSpDefense) / 10;
            }
            // Random part of the formula.
            points2 += (Random() & 0x1F);
            // Favor trainers with higher id;
            points2 += tournamentId2;

            if (points1 > points2)
            {
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId2].isEliminated = 1;
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId2].eliminatedAt = roundId;
                gSaveBlock2Ptr->frontier.field_EC0[tournamentId2] = GetWinningMove(tournamentId1, tournamentId2, roundId);
            }
            else if (points1 < points2)
            {
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].isEliminated = 1;
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].eliminatedAt = roundId;
                gSaveBlock2Ptr->frontier.field_EC0[tournamentId1] = GetWinningMove(tournamentId2, tournamentId1, roundId);
            }
            // Points are the same, so we favor the one with the higher id.
            else if (tournamentId1 > tournamentId2)
            {
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId2].isEliminated = 1;
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId2].eliminatedAt = roundId;
                gSaveBlock2Ptr->frontier.field_EC0[tournamentId2] = GetWinningMove(tournamentId1, tournamentId2, roundId);
            }
            else
            {
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].isEliminated = 1;
                gSaveBlock2Ptr->frontier.domeTrainers[tournamentId1].eliminatedAt = roundId;
                gSaveBlock2Ptr->frontier.field_EC0[tournamentId1] = GetWinningMove(tournamentId2, tournamentId1, roundId);
            }
        }
    }
}

static void CopyDomeTrainerName(u8 *str, u16 trainerId)
{
    int i = 0;
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyDomeBrainTrainerName(str);
    }
    else
    {
        if (trainerId == TRAINER_PLAYER)
        {
            for (i = 0; i < PLAYER_NAME_LENGTH; i++)
                str[i] = gSaveBlock2Ptr->playerName[i];
        }
        else if (trainerId < 300)
        {
            for (i = 0; i < PLAYER_NAME_LENGTH; i++)
                str[i] = gFacilityTrainers[trainerId].trainerName[i];
        }
        str[i] = EOS;
    }
}

static u8 GetDomeBrainTrainerPicId(void)
{
    return gTrainers[TRAINER_TUCKER].trainerPic;
}

static u8 GetDomeBrainTrainerClass(void)
{
    return gTrainers[TRAINER_TUCKER].trainerClass;
}

static void CopyDomeBrainTrainerName(u8 *str)
{
    int i;

    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        str[i] = gTrainers[TRAINER_TUCKER].trainerName[i];
    str[i] = EOS;
}
