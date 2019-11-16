#include "global.h"
#include "frontier_util.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "field_specials.h"
#include "battle.h"
#include "script_pokemon_util_80F87D8.h"
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
#include "constants/frontier_util.h"
#include "constants/trainers.h"
#include "constants/species.h"
#include "constants/game_stat.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/event_objects.h"
#include "party_menu.h"

struct FrontierBrainMon
{
    u16 species;
    u16 heldItem;
    u8 fixedIV;
    u8 nature;
    u8 evs[NUM_STATS];
    u16 moves[4];
};

// This file's functions.
static void sub_81A17A0(void);
static void sub_81A1830(void);
static void sub_81A1968(void);
static void LoadSelectedParty(void);
static void DoSoftReset_(void);
static void SetFrontierTrainers(void);
static void sub_81A1B38(void);
static void ShowFacilityResultsWindow(void);
static void sub_81A31FC(void);
static void sub_81A35EC(void);
static void IsTrainerFrontierBrain(void);
static void sub_81A3B64(void);
static void GetFacilitySymbolCount(void);
static void GiveFacilitySymbol(void);
static void CheckBattleTypeFlag(void);
static void sub_81A3FD4(void);
static void ValidateVisitingTrainer(void);
static void sub_81A4230(void);
static void sub_81A43A8(void);
static void sub_81A4410(void);
static void BufferFrontierTrainerName(void);
static void sub_81A447C(void);
static void SetFacilityBrainEventObject(void);
static void ShowTowerResultsWindow(u8);
static void ShowDomeResultsWindow(u8);
static void ShowPalaceResultsWindow(u8);
static void ShowPikeResultsWindow(void);
static void ShowFactoryResultsWindow(u8);
static void ShowArenaResultsWindow(void);
static void ShowPyramidResultsWindow(void);
static void ShowLinkContestResultsWindow(void);
static void CopyFrontierBrainText(bool8 playerWonText);

// const rom data
static const u8 gUnknown_08611550[][4] =
{
    [FRONTIER_FACILITY_TOWER]   = {0x23, 0x46, 0x23, 0x01},
    [FRONTIER_FACILITY_DOME]    = {0x04, 0x09, 0x05, 0x00},
    [FRONTIER_FACILITY_PALACE]  = {0x15, 0x2a, 0x15, 0x01},
    [FRONTIER_FACILITY_ARENA]   = {0x1c, 0x38, 0x1c, 0x01},
    [FRONTIER_FACILITY_FACTORY] = {0x15, 0x2a, 0x15, 0x01},
    [FRONTIER_FACILITY_PIKE]    = {0x1c, 0x8c, 0x38, 0x01},
    [FRONTIER_FACILITY_PYRAMID] = {0x15, 0x46, 0x23, 0x00},
};

static const struct FrontierBrainMon sFrontierBrainsMons[][2][3] =
{
    [FRONTIER_FACILITY_TOWER] =
    {
        // Silver Symbol.
        {
            {
                .species = SPECIES_ALAKAZAM,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 24,
                .nature = 15,
                .evs = {106, 0, 152, 152, 100, 0},
                .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_DISABLE},
            },
            {
                .species = SPECIES_ENTEI,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 24,
                .nature = 1,
                .evs = {100, 152, 152, 0, 100, 6},
                .moves = {MOVE_FIRE_BLAST, MOVE_CALM_MIND, MOVE_RETURN, MOVE_ROAR},
            },
            {
                .species = SPECIES_SNORLAX,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 24,
                .nature = 3,
                .evs = {152, 152, 0, 0, 106, 100},
                .moves = {MOVE_BODY_SLAM, MOVE_BELLY_DRUM, MOVE_YAWN, MOVE_SHADOW_BALL},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_RAIKOU,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 31,
                .nature = 15,
                .evs = {158, 0, 252, 100, 0, 0},
                .moves = {MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_REFLECT, MOVE_REST},
            },
            {
                .species = SPECIES_LATIOS,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 31,
                .nature = 15,
                .evs = {252, 0, 252, 6, 0, 0},
                .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_RECOVER, MOVE_DRAGON_CLAW},
            },
            {
                .species = SPECIES_SNORLAX,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 31,
                .nature = 3,
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
                .nature = 2,
                .evs = {152, 152, 106, 0, 100, 0},
                .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_COUNTER},
            },
            {
                .species = SPECIES_SALAMENCE,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 20,
                .nature = 3,
                .evs = {152, 152, 106, 100, 0, 0},
                .moves = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE},
            },
            {
                .species = SPECIES_CHARIZARD,
                .heldItem = ITEM_WHITE_HERB,
                .fixedIV = 20,
                .nature = 17,
                .evs = {100, 152, 106, 152, 0, 0},
                .moves = {MOVE_OVERHEAT, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_EARTHQUAKE},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_SWAMPERT,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 31,
                .nature = 2,
                .evs = {252, 252, 6, 0, 0, 0},
                .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
            },
            {
                .species = SPECIES_METAGROSS,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 31,
                .nature = 2,
                .evs = {252, 252, 6, 0, 0, 0},
                .moves = {MOVE_PSYCHIC, MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_PROTECT},
            },
            {
                .species = SPECIES_LATIAS,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 31,
                .nature = 15,
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
                .nature = 3,
                .evs = {152, 0, 0, 152, 100, 106},
                .moves = {MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM, MOVE_TOXIC, MOVE_FLY},
            },
            {
                .species = SPECIES_SLAKING,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = 16,
                .nature = 0,
                .evs = {152, 152, 0, 106, 100, 0},
                .moves = {MOVE_EARTHQUAKE, MOVE_SWAGGER, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
            },
            {
                .species = SPECIES_LAPRAS,
                .heldItem = ITEM_QUICK_CLAW,
                .fixedIV = 16,
                .nature = 17,
                .evs = {0, 0, 252, 0, 106, 152},
                .moves = {MOVE_ICE_BEAM, MOVE_HORN_DRILL, MOVE_CONFUSE_RAY, MOVE_PROTECT},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_ARCANINE,
                .heldItem = ITEM_WHITE_HERB,
                .fixedIV = 31,
                .nature = 11,
                .evs = {6, 252, 252, 0, 0, 0},
                .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_ROAR, MOVE_PROTECT},
            },
            {
                .species = SPECIES_SLAKING,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = 31,
                .nature = 0,
                .evs = {6, 252, 0, 252, 0, 0},
                .moves = {MOVE_HYPER_BEAM, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_YAWN},
            },
            {
                .species = SPECIES_SUICUNE,
                .heldItem = ITEM_KINGS_ROCK,
                .fixedIV = 31,
                .nature = 11,
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
                .nature = 13,
                .evs = {106, 152, 0, 152, 0, 100},
                .moves = {MOVE_MEGAHORN, MOVE_ROCK_TOMB, MOVE_ENDURE, MOVE_REVERSAL},
            },
            {
                .species = SPECIES_UMBREON,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 20,
                .nature = 20,
                .evs = {152, 0, 100, 0, 152, 106},
                .moves = {MOVE_BODY_SLAM, MOVE_CONFUSE_RAY, MOVE_PSYCHIC, MOVE_FAINT_ATTACK},
            },
            {
                .species = SPECIES_SHEDINJA,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 20,
                .nature = 3,
                .evs = {0, 252, 6, 252, 0, 0},
                .moves = {MOVE_SHADOW_BALL, MOVE_RETURN, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_UMBREON,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 31,
                .nature = 20,
                .evs = {252, 0, 0, 0, 252, 6},
                .moves = {MOVE_DOUBLE_EDGE, MOVE_CONFUSE_RAY, MOVE_REST, MOVE_PSYCHIC},
            },
            {
                .species = SPECIES_GENGAR,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 31,
                .nature = 15,
                .evs = {252, 0, 252, 0, 6, 0},
                .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_DESTINY_BOND},
            },
            {
                .species = SPECIES_BRELOOM,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 31,
                .nature = 13,
                .evs = {6, 252, 0, 252, 0, 0},
                .moves = {MOVE_SPORE, MOVE_FOCUS_PUNCH, MOVE_GIGA_DRAIN, MOVE_HEADBUTT},
            },
        },
    },
    [FRONTIER_FACILITY_FACTORY] =
    {
        // Because Factory's pokemon are random, this facility's Brain also uses random pokemon.
        // What is interesting, this team is actually the one Steven uses in the multi tag battle alongside the player.
        {
            {
                .species = SPECIES_METANG,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = 31,
                .nature = 2,
                .evs = {0, 252, 252, 0, 6, 0},
                .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
            },
            {
                .species = SPECIES_SKARMORY,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = 31,
                .nature = 8,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
            },
            {
                .species = SPECIES_AGGRON,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = 31,
                .nature = 3,
                .evs = {0, 252, 0, 0, 252, 6},
                .moves = {MOVE_THUNDERBOLT, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
            },
        },
        {
            {
                .species = SPECIES_METANG,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = 31,
                .nature = 2,
                .evs = {0, 252, 252, 0, 6, 0},
                .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
            },
            {
                .species = SPECIES_SKARMORY,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = 31,
                .nature = 8,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
            },
            {
                .species = SPECIES_AGGRON,
                .heldItem = ITEM_SITRUS_BERRY,
                .fixedIV = 31,
                .nature = 3,
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
                .nature = 2,
                .evs = {252, 0, 252, 0, 6, 0},
                .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_POISON_FANG, MOVE_GIGA_DRAIN},
            },
            {
                .species = SPECIES_SHUCKLE,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 16,
                .nature = 5,
                .evs = {252, 0, 0, 0, 106, 252},
                .moves = {MOVE_TOXIC, MOVE_SANDSTORM, MOVE_PROTECT, MOVE_REST},
            },
            {
                .species = SPECIES_MILOTIC,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 16,
                .nature = 15,
                .evs = {152, 0, 100, 0, 152, 106},
                .moves = {MOVE_ICE_BEAM, MOVE_MIRROR_COAT, MOVE_SURF, MOVE_RECOVER},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_SEVIPER,
                .heldItem = ITEM_FOCUS_BAND,
                .fixedIV = 31,
                .nature = 5,
                .evs = {252, 0, 0, 0, 252, 6},
                .moves = {MOVE_SWAGGER, MOVE_CRUNCH, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN},
            },
            {
                .species = SPECIES_STEELIX,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 31,
                .nature = 2,
                .evs = {252, 0, 0, 0, 6, 252},
                .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION, MOVE_SCREECH},
            },
            {
                .species = SPECIES_GYARADOS,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 31,
                .nature = 3,
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
                .nature = 3,
                .evs = {152, 152, 0, 0, 106, 100},
                .moves = {MOVE_EXPLOSION, MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER},
            },
            {
                .species = SPECIES_REGISTEEL,
                .heldItem = ITEM_LEFTOVERS,
                .fixedIV = 16,
                .nature = 3,
                .evs = {152, 152, 0, 0, 6, 200},
                .moves = {MOVE_EARTHQUAKE, MOVE_METAL_CLAW, MOVE_TOXIC, MOVE_IRON_DEFENSE},
            },
            {
                .species = SPECIES_REGICE,
                .heldItem = ITEM_CHESTO_BERRY,
                .fixedIV = 16,
                .nature = 15,
                .evs = {106, 0, 152, 0, 100, 152},
                .moves = {MOVE_ICE_BEAM, MOVE_AMNESIA, MOVE_THUNDER, MOVE_REST},
            },
        },
        // Gold Symbol.
        {
            {
                .species = SPECIES_ARTICUNO,
                .heldItem = ITEM_SCOPE_LENS,
                .fixedIV = 31,
                .nature = 16,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_AERIAL_ACE, MOVE_REFLECT},
            },
            {
                .species = SPECIES_ZAPDOS,
                .heldItem = ITEM_LUM_BERRY,
                .fixedIV = 31,
                .nature = 16,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_THUNDER, MOVE_DETECT, MOVE_DRILL_PECK, MOVE_LIGHT_SCREEN},
            },
            {
                .species = SPECIES_MOLTRES,
                .heldItem = ITEM_BRIGHT_POWDER,
                .fixedIV = 31,
                .nature = 16,
                .evs = {6, 0, 252, 252, 0, 0},
                .moves = {MOVE_FIRE_BLAST, MOVE_HYPER_BEAM, MOVE_AERIAL_ACE, MOVE_SAFEGUARD},
            },
        },
    },
};

static const u8 gUnknown_086118B4[][7][4] =
{
    {
        {1, 2, 3, 3}, {1, 1, 0, 0}, {4, 5, 0, 0}, {1, 0, 0, 0}, {3, 4, 0, 0}, {1, 0, 0, 0}, {5, 0, 0, 0}
    },
    {
        {2, 3, 4, 4}, {1, 1, 0, 0}, {4, 5, 0, 0}, {1, 0, 0, 0}, {3, 4, 0, 0}, {1, 0, 0, 0}, {5, 0, 0, 0}
    },
    {
        {3, 4, 5, 5}, {2, 2, 0, 0}, {5, 6, 0, 0}, {1, 0, 0, 0}, {4, 5, 0, 0}, {2, 0, 0, 0}, {6, 0, 0, 0}
    },
    {
        {4, 5, 6, 6}, {2, 2, 0, 0}, {5, 6, 0, 0}, {2, 0, 0, 0}, {4, 5, 0, 0}, {2, 0, 0, 0}, {6, 0, 0, 0}
    },
    {
        {5, 6, 7, 7}, {3, 3, 0, 0}, {6, 7, 0, 0}, {2, 0, 0, 0}, {5, 6, 0, 0}, {2, 0, 0, 0}, {7, 0, 0, 0}
    },
    {
        {6, 7, 8, 8}, {3, 3, 0, 0}, {6, 7, 0, 0}, {2, 0, 0, 0}, {5, 6, 0, 0}, {4, 0, 0, 0}, {7, 0, 0, 0}
    },
    {
        {7, 8, 9, 9}, {4, 4, 0, 0}, {7, 8, 0, 0}, {3, 0, 0, 0}, {6, 7, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}
    },
    {
        {8, 9, 10, 10}, {4, 4, 0, 0}, {7, 8, 0, 0}, {3, 0, 0, 0},{6, 7, 0, 0}, {4, 0, 0, 0}, {8, 0, 0, 0}
    },
    {
        {9, 10, 11, 11}, {5, 5, 0, 0}, {8, 9, 0, 0}, {4, 0, 0, 0}, {7, 8, 0, 0}, {8, 0, 0, 0}, {9, 0, 0, 0}
    },
    {
        {10, 11, 12, 12}, {5, 5, 0, 0}, {8, 9, 0, 0}, {4, 0, 0, 0}, {7, 8, 0, 0}, {8, 0, 0, 0}, {9, 0, 0, 0}
    },
    {
        {11, 12, 13, 13}, {6, 6, 0, 0}, {9, 10, 0, 0}, {5, 0, 0,0}, {8, 9, 0, 0}, {8, 0, 0, 0}, {10, 0, 0, 0}
    },
    {
        {12, 13, 14, 14}, {6, 6, 0, 0}, {9, 10, 0, 0}, {6, 0, 0,0}, {8, 9, 0, 0}, {8, 0, 0, 0}, {10, 0, 0, 0}
    },
    {
        {13, 14, 15, 15}, {7, 7, 0, 0}, {10, 11, 0, 0}, {7, 0, 0, 0}, {9, 10, 0, 0}, {10, 0, 0, 0}, {11, 0, 0, 0}
    },
    {
        {14, 15, 15, 15}, {7, 7, 0, 0}, {10, 11, 0, 0}, {8, 0, 0, 0}, {9, 10, 0, 0}, {10, 0, 0, 0}, {11, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {8, 8, 0, 0}, {11, 12, 0, 0}, {9, 0, 0, 0}, {10, 11, 0, 0}, {10, 0, 0, 0}, {12, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {8, 8, 0, 0}, {11, 12, 0, 0}, {10, 0, 0, 0}, {10, 11, 0, 0}, {10, 0, 0, 0}, {12, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {9, 9, 0, 0}, {12, 13, 0, 0}, {11, 0, 0, 0}, {11, 12, 0, 0}, {12, 0, 0, 0}, {13, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {9, 9, 0, 0}, {12, 13, 0, 0}, {12, 0, 0, 0}, {11, 12, 0, 0}, {12, 0, 0, 0}, {13, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {10, 10, 0, 0}, {13, 14, 0, 0}, {13, 0, 0, 0}, {12, 13, 0, 0}, {12, 0, 0, 0}, {14, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {10, 10, 0, 0}, {13, 14, 0, 0}, {14, 0, 0, 0}, {12, 13, 0, 0}, {12, 0, 0, 0}, {14, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {11, 11, 0, 0}, {14, 15, 0, 0}, {15, 0, 0, 0}, {13, 14, 0, 0}, {12, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {11, 11, 0, 0}, {14, 15, 0, 0}, {15, 0, 0, 0}, {13, 14, 0, 0}, {14, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {12, 12, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {14, 15, 0, 0}, {14, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {12, 12, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {14, 15, 0, 0}, {14, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {13, 13, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 15, 0, 0}, {14, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {13, 13, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {14, 14, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {14, 14, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {15, 15, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 0, 0, 0}
    },
    {
        {15, 15, 15, 15}, {15, 15, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 15, 0, 0}, {15, 0, 0, 0}, {15, 0, 0, 0}
    },
};

static const u16 gUnknown_08611BFC[][2] =
{
    [FRONTIER_FACILITY_TOWER]   = {0x0001, 0x0002},
    [FRONTIER_FACILITY_DOME]    = {0x0004, 0x0008},
    [FRONTIER_FACILITY_PALACE]  = {0x0010, 0x0020},
    [FRONTIER_FACILITY_ARENA]   = {0x0040, 0x0080},
    [FRONTIER_FACILITY_FACTORY] = {0x0100, 0x0200},
    [FRONTIER_FACILITY_PIKE]    = {0x0400, 0x0800},
    [FRONTIER_FACILITY_PYRAMID] = {0x1000, 0x2000},
};

static void (* const sFrontierUtilFuncs[])(void) =
{
    [FRONTIER_UTIL_FUNC_0]                     = sub_81A17A0,
    [FRONTIER_UTIL_FUNC_1]                     = sub_81A1830,
    [FRONTIER_UTIL_FUNC_2]                     = sub_81A1968,
    [FRONTIER_UTIL_FUNC_LOAD_SELECTED_PARTY]   = LoadSelectedParty,
    [FRONTIER_UTIL_FUNC_SOFT_RESET]            = DoSoftReset_,
    [FRONTIER_UTIL_FUNC_SET_FRONTIER_TRAINERS] = SetFrontierTrainers,
    [FRONTIER_UTIL_FUNC_6]                     = sub_81A1B38,
    [FRONTIER_UTIL_FUNC_RESULTS_WINDOW]        = ShowFacilityResultsWindow,
    [FRONTIER_UTIL_FUNC_8]                     = sub_81A31FC,
    [FRONTIER_UTIL_FUNC_9]                     = sub_81A35EC,
    [FRONTIER_UTIL_FUNC_IS_FRONTIER_BRAIN]     = IsTrainerFrontierBrain,
    [FRONTIER_UTIL_FUNC_11]                    = sub_81A3B64,
    [FRONTIER_UTIL_FUNC_GET_FACILITY_SYMBOLS]  = GetFacilitySymbolCount,
    [FRONTIER_UTIL_FUNC_GIVE_FACILITY_SYMBOL]  = GiveFacilitySymbol,
    [FRONTIER_UTIL_FUNC_CHECK_BATTLE_TYPE]     = CheckBattleTypeFlag,
    [FRONTIER_UTIL_FUNC_15]                    = sub_81A3FD4,
    [FRONTIER_UTIL_FUNC_CHECK_VISIT_TRAINER]   = ValidateVisitingTrainer,
    [FRONTIER_UTIL_FUNC_17]                    = sub_81A4230,
    [FRONTIER_UTIL_FUNC_18]                    = sub_81A43A8,
    [FRONTIER_UTIL_FUNC_19]                    = sub_81A4410,
    [FRONTIER_UTIL_FUNC_BUFFER_TRAINER_NAME]   = BufferFrontierTrainerName,
    [FRONTIER_UTIL_FUNC_21]                    = sub_81A447C,
    [FRONTIER_UTIL_FUNC_SET_BRAIN_OBJECT]      = SetFacilityBrainEventObject,
};

static const struct WindowTemplate gUnknown_08611C74 =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 0x1c,
    .height = 0x12,
    .paletteNum = 15,
    .baseBlock = 1
};

static const struct WindowTemplate gUnknown_08611C7C =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 2,
    .width = 0x1a,
    .height = 15,
    .paletteNum = 15,
    .baseBlock = 1
};

static const struct WindowTemplate gUnknown_08611C84 =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 1,
    .width = 0x1a,
    .height = 17,
    .paletteNum = 15,
    .baseBlock = 1
};

// Second field - whether the character is female.
static const u8 sFacilityToBrainEventObjGfx[][2] =
{
    [FRONTIER_FACILITY_TOWER]   = {EVENT_OBJ_GFX_ANABEL,  TRUE},
    [FRONTIER_FACILITY_DOME]    = {EVENT_OBJ_GFX_TUCKER,  FALSE},
    [FRONTIER_FACILITY_PALACE]  = {EVENT_OBJ_GFX_SPENSER, FALSE},
    [FRONTIER_FACILITY_ARENA]   = {EVENT_OBJ_GFX_GRETA,   TRUE},
    [FRONTIER_FACILITY_FACTORY] = {EVENT_OBJ_GFX_NOLAND,  FALSE},
    [FRONTIER_FACILITY_PIKE]    = {EVENT_OBJ_GFX_LUCY,    TRUE},
    [FRONTIER_FACILITY_PYRAMID] = {EVENT_OBJ_GFX_BRANDON, FALSE},
};

const u16 gFrontierBannedSpecies[] =
{
    SPECIES_MEW, SPECIES_MEWTWO, SPECIES_HO_OH, SPECIES_LUGIA, SPECIES_CELEBI,
    SPECIES_KYOGRE, SPECIES_GROUDON, SPECIES_RAYQUAZA, SPECIES_JIRACHI, SPECIES_DEOXYS, 0xFFFF
};

static const u8 *const sRecordsWindowChallengeTexts[][2] =
{
    [RANKING_HALL_BATTLE_TOWER_SINGLES] = {gText_BattleTower2,  gText_FacilitySingle},
    [RANKING_HALL_BATTLE_TOWER_DOUBLES] = {gText_BattleTower2,  gText_FacilityDouble},
    [RANKING_HALL_BATTLE_TOWER_MULTIS]  = {gText_BattleTower2,  gText_FacilityMulti},
    [RANKING_HALL_BATTLE_DOME]          = {gText_BattleDome,    gText_FacilitySingle},
    [RANKING_HALL_BATTLE_PALACE]        = {gText_BattlePalace,  gText_FacilitySingle},
    [RANKING_HALL_BATTLE_ARENA]         = {gText_BattleArena,   gText_Facility},
    [RANKING_HALL_BATTLE_FACTORY]       = {gText_BattleFactory, gText_FacilitySingle},
    [RANKING_HALL_BATTLE_PIKE]          = {gText_BattlePike,    gText_Facility},
    [RANKING_HALL_BATTLE_PYRAMID]       = {gText_BattlePyramid, gText_Facility},
    [RANKING_HALL_BATTLE_TOWER_LINK]    = {gText_BattleTower2,  gText_FacilityLink},
};

static const u8 *const sLevelModeText[] =
{
    gText_RecordsLv50,
    gText_RecordsOpenLevel,
};

static const u8 *const sHallFacilityToRecordsText[] =
{
    [RANKING_HALL_BATTLE_TOWER_SINGLES] = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_BATTLE_TOWER_DOUBLES] = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_BATTLE_TOWER_MULTIS]  = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_BATTLE_DOME]          = gText_FrontierFacilityClearStreak,
    [RANKING_HALL_BATTLE_PALACE]        = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_BATTLE_ARENA]         = gText_FrontierFacilityKOsStreak,
    [RANKING_HALL_BATTLE_FACTORY]       = gText_FrontierFacilityWinStreak,
    [RANKING_HALL_BATTLE_PIKE]          = gText_FrontierFacilityRoomsCleared,
    [RANKING_HALL_BATTLE_PYRAMID]       = gText_FrontierFacilityFloorsCleared,
    [RANKING_HALL_BATTLE_TOWER_LINK]    = gText_FrontierFacilityWinStreak,
};

static const u16 gFacilityToBrainTrainerId[] =
{
    [FRONTIER_FACILITY_TOWER]   = TRAINER_ANABEL,
    [FRONTIER_FACILITY_DOME]    = TRAINER_TUCKER,
    [FRONTIER_FACILITY_PALACE]  = TRAINER_SPENSER,
    [FRONTIER_FACILITY_ARENA]   = TRAINER_GRETA,
    [FRONTIER_FACILITY_FACTORY] = TRAINER_NOLAND,
    [FRONTIER_FACILITY_PIKE]    = TRAINER_LUCY,
    [FRONTIER_FACILITY_PYRAMID] = TRAINER_BRANDON,
};

static const u8 *const gUnknown_08611D40[] =
{
    gText_082C843F,
    gText_082C848B,
    gText_082C8628,
    gText_082C85B4,
    gText_082C8512,
    gText_082C859D,
    gText_082C86C3,
};

static const u8 *const gUnknown_08611D5C[] =
{
    gText_082C8458,
    gText_082C84C1,
    gText_082C8662,
    gText_082C85E3,
    gText_082C853B,
    gText_082C85A4,
    gText_082C86FE,
};

static const u8 *const gUnknown_08611D78[] =
{
    gText_082C846C,
    gText_082C84D0,
    gText_082C8682,
    gText_082C85F5,
    gText_082C8561,
    gText_082C85A9,
    gText_082C8739,
};

static const u8 *const gUnknown_08611D94[] =
{
    gText_082C8480,
    gText_082C84F7,
    gText_082C86B3,
    gText_082C8611,
    gText_082C8589,
    gText_082C85AE,
    gText_082C877B,
};

static const u8 *const *const gUnknown_08611DB0[] =
{
    gUnknown_08611D40,
    gUnknown_08611D78,
};

static const u8 *const *const gUnknown_08611DB8[] =
{
    gUnknown_08611D5C,
    gUnknown_08611D94,
};

// code
void CallFrontierUtilFunc(void)
{
    sFrontierUtilFuncs[gSpecialVar_0x8004]();
}

static void sub_81A17A0(void)
{
    VarSet(VAR_TEMP_0, 0xFF);
    switch (gSaveBlock2Ptr->frontier.field_CA8)
    {
    case 0:
        break;
    case 1:
        FrontierGamblerSetWonOrLost(FALSE);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 4:
        FrontierGamblerSetWonOrLost(FALSE);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 3:
        FrontierGamblerSetWonOrLost(TRUE);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 2:
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    }
}

static void sub_81A1830(void)
{
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 currSymbol = GetPlayerSymbolCountForFacility(facility);
    if (currSymbol == 2)
        currSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA8;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA9_a;
        break;
    case 5:
        gSpecialVar_Result = gBattleOutcome;
        gBattleOutcome = 0;
        break;
    case 6:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA9_b;
        break;
    case 7:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D00 & gUnknown_08611BFC[facility][currSymbol];
        break;
    }
}

static void sub_81A1968(void)
{
    s32 i;
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 currSymbol = GetPlayerSymbolCountForFacility(facility);
    if (currSymbol == 2)
        currSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.lvlMode = gSpecialVar_0x8006;
        break;
    case 2:
        gSaveBlock2Ptr->frontier.curChallengeBattleNum = gSpecialVar_0x8006;
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_CA9_a = gSpecialVar_0x8006;
        break;
    case 4:
        for (i = 0; i < 4; i++)
            gSaveBlock2Ptr->frontier.selectedPartyMons[i] = gSelectedOrderFromParty[i];
        break;
    case 6:
        gSaveBlock2Ptr->frontier.field_CA9_b = gSpecialVar_0x8006;
        break;
    case 7:
        gSaveBlock2Ptr->frontier.field_D00 |= gUnknown_08611BFC[facility][currSymbol];
        break;
    }
}

static void LoadSelectedParty(void)
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

static void sub_81A1B38(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
            gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1] = gPlayerParty[i];
    }
}

static void ShowFacilityResultsWindow(void)
{
    if (gSpecialVar_0x8006 > 3)
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
    case RESULTS_LINK_CONTEST:
        ShowLinkContestResultsWindow();
        break;
    }
}

static bool8 sub_81A1C24(u32 flags)
{
    if (gSaveBlock2Ptr->frontier.field_CDC & flags)
        return TRUE;
    else
        return FALSE;
}

static void PrintAligned(const u8 *str, s32 y)
{
    s32 x = GetStringCenterAlignXOffset(1, str, 224);
    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, y, TEXT_SPEED_FF, NULL);
}

static void PrintHyphens(s32 y)
{
    s32 i;
    u8 text[37];

    for (i = 0; i < 36; i++)
        text[i] = CHAR_HYPHEN;
    text[i] = EOS;

    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, 1, text, 4, y, TEXT_SPEED_FF, NULL);
}

// Battle Tower records.
static void TowerPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void TowerPrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode];
    TowerPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 TowerGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void TowerPrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = TowerGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(2);
        else
            isCurrent = sub_81A1C24(1);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x8000);
        else
            isCurrent = sub_81A1C24(0x4000);
        break;
    case FRONTIER_MODE_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x20000);
        else
            isCurrent = sub_81A1C24(0x10000);
        break;
    case FRONTIER_MODE_LINK_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x80000);
        else
            isCurrent = sub_81A1C24(0x40000);
        break;
    }

    if (isCurrent == TRUE)
        TowerPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        TowerPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowTowerResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
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
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 132, 49);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 132, 65);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 97);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Dome records.
static u16 DomeGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PrintTwoStrings(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str1, x1, y, TEXT_SPEED_FF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void DomePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = DomeGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(8);
        else
            isCurrent = sub_81A1C24(4);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x200000);
        else
            isCurrent = sub_81A1C24(0x100000);
        break;
    }

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_ClearStreak, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_ClearStreak, winStreak, x1, x2, y);
}

static void ShowDomeResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleTourneyResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleTourneyResults);

    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 64, 121, 33);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_50], 64, 121, 49);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_50], 64, 112, 65);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 64, 121, 97);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_OPEN], 64, 121, 113);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_OPEN], 64, 112, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Palace records.
static void PalacePrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void PalacePrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode];
    PalacePrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PalaceGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PalacePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PalaceGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x20);
        else
            isCurrent = sub_81A1C24(0x10);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x800000);
        else
            isCurrent = sub_81A1C24(0x400000);
    }

    if (isCurrent == TRUE)
        PalacePrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PalacePrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPalaceResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleHallResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleHallResults);

    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 131, 49);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 131, 65);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 97);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Pike records.
static u16 PikeGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PikePrintCleared(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str1, x1, y, TEXT_SPEED_FF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void PikePrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PikeGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x800);
    else
        isCurrent = sub_81A1C24(0x400);

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_RoomsCleared, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_RoomsCleared, winStreak, x1, x2, y);
}

static void ShowPikeResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, gText_BattleChoiceResults);
    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 114, 33);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_50], 64, 114, 49);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_50], 64, 114, 65);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 114, 97);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_OPEN], 64, 114, 113);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_OPEN], 64, 114, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Arena records.
static void ArenaPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_KOsInARow);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void ArenaPrintRecordStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode];
    ArenaPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 ArenaGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void ArenaPrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = ArenaGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x80);
    else
        isCurrent = sub_81A1C24(0x40);

    if (isCurrent == TRUE)
        ArenaPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        ArenaPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowArenaResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHyphens(10);
    StringExpandPlaceholders(gStringVar4, gText_SetKOTourneyResults);
    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 72, 126, 49);
    ArenaPrintRecordStreak(FRONTIER_LVL_50, 72, 126, 65);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 72, 126, 97);
    ArenaPrintRecordStreak(FRONTIER_LVL_OPEN, 72, 126, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Factory records.
static void FactoryPrintStreak(const u8 *str, u16 num1, u16 num2, u8 x1, u8 x2, u8 x3, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num1 > 9999)
        num1 = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num1, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);

    ConvertIntToDecimalStringN(gStringVar1, num2, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_TimesVar1);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x3, y, TEXT_SPEED_FF, NULL);
}

static void FactoryPrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    u16 num1 = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode];
    u16 num2 = gSaveBlock2Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode];
    FactoryPrintStreak(gText_Record, num1, num2, x1, x2, x3, y);
}

static u16 FactoryGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static u16 FactoryGetRentsCount(u8 battleMode, u8 lvlMode)
{
    u16 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
    if (rents > 9999)
        return 9999;
    else
        return rents;
}

static void FactoryPrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = FactoryGetWinStreak(battleMode, lvlMode);
    u16 rents = FactoryGetRentsCount(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x200);
        else
            isCurrent = sub_81A1C24(0x100);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x2000000);
        else
            isCurrent = sub_81A1C24(0x1000000);
        break;
    }

    if (isCurrent == TRUE)
        FactoryPrintStreak(gText_Current, winStreak, rents, x1, x2, x3, y);
    else
        FactoryPrintStreak(gText_Prev, winStreak, rents, x1, x2, x3, y);
}

static void ShowFactoryResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapSingleResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapDoubleResults);

    PrintAligned(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_RentalSwap, 152, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 49);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_50, 8, 64, 158, 65);
    FactoryPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 113);
    FactoryPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Pyramid records.
static void PyramidPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_FloorsCleared);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

static void PyramidPrintRecordStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode];
    PyramidPrintStreak(gText_Record, num, x1, x2, y);
}

static u16 PyramidGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

static void PyramidPrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PyramidGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x2000);
    else
        isCurrent = sub_81A1C24(0x1000);

    if (isCurrent == TRUE)
        PyramidPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PyramidPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

static void ShowPyramidResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, gText_BattleQuestResults);
    PrintAligned(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 111, 49);
    PyramidPrintRecordStreak(FRONTIER_LVL_50, 64, 111, 65);
    PyramidPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 111, 97);
    PyramidPrintRecordStreak(FRONTIER_LVL_OPEN, 64, 111, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Link contest records. Why is it in this file?
static void ShowLinkContestResultsWindow(void)
{
    const u8 *str;
    s32 i, j;
    s32 x;

    gRecordsWindowId = AddWindow(&gUnknown_08611C7C);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));

    StringExpandPlaceholders(gStringVar4, gText_LinkContestResults);
    x = GetStringCenterAlignXOffset(1, gStringVar4, 208);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x, 1, TEXT_SPEED_FF, NULL);

    str = gText_1st;
    x = GetStringRightAlignXOffset(1, str, 38) + 50;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    str = gText_2nd;
    x = GetStringRightAlignXOffset(1, str, 38) + 88;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    str = gText_3rd;
    x = GetStringRightAlignXOffset(1, str, 38) + 126;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    str = gText_4th;
    x = GetStringRightAlignXOffset(1, str, 38) + 164;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, 25, TEXT_SPEED_FF, NULL);

    x = 6;
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Cool, x, 41, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Beauty, x, 57, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Cute, x, 73, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Smart, x, 89, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Tough, x, 105, TEXT_SPEED_FF, NULL);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            ConvertIntToDecimalStringN(gStringVar4, gSaveBlock2Ptr->contestLinkResults[i][j], STR_CONV_MODE_RIGHT_ALIGN, 4);
            AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, (j * 38) + 64, (i * 16) + 41, TEXT_SPEED_FF, NULL);
        }
    }

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

static void sub_81A31FC(void)
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
                StringCopy(gSaveBlock2Ptr->frontier.opponentName[lvlMode], name);
                SetTrainerId(gLinkPlayers[gBattleScripting.multiplayerId ^ 1].trainerId, gSaveBlock2Ptr->frontier.field_EF1[lvlMode]);
            }
            if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] > 1
                && sub_80EE818())
            {
                switch (battleMode)
                {
                case FRONTIER_MODE_SINGLES:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 1);
                    break;
                case FRONTIER_MODE_DOUBLES:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 2);
                    break;
                case FRONTIER_MODE_MULTIS:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 3);
                    break;
                case FRONTIER_MODE_LINK_MULTIS:
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode], 4);
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
                && sub_80EE818())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode], 5);
                else
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode], 6);
            }
        }
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] > 1
                && sub_80EE818())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], 11);
                else
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode], 12);
            }
        }
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > 1
                && sub_80EE818())
            {
                sub_80EE8C8(gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode], 10);
            }
        }
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode])
        {
            gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
            gSaveBlock2Ptr->frontier.factoryRecordRentsCount[battleMode][lvlMode] = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
            if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] > 1
                && sub_80EE818())
            {
                if (battleMode == FRONTIER_MODE_SINGLES)
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], 7);
                else
                    sub_80EE8C8(gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode], 8);
            }
        }
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pikeRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.pikeRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] > 1
                && sub_80EE818())
            {
                sub_80EE8C8(gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode], 9);
            }
        }
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode])
        {
            gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
            if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > 1
                && sub_80EE818())
            {
                sub_80EE8C8(gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode], 13);
            }
        }
        break;
    }
}

static void sub_81A35EC(void)
{
    VarGet(VAR_FRONTIER_FACILITY); // Unused return value.
    gSpecialVar_Result = sub_81A3610();
}

u8 sub_81A3610(void)
{
    s32 ret = 0;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 val = GetCurrentFacilityWinStreak();
    s32 r5 = val + gUnknown_08611550[facility][3];
    s32 symbolsCount;

    if (battleMode != FRONTIER_MODE_SINGLES)
        return 0;

    symbolsCount = GetPlayerSymbolCountForFacility(facility);
    switch (symbolsCount)
    {
    case 0:
    case 1:
        if (r5 == gUnknown_08611550[facility][symbolsCount])
            ret = symbolsCount + 1;
        break;
    case 2:
    default:
        if (r5 == gUnknown_08611550[facility][0])
            ret = 3;
        else if (r5 == gUnknown_08611550[facility][1])
            ret = 4;
        else if (r5 > gUnknown_08611550[facility][1] && (r5 - gUnknown_08611550[facility][1]) % gUnknown_08611550[facility][2] == 0)
            ret = 4;
        break;
    }

    return ret;
}

void CopyFrontierTrainerText(u8 whichText, u16 trainerId)
{
    switch (whichText)
    {
    case FRONTIER_BEFORE_TEXT:
        if (trainerId == TRAINER_EREADER)
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.greeting);
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
            CopyFrontierBrainText(FALSE);
        else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
            FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
        else if (trainerId < TRAINER_RECORD_MIXING_APPRENTICE)
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.towerRecords[trainerId - TRAINER_RECORD_MIXING_FRIEND].greeting);
        else
            CopyFriendsApprenticeChallengeText(trainerId - TRAINER_RECORD_MIXING_APPRENTICE);
        break;
    case FRONTIER_PLAYER_LOST_TEXT:
        if (trainerId == TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerLost);
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            CopyFrontierBrainText(FALSE);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
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
                FrontierSpeechToString(gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].easyChatWords);
        }
        break;
    case FRONTIER_PLAYER_WON_TEXT:
        if (trainerId == TRAINER_EREADER)
        {
            FrontierSpeechToString(gSaveBlock2Ptr->frontier.ereaderTrainer.farewellPlayerWon);
        }
        else if (trainerId == TRAINER_FRONTIER_BRAIN)
        {
            CopyFrontierBrainText(TRUE);
        }
        else if (trainerId < TRAINER_RECORD_MIXING_FRIEND)
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
                FrontierSpeechToString(gApprentices[trainerId].easyChatWords);
            }
            else
            {
                trainerId = gSaveBlock2Ptr->apprentices[trainerId - TRAINER_RECORD_MIXING_APPRENTICE].id;
                FrontierSpeechToString(gApprentices[trainerId].easyChatWords);
            }
        }
        break;
    }
}

void sub_81A3908(void)
{
    s32 battleMode, lvlMode;

    gSaveBlock2Ptr->frontier.field_CDC = 0;
    for (battleMode = 0; battleMode < 4; battleMode++)
    {
        for (lvlMode = 0; lvlMode < 2; lvlMode++)
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
    if (gSaveBlock2Ptr->frontier.field_CA8 != 0)
        gSaveBlock2Ptr->frontier.field_CA8 = 1;
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

void sub_81A3ACC(void)
{
    s32 i;

    for (i = 0; i < 20; i++)
        gSaveBlock2Ptr->frontier.trainerIds[i] = 0xFFFF;
}

static void IsTrainerFrontierBrain(void)
{
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

u8 GetPlayerSymbolCountForFacility(u8 facility)
{
    return FlagGet(FLAG_SYS_TOWER_SILVER + facility * 2)
         + FlagGet(FLAG_SYS_TOWER_GOLD + facility * 2);
}

static void sub_81A3B64(void)
{
    s32 challengeNum = 0;
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 points;

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        challengeNum = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_DOME:
        challengeNum = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
        break;
    case FRONTIER_FACILITY_PALACE:
        challengeNum = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_ARENA:
        challengeNum = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_FACTORY:
        challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
        break;
    case FRONTIER_FACILITY_PIKE:
        challengeNum = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] / 14;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        challengeNum = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7;
        break;
    }

    if (challengeNum != 0)
        challengeNum--;
    if (challengeNum >= ARRAY_COUNT(gUnknown_086118B4))
        challengeNum = ARRAY_COUNT(gUnknown_086118B4) - 1;

    points = gUnknown_086118B4[challengeNum][facility][battleMode];
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
        points += 10;
    gSaveBlock2Ptr->frontier.battlePoints += points;
    ConvertIntToDecimalStringN(gStringVar1, points, STR_CONV_MODE_LEFT_ALIGN, 2);
    if (gSaveBlock2Ptr->frontier.battlePoints > 9999)
        gSaveBlock2Ptr->frontier.battlePoints = 9999;

    points = gSaveBlock2Ptr->frontier.field_EBA;
    points += gUnknown_086118B4[challengeNum][facility][battleMode];
    IncrementDailyBattlePoints(gUnknown_086118B4[challengeNum][facility][battleMode]);
    if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
    {
        points += 10;
        IncrementDailyBattlePoints(10);
    }
    if (points > 0xFFFF)
        points = 0xFFFF;
    gSaveBlock2Ptr->frontier.field_EBA = points;
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

static u8 sub_81A3DD0(u16 species, u8 arg1, s32 arg2)
{
    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        arg1++;
        switch (arg1)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
            if (arg2 == arg1)
                StringAppend(gStringVar1, gText_SpaceAndSpace);
            else if (arg2 > arg1)
                StringAppend(gStringVar1, gText_CommaSpace);
            break;
        case 2:
            if (arg1 == arg2)
                StringAppend(gStringVar1, gText_SpaceAndSpace);
            else
                StringAppend(gStringVar1, gText_CommaSpace);
            StringAppend(gStringVar1, gText_NewLine);
            break;
        default:
            if (arg1 == arg2)
                StringAppend(gStringVar1, gText_SpaceAndSpace);
            else
                StringAppend(gStringVar1, gText_CommaSpace);
            StringAppend(gStringVar1, gText_ScrollTextUp);
            break;
        }
        StringAppend(gStringVar1, gSpeciesNames[species]);
    }

    return arg1;
}

static void AppendIfValid(u16 species, u16 heldItem, u16 hp, u8 lvlMode, u8 monLevel, u16 *speciesArray, u16 *itemsArray, u8 *count)
{
    s32 i = 0;

    if (species == SPECIES_EGG || species == SPECIES_NONE)
        return;

    for (i = 0; gFrontierBannedSpecies[i] != 0xFFFF && gFrontierBannedSpecies[i] != species; i++)
        ;

    if (gFrontierBannedSpecies[i] != 0xFFFF)
        return;
    if (lvlMode == FRONTIER_LVL_50 && monLevel > 50)
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

static void sub_81A3FD4(void)
{
    u16 speciesArray[6];
    u16 itemArray[6];
    s32 monId = 0;
    s32 toChoose = 0;
    u8 count = 0;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 monIdLooper;

    switch (battleMode)
    {
    case FRONTIER_MODE_SINGLES:
        toChoose = 3;
        break;
    case FRONTIER_MODE_MULTIS:
    case FRONTIER_MODE_LINK_MULTIS:
        toChoose = 2;
        break;
    case FRONTIER_MODE_DOUBLES:
        if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_TOWER)
            toChoose = 4;
        else
            toChoose = 3;
        break;
    }

    monIdLooper = 0;
    do
    {
        monId = monIdLooper;
        count = 0;
        do
        {
            u16 species = GetMonData(&gPlayerParty[monId], MON_DATA_SPECIES2);
            u16 heldItem = GetMonData(&gPlayerParty[monId], MON_DATA_HELD_ITEM);
            u8 level = GetMonData(&gPlayerParty[monId], MON_DATA_LEVEL);
            u16 hp = GetMonData(&gPlayerParty[monId], MON_DATA_HP);
            if (VarGet(VAR_FRONTIER_FACILITY) == FRONTIER_FACILITY_PYRAMID)
            {
                if (heldItem == 0)
                    AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &count);
            }
            else
            {
                AppendIfValid(species, heldItem, hp, gSpecialVar_Result, level, speciesArray, itemArray, &count);
            }
            monId++;
            if (monId >= PARTY_SIZE)
                monId = 0;
        } while (monId != monIdLooper);

        monIdLooper++;
    } while (monIdLooper < PARTY_SIZE && count < toChoose);

    if (count < toChoose)
    {
        s32 i;
        s32 caughtBannedMons = 0;
        s32 species = gFrontierBannedSpecies[0];
        for (i = 0; species != 0xFFFF; i++, species = gFrontierBannedSpecies[i])
        {
            if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
                caughtBannedMons++;
        }
        gStringVar1[0] = EOS;
        gSpecialVar_0x8004 = 1;
        count = 0;
        for (i = 0; gFrontierBannedSpecies[i] != 0xFFFF; i++)
            count = sub_81A3DD0(gFrontierBannedSpecies[i], count, caughtBannedMons);

        if (count == 0)
        {
            StringAppend(gStringVar1, gText_Space2);
            StringAppend(gStringVar1, gText_Are);
        }
        else
        {
            if (count & 1)
                StringAppend(gStringVar1, gText_ScrollTextUp);
            else
                StringAppend(gStringVar1, gText_Space2);
            StringAppend(gStringVar1, gText_Are2);
        }
    }
    else
    {
        gSpecialVar_0x8004 = 0;
        gSaveBlock2Ptr->frontier.lvlMode = gSpecialVar_Result;
    }
}

static void ValidateVisitingTrainer(void)
{
    ValidateEReaderTrainer();
}

static void sub_81A4230(void)
{
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);

    switch (facility)
    {
    case FRONTIER_FACILITY_TOWER:
        if (gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode] < 9999)
        {
            gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode]++;
            if (battleMode == FRONTIER_MODE_SINGLES)
            {
                SetGameStat(GAME_STAT_BATTLE_TOWER_BEST_STREAK, gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode]);
                gSaveBlock2Ptr->frontier.field_D02 = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
            }
        }
        break;
    case FRONTIER_FACILITY_DOME:
        if (gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode]++;
        if (gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PALACE:
        if (gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_ARENA:
        if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_FACTORY:
        if (gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]++;
        break;
    case FRONTIER_FACILITY_PIKE:
        if (gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode]++;
        break;
    case FRONTIER_FACILITY_PYRAMID:
        if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] < 9999)
            gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode]++;
        break;
    }
}

static void sub_81A43A8(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock2Ptr->frontier.selectedPartyMons[i] != 0)
        {
            u16 item = GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_HELD_ITEM, NULL);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
        }
    }
}

static void sub_81A4410(void)
{
    gSpecialVar_Result = MoveRecordedBattleToSaveData();
    gSaveBlock2Ptr->frontier.field_CA9_b = 1;
}

static void BufferFrontierTrainerName(void)
{
    switch (gSpecialVar_0x8005)
    {
    case 0:
        GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
        break;
    case 1:
        GetFrontierTrainerName(gStringVar2, gTrainerBattleOpponent_A);
        break;
    }
}

static void sub_81A447C(void)
{
    u8 i, j, k;

    for (i = 0; i < 4; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                for (k = 0; k < MAX_MON_MOVES; k++)
                {
                    if (GetMonData(&gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1], MON_DATA_MOVE1 + k, NULL)
                        == GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j, NULL))
                        break;
                }
                if (k == MAX_MON_MOVES)
                    SetMonMoveSlot(&gPlayerParty[i], MOVE_SKETCH, j);
            }
            gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1] = gPlayerParty[i];
        }
    }
}

static void SetFacilityBrainEventObject(void)
{
    SetFrontierBrainEventObjGfx(VarGet(VAR_FRONTIER_FACILITY));
}

// Battle Frontier Ranking Hall records.
static void Print1PRecord(s32 position, s32 x, s32 y, struct RankingHall1P *hallRecord, s32 hallFacilityId)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    hallRecord->name[PLAYER_NAME_LENGTH] = EOS;
    if (hallRecord->winStreak)
    {
        TVShowConvertInternationalString(text, hallRecord->name, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, 1, text, (x + 2) * 8, (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
        winStreak = hallRecord->winStreak;
        if (winStreak > 9999)
            winStreak = 9999;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, sHallFacilityToRecordsText[hallFacilityId]);
        AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, GetStringRightAlignXOffset(1, sHallFacilityToRecordsText[hallFacilityId], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    }
}

static void Print2PRecord(s32 position, s32 x, s32 y, struct RankingHall2P *hallRecord)
{
    u8 text[32];
    u16 winStreak;

    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_123Dot[position], x * 8, (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    if (hallRecord->winStreak)
    {
        hallRecord->name1[PLAYER_NAME_LENGTH] = EOS;
        hallRecord->name2[PLAYER_NAME_LENGTH] = EOS;
        TVShowConvertInternationalString(text, hallRecord->name1, hallRecord->language);
        AddTextPrinterParameterized(gRecordsWindowId, 1, text, (x + 2) * 8, (8 * (y + 5 * position - 1)) + 1, TEXT_SPEED_FF, NULL);
        if (IsStringJapanese(hallRecord->name2))
            TVShowConvertInternationalString(text, hallRecord->name2, LANGUAGE_JAPANESE);
        else
            StringCopy(text, hallRecord->name2);
        AddTextPrinterParameterized(gRecordsWindowId, 1, text, (x + 4) * 8, (8 * (y + 5 * position + 1)) + 1, TEXT_SPEED_FF, NULL);

        winStreak = hallRecord->winStreak;
        if (winStreak > 9999)
            winStreak = 9999;
        ConvertIntToDecimalStringN(gStringVar2, winStreak, STR_CONV_MODE_RIGHT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, sHallFacilityToRecordsText[RANKING_HALL_BATTLE_TOWER_LINK]);
        AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, GetStringRightAlignXOffset(1, sHallFacilityToRecordsText[RANKING_HALL_BATTLE_TOWER_LINK], 0xC8), (8 * (y + 5 * position)) + 1, TEXT_SPEED_FF, NULL);
    }
}

static void Fill1PRecords(struct RankingHall1P *dst, s32 hallFacilityId, s32 lvlMode)
{
    s32 i, j;
    struct RankingHall1P record1P[4];
    struct PlayerHallRecords *playerHallRecords = calloc(1, sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < 3; i++)
        record1P[i] = gSaveBlock2Ptr->hallRecords1P[hallFacilityId][lvlMode][i];

    record1P[3] = playerHallRecords->onePlayer[hallFacilityId][lvlMode];

    for (i = 0; i < 3; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < 4; j++)
        {
            if (record1P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record1P[j].winStreak;
            }
        }
        if (record1P[3].winStreak >= highestWinStreak)
            highestId = 3;

        dst[i] = record1P[highestId];
        record1P[highestId].winStreak = 0;
    }

    free(playerHallRecords);
}

static void Fill2PRecords(struct RankingHall2P *dst, s32 lvlMode)
{
    s32 i, j;
    struct RankingHall2P record2P[4];
    struct PlayerHallRecords *playerHallRecords = calloc(1, sizeof(struct PlayerHallRecords));
    GetPlayerHallRecords(playerHallRecords);

    for (i = 0; i < 3; i++)
        record2P[i] = gSaveBlock2Ptr->hallRecords2P[lvlMode][i];

    record2P[3] = playerHallRecords->twoPlayers[lvlMode];

    for (i = 0; i < 3; i++)
    {
        s32 highestWinStreak = 0;
        s32 highestId = 0;
        for (j = 0; j < 3; j++)
        {
            if (record2P[j].winStreak > highestWinStreak)
            {
                highestId = j;
                highestWinStreak = record2P[j].winStreak;
            }
        }
        if (record2P[3].winStreak >= highestWinStreak)
            highestId = 3;

        dst[i] = record2P[highestId];
        record2P[highestId].winStreak = 0;
    }

    free(playerHallRecords);
}

static void PrintHallRecords(s32 hallFacilityId, s32 lvlMode)
{
    s32 i;
    s32 x;
    struct RankingHall1P records1P[3];
    struct RankingHall2P records2P[3];

    StringCopy(gStringVar1, sRecordsWindowChallengeTexts[hallFacilityId][0]);
    StringExpandPlaceholders(gStringVar4, sRecordsWindowChallengeTexts[hallFacilityId][1]);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, 0, 1, TEXT_SPEED_FF, NULL);
    x = GetStringRightAlignXOffset(1, sLevelModeText[lvlMode], 0xD0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, sLevelModeText[lvlMode], x, 1, TEXT_SPEED_FF, NULL);
    if (hallFacilityId == RANKING_HALL_BATTLE_TOWER_LINK)
    {
        gSaveBlock2Ptr->frontier.opponentName[0][PLAYER_NAME_LENGTH] = EOS;
        gSaveBlock2Ptr->frontier.opponentName[1][PLAYER_NAME_LENGTH] = EOS;
        Fill2PRecords(records2P, lvlMode);
        for (i = 0; i < 3; i++)
            Print2PRecord(i, 1, 4, &records2P[i]);
    }
    else
    {
        Fill1PRecords(records1P, hallFacilityId, lvlMode);
        for (i = 0; i < 3; i++)
            Print1PRecord(i, 1, 4, &records1P[i], hallFacilityId);
    }
}

void ShowRankingHallRecordsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C84);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_50);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

void ScrollRankingHallRecordsWindow(void)
{
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    PrintHallRecords(gSpecialVar_0x8005, FRONTIER_LVL_OPEN);
    CopyWindowToVram(gRecordsWindowId, 2);
}

void ClearRankingHallRecords(void)
{
    s32 i, j, k;

    for (i = 0; i < HALL_FACILITIES_COUNT; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 3; k++)
            {
                CopyTrainerId(gSaveBlock2Ptr->hallRecords1P[i][j][k].id, 0); // BUG: Passing 0 as a pointer instead of a pointer holding a value of 0.
                gSaveBlock2Ptr->hallRecords1P[i][j][k].name[0] = EOS;
                gSaveBlock2Ptr->hallRecords1P[i][j][k].winStreak = 0;
            }
        }
    }

    for (j = 0; j < 2; j++)
    {
        for (k = 0; k < 3; k++)
        {
            CopyTrainerId(gSaveBlock2Ptr->hallRecords2P[j][k].id1, 0); // BUG: Passing 0 as a pointer instead of a pointer holding a value of 0.
            CopyTrainerId(gSaveBlock2Ptr->hallRecords2P[j][k].id2, 0); // BUG: Passing 0 as a pointer instead of a pointer holding a value of 0.
            gSaveBlock2Ptr->hallRecords2P[j][k].name1[0] = EOS;
            gSaveBlock2Ptr->hallRecords2P[j][k].name2[0] = EOS;
            gSaveBlock2Ptr->hallRecords2P[j][k].winStreak = 0;
        }
    }
}

void sub_81A4C30(void)
{
    s32 i;
    struct Pokemon *monsParty = calloc(PARTY_SIZE, sizeof(struct Pokemon));

    for (i = 0; i < PARTY_SIZE; i++)
        monsParty[i] = gPlayerParty[i];

    i = gPlayerPartyCount;
    LoadPlayerParty();
    SetContinueGameWarpStatusToDynamicWarp();
    TrySavingData(SAVE_LINK);
    ClearContinueGameWarpStatus2();
    gPlayerPartyCount = i;

    for (i = 0; i < PARTY_SIZE; i++)
        gPlayerParty[i] = monsParty[i];

    free(monsParty);
}

// Frontier Brain functions.
u8 GetFrontierBrainTrainerPicIndex(void)
{
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    return gTrainers[gFacilityToBrainTrainerId[facility]].trainerPic;
}

u8 GetFrontierBrainTrainerClass(void)
{
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    return gTrainers[gFacilityToBrainTrainerId[facility]].trainerClass;
}

void CopyFrontierBrainTrainerName(u8 *dst)
{
    s32 i;
    s32 facility;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        facility = GetRecordedBattleFrontierFacility();
    else
        facility = VarGet(VAR_FRONTIER_FACILITY);

    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        dst[i] = gTrainers[gFacilityToBrainTrainerId[facility]].trainerName[i];

    dst[i] = EOS;
}

bool8 IsFrontierBrainFemale(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    return sFacilityToBrainEventObjGfx[facility][1];
}

void SetFrontierBrainEventObjGfx_2(void)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    VarSet(VAR_OBJ_GFX_ID_0, sFacilityToBrainEventObjGfx[facility][0]);
}

#define FRONTIER_BRAIN_OTID 61226

#ifdef NONMATCHING
void CreateFrontierBrainPokemon(void)
{
    s32 i, j;
    s32 monCountInBits;
    s32 monPartyId;
    s32 monLevel = 0;
    u8 friendship;
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    if (facility == FRONTIER_FACILITY_DOME)
        monCountInBits = GetDomeTrainerMonCountInBits(TrainerIdToDomeTournamentId(TRAINER_FRONTIER_BRAIN));
    else
        monCountInBits = 7;

    ZeroEnemyPartyMons();
    monPartyId = 0;
    monLevel = SetFacilityPtrsGetLevel();
    for (i = 0; i < 3; monCountInBits >>= 1, i++)
    {
        if (!(monCountInBits & 1))
            continue;

        do
        {
            j = Random32();
        } while (IsShinyOtIdPersonality(FRONTIER_BRAIN_OTID, j) || sFrontierBrainsMons[facility][symbol][i].nature != GetNatureFromPersonality(j));
        CreateMon(&gEnemyParty[monPartyId],
                  sFrontierBrainsMons[facility][symbol][i].species,
                  monLevel,
                  sFrontierBrainsMons[facility][symbol][i].fixedIV,
                  TRUE, j,
                  OT_ID_PRESET, FRONTIER_BRAIN_OTID);
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_HELD_ITEM, &sFrontierBrainsMons[facility][symbol][i].heldItem);
        for (j = 0; j < NUM_STATS; j++)
            SetMonData(&gEnemyParty[monPartyId], MON_DATA_HP_EV + j, &sFrontierBrainsMons[facility][symbol][i].evs[j]);
        friendship = 0xFF;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            SetMonMoveSlot(&gEnemyParty[monPartyId], sFrontierBrainsMons[facility][symbol][i].moves[j], j);
            if (sFrontierBrainsMons[facility][symbol][i].moves[j] == MOVE_FRUSTRATION)
                friendship = 0;
        }
        SetMonData(&gEnemyParty[monPartyId], MON_DATA_FRIENDSHIP, &friendship);
        CalculateMonStats(&gEnemyParty[monPartyId]);
        monPartyId++;
    }
}
#else
NAKED
void CreateFrontierBrainPokemon(void)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x44\n\
    ldr r0, =0x000040cf\n\
    bl VarGet\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    str r0, [sp, 0x20]\n\
    bl GetFronterBrainSymbol\n\
    str r0, [sp, 0x24]\n\
    ldr r0, [sp, 0x20]\n\
    cmp r0, 0x1\n\
    bne _081A4E44\n\
    ldr r0, =0x000003fe\n\
    bl TrainerIdToDomeTournamentId\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    bl GetDomeTrainerMonCountInBits\n\
    adds r4, r0, 0\n\
    b _081A4E46\n\
    .pool\n\
_081A4E44:\n\
    movs r4, 0x7\n\
_081A4E46:\n\
    bl ZeroEnemyPartyMons\n\
    movs r1, 0\n\
    str r1, [sp, 0x18]\n\
    bl SetFacilityPtrsGetLevel\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    str r0, [sp, 0x1C]\n\
    movs r2, 0\n\
    str r2, [sp, 0x14]\n\
_081A4E5C:\n\
    movs r0, 0x1\n\
    ands r0, r4\n\
    asrs r4, 1\n\
    str r4, [sp, 0x30]\n\
    ldr r3, [sp, 0x14]\n\
    adds r3, 0x1\n\
    str r3, [sp, 0x28]\n\
    cmp r0, 0\n\
    bne _081A4E70\n\
    b _081A4FC4\n\
_081A4E70:\n\
    ldr r4, [sp, 0x14]\n\
    lsls r4, 2\n\
    mov r9, r4\n\
    ldr r0, [sp, 0x24]\n\
    lsls r0, 4\n\
    str r0, [sp, 0x38]\n\
    ldr r1, [sp, 0x20]\n\
    lsls r1, 4\n\
    str r1, [sp, 0x34]\n\
    ldr r2, [sp, 0x1C]\n\
    lsls r2, 24\n\
    str r2, [sp, 0x3C]\n\
    ldr r3, [sp, 0x18]\n\
    adds r3, 0x1\n\
    str r3, [sp, 0x2C]\n\
    ldr r0, [sp, 0x14]\n\
    add r0, r9\n\
    lsls r0, 2\n\
    mov r8, r0\n\
_081A4E96:\n\
    bl Random\n\
    adds r4, r0, 0\n\
    bl Random\n\
    lsls r4, 16\n\
    lsrs r7, r4, 16\n\
    lsls r0, 16\n\
    orrs r7, r0\n\
    ldr r0, =0x0000ef2a\n\
    adds r1, r7, 0\n\
    bl IsShinyOtIdPersonality\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bne _081A4E96\n\
    ldr r4, [sp, 0x38]\n\
    ldr r1, [sp, 0x24]\n\
    subs r0, r4, r1\n\
    lsls r5, r0, 2\n\
    mov r2, r8\n\
    adds r4, r2, r5\n\
    ldr r3, [sp, 0x34]\n\
    ldr r1, [sp, 0x20]\n\
    subs r0, r3, r1\n\
    lsls r6, r0, 3\n\
    adds r4, r6\n\
    ldr r2, =sFrontierBrainsMons\n\
    adds r4, r2\n\
    adds r0, r7, 0\n\
    bl GetNatureFromPersonality\n\
    ldrb r1, [r4, 0x5]\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r1, r0\n\
    bne _081A4E96\n\
    ldr r4, [sp, 0x18]\n\
    movs r0, 0x64\n\
    adds r3, r4, 0\n\
    muls r3, r0\n\
    mov r8, r3\n\
    ldr r1, =gEnemyParty\n\
    add r1, r8\n\
    mov r10, r1\n\
    ldr r4, [sp, 0x14]\n\
    add r4, r9\n\
    lsls r4, 2\n\
    adds r0, r4, r5\n\
    adds r0, r6\n\
    ldr r2, =sFrontierBrainsMons\n\
    adds r0, r2\n\
    ldrh r1, [r0]\n\
    ldr r3, [sp, 0x3C]\n\
    lsrs r2, r3, 24\n\
    ldrb r3, [r0, 0x4]\n\
    movs r0, 0x1\n\
    str r0, [sp]\n\
    str r7, [sp, 0x4]\n\
    str r0, [sp, 0x8]\n\
    ldr r0, =0x0000ef2a\n\
    str r0, [sp, 0xC]\n\
    mov r0, r10\n\
    bl CreateMon\n\
    ldr r0, =sFrontierBrainsMons\n\
    adds r5, r0\n\
    adds r5, r6, r5\n\
    adds r4, r5, r4\n\
    adds r4, 0x2\n\
    mov r0, r10\n\
    movs r1, 0xC\n\
    adds r2, r4, 0\n\
    bl SetMonData\n\
    movs r7, 0\n\
    mov r6, r8\n\
    ldr r3, =gEnemyParty\n\
_081A4F32:\n\
    adds r1, r7, 0\n\
    adds r1, 0x1A\n\
    ldr r0, [sp, 0x14]\n\
    add r0, r9\n\
    lsls r4, r0, 2\n\
    adds r2, r5, r4\n\
    adds r0, r7, 0x6\n\
    adds r2, r0\n\
    adds r0, r6, r3\n\
    str r3, [sp, 0x40]\n\
    bl SetMonData\n\
    adds r7, 0x1\n\
    ldr r3, [sp, 0x40]\n\
    cmp r7, 0x5\n\
    ble _081A4F32\n\
    movs r1, 0xFF\n\
    add r0, sp, 0x10\n\
    strb r1, [r0]\n\
    movs r7, 0\n\
    ldr r1, [sp, 0x18]\n\
    movs r2, 0x64\n\
    adds r6, r1, 0\n\
    muls r6, r2\n\
    ldr r3, =sFrontierBrainsMons + 0xC\n\
    mov r8, r3\n\
    ldr r3, =gEnemyParty\n\
    adds r5, r4, 0\n\
_081A4F6A:\n\
    ldr r4, [sp, 0x38]\n\
    ldr r0, [sp, 0x24]\n\
    subs r1, r4, r0\n\
    lsls r1, 2\n\
    adds r1, r5, r1\n\
    ldr r2, [sp, 0x34]\n\
    ldr r4, [sp, 0x20]\n\
    subs r0, r2, r4\n\
    lsls r0, 3\n\
    adds r1, r0\n\
    add r1, r8\n\
    ldrh r4, [r1]\n\
    lsls r2, r7, 24\n\
    lsrs r2, 24\n\
    adds r0, r6, r3\n\
    adds r1, r4, 0\n\
    str r3, [sp, 0x40]\n\
    bl SetMonMoveSlot\n\
    ldr r3, [sp, 0x40]\n\
    cmp r4, 0xDA\n\
    bne _081A4F9C\n\
    movs r1, 0\n\
    add r0, sp, 0x10\n\
    strb r1, [r0]\n\
_081A4F9C:\n\
    adds r5, 0x2\n\
    adds r7, 0x1\n\
    cmp r7, 0x3\n\
    ble _081A4F6A\n\
    ldr r0, [sp, 0x18]\n\
    movs r1, 0x64\n\
    adds r4, r0, 0\n\
    muls r4, r1\n\
    ldr r0, =gEnemyParty\n\
    adds r4, r0\n\
    adds r0, r4, 0\n\
    movs r1, 0x20\n\
    add r2, sp, 0x10\n\
    bl SetMonData\n\
    adds r0, r4, 0\n\
    bl CalculateMonStats\n\
    ldr r2, [sp, 0x2C]\n\
    str r2, [sp, 0x18]\n\
_081A4FC4:\n\
    ldr r4, [sp, 0x30]\n\
    ldr r3, [sp, 0x28]\n\
    str r3, [sp, 0x14]\n\
    cmp r3, 0x2\n\
    bgt _081A4FD0\n\
    b _081A4E5C\n\
_081A4FD0:\n\
    add sp, 0x44\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
");
}
#endif

u16 GetFrontierBrainMonSpecies(u8 monId)
{
    s32 facility = VarGet(VAR_FRONTIER_FACILITY);
    s32 symbol = GetFronterBrainSymbol();

    return sFrontierBrainsMons[facility][symbol][monId].species;
}

void SetFrontierBrainEventObjGfx(u8 facility)
{
    gTrainerBattleOpponent_A = TRAINER_FRONTIER_BRAIN;
    VarSet(VAR_OBJ_GFX_ID_0, sFacilityToBrainEventObjGfx[facility][0]);
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
        if (winStreak + gUnknown_08611550[facility][3] == gUnknown_08611550[facility][0])
            symbol = 0;
        else if (winStreak + gUnknown_08611550[facility][3] == gUnknown_08611550[facility][1])
            symbol = 1;
        else if (winStreak + gUnknown_08611550[facility][3] > gUnknown_08611550[facility][1]
                 && (winStreak + gUnknown_08611550[facility][3] - gUnknown_08611550[facility][1]) % gUnknown_08611550[facility][2] == 0)
            symbol = 1;
    }
    return symbol;
}

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
        StringCopy(gStringVar4, gUnknown_08611DB0[symbol][facility]);
        break;
    case TRUE:
        StringCopy(gStringVar4, gUnknown_08611DB8[symbol][facility]);
        break;
    }
}
