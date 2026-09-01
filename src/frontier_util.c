#include "global.h"
#include "frontier_util.h"
#include "easy_chat.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_frontier.h"
#include "battle_special.h"
#include "battle_tower.h"
#include "field_specials.h"
#include "battle.h"
#include "script_pokemon_util.h"
#include "main.h"
#include "window.h"
#include "menu.h"
#include "text.h"
#include "battle_records.h"
#include "international_string_util.h"
#include "string_util.h"
#include "new_game.h"
#include "link.h"
#include "tv.h"
#include "apprentice.h"
#include "pokedex.h"
#include "recorded_battle.h"
#include "data.h"
#include "record_mixing.h"
#include "strings.h"
#include "malloc.h"
#include "save.h"
#include "load_save.h"
#include "battle_dome.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_pike.h"
#include "constants/frontier_util.h"
#include "constants/trainers.h"
#include "constants/game_stat.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/event_objects.h"
#include "party_menu.h"
#include "list_menu.h"

struct FrontierBrainMon
{
    enum Species species;
    enum Item heldItem;
    u8 fixedIV;
    u8 nature;
    u8 evs[NUM_STATS];
    enum Move moves[MAX_MON_MOVES];
};

// This file's functions.
static void GetChallengeStatus(void);
static void GetFrontierData(void);
static void SetFrontierData(void);
static void SetSelectedPartyOrder(void);
static void DoSoftReset_(void);
static void SetFrontierTrainers(void);
static void SaveSelectedParty(void);
static void ShowFacilityResultsWindow(void);
static void CheckPutFrontierTVShowOnAir(void);
static void Script_GetFrontierBrainStatus(void);
static void IsTrainerFrontierBrain(void);
static void GiveBattlePoints(void);
static void GetFacilitySymbolCount(void);
static void GiveFacilitySymbol(void);
static void CheckBattleTypeFlag(void);
static void CheckPartyIneligibility(void);
static void ValidateVisitingTrainer(void);
static void IncrementWinStreak(void);
static void RestoreHeldItems(void);
static void SaveRecordBattle(void);
static void BufferFrontierTrainerName(void);
static void ResetSketchedMoves(void);
static void SetFacilityBrainObjectEvent(void);
static void ShowTowerResultsWindow(u8);
static void ShowDomeResultsWindow(u8);
static void ShowPalaceResultsWindow(u8);
static void ShowPikeResultsWindow(void);
static void ShowFactoryResultsWindow(u8);
static void ShowArenaResultsWindow(void);
static void ShowPyramidResultsWindow(void);
static void ShowLinkContestResultsWindow(void);
static void CopyFrontierBrainText(bool8 playerWonText);
static u16 *MakeCaughtBannedSpeciesList(u32 totalBannedSpecies);
static void PrintBannedSpeciesName(u8 windowId, u32 itemId, u8 y);
static void Task_BannedSpeciesWindowInput(u8 taskId);

// battledBit: Flags to change the conversation when the Frontier Brain is encountered for a battle
// First bit is has battled them before and not won yet, second bit is has battled them and won (obtained a Symbol)
const struct FrontierBrain gFrontierBrainInfo[NUM_FRONTIER_FACILITIES] =
{
    [FRONTIER_FACILITY_TOWER] =
    {
        .trainerId = TRAINER_ANABEL,
        .objEventGfx = OBJ_EVENT_GFX_ANABEL,
        .isFemale = TRUE,
        .lostTexts = {
            COMPOUND_STRING("Okay, I understand…"), //Silver
            COMPOUND_STRING("Thank you…")           //Gold
        },
        .wonTexts = {
            COMPOUND_STRING("It's very disappointing…"), //Silver
            COMPOUND_STRING("I'm terribly sorry…")       //Gold
        },
        .battledBit = {1 << 0, 1 << 1},
        .streakAppearances = {35, 70, 35, 1},
        .goldSymbolFlag = FLAG_SYS_TOWER_GOLD,
        .silverSymbolFlag = FLAG_SYS_TOWER_SILVER,
    },
    [FRONTIER_FACILITY_DOME] =
    {
        .trainerId = TRAINER_TUCKER,
        .objEventGfx = OBJ_EVENT_GFX_TUCKER,
        .isFemale = FALSE,
        .lostTexts = {
            COMPOUND_STRING(
                "Grr…\n"
                "What the…"),        //Silver
            COMPOUND_STRING(
                "Ahahaha!\n"
                "You're inspiring!") //Gold
        },
        .wonTexts = {
            COMPOUND_STRING(
                "Ahahaha! Aren't you embarrassed?\n"
                "Everyone's watching!"),                              //Silver
            COMPOUND_STRING("My DOME ACE title isn't just for show!") //Gold
        },
        .battledBit = {1 << 2, 1 << 3},
        .streakAppearances = {4, 9, 5, 0},
        .goldSymbolFlag = FLAG_SYS_DOME_GOLD,
        .silverSymbolFlag = FLAG_SYS_DOME_SILVER,
    },
    [FRONTIER_FACILITY_PALACE] =
    {
        .trainerId = TRAINER_SPENSER,
        .objEventGfx = OBJ_EVENT_GFX_SPENSER,
        .isFemale = FALSE,
        .lostTexts = {
            COMPOUND_STRING(
                "Ah…\n"
                "Now this is something else…"), //Silver
            COMPOUND_STRING(
                "Gwah!\n"
                "Hahahaha!")                    //Gold
        },
        .wonTexts = {
            COMPOUND_STRING(
                "Your POKéMON are wimpy because\n"
                "you're wimpy as a TRAINER!"),           //Silver
            COMPOUND_STRING(
                "Gwahahaha!\n"
                "My brethren, we have nothing to fear!") //Gold
        },
        .battledBit = {1 << 4, 1 << 5},
        .streakAppearances = {21, 42, 21, 1},
        .goldSymbolFlag = FLAG_SYS_PALACE_GOLD,
        .silverSymbolFlag = FLAG_SYS_PALACE_SILVER,
    },
    [FRONTIER_FACILITY_ARENA] =
    {
        .trainerId = TRAINER_GRETA,
        .objEventGfx = OBJ_EVENT_GFX_GRETA,
        .isFemale = TRUE,
        .lostTexts = {
            COMPOUND_STRING(
                "No way!\n"
                "Good job!"),        //Silver
            COMPOUND_STRING(
                "Huh?\n"
                "Are you serious?!") //Gold
        },
        .wonTexts = {
            COMPOUND_STRING(
                "Oh, come on!\n"
                "You have to try harder than that!"), //Silver
            COMPOUND_STRING(
                "Heheh!\n"
                "What did you expect?")               //Gold
        },
        .battledBit = {1 << 6, 1 << 7},
        .streakAppearances = {28, 56, 28, 1},
        .goldSymbolFlag = FLAG_SYS_ARENA_GOLD,
        .silverSymbolFlag = FLAG_SYS_ARENA_SILVER,
    },
    [FRONTIER_FACILITY_FACTORY] =
    {
        .trainerId = TRAINER_NOLAND,
        .objEventGfx = OBJ_EVENT_GFX_NOLAND,
        .isFemale = FALSE,
        .lostTexts = {
            COMPOUND_STRING(
                "Good job!\n"
                "You know what you're doing!"),    //Silver
            COMPOUND_STRING("What happened here?") //Gold
        },
        .wonTexts = {
            COMPOUND_STRING(
                "Way to work!\n"
                "That was a good lesson, eh?"), //Silver
            COMPOUND_STRING(
                "Hey, hey, hey!\n"
                "You're finished already?")     //Gold
        },
        .battledBit = {1 << 8, 1 << 9},
        .streakAppearances = {21, 42, 21, 1},
        .goldSymbolFlag = FLAG_SYS_FACTORY_GOLD,
        .silverSymbolFlag = FLAG_SYS_FACTORY_SILVER,
    },
    [FRONTIER_FACILITY_PIKE] =
    {
        .trainerId = TRAINER_LUCY,
        .objEventGfx = OBJ_EVENT_GFX_LUCY,
        .isFemale = TRUE,
        .lostTexts = {
            COMPOUND_STRING("Urk…"), //Silver
            COMPOUND_STRING("Darn!") //Gold
        },
        .wonTexts = {
            COMPOUND_STRING("Humph…"), //Silver
            COMPOUND_STRING("Hah!")    //Gold
        },
        .battledBit = {1 << 10, 1 << 11},
        .streakAppearances = {28, 140, 56, 1},
        .goldSymbolFlag = FLAG_SYS_PIKE_GOLD,
        .silverSymbolFlag = FLAG_SYS_PIKE_SILVER,
    },
    [FRONTIER_FACILITY_PYRAMID] =
    {
        .trainerId = TRAINER_BRANDON,
        .objEventGfx = OBJ_EVENT_GFX_BRANDON,
        .isFemale = FALSE,
        .lostTexts = {
            COMPOUND_STRING(
                "That's it! You've done great!\n"
                "You've worked hard for this!"), //Silver
            COMPOUND_STRING(
                "That's it! You've done it!\n"
                "You kept working for this!")    //Gold
        },
        .wonTexts = {
            COMPOUND_STRING(
                "Hey! What's wrong with you!\n"
                "Let's see some effort! Get up!"),       //Silver
            COMPOUND_STRING(
                "Hey! Don't you give up now!\n"
                "Get up! Don't lose faith in yourself!") //Gold
        },
        .battledBit = {1 << 12, 1 << 13},
        .streakAppearances = {21, 70, 35, 0},
        .goldSymbolFlag = FLAG_SYS_PYRAMID_GOLD,
        .silverSymbolFlag = FLAG_SYS_PYRAMID_SILVER,
    },
};

static const struct FrontierBrainMon sFrontierBrainsMons[][2][FRONTIER_PARTY_SIZE] =
{
    [FRONTIER_FACILITY_TOWER] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_ALAKAZAM,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 24,
                .nature = NATURE_MODEST,
                .evs = {106, 0, 152, 152, 100, 0},
                .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_DISABLE},
            },
            {
                .species = SPECIES_ENTEI,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 24,
                .nature = NATURE_LONELY,
                .evs = {100, 152, 152, 0, 100, 6},
                .moves = {MOVE_FIRE_BLAST, MOVE_CALM_MIND, MOVE_RETURN, MOVE_ROAR},
            },
            {
                .species = SPECIES_SNORLAX,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 24,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 0, 0, 106, 100},
                .moves = {MOVE_BODY_SLAM, MOVE_BELLY_DRUM, MOVE_YAWN, MOVE_SHADOW_BALL},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_RAIKOU,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {158, 0, 252, 100, 0, 0},
                .moves = {MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_REFLECT, MOVE_REST},
            },
            {
                .species = SPECIES_LATIOS,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {252, 0, 252, 6, 0, 0},
                .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_RECOVER, MOVE_DRAGON_CLAW},
            },
            {
                .species = SPECIES_SNORLAX,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {252, 252, 0, 0, 6, 0},
                .moves = {MOVE_CURSE, MOVE_RETURN, MOVE_REST, MOVE_SHADOW_BALL},
            },
        },
    },
    [FRONTIER_FACILITY_DOME] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_SWAMPERT,
                .heldItem = ITEM_FOCUS_BAND,
                .fixedIV = 20,
                .nature = NATURE_BRAVE,
                .evs = {152, 152, 106, 0, 100, 0},
                .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_COUNTER},
            },
            {
                .species = SPECIES_SALAMENCE,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 20,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 106, 100, 0, 0},
                .moves = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE},
            },
            {
                .species = SPECIES_CHARIZARD,
                .heldItem = ITEM_WHITE_HERB,
                .fixedIV = 20,
                .nature = NATURE_QUIET,
                .evs = {100, 152, 106, 152, 0, 0},
                .moves = {MOVE_OVERHEAT, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_SWAMPERT,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {252, 252, 6, 0, 0, 0},
                .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
            },
            {
                .species = SPECIES_METAGROSS,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {252, 252, 6, 0, 0, 0},
                .moves = {MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_PROTECT},
            },
            {
                .species = SPECIES_LATIAS,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {252, 0, 252, 6, 0, 0},
                .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_REST},
            },
        },
    },
    [FRONTIER_FACILITY_PALACE] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_CROBAT,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 16,
                .nature = NATURE_ADAMANT,
                .evs = {152, 0, 0, 152, 100, 106},
                .moves = {MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM, MOVE_TOXIC, MOVE_FLY},
            },
            {
                .species = SPECIES_SLAKING,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = 16,
                .nature = NATURE_HARDY,
                .evs = {152, 152, 0, 106, 100, 0},
                .moves = {MOVE_EARTHQUAKE, MOVE_SWAGGER, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
            },
            {
                .species = SPECIES_LAPRAS,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 16,
                .nature = NATURE_QUIET,
                .evs = {0, 0, 252, 0, 106, 152},
                .moves = {MOVE_ICE_BEAM, MOVE_HORN_DRILL, MOVE_CONFUSE_RAY, MOVE_PROTECT},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_ARCANINE,
                .heldItem = ITEM_WHITE_HERB,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_HASTY,
                .evs = {6, 252, 252, 0, 0, 0},
                .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_ROAR, MOVE_PROTECT},
            },
            {
                .species = SPECIES_SLAKING,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_HARDY,
                .evs = {6, 252, 0, 252, 0, 0},
                .moves = {MOVE_HYPER_BEAM, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_YAWN},
            },
            {
                .species = SPECIES_SUICUNE,
                .heldItem = ITEM_KINGS_ROCK,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_HASTY,
                .evs = {252, 0, 252, 6, 0, 0},
                .moves = {MOVE_BLIZZARD, MOVE_SURF, MOVE_BITE, MOVE_CALM_MIND},
            },
        },
    },
    [FRONTIER_FACILITY_ARENA] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_HERACROSS,
                .heldItem = ITEM_SALAC_BERRY,
                .fixedIV = 20,
                .nature = NATURE_JOLLY,
                .evs = {106, 152, 0, 152, 0, 100},
                .moves = {MOVE_MEGAHORN, MOVE_ROCK_TOMB, MOVE_ENDURE, MOVE_REVERSAL},
            },
            {
                .species = SPECIES_UMBREON,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 20,
                .nature = NATURE_CALM,
                .evs = {152, 0, 100, 0, 152, 106},
                .moves = {MOVE_BODY_SLAM, MOVE_CONFUSE_RAY, MOVE_PSYCHIC, MOVE_FEINT_ATTACK},
            },
            {
                .species = SPECIES_SHEDINJA,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 20,
                .nature = NATURE_ADAMANT,
                .evs = {0, 252, 6, 252, 0, 0},
                .moves = {MOVE_SHADOW_BALL, MOVE_RETURN, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_UMBREON,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_CALM,
                .evs = {252, 0, 0, 0, 252, 6},
                .moves = {MOVE_DOUBLE_EDGE, MOVE_CONFUSE_RAY, MOVE_REST, MOVE_PSYCHIC},
            },
            {
                .species = SPECIES_GENGAR,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MODEST,
                .evs = {252, 0, 252, 0, 6, 0},
                .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_DESTINY_BOND},
            },
            {
                .species = SPECIES_BRELOOM,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_JOLLY,
                .evs = {6, 252, 0, 252, 0, 0},
                .moves = {MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_GIGA_DRAIN, MOVE_HEADBUTT},
            },
        },
    },
    [FRONTIER_FACILITY_FACTORY] =
    {
        // Because Factory's Pokémon are random, this facility's Brain also uses random Pokémon.
        // What is interesting, this team is actually the one Steven uses in the multi tag battle alongside the player.
        {
            {
                .species = SPECIES_METANG,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {0, 252, 252, 0, 6, 0},
                .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
            },
            {
                .species = SPECIES_SKARMORY,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_IMPISH,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
            },
            {
                .species = SPECIES_AGGRON,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {0, 252, 0, 0, 252, 6},
                .moves = {MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
            },
        },
        {
            {
                .species = SPECIES_METANG,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {0, 252, 252, 0, 6, 0},
                .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
            },
            {
                .species = SPECIES_SKARMORY,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_IMPISH,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
            },
            {
                .species = SPECIES_AGGRON,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {0, 252, 0, 0, 252, 6},
                .moves = {MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
            },
        },
    },
    [FRONTIER_FACILITY_PIKE] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_SEVIPER,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 16,
                .nature = NATURE_BRAVE,
                .evs = {252, 0, 252, 0, 6, 0},
                .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_POISON_FANG, MOVE_GIGA_DRAIN},
            },
            {
                .species = SPECIES_SHUCKLE,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 16,
                .nature = NATURE_BOLD,
                .evs = {252, 0, 0, 0, 106, 252},
                .moves = {MOVE_TOXIC, MOVE_SANDSTORM, MOVE_PROTECT, MOVE_REST},
            },
            {
                .species = SPECIES_MILOTIC,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 16,
                .nature = NATURE_MODEST,
                .evs = {152, 0, 100, 0, 152, 106},
                .moves = {MOVE_ICE_BEAM, MOVE_MIRROR_COAT, MOVE_SURF, MOVE_RECOVER},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_SEVIPER,
                .heldItem = ITEM_FOCUS_BAND,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BOLD,
                .evs = {252, 0, 0, 0, 252, 6},
                .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN},
            },
            {
                .species = SPECIES_STEELIX,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_BRAVE,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_SCREECH},
            },
            {
                .species = SPECIES_GYARADOS,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_ADAMANT,
                .evs = {252, 6, 0, 0, 0, 252},
                .moves = {MOVE_DRAGON_DANCE, MOVE_RETURN, MOVE_ROAR, MOVE_REST},
            },
        },
    },
    [FRONTIER_FACILITY_PYRAMID] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_REGIROCK,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 16,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 0, 0, 106, 100},
                .moves = {MOVE_EXPLOSION, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER},
            },
            {
                .species = SPECIES_REGISTEEL,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 16,
                .nature = NATURE_ADAMANT,
                .evs = {152, 152, 0, 0, 6, 200},
                .moves = {MOVE_EARTHQUAKE, MOVE_METAL_CLAW, MOVE_TOXIC, MOVE_IRON_DEFENSE},
            },
            {
                .species = SPECIES_REGICE,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 16,
                .nature = NATURE_MODEST,
                .evs = {106, 0, 152, 0, 100, 152},
                .moves = {MOVE_ICE_BEAM, MOVE_AMNESIA, MOVE_THUNDER, MOVE_REST},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_ARTICUNO,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MILD,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_AERIAL_ACE, MOVE_REFLECT},
            },
            {
                .species = SPECIES_ZAPDOS,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MILD,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_THUNDER, MOVE_DETECT, MOVE_DRILL_PECK, MOVE_LIGHT_SCREEN},
            },
            {
                .species = SPECIES_MOLTRES,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = MAX_PER_STAT_IVS,
                .nature = NATURE_MILD,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_BEAM, MOVE_AERIAL_ACE, MOVE_SAFEGUARD},
            },
        },
    },
};

static const u8 sBattlePointAwards[NUM_FRONTIER_FACILITIES][FRONTIER_MODE_COUNT][30] =
{
    /* facility, mode, tier */
    [FRONTIER_FACILITY_TOWER] = /* Tier: 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 */
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_MULTIS]      = {  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_LINK_MULTIS] = {  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_DOME] =
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15 },
    },
    [FRONTIER_FACILITY_PALACE] =
    {
        [FRONTIER_MODE_SINGLES]     = {  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_ARENA] =
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  1,  1,  2,  2,  2,  3,  3,  4,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_FACTORY] =
    {
        [FRONTIER_MODE_SINGLES]     = {  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15 },
        [FRONTIER_MODE_DOUBLES]     = {  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_PIKE] =
    {
        [FRONTIER_MODE_SINGLES]     = {  1,  1,  2,  2,  2,  4,  4,  4,  8,  8,  8,  8, 10, 10, 10, 10, 12, 12, 12, 12, 12, 14, 14, 14, 14, 15, 15, 15, 15, 15 },
    },
    [FRONTIER_FACILITY_PYRAMID] =
    {
        [FRONTIER_MODE_SINGLES]     = {  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
    },
};

static void (*const sFrontierUtilFuncs[])(void) =
{
    [FRONTIER_UTIL_FUNC_GET_STATUS]            = GetChallengeStatus,
    [FRONTIER_UTIL_FUNC_GET_DATA]              = GetFrontierData,
    [FRONTIER_UTIL_FUNC_SET_DATA]              = SetFrontierData,
    [FRONTIER_UTIL_FUNC_SET_PARTY_ORDER]       = SetSelectedPartyOrder,
    [FRONTIER_UTIL_FUNC_SOFT_RESET]            = DoSoftReset_,
    [FRONTIER_UTIL_FUNC_SET_TRAINERS]          = SetFrontierTrainers,
    [FRONTIER_UTIL_FUNC_SAVE_PARTY]            = SaveSelectedParty,
    [FRONTIER_UTIL_FUNC_RESULTS_WINDOW]        = ShowFacilityResultsWindow,
    [FRONTIER_UTIL_FUNC_CHECK_AIR_TV_SHOW]     = CheckPutFrontierTVShowOnAir,
    [FRONTIER_UTIL_FUNC_GET_BRAIN_STATUS]      = Script_GetFrontierBrainStatus,
    [FRONTIER_UTIL_FUNC_IS_BRAIN]              = IsTrainerFrontierBrain,
    [FRONTIER_UTIL_FUNC_GIVE_BATTLE_POINTS]    = GiveBattlePoints,
    [FRONTIER_UTIL_FUNC_GET_FACILITY_SYMBOLS]  = GetFacilitySymbolCount,
    [FRONTIER_UTIL_FUNC_GIVE_FACILITY_SYMBOL]  = GiveFacilitySymbol,
    [FRONTIER_UTIL_FUNC_CHECK_BATTLE_TYPE]     = CheckBattleTypeFlag,
    [FRONTIER_UTIL_FUNC_CHECK_INELIGIBLE]      = CheckPartyIneligibility,
    [FRONTIER_UTIL_FUNC_CHECK_VISIT_TRAINER]   = ValidateVisitingTrainer,
    [FRONTIER_UTIL_FUNC_INCREMENT_STREAK]      = IncrementWinStreak,
    [FRONTIER_UTIL_FUNC_RESTORE_HELD_ITEMS]    = RestoreHeldItems,
    [FRONTIER_UTIL_FUNC_SAVE_BATTLE]           = SaveRecordBattle,
    [FRONTIER_UTIL_FUNC_BUFFER_TRAINER_NAME]   = BufferFrontierTrainerName,
    [FRONTIER_UTIL_FUNC_RESET_SKETCH_MOVES]    = ResetSketchedMoves,
    [FRONTIER_UTIL_FUNC_SET_BRAIN_OBJECT]      = SetFacilityBrainObjectEvent,
};

static const struct WindowTemplate sFrontierResultsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 18,
    .paletteNum = 15,
    .baseBlock = 1
};

static const struct WindowTemplate sLinkContestResultsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 2,
    .width = 26,
    .height = 15,
    .paletteNum = 15,
    .baseBlock = 1
};

static const struct WindowTemplate sRankingHallRecordsWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 1,
    .width = 26,
    .height = 17,
    .paletteNum = 15,
    .baseBlock = 1
};

static const u8 *const sRecordsWindowChallengeTexts[][2] =
{
    [RANKING_HALL_TOWER_SINGLES] = {gText_BattleTower2,  gText_FacilitySingle},
    [RANKING_HALL_TOWER_DOUBLES] = {gText_BattleTower2,  gText_FacilityDouble},
    [RANKING_HALL_TOWER_MULTIS]  = {gText_BattleTower2,  gText_FacilityMulti},
    [RANKING_HALL_DOME]          = {gText_BattleDome,    gText_FacilitySingle},
    [RANKING_HALL_PALACE]        = {gText_BattlePalace,  gText_FacilitySingle},
    [RANKING_HALL_ARENA]         = {gText_BattleArena,   gText_Facility},
    [RANKING_HALL_FACTORY]       = {gText_BattleFactory, gText_FacilitySingle},
    [RANKING_HALL_PIKE]          = {gText_BattlePike,    gText_Facility},
    [RANKING_HALL_PYRAMID]       = {gText_BattlePyramid, gText_Facility},
    [RANKING_HALL_TOWER_LINK]    = {gText_BattleTower2,  gText_FacilityLink},
};

static const u8 *const sLevelModeText[] =
{
    [FRONTIER_LVL_50]   = gText_RecordsLv50,
    [FRONTIER_LVL_OPEN] = gText_RecordsOpenLevel,
};

static const u8 *const sHallFacilityToRecordsText[] =
{
    [RANKING_HALL_TOWER_SINGLES] = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_TOWER_DOUBLES] = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_TOWER_MULTIS]  = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_DOME]          = gText_FrontierFacilityClearStreak,
    [RANKING_HALL_PALACE]        = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_ARENA]         = gText_FrontierFacilityKOsStreak,
    [RANKING_HALL_FACTORY]       = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_PIKE]          = gText_FrontierFacilityRoomsCleared,
    [RANKING_HALL_PYRAMID]       = gText_FrontierFacilityFloorsCleared,
    [RANKING_HALL_TOWER_LINK]    = gText_FrontierFacilityWinStreak,
};

// Trainer ID ranges for possible frontier trainers to encounter on particular challenges
// Trainers are scaled by difficulty, so higher trainer IDs have better teams
static const u16 sFrontierTrainerIdRanges[][2] =
{
    {FRONTIER_TRAINER_BRADY,   FRONTIER_TRAINER_JILL},   //   0 -  99
    {FRONTIER_TRAINER_TREVIN,  FRONTIER_TRAINER_CHLOE},  //  80 - 119
    {FRONTIER_TRAINER_ERIK,    FRONTIER_TRAINER_SOFIA},  // 100 - 139
    {FRONTIER_TRAINER_NORTON,  FRONTIER_TRAINER_JAZLYN}, // 120 - 159
    {FRONTIER_TRAINER_BRADEN,  FRONTIER_TRAINER_ALISON}, // 140 - 179
    {FRONTIER_TRAINER_ZACHERY, FRONTIER_TRAINER_LAMAR},  // 160 - 199
    {FRONTIER_TRAINER_HANK,    FRONTIER_TRAINER_TESS},   // 180 - 219
    {FRONTIER_TRAINER_JAXON,   FRONTIER_TRAINER_GRETEL}, // 200 - 299
};

static const u16 sFrontierTrainerIdRangesHard[][2] =
{
    {FRONTIER_TRAINER_ERIK,    FRONTIER_TRAINER_CHLOE},  // 100 - 119
    {FRONTIER_TRAINER_NORTON,  FRONTIER_TRAINER_SOFIA},  // 120 - 139
    {FRONTIER_TRAINER_BRADEN,  FRONTIER_TRAINER_JAZLYN}, // 140 - 159
    {FRONTIER_TRAINER_ZACHERY, FRONTIER_TRAINER_ALISON}, // 160 - 179
    {FRONTIER_TRAINER_HANK,    FRONTIER_TRAINER_LAMAR},  // 180 - 199
    {FRONTIER_TRAINER_JAXON,   FRONTIER_TRAINER_TESS},   // 200 - 219
    {FRONTIER_TRAINER_LEON,    FRONTIER_TRAINER_RAUL},   // 220 - 239
    {FRONTIER_TRAINER_JAXON,   FRONTIER_TRAINER_GRETEL}, // 200 - 299
};

#define BANNED_SPECIES_SHOWN 6

static const struct ListMenuTemplate sCaughtBannedSpeciesListTemplate =
{
    .items = NULL,
    .isDynamic = TRUE,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = PrintBannedSpeciesName,
    .maxShowed = BANNED_SPECIES_SHOWN,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = 0
};

static const struct WindowTemplate sBannedSpeciesWindowTemplateMain =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 12,
    .height = 2 * BANNED_SPECIES_SHOWN,
    .paletteNum = 15,
    .baseBlock = 1,
};

#define TAG_LIST_ARROWS 5425

static const struct ScrollArrowsTemplate sCaughtBannedSpeciesScrollArrowsTemplate =
{
    .firstArrowType = SCROLL_ARROW_UP,
    .firstX = 56,
    .firstY = 8,
    .secondArrowType = SCROLL_ARROW_DOWN,
    .secondX = 56,
    .secondY = 104,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 0,
    .tileTag = TAG_LIST_ARROWS,
    .palTag = TAG_LIST_ARROWS,
    .palNum = 0,
};

// code
void CallFrontierUtilFunc(void)
{
    sFrontierUtilFuncs[gSpecialVar_0x8004]();
}

// VAR_TEMP_CHALLENGE_STATUS is used to react to the status in OnFrame map scripts
static void GetChallengeStatus(void)
{
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0xFF);
    switch (gSaveBlock2Ptr->frontier.challengeStatus)
    {
    case 0:
        break;
    case CHALLENGE_STATUS_SAVING:
        FrontierGamblerSetWonOrLost(FALSE);
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock2Ptr->frontier.challengeStatus);
        break;
    case CHALLENGE_STATUS_LOST:
        FrontierGamblerSetWonOrLost(FALSE);
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock2Ptr->frontier.challengeStatus);
        break;
    case CHALLENGE_STATUS_WON:
        FrontierGamblerSetWonOrLost(TRUE);
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock2Ptr->frontier.challengeStatus);
        break;
    case CHALLENGE_STATUS_PAUSED:
        VarSet(VAR_TEMP_CHALLENGE_STATUS, gSaveBlock2Ptr->frontier.challengeStatus);
        break;
    }
}

static void GetFrontierData(void)
{
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 hasSymbol = GetPlayerSymbolCountForFacility(facility);
    if (hasSymbol == 2)
        hasSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case FRONTIER_DATA_CHALLENGE_STATUS:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.challengeStatus;
        break;
    case FRONTIER_DATA_LVL_MODE:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    case FRONTIER_DATA_BATTLE_NUM:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
        break;
    case FRONTIER_DATA_PAUSED:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.challengePaused;
        break;
    case FRONTIER_DATA_BATTLE_OUTCOME:
        gSpecialVar_Result = gBattleOutcome;
        gBattleOutcome = 0;
        break;
    case FRONTIER_DATA_RECORD_DISABLED:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.disableRecordBattle;
        break;
    case FRONTIER_DATA_HEARD_BRAIN_SPEECH:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.battledBrainFlags & gFrontierBrainInfo[facility].battledBit[hasSymbol];
        break;
    }
}

static void SetFrontierData(void)
{
    s32 i;
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 hasSymbol = GetPlayerSymbolCountForFacility(facility);
    if (hasSymbol == 2)
        hasSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case FRONTIER_DATA_CHALLENGE_STATUS:
        gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_LVL_MODE:
        gSaveBlock2Ptr->frontier.lvlMode = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_BATTLE_NUM:
        gSaveBlock2Ptr->frontier.curChallengeBattleNum = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_PAUSED:
        gSaveBlock2Ptr->frontier.challengePaused = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_SELECTED_MON_ORDER:
        for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
            gSaveBlock2Ptr->frontier.selectedPartyMons[i] = gSelectedOrderFromParty[i];
        break;
    case FRONTIER_DATA_RECORD_DISABLED:
        gSaveBlock2Ptr->frontier.disableRecordBattle = gSpecialVar_0x8006;
        break;
    case FRONTIER_DATA_HEARD_BRAIN_SPEECH:
        gSaveBlock2Ptr->frontier.battledBrainFlags |= gFrontierBrainInfo[facility].battledBit[hasSymbol];
        break;
    }
}

static void SetSelectedPartyOrder(void)
{
    s32 i;

    ClearSelectedPartyOrder();
    for (i = 0; i < gSpecialVar_0x8005; i++)
        gSelectedOrderFromParty[i] = gSaveBlock2Ptr->frontier.selectedPartyMons[i];
    ReducePlayerPartyToSelectedMons();
}

static void DoSoftReset_(void)
{
    DoSoftReset();
}

static void SetFrontierTrainers(void)
{
    gFacilityTrainers = gBattleFrontierTrainers;
}

static void SaveSelectedParty(void)
{
    u8 i;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
            SavePlayerPartyMon(gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1, &gParties[B_TRAINER_PLAYER][i]);
    }
}

static void ShowFacilityResultsWindow(void)
{
    if (gSpecialVar_0x8006 >= FRONTIER_MODE_COUNT)
        gSpecialVar_0x8006 = 0;
    switch (gSpecialVar_0x8005)
    {
    case FRONTIER_FACILITY_TOWER:
        ShowTowerResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_DOME:
        ShowDomeResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_PALACE:
        ShowPalaceResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_PIKE:
        ShowPikeResultsWindow();
        break;
    case FRONTIER_FACILITY_FACTORY:
        ShowFactoryResultsWindow(gSpecialVar_0x8006);
        break;
    case FRONTIER_FACILITY_ARENA:
        ShowArenaResultsWindow();
        break;
    case FRONTIER_FACILITY_PYRAMID:
        ShowPyramidResultsWindow();
        break;
    case FACILITY_LINK_CONTEST:
        ShowLinkContestResultsWindow();
        break;
    }
}

static bool8 IsWinStreakActive(u32 challenge)
{
    if (gSaveBlock2Ptr->frontier.winStreakActiveFlags & challenge)
        return TRUE;
    else
        return FALSE;
}

static void PrintAligned(const u8 *str, s32 y)
{
    s32 x = GetStringCenterAlignXOffset(FONT_NORMAL, str, DISPLAY_WIDTH - 16);
    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, y, TEXT_SKIP_DRAW, NULL);
}

static void PrintHyphens(s32 y)
{
    s32 i;
    u8 text[37];

    for (i = 0; i < (int)ARRAY_COUNT(text) - 1; i++)
        text[i] = CHAR_HYPHEN;
    text[i] = EOS;

    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, 4, y, TEXT_SKIP_DRAW, NULL);
}

// Battle Tower records.
static void TowerPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void TowerPrintRecordStreak(u8 battleMode, enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode];
    TowerPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 TowerGetWinStreak(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void TowerPrintPrevOrCurrentStreak(u8 battleMode, enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = TowerGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_DOUBLES_50);
        break;
    case FRONTIER_MODE_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_MULTIS_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_MULTIS_50);
        break;
    case FRONTIER_MODE_LINK_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_TOWER_LINK_MULTIS_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_TOWER_LINK_MULTIS_50);
        break;
    }

    if (isCurrent == TRUE)
        TowerPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        TowerPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowTowerResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_DOUBLES)
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_MULTIS)
        StringExpandPlaceholders(gStringVar4, gText_MultiBattleRoomResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_LinkMultiBattleRoomResults);

    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 16, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 16, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 132, 49);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 132, 65);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 97);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Dome records.
static u16 DomeGetWinStreak(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PrintTwoStrings(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str1, x1, y, TEXT_SKIP_DRAW, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void DomePrintPrevOrCurrentStreak(u8 battleMode, enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = DomeGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_DOME_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_DOME_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_DOME_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_DOME_DOUBLES_50);
        break;
    }

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_ClearStreak, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_ClearStreak, winStreak, x1, x2, y);
}

static void ShowDomeResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleTourneyResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleTourneyResults);

    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 64, 121, 33);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_50], 64, 121, 49);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_50], 64, 112, 65);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 64, 121, 97);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_OPEN], 64, 121, 113);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_OPEN], 64, 112, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Palace records.
static void PalacePrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void PalacePrintRecordStreak(u8 battleMode, enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode];
    PalacePrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PalaceGetWinStreak(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PalacePrintPrevOrCurrentStreak(u8 battleMode, enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PalaceGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_PALACE_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_PALACE_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_PALACE_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_PALACE_DOUBLES_50);
    }

    if (isCurrent == TRUE)
        PalacePrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PalacePrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPalaceResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleHallResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleHallResults);

    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 16, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 16, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 131, 49);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 131, 65);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 97);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Pike records.
static u16 PikeGetWinStreak(enum FrontierLevelMode lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PikePrintCleared(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str1, x1, y, TEXT_SKIP_DRAW, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void PikePrintPrevOrCurrentStreak(enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PikeGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = IsWinStreakActive(STREAK_PIKE_OPEN);
    else
        isCurrent = IsWinStreakActive(STREAK_PIKE_50);

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_RoomsCleared, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_RoomsCleared, winStreak, x1, x2, y);
}

static void ShowPikeResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, gText_BattleChoiceResults);
    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 114, 33);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_50], 64, 114, 49);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_50], 64, 114, 65);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 114, 97);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_OPEN], 64, 114, 113);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_OPEN], 64, 114, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Arena records.
static void ArenaPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_KOsInARow);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void ArenaPrintRecordStreak(enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode];
    ArenaPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 ArenaGetWinStreak(enum FrontierLevelMode lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void ArenaPrintPrevOrCurrentStreak(enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = ArenaGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = IsWinStreakActive(STREAK_ARENA_OPEN);
    else
        isCurrent = IsWinStreakActive(STREAK_ARENA_50);

    if (isCurrent == TRUE)
        ArenaPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        ArenaPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowArenaResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHyphens(10);
    StringExpandPlaceholders(gStringVar4, gText_SetKOTourneyResults);
    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 16, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 16, 97, TEXT_SKIP_DRAW, NULL);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 72, 126, 49);
    ArenaPrintRecordStreak(FRONTIER_LVL_50, 72, 126, 65);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 72, 126, 97);
    ArenaPrintRecordStreak(FRONTIER_LVL_OPEN, 72, 126, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Factory records.
static void FactoryPrintStreak(const u8 *str, u16 num1, u16 num2, u8 x1, u8 x2, u8 x3, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num1 > MAX_STREAK)
        num1 = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num1, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);

    ConvertIntToDecimalStringN(gStringVar1, num2, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_TimesVar1);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x3, y, TEXT_SKIP_DRAW, NULL);
}

static void FactoryPrintRecordStreak(u8 battleMode, enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    u16 num1 = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode];
    u16 num2 = gSaveBlock2Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode];
    FactoryPrintStreak(gText_Record, num1, num2, x1, x2, x3, y);
}

static u16 FactoryGetWinStreak(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static u16 FactoryGetRentsCount(u8 battleMode, enum FrontierLevelMode lvlMode)
{
    u16 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
    if (rents > MAX_STREAK)
        return MAX_STREAK;
    else
        return rents;
}

static void FactoryPrintPrevOrCurrentStreak(u8 battleMode, enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = FactoryGetWinStreak(battleMode, lvlMode);
    u16 rents = FactoryGetRentsCount(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_FACTORY_SINGLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_FACTORY_SINGLES_50);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = IsWinStreakActive(STREAK_FACTORY_DOUBLES_OPEN);
        else
            isCurrent = IsWinStreakActive(STREAK_FACTORY_DOUBLES_50);
        break;
    }

    if (isCurrent == TRUE)
        FactoryPrintStreak(gText_Current, winStreak, rents, x1, x2, x3, y);
    else
        FactoryPrintStreak(gText_Prev, winStreak, rents, x1, x2, x3, y);
}

static void ShowFactoryResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapSingleResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapDoubleResults);

    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_RentalSwap, 152, 33, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 49);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 65);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 113);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Battle Pyramid records.
static void PyramidPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x1, y, TEXT_SKIP_DRAW, NULL);
    if (num > MAX_STREAK)
        num = MAX_STREAK;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_FloorsCleared);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x2, y, TEXT_SKIP_DRAW, NULL);
}

static void PyramidPrintRecordStreak(enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode];
    PyramidPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PyramidGetWinStreak(enum FrontierLevelMode lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
    if (winStreak > MAX_STREAK)
        return MAX_STREAK;
    else
        return winStreak;
}

static void PyramidPrintPrevOrCurrentStreak(enum FrontierLevelMode lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PyramidGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = IsWinStreakActive(STREAK_PYRAMID_OPEN);
    else
        isCurrent = IsWinStreakActive(STREAK_PYRAMID_50);

    if (isCurrent == TRUE)
        PyramidPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PyramidPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPyramidResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&sFrontierResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, gText_BattleQuestResults);
    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Lv502, 8, 49, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_OpenLv, 8, 97, TEXT_SKIP_DRAW, NULL);
    PrintHyphens(10);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 111, 49);
    PyramidPrintRecordStreak(FRONTIER_LVL_50, 64, 111, 65);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 111, 97);
    PyramidPrintRecordStreak(FRONTIER_LVL_OPEN, 64, 111, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

// Link contest records. Why is it in this file?
static void ShowLinkContestResultsWindow(void)
{
    const u8 *str;
    s32 i, j;
    s32 x;

    gRecordsWindowId = AddWindow(&sLinkContestResultsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));

    StringExpandPlaceholders(gStringVar4, gText_LinkContestResults);
    x = GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 208);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, x, 1, TEXT_SKIP_DRAW, NULL);

    str = gText_1st;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 50;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_2nd;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 88;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_3rd;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 126;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    str = gText_4th;
    x = GetStringRightAlignXOffset(FONT_NORMAL, str, 38) + 164;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, str, x, 25, TEXT_SKIP_DRAW, NULL);

    x = 6;
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Cool, x, 41, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Beauty, x, 57, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Cute, x, 73, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Smart, x, 89, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_Tough, x, 105, TEXT_SKIP_DRAW, NULL);

    for (i = 0; i < CONTEST_CATEGORIES_COUNT; i++)
    {
        for (j = 0; j < CONTESTANT_COUNT; j++)
        {
            ConvertIntToDecimalStringN(gStringVar4, gSaveBlock2Ptr->contestLinkResults[i][j], STR_CONV_MODE_RIGHT_ALIGN, 4);
            AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, (j * 38) + 64, (i * 16) + 41, TEXT_SKIP_DRAW, NULL);
        }
    }

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

static void CheckPutFrontierTVShowOnAir(void)
{
    u8 name[32];
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
            if (battleMode == FRONTIER_MODE_LINK_MULTIS)
            {
                StringCopy(name, gLinkPlayers[gBattleScripting.multiplayerId ^ 1].name);
                StripExtCtrlCodes(name);
                StringCopy(gSaveBlock2Ptr->frontier.opponentNames[lvlMode], name);
                SetTrainerId(gLinkPlayers[gBattleScripting.multiplayerId ^ 1].trainerId, gSaveBlock2Ptr->frontier.opponentTrainerIds[lvlMode]);
            }
            if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                switch (battleMode)
                {
                case FRONTIER_MODE_SINGLES:
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_SINGLES);
                    break;
                case FRONTIER_MODE_DOUBLES:
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_DOUBLES);
                    break;
                case FRONTIER_MODE_MULTIS:
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_MULTIS);
                    break;
                case FRONTIER_MODE_LINK_MULTIS:
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_TOWER_LINK_MULTIS);
                    break;
                }
            }
        }
        break;
    case FRONTIER_FACILITY_DOME:
        if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_DOME_SINGLES);
                else
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_DOME_DOUBLES);
            }
        }
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_PALACE_SINGLES);
                else
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_PALACE_DOUBLES);
            }
        }
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode], FRONTIER_SHOW_ARENA);
            }
        }
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
            gSaveBlock2Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_FACTORY_SINGLES);
                else
                    TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], FRONTIER_SHOW_FACTORY_DOUBLES);
            }
        }
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pikeRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.pikeRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode], FRONTIER_SHOW_PIKE);
            }
        }
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > 1
                && ShouldAirFrontierTVShow())
            {
                TryPutFrontierTVShowOnAir(gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode], FRONTIER_SHOW_PYRAMID);
            }
        }
        break;
    }
}

static void Script_GetFrontierBrainStatus(void)
{
    VarGet(VAR_FRONTIER_FACILITY); // Unused return value.
    gSpecialVar_Result = GetFrontierBrainStatus();
}

u8 GetFrontierBrainStatus(void)
{
    s32 status = FRONTIER_BRAIN_NOT_READY;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 winStreakNoModifier = GetCurrentFacilityWinStreak();
    s32 winStreak = winStreakNoModifier + gFrontierBrainInfo[facility].streakAppearances[3];
    s32 symbolsCount;

    if (battleMode != FRONTIER_MODE_SINGLES)
        return FRONTIER_BRAIN_NOT_READY;

    symbolsCount = GetPlayerSymbolCountForFacility(facility);
    switch (symbolsCount)
    {
    // Missing a symbol
    case 0:
    case 1:
        if (winStreak == gFrontierBrainInfo[facility].streakAppearances[symbolsCount])
            status = symbolsCount + 1; // FRONTIER_BRAIN_SILVER and FRONTIER_BRAIN_GOLD
        break;
    // Already received both symbols
    case 2:
    default:
        // Silver streak is reached
        if (winStreak == gFrontierBrainInfo[facility].streakAppearances[0])
            status = FRONTIER_BRAIN_STREAK;
        // Gold streak is reached
        else if (winStreak == gFrontierBrainInfo[facility].streakAppearances[1])
            status = FRONTIER_BRAIN_STREAK_LONG;
        // Some increment of the gold streak is reached
        else if (winStreak > gFrontierBrainInfo[facility].streakAppearances[1] && (winStreak - gFrontierBrainInfo[facility].streakAppearances[1]) % gFrontierBrainInfo[facility].streakAppearances[2] == 0)
            status = FRONTIER_BRAIN_STREAK_LONG;
        break;
    }

    return status;
}

void CopyFrontierTrainerText(u8 whichText, u16 trainerId)
{
    switch (whichText)
    {
    case FRONTIER_BEFORE_TEXT:
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        if (trainerId == TRAINER_EREADER)
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.greeting);
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
    #else
        if (trainerId == TRAINER_FRONTIER_BRAIN)
    #endif //FREE_BATTLE_TOWER_E_READER
            CopyFrontierBrainText(FALSE);
        else if (trainerId < FRONTIER_TRAINERS_COUNT)
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].greeting);
        else
            BufferApprenticeChallengeText(trainerId - TRAINER_RECORD_MIXING_APPRENTICE);
        break;
    case FRONTIER_PLAYER_LOST_TEXT:
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        if (trainerId == TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerLost);
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
    #else
        if (trainerId == TRAINER_FRONTIER_BRAIN)
    #endif //FREE_BATTLE_TOWER_E_READER
        {
            CopyFrontierBrainText(FALSE);
        }
        else if (trainerId < FRONTIER_TRAINERS_COUNT)
        {
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechWin);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(GetRecordedBattleEasyChatSpeech());
            else
                FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].speechWon);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(GetRecordedBattleEasyChatSpeech());
            else
                FrontierSpeechToString(gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].speechWon);
        }
        break;
    case FRONTIER_PLAYER_WON_TEXT:
        if (trainerId == TRAINER_EREADER)
        {
        #if FREE_BATTLE_TOWER_E_READER == FALSE
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerWon);
        #endif //FREE_BATTLE_TOWER_E_READER
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            CopyFrontierBrainText(TRUE);
        }
        else if (trainerId < FRONTIER_TRAINERS_COUNT)
        {
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechLose);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                FrontierSpeechToString(GetRecordedBattleEasyChatSpeech());
            else
                FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].speechLost);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            {
                trainerId = GetRecordedBattleApprenticeId();
                FrontierSpeechToString(gApprentices[trainerId].speechLost);
            }
            else
            {
                trainerId = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id;
                FrontierSpeechToString(gApprentices[trainerId].speechLost);
            }
        }
        break;
    }
}

void ResetWinStreaks(void)
{
    s32 battleMode, lvlMode;

    gSaveBlock2Ptr->frontier.winStreakActiveFlags = 0;
    for (battleMode = 0; battleMode < FRONTIER_MODE_COUNT; battleMode++)
    {
        for (lvlMode = 0; lvlMode < FRONTIER_LVL_TENT; lvlMode++)
        {
            gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] = 0;
            if (battleMode < FRONTIER_MODE_MULTIS)
            {
                gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] = 0;
                gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] = 0;
                gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
            }
            if (battleMode == FRONTIER_MODE_SINGLES)
            {
                gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = 0;
                gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] = 0;
                gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = 0;
            }
        }
    }
    if (gSaveBlock2Ptr->frontier.challengeStatus != 0)
        gSaveBlock2Ptr->frontier.challengeStatus = CHALLENGE_STATUS_SAVING;
}

u32 GetCurrentFacilityWinStreak(void)
{
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        return gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_DOME:
        return gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_PALACE:
        return gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_ARENA:
        return gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
    case FRONTIER_FACILITY_FACTORY:
        return gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    case FRONTIER_FACILITY_PIKE:
        return gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    case FRONTIER_FACILITY_PYRAMID:
        return gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
    default:
        return 0;
    }
}

void ResetFrontierTrainerIds(void)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.trainerIds); i++)
        gSaveBlock2Ptr->frontier.trainerIds[i] = 0xFFFF;
}

static void IsTrainerFrontierBrain(void)
{
    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

u8 GetPlayerSymbolCountForFacility(u8 facility)
{
    return FlagGet(FLAG_SYS_TOWER_SILVER + facility * 2)
         + FlagGet(FLAG_SYS_TOWER_GOLD + facility * 2);
}

static void GiveBattlePoints(void)
{
    s32 challengeNum = 0;
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 points;

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
        break;
    case FRONTIER_FACILITY_DOME:
        challengeNum = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
        break;
    case FRONTIER_FACILITY_PALACE:
        challengeNum = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
        break;
    case FRONTIER_FACILITY_ARENA:
        challengeNum = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
        break;
    case FRONTIER_FACILITY_FACTORY:
        challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
        break;
    case FRONTIER_FACILITY_PIKE:
        challengeNum = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] / NUM_PIKE_ROOMS;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        challengeNum = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;
        break;
    }

    if (challengeNum != 0)
        challengeNum--;
    if (challengeNum >= ARRAY_COUNT(sBattlePointAwards[0][0]))
        challengeNum = ARRAY_COUNT(sBattlePointAwards[0][0]) - 1;

    points = sBattlePointAwards[facility][battleMode][challengeNum];
    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
        points += 10;
    gSaveBlock2Ptr->frontier.battlePoints += points;
    ConvertIntToDecimalStringN(gStringVar1, points, STR_CONV_MODE_LEFT_ALIGN, 2);
    if (gSaveBlock2Ptr->frontier.battlePoints > MAX_BATTLE_FRONTIER_POINTS)
        gSaveBlock2Ptr->frontier.battlePoints = MAX_BATTLE_FRONTIER_POINTS;

    points = gSaveBlock2Ptr->frontier.cardBattlePoints;
    points += sBattlePointAwards[facility][battleMode][challengeNum];
    IncrementDailyBattlePoints(sBattlePointAwards[facility][battleMode][challengeNum]);
    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_FRONTIER_BRAIN)
    {
        points += 10;
        IncrementDailyBattlePoints(10);
    }
    if (points > 0xFFFF)
        points = 0xFFFF;
    gSaveBlock2Ptr->frontier.cardBattlePoints = points;
}

static void GetFacilitySymbolCount(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    gSpecialVar_Result = GetPlayerSymbolCountForFacility(facility);
}

static void GiveFacilitySymbol(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    if (GetPlayerSymbolCountForFacility(facility) == 0)
        FlagSet(FLAG_SYS_TOWER_SILVER + facility * 2);
    else
        FlagSet(FLAG_SYS_TOWER_GOLD + facility * 2);
}

static void CheckBattleTypeFlag(void)
{
    if (gBattleTypeFlags & gSpecialVar_0x8005)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static void AppendCaughtBannedMonSpeciesName(enum Species species, u8 count, s32 numBannedMonsCaught)
{
    if (count == 1)
        ;
    else if (numBannedMonsCaught == count)
        StringAppend(gStringVar1, gText_SpaceAndSpace);
    else if (numBannedMonsCaught > count)
        StringAppend(gStringVar1, gText_CommaSpace);
    if (count == 3)
        StringAppend(gStringVar1, gText_NewLine2);
    else if (count == 6)
        StringAppend(gStringVar1, gText_LineBreak);
    StringAppend(gStringVar1, GetSpeciesName(species));
}

static void AppendIfValid(enum Species species, enum Item heldItem, u16 hp, enum FrontierLevelMode lvlMode, u8 monLevel, enum Species *speciesArray, enum Item *itemsArray, u8 *count)
{
    s32 i = 0;

    if (species == SPECIES_EGG || species == SPECIES_NONE)
        return;
    if (gSpeciesInfo[species].isFrontierBanned)
        return;
    if (lvlMode == FRONTIER_LVL_50 && monLevel > FRONTIER_MAX_LEVEL_50)
        return;

    for (i = 0; i < *count && speciesArray[i] != species; i++)
        ;
    if (i != *count)
        return;

    if (heldItem != 0)
    {
        for (i = 0; i < *count && itemsArray[i] != heldItem; i++)
            ;
        if (i != *count)
            return;
    }

    speciesArray[*count] = species;
    itemsArray[*count] = heldItem;
    (*count)++;
}

// gSpecialVar_Result is the level mode before and after calls to this function
// gSpecialVar_0x8004 is used to store the return value instead (TRUE if there are insufficient eligible mons)
// The names of ineligible Pokémon that have been caught are also buffered to print
static void CheckPartyIneligibility(void)
{
    enum Species speciesArray[PARTY_SIZE];
    enum Item itemArray[PARTY_SIZE];
    s32 monId = 0;
    s32 toChoose = 0;
    u8 count = 0;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 monIdLooper;

    // count is re-used, define for clarity
    #define numEligibleMons count

    switch (battleMode)
    {
    case FRONTIER_MODE_SINGLES:
        toChoose = FRONTIER_PARTY_SIZE;
        break;
    case FRONTIER_MODE_MULTIS:
    case FRONTIER_MODE_LINK_MULTIS:
        toChoose = FRONTIER_MULTI_PARTY_SIZE;
        break;
    case FRONTIER_MODE_DOUBLES:
        if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_TOWER)
            toChoose = FRONTIER_DOUBLES_PARTY_SIZE;
        else
            toChoose = FRONTIER_PARTY_SIZE;
        break;
    }

    monIdLooper = 0;
    do
    {
        monId = monIdLooper;
        numEligibleMons = 0;
        do
        {
            enum Species species = GetMonData(&gParties[B_TRAINER_PLAYER][monId], MON_DATA_SPECIES_OR_EGG);
            enum Item heldItem = GetMonData(&gParties[B_TRAINER_PLAYER][monId], MON_DATA_HELD_ITEM);
            u8 level = GetMonData(&gParties[B_TRAINER_PLAYER][monId], MON_DATA_LEVEL);
            u16 hp = GetMonData(&gParties[B_TRAINER_PLAYER][monId], MON_DATA_HP);
            if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_PYRAMID)
            {
                if (heldItem == ITEM_NONE)
                    AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &numEligibleMons);
            }
            else
            {
                AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &numEligibleMons);
            }
            monId++;
            if (monId >= PARTY_SIZE)
                monId = 0;
        } while (monId != monIdLooper);

        monIdLooper++;
    } while (monIdLooper < PARTY_SIZE && numEligibleMons < toChoose);

    if (numEligibleMons < toChoose)
    {
        u32 i, j;
        enum Species baseSpecies = 0;
        u32 totalCaughtBanned = 0;
        u32 totalPartyBanned = 0;
        u32 partyBanned[PARTY_SIZE] = {0};

        for (i = 0; i < NUM_SPECIES; i++)
        {
            if (!IsSpeciesEnabled(i))
                continue;
            baseSpecies = GET_BASE_SPECIES_ID(i);
            if (baseSpecies == i && gSpeciesInfo[baseSpecies].isFrontierBanned)
            {
                if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(baseSpecies), FLAG_GET_CAUGHT))
                    totalCaughtBanned++;
            }
        }

        for (i = 0; i < PARTY_SIZE; i++)
        {
            enum Species species = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG);
            if (species == SPECIES_EGG || species == SPECIES_NONE)
                continue;
            if (gSpeciesInfo[GET_BASE_SPECIES_ID(species)].isFrontierBanned)
            {
                bool32 addToList = TRUE;
                for (j = 0; j < totalPartyBanned; j++)
                    if (partyBanned[j] == species)
                        addToList = FALSE;
                if (addToList)
                {
                    partyBanned[totalPartyBanned] = species;
                    totalPartyBanned++;
                }
            }
        }

        gStringVar1[0] = EOS;
        gSpecialVar_0x8004 = TRUE;
        if (totalCaughtBanned == 0)
        {
            StringAppend(gStringVar1, gText_FrontierFacilityAreInelegible);
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar2, totalCaughtBanned, STR_CONV_MODE_LEFT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_FrontierFacilityTotalCaughtSpeciesBanned);
            StringAppend(gStringVar1, gStringVar4);
        }
        if (totalPartyBanned > 0)
        {
            StringAppend(gStringVar1, gText_FrontierFacilityIncluding);
            for (i = 0; i < totalPartyBanned; i++)
                AppendCaughtBannedMonSpeciesName(partyBanned[i], i+1, totalPartyBanned);
        }
        gSpecialVar_0x8005 = totalCaughtBanned;
    }
    else
    {
        gSpecialVar_0x8004 = FALSE;
        gSaveBlock2Ptr->frontier.lvlMode = gSpecialVar_Result;
    }
    #undef numEligibleMons
}

static void ValidateVisitingTrainer(void)
{
    ValidateEReaderTrainer();
}

static void IncrementWinStreak(void)
{
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] < MAX_STREAK)
        {
            gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode]++;
            if (battleMode == FRONTIER_MODE_SINGLES)
            {
                SetGameStat(GAME_STAT_BATTLE_TOWER_SINGLES_STREAK, gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode]);
                gSaveBlock2Ptr->frontier.towerSinglesStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
            }
        }
        break;
    case FRONTIER_FACILITY_DOME:
        if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode]++;
        if (gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] < MAX_STREAK)
            gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] < MAX_STREAK)
            gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] < MAX_STREAK)
            gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] < MAX_STREAK)
            gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode]++;
        break;
    }
}

static void RestoreHeldItems(void)
{
    u8 i;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        if (gSaveBlock2Ptr->frontier.selectedPartyMons[i] != 0)
        {
            enum Item item = GetMonData(GetSavedPlayerPartyMon(gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1), MON_DATA_HELD_ITEM);
            SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HELD_ITEM, &item);
        }
    }
}

static void SaveRecordBattle(void)
{
    gSpecialVar_Result = MoveRecordedBattleToSaveData();
    gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
}

static void BufferFrontierTrainerName(void)
{
    switch (gSpecialVar_0x8005)
    {
    case 0:
        GetFrontierTrainerName(gStringVar1, TRAINER_BATTLE_PARAM.opponentA);
        break;
    case 1:
        GetFrontierTrainerName(gStringVar2, TRAINER_BATTLE_PARAM.opponentA);
        break;
    }
}

static void ResetSketchedMoves(void)
{
    u8 i, j, k;

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                for (k = 0; k < MAX_MON_MOVES; k++)
                {
                    if (GetMonData(GetSavedPlayerPartyMon(gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1), MON_DATA_MOVE1 + k)
                        == GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_MOVE1 + j))
                        break;
                }
                if (k == MAX_MON_MOVES)
                    SetMonMoveSlot(&gParties[B_TRAINER_PLAYER][i], MOVE_SKETCH, j);
            }
            SavePlayerPartyMon(gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1, &gParties[B_TRAINER_PLAYER][i]);
        }
    }
}

static void SetFacilityBrainObjectEvent(void)
{
    SetFrontierBrainObjEventGfx(VarGet(VAR_FRONTIER_FACILITY));
}

// Battle Frontier Ranking Hall records.
static void Print1PRecord(s32 position, s32 x, s32 y, struct RankingHall1P *hallRecord, s32 hallFacilityId)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    hallRecord->name[PLAYER_NAME_LENGTH] = EOS;
    if (hallRecord->winStreak)
    {
        TVShowConvertInternationalString(text, hallRecord->name, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, (x + 2) * 8, (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
        winStreak = hallRecord->winStreak;
        if (winStreak > MAX_STREAK)
            winStreak = MAX_STREAK;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, sHallFacilityToRecordsText[hallFacilityId]);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, GetStringRightAlignXOffset(FONT_NORMAL, sHallFacilityToRecordsText[hallFacilityId], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    }
}

static void Print2PRecord(s32 position, s32 x, s32 y, struct RankingHall2P *hallRecord)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    if (hallRecord->winStreak)
    {
        hallRecord->name1[PLAYER_NAME_LENGTH] = EOS;
        hallRecord->name2[PLAYER_NAME_LENGTH] = EOS;
        TVShowConvertInternationalString(text, hallRecord->name1, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, (x + 2) * 8, (8 * (y + 5 * position - 1)) + 1, TEXT_SKIP_DRAW, NULL);
        if (IsStringJapanese(hallRecord->name2))
            TVShowConvertInternationalString(text, hallRecord->name2, LANGUAGE_JAPANESE);
        else
            StringCopy(text, hallRecord->name2);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, text, (x + 4) * 8, (8 * (y + 5 * position + 1)) + 1, TEXT_SKIP_DRAW, NULL);

        winStreak = hallRecord->winStreak;
        if (winStreak > MAX_STREAK)
            winStreak = MAX_STREAK;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, sHallFacilityToRecordsText[RANKING_HALL_TOWER_LINK]);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, GetStringRightAlignXOffset(FONT_NORMAL, sHallFacilityToRecordsText[RANKING_HALL_TOWER_LINK], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SKIP_DRAW, NULL);
    }
}

static void Fill1PRecords(struct RankingHall1P *dst, s32 hallFacilityId, s32 lvlMode)
{
#if FREE_RECORD_MIXING_HALL_RECORDS == FALSE
    s32 i, j;
    struct RankingHall1P record1P[HALL_RECORDS_COUNT + 1];
    struct PlayerHallRecords *playerHallRecords = AllocZeroed(sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
        record1P[i] = gSaveBlock2Ptr->hallRecords1P[hallFacilityId][lvlMode][i];

    record1P[HALL_RECORDS_COUNT] = playerHallRecords->onePlayer[hallFacilityId][lvlMode];

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < HALL_RECORDS_COUNT + 1; j++)
        {
            if (record1P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record1P[j].winStreak;
            }
        }
        if (record1P[HALL_RECORDS_COUNT].winStreak >= highestWinStreak)
            highestId = HALL_RECORDS_COUNT;

        dst[i] = record1P[highestId];
        record1P[highestId].winStreak = 0;
    }

    Free(playerHallRecords);
#endif //FREE_RECORD_MIXING_HALL_RECORDS
}

static void Fill2PRecords(struct RankingHall2P *dst, s32 lvlMode)
{
#if FREE_RECORD_MIXING_HALL_RECORDS == FALSE
    s32 i, j;
    struct RankingHall2P record2P[HALL_RECORDS_COUNT + 1];
    struct PlayerHallRecords *playerHallRecords = AllocZeroed(sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
        record2P[i] = gSaveBlock2Ptr->hallRecords2P[lvlMode][i];

    record2P[HALL_RECORDS_COUNT] = playerHallRecords->twoPlayers[lvlMode];

    for (i = 0; i < HALL_RECORDS_COUNT; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < HALL_RECORDS_COUNT; j++)
        {
            if (record2P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record2P[j].winStreak;
            }
        }
        if (record2P[HALL_RECORDS_COUNT].winStreak >= highestWinStreak)
            highestId = HALL_RECORDS_COUNT;

        dst[i] = record2P[highestId];
        record2P[highestId].winStreak = 0;
    }

    Free(playerHallRecords);
#endif //FREE_RECORD_MIXING_HALL_RECORDS
}

static void PrintHallRecords(s32 hallFacilityId, s32 lvlMode)
{
    s32 i;
    s32 x;
    struct RankingHall1P records1P[HALL_RECORDS_COUNT];
    struct RankingHall2P records2P[HALL_RECORDS_COUNT];

    StringCopy(gStringVar1, sRecordsWindowChallengeTexts[hallFacilityId][0]);
    StringExpandPlaceholders(gStringVar4, sRecordsWindowChallengeTexts[hallFacilityId][1]);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    x = GetStringRightAlignXOffset(FONT_NORMAL, sLevelModeText[lvlMode], DISPLAY_WIDTH - 32);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, sLevelModeText[lvlMode], x, 1, TEXT_SKIP_DRAW, NULL);
    if (hallFacilityId == RANKING_HALL_TOWER_LINK)
    {
        gSaveBlock2Ptr->frontier.opponentNames[0][PLAYER_NAME_LENGTH] = EOS;
        gSaveBlock2Ptr->frontier.opponentNames[1][PLAYER_NAME_LENGTH] = EOS;
        Fill2PRecords(records2P, lvlMode);
        for (i = 0; i < HALL_RECORDS_COUNT; i++)
            Print2PRecord(i, 1, 4, &records2P[i]);
    }
    else
    {
        Fill1PRecords(records1P, hallFacilityId, lvlMode);
        for (i = 0; i < HALL_RECORDS_COUNT; i++)
            Print1PRecord(i, 1, 4, &records1P[i], hallFacilityId);
    }
}

void ShowRankingHallRecordsWindow(void)
{
    gRecordsWindowId = AddWindow(&sRankingHallRecordsWindowTemplate);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_50);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}

void ScrollRankingHallRecordsWindow(void)
{
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_OPEN);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_GFX);
}

void ClearRankingHallRecords(void)
{
#if FREE_RECORD_MIXING_HALL_RECORDS == FALSE
    s32 i, j, k;

    // UB: Passing 0 as a pointer instead of a pointer holding a value of 0.
#ifdef UBFIX
    u8 emptyId[TRAINER_ID_LENGTH] = {0};
    #define ZERO emptyId
#else
    #define ZERO 0
#endif

    for (i = 0; i < HALL_FACILITIES_COUNT; i++)
    {
        for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
        {
            for (k = 0; k < HALL_RECORDS_COUNT; k++)
            {
                CopyTrainerId(gSaveBlock2Ptr->hallRecords1P[i][j][k].id, ZERO);
                gSaveBlock2Ptr->hallRecords1P[i][j][k].name[0] = EOS;
                gSaveBlock2Ptr->hallRecords1P[i][j][k].winStreak = 0;
            }
        }
    }

    for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
    {
        for (k = 0; k < HALL_RECORDS_COUNT; k++)
        {
            CopyTrainerId(gSaveBlock2Ptr->hallRecords2P[j][k].id1, ZERO);
            CopyTrainerId(gSaveBlock2Ptr->hallRecords2P[j][k].id2, ZERO);
            gSaveBlock2Ptr->hallRecords2P[j][k].name1[0] = EOS;
            gSaveBlock2Ptr->hallRecords2P[j][k].name2[0] = EOS;
            gSaveBlock2Ptr->hallRecords2P[j][k].winStreak = 0;
        }
    }
#endif //FREE_RECORD_MIXING_HALL_RECORDS
}

void SaveGameFrontier(void)
{
    s32 i;
    struct Pokemon *monsParty = AllocZeroed(sizeof(struct Pokemon) * PARTY_SIZE);

    for (i = 0; i < PARTY_SIZE; i++)
        monsParty[i] = gParties[B_TRAINER_PLAYER][i];

    i = gPartiesCount[B_TRAINER_PLAYER];
    LoadPlayerParty();
    SetContinueGameWarpStatusToDynamicWarp();
    TrySavingData(SAVE_LINK);
    ClearContinueGameWarpStatus2();
    gPartiesCount[B_TRAINER_PLAYER] = i;

    for (i = 0; i < PARTY_SIZE; i++)
        gParties[B_TRAINER_PLAYER][i] = monsParty[i];

    Free(monsParty);
}

// Frontier Brain functions.
enum TrainerPicID GetFrontierBrainTrainerPicIndex(void)
{
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    return GetTrainerPicFromId(gFrontierBrainInfo[facility].trainerId);
}

enum TrainerClassID GetFrontierBrainTrainerClass(void)
{
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    return GetTrainerClassFromId(gFrontierBrainInfo[facility].trainerId);
}

void CopyFrontierBrainTrainerName(u8 *dst)
{
    s32 i;
    s32 facility;
    const u8 *trainerName;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    trainerName = GetTrainerNameFromId(gFrontierBrainInfo[facility].trainerId);
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        dst[i] = trainerName[i];

    dst[i] = EOS;
}

bool8 IsFrontierBrainFemale(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    return gFrontierBrainInfo[facility].isFemale;
}

void SetFrontierBrainObjEventGfx_2(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    VarSet(VAR_OBJ_GFX_ID_0, gFrontierBrainInfo[facility].objEventGfx);
}

#define FRONTIER_BRAIN_OTID 61226

void CreateFrontierBrainPokemon(void)
{
    s32 i, j;
    s32 selectedMonBits;
    s32 monPartyId;
    s32 monLevel = 0;
    u8 friendship;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    if (facility == FRONTIER_FACILITY_DOME)
        selectedMonBits = GetDomeTrainerSelectedMons(TrainerIdToDomeTournamentId(TRAINER_FRONTIER_BRAIN));
    else
        selectedMonBits = (1 << FRONTIER_PARTY_SIZE) - 1; // all 3 mons selected

    ZeroEnemyPartyMons();
    monPartyId = 0;
    monLevel = SetFacilityPtrsGetLevel();
    for (i = 0; i < FRONTIER_PARTY_SIZE; selectedMonBits >>= 1, i++)
    {
        if (!(selectedMonBits & 1))
            continue;

        u32 personality = GetMonPersonality(sFrontierBrainsMons[facility][symbol][i].species,
                                            MON_GENDER_RANDOM,
                                            sFrontierBrainsMons[facility][symbol][i].nature,
                                            RANDOM_UNOWN_LETTER);
        CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][monPartyId],
                  sFrontierBrainsMons[facility][symbol][i].species,
                  monLevel,
                  personality,
                  OTID_STRUCT_PRESET(FRONTIER_BRAIN_OTID),
                  sFrontierBrainsMons[facility][symbol][i].fixedIV);
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][monPartyId], MON_DATA_HELD_ITEM, &sFrontierBrainsMons[facility][symbol][i].heldItem);
        for (j = 0; j < NUM_STATS; j++)
            SetMonData(&gParties[B_TRAINER_OPPONENT_A][monPartyId], MON_DATA_HP_EV + j, &sFrontierBrainsMons[facility][symbol][i].evs[j]);
        friendship = MAX_FRIENDSHIP;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&gParties[B_TRAINER_OPPONENT_A][monPartyId], sFrontierBrainsMons[facility][symbol][i].moves[j], j);
            if (GetMoveEffect(sFrontierBrainsMons[facility][symbol][i].moves[j]) == EFFECT_FRUSTRATION)
                friendship = 0;
        }
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][monPartyId], MON_DATA_FRIENDSHIP, &friendship);
        CalculateMonStats(&gParties[B_TRAINER_OPPONENT_A][monPartyId]);
        monPartyId++;
    }
}

enum Species GetFrontierBrainMonSpecies(u8 monId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].species;
}

void SetFrontierBrainObjEventGfx(u8 facility)
{
    TRAINER_BATTLE_PARAM.opponentA = TRAINER_FRONTIER_BRAIN;
    VarSet(VAR_OBJ_GFX_ID_0, gFrontierBrainInfo[facility].objEventGfx);
}

u16 GetFrontierBrainMonMove(u8 monId, u8 moveSlotId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].moves[moveSlotId];
}

u8 GetFrontierBrainMonNature(u8 monId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].nature;
}

u8 GetFrontierBrainMonEvs(u8 monId, u8 evStatId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].evs[evStatId];
}

s32 GetFronterBrainSymbol(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetPlayerSymbolCountForFacility(facility);

    if (symbol == 2)
    {
        u16 winStreak = GetCurrentFacilityWinStreak();
        if (winStreak + gFrontierBrainInfo[facility].streakAppearances[3] == gFrontierBrainInfo[facility].streakAppearances[0])
            symbol = 0;
        else if (winStreak + gFrontierBrainInfo[facility].streakAppearances[3] == gFrontierBrainInfo[facility].streakAppearances[1])
            symbol = 1;
        else if (winStreak + gFrontierBrainInfo[facility].streakAppearances[3] > gFrontierBrainInfo[facility].streakAppearances[1]
                 && (winStreak + gFrontierBrainInfo[facility].streakAppearances[3] - gFrontierBrainInfo[facility].streakAppearances[1]) % gFrontierBrainInfo[facility].streakAppearances[2] == 0)
            symbol = 1;
    }
    return symbol;
}

// Called for intro speech as well despite the fact that its handled in the map scripts files instead
static void CopyFrontierBrainText(bool8 playerWonText)
{
    s32 facility;
    s32 symbol;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
    {
        facility = GetRecordedBattleFrontierFacility();
        symbol = GetRecordedBattleFronterBrainSymbol();
    }
    else
    {
        facility = VarGet(VAR_FRONTIER_FACILITY);
        symbol = GetFronterBrainSymbol();
    }

    switch (playerWonText)
    {
    case FALSE:
        StringCopy(gStringVar4, gFrontierBrainInfo[facility].wonTexts[symbol]);
        break;
    case TRUE:
        StringCopy(gStringVar4, gFrontierBrainInfo[facility].lostTexts[symbol]);
        break;
    }
}

void ClearEnemyPartyAfterChallenge()
{
    // We zero out the Enemy's party here when the player either wins or loses the challenge since we
    // can't do it the usual way in FreeResetData_ReturnToOvOrDoEvolutions() in battle_main.c due to the
    // way facilities like the Battle Factory and the Slateport Battle Tent work
    if (gSpecialVar_0x8005 == 0)
    {
        ZeroEnemyPartyMons();
    }
}

bool8 IsFrontierTrainerFemale(u16 trainerId)
{
    u32 i;
    u8 facilityClass;

    SetFacilityPtrsGetLevel();
    if (trainerId == TRAINER_EREADER)
    {
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    #else
        facilityClass = 0;
    #endif //FREE_BATTLE_TOWER_E_READER
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        return IsFrontierBrainFemale();
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i].class == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
        return TRUE;
    else
        return FALSE;
}

// Frontier Trainer parties are roughly scaled in difficulty with higher trainer IDs, so scale IVs as well
// Duplicated in Battle Dome as GetDomeTrainerMonIvs
u8 GetFrontierTrainerFixedIvs(u16 trainerId)
{
    u8 fixedIv;

    if (trainerId <= FRONTIER_TRAINER_JILL)         // 0 - 99
        fixedIv = 3;
    else if (trainerId <= FRONTIER_TRAINER_CHLOE)   // 100 - 119
        fixedIv = 6;
    else if (trainerId <= FRONTIER_TRAINER_SOFIA)   // 120 - 139
        fixedIv = 9;
    else if (trainerId <= FRONTIER_TRAINER_JAZLYN)  // 140 - 159
        fixedIv = 12;
    else if (trainerId <= FRONTIER_TRAINER_ALISON)  // 160 - 179
        fixedIv = 15;
    else if (trainerId <= FRONTIER_TRAINER_LAMAR)   // 180 - 199
        fixedIv = 18;
    else if (trainerId <= FRONTIER_TRAINER_TESS)    // 200 - 219
        fixedIv = 21;
    else                                            // 220+ (- 299)
        fixedIv = MAX_PER_STAT_IVS;

    return fixedIv;
}


u16 GetRandomScaledFrontierTrainerId(u8 challengeNum, u8 battleNum)
{
    u16 trainerId;

    if (challengeNum <= 7)
    {
        if (battleNum == FRONTIER_STAGES_PER_CHALLENGE - 1)
        {
            // The last battle in each challenge has a jump in difficulty, pulls from a table with higher ranges
            trainerId = (sFrontierTrainerIdRangesHard[challengeNum][1] - sFrontierTrainerIdRangesHard[challengeNum][0]) + 1;
            trainerId = sFrontierTrainerIdRangesHard[challengeNum][0] + (Random() % trainerId);
        }
        else
        {
            trainerId = (sFrontierTrainerIdRanges[challengeNum][1] - sFrontierTrainerIdRanges[challengeNum][0]) + 1;
            trainerId = sFrontierTrainerIdRanges[challengeNum][0] + (Random() % trainerId);
        }
    }
    else
    {
        // After challenge 7, trainer IDs always come from the last, hardest range, which is the same for both trainer ID tables
        trainerId = (sFrontierTrainerIdRanges[7][1] - sFrontierTrainerIdRanges[7][0]) + 1;
        trainerId = sFrontierTrainerIdRanges[7][0] + (Random() % trainerId);
    }

    return trainerId;
}

static void UNUSED GetRandomScaledFrontierTrainerIdRange(u8 challengeNum, u8 battleNum, u16 *trainerIdPtr, u8 *rangePtr)
{
    u16 trainerId, range;

    if (challengeNum <= 7)
    {
        if (battleNum == FRONTIER_STAGES_PER_CHALLENGE - 1)
        {
            // The last battle in each challenge has a jump in difficulty, pulls from a table with higher ranges
            range = (sFrontierTrainerIdRangesHard[challengeNum][1] - sFrontierTrainerIdRangesHard[challengeNum][0]) + 1;
            trainerId = sFrontierTrainerIdRangesHard[challengeNum][0];
        }
        else
        {
            range = (sFrontierTrainerIdRanges[challengeNum][1] - sFrontierTrainerIdRanges[challengeNum][0]) + 1;
            trainerId = sFrontierTrainerIdRanges[challengeNum][0];
        }
    }
    else
    {
        // After challenge 7, trainer IDs always come from the last, hardest range, which is the same for both trainer ID tables
        range = (sFrontierTrainerIdRanges[7][1] - sFrontierTrainerIdRanges[7][0]) + 1;
        trainerId = sFrontierTrainerIdRanges[7][0];
    }

    *trainerIdPtr = trainerId;
    *rangePtr = range;
}

void SetBattleFacilityTrainerGfxId(u16 trainerId, u8 tempVarId)
{
    u32 i;
    u8 facilityClass;
    u8 trainerObjectGfxId;

    SetFacilityPtrsGetLevel();
#if FREE_BATTLE_TOWER_E_READER == FALSE
    if (trainerId == TRAINER_EREADER)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
#else
    if (trainerId == TRAINER_FRONTIER_BRAIN)
#endif //FREE_BATTLE_TOWER_E_READER
    {
        SetFrontierBrainObjEventGfx_2();
        return;
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i].class == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleFacilityClasses[i].gfxId;
        switch (tempVarId)
        {
        case 0:
        default:
            VarSet(VAR_OBJ_GFX_ID_0, trainerObjectGfxId);
            return;
        case 1:
            VarSet(VAR_OBJ_GFX_ID_1, trainerObjectGfxId);
            return;
        case 15:
            VarSet(VAR_OBJ_GFX_ID_E, trainerObjectGfxId);
            return;
        }
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i].class == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleFacilityClasses[i].gfxId;
        switch (tempVarId)
        {
        case 0:
        default:
            VarSet(VAR_OBJ_GFX_ID_0, trainerObjectGfxId);
            return;
        case 1:
            VarSet(VAR_OBJ_GFX_ID_1, trainerObjectGfxId);
            return;
        case 15:
            VarSet(VAR_OBJ_GFX_ID_E, trainerObjectGfxId);
            return;
        }
    }

    switch (tempVarId)
    {
    case 0:
    default:
        VarSet(VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1);
        return;
    case 1:
        VarSet(VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1);
        return;
    case 15:
        VarSet(VAR_OBJ_GFX_ID_E, OBJ_EVENT_GFX_BOY_1);
        return;
    }
}

u16 GetBattleFacilityTrainerGfxId(u16 trainerId)
{
    u32 i;
    u8 facilityClass;
    u16 trainerObjectGfxId;

    SetFacilityPtrsGetLevel();
#if FREE_BATTLE_TOWER_E_READER == FALSE
    if (trainerId == TRAINER_EREADER)
    {
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
#else
    if (trainerId < FRONTIER_TRAINERS_COUNT)
#endif //FREE_BATTLE_TOWER_E_READER
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i].class == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleFacilityClasses[i].gfxId;
        return trainerObjectGfxId;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i].class == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleFacilityClasses[i].gfxId;
        return trainerObjectGfxId;
    }
    else
    {
        return OBJ_EVENT_GFX_BOY_1;
    }
}

u8 GetFrontierTrainerFrontSpriteId(u16 trainerId)
{
    SetFacilityPtrsGetLevel();

#if FREE_BATTLE_TOWER_E_READER == FALSE
    if (trainerId == TRAINER_EREADER)
    {
        return gFacilityClassToPicIndex[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
#else
    if (trainerId == TRAINER_FRONTIER_BRAIN)
#endif //FREE_BATTLE_TOWER_E_READER
    {
        return GetFrontierBrainTrainerPicIndex();
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        return gFacilityClassToPicIndex[gFacilityTrainers[trainerId].facilityClass];
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return gFacilityClassToPicIndex[GetRecordedBattleRecordMixFriendClass()];
        else
            return gFacilityClassToPicIndex[gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass];
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return gFacilityClassToPicIndex[gApprentices[GetRecordedBattleApprenticeId()].facilityClass];
        else
            return gFacilityClassToPicIndex[gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass];
    }
}

enum TrainerClassID GetFrontierOpponentClass(u16 trainerId)
{
    u8 trainerClass = 0;
    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(trainerId);
    SetFacilityPtrsGetLevel();

#if FREE_BATTLE_TOWER_E_READER == FALSE
    if (trainerId == TRAINER_EREADER)
    {
        trainerClass = gFacilityClassToTrainerClass[gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass];
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
#else
    if (trainerId == TRAINER_FRONTIER_BRAIN)
#endif //FREE_BATTLE_TOWER_E_READER
    {
        return GetFrontierBrainTrainerClass();
    }
    else if (trainerId > TRAINER_PARTNER(PARTNER_NONE))
    {
        trainerClass = gBattlePartners[difficulty][trainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerClass;
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        trainerClass = gFacilityClassToTrainerClass[gFacilityTrainers[trainerId].facilityClass];
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            trainerClass = gFacilityClassToTrainerClass[GetRecordedBattleRecordMixFriendClass()];
        }
        else
        {
            trainerClass = gFacilityClassToTrainerClass[gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass];
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            trainerClass = gFacilityClassToTrainerClass[gApprentices[GetRecordedBattleApprenticeId()].facilityClass];
        }
        else
        {
            trainerClass = gFacilityClassToTrainerClass[gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass];
        }
    }

    return trainerClass;
}

u8 GetFrontierTrainerFacilityClass(u16 trainerId)
{
    u8 facilityClass;
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_EREADER)
    {
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        facilityClass = gSaveBlock2Ptr->frontier.ereaderTrainer.facilityClass;
    #else
        facilityClass = 0;
    #endif //FREE_BATTLE_TOWER_E_READER
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        facilityClass = gFacilityTrainers[trainerId].facilityClass;
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            facilityClass = GetRecordedBattleRecordMixFriendClass();
        else
            facilityClass = gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].facilityClass;
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            facilityClass = gApprentices[GetRecordedBattleApprenticeId()].facilityClass;
        else
            facilityClass = gApprentices[gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id].facilityClass;
    }

    return facilityClass;
}

void GetFrontierTrainerName(u8 *dst, u16 trainerId)
{
    s32 i = 0;
    enum DifficultyLevel difficulty = GetBattlePartnerDifficultyLevel(trainerId);
    SetFacilityPtrsGetLevel();

    if (trainerId == TRAINER_EREADER)
    {
    #if FREE_BATTLE_TOWER_E_READER == FALSE
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gSaveBlock2Ptr->frontier.ereaderTrainer.name[i];
    #endif //FREE_BATTLE_TOWER_E_READER
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(dst);
        return;
    }
    else if (trainerId > TRAINER_PARTNER(PARTNER_NONE))
    {
        for (i = 0; gBattlePartners[difficulty][trainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerName[i] != EOS; i++)
            dst[i] = gBattlePartners[difficulty][trainerId - TRAINER_PARTNER(PARTNER_NONE)].trainerName[i];
    }
    else if (trainerId < FRONTIER_TRAINERS_COUNT)
    {
        for (i = 0; i < PLAYER_NAME_LENGTH; i++)
            dst[i] = gFacilityTrainers[trainerId].trainerName[i];
    }
    else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            GetRecordedBattleRecordMixFriendName(dst);
            return;
        }
        else
        {
            struct EmeraldBattleTowerRecord *record = &gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND];
            TVShowConvertInternationalString(dst, record->name, record->language);
            return;
        }
    }
    else
    {
        u8 id, language;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            id = GetRecordedBattleApprenticeId();
            language = GetRecordedBattleApprenticeLanguage();
        }
        else
        {
            struct Apprentice *apprentice = &gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE];
            id = apprentice->id;
            language = apprentice->language;
        }
        TVShowConvertInternationalString(dst, GetApprenticeNameInLanguage(id, language), language);
        return;
    }

    dst[i] = EOS;
}

u16 GetRandomFrontierMonFromSet(u16 trainerId)
{
    u8 level = SetFacilityPtrsGetLevel();
    const u16 *monSet = gFacilityTrainers[trainerId].monSet;
    u8 numMons = 0;
    u32 monId = monSet[numMons];

    while (monId != 0xFFFF)
    {
        numMons++;
        monId = monSet[numMons];
        if (monId == 0xFFFF)
            break;
    }

    do
    {
        // "High tier" Pokémon are only allowed on open level mode
        // 20 is not a possible value for level here
        monId = monSet[Random() % numMons];
    } while ((level == FRONTIER_MAX_LEVEL_50 || level == 20) && monId > FRONTIER_MONS_HIGH_TIER);

    return monId;
}

void FrontierSpeechToString(const u16 *words)
{
    ConvertEasyChatWordsToString(gStringVar4, words, 3, 2);
    if (GetStringWidth(FONT_NORMAL, gStringVar4, -1) > 204u)
    {
        s32 i = 0;

        ConvertEasyChatWordsToString(gStringVar4, words, 2, 3);
        while (gStringVar4[i++] != CHAR_NEWLINE)
            ;
        while (gStringVar4[i] != CHAR_NEWLINE)
            i++;

        gStringVar4[i] = CHAR_PROMPT_SCROLL;
    }
}

u8 SetFacilityPtrsGetLevel(void)
{
    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        return SetTentPtrsGetLevel();
    }
    else
    {
        gFacilityTrainers = gBattleFrontierTrainers;
        gFacilityTrainerMons = gBattleFrontierMons;
        return GetFrontierEnemyMonLevel(gSaveBlock2Ptr->frontier.lvlMode);
    }
}

u8 GetFrontierEnemyMonLevel(enum FrontierLevelMode lvlMode)
{
    u8 level;

    switch (lvlMode)
    {
    default:
    case FRONTIER_LVL_50:
        level = FRONTIER_MAX_LEVEL_50;
        break;
    case FRONTIER_LVL_OPEN:
        level = GetHighestLevelInPlayerParty();
        if (level < FRONTIER_MIN_LEVEL_OPEN)
            level = FRONTIER_MIN_LEVEL_OPEN;
        break;
    }

    return level;
}

s32 GetHighestLevelInPlayerParty(void)
{
    s32 highestLevel = 0;
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES)
            && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
        {
            s32 level = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_LEVEL);
            if (level > highestLevel)
                highestLevel = level;
        }
    }

    return highestLevel;
}

u16 FacilityClassToGraphicsId(u8 facilityClass)
{
    u16 trainerObjectGfxId;
    u8 i;

    // Search male classes.
    for (i = 0; i < ARRAY_COUNT(gTowerMaleFacilityClasses); i++)
    {
        if (gTowerMaleFacilityClasses[i].class == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerMaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerMaleFacilityClasses[i].gfxId;
        return trainerObjectGfxId;
    }

    // Search female classes.
    for (i = 0; i < ARRAY_COUNT(gTowerFemaleFacilityClasses); i++)
    {
        if (gTowerFemaleFacilityClasses[i].class == facilityClass)
            break;
    }
    if (i != ARRAY_COUNT(gTowerFemaleFacilityClasses))
    {
        trainerObjectGfxId = gTowerFemaleFacilityClasses[i].gfxId;
        return trainerObjectGfxId;
    }
    else
    {
        return OBJ_EVENT_GFX_BOY_1;
    }
}

#define tWindowId     data[0]
#define tMenuTaskId   data[1]
#define tArrowTaskId  data[2]
#define tScrollOffset data[3]
#define tListPointerElemId 4

static u16 *MakeCaughtBannedSpeciesList(u32 totalBannedSpecies)
{
    u32 count = 0;
    u16 *list = AllocZeroed(sizeof(u16) * totalBannedSpecies);
    for (enum Species i = 0; i < NUM_SPECIES; i++)
    {
        if (!IsSpeciesEnabled(i))
            continue;

        enum Species baseSpecies = GET_BASE_SPECIES_ID(i);
        if (baseSpecies == i && gSpeciesInfo[baseSpecies].isFrontierBanned)
        {
            if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(baseSpecies), FLAG_GET_CAUGHT))
            {
                list[count] = i;
                count++;
            }
        }
    }
    return list;
}

static void PrintBannedSpeciesName(u8 windowId, u32 itemId, u8 y)
{
    u8 colors[3] = {
        sCaughtBannedSpeciesListTemplate.fillValue,
        sCaughtBannedSpeciesListTemplate.cursorPal,
        sCaughtBannedSpeciesListTemplate.cursorShadowPal
    };
    u16 *list = (u16 *) GetWordTaskArg(gSpecialVar_0x8006, tListPointerElemId);
    AddTextPrinterParameterized4(windowId,
                                 sCaughtBannedSpeciesListTemplate.fontId,
                                 sCaughtBannedSpeciesListTemplate.item_X, y,
                                 sCaughtBannedSpeciesListTemplate.lettersSpacing, 0, colors, TEXT_SKIP_DRAW,
                                 GetSpeciesName(list[itemId]));
}

void ShowBattleFrontierCaughtBannedSpecies(void)
{
    u8 windowId;
    struct ListMenuTemplate listTemplate = sCaughtBannedSpeciesListTemplate;
    u32 totalCaughtBanned = gSpecialVar_0x8005;
    listTemplate.totalItems = totalCaughtBanned;

    // create window
    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sBannedSpeciesWindowTemplateMain);
    DrawStdWindowFrame(windowId, FALSE);
    listTemplate.windowId = windowId;

    u16 *listItems = MakeCaughtBannedSpeciesList(totalCaughtBanned);
    u32 inputTaskId = CreateTask(Task_BannedSpeciesWindowInput, 3);
    gTasks[inputTaskId].tWindowId = windowId;
    gSpecialVar_0x8006 = inputTaskId;
    SetWordTaskArg(inputTaskId, tListPointerElemId, (u32)listItems);
    u32 menuTaskId = ListMenuInit(&listTemplate, 0, 0);
    gTasks[inputTaskId].tMenuTaskId = menuTaskId;
    gTasks[inputTaskId].tArrowTaskId = TASK_NONE;
    if (listTemplate.totalItems > listTemplate.maxShowed)
    {
        gTempScrollArrowTemplate = sCaughtBannedSpeciesScrollArrowsTemplate;
        gTempScrollArrowTemplate.fullyDownThreshold = listTemplate.totalItems - listTemplate.maxShowed;
        gTasks[inputTaskId].tArrowTaskId = AddScrollIndicatorArrowPair(&gTempScrollArrowTemplate, (u16 *)&gTasks[inputTaskId].tScrollOffset);
    }

    // draw everything
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Task_BannedSpeciesWindowInput(u8 taskId)
{
    ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);
    ListMenuGetScrollAndRow(gTasks[taskId].tMenuTaskId, (u16 *)&gTasks[taskId].tScrollOffset, NULL);
    if (JOY_NEW(B_BUTTON))
    {
        ScriptContext_Enable();
        if (gTasks[taskId].tArrowTaskId < TASK_NONE)
            RemoveScrollIndicatorArrowPair(gTasks[taskId].tArrowTaskId);
        Free((struct ListItem *)(GetWordTaskArg(taskId, tListPointerElemId)));
        DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
        RemoveWindow(gTasks[taskId].tWindowId);
        DestroyTask(taskId);
    }
}

#undef tWindowId
#undef tMenuTaskId
#undef tArrowTaskId
#undef tScrollOffset
#undef tListPointerElemId
