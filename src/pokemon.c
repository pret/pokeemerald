#include "global.h"
#include "malloc.h"
#include "apprentice.h"
#include "battle.h"
#include "battle_ai_util.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "caps.h"
#include "data.h"
#include "daycare.h"
#include "dexnav.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "evolution_scene.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "fishing.h"
#include "follower_npc.h"
#include "frontier_util.h"
#include "graphics.h"
#include "item.h"
#include "link.h"
#include "m4a.h"
#include "main.h"
#include "mail.h"
#include "move_relearner.h"
#include "naming_screen.h"
#include "overworld.h"
#include "ow_abilities.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "pokemon_animation.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "pokerus.h"
#include "random.h"
#include "random_mon_generation.h"
#include "recorded_battle.h"
#include "regions.h"
#include "rtc.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "test_runner.h"
#include "text.h"
#include "trainer.h"
#include "trainer_hill.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_partner.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_string_ids.h"
#include "constants/cries.h"
#include "constants/event_objects.h"
#include "constants/form_change_types.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/regions.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/union_room.h"
#include "constants/weather.h"

extern enum Item gSpecialVar_ItemId;

#define FRIENDSHIP_EVO_THRESHOLD ((P_FRIENDSHIP_EVO_THRESHOLD >= GEN_8) ? 160 : 220)

struct SpeciesItem
{
    enum Species species;
    enum Item item;
};

static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon);
static u16 CalculateBoxMonChecksumDecrypt(struct BoxPokemon *boxMon);
static u16 CalculateBoxMonChecksumReencrypt(struct BoxPokemon *boxMon);
static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, enum SubstructType substructType);
static void EncryptBoxMon(struct BoxPokemon *boxMon);
static void DecryptBoxMon(struct BoxPokemon *boxMon);
static void Task_PlayMapChosenOrBattleBGM(u8 taskId);
void TrySpecialOverworldEvo();

EWRAM_DATA static u8 sLearningMoveTableID = 0;
EWRAM_DATA u8 gPartiesCount[MAX_BATTLE_TRAINERS] = {0};
EWRAM_DATA struct Pokemon gParties[MAX_BATTLE_TRAINERS][PARTY_SIZE] = {0};
EWRAM_DATA struct SpriteTemplate gMultiuseSpriteTemplate = {0};
EWRAM_DATA static struct MonSpritesGfxManager *sMonSpritesGfxManagers[MON_SPR_GFX_MANAGERS_COUNT] = {NULL};
EWRAM_DATA u8 gTriedEvolving = 0;
EWRAM_DATA u16 gFollowerSteps = 0;

struct Pokemon (*const gPlayerPartyPtr)[6] = &gParties[B_TRAINER_PLAYER];
u8 (*const gPlayerPartyCountPtr) = &gPartiesCount[B_TRAINER_PLAYER];
struct Pokemon (*const gEnemyPartyPtr)[6] = &gParties[B_TRAINER_OPPONENT_A];
u8 (*const gEnemyPartyCountPtr) = &gPartiesCount[B_TRAINER_OPPONENT_A];

#include "data/abilities.h"

// Used in an unreferenced function in RS.
// Unreferenced here and in FRLG.
struct CombinedMove
{
    enum Move move1;
    enum Move move2;
    enum Move newMove;
};

static const struct CombinedMove sCombinedMoves[2] =
{
    {MOVE_EMBER, MOVE_GUST, MOVE_HEAT_WAVE},
    {0xFFFF, 0xFFFF, 0xFFFF}
};

// NOTE: The order of the elements in the array below is irrelevant.
// To reorder the pokedex, see the values in include/constants/pokedex.h.

#define KANTO_TO_NATIONAL(name)     [KANTO_DEX_##name - 1] = NATIONAL_DEX_##name,
#define HOENN_TO_NATIONAL(name)     [HOENN_DEX_##name - 1] = NATIONAL_DEX_##name,

static const enum NationalDexOrder sKantoToNationalOrder[KANTO_DEX_COUNT] =
{
    FOREACH_SPECIES_IN_KANTO_DEX_ORDER(KANTO_TO_NATIONAL)
};


// Assigns all Hoenn Dex Indexes to a National Dex Index
static const enum NationalDexOrder sHoennToNationalOrder[HOENN_DEX_COUNT - 1] =
{
    FOREACH_SPECIES_IN_HOENN_DEX_ORDER(HOENN_TO_NATIONAL)
};

// In Battle Palace, moves are chosen based on the Pokémon's nature rather than by the player
// Moves are grouped into "Attack", "Defense", or "Support" (see PALACE_MOVE_GROUP_*)
// Each nature has a certain percent chance of selecting a move from a particular group
// and a separate percent chance for each group when at or below 50% HP
// The table below doesn't list percentages for Support because you can subtract the other two
// Support percentages are listed in comments off to the side instead
#define PALACE_STYLE(atk, def, atkLow, defLow) {atk, atk + def, atkLow, atkLow + defLow}

const struct NatureInfo gNaturesInfo[NUM_NATURES] =
{
    [NATURE_HARDY] =
    {
        .name = COMPOUND_STRING("Hardy"),
        .statUp = STAT_ATK,
        .statDown = STAT_ATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_HARDY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(61, 7, 61, 7), //32% support >= 50% HP, 32% support < 50% HP
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_LONELY] =
    {
        .name = COMPOUND_STRING("Lonely"),
        .statUp = STAT_ATK,
        .statDown = STAT_DEF,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_LONELY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(20, 25, 84, 8), //55%,  8%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_BRAVE] =
    {
        .name = COMPOUND_STRING("Brave"),
        .statUp = STAT_ATK,
        .statDown = STAT_SPEED,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_BRAVE, AFFINE_TURN_UP},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow,
        .battlePalacePercents = PALACE_STYLE(70, 15, 32, 60), //15%, 8%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_ADAMANT] =
    {
        .name = COMPOUND_STRING("Adamant"),
        .statUp = STAT_ATK,
        .statDown = STAT_SPATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_ADAMANT, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(38, 31, 70, 15), //31%, 15%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_NAUGHTY] =
    {
        .name = COMPOUND_STRING("Naughty"),
        .statUp = STAT_ATK,
        .statDown = STAT_SPDEF,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_NAUGHTY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(20, 70, 70, 22), //10%, 8%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_BOLD] =
    {
        .name = COMPOUND_STRING("Bold"),
        .statUp = STAT_DEF,
        .statDown = STAT_ATK,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_BOLD, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow,
        .battlePalacePercents = PALACE_STYLE(30, 20, 32, 58), //50%, 10%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_DOCILE] =
    {
        .name = COMPOUND_STRING("Docile"),
        .statUp = STAT_DEF,
        .statDown = STAT_DEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_DOCILE, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_RANDOM,
    },
    [NATURE_RELAXED] =
    {
        .name = COMPOUND_STRING("Relaxed"),
        .statUp = STAT_DEF,
        .statDown = STAT_SPEED,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_RELAXED, AFFINE_TURN_UP_AND_DOWN},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(25, 15, 75, 15), //60%, 10%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_IMPISH] =
    {
        .name = COMPOUND_STRING("Impish"),
        .statUp = STAT_DEF,
        .statDown = STAT_SPATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_IMPISH, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow,
        .battlePalacePercents = PALACE_STYLE(69, 6, 28, 55), //25%, 17%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_LAX] =
    {
        .name = COMPOUND_STRING("Lax"),
        .statUp = STAT_DEF,
        .statDown = STAT_SPDEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_LAX, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow,
        .battlePalacePercents = PALACE_STYLE(35, 10, 29, 6), //55%, 65%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_TIMID] =
    {
        .name = COMPOUND_STRING("Timid"),
        .statUp = STAT_SPEED,
        .statDown = STAT_ATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_TIMID, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow,
        .battlePalacePercents = PALACE_STYLE(62, 10, 30, 20), //28%, 50%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_HASTY] =
    {
        .name = COMPOUND_STRING("Hasty"),
        .statUp = STAT_SPEED,
        .statDown = STAT_DEF,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_HASTY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(58, 37, 88, 6), //5%, 6%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_SERIOUS] =
    {
        .name = COMPOUND_STRING("Serious"),
        .statUp = STAT_SPEED,
        .statDown = STAT_SPEED,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_SERIOUS, AFFINE_TURN_DOWN},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow,
        .battlePalacePercents = PALACE_STYLE(34, 11, 29, 11), //55%, 60%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_JOLLY] =
    {
        .name = COMPOUND_STRING("Jolly"),
        .statUp = STAT_SPEED,
        .statDown = STAT_SPATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_JOLLY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow,
        .battlePalacePercents = PALACE_STYLE(35, 5, 35, 60), //60%, 5%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_NAIVE] =
    {
        .name = COMPOUND_STRING("Naive"),
        .statUp = STAT_SPEED,
        .statDown = STAT_SPDEF,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_NAIVE, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_RANDOM,
    },
    [NATURE_MODEST] =
    {
        .name = COMPOUND_STRING("Modest"),
        .statUp = STAT_SPATK,
        .statDown = STAT_ATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_MODEST, AFFINE_TURN_DOWN_SLOW},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow,
        .battlePalacePercents = PALACE_STYLE(35, 45, 34, 60), //20%, 6%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_MILD] =
    {
        .name = COMPOUND_STRING("Mild"),
        .statUp = STAT_SPATK,
        .statDown = STAT_DEF,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_MILD, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow,
        .battlePalacePercents = PALACE_STYLE(44, 50, 34, 6), //6%, 60%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_QUIET] =
    {
        .name = COMPOUND_STRING("Quiet"),
        .statUp = STAT_SPATK,
        .statDown = STAT_SPEED,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_QUIET, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_BASHFUL] =
    {
        .name = COMPOUND_STRING("Bashful"),
        .statUp = STAT_SPATK,
        .statDown = STAT_SPATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_BASHFUL, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow,
        .battlePalacePercents = PALACE_STYLE(30, 58, 30, 58), //12%, 12%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_RASH] =
    {
        .name = COMPOUND_STRING("Rash"),
        .statUp = STAT_SPATK,
        .statDown = STAT_SPDEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_RASH, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow,
        .battlePalacePercents = PALACE_STYLE(30, 13, 27, 6), //57%, 67%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_CALM] =
    {
        .name = COMPOUND_STRING("Calm"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_ATK,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_CALM, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow,
        .battlePalacePercents = PALACE_STYLE(40, 50, 25, 62), //10%, 13%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_GENTLE] =
    {
        .name = COMPOUND_STRING("Gentle"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_DEF,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_GENTLE, AFFINE_TURN_DOWN_SLIGHT},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(18, 70, 90, 5), //12%, 5%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_SASSY] =
    {
        .name = COMPOUND_STRING("Sassy"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_SPEED,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_SASSY, AFFINE_TURN_UP_HIGH},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow,
        .battlePalacePercents = PALACE_STYLE(88, 6, 22, 20), //6%, 58%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_CAREFUL] =
    {
        .name = COMPOUND_STRING("Careful"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_SPATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_CAREFUL, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow,
        .battlePalacePercents = PALACE_STYLE(42, 50, 42, 5), //8%, 53%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_QUIRKY] =
    {
        .name = COMPOUND_STRING("Quirky"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_SPDEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_QUIRKY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
};

#include "data/graphics/pokemon.h"

#include "data/pokemon/trainer_class_lookups.h"
#include "data/pokemon/experience_tables.h"

#if P_LVL_UP_LEARNSETS >= GEN_9
#include "data/pokemon/level_up_learnsets/gen_9.h" // Scarlet/Violet
#elif P_LVL_UP_LEARNSETS >= GEN_8
#include "data/pokemon/level_up_learnsets/gen_8.h" // Sword/Shield
#elif P_LVL_UP_LEARNSETS >= GEN_7
#include "data/pokemon/level_up_learnsets/gen_7.h" // Ultra Sun/Ultra Moon
#elif P_LVL_UP_LEARNSETS >= GEN_6
#include "data/pokemon/level_up_learnsets/gen_6.h" // Omega Ruby/Alpha Sapphire
#elif P_LVL_UP_LEARNSETS >= GEN_5
#include "data/pokemon/level_up_learnsets/gen_5.h" // Black 2/White 2
#elif P_LVL_UP_LEARNSETS >= GEN_4
#include "data/pokemon/level_up_learnsets/gen_4.h" // HeartGold/SoulSilver
#elif P_LVL_UP_LEARNSETS >= GEN_3
#include "data/pokemon/level_up_learnsets/gen_3.h" // Ruby/Sapphire/Emerald
#elif P_LVL_UP_LEARNSETS >= GEN_2
#include "data/pokemon/level_up_learnsets/gen_2.h" // Crystal
#elif P_LVL_UP_LEARNSETS >= GEN_1
#include "data/pokemon/level_up_learnsets/gen_1.h" // Yellow
#endif

#include "data/pokemon/teachable_learnsets.h"
#include "data/pokemon/egg_moves.h"
#include "data/pokemon/form_species_tables.h"
#include "data/pokemon/form_change_tables.h"
#include "data/pokemon/form_change_table_pointers.h"
#include "data/pokemon/wild_encounter_ow_behavior.h"
#include "data/object_events/object_event_pic_tables_followers.h"

#include "data/pokemon/species_info.h"

#define PP_UP_SHIFTS(val)           val,        (val) << 2,        (val) << 4,        (val) << 6
#define PP_UP_SHIFTS_INV(val) (u8)~(val), (u8)~((val) << 2), (u8)~((val) << 4), (u8)~((val) << 6)

// PP Up bonuses are stored for a Pokémon as a single byte.
// There are 2 bits (a value 0-3) for each move slot that
// represent how many PP Ups have been applied.
// The following arrays take a move slot id and return:
// gPPUpGetMask - A mask to get the number of PP Ups applied to that move slot
// gPPUpClearMask - A mask to clear the number of PP Ups applied to that move slot
// gPPUpAddValues - A value to add to the PP Bonuses byte to apply 1 PP Up to that move slot
const u8 gPPUpGetMask[MAX_MON_MOVES]   = {PP_UP_SHIFTS(3)};
const u8 gPPUpClearMask[MAX_MON_MOVES] = {PP_UP_SHIFTS_INV(3)};
const u8 gPPUpAddValues[MAX_MON_MOVES] = {PP_UP_SHIFTS(1)};

const u8 gStatStageRatios[MAX_STAT_STAGE + 1][2] =
{
    {10, 40}, // -6, MIN_STAT_STAGE
    {10, 35}, // -5
    {10, 30}, // -4
    {10, 25}, // -3
    {10, 20}, // -2
    {10, 15}, // -1
    {10, 10}, //  0, DEFAULT_STAT_STAGE
    {15, 10}, // +1
    {20, 10}, // +2
    {25, 10}, // +3
    {30, 10}, // +4
    {35, 10}, // +5
    {40, 10}, // +6, MAX_STAT_STAGE
};

// The classes used by other players in the Union Room.
// These should correspond with the overworld graphics in sUnionRoomObjGfxIds
const u16 gUnionRoomFacilityClasses[NUM_UNION_ROOM_CLASSES * GENDER_COUNT] =
{
    // Male classes
    FACILITY_CLASS_COOLTRAINER_M,
    FACILITY_CLASS_BLACK_BELT,
    FACILITY_CLASS_CAMPER,
    FACILITY_CLASS_YOUNGSTER,
    FACILITY_CLASS_PSYCHIC_M,
    FACILITY_CLASS_BUG_CATCHER,
    FACILITY_CLASS_PKMN_BREEDER_M,
    FACILITY_CLASS_GUITARIST,
    // Female classes
    FACILITY_CLASS_COOLTRAINER_F,
    FACILITY_CLASS_HEX_MANIAC,
    FACILITY_CLASS_PICNICKER,
    FACILITY_CLASS_LASS,
    FACILITY_CLASS_PSYCHIC_F,
    FACILITY_CLASS_BATTLE_GIRL,
    FACILITY_CLASS_PKMN_BREEDER_F,
    FACILITY_CLASS_BEAUTY
};

const struct SpriteTemplate gBattlerSpriteTemplates[MAX_BATTLERS_COUNT] =
{
    [B_POSITION_PLAYER_LEFT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gBattlerPicTable_PlayerLeft,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [B_POSITION_OPPONENT_LEFT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpriteOpponentSide,
        .anims = NULL,
        .images = gBattlerPicTable_OpponentLeft,
        .affineAnims = gAffineAnims_BattleSpriteOpponentSide,
        .callback = SpriteCB_WildMon,
    },
    [B_POSITION_PLAYER_RIGHT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gBattlerPicTable_PlayerRight,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [B_POSITION_OPPONENT_RIGHT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpriteOpponentSide,
        .anims = NULL,
        .images = gBattlerPicTable_OpponentRight,
        .affineAnims = gAffineAnims_BattleSpriteOpponentSide,
        .callback = SpriteCB_WildMon
    },
};

static const struct SpriteTemplate sTrainerBackSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = 0,
    .oam = &gOamData_BattleSpritePlayerSide,
    .anims = NULL,
    .affineAnims = gAffineAnims_BattleSpritePlayerSide,
    .callback = SpriteCB_BattleSpriteStartSlideLeft,
};

#define NUM_SECRET_BASE_CLASSES 5
static const u8 sSecretBaseFacilityClasses[GENDER_COUNT][NUM_SECRET_BASE_CLASSES] =
{
    [MALE] = {
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_BUG_CATCHER,
        FACILITY_CLASS_RICH_BOY,
        FACILITY_CLASS_CAMPER,
        FACILITY_CLASS_COOLTRAINER_M
    },
    [FEMALE] = {
        FACILITY_CLASS_LASS,
        FACILITY_CLASS_SCHOOL_KID_F,
        FACILITY_CLASS_LADY,
        FACILITY_CLASS_PICNICKER,
        FACILITY_CLASS_COOLTRAINER_F
    }
};

static const u8 sGetMonDataEVConstants[] =
{
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_SPATK_EV
};

// For stat-raising items
static const enum Stat sStatsToRaise[] =
{
    STAT_ATK, STAT_ATK, STAT_DEF, STAT_SPEED, STAT_SPATK, STAT_SPDEF, STAT_ACC
};

// 3 modifiers each for how much to change friendship for different ranges
// 0-99, 100-199, 200+
static const s8 sFriendshipEventModifiers[][3] =
{
    [FRIENDSHIP_EVENT_GROW_LEVEL]      = { 5,  3,  2},
    [FRIENDSHIP_EVENT_VITAMIN]         = { 5,  3,  2},
    [FRIENDSHIP_EVENT_BATTLE_ITEM]     = { 1,  1,  0},
    [FRIENDSHIP_EVENT_LEAGUE_BATTLE]   = { 3,  2,  1},
    [FRIENDSHIP_EVENT_LEARN_TMHM]      = { 1,  1,  0},
    [FRIENDSHIP_EVENT_WALKING]         = { 1,  1,  1},
    [FRIENDSHIP_EVENT_FAINT_SMALL]     = {-1, -1, -1},
    [FRIENDSHIP_EVENT_FAINT_FIELD_PSN] = {-5, -5, -10},
    [FRIENDSHIP_EVENT_FAINT_LARGE]     = {-5, -5, -10},
    [FRIENDSHIP_EVENT_MASSAGE]         = { 3,  3,  3 },
};

static const struct SpeciesItem sAlteringCaveWildMonHeldItems[] =
{
    {SPECIES_NONE,      ITEM_NONE},
    {SPECIES_MAREEP,    ITEM_GANLON_BERRY},
    {SPECIES_PINECO,    ITEM_APICOT_BERRY},
    {SPECIES_HOUNDOUR,  ITEM_BIG_MUSHROOM},
    {SPECIES_TEDDIURSA, ITEM_PETAYA_BERRY},
    {SPECIES_AIPOM,     ITEM_BERRY_JUICE},
    {SPECIES_SHUCKLE,   ITEM_BERRY_JUICE},
    {SPECIES_STANTLER,  ITEM_PETAYA_BERRY},
    {SPECIES_SMEARGLE,  ITEM_SALAC_BERRY},
};

static const struct OamData sOamData_64x64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct SpriteTemplate sSpriteTemplate_64x64 =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_64x64,
};

// NOTE: Reordering this array will break compatibility with existing
// saves.
static const u32 sCompressedStatuses[] =
{
    STATUS1_NONE,
    STATUS1_SLEEP_TURN(1),
    STATUS1_SLEEP_TURN(2),
    STATUS1_SLEEP_TURN(3),
    STATUS1_SLEEP_TURN(4),
    STATUS1_SLEEP_TURN(5),
    STATUS1_POISON,
    STATUS1_BURN,
    STATUS1_FREEZE,
    STATUS1_PARALYSIS,
    STATUS1_TOXIC_POISON,
    STATUS1_FROSTBITE,
};

// Attempt to detect situations where the BoxPokemon struct is unable to
// contain all the values.
// TODO: Is it possible to compute:
// - The maximum experience.
// - The maximum PP.
// - The maximum HP.
// - The maximum form countdown.

// The following definition of sBoxPokemonConstantsFit and STATIC_ASSERTS
// will prevent developers from compiling the game if the value of the
// constant on the left does not fit within the number of bits defined
// in BoxPokemon or its substructs (currently located in include/pokemon.h).

// To successfully compile, developers will need to do one of the following:
// 1) Decrease the size of the constant.
// 2) Increase the number of bits both on the struct AND in the corresponding assert. This will likely break user's saves unless there is free space after the member that is being adjsted.
// 3) Repurpose unused IDs.

// EXAMPLES
// If a developer has added enough new items so that ITEMS_COUNT now equals 1200, they could...
// 1) remove new items until ITEMS_COUNT is 1023, the max value that will fit in 10 bits.
// 2) change heldItem:10 to heldItem:11 AND change the below assert for ITEMS_COUNT to check for (1 << 11).
// 3) repurpose IDs from other items that aren't being used, like ITEM_GOLD_TEETH or ITEM_SS_TICKET until ITEMS_COUNT equals 1023, the max value that will fit in 10 bits.

UNUSED static const struct BoxPokemon sBoxPokemonConstantsFit =
{
    .language = NUM_LANGUAGES - 1,
    .hiddenNatureModifier = NUM_NATURES - 1,
    .compressedStatus = ARRAY_COUNT(sCompressedStatuses) - 1,
    .secure.substructs[0].type0 = {
        .species = NUM_SPECIES - 1,
        .teraType = NUMBER_OF_MON_TYPES - 1,
        .heldItem = ITEMS_COUNT - 1,
        .pokeball = POKEBALL_COUNT - 1,
    },
    .secure.substructs[1].type1 = {
        .move1 = MOVES_COUNT_ALL - 1,
        .move2 = MOVES_COUNT_ALL - 1,
        .move3 = MOVES_COUNT_ALL - 1,
        .move4 = MOVES_COUNT_ALL - 1,
    },
    .secure.substructs[2].type2 = {
        .hpEV = MAX_PER_STAT_EVS,
        .attackEV = MAX_PER_STAT_EVS,
        .defenseEV = MAX_PER_STAT_EVS,
        .speedEV = MAX_PER_STAT_EVS,
        .spAttackEV = MAX_PER_STAT_EVS,
        .spDefenseEV = MAX_PER_STAT_EVS,
    },
    .secure.substructs[3].type3 = {
        .metLocation = min(MAPSEC_COUNT, min(METLOC_SPECIAL_EGG, min(METLOC_IN_GAME_TRADE, METLOC_FATEFUL_ENCOUNTER))),
        .metLevel = MAX_LEVEL,
        .metGame = NUM_VERSIONS, // NOTE: NUM_VERSIONS is inclusive!
        .dynamaxLevel = MAX_DYNAMAX_LEVEL,
        .otGender = GENDER_COUNT - 1,
        .hpIV = MAX_PER_STAT_IVS,
        .attackIV = MAX_PER_STAT_IVS,
        .defenseIV = MAX_PER_STAT_IVS,
        .speedIV = MAX_PER_STAT_IVS,
        .spAttackIV = MAX_PER_STAT_IVS,
        .spDefenseIV = MAX_PER_STAT_IVS,
        .abilityNum = NUM_ABILITY_SLOTS - 1,
    },
};

STATIC_ASSERT(MAX_LEVEL <= 100, PokemonSubstruct0_experience_PotentiallyTooSmall); // Maximum of ~2 million exp.

static u32 CompressStatus(u32 status)
{
    s32 i;
    for (i = 0; i < ARRAY_COUNT(sCompressedStatuses); i++)
    {
        if (sCompressedStatuses[i] == status)
            return i;
    }
    return 0; // STATUS1_NONE
}

static u32 UncompressStatus(u32 compressedStatus)
{
    if (compressedStatus < ARRAY_COUNT(sCompressedStatuses))
        return sCompressedStatuses[compressedStatus];
    else
        return STATUS1_NONE;
}

void ZeroBoxMonData(struct BoxPokemon *boxMon)
{
    u8 *raw = (u8 *)boxMon;
    u32 i;
    for (i = 0; i < sizeof(struct BoxPokemon); i++)
        raw[i] = 0;
}

void ZeroMonData(struct Pokemon *mon)
{
    u32 arg;
    ZeroBoxMonData(&mon->box);
    arg = 0;
    SetMonData(mon, MON_DATA_STATUS, &arg);
    SetMonData(mon, MON_DATA_LEVEL, &arg);
    SetMonData(mon, MON_DATA_HP, &arg);
    SetMonData(mon, MON_DATA_MAX_HP, &arg);
    SetMonData(mon, MON_DATA_ATK, &arg);
    SetMonData(mon, MON_DATA_DEF, &arg);
    SetMonData(mon, MON_DATA_SPEED, &arg);
    SetMonData(mon, MON_DATA_SPATK, &arg);
    SetMonData(mon, MON_DATA_SPDEF, &arg);
    arg = MAIL_NONE;
    SetMonData(mon, MON_DATA_MAIL, &arg);
}

void ZeroPartyMons(struct Pokemon *party)
{
    for (s32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&party[i]);
}

void ZeroPlayerPartyMons(void)
{
    for (s32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    gPartiesCount[B_TRAINER_PLAYER] = 0;
}

void ZeroEnemyPartyMons(void)
{
    for (s32 i = 0; i < PARTY_SIZE; i++)
    {
        ZeroMonData(&gParties[B_TRAINER_OPPONENT_A][i]);
        ZeroMonData(&gParties[B_TRAINER_OPPONENT_B][i]);
    }
    gPartiesCount[B_TRAINER_OPPONENT_A] = 0;
    gPartiesCount[B_TRAINER_OPPONENT_B] = 0;
}

void CreateRandomMon(struct Pokemon *mon, enum Species species, u8 level)
{
    CreateRandomMonWithIVs(mon, species, level, USE_RANDOM_IVS);
}

void CreateRandomMonWithIVs(struct Pokemon *mon, enum Species species, u8 level, u8 fixedIv)
{
    CreateMonWithIVs(mon, species, level, Random32(), OTID_STRUCT_PLAYER_ID, fixedIv);
    GiveMonInitialMoveset(mon);
}

void CreateMon(struct Pokemon *mon, enum Species species, u8 level, u32 personality, struct OriginalTrainerId trainerId)
{
    u32 mail;
    ZeroMonData(mon);
    CreateBoxMon(&mon->box, species, level, personality, trainerId);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    mail = MAIL_NONE;
    SetMonData(mon, MON_DATA_MAIL, &mail);
}

void CreateMonWithIVs(struct Pokemon *mon, enum Species species, u8 level, u32 personality, struct OriginalTrainerId trainerId, u8 fixedIV)
{
    CreateMon(mon, species, level, personality, trainerId);
    SetBoxMonIVs(&mon->box, fixedIV);
    CalculateMonStats(mon);
}

bool32 ComputePlayerShinyOdds(u32 personality, u32 value)
{
    if (FlagGet(P_FLAG_FORCE_NO_SHINY))
        return FALSE;

    if (FlagGet(P_FLAG_FORCE_SHINY))
        return TRUE;

    if (P_ONLY_OBTAINABLE_SHINIES && (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || (FlagGet(WE_FLAG_NO_CATCHING))))
        return FALSE;

    if (P_NO_SHINIES_WITHOUT_POKEBALLS && !HasAtLeastOnePokeBall() && FlagGet(FLAG_SYS_POKEDEX_GET))
        return FALSE;

    u32 totalRerolls = 0;

    if (CheckBagHasItem(ITEM_SHINY_CHARM, 1))
        totalRerolls += I_SHINY_CHARM_ADDITIONAL_ROLLS;

    if (LURE_STEP_COUNT != 0)
        totalRerolls += 1;

    totalRerolls += CalculateChainFishingShinyRolls();

    if (gDexNavSpecies)
        totalRerolls += CalculateDexNavShinyRolls();

    while (GET_SHINY_VALUE(value, personality) >= SHINY_ODDS && totalRerolls > 0)
    {
        personality = Random32();
        totalRerolls--;
    }

    return GET_SHINY_VALUE(value, personality) < SHINY_ODDS;
}

void SetBoxMonIVs(struct BoxPokemon *mon, u8 fixedIV)
{
    u32 i, value;

    if (fixedIV < USE_RANDOM_IVS)
    {
        for (i = 0; i < NUM_STATS; i++)
            SetBoxMonData(mon, MON_DATA_HP_IV + i, &fixedIV);
        return;
    }

    u32 iv;
    u32 ivRandom = Random32();
    enum Species species = GetBoxMonData(mon, MON_DATA_SPECIES);
    value = (u16)ivRandom;

    iv = value & MAX_IV_MASK;
    SetBoxMonData(mon, MON_DATA_HP_IV, &iv);
    iv = (value & (MAX_IV_MASK << 5)) >> 5;
    SetBoxMonData(mon, MON_DATA_ATK_IV, &iv);
    iv = (value & (MAX_IV_MASK << 10)) >> 10;
    SetBoxMonData(mon, MON_DATA_DEF_IV, &iv);

    value = (u16)(ivRandom >> 16);

    iv = value & MAX_IV_MASK;
    SetBoxMonData(mon, MON_DATA_SPEED_IV, &iv);
    iv = (value & (MAX_IV_MASK << 5)) >> 5;
    SetBoxMonData(mon, MON_DATA_SPATK_IV, &iv);
    iv = (value & (MAX_IV_MASK << 10)) >> 10;
    SetBoxMonData(mon, MON_DATA_SPDEF_IV, &iv);

    SetBoxMonPerfectIVs(mon, gSpeciesInfo[species].perfectIVCount);
}

void SetBoxMonPerfectIVs(struct BoxPokemon *mon, u32 numPerfect)
{
    if (!numPerfect)
        return;

    u32 i, iv = MAX_PER_STAT_IVS;
    if (numPerfect >= NUM_STATS)
    {
        for (i = 0; i < NUM_STATS; i++)
            SetBoxMonData(mon, MON_DATA_HP_IV + i, &iv);
        return;
    }

    enum Stat availableIVs[NUM_STATS];
    enum Stat selectedIvs[NUM_STATS];
    // Initialize a list of IV indices.
    for (i = 0; i < NUM_STATS; i++)
        availableIVs[i] = i;

    // Select the IVs that will be perfected.
    for (i = 0; i < numPerfect; i++)
    {
        u8 index = Random() % (NUM_STATS - i);
        selectedIvs[i] = availableIVs[index];
        RemoveIVIndexFromList(availableIVs, index);
        SetBoxMonData(mon, MON_DATA_HP_IV + selectedIvs[i], &iv);
    }
}

void CreateBoxMon(struct BoxPokemon *boxMon, enum Species species, u8 level, u32 personality, struct OriginalTrainerId trainerId)
{
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    u32 value;
    u16 checksum;
    bool32 isShiny;

    ZeroBoxMonData(boxMon);
    // Determine original trainer ID
    if (trainerId.method == OT_ID_RANDOM_NO_SHINY)
    {
        value = Random32();
        isShiny = FALSE;
    }
    else if (trainerId.method == OT_ID_PRESET)
    {
        value = trainerId.value;
        isShiny = GET_SHINY_VALUE(value, personality) < SHINY_ODDS;
    }
    else // Player is the OT
    {
        value = READ_OTID_FROM_SAVE;
        isShiny = ComputePlayerShinyOdds(personality, value);
    }

    SetBoxMonData(boxMon, MON_DATA_PERSONALITY, &personality);
    SetBoxMonData(boxMon, MON_DATA_OT_ID, &value);

    checksum = CalculateBoxMonChecksum(boxMon);
    SetBoxMonData(boxMon, MON_DATA_CHECKSUM, &checksum);
    EncryptBoxMon(boxMon);
    SetBoxMonData(boxMon, MON_DATA_IS_SHINY, &isShiny);
    StringCopy(speciesName, GetSpeciesName(species));
    SetBoxMonData(boxMon, MON_DATA_NICKNAME, speciesName);
    SetBoxMonData(boxMon, MON_DATA_LANGUAGE, &gGameLanguage);
    SetBoxMonData(boxMon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetBoxMonData(boxMon, MON_DATA_SPECIES, &species);
    SetBoxMonData(boxMon, MON_DATA_EXP, &gExperienceTables[gSpeciesInfo[species].growthRate][level]);
    SetBoxMonData(boxMon, MON_DATA_FRIENDSHIP, &gSpeciesInfo[species].friendship);
    value = GetCurrentRegionMapSectionId();
    SetBoxMonData(boxMon, MON_DATA_MET_LOCATION, &value);
    SetBoxMonData(boxMon, MON_DATA_MET_LEVEL, &level);
    SetBoxMonData(boxMon, MON_DATA_MET_GAME, &gGameVersion);
    value = BALL_POKE;
    SetBoxMonData(boxMon, MON_DATA_POKEBALL, &value);
    SetBoxMonData(boxMon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);

    value = boxMon->personality & 0x1;
    enum Type teraType = value == 0 ? GetSpeciesType(species, 0) : GetSpeciesType(species, 1);
    SetBoxMonData(boxMon, MON_DATA_TERA_TYPE, &teraType);
    //using gen 3-4 ability formula, it was changed in later gens
    if (GetSpeciesAbility(species, 1))
        SetBoxMonData(boxMon, MON_DATA_ABILITY_NUM, &value);
}

static bool32 IsValidGender(u32 gender)
{
    switch (gender)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
    case MON_GENDER_RANDOM:
        return TRUE;
    default:
        return FALSE;
    }
}

static void CleanIncompatibleGenderSpecies(enum Species species, u8 *gender)
{
    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        *gender = MON_GENDER_RANDOM;
        return;
    }
    if (*gender == MON_GENDERLESS)
        *gender = MON_GENDER_RANDOM;
}

u32 GetMonPersonality(enum Species species, u8 gender, u8 nature, u8 unownLetter)
{
    u32 personality, actualLetter;

    assertf(IsValidGender(gender), "invalid gender: %d", gender)
    {
        gender = MON_GENDER_RANDOM;
    }

    assertf(nature <= NATURE_RANDOM, "invalid nature: %d", nature)
    {
        nature = NATURE_RANDOM;
    }

    assertf(unownLetter <= NUM_UNOWN_FORMS, "invalid letter: %d", unownLetter)
    {
        unownLetter = RANDOM_UNOWN_LETTER;
    }

    CleanIncompatibleGenderSpecies(species, &gender);
    do
    {
        personality = Random32();
        actualLetter = GET_UNOWN_LETTER(personality);
    }
    while ((nature != GetNatureFromPersonality(personality) && nature != NATURE_RANDOM)
            || (gender != MON_GENDER_RANDOM && gender != GetGenderFromSpeciesAndPersonality(species, personality))
            || ((actualLetter != unownLetter - 1) && unownLetter > 0));
    return personality;
}

// This is only used to create Wally's Ralts.
void CreateMaleMon(struct Pokemon *mon, enum Species species, u8 level)
{
    u32 personality = GetMonPersonality(species, MON_MALE, NATURE_RANDOM, RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(mon, species, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(mon);
}

void CreateMonWithIVsPersonality(struct Pokemon *mon, enum Species species, u8 level, u32 ivs, u32 personality)
{
    CreateMon(mon, species, level, personality, OTID_STRUCT_PLAYER_ID);
    SetMonData(mon, MON_DATA_IVS, &ivs);
    CalculateMonStats(mon);
    GiveMonInitialMoveset(mon);
}

void CreateBattleTowerMon(struct Pokemon *mon, struct BattleTowerPokemon *src)
{
    s32 i;
    u8 nickname[max(32, POKEMON_NAME_BUFFER_SIZE)];
    enum Language language;
    u8 value;

    CreateMon(mon, src->species, src->level, src->personality, OTID_STRUCT_PRESET(src->otId));

    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, src->moves[i], i);

    SetMonData(mon, MON_DATA_PP_BONUSES, &src->ppBonuses);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->heldItem);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &src->friendship);

    StringCopy(nickname, src->nickname);

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
    {
        language = LANGUAGE_JAPANESE;
        StripExtCtrlCodes(nickname);
    }
    else
    {
        language = GAME_LANGUAGE;
    }

    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_NICKNAME, nickname);
    SetMonData(mon, MON_DATA_HP_EV, &src->hpEV);
    SetMonData(mon, MON_DATA_ATK_EV, &src->attackEV);
    SetMonData(mon, MON_DATA_DEF_EV, &src->defenseEV);
    SetMonData(mon, MON_DATA_SPEED_EV, &src->speedEV);
    SetMonData(mon, MON_DATA_SPATK_EV, &src->spAttackEV);
    SetMonData(mon, MON_DATA_SPDEF_EV, &src->spDefenseEV);
    value = src->abilityNum;
    SetMonData(mon, MON_DATA_ABILITY_NUM, &value);
    value = src->hpIV;
    SetMonData(mon, MON_DATA_HP_IV, &value);
    value = src->attackIV;
    SetMonData(mon, MON_DATA_ATK_IV, &value);
    value = src->defenseIV;
    SetMonData(mon, MON_DATA_DEF_IV, &value);
    value = src->speedIV;
    SetMonData(mon, MON_DATA_SPEED_IV, &value);
    value = src->spAttackIV;
    SetMonData(mon, MON_DATA_SPATK_IV, &value);
    value = src->spDefenseIV;
    SetMonData(mon, MON_DATA_SPDEF_IV, &value);
    MonRestorePP(mon);
    CalculateMonStats(mon);
}

void CreateBattleTowerMon_HandleLevel(struct Pokemon *mon, struct BattleTowerPokemon *src, bool8 lvl50)
{
    s32 i;
    u8 nickname[max(32, POKEMON_NAME_BUFFER_SIZE)];
    u8 level;
    enum Language language;
    u8 value;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
        level = GetFrontierEnemyMonLevel(gSaveBlock2Ptr->frontier.lvlMode);
    else if (lvl50)
        level = FRONTIER_MAX_LEVEL_50;
    else
        level = src->level;

    CreateMon(mon, src->species, level, src->personality, OTID_STRUCT_PRESET(src->otId));

    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, src->moves[i], i);

    SetMonData(mon, MON_DATA_PP_BONUSES, &src->ppBonuses);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->heldItem);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &src->friendship);

    StringCopy(nickname, src->nickname);

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
    {
        language = LANGUAGE_JAPANESE;
        StripExtCtrlCodes(nickname);
    }
    else
    {
        language = GAME_LANGUAGE;
    }

    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_NICKNAME, nickname);
    SetMonData(mon, MON_DATA_HP_EV, &src->hpEV);
    SetMonData(mon, MON_DATA_ATK_EV, &src->attackEV);
    SetMonData(mon, MON_DATA_DEF_EV, &src->defenseEV);
    SetMonData(mon, MON_DATA_SPEED_EV, &src->speedEV);
    SetMonData(mon, MON_DATA_SPATK_EV, &src->spAttackEV);
    SetMonData(mon, MON_DATA_SPDEF_EV, &src->spDefenseEV);
    value = src->abilityNum;
    SetMonData(mon, MON_DATA_ABILITY_NUM, &value);
    value = src->hpIV;
    SetMonData(mon, MON_DATA_HP_IV, &value);
    value = src->attackIV;
    SetMonData(mon, MON_DATA_ATK_IV, &value);
    value = src->defenseIV;
    SetMonData(mon, MON_DATA_DEF_IV, &value);
    value = src->speedIV;
    SetMonData(mon, MON_DATA_SPEED_IV, &value);
    value = src->spAttackIV;
    SetMonData(mon, MON_DATA_SPATK_IV, &value);
    value = src->spDefenseIV;
    SetMonData(mon, MON_DATA_SPDEF_IV, &value);
    MonRestorePP(mon);
    CalculateMonStats(mon);
}

void CreateApprenticeMon(struct Pokemon *mon, const struct Apprentice *src, u8 monId)
{
    s32 i;
    u16 evAmount;
    u8 language;
    u32 otId = gApprentices[src->id].otId;
    u32 personality = ((gApprentices[src->id].otId >> 8) | ((gApprentices[src->id].otId & 0xFF) << 8))
                    + src->party[monId].species + src->number;

    CreateMonWithIVs(mon,
              src->party[monId].species,
              GetFrontierEnemyMonLevel(src->lvlMode - 1),
              personality,
              OTID_STRUCT_PRESET(otId),
              MAX_PER_STAT_IVS);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->party[monId].item);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, src->party[monId].moves[i], i);

    evAmount = MAX_TOTAL_EVS / NUM_STATS;
    for (i = 0; i < NUM_STATS; i++)
        SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);

    language = src->language;
    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_OT_NAME, GetApprenticeNameInLanguage(src->id, language));
    CalculateMonStats(mon);
}

void ConvertPokemonToBattleTowerPokemon(struct Pokemon *mon, struct BattleTowerPokemon *dest)
{
    s32 i;
    enum Item heldItem;

    dest->species = GetMonData(mon, MON_DATA_SPECIES);
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (heldItem == ITEM_ENIGMA_BERRY_E_READER)
        heldItem = ITEM_NONE;

    dest->heldItem = heldItem;

    for (i = 0; i < MAX_MON_MOVES; i++)
        dest->moves[i] = GetMonData(mon, MON_DATA_MOVE1 + i);

    dest->level = GetMonData(mon, MON_DATA_LEVEL);
    dest->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    dest->otId = GetMonData(mon, MON_DATA_OT_ID);
    dest->hpEV = GetMonData(mon, MON_DATA_HP_EV);
    dest->attackEV = GetMonData(mon, MON_DATA_ATK_EV);
    dest->defenseEV = GetMonData(mon, MON_DATA_DEF_EV);
    dest->speedEV = GetMonData(mon, MON_DATA_SPEED_EV);
    dest->spAttackEV = GetMonData(mon, MON_DATA_SPATK_EV);
    dest->spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV);
    dest->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    dest->hpIV = GetMonData(mon, MON_DATA_HP_IV);
    dest->attackIV = GetMonData(mon, MON_DATA_ATK_IV);
    dest->defenseIV = GetMonData(mon, MON_DATA_DEF_IV);
    dest->speedIV  = GetMonData(mon, MON_DATA_SPEED_IV);
    dest->spAttackIV  = GetMonData(mon, MON_DATA_SPATK_IV);
    dest->spDefenseIV  = GetMonData(mon, MON_DATA_SPDEF_IV);
    dest->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    dest->personality = GetMonData(mon, MON_DATA_PERSONALITY);
    GetMonData(mon, MON_DATA_NICKNAME10, dest->nickname);
}

static void CreateEventMon(struct Pokemon *mon, enum Species species, u8 level, u32 personality, struct OriginalTrainerId otId)
{
    bool32 isModernFatefulEncounter = TRUE;

    CreateMonWithIVs(mon, species, level, personality, otId, USE_RANDOM_IVS);
    GiveMonInitialMoveset(mon);
    SetMonData(mon, MON_DATA_MODERN_FATEFUL_ENCOUNTER, &isModernFatefulEncounter);
    CalculateMonStats(mon);
}

enum TrainerPicID GetUnionRoomTrainerPic(void)
{
    u8 linkId;
    u32 arrId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        linkId = gRecordedBattleMultiplayerId ^ 1;
    else
        linkId = GetMultiplayerId() ^ 1;

    arrId = gLinkPlayers[linkId].trainerId % NUM_UNION_ROOM_CLASSES;
    arrId |= gLinkPlayers[linkId].gender * NUM_UNION_ROOM_CLASSES;
    return FacilityClassToPicIndex(gUnionRoomFacilityClasses[arrId]);
}

enum TrainerClassID GetUnionRoomTrainerClass(void)
{
    u8 linkId;
    u32 arrId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        linkId = gRecordedBattleMultiplayerId ^ 1;
    else
        linkId = GetMultiplayerId() ^ 1;

    arrId = gLinkPlayers[linkId].trainerId % NUM_UNION_ROOM_CLASSES;
    arrId |= gLinkPlayers[linkId].gender * NUM_UNION_ROOM_CLASSES;
    return gFacilityClassToTrainerClass[gUnionRoomFacilityClasses[arrId]];
}

void CreateEnemyEventMon(void)
{
    s32 species = gSpecialVar_0x8004;
    s32 level = gSpecialVar_0x8005;
    s32 itemId = gSpecialVar_0x8006;

    ZeroEnemyPartyMons();

    CreateEventMon(&gParties[B_TRAINER_OPPONENT_A][0], species, level, Random32(), OTID_STRUCT_PLAYER_ID);
    if (itemId)
    {
        u8 heldItem[2];
        heldItem[0] = itemId;
        heldItem[1] = itemId >> 8;
        SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HELD_ITEM, heldItem);
    }
}

static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon)
{
    u32 checksum = 0;

    for (u32 i = 0; i < ARRAY_COUNT(boxMon->secure.raw); i++)
        checksum += boxMon->secure.raw[i] + (boxMon->secure.raw[i] >> 16);

    return checksum;
}

static u16 CalculateBoxMonChecksumDecrypt(struct BoxPokemon *boxMon)
{
    u32 checksum = 0;

    for (u32 i = 0; i < ARRAY_COUNT(boxMon->secure.raw); i++)
    {
        boxMon->secure.raw[i] ^= (boxMon->otId ^ boxMon->personality);
        checksum += boxMon->secure.raw[i] + (boxMon->secure.raw[i] >> 16);
    }

    return checksum;
}

static u16 CalculateBoxMonChecksumReencrypt(struct BoxPokemon *boxMon)
{
    u32 checksum = 0;

    for (u32 i = 0; i < ARRAY_COUNT(boxMon->secure.raw); i++)
    {
        checksum += boxMon->secure.raw[i] + (boxMon->secure.raw[i] >> 16);
        boxMon->secure.raw[i] ^= (boxMon->otId ^ boxMon->personality);
    }

    return checksum;
}

void CalculateMonStats(struct Pokemon *mon)
{
    CalculateMonStatsCont(mon, TRUE);
}

void CalculateMonStatsCont(struct Pokemon *mon, bool32 updateSpeedStat)
{
    s32 oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP);
    s32 currentHP = GetMonData(mon, MON_DATA_HP);
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u8 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    s32 level = GetLevelFromMonExp(mon);
    s32 newMaxHP;

    u8 nature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);

    SetMonData(mon, MON_DATA_LEVEL, &level);

    bool32 hyperTrained[NUM_STATS]; //In a battle test, hyper training flag indicates a fixed stat
    s32 iv[NUM_STATS];
    s32 ev[NUM_STATS];
    for (u32 i = 0; i < NUM_STATS; i++)
    {
        hyperTrained[i] = GetMonData(mon, MON_DATA_HYPER_TRAINED_HP + i);
        iv[i] = GetMonData(mon, MON_DATA_HP_IV + i);
        ev[i] = GetMonData(mon, MON_DATA_HP_EV + i);

        if (hyperTrained[i])
        {
        #if TESTING
            if (gMain.inBattle)
                continue;
        #endif
            iv[i] = MAX_PER_STAT_IVS;
        }

        if (i == STAT_HP)
            continue;

        u8 baseStat = GetSpeciesBaseStat(species, i);
        s32 n = (((2 * baseStat + iv[i] + ev[i] / 4) * level) / 100) + 5;
        n = ModifyStatByNature(nature, n, i);
        if (B_FRIENDSHIP_BOOST == TRUE)
            n = n + ((n * 10 * friendship) / (MAX_FRIENDSHIP * 100));
        SetMonData(mon, MON_DATA_MAX_HP + i, &n);
    }

#if TESTING
    if (hyperTrained[STAT_HP] && gMain.inBattle)
        return;
#endif

    if (HasShedinjaHPHandling(species))
    {
        newMaxHP = 1;
    }
    else
    {
        s32 n = 2 * GetSpeciesBaseHP(species) + iv[STAT_HP];
        newMaxHP = (((n + ev[STAT_HP] / 4) * level) / 100) + level + 10;
    }

    gBattleScripting.levelUpHP = newMaxHP - oldMaxHP;
    if (gBattleScripting.levelUpHP == 0)
        gBattleScripting.levelUpHP = 1;
    SetMonData(mon, MON_DATA_MAX_HP, &newMaxHP);

    // Since a Pokémon's maxHP data could either not have
    // been initialized at this point or this Pokémon is
    // just fainted, the check for oldMaxHP is important.
    if (currentHP == 0 && oldMaxHP != 0)
        return;

    // Only add to currentHP if newMaxHP went up.
    if (newMaxHP > oldMaxHP)
        currentHP += newMaxHP - oldMaxHP;

    // Ensure currentHP does not surpass newMaxHP.
    if (currentHP > newMaxHP)
        currentHP = newMaxHP;

    SetMonData(mon, MON_DATA_HP, &currentHP);
}

void BoxMonToMon(const struct BoxPokemon *src, struct Pokemon *dest)
{
    u32 value = 0;
    dest->box = *src;
    dest->status = GetBoxMonData(&dest->box, MON_DATA_STATUS);
    dest->hp = 0;
    dest->maxHP = 0;
    value = MAIL_NONE;
    SetMonData(dest, MON_DATA_MAIL, &value);
    value = GetBoxMonData(&dest->box, MON_DATA_HP_LOST);
    CalculateMonStats(dest);
    value = GetMonData(dest, MON_DATA_MAX_HP) - value;
    SetMonData(dest, MON_DATA_HP, &value);
}

u8 GetLevelFromMonExp(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u32 exp = GetMonData(mon, MON_DATA_EXP);
    s32 level = 1;

    while (level <= MAX_LEVEL && gExperienceTables[gSpeciesInfo[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon)
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    u32 exp = GetBoxMonData(boxMon, MON_DATA_EXP);
    s32 level = 1;

    while (level <= MAX_LEVEL && gExperienceTables[gSpeciesInfo[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u16 GiveMoveToMon(struct Pokemon *mon, enum Move move)
{
    return GiveMoveToBoxMon(&mon->box, move);
}

u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, enum Move move)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        enum Move existingMove = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i);
        if (existingMove == MOVE_NONE)
        {
            u32 pp = GetMovePP(move);
            SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &move);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp);
            return move;
        }
        if (existingMove == move)
            return MON_ALREADY_KNOWS_MOVE;
    }
    return MON_HAS_MAX_MOVES;
}

u16 GiveMoveToBattleMon(struct BattlePokemon *mon, enum Move move)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (mon->moves[i] == MOVE_NONE)
        {
            mon->moves[i] = move;
            mon->pp[i] = GetMovePP(move);
            return move;
        }
    }

    return MON_HAS_MAX_MOVES;
}

void SetMonMoveSlot(struct Pokemon *mon, enum Move move, u8 slot)
{
    SetBoxMonMoveSlot(&mon->box, move, slot);
}

void SetBoxMonMoveSlot(struct BoxPokemon *mon, enum Move move, u8 slot)
{
    SetBoxMonData(mon, MON_DATA_MOVE1 + slot, &move);
    u32 pp = GetMovePP(move);
    SetBoxMonData(mon, MON_DATA_PP1 + slot, &pp);
}

static void SetMonMoveSlot_KeepPP(struct Pokemon *mon, enum Move move, u8 slot)
{
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    u8 currPP = GetMonData(mon, MON_DATA_PP1 + slot);
    u8 newPP = CalculatePPWithBonus(move, ppBonuses, slot);
    u16 finalPP = min(currPP, newPP);

    SetMonData(mon, MON_DATA_MOVE1 + slot, &move);
    SetMonData(mon, MON_DATA_PP1 + slot, &finalPP);
}

void SetBattleMonMoveSlot(struct BattlePokemon *mon, enum Move move, u8 slot)
{
    mon->moves[slot] = move;
    mon->pp[slot] = GetMovePP(move);
}

void GiveMonInitialMoveset(struct Pokemon *mon)
{
    GiveBoxMonInitialMoveset(&mon->box);
}

void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon) //Credit: AsparagusEduardo
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    s32 level = GetLevelFromBoxMonExp(boxMon);
    s32 i;
    enum Move moves[MAX_MON_MOVES] = {MOVE_NONE};
    u8 addedMoves = 0;
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        s32 j;
        bool32 alreadyKnown = FALSE;

        if (learnset[i].level > level)
            break;
        if (learnset[i].level == 0)
            continue;

        for (j = 0; j < addedMoves; j++)
        {
            if (moves[j] == learnset[i].move)
            {
                alreadyKnown = TRUE;
                break;
            }
        }

        if (!alreadyKnown)
        {
            if (addedMoves < MAX_MON_MOVES)
            {
                moves[addedMoves] = learnset[i].move;
                addedMoves++;
            }
            else
            {
                for (j = 0; j < MAX_MON_MOVES - 1; j++)
                    moves[j] = moves[j + 1];
                moves[MAX_MON_MOVES - 1] = learnset[i].move;
            }
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &moves[i]);
        u32 pp = GetMovePP(moves[i]);
        SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp);
    }
}

void GiveMonDefaultMove(struct Pokemon *mon, u32 slot)
{
    GiveBoxMonDefaultMove(&mon->box, slot);
}

void GiveBoxMonDefaultMove(struct BoxPokemon *boxMon, u32 slot)
{
    enum Move move = MOVE_NONE;
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    s32 level = GetLevelFromBoxMonExp(boxMon);
    for (u32 i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        s32 j;
        bool32 alreadyKnown = FALSE;

        if (learnset[i].level > level)
            break;
        if (learnset[i].level == 0)
            continue;

        for (j = 0; j < slot; j++)
        {
            if (GetBoxMonData(boxMon, MON_DATA_MOVE1 + j) == learnset[i].move)
            {
                alreadyKnown = TRUE;
                break;
            }
        }
        if (!alreadyKnown)
            move = learnset[i].move;
    }

    SetBoxMonData(boxMon, MON_DATA_MOVE1 + slot, &move);
    u32 pp = GetMovePP(move);
    SetBoxMonData(boxMon, MON_DATA_PP1 + slot, &pp);
}

enum Move MonTryLearningNewMoveAtLevel(struct Pokemon *mon, bool32 firstMove, u32 level)
{
    enum Move retVal = MOVE_NONE;
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    // since you can learn more than one move per level
    // the game needs to know whether you decided to
    // learn it or keep the old set to avoid asking
    // you to learn the same move over and over again
    if (firstMove)
    {
        sLearningMoveTableID = 0;

        while (learnset[sLearningMoveTableID].level != level)
        {
            sLearningMoveTableID++;
            if (learnset[sLearningMoveTableID].move == LEVEL_UP_MOVE_END)
                return MOVE_NONE;
        }
    }

    //  Handler for Pokémon whose moves change upon form change.
    //  For example, if Zacian or Zamazenta should learn Iron Head,
    //  they're prevented from doing if they have Behemoth Blade/Bash,
    //  since it transforms into them while in their Crowned forms.
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    for (u32 i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_END_BATTLE
            && learnset[sLearningMoveTableID].move == formChanges[i].param3)
        {
            for (u32 j = 0; j < MAX_MON_MOVES; j++)
            {
                if (formChanges[i].param2 == GetMonData(mon, MON_DATA_MOVE1 + j))
                {
                    sLearningMoveTableID++;
                    return MON_ALREADY_KNOWS_MOVE;
                }
            }
        }
    }

    if (learnset[sLearningMoveTableID].level == level)
    {
        gMoveToLearn = learnset[sLearningMoveTableID].move;
        sLearningMoveTableID++;
        retVal = GiveMoveToMon(mon, gMoveToLearn);
    }

    return retVal;
}

enum Move MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove)
{
    return MonTryLearningNewMoveAtLevel(mon, firstMove, GetMonData(mon, MON_DATA_LEVEL));
}

void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, enum Move move)
{
    s32 i;
    enum Move moves[MAX_MON_MOVES];
    u8 pp[MAX_MON_MOVES];
    u8 ppBonuses;

    for (i = 0; i < MAX_MON_MOVES - 1; i++)
    {
        moves[i] = GetMonData(mon, MON_DATA_MOVE2 + i);
        pp[i] = GetMonData(mon, MON_DATA_PP2 + i);
    }

    ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    ppBonuses >>= 2;
    moves[MAX_MON_MOVES - 1] = move;
    pp[MAX_MON_MOVES - 1] = GetMovePP(move);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        SetMonData(mon, MON_DATA_MOVE1 + i, &moves[i]);
        SetMonData(mon, MON_DATA_PP1 + i, &pp[i]);
    }

    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

u32 CountAliveMonsInBattle(u8 caseId, enum BattlerId battler)
{
    enum BattlerId i;
    u32 aliveMonCount = 0;

    switch (caseId)
    {
    case BATTLE_ALIVE_EXCEPT_BATTLER:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (i != battler && IsBattlerAlive(i))
                aliveMonCount++;
        }
        break;
    case BATTLE_ALIVE_EXCEPT_BATTLER_SIDE:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (i != battler && i != GetPartnerBattler(battler) && IsBattlerAlive(i))
                aliveMonCount++;
        }
        break;
    case BATTLE_ALIVE_SIDE:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (IsBattlerAlly(i, battler) && IsBattlerAlive(i))
                aliveMonCount++;
        }
        break;
    }

    return aliveMonCount;
}

u8 GetMonGender(struct Pokemon *mon)
{
    return GetBoxMonGender(&mon->box);
}

u8 GetBoxMonGender(struct BoxPokemon *boxMon)
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    u32 personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);

    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gSpeciesInfo[species].genderRatio;
    }

    if (gSpeciesInfo[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

u8 GetGenderFromSpeciesAndPersonality(enum Species species, u32 personality)
{
    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gSpeciesInfo[species].genderRatio;
    }

    if (gSpeciesInfo[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

bool32 IsPersonalityFemale(enum Species species, u32 personality)
{
    return GetGenderFromSpeciesAndPersonality(species, personality) == MON_FEMALE;
}

enum Species GetUnownSpeciesId(u32 personality)
{
    u16 unownLetter = GetUnownLetterByPersonality(personality);

    if (unownLetter == 0)
        return SPECIES_UNOWN;
    return unownLetter + SPECIES_UNOWN_B - 1;
}

void SetMultiuseSpriteTemplateToPokemon(enum Species speciesTag, enum BattlerPosition battlerPosition)
{
    if (gMonSpritesGfxPtr != NULL)
        gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
    else if (sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_A])
        gMultiuseSpriteTemplate = sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_A]->templates[battlerPosition];
    else if (sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_B])
        gMultiuseSpriteTemplate = sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_B]->templates[battlerPosition];
    else
        gMultiuseSpriteTemplate = gBattlerSpriteTemplates[battlerPosition];

    gMultiuseSpriteTemplate.paletteTag = speciesTag;
    if (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_PLAYER_RIGHT)
        gMultiuseSpriteTemplate.anims = gAnims_MonPic;
    else
    {
        if (speciesTag > SPECIES_SHINY_TAG)
            speciesTag = speciesTag - SPECIES_SHINY_TAG;

        speciesTag = SanitizeSpeciesId(speciesTag);
        if (gSpeciesInfo[speciesTag].frontAnimFrames != NULL)
            gMultiuseSpriteTemplate.anims = gSpeciesInfo[speciesTag].frontAnimFrames;
        else
            gMultiuseSpriteTemplate.anims = gSpeciesInfo[SPECIES_NONE].frontAnimFrames;
    }
}

void SetMultiuseSpriteTemplateToTrainerBack(enum TrainerPicID trainerPicId, enum BattlerPosition battlerPosition)
{
    gMultiuseSpriteTemplate.paletteTag = GetTrainerPicTag(trainerPicId, FALSE);
    if (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_PLAYER_RIGHT)
    {
        gMultiuseSpriteTemplate = sTrainerBackSpriteTemplate;
        gMultiuseSpriteTemplate.images = GetTrainerBackPicImage(trainerPicId);
        gMultiuseSpriteTemplate.anims = GetTrainerBackPicAnims(trainerPicId);
    }
    else
    {
        if (gMonSpritesGfxPtr != NULL)
            gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
        else
            gMultiuseSpriteTemplate = gBattlerSpriteTemplates[battlerPosition];
        gMultiuseSpriteTemplate.anims = gAnims_Trainer;
    }
}

void SetMultiuseSpriteTemplateToTrainerFront(enum TrainerPicID trainerPicId, enum BattlerPosition battlerPosition)
{
    if (gMonSpritesGfxPtr != NULL)
        gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
    else
        gMultiuseSpriteTemplate = gBattlerSpriteTemplates[battlerPosition];

    gMultiuseSpriteTemplate.paletteTag = GetTrainerPicTag(trainerPicId, TRUE);
    gMultiuseSpriteTemplate.anims = gAnims_Trainer;
}

static void EncryptBoxMon(struct BoxPokemon *boxMon)
{
    for (u32 i = 0; i < ARRAY_COUNT(boxMon->secure.raw); i++)
    {
        boxMon->secure.raw[i] ^= boxMon->personality;
        boxMon->secure.raw[i] ^= boxMon->otId;
    }
}

static void DecryptBoxMon(struct BoxPokemon *boxMon)
{
    for (u32 i = 0; i < ARRAY_COUNT(boxMon->secure.raw); i++)
    {
        boxMon->secure.raw[i] ^= boxMon->otId;
        boxMon->secure.raw[i] ^= boxMon->personality;
    }
}

static const u8 sSubstructOffsets[4][24] =
{
    [SUBSTRUCT_TYPE_0] = {0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 2, 3, 1, 1, 2, 3, 2, 3, 1, 1, 2, 3, 2, 3},
    [SUBSTRUCT_TYPE_1] = {1, 1, 2, 3, 2, 3, 0, 0, 0, 0, 0, 0, 2, 3, 1, 1, 3, 2, 2, 3, 1, 1, 3, 2},
    [SUBSTRUCT_TYPE_2] = {2, 3, 1, 1, 3, 2, 2, 3, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 3, 2, 3, 2, 1, 1},
    [SUBSTRUCT_TYPE_3] = {3, 2, 3, 2, 1, 1, 3, 2, 3, 2, 1, 1, 3, 2, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0},
};

ARM_FUNC NOINLINE static u32 ConstantMod24(u32 a) { return a % 24; }

static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, enum SubstructType substructType)
{
    return &boxMon->secure.substructs[sSubstructOffsets[substructType][ConstantMod24(personality)]];
}

/* GameFreak called GetMonData with either 2 or 3 arguments, for type
 * safety we have a GetMonData macro (in include/pokemon.h) which
 * dispatches to either GetMonData2 or GetMonData3 based on the number
 * of arguments. */
u32 GetMonData3(struct Pokemon *mon, s32 field, u8 *data)
{
    u32 ret;

    switch (field)
    {
    case MON_DATA_STATUS:
        ret = mon->status;
        break;
    case MON_DATA_LEVEL:
        ret = mon->level;
        break;
    case MON_DATA_HP:
        ret = mon->hp;
        break;
    case MON_DATA_MAX_HP:
        ret = mon->maxHP;
        break;
    case MON_DATA_ATK:
        ret = mon->attack;
        break;
    case MON_DATA_DEF:
        ret = mon->defense;
        break;
    case MON_DATA_SPEED:
        ret = mon->speed;
        break;
    case MON_DATA_SPATK:
        ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF:
        ret = mon->spDefense;
        break;
    case MON_DATA_MAIL:
        ret = mon->mail;
        break;
    default:
        ret = GetBoxMonData(&mon->box, field, data);
        break;
    }
    return ret;
}

u32 GetMonData2(struct Pokemon *mon, s32 field)
{
    return GetMonData3(mon, field, NULL);
}

union EvolutionTracker
{
    u16 combinedValue:10;
    struct {
        u16 tracker1: 5;
        u16 tracker2: 5;
    };
};

static ALWAYS_INLINE struct PokemonSubstruct0 *GetSubstruct0(struct BoxPokemon *boxMon)
{
    return &(GetSubstruct(boxMon, boxMon->personality, SUBSTRUCT_TYPE_0)->type0);
}

static ALWAYS_INLINE struct PokemonSubstruct1 *GetSubstruct1(struct BoxPokemon *boxMon)
{
    return &(GetSubstruct(boxMon, boxMon->personality, SUBSTRUCT_TYPE_1)->type1);
}

static ALWAYS_INLINE struct PokemonSubstruct2 *GetSubstruct2(struct BoxPokemon *boxMon)
{
    return &(GetSubstruct(boxMon, boxMon->personality, SUBSTRUCT_TYPE_2)->type2);
}

static ALWAYS_INLINE struct PokemonSubstruct3 *GetSubstruct3(struct BoxPokemon *boxMon)
{
    return &(GetSubstruct(boxMon, boxMon->personality, SUBSTRUCT_TYPE_3)->type3);
}

static bool32 IsBadEgg(struct BoxPokemon *boxMon)
{
    if (boxMon->isBadEgg)
        return TRUE;

    if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum)
    {
        boxMon->isBadEgg = TRUE;
        boxMon->isEgg = TRUE;
        GetSubstruct3(boxMon)->isEgg = TRUE;

        return TRUE;
    }

    return FALSE;
}

static ALWAYS_INLINE bool32 IsEggOrBadEgg(struct BoxPokemon *boxMon)
{
    return GetSubstruct3(boxMon)->isEgg || IsBadEgg(boxMon);
}

/* GameFreak called GetBoxMonData with either 2 or 3 arguments, for type
 * safety we have a GetBoxMonData macro (in include/pokemon.h) which
 * dispatches to either GetBoxMonData2 or GetBoxMonData3 based on the
 * number of arguments. */
u32 GetBoxMonData3(struct BoxPokemon *boxMon, s32 field, u8 *data)
{
    s32 i;
    u32 retVal = 0;

    // Any field greater than MON_DATA_ENCRYPT_SEPARATOR is encrypted and must be treated as such
    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        DecryptBoxMon(boxMon);

        switch (field)
        {
        case MON_DATA_NICKNAME:
        case MON_DATA_NICKNAME10:
        {
            if (IsBadEgg(boxMon))
            {
                for (retVal = 0;
                    retVal < POKEMON_NAME_LENGTH && gText_BadEgg[retVal] != EOS;
                    data[retVal] = gText_BadEgg[retVal], retVal++) {}

                data[retVal] = EOS;
            }
            else if (boxMon->isEgg)
            {
                StringCopy(data, gText_EggNickname);
                retVal = StringLength(data);
            }
            else if (boxMon->language == LANGUAGE_JAPANESE)
            {
                data[0] = EXT_CTRL_CODE_BEGIN;
                data[1] = EXT_CTRL_CODE_JPN;

                for (retVal = 2, i = 0;
                    i < 5 && boxMon->nickname[i] != EOS;
                    data[retVal] = boxMon->nickname[i], retVal++, i++) {}

                data[retVal++] = EXT_CTRL_CODE_BEGIN;
                data[retVal++] = EXT_CTRL_CODE_ENG;
                data[retVal] = EOS;
            }
            else
            {
                retVal = 0;
                while (retVal < min(sizeof(boxMon->nickname), POKEMON_NAME_LENGTH))
                {
                    data[retVal] = boxMon->nickname[retVal];
                    retVal++;
                }

                // Vanilla Pokémon have 0s in nickname11 and nickname12
                // so if both are 0 we assume that this is a vanilla
                // Pokémon and replace them with EOS. This means that
                // two CHAR_SPACE at the end of a nickname are trimmed.
                struct PokemonSubstruct0 *substruct0 = GetSubstruct0(boxMon);
                if (field != MON_DATA_NICKNAME10 && POKEMON_NAME_LENGTH >= 12)
                {
                    if (substruct0->nickname11 == 0 && substruct0->nickname12 == 0)
                    {
                        data[retVal++] = EOS;
                        data[retVal++] = EOS;
                    }
                    else
                    {
                        data[retVal++] = substruct0->nickname11;
                        data[retVal++] = substruct0->nickname12;
                    }
                }
                else if (field != MON_DATA_NICKNAME10 && POKEMON_NAME_LENGTH >= 11)
                {
                    if (substruct0->nickname11 == 0)
                    {
                        data[retVal++] = EOS;
                    }
                    else
                    {
                        data[retVal++] = substruct0->nickname11;
                    }
                }

                data[retVal] = EOS;
            }
            break;
        }
        case MON_DATA_SPECIES:
            retVal = IsBadEgg(boxMon) ? SPECIES_EGG : GetSubstruct0(boxMon)->species;
            break;
        case MON_DATA_HELD_ITEM:
            retVal = GetSubstruct0(boxMon)->heldItem;
            break;
        case MON_DATA_EXP:
            retVal = GetSubstruct0(boxMon)->experience;
            break;
        case MON_DATA_PP_BONUSES:
            retVal = GetSubstruct0(boxMon)->ppBonuses;
            break;
        case MON_DATA_FRIENDSHIP:
            retVal = GetSubstruct0(boxMon)->friendship;
            break;
        case MON_DATA_MOVE1:
            retVal = GetSubstruct1(boxMon)->move1;
            break;
        case MON_DATA_MOVE2:
            retVal = GetSubstruct1(boxMon)->move2;
            break;
        case MON_DATA_MOVE3:
            retVal = GetSubstruct1(boxMon)->move3;
            break;
        case MON_DATA_MOVE4:
            retVal = GetSubstruct1(boxMon)->move4;
            break;
        case MON_DATA_PP1:
            retVal = GetSubstruct1(boxMon)->pp1;
            break;
        case MON_DATA_PP2:
            retVal = GetSubstruct1(boxMon)->pp2;
            break;
        case MON_DATA_PP3:
            retVal = GetSubstruct1(boxMon)->pp3;
            break;
        case MON_DATA_PP4:
            retVal = GetSubstruct1(boxMon)->pp4;
            break;
        case MON_DATA_HP_EV:
            retVal = GetSubstruct2(boxMon)->hpEV;
            break;
        case MON_DATA_ATK_EV:
            retVal = GetSubstruct2(boxMon)->attackEV;
            break;
        case MON_DATA_DEF_EV:
            retVal = GetSubstruct2(boxMon)->defenseEV;
            break;
        case MON_DATA_SPEED_EV:
            retVal = GetSubstruct2(boxMon)->speedEV;
            break;
        case MON_DATA_SPATK_EV:
            retVal = GetSubstruct2(boxMon)->spAttackEV;
            break;
        case MON_DATA_SPDEF_EV:
            retVal = GetSubstruct2(boxMon)->spDefenseEV;
            break;
        case MON_DATA_COOL:
            retVal = GetSubstruct2(boxMon)->cool;
            break;
        case MON_DATA_BEAUTY:
            retVal = GetSubstruct2(boxMon)->beauty;
            break;
        case MON_DATA_CUTE:
            retVal = GetSubstruct2(boxMon)->cute;
            break;
        case MON_DATA_SMART:
            retVal = GetSubstruct2(boxMon)->smart;
            break;
        case MON_DATA_TOUGH:
            retVal = GetSubstruct2(boxMon)->tough;
            break;
        case MON_DATA_SHEEN:
            retVal = GetSubstruct2(boxMon)->sheen;
            break;
        case MON_DATA_POKERUS:
            retVal = GetSubstruct3(boxMon)->pokerus;
            break;
        case MON_DATA_POKERUS_STRAIN:
            retVal = ((GetSubstruct3(boxMon)->pokerus & 0xF0) >> 4);
            break;
        case MON_DATA_POKERUS_DAYS_LEFT:
            retVal = (GetSubstruct3(boxMon)->pokerus & 0x0F);
            break;
        case MON_DATA_MET_LOCATION:
            retVal = GetSubstruct3(boxMon)->metLocation;
            break;
        case MON_DATA_MET_LEVEL:
            retVal = GetSubstruct3(boxMon)->metLevel;
            break;
        case MON_DATA_MET_GAME:
            retVal = GetSubstruct3(boxMon)->metGame;
            break;
        case MON_DATA_POKEBALL:
            retVal = GetSubstruct0(boxMon)->pokeball;
            break;
        case MON_DATA_OT_GENDER:
            retVal = GetSubstruct3(boxMon)->otGender;
            break;
        case MON_DATA_HP_IV:
            retVal = GetSubstruct3(boxMon)->hpIV;
            break;
        case MON_DATA_ATK_IV:
            retVal = GetSubstruct3(boxMon)->attackIV;
            break;
        case MON_DATA_DEF_IV:
            retVal = GetSubstruct3(boxMon)->defenseIV;
            break;
        case MON_DATA_SPEED_IV:
            retVal = GetSubstruct3(boxMon)->speedIV;
            break;
        case MON_DATA_SPATK_IV:
            retVal = GetSubstruct3(boxMon)->spAttackIV;
            break;
        case MON_DATA_SPDEF_IV:
            retVal = GetSubstruct3(boxMon)->spDefenseIV;
            break;
        case MON_DATA_IS_EGG:
            retVal = IsEggOrBadEgg(boxMon);
            break;
        case MON_DATA_ABILITY_NUM:
            retVal = GetSubstruct3(boxMon)->abilityNum;
            break;
        case MON_DATA_COOL_RIBBON:
            retVal = GetSubstruct3(boxMon)->coolRibbon;
            break;
        case MON_DATA_BEAUTY_RIBBON:
            retVal = GetSubstruct3(boxMon)->beautyRibbon;
            break;
        case MON_DATA_CUTE_RIBBON:
            retVal = GetSubstruct3(boxMon)->cuteRibbon;
            break;
        case MON_DATA_SMART_RIBBON:
            retVal = GetSubstruct3(boxMon)->smartRibbon;
            break;
        case MON_DATA_TOUGH_RIBBON:
            retVal = GetSubstruct3(boxMon)->toughRibbon;
            break;
        case MON_DATA_CHAMPION_RIBBON:
            retVal = GetSubstruct3(boxMon)->championRibbon;
            break;
        case MON_DATA_WINNING_RIBBON:
            retVal = GetSubstruct3(boxMon)->winningRibbon;
            break;
        case MON_DATA_VICTORY_RIBBON:
            retVal = GetSubstruct3(boxMon)->victoryRibbon;
            break;
        case MON_DATA_ARTIST_RIBBON:
            retVal = GetSubstruct3(boxMon)->artistRibbon;
            break;
        case MON_DATA_EFFORT_RIBBON:
            retVal = GetSubstruct3(boxMon)->effortRibbon;
            break;
        case MON_DATA_MARINE_RIBBON:
            retVal = GetSubstruct3(boxMon)->marineRibbon;
            break;
        case MON_DATA_LAND_RIBBON:
            retVal = GetSubstruct3(boxMon)->landRibbon;
            break;
        case MON_DATA_SKY_RIBBON:
            retVal = GetSubstruct3(boxMon)->skyRibbon;
            break;
        case MON_DATA_COUNTRY_RIBBON:
            retVal = GetSubstruct3(boxMon)->countryRibbon;
            break;
        case MON_DATA_NATIONAL_RIBBON:
            retVal = GetSubstruct3(boxMon)->nationalRibbon;
            break;
        case MON_DATA_EARTH_RIBBON:
            retVal = GetSubstruct3(boxMon)->earthRibbon;
            break;
        case MON_DATA_WORLD_RIBBON:
            retVal = GetSubstruct3(boxMon)->worldRibbon;
            break;
        case MON_DATA_MODERN_FATEFUL_ENCOUNTER:
            retVal = GetSubstruct3(boxMon)->modernFatefulEncounter;
            break;
        case MON_DATA_SPECIES_OR_EGG:
            retVal = GetSubstruct0(boxMon)->species;
            if (retVal && IsEggOrBadEgg(boxMon))
                retVal = SPECIES_EGG;
            break;
        case MON_DATA_IVS:
        {
            struct PokemonSubstruct3 *substruct3 = GetSubstruct3(boxMon);
            retVal = substruct3->hpIV
                    | (substruct3->attackIV << 5)
                    | (substruct3->defenseIV << 10)
                    | (substruct3->speedIV << 15)
                    | (substruct3->spAttackIV << 20)
                    | (substruct3->spDefenseIV << 25);
            break;
        }
        case MON_DATA_KNOWN_MOVES:
            if (GetSubstruct0(boxMon)->species && !IsEggOrBadEgg(boxMon))
            {
                struct PokemonSubstruct1 *substruct1 = GetSubstruct1(boxMon);
                u16 *moves = (u16 *)data;
                s32 i = 0;

                while (moves[i] != MOVES_COUNT)
                {
                    enum Move move = moves[i];
                    if (substruct1->move1 == move
                        || substruct1->move2 == move
                        || substruct1->move3 == move
                        || substruct1->move4 == move)
                        retVal |= (1u << i);
                    i++;
                }
            }
            break;
        case MON_DATA_RIBBON_COUNT:
            if (GetSubstruct0(boxMon)->species && !IsEggOrBadEgg(boxMon))
            {
                struct PokemonSubstruct3 *substruct3 = GetSubstruct3(boxMon);
                retVal = 0;
                retVal += substruct3->coolRibbon;
                retVal += substruct3->beautyRibbon;
                retVal += substruct3->cuteRibbon;
                retVal += substruct3->smartRibbon;
                retVal += substruct3->toughRibbon;
                retVal += substruct3->championRibbon;
                retVal += substruct3->winningRibbon;
                retVal += substruct3->victoryRibbon;
                retVal += substruct3->artistRibbon;
                retVal += substruct3->effortRibbon;
                retVal += substruct3->marineRibbon;
                retVal += substruct3->landRibbon;
                retVal += substruct3->skyRibbon;
                retVal += substruct3->countryRibbon;
                retVal += substruct3->nationalRibbon;
                retVal += substruct3->earthRibbon;
                retVal += substruct3->worldRibbon;
            }
            break;
        case MON_DATA_RIBBONS:
            if (GetSubstruct0(boxMon)->species && !IsEggOrBadEgg(boxMon))
            {
                struct PokemonSubstruct3 *substruct3 = GetSubstruct3(boxMon);
                retVal = substruct3->championRibbon
                       | (substruct3->coolRibbon << 1)
                       | (substruct3->beautyRibbon << 4)
                       | (substruct3->cuteRibbon << 7)
                       | (substruct3->smartRibbon << 10)
                       | (substruct3->toughRibbon << 13)
                       | (substruct3->winningRibbon << 16)
                       | (substruct3->victoryRibbon << 17)
                       | (substruct3->artistRibbon << 18)
                       | (substruct3->effortRibbon << 19)
                       | (substruct3->marineRibbon << 20)
                       | (substruct3->landRibbon << 21)
                       | (substruct3->skyRibbon << 22)
                       | (substruct3->countryRibbon << 23)
                       | (substruct3->nationalRibbon << 24)
                       | (substruct3->earthRibbon << 25)
                       | (substruct3->worldRibbon << 26);
            }
            break;
        case MON_DATA_HYPER_TRAINED_HP:
            retVal = GetSubstruct1(boxMon)->hyperTrainedHP;
            break;
        case MON_DATA_HYPER_TRAINED_ATK:
            retVal = GetSubstruct1(boxMon)->hyperTrainedAttack;
            break;
        case MON_DATA_HYPER_TRAINED_DEF:
            retVal = GetSubstruct1(boxMon)->hyperTrainedDefense;
            break;
        case MON_DATA_HYPER_TRAINED_SPEED:
            retVal = GetSubstruct1(boxMon)->hyperTrainedSpeed;
            break;
        case MON_DATA_HYPER_TRAINED_SPATK:
            retVal = GetSubstruct1(boxMon)->hyperTrainedSpAttack;
            break;
        case MON_DATA_HYPER_TRAINED_SPDEF:
            retVal = GetSubstruct1(boxMon)->hyperTrainedSpDefense;
            break;
        case MON_DATA_IS_SHADOW:
            retVal = GetSubstruct3(boxMon)->isShadow;
            break;
        case MON_DATA_DYNAMAX_LEVEL:
            retVal = GetSubstruct3(boxMon)->dynamaxLevel;
            break;
        case MON_DATA_GIGANTAMAX_FACTOR:
            retVal = GetSubstruct3(boxMon)->gigantamaxFactor;
            break;
        case MON_DATA_TERA_TYPE:
            {
                struct PokemonSubstruct0 *substruct0 = GetSubstruct0(boxMon);
                if (gSpeciesInfo[substruct0->species].forceTeraType)
                {
                    retVal = gSpeciesInfo[substruct0->species].forceTeraType;
                }
                else if (substruct0->teraType == TYPE_NONE) // Tera Type hasn't been modified so we can just use the personality
                {
                    const enum Type *types = gSpeciesInfo[substruct0->species].types;
                    retVal = (boxMon->personality & 0x1) == 0 ? types[0] : types[1];
                }
                else
                {
                    retVal = substruct0->teraType;
                }
            }
            break;
        case MON_DATA_EVOLUTION_TRACKER:
            {
                struct PokemonSubstruct1 *substruct1 = GetSubstruct1(boxMon);
                retVal = (union EvolutionTracker) {
                    .tracker1 = substruct1->evolutionTracker1,
                    .tracker2 = substruct1->evolutionTracker2,
                }.combinedValue;
            }
            break;
        default:
            break;
        }
    }
    else
    {
        switch (field)
        {
        case MON_DATA_STATUS:
            retVal = UncompressStatus(boxMon->compressedStatus);
            break;
        case MON_DATA_HP_LOST:
            retVal = boxMon->hpLost;
            break;
        case MON_DATA_PERSONALITY:
            retVal = boxMon->personality;
            break;
        case MON_DATA_OT_ID:
            retVal = boxMon->otId;
            break;
        case MON_DATA_LANGUAGE:
            retVal = boxMon->language;
            break;
        case MON_DATA_SANITY_IS_BAD_EGG:
            retVal = boxMon->isBadEgg;
            break;
        case MON_DATA_SANITY_HAS_SPECIES:
            retVal = boxMon->hasSpecies;
            break;
        case MON_DATA_SANITY_IS_EGG:
            retVal = boxMon->isEgg;
            break;
        case MON_DATA_OT_NAME:
        {
            retVal = 0;

            while (retVal < PLAYER_NAME_LENGTH)
            {
                data[retVal] = boxMon->otName[retVal];
                retVal++;
            }

            data[retVal] = EOS;
            break;
        }
        case MON_DATA_MARKINGS:
            retVal = boxMon->markings;
            break;
        case MON_DATA_CHECKSUM:
            retVal = boxMon->checksum;
            break;
        case MON_DATA_IS_SHINY:
        {
            u32 shinyValue = GET_SHINY_VALUE(boxMon->otId, boxMon->personality);
            retVal = (shinyValue < SHINY_ODDS) ^ boxMon->shinyModifier;
            break;
        }
        case MON_DATA_HIDDEN_NATURE:
        {
            u32 nature = GetNatureFromPersonality(boxMon->personality);
            retVal = nature ^ boxMon->hiddenNatureModifier;
            break;
        }
        case MON_DATA_DAYS_SINCE_FORM_CHANGE:
            retVal = boxMon->daysSinceFormChange;
            break;
        default:
            break;
        }
    }

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
        EncryptBoxMon(boxMon);

    return retVal;
}

u32 GetBoxMonData2(struct BoxPokemon *boxMon, s32 field)
{
    return GetBoxMonData3(boxMon, field, NULL);
}

#define SET8(lhs) (lhs) = *data
#define SET16(lhs) (lhs) = data[0] + (data[1] << 8)
#define SET32(lhs) (lhs) = data[0] + (data[1] << 8) + (data[2] << 16) + (data[3] << 24)
//
// Prefer SET_BY_WIDTH for fields whose types might be extended (e.g.
// anything whose typedef is in gametypes.h).
//
#define SET_BY_WIDTH(lhs) \
    do { \
       if (sizeof(lhs) == 1) \
          SET8(lhs); \
       else if (sizeof(lhs) == 2) \
          SET16(lhs); \
       else if (sizeof(lhs) == 4) \
          SET32(lhs); \
   } while (0)

void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg)
{
    const u8 *data = dataArg;

    switch (field)
    {
    case MON_DATA_STATUS:
        SET32(mon->status);
        SetBoxMonData(&mon->box, MON_DATA_STATUS, dataArg);
        break;
    case MON_DATA_LEVEL:
        SET8(mon->level);
        break;
    case MON_DATA_HP:
    {
        u32 hpLost;
        SET16(mon->hp);
        hpLost = mon->maxHP - mon->hp;
        SetBoxMonData(&mon->box, MON_DATA_HP_LOST, &hpLost);
        break;
    }
    case MON_DATA_HP_LOST:
    {
        u32 hpLost;
        SET16(hpLost);
        mon->hp = mon->maxHP - hpLost;
        SetBoxMonData(&mon->box, MON_DATA_HP_LOST, &hpLost);
        break;
    }
    case MON_DATA_MAX_HP:
        SET16(mon->maxHP);
        break;
    case MON_DATA_ATK:
        SET16(mon->attack);
        break;
    case MON_DATA_DEF:
        SET16(mon->defense);
        break;
    case MON_DATA_SPEED:
        SET16(mon->speed);
        break;
    case MON_DATA_SPATK:
        SET16(mon->spAttack);
        break;
    case MON_DATA_SPDEF:
        SET16(mon->spDefense);
        break;
    case MON_DATA_MAIL:
        SET8(mon->mail);
        break;
    case MON_DATA_SPECIES_OR_EGG:
        break;
    default:
        SetBoxMonData(&mon->box, field, data);
        break;
    }
}

void SetBoxMonData(struct BoxPokemon *boxMon, s32 field, const void *dataArg)
{
    const u8 *data = dataArg;

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        if (CalculateBoxMonChecksumDecrypt(boxMon) != boxMon->checksum)
        {
            boxMon->isBadEgg = TRUE;
            boxMon->isEgg = TRUE;
            GetSubstruct3(boxMon)->isEgg = TRUE;
            EncryptBoxMon(boxMon);
            return;
        }

        switch (field)
        {
        case MON_DATA_NICKNAME:
        case MON_DATA_NICKNAME10:
        {
            s32 i;
            struct PokemonSubstruct0 *substruct0 = GetSubstruct0(boxMon);
            for (i = 0; i < min(sizeof(boxMon->nickname), POKEMON_NAME_LENGTH); i++)
                boxMon->nickname[i] = data[i];
            if (field != MON_DATA_NICKNAME10)
            {
                if (POKEMON_NAME_LENGTH >= 11)
                    substruct0->nickname11 = data[10];
                if (POKEMON_NAME_LENGTH >= 12)
                    substruct0->nickname12 = data[11];
            }
            else
            {
                substruct0->nickname11 = EOS;
                substruct0->nickname12 = EOS;
            }
            break;
        }
        case MON_DATA_SPECIES:
        {
            struct PokemonSubstruct0 *substruct0 = GetSubstruct0(boxMon);
            SET16(substruct0->species);
            if (substruct0->species)
                boxMon->hasSpecies = TRUE;
            else
                boxMon->hasSpecies = FALSE;
            break;
        }
        case MON_DATA_HELD_ITEM:
            SET16(GetSubstruct0(boxMon)->heldItem);
            break;
        case MON_DATA_EXP:
            SET32(GetSubstruct0(boxMon)->experience);
            break;
        case MON_DATA_PP_BONUSES:
            SET8(GetSubstruct0(boxMon)->ppBonuses);
            break;
        case MON_DATA_FRIENDSHIP:
            SET8(GetSubstruct0(boxMon)->friendship);
            break;
        case MON_DATA_MOVE1:
            SET16(GetSubstruct1(boxMon)->move1);
            break;
        case MON_DATA_MOVE2:
            SET16(GetSubstruct1(boxMon)->move2);
            break;
        case MON_DATA_MOVE3:
            SET16(GetSubstruct1(boxMon)->move3);
            break;
        case MON_DATA_MOVE4:
            SET16(GetSubstruct1(boxMon)->move4);
            break;
        case MON_DATA_PP1:
            SET8(GetSubstruct1(boxMon)->pp1);
            break;
        case MON_DATA_PP2:
            SET8(GetSubstruct1(boxMon)->pp2);
            break;
        case MON_DATA_PP3:
            SET8(GetSubstruct1(boxMon)->pp3);
            break;
        case MON_DATA_PP4:
            SET8(GetSubstruct1(boxMon)->pp4);
            break;
        case MON_DATA_HP_EV:
            SET8(GetSubstruct2(boxMon)->hpEV);
            break;
        case MON_DATA_ATK_EV:
            SET8(GetSubstruct2(boxMon)->attackEV);
            break;
        case MON_DATA_DEF_EV:
            SET8(GetSubstruct2(boxMon)->defenseEV);
            break;
        case MON_DATA_SPEED_EV:
            SET8(GetSubstruct2(boxMon)->speedEV);
            break;
        case MON_DATA_SPATK_EV:
            SET8(GetSubstruct2(boxMon)->spAttackEV);
            break;
        case MON_DATA_SPDEF_EV:
            SET8(GetSubstruct2(boxMon)->spDefenseEV);
            break;
        case MON_DATA_COOL:
            SET8(GetSubstruct2(boxMon)->cool);
            break;
        case MON_DATA_BEAUTY:
            SET8(GetSubstruct2(boxMon)->beauty);
            break;
        case MON_DATA_CUTE:
            SET8(GetSubstruct2(boxMon)->cute);
            break;
        case MON_DATA_SMART:
            SET8(GetSubstruct2(boxMon)->smart);
            break;
        case MON_DATA_TOUGH:
            SET8(GetSubstruct2(boxMon)->tough);
            break;
        case MON_DATA_SHEEN:
            SET8(GetSubstruct2(boxMon)->sheen);
            break;
        case MON_DATA_POKERUS:
            SET8(GetSubstruct3(boxMon)->pokerus);
            break;
        case MON_DATA_POKERUS_STRAIN:
            GetSubstruct3(boxMon)->pokerus = (*data << 4) | (GetSubstruct3(boxMon)->pokerus & 0x0F);
            break;
        case MON_DATA_POKERUS_DAYS_LEFT:
            GetSubstruct3(boxMon)->pokerus = (GetSubstruct3(boxMon)->pokerus & 0xF0) | *data;
            break;
        case MON_DATA_MET_LOCATION:
            SET8(GetSubstruct3(boxMon)->metLocation);
            break;
        case MON_DATA_MET_LEVEL:
            SET8(GetSubstruct3(boxMon)->metLevel);
            break;
        case MON_DATA_MET_GAME:
            SET8(GetSubstruct3(boxMon)->metGame);
            break;
        case MON_DATA_POKEBALL:
            SET8(GetSubstruct0(boxMon)->pokeball);
            break;
        case MON_DATA_OT_GENDER:
            SET8(GetSubstruct3(boxMon)->otGender);
            break;
        case MON_DATA_HP_IV:
            SET8(GetSubstruct3(boxMon)->hpIV);
            break;
        case MON_DATA_ATK_IV:
            SET8(GetSubstruct3(boxMon)->attackIV);
            break;
        case MON_DATA_DEF_IV:
            SET8(GetSubstruct3(boxMon)->defenseIV);
            break;
        case MON_DATA_SPEED_IV:
            SET8(GetSubstruct3(boxMon)->speedIV);
            break;
        case MON_DATA_SPATK_IV:
            SET8(GetSubstruct3(boxMon)->spAttackIV);
            break;
        case MON_DATA_SPDEF_IV:
            SET8(GetSubstruct3(boxMon)->spDefenseIV);
            break;
        case MON_DATA_IS_EGG:
            SET8(GetSubstruct3(boxMon)->isEgg);
            SET8(boxMon->isEgg);
            break;
        case MON_DATA_ABILITY_NUM:
            SET8(GetSubstruct3(boxMon)->abilityNum);
            break;
        case MON_DATA_COOL_RIBBON:
            SET8(GetSubstruct3(boxMon)->coolRibbon);
            break;
        case MON_DATA_BEAUTY_RIBBON:
            SET8(GetSubstruct3(boxMon)->beautyRibbon);
            break;
        case MON_DATA_CUTE_RIBBON:
            SET8(GetSubstruct3(boxMon)->cuteRibbon);
            break;
        case MON_DATA_SMART_RIBBON:
            SET8(GetSubstruct3(boxMon)->smartRibbon);
            break;
        case MON_DATA_TOUGH_RIBBON:
            SET8(GetSubstruct3(boxMon)->toughRibbon);
            break;
        case MON_DATA_CHAMPION_RIBBON:
            SET8(GetSubstruct3(boxMon)->championRibbon);
            break;
        case MON_DATA_WINNING_RIBBON:
            SET8(GetSubstruct3(boxMon)->winningRibbon);
            break;
        case MON_DATA_VICTORY_RIBBON:
            SET8(GetSubstruct3(boxMon)->victoryRibbon);
            break;
        case MON_DATA_ARTIST_RIBBON:
            SET8(GetSubstruct3(boxMon)->artistRibbon);
            break;
        case MON_DATA_EFFORT_RIBBON:
            SET8(GetSubstruct3(boxMon)->effortRibbon);
            break;
        case MON_DATA_MARINE_RIBBON:
            SET8(GetSubstruct3(boxMon)->marineRibbon);
            break;
        case MON_DATA_LAND_RIBBON:
            SET8(GetSubstruct3(boxMon)->landRibbon);
            break;
        case MON_DATA_SKY_RIBBON:
            SET8(GetSubstruct3(boxMon)->skyRibbon);
            break;
        case MON_DATA_COUNTRY_RIBBON:
            SET8(GetSubstruct3(boxMon)->countryRibbon);
            break;
        case MON_DATA_NATIONAL_RIBBON:
            SET8(GetSubstruct3(boxMon)->nationalRibbon);
            break;
        case MON_DATA_EARTH_RIBBON:
            SET8(GetSubstruct3(boxMon)->earthRibbon);
            break;
        case MON_DATA_WORLD_RIBBON:
            SET8(GetSubstruct3(boxMon)->worldRibbon);
            break;
        case MON_DATA_MODERN_FATEFUL_ENCOUNTER:
            SET8(GetSubstruct3(boxMon)->modernFatefulEncounter);
            break;
        case MON_DATA_IVS:
        {
            u32 ivs;
            struct PokemonSubstruct3 *substruct3 = GetSubstruct3(boxMon);
            SET32(ivs);
            substruct3->hpIV = ivs & MAX_IV_MASK;
            substruct3->attackIV = (ivs >> 5) & MAX_IV_MASK;
            substruct3->defenseIV = (ivs >> 10) & MAX_IV_MASK;
            substruct3->speedIV = (ivs >> 15) & MAX_IV_MASK;
            substruct3->spAttackIV = (ivs >> 20) & MAX_IV_MASK;
            substruct3->spDefenseIV = (ivs >> 25) & MAX_IV_MASK;
            break;
        }
        case MON_DATA_HYPER_TRAINED_HP:
            SET8(GetSubstruct1(boxMon)->hyperTrainedHP);
            break;
        case MON_DATA_HYPER_TRAINED_ATK:
            SET8(GetSubstruct1(boxMon)->hyperTrainedAttack);
            break;
        case MON_DATA_HYPER_TRAINED_DEF:
            SET8(GetSubstruct1(boxMon)->hyperTrainedDefense);
            break;
        case MON_DATA_HYPER_TRAINED_SPEED:
            SET8(GetSubstruct1(boxMon)->hyperTrainedSpeed);
            break;
        case MON_DATA_HYPER_TRAINED_SPATK:
            SET8(GetSubstruct1(boxMon)->hyperTrainedSpAttack);
            break;
        case MON_DATA_HYPER_TRAINED_SPDEF:
            SET8(GetSubstruct1(boxMon)->hyperTrainedSpDefense);
            break;
        case MON_DATA_IS_SHADOW:
            SET8(GetSubstruct3(boxMon)->isShadow);
            break;
        case MON_DATA_DYNAMAX_LEVEL:
            SET8(GetSubstruct3(boxMon)->dynamaxLevel);
            break;
        case MON_DATA_GIGANTAMAX_FACTOR:
            SET8(GetSubstruct3(boxMon)->gigantamaxFactor);
            break;
        case MON_DATA_TERA_TYPE:
            SET8(GetSubstruct0(boxMon)->teraType);
            break;
        case MON_DATA_EVOLUTION_TRACKER:
        {
            union EvolutionTracker evoTracker;
            struct PokemonSubstruct1 *substruct1 = GetSubstruct1(boxMon);
            SET32(evoTracker.combinedValue);
            substruct1->evolutionTracker1 = evoTracker.tracker1;
            substruct1->evolutionTracker2 = evoTracker.tracker2;
            break;
        }
        default:
            break;
        }
    }
    else
    {
        switch (field)
        {
        case MON_DATA_STATUS:
        {
            u32 status;
            SET32(status);
            boxMon->compressedStatus = CompressStatus(status);
            break;
        }
        case MON_DATA_HP_LOST:
            SET16(boxMon->hpLost);
            break;
        case MON_DATA_PERSONALITY:
            SET32(boxMon->personality);
            break;
        case MON_DATA_OT_ID:
            SET32(boxMon->otId);
            break;
        case MON_DATA_LANGUAGE:
            SET8(boxMon->language);
            break;
        case MON_DATA_SANITY_IS_BAD_EGG:
            SET8(boxMon->isBadEgg);
            break;
        case MON_DATA_SANITY_HAS_SPECIES:
            SET8(boxMon->hasSpecies);
            break;
        case MON_DATA_SANITY_IS_EGG:
            SET8(boxMon->isEgg);
            break;
        case MON_DATA_OT_NAME:
        {
            s32 i;
            for (i = 0; i < PLAYER_NAME_LENGTH; i++)
                boxMon->otName[i] = data[i];
            break;
        }
        case MON_DATA_MARKINGS:
            SET8(boxMon->markings);
            break;
        case MON_DATA_CHECKSUM:
            SET16(boxMon->checksum);
            break;
        case MON_DATA_IS_SHINY:
        {
            u32 shinyValue = GET_SHINY_VALUE(boxMon->otId, boxMon->personality);
            bool32 isShiny;
            SET8(isShiny);
            boxMon->shinyModifier = (shinyValue < SHINY_ODDS) ^ isShiny;
            break;
        }
        case MON_DATA_HIDDEN_NATURE:
        {
            u32 nature = GetNatureFromPersonality(boxMon->personality);
            u32 hiddenNature;
            SET8(hiddenNature);
            boxMon->hiddenNatureModifier = nature ^ hiddenNature;
            break;
        }
        case MON_DATA_DAYS_SINCE_FORM_CHANGE:
            SET8(boxMon->daysSinceFormChange);
            break;
        }
    }

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
        boxMon->checksum = CalculateBoxMonChecksumReencrypt(boxMon);
}

void CopyMon(void *dest, void *src, size_t size)
{
    memcpy(dest, src, size);
}

u8 GiveCapturedMonToPlayer(struct Pokemon *mon)
{
    s32 i;

    SetMonData(mon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetMonData(mon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);
    SetMonData(mon, MON_DATA_OT_ID, gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == SPECIES_NONE)
            break;
    }

    if (i >= PARTY_SIZE)
        return CopyMonToPC(mon);

    CopyMon(&gParties[B_TRAINER_PLAYER][i], mon, sizeof(*mon));
    gPartiesCount[B_TRAINER_PLAYER] = i + 1;
    return MON_GIVEN_TO_PARTY;
}

u8 CopyMonToPC(struct Pokemon *mon)
{
    s32 boxNo, boxPos;

    SetPCBoxToSendMon(VarGet(VAR_PC_BOX_TO_SEND_MON));

    boxNo = StorageGetCurrentBox();

    do
    {
        for (boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
        {
            struct BoxPokemon *checkingMon = GetBoxedMonPtr(boxNo, boxPos);
            if (GetBoxMonData(checkingMon, MON_DATA_SPECIES) == SPECIES_NONE)
            {
                MonRestorePP(mon);
                CopyMon(checkingMon, &mon->box, sizeof(mon->box));
                gSpecialVar_MonBoxId = boxNo;
                gSpecialVar_MonBoxPos = boxPos;
                if (GetPCBoxToSendMon() != boxNo)
                    FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
                VarSet(VAR_PC_BOX_TO_SEND_MON, boxNo);
                return MON_GIVEN_TO_PC;
            }
        }

        boxNo++;
        if (boxNo == TOTAL_BOXES_COUNT)
            boxNo = 0;
    } while (boxNo != StorageGetCurrentBox());

    return MON_CANT_GIVE;
}

u8 CalculatePartyCount(enum BattleTrainer trainer)
{
    u32 partyCount = 0;

    while (partyCount < PARTY_SIZE
        && GetMonData(&gParties[trainer][partyCount], MON_DATA_SPECIES) != SPECIES_NONE)
    {
        partyCount++;
    }

    return partyCount;
}

u8 CalculatePartyCountOfSide(enum BattlerId battler)
{
    return CalculatePartyCount(GetBattlerTrainer(battler)) + (BattleSideHasTwoTrainers(battler & BIT_SIDE) ? CalculatePartyCount(GetBattlerTrainer(GetPartnerBattler(battler))) : 0);
}

u8 CalculatePlayerPartyCount(void)
{
    gPartiesCount[B_TRAINER_PLAYER] = CalculatePartyCount(B_TRAINER_PLAYER);
    return gPartiesCount[B_TRAINER_PLAYER];
}

u8 CalculatePartnerPartyCount(void)
{
    gPartiesCount[B_TRAINER_PARTNER] = CalculatePartyCount(B_TRAINER_PARTNER);
    return gPartiesCount[B_TRAINER_PARTNER];
}

u8 CalculateEnemyPartyCount(void)
{
    gPartiesCount[B_TRAINER_OPPONENT_A] = CalculatePartyCount(B_TRAINER_OPPONENT_A);
    gPartiesCount[B_TRAINER_OPPONENT_B] = CalculatePartyCount(B_TRAINER_OPPONENT_B);
    return gPartiesCount[B_TRAINER_OPPONENT_A] + gPartiesCount[B_TRAINER_OPPONENT_B];
}

u8 GetMonsStateToDoubles(void)
{
    s32 aliveCount = 0;
    s32 i;
    CalculatePlayerPartyCount();

    if (OW_DOUBLE_APPROACH_WITH_ONE_MON)
        return PLAYER_HAS_TWO_USABLE_MONS;

    if (gPartiesCount[B_TRAINER_PLAYER] == 1)
        return gPartiesCount[B_TRAINER_PLAYER]; // PLAYER_HAS_ONE_MON

    for (i = 0; i < gPartiesCount[B_TRAINER_PLAYER]; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP) != 0
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE)
            aliveCount++;
    }

    return (aliveCount > 1) ? PLAYER_HAS_TWO_USABLE_MONS : PLAYER_HAS_ONE_USABLE_MON;
}

u8 GetMonsStateToDoubles_2(void)
{
    s32 aliveCount = 0;
    s32 i;

    if (OW_DOUBLE_APPROACH_WITH_ONE_MON
     || FollowerNPCIsBattlePartner())
        return PLAYER_HAS_TWO_USABLE_MONS;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        enum Species species = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_EGG && species != SPECIES_NONE
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP) != 0)
            aliveCount++;
    }

    if (aliveCount == 1)
        return PLAYER_HAS_ONE_MON; // may have more than one, but only one is alive

    return (aliveCount > 1) ? PLAYER_HAS_TWO_USABLE_MONS : PLAYER_HAS_ONE_USABLE_MON;
}

enum Ability GetAbilityBySpecies(enum Species species, u8 abilityNum)
{
    int i;

    if (abilityNum < NUM_ABILITY_SLOTS)
        gLastUsedAbility = GetSpeciesAbility(species, abilityNum);
    else
        gLastUsedAbility = ABILITY_NONE;

    if (abilityNum >= NUM_NORMAL_ABILITY_SLOTS) // if abilityNum is empty hidden ability, look for other hidden abilities
    {
        for (i = NUM_NORMAL_ABILITY_SLOTS; i < NUM_ABILITY_SLOTS && gLastUsedAbility == ABILITY_NONE; i++)
        {
            gLastUsedAbility = GetSpeciesAbility(species, i);
        }
    }

    for (i = 0; i < NUM_ABILITY_SLOTS && gLastUsedAbility == ABILITY_NONE; i++) // look for any non-empty ability
    {
        gLastUsedAbility = GetSpeciesAbility(species, i);
    }

    return gLastUsedAbility;
}

enum Ability GetMonAbility(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u8 abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    return GetAbilityBySpecies(species, abilityNum);
}

void CreateSecretBaseEnemyParty(struct SecretBase *secretBaseRecord)
{
    s32 i, j;

    ZeroEnemyPartyMons();
    *gBattleResources->secretBase = *secretBaseRecord;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBattleResources->secretBase->party.species[i])
        {
            CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][i],
                gBattleResources->secretBase->party.species[i],
                gBattleResources->secretBase->party.levels[i],
                gBattleResources->secretBase->party.personality[i],
                OTID_STRUCT_RANDOM_NO_SHINY,
                15);
            SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gBattleResources->secretBase->party.heldItems[i]);

            for (j = 0; j < NUM_STATS; j++)
                SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HP_EV + j, &gBattleResources->secretBase->party.EVs[i]);

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_MOVE1 + j, &gBattleResources->secretBase->party.moves[i * MAX_MON_MOVES + j]);
                u32 pp = GetMovePP(gBattleResources->secretBase->party.moves[i * MAX_MON_MOVES + j]);
                SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_PP1 + j, &pp);
            }
        }
    }
}

enum TrainerPicID GetSecretBaseTrainerPicIndex(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % NUM_SECRET_BASE_CLASSES];
    return gFacilityClassToPicIndex[facilityClass];
}

enum TrainerClassID GetSecretBaseTrainerClass(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % NUM_SECRET_BASE_CLASSES];
    return gFacilityClassToTrainerClass[facilityClass];
}

bool8 IsPlayerPartyAndPokemonStorageFull(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == SPECIES_NONE)
            return FALSE;

    return IsPokemonStorageFull();
}

bool8 IsPokemonStorageFull(void)
{
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
        for (j = 0; j < IN_BOX_COUNT; j++)
            if (GetBoxMonDataAt(i, j, MON_DATA_SPECIES) == SPECIES_NONE)
                return FALSE;

    return TRUE;
}

const u8 *GetSpeciesName(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].speciesName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].speciesName;
    return gSpeciesInfo[species].speciesName;
}

const u8 *GetSpeciesCategory(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].categoryName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].categoryName;
    return gSpeciesInfo[species].categoryName;
}

const u8 *GetSpeciesPokedexDescription(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].description == NULL)
        return gSpeciesInfo[SPECIES_NONE].description;
    return gSpeciesInfo[species].description;
}

u32 GetSpeciesHeight(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].height;
}

u32 GetSpeciesWeight(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].weight;
}

enum Type GetSpeciesType(enum Species species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].types[slot];
}

enum Ability GetSpeciesAbility(enum Species species, u8 slot)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].abilities[slot];
}

u32 GetSpeciesBaseHP(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseHP;
}

u32 GetSpeciesBaseAttack(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseAttack;
}

u32 GetSpeciesBaseDefense(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseDefense;
}

u32 GetSpeciesBaseSpAttack(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpAttack;
}

u32 GetSpeciesBaseSpDefense(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpDefense;
}

u32 GetSpeciesBaseSpeed(enum Species species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].baseSpeed;
}

u32 GetSpeciesBaseStat(enum Species species, u32 statIndex)
{
    switch (statIndex)
    {
    case STAT_HP:
        return GetSpeciesBaseHP(species);
    case STAT_ATK:
        return GetSpeciesBaseAttack(species);
    case STAT_DEF:
        return GetSpeciesBaseDefense(species);
    case STAT_SPEED:
        return GetSpeciesBaseSpeed(species);
    case STAT_SPATK:
        return GetSpeciesBaseSpAttack(species);
    case STAT_SPDEF:
        return GetSpeciesBaseSpDefense(species);
    }
    return 0;
}

u32 GetSpeciesBaseStatTotal(enum Species species)
{
    u32 total = 0;

    for (u32 i = 0; i < NUM_STATS; i++)
        total += GetSpeciesBaseStat(species, i);

    return total;
}

const struct LevelUpMove *GetSpeciesLevelUpLearnset(enum Species species)
{
    const struct LevelUpMove *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].levelUpLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].levelUpLearnset;
    return learnset;
}

const u16 *GetSpeciesTeachableLearnset(enum Species species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].teachableLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].teachableLearnset;
    return learnset;
}

const u16 *GetSpeciesEggMoves(enum Species species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].eggMoveLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].eggMoveLearnset;
    return learnset;
}

//only used in test assumptions at the moment
bool32 SpeciesHasEggMove(enum Species species, enum Move move)
{
    const u16 *learnset = GetSpeciesEggMoves(species);
    for (u32 i = 0; learnset[i] != MOVE_UNAVAILABLE; i++)
    {
        if (learnset[i] == move)
            return TRUE;
    }
    return FALSE;
}

const struct Evolution *GetSpeciesEvolutions(enum Species species)
{
    const struct Evolution *evolutions = gSpeciesInfo[SanitizeSpeciesId(species)].evolutions;
    if (evolutions == NULL)
        return gSpeciesInfo[SPECIES_NONE].evolutions;
    return evolutions;
}

const u16 *GetSpeciesFormTable(enum Species species)
{
    const u16 *formTable = gSpeciesInfo[SanitizeSpeciesId(species)].formSpeciesIdTable;
    if (formTable == NULL)
        return gSpeciesInfo[SPECIES_NONE].formSpeciesIdTable;
    return formTable;
}

const struct FormChange *GetSpeciesFormChanges(enum Species species)
{
    const struct FormChange *formChanges = gSpeciesInfo[SanitizeSpeciesId(species)].formChangeTable;
    if (formChanges == NULL)
        return gSpeciesInfo[SPECIES_NONE].formChangeTable;
    return formChanges;
}

u8 CalculatePPWithBonus(enum Move move, u8 ppBonuses, u8 moveIndex)
{
    u8 basePP = GetMovePP(move);
    return basePP + ((basePP * 20 * ((gPPUpGetMask[moveIndex] & ppBonuses) >> (2 * moveIndex))) / 100);
}

void RemoveMonPPBonus(struct Pokemon *mon, u8 moveIndex)
{
    RemoveBoxMonPPBonus(&mon->box, moveIndex);
}

void RemoveBoxMonPPBonus(struct BoxPokemon *mon, u8 moveIndex)
{
    u8 ppBonuses = GetBoxMonData(mon, MON_DATA_PP_BONUSES);
    ppBonuses &= gPPUpClearMask[moveIndex];
    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

void RemoveBattleMonPPBonus(struct BattlePokemon *mon, u8 moveIndex)
{
    mon->ppBonuses &= gPPUpClearMask[moveIndex];
}

void PokemonToBattleMon(struct Pokemon *src, struct BattlePokemon *dst)
{
    s32 i;
    u8 nickname[POKEMON_NAME_BUFFER_SIZE];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        dst->moves[i] = GetMonData(src, MON_DATA_MOVE1 + i);
        dst->pp[i] = GetMonData(src, MON_DATA_PP1 + i);
    }

    dst->species = GetMonData(src, MON_DATA_SPECIES);
    dst->item = GetMonData(src, MON_DATA_HELD_ITEM);
    dst->ppBonuses = GetMonData(src, MON_DATA_PP_BONUSES);
    dst->friendship = GetMonData(src, MON_DATA_FRIENDSHIP);
    dst->experience = GetMonData(src, MON_DATA_EXP);
    dst->hpIV = GetMonData(src, MON_DATA_HP_IV);
    dst->attackIV = GetMonData(src, MON_DATA_ATK_IV);
    dst->defenseIV = GetMonData(src, MON_DATA_DEF_IV);
    dst->speedIV = GetMonData(src, MON_DATA_SPEED_IV);
    dst->spAttackIV = GetMonData(src, MON_DATA_SPATK_IV);
    dst->spDefenseIV = GetMonData(src, MON_DATA_SPDEF_IV);
    dst->personality = GetMonData(src, MON_DATA_PERSONALITY);
    dst->status1 = GetMonData(src, MON_DATA_STATUS);
    dst->level = GetMonData(src, MON_DATA_LEVEL);
    dst->hp = GetMonData(src, MON_DATA_HP);
    dst->maxHP = GetMonData(src, MON_DATA_MAX_HP);
    dst->attack = GetMonData(src, MON_DATA_ATK);
    dst->defense = GetMonData(src, MON_DATA_DEF);
    dst->speed = GetMonData(src, MON_DATA_SPEED);
    dst->spAttack = GetMonData(src, MON_DATA_SPATK);
    dst->spDefense = GetMonData(src, MON_DATA_SPDEF);
    dst->abilityNum = GetMonData(src, MON_DATA_ABILITY_NUM);
    dst->otId = GetMonData(src, MON_DATA_OT_ID);
    dst->types[0] = GetSpeciesType(dst->species, 0);
    dst->types[1] = GetSpeciesType(dst->species, 1);
    dst->types[2] = TYPE_MYSTERY;
    dst->isShiny = IsMonShiny(src);
    dst->affectionHearts = GetMonAffectionHearts(src);
    dst->ability = GetAbilityBySpecies(dst->species, dst->abilityNum);
    GetMonData(src, MON_DATA_NICKNAME, nickname);
    StringCopy_Nickname(dst->nickname, nickname);
    GetMonData(src, MON_DATA_OT_NAME, dst->otName);

    for (i = 0; i < NUM_BATTLE_STATS; i++)
        dst->statStages[i] = DEFAULT_STAT_STAGE;

    memset(&dst->volatiles, 0, sizeof(struct Volatiles));
}

bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, enum Item item, u8 partyIndex, u8 moveIndex)
{
    return PokemonUseItemEffects(mon, item, partyIndex, moveIndex, FALSE);
}

#define UPDATE_FRIENDSHIP_FROM_ITEM()                                                                   \
{                                                                                                       \
    if ((!retVal || friendshipOnly) && !ShouldSkipFriendshipChange() && friendshipChange == 0)      \
    {                                                                                                   \
        friendshipChange = itemEffect[itemEffectParam];                                                 \
        friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);                                        \
        friendship += CalculateFriendshipBonuses(mon,friendshipChange,holdEffect);                      \
        if (friendship < 0)                                                                             \
            friendship = 0;                                                                             \
        if (friendship > MAX_FRIENDSHIP)                                                                \
            friendship = MAX_FRIENDSHIP;                                                                \
        SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);                                              \
        retVal = FALSE;                                                                                 \
    }                                                                                                   \
}

// EXP candies store an index for this table in their holdEffectParam.
const u32 sExpCandyExperienceTable[] = {
    [EXP_100 - 1] = 100,
    [EXP_800 - 1] = 800,
    [EXP_3000 - 1] = 3000,
    [EXP_10000 - 1] = 10000,
    [EXP_30000 - 1] = 30000,
};

// Returns TRUE if the item has no effect on the Pokémon, FALSE otherwise
bool8 PokemonUseItemEffects(struct Pokemon *mon, enum Item item, u8 partyIndex, u8 moveIndex, bool8 usedByAI)
{
    u32 dataUnsigned;
    s32 dataSigned, evCap;
    s32 friendship;
    s32 i;
    bool8 retVal = TRUE;
    const u8 *itemEffect;
    u8 itemEffectParam = ITEM_EFFECT_ARG_START;
    u32 temp1, temp2;
    s8 friendshipChange = 0;
    enum HoldEffect holdEffect;
    enum BattlerId battler = MAX_BATTLERS_COUNT;
    bool32 friendshipOnly = FALSE;
    enum Item heldItem;
    u8 effectFlags;
    s8 evChange;
    u16 evCount;
    u8 levelBefore;
    bool8 didLevelUp = FALSE;
    bool8 isLevelUpItem;

    // Determine the EV cap to use
    u32 maxAllowedEVs = !B_EV_ITEMS_CAP ? MAX_TOTAL_EVS : GetCurrentEVCap();

    // Get item hold effect
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    holdEffect = GetItemHoldEffect(heldItem);

    // Skip using the item if it won't do anything
    if (GetItemEffect(item) == NULL && item != ITEM_ENIGMA_BERRY_E_READER)
        return TRUE;

    // Get item effect
    itemEffect = GetItemEffect(item);
    isLevelUpItem = (itemEffect[3] & ITEM3_LEVEL_UP) != 0;
    levelBefore = GetMonData(mon, MON_DATA_LEVEL, NULL);

    // Do item effect
    for (i = 0; i < ITEM_EFFECT_ARG_START; i++)
    {
        switch (i)
        {

        // Handle ITEM0 effects (infatuation, Dire Hit, X Attack). ITEM0_SACRED_ASH is handled in party_menu.c
        // Now handled in item battle scripts.
        case 0:
            break;

        // Handle ITEM1 effects (in-battle stat boosting effects)
        // Now handled in item battle scripts.
        case 1:
            break;
        // Formerly used by the item effects of the X Sp. Atk and the X Accuracy
        case 2:
            break;

        // Handle ITEM3 effects (Guard Spec, Rare Candy, cure status)
        case 3:
            // Rare Candy / EXP Candy
            if ((itemEffect[i] & ITEM3_LEVEL_UP)
             && GetMonData(mon, MON_DATA_LEVEL) != MAX_LEVEL)
            {
                u8 param = GetItemHoldEffectParam(item);
                dataUnsigned = 0;

                if (param == 0) // Rare Candy
                {
                    dataUnsigned = gExperienceTables[gSpeciesInfo[GetMonData(mon, MON_DATA_SPECIES)].growthRate][GetMonData(mon, MON_DATA_LEVEL) + 1];
                }
                else if (param - 1 < ARRAY_COUNT(sExpCandyExperienceTable)) // EXP Candies
                {
                    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
                    dataUnsigned = sExpCandyExperienceTable[param - 1] + GetMonData(mon, MON_DATA_EXP);

                    if (B_RARE_CANDY_CAP && B_EXP_CAP_TYPE == EXP_CAP_HARD)
                    {
                        u32 currentLevelCap = GetCurrentLevelCap();
                        if (dataUnsigned > gExperienceTables[gSpeciesInfo[species].growthRate][currentLevelCap])
                            dataUnsigned = gExperienceTables[gSpeciesInfo[species].growthRate][currentLevelCap];
                    }
                    else if (dataUnsigned > gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL])
                    {
                        dataUnsigned = gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL];
                    }
                }

                if (dataUnsigned != 0) // Failsafe
                {
                    SetMonData(mon, MON_DATA_EXP, &dataUnsigned);
                    CalculateMonStats(mon);
                    if (GetMonData(mon, MON_DATA_LEVEL, NULL) > levelBefore)
                        didLevelUp = TRUE;
                    retVal = FALSE;
                }
            }

            // Cure status
            if ((itemEffect[i] & ITEM3_SLEEP) && HealStatusConditions(mon, STATUS1_SLEEP, battler) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_POISON) && HealStatusConditions(mon, STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER, battler) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_BURN) && HealStatusConditions(mon, STATUS1_BURN, battler) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_FREEZE) && HealStatusConditions(mon, STATUS1_ICY_ANY, battler) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_PARALYSIS) && HealStatusConditions(mon, STATUS1_PARALYSIS, battler) == 0)
                retVal = FALSE;
            break;

        // Handle ITEM4 effects (Change HP/Atk EVs, HP heal, PP heal, PP up, Revive, and evolution stones)
        case 4:
            effectFlags = itemEffect[i];

            // PP Up
            if (effectFlags & ITEM4_PP_UP)
            {
                u32 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
                effectFlags &= ~ITEM4_PP_UP;
                dataUnsigned = (ppBonuses & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                temp1 = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex), ppBonuses, moveIndex);
                if (dataUnsigned <= 2 && temp1 > 4)
                {
                    dataUnsigned = ppBonuses + gPPUpAddValues[moveIndex];
                    SetMonData(mon, MON_DATA_PP_BONUSES, &dataUnsigned);

                    dataUnsigned = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex), dataUnsigned, moveIndex) - temp1;
                    dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex) + dataUnsigned;
                    SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                    retVal = FALSE;
                }
            }
            temp1 = 0;

            // Loop through and try each of the remaining ITEM4 effects
            while (effectFlags != 0)
            {
                if (effectFlags & 1)
                {
                    switch (temp1)
                    {
                    case 0: // ITEM4_EV_HP
                    case 1: // ITEM4_EV_ATK
                        evCount = GetMonEVCount(mon);
                        temp2 = itemEffect[itemEffectParam];
                        dataSigned = GetMonData(mon, sGetMonDataEVConstants[temp1]);
                        evChange = temp2;

                        if (evChange > 0) // Increasing EV (HP or Atk)
                        {
                            // Check if the total EV limit is reached
                            if (evCount >= maxAllowedEVs)
                                return TRUE;

                            // Ensure the increase does not exceed the max EV per stat (252)
                            evCap = (itemEffect[10] & ITEM10_IS_VITAMIN) ? EV_ITEM_RAISE_LIMIT : MAX_PER_STAT_EVS;

                            // Check if the per-stat limit is reached
                            if (dataSigned >= evCap)
                                return TRUE;  // Prevents item use if the per-stat cap is already reached

                            if (dataSigned + evChange > evCap)
                                temp2 = evCap - dataSigned;
                            else
                                temp2 = evChange;

                            // Ensure the total EVs do not exceed the maximum allowed (510)
                            if (evCount + temp2 > maxAllowedEVs)
                                temp2 = maxAllowedEVs - evCount;

                            // Prevent item use if no EVs can be increased
                            if (temp2 == 0)
                                return TRUE;

                            // Apply the EV increase
                            dataSigned += temp2;
                        }
                        else if (evChange < 0) // Decreasing EV (HP or Atk)
                        {
                            if (dataSigned == 0)
                            {
                                // No EVs to lose, but make sure friendship updates anyway
                                friendshipOnly = TRUE;
                                itemEffectParam++;
                                break;
                            }
                            dataSigned += evChange;
                            if (I_BERRY_EV_JUMP == GEN_4 && dataSigned > 100)
                                dataSigned = 100;
                            if (dataSigned < 0)
                                dataSigned = 0;
                        }
                        else // Reset EV (HP or Atk)
                        {
                            if (dataSigned == 0)
                                break;

                            dataSigned = 0;
                        }

                        // Update EVs and stats
                        SetMonData(mon, sGetMonDataEVConstants[temp1], &dataSigned);
                        CalculateMonStats(mon);
                        itemEffectParam++;
                        retVal = FALSE;
                        break;

                    case 2: // ITEM4_HEAL_HP
                    {
                        u32 currentHP = GetMonData(mon, MON_DATA_HP);
                        u32 maxHP = GetMonData(mon, MON_DATA_MAX_HP);
                        if (isLevelUpItem && !didLevelUp && (effectFlags & (ITEM4_REVIVE >> 2)))
                        {
                            itemEffectParam++;
                            break;
                        }
                        // Check use validity.
                        if ((effectFlags & (ITEM4_REVIVE >> 2) && currentHP != 0)
                              || (!(effectFlags & (ITEM4_REVIVE >> 2)) && currentHP == 0))
                        {
                            itemEffectParam++;
                            break;
                        }

                        // Get amount of HP to restore
                        dataUnsigned = itemEffect[itemEffectParam++];
                        switch (dataUnsigned)
                        {
                        case ITEM6_HEAL_HP_FULL:
                            dataUnsigned = maxHP - currentHP;
                            break;
                        case ITEM6_HEAL_HP_HALF:
                            dataUnsigned = maxHP / 2;
                            if (dataUnsigned == 0)
                                dataUnsigned = 1;
                            break;
                        case ITEM6_HEAL_HP_LVL_UP:
                            dataUnsigned = gBattleScripting.levelUpHP;
                            break;
                        case ITEM6_HEAL_HP_QUARTER:
                            dataUnsigned = maxHP / 4;
                            if (dataUnsigned == 0)
                                dataUnsigned = 1;
                            break;
                        }

                        // Only restore HP if not at max health
                        if (maxHP != currentHP)
                        {
                            // Restore HP
                            dataUnsigned = currentHP + dataUnsigned;
                            if (dataUnsigned > maxHP)
                                dataUnsigned = maxHP;
                            SetMonData(mon, MON_DATA_HP, &dataUnsigned);
                            retVal = FALSE;
                        }
                        effectFlags &= ~(ITEM4_REVIVE >> 2);
                        break;
                    }
                    case 3: // ITEM4_HEAL_PP
                        if (!(effectFlags & (ITEM4_HEAL_PP_ONE >> 3)))
                        {
                            // Heal PP for all moves
                            for (temp2 = 0; (signed)(temp2) < (signed)(MAX_MON_MOVES); temp2++)
                            {
                                enum Move move;
                                u32 ppBonus;
                                dataUnsigned = GetMonData(mon, MON_DATA_PP1 + temp2);
                                move = GetMonData(mon, MON_DATA_MOVE1 + temp2);
                                ppBonus = CalculatePPWithBonus(move, GetMonData(mon, MON_DATA_PP_BONUSES), temp2);
                                if (dataUnsigned != ppBonus)
                                {
                                    dataUnsigned += itemEffect[itemEffectParam];
                                    if (dataUnsigned > ppBonus)
                                        dataUnsigned = ppBonus;
                                    SetMonData(mon, MON_DATA_PP1 + temp2, &dataUnsigned);
                                    retVal = FALSE;
                                }
                            }
                            itemEffectParam++;
                        }
                        else
                        {
                            // Heal PP for one move
                            enum Move move;
                            dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex);
                            move = GetMonData(mon, MON_DATA_MOVE1 + moveIndex);
                            u32 ppBonus = CalculatePPWithBonus(move, GetMonData(mon, MON_DATA_PP_BONUSES), moveIndex);
                            if (dataUnsigned != ppBonus)
                            {
                                dataUnsigned += itemEffect[itemEffectParam++];
                                if (dataUnsigned > ppBonus)
                                    dataUnsigned = ppBonus;
                                SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                                retVal = FALSE;
                            }
                        }
                        break;

                    // cases 4-6 are ITEM4_HEAL_PP_ONE, ITEM4_PP_UP, and ITEM4_REVIVE, which
                    // are already handled above by other cases or before the loop

                    case 7: // ITEM4_EVO_STONE
                        {
                            bool32 canStopEvo = TRUE;
                            enum Species targetSpecies = GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, item, NULL, &canStopEvo, CHECK_EVO);

                            if (targetSpecies != SPECIES_NONE)
                            {
                                GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, item, NULL, &canStopEvo, DO_EVO);
                                BeginEvolutionScene(mon, targetSpecies, canStopEvo, partyIndex);
                                return FALSE;
                            }
                        }
                        break;
                    }
                }
                temp1++;
                effectFlags >>= 1;
            }
            break;

        // Handle ITEM5 effects (Change Def/SpDef/SpAtk/Speed EVs, PP Max, and friendship changes)
        case 5:
            effectFlags = itemEffect[i];
            temp1 = 0;

            // Loop through and try each of the ITEM5 effects
            while (effectFlags != 0)
            {
                if (effectFlags & 1)
                {
                    switch (temp1)
                    {
                    case 0: // ITEM5_EV_DEF
                    case 1: // ITEM5_EV_SPEED
                    case 2: // ITEM5_EV_SPDEF
                    case 3: // ITEM5_EV_SPATK
                        evCount = GetMonEVCount(mon);
                        temp2 = itemEffect[itemEffectParam];
                        dataSigned = GetMonData(mon, sGetMonDataEVConstants[temp1 + 2]);
                        evChange = temp2;
                        if (evChange > 0) // Increasing EV
                        {
                            // Check if the total EV limit is reached
                            if (evCount >= maxAllowedEVs)
                                return TRUE;

                            // Ensure the increase does not exceed the max EV per stat (252)
                            evCap = (itemEffect[10] & ITEM10_IS_VITAMIN) ? EV_ITEM_RAISE_LIMIT : MAX_PER_STAT_EVS;

                            // Check if the per-stat limit is reached
                            if (dataSigned >= evCap)
                                return TRUE;  // Prevents item use if the per-stat cap is already reached

                            if (dataSigned + evChange > evCap)
                                temp2 = evCap - dataSigned;
                            else
                                temp2 = evChange;

                            // Ensure the total EVs do not exceed the maximum allowed (510)
                            if (evCount + temp2 > maxAllowedEVs)
                                temp2 = maxAllowedEVs - evCount;

                            // Prevent item use if no EVs can be increased
                            if (temp2 == 0)
                                return TRUE;

                            // Apply the EV increase
                            dataSigned += temp2;
                        }
                        else if (evChange < 0) // Decreasing EV
                        {
                            if (dataSigned == 0)
                            {
                                // No EVs to lose, but make sure friendship updates anyway
                                friendshipOnly = TRUE;
                                itemEffectParam++;
                                break;
                            }
                            dataSigned += evChange;
                            if (I_BERRY_EV_JUMP == GEN_4 && dataSigned > 100)
                                dataSigned = 100;
                            if (dataSigned < 0)
                                dataSigned = 0;
                        }
                        else // Reset EV
                        {
                            if (dataSigned == 0)
                                break;

                            dataSigned = 0;
                        }

                        // Update EVs and stats
                        SetMonData(mon, sGetMonDataEVConstants[temp1 + 2], &dataSigned);
                        CalculateMonStats(mon);
                        retVal = FALSE;
                        itemEffectParam++;
                        break;

                    case 4: // ITEM5_PP_MAX
                    {
                        u32 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
                        dataUnsigned = (ppBonuses & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                        temp2 = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex), ppBonuses, moveIndex);

                        // Check if 3 PP Ups have been applied already, and that the move has a total PP of at least 5 (excludes Sketch)
                        if (dataUnsigned < 3 && temp2 >= 5)
                        {
                            dataUnsigned = ppBonuses;
                            dataUnsigned &= gPPUpClearMask[moveIndex];
                            dataUnsigned += gPPUpAddValues[moveIndex] * 3; // Apply 3 PP Ups (max)

                            SetMonData(mon, MON_DATA_PP_BONUSES, &dataUnsigned);
                            dataUnsigned = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex), dataUnsigned, moveIndex) - temp2;
                            dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex) + dataUnsigned;
                            SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                            retVal = FALSE;
                        }
                        break;
                    }
                    case 5: // ITEM5_FRIENDSHIP_LOW
                        // Changes to friendship are given differently depending on
                        // how much friendship the Pokémon already has.
                        // In general, Pokémon with lower friendship receive more,
                        // and Pokémon with higher friendship receive less.
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP) < 100)
                            UPDATE_FRIENDSHIP_FROM_ITEM();
                        itemEffectParam++;
                        break;

                    case 6: // ITEM5_FRIENDSHIP_MID
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP) >= 100 && GetMonData(mon, MON_DATA_FRIENDSHIP) < 200)
                            UPDATE_FRIENDSHIP_FROM_ITEM();
                        itemEffectParam++;
                        break;

                    case 7: // ITEM5_FRIENDSHIP_HIGH
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP) >= 200)
                            UPDATE_FRIENDSHIP_FROM_ITEM();
                        itemEffectParam++;
                        break;
                    }
                }
                temp1++;
                effectFlags >>= 1;
            }
            break;
        }
    }
    return retVal;
}

bool8 HealStatusConditions(struct Pokemon *mon, u32 healMask, enum BattlerId battler)
{
    u32 status = GetMonData(mon, MON_DATA_STATUS, 0);

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);

    if (status & healMask)
    {
        if (status & STATUS1_PARALYSIS)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PARALYSIS;
        else if (status & STATUS1_POISON || status & STATUS1_TOXIC_POISON)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_POISON;
        else if (status & STATUS1_BURN)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_BURN;
        else if (status & STATUS1_SLEEP)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_SLEEP;
        else if (status & STATUS1_FREEZE)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FREEZE;
        else if (status & STATUS1_FROSTBITE)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FROSTBITE;
        status &= ~healMask;
        SetMonData(mon, MON_DATA_STATUS, &status);
        if (gMain.inBattle && battler != MAX_BATTLERS_COUNT)
        {
            gBattleMons[battler].status1 &= ~healMask;
            if ((healMask & STATUS1_SLEEP))
            {
                struct Pokemon *party = GetBattlerParty(battler);

                for (u32 i = 0; i < PARTY_SIZE; i++)
                {
                    if (&party[i] == mon)
                    {
                        TryDeactivateSleepClause(battler, i);
                        break;
                    }
                }
            }
        }
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

u8 GetItemEffectParamOffset(enum BattlerId battler, enum Item itemId, u8 effectByte, u8 effectBit)
{
    const u8 *temp;
    const u8 *itemEffect;
    u8 offset;
    int i;
    u8 j;
    u8 effectFlags;

    offset = ITEM_EFFECT_ARG_START;

    temp = GetItemEffect(itemId);

    if (temp != NULL && !temp && itemId != ITEM_ENIGMA_BERRY_E_READER)
        return 0;

    if (itemId == ITEM_ENIGMA_BERRY_E_READER)
    {
        temp = gEnigmaBerries[battler].itemEffect;
    }

    itemEffect = temp;

    for (i = 0; i < ITEM_EFFECT_ARG_START; i++)
    {
        switch (i)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            if (i == effectByte)
                return 0;
            break;
        case 4:
            effectFlags = itemEffect[4];
            if (effectFlags & ITEM4_PP_UP)
                effectFlags &= ~(ITEM4_PP_UP);
            j = 0;
            while (effectFlags)
            {
                if (effectFlags & 1)
                {
                    switch (j)
                    {
                    case 2: // ITEM4_HEAL_HP
                        if (effectFlags & (ITEM4_REVIVE >> 2))
                            effectFlags &= ~(ITEM4_REVIVE >> 2);
                        // fallthrough
                    case 0: // ITEM4_EV_HP
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 1: // ITEM4_EV_ATK
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 3: // ITEM4_HEAL_PP
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7: // ITEM4_EVO_STONE
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                effectFlags >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        case 5:
            effectFlags = itemEffect[5];
            j = 0;
            while (effectFlags)
            {
                if (effectFlags & 1)
                {
                    switch (j)
                    {
                    case 0: // ITEM5_EV_DEF
                    case 1: // ITEM5_EV_SPEED
                    case 2: // ITEM5_EV_SPDEF
                    case 3: // ITEM5_EV_SPATK
                    case 4: // ITEM5_PP_MAX
                    case 5: // ITEM5_FRIENDSHIP_LOW
                    case 6: // ITEM5_FRIENDSHIP_MID
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7: // ITEM5_FRIENDSHIP_HIGH
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                effectFlags >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        }
    }

    return offset;
}

u8 GetNature(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_PERSONALITY, 0) % NUM_NATURES;
}

u8 GetNatureFromPersonality(u32 personality)
{
    return personality % NUM_NATURES;
}

enum Species GetGMaxTargetSpecies(enum Species species)
{
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);
    u32 i;
    for (i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_BATTLE_GIGANTAMAX)
            return formChanges[i].targetSpecies;
    }
    return species;
}

bool32 DoesMonMeetAdditionalConditions(struct Pokemon *mon, const struct EvolutionParam *params, struct Pokemon *tradePartner, u32 partyId, bool32 *canStopEvo, enum EvoState evoState)
{
    u32 i, j;
    enum Item heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    u32 gender = GetMonGender(mon);
    u32 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, 0);
    u32 attack = GetMonData(mon, MON_DATA_ATK, 0);
    u32 defense = GetMonData(mon, MON_DATA_DEF, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    u16 upperPersonality = personality >> 16;
    u32 weather = GetCurrentWeather();
    u32 nature = GetNature(mon);
    bool32 removeHoldItem = FALSE;
    enum Item removeBagItem = ITEM_NONE;
    u32 removeBagItemCount = 0;
    u32 evolutionTracker = GetMonData(mon, MON_DATA_EVOLUTION_TRACKER, 0);
    enum Species partnerSpecies;
    enum Item partnerHeldItem;
    enum HoldEffect partnerHoldEffect;

    if (tradePartner != NULL)
    {
        partnerSpecies = GetMonData(tradePartner, MON_DATA_SPECIES, 0);
        partnerHeldItem = GetMonData(tradePartner, MON_DATA_HELD_ITEM, 0);
        partnerHoldEffect = GetItemHoldEffect(partnerHeldItem);
    }
    else
    {
        partnerSpecies = SPECIES_NONE;
        partnerHeldItem = ITEM_NONE;
        partnerHoldEffect = HOLD_EFFECT_NONE;
    }

    // Check for additional conditions (only if the primary method passes). Skips if there's no additional conditions.
    for (i = 0; params != NULL && params[i].condition != CONDITIONS_END; i++)
    {
        enum EvolutionConditions condition = params[i].condition;
        bool32 currentCondition = FALSE;

        switch (condition)
        {
        // Gen 2
        case IF_GENDER:
            if (gender == params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_MIN_FRIENDSHIP:
            if (friendship >= params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_ATK_GT_DEF:
            if (attack > defense)
                currentCondition = TRUE;
            break;
        case IF_ATK_EQ_DEF:
            if (attack == defense)
                currentCondition = TRUE;
            break;
        case IF_ATK_LT_DEF:
            if (attack < defense)
                currentCondition = TRUE;
            break;
        case IF_TIME:
            if (GetTimeOfDay() == params[i].arg1)
                currentCondition = TRUE;

            break;
        case IF_NOT_TIME:
            if (GetTimeOfDay() != params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_HOLD_ITEM:
            if (heldItem == params[i].arg1)
            {
                currentCondition = TRUE;
                removeHoldItem = TRUE;
            }
            break;
        // Gen 3
        case IF_PID_UPPER_MODULO_10_GT:
            if ((upperPersonality % 10) > params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_UPPER_MODULO_10_EQ:
            if ((upperPersonality % 10) == params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_UPPER_MODULO_10_LT:
            if ((upperPersonality % 10) < params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_MIN_BEAUTY:
        {
            u32 beauty = GetMonData(mon, MON_DATA_BEAUTY, 0);
            if (beauty >= params[i].arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_COOLNESS:
        {
            u32 coolness = GetMonData(mon, MON_DATA_COOL, 0);
            if (coolness >= params[i].arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_SMARTNESS:
        // remember that even though it's called "Smart/Smartness" here,
        // from gen 6 and up it's known as "Clever/Cleverness."
        {
            u32 smartness = GetMonData(mon, MON_DATA_SMART, 0);
            if (smartness >= params[i].arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_TOUGHNESS:
        {
            u32 toughness = GetMonData(mon, MON_DATA_TOUGH, 0);
            if (toughness >= params[i].arg1)
                currentCondition = TRUE;
            break;
        }
        case IF_MIN_CUTENESS:
        {
            u32 cuteness = GetMonData(mon, MON_DATA_CUTE, 0);
            if (cuteness >= params[i].arg1)
                currentCondition = TRUE;
            break;
        }
        // Gen 4
        case IF_SPECIES_IN_PARTY:
            for (j = 0; j < PARTY_SIZE; j++)
            {
                if (GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SPECIES) == params[i].arg1)
                {
                    currentCondition = TRUE;
                    break;
                }
            }
            break;
        case IF_IN_MAP:
            if (params[i].arg1 == ((gSaveBlock1Ptr->location.mapGroup) << 8 | gSaveBlock1Ptr->location.mapNum))
                currentCondition = TRUE;
            break;
        case IF_IN_MAPSEC:
            if (gMapHeader.regionMapSectionId == params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_KNOWS_MOVE:
            if (MonKnowsMove(mon, params[i].arg1))
                currentCondition = TRUE;
            break;
        // Gen 5
        case IF_TRADE_PARTNER_SPECIES:
            if (params[i].arg1 == partnerSpecies && partnerHoldEffect != HOLD_EFFECT_PREVENT_EVOLVE)
                currentCondition = TRUE;
            break;
        // Gen 6
        case IF_TYPE_IN_PARTY:
            for (j = 0; j < PARTY_SIZE; j++)
            {
                enum Species currSpecies = GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SPECIES);
                if (GetSpeciesType(currSpecies, 0) == params[i].arg1
                 || GetSpeciesType(currSpecies, 1) == params[i].arg1)
                {
                    currentCondition = TRUE;
                    break;
                }
            }
            break;
        case IF_WEATHER:
            if (params[i].arg1 == WEATHER_RAIN)
            {
                if (weather == WEATHER_RAIN || weather == WEATHER_RAIN_THUNDERSTORM || weather == WEATHER_DOWNPOUR)
                    currentCondition = TRUE;
            }
            else if (params[i].arg1 == WEATHER_FOG)
            {
                if (weather == WEATHER_FOG_DIAGONAL || weather == WEATHER_FOG_HORIZONTAL)
                    currentCondition = TRUE;
            }
            else if (weather == params[i].arg1)
            {
                currentCondition = TRUE;
            }
            break;
        case IF_KNOWS_MOVE_TYPE:
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (GetMoveType(GetMonData(mon, MON_DATA_MOVE1 + j)) == params[i].arg1)
                {
                    currentCondition = TRUE;
                    break;
                }
            }
            break;
        // Gen 8
        case IF_NATURE:
            if (nature == params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_AMPED_NATURE:
            switch (nature)
            {
            case NATURE_HARDY:
            case NATURE_BRAVE:
            case NATURE_ADAMANT:
            case NATURE_NAUGHTY:
            case NATURE_DOCILE:
            case NATURE_IMPISH:
            case NATURE_LAX:
            case NATURE_HASTY:
            case NATURE_JOLLY:
            case NATURE_NAIVE:
            case NATURE_RASH:
            case NATURE_SASSY:
            case NATURE_QUIRKY:
                currentCondition = TRUE;
                break;
            }
            break;
        case IF_LOW_KEY_NATURE:
            switch (nature)
            {
            case NATURE_LONELY:
            case NATURE_BOLD:
            case NATURE_RELAXED:
            case NATURE_TIMID:
            case NATURE_SERIOUS:
            case NATURE_MODEST:
            case NATURE_MILD:
            case NATURE_QUIET:
            case NATURE_BASHFUL:
            case NATURE_CALM:
            case NATURE_GENTLE:
            case NATURE_CAREFUL:
                currentCondition = TRUE;
                break;
            }
            break;
        case IF_RECOIL_DAMAGE_GE:
            if (evolutionTracker >= params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_CURRENT_DAMAGE_GE:
        {
            u32 currentHp = GetMonData(mon, MON_DATA_HP);
            if (currentHp != 0 && (GetMonData(mon, MON_DATA_MAX_HP) - currentHp >= params[i].arg1))
                currentCondition = TRUE;
            break;
        }
        case IF_CRITICAL_HITS_GE:
            if (partyId != PARTY_SIZE && gPartyCriticalHits[partyId] >= params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_USED_MOVE_X_TIMES:
            if (evolutionTracker >= params[i].arg2)
                currentCondition = TRUE;
            break;
        // Gen 9
        case IF_DEFEAT_X_WITH_ITEMS:
            if (evolutionTracker >= params[i].arg3)
                currentCondition = TRUE;
            break;
        case IF_PID_MODULO_100_GT:
            if ((personality % 100) > params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_MODULO_100_EQ:
            if ((personality % 100) == params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_PID_MODULO_100_LT:
            if ((personality % 100) < params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_MIN_OVERWORLD_STEPS:
            if (mon == GetFirstLiveMon() && gFollowerSteps >= params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_BAG_ITEM_COUNT:
            if (CheckBagHasItem(params[i].arg1, params[i].arg2))
            {
                currentCondition = TRUE;
                removeBagItem = params[i].arg1;
                removeBagItemCount = params[i].arg2;
                if (canStopEvo != NULL)
                    *canStopEvo = FALSE;
            }
            break;
        case IF_REGION:
            if (GetCurrentRegion() == params[i].arg1)
                currentCondition = TRUE;
            break;
        case IF_NOT_REGION:
            if (GetCurrentRegion() != params[i].arg1)
                currentCondition = TRUE;
            break;
        case CONDITIONS_END:
            break;
        }

        // check if an evolution is about to happen and items should be removed
        if (evoState == DO_EVO)
        {
            if (removeHoldItem)
            {
                enum Item heldItem = ITEM_NONE;
                SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
            }

            if (removeBagItem != ITEM_NONE)
                RemoveBagItem(removeBagItem, removeBagItemCount);
        }

        if (currentCondition == FALSE)
            return FALSE;
    }

    return TRUE;
}

enum Species GetEvolutionTargetSpecies(struct Pokemon *mon, enum EvolutionMode mode, enum Item evolutionItem, struct Pokemon *tradePartner, bool32 *canStopEvo, enum EvoState evoState)
{
    int i;
    enum Species targetSpecies = SPECIES_NONE;
    enum Species species = GetMonData(mon, MON_DATA_SPECIES, 0);
    enum Item heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
    u32 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    enum HoldEffect holdEffect;
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions == NULL)
        return SPECIES_NONE;

    holdEffect = GetItemHoldEffect(heldItem);

    // Prevent evolution with Everstone, unless we're just viewing the party menu with an evolution item
    if (holdEffect == HOLD_EFFECT_PREVENT_EVOLVE
        && mode != EVO_MODE_ITEM_CHECK
        && (P_KADABRA_EVERSTONE < GEN_4 || species != SPECIES_KADABRA))
        return SPECIES_NONE;

    switch (mode)
    {
    case EVO_MODE_NORMAL:
    case EVO_MODE_BATTLE_ONLY:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            bool32 conditionsMet = FALSE;
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            // Check main primary evolution method
            switch (evolutions[i].method)
            {
            case EVO_LEVEL:
                if (evolutions[i].param <= level)
                    conditionsMet = TRUE;
                break;
            case EVO_LEVEL_BATTLE_ONLY:
                if (mode == EVO_MODE_BATTLE_ONLY && evolutions[i].param <= level)
                    conditionsMet = TRUE;
                break;
            }

            if (conditionsMet && DoesMonMeetAdditionalConditions(mon, evolutions[i].params, NULL, PARTY_SIZE, canStopEvo, evoState))
            {
                // All checks passed, so stop checking the rest of the evolutions.
                // This is different from vanilla where the loop continues.
                // If you have overlapping evolutions, put the ones you want to happen first on top of the list.
                targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    case EVO_MODE_TRADE:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            bool32 conditionsMet = FALSE;
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_TRADE:
                conditionsMet = TRUE;
                break;
            }

            if (conditionsMet && DoesMonMeetAdditionalConditions(mon, evolutions[i].params, tradePartner, PARTY_SIZE, canStopEvo, evoState))
            {
                // All checks passed, so stop checking the rest of the evolutions.
                // This is different from vanilla where the loop continues.
                // If you have overlapping evolutions, put the ones you want to happen first on top of the list.
                targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    case EVO_MODE_ITEM_USE:
    case EVO_MODE_ITEM_CHECK:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            bool32 conditionsMet = FALSE;
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_ITEM:
                if (evolutions[i].param == evolutionItem)
                    conditionsMet = TRUE;
                break;
            }

            if (conditionsMet && DoesMonMeetAdditionalConditions(mon, evolutions[i].params, NULL, PARTY_SIZE, canStopEvo, evoState))
            {
                // All checks passed, so stop checking the rest of the evolutions.
                // This is different from vanilla where the loop continues.
                // If you have overlapping evolutions, put the ones you want to happen first on top of the list.
                targetSpecies = evolutions[i].targetSpecies;
                if (canStopEvo != NULL)
                    *canStopEvo = FALSE;
                break;
            }
        }
        break;
    // Battle evolution without leveling; party slot is being passed into the evolutionItem arg.
    case EVO_MODE_BATTLE_SPECIAL:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            bool32 conditionsMet = FALSE;
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_BATTLE_END:
                conditionsMet = TRUE;
                break;
            }

            if (conditionsMet && DoesMonMeetAdditionalConditions(mon, evolutions[i].params, NULL, evolutionItem, canStopEvo, evoState))
            {
                // All checks passed, so stop checking the rest of the evolutions.
                // This is different from vanilla where the loop continues.
                // If you have overlapping evolutions, put the ones you want to happen first on top of the list.
                targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    // Overworld evolution without leveling; evolution method is being passed into the evolutionItem arg.
    case EVO_MODE_OVERWORLD_SPECIAL:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            bool32 conditionsMet = FALSE;
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_SPIN:
                if (gSpecialVar_0x8000 == evolutions[i].param)
                    conditionsMet = TRUE;
                break;
            }

            if (conditionsMet && DoesMonMeetAdditionalConditions(mon, evolutions[i].params, NULL, PARTY_SIZE, canStopEvo, evoState))
            {
                // All checks passed, so stop checking the rest of the evolutions.
                // This is different from vanilla where the loop continues.
                // If you have overlapping evolutions, put the ones you want to happen first on top of the list.
                targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    case EVO_MODE_SCRIPT_TRIGGER:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;
            if (evolutions[i].method != EVO_SCRIPT_TRIGGER)
                continue;
            if (evolutions[i].param != evolutionItem)
                continue;
            if (DoesMonMeetAdditionalConditions(mon, evolutions[i].params, NULL, PARTY_SIZE, canStopEvo, evoState))
            {
                // All checks passed, so stop checking the rest of the evolutions.
                // This is different from vanilla where the loop continues.
                // If you have overlapping evolutions, put the ones you want to happen first on top of the list.
                targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    }

    // Pikachu, Meowth, Eevee and Duraludon cannot evolve if they have the
    // Gigantamax Factor. We assume that is because their evolutions
    // do not have a Gigantamax Form.
    if (GetMonData(mon, MON_DATA_GIGANTAMAX_FACTOR)
     && GetGMaxTargetSpecies(species) != species
     && GetGMaxTargetSpecies(targetSpecies) == targetSpecies)
    {
        return SPECIES_NONE;
    }

    return targetSpecies;
}

bool8 IsMonPastEvolutionLevel(struct Pokemon *mon)
{
    int i;
    enum Species species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions == NULL)
        return FALSE;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
            continue;

        switch (evolutions[i].method)
        {
        case EVO_LEVEL:
            if (evolutions[i].param <= level)
                return TRUE;
            break;
        }
    }

    return FALSE;
}

enum Species NationalPokedexNumToSpecies(enum NationalDexOrder nationalNum)
{
    enum Species species;

    if (!nationalNum)
        return SPECIES_NONE;

    species = 1;

    while (species < (NUM_SPECIES) && gSpeciesInfo[species].natDexNum != nationalNum)
        species++;

    if (species == NUM_SPECIES)
        return SPECIES_NONE;

    return GET_BASE_SPECIES_ID(species);
}

u32 NationalToRegionalOrder(enum NationalDexOrder nationalNum)
{
    if (IS_FRLG)
        return NationalToKantoOrder(nationalNum);
    return NationalToHoennOrder(nationalNum);
}

enum KantoDexOrder NationalToKantoOrder(enum NationalDexOrder nationalNum)
{
    u16 kantoNum;

    if (!nationalNum)
        return 0;

    kantoNum = 0;

    while (kantoNum < KANTO_DEX_COUNT && sKantoToNationalOrder[kantoNum] != nationalNum)
        kantoNum++;

    if (kantoNum >= KANTO_DEX_COUNT)
        return 0;

    return kantoNum + 1;
}

enum HoennDexOrder NationalToHoennOrder(enum NationalDexOrder nationalNum)
{
    u16 hoennNum;

    if (!nationalNum)
        return 0;

    hoennNum = 0;

    while (hoennNum < (HOENN_DEX_COUNT - 1) && sHoennToNationalOrder[hoennNum] != nationalNum)
        hoennNum++;

    if (hoennNum >= HOENN_DEX_COUNT - 1)
        return 0;

    return hoennNum + 1;
}

enum NationalDexOrder SpeciesToNationalPokedexNum(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (!species)
        return NATIONAL_DEX_NONE;

    return gSpeciesInfo[species].natDexNum;
}

u32 SpeciesToRegionalPokedexNum(enum Species species)
{
    if (IS_FRLG)
        return SpeciesToKantoPokedexNum(species);
    return SpeciesToHoennPokedexNum(species);
}

enum KantoDexOrder SpeciesToKantoPokedexNum(enum Species species)
{
    if (!species)
        return 0;
    return NationalToKantoOrder(gSpeciesInfo[species].natDexNum);
}

enum HoennDexOrder SpeciesToHoennPokedexNum(enum Species species)
{
    if (!species)
        return 0;
    return NationalToHoennOrder(gSpeciesInfo[species].natDexNum);
}

enum NationalDexOrder RegionalToNationalOrder(u32 regionalNum)
{
    if (IS_FRLG)
        return KantoToNationalOrder(regionalNum);
    return HoennToNationalOrder(regionalNum);
}

enum NationalDexOrder KantoToNationalOrder(enum KantoDexOrder kantoNum)
{
    if (!kantoNum || kantoNum >= (KANTO_DEX_COUNT + 1))
        return 0;

    return sKantoToNationalOrder[kantoNum - 1];
}

enum NationalDexOrder HoennToNationalOrder(enum HoennDexOrder hoennNum)
{
    if (!hoennNum || hoennNum >= HOENN_DEX_COUNT)
        return 0;

    return sHoennToNationalOrder[hoennNum - 1];
}

void EvolutionRenameMon(struct Pokemon *mon, enum Species oldSpecies, enum Species newSpecies)
{
    u8 language;
    GetMonData(mon, MON_DATA_NICKNAME, gStringVar1);
    language = GetMonData(mon, MON_DATA_LANGUAGE, &language);
    if (language == GAME_LANGUAGE && !StringCompare(GetSpeciesName(oldSpecies), gStringVar1))
        SetMonData(mon, MON_DATA_NICKNAME, GetSpeciesName(newSpecies));
}

// The below two functions determine which side of a multi battle the trainer battles on
// 0 is the left (top in  party menu), 1 is right (bottom in party menu)
u8 GetPlayerFlankId(void)
{
    u8 flankId = 0;
    switch (gLinkPlayers[GetMultiplayerId()].id)
    {
    case 0:
    case 1:
        flankId = 0;
        break;
    case 2:
    case 3:
        flankId = 1;
        break;
    }
    return flankId;
}

u16 GetLinkTrainerFlankId(u8 linkPlayerId)
{
    u16 flankId = 0;
    switch (gLinkPlayers[linkPlayerId].id)
    {
    case 0:
    case 1:
        flankId = 0;
        break;
    case 2:
    case 3:
        flankId = 1;
        break;
    }
    return flankId;
}

s32 GetBattlerMultiplayerId(u16 id)
{
    s32 multiplayerId;
    for (multiplayerId = 0; multiplayerId < MAX_LINK_PLAYERS; multiplayerId++)
        if (gLinkPlayers[multiplayerId].id == id)
            break;
    return multiplayerId;
}

u8 GetTrainerEncounterMusicId(u16 trainerOpponentId)
{
    u32 sanitizedTrainerId = SanitizeTrainerId(trainerOpponentId);
    enum DifficultyLevel difficulty = GetTrainerDifficultyLevel(sanitizedTrainerId);

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        return GetTrainerEncounterMusicIdInBattlePyramid(trainerOpponentId);
    else if (InTrainerHillChallenge())
        return GetTrainerEncounterMusicIdInTrainerHill(trainerOpponentId);
    else
        return gTrainers[difficulty][sanitizedTrainerId].encounterMusic;
}

u16 ModifyStatByNature(u8 nature, u16 stat, enum Stat statIndex)
{
    // Don't modify HP, Accuracy, or Evasion by nature
    if (statIndex <= STAT_HP || statIndex > NUM_NATURE_STATS || gNaturesInfo[nature].statUp == gNaturesInfo[nature].statDown)
        return stat;
    else if (statIndex == gNaturesInfo[nature].statUp)
        return stat * 110 / 100;
    else if (statIndex == gNaturesInfo[nature].statDown)
        return stat * 90 / 100;
    else
        return stat;
}

void AdjustFriendship(struct Pokemon *mon, u8 event)
{
    enum Species species;
    enum Item heldItem;
    enum HoldEffect holdEffect;
    s8 mod;

    if (ShouldSkipFriendshipChange())
        return;

    species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0);
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
    holdEffect = GetItemHoldEffect(heldItem);

    if (species && species != SPECIES_EGG)
    {
        u8 friendshipLevel = 0;
        s32 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, 0);

        if (friendship > 99)
            friendshipLevel++;
        if (friendship > 199)
            friendshipLevel++;

        if (event == FRIENDSHIP_EVENT_WALKING)
        {
            // 50% chance every 128 steps
            if (Random() & 1)
                return;
        }
        if (event == FRIENDSHIP_EVENT_LEAGUE_BATTLE)
        {
            // Only if it's a trainer battle with league progression significance
            if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
                return;

            if (IsSpecialTrainer(TRAINER_BATTLE_PARAM.opponentA))
                return;

            enum TrainerClassID opponentTrainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);
            if (!(opponentTrainerClass == TRAINER_CLASS_LEADER
                || opponentTrainerClass == TRAINER_CLASS_ELITE_FOUR
                || opponentTrainerClass == TRAINER_CLASS_CHAMPION))
                return;
        }

        mod = sFriendshipEventModifiers[event][friendshipLevel];
        friendship += CalculateFriendshipBonuses(mon,mod,holdEffect);

        if (friendship < 0)
            friendship = 0;
        if (friendship > MAX_FRIENDSHIP)
            friendship = MAX_FRIENDSHIP;

        SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
    }
}

s32 CalculateFriendshipBonuses(struct Pokemon *mon, s32 modifier, enum HoldEffect itemHoldEffect)
{
    s32 bonus = 0;

    if ((modifier > 0) && (itemHoldEffect == HOLD_EFFECT_FRIENDSHIP_UP))
        bonus += 150 * modifier / 100;
    else
        bonus += modifier;

    if (modifier == 0)
        return bonus;

    if (GetMonData(mon, MON_DATA_POKEBALL) == BALL_LUXURY)
        bonus += ITEM_FRIENDSHIP_LUXURY_BONUS;

    if (GetMonData(mon, MON_DATA_MET_LOCATION) == GetCurrentRegionMapSectionId())
        bonus += ITEM_FRIENDSHIP_MAPSEC_BONUS;

    return bonus;
}

void MonGainEVs(struct Pokemon *mon, enum Species defeatedSpecies)
{
    u8 evs[NUM_STATS];
    u16 evIncrease = 0;
    u16 totalEVs = 0;
    enum Item heldItem;
    enum HoldEffect holdEffect;
    enum Stat i;
    int multiplier;
    u8 stat;
    u8 bonus;
    u32 currentEVCap = GetCurrentEVCap();

    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
    holdEffect = GetItemHoldEffect(heldItem);

    stat = GetItemSecondaryId(heldItem);
    bonus = GetItemHoldEffectParam(heldItem);

    for (i = 0; i < NUM_STATS; i++)
    {
        evs[i] = GetMonData(mon, MON_DATA_HP_EV + i, 0);
        totalEVs += evs[i];
    }

    for (i = 0; i < NUM_STATS; i++)
    {
        if (totalEVs >= currentEVCap)
            break;

        if (CheckMonHasHadPokerus(mon))
            multiplier = 2;
        else
            multiplier = 1;

        switch (i)
        {
        case STAT_HP:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_HP)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_HP + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_HP * multiplier;
            break;
        case STAT_ATK:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_ATK)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_Attack + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_Attack * multiplier;
            break;
        case STAT_DEF:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_DEF)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_Defense + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_Defense * multiplier;
            break;
        case STAT_SPEED:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_SPEED)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_Speed + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_Speed * multiplier;
            break;
        case STAT_SPATK:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_SPATK)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_SpAttack + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_SpAttack * multiplier;
            break;
        case STAT_SPDEF:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_SPDEF)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_SpDefense + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_SpDefense * multiplier;
            break;
        default:
            break;
        }

        if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
            evIncrease *= 2;

        if (totalEVs + (s16)evIncrease > currentEVCap)
            evIncrease = ((s16)evIncrease + currentEVCap) - (totalEVs + evIncrease);

        if (evs[i] + (s16)evIncrease > MAX_PER_STAT_EVS)
        {
            int val1 = (s16)evIncrease + MAX_PER_STAT_EVS;
            int val2 = evs[i] + evIncrease;
            evIncrease = val1 - val2;
        }

        evs[i] += evIncrease;
        totalEVs += evIncrease;
        SetMonData(mon, MON_DATA_HP_EV + i, &evs[i]);
    }
}

u16 GetMonEVCount(struct Pokemon *mon)
{
    int i;
    u16 count = 0;

    for (i = 0; i < NUM_STATS; i++)
        count += GetMonData(mon, MON_DATA_HP_EV + i, 0);

    return count;
}

bool8 TryIncrementMonLevel(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 nextLevel = GetMonData(mon, MON_DATA_LEVEL, 0) + 1;
    u32 expPoints = GetMonData(mon, MON_DATA_EXP, 0);
    if (expPoints > gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL])
    {
        expPoints = gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL];
        SetMonData(mon, MON_DATA_EXP, &expPoints);
    }
    if (nextLevel > GetCurrentLevelCap() || expPoints < gExperienceTables[gSpeciesInfo[species].growthRate][nextLevel])
    {
        return FALSE;
    }
    else
    {
        SetMonData(mon, MON_DATA_LEVEL, &nextLevel);
        return TRUE;
    }
}

bool32 CanLearnTeachableMove(enum Species species, enum Move move)
{
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);
    if (species == SPECIES_EGG)
        return FALSE;
    for (u32 i = 0; teachableLearnset[i] != MOVE_UNAVAILABLE; i++)
    {
        if (teachableLearnset[i] == move)
            return TRUE;
    }
    return FALSE;
}

u16 SpeciesToPokedexNum(enum Species species)
{
    if (IsNationalPokedexEnabled())
    {
        return SpeciesToNationalPokedexNum(species);
    }
    else
    {
        species = SpeciesToRegionalPokedexNum(species);
        if (species <= REGIONAL_DEX_COUNT)
            return species;
        return 0xFFFF;
    }
}

bool32 IsSpeciesInRegionalDex(enum Species species)
{
    if (IS_FRLG)
        return IsSpeciesInKantoDex(species);
    return IsSpeciesInHoennDex(species);
}

bool32 IsSpeciesInKantoDex(enum Species species)
{
    if (SpeciesToKantoPokedexNum(species) > KANTO_DEX_COUNT)
        return FALSE;
    else
        return TRUE;
}

bool32 IsSpeciesInHoennDex(enum Species species)
{
    if (SpeciesToHoennPokedexNum(species) > HOENN_DEX_COUNT)
        return FALSE;
    else
        return TRUE;
}

u16 GetBattleBGM(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
    {
        switch (GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES))
        {
        case SPECIES_RAYQUAZA:
            return MUS_VS_RAYQUAZA;
        case SPECIES_KYOGRE:
        case SPECIES_GROUDON:
            return MUS_VS_KYOGRE_GROUDON;
        case SPECIES_REGIROCK:
        case SPECIES_REGICE:
        case SPECIES_REGISTEEL:
        case SPECIES_REGIGIGAS:
        case SPECIES_REGIELEKI:
        case SPECIES_REGIDRAGO:
            return MUS_VS_REGI;
        default:
            return MUS_RG_VS_LEGEND;
        }
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        return MUS_VS_TRAINER;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        enum TrainerClassID trainerClass;

        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
            trainerClass = GetFrontierOpponentClass(TRAINER_BATTLE_PARAM.opponentA);
        else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
            trainerClass = TRAINER_CLASS_EXPERT;
        else
            trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);

        switch (trainerClass)
        {
        case TRAINER_CLASS_AQUA_LEADER:
        case TRAINER_CLASS_MAGMA_LEADER:
            return MUS_VS_AQUA_MAGMA_LEADER;
        case TRAINER_CLASS_TEAM_AQUA:
        case TRAINER_CLASS_TEAM_MAGMA:
        case TRAINER_CLASS_AQUA_ADMIN:
        case TRAINER_CLASS_MAGMA_ADMIN:
            return MUS_VS_AQUA_MAGMA;
        case TRAINER_CLASS_LEADER:
            return MUS_VS_GYM_LEADER;
        case TRAINER_CLASS_CHAMPION:
            return MUS_VS_CHAMPION;
        case TRAINER_CLASS_RIVAL:
            if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                return MUS_VS_RIVAL;
            if (!StringCompare(GetTrainerNameFromId(TRAINER_BATTLE_PARAM.opponentA), gText_BattleWallyName))
                return MUS_VS_TRAINER;
            return MUS_VS_RIVAL;
        case TRAINER_CLASS_ELITE_FOUR:
            return MUS_VS_ELITE_FOUR;
        case TRAINER_CLASS_CHAMPION_FRLG:
            return MUS_RG_VS_CHAMPION;
        case TRAINER_CLASS_LEADER_FRLG:
        case TRAINER_CLASS_ELITE_FOUR_FRLG:
            return MUS_RG_VS_GYM_LEADER;
        case TRAINER_CLASS_SALON_MAIDEN:
        case TRAINER_CLASS_DOME_ACE:
        case TRAINER_CLASS_PALACE_MAVEN:
        case TRAINER_CLASS_ARENA_TYCOON:
        case TRAINER_CLASS_FACTORY_HEAD:
        case TRAINER_CLASS_PIKE_QUEEN:
        case TRAINER_CLASS_PYRAMID_KING:
            return MUS_VS_FRONTIER_BRAIN;
        default:
            if (GetCurrentRegion() == REGION_KANTO)
                return MUS_RG_VS_TRAINER;
            else
                return MUS_VS_TRAINER;
        }
    }
    else
    {
        if (GetCurrentRegion() == REGION_KANTO)
            return MUS_RG_VS_WILD;
        else
            return MUS_VS_WILD;
    }
}

void PlayBattleBGM(void)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    PlayBGM(GetBattleBGM());
}

void PlayMapChosenOrBattleBGM(u16 songId)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    if (songId)
        PlayNewMapMusic(songId);
    else
        PlayNewMapMusic(GetBattleBGM());
}

// Identical to PlayMapChosenOrBattleBGM, but uses a task instead
// Only used by Battle Dome
#define tSongId data[0]
void CreateTask_PlayMapChosenOrBattleBGM(u16 songId)
{
    u8 taskId;

    ResetMapMusic();
    m4aMPlayAllStop();

    taskId = CreateTask(Task_PlayMapChosenOrBattleBGM, 0);
    gTasks[taskId].tSongId = songId;
}

static void Task_PlayMapChosenOrBattleBGM(u8 taskId)
{
    if (gTasks[taskId].tSongId)
        PlayNewMapMusic(gTasks[taskId].tSongId);
    else
        PlayNewMapMusic(GetBattleBGM());
    DestroyTask(taskId);
}

#undef tSongId

const u16 *GetMonFrontSpritePal(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    bool32 isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    bool32 isEgg = GetMonData(mon, MON_DATA_IS_EGG);
    return GetMonSpritePalFromSpeciesAndPersonalityIsEgg(species, isShiny, personality, isEgg);
}

const u16 *GetMonSpritePalFromSpeciesAndPersonality(enum Species species, bool32 isShiny, u32 personality)
{
    return GetMonSpritePalFromSpeciesIsEgg(species, isShiny, IsPersonalityFemale(species, personality), FALSE);
}

const u16 *GetMonSpritePalFromSpeciesAndPersonalityIsEgg(enum Species species, bool32 isShiny, u32 personality, bool32 isEgg)
{
    return GetMonSpritePalFromSpeciesIsEgg(species, isShiny, IsPersonalityFemale(species, personality), isEgg);
}

const u16 *GetMonSpritePalFromSpecies(enum Species species, bool32 isShiny, bool32 isFemale)
{
    return GetMonSpritePalFromSpeciesIsEgg(species, isShiny, isFemale, FALSE);
}

const u16 *GetMonSpritePalFromSpeciesIsEgg(enum Species species, bool32 isShiny, bool32 isFemale, bool32 isEgg)
{
    species = SanitizeSpeciesId(species);

    if (isEgg)
    {
        if (gSpeciesInfo[species].eggId != EGG_ID_NONE)
            return gEggDatas[gSpeciesInfo[species].eggId].eggPalette;
        else
            return gSpeciesInfo[SPECIES_EGG].palette;
    }
    else if (isShiny)
    {
    #if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].shinyPaletteFemale != NULL && isFemale)
            return gSpeciesInfo[species].shinyPaletteFemale;
        else
    #endif
        if (gSpeciesInfo[species].shinyPalette != NULL)
            return gSpeciesInfo[species].shinyPalette;
        else
            return gSpeciesInfo[SPECIES_NONE].shinyPalette;
    }
    else
    {
    #if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].paletteFemale != NULL && isFemale)
            return gSpeciesInfo[species].paletteFemale;
        else
    #endif
        if (gSpeciesInfo[species].palette != NULL)
            return gSpeciesInfo[species].palette;
        else
            return gSpeciesInfo[SPECIES_NONE].palette;
    }
}

#define OR_MOVE_IS_HM(_hm) || (move == MOVE_##_hm)

bool32 IsMoveHM(enum Move move)
{
    return FALSE FOREACH_HM(OR_MOVE_IS_HM);
}

#undef OR_MOVE_IS_HM

bool32 CannotForgetMove(enum Move move)
{
    if (P_CAN_FORGET_HIDDEN_MOVE)
        return FALSE;

    return IsMoveHM(move);
}

bool8 IsMonSpriteNotFlipped(enum Species species)
{
    return gSpeciesInfo[species].noFlip;
}

s8 GetMonFlavorRelation(struct Pokemon *mon, enum Flavor flavor)
{
    u8 nature = GetNature(mon);
    return gPokeblockFlavorCompatibilityTable[nature * FLAVOR_COUNT + flavor];
}

s8 GetFlavorRelationByPersonality(u32 personality, enum Flavor flavor)
{
    u8 nature = GetNatureFromPersonality(personality);
    return gPokeblockFlavorCompatibilityTable[nature * FLAVOR_COUNT + flavor];
}

bool8 IsTradedMon(struct Pokemon *mon)
{
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u32 otId;
    GetMonData(mon, MON_DATA_OT_NAME, otName);
    otId = GetMonData(mon, MON_DATA_OT_ID, 0);
    return IsOtherTrainer(otId, otName);
}

bool8 IsOtherTrainer(u32 otId, u8 *otName)
{
    if (otId == READ_OTID_FROM_SAVE)
    {
        int i;
        for (i = 0; otName[i] != EOS; i++)
            if (otName[i] != gSaveBlock2Ptr->playerName[i])
                return TRUE;
        return FALSE;
    }

    return TRUE;
}

void MonRestorePP(struct Pokemon *mon)
{
    BoxMonRestorePP(&mon->box);
}

void BoxMonRestorePP(struct BoxPokemon *boxMon)
{
    int i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0))
        {
            enum Move move = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0);
            u16 bonus = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES, 0);
            u8 pp = CalculatePPWithBonus(move, bonus, i);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp);
        }
    }
}

void SetMonPreventsSwitchingString(void)
{
    gLastUsedAbility = gBattleStruct->abilityPreventingSwitchout;

    gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
    gBattleTextBuff1[1] = B_BUFF_MON_NICK_WITH_PREFIX;
    gBattleTextBuff1[2] = gBattleStruct->battlerPreventingSwitchout;
    gBattleTextBuff1[4] = B_BUFF_EOS;

    if (IsOnPlayerSide(gBattleStruct->battlerPreventingSwitchout))
        gBattleTextBuff1[3] = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[gBattleStruct->battlerPreventingSwitchout]);
    else
        gBattleTextBuff1[3] = gBattlerPartyIndexes[gBattleStruct->battlerPreventingSwitchout];

    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff2, gBattlerInMenuId, GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[gBattlerInMenuId]))

    BattleStringExpandPlaceholders(gText_PkmnsXPreventsSwitching, gStringVar4, sizeof(gStringVar4));
}

static s32 GetWildMonTableIdInAlteringCave(enum Species species)
{
    s32 i;
    for (i = 0; i < (s32) ARRAY_COUNT(sAlteringCaveWildMonHeldItems); i++)
        if (sAlteringCaveWildMonHeldItems[i].species == species)
            return i;
    return 0;
}

static inline bool32 CanFirstMonBoostHeldItemRarity(void)
{
    enum Ability ability;
    if (GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SANITY_IS_EGG))
        return FALSE;

    ability = GetMonAbility(&gParties[B_TRAINER_PLAYER][0]);
    if (ability == ABILITY_COMPOUND_EYES)
        return TRUE;
    else if ((OW_SUPER_LUCK >= GEN_8) && ability == ABILITY_SUPER_LUCK)
        return TRUE;
    return FALSE;
}

void SetWildMonHeldItem(void)
{
    u16 rnd;
    enum Species species;
    u16 count = (WILD_DOUBLE_BATTLE) ? 2 : 1;
    u16 i;
    bool32 itemHeldBoost = CanFirstMonBoostHeldItemRarity();
    u16 chanceNoItem = itemHeldBoost ? 20 : 45;
    u16 chanceNotRare = itemHeldBoost ? 80 : 95;

    for (i = 0; i < count; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM) != ITEM_NONE)
            continue; // prevent overwriting previously set item

        rnd = Random() % 100;
        species = GetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_SPECIES, 0);
        if (gMapHeader.mapLayoutId == LAYOUT_ALTERING_CAVE)
        {
            s32 alteringCaveId = GetWildMonTableIdInAlteringCave(species);
            if (alteringCaveId != 0)
            {
                // In active Altering Cave, use special item list
                if (rnd < chanceNotRare)
                    continue;
                SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &sAlteringCaveWildMonHeldItems[alteringCaveId].item);
            }
            else
            {
                // In inactive Altering Cave, use normal items
                if (rnd < chanceNoItem)
                    continue;
                if (rnd < chanceNotRare)
                    SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemCommon);
                else
                    SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemRare);
            }
        }
        else
        {
            if (gSpeciesInfo[species].itemCommon == gSpeciesInfo[species].itemRare && gSpeciesInfo[species].itemCommon != ITEM_NONE)
            {
                // Both held items are the same, 100% chance to hold item
                SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemCommon);
            }
            else
            {
                if (rnd < chanceNoItem)
                    continue;
                if (rnd < chanceNotRare)
                    SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemCommon);
                else
                    SetMonData(&gParties[B_TRAINER_OPPONENT_A][i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemRare);
            }
        }
    }
}

bool8 IsMonShiny(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_IS_SHINY);
}

const u8 *GetTrainerPartnerName(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        GetFrontierTrainerName(gStringVar1, gPartnerTrainerId);
        return gStringVar1;
    }
    else
    {
        u8 id = GetMultiplayerId();
        return gLinkPlayers[GetBattlerMultiplayerId(gLinkPlayers[id].id ^ 2)].name;
    }
}

#define READ_PTR_FROM_TASK(taskId, dataId)                      \
    (void *)(                                                   \
    ((u16)(gTasks[taskId].data[dataId]) |                       \
    ((u16)(gTasks[taskId].data[dataId + 1]) << 16)))

#define STORE_PTR_IN_TASK(ptr, taskId, dataId)                 \
{                                                              \
    gTasks[taskId].data[dataId] = (u32)(ptr);                  \
    gTasks[taskId].data[dataId + 1] = (u32)(ptr) >> 16;        \
}

#define sAnimId    data[2]
#define sAnimDelay data[3]

static void Task_AnimateAfterDelay(u8 taskId)
{
    if (--gTasks[taskId].sAnimDelay == 0)
    {
        LaunchAnimationTaskForFrontSprite(READ_PTR_FROM_TASK(taskId, 0), gTasks[taskId].sAnimId);
        DestroyTask(taskId);
    }
}

static void Task_PokemonSummaryAnimateAfterDelay(u8 taskId)
{
    if (--gTasks[taskId].sAnimDelay == 0)
    {
        StartMonSummaryAnimation(READ_PTR_FROM_TASK(taskId, 0), gTasks[taskId].sAnimId);
        SummaryScreen_SetAnimDelayTaskId(TASK_NONE);
        DestroyTask(taskId);
    }
}

void BattleAnimateFrontSprite(struct Sprite *sprite, enum Species species, bool8 noCry, u8 panMode)
{
    if (gHitMarker & HITMARKER_NO_ANIMATIONS && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
        DoMonFrontSpriteAnimation(sprite, species, noCry, panMode | SKIP_FRONT_ANIM);
    else
        DoMonFrontSpriteAnimation(sprite, species, noCry, panMode);
}

void DoMonFrontSpriteAnimation(struct Sprite *sprite, enum Species species, bool8 noCry, u8 panModeAnimFlag)
{
    s8 pan;
    switch (panModeAnimFlag & (u8)~SKIP_FRONT_ANIM) // Exclude anim flag to get pan mode
    {
    case 0:
        pan = -25;
        break;
    case 1:
        pan = 25;
        break;
    default:
        pan = 0;
        break;
    }
    if (panModeAnimFlag & SKIP_FRONT_ANIM || (gBattleTypeFlags & BATTLE_TYPE_GHOST))
    {
        // No animation, only check if cry needs to be played
        if (!noCry)
            PlayCry_Normal(species, pan);
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (!noCry)
        {
            PlayCry_Normal(species, pan);
            if (HasTwoFramesAnimation(species))
                StartSpriteAnim(sprite, 1);
        }
        if (gSpeciesInfo[species].frontAnimDelay != 0)
        {
            // Animation has delay, start delay task
            u8 taskId = CreateTask(Task_AnimateAfterDelay, 0);
            STORE_PTR_IN_TASK(sprite, taskId, 0);
            gTasks[taskId].sAnimId = gSpeciesInfo[species].frontAnimId;
            gTasks[taskId].sAnimDelay = gSpeciesInfo[species].frontAnimDelay;
        }
        else
        {
            // No delay, start animation
            LaunchAnimationTaskForFrontSprite(sprite, gSpeciesInfo[species].frontAnimId);
        }
        sprite->callback = SpriteCallbackDummy_2;
    }
}

void PokemonSummaryDoMonAnimation(struct Sprite *sprite, enum Species species, bool8 oneFrame)
{
    if (!oneFrame && HasTwoFramesAnimation(species))
        StartSpriteAnim(sprite, 1);
    if (gSpeciesInfo[species].frontAnimDelay != 0)
    {
        // Animation has delay, start delay task
        u8 taskId = CreateTask(Task_PokemonSummaryAnimateAfterDelay, 0);
        STORE_PTR_IN_TASK(sprite, taskId, 0);
        gTasks[taskId].sAnimId = gSpeciesInfo[species].frontAnimId;
        gTasks[taskId].sAnimDelay = gSpeciesInfo[species].frontAnimDelay;
        SummaryScreen_SetAnimDelayTaskId(taskId);
        SetSpriteCB_MonAnimDummy(sprite);
    }
    else
    {
        // No delay, start animation
        StartMonSummaryAnimation(sprite, gSpeciesInfo[species].frontAnimId);
    }
}

void StopPokemonAnimationDelayTask(void)
{
    u8 delayTaskId = FindTaskIdByFunc(Task_PokemonSummaryAnimateAfterDelay);
    if (delayTaskId != TASK_NONE)
        DestroyTask(delayTaskId);
}

void BattleAnimateBackSprite(struct Sprite *sprite, enum Species species)
{
    if (gHitMarker & HITMARKER_NO_ANIMATIONS && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        LaunchAnimationTaskForBackSprite(sprite, GetSpeciesBackAnimSet(species));
        sprite->callback = SpriteCallbackDummy_2;
    }
}

// Identical to GetOpposingLinkMultiBattlerId but for the player
// "rightSide" from that team's perspective, i.e. B_POSITION_*_RIGHT
static u8 UNUSED GetOwnOpposingLinkMultiBattlerId(bool8 rightSide)
{
    s32 i;
    s32 battler = 0;
    u8 multiplayerId = GetMultiplayerId();
    switch (gLinkPlayers[multiplayerId].id)
    {
    case 0:
    case 2:
        battler = rightSide ? 3 : 1;
        break;
    case 1:
    case 3:
        battler = rightSide ? 2 : 0;
        break;
    }
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayers[i].id == (s16)battler)
            break;
    }
    return i;
}

u8 GetOpposingLinkMultiBattlerId(bool8 rightSide, u8 multiplayerId)
{
    s32 i;
    s32 battler = 0;
    switch (gLinkPlayers[multiplayerId].id)
    {
    case 0:
    case 2:
        battler = rightSide ? 3 : 1;
        break;
    case 1:
    case 3:
        battler = rightSide ? 2 : 0;
        break;
    }
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayers[i].id == (s16)battler)
            break;
    }
    return i;
}

enum TrainerPicID FacilityClassToPicIndex(u16 facilityClass)
{
    return gFacilityClassToPicIndex[facilityClass];
}

enum TrainerPicID PlayerGenderToFrontTrainerPicId(enum Gender playerGender)
{
    if (playerGender != MALE)
        return FacilityClassToPicIndex(IS_FRLG ? FACILITY_CLASS_LEAF : FACILITY_CLASS_MAY);
    else
        return FacilityClassToPicIndex(IS_FRLG ? FACILITY_CLASS_RED : FACILITY_CLASS_BRENDAN);
}

void HandleSetPokedexFlag(enum NationalDexOrder nationalNum, u8 caseId, u32 personality)
{
    u8 getFlagCaseId = (caseId == FLAG_SET_SEEN) ? FLAG_GET_SEEN : FLAG_GET_CAUGHT;
    if (!GetSetPokedexFlag(nationalNum, getFlagCaseId)) // don't set if it's already set
    {
        GetSetPokedexFlag(nationalNum, caseId);
        if (NationalPokedexNumToSpecies(nationalNum) == SPECIES_UNOWN)
            gSaveBlock2Ptr->pokedex.unownPersonality = personality;
        if (NationalPokedexNumToSpecies(nationalNum) == SPECIES_SPINDA)
            gSaveBlock2Ptr->pokedex.spindaPersonality = personality;
    }
}

void HandleSetPokedexFlagFromMon(struct Pokemon *mon, u32 caseId)
{
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    enum NationalDexOrder nationalNum = SpeciesToNationalPokedexNum(GetMonData(mon, MON_DATA_SPECIES));

    HandleSetPokedexFlag(nationalNum, caseId, personality);
}

bool8 HasTwoFramesAnimation(enum Species species)
{
    return P_TWO_FRAME_FRONT_SPRITES
        && gSpeciesInfo[species].frontAnimFrames != sAnims_SingleFramePlaceHolder
        && species != SPECIES_UNOWN
        && !gTestRunnerHeadless;
}

bool8 ShouldSkipFriendshipChange(void)
{
    if (gMain.inBattle && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER))
        return TRUE;
    if (!gMain.inBattle && (InBattlePike() || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE))
        return TRUE;
    return FALSE;
}

// The below functions are for the 'MonSpritesGfxManager', a method of allocating
// space for Pokémon sprites. These are only used for the summary screen Pokémon
// sprites (unless gMonSpritesGfxPtr is in use), but were set up for more general use.
// Only the 'default' mode (MON_SPR_GFX_MODE_NORMAL) is used, which is set
// up to allocate 4 sprites using the battler sprite templates (gBattlerSpriteTemplates).
// MON_SPR_GFX_MODE_BATTLE is identical but never used.
// MON_SPR_GFX_MODE_FULL_PARTY is set up to allocate 7 sprites (party + trainer?)
// using a generic 64x64 template, and is also never used.

// Between the unnecessarily large sizes below, a mistake allocating the spritePointers
// field, and the fact that ultimately only 1 of the 4 sprite positions is used, this
// system wastes a good deal of memory.

#define ALLOC_FAIL_BUFFER (1 << 0)
#define ALLOC_FAIL_STRUCT (1 << 1)
#define GFX_MANAGER_ACTIVE 0xA3 // Arbitrary value

static void InitMonSpritesGfx_Battle(struct MonSpritesGfxManager *gfx)
{
    u16 i, j;
    for (i = 0; i < gfx->numSprites; i++)
    {
        gfx->templates[i] = gBattlerSpriteTemplates[i];
        for (j = 0; j < gfx->numFrames; j++)
            gfx->frameImages[i * gfx->numFrames + j].data = &gfx->spritePointers[i][j * MON_PIC_SIZE];

        gfx->templates[i].images = &gfx->frameImages[i * gfx->numFrames];
    }
}

static void InitMonSpritesGfx_FullParty(struct MonSpritesGfxManager *gfx)
{
    u16 i, j;
    for (i = 0; i < gfx->numSprites; i++)
    {
        gfx->templates[i] = sSpriteTemplate_64x64;
        for (j = 0; j < gfx->numFrames; j++)
            gfx->frameImages[i * gfx->numSprites + j].data = &gfx->spritePointers[i][j * MON_PIC_SIZE];

        gfx->templates[i].images = &gfx->frameImages[i * gfx->numSprites];
        gfx->templates[i].anims = gAnims_MonPic;
        gfx->templates[i].paletteTag = i;
    }
}

struct MonSpritesGfxManager *CreateMonSpritesGfxManager(u8 managerId, u8 mode)
{
    u8 i;
    u8 failureFlags;
    struct MonSpritesGfxManager *gfx;

    failureFlags = 0;
    managerId %= MON_SPR_GFX_MANAGERS_COUNT;
    gfx = AllocZeroed(sizeof(*gfx));
    if (gfx == NULL)
        return NULL;

    switch (mode)
    {
    case MON_SPR_GFX_MODE_FULL_PARTY:
        gfx->numSprites = PARTY_SIZE + 1;
        gfx->numSprites2 = PARTY_SIZE + 1;
        gfx->numFrames = MAX_MON_PIC_FRAMES;
        gfx->dataSize = 1;
        gfx->mode = MON_SPR_GFX_MODE_FULL_PARTY;
        break;
 // case MON_SPR_GFX_MODE_BATTLE:
    case MON_SPR_GFX_MODE_NORMAL:
    default:
        gfx->numSprites = MAX_BATTLERS_COUNT;
        gfx->numSprites2 = MAX_BATTLERS_COUNT;
        gfx->numFrames = MAX_MON_PIC_FRAMES;
        gfx->dataSize = 1;
        gfx->mode = MON_SPR_GFX_MODE_NORMAL;
        break;
    }

    // Set up sprite / sprite pointer buffers
    gfx->spriteBuffer = AllocZeroed(gfx->dataSize * MON_PIC_SIZE * MAX_MON_PIC_FRAMES * gfx->numSprites);
    gfx->spritePointers = AllocZeroed(gfx->numSprites * 32); // ? Only * 4 is necessary, perhaps they were thinking bits.
    if (gfx->spriteBuffer == NULL || gfx->spritePointers == NULL)
    {
        failureFlags |= ALLOC_FAIL_BUFFER;
    }
    else
    {
        for (i = 0; i < gfx->numSprites; i++)
            gfx->spritePointers[i] = gfx->spriteBuffer + (gfx->dataSize * MON_PIC_SIZE * MAX_MON_PIC_FRAMES * i);
    }

    // Set up sprite structs
    gfx->templates = AllocZeroed(sizeof(struct SpriteTemplate) * gfx->numSprites);
    gfx->frameImages = AllocZeroed(sizeof(struct SpriteFrameImage) * gfx->numSprites * gfx->numFrames);
    if (gfx->templates == NULL || gfx->frameImages == NULL)
    {
        failureFlags |= ALLOC_FAIL_STRUCT;
    }
    else
    {
        for (i = 0; i < gfx->numFrames * gfx->numSprites; i++)
            gfx->frameImages[i].size = MON_PIC_SIZE;

        switch (gfx->mode)
        {
        case MON_SPR_GFX_MODE_FULL_PARTY:
            InitMonSpritesGfx_FullParty(gfx);
            break;
        case MON_SPR_GFX_MODE_NORMAL:
        case MON_SPR_GFX_MODE_BATTLE:
        default:
            InitMonSpritesGfx_Battle(gfx);
            break;
        }
    }

    // If either of the allocations failed free their respective members
    if (failureFlags & ALLOC_FAIL_STRUCT)
    {
        TRY_FREE_AND_SET_NULL(gfx->frameImages);
        TRY_FREE_AND_SET_NULL(gfx->templates);
    }
    if (failureFlags & ALLOC_FAIL_BUFFER)
    {
        TRY_FREE_AND_SET_NULL(gfx->spritePointers);
        TRY_FREE_AND_SET_NULL(gfx->spriteBuffer);
    }

    if (failureFlags)
    {
        // Clear, something failed to allocate
        memset(gfx, 0, sizeof(*gfx));
        Free(gfx);
    }
    else
    {
        gfx->active = GFX_MANAGER_ACTIVE;
        sMonSpritesGfxManagers[managerId] = gfx;
    }

    return sMonSpritesGfxManagers[managerId];
}

void DestroyMonSpritesGfxManager(u8 managerId)
{
    struct MonSpritesGfxManager *gfx;

    managerId %= MON_SPR_GFX_MANAGERS_COUNT;
    gfx = sMonSpritesGfxManagers[managerId];
    if (gfx == NULL)
        return;

    if (gfx->active != GFX_MANAGER_ACTIVE)
    {
        memset(gfx, 0, sizeof(*gfx));
    }
    else
    {
        TRY_FREE_AND_SET_NULL(gfx->frameImages);
        TRY_FREE_AND_SET_NULL(gfx->templates);
        TRY_FREE_AND_SET_NULL(gfx->spritePointers);
        TRY_FREE_AND_SET_NULL(gfx->spriteBuffer);
        memset(gfx, 0, sizeof(*gfx));
        Free(gfx);
    }
}

u8 *MonSpritesGfxManager_GetSpritePtr(u8 managerId, u8 spriteNum)
{
    struct MonSpritesGfxManager *gfx = sMonSpritesGfxManagers[managerId % MON_SPR_GFX_MANAGERS_COUNT];
    if (gfx->active != GFX_MANAGER_ACTIVE)
    {
        return NULL;
    }
    else
    {
        if (spriteNum >= gfx->numSprites)
            spriteNum = 0;

        return gfx->spritePointers[spriteNum];
    }
}

enum Species GetFormSpeciesId(enum Species speciesId, u8 formId)
{
    if (GetSpeciesFormTable(speciesId) != NULL)
        return GetSpeciesFormTable(speciesId)[formId];
    else
        return speciesId;
}

u8 GetFormIdFromFormSpeciesId(enum Species formSpeciesId)
{
    u8 targetFormId = 0;

    if (GetSpeciesFormTable(formSpeciesId) != NULL)
    {
        for (targetFormId = 0; GetSpeciesFormTable(formSpeciesId)[targetFormId] != FORM_SPECIES_END; targetFormId++)
        {
            if (formSpeciesId == GetSpeciesFormTable(formSpeciesId)[targetFormId])
                break;
        }
    }
    return targetFormId;
}

// Returns the current species if no form change is possible
enum Species GetFormChangeTargetSpeciesBoxMon(struct BoxPokemon *boxMon, enum FormChanges method)
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (formChanges == NULL)
        return species;

    struct FormChangeContext ctx =
    {
        .method = method,
        .currentSpecies = species,
        .heldItem = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM),
        .ability = GetAbilityBySpecies(species, GetBoxMonData(boxMon, MON_DATA_ABILITY_NUM)),
        .partyItemUsed = gSpecialVar_ItemId,
        .multichoiceSelection = gSpecialVar_Result,
        .status = GetBoxMonData(boxMon, MON_DATA_STATUS),
    };

    return GetFormChangeTargetSpecies_Internal(ctx);
}

// Returns the current species if no form change is possible
enum Species GetFormChangeTargetSpecies(struct Pokemon *mon, enum FormChanges method)
{
    return GetFormChangeTargetSpeciesBoxMon(&mon->box, method);
}

enum Species GetFormChangeTargetSpecies_Internal(struct FormChangeContext ctx)
{
    u32 i;
    enum Species targetSpecies = ctx.currentSpecies;
    const struct FormChange *formChanges = GetSpeciesFormChanges(ctx.currentSpecies);

    if (formChanges == NULL)
        return ctx.currentSpecies;

    for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (!(ctx.method == formChanges[i].method && ctx.currentSpecies != formChanges[i].targetSpecies))
            continue;

        switch (ctx.method)
        {
        case FORM_CHANGE_ITEM_HOLD:
            if ((ctx.heldItem == formChanges[i].param1 || formChanges[i].param1 == ITEM_NONE)
                && (ctx.ability == formChanges[i].param2 || formChanges[i].param2 == ABILITY_NONE))
            {
                // This is to prevent reverting to base form when giving the item to the corresponding form.
                // Eg. Giving a Zap Plate to an Electric Arceus without an item (most likely to happen when using givemon)
                bool32 currentItemForm = FALSE;
                for (u32 j = 0; formChanges[j].method != FORM_CHANGE_TERMINATOR; j++)
                {
                    if (ctx.currentSpecies == formChanges[j].targetSpecies
                        && formChanges[j].param1 == ctx.heldItem
                        && formChanges[j].param1 != ITEM_NONE)
                    {
                        currentItemForm = TRUE;
                        break;
                    }
                }
                if (!currentItemForm)
                    targetSpecies = formChanges[i].targetSpecies;
            }
            break;
        case FORM_CHANGE_ITEM_USE:
            if (ctx.partyItemUsed == formChanges[i].param1)
            {
                bool32 pass = TRUE;
                switch (formChanges[i].param2)
                {
                case DAY:
                    if (GetTimeOfDay() == TIME_NIGHT)
                        pass = FALSE;
                    break;
                case NIGHT:
                    if (GetTimeOfDay() != TIME_NIGHT)
                        pass = FALSE;
                    break;
                }

                if (formChanges[i].param3 != STATUS1_NONE && ctx.status & formChanges[i].param3)
                    pass = FALSE;

                if (pass)
                    targetSpecies = formChanges[i].targetSpecies;
            }
            break;
        case FORM_CHANGE_ITEM_USE_MULTICHOICE:
            if (ctx.partyItemUsed == formChanges[i].param1
             && ctx.multichoiceSelection == formChanges[i].param2)
            {
                targetSpecies = formChanges[i].targetSpecies;
            }
            break;
        case FORM_CHANGE_MOVE:
            if (ctx.learnedMove != formChanges[i].param2)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BEGIN_BATTLE:
        case FORM_CHANGE_END_BATTLE:
            if (ctx.heldItem == formChanges[i].param1 || formChanges[i].param1 == ITEM_NONE)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_END_BATTLE_ENVIRONMENT:
            if (gBattleEnvironment == formChanges[i].param1)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_WITHDRAW:
        case FORM_CHANGE_DEPOSIT:
        case FORM_CHANGE_FAINT:
        case FORM_CHANGE_DAYS_PASSED:
        case FORM_CHANGE_BEGIN_WILD_ENCOUNTER:
            targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_STATUS:
            if (ctx.status & formChanges[i].param1)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_TIME_OF_DAY:
            switch (formChanges[i].param1)
            {
            case DAY:
                if (GetTimeOfDay() != TIME_NIGHT)
                    targetSpecies = formChanges[i].targetSpecies;
                break;
            case NIGHT:
                if (GetTimeOfDay() == TIME_NIGHT)
                    targetSpecies = formChanges[i].targetSpecies;
                break;
            }
            break;
        case FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM:
        case FORM_CHANGE_BATTLE_PRIMAL_REVERSION:
        case FORM_CHANGE_BATTLE_ULTRA_BURST:
            if (ctx.heldItem == formChanges[i].param1)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE:
            if (ctx.moves[0] == formChanges[i].param1
                || ctx.moves[1] == formChanges[i].param1
                || ctx.moves[2] == formChanges[i].param1
                || ctx.moves[3] == formChanges[i].param1)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_SWITCH_OUT:
            if (formChanges[i].param1 == ctx.ability || formChanges[i].param1 == ABILITY_NONE)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_HP_PERCENT_DURING_MOVE:
            if (ctx.ability == formChanges[i].param1
                && gCurrentMove == formChanges[i].param4)
            {
                // We multiply by 100 to make sure that integer division doesn't mess with the health check.
                u32 hpCheck = ctx.hp * 100 * 100 / ctx.maxHP;
                switch (formChanges[i].param2)
                {
                case HP_HIGHER_THAN:
                    if (hpCheck > formChanges[i].param3 * 100)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case HP_LOWER_EQ_THAN:
                    if (hpCheck <= formChanges[i].param3 * 100)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                }
            }
            break;
        case FORM_CHANGE_BATTLE_HP_PERCENT_TURN_END:
        case FORM_CHANGE_BATTLE_HP_PERCENT_SEND_OUT:
            if (ctx.ability == formChanges[i].param1
                && ctx.level >= formChanges[i].param4)
            {
                // We multiply by 100 to make sure that integer division doesn't mess with the health check.
                u32 hpCheck = ctx.hp * 100 * 100 / ctx.maxHP;
                switch (formChanges[i].param2)
                {
                case HP_HIGHER_THAN:
                    if (hpCheck > formChanges[i].param3 * 100)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case HP_LOWER_EQ_THAN:
                    if (hpCheck <= formChanges[i].param3 * 100)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                }
            }
            break;
        case FORM_CHANGE_BATTLE_GIGANTAMAX:
            if (ctx.gmaxFactor)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_WEATHER:
            // Check if there is a required ability and if the battler's ability does not match it
            // or is suppressed. If so, revert to the no weather form.
            if (formChanges[i].param2
                && ctx.ability != formChanges[i].param2
                && formChanges[i].param1 == B_WEATHER_NONE)
            {
                targetSpecies = formChanges[i].targetSpecies;
            }
            // We need to revert the weather form if the field is under Air Lock, too.
            else if (!HasWeatherEffect() && formChanges[i].param1 == B_WEATHER_NONE)
            {
                targetSpecies = formChanges[i].targetSpecies;
            }
            // Otherwise, just check for a match between the weather and the form change table.
            // Added a check for whether the weather is in effect to prevent end-of-turn soft locks with Cloud Nine / Air Lock
            else if (((gBattleWeather & formChanges[i].param1) && HasWeatherEffect())
                || (gBattleWeather == B_WEATHER_NONE && formChanges[i].param1 == B_WEATHER_NONE))
            {
                targetSpecies = formChanges[i].targetSpecies;
            }
            break;
        case FORM_CHANGE_BATTLE_HIT_BY_MOVE_CATEGORY:
            if (ctx.ability == formChanges[i].param1
                && formChanges[i].param2 == GetBattleMoveCategory(gCurrentMove))
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_SWITCH_IN:
        case FORM_CHANGE_BATTLE_TURN_END:
        case FORM_CHANGE_BATTLE_HIT_BY_CONFUSION_SELF_DMG:
        case FORM_CHANGE_BATTLE_BOND:
            if (formChanges[i].param1 == ctx.ability)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_TERASTALLIZATION:
            if (ctx.teraType == formChanges[i].param1)
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_BEFORE_MOVE:
        case FORM_CHANGE_BATTLE_AFTER_MOVE:
            if (formChanges[i].param1 == gCurrentMove
                && (formChanges[i].param2 == ABILITY_NONE || formChanges[i].param2 == ctx.ability))
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_BATTLE_BEFORE_MOVE_CATEGORY:
            if (formChanges[i].param1 == GetBattleMoveCategory(gCurrentMove)
                && (formChanges[i].param2 == ABILITY_NONE || formChanges[i].param2 == ctx.ability))
                targetSpecies = formChanges[i].targetSpecies;
            break;
        case FORM_CHANGE_OVERWORLD_WEATHER:
        case FORM_CHANGE_TERMINATOR:
            break;
        }
    }

    return targetSpecies;
}


void TrySetDayLimitToFormChange(struct Pokemon *mon)
{
    u32 i;
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    for (i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_DAYS_PASSED && species != formChanges[i].targetSpecies)
        {
            SetMonData(mon, MON_DATA_DAYS_SINCE_FORM_CHANGE, &formChanges[i].param1);
            break;
        }
    }
}

bool32 DoesSpeciesHaveFormChangeMethod(enum Species species, enum FormChanges method)
{
    u32 i;
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    for (i = 0; formChanges != NULL && formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (method == formChanges[i].method && species != formChanges[i].targetSpecies)
            return TRUE;
    }

    return FALSE;
}

u16 MonTryLearningNewMoveEvolution(struct Pokemon *mon, bool8 firstMove)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u8 level = GetMonData(mon, MON_DATA_LEVEL);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    // Since you can learn more than one move per level,
    // the game needs to know whether you decided to
    // learn it or keep the old set to avoid asking
    // you to learn the same move over and over again.
    if (firstMove)
    {
        sLearningMoveTableID = 0;
    }
    while (learnset[sLearningMoveTableID].move != LEVEL_UP_MOVE_END)
    {
        while ((learnset[sLearningMoveTableID].level == 0 || learnset[sLearningMoveTableID].level == level)
             && !(P_EVOLUTION_LEVEL_1_LEARN >= GEN_8 && learnset[sLearningMoveTableID].level == 1))
        {
            gMoveToLearn = learnset[sLearningMoveTableID].move;
            sLearningMoveTableID++;
            return GiveMoveToMon(mon, gMoveToLearn);
        }
        sLearningMoveTableID++;
    }
    return 0;
}

// Removes the selected index from the given IV list and shifts the remaining
// elements to the left.
void RemoveIVIndexFromList(u8 *ivs, u8 selectedIv)
{
    s32 i, j;
    u8 temp[NUM_STATS];

    ivs[selectedIv] = 0xFF;
    for (i = 0; i < NUM_STATS; i++)
    {
        temp[i] = ivs[i];
    }

    j = 0;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (temp[i] != 0xFF)
            ivs[j++] = temp[i];
    }
}

void TrySpecialOverworldEvo(void)
{
    u8 i;
    bool32 canStopEvo = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        enum Species targetSpecies = GetEvolutionTargetSpecies(&gParties[B_TRAINER_PLAYER][i], EVO_MODE_OVERWORLD_SPECIAL, 0, NULL, &canStopEvo, CHECK_EVO);

        if (targetSpecies != SPECIES_NONE && !(gTriedEvolving & (1u << i)))
        {
            GetEvolutionTargetSpecies(&gParties[B_TRAINER_PLAYER][i], EVO_MODE_OVERWORLD_SPECIAL, 0, NULL, &canStopEvo, DO_EVO);
            gTriedEvolving |= 1u << i;

            if (gMain.callback2 == TrySpecialOverworldEvo) // This fixes small graphics glitches.
                EvolutionScene(&gParties[B_TRAINER_PLAYER][i], targetSpecies, canStopEvo, i);
            else
                BeginEvolutionScene(&gParties[B_TRAINER_PLAYER][i], targetSpecies, canStopEvo, i);

            gCB2_AfterEvolution = TrySpecialOverworldEvo;
            return;
        }
    }

    gTriedEvolving = 0;
    SetMainCallback2(CB2_ReturnToField);
}

bool32 SpeciesHasGenderDifferences(enum Species species)
{
#if P_GENDER_DIFFERENCES
    if (gSpeciesInfo[species].frontPicFemale != NULL
     || gSpeciesInfo[species].backPicFemale != NULL
     || gSpeciesInfo[species].paletteFemale != NULL
     || gSpeciesInfo[species].shinyPaletteFemale != NULL
     || gSpeciesInfo[species].iconSpriteFemale != NULL)
        return TRUE;
#endif

    return FALSE;
}

static struct PartyState *GetBattlerPartyStateByPokemon(struct Pokemon *partyMon, enum BattleTrainer trainer)
{
    struct Pokemon *party = GetTrainerParty(trainer);

    for (int i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &party[i];
        if (partyMon == mon)
            return &gBattleStruct->partyState[trainer][i];
    }
    return NULL;
}

bool32 TryFormChange(struct Pokemon *mon, enum FormChanges method, enum BattleTrainer trainer)
{
    if (GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_NONE
     || GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EGG)
        return FALSE;

    enum Species currentSpecies = GetMonData(mon, MON_DATA_SPECIES);
    enum Species targetSpecies = GetFormChangeTargetSpecies(mon, method);

    struct PartyState *battlePartyState = GetBattlerPartyStateByPokemon(mon, trainer);
    // If the battle ends, and there's not a specified species to change back to,
    // use the species at the start of the battle.
    if (targetSpecies == SPECIES_NONE
        && battlePartyState != NULL && battlePartyState->changedSpecies != SPECIES_NONE
        // This is added to prevent FORM_CHANGE_END_BATTLE_ENVIRONMENT from omitting move changes
        // at the end of the battle, as it was being counting as a successful form change.
        && (method == FORM_CHANGE_END_BATTLE || method == FORM_CHANGE_FAINT))
    {
        targetSpecies = battlePartyState->changedSpecies;
    }

    assertf(targetSpecies != SPECIES_NONE, "form change target returned NONE. cur:%d, method:%d", currentSpecies, method)
    {
        return FALSE;
    }

    if (targetSpecies != currentSpecies)
    {
        TryToSetBattleFormChangeMoves(mon, method);
        SetMonData(mon, MON_DATA_SPECIES, &targetSpecies);
        TrySetDayLimitToFormChange(mon);
        CalculateMonStats(mon);
        return TRUE;
    }

    return FALSE;
}

bool32 TryBoxMonFormChange(struct BoxPokemon *boxMon, enum FormChanges method)
{
    if (GetBoxMonData(boxMon, MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_NONE
     || GetBoxMonData(boxMon, MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EGG)
        return FALSE;

    enum Species currentSpecies = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    enum Species targetSpecies = GetFormChangeTargetSpeciesBoxMon(boxMon, method);

    assertf(targetSpecies != SPECIES_NONE, "form change target returned NONE. cur:%d, method:%d", currentSpecies, method)
    {
        return FALSE;
    }

    if (targetSpecies != currentSpecies)
    {
        SetBoxMonData(boxMon, MON_DATA_SPECIES, &targetSpecies);
        return TRUE;
    }
    return FALSE;
}

enum Species SanitizeSpeciesId(enum Species species)
{
    assertf(species <= NUM_SPECIES, "invalid species: %d", species)
    {
        return SPECIES_NONE;
    }

    assertf(species == SPECIES_NONE || IsSpeciesEnabled(species), "disabled species: %d", species)
    {
        return SPECIES_NONE;
    }

    return species;
}

bool32 IsSpeciesEnabled(enum Species species)
{
    // This function should not use the GetSpeciesBaseHP function, as the included sanitation will result in an infinite loop
    return gSpeciesInfo[species].baseHP > 0 || species == SPECIES_EGG;
}

void TryToSetBattleFormChangeMoves(struct Pokemon *mon, enum FormChanges method)
{
    int i, j;
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (formChanges == NULL
        || (method != FORM_CHANGE_BEGIN_BATTLE && method != FORM_CHANGE_END_BATTLE))
        return;

    for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == method
            && formChanges[i].param2
            && formChanges[i].param3
            && formChanges[i].targetSpecies != species)
        {
            u16 originalMove = formChanges[i].param2;
            u16 newMove = formChanges[i].param3;

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                u16 currMove = GetMonData(mon, MON_DATA_MOVE1 + j);
                if (currMove == originalMove)
                    SetMonMoveSlot_KeepPP(mon, newMove, j);
            }
            break;
        }
    }
}

u32 GetMonFriendshipScore(struct Pokemon *pokemon)
{
    u32 friendshipScore = GetMonData(pokemon, MON_DATA_FRIENDSHIP);

    if (friendshipScore == MAX_FRIENDSHIP)
        return FRIENDSHIP_MAX;
    if (friendshipScore >= 200)
        return FRIENDSHIP_200_TO_254;
    if (friendshipScore >= 150)
        return FRIENDSHIP_150_TO_199;
    if (friendshipScore >= 100)
        return FRIENDSHIP_100_TO_149;
    if (friendshipScore >= 50)
        return FRIENDSHIP_50_TO_99;
    if (friendshipScore >= 1)
        return FRIENDSHIP_1_TO_49;

    return FRIENDSHIP_NONE;
}

u32 GetMonAffectionHearts(struct Pokemon *pokemon)
{
    u32 friendship = GetMonData(pokemon, MON_DATA_FRIENDSHIP);

    if (friendship == MAX_FRIENDSHIP)
        return AFFECTION_FIVE_HEARTS;
    if (friendship >= 220)
        return AFFECTION_FOUR_HEARTS;
    if (friendship >= 180)
        return AFFECTION_THREE_HEARTS;
    if (friendship >= 130)
        return AFFECTION_TWO_HEARTS;
    if (friendship >= 80)
        return AFFECTION_ONE_HEART;

    return AFFECTION_NO_HEARTS;
}

void UpdateMonPersonality(struct BoxPokemon *boxMon, u32 personality)
{
    struct PokemonSubstruct0 *old0, *new0;
    struct PokemonSubstruct1 *old1, *new1;
    struct PokemonSubstruct2 *old2, *new2;
    struct PokemonSubstruct3 *old3, *new3;
    struct BoxPokemon old;

    bool32 isShiny = GetBoxMonData(boxMon, MON_DATA_IS_SHINY);
    u32 hiddenNature = GetBoxMonData(boxMon, MON_DATA_HIDDEN_NATURE);
    enum Type teraType = GetBoxMonData(boxMon, MON_DATA_TERA_TYPE);

    old = *boxMon;
    old0 = &(GetSubstruct(&old, old.personality, SUBSTRUCT_TYPE_0)->type0);
    old1 = &(GetSubstruct(&old, old.personality, SUBSTRUCT_TYPE_1)->type1);
    old2 = &(GetSubstruct(&old, old.personality, SUBSTRUCT_TYPE_2)->type2);
    old3 = &(GetSubstruct(&old, old.personality, SUBSTRUCT_TYPE_3)->type3);

    new0 = &(GetSubstruct(boxMon, personality, SUBSTRUCT_TYPE_0)->type0);
    new1 = &(GetSubstruct(boxMon, personality, SUBSTRUCT_TYPE_1)->type1);
    new2 = &(GetSubstruct(boxMon, personality, SUBSTRUCT_TYPE_2)->type2);
    new3 = &(GetSubstruct(boxMon, personality, SUBSTRUCT_TYPE_3)->type3);

    DecryptBoxMon(&old);
    boxMon->personality = personality;
    *new0 = *old0;
    *new1 = *old1;
    *new2 = *old2;
    *new3 = *old3;
    boxMon->checksum = CalculateBoxMonChecksumReencrypt(boxMon);

    SetBoxMonData(boxMon, MON_DATA_IS_SHINY, &isShiny);
    SetBoxMonData(boxMon, MON_DATA_HIDDEN_NATURE, &hiddenNature);
    SetBoxMonData(boxMon, MON_DATA_TERA_TYPE, &teraType);
}

void HealPokemon(struct Pokemon *mon)
{
    u32 data;

    data = GetMonData(mon, MON_DATA_MAX_HP);
    SetMonData(mon, MON_DATA_HP, &data);

    data = STATUS1_NONE;
    SetMonData(mon, MON_DATA_STATUS, &data);

    MonRestorePP(mon);
}

void HealBoxPokemon(struct BoxPokemon *boxMon)
{
    u32 data;

    data = 0;
    SetBoxMonData(boxMon, MON_DATA_HP_LOST, &data);

    data = STATUS1_NONE;
    SetBoxMonData(boxMon, MON_DATA_STATUS, &data);

    BoxMonRestorePP(boxMon);
}

enum PokemonCry GetCryIdBySpecies(enum Species species)
{
    species = SanitizeSpeciesId(species);
    if (P_CRIES_ENABLED == FALSE || gSpeciesInfo[species].cryId >= CRY_COUNT || gTestRunnerHeadless)
        return CRY_NONE;
    return gSpeciesInfo[species].cryId;
}

enum Species GetSpeciesPreEvolution(enum Species species)
{
    int i, j;

    for (i = SPECIES_BULBASAUR; i < NUM_SPECIES; i++)
    {
        if (!IsSpeciesEnabled(i))
            continue;

        const struct Evolution *evolutions = GetSpeciesEvolutions(i);
        if (evolutions == NULL)
            continue;

        for (j = 0; evolutions[j].method != EVOLUTIONS_END; j++)
        {
            if (IsSpeciesEnabled(evolutions[j].targetSpecies) && SanitizeSpeciesId(evolutions[j].targetSpecies) == species)
                return i;
        }
    }

    return SPECIES_NONE;
}

void UpdateDaysPassedSinceFormChange(u16 days)
{
    u32 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        enum Species currentSpecies = GetMonData(mon, MON_DATA_SPECIES);
        u8 daysSinceFormChange;

        if (currentSpecies == SPECIES_NONE)
            continue;

        daysSinceFormChange = GetMonData(mon, MON_DATA_DAYS_SINCE_FORM_CHANGE, 0);
        if (daysSinceFormChange == 0)
            continue;

        if (daysSinceFormChange > days)
            daysSinceFormChange -= days;
        else
            daysSinceFormChange = 0;

        SetMonData(mon, MON_DATA_DAYS_SINCE_FORM_CHANGE, &daysSinceFormChange);

        if (daysSinceFormChange == 0)
            TryFormChange(mon, FORM_CHANGE_DAYS_PASSED, B_TRAINER_PLAYER);
    }
}

enum Type CheckDynamicMoveType(struct Pokemon *mon, enum Move move, enum BattlerId battler, enum MonState state)
{
    enum Type moveType = GetDynamicMoveType(mon, move, battler, GetBattlerAbility(battler), GetBattlerHoldEffect(battler), state);
    if (moveType != TYPE_NONE)
        return moveType;
    return GetMoveType(move);
}

uq4_12_t GetDynamaxLevelHPMultiplier(u32 dynamaxLevel, bool32 inverseMultiplier)
{
    if (inverseMultiplier)
        return UQ_4_12(1.0/(1.5 + 0.05 * dynamaxLevel));
    return UQ_4_12(1.5 + 0.05 * dynamaxLevel);
}

bool32 IsSpeciesRegionalForm(enum Species species)
{
    return gSpeciesInfo[species].isAlolanForm
        || gSpeciesInfo[species].isGalarianForm
        || gSpeciesInfo[species].isHisuianForm
        || gSpeciesInfo[species].isPaldeanForm;
}

bool32 IsSpeciesRegionalFormFromRegion(enum Species species, enum Region region)
{
    switch (region)
    {
    case REGION_ALOLA:  return gSpeciesInfo[species].isAlolanForm;
    case REGION_GALAR:  return gSpeciesInfo[species].isGalarianForm;
    case REGION_HISUI:  return gSpeciesInfo[species].isHisuianForm;
    case REGION_PALDEA: return gSpeciesInfo[species].isPaldeanForm;
    default:            return FALSE;
    }
}

bool32 SpeciesHasRegionalForm(enum Species species)
{
    u32 formId;
    const u16 *formTable = GetSpeciesFormTable(species);
    for (formId = 0; formTable != NULL && formTable[formId] != FORM_SPECIES_END; formId++)
    {
        if (IsSpeciesRegionalForm(formTable[formId]))
            return TRUE;
    }
    return FALSE;
}

enum Species GetRegionalFormByRegion(enum Species species, enum Region region)
{
    u32 formId = 0;
    enum Species firstFoundSpecies = 0;
    const u16 *formTable = GetSpeciesFormTable(species);

    if (formTable != NULL)
    {
        for (formId = 0; formTable[formId] != FORM_SPECIES_END; formId++)
        {
            if (firstFoundSpecies == 0)
                firstFoundSpecies = formTable[formId];

            if (IsSpeciesRegionalFormFromRegion(formTable[formId], region))
                return formTable[formId];
        }
        if (firstFoundSpecies != 0)
            return firstFoundSpecies;
    }
    return species;
}

bool32 IsSpeciesForeignRegionalForm(enum Species species, enum Region currentRegion)
{
    for (enum Region i = 0; i < REGIONS_COUNT; i++)
    {
        if (currentRegion != i && IsSpeciesRegionalFormFromRegion(species, i))
            return TRUE;
        else if (currentRegion == i && SpeciesHasRegionalForm(species) && !IsSpeciesRegionalFormFromRegion(species, i))
            return TRUE;
    }
    return FALSE;
}

enum Type GetTeraTypeFromPersonality(struct Pokemon *mon)
{
    const u8 *types = gSpeciesInfo[GetMonData(mon, MON_DATA_SPECIES)].types;
    return (GetMonData(mon, MON_DATA_PERSONALITY) & 0x1) == 0 ? types[0] : types[1];
}

struct Pokemon *GetSavedPlayerPartyMon(u32 index)
{
    return &gSaveBlock1Ptr->playerParty[index];
}

u8 *GetSavedPlayerPartyCount(void)
{
    return &gSaveBlock1Ptr->playerPartyCount;
}

void SavePlayerPartyMon(u32 index, struct Pokemon *mon)
{
    gSaveBlock1Ptr->playerParty[index] = *mon;
}

bool32 IsSpeciesOfType(enum Species species, enum Type type)
{
    if (gSpeciesInfo[species].types[0] == type
     || gSpeciesInfo[species].types[1] == type)
        return TRUE;
    return FALSE;
}

struct BoxPokemon *GetSelectedBoxMonFromPcOrParty(void)
{
    struct BoxPokemon *boxmon;
    if (gSpecialVar_0x8004 == PC_MON_CHOSEN)
        boxmon = GetBoxedMonPtr(gSpecialVar_MonBoxId, gSpecialVar_MonBoxPos);
    else
        boxmon = &(gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004].box);
    return boxmon;
}

u32 GiveScriptedMonToPlayer(struct Pokemon *mon, u8 slot)
{
    u32 sentToPc;
    u32 i = 0;
    if (slot < PARTY_SIZE)
    {
        CopyMon(&gParties[B_TRAINER_PLAYER][slot], mon, sizeof(struct Pokemon));
        sentToPc = MON_GIVEN_TO_PARTY;
    }
    else
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == SPECIES_NONE)
                break;
        }
        if (i >= PARTY_SIZE)
        {
            sentToPc = CopyMonToPC(mon);
        }
        else
        {
            sentToPc = MON_GIVEN_TO_PARTY;
            CopyMon(&gParties[B_TRAINER_PLAYER][i], mon, sizeof(struct Pokemon));
            gPartiesCount[B_TRAINER_PLAYER] = i + 1;
        }
    }
    if (sentToPc != MON_CANT_GIVE)
    {
        HandleSetPokedexFlagFromMon(mon, FLAG_SET_SEEN);
        HandleSetPokedexFlagFromMon(mon, FLAG_SET_CAUGHT);
    }
    CalculatePlayerPartyCount();
    return sentToPc;
}

void ChangePokemonNicknameWithCallback(void (*callback)(void))
{
    struct BoxPokemon *boxMon = GetSelectedBoxMonFromPcOrParty();
    GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar3);
    GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar2);
    DoNamingScreen(NAMING_SCREEN_NICKNAME, gStringVar2, GetBoxMonData(boxMon, MON_DATA_SPECIES), GetBoxMonGender(boxMon), GetBoxMonData(boxMon, MON_DATA_PERSONALITY), callback);
}

bool32 HasShedinjaHPHandling(enum Species species)
{
    if (species == SPECIES_SHEDINJA)
        return TRUE;
    if (P_BASE_HP_1_SHEDINJA_HANDLING && GetSpeciesBaseHP(species) == 1)
        return TRUE;
    return FALSE;
}

static u32 ResolveAbility(enum Species species, u32 abilityNum)
{
    assertf(abilityNum < NUM_ABILITY_SLOTS && GetAbilityBySpecies(species, abilityNum) != ABILITY_NONE,
            "invalid ability num %d for species %d", abilityNum, species)
    {
        return 0;
    }
    return abilityNum;
}

static enum PokeBall ResolveBall(u32 ballTemplate)
{
    if (ballTemplate < POKEBALL_COUNT)
        return ballTemplate;
    if (ballTemplate == BALL_RANDOM)
        return GetRandomBall();

    errorf("Unknown ball value %d when creating pokemon", ballTemplate);
    return BALL_STRANGE;
}

static void ResolveIVs(enum Species species, const u16 *ivsTemplate, u8 *ivs)
{
    u32 i;
    u32 nonFixedIvCount = 0;
    enum Stat availableIVs[NUM_STATS];
    enum Stat selectedIvs[NUM_STATS];
    for (i = 0; i < NUM_STATS; i++)
    {
        if (ivsTemplate[i] < USE_RANDOM_IVS)
        {
            ivs[i] = ivsTemplate[i];
        }
        else if (ivsTemplate[i] == USE_RANDOM_IVS)
        {
            availableIVs[nonFixedIvCount] = i;
            ivs[i] = Random() % (MAX_PER_STAT_IVS + 1);
            nonFixedIvCount++;
        }
        else
        {
            errorf("invalid iv value of %d above maximum of %d", ivs[i], MAX_PER_STAT_IVS);
            ivs[i] = MAX_PER_STAT_IVS;
        }
    }

    // Perfect IV calculation
    if (gSpeciesInfo[species].perfectIVCount != 0)
    {
        // Select the IVs that will be perfected.
        for (i = 0; i < nonFixedIvCount && i < gSpeciesInfo[species].perfectIVCount; i++)
        {
            u8 index = Random() % (nonFixedIvCount - i);
            selectedIvs[i] = availableIVs[index];
            RemoveIVIndexFromList(availableIVs, index);
        }
        for (i = 0; i < nonFixedIvCount && i < gSpeciesInfo[species].perfectIVCount; i++)
        {
            ivs[selectedIvs[i]] = MAX_PER_STAT_IVS;
        }
    }
}

void ResolveEVs(const u16 *evsTemplate, u8 *evs, bool32 ignoreTotalEvCheck)
{
    u32 evTotal = 0;
    for (u32 i = 0; i < NUM_STATS; i++)
    {
        if (evsTemplate[i] <= MAX_PER_STAT_EVS)
        {
            evs[i] = evsTemplate[i];
        }
        else
        {
            errorf("invalid ev value of %d above maximum of %d", evs[i], MAX_PER_STAT_EVS);
            evs[i] = 0;
        }
        evTotal += evs[i];
    }
    if (!OW_CHECK_FOR_TOTAL_EVS || ignoreTotalEvCheck)
        return;
    assertf(evTotal <= MAX_TOTAL_EVS, "invalid total ev value of %d above maximum of %d", evTotal, MAX_TOTAL_EVS)
    {
        for (u32 i = 0; i < NUM_STATS; i++)
        {
            evs[i] = 0;
        }
    }
}

static enum Species ResolveSpecies(u32 speciesTemplate)
{
    assertf (IsSpeciesEnabled(speciesTemplate), "unknown species %d when creating pokemon", speciesTemplate)
    {
        return SPECIES_PORYGON;
    }
    return speciesTemplate;
}

static u32 ResolveLevel(u32 levelTemplate)
{
    assertf (MIN_LEVEL <= levelTemplate &&levelTemplate <= MAX_LEVEL, "using invalid level %d when creating pokemon", levelTemplate)
    {
        return MIN_LEVEL;
    }
    return levelTemplate;
}

static u32 ResolvePersonality(enum Species species, u32 genderTemplate, u32 natureTemplate, enum GeneratedMonOrigin originTemplate)
{
    u32 gender;
    u32 nature;
    assertf(originTemplate != UNDEFINED_MON_ORIGIN, "origin was not explicitly set when creating pokemon")
    {
        // if the origin was not explictly set, never apply Synchronize or Cute Charm effects
        if (genderTemplate == MON_GENDER_MAY_CUTE_CHARM)
            genderTemplate = MON_GENDER_RANDOM;
        if (natureTemplate == NATURE_MAY_SYNCHRONIZE)
            natureTemplate = NATURE_RANDOM;
    }
    if (genderTemplate == MON_GENDER_MAY_CUTE_CHARM)
        gender = GetSynchronizedGender(originTemplate, genderTemplate);
    else
        gender = genderTemplate;
    if (natureTemplate == NATURE_MAY_SYNCHRONIZE)
        nature = GetSynchronizedNature(originTemplate, natureTemplate);
    else
        nature = natureTemplate;
    return GetMonPersonality(species, gender, nature, RANDOM_UNOWN_LETTER);
}

static bool32 ResolveShinyness(u32 isShinyTemplate)
{
    assertf(isShinyTemplate == TRUE || isShinyTemplate == FALSE, "using non boolean isShiny value %d when creating pokemon", isShinyTemplate)
    {
        return FALSE;
    }
    return isShinyTemplate;
}

static bool32 ResolveDynamaxLevel(u32 dynamaxLevelTemplate)
{
    assertf(dynamaxLevelTemplate <= MAX_DYNAMAX_LEVEL, "invalid dynamax level value %d when creating pokemon", dynamaxLevelTemplate)
    {
        return FALSE;
    }
    return dynamaxLevelTemplate;
}

static bool32 ResolveGmaxFactor(u32 gmaxFactorTemplate)
{
    assertf(gmaxFactorTemplate == TRUE || gmaxFactorTemplate == FALSE, "using non boolean gmaxFactor value %d when creating pokemon", gmaxFactorTemplate)
    {
        return FALSE;
    }
    return gmaxFactorTemplate;
}

static bool32 ResolveIsEgg(u32 isEggTemplate)
{
    assertf(isEggTemplate == TRUE || isEggTemplate == FALSE, "using non boolean isEgg value %d when creating pokemon", isEggTemplate)
    {
        return FALSE;
    }
    return isEggTemplate;
}

static bool32 ResolveTeraType(u32 teraTypeTemplate)
{
    assertf(teraTypeTemplate != TYPE_NONE && teraTypeTemplate != TYPE_MYSTERY && teraTypeTemplate < NUMBER_OF_MON_TYPES, "using invalid tera type %d when creating pokemon", teraTypeTemplate)
    {
        return TYPE_STELLAR;
    }
    return teraTypeTemplate;
}

static enum Item ResolveHeldItem(u32 heldItemTemplate)
{
    assertf(heldItemTemplate < ITEMS_COUNT,"using invalid item %d when creating pokemon", heldItemTemplate)
    {
        return ITEM_NONE;
    }
    assertf(!ItemIsMail(heldItemTemplate) && !GetItemImportance(heldItemTemplate), "trying to give item %d that can't be held to newly created pokemon", heldItemTemplate)
    {
        return ITEM_NONE;
    }
    return heldItemTemplate;
}

void CreateMonFromTemplate(struct Pokemon *mon, const struct PokemonTemplate *monTemplate)
{
    enum Species species = ResolveSpecies(monTemplate->species);
    u8 level = ResolveLevel(monTemplate->level);
    u32 personality = ResolvePersonality(species, monTemplate->gender, monTemplate->nature, monTemplate->origin);
    CreateMon(mon, species, level, personality, OTID_STRUCT_PLAYER_ID);

    enum Item heldItem = ResolveHeldItem(monTemplate->heldItem);
    SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);

    if (monTemplate->doNotUseDefaultBall)
    {
        enum PokeBall ball = ResolveBall(monTemplate->ball);
        SetMonData(mon, MON_DATA_POKEBALL, &ball);
    }

    if (monTemplate->doNotUseDefaultShinyness && monTemplate->isShiny != SHINY_MODE_RANDOM)
    {
        bool32 isShiny = ResolveShinyness(monTemplate->isShiny);
        SetMonData(mon, MON_DATA_IS_SHINY, &isShiny);
    }

    if (monTemplate->doNotUseDefaultAbility)
    {
        u8 abilityNum = ResolveAbility(species, monTemplate->abilityNum);
        SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
    }

    u8 ivs[NUM_STATS];
    u8 evs[NUM_STATS];
    ResolveIVs(species, monTemplate->ivs, ivs);
    ResolveEVs(monTemplate->evs, evs, monTemplate->ignoreTotalEvCheck);
    for (u32 i = 0; i < NUM_STATS; i++)
    {
        SetMonData(mon, MON_DATA_HP_IV + i, &ivs[i]);
        SetMonData(mon, MON_DATA_HP_EV + i, &evs[i]);
    }

    enum Move moves[MAX_MON_MOVES];
    ResolveMoves(species, level, monTemplate->moves, moves);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        SetMonMoveSlot(mon, moves[i], i);
    }

    u32 dmaxLevel = ResolveDynamaxLevel(monTemplate->dmaxLevel);
    SetMonData(mon, MON_DATA_DYNAMAX_LEVEL, &dmaxLevel);

    bool32 gmaxFactor = ResolveGmaxFactor(monTemplate->gmaxFactor);
    SetMonData(mon, MON_DATA_GIGANTAMAX_FACTOR, &gmaxFactor);

    if (monTemplate->doNotUseDefaultTeraType)
    {
        enum Type teraType = ResolveTeraType(monTemplate->teraType);
        SetMonData(mon, MON_DATA_TERA_TYPE, &teraType);
    }

    bool32 isEgg = ResolveIsEgg(monTemplate->isEgg);
    SetMonData(mon, MON_DATA_IS_EGG, &isEgg);

    CalculateMonStats(mon);
    TryFormChange(mon, FORM_CHANGE_ITEM_HOLD, B_TRAINER_PLAYER);
}
