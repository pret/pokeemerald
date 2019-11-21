#include "global.h"
#include "apprentice.h"
#include "battle.h"
#include "battle_tower.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "new_game.h"
#include "party_menu.h"
#include "random.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "constants/battle_frontier.h"
#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/moves.h"

/* Summary of Apprentice, because (as of writing at least) its not very well documented online
 *
 * ## Basic info
 * In the Battle Tower lobby there is an NPC which asks to be taught by the player
 * They can be any 1 of 16 NPC trainers, each with their own name, class, and set of possible party species
 * They ask the player a series of questions once per day, and eventually depart the lobby to be replaced by a new Apprentice
 *
 * ## Initial Questions
 * The first question they always ask is a request to be taught, which cannot be rejected
 * The second question (which follows immediately after) is whether they should participate in Battle Tower Lv 50 or Open Lv
 * After these opening questions they always ask the player to choose between 2 mons, which they repeat 3 times
 *
 * ## Random Questions
 * After choosing 3 mons for them, the Apprentice will randomly ask between 1 and 8 questions of 4 different types, as follows
 * - Asking which mon to lead with, which they will only ask at most once
 * - Asking which move a mon should use, which they will ask at most 5 times
 * - Asking what held item to give to a mon, which they will ask at most 3 times (once for each mon)
 * - Asking what they should say when they win a battle, which will always be their final question before departing
 * 
 * ## After departing
 * After telling them what they should say when they win a battle they will leave the lobby for a final time
 * They will then be replaced by a new random Apprentice (they can repeat)
 * Up to 4 old Apprentices are saved and can be encountered (or partnered with) during challenges of the mode they were told to battle in
 * They can also be record mixed to and from other Emerald games
 * Old/record mixed Apprentices are stored in struct Apprentice apprentices of SaveBlock2
 *   and the current Apprentice is stored in struct PlayersApprentice playerApprentice of SaveBlock2
 */

#define PLAYER_APPRENTICE gSaveBlock2Ptr->playerApprentice
#define CURRENT_QUESTION_NUM  PLAYER_APPRENTICE.questionsAnswered - NUM_WHICH_MON_QUESTIONS

struct ApprenticePartyMovesData
{
    u8 moveCounter;
    u16 moves[MULTI_PARTY_SIZE][NUM_WHICH_MOVE_QUESTIONS];
    u8 moveSlots[MULTI_PARTY_SIZE][NUM_WHICH_MOVE_QUESTIONS];
};

struct ApprenticeQuestionData
{
    u16 speciesId;
    u16 altSpeciesId;
    u16 moveId1;
    u16 moveId2;
};

// data/text/apprentice.inc
extern const u8 gText_ApprenticePleaseTeach0[];
extern const u8 gText_ApprenticePleaseTeach1[];
extern const u8 gText_ApprenticePleaseTeach2[];
extern const u8 gText_ApprenticePleaseTeach3[];
extern const u8 gText_ApprenticePleaseTeach4[];
extern const u8 gText_ApprenticePleaseTeach5[];
extern const u8 gText_ApprenticePleaseTeach6[];
extern const u8 gText_ApprenticePleaseTeach7[];
extern const u8 gText_ApprenticePleaseTeach8[];
extern const u8 gText_ApprenticePleaseTeach9[];
extern const u8 gText_ApprenticePleaseTeach10[];
extern const u8 gText_ApprenticePleaseTeach11[];
extern const u8 gText_ApprenticePleaseTeach12[];
extern const u8 gText_ApprenticePleaseTeach13[];
extern const u8 gText_ApprenticePleaseTeach14[];
extern const u8 gText_ApprenticePleaseTeach15[];
extern const u8 gText_ApprenticeRejectTeaching0[];
extern const u8 gText_ApprenticeRejectTeaching1[];
extern const u8 gText_ApprenticeRejectTeaching2[];
extern const u8 gText_ApprenticeRejectTeaching3[];
extern const u8 gText_ApprenticeRejectTeaching4[];
extern const u8 gText_ApprenticeRejectTeaching5[];
extern const u8 gText_ApprenticeRejectTeaching6[];
extern const u8 gText_ApprenticeRejectTeaching7[];
extern const u8 gText_ApprenticeRejectTeaching8[];
extern const u8 gText_ApprenticeRejectTeaching9[];
extern const u8 gText_ApprenticeRejectTeaching10[];
extern const u8 gText_ApprenticeRejectTeaching11[];
extern const u8 gText_ApprenticeRejectTeaching12[];
extern const u8 gText_ApprenticeRejectTeaching13[];
extern const u8 gText_ApprenticeRejectTeaching14[];
extern const u8 gText_ApprenticeRejectTeaching15[];
extern const u8 gText_ApprenticeWhichLevelMode0[];
extern const u8 gText_ApprenticeWhichLevelMode1[];
extern const u8 gText_ApprenticeWhichLevelMode2[];
extern const u8 gText_ApprenticeWhichLevelMode3[];
extern const u8 gText_ApprenticeWhichLevelMode4[];
extern const u8 gText_ApprenticeWhichLevelMode5[];
extern const u8 gText_ApprenticeWhichLevelMode6[];
extern const u8 gText_ApprenticeWhichLevelMode7[];
extern const u8 gText_ApprenticeWhichLevelMode8[];
extern const u8 gText_ApprenticeWhichLevelMode9[];
extern const u8 gText_ApprenticeWhichLevelMode10[];
extern const u8 gText_ApprenticeWhichLevelMode11[];
extern const u8 gText_ApprenticeWhichLevelMode12[];
extern const u8 gText_ApprenticeWhichLevelMode13[];
extern const u8 gText_ApprenticeWhichLevelMode14[];
extern const u8 gText_ApprenticeWhichLevelMode15[];
extern const u8 gText_ApprenticeLevelModeThanks0[];
extern const u8 gText_ApprenticeLevelModeThanks1[];
extern const u8 gText_ApprenticeLevelModeThanks2[];
extern const u8 gText_ApprenticeLevelModeThanks3[];
extern const u8 gText_ApprenticeLevelModeThanks4[];
extern const u8 gText_ApprenticeLevelModeThanks5[];
extern const u8 gText_ApprenticeLevelModeThanks6[];
extern const u8 gText_ApprenticeLevelModeThanks7[];
extern const u8 gText_ApprenticeLevelModeThanks8[];
extern const u8 gText_ApprenticeLevelModeThanks9[];
extern const u8 gText_ApprenticeLevelModeThanks10[];
extern const u8 gText_ApprenticeLevelModeThanks11[];
extern const u8 gText_ApprenticeLevelModeThanks12[];
extern const u8 gText_ApprenticeLevelModeThanks13[];
extern const u8 gText_ApprenticeLevelModeThanks14[];
extern const u8 gText_ApprenticeLevelModeThanks15[];

extern const u8 gText_ApprenticeWhichMon0[];
extern const u8 gText_ApprenticeWhichMon1[];
extern const u8 gText_ApprenticeWhichMon2[];
extern const u8 gText_ApprenticeWhichMon3[];
extern const u8 gText_ApprenticeWhichMon4[];
extern const u8 gText_ApprenticeWhichMon5[];
extern const u8 gText_ApprenticeWhichMon6[];
extern const u8 gText_ApprenticeWhichMon7[];
extern const u8 gText_ApprenticeWhichMon8[];
extern const u8 gText_ApprenticeWhichMon9[];
extern const u8 gText_ApprenticeWhichMon10[];
extern const u8 gText_ApprenticeWhichMon11[];
extern const u8 gText_ApprenticeWhichMon12[];
extern const u8 gText_ApprenticeWhichMon13[];
extern const u8 gText_ApprenticeWhichMon14[];
extern const u8 gText_ApprenticeWhichMon15[];
extern const u8 gText_ApprenticeMonThanks0[];
extern const u8 gText_ApprenticeMonThanks1[];
extern const u8 gText_ApprenticeMonThanks2[];
extern const u8 gText_ApprenticeMonThanks3[];
extern const u8 gText_ApprenticeMonThanks4[];
extern const u8 gText_ApprenticeMonThanks5[];
extern const u8 gText_ApprenticeMonThanks6[];
extern const u8 gText_ApprenticeMonThanks7[];
extern const u8 gText_ApprenticeMonThanks8[];
extern const u8 gText_ApprenticeMonThanks9[];
extern const u8 gText_ApprenticeMonThanks10[];
extern const u8 gText_ApprenticeMonThanks11[];
extern const u8 gText_ApprenticeMonThanks12[];
extern const u8 gText_ApprenticeMonThanks13[];
extern const u8 gText_ApprenticeMonThanks14[];
extern const u8 gText_ApprenticeMonThanks15[];

extern const u8 gText_ApprenticeWhatHeldItem0[];
extern const u8 gText_ApprenticeWhatHeldItem1[];
extern const u8 gText_ApprenticeWhatHeldItem2[];
extern const u8 gText_ApprenticeWhatHeldItem3[];
extern const u8 gText_ApprenticeWhatHeldItem4[];
extern const u8 gText_ApprenticeWhatHeldItem5[];
extern const u8 gText_ApprenticeWhatHeldItem6[];
extern const u8 gText_ApprenticeWhatHeldItem7[];
extern const u8 gText_ApprenticeWhatHeldItem8[];
extern const u8 gText_ApprenticeWhatHeldItem9[];
extern const u8 gText_ApprenticeWhatHeldItem10[];
extern const u8 gText_ApprenticeWhatHeldItem11[];
extern const u8 gText_ApprenticeWhatHeldItem12[];
extern const u8 gText_ApprenticeWhatHeldItem13[];
extern const u8 gText_ApprenticeWhatHeldItem14[];
extern const u8 gText_ApprenticeWhatHeldItem15[];
extern const u8 gText_ApprenticeHoldNothing0[];
extern const u8 gText_ApprenticeHoldNothing1[];
extern const u8 gText_ApprenticeHoldNothing2[];
extern const u8 gText_ApprenticeHoldNothing3[];
extern const u8 gText_ApprenticeHoldNothing4[];
extern const u8 gText_ApprenticeHoldNothing5[];
extern const u8 gText_ApprenticeHoldNothing6[];
extern const u8 gText_ApprenticeHoldNothing7[];
extern const u8 gText_ApprenticeHoldNothing8[];
extern const u8 gText_ApprenticeHoldNothing9[];
extern const u8 gText_ApprenticeHoldNothing10[];
extern const u8 gText_ApprenticeHoldNothing11[];
extern const u8 gText_ApprenticeHoldNothing12[];
extern const u8 gText_ApprenticeHoldNothing13[];
extern const u8 gText_ApprenticeHoldNothing14[];
extern const u8 gText_ApprenticeHoldNothing15[];
extern const u8 gText_ApprenticeThanksNoHeldItem0[];
extern const u8 gText_ApprenticeThanksNoHeldItem1[];
extern const u8 gText_ApprenticeThanksNoHeldItem2[];
extern const u8 gText_ApprenticeThanksNoHeldItem3[];
extern const u8 gText_ApprenticeThanksNoHeldItem4[];
extern const u8 gText_ApprenticeThanksNoHeldItem5[];
extern const u8 gText_ApprenticeThanksNoHeldItem6[];
extern const u8 gText_ApprenticeThanksNoHeldItem7[];
extern const u8 gText_ApprenticeThanksNoHeldItem8[];
extern const u8 gText_ApprenticeThanksNoHeldItem9[];
extern const u8 gText_ApprenticeThanksNoHeldItem10[];
extern const u8 gText_ApprenticeThanksNoHeldItem11[];
extern const u8 gText_ApprenticeThanksNoHeldItem12[];
extern const u8 gText_ApprenticeThanksNoHeldItem13[];
extern const u8 gText_ApprenticeThanksNoHeldItem14[];
extern const u8 gText_ApprenticeThanksNoHeldItem15[];
extern const u8 gText_ApprenticeThanksHeldItem0[];
extern const u8 gText_ApprenticeThanksHeldItem1[];
extern const u8 gText_ApprenticeThanksHeldItem2[];
extern const u8 gText_ApprenticeThanksHeldItem3[];
extern const u8 gText_ApprenticeThanksHeldItem4[];
extern const u8 gText_ApprenticeThanksHeldItem5[];
extern const u8 gText_ApprenticeThanksHeldItem6[];
extern const u8 gText_ApprenticeThanksHeldItem7[];
extern const u8 gText_ApprenticeThanksHeldItem8[];
extern const u8 gText_ApprenticeThanksHeldItem9[];
extern const u8 gText_ApprenticeThanksHeldItem10[];
extern const u8 gText_ApprenticeThanksHeldItem11[];
extern const u8 gText_ApprenticeThanksHeldItem12[];
extern const u8 gText_ApprenticeThanksHeldItem13[];
extern const u8 gText_ApprenticeThanksHeldItem14[];
extern const u8 gText_ApprenticeThanksHeldItem15[];
extern const u8 gText_ApprenticeItemAlreadyRecommended0[];
extern const u8 gText_ApprenticeItemAlreadyRecommended1[];
extern const u8 gText_ApprenticeItemAlreadyRecommended2[];
extern const u8 gText_ApprenticeItemAlreadyRecommended3[];
extern const u8 gText_ApprenticeItemAlreadyRecommended4[];
extern const u8 gText_ApprenticeItemAlreadyRecommended5[];
extern const u8 gText_ApprenticeItemAlreadyRecommended6[];
extern const u8 gText_ApprenticeItemAlreadyRecommended7[];
extern const u8 gText_ApprenticeItemAlreadyRecommended8[];
extern const u8 gText_ApprenticeItemAlreadyRecommended9[];
extern const u8 gText_ApprenticeItemAlreadyRecommended10[];
extern const u8 gText_ApprenticeItemAlreadyRecommended11[];
extern const u8 gText_ApprenticeItemAlreadyRecommended12[];
extern const u8 gText_ApprenticeItemAlreadyRecommended13[];
extern const u8 gText_ApprenticeItemAlreadyRecommended14[];
extern const u8 gText_ApprenticeItemAlreadyRecommended15[];

extern const u8 gText_ApprenticeWhichMove0[];
extern const u8 gText_ApprenticeWhichMove1[];
extern const u8 gText_ApprenticeWhichMove2[];
extern const u8 gText_ApprenticeWhichMove3[];
extern const u8 gText_ApprenticeWhichMove4[];
extern const u8 gText_ApprenticeWhichMove5[];
extern const u8 gText_ApprenticeWhichMove6[];
extern const u8 gText_ApprenticeWhichMove7[];
extern const u8 gText_ApprenticeWhichMove8[];
extern const u8 gText_ApprenticeWhichMove9[];
extern const u8 gText_ApprenticeWhichMove10[];
extern const u8 gText_ApprenticeWhichMove11[];
extern const u8 gText_ApprenticeWhichMove12[];
extern const u8 gText_ApprenticeWhichMove13[];
extern const u8 gText_ApprenticeWhichMove14[];
extern const u8 gText_ApprenticeWhichMove15[];
extern const u8 gText_ApprenticeMoveThanks0[];
extern const u8 gText_ApprenticeMoveThanks1[];
extern const u8 gText_ApprenticeMoveThanks2[];
extern const u8 gText_ApprenticeMoveThanks3[];
extern const u8 gText_ApprenticeMoveThanks4[];
extern const u8 gText_ApprenticeMoveThanks5[];
extern const u8 gText_ApprenticeMoveThanks6[];
extern const u8 gText_ApprenticeMoveThanks7[];
extern const u8 gText_ApprenticeMoveThanks8[];
extern const u8 gText_ApprenticeMoveThanks9[];
extern const u8 gText_ApprenticeMoveThanks10[];
extern const u8 gText_ApprenticeMoveThanks11[];
extern const u8 gText_ApprenticeMoveThanks12[];
extern const u8 gText_ApprenticeMoveThanks13[];
extern const u8 gText_ApprenticeMoveThanks14[];
extern const u8 gText_ApprenticeMoveThanks15[];

extern const u8 gText_ApprenticeWhichMonFirst0[];
extern const u8 gText_ApprenticeWhichMonFirst1[];
extern const u8 gText_ApprenticeWhichMonFirst2[];
extern const u8 gText_ApprenticeWhichMonFirst3[];
extern const u8 gText_ApprenticeWhichMonFirst4[];
extern const u8 gText_ApprenticeWhichMonFirst5[];
extern const u8 gText_ApprenticeWhichMonFirst6[];
extern const u8 gText_ApprenticeWhichMonFirst7[];
extern const u8 gText_ApprenticeWhichMonFirst8[];
extern const u8 gText_ApprenticeWhichMonFirst9[];
extern const u8 gText_ApprenticeWhichMonFirst10[];
extern const u8 gText_ApprenticeWhichMonFirst11[];
extern const u8 gText_ApprenticeWhichMonFirst12[];
extern const u8 gText_ApprenticeWhichMonFirst13[];
extern const u8 gText_ApprenticeWhichMonFirst14[];
extern const u8 gText_ApprenticeWhichMonFirst15[];
extern const u8 gText_ApprenticeMonFirstThanks0[];
extern const u8 gText_ApprenticeMonFirstThanks1[];
extern const u8 gText_ApprenticeMonFirstThanks2[];
extern const u8 gText_ApprenticeMonFirstThanks3[];
extern const u8 gText_ApprenticeMonFirstThanks4[];
extern const u8 gText_ApprenticeMonFirstThanks5[];
extern const u8 gText_ApprenticeMonFirstThanks6[];
extern const u8 gText_ApprenticeMonFirstThanks7[];
extern const u8 gText_ApprenticeMonFirstThanks8[];
extern const u8 gText_ApprenticeMonFirstThanks9[];
extern const u8 gText_ApprenticeMonFirstThanks10[];
extern const u8 gText_ApprenticeMonFirstThanks11[];
extern const u8 gText_ApprenticeMonFirstThanks12[];
extern const u8 gText_ApprenticeMonFirstThanks13[];
extern const u8 gText_ApprenticeMonFirstThanks14[];
extern const u8 gText_ApprenticeMonFirstThanks15[];

extern const u8 gText_ApprenticePickWinSpeech0[];
extern const u8 gText_ApprenticePickWinSpeech1[];
extern const u8 gText_ApprenticePickWinSpeech2[];
extern const u8 gText_ApprenticePickWinSpeech3[];
extern const u8 gText_ApprenticePickWinSpeech4[];
extern const u8 gText_ApprenticePickWinSpeech5[];
extern const u8 gText_ApprenticePickWinSpeech6[];
extern const u8 gText_ApprenticePickWinSpeech7[];
extern const u8 gText_ApprenticePickWinSpeech8[];
extern const u8 gText_ApprenticePickWinSpeech9[];
extern const u8 gText_ApprenticePickWinSpeech10[];
extern const u8 gText_ApprenticePickWinSpeech11[];
extern const u8 gText_ApprenticePickWinSpeech12[];
extern const u8 gText_ApprenticePickWinSpeech13[];
extern const u8 gText_ApprenticePickWinSpeech14[];
extern const u8 gText_ApprenticePickWinSpeech15[];
extern const u8 gText_ApprenticeWinSpeechThanks0[];
extern const u8 gText_ApprenticeWinSpeechThanks1[];
extern const u8 gText_ApprenticeWinSpeechThanks2[];
extern const u8 gText_ApprenticeWinSpeechThanks3[];
extern const u8 gText_ApprenticeWinSpeechThanks4[];
extern const u8 gText_ApprenticeWinSpeechThanks5[];
extern const u8 gText_ApprenticeWinSpeechThanks6[];
extern const u8 gText_ApprenticeWinSpeechThanks7[];
extern const u8 gText_ApprenticeWinSpeechThanks8[];
extern const u8 gText_ApprenticeWinSpeechThanks9[];
extern const u8 gText_ApprenticeWinSpeechThanks10[];
extern const u8 gText_ApprenticeWinSpeechThanks11[];
extern const u8 gText_ApprenticeWinSpeechThanks12[];
extern const u8 gText_ApprenticeWinSpeechThanks13[];
extern const u8 gText_ApprenticeWinSpeechThanks14[];
extern const u8 gText_ApprenticeWinSpeechThanks15[];

extern const u8 gText_ApprenticeChallenge0[];
extern const u8 gText_ApprenticeChallenge1[];
extern const u8 gText_ApprenticeChallenge2[];
extern const u8 gText_ApprenticeChallenge3[];
extern const u8 gText_ApprenticeChallenge4[];
extern const u8 gText_ApprenticeChallenge5[];
extern const u8 gText_ApprenticeChallenge6[];
extern const u8 gText_ApprenticeChallenge7[];
extern const u8 gText_ApprenticeChallenge8[];
extern const u8 gText_ApprenticeChallenge9[];
extern const u8 gText_ApprenticeChallenge10[];
extern const u8 gText_ApprenticeChallenge11[];
extern const u8 gText_ApprenticeChallenge12[];
extern const u8 gText_ApprenticeChallenge13[];
extern const u8 gText_ApprenticeChallenge14[];
extern const u8 gText_ApprenticeChallenge15[];

// IWRAM common
struct ApprenticePartyMovesData *gApprenticePartyMovesData;
struct ApprenticeQuestionData *gApprenticeQuestionData;
void (*gApprenticeFunc)(void);

// This file's functions.
static u16 GetRandomAlternateMove(u8 monId);
static bool8 TrySetMove(u8 monId, u16 moveId);
static void CreateChooseAnswerTask(bool8 noBButton, u8 itemsCount, u8 windowId);
static u8 CreateAndShowWindow(u8 left, u8 top, u8 width, u8 height);
static void RemoveAndHideWindow(u8 windowId);
static void ExecuteFuncAfterButtonPress(void (*func)(void));

static void Script_GivenApprenticeLvlMode(void);
static void Script_SetApprenticeLvlMode(void);
static void Script_SetApprenticeId(void);
static void ShuffleApprenticeSpecies(void);
static void Script_SetRandomQuestionData(void);
static void IncrementQuestionsAnswered(void);
static void IsFinalQuestion(void);
static void Script_CreateApprenticeMenu(void);
static void Script_PrintApprenticeMessage(void);
static void Script_ResetPlayerApprentice(void);
static void GetShouldCheckApprenticeGone(void);
static void ApprenticeGetQuestion(void);
static void GetNumApprenticePartyMonsAssigned(void);
static void SetApprenticePartyMon(void);
static void InitQuestionData(void);
static void FreeQuestionData(void);
static void ApprenticeBufferString(void);
static void SetApprenticeMonMove(void);
static void SetLeadApprenticeMon(void);
static void Script_ApprenticeOpenBagMenu(void);
static void TrySetApprenticeHeldItem(void);
static void SaveApprentice(void);
static void SetSavedApprenticeTrainerGfxId(void);
static void SetPlayerApprenticeTrainerGfxId(void);
static void GetShouldApprenticeLeave(void);
static void ShiftSavedApprentices(void);

// rodata

const struct ApprenticeTrainer gApprentices[NUM_APPRENTICES] =
{
    {
        .name = {_("サダヒロ"), _("ALANN"), _("ALAIN"), _("ADELFO"), _("CLAUS"), _("TEO")},
        .otId = 0xBDC9,
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .species = {SPECIES_BEAUTIFLY, SPECIES_DUSTOX, SPECIES_ILLUMISE, SPECIES_SHIFTRY, SPECIES_BRELOOM, SPECIES_NINJASK, SPECIES_SHEDINJA, SPECIES_PINSIR, SPECIES_HERACROSS, SPECIES_VOLBEAT},
        .id = 0,
        .speechLost = {EC_WORD_NO, EC_WORD_MISTAKE, EC_WORD_EXCL, EC_WORD_I, EC_WORD_LOST, EC_WORD_BADLY},
    },
    {
        .name = {_("ヒロオ"), _("LIONEL"), _("LIONEL"), _("CAIO"), _("LUDWIG"), _("LEO")},
        .otId = 0xCF09,
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .species = {SPECIES_SWELLOW, SPECIES_SWALOT, SPECIES_SHUCKLE, SPECIES_MANECTRIC, SPECIES_TORKOAL, SPECIES_HARIYAMA, SPECIES_MIGHTYENA, SPECIES_LUDICOLO, SPECIES_CRAWDAUNT, SPECIES_WHISCASH},
        .id = 1,
        .speechLost = {EC_WORD_OKAY, EC_WORD_I, EC_WORD_LOST, EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_MASTER},
    },
    {
        .name = {_("ケイジ"), _("SONNY"), _("HERVE"), _("FEDRO"), _("WENZEL"), _("SANTI")},
        .otId = 0x2E34,
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .species = {SPECIES_LINOONE, SPECIES_MIGHTYENA, SPECIES_WHISCASH, SPECIES_ZANGOOSE, SPECIES_SEVIPER, SPECIES_NINETALES, SPECIES_KECLEON, SPECIES_SHUCKLE, SPECIES_MANECTRIC, SPECIES_MACHAMP},
        .id = 2,
        .speechLost = {EC_WORD_I, EC_WORD_WENT, EC_WORD_AND, EC_WORD_LOST, EC_WORD_AWW, EC_WORD_ELLIPSIS},
    },
    {
        .name = {_("ユラ"), _("LAYLA"), _("LAYLA"), _("ASTRID"), _("SONJA"), _("LOLA")},
        .otId = 0x84EF,
        .facilityClass = FACILITY_CLASS_LASS,
        .species = {SPECIES_SWALOT, SPECIES_XATU, SPECIES_ALTARIA, SPECIES_GOLDUCK, SPECIES_FLYGON, SPECIES_ALAKAZAM, SPECIES_GARDEVOIR, SPECIES_WAILORD, SPECIES_GRUMPIG, SPECIES_MIGHTYENA},
        .id = 3,
        .speechLost = {EC_WORD_IS, EC_WORD_THIS, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_QUES, 0xFFFF},
    },
    {
        .name = {_("ヨウカ"), _("MACY"), _("AMELIE"), _("CLEO"), _("MARIA"), _("ELISA")},
        .otId = 0x1E43,
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .species = {SPECIES_WIGGLYTUFF, SPECIES_LINOONE, SPECIES_KINGDRA, SPECIES_DELCATTY, SPECIES_RAICHU, SPECIES_FEAROW, SPECIES_STARMIE, SPECIES_MEDICHAM, SPECIES_SHIFTRY, SPECIES_BEAUTIFLY},
        .id = 4,
        .speechLost = {EC_WORD_THIS, EC_WORD_WON_T, EC_WORD_BE, EC_WORD_HAPPENING, EC_WORD_NEXT, EC_WORD_TIME},
    },
    {
        .name = {_("ヤスシ"), _("DONTE"), _("BRAHIM"), _("GLAUCO"), _("JOSEF"), _("ROQUE")},
        .otId = 0x379F,
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .species = {SPECIES_STARMIE, SPECIES_DODRIO, SPECIES_AGGRON, SPECIES_MAGNETON, SPECIES_MACHAMP, SPECIES_ARMALDO, SPECIES_HERACROSS, SPECIES_NOSEPASS, SPECIES_EXPLOUD, SPECIES_MIGHTYENA},
        .id = 5,
        .speechLost = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_RUN, EC_WORD_BYE_BYE, EC_WORD_EXCL},
    },
    {
        .name = {_("ミサオ"), _("AMIRA"), _("LAURE"), _("DAFNE"), _("AMELIE"), _("LARA")},
        .otId = 0xF555,
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .species = {SPECIES_STARMIE, SPECIES_DODRIO, SPECIES_MAGNETON, SPECIES_MEDICHAM, SPECIES_MIGHTYENA, SPECIES_GLALIE, SPECIES_GOLEM, SPECIES_ELECTRODE, SPECIES_PELIPPER, SPECIES_SHARPEDO},
        .id = 6,
        .speechLost = {EC_WORD_AHAHA, EC_WORD_DEFEATED, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_NOTHING, EC_WORD_EXCL},
    },
    {
        .name = {_("カズサ"), _("KALI"), _("JODIE"), _("ILENIA"), _("KARO"), _("ELSA")},
        .otId = 0x8D26,
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .species = {SPECIES_NINETALES, SPECIES_ALAKAZAM, SPECIES_SCEPTILE, SPECIES_SALAMENCE, SPECIES_GOLDUCK, SPECIES_MAWILE, SPECIES_WEEZING, SPECIES_LANTURN, SPECIES_GARDEVOIR, SPECIES_MILOTIC},
        .id = 7,
        .speechLost = {EC_WORD_YOU_RE, EC_WORD_STRONG, EC_WORD_AREN_T, EC_WORD_YOU, EC_WORD_QUES, 0xFFFF},
    },
    {
        .name = {_("スミレ"), _("ANNIE"), _("ANNIE"), _("IMELDA"), _("INES"), _("ROSA")},
        .otId = 0x800C,
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .species = {SPECIES_SCEPTILE, SPECIES_VILEPLUME, SPECIES_BELLOSSOM, SPECIES_ROSELIA, SPECIES_CORSOLA, SPECIES_FLYGON, SPECIES_BRELOOM, SPECIES_MILOTIC, SPECIES_ALTARIA, SPECIES_CRADILY},
        .id = 8,
        .speechLost = {EC_WORD_WHAT, EC_WORD_TOUGH, EC_WORD_POKEMON, EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_EXCL},
    },
    {
        .name = {_("アキノリ"), _("DILLEN"), _("RENE"), _("INDRO"), _("DETLEF"), _("PEDRO")},
        .otId = 0x469f,
        .facilityClass = FACILITY_CLASS_HIKER,
        .species = {SPECIES_SKARMORY, SPECIES_GOLEM, SPECIES_BLAZIKEN, SPECIES_CAMERUPT, SPECIES_DONPHAN, SPECIES_MUK, SPECIES_SALAMENCE, SPECIES_TROPIUS, SPECIES_SOLROCK, SPECIES_RHYDON},
        .id = 9,
        .speechLost = {EC_WORD_WE, EC_WORD_WERE, EC_WORD_JUST, EC_WORD_SHREDDED, EC_WORD_ELLIPSIS, 0xFFFF},
    },
    {
        .name = {_("トウゾウ"), _("DALLAS"), _("BRUNO"), _("LEARCO"), _("ANSGAR"), _("MANOLO")},
        .otId = 0x71FC,
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .species = {SPECIES_SEAKING, SPECIES_STARMIE, SPECIES_GOLDUCK, SPECIES_TENTACRUEL, SPECIES_OCTILLERY, SPECIES_GOREBYSS, SPECIES_GLALIE, SPECIES_WAILORD, SPECIES_SHARPEDO, SPECIES_KINGDRA},
        .id = 10,
        .speechLost = {EC_WORD_YOUR, EC_WORD_WIN, EC_WORD_ANGERS, EC_WORD_ME, EC_WORD_EXCL, 0xFFFF},
    },
    {
        .name = {_("セイヤ"), _("FRANK"), _("FRANK"), _("OLINDO"), _("FRANK"), _("MAURO")},
        .otId = 0xA39E,
        .facilityClass = FACILITY_CLASS_SAILOR,
        .species = {SPECIES_QUAGSIRE, SPECIES_STARMIE, SPECIES_PELIPPER, SPECIES_CRAWDAUNT, SPECIES_WAILORD, SPECIES_GYARADOS, SPECIES_SWAMPERT, SPECIES_LANTURN, SPECIES_WHISCASH, SPECIES_SHUCKLE},
        .id = 11,
        .speechLost = {EC_WORD_LOSING, EC_WORD_DOESN_T, EC_MOVE(CUT), EC_WORD_ME, EC_WORD_DEEP, EC_WORD_OK_QUES},
    },
    {
        .name = {_("リュウジ"), _("LAMONT"), _("XAV"), _("ORFEO"), _("JÜRGEN"), _("JORGE")},
        .otId = 0xE590,
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .species = {SPECIES_ABSOL, SPECIES_CROBAT, SPECIES_EXPLOUD, SPECIES_MAGNETON, SPECIES_SHARPEDO, SPECIES_MANECTRIC, SPECIES_METAGROSS, SPECIES_ELECTRODE, SPECIES_NOSEPASS, SPECIES_WEEZING},
        .id = 12,
        .speechLost = {EC_WORD_A, EC_WORD_LOSS, EC_WORD_IS, EC_WORD_WHAT, EC_WORD_THIS, EC_WORD_IS},
    },
    {
        .name = {_("カツアキ"), _("TYRESE"), _("ANDY"), _("PARIDE"), _("DAVID"), _("CHICHO")},
        .otId = 0xD018,
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .species = {SPECIES_BLAZIKEN, SPECIES_GOLEM, SPECIES_MACHAMP, SPECIES_RHYDON, SPECIES_HARIYAMA, SPECIES_AGGRON, SPECIES_MEDICHAM, SPECIES_ZANGOOSE, SPECIES_VIGOROTH, SPECIES_SLAKING},
        .id = 13,
        .speechLost = {EC_WORD_I_AM, EC_WORD_TOO_WEAK, EC_WORD_AND, EC_WORD_LOW, EC_WORD_OF, EC_WORD_POWER},
    },
    {
        .name = {_("トシミツ"), _("DANTE"), _("DANTE"), _("RAOUL"), _("LOTHAR"), _("PABLO")},
        .otId = 0xBC75,
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .species = {SPECIES_SCEPTILE, SPECIES_SANDSLASH, SPECIES_FLYGON, SPECIES_CLAYDOL, SPECIES_ARMALDO, SPECIES_CROBAT, SPECIES_CRADILY, SPECIES_SOLROCK, SPECIES_LUNATONE, SPECIES_GOLEM},
        .id = 14,
        .speechLost = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_UNDERSTAND, EC_WORD_WHAT, EC_WORD_IS, EC_WORD_HAPPENING},
    },
    {
        .name = {_("ローウェン"), _("ARTURO"), _("ARTURO"), _("ROMOLO"), _("BRIAN"), _("ARTURO")},
        .otId = 0xFA02,
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .species = {SPECIES_ABSOL, SPECIES_MIGHTYENA, SPECIES_ALAKAZAM, SPECIES_BANETTE, SPECIES_NINETALES, SPECIES_CLAYDOL, SPECIES_MUK, SPECIES_SALAMENCE, SPECIES_WALREIN, SPECIES_DUSCLOPS},
        .id = 15,
        .speechLost = {EC_WORD_THIS, EC_WORD_HAS, EC_WORD_TO, EC_WORD_BE, EC_WORD_A, EC_WORD_LIE},
    },
};

// Sequence of 4 messages for the first meeting with the apprentice
static const u8 *const sApprenticeFirstMeetingTexts[NUM_APPRENTICES][4] =
{
    {gText_ApprenticePleaseTeach0,  gText_ApprenticeRejectTeaching0,  gText_ApprenticeWhichLevelMode0,  gText_ApprenticeLevelModeThanks0},
    {gText_ApprenticePleaseTeach1,  gText_ApprenticeRejectTeaching1,  gText_ApprenticeWhichLevelMode1,  gText_ApprenticeLevelModeThanks1},
    {gText_ApprenticePleaseTeach2,  gText_ApprenticeRejectTeaching2,  gText_ApprenticeWhichLevelMode2,  gText_ApprenticeLevelModeThanks2},
    {gText_ApprenticePleaseTeach3,  gText_ApprenticeRejectTeaching3,  gText_ApprenticeWhichLevelMode3,  gText_ApprenticeLevelModeThanks3},
    {gText_ApprenticePleaseTeach4,  gText_ApprenticeRejectTeaching4,  gText_ApprenticeWhichLevelMode4,  gText_ApprenticeLevelModeThanks4},
    {gText_ApprenticePleaseTeach5,  gText_ApprenticeRejectTeaching5,  gText_ApprenticeWhichLevelMode5,  gText_ApprenticeLevelModeThanks5},
    {gText_ApprenticePleaseTeach6,  gText_ApprenticeRejectTeaching6,  gText_ApprenticeWhichLevelMode6,  gText_ApprenticeLevelModeThanks6},
    {gText_ApprenticePleaseTeach7,  gText_ApprenticeRejectTeaching7,  gText_ApprenticeWhichLevelMode7,  gText_ApprenticeLevelModeThanks7},
    {gText_ApprenticePleaseTeach8,  gText_ApprenticeRejectTeaching8,  gText_ApprenticeWhichLevelMode8,  gText_ApprenticeLevelModeThanks8},
    {gText_ApprenticePleaseTeach9,  gText_ApprenticeRejectTeaching9,  gText_ApprenticeWhichLevelMode9,  gText_ApprenticeLevelModeThanks9},
    {gText_ApprenticePleaseTeach10, gText_ApprenticeRejectTeaching10, gText_ApprenticeWhichLevelMode10, gText_ApprenticeLevelModeThanks10},
    {gText_ApprenticePleaseTeach11, gText_ApprenticeRejectTeaching11, gText_ApprenticeWhichLevelMode11, gText_ApprenticeLevelModeThanks11},
    {gText_ApprenticePleaseTeach12, gText_ApprenticeRejectTeaching12, gText_ApprenticeWhichLevelMode12, gText_ApprenticeLevelModeThanks12},
    {gText_ApprenticePleaseTeach13, gText_ApprenticeRejectTeaching13, gText_ApprenticeWhichLevelMode13, gText_ApprenticeLevelModeThanks13},
    {gText_ApprenticePleaseTeach14, gText_ApprenticeRejectTeaching14, gText_ApprenticeWhichLevelMode14, gText_ApprenticeLevelModeThanks14},
    {gText_ApprenticePleaseTeach15, gText_ApprenticeRejectTeaching15, gText_ApprenticeWhichLevelMode15, gText_ApprenticeLevelModeThanks15},
};

static const u8 *const sApprenticeWhichMonTexts[NUM_APPRENTICES][2] =
{
    {gText_ApprenticeWhichMon0,  gText_ApprenticeMonThanks0},
    {gText_ApprenticeWhichMon1,  gText_ApprenticeMonThanks1},
    {gText_ApprenticeWhichMon2,  gText_ApprenticeMonThanks2},
    {gText_ApprenticeWhichMon3,  gText_ApprenticeMonThanks3},
    {gText_ApprenticeWhichMon4,  gText_ApprenticeMonThanks4},
    {gText_ApprenticeWhichMon5,  gText_ApprenticeMonThanks5},
    {gText_ApprenticeWhichMon6,  gText_ApprenticeMonThanks6},
    {gText_ApprenticeWhichMon7,  gText_ApprenticeMonThanks7},
    {gText_ApprenticeWhichMon8,  gText_ApprenticeMonThanks8},
    {gText_ApprenticeWhichMon9,  gText_ApprenticeMonThanks9},
    {gText_ApprenticeWhichMon10, gText_ApprenticeMonThanks10},
    {gText_ApprenticeWhichMon11, gText_ApprenticeMonThanks11},
    {gText_ApprenticeWhichMon12, gText_ApprenticeMonThanks12},
    {gText_ApprenticeWhichMon13, gText_ApprenticeMonThanks13},
    {gText_ApprenticeWhichMon14, gText_ApprenticeMonThanks14},
    {gText_ApprenticeWhichMon15, gText_ApprenticeMonThanks15},
};

// Sequence of 5 messages for suggesting a held item to the apprentice
static const u8 *const sApprenticeHeldItemTexts[NUM_APPRENTICES][5] =
{
    {gText_ApprenticeWhatHeldItem0,  gText_ApprenticeHoldNothing0,  gText_ApprenticeThanksNoHeldItem0,  gText_ApprenticeThanksHeldItem0,  gText_ApprenticeItemAlreadyRecommended0},
    {gText_ApprenticeWhatHeldItem1,  gText_ApprenticeHoldNothing1,  gText_ApprenticeThanksNoHeldItem1,  gText_ApprenticeThanksHeldItem1,  gText_ApprenticeItemAlreadyRecommended1},
    {gText_ApprenticeWhatHeldItem2,  gText_ApprenticeHoldNothing2,  gText_ApprenticeThanksNoHeldItem2,  gText_ApprenticeThanksHeldItem2,  gText_ApprenticeItemAlreadyRecommended2},
    {gText_ApprenticeWhatHeldItem3,  gText_ApprenticeHoldNothing3,  gText_ApprenticeThanksNoHeldItem3,  gText_ApprenticeThanksHeldItem3,  gText_ApprenticeItemAlreadyRecommended3},
    {gText_ApprenticeWhatHeldItem4,  gText_ApprenticeHoldNothing4,  gText_ApprenticeThanksNoHeldItem4,  gText_ApprenticeThanksHeldItem4,  gText_ApprenticeItemAlreadyRecommended4},
    {gText_ApprenticeWhatHeldItem5,  gText_ApprenticeHoldNothing5,  gText_ApprenticeThanksNoHeldItem5,  gText_ApprenticeThanksHeldItem5,  gText_ApprenticeItemAlreadyRecommended5},
    {gText_ApprenticeWhatHeldItem6,  gText_ApprenticeHoldNothing6,  gText_ApprenticeThanksNoHeldItem6,  gText_ApprenticeThanksHeldItem6,  gText_ApprenticeItemAlreadyRecommended6},
    {gText_ApprenticeWhatHeldItem7,  gText_ApprenticeHoldNothing7,  gText_ApprenticeThanksNoHeldItem7,  gText_ApprenticeThanksHeldItem7,  gText_ApprenticeItemAlreadyRecommended7},
    {gText_ApprenticeWhatHeldItem8,  gText_ApprenticeHoldNothing8,  gText_ApprenticeThanksNoHeldItem8,  gText_ApprenticeThanksHeldItem8,  gText_ApprenticeItemAlreadyRecommended8},
    {gText_ApprenticeWhatHeldItem9,  gText_ApprenticeHoldNothing9,  gText_ApprenticeThanksNoHeldItem9,  gText_ApprenticeThanksHeldItem9,  gText_ApprenticeItemAlreadyRecommended9},
    {gText_ApprenticeWhatHeldItem10, gText_ApprenticeHoldNothing10, gText_ApprenticeThanksNoHeldItem10, gText_ApprenticeThanksHeldItem10, gText_ApprenticeItemAlreadyRecommended10},
    {gText_ApprenticeWhatHeldItem11, gText_ApprenticeHoldNothing11, gText_ApprenticeThanksNoHeldItem11, gText_ApprenticeThanksHeldItem11, gText_ApprenticeItemAlreadyRecommended11},
    {gText_ApprenticeWhatHeldItem12, gText_ApprenticeHoldNothing12, gText_ApprenticeThanksNoHeldItem12, gText_ApprenticeThanksHeldItem12, gText_ApprenticeItemAlreadyRecommended12},
    {gText_ApprenticeWhatHeldItem13, gText_ApprenticeHoldNothing13, gText_ApprenticeThanksNoHeldItem13, gText_ApprenticeThanksHeldItem13, gText_ApprenticeItemAlreadyRecommended13},
    {gText_ApprenticeWhatHeldItem14, gText_ApprenticeHoldNothing14, gText_ApprenticeThanksNoHeldItem14, gText_ApprenticeThanksHeldItem14, gText_ApprenticeItemAlreadyRecommended14},
    {gText_ApprenticeWhatHeldItem15, gText_ApprenticeHoldNothing15, gText_ApprenticeThanksNoHeldItem15, gText_ApprenticeThanksHeldItem15, gText_ApprenticeItemAlreadyRecommended15},
};

static const u8 *const sApprenticeWhichMoveTexts[NUM_APPRENTICES][2] =
{
    {gText_ApprenticeWhichMove0,  gText_ApprenticeMoveThanks0},
    {gText_ApprenticeWhichMove1,  gText_ApprenticeMoveThanks1},
    {gText_ApprenticeWhichMove2,  gText_ApprenticeMoveThanks2},
    {gText_ApprenticeWhichMove3,  gText_ApprenticeMoveThanks3},
    {gText_ApprenticeWhichMove4,  gText_ApprenticeMoveThanks4},
    {gText_ApprenticeWhichMove5,  gText_ApprenticeMoveThanks5},
    {gText_ApprenticeWhichMove6,  gText_ApprenticeMoveThanks6},
    {gText_ApprenticeWhichMove7,  gText_ApprenticeMoveThanks7},
    {gText_ApprenticeWhichMove8,  gText_ApprenticeMoveThanks8},
    {gText_ApprenticeWhichMove9,  gText_ApprenticeMoveThanks9},
    {gText_ApprenticeWhichMove10, gText_ApprenticeMoveThanks10},
    {gText_ApprenticeWhichMove11, gText_ApprenticeMoveThanks11},
    {gText_ApprenticeWhichMove12, gText_ApprenticeMoveThanks12},
    {gText_ApprenticeWhichMove13, gText_ApprenticeMoveThanks13},
    {gText_ApprenticeWhichMove14, gText_ApprenticeMoveThanks14},
    {gText_ApprenticeWhichMove15, gText_ApprenticeMoveThanks15},
};

static const u8 *const sApprenticeWhichMonFirstTexts[NUM_APPRENTICES][2] =
{
    {gText_ApprenticeWhichMonFirst0,  gText_ApprenticeMonFirstThanks0},
    {gText_ApprenticeWhichMonFirst1,  gText_ApprenticeMonFirstThanks1},
    {gText_ApprenticeWhichMonFirst2,  gText_ApprenticeMonFirstThanks2},
    {gText_ApprenticeWhichMonFirst3,  gText_ApprenticeMonFirstThanks3},
    {gText_ApprenticeWhichMonFirst4,  gText_ApprenticeMonFirstThanks4},
    {gText_ApprenticeWhichMonFirst5,  gText_ApprenticeMonFirstThanks5},
    {gText_ApprenticeWhichMonFirst6,  gText_ApprenticeMonFirstThanks6},
    {gText_ApprenticeWhichMonFirst7,  gText_ApprenticeMonFirstThanks7},
    {gText_ApprenticeWhichMonFirst8,  gText_ApprenticeMonFirstThanks8},
    {gText_ApprenticeWhichMonFirst9,  gText_ApprenticeMonFirstThanks9},
    {gText_ApprenticeWhichMonFirst10, gText_ApprenticeMonFirstThanks10},
    {gText_ApprenticeWhichMonFirst11, gText_ApprenticeMonFirstThanks11},
    {gText_ApprenticeWhichMonFirst12, gText_ApprenticeMonFirstThanks12},
    {gText_ApprenticeWhichMonFirst13, gText_ApprenticeMonFirstThanks13},
    {gText_ApprenticeWhichMonFirst14, gText_ApprenticeMonFirstThanks14},
    {gText_ApprenticeWhichMonFirst15, gText_ApprenticeMonFirstThanks15},
};

static const u8 *const sApprenticePickWinSpeechTexts[NUM_APPRENTICES][2] =
{
    {gText_ApprenticePickWinSpeech0,  gText_ApprenticeWinSpeechThanks0},
    {gText_ApprenticePickWinSpeech1,  gText_ApprenticeWinSpeechThanks1},
    {gText_ApprenticePickWinSpeech2,  gText_ApprenticeWinSpeechThanks2},
    {gText_ApprenticePickWinSpeech3,  gText_ApprenticeWinSpeechThanks3},
    {gText_ApprenticePickWinSpeech4,  gText_ApprenticeWinSpeechThanks4},
    {gText_ApprenticePickWinSpeech5,  gText_ApprenticeWinSpeechThanks5},
    {gText_ApprenticePickWinSpeech6,  gText_ApprenticeWinSpeechThanks6},
    {gText_ApprenticePickWinSpeech7,  gText_ApprenticeWinSpeechThanks7},
    {gText_ApprenticePickWinSpeech8,  gText_ApprenticeWinSpeechThanks8},
    {gText_ApprenticePickWinSpeech9,  gText_ApprenticeWinSpeechThanks9},
    {gText_ApprenticePickWinSpeech10, gText_ApprenticeWinSpeechThanks10},
    {gText_ApprenticePickWinSpeech11, gText_ApprenticeWinSpeechThanks11},
    {gText_ApprenticePickWinSpeech12, gText_ApprenticeWinSpeechThanks12},
    {gText_ApprenticePickWinSpeech13, gText_ApprenticeWinSpeechThanks13},
    {gText_ApprenticePickWinSpeech14, gText_ApprenticeWinSpeechThanks14},
    {gText_ApprenticePickWinSpeech15, gText_ApprenticeWinSpeechThanks15},
};

static const u8 *const sApprenticeChallengeTexts[NUM_APPRENTICES] =
{
    gText_ApprenticeChallenge0,
    gText_ApprenticeChallenge1,
    gText_ApprenticeChallenge2,
    gText_ApprenticeChallenge3,
    gText_ApprenticeChallenge4,
    gText_ApprenticeChallenge5,
    gText_ApprenticeChallenge6,
    gText_ApprenticeChallenge7,
    gText_ApprenticeChallenge8,
    gText_ApprenticeChallenge9,
    gText_ApprenticeChallenge10,
    gText_ApprenticeChallenge11,
    gText_ApprenticeChallenge12,
    gText_ApprenticeChallenge13,
    gText_ApprenticeChallenge14,
    gText_ApprenticeChallenge15,
};

// Unclear what the criteria are for valid moves
// Notably, a large percentage of multi-strike moves are not valid
static const bool8 sValidApprenticeMoves[MOVES_COUNT] =
{
    [MOVE_NONE] = FALSE,
    [MOVE_POUND] = FALSE,
    [MOVE_KARATE_CHOP] = TRUE,
    [MOVE_DOUBLE_SLAP] = TRUE,
    [MOVE_COMET_PUNCH] = FALSE,
    [MOVE_MEGA_PUNCH] = TRUE,
    [MOVE_PAY_DAY] = FALSE,
    [MOVE_FIRE_PUNCH] = TRUE,
    [MOVE_ICE_PUNCH] = TRUE,
    [MOVE_THUNDER_PUNCH] = TRUE,
    [MOVE_SCRATCH] = FALSE,
    [MOVE_VICE_GRIP] = FALSE,
    [MOVE_GUILLOTINE] = TRUE,
    [MOVE_RAZOR_WIND] = FALSE,
    [MOVE_SWORDS_DANCE] = TRUE,
    [MOVE_CUT] = FALSE,
    [MOVE_GUST] = FALSE,
    [MOVE_WING_ATTACK] = FALSE,
    [MOVE_WHIRLWIND] = TRUE,
    [MOVE_FLY] = TRUE,
    [MOVE_BIND] = TRUE,
    [MOVE_SLAM] = TRUE,
    [MOVE_VINE_WHIP] = FALSE,
    [MOVE_STOMP] = TRUE,
    [MOVE_DOUBLE_KICK] = TRUE,
    [MOVE_MEGA_KICK] = TRUE,
    [MOVE_JUMP_KICK] = TRUE,
    [MOVE_ROLLING_KICK] = TRUE,
    [MOVE_SAND_ATTACK] = TRUE,
    [MOVE_HEADBUTT] = TRUE,
    [MOVE_HORN_ATTACK] = FALSE,
    [MOVE_FURY_ATTACK] = FALSE,
    [MOVE_HORN_DRILL] = TRUE,
    [MOVE_TACKLE] = FALSE,
    [MOVE_BODY_SLAM] = TRUE,
    [MOVE_WRAP] = TRUE,
    [MOVE_TAKE_DOWN] = TRUE,
    [MOVE_THRASH] = TRUE,
    [MOVE_DOUBLE_EDGE] = TRUE,
    [MOVE_TAIL_WHIP] = FALSE,
    [MOVE_POISON_STING] = FALSE,
    [MOVE_TWINEEDLE] = TRUE,
    [MOVE_PIN_MISSILE] = FALSE,
    [MOVE_LEER] = FALSE,
    [MOVE_BITE] = TRUE,
    [MOVE_GROWL] = FALSE,
    [MOVE_ROAR] = TRUE,
    [MOVE_SING] = TRUE,
    [MOVE_SUPERSONIC] = TRUE,
    [MOVE_SONIC_BOOM] = TRUE,
    [MOVE_DISABLE] = TRUE,
    [MOVE_ACID] = FALSE,
    [MOVE_EMBER] = FALSE,
    [MOVE_FLAMETHROWER] = TRUE,
    [MOVE_MIST] = TRUE,
    [MOVE_WATER_GUN] = FALSE,
    [MOVE_HYDRO_PUMP] = TRUE,
    [MOVE_SURF] = TRUE,
    [MOVE_ICE_BEAM] = TRUE,
    [MOVE_BLIZZARD] = TRUE,
    [MOVE_PSYBEAM] = TRUE,
    [MOVE_BUBBLE_BEAM] = FALSE,
    [MOVE_AURORA_BEAM] = FALSE,
    [MOVE_HYPER_BEAM] = TRUE,
    [MOVE_PECK] = FALSE,
    [MOVE_DRILL_PECK] = TRUE,
    [MOVE_SUBMISSION] = TRUE,
    [MOVE_LOW_KICK] = TRUE,
    [MOVE_COUNTER] = TRUE,
    [MOVE_SEISMIC_TOSS] = TRUE,
    [MOVE_STRENGTH] = TRUE,
    [MOVE_ABSORB] = FALSE,
    [MOVE_MEGA_DRAIN] = FALSE,
    [MOVE_LEECH_SEED] = TRUE,
    [MOVE_GROWTH] = TRUE,
    [MOVE_RAZOR_LEAF] = TRUE,
    [MOVE_SOLAR_BEAM] = TRUE,
    [MOVE_POISON_POWDER] = TRUE,
    [MOVE_STUN_SPORE] = TRUE,
    [MOVE_SLEEP_POWDER] = TRUE,
    [MOVE_PETAL_DANCE] = TRUE,
    [MOVE_STRING_SHOT] = FALSE,
    [MOVE_DRAGON_RAGE] = TRUE,
    [MOVE_FIRE_SPIN] = TRUE,
    [MOVE_THUNDER_SHOCK] = FALSE,
    [MOVE_THUNDERBOLT] = TRUE,
    [MOVE_THUNDER_WAVE] = TRUE,
    [MOVE_THUNDER] = TRUE,
    [MOVE_ROCK_THROW] = FALSE,
    [MOVE_EARTHQUAKE] = TRUE,
    [MOVE_FISSURE] = TRUE,
    [MOVE_DIG] = TRUE,
    [MOVE_TOXIC] = TRUE,
    [MOVE_CONFUSION] = FALSE,
    [MOVE_PSYCHIC] = TRUE,
    [MOVE_HYPNOSIS] = TRUE,
    [MOVE_MEDITATE] = TRUE,
    [MOVE_AGILITY] = TRUE,
    [MOVE_QUICK_ATTACK] = TRUE,
    [MOVE_RAGE] = FALSE,
    [MOVE_TELEPORT] = FALSE,
    [MOVE_NIGHT_SHADE] = TRUE,
    [MOVE_MIMIC] = TRUE,
    [MOVE_SCREECH] = TRUE,
    [MOVE_DOUBLE_TEAM] = TRUE,
    [MOVE_RECOVER] = TRUE,
    [MOVE_HARDEN] = TRUE,
    [MOVE_MINIMIZE] = TRUE,
    [MOVE_SMOKESCREEN] = TRUE,
    [MOVE_CONFUSE_RAY] = TRUE,
    [MOVE_WITHDRAW] = TRUE,
    [MOVE_DEFENSE_CURL] = TRUE,
    [MOVE_BARRIER] = TRUE,
    [MOVE_LIGHT_SCREEN] = TRUE,
    [MOVE_HAZE] = TRUE,
    [MOVE_REFLECT] = TRUE,
    [MOVE_FOCUS_ENERGY] = TRUE,
    [MOVE_BIDE] = FALSE,
    [MOVE_METRONOME] = TRUE,
    [MOVE_MIRROR_MOVE] = TRUE,
    [MOVE_SELF_DESTRUCT] = TRUE,
    [MOVE_EGG_BOMB] = TRUE,
    [MOVE_LICK] = TRUE,
    [MOVE_SMOG] = FALSE,
    [MOVE_SLUDGE] = FALSE,
    [MOVE_BONE_CLUB] = FALSE,
    [MOVE_FIRE_BLAST] = TRUE,
    [MOVE_WATERFALL] = TRUE,
    [MOVE_CLAMP] = TRUE,
    [MOVE_SWIFT] = TRUE,
    [MOVE_SKULL_BASH] = TRUE,
    [MOVE_SPIKE_CANNON] = FALSE,
    [MOVE_CONSTRICT] = FALSE,
    [MOVE_AMNESIA] = TRUE,
    [MOVE_KINESIS] = TRUE,
    [MOVE_SOFT_BOILED] = TRUE,
    [MOVE_HI_JUMP_KICK] = TRUE,
    [MOVE_GLARE] = TRUE,
    [MOVE_DREAM_EATER] = TRUE,
    [MOVE_POISON_GAS] = FALSE,
    [MOVE_BARRAGE] = FALSE,
    [MOVE_LEECH_LIFE] = FALSE,
    [MOVE_LOVELY_KISS] = TRUE,
    [MOVE_SKY_ATTACK] = TRUE,
    [MOVE_TRANSFORM] = TRUE,
    [MOVE_BUBBLE] = FALSE,
    [MOVE_DIZZY_PUNCH] = TRUE,
    [MOVE_SPORE] = TRUE,
    [MOVE_FLASH] = TRUE,
    [MOVE_PSYWAVE] = TRUE,
    [MOVE_SPLASH] = FALSE,
    [MOVE_ACID_ARMOR] = TRUE,
    [MOVE_CRABHAMMER] = TRUE,
    [MOVE_EXPLOSION] = TRUE,
    [MOVE_FURY_SWIPES] = FALSE,
    [MOVE_BONEMERANG] = TRUE,
    [MOVE_REST] = TRUE,
    [MOVE_ROCK_SLIDE] = TRUE,
    [MOVE_HYPER_FANG] = TRUE,
    [MOVE_SHARPEN] = TRUE,
    [MOVE_CONVERSION] = TRUE,
    [MOVE_TRI_ATTACK] = TRUE,
    [MOVE_SUPER_FANG] = TRUE,
    [MOVE_SLASH] = TRUE,
    [MOVE_SUBSTITUTE] = TRUE,
    [MOVE_STRUGGLE] = TRUE,
    [MOVE_SKETCH] = TRUE,
    [MOVE_TRIPLE_KICK] = TRUE,
    [MOVE_THIEF] = TRUE,
    [MOVE_SPIDER_WEB] = TRUE,
    [MOVE_MIND_READER] = TRUE,
    [MOVE_NIGHTMARE] = TRUE,
    [MOVE_FLAME_WHEEL] = FALSE,
    [MOVE_SNORE] = TRUE,
    [MOVE_CURSE] = TRUE,
    [MOVE_FLAIL] = TRUE,
    [MOVE_CONVERSION_2] = TRUE,
    [MOVE_AEROBLAST] = TRUE,
    [MOVE_COTTON_SPORE] = TRUE,
    [MOVE_REVERSAL] = TRUE,
    [MOVE_SPITE] = TRUE,
    [MOVE_POWDER_SNOW] = FALSE,
    [MOVE_PROTECT] = TRUE,
    [MOVE_MACH_PUNCH] = TRUE,
    [MOVE_SCARY_FACE] = TRUE,
    [MOVE_FAINT_ATTACK] = TRUE,
    [MOVE_SWEET_KISS] = TRUE,
    [MOVE_BELLY_DRUM] = TRUE,
    [MOVE_SLUDGE_BOMB] = TRUE,
    [MOVE_MUD_SLAP] = TRUE,
    [MOVE_OCTAZOOKA] = TRUE,
    [MOVE_SPIKES] = TRUE,
    [MOVE_ZAP_CANNON] = TRUE,
    [MOVE_FORESIGHT] = TRUE,
    [MOVE_DESTINY_BOND] = TRUE,
    [MOVE_PERISH_SONG] = TRUE,
    [MOVE_ICY_WIND] = TRUE,
    [MOVE_DETECT] = TRUE,
    [MOVE_BONE_RUSH] = FALSE,
    [MOVE_LOCK_ON] = TRUE,
    [MOVE_OUTRAGE] = TRUE,
    [MOVE_SANDSTORM] = TRUE,
    [MOVE_GIGA_DRAIN] = TRUE,
    [MOVE_ENDURE] = TRUE,
    [MOVE_CHARM] = TRUE,
    [MOVE_ROLLOUT] = TRUE,
    [MOVE_FALSE_SWIPE] = TRUE,
    [MOVE_SWAGGER] = TRUE,
    [MOVE_MILK_DRINK] = TRUE,
    [MOVE_SPARK] = FALSE,
    [MOVE_FURY_CUTTER] = TRUE,
    [MOVE_STEEL_WING] = TRUE,
    [MOVE_MEAN_LOOK] = TRUE,
    [MOVE_ATTRACT] = TRUE,
    [MOVE_SLEEP_TALK] = TRUE,
    [MOVE_HEAL_BELL] = TRUE,
    [MOVE_RETURN] = TRUE,
    [MOVE_PRESENT] = TRUE,
    [MOVE_FRUSTRATION] = TRUE,
    [MOVE_SAFEGUARD] = TRUE,
    [MOVE_PAIN_SPLIT] = TRUE,
    [MOVE_SACRED_FIRE] = TRUE,
    [MOVE_MAGNITUDE] = FALSE,
    [MOVE_DYNAMIC_PUNCH] = TRUE,
    [MOVE_MEGAHORN] = TRUE,
    [MOVE_DRAGON_BREATH] = TRUE,
    [MOVE_BATON_PASS] = TRUE,
    [MOVE_ENCORE] = TRUE,
    [MOVE_PURSUIT] = TRUE,
    [MOVE_RAPID_SPIN] = TRUE,
    [MOVE_SWEET_SCENT] = TRUE,
    [MOVE_IRON_TAIL] = TRUE,
    [MOVE_METAL_CLAW] = TRUE,
    [MOVE_VITAL_THROW] = TRUE,
    [MOVE_MORNING_SUN] = TRUE,
    [MOVE_SYNTHESIS] = TRUE,
    [MOVE_MOONLIGHT] = TRUE,
    [MOVE_HIDDEN_POWER] = TRUE,
    [MOVE_CROSS_CHOP] = TRUE,
    [MOVE_TWISTER] = FALSE,
    [MOVE_RAIN_DANCE] = TRUE,
    [MOVE_SUNNY_DAY] = TRUE,
    [MOVE_CRUNCH] = TRUE,
    [MOVE_MIRROR_COAT] = TRUE,
    [MOVE_PSYCH_UP] = TRUE,
    [MOVE_EXTREME_SPEED] = TRUE,
    [MOVE_ANCIENT_POWER] = TRUE,
    [MOVE_SHADOW_BALL] = TRUE,
    [MOVE_FUTURE_SIGHT] = TRUE,
    [MOVE_ROCK_SMASH] = TRUE,
    [MOVE_WHIRLPOOL] = TRUE,
    [MOVE_BEAT_UP] = TRUE,
    [MOVE_FAKE_OUT] = TRUE,
    [MOVE_UPROAR] = TRUE,
    [MOVE_STOCKPILE] = TRUE,
    [MOVE_SPIT_UP] = TRUE,
    [MOVE_SWALLOW] = TRUE,
    [MOVE_HEAT_WAVE] = TRUE,
    [MOVE_HAIL] = TRUE,
    [MOVE_TORMENT] = TRUE,
    [MOVE_FLATTER] = TRUE,
    [MOVE_WILL_O_WISP] = TRUE,
    [MOVE_MEMENTO] = TRUE,
    [MOVE_FACADE] = TRUE,
    [MOVE_FOCUS_PUNCH] = TRUE,
    [MOVE_SMELLING_SALT] = TRUE,
    [MOVE_FOLLOW_ME] = TRUE,
    [MOVE_NATURE_POWER] = TRUE,
    [MOVE_CHARGE] = TRUE,
    [MOVE_TAUNT] = TRUE,
    [MOVE_HELPING_HAND] = TRUE,
    [MOVE_TRICK] = TRUE,
    [MOVE_ROLE_PLAY] = TRUE,
    [MOVE_WISH] = TRUE,
    [MOVE_ASSIST] = TRUE,
    [MOVE_INGRAIN] = TRUE,
    [MOVE_SUPERPOWER] = TRUE,
    [MOVE_MAGIC_COAT] = TRUE,
    [MOVE_RECYCLE] = TRUE,
    [MOVE_REVENGE] = TRUE,
    [MOVE_BRICK_BREAK] = TRUE,
    [MOVE_YAWN] = TRUE,
    [MOVE_KNOCK_OFF] = TRUE,
    [MOVE_ENDEAVOR] = TRUE,
    [MOVE_ERUPTION] = TRUE,
    [MOVE_SKILL_SWAP] = TRUE,
    [MOVE_IMPRISON] = TRUE,
    [MOVE_REFRESH] = TRUE,
    [MOVE_GRUDGE] = TRUE,
    [MOVE_SNATCH] = TRUE,
    [MOVE_SECRET_POWER] = TRUE,
    [MOVE_DIVE] = TRUE,
    [MOVE_ARM_THRUST] = FALSE,
    [MOVE_CAMOUFLAGE] = TRUE,
    [MOVE_TAIL_GLOW] = TRUE,
    [MOVE_LUSTER_PURGE] = TRUE,
    [MOVE_MIST_BALL] = TRUE,
    [MOVE_FEATHER_DANCE] = TRUE,
    [MOVE_TEETER_DANCE] = TRUE,
    [MOVE_BLAZE_KICK] = TRUE,
    [MOVE_MUD_SPORT] = TRUE,
    [MOVE_ICE_BALL] = FALSE,
    [MOVE_NEEDLE_ARM] = TRUE,
    [MOVE_SLACK_OFF] = TRUE,
    [MOVE_HYPER_VOICE] = TRUE,
    [MOVE_POISON_FANG] = FALSE,
    [MOVE_CRUSH_CLAW] = TRUE,
    [MOVE_BLAST_BURN] = TRUE,
    [MOVE_HYDRO_CANNON] = TRUE,
    [MOVE_METEOR_MASH] = TRUE,
    [MOVE_ASTONISH] = TRUE,
    [MOVE_WEATHER_BALL] = TRUE,
    [MOVE_AROMATHERAPY] = TRUE,
    [MOVE_FAKE_TEARS] = TRUE,
    [MOVE_AIR_CUTTER] = TRUE,
    [MOVE_OVERHEAT] = TRUE,
    [MOVE_ODOR_SLEUTH] = TRUE,
    [MOVE_ROCK_TOMB] = TRUE,
    [MOVE_SILVER_WIND] = TRUE,
    [MOVE_METAL_SOUND] = TRUE,
    [MOVE_GRASS_WHISTLE] = TRUE,
    [MOVE_TICKLE] = TRUE,
    [MOVE_COSMIC_POWER] = TRUE,
    [MOVE_WATER_SPOUT] = TRUE,
    [MOVE_SIGNAL_BEAM] = TRUE,
    [MOVE_SHADOW_PUNCH] = TRUE,
    [MOVE_EXTRASENSORY] = TRUE,
    [MOVE_SKY_UPPERCUT] = TRUE,
    [MOVE_SAND_TOMB] = TRUE,
    [MOVE_SHEER_COLD] = TRUE,
    [MOVE_MUDDY_WATER] = TRUE,
    [MOVE_BULLET_SEED] = FALSE,
    [MOVE_AERIAL_ACE] = TRUE,
    [MOVE_ICICLE_SPEAR] = FALSE,
    [MOVE_IRON_DEFENSE] = TRUE,
    [MOVE_BLOCK] = TRUE,
    [MOVE_HOWL] = TRUE,
    [MOVE_DRAGON_CLAW] = TRUE,
    [MOVE_FRENZY_PLANT] = TRUE,
    [MOVE_BULK_UP] = TRUE,
    [MOVE_BOUNCE] = TRUE,
    [MOVE_MUD_SHOT] = FALSE,
    [MOVE_POISON_TAIL] = TRUE,
    [MOVE_COVET] = TRUE,
    [MOVE_VOLT_TACKLE] = TRUE,
    [MOVE_MAGICAL_LEAF] = TRUE,
    [MOVE_WATER_SPORT] = TRUE,
    [MOVE_CALM_MIND] = TRUE,
    [MOVE_LEAF_BLADE] = TRUE,
    [MOVE_DRAGON_DANCE] = TRUE,
    [MOVE_ROCK_BLAST] = FALSE,
    [MOVE_SHOCK_WAVE] = TRUE,
    [MOVE_WATER_PULSE] = TRUE,
    [MOVE_DOOM_DESIRE] = TRUE,
    [MOVE_PSYCHO_BOOST] = TRUE,
};

// The possible questions to ask after the initial 3 WHICH MON questions. Retrieved from here and shuffled
// WHAT_ITEM has max 3 occurrences, one for each party member
// WHICH_MOVE has max 5 occurrences, defined as NUM_WHICH_MOVE_QUESTIONS
// WHICH_FIRST has max 1 occurrence, lead mon should only be chosen once
// WHICH_SPEECH has max 1 occurrence, as the apprentice leaves after its asked
static const u8 sQuestionPossibilities[] = 
{
    QUESTION_ID_WHAT_ITEM,
    QUESTION_ID_WHAT_ITEM, 
    QUESTION_ID_WHAT_ITEM, 
    QUESTION_ID_WHICH_MOVE,
    QUESTION_ID_WHICH_MOVE, 
    QUESTION_ID_WHICH_MOVE, 
    QUESTION_ID_WHICH_MOVE, 
    QUESTION_ID_WHICH_MOVE, 
    QUESTION_ID_WHICH_FIRST, 
    QUESTION_ID_WIN_SPEECH 
};

static void (* const sApprenticeFunctions[])(void) =
{
    [APPRENTICE_FUNC_GAVE_LVLMODE]        = Script_GivenApprenticeLvlMode,
    [APPRENTICE_FUNC_SET_LVLMODE]         = Script_SetApprenticeLvlMode,
    [APPRENTICE_FUNC_SET_ID]              = Script_SetApprenticeId,
    [APPRENTICE_FUNC_SHUFFLE_SPECIES]     = ShuffleApprenticeSpecies,
    [APPRENTICE_FUNC_RANDOMIZE_QUESTIONS] = Script_SetRandomQuestionData,
    [APPRENTICE_FUNC_ANSWERED_QUESTION]   = IncrementQuestionsAnswered,
    [APPRENTICE_FUNC_IS_FINAL_QUESTION]   = IsFinalQuestion,
    [APPRENTICE_FUNC_MENU]                = Script_CreateApprenticeMenu,
    [APPRENTICE_FUNC_PRINT_MSG]           = Script_PrintApprenticeMessage,
    [APPRENTICE_FUNC_RESET]               = Script_ResetPlayerApprentice,
    [APPRENTICE_FUNC_CHECK_GONE]          = GetShouldCheckApprenticeGone,
    [APPRENTICE_FUNC_GET_QUESTION]        = ApprenticeGetQuestion,
    [APPRENTICE_FUNC_GET_NUM_PARTY_MONS]  = GetNumApprenticePartyMonsAssigned,
    [APPRENTICE_FUNC_SET_PARTY_MON]       = SetApprenticePartyMon,
    [APPRENTICE_FUNC_INIT_QUESTION_DATA]  = InitQuestionData,
    [APPRENTICE_FUNC_FREE_QUESTION_DATA]  = FreeQuestionData,
    [APPRENTICE_FUNC_BUFFER_STRING]       = ApprenticeBufferString,
    [APPRENTICE_FUNC_SET_MOVE]            = SetApprenticeMonMove,
    [APPRENTICE_FUNC_SET_LEAD_MON]        = SetLeadApprenticeMon,
    [APPRENTICE_FUNC_OPEN_BAG]            = Script_ApprenticeOpenBagMenu,
    [APPRENTICE_FUNC_TRY_SET_HELD_ITEM]   = TrySetApprenticeHeldItem,
    [APPRENTICE_FUNC_SAVE]                = SaveApprentice,
    [APPRENTICE_FUNC_SET_GFX_SAVED]       = SetSavedApprenticeTrainerGfxId,
    [APPRENTICE_FUNC_SET_GFX]             = SetPlayerApprenticeTrainerGfxId,
    [APPRENTICE_FUNC_SHOULD_LEAVE]        = GetShouldApprenticeLeave,
    [APPRENTICE_FUNC_SHIFT_SAVED]         = ShiftSavedApprentices,
};

// The first Apprentice can only be one of these
static const u8 sInitialApprenticeIds[8] = {0, 1, 2, 3, 6, 7, 8, 9};


void BufferApprenticeChallengeText(u8 saveApprenticeId)
{
    u8 i, num;
    const u8 *challengeText;

    num = gSaveBlock2Ptr->apprentices[saveApprenticeId].number;
    for (i = 0; num != 0 && i < APPRENTICE_COUNT; num /= 10, i++)
        ;

    StringCopy7(gStringVar1, gSaveBlock2Ptr->apprentices[saveApprenticeId].playerName);
    ConvertInternationalString(gStringVar1, gSaveBlock2Ptr->apprentices[saveApprenticeId].language);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->apprentices[saveApprenticeId].number, STR_CONV_MODE_RIGHT_ALIGN, i);
    challengeText = sApprenticeChallengeTexts[gSaveBlock2Ptr->apprentices[saveApprenticeId].id];
    StringExpandPlaceholders(gStringVar4, challengeText);
}

void Apprentice_EnableBothScriptContexts(void)
{
    EnableBothScriptContexts();
}

void ResetApprenticeStruct(struct Apprentice *apprentice)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(apprentice->speechWon); i++)
        apprentice->speechWon[i] = 0xFFFF;

    apprentice->playerName[0] = EOS;
    apprentice->id = NUM_APPRENTICES;
}

void ResetAllApprenticeData(void)
{
    u8 i, j;

    PLAYER_APPRENTICE.saveId = 0;
    for (i = 0; i < APPRENTICE_COUNT; i++)
    {
        for (j = 0; j < ARRAY_COUNT(gSaveBlock2Ptr->apprentices[i].speechWon); j++)
            gSaveBlock2Ptr->apprentices[i].speechWon[j] = 0xFFFF;
        gSaveBlock2Ptr->apprentices[i].id = NUM_APPRENTICES;
        gSaveBlock2Ptr->apprentices[i].playerName[0] = EOS;
        gSaveBlock2Ptr->apprentices[i].lvlMode = 0;
        gSaveBlock2Ptr->apprentices[i].number = 0;
        gSaveBlock2Ptr->apprentices[i].numQuestions = 0;
        for (j = 0; j < TRAINER_ID_LENGTH; j++)
            gSaveBlock2Ptr->apprentices[i].playerId[j] = 0;
        gSaveBlock2Ptr->apprentices[i].language = gGameLanguage;
        gSaveBlock2Ptr->apprentices[i].checksum = 0;
    }

    Script_ResetPlayerApprentice();
}

static bool8 GivenApprenticeLvlMode(void)
{
    return (PLAYER_APPRENTICE.lvlMode != 0);
}

static void SetApprenticeId(void)
{
    if (gSaveBlock2Ptr->apprentices[0].number == 0)
    {
        do
        {
            PLAYER_APPRENTICE.id = sInitialApprenticeIds[Random() % ARRAY_COUNT(sInitialApprenticeIds)];
        } while (PLAYER_APPRENTICE.id == gSaveBlock2Ptr->apprentices[0].id);
    }
    else
    {
        do
        {
            PLAYER_APPRENTICE.id = Random() % (NUM_APPRENTICES);
        } while (PLAYER_APPRENTICE.id == gSaveBlock2Ptr->apprentices[0].id);
    }
}

static void SetPlayersApprenticeLvlMode(u8 mode)
{
    PLAYER_APPRENTICE.lvlMode = mode;
}

static void ShuffleApprenticeSpecies(void)
{
    u8 species[APPRENTICE_SPECIES_COUNT];
    u8 i;

    for (i = 0; i < ARRAY_COUNT(species); i++)
        species[i] = i;

    // Shuffle the possible species an arbitrary 50 times
    for (i = 0; i < 50; i++)
    {
        u8 temp;
        u8 rand1 = Random() % ARRAY_COUNT(species);
        u8 rand2 = Random() % ARRAY_COUNT(species);
        SWAP(species[rand1], species[rand2], temp);
    }

    for (i = 0; i < MULTI_PARTY_SIZE; i++)
        PLAYER_APPRENTICE.speciesIds[i] = ((species[i * 2] & 0xF) << 4) | ((species[i * 2 + 1]) & 0xF);
}

// Pick one of the Apprentice's mons to ask the question about
// Picking a move chooses a random mon, picking a held item is sequential (so that none are repeated)
static u8 GetMonIdForQuestion(u8 questionId, u8 *party, u8 *partySlot)
{
    u8 i, count;
    u8 monId = 0;

    if (questionId == QUESTION_ID_WHICH_MOVE)
    {
        do
        {
            monId = Random() % (MULTI_PARTY_SIZE);
            for (count = 0, i = 0; i < NUM_WHICH_MOVE_QUESTIONS; i++)
            {
                if (gApprenticePartyMovesData->moves[monId][i] != MOVE_NONE)
                    count++;
            }
        } while (count > MULTI_PARTY_SIZE);
    }
    else if (questionId == QUESTION_ID_WHAT_ITEM)
    {
        monId = party[*partySlot];
        (*partySlot)++;
    }

    return monId;
}

// Sets the random order and data for the remaining questions after the initial "choose mon" questions
static void SetRandomQuestionData(void)
{
    u8 questionOrder[APPRENTICE_MAX_QUESTIONS + 1];
    u8 partyOrder[MULTI_PARTY_SIZE];
    u8 partySlot;
    u8 i, j;
    u8 rand1, rand2;
    u8 id;

    for (i = 0; i < ARRAY_COUNT(partyOrder); i++)
        partyOrder[i] = i;

    // Shuffle the party an arbitrary 10 times
    for (i = 0; i < 10; i++)
    {
        u8 temp;
        rand1 = Random() % ARRAY_COUNT(partyOrder);
        rand2 = Random() % ARRAY_COUNT(partyOrder);
        SWAP(partyOrder[rand1], partyOrder[rand2], temp);
    }

    for (i = 0; i < ARRAY_COUNT(questionOrder); i++)
        questionOrder[i] = sQuestionPossibilities[i];
    
    // Shuffle the questions an arbitrary 50 times
    for (i = 0; i < 50; i++)
    {
        u8 temp;
        rand1 = Random() % ARRAY_COUNT(questionOrder);
        rand2 = Random() % ARRAY_COUNT(questionOrder);
        SWAP(questionOrder[rand1], questionOrder[rand2], temp);
    }

    gApprenticePartyMovesData = AllocZeroed(sizeof(*gApprenticePartyMovesData));
    gApprenticePartyMovesData->moveCounter = 0;
    for (i = 0; i < NUM_WHICH_MOVE_QUESTIONS; i++)
    {
        for (j = 0; j < MULTI_PARTY_SIZE; j++)
            gApprenticePartyMovesData->moveSlots[j][i] = MAX_MON_MOVES;
    }

    partySlot = 0;
    for (i = 0; i < APPRENTICE_MAX_QUESTIONS; i++)
    {
        PLAYER_APPRENTICE.questions[i].questionId = questionOrder[i];
        if (questionOrder[i] != QUESTION_ID_WHICH_FIRST)
        {
            PLAYER_APPRENTICE.questions[i].monId = GetMonIdForQuestion(questionOrder[i], partyOrder, &partySlot);
            id = PLAYER_APPRENTICE.questions[i].monId;
            if (questionOrder[i] == QUESTION_ID_WHICH_MOVE)
            {
                do
                {
                    rand1 = Random() % MAX_MON_MOVES;
                    for (j = 0; j < gApprenticePartyMovesData->moveCounter + 1; j++)
                    {
                        if (gApprenticePartyMovesData->moveSlots[id][j] == rand1)
                            break;
                    }
                } while (j != gApprenticePartyMovesData->moveCounter + 1);

                gApprenticePartyMovesData->moveSlots[id][gApprenticePartyMovesData->moveCounter] = rand1;
                PLAYER_APPRENTICE.questions[i].moveSlot = rand1;
                PLAYER_APPRENTICE.questions[i].data = GetRandomAlternateMove(PLAYER_APPRENTICE.questions[i].monId);
            }
        }
    }

    FREE_AND_SET_NULL(gApprenticePartyMovesData);
}

// No idea why a do-while loop is needed, but it will not match without it.

#define APPRENTICE_SPECIES_ID(speciesArrId, monId) speciesArrId = (PLAYER_APPRENTICE.speciesIds[monId] >> \
                                                                  (((PLAYER_APPRENTICE.party >> monId) & 1) << 2)) & 0xF; \
                                                   do {} while (0)

// Why the need to have two macros do the exact thing differently?
#define APPRENTICE_SPECIES_ID_2(speciesArrId, monId) {  u8 a0 = ((PLAYER_APPRENTICE.party >> monId) & 1);\
                                                        speciesArrId = PLAYER_APPRENTICE.speciesIds[monId];     \
                                                        speciesArrId = ((speciesArrId) >> (a0 << 2)) & 0xF; \
                                                     }

// Get the second move choice for the "Which move" question
// Unlike the first move choice, this can be either a level up move or a TM/HM move
static u16 GetRandomAlternateMove(u8 monId)
{
    u8 i, j;
    u8 id;
    u8 numLearnsetMoves;
    u16 species;
    const u16 *learnset;
    bool32 needTMs = FALSE;
    u16 moveId = MOVE_NONE;
    bool32 shouldUseMove;
    u8 level;

    if (monId < MULTI_PARTY_SIZE)
    {
        APPRENTICE_SPECIES_ID(id, monId);
    }
    else
    {
        id = 0;
    }

    species = gApprentices[PLAYER_APPRENTICE.id].species[id];
    learnset = gLevelUpLearnsets[species];
    j = 0;

    // Despite being open level, level up moves are only read up to level 60
    if (PLAYER_APPRENTICE.lvlMode == APPRENTICE_LVL_MODE_50)
        level = 50;
    else // == APPRENTICE_LVL_MODE_OPEN
        level = 60;

    for (j = 0; learnset[j] != LEVEL_UP_END; j++)
    {
        if ((learnset[j] & LEVEL_UP_MOVE_LV) > (level << 9))
            break;
    }

    numLearnsetMoves = j;
    i = 0;

    // i < 5 here is arbitrary, i isnt used and is only incremented when the selected move isnt in sValidApprenticeMoves
    // This while loop contains 3 potential infinite loops, though none of them would occur in the base game
    while (i < 5)
    {
        if (Random() % 2 == 0 || needTMs == TRUE)
        {
            // Get TM move
            // NOTE: Below is an infinite loop if a species that only learns TMs for moves
            //       that are also in its level up learnset is assigned to an Apprentice
            do
            {
                // NOTE: Below is an infinite loop if a species which cannot learn TMs is assigned to an Apprentice
                do
                {
                    id = Random() % (NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES);
                    shouldUseMove = CanSpeciesLearnTMHM(species, id);
                }
                while (!shouldUseMove);

                moveId = ItemIdToBattleMoveId(ITEM_TM01 + id);
                shouldUseMove = TRUE;

                if (numLearnsetMoves <= MAX_MON_MOVES)
                    j = 0;
                else
                    j = numLearnsetMoves - MAX_MON_MOVES;

                for (; j < numLearnsetMoves; j++)
                {
                    // Keep looking for TMs until one not in the level up learnset is found
                    if ((learnset[j] & LEVEL_UP_MOVE_ID) == moveId)
                    {
                        shouldUseMove = FALSE;
                        break;
                    }
                }
            } while (shouldUseMove != TRUE);
        }
        else
        {
            if (numLearnsetMoves <= MAX_MON_MOVES)
            {
                needTMs = TRUE;
                continue;
            }
            else
            {
                // Get level up move
                // NOTE: Below is an infinite loop if a mon whose last 4 moves contain
                //       all the moves in the rest of its learnset is assigned to an Apprentice
                do
                {
                    // Get a random move excluding the 4 it would know at max level
                    u8 learnsetId = Random() % (numLearnsetMoves - MAX_MON_MOVES);
                    moveId = learnset[learnsetId] & LEVEL_UP_MOVE_ID;
                    shouldUseMove = TRUE;

                    for (j = numLearnsetMoves - MAX_MON_MOVES; j < numLearnsetMoves; j++)
                    {
                        // Keep looking for moves until one not in the last 4 is found
                        if ((learnset[j] & LEVEL_UP_MOVE_ID) == moveId)
                        {
                            shouldUseMove = FALSE;
                            break;
                        }
                    }
                } while (shouldUseMove != TRUE);
            }
        }

        if (TrySetMove(monId, moveId))
        {
            if (sValidApprenticeMoves[moveId])
                break;
            i++;
        }
    }

    gApprenticePartyMovesData->moveCounter++;
    return moveId;
}

static bool8 TrySetMove(u8 monId, u16 moveId)
{
    u8 i;

    for (i = 0; i < NUM_WHICH_MOVE_QUESTIONS; i++)
    {
        if (gApprenticePartyMovesData->moves[monId][i] == moveId)
            return FALSE;
    }

    gApprenticePartyMovesData->moves[monId][gApprenticePartyMovesData->moveCounter] = moveId;
    return TRUE;
}

static void GetLatestLearnedMoves(u16 species, u16 *moves)
{
    u8 i, j;
    u8 level, numLearnsetMoves;
    const u16 *learnset;

    if (PLAYER_APPRENTICE.lvlMode == APPRENTICE_LVL_MODE_50)
        level = 50;
    else // == APPRENTICE_LVL_MODE_OPEN
        level = 60;

    learnset = gLevelUpLearnsets[species];
    for (i = 0; learnset[i] != LEVEL_UP_END; i++)
    {
        if ((learnset[i] & LEVEL_UP_MOVE_LV) > (level << 9))
            break;
    }

    numLearnsetMoves = i;
    if (numLearnsetMoves > MAX_MON_MOVES)
        numLearnsetMoves = MAX_MON_MOVES;

    for (j = 0; j < numLearnsetMoves; j++)
        moves[j] = learnset[(i - 1) - j] & LEVEL_UP_MOVE_ID;
}

// Get the level up move or previously suggested move to be the first move choice
// Compare to GetRandomAlternateMove, which gets the move that will be the second choice
static u16 GetDefaultMove(u8 monId, u8 speciesArrayId, u8 moveSlot)
{
    u16 moves[MAX_MON_MOVES];
    u8 i, numQuestions;

    if (PLAYER_APPRENTICE.questionsAnswered < NUM_WHICH_MON_QUESTIONS)
        return MOVE_NONE;

    numQuestions = 0;
    for (i = 0; i < APPRENTICE_MAX_QUESTIONS && PLAYER_APPRENTICE.questions[i].questionId != QUESTION_ID_WIN_SPEECH; i++)
        numQuestions++;

    GetLatestLearnedMoves(gApprentices[PLAYER_APPRENTICE.id].species[speciesArrayId], moves);
    for (i = 0; i < numQuestions && i < CURRENT_QUESTION_NUM; i++)
    {
        if (PLAYER_APPRENTICE.questions[i].questionId == QUESTION_ID_WHICH_MOVE
            && PLAYER_APPRENTICE.questions[i].monId == monId
            && PLAYER_APPRENTICE.questions[i].suggestedChange)
        {
            moves[PLAYER_APPRENTICE.questions[i].moveSlot] = PLAYER_APPRENTICE.questions[i].data;
        }
    }

    return moves[moveSlot];
}

static void SaveApprenticeParty(u8 numQuestions)
{
    struct ApprenticeMon *apprenticeMons[MULTI_PARTY_SIZE];
    u8 i, j;
    u32 speciesTableId;

    for (i = 0; i < MULTI_PARTY_SIZE; i++)
    {
        gSaveBlock2Ptr->apprentices[0].party[i].species = SPECIES_NONE;
        gSaveBlock2Ptr->apprentices[0].party[i].item = ITEM_NONE;
        for (j = 0; j < MAX_MON_MOVES; j++)
            gSaveBlock2Ptr->apprentices[0].party[i].moves[j] = MOVE_NONE;
    }

    // Save party order
    j = PLAYER_APPRENTICE.leadMonId;
    for (i = 0; i < MULTI_PARTY_SIZE; i++)
    {
        apprenticeMons[j] = &gSaveBlock2Ptr->apprentices[0].party[i];
        j = (j + 1) % (MULTI_PARTY_SIZE);
    }

    // Save party species
    for (i = 0; i < MULTI_PARTY_SIZE; i++)
    {
        APPRENTICE_SPECIES_ID(speciesTableId, i);
        apprenticeMons[i]->species = gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId];
        GetLatestLearnedMoves(apprenticeMons[i]->species, apprenticeMons[i]->moves);
    }

    // Update party based on response to held item / move choice questions
    for (i = 0; i < numQuestions; i++)
    {
        u8 questionId = PLAYER_APPRENTICE.questions[i].questionId;
        u8 monId = PLAYER_APPRENTICE.questions[i].monId;
        if (questionId == QUESTION_ID_WHAT_ITEM)
        {
            if (PLAYER_APPRENTICE.questions[i].suggestedChange)
                apprenticeMons[monId]->item = PLAYER_APPRENTICE.questions[i].data;
        }
        else if (questionId == QUESTION_ID_WHICH_MOVE)
        {
            if (PLAYER_APPRENTICE.questions[i].suggestedChange)
            {
                u32 moveSlot = PLAYER_APPRENTICE.questions[i].moveSlot;
                apprenticeMons[monId]->moves[moveSlot] = PLAYER_APPRENTICE.questions[i].data;
            }
        }
    }
}

static void CreateApprenticeMenu(u8 menu)
{
    u8 i;
    u8 windowId;
    const u8 *strings[3];
    u8 count = 2;
    u8 width;
    u8 left;
    u8 top;
    s32 pixelWidth;

    switch (menu)
    {
    case APPRENTICE_ASK_WHICH_LEVEL:
        left = 18;
        top = 8;
        strings[0] = gText_Lv50;
        strings[1] = gText_OpenLevel;
        break;
    case APPRENTICE_ASK_3SPECIES:
        count = MULTI_PARTY_SIZE;
        left = 18;
        top = 6;
        for (i = 0; i < MULTI_PARTY_SIZE; i++)
        {
            u16 species;
            u32 speciesTableId;

            APPRENTICE_SPECIES_ID(speciesTableId, i);
            species =  gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId];
            strings[i] = gSpeciesNames[species];
        }
        break;
    case APPRENTICE_ASK_2SPECIES:
        left = 18;
        top = 8;
        if (PLAYER_APPRENTICE.questionsAnswered >= NUM_WHICH_MON_QUESTIONS)
            return;
        strings[1] = gSpeciesNames[gApprenticeQuestionData->altSpeciesId];
        strings[0] = gSpeciesNames[gApprenticeQuestionData->speciesId];
        break;
    case APPRENTICE_ASK_MOVES:
        left = 17;
        top = 8;
        strings[0] = gMoveNames[gApprenticeQuestionData->moveId1];
        strings[1] = gMoveNames[gApprenticeQuestionData->moveId2];
        break;
    case APPRENTICE_ASK_GIVE:
        left = 18;
        top = 8;
        strings[0] = gText_Give;
        strings[1] = gText_NoNeed;
        break;
    case APPRENTICE_ASK_YES_NO:
        left = 20;
        top = 8;
        strings[0] = gText_Yes;
        strings[1] = gText_No;
        break;
    default:
        left = 0;
        top = 0;
        break;
    }

    pixelWidth = 0;
    for (i = 0; i < count; i++)
    {
        s32 width = GetStringWidth(1, strings[i], 0);
        if (width > pixelWidth)
            pixelWidth = width;
    }

    width = ConvertPixelWidthToTileWidth(pixelWidth);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, width);
    windowId = CreateAndShowWindow(left, top, width, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);

    for (i = 0; i < count; i++)
        AddTextPrinterParameterized(windowId, 1, strings[i], 8, (i * 16) + 1, TEXT_SPEED_FF, NULL);

    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, 0);
    CreateChooseAnswerTask(TRUE, count, windowId);
}

#define tNoBButton data[4]
#define tWrapAround data[5]
#define tWindowId data[6]

static void Task_ChooseAnswer(u8 taskId)
{
    s8 input;
    s16 *data = gTasks[taskId].data;

    if (!tWrapAround)
        input = Menu_ProcessInputNoWrap();
    else
        input = Menu_ProcessInput();

    switch (input)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tNoBButton)
            return;

        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0x7F;
        break;
    default:
        gSpecialVar_Result = input;
        break;
    }

    RemoveAndHideWindow(tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static u8 CreateAndShowWindow(u8 left, u8 top, u8 width, u8 height)
{
    u8 windowId;
    struct WindowTemplate winTemplate = CreateWindowTemplate(0, left + 1, top + 1, width, height, 15, 100);

    windowId = AddWindow(&winTemplate);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
    return windowId;
}

static void RemoveAndHideWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
}

static void CreateChooseAnswerTask(bool8 noBButton, u8 answers, u8 windowId)
{
    u8 taskId = CreateTask(Task_ChooseAnswer, 80);
    gTasks[taskId].tNoBButton = noBButton;

    if (answers > 3)
        gTasks[taskId].tWrapAround = TRUE;
    else
        gTasks[taskId].tWrapAround = FALSE;

    gTasks[taskId].tWindowId = windowId;
}

#undef tNoBButton
#undef tWrapAround
#undef tWindowId

void CallApprenticeFunction(void)
{
    sApprenticeFunctions[gSpecialVar_0x8004]();
}

static void Script_ResetPlayerApprentice(void)
{
    u8 i;

    SetApprenticeId();
    PLAYER_APPRENTICE.lvlMode = 0;
    PLAYER_APPRENTICE.questionsAnswered = 0;
    PLAYER_APPRENTICE.leadMonId = 0;
    PLAYER_APPRENTICE.party = 0;

    for (i = 0; i < MULTI_PARTY_SIZE; i++)
        PLAYER_APPRENTICE.speciesIds[i] = 0;

    for (i = 0; i < APPRENTICE_MAX_QUESTIONS; i++)
    {
        PLAYER_APPRENTICE.questions[i].questionId = 0;
        PLAYER_APPRENTICE.questions[i].monId = 0;
        PLAYER_APPRENTICE.questions[i].moveSlot = 0;
        PLAYER_APPRENTICE.questions[i].suggestedChange = 0;
        PLAYER_APPRENTICE.questions[i].data = 0;
    }
}

static void Script_GivenApprenticeLvlMode(void)
{
    if (!GivenApprenticeLvlMode())
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

// VAR_0x8005 is 1 + the selection value from the multichoice APPRENTICE_ASK_WHICH_LEVEL
// i.e. APPRENTICE_LVL_MODE_50 or APPRENTICE_LVL_MODE_OPEN
static void Script_SetApprenticeLvlMode(void)
{
    SetPlayersApprenticeLvlMode(gSpecialVar_0x8005);
}

// Never called, APPRENTICE_FUNC_SET_ID is unused
static void Script_SetApprenticeId(void)
{
    SetApprenticeId();
}

static void Script_SetRandomQuestionData(void)
{
    SetRandomQuestionData();
}

static void IncrementQuestionsAnswered(void)
{
    PLAYER_APPRENTICE.questionsAnswered++;
}

// The first 3 questions answered after meeting the Apprentice are always selecting party mons
//  after which this is never called
static void GetNumApprenticePartyMonsAssigned(void)
{
    gSpecialVar_Result = PLAYER_APPRENTICE.questionsAnswered;
}

// Never called, APPRENTICE_FUNC_IS_FINAL_QUESTION is unused
static void IsFinalQuestion(void)
{
    s32 questionNum = CURRENT_QUESTION_NUM;
    
    if (questionNum < 0)
    {
        // Not finished asking initial questions
        gSpecialVar_Result = FALSE;
    }
    else
    {
        if (questionNum > APPRENTICE_MAX_QUESTIONS - 1)
            gSpecialVar_Result = TRUE;

        if (PLAYER_APPRENTICE.questions[questionNum].questionId == QUESTION_ID_WIN_SPEECH)
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
    }
}

static void Script_CreateApprenticeMenu(void)
{
    CreateApprenticeMenu(gSpecialVar_0x8005);
}

static void Task_WaitForPrintingMessage(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        DestroyTask(taskId);
        if (gSpecialVar_0x8005)
            ExecuteFuncAfterButtonPress(EnableBothScriptContexts);
        else
            EnableBothScriptContexts();
    }
}

static void PrintApprenticeMessage(void)
{
    const u8 *string;

    if (gSpecialVar_0x8006 == APPRENTICE_MSG_WHICH_MON)
    {
        string = sApprenticeWhichMonTexts[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_THANKS_MON)
    {
        string = sApprenticeWhichMonTexts[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_WHICH_MOVE)
    {
        string = sApprenticeWhichMoveTexts[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_THANKS_MOVE)
    {
        string = sApprenticeWhichMoveTexts[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_WHICH_MON_FIRST)
    {
        string = sApprenticeWhichMonFirstTexts[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_THANKS_MON_FIRST)
    {
        string = sApprenticeWhichMonFirstTexts[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_WHAT_HELD_ITEM)
    {
        string = sApprenticeHeldItemTexts[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_PICK_WIN_SPEECH)
    {
        string = sApprenticePickWinSpeechTexts[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_THANKS_HELD_ITEM)
    {
        string = sApprenticeHeldItemTexts[PLAYER_APPRENTICE.id][3];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_HOLD_NOTHING)
    {
        string = sApprenticeHeldItemTexts[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_ITEM_ALREADY_SUGGESTED)
    {
        string = sApprenticeHeldItemTexts[PLAYER_APPRENTICE.id][4];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_THANKS_NO_HELD_ITEM)
    {
        string = sApprenticeHeldItemTexts[PLAYER_APPRENTICE.id][2];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_THANKS_WIN_SPEECH)
    {
        string = sApprenticePickWinSpeechTexts[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_PLEASE_TEACH)
    {
        string = sApprenticeFirstMeetingTexts[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_REJECT)
    {
        string = sApprenticeFirstMeetingTexts[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_WHICH_LVL_MODE)
    {
        string = sApprenticeFirstMeetingTexts[PLAYER_APPRENTICE.id][2];
    }
    else if (gSpecialVar_0x8006 == APPRENTICE_MSG_THANKS_LVL_MODE)
    {
        string = sApprenticeFirstMeetingTexts[PLAYER_APPRENTICE.id][3];
    }
    else
    {
        EnableBothScriptContexts();
        return;
    }

    StringExpandPlaceholders(gStringVar4, string);
    AddTextPrinterForMessage(TRUE);
    CreateTask(Task_WaitForPrintingMessage, 1);
}

static void Script_PrintApprenticeMessage(void)
{
    ScriptContext2_Enable();
    FreezeEventObjects();
    sub_808B864();
    sub_808BCF4();
    DrawDialogueFrame(0, 1);
    PrintApprenticeMessage();
}

static void ApprenticeGetQuestion(void)
{
    if (PLAYER_APPRENTICE.questionsAnswered < NUM_WHICH_MON_QUESTIONS)
    {
        gSpecialVar_Result = APPRENTICE_QUESTION_WHICH_MON;
    }
    else if (PLAYER_APPRENTICE.questionsAnswered > (APPRENTICE_MAX_QUESTIONS + NUM_WHICH_MON_QUESTIONS - 1))
    {
        gSpecialVar_Result = APPRENTICE_QUESTION_WIN_SPEECH;
    }
    else
    {
        s32 id = CURRENT_QUESTION_NUM;
        switch (PLAYER_APPRENTICE.questions[id].questionId)
        {
        case QUESTION_ID_WHAT_ITEM:
            gSpecialVar_Result = APPRENTICE_QUESTION_WHAT_ITEM;
            break;
        case QUESTION_ID_WHICH_MOVE:
            gSpecialVar_Result = APPRENTICE_QUESTION_WHICH_MOVE;
            break;
        case QUESTION_ID_WHICH_FIRST:
            gSpecialVar_Result = APPRENTICE_QUESTION_WHICH_FIRST;
            break;
        default:
      //case QUESTION_ID_WIN_SPEECH:  
            gSpecialVar_Result = APPRENTICE_QUESTION_WIN_SPEECH;
            break;
        }
    }
}

// gSpecialVar_0x8005 is 0 or 1 for the mon selection (0 is already on the team)
// gSpecialVar_0x8006 is 0-2 for the number of party mons selected so far
static void SetApprenticePartyMon(void)
{
    if (gSpecialVar_0x8005)
    {
        u8 partySlot = gSpecialVar_0x8006;
        PLAYER_APPRENTICE.party |= 1 << partySlot;
    }
}

// gSpecialVar_0x8005 is 0 or 1 for the move selection
// Selection 0 is implicitly the default move assigned
static void SetApprenticeMonMove(void)
{
    if (PLAYER_APPRENTICE.questionsAnswered >= NUM_WHICH_MON_QUESTIONS)
    {
        u8 id = CURRENT_QUESTION_NUM;
        if (gSpecialVar_0x8005)
            PLAYER_APPRENTICE.questions[id].suggestedChange = TRUE;
        else
            PLAYER_APPRENTICE.questions[id].suggestedChange = FALSE;
    }
}

static void InitQuestionData(void)
{
    u8 i;
    u8 count = 0;
    u8 id1, id2;

    for (i = 0; i < APPRENTICE_MAX_QUESTIONS && (PLAYER_APPRENTICE.questions[i].questionId != QUESTION_ID_WIN_SPEECH); count++, i++)
        ;

    gApprenticeQuestionData = AllocZeroed(sizeof(*gApprenticeQuestionData));
    if (gSpecialVar_0x8005 == APPRENTICE_QUESTION_WHICH_MON)
    {
        if (PLAYER_APPRENTICE.questionsAnswered < NUM_WHICH_MON_QUESTIONS)
        {
            // For the first MULTI_PARTY_SIZE (3) questions, a mon is asked to be selected for the Apprentice's party
            id1 = PLAYER_APPRENTICE.speciesIds[PLAYER_APPRENTICE.questionsAnswered] >> 4;
            gApprenticeQuestionData->altSpeciesId = gApprentices[PLAYER_APPRENTICE.id].species[id1];

            id2 = PLAYER_APPRENTICE.speciesIds[PLAYER_APPRENTICE.questionsAnswered] & 0xF;
            gApprenticeQuestionData->speciesId = gApprentices[PLAYER_APPRENTICE.id].species[id2];
        }
    }
    else if (gSpecialVar_0x8005 == APPRENTICE_QUESTION_WHICH_MOVE)
    {
        if (PLAYER_APPRENTICE.questionsAnswered >= NUM_WHICH_MON_QUESTIONS
            && PLAYER_APPRENTICE.questionsAnswered < count + NUM_WHICH_MON_QUESTIONS
            && PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].questionId == QUESTION_ID_WHICH_MOVE)
        {
            // count re-used as monId
            count = PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].monId;
            APPRENTICE_SPECIES_ID_2(id1, count);
            gApprenticeQuestionData->speciesId = gApprentices[PLAYER_APPRENTICE.id].species[id1];
            gApprenticeQuestionData->moveId1 = GetDefaultMove(count, id1, PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].moveSlot);
            gApprenticeQuestionData->moveId2 = PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].data;
        }
    }
    else if (gSpecialVar_0x8005 == APPRENTICE_QUESTION_WHAT_ITEM)
    {
        if (PLAYER_APPRENTICE.questionsAnswered >= NUM_WHICH_MON_QUESTIONS
            && PLAYER_APPRENTICE.questionsAnswered < count + NUM_WHICH_MON_QUESTIONS
            && PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].questionId == QUESTION_ID_WHAT_ITEM)
        {
            // count re-used as monId
            count = PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].monId;
            APPRENTICE_SPECIES_ID_2(id2, count);
            gApprenticeQuestionData->speciesId = gApprentices[PLAYER_APPRENTICE.id].species[id2];
        }
    }
}

static void FreeQuestionData(void)
{
    FREE_AND_SET_NULL(gApprenticeQuestionData);
}

static void ApprenticeBufferString(void)
{
    u8 *stringDst;
    u8 text[16];
    u32 speciesArrayId;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        stringDst = gStringVar1;
        break;
    case 1:
        stringDst = gStringVar2;
        break;
    case 2:
        stringDst = gStringVar3;
        break;
    default:
        return;
    }

    switch (gSpecialVar_0x8006)
    {
    case APPRENTICE_BUFF_SPECIES1:
        StringCopy(stringDst, gSpeciesNames[gApprenticeQuestionData->speciesId]);
        break;
    case APPRENTICE_BUFF_SPECIES2:
        StringCopy(stringDst, gSpeciesNames[gApprenticeQuestionData->altSpeciesId]);
        break;
    case APPRENTICE_BUFF_SPECIES3:
        StringCopy(stringDst, gSpeciesNames[gApprenticeQuestionData->speciesId]);
        break;
    case APPRENTICE_BUFF_MOVE1:
        StringCopy(stringDst, gMoveNames[gApprenticeQuestionData->moveId1]);
        break;
    case APPRENTICE_BUFF_MOVE2:
        StringCopy(stringDst, gMoveNames[gApprenticeQuestionData->moveId2]);
        break;
    case APPRENTICE_BUFF_ITEM:
        StringCopy(stringDst, ItemId_GetName(PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].data));
        break;
    case APPRENTICE_BUFF_NAME:
        TVShowConvertInternationalString(text, GetApprenticeNameInLanguage(PLAYER_APPRENTICE.id, LANGUAGE_ENGLISH), LANGUAGE_ENGLISH);
        StringCopy(stringDst, text);
        break;
    case APPRENTICE_BUFF_LEVEL:
        if (PLAYER_APPRENTICE.lvlMode == APPRENTICE_LVL_MODE_50)
            StringCopy(stringDst, gText_Lv50);
        else // == APPRENTICE_LVL_MODE_OPEN
            StringCopy(stringDst, gText_OpenLevel);
        break;
    case APPRENTICE_BUFF_WIN_SPEECH:
        FrontierSpeechToString(gSaveBlock2Ptr->apprentices[0].speechWon);
        StringCopy(stringDst, gStringVar4);
        break;
    case APPRENTICE_BUFF_LEAD_MON_SPECIES:
        if (PLAYER_APPRENTICE.leadMonId < MULTI_PARTY_SIZE)
        {
            APPRENTICE_SPECIES_ID(speciesArrayId, PLAYER_APPRENTICE.leadMonId);
        }
        else
        {
            speciesArrayId = 0;
        }
        StringCopy(stringDst, gSpeciesNames[gApprentices[PLAYER_APPRENTICE.id].species[speciesArrayId]]);
        break;
    }
}

static void SetLeadApprenticeMon(void)
{
    PLAYER_APPRENTICE.leadMonId = gSpecialVar_0x8005;
}

static void Script_ApprenticeOpenBagMenu(void)
{
    ApprenticeOpenBagMenu();
}

static void TrySetApprenticeHeldItem(void)
{
    u8 i, j;
    u8 count;

    if (PLAYER_APPRENTICE.questionsAnswered < NUM_WHICH_MON_QUESTIONS)
        return;

    for (count = 0, j = 0; j < APPRENTICE_MAX_QUESTIONS && PLAYER_APPRENTICE.questions[j].questionId != QUESTION_ID_WIN_SPEECH; count++, j++)
        ;

    // Make sure the item hasnt already been suggested in previous questions
    for (i = 0; i < count && i < CURRENT_QUESTION_NUM; i++)
    {
        do {} while(0);
        if (PLAYER_APPRENTICE.questions[i].questionId == QUESTION_ID_WHAT_ITEM
            && PLAYER_APPRENTICE.questions[i].suggestedChange
            && PLAYER_APPRENTICE.questions[i].data == gSpecialVar_0x8005)
        {
            PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].suggestedChange = FALSE;
            PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].data = gSpecialVar_0x8005;
            gSpecialVar_Result = FALSE;
            return;
        }
    }

    PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].suggestedChange = TRUE;
    PLAYER_APPRENTICE.questions[CURRENT_QUESTION_NUM].data = gSpecialVar_0x8005;
    gSpecialVar_Result = TRUE;
}

static void ShiftSavedApprentices(void)
{
    s32 i;
    s32 apprenticeNum;
    s32 apprenticeIdx;

    if (gSaveBlock2Ptr->apprentices[0].playerName[0] == EOS)
        return;

    for (i = 0; i < APPRENTICE_COUNT - 1; i++)
    {
        if (gSaveBlock2Ptr->apprentices[i + 1].playerName[0] == EOS)
        {
            gSaveBlock2Ptr->apprentices[i + 1] = gSaveBlock2Ptr->apprentices[0];
            return;
        }
    }

    apprenticeNum = 0xFFFF;
    apprenticeIdx = -1;
    for (i = 1; i < APPRENTICE_COUNT; i++)
    {
        if (GetTrainerId(gSaveBlock2Ptr->apprentices[i].playerId) == GetTrainerId(gSaveBlock2Ptr->playerTrainerId)
            && gSaveBlock2Ptr->apprentices[i].number < apprenticeNum)
        {
            apprenticeNum = gSaveBlock2Ptr->apprentices[i].number;
            apprenticeIdx = i;
        }
    }

    if (apprenticeIdx > 0)
        gSaveBlock2Ptr->apprentices[apprenticeIdx] = gSaveBlock2Ptr->apprentices[0];
}

// Apprentice is always saved in the first slot. Pre-existing Apprentices are moved by ShiftSavedApprentices
static void SaveApprentice(void)
{
    u8 i;

    gSaveBlock2Ptr->apprentices[0].id = PLAYER_APPRENTICE.id;
    gSaveBlock2Ptr->apprentices[0].lvlMode = PLAYER_APPRENTICE.lvlMode;

    // Count questions asked until the final (win speech) question was reached
    for (i = 0; i < APPRENTICE_MAX_QUESTIONS && (PLAYER_APPRENTICE.questions[i].questionId != QUESTION_ID_WIN_SPEECH); i++)
        ;

    gSaveBlock2Ptr->apprentices[0].numQuestions = i;
    if (gSaveBlock2Ptr->apprentices[0].number < 255)
        gSaveBlock2Ptr->apprentices[0].number++;

    SaveApprenticeParty(gSaveBlock2Ptr->apprentices[0].numQuestions);
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        gSaveBlock2Ptr->apprentices[0].playerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    StringCopy(gSaveBlock2Ptr->apprentices[0].playerName, gSaveBlock2Ptr->playerName);
    gSaveBlock2Ptr->apprentices[0].language = gGameLanguage;
    CalcApprenticeChecksum(&gSaveBlock2Ptr->apprentices[0]);
}

// Never called, APPRENTICE_FUNC_SET_GFX_SAVED is unused
static void SetSavedApprenticeTrainerGfxId(void)
{
    u8 i;
    u8 mapObjectGfxId;
    u8 class = gApprentices[gSaveBlock2Ptr->apprentices[0].id].facilityClass;

    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses) && gTowerMaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        mapObjectGfxId = gTowerMaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses) && gTowerFemaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        mapObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
    }
}

static void SetPlayerApprenticeTrainerGfxId(void)
{
    u8 i;
    u8 mapObjectGfxId;
    u8 class = gApprentices[PLAYER_APPRENTICE.id].facilityClass;

    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses) && gTowerMaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        mapObjectGfxId = gTowerMaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses) && gTowerFemaleFacilityClasses[i] != class; i++)
        ;
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        mapObjectGfxId = gTowerFemaleTrainerGfxIds[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
    }
}

// Both of the below functions may have been dummied / used for debug
// In all cases theres a conditional for VAR_0x8004 right after the call to these functions
static void GetShouldCheckApprenticeGone(void)
{
    gSpecialVar_0x8004 = TRUE;
}

static void GetShouldApprenticeLeave(void)
{
    gSpecialVar_0x8004 = TRUE;
}

const u8 *GetApprenticeNameInLanguage(u32 apprenticeId, s32 language)
{
    const struct ApprenticeTrainer *apprentice = &gApprentices[apprenticeId];

    switch (language)
    {
    case LANGUAGE_JAPANESE:
        return apprentice->name[0];
    case LANGUAGE_ENGLISH:
        return apprentice->name[1];
    case LANGUAGE_FRENCH:
        return apprentice->name[2];
    case LANGUAGE_ITALIAN:
        return apprentice->name[3];
    case LANGUAGE_GERMAN:
        return apprentice->name[4];
    case LANGUAGE_SPANISH:
    default:
        return apprentice->name[5];
    }
}

// Functionally unused
static void Task_SwitchToFollowupFuncAfterButtonPress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
        SwitchTaskToFollowupFunc(taskId);
}

static void Task_ExecuteFuncAfterButtonPress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        gApprenticeFunc = (void*)(u32)(((u16)gTasks[taskId].data[0] | (gTasks[taskId].data[1] << 16)));
        gApprenticeFunc();
        DestroyTask(taskId);
    }
}

static void ExecuteFuncAfterButtonPress(void (*func)(void))
{
    u8 taskId = CreateTask(Task_ExecuteFuncAfterButtonPress, 1);
    gTasks[taskId].data[0] = (u32)(func);
    gTasks[taskId].data[1] = (u32)(func) >> 16;
}

// Unused
static void ExecuteFollowupFuncAfterButtonPress(TaskFunc task)
{
    u8 taskId = CreateTask(Task_SwitchToFollowupFuncAfterButtonPress, 1);
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchToFollowupFuncAfterButtonPress, task);
}
