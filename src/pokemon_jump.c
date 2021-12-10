#include "global.h"
#include "malloc.h"
#include "battle_anim.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "minigame_countdown.h"
#include "palette.h"
#include "random.h"
#include "digit_obj_util.h"
#include "save.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "pokemon.h"
#include "pokemon_jump.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/items.h"

#define MAX_JUMP_SCORE 99990
#define MAX_JUMPS 9999

#define JUMP_PEAK (-30)

enum {
    BG_INTERFACE,
    BG_BONUSES,
    BG_VENUSAUR,
    BG_SCENERY,
};

// IDs for persistent windows
enum {
    WIN_POINTS,
    WIN_TIMES,
    NUM_WINDOWS
};

enum {
    PACKET_MON_INFO = 1,
    PACKET_UNUSED,
    PACKET_LEADER_STATE,
    PACKET_MEMBER_STATE,
};

enum {
    JUMP_TYPE_NORMAL,
    JUMP_TYPE_FAST,
    JUMP_TYPE_SLOW,
};

enum {
    FUNC_GAME_INTRO,
    FUNC_WAIT_ROUND,
    FUNC_GAME_ROUND,
    FUNC_GAME_OVER,
    FUNC_ASK_PLAY_AGAIN,
    FUNC_RESET_GAME,
    FUNC_EXIT,
    FUNC_GIVE_PRIZE,
    FUNC_SAVE,
    FUNC_NONE
};

enum {
    GFXFUNC_LOAD,
    GFXFUNC_SHOW_NAMES,
    GFXFUNC_SHOW_NAMES_HIGHLIGHT,
    GFXFUNC_ERASE_NAMES,
    GFXFUNC_MSG_PLAY_AGAIN,
    GFXFUNC_MSG_SAVING,
    GFXFUNC_ERASE_MSG,
    GFXFUNC_MSG_PLAYER_DROPPED,
    GFXFUNC_MSG_COMM_STANDBY,
    GFXFUNC_COUNTDOWN,
};

enum {
    VINE_HIGHEST,
    VINE_DOWNSWING_HIGHER,
    VINE_DOWNSWING_HIGH,
    VINE_DOWNSWING_LOW,
    VINE_DOWNSWING_LOWER,
    VINE_LOWEST,
    VINE_UPSWING_LOWER,
    VINE_UPSWING_LOW,
    VINE_UPSWING_HIGH,
    VINE_UPSWING_HIGHER,
    NUM_VINESTATES
};

// Used to compare limits for vineStateTimer
// The upper 8 bits of vineStateTimer are the vine state,
// the lower 8 bits are a timer to the next state.
// When the timer is incremented above 255, it increments
// the vine state and the timer is reset.
#define VINE_STATE_TIMER(vineState)(((vineState) << 8) | 0xFF)

enum {
    MONSTATE_NORMAL, // Pokémon is either on the ground or in the middle of a jump
    MONSTATE_JUMP,   // Pokémon has begun a jump
    MONSTATE_HIT,    // Pokémon got hit by the vine
};

enum {
    JUMPSTATE_NONE,
    JUMPSTATE_SUCCESS, // Cleared vine
    JUMPSTATE_FAILURE, // Hit vine
};

#define PLAY_AGAIN_NO  1
#define PLAY_AGAIN_YES 2

#define TAG_MON1 0
#define TAG_MON2 1 // MON2-5 used implicitly by adding multiplayer id to tag
#define TAG_MON3 2
#define TAG_MON4 3
#define TAG_MON5 4

#define GFXTAG_VINE1     5
#define GFXTAG_VINE2     6
#define GFXTAG_VINE3     7
#define GFXTAG_VINE4     8
#define GFXTAG_COUNTDOWN 9
#define GFXTAG_STAR      10

#define PALTAG_1         5
#define PALTAG_2         6
#define PALTAG_COUNTDOWN 7

#define TAG_DIGITS 800

#define VINE_SPRITES_PER_SIDE 4 // Vine rope is divided into 8 sprites, 4 per side copied and flipped horizontally

// Used by SetLinkTimeInterval to get a bit mask for capping
// a timer that controls how frequently link data is sent.
#define LINK_INTERVAL_NONE   0
#define LINK_INTERVAL_SHORT  3 // 3 frame interval
#define LINK_INTERVAL_MEDIUM 4 // 7 frame interval
#define LINK_INTERVAL_LONG   5 // 15 frame interval

#define LINK_TIMER_STOPPED 0x1111

struct PokemonJump_MonInfo
{
    u16 species;
    u32 otId;
    u32 personality;
};

struct PokemonJump_Player
{
    int jumpOffset;
    int jumpOffsetIdx;
    u32 unused;
    u16 monJumpType;
    u16 jumpTimeStart;
    u16 monState;
    u16 prevMonState;
    int jumpState;
    bool32 funcFinished;
    u8 name[11];
};

struct PokemonJumpGfx
{
    bool32 funcFinished;
    u16 mainState;
    u8 taskId;
    u8 unused1[3];
    u8 resetVineState;
    u8 resetVineTimer;
    u8 vineState;
    u8 msgWindowState;
    u8 vinePalNumDownswing;
    u8 vinePalNumUpswing;
    u16 unused2;
    u16 msgWindowId;
    u16 fanfare;
    u32 bonusTimer;
    u16 nameWindowIds[MAX_RFU_PLAYERS];
    u8 itemName[64];
    u8 itemQuantityStr[64];
    u8 prizeMsg[256];
    u16 tilemapBuffer[0x4000];
    struct Sprite *monSprites[MAX_RFU_PLAYERS];
    struct Sprite *starSprites[MAX_RFU_PLAYERS];
    struct Sprite *vineSprites[VINE_SPRITES_PER_SIDE * 2];
    u8 unused3[12];
    u8 monSpriteSubpriorities[MAX_RFU_PLAYERS];
};

struct PokemonJump_CommData
{
    u8 funcId;
    u8 receivedBonusFlags;
    u16 data; // Multi-use
    u16 jumpsInRow;
    u32 jumpScore;
};

struct PokemonJump
{
    MainCallback exitCallback;
    u8 taskId;
    u8 numPlayers;
    u8 multiplayerId;
    u8 startDelayTimer;
    u16 mainState;
    u16 helperState;
    u16 excellentsInRow;
    u16 excellentsInRowRecord;
    bool32 gameOver;
    u32 vineState;
    u32 prevVineState;
    int vineSpeed;
    u32 vineSpeedAccel;
    u32 rngSeed;
    u32 nextVineSpeed;
    int linkTimer;
    u32 linkTimerLimit;
    u16 vineStateTimer;
    bool16 ignoreJumpInput;
    u16 unused1;
    u16 unused2; // Set to 0, never read
    u16 timer;
    u16 prizeItemId;
    u16 prizeItemQuantity;
    u16 playAgainComm;
    u8 unused3; // Set to 0, never read
    u8 playAgainState;
    bool8 allowVineUpdates;
    bool8 isLeader;
    bool8 funcActive;
    bool8 allPlayersReady;
    u16 vineTimer;
    u8 nextFuncId;
    bool8 showBonus;
    u16 vineSpeedDelay;
    u8 vineBaseSpeedIdx;
    u8 vineSpeedStage;
    int numPlayersAtPeak;
    bool32 initScoreUpdate;
    bool32 updateScore;
    bool32 unused4; // Set to TRUE, never read
    bool32 giveBonus;
    bool32 skipJumpUpdate;
    bool32 atMaxSpeedStage;
    struct PokemonJump_CommData comm;
    bool8 atJumpPeak[MAX_RFU_PLAYERS];
    bool8 atJumpPeak2[MAX_RFU_PLAYERS];
    bool8 atJumpPeak3[MAX_RFU_PLAYERS];
    u8 memberFuncIds[MAX_RFU_PLAYERS];
    u16 playAgainStates[MAX_RFU_PLAYERS];
    u16 jumpTimeStarts[MAX_RFU_PLAYERS];
    struct PokemonJumpGfx jumpGfx;
    struct PokemonJump_MonInfo monInfo[MAX_RFU_PLAYERS];
    struct PokemonJump_Player players[MAX_RFU_PLAYERS];
    struct PokemonJump_Player *player;
};

struct PokemonJumpMons
{
    u16 species;
    u16 jumpType;
};

static void InitGame(struct PokemonJump *);
static void ResetForNewGame(struct PokemonJump *);
static void InitPlayerAndJumpTypes(void);
static void ResetPlayersForNewGame(void);
static s16 GetPokemonJumpSpeciesIdx(u16 species);
static void InitJumpMonInfo(struct PokemonJump_MonInfo *, struct Pokemon *);
static void CB2_PokemonJump(void);
static void Task_StartPokemonJump(u8);
static void Task_PokemonJump_Leader(u8);
static void SendLinkData_Leader(void);
static void Task_PokemonJump_Member(u8);
static void SendLinkData_Member(void);
static bool32 GameIntro_Leader(void);
static bool32 WaitRound_Leader(void);
static bool32 GameRound_Leader(void);
static bool32 GameOver_Leader(void);
static bool32 GameOver_Member(void);
static bool32 AskPlayAgain_Leader(void);
static bool32 AskPlayAgain_Member(void);
static bool32 ResetGame_Leader(void);
static bool32 ResetGame_Member(void);
static bool32 ExitGame(void);
static bool32 GivePrize_Leader(void);
static bool32 GivePrize_Member(void);
static bool32 SavePokeJump(void);
static bool32 DoGameIntro(void);
static bool32 HandleSwingRound(void);
static bool32 DoVineHitEffect(void);
static bool32 GameIntro_Member(void);
static bool32 WaitRound_Member(void);
static bool32 GameRound_Member(void);
static bool32 TryGivePrize(void);
static bool32 DoPlayAgainPrompt(void);
static bool32 ClosePokeJumpLink(void);
static bool32 CloseMessageAndResetScore(void);
static void Task_CommunicateMonInfo(u8);
static void SetTaskWithPokeJumpStruct(TaskFunc, u8);
static void InitVineState(void);
static void ResetVineState(void);
static void UpdateVineState(void);
static int GetVineSpeed(void);
static void UpdateVineSpeed(void);
static int PokeJumpRandom(void);
static void ResetVineAfterHit(void);
static void ResetPlayersJumpStates(void);
static void ResetPlayersMonState(void);
static bool32 IsPlayersMonState(u16);
static void SetMonStateJump(void);
static void UpdateGame(void);
static void TryUpdateVineSwing(void);
static void DisallowVineUpdates(void);
static void AllowVineUpdates(void);
static void HandleMonState(void);
static void UpdateJump(int);
static void TryUpdateScore(void);
static bool32 UpdateVineHitStates(void);
static bool32 AllPlayersJumpedOrHit(void);
static bool32 DidAllPlayersClearVine(void);
static bool32 ShouldPlayAgain(void);
static void AddJumpScore(int);
static int GetPlayersAtJumpPeak(void);
static bool32 AreLinkQueuesEmpty(void);
static int GetNumPlayersForBonus(u8 *);
static void ClearUnreadField(void);
static int GetScoreBonus(int);
static void TryUpdateExcellentsRecord(u16);
static bool32 HasEnoughScoreForPrize(void);
static u16 GetPrizeData(void);
static void UnpackPrizeData(u16, u16 *, u16 *);
static u16 GetPrizeItemId(void);
static u16 GetPrizeQuantity(void);
static u16 GetQuantityLimitedByBag(u16, u16);
static void SpriteCB_Star(struct Sprite *);
static void SpriteCB_MonHitShake(struct Sprite *);
static void SpriteCB_MonHitFlash(struct Sprite *);
static void SpriteCB_MonIntroBounce(struct Sprite *);
static void UpdateVineSwing(int);
static void StartPokeJumpGfx(struct PokemonJumpGfx *);
static void InitPokeJumpGfx(struct PokemonJumpGfx *);
static void FreeWindowsAndDigitObj(void);
static void SetUpPokeJumpGfxFuncById(int);
static bool32 IsPokeJumpGfxFuncFinished(void);
static void SetUpResetVineGfx(void);
static bool32 ResetVineGfx(void);
static void PrintPrizeMessage(u16, u16);
static void PrintPrizeFilledBagMessage(u16);
static void PrintNoRoomForPrizeMessage(u16);
static bool32 DoPrizeMessageAndFanfare(void);
static void ClearMessageWindow(void);
static void SetMonSpriteY(u32, s16);
static void StartMonHitShake(u8);
static bool32 RemoveMessageWindow(void);
static void PrintScore(int);
static s8 HandlePlayAgainInput(void);
static int DoSameJumpTimeBonus(u8);
static void PrintJumpsInRow(u16);
static void StartMonHitFlash(u8);
static int IsMonHitShakeActive(int);
static void StopMonHitFlash(void);
static void ResetMonSpriteSubpriorities(void);
static void StartMonIntroBounce(int);
static int IsMonIntroBounceActive(void);
static void SendPacket_MonInfo(struct PokemonJump_MonInfo *);
static bool32 RecvPacket_MonInfo(int, struct PokemonJump_MonInfo *);
static void SendPacket_LeaderState(struct PokemonJump_Player *, struct PokemonJump_CommData *);
static bool32 RecvPacket_LeaderState(struct PokemonJump_Player *, struct PokemonJump_CommData *);
static void SendPacket_MemberState(struct PokemonJump_Player *, u8, u16);
static bool32 RecvPacket_MemberStateToLeader(struct PokemonJump_Player *, int, u8 *, u16 *);
static bool32 RecvPacket_MemberStateToMember(struct PokemonJump_Player *, int);
static bool32 TryUpdateRecords(u32, u16, u16);
static void IncrementGamesWithMaxPlayers(void);
static void Task_RunPokeJumpGfxFunc(u8);
static void ShowBonus(u8);
static void Task_UpdateBonus(u8);
static void LoadPokeJumpGfx(void);
static void InitDigitPrinters(void);
static void PrintScoreSuffixes(void);
static void CreateJumpMonSprites(void);
static void AddPlayerNameWindows(void);
static void DrawPlayerNameWindows(void);
static void SetUpPokeJumpGfxFunc(void (*func)(void));
static void PrintPokeJumpPlayerNames(bool32);
static u32 AddMessageWindow(u32, u32, u32, u32);
static void CreatePokeJumpYesNoMenu(u16, u16, u8);
static void PrintPlayerNamesNoHighlight(void);
static void PrintPlayerNamesWithHighlight(void);
static void ErasePlayerNames(void);
static void Msg_WantToPlayAgain(void);
static void Msg_SavingDontTurnOff(void);
static void EraseMessage(void);
static void Msg_SomeoneDroppedOut(void);
static void DoPokeJumpCountdown(void);
static void Msg_CommunicationStandby(void);
static void Task_ShowPokemonJumpRecords(u8);
static void PrintRecordsText(u16, int);
static void TruncateToFirstWordOnly(u8 *);

EWRAM_DATA static struct PokemonJump *sPokemonJump = NULL;
EWRAM_DATA static struct PokemonJumpGfx *sPokemonJumpGfx = NULL;

/*
    According to the clerk, the Pokémon allowed in
    Pokémon Jump are all <= 28 inches, and do not
    only swim, burrow, or fly.
*/
static const struct PokemonJumpMons sPokeJumpMons[] =
{
    { .species = SPECIES_BULBASAUR,  .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_CHARMANDER, .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_SQUIRTLE,   .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_CATERPIE,   .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_METAPOD,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_WEEDLE,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_KAKUNA,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_RATTATA,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_RATICATE,   .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_PIKACHU,    .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_SANDSHREW,  .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_NIDORAN_F,  .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_NIDORAN_M,  .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_CLEFAIRY,   .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_VULPIX,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_JIGGLYPUFF, .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_ODDISH,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_PARAS,      .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_MEOWTH,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_PSYDUCK,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_MANKEY,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_GROWLITHE,  .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_POLIWAG,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_BELLSPROUT, .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SHELLDER,   .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_KRABBY,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_EXEGGCUTE,  .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_CUBONE,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_DITTO,      .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_EEVEE,      .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_OMANYTE,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_KABUTO,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_CHIKORITA,  .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_CYNDAQUIL,  .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_TOTODILE,   .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_SPINARAK,   .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_PICHU,      .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_CLEFFA,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_IGGLYBUFF,  .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_TOGEPI,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_MAREEP,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_BELLOSSOM,  .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_MARILL,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SUNKERN,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_WOOPER,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_PINECO,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SNUBBULL,   .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_SHUCKLE,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_TEDDIURSA,  .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_SLUGMA,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SWINUB,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_HOUNDOUR,   .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_PHANPY,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_PORYGON2,   .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_TYROGUE,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_SMOOCHUM,   .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_ELEKID,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_MAGBY,      .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_LARVITAR,   .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_TREECKO,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_TORCHIC,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_MUDKIP,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_MARSHTOMP,  .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_POOCHYENA,  .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_ZIGZAGOON,  .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_LINOONE,    .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_WURMPLE,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_SILCOON,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_CASCOON,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_LOTAD,      .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SEEDOT,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_RALTS,      .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_KIRLIA,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_SURSKIT,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SHROOMISH,  .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_NINCADA,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_WHISMUR,    .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_AZURILL,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SKITTY,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_SABLEYE,    .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_MAWILE,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_ARON,       .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_MEDITITE,   .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_ELECTRIKE,  .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_PLUSLE,     .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_MINUN,      .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_VOLBEAT,    .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_ILLUMISE,   .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_ROSELIA,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_GULPIN,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_NUMEL,      .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_TORKOAL,    .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_SPOINK,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_TRAPINCH,   .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_CACNEA,     .jumpType = JUMP_TYPE_SLOW, },
    { .species = SPECIES_ANORITH,    .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_WYNAUT,     .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_SNORUNT,    .jumpType = JUMP_TYPE_NORMAL, },
    { .species = SPECIES_CLAMPERL,   .jumpType = JUMP_TYPE_FAST, },
    { .species = SPECIES_BAGON,      .jumpType = JUMP_TYPE_FAST, },
};

void StartPokemonJump(u16 partyId, MainCallback exitCallback)
{
    u8 taskId;

    if (gReceivedRemoteLinkPlayers)
    {
        sPokemonJump = Alloc(sizeof(*sPokemonJump));
        if (sPokemonJump)
        {
            ResetTasks();
            taskId = CreateTask(Task_StartPokemonJump, 1);
            sPokemonJump->mainState = 0;
            sPokemonJump->exitCallback = exitCallback;
            sPokemonJump->taskId = taskId;
            sPokemonJump->multiplayerId = GetMultiplayerId();
            InitJumpMonInfo(&sPokemonJump->monInfo[sPokemonJump->multiplayerId], &gPlayerParty[partyId]);
            InitGame(sPokemonJump);
            SetWordTaskArg(taskId, 2, (u32)sPokemonJump);
            SetMainCallback2(CB2_PokemonJump);
            return;
        }
    }

    // Exit - Players not connected, or alloc failed
    SetMainCallback2(exitCallback);
}

static void FreePokemonJump(void)
{
    FreeWindowsAndDigitObj();
    Free(sPokemonJump);
}

static void InitGame(struct PokemonJump *jump)
{
    jump->numPlayers = GetLinkPlayerCount();
    jump->comm.funcId = FUNC_RESET_GAME;
    jump->comm.data = 0;
    InitPlayerAndJumpTypes();
    ResetForNewGame(jump);
    if (jump->numPlayers == MAX_RFU_PLAYERS)
        IncrementGamesWithMaxPlayers();
}

static void ResetForNewGame(struct PokemonJump *jump)
{
    int i;

    jump->vineState = VINE_UPSWING_LOWER;
    jump->prevVineState = VINE_UPSWING_LOWER;
    jump->vineTimer = 0;
    jump->vineSpeed = 0;
    jump->updateScore = FALSE;
    jump->isLeader = GetMultiplayerId() == 0;
    jump->mainState = 0;
    jump->helperState = 0;
    jump->excellentsInRow = 0;
    jump->excellentsInRowRecord = 0;
    jump->initScoreUpdate = FALSE;
    jump->unused2 = 0;
    jump->unused3 = 0;
    jump->numPlayersAtPeak = 0;
    jump->allowVineUpdates = FALSE;
    jump->allPlayersReady = FALSE;
    jump->funcActive = TRUE;
    jump->comm.jumpScore = 0;
    jump->comm.receivedBonusFlags = 0;
    jump->comm.jumpsInRow = 0;
    jump->unused4 = TRUE;
    jump->showBonus = FALSE;
    jump->skipJumpUpdate = FALSE;
    jump->giveBonus = FALSE;
    jump->linkTimer = 0;
    jump->linkTimerLimit = 0;
    ResetPlayersForNewGame();
    ResetPlayersJumpStates();

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        jump->atJumpPeak[i] = FALSE;
        jump->jumpTimeStarts[i] = 0;
    }
}

static void InitPlayerAndJumpTypes(void)
{
    int i, index;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        index = GetPokemonJumpSpeciesIdx(sPokemonJump->monInfo[i].species);
        sPokemonJump->players[i].monJumpType = sPokeJumpMons[index].jumpType;
    }

    sPokemonJump->player = &sPokemonJump->players[sPokemonJump->multiplayerId];
}

static void ResetPlayersForNewGame(void)
{
    int i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        sPokemonJump->players[i].jumpTimeStart = 0;
        sPokemonJump->players[i].monState = MONSTATE_NORMAL;
        sPokemonJump->players[i].prevMonState = MONSTATE_NORMAL;
        sPokemonJump->players[i].jumpOffset = 0;
        sPokemonJump->players[i].jumpOffsetIdx = INT_MAX;
        sPokemonJump->players[i].jumpState = JUMPSTATE_NONE;
        sPokemonJump->memberFuncIds[i] = FUNC_NONE;
    }
}

static s16 GetPokemonJumpSpeciesIdx(u16 species)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sPokeJumpMons); i++)
    {
        if (sPokeJumpMons[i].species == species)
            return i;
    }

    return -1; // species isnt allowed
}

static void InitJumpMonInfo(struct PokemonJump_MonInfo *monInfo, struct Pokemon *mon)
{
    monInfo->species = GetMonData(mon, MON_DATA_SPECIES);
    monInfo->otId = GetMonData(mon, MON_DATA_OT_ID);
    monInfo->personality = GetMonData(mon, MON_DATA_PERSONALITY);
}

static void VBlankCB_PokemonJump(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void CB2_PokemonJump(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void SetPokeJumpTask(TaskFunc func)
{
    sPokemonJump->taskId = CreateTask(func, 1);
    sPokemonJump->mainState = 0;
}

static void Task_StartPokemonJump(u8 taskId)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetTaskWithPokeJumpStruct(Task_CommunicateMonInfo, 5);
        FadeOutMapMusic(4);
        sPokemonJump->mainState++;
        break;
    case 1:
        if (!FuncIsActiveTask(Task_CommunicateMonInfo))
        {
            StartPokeJumpGfx(&sPokemonJump->jumpGfx);
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
            sPokemonJump->mainState++;
        }
        break;
    case 2:
        if (!IsPokeJumpGfxFuncFinished() && IsNotWaitingForBGMStop() == TRUE)
        {
            FadeOutAndPlayNewMapMusic(MUS_RG_POKE_JUMP, 8);
            sPokemonJump->mainState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
            SetVBlankCallback(VBlankCB_PokemonJump);
            sPokemonJump->mainState++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            sPokemonJump->startDelayTimer = 0;
            sPokemonJump->mainState++;
        }
        break;
    case 5:
        sPokemonJump->startDelayTimer++;
        if (sPokemonJump->startDelayTimer >= 20)
        {
            if (sPokemonJump->isLeader)
                SetPokeJumpTask(Task_PokemonJump_Leader);
            else
                SetPokeJumpTask(Task_PokemonJump_Member);

            InitVineState();
            DestroyTask(taskId);
        }
        break;
    }
}

static void SetLinkTimeInterval(int intervalId)
{
    if (intervalId == LINK_INTERVAL_NONE)
    {
        // Link data is sent when timer reaches 0.
        // Set timer to 1 and set limit to special
        // 'stopped' value so timer won't change
        sPokemonJump->linkTimerLimit = LINK_TIMER_STOPPED;
        sPokemonJump->linkTimer = 1;
    }
    else
    {
        sPokemonJump->linkTimerLimit = (1 << (intervalId - 1)) - 1;
        sPokemonJump->linkTimer = 0;
    }
}

static void SetFunc_Leader(u8 funcId)
{
    int i;

    sPokemonJump->comm.funcId = funcId;
    sPokemonJump->mainState = 0;
    sPokemonJump->helperState = 0;
    sPokemonJump->funcActive = TRUE;
    sPokemonJump->allPlayersReady = FALSE;
    for (i = 1; i < sPokemonJump->numPlayers; i++)
        sPokemonJump->players[i].funcFinished = FALSE;
}

static void RecvLinkData_Leader(void)
{
    int i;
    int numReady;
    u16 monState;
    u8 funcId;
    u16 playAgainState;

    for (i = 1, numReady = 0; i < sPokemonJump->numPlayers; i++)
    {
        monState = sPokemonJump->players[i].monState;
        if (RecvPacket_MemberStateToLeader(&sPokemonJump->players[i], i, &funcId, &playAgainState))
        {
            sPokemonJump->playAgainStates[i] = playAgainState;
            sPokemonJump->memberFuncIds[i] = funcId;
            sPokemonJump->players[i].prevMonState = monState;
        }

        // Group member has finished currently assigned function
        if (sPokemonJump->players[i].funcFinished && sPokemonJump->memberFuncIds[i] == sPokemonJump->comm.funcId)
            numReady++;
    }

    if (numReady == sPokemonJump->numPlayers - 1)
        sPokemonJump->allPlayersReady = TRUE;
}

static bool32 (* const sPokeJumpLeaderFuncs[])(void) =
{
    [FUNC_GAME_INTRO]     = GameIntro_Leader,
    [FUNC_WAIT_ROUND]     = WaitRound_Leader,
    [FUNC_GAME_ROUND]     = GameRound_Leader,
    [FUNC_GAME_OVER]      = GameOver_Leader,
    [FUNC_ASK_PLAY_AGAIN] = AskPlayAgain_Leader,
    [FUNC_RESET_GAME]     = ResetGame_Leader,
    [FUNC_EXIT]           = ExitGame,
    [FUNC_GIVE_PRIZE]     = GivePrize_Leader,
    [FUNC_SAVE]           = SavePokeJump,
};

static void Task_PokemonJump_Leader(u8 taskId)
{
    RecvLinkData_Leader();
    TryUpdateScore();
    if (!sPokemonJump->funcActive && sPokemonJump->allPlayersReady)
    {
        SetFunc_Leader(sPokemonJump->nextFuncId);
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
    }

    if (sPokemonJump->funcActive == TRUE)
    {
        if (!sPokeJumpLeaderFuncs[sPokemonJump->comm.funcId]())
        {
            sPokemonJump->funcActive = FALSE;
            sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished = TRUE;
        }
    }

    UpdateGame();
    SendLinkData_Leader();
}

static void SendLinkData_Leader(void)
{
    if (!sPokemonJump->linkTimer)
        SendPacket_LeaderState(sPokemonJump->players, &sPokemonJump->comm);

    if (sPokemonJump->linkTimerLimit != LINK_TIMER_STOPPED)
    {
        sPokemonJump->linkTimer++;
        sPokemonJump->linkTimer &= sPokemonJump->linkTimerLimit;
    }
}

static void SetFunc_Member(u8 funcId)
{
    sPokemonJump->comm.funcId = funcId;
    sPokemonJump->mainState = 0;
    sPokemonJump->helperState = 0;
    sPokemonJump->funcActive = TRUE;
    sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished = FALSE;
}

static void RecvLinkData_Member(void)
{
    int i;
    u16 monState;
    struct PokemonJump_CommData leaderData;

    monState = sPokemonJump->players[0].monState;
    if (RecvPacket_LeaderState(sPokemonJump->players, &leaderData))
    {
        if (sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished == TRUE
         && leaderData.funcId != sPokemonJump->comm.funcId)
        {
            SetFunc_Member(leaderData.funcId);
        }

        if (sPokemonJump->comm.jumpScore != leaderData.jumpScore)
        {
            sPokemonJump->comm.jumpScore = leaderData.jumpScore;
            sPokemonJump->updateScore = TRUE;
            sPokemonJump->comm.receivedBonusFlags = leaderData.receivedBonusFlags;
            if (sPokemonJump->comm.receivedBonusFlags)
                sPokemonJump->showBonus = TRUE;
            else
                sPokemonJump->showBonus = FALSE;
        }

        sPokemonJump->comm.data = leaderData.data;
        sPokemonJump->comm.jumpsInRow = leaderData.jumpsInRow;
        sPokemonJump->players[0].prevMonState = monState;
    }

    for (i = 1; i < sPokemonJump->numPlayers; i++)
    {
        if (i != sPokemonJump->multiplayerId)
        {
            monState = sPokemonJump->players[i].monState;
            if (RecvPacket_MemberStateToMember(&sPokemonJump->players[i], i))
                sPokemonJump->players[i].prevMonState = monState;
        }
    }
}

static bool32 (* const sPokeJumpMemberFuncs[])(void) =
{
    [FUNC_GAME_INTRO]     = GameIntro_Member,
    [FUNC_WAIT_ROUND]     = WaitRound_Member,
    [FUNC_GAME_ROUND]     = GameRound_Member,
    [FUNC_GAME_OVER]      = GameOver_Member,
    [FUNC_ASK_PLAY_AGAIN] = AskPlayAgain_Member,
    [FUNC_RESET_GAME]     = ResetGame_Member,
    [FUNC_EXIT]           = ExitGame,
    [FUNC_GIVE_PRIZE]     = GivePrize_Member,
    [FUNC_SAVE]           = SavePokeJump,
};

static void Task_PokemonJump_Member(u8 taskId)
{
    RecvLinkData_Member();
    if (sPokemonJump->funcActive)
    {
        if (!sPokeJumpMemberFuncs[sPokemonJump->comm.funcId]())
        {
            sPokemonJump->funcActive = FALSE;
            sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished = TRUE;
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        }
    }

    UpdateGame();
    SendLinkData_Member();
}

static void SendLinkData_Member(void)
{
    if (!sPokemonJump->linkTimer)
        SendPacket_MemberState(&sPokemonJump->players[sPokemonJump->multiplayerId], sPokemonJump->comm.funcId, sPokemonJump->playAgainComm);

    if (sPokemonJump->linkTimerLimit != LINK_TIMER_STOPPED)
    {
        sPokemonJump->linkTimer++;
        sPokemonJump->linkTimer &= sPokemonJump->linkTimerLimit;
    }
}

static bool32 GameIntro_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (!DoGameIntro())
        {
            sPokemonJump->comm.data = sPokemonJump->vineTimer;
            sPokemonJump->nextFuncId = FUNC_WAIT_ROUND;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 GameIntro_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->rngSeed = sPokemonJump->comm.data;
        sPokemonJump->mainState++;
        // fall through
    case 1:
        return DoGameIntro();
    }

    return TRUE;
}

static bool32 WaitRound_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        ResetPlayersJumpStates();
        SetLinkTimeInterval(LINK_INTERVAL_LONG);
        sPokemonJump->mainState++;
        break;
    case 1:
        if (sPokemonJump->allPlayersReady)
        {
            sPokemonJump->nextFuncId = FUNC_GAME_ROUND;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 WaitRound_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        ResetPlayersJumpStates();
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->vineTimer = sPokemonJump->comm.data;
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (AreLinkQueuesEmpty())
            return FALSE;
        break;
    }

    return TRUE;
}

static bool32 GameRound_Leader(void)
{
    if (!HandleSwingRound())
    {
        sPokemonJump->comm.data = sPokemonJump->vineTimer;
        sPokemonJump->nextFuncId = FUNC_WAIT_ROUND;
    }
    else if (UpdateVineHitStates())
    {
        return TRUE;
    }
    else
    {
        // Someone hit the vine
        ResetVineAfterHit();
        sPokemonJump->nextFuncId = FUNC_GAME_OVER;
    }

    return FALSE;
}

static bool32 GameRound_Member(void)
{
    if (!HandleSwingRound())
        ;
    else if (UpdateVineHitStates())
        return TRUE;
    else // Someone hit the vine
        ResetVineAfterHit();

    return FALSE;
}

static bool32 GameOver_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        UpdateVineHitStates();
        if (AllPlayersJumpedOrHit())
            sPokemonJump->mainState++;
        break;
    case 1:
        if (!DoVineHitEffect())
        {
            if (HasEnoughScoreForPrize())
            {
                sPokemonJump->comm.data = GetPrizeData();
                sPokemonJump->nextFuncId = FUNC_GIVE_PRIZE;
            }
            else if (sPokemonJump->comm.jumpsInRow >= 200)
            {
                sPokemonJump->comm.data = sPokemonJump->excellentsInRowRecord;
                sPokemonJump->nextFuncId = FUNC_SAVE;
            }
            else
            {
                sPokemonJump->comm.data = sPokemonJump->excellentsInRowRecord;
                sPokemonJump->nextFuncId = FUNC_ASK_PLAY_AGAIN;
            }

            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool32 GameOver_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        if (!UpdateVineHitStates())
            ResetVineAfterHit();
        if (AllPlayersJumpedOrHit())
            sPokemonJump->mainState++;
        break;
    case 1:
        if (!DoVineHitEffect())
        {
            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool32 AskPlayAgain_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_MEDIUM);
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (!DoPlayAgainPrompt())
        {
            TryUpdateRecords(sPokemonJump->comm.jumpScore, sPokemonJump->comm.jumpsInRow, sPokemonJump->comm.data);
            sPokemonJump->mainState++;
        }
        break;
    case 2:
        if (sPokemonJump->allPlayersReady)
        {
            if (ShouldPlayAgain())
                sPokemonJump->nextFuncId = FUNC_RESET_GAME;
            else
                sPokemonJump->nextFuncId = FUNC_EXIT;

            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 3:
        return FALSE;
    }

    return TRUE;
}

static bool32 AskPlayAgain_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (!DoPlayAgainPrompt())
        {
            TryUpdateRecords(sPokemonJump->comm.jumpScore, sPokemonJump->comm.jumpsInRow, sPokemonJump->comm.data);
            sPokemonJump->playAgainComm = sPokemonJump->playAgainState;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 ResetGame_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        if (!CloseMessageAndResetScore())
            sPokemonJump->mainState++;
        break;
    case 1:
        if (sPokemonJump->allPlayersReady)
        {
            ResetForNewGame(sPokemonJump);
            sPokemonJump->rngSeed = Random();
            sPokemonJump->comm.data = sPokemonJump->rngSeed;
            sPokemonJump->nextFuncId = FUNC_GAME_INTRO;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 ResetGame_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        if (!CloseMessageAndResetScore())
        {
            ResetForNewGame(sPokemonJump);
            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

static bool32 ExitGame(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        sPokemonJump->mainState = 1;
        break;
    case 1:
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->mainState++;
        break;
    case 2:
        if (!ClosePokeJumpLink())
        {
            SetMainCallback2(sPokemonJump->exitCallback);
            FreePokemonJump();
        }
        break;
    }

    return TRUE;
}

static bool32 GivePrize_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_MEDIUM);
        sPokemonJump->mainState++;
        break;
    case 1:
        if (!TryGivePrize())
        {
            sPokemonJump->comm.data = sPokemonJump->excellentsInRowRecord;
            sPokemonJump->nextFuncId = FUNC_SAVE;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 GivePrize_Member(void)
{
    SetLinkTimeInterval(LINK_INTERVAL_NONE);
    if (!TryGivePrize())
        return FALSE;
    else
        return TRUE;
}

static bool32 SavePokeJump(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        TryUpdateRecords(sPokemonJump->comm.jumpScore, sPokemonJump->comm.jumpsInRow, sPokemonJump->comm.data);
        SetUpPokeJumpGfxFuncById(GFXFUNC_MSG_SAVING);
        sPokemonJump->mainState++;
        break;
    case 1:
        if (!IsPokeJumpGfxFuncFinished())
        {
            SetLinkTimeInterval(LINK_INTERVAL_NONE);
            sPokemonJump->mainState++;
        }
        break;
    case 2:
        if (AreLinkQueuesEmpty())
        {
            CreateTask(Task_LinkFullSave, 6);
            sPokemonJump->mainState++;
        }
        break;
    case 3:
        if (!FuncIsActiveTask(Task_LinkFullSave))
        {
            ClearMessageWindow();
            sPokemonJump->mainState++;
        }
        break;
    case 4:
        if (!RemoveMessageWindow())
        {
            sPokemonJump->nextFuncId = FUNC_ASK_PLAY_AGAIN;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 DoGameIntro(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        SetUpPokeJumpGfxFuncById(GFXFUNC_SHOW_NAMES_HIGHLIGHT);
        ResetMonSpriteSubpriorities();
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!IsPokeJumpGfxFuncFinished())
        {
            StartMonIntroBounce(sPokemonJump->multiplayerId);
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 2:
        if (++sPokemonJump->timer > 120)
        {
            SetUpPokeJumpGfxFuncById(GFXFUNC_ERASE_NAMES);
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (IsPokeJumpGfxFuncFinished() != TRUE && IsMonIntroBounceActive() != TRUE)
            sPokemonJump->helperState++;
        break;
    case 4:
        SetUpPokeJumpGfxFuncById(GFXFUNC_COUNTDOWN);
        sPokemonJump->helperState++;
        break;
    case 5:
        if (!IsPokeJumpGfxFuncFinished())
        {
            DisallowVineUpdates();
            SetUpResetVineGfx();
            sPokemonJump->helperState++;
        }
        break;
    case 6:
        if (!ResetVineGfx())
        {
            AllowVineUpdates();
            ResetVineState();
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 7:
        return FALSE;
    }

    return TRUE;
}

// Update the vine and wait for player to input a jump
// Returns false when vine reaches the 'hit' point, after
// which input is ignored
static bool32 HandleSwingRound(void)
{
    UpdateVineState();
    if (sPokemonJump->ignoreJumpInput)
    {
        sPokemonJump->ignoreJumpInput = FALSE;
        return FALSE;
    }

    switch (sPokemonJump->helperState)
    {
    case 0:
        if (IsPlayersMonState(MONSTATE_NORMAL))
            sPokemonJump->helperState++;
        else
            break;
        // fall through
    case 1:
        if (JOY_NEW(A_BUTTON))
        {
            SetMonStateJump();
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
            sPokemonJump->helperState++;
        }
        break;
    case 2:
        if (IsPlayersMonState(MONSTATE_JUMP) == TRUE)
            sPokemonJump->helperState++;
        break;
    case 3:
        if (IsPlayersMonState(MONSTATE_NORMAL) == TRUE)
            sPokemonJump->helperState = 0;
        break;
    }

    return TRUE;
}

static bool32 DoVineHitEffect(void)
{
    int i;

    switch (sPokemonJump->helperState)
    {
    case 0:
        for (i = 0; i < sPokemonJump->numPlayers; i++)
        {
            if (IsMonHitShakeActive(i) == TRUE)
                return TRUE;
        }

        sPokemonJump->helperState++;
        break;
    case 1:
        for (i = 0; i < sPokemonJump->numPlayers; i++)
        {
            if (sPokemonJump->players[i].monState == MONSTATE_HIT)
                StartMonHitFlash(i);
        }

        SetUpPokeJumpGfxFuncById(GFXFUNC_SHOW_NAMES);
        sPokemonJump->timer = 0;
        sPokemonJump->helperState++;
        break;
    case 2:
        if (++sPokemonJump->timer > 100)
        {
            SetUpPokeJumpGfxFuncById(GFXFUNC_ERASE_NAMES);
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (!IsPokeJumpGfxFuncFinished())
        {
            StopMonHitFlash();
            sPokemonJump->comm.receivedBonusFlags = 0;
            ResetPlayersMonState();
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 4:
        return FALSE;
    }

    return TRUE;
}

static bool32 TryGivePrize(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        UnpackPrizeData(sPokemonJump->comm.data, &sPokemonJump->prizeItemId, &sPokemonJump->prizeItemQuantity);
        PrintPrizeMessage(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity);
        sPokemonJump->helperState++;
        break;
    case 1:
    case 4:
        if (!DoPrizeMessageAndFanfare())
        {
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 2:
    case 5:
        // Wait to continue after message
        sPokemonJump->timer++;
        if (JOY_NEW(A_BUTTON | B_BUTTON) || sPokemonJump->timer > 180)
        {
            ClearMessageWindow();
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (!RemoveMessageWindow())
        {
            sPokemonJump->prizeItemQuantity = GetQuantityLimitedByBag(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity);
            if (sPokemonJump->prizeItemQuantity && AddBagItem(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity))
            {
                if (!CheckBagHasSpace(sPokemonJump->prizeItemId, 1))
                {
                    // An item was given successfully, but no room for any more.
                    // It's possible the full prize quantity had to be limited
                    PrintPrizeFilledBagMessage(sPokemonJump->prizeItemId);
                    sPokemonJump->helperState = 4; // Do message
                }
                else
                {
                    sPokemonJump->helperState = 6; // Exit
                    break;
                }
            }
            else
            {
                PrintNoRoomForPrizeMessage(sPokemonJump->prizeItemId);
                sPokemonJump->helperState = 4; // Do message
            }
        }
        break;
    case 6:
        if (!RemoveMessageWindow())
            return FALSE;
        break;
    }

    return TRUE;
}

static bool32 DoPlayAgainPrompt(void)
{
    s8 input;

    switch (sPokemonJump->helperState)
    {
    case 0:
        SetUpPokeJumpGfxFuncById(GFXFUNC_MSG_PLAY_AGAIN);
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!IsPokeJumpGfxFuncFinished())
            sPokemonJump->helperState++;
        break;
    case 2:
        input = HandlePlayAgainInput();
        switch (input)
        {
        case MENU_B_PRESSED:
        case 1: // No
            sPokemonJump->playAgainState = PLAY_AGAIN_NO;
            SetUpPokeJumpGfxFuncById(GFXFUNC_ERASE_MSG);
            sPokemonJump->helperState++;
            break;
        case 0: // Yes
            sPokemonJump->playAgainState = PLAY_AGAIN_YES;
            SetUpPokeJumpGfxFuncById(GFXFUNC_ERASE_MSG);
            sPokemonJump->helperState++;
            break;
        }
        break;
    case 3:
        if (!IsPokeJumpGfxFuncFinished())
            sPokemonJump->helperState++;
        break;
    case 4:
        SetUpPokeJumpGfxFuncById(GFXFUNC_MSG_COMM_STANDBY);
        sPokemonJump->helperState++;
        break;
    case 5:
        if (!IsPokeJumpGfxFuncFinished())
        {
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 6:
        return FALSE;
    }

    return TRUE;
}

static bool32 ClosePokeJumpLink(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        ClearMessageWindow();
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!RemoveMessageWindow())
        {
            SetUpPokeJumpGfxFuncById(GFXFUNC_MSG_PLAYER_DROPPED);
            sPokemonJump->helperState++;
        }
        break;
    case 2:
        if (!IsPokeJumpGfxFuncFinished())
        {
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (++sPokemonJump->timer > 120)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
            sPokemonJump->helperState++;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            SetCloseLinkCallback();
            sPokemonJump->helperState++;
        }
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
            return FALSE;
        break;
    }

    return TRUE;
}

static bool32 CloseMessageAndResetScore(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        ClearMessageWindow();
        PrintScore(0);
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!RemoveMessageWindow())
        {
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

#define tState data[0]
#define tNumReceived data[1]
#define tReceivedPacket(playerId) data[(playerId) + 2]
#define DATAIDX_GAME_STRUCT 14

static void Task_CommunicateMonInfo(u8 taskId)
{
    int i;
    s16 *data = gTasks[taskId].data;
    struct PokemonJump *jump = (struct PokemonJump *)GetWordTaskArg(taskId, DATAIDX_GAME_STRUCT);

    switch (tState)
    {
    case 0:
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            tReceivedPacket(i) = FALSE;

        tState++;
        // fall through
    case 1:
        SendPacket_MonInfo(&jump->monInfo[jump->multiplayerId]);
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
        {
            if (!tReceivedPacket(i) && RecvPacket_MonInfo(i, &jump->monInfo[i]))
            {
                StringCopy(jump->players[i].name, gLinkPlayers[i].name);
                tReceivedPacket(i) = TRUE;
                tNumReceived++;
                if (tNumReceived == jump->numPlayers)
                {
                    InitPlayerAndJumpTypes();
                    DestroyTask(taskId);
                    break;
                }
            }
        }
        break;
    }
}

static void SetTaskWithPokeJumpStruct(TaskFunc func, u8 taskPriority)
{
    u8 taskId = CreateTask(func, taskPriority);
    SetWordTaskArg(taskId, DATAIDX_GAME_STRUCT, (u32)sPokemonJump);
}

#undef tState
#undef tNumReceived
#undef tReceivedPacket
#undef DATAIDX_GAME_STRUCT

static void InitVineState(void)
{
    sPokemonJump->vineTimer = 0;
    sPokemonJump->vineState = VINE_UPSWING_LOWER;
    sPokemonJump->vineStateTimer = 0;
    sPokemonJump->vineSpeed = 0;
    sPokemonJump->ignoreJumpInput = FALSE;
    sPokemonJump->gameOver = FALSE;
}

static void ResetVineState(void)
{
    sPokemonJump->vineTimer = 0;
    sPokemonJump->vineStateTimer = VINE_STATE_TIMER(VINE_UPSWING_LOWER);
    sPokemonJump->vineState = VINE_UPSWING_LOW;
    sPokemonJump->ignoreJumpInput = FALSE;
    sPokemonJump->gameOver = FALSE;
    sPokemonJump->vineSpeedStage = 0;
    sPokemonJump->vineBaseSpeedIdx = 0;
    sPokemonJump->vineSpeedAccel = 0;
    sPokemonJump->vineSpeedDelay = 0;
    sPokemonJump->atMaxSpeedStage = FALSE;
    UpdateVineSpeed();
}

static void UpdateVineState(void)
{
    if (sPokemonJump->allowVineUpdates)
    {
        sPokemonJump->vineTimer++;
        sPokemonJump->vineStateTimer += GetVineSpeed();
        if (sPokemonJump->vineStateTimer >= VINE_STATE_TIMER(NUM_VINESTATES - 1))
            sPokemonJump->vineStateTimer -= VINE_STATE_TIMER(NUM_VINESTATES - 1);

        sPokemonJump->prevVineState = sPokemonJump->vineState;
        sPokemonJump->vineState = sPokemonJump->vineStateTimer >> 8;

        // If beginning upswing
        if (sPokemonJump->vineState > VINE_UPSWING_LOWER && sPokemonJump->prevVineState < VINE_UPSWING_LOW)
        {
            sPokemonJump->ignoreJumpInput++;
            UpdateVineSpeed();
        }
    }
}

static int GetVineSpeed(void)
{
    int speed;

    if (sPokemonJump->gameOver)
        return 0;

    speed = sPokemonJump->vineSpeed;
    if (sPokemonJump->vineStateTimer <= VINE_STATE_TIMER(VINE_LOWEST))
    {
        // If at or below lowest, then vine is in downswing
        // Increase speed in downswing
        sPokemonJump->vineSpeedAccel += 80;
        speed += sPokemonJump->vineSpeedAccel / 256;
    }

    return speed;
}

static const u16 sVineBaseSpeeds[] = {26, 31, 36, 41, 46, 51, 56, 61};
static const u16 sVineSpeedDelays[] = {0, 1, 1, 2};

static void UpdateVineSpeed(void)
{
    int baseSpeed;

    sPokemonJump->vineSpeedAccel = 0;
    if (sPokemonJump->vineSpeedDelay)
    {
        sPokemonJump->vineSpeedDelay--;
        if (sPokemonJump->atMaxSpeedStage)
        {
            if (PokeJumpRandom() % 4)
            {
                sPokemonJump->vineSpeed = sPokemonJump->nextVineSpeed;
            }
            else
            {
                if (sPokemonJump->nextVineSpeed > 54)
                    sPokemonJump->vineSpeed = 30;
                else
                    sPokemonJump->vineSpeed = 82;
            }
        }
    }
    else
    {
        if (!(sPokemonJump->vineBaseSpeedIdx & ARRAY_COUNT(sVineBaseSpeeds)))
        {
            sPokemonJump->nextVineSpeed = sVineBaseSpeeds[sPokemonJump->vineBaseSpeedIdx] + (sPokemonJump->vineSpeedStage * 7);
            sPokemonJump->vineSpeedDelay = sVineSpeedDelays[PokeJumpRandom() % ARRAY_COUNT(sVineSpeedDelays)] + 2;
            sPokemonJump->vineBaseSpeedIdx++;
        }
        else
        {
            if (sPokemonJump->vineBaseSpeedIdx == ARRAY_COUNT(sVineBaseSpeeds))
            {
                if (sPokemonJump->vineSpeedStage < 3)
                    sPokemonJump->vineSpeedStage++;
                else
                    sPokemonJump->atMaxSpeedStage = TRUE;
            }

            baseSpeed = sVineBaseSpeeds[15 - sPokemonJump->vineBaseSpeedIdx];
            sPokemonJump->nextVineSpeed = baseSpeed + (sPokemonJump->vineSpeedStage * 7);
            if (++sPokemonJump->vineBaseSpeedIdx > 15)
            {
                if (PokeJumpRandom() % 4 == 0)
                    sPokemonJump->nextVineSpeed -= 5;

                sPokemonJump->vineBaseSpeedIdx = 0;
            }
        }

        sPokemonJump->vineSpeed = sPokemonJump->nextVineSpeed;
    }
}

static int PokeJumpRandom(void)
{
    sPokemonJump->rngSeed = ISO_RANDOMIZE1(sPokemonJump->rngSeed);
    return sPokemonJump->rngSeed >> 16;
}

static void ResetVineAfterHit(void)
{
    sPokemonJump->gameOver = TRUE;
    sPokemonJump->vineState = VINE_UPSWING_LOWER;
    sPokemonJump->vineStateTimer = VINE_STATE_TIMER(VINE_LOWEST);
    AllowVineUpdates();
}

static int IsGameOver(void)
{
    return sPokemonJump->gameOver;
}

static void ResetPlayersJumpStates(void)
{
    int i;
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        sPokemonJump->players[i].jumpState = JUMPSTATE_NONE;
}

static void ResetPlayersMonState(void)
{
    sPokemonJump->player->monState = MONSTATE_NORMAL;
    sPokemonJump->player->prevMonState = MONSTATE_NORMAL;
}

static bool32 IsPlayersMonState(u16 monState)
{
    if (sPokemonJump->players[sPokemonJump->multiplayerId].monState == monState)
        return TRUE;
    else
        return FALSE;
}

static void SetMonStateJump(void)
{
    sPokemonJump->player->jumpTimeStart = sPokemonJump->vineTimer;
    sPokemonJump->player->prevMonState = sPokemonJump->player->monState;
    sPokemonJump->player->monState = MONSTATE_JUMP;
}

static void SetMonStateHit(void)
{
    sPokemonJump->player->prevMonState = sPokemonJump->player->monState;
    sPokemonJump->player->monState = MONSTATE_HIT;
    sPokemonJump->player->jumpTimeStart = sPokemonJump->vineTimer;
    sPokemonJump->player->jumpState = JUMPSTATE_FAILURE;
}

static void SetMonStateNormal(void)
{
    sPokemonJump->player->prevMonState = sPokemonJump->player->monState;
    sPokemonJump->player->monState = MONSTATE_NORMAL;
}

static const u16 sSoundEffects[MAX_RFU_PLAYERS - 1] = {SE_SHOP, SE_SHINY, SE_M_MORNING_SUN, SE_RG_POKE_JUMP_SUCCESS};

static void UpdateGame(void)
{
    if (sPokemonJump->updateScore)
    {
        PrintScore(sPokemonJump->comm.jumpScore);
        sPokemonJump->updateScore = FALSE;
        if (sPokemonJump->showBonus)
        {
            int numPlayers = DoSameJumpTimeBonus(sPokemonJump->comm.receivedBonusFlags);
            PlaySE(sSoundEffects[numPlayers - 2]);
            sPokemonJump->showBonus = FALSE;
        }
    }

    PrintJumpsInRow(sPokemonJump->comm.jumpsInRow);
    HandleMonState();
    TryUpdateVineSwing();
}

static void TryUpdateVineSwing(void)
{
    if (sPokemonJump->allowVineUpdates)
        UpdateVineSwing(sPokemonJump->vineState);
}

static void DisallowVineUpdates(void)
{
    sPokemonJump->allowVineUpdates = FALSE;
}

static void AllowVineUpdates(void)
{
    sPokemonJump->allowVineUpdates = TRUE;
}

#define F_SE_JUMP (1 << 0)
#define F_SE_FAIL (1 << 1)

static void HandleMonState(void)
{
    int i;
    int soundFlags = 0;
    int numPlayers = sPokemonJump->numPlayers;

    for (i = 0; i < numPlayers; i++)
    {
        switch (sPokemonJump->players[i].monState)
        {
        case MONSTATE_NORMAL:
            SetMonSpriteY(i, 0);
            break;
        case MONSTATE_JUMP:
            if (sPokemonJump->players[i].prevMonState != MONSTATE_JUMP || sPokemonJump->players[i].jumpTimeStart != sPokemonJump->jumpTimeStarts[i])
            {
                // This is a new jump, play SE and init fields for jump handling
                if (i == sPokemonJump->multiplayerId)
                    sPokemonJump->players[i].prevMonState = MONSTATE_JUMP;

                soundFlags |= F_SE_JUMP;
                sPokemonJump->players[i].jumpOffsetIdx = INT_MAX;
                sPokemonJump->jumpTimeStarts[i] = sPokemonJump->players[i].jumpTimeStart;
            }

            UpdateJump(i);
            break;
        case MONSTATE_HIT:
            if (sPokemonJump->players[i].prevMonState != MONSTATE_HIT)
            {
                if (i == sPokemonJump->multiplayerId)
                    sPokemonJump->players[i].prevMonState = MONSTATE_HIT;

                soundFlags |= F_SE_FAIL;
                StartMonHitShake(i);
            }
            break;
        }
    }

    if (soundFlags & F_SE_FAIL)
        PlaySE(SE_RG_POKE_JUMP_FAILURE);
    else if (soundFlags & F_SE_JUMP)
        PlaySE(SE_LEDGE);
}

static const s8 sJumpOffsets[][48] =
{
    [JUMP_TYPE_NORMAL] = { -3,  -6,  -8, -10, -13, -15, -17, -19,
                          -21, -23, -25, -27, -28, -29,
                          JUMP_PEAK, JUMP_PEAK, JUMP_PEAK,
                          -28, -27, -26, -25, -23, -22, -20, -18,
                          -17, -15, -13, -11,  -8,  -6,  -4,  -1},

    [JUMP_TYPE_FAST]  = { -3,  -6,  -9, -11, -14, -16, -18, -20,
                         -22, -24, -26, -28, -29,
                         JUMP_PEAK, JUMP_PEAK,
                         -28, -26, -24, -22, -20, -18, -16, -14,
                         -11, -9,  -6,  -4,  -1},

    [JUMP_TYPE_SLOW]  = { -3,  -6,  -9, -11, -13, -15, -17, -19,
                         -21, -23, -25, -27, -28, -29,
                         JUMP_PEAK, JUMP_PEAK, JUMP_PEAK, JUMP_PEAK,
                         -29, -29, -28, -28, -27, -27, -26, -25,
                         -24, -22, -20, -18, -16, -14, -12, -11,
                          -9,  -6,  -4,  -1},
};

static void UpdateJump(int multiplayerId)
{
    int jumpOffsetIdx;
    int jumpOffset;
    struct PokemonJump_Player *player;

    if (sPokemonJump->skipJumpUpdate) // Always false
        return;

    player = &sPokemonJump->players[multiplayerId];
    if (player->jumpOffsetIdx != INT_MAX)
    {
        player->jumpOffsetIdx++;
        jumpOffsetIdx = player->jumpOffsetIdx;
    }
    else
    {
        jumpOffsetIdx = sPokemonJump->vineTimer - player->jumpTimeStart;
        if (jumpOffsetIdx >= 65000)
        {
            jumpOffsetIdx -= 65000;
            jumpOffsetIdx += sPokemonJump->vineTimer;
        }

        player->jumpOffsetIdx = jumpOffsetIdx;
    }

    if (jumpOffsetIdx < 4)
        return;

    jumpOffsetIdx -= 4;
    if (jumpOffsetIdx < (int)ARRAY_COUNT(sJumpOffsets[0]))
        jumpOffset = sJumpOffsets[player->monJumpType][jumpOffsetIdx];
    else
        jumpOffset = 0;

    SetMonSpriteY(multiplayerId, jumpOffset);
    if (jumpOffset == 0 && multiplayerId == sPokemonJump->multiplayerId)
        SetMonStateNormal();

    player->jumpOffset = jumpOffset;
}

static void TryUpdateScore(void)
{
    if (sPokemonJump->vineState == VINE_UPSWING_HIGH && sPokemonJump->prevVineState == VINE_UPSWING_LOW)
    {
        // Vine has passed through the point where it
        // would hit the players, allow score to update

        if (!sPokemonJump->initScoreUpdate)
        {
            ClearUnreadField();
            sPokemonJump->numPlayersAtPeak = 0;
            sPokemonJump->initScoreUpdate = TRUE;
            sPokemonJump->comm.receivedBonusFlags = 0;
        }
        else
        {
            if (sPokemonJump->numPlayersAtPeak == MAX_RFU_PLAYERS)
            {
                // An 'excellent' is the max 5 players all jumping synchronously
                sPokemonJump->excellentsInRow++;
                TryUpdateExcellentsRecord(sPokemonJump->excellentsInRow);
            }
            else
            {
                sPokemonJump->excellentsInRow = 0;
            }

            if (sPokemonJump->numPlayersAtPeak > 1)
            {
                sPokemonJump->giveBonus = TRUE;
                // Unclear why atJumpPeak needed to be copied over twice
                memcpy(sPokemonJump->atJumpPeak3, sPokemonJump->atJumpPeak2, sizeof(u8) * MAX_RFU_PLAYERS);
            }

            ClearUnreadField();
            sPokemonJump->numPlayersAtPeak = 0;
            sPokemonJump->initScoreUpdate = TRUE;
            sPokemonJump->comm.receivedBonusFlags = 0;
            if (sPokemonJump->comm.jumpsInRow < MAX_JUMPS)
                sPokemonJump->comm.jumpsInRow++;

            AddJumpScore(10);
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        }
    }

    if (sPokemonJump->giveBonus && (DidAllPlayersClearVine() == TRUE || sPokemonJump->vineState == VINE_HIGHEST))
    {
        int numPlayers = GetNumPlayersForBonus(sPokemonJump->atJumpPeak3);
        AddJumpScore(GetScoreBonus(numPlayers));
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        sPokemonJump->giveBonus = FALSE;
    }

    if (sPokemonJump->initScoreUpdate)
    {
        int numAtPeak = GetPlayersAtJumpPeak();
        if (numAtPeak > sPokemonJump->numPlayersAtPeak)
        {
            sPokemonJump->numPlayersAtPeak = numAtPeak;
            memcpy(sPokemonJump->atJumpPeak2, sPokemonJump->atJumpPeak, sizeof(u8) * MAX_RFU_PLAYERS);
        }
    }
}

// Returns FALSE if any player was hit by vine
static bool32 UpdateVineHitStates(void)
{
    int i;

    if (sPokemonJump->vineState == VINE_UPSWING_LOWER && sPokemonJump->player->jumpOffset == 0)
    {
        // Vine is in position to hit the player and jump offset is 0.
        // Unless the player had just jumped and has been forced to the ground
        // by someone else getting hit, the player has been hit
        if (sPokemonJump->player->prevMonState == MONSTATE_JUMP && IsGameOver() == TRUE)
        {
            sPokemonJump->player->jumpState = JUMPSTATE_SUCCESS;
        }
        else
        {
            // Hit vine
            SetMonStateHit();
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        }
    }

    if (sPokemonJump->vineState == VINE_UPSWING_LOW
     && sPokemonJump->prevVineState == VINE_UPSWING_LOWER
     && sPokemonJump->player->monState != MONSTATE_HIT)
    {
        sPokemonJump->player->jumpState = JUMPSTATE_SUCCESS;
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
    }

    for (i = 0; i < sPokemonJump->numPlayers; i++)
    {
        if (sPokemonJump->players[i].monState == MONSTATE_HIT)
            return FALSE;
    }

    return TRUE;
}

// Has everyone either jumped or been hit by the vine
static bool32 AllPlayersJumpedOrHit(void)
{
    int i;
    int numPlayers = sPokemonJump->numPlayers;
    int numJumpedOrHit = 0;
    for (i = 0; i < numPlayers; i++)
    {
        if (sPokemonJump->players[i].jumpState != JUMPSTATE_NONE)
            numJumpedOrHit++;
    }

    return numJumpedOrHit == numPlayers;
}

static bool32 DidAllPlayersClearVine(void)
{
    int i;
    for (i = 0; i < sPokemonJump->numPlayers; i++)
    {
        if (sPokemonJump->players[i].jumpState != JUMPSTATE_SUCCESS)
            return FALSE;
    }

    return TRUE;
}

static bool32 ShouldPlayAgain(void)
{
    int i;

    if (sPokemonJump->playAgainState == PLAY_AGAIN_NO)
        return FALSE;

    for (i = 1; i < sPokemonJump->numPlayers; i++)
    {
        if (sPokemonJump->playAgainStates[i] == PLAY_AGAIN_NO)
            return FALSE;
    }

    return TRUE;
}

static void AddJumpScore(int score)
{
    sPokemonJump->comm.jumpScore += score;
    sPokemonJump->updateScore = TRUE;
    if (sPokemonJump->comm.jumpScore >= MAX_JUMP_SCORE)
        sPokemonJump->comm.jumpScore = MAX_JUMP_SCORE;
}

static int GetPlayersAtJumpPeak(void)
{
    int i;
    int numAtPeak = 0;
    int numPlayers = sPokemonJump->numPlayers;

    for (i = 0; i < numPlayers; i++)
    {
        if (sPokemonJump->players[i].jumpOffset == JUMP_PEAK)
        {
            sPokemonJump->atJumpPeak[i] = TRUE;
            numAtPeak++;
        }
        else
        {
            sPokemonJump->atJumpPeak[i] = FALSE;
        }
    }

    return numAtPeak;
}

static bool32 AreLinkQueuesEmpty(void)
{
    return !gRfu.recvQueue.count && !gRfu.sendQueue.count;
}

static int GetNumPlayersForBonus(u8 *arg0)
{
    int i = 0;
    int flags = 0;
    int count = 0;

    for (; i < MAX_RFU_PLAYERS; i++)
    {
        if (arg0[i])
        {
            flags |= 1 << i;
            count++;
        }
    }

    sPokemonJump->comm.receivedBonusFlags = flags;
    if (flags)
        sPokemonJump->showBonus = TRUE;

    return count;
}

static void ClearUnreadField(void)
{
    sPokemonJump->unused3 = 0;
}

// Bonuses given depend on the number of
// players that jumped at the same time
static const int sScoreBonuses[MAX_RFU_PLAYERS + 1] = {0, 0, 50, 100, 200, 500};

static int GetScoreBonus(int numPlayers)
{
    return sScoreBonuses[numPlayers];
}

static void TryUpdateExcellentsRecord(u16 excellentsInRow)
{
    if (excellentsInRow > sPokemonJump->excellentsInRowRecord)
        sPokemonJump->excellentsInRowRecord = excellentsInRow;
}

static const u16 sPrizeItems[] = {
    ITEM_LEPPA_BERRY,
    ITEM_LUM_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_MAGO_BERRY,
    ITEM_AGUAV_BERRY,
    ITEM_IAPAPA_BERRY
};

struct {
    u32 score;
    u32 quantity;
} static const sPrizeQuantityData[] =
{
    { .score =  5000, .quantity = 1},
    { .score =  8000, .quantity = 2},
    { .score = 12000, .quantity = 3},
    { .score = 16000, .quantity = 4},
    { .score = 20000, .quantity = 5},
};

static bool32 HasEnoughScoreForPrize(void)
{
    if (sPokemonJump->comm.jumpScore >= sPrizeQuantityData[0].score)
        return TRUE;
    else
        return FALSE;
}

static u16 GetPrizeData(void)
{
    u16 itemId = GetPrizeItemId();
    u16 quantity = GetPrizeQuantity();
    return (quantity << 12) | (itemId & 0xFFF);
}

static void UnpackPrizeData(u16 data, u16 *itemId, u16 *quantity)
{
    *quantity = data >> 12;
    *itemId = data & 0xFFF;
}

static u16 GetPrizeItemId(void)
{
    u16 index = Random() % ARRAY_COUNT(sPrizeItems);
    return sPrizeItems[index];
}

static u16 GetPrizeQuantity(void)
{
    u32 quantity, i;

    quantity = 0;
    for (i = 0; i < ARRAY_COUNT(sPrizeQuantityData); i++)
    {
        if (sPokemonJump->comm.jumpScore >= sPrizeQuantityData[i].score)
            quantity = sPrizeQuantityData[i].quantity;
        else
            break;
    }

    return quantity;
}

static u16 GetQuantityLimitedByBag(u16 item, u16 quantity)
{
    while (quantity && !CheckBagHasSpace(item, quantity))
        quantity--;

    return quantity;
}

static u16 GetNumPokeJumpPlayers(void)
{
    return GetLinkPlayerCount();
}

static u16 GetPokeJumpMultiplayerId(void)
{
    return sPokemonJump->multiplayerId;
}

static struct PokemonJump_MonInfo *GetMonInfoByMultiplayerId(u8 multiplayerId)
{
    return &sPokemonJump->monInfo[multiplayerId];
}

static u8 *GetPokeJumpPlayerName(u8 multiplayerId)
{
    return sPokemonJump->players[multiplayerId].name;
}

bool32 IsSpeciesAllowedInPokemonJump(u16 species)
{
    return GetPokemonJumpSpeciesIdx(species) > -1;
}

void IsPokemonJumpSpeciesInParty(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_HAS_SPECIES))
        {
            u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            if (IsSpeciesAllowedInPokemonJump(species))
            {
                gSpecialVar_Result = TRUE;
                return;
            }
        }
    }

    gSpecialVar_Result = FALSE;
}

static const u16 sPokeJumpPal1[] = INCBIN_U16("graphics/pokemon_jump/pal1.gbapal");
static const u16 sPokeJumpPal2[] = INCBIN_U16("graphics/pokemon_jump/pal2.gbapal");

static const u32 sVine1_Gfx[] = INCBIN_U32("graphics/pokemon_jump/vine1.4bpp.lz");
static const u32 sVine2_Gfx[] = INCBIN_U32("graphics/pokemon_jump/vine2.4bpp.lz");
static const u32 sVine3_Gfx[] = INCBIN_U32("graphics/pokemon_jump/vine3.4bpp.lz");
static const u32 sVine4_Gfx[] = INCBIN_U32("graphics/pokemon_jump/vine4.4bpp.lz");

static const u32 sStar_Gfx[] = INCBIN_U32("graphics/pokemon_jump/star.4bpp.lz");

static const struct CompressedSpriteSheet sCompressedSpriteSheets[] =
{
    {sVine1_Gfx, 0x600, GFXTAG_VINE1},
    {sVine2_Gfx, 0xC00, GFXTAG_VINE2},
    {sVine3_Gfx, 0x600, GFXTAG_VINE3},
    {sVine4_Gfx, 0x600, GFXTAG_VINE4},
    {sStar_Gfx,  0x200, GFXTAG_STAR},
};

static const struct SpritePalette sSpritePalettes[] =
{
    {sPokeJumpPal1, PALTAG_1},
    {sPokeJumpPal2, PALTAG_2},
};

static const struct OamData sOamData_JumpMon;
static const struct SpriteTemplate sSpriteTemplate_Vine1;
static const struct SpriteTemplate sSpriteTemplate_Vine2;
static const struct SpriteTemplate sSpriteTemplate_Vine3;
static const struct SpriteTemplate sSpriteTemplate_Vine4;

static const struct SpriteTemplate sSpriteTemplate_JumpMon =
{
    .tileTag = TAG_MON1,
    .paletteTag = TAG_MON1,
    .oam = &sOamData_JumpMon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const s16 sVineYCoords[VINE_SPRITES_PER_SIDE][NUM_VINESTATES] =
{
    {96, 96, 96, 114, 120, 120, 120, 114, 96, 96},
    {70, 80, 96, 114, 120, 128, 120, 114, 96, 80},
    {50, 72, 96, 114, 128, 136, 128, 114, 96, 72},
    {42, 72, 96, 114, 128, 136, 128, 114, 96, 72},
};

static const s16 sVineXCoords[VINE_SPRITES_PER_SIDE * 2] = {16, 40, 72, 104, 136, 168, 200, 224};

static const struct SpriteTemplate *const sSpriteTemplates_Vine[VINE_SPRITES_PER_SIDE] =
{
    &sSpriteTemplate_Vine1,
    &sSpriteTemplate_Vine2,
    &sSpriteTemplate_Vine3,
    &sSpriteTemplate_Vine4,
};

static const struct OamData sOamData_JumpMon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_Vine16x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_Vine32x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_Vine32x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnims_Vine_Highest[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_Vine_Higher[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_Vine_High[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_Vine_Low[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_Vine_Lower[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_Vine_Lowest[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_VineTall_Highest[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_VineTall_Higher[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_VineTall_High[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_VineTall_Low[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_VineTall_Lower[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnims_VineTall_Lowest[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Vine[] =
{
    sAnims_Vine_Highest,
    sAnims_Vine_Higher,
    sAnims_Vine_High,
    sAnims_Vine_Low,
    sAnims_Vine_Lower,
    sAnims_Vine_Lowest
};

// Vine 2 needs its own set of anims because the graphic is twice as large
static const union AnimCmd *const sAnims_VineTall[] =
{
    sAnims_VineTall_Highest,
    sAnims_VineTall_Higher,
    sAnims_VineTall_High,
    sAnims_VineTall_Low,
    sAnims_VineTall_Lower,
    sAnims_VineTall_Lowest
};

static const struct SpriteTemplate sSpriteTemplate_Vine1 =
{
    .tileTag = GFXTAG_VINE1,
    .paletteTag = PALTAG_1,
    .oam = &sOamData_Vine16x32,
    .anims = sAnims_Vine,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Vine2 =
{
    .tileTag = GFXTAG_VINE2,
    .paletteTag = PALTAG_1,
    .oam = &sOamData_Vine32x32,
    .anims = sAnims_VineTall,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Vine3 =
{
    .tileTag = GFXTAG_VINE3,
    .paletteTag = PALTAG_1,
    .oam = &sOamData_Vine32x16,
    .anims = sAnims_Vine,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_Vine4 =
{
    .tileTag = GFXTAG_VINE4,
    .paletteTag = PALTAG_1,
    .oam = &sOamData_Vine32x16,
    .anims = sAnims_Vine,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_Star =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnim_Star_Still[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Star_Spinning[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Star[] =
{
    sAnim_Star_Still,
    sAnim_Star_Spinning
};

static const struct SpriteTemplate sSpriteTemplate_Star =
{
    .tileTag = GFXTAG_STAR,
    .paletteTag = PALTAG_1,
    .oam = &sOamData_Star,
    .anims = sAnims_Star,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static void LoadSpriteSheetsAndPalettes(struct PokemonJumpGfx *jumpGfx)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(sCompressedSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sCompressedSpriteSheets[i]);

    for (i = 0; i < ARRAY_COUNT(sSpritePalettes); i++)
        LoadSpritePalette(&sSpritePalettes[i]);

    jumpGfx->vinePalNumDownswing = IndexOfSpritePaletteTag(PALTAG_1);
    jumpGfx->vinePalNumUpswing = IndexOfSpritePaletteTag(PALTAG_2);
}

static void ResetPokeJumpSpriteData(struct Sprite *sprite)
{
    int i;
    for (i = 0; i < (int)ARRAY_COUNT(sprite->data); i++)
        sprite->data[i] = 0;
}

static void CreateJumpMonSprite(struct PokemonJumpGfx *jumpGfx, struct PokemonJump_MonInfo *monInfo, s16 x, s16 y, u8 multiplayerId)
{
    struct SpriteTemplate spriteTemplate;
    struct SpriteSheet spriteSheet;
    struct CompressedSpritePalette spritePalette;
    u8 *buffer;
    u8 *unusedBuffer;
    u8 subpriority;
    u8 spriteId;

    spriteTemplate = sSpriteTemplate_JumpMon;
    buffer = Alloc(0x2000);
    unusedBuffer = Alloc(MON_PIC_SIZE);
    if (multiplayerId == GetPokeJumpMultiplayerId())
        subpriority = 3;
    else
        subpriority = multiplayerId + 4;

    if (buffer && unusedBuffer)
    {
        HandleLoadSpecialPokePic(
            &gMonFrontPicTable[monInfo->species],
            buffer,
            monInfo->species,
            monInfo->personality);

        spriteSheet.data = buffer;
        spriteSheet.tag = multiplayerId;
        spriteSheet.size = MON_PIC_SIZE;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetMonSpritePalFromSpeciesAndPersonality(monInfo->species, monInfo->otId, monInfo->personality);
        spritePalette.tag = multiplayerId;
        LoadCompressedSpritePalette(&spritePalette);

        Free(buffer);
        Free(unusedBuffer);

        spriteTemplate.tileTag += multiplayerId;
        spriteTemplate.paletteTag += multiplayerId;
        spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            jumpGfx->monSprites[multiplayerId] = &gSprites[spriteId];
            jumpGfx->monSpriteSubpriorities[multiplayerId] = subpriority;
            return;
        }
    }

    jumpGfx->monSprites[multiplayerId] = NULL;
}

#define sState data[0]
#define sTimer data[1]
#define sOffset data[7] // Never read

static void DoStarAnim(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    ResetPokeJumpSpriteData(jumpGfx->starSprites[multiplayerId]);
    jumpGfx->starSprites[multiplayerId]->sOffset = jumpGfx->monSprites[multiplayerId] - gSprites;
    jumpGfx->starSprites[multiplayerId]->invisible = FALSE;
    jumpGfx->starSprites[multiplayerId]->y = 96;
    jumpGfx->starSprites[multiplayerId]->callback = SpriteCB_Star;
    StartSpriteAnim(jumpGfx->starSprites[multiplayerId], 1);
}

static void SpriteCB_Star(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (sprite->animEnded)
        {
            sprite->invisible = TRUE;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    case 1:
        sprite->y--;
        sprite->sTimer++;
        if (sprite->y <= 72)
        {
            sprite->y = 72;
            sprite->sState++;
        }
        break;
    case 2:
        if (++sprite->sTimer >= 48)
        {
            sprite->invisible = TRUE;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

#undef sState
#undef sTimer
#undef sOffset

static void Gfx_StartMonHitShake(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    jumpGfx->monSprites[multiplayerId]->callback = SpriteCB_MonHitShake;
    jumpGfx->monSprites[multiplayerId]->y2 = 0;
    ResetPokeJumpSpriteData(jumpGfx->monSprites[multiplayerId]);
}

static bool32 Gfx_IsMonHitShakeActive(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    return jumpGfx->monSprites[multiplayerId]->callback == SpriteCB_MonHitShake;
}

#define sTimer     data[1]
#define sNumShakes data[2]

static void SpriteCB_MonHitShake(struct Sprite *sprite)
{
    if (++sprite->sTimer > 1)
    {
        if (++sprite->sNumShakes & 1)
            sprite->y2 = 2;
        else
            sprite->y2 = -2;

        sprite->sTimer = 0;
    }

    if (sprite->sNumShakes > 12)
    {
        sprite->y2 = 0;
        sprite->callback = SpriteCallbackDummy;
    }
}

#undef sTimer
#undef sNumShakes

static void Gfx_StartMonHitFlash(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    ResetPokeJumpSpriteData(jumpGfx->monSprites[multiplayerId]);
    jumpGfx->monSprites[multiplayerId]->callback = SpriteCB_MonHitFlash;
}

static void Gfx_StopMonHitFlash(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    u16 numPlayers = GetNumPokeJumpPlayers();
    for (i = 0; i < numPlayers; i++)
    {
        if (jumpGfx->monSprites[i]->callback == SpriteCB_MonHitFlash)
        {
            jumpGfx->monSprites[i]->invisible = FALSE;
            jumpGfx->monSprites[i]->callback = SpriteCallbackDummy;
            jumpGfx->monSprites[i]->subpriority = 10;
        }
    }
}

#define sTimer data[0]

static void SpriteCB_MonHitFlash(struct Sprite *sprite)
{
    if (++sprite->sTimer > 3)
    {
        sprite->sTimer = 0;
        sprite->invisible ^= 1;
    }
}

#undef sTimer

static void Gfx_ResetMonSpriteSubpriorities(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    u16 numPlayers = GetNumPokeJumpPlayers();
    for (i = 0; i < numPlayers; i++)
        jumpGfx->monSprites[i]->subpriority = jumpGfx->monSpriteSubpriorities[i];
}

static void Gfx_StartMonIntroBounce(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    ResetPokeJumpSpriteData(jumpGfx->monSprites[multiplayerId]);
    jumpGfx->monSprites[multiplayerId]->callback = SpriteCB_MonIntroBounce;
}

static bool32 Gfx_IsMonIntroBounceActive(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    u16 numPlayers = GetNumPokeJumpPlayers();
    for (i = 0; i < numPlayers; i++)
    {
        if (jumpGfx->monSprites[i]->callback == SpriteCB_MonIntroBounce)
            return TRUE;
    }

    return FALSE;
}

#define sState   data[0]
#define sHopPos  data[1]
#define sNumHops data[2]

static void SpriteCB_MonIntroBounce(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        PlaySE(SE_BIKE_HOP);
        sprite->sHopPos = 0;
        sprite->sState++;
        // fall through
    case 1:
        sprite->sHopPos += 4;
        if (sprite->sHopPos > 127)
            sprite->sHopPos = 0;

        sprite->y2 = -(gSineTable[sprite->sHopPos] >> 3);
        if (sprite->sHopPos == 0)
        {
            if (++sprite->sNumHops < 2)
                sprite->sState = 0;
            else
                sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

#undef sState
#undef sHopPos
#undef sNumHops

static void CreateStarSprite(struct PokemonJumpGfx *jumpGfx, s16 x, s16 y, u8 multiplayerId)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Star, x, y, 1);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].invisible = TRUE;
        jumpGfx->starSprites[multiplayerId] = &gSprites[spriteId];
    }
}

static void CreateVineSprites(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    int count;
    u8 spriteId;

    count = 0;
    for (i = 0; i < VINE_SPRITES_PER_SIDE; i++)
    {
        spriteId = CreateSprite(sSpriteTemplates_Vine[i], sVineXCoords[count], sVineYCoords[i][0], 2);
        jumpGfx->vineSprites[count] = &gSprites[spriteId];
        count++;
    }

    for (i = VINE_SPRITES_PER_SIDE - 1; i >= 0; i--)
    {
        spriteId = CreateSprite(sSpriteTemplates_Vine[i], sVineXCoords[count], sVineYCoords[i][0], 2);
        jumpGfx->vineSprites[count] = &gSprites[spriteId];
        jumpGfx->vineSprites[count]->hFlip = TRUE;
        count++;
    }
}

static void UpdateVineAnim(struct PokemonJumpGfx *jumpGfx, int vineState)
{
    int i, count, palNum;
    int priority;

    if (vineState > VINE_LOWEST)
    {
        // animNums for vine on upswing are same as
        // on downswing but in reverse
        vineState = NUM_VINESTATES - vineState;
        priority = 3; // Set vine behind Pokémon
        palNum = jumpGfx->vinePalNumUpswing;
    }
    else
    {
        priority = 2; // Set vine in front of Pokémon
        palNum = jumpGfx->vinePalNumDownswing;
    }

    count = 0;
    for (i = 0; i < VINE_SPRITES_PER_SIDE; i++)
    {
        jumpGfx->vineSprites[count]->y = sVineYCoords[i][vineState];
        jumpGfx->vineSprites[count]->oam.priority = priority;
        jumpGfx->vineSprites[count]->oam.paletteNum = palNum;
        StartSpriteAnim(jumpGfx->vineSprites[count], vineState);
        count++;
    }

    for (i = VINE_SPRITES_PER_SIDE - 1; i >= 0; i--)
    {
        jumpGfx->vineSprites[count]->y = sVineYCoords[i][vineState];
        jumpGfx->vineSprites[count]->oam.priority = priority;
        jumpGfx->vineSprites[count]->oam.paletteNum = palNum;
        StartSpriteAnim(jumpGfx->vineSprites[count], vineState);
        count++;
    }
}

static void StartPokeJumpCountdown(struct PokemonJumpGfx *jumpGfx)
{
    StartMinigameCountdown(GFXTAG_COUNTDOWN, PALTAG_COUNTDOWN, 120, 80, 0);
    Gfx_ResetMonSpriteSubpriorities(jumpGfx);
}

static bool32 IsPokeJumpCountdownRunning(void)
{
    return IsMinigameCountdownRunning();
}

static void StartPokeJumpGfx(struct PokemonJumpGfx *jumpGfx)
{
    u8 taskId;

    sPokemonJumpGfx = jumpGfx;
    InitPokeJumpGfx(sPokemonJumpGfx);
    taskId = CreateTask(Task_RunPokeJumpGfxFunc, 3);
    sPokemonJumpGfx->taskId = taskId;
    SetWordTaskArg(sPokemonJumpGfx->taskId, 2, (u32) sPokemonJumpGfx);
    SetUpPokeJumpGfxFunc(LoadPokeJumpGfx);
}

static void FreeWindowsAndDigitObj(void)
{
    FreeAllWindowBuffers();
    DigitObjUtil_Free();
}

static void InitPokeJumpGfx(struct PokemonJumpGfx *jumpGfx)
{
    jumpGfx->mainState = 0;
    jumpGfx->funcFinished = FALSE;
    jumpGfx->msgWindowId = WINDOW_NONE;
}

static const u16 sInterface_Pal[] = INCBIN_U16("graphics/pokemon_jump/interface.gbapal");

static const u16 sBg_Pal[] = INCBIN_U16("graphics/pokemon_jump/bg.gbapal");
static const u32 sBg_Gfx[] = INCBIN_U32("graphics/pokemon_jump/bg.4bpp.lz");
static const u32 sBg_Tilemap[] = INCBIN_U32("graphics/pokemon_jump/bg.bin.lz");

static const u16 sVenusaur_Pal[] = INCBIN_U16("graphics/pokemon_jump/venusaur.gbapal");
static const u32 sVenusaur_Gfx[] = INCBIN_U32("graphics/pokemon_jump/venusaur.4bpp.lz");
static const u32 sVenusaur_Tilemap[] = INCBIN_U32("graphics/pokemon_jump/venusaur.bin.lz");

static const u16 sBonuses_Pal[] = INCBIN_U16("graphics/pokemon_jump/bonuses.gbapal");
static const u32 sBonuses_Gfx[] = INCBIN_U32("graphics/pokemon_jump/bonuses.4bpp.lz");
static const u32 sBonuses_Tilemap[] = INCBIN_U32("graphics/pokemon_jump/bonuses.bin.lz");

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = BG_INTERFACE,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = BG_VENUSAUR,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = BG_BONUSES,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = BG_SCENERY,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_POINTS] = {
        .bg = BG_INTERFACE,
        .tilemapLeft = 19,
        .tilemapTop = 0,
        .width = 6,
        .height = 2,
        .paletteNum = 2,
        .baseBlock = 0x13,
    },
    [WIN_TIMES] = {
        .bg = BG_INTERFACE,
        .tilemapLeft = 8,
        .tilemapTop = 0,
        .width = 6,
        .height = 2,
        .paletteNum = 2,
        .baseBlock = 0x1F,
    },
    DUMMY_WIN_TEMPLATE,
};

struct
{
    int id;
    void (*func)(void);
} static const sPokeJumpGfxFuncs[] =
{
    {GFXFUNC_LOAD,                 LoadPokeJumpGfx}, // Element not used, LoadPokeJumpGfx is passed directly to SetUpPokeJumpGfxFunc
    {GFXFUNC_SHOW_NAMES,           PrintPlayerNamesNoHighlight},
    {GFXFUNC_SHOW_NAMES_HIGHLIGHT, PrintPlayerNamesWithHighlight},
    {GFXFUNC_ERASE_NAMES,          ErasePlayerNames},
    {GFXFUNC_MSG_PLAY_AGAIN,       Msg_WantToPlayAgain},
    {GFXFUNC_MSG_SAVING,           Msg_SavingDontTurnOff},
    {GFXFUNC_ERASE_MSG,            EraseMessage},
    {GFXFUNC_MSG_PLAYER_DROPPED,   Msg_SomeoneDroppedOut},
    {GFXFUNC_COUNTDOWN,            DoPokeJumpCountdown},
    {GFXFUNC_MSG_COMM_STANDBY,     Msg_CommunicationStandby},
};

static void SetUpPokeJumpGfxFuncById(int id)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(sPokeJumpGfxFuncs); i++)
    {
        if (sPokeJumpGfxFuncs[i].id == id)
            SetUpPokeJumpGfxFunc(sPokeJumpGfxFuncs[i].func);
    }
}

static bool32 IsPokeJumpGfxFuncFinished(void)
{
    return (sPokemonJumpGfx->funcFinished != TRUE);
}

static void SetUpPokeJumpGfxFunc(void (*func)(void))
{
    SetWordTaskArg(sPokemonJumpGfx->taskId, 0, (u32) func);
    sPokemonJumpGfx->mainState = 0;
    sPokemonJumpGfx->funcFinished = FALSE;
}

static void Task_RunPokeJumpGfxFunc(u8 taskId)
{
    if (!sPokemonJumpGfx->funcFinished)
    {
        // Read the function set in the data by SetUpPokeJumpGfxFunc
        void (*func)(void) = (void *)(GetWordTaskArg(taskId, 0));

        func();
    }
}

static void LoadPokeJumpGfx(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        InitWindows(sWindowTemplates);
        ResetTempTileDataBuffers();
        LoadSpriteSheetsAndPalettes(sPokemonJumpGfx);
        InitDigitPrinters();
        LoadPalette(sBg_Pal, 0, 0x20);
        DecompressAndCopyTileDataToVram(BG_SCENERY, sBg_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_SCENERY, sBg_Tilemap, 0, 0, 1);
        LoadPalette(sVenusaur_Pal, 0x30, 0x20);
        DecompressAndCopyTileDataToVram(BG_VENUSAUR, sVenusaur_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_VENUSAUR, sVenusaur_Tilemap, 0, 0, 1);
        LoadPalette(sBonuses_Pal, 0x10, 0x20);
        DecompressAndCopyTileDataToVram(BG_BONUSES, sBonuses_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BONUSES, sBonuses_Tilemap, 0, 0, 1);
        LoadPalette(sInterface_Pal, 0x20, 0x20);
        SetBgTilemapBuffer(BG_INTERFACE, sPokemonJumpGfx->tilemapBuffer);
        FillBgTilemapBufferRect_Palette0(BG_INTERFACE, 0, 0, 0, 0x20, 0x20);
        PrintScoreSuffixes();
        PrintScore(0);
        LoadUserWindowBorderGfxOnBg(0, 1, 0xE0);
        CopyBgTilemapBufferToVram(BG_INTERFACE);
        CopyBgTilemapBufferToVram(BG_VENUSAUR);
        CopyBgTilemapBufferToVram(BG_BONUSES);
        ResetBgPositions();
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            CreateJumpMonSprites();
            CreateVineSprites(sPokemonJumpGfx);
            UpdateVineAnim(sPokemonJumpGfx, VINE_UPSWING_LOWER);
            ShowBg(BG_SCENERY);
            ShowBg(BG_INTERFACE);
            ShowBg(BG_VENUSAUR);
            HideBg(BG_BONUSES);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void PrintPlayerNamesNoHighlight(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        AddPlayerNameWindows();
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PrintPokeJumpPlayerNames(FALSE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            DrawPlayerNameWindows();
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void PrintPlayerNamesWithHighlight(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        AddPlayerNameWindows();
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PrintPokeJumpPlayerNames(TRUE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            DrawPlayerNameWindows();
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void ErasePlayerNames(void)
{
    int i, numPlayers;

    numPlayers = GetNumPokeJumpPlayers();
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        for (i = 0; i < numPlayers; i++)
            ClearWindowTilemap(sPokemonJumpGfx->nameWindowIds[i]);

        CopyBgTilemapBufferToVram(BG_INTERFACE);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            for (i = 0; i < numPlayers; i++)
                RemoveWindow(sPokemonJumpGfx->nameWindowIds[i]);

            sPokemonJumpGfx->funcFinished = TRUE;
        }
        break;
    }
}

static void Msg_WantToPlayAgain(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(1, 8, 20, 2);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_WantToPlayAgain2, 0, 1, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter(sPokemonJumpGfx->msgWindowId, 1, 14);
            CreatePokeJumpYesNoMenu(23, 7, 0);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void Msg_SavingDontTurnOff(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(2, 7, 26, 4);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_SavingDontTurnOffPower, 0, 1, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter(sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void EraseMessage(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        ClearMessageWindow();
        EraseYesNoWindow();
        CopyBgTilemapBufferToVram(BG_INTERFACE);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!RemoveMessageWindow() && !IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void Msg_SomeoneDroppedOut(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(2, 8, 22, 4);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_SomeoneDroppedOut2, 0, 1, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter(sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void Msg_CommunicationStandby(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(7, 10, 16, 2);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_CommunicationStandby4, 0, 1, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter(sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void DoPokeJumpCountdown(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        StartPokeJumpCountdown(sPokemonJumpGfx);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsPokeJumpCountdownRunning())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

static void SetUpResetVineGfx(void)
{
    sPokemonJumpGfx->resetVineState = 0;
    sPokemonJumpGfx->resetVineTimer = 0;
    sPokemonJumpGfx->vineState = VINE_UPSWING_LOWER;
    UpdateVineSwing(sPokemonJumpGfx->vineState);
}

static bool32 ResetVineGfx(void)
{
    switch (sPokemonJumpGfx->resetVineState)
    {
    case 0:
        sPokemonJumpGfx->resetVineTimer++;
        if (sPokemonJumpGfx->resetVineTimer > 10)
        {
            sPokemonJumpGfx->resetVineTimer = 0;
            sPokemonJumpGfx->vineState++;
            if (sPokemonJumpGfx->vineState >= NUM_VINESTATES)
            {
                sPokemonJumpGfx->vineState = VINE_HIGHEST;
                sPokemonJumpGfx->resetVineState++;
            }
        }
        UpdateVineSwing(sPokemonJumpGfx->vineState);
        if (sPokemonJumpGfx->vineState != VINE_UPSWING_LOW)
            break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

static void PrintPrizeMessage(u16 itemId, u16 quantity)
{
    CopyItemNameHandlePlural(itemId, sPokemonJumpGfx->itemName, quantity);
    ConvertIntToDecimalStringN(sPokemonJumpGfx->itemQuantityStr, quantity, STR_CONV_MODE_LEFT_ALIGN, 1);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sPokemonJumpGfx->itemQuantityStr);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(sPokemonJumpGfx->prizeMsg, gText_AwesomeWonF701F700);
    sPokemonJumpGfx->msgWindowId = AddMessageWindow(4, 8, 22, 4);
    AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, sPokemonJumpGfx->prizeMsg, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
    sPokemonJumpGfx->fanfare = MUS_LEVEL_UP;
    sPokemonJumpGfx->msgWindowState = 0;
}

static void PrintPrizeFilledBagMessage(u16 itemId)
{
    CopyItemName(itemId, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(sPokemonJumpGfx->prizeMsg, gText_FilledStorageSpace2);
    sPokemonJumpGfx->msgWindowId = AddMessageWindow(4, 8, 22, 4);
    AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, sPokemonJumpGfx->prizeMsg, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
    sPokemonJumpGfx->fanfare = MUS_DUMMY;
    sPokemonJumpGfx->msgWindowState = 0;
}

static void PrintNoRoomForPrizeMessage(u16 itemId)
{
    CopyItemName(itemId, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(sPokemonJumpGfx->prizeMsg, gText_CantHoldMore);
    sPokemonJumpGfx->msgWindowId = AddMessageWindow(4, 9, 22, 2);
    AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, sPokemonJumpGfx->prizeMsg, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
    sPokemonJumpGfx->fanfare = MUS_DUMMY;
    sPokemonJumpGfx->msgWindowState = 0;
}

static bool32 DoPrizeMessageAndFanfare(void)
{
    switch (sPokemonJumpGfx->msgWindowState)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter(sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->msgWindowState++;
        }
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            break;
        if (sPokemonJumpGfx->fanfare == MUS_DUMMY)
        {
            sPokemonJumpGfx->msgWindowState += 2;
            return FALSE;
        }
        PlayFanfare(sPokemonJumpGfx->fanfare);
        sPokemonJumpGfx->msgWindowState++;
    case 2:
        if (!IsFanfareTaskInactive())
            break;
        sPokemonJumpGfx->msgWindowState++;
    case 3:
        return FALSE;
    }

    return TRUE;
}

static void ClearMessageWindow(void)
{
    if (sPokemonJumpGfx->msgWindowId != WINDOW_NONE)
    {
        rbox_fill_rectangle(sPokemonJumpGfx->msgWindowId);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_MAP);
        sPokemonJumpGfx->msgWindowState = 0;
    }
}

static bool32 RemoveMessageWindow(void)
{
    if (sPokemonJumpGfx->msgWindowId == WINDOW_NONE)
        return FALSE;

    switch (sPokemonJumpGfx->msgWindowState)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            RemoveWindow(sPokemonJumpGfx->msgWindowId);
            sPokemonJumpGfx->msgWindowId = WINDOW_NONE;
            sPokemonJumpGfx->msgWindowState++;
        }
        else
            break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

static s8 HandlePlayAgainInput(void)
{
    return Menu_ProcessInputNoWrapClearOnChoose();
}

static u32 AddMessageWindow(u32 left, u32 top, u32 width, u32 height)
{
    u32 windowId;
    struct WindowTemplate window;

    window.bg = BG_INTERFACE;
    window.tilemapLeft = left;
    window.tilemapTop = top;
    window.width = width;
    window.height = height;
    window.paletteNum = 0xF;
    window.baseBlock = 0x43;

    windowId = AddWindow(&window);
    FillWindowPixelBuffer(windowId, 0x11);
    return windowId;
}

static void CreatePokeJumpYesNoMenu(u16 left, u16 top, u8 cursorPos)
{
    struct WindowTemplate window;
    u8 a = cursorPos;

    window.bg = BG_INTERFACE;
    window.tilemapLeft = left;
    window.tilemapTop = top;
    window.width = 6;
    window.height = 4;
    window.paletteNum = 2;
    window.baseBlock = 0x2B;

    CreateYesNoMenu(&window, 1, 0xD, a);
}

// "Points" for jump score and "times" for number of jumps in a row
static void PrintScoreSuffixes(void)
{
    u8 color[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

    PutWindowTilemap(WIN_POINTS);
    PutWindowTilemap(WIN_TIMES);
    FillWindowPixelBuffer(WIN_POINTS, 0);
    FillWindowPixelBuffer(WIN_TIMES, 0);
    AddTextPrinterParameterized3(WIN_POINTS, FONT_SMALL, 0, 1, color, 0, gText_SpacePoints2);
    AddTextPrinterParameterized3(WIN_TIMES, FONT_SMALL, 0, 1, color, 0, gText_SpaceTimes3);
}

// The venusaurs in the background are actually an empty 256x512 bg with 3 pairs of venusaurs on it.
// The below array is used to get values for where to set the bg Y to show the corresponding
// venusaur pair in their state of swinging the vine rope
// NEUTRAL/DOWN/UP refers to which direction the Venusaur is facing as it swings the vine
enum {
    VENUSAUR_NEUTRAL,
    VENUSAUR_DOWN,
    VENUSAUR_UP,
};

static const u8 sVenusaurStates[] = {
    [VINE_HIGHEST]          = VENUSAUR_UP,
    [VINE_DOWNSWING_HIGHER] = VENUSAUR_UP,
    [VINE_DOWNSWING_HIGH]   = VENUSAUR_NEUTRAL,
    [VINE_DOWNSWING_LOW]    = VENUSAUR_NEUTRAL,
    [VINE_DOWNSWING_LOWER]  = VENUSAUR_DOWN,
    [VINE_LOWEST]           = VENUSAUR_DOWN,
    [VINE_UPSWING_LOWER]    = VENUSAUR_DOWN,
    [VINE_UPSWING_LOW]      = VENUSAUR_NEUTRAL,
    [VINE_UPSWING_HIGH]     = VENUSAUR_NEUTRAL,
    [VINE_UPSWING_HIGHER]   = VENUSAUR_UP,
};

static const struct CompressedSpriteSheet sSpriteSheet_Digits = {gMinigameDigits_Gfx, 0, TAG_DIGITS};
static const struct SpritePalette sSpritePalette_Digits = {gMinigameDigits_Pal, TAG_DIGITS};

static const u16 sPlayerNameWindowCoords_2Players[] = {
     6, 8,
    16, 8
};
static const u16 sPlayerNameWindowCoords_3Players[] = {
     6, 8,
    11, 6,
    16, 8
};
static const u16 sPlayerNameWindowCoords_4Players[] = {
     2, 6,
     6, 8,
    16, 8,
    20, 6
};
static const u16 sPlayerNameWindowCoords_5Players[] = {
     2, 6,
     6, 8,
    11, 6,
    16, 8,
    20, 6
};

static const u16 *const sPlayerNameWindowCoords[MAX_RFU_PLAYERS - 1] =
{
    sPlayerNameWindowCoords_2Players,
    sPlayerNameWindowCoords_3Players,
    sPlayerNameWindowCoords_4Players,
    sPlayerNameWindowCoords_5Players,
};

static const s16 sMonXCoords_2Players[] = {88, 152};
static const s16 sMonXCoords_3Players[] = {88, 120, 152};
static const s16 sMonXCoords_4Players[] = {56, 88, 152, 184};
static const s16 sMonXCoords_5Players[] = {56, 88, 120, 152, 184};

static const s16 *const sMonXCoords[MAX_RFU_PLAYERS - 1] =
{
    sMonXCoords_2Players,
    sMonXCoords_3Players,
    sMonXCoords_4Players,
    sMonXCoords_5Players,
};

static void CreateJumpMonSprites(void)
{
    int i, y, playersCount = GetNumPokeJumpPlayers();
    const s16 *xCoords = sMonXCoords[playersCount - 2];

    for (i = 0; i < playersCount; i++)
    {
        struct PokemonJump_MonInfo *monInfo = GetMonInfoByMultiplayerId(i);

        y = gMonFrontPicCoords[monInfo->species].y_offset;
        CreateJumpMonSprite(sPokemonJumpGfx, monInfo, *xCoords, y + 112, i);
        CreateStarSprite(sPokemonJumpGfx, *xCoords, 112, i);
        xCoords++;
    }
}

static void SetMonSpriteY(u32 id, s16 y)
{
    sPokemonJumpGfx->monSprites[id]->y2 = y;
}

static void UpdateVineSwing(int vineState)
{
    UpdateVineAnim(sPokemonJumpGfx, vineState);
    ChangeBgY(BG_VENUSAUR, (sVenusaurStates[vineState] * 5) << 13, BG_COORD_SET);
}

static int DoSameJumpTimeBonus(u8 flags)
{
    int i, numPlayers;

    for (i = 0, numPlayers = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (flags & 1)
        {
            // Player was part of a synchronous jump
            // Give a bonus to them
            DoStarAnim(sPokemonJumpGfx, i);
            numPlayers++;
        }
        flags >>= 1;
    }

    ShowBonus(numPlayers - 2);
    return numPlayers;
}

static void InitDigitPrinters(void)
{
    struct DigitObjUtilTemplate template = {
        .shape = SPRITE_SHAPE(8x8),
        .size = SPRITE_SIZE(8x8),
        .strConvMode = 0,
        .priority = 1,
        .oamCount = 5,
        .xDelta = 8,
        .x = 108,
        .y = 6,
        .spriteSheet = (void*) &sSpriteSheet_Digits,
        .spritePal = &sSpritePalette_Digits,
    };

    DigitObjUtil_Init(NUM_WINDOWS);
    DigitObjUtil_CreatePrinter(WIN_POINTS, 0, &template);

    template.oamCount = 4;
    template.x = 30;
    template.y = 6;
    DigitObjUtil_CreatePrinter(WIN_TIMES, 0, &template);
}

static void PrintScore(int num)
{
    DigitObjUtil_PrintNumOn(WIN_POINTS, num);
}

static void PrintJumpsInRow(u16 num)
{
    DigitObjUtil_PrintNumOn(WIN_TIMES, num);
}

static void StartMonHitShake(u8 multiplayerId)
{
    Gfx_StartMonHitShake(sPokemonJumpGfx, multiplayerId);
}

static void StartMonHitFlash(u8 multiplayerId)
{
    Gfx_StartMonHitFlash(sPokemonJumpGfx, multiplayerId);
}

static int IsMonHitShakeActive(int multiplayerId)
{
    return Gfx_IsMonHitShakeActive(sPokemonJumpGfx, multiplayerId);
}

static void StopMonHitFlash(void)
{
    Gfx_StopMonHitFlash(sPokemonJumpGfx);
}

static void ResetMonSpriteSubpriorities(void)
{
    Gfx_ResetMonSpriteSubpriorities(sPokemonJumpGfx);
}

static void StartMonIntroBounce(int multiplayerId)
{
    Gfx_StartMonIntroBounce(sPokemonJumpGfx, multiplayerId);
}

static int IsMonIntroBounceActive(void)
{
    return Gfx_IsMonIntroBounceActive(sPokemonJumpGfx);
}

static void AddPlayerNameWindows(void)
{
    struct WindowTemplate window;
    int i, playersCount = GetNumPokeJumpPlayers();
    const u16 *winCoords = sPlayerNameWindowCoords[playersCount - 2];

    window.bg = BG_INTERFACE;
    window.width = 8;
    window.height = 2;
    window.paletteNum = 2;
    window.baseBlock = 0x2B;

    for (i = 0; i < playersCount; i++)
    {
        window.tilemapLeft = winCoords[0];
        window.tilemapTop = winCoords[1];
        sPokemonJumpGfx->nameWindowIds[i] = AddWindow(&window);
        ClearWindowTilemap(sPokemonJumpGfx->nameWindowIds[i]);
        window.baseBlock += 0x10;
        winCoords += 2;
    }

    CopyBgTilemapBufferToVram(BG_INTERFACE);
}

static void PrintPokeJumpPlayerName(int multiplayerId, u8 bgColor, u8 fgColor, u8 shadow)
{
    u32 x;
    u8 colors[3] = {bgColor, fgColor, shadow};

    FillWindowPixelBuffer(sPokemonJumpGfx->nameWindowIds[multiplayerId], 0);
    x = 64 - GetStringWidth(FONT_NORMAL, GetPokeJumpPlayerName(multiplayerId), -1);
    x /= 2;
    AddTextPrinterParameterized3(sPokemonJumpGfx->nameWindowIds[multiplayerId], FONT_NORMAL, x, 1, colors, TEXT_SKIP_DRAW, GetPokeJumpPlayerName(multiplayerId));
    CopyWindowToVram(sPokemonJumpGfx->nameWindowIds[multiplayerId], COPYWIN_GFX);
}

static void PrintPokeJumpPlayerNames(bool32 highlightSelf)
{
    int i, multiplayerId, playersCount = GetNumPokeJumpPlayers();

    if (!highlightSelf)
    {
        for (i = 0; i < playersCount; i++)
            PrintPokeJumpPlayerName(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY);
    }
    else
    {
        // Highlight own name
        multiplayerId = GetPokeJumpMultiplayerId();
        for (i = 0; i < playersCount; i++)
        {
            if (multiplayerId != i)
                PrintPokeJumpPlayerName(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY);
            else
                PrintPokeJumpPlayerName(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED);
        }
    }
}

static void DrawPlayerNameWindows(void)
{
    int i, playersCount = GetNumPokeJumpPlayers();

    for (i = 0; i < playersCount; i++)
        PutWindowTilemap(sPokemonJumpGfx->nameWindowIds[i]);
    CopyBgTilemapBufferToVram(BG_INTERFACE);
}

static void ShowBonus(u8 bonusId)
{
    sPokemonJumpGfx->bonusTimer = 0;
    ChangeBgX(BG_BONUSES, (bonusId / 2) * 256 * 256, BG_COORD_SET);
    ChangeBgY(BG_BONUSES, (((bonusId % 2) * 256) - 40) * 256, BG_COORD_SET);
    ShowBg(BG_BONUSES);
    CreateTask(Task_UpdateBonus, 4);
}

static bool32 UpdateBonus(void)
{
    if (sPokemonJumpGfx->bonusTimer >= 32)
    {
        return FALSE;
    }
    else
    {
        ChangeBgY(BG_BONUSES, 128, BG_COORD_ADD);
        if (++sPokemonJumpGfx->bonusTimer >= 32)
            HideBg(BG_BONUSES);
        return TRUE;
    }
}

static void Task_UpdateBonus(u8 taskId)
{
    if (!UpdateBonus())
        DestroyTask(taskId);
}

struct MonInfoPacket
{
    u8 id;
    u16 species;
    u32 personality;
    u32 otId;
};

static void SendPacket_MonInfo(struct PokemonJump_MonInfo *monInfo)
{
    struct MonInfoPacket packet;
    packet.id = PACKET_MON_INFO,
    packet.species = monInfo->species,
    packet.otId = monInfo->otId,
    packet.personality = monInfo->personality,
    Rfu_SendPacket(&packet);
}

static bool32 RecvPacket_MonInfo(int multiplayerId, struct PokemonJump_MonInfo *monInfo)
{
    struct MonInfoPacket packet;

    if ((gRecvCmds[multiplayerId][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id == PACKET_MON_INFO)
    {
        monInfo->species = packet.species;
        monInfo->otId = packet.otId;
        monInfo->personality = packet.personality;
        return TRUE;
    }

    return FALSE;
}

struct UnusedPacket
{
    u8 id;
    u32 data;
    u32 filler;
};

// Data packet that's never sent
// No function to read it either
static void SendPacket_Unused(u32 data)
{
    struct UnusedPacket packet;
    packet.id = PACKET_UNUSED;
    packet.data = data;
    Rfu_SendPacket(&packet);
}

struct LeaderStatePacket
{
    u8 id;
    u8 funcId;
    u8 monState;
    u8 receivedBonusFlags:5; // 1 bit for each player (MAX_RFU_PLAYERS)
    u8 jumpState:3;
    u16 jumpTimeStart;
    u16 vineTimer;
    u32 jumpsInRow:15;
    u32 jumpScore:17;
};

static void SendPacket_LeaderState(struct PokemonJump_Player *player, struct PokemonJump_CommData *comm)
{
    struct LeaderStatePacket packet;
    packet.id = PACKET_LEADER_STATE;
    packet.jumpScore = comm->jumpScore;
    packet.receivedBonusFlags = comm->receivedBonusFlags;
    packet.funcId = comm->funcId;
    packet.vineTimer = comm->data;
    packet.jumpsInRow = comm->jumpsInRow;
    packet.monState = player->monState;
    packet.jumpState = player->jumpState;
    packet.jumpTimeStart = player->jumpTimeStart;
    Rfu_SendPacket(&packet);
}

// Used by group members to read the state of the group leader
static bool32 RecvPacket_LeaderState(struct PokemonJump_Player *player, struct PokemonJump_CommData *comm)
{
    struct LeaderStatePacket packet;

    if ((gRecvCmds[0][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[0][1], sizeof(packet));
    if (packet.id != PACKET_LEADER_STATE)
        return FALSE;

    comm->jumpScore = packet.jumpScore;
    comm->receivedBonusFlags = packet.receivedBonusFlags;
    comm->funcId = packet.funcId;
    comm->data = packet.vineTimer;
    comm->jumpsInRow = packet.jumpsInRow;
    player->monState = packet.monState;
    player->jumpState = packet.jumpState;
    player->jumpTimeStart = packet.jumpTimeStart;
    return TRUE;
}

struct MemberStatePacket
{
    u8 id;
    u8 monState;
    u8 jumpState;
    bool8 funcFinished;
    u16 jumpTimeStart;
    u8 funcId;
    u16 playAgainState;
};

static void SendPacket_MemberState(struct PokemonJump_Player *player, u8 funcId, u16 playAgainState)
{
    struct MemberStatePacket packet;
    packet.id = PACKET_MEMBER_STATE;
    packet.monState = player->monState;
    packet.jumpState = player->jumpState;
    packet.funcFinished = player->funcFinished;
    packet.jumpTimeStart = player->jumpTimeStart;
    packet.funcId = funcId;
    packet.playAgainState = playAgainState;
    Rfu_SendPacket(&packet);
}

// Used by the group leader to read the state of group members
static bool32 RecvPacket_MemberStateToLeader(struct PokemonJump_Player *player, int multiplayerId, u8 *funcId, u16 *playAgainState)
{
    struct MemberStatePacket packet;

    if ((gRecvCmds[multiplayerId][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id != PACKET_MEMBER_STATE)
        return FALSE;

    player->monState = packet.monState;
    player->jumpState = packet.jumpState;
    player->funcFinished = packet.funcFinished;
    player->jumpTimeStart = packet.jumpTimeStart;
    *funcId = packet.funcId;
    *playAgainState = packet.playAgainState;
    return TRUE;
}

// Used by group members to read the state of other group members
static bool32 RecvPacket_MemberStateToMember(struct PokemonJump_Player *player, int multiplayerId)
{
    struct MemberStatePacket packet;

    if ((gRecvCmds[multiplayerId][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id != PACKET_MEMBER_STATE)
        return FALSE;

    player->monState = packet.monState;
    player->jumpState = packet.jumpState;
    player->funcFinished = packet.funcFinished;
    player->jumpTimeStart = packet.jumpTimeStart;
    return TRUE;
}

static struct PokemonJumpRecords *GetPokeJumpRecords(void)
{
    return &gSaveBlock2Ptr->pokeJump;
}

void ResetPokemonJumpRecords(void)
{
    struct PokemonJumpRecords *records = GetPokeJumpRecords();
    records->jumpsInRow = 0;
    records->bestJumpScore = 0;
    records->excellentsInRow = 0;
    records->gamesWithMaxPlayers = 0;
    records->unused2 = 0;
    records->unused1 = 0;
}

static bool32 TryUpdateRecords(u32 jumpScore, u16 jumpsInRow, u16 excellentsInRow)
{
    struct PokemonJumpRecords *records = GetPokeJumpRecords();
    bool32 newRecord = FALSE;

    if (records->bestJumpScore < jumpScore && jumpScore <= MAX_JUMP_SCORE)
        records->bestJumpScore = jumpScore, newRecord = TRUE;
    if (records->jumpsInRow < jumpsInRow && jumpsInRow <= MAX_JUMPS)
        records->jumpsInRow = jumpsInRow, newRecord = TRUE;
    if (records->excellentsInRow < excellentsInRow && excellentsInRow <= MAX_JUMPS)
        records->excellentsInRow = excellentsInRow, newRecord = TRUE;

    return newRecord;
}

static void IncrementGamesWithMaxPlayers(void)
{
    struct PokemonJumpRecords *records = GetPokeJumpRecords();
    if (records->gamesWithMaxPlayers < 9999)
        records->gamesWithMaxPlayers++;
}

void ShowPokemonJumpRecords(void)
{
    u8 taskId = CreateTask(Task_ShowPokemonJumpRecords, 0);
    Task_ShowPokemonJumpRecords(taskId);
}

static const struct WindowTemplate sWindowTemplate_Records =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 9,
    .paletteNum = 15,
    .baseBlock = 0x1,
};

static const u8 *const sRecordsTexts[] = {gText_JumpsInARow, gText_BestScore2, gText_ExcellentsInARow};

#define tState data[0]
#define tWindowId data[1]

static void Task_ShowPokemonJumpRecords(u8 taskId)
{
    struct WindowTemplate window;
    int i, width, widthCurr;
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        window = sWindowTemplate_Records;
        width = GetStringWidth(FONT_NORMAL, gText_PkmnJumpRecords, 0);
        for (i = 0; i < ARRAY_COUNT(sRecordsTexts); i++)
        {
            widthCurr = GetStringWidth(FONT_NORMAL, sRecordsTexts[i], 0) + 38;
            if (widthCurr > width)
                width = widthCurr;
        }
        width = (width + 7) / 8;
        if (width & 1)
            width++;
        window.tilemapLeft = (30 - width) / 2;
        window.width = width;
        tWindowId = AddWindow(&window);
        PrintRecordsText(tWindowId, width);
        CopyWindowToVram(tWindowId, COPYWIN_FULL);
        tState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            tState++;
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            rbox_fill_rectangle(tWindowId);
            CopyWindowToVram(tWindowId, COPYWIN_MAP);
            tState++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            RemoveWindow(tWindowId);
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
        break;
    }
}

#undef tState
#undef tWindowId

static void PrintRecordsText(u16 windowId, int width)
{
    int i, x;
    int recordNums[3];
    struct PokemonJumpRecords *records = GetPokeJumpRecords();
    recordNums[0] = records->jumpsInRow;
    recordNums[1] = records->bestJumpScore;
    recordNums[2] = records->excellentsInRow;

    LoadUserWindowBorderGfx_(windowId, 0x21D, 0xD0);
    DrawTextBorderOuter(windowId, 0x21D, 0xD);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_PkmnJumpRecords, GetStringCenterAlignXOffset(FONT_NORMAL, gText_PkmnJumpRecords, width * 8), 1, TEXT_SKIP_DRAW, NULL);
    for (i = 0; i < ARRAY_COUNT(sRecordsTexts); i++)
    {
        AddTextPrinterParameterized(windowId, FONT_NORMAL, sRecordsTexts[i], 0, 25 + (i * 16), TEXT_SKIP_DRAW, NULL);
        ConvertIntToDecimalStringN(gStringVar1, recordNums[i], STR_CONV_MODE_LEFT_ALIGN, 5);
        TruncateToFirstWordOnly(gStringVar1);
        x = (width * 8) - GetStringWidth(FONT_NORMAL, gStringVar1, 0);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar1, x, 25 + (i * 16), TEXT_SKIP_DRAW, NULL);
    }
    PutWindowTilemap(windowId);
}

static void TruncateToFirstWordOnly(u8 *str)
{
    for (;*str != EOS; str++)
    {
        if (*str == CHAR_SPACE)
        {
            *str = EOS;
            break;
        }
    }
}
