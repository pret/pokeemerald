#include "global.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "event_data.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "save.h"
#include "strings.h"
#include "fieldmap.h"
#include "party_menu.h"
#include "palette.h"
#include "field_screen_effect.h"
#include "field_message_box.h"
#include "random.h"
#include "item.h"
#include "util.h"
#include "sound.h"
#include "task.h"
#include "start_menu.h"
#include "string_util.h"
#include "trainer_see.h"
#include "main.h"
#include "load_save.h"
#include "script.h"
#include "alloc.h"
#include "overworld.h"
#include "event_scripts.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"

extern const struct MapLayout *const gMapLayouts[];
extern const u16 gUnknown_08D856C8[][16];

#define TOTAL_ROUNDS 20
#define PICKUP_ITEMS_PER_ROUND 10

struct PyramidWildMon
{
    u16 species;
    u8 lvl;
    u8 abilityBit;
    u16 moves[4];
};

struct Struct_08613650
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 runMultiplier;
    u8 unk5[8];
};

struct ClassMusic
{
    u8 class;
    u8 music;
};

// This file's functions.
static void sub_81A8E9C(void);
static void sub_81A8F38(void);
static void sub_81A9048(void);
static void sub_81A9134(void);
static void sub_81A917C(void);
static void sub_81A91FC(void);
static void sub_81A9254(void);
static void sub_81A9290(void);
static void sub_81A93C8(void);
static void sub_81A9414(void);
static void sub_81A9424(void);
static void sub_81A9618(void);
static void sub_81A966C(void);
static void sub_81A9684(void);
static void sub_81A975C(void);
static void sub_81A97C8(void);
static void sub_81A9828(void);
static void sub_81A9834(void);
static void InitBagItems(u8 lvlMode);
static u8 sub_81AA9E4(void);
static u8 sub_81A9998(s32 *, u8, u8);
static void sub_81A97DC(u8 taskId);
static void sub_81A9B44(u16 trainerId);
static void sub_81AA96C(u8 *mapNums);
static void sub_81AA33C(u8 *, u8 *);
static void sub_81AA398(u8);
static bool8 sub_81AA4D8(u8, u8);
static bool8 sub_81AA648(u8, u8);
static bool8 sub_81AA760(u8 arg0, u8 *mapNums, u8 whichMap, u8 id);
static bool8 sub_81AA810(u8 arg0, u8 x, u8 y, u8 *mapNums, u8 whichMap, u8 id);

// Const rom data.
#include "data/battle_frontier/battle_pyramid_level_50_wild_mons.h"
#include "data/battle_frontier/battle_pyramid_open_level_wild_mons.h"

static const struct Struct_08613650 gUnknown_08613650[] =
{
    {
        .unk0 = 0x07,
        .unk1 = 0x03,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x80,
        .unk5 = {0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03}
    },
    {
        .unk0 = 0x06,
        .unk1 = 0x03,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x80,
        .unk5 = {0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04}
    },
    {
        .unk0 = 0x05,
        .unk1 = 0x03,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x78,
        .unk5 = {0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05}
    },
    {
        .unk0 = 0x04,
        .unk1 = 0x04,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x78,
        .unk5 = {0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06}
    },
    {
        .unk0 = 0x04,
        .unk1 = 0x04,
        .unk2 = 0x00,
        .unk3 = 0x01,
        .runMultiplier = 0x70,
        .unk5 = {0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07}
    },
    {
        .unk0 = 0x03,
        .unk1 = 0x05,
        .unk2 = 0x00,
        .unk3 = 0x02,
        .runMultiplier = 0x70,
        .unk5 = {0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c}
    },
    {
        .unk0 = 0x03,
        .unk1 = 0x05,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x68,
        .unk5 = {0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d}
    },
    {
        .unk0 = 0x02,
        .unk1 = 0x04,
        .unk2 = 0x00,
        .unk3 = 0x01,
        .runMultiplier = 0x68,
        .unk5 = {0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e}
    },
    {
        .unk0 = 0x04,
        .unk1 = 0x05,
        .unk2 = 0x00,
        .unk3 = 0x02,
        .runMultiplier = 0x60,
        .unk5 = {0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f}
    },
    {
        .unk0 = 0x03,
        .unk1 = 0x06,
        .unk2 = 0x00,
        .unk3 = 0x04,
        .runMultiplier = 0x60,
        .unk5 = {0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f}
    },
    {
        .unk0 = 0x02,
        .unk1 = 0x03,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x58,
        .unk5 = {0x0c, 0x0d, 0x0e, 0x0c, 0x0d, 0x0e, 0x0c, 0x0d}
    },
    {
        .unk0 = 0x04,
        .unk1 = 0x05,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x58,
        .unk5 = {0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b}
    },
    {
        .unk0 = 0x03,
        .unk1 = 0x07,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x50,
        .unk5 = {0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c}
    },
    {
        .unk0 = 0x02,
        .unk1 = 0x04,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x50,
        .unk5 = {0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d}
    },
    {
        .unk0 = 0x03,
        .unk1 = 0x06,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x50,
        .unk5 = {0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e}
    },
    {
        .unk0 = 0x03,
        .unk1 = 0x08,
        .unk2 = 0x00,
        .unk3 = 0x00,
        .runMultiplier = 0x50,
        .unk5 = {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}
    }
};

static const u8 gUnknown_08613750[34][2] =
{
    {0x28, 0x00},
    {0x46, 0x01},
    {0x5a, 0x02},
    {0x64, 0x03},
    {0x23, 0x01},
    {0x37, 0x02},
    {0x4b, 0x03},
    {0x5a, 0x04},
    {0x64, 0x0a},
    {0x23, 0x02},
    {0x37, 0x03},
    {0x4b, 0x04},
    {0x5a, 0x05},
    {0x64, 0x0b},
    {0x23, 0x03},
    {0x37, 0x04},
    {0x4b, 0x05},
    {0x5a, 0x06},
    {0x64, 0x0c},
    {0x23, 0x04},
    {0x37, 0x05},
    {0x4b, 0x06},
    {0x5a, 0x07},
    {0x64, 0x0d},
    {0x23, 0x05},
    {0x37, 0x06},
    {0x4b, 0x07},
    {0x5a, 0x08},
    {0x64, 0x0e},
    {0x23, 0x06},
    {0x37, 0x07},
    {0x4b, 0x08},
    {0x5a, 0x09},
    {0x64, 0x0f}
};

static const u8 gUnknown_08613794[] =
{
    0x00, 0x04, 0x09, 0x0e, 0x13, 0x18, 0x1d, 0x00
};

static const u16 sPickupItemsLvl50[TOTAL_ROUNDS][PICKUP_ITEMS_PER_ROUND] =
{
    {ITEM_HYPER_POTION, ITEM_FLUFFY_TAIL, ITEM_CHERI_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_DIRE_HIT, ITEM_PECHA_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_ATTACK, ITEM_RAWST_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_DEFEND, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPEED, ITEM_CHESTO_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_ACCURACY, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPECIAL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_GUARD_SPEC, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_FLUFFY_TAIL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_DIRE_HIT, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_ATTACK, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_DEFEND, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPEED, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_ACCURACY, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPECIAL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_GUARD_SPEC, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_FLUFFY_TAIL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_DIRE_HIT, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_ATTACK, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_DEFEND, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
};

static const u16 sPickupItemsLvlOpen[TOTAL_ROUNDS][PICKUP_ITEMS_PER_ROUND] =
{
    {ITEM_HYPER_POTION, ITEM_FLUFFY_TAIL, ITEM_CHERI_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_DIRE_HIT, ITEM_PECHA_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_ATTACK, ITEM_RAWST_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_DEFEND, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPEED, ITEM_CHESTO_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_ACCURACY, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPECIAL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_GUARD_SPEC, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_FLUFFY_TAIL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_DIRE_HIT, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_ATTACK, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_DEFEND, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPEED, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_ACCURACY, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_SPECIAL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_GUARD_SPEC, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_FLUFFY_TAIL, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_BRIGHT_POWDER, ITEM_SHELL_BELL, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_DIRE_HIT, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_LEFTOVERS, ITEM_CHOICE_BAND, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
    {ITEM_HYPER_POTION, ITEM_X_ATTACK, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LUM_BERRY, ITEM_REVIVE, ITEM_SCOPE_LENS, ITEM_FOCUS_BAND, ITEM_MAX_REVIVE, ITEM_SACRED_ASH},
    {ITEM_HYPER_POTION, ITEM_X_DEFEND, ITEM_LUM_BERRY, ITEM_ETHER, ITEM_LEPPA_BERRY, ITEM_REVIVE, ITEM_QUICK_CLAW, ITEM_KINGS_ROCK, ITEM_FULL_RESTORE, ITEM_MAX_ELIXIR},
};

static const u8 gUnknown_08613ABC[63][2] =
{
    {0x1f, 0x00},
    {0x2e, 0x01},
    {0x3d, 0x02},
    {0x47, 0x03},
    {0x51, 0x04},
    {0x5b, 0x05},
    {0x5e, 0x06},
    {0x61, 0x07},
    {0x64, 0x08},
    {0x0f, 0x00},
    {0x2e, 0x01},
    {0x3d, 0x02},
    {0x47, 0x03},
    {0x51, 0x04},
    {0x5b, 0x05},
    {0x5e, 0x06},
    {0x61, 0x08},
    {0x64, 0x09},
    {0x0f, 0x00},
    {0x1e, 0x01},
    {0x3d, 0x02},
    {0x47, 0x03},
    {0x51, 0x04},
    {0x5b, 0x05},
    {0x5e, 0x06},
    {0x61, 0x07},
    {0x64, 0x08},
    {0x1c, 0x00},
    {0x2b, 0x01},
    {0x3a, 0x02},
    {0x44, 0x03},
    {0x4e, 0x04},
    {0x58, 0x05},
    {0x5c, 0x07},
    {0x60, 0x08},
    {0x64, 0x09},
    {0x0f, 0x00},
    {0x2b, 0x01},
    {0x3a, 0x02},
    {0x44, 0x03},
    {0x4e, 0x04},
    {0x58, 0x05},
    {0x5c, 0x06},
    {0x60, 0x07},
    {0x64, 0x09},
    {0x0f, 0x00},
    {0x1e, 0x01},
    {0x3a, 0x02},
    {0x44, 0x03},
    {0x4e, 0x04},
    {0x58, 0x05},
    {0x5c, 0x06},
    {0x60, 0x07},
    {0x64, 0x08},
    {0x1c, 0x00},
    {0x2b, 0x01},
    {0x3a, 0x02},
    {0x44, 0x03},
    {0x4e, 0x04},
    {0x58, 0x05},
    {0x5c, 0x06},
    {0x60, 0x08},
    {0x64, 0x09},
};

static const u8 gUnknown_08613B3A[] = {0x00, 0x09, 0x12, 0x1b, 0x24, 0x2d, 0x36};

static const struct ClassMusic gUnknown_08613B44[54] =
{
    {0x03, 0x06},
    {0x0b, 0x06},
    {0x0d, 0x06},
    {0x0f, 0x01},
    {0x2b, 0x04},
    {0x2d, 0x01},
    {0x24, 0x09},
    {0x29, 0x04},
    {0x05, 0x05},
    {0x18, 0x04},
    {0x2f, 0x00},
    {0x2e, 0x09},
    {0x11, 0x0c},
    {0x10, 0x0b},
    {0x1e, 0x0d},
    {0x08, 0x01},
    {0x17, 0x03},
    {0x0c, 0x04},
    {0x38, 0x04},
    {0x1c, 0x03},
    {0x1a, 0x00},
    {0x19, 0x0b},
    {0x09, 0x07},
    {0x31, 0x07},
    {0x35, 0x07},
    {0x36, 0x01},
    {0x33, 0x00},
    {0x2a, 0x03},
    {0x16, 0x0d},
    {0x0e, 0x03},
    {0x15, 0x01},
    {0x14, 0x01},
    {0x2c, 0x01},
    {0x1b, 0x02},
    {0x04, 0x01},
    {0x07, 0x03},
    {0x34, 0x05},
    {0x32, 0x00},
    {0x37, 0x02},
    {0x1d, 0x04},
    {0x22, 0x09},
    {0x1f, 0x01},
    {0x25, 0x00},
    {0x0a, 0x04},
    {0x28, 0x00},
    {0x06, 0x05},
    {0x27, 0x0b},
    {0x26, 0x00},
    {0x13, 0x00},
    {0x12, 0x02},
    {0x39, 0x08},
    {0x02, 0x0b},
    {0x20, 0x01},
    {0x21, 0x00},
};

static const u8 gUnknown_08613C1C[50][2] =
{
    {0x0d, 0x03},
    {0x0e, 0x04},
    {0x10, 0x01},
    {0x11, 0x00},
    {0x03, 0x02},
    {0x12, 0x03},
    {0x0c, 0x03},
    {0x13, 0x03},
    {0x14, 0x03},
    {0x15, 0x02},
    {0x17, 0x02},
    {0x07, 0x02},
    {0x0a, 0x04},
    {0x19, 0x02},
    {0x1a, 0x02},
    {0x1b, 0x00},
    {0x1d, 0x02},
    {0x1e, 0x02},
    {0x1f, 0x03},
    {0x20, 0x04},
    {0x26, 0x00},
    {0x27, 0x01},
    {0x29, 0x04},
    {0x2a, 0x05},
    {0x09, 0x04},
    {0x16, 0x05},
    {0x2b, 0x00},
    {0x2d, 0x04},
    {0x2e, 0x02},
    {0x30, 0x02},
    {0x32, 0x02},
    {0x31, 0x03},
    {0x2f, 0x03},
    {0x33, 0x03},
    {0x34, 0x02},
    {0x04, 0x02},
    {0x35, 0x00},
    {0x36, 0x03},
    {0x37, 0x03},
    {0x38, 0x03},
    {0x1c, 0x01},
    {0x3a, 0x02},
    {0x05, 0x02},
    {0x42, 0x02},
    {0x02, 0x03},
    {0x44, 0x02},
    {0x45, 0x03},
    {0x47, 0x03},
    {0x43, 0x00},
    {0x00, 0x04},
};

static const u8 *const gUnknown_08613C80[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_252D2D,
    BattleFrontier_BattlePyramidEmptySquare_Text_252D57,
    BattleFrontier_BattlePyramidEmptySquare_Text_252D81,
    BattleFrontier_BattlePyramidEmptySquare_Text_252DAB,
};

static const u8 *const gUnknown_08613C90[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_25330B,
    BattleFrontier_BattlePyramidEmptySquare_Text_2532CC,
    BattleFrontier_BattlePyramidEmptySquare_Text_25328B,
    BattleFrontier_BattlePyramidEmptySquare_Text_253248,
    BattleFrontier_BattlePyramidEmptySquare_Text_253206,
    BattleFrontier_BattlePyramidEmptySquare_Text_2531C4,
    BattleFrontier_BattlePyramidEmptySquare_Text_253183,
    BattleFrontier_BattlePyramidEmptySquare_Text_253140,
    BattleFrontier_BattlePyramidEmptySquare_Text_2530FD,
};

static const u8 *const gUnknown_08613CB4[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_2544A6,
    BattleFrontier_BattlePyramidEmptySquare_Text_25445A,
    BattleFrontier_BattlePyramidEmptySquare_Text_25440B,
    BattleFrontier_BattlePyramidEmptySquare_Text_2543BA,
    BattleFrontier_BattlePyramidEmptySquare_Text_25436A,
    BattleFrontier_BattlePyramidEmptySquare_Text_25431A,
    BattleFrontier_BattlePyramidEmptySquare_Text_2542CB,
    BattleFrontier_BattlePyramidEmptySquare_Text_25427A,
};

static const u8 *const gUnknown_08613CD4[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_252DD5,
    BattleFrontier_BattlePyramidEmptySquare_Text_252E03,
    BattleFrontier_BattlePyramidEmptySquare_Text_252E31,
    BattleFrontier_BattlePyramidEmptySquare_Text_252E5F,
};

static const u8 *const gUnknown_08613CE4[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_25362E,
    BattleFrontier_BattlePyramidEmptySquare_Text_2535D4,
    BattleFrontier_BattlePyramidEmptySquare_Text_253578,
    BattleFrontier_BattlePyramidEmptySquare_Text_25351A,
    BattleFrontier_BattlePyramidEmptySquare_Text_2534BD,
    BattleFrontier_BattlePyramidEmptySquare_Text_253460,
    BattleFrontier_BattlePyramidEmptySquare_Text_253404,
    BattleFrontier_BattlePyramidEmptySquare_Text_2533A6,
    BattleFrontier_BattlePyramidEmptySquare_Text_25334D,
};

static const u8 *const gUnknown_08613D08[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_25471E,
    BattleFrontier_BattlePyramidEmptySquare_Text_2546CC,
    BattleFrontier_BattlePyramidEmptySquare_Text_25467C,
    BattleFrontier_BattlePyramidEmptySquare_Text_25462A,
    BattleFrontier_BattlePyramidEmptySquare_Text_2545D9,
    BattleFrontier_BattlePyramidEmptySquare_Text_254588,
    BattleFrontier_BattlePyramidEmptySquare_Text_254538,
    BattleFrontier_BattlePyramidEmptySquare_Text_2544E6,
};

static const u8 *const gUnknown_08613D28[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_252E8D,
    BattleFrontier_BattlePyramidEmptySquare_Text_252EAA,
    BattleFrontier_BattlePyramidEmptySquare_Text_252EC7,
    BattleFrontier_BattlePyramidEmptySquare_Text_252EE4,
};

static const u8 *const gUnknown_08613D38[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_2539EC,
    BattleFrontier_BattlePyramidEmptySquare_Text_253980,
    BattleFrontier_BattlePyramidEmptySquare_Text_253915,
    BattleFrontier_BattlePyramidEmptySquare_Text_2538A8,
    BattleFrontier_BattlePyramidEmptySquare_Text_25383C,
    BattleFrontier_BattlePyramidEmptySquare_Text_2537D0,
    BattleFrontier_BattlePyramidEmptySquare_Text_253765,
    BattleFrontier_BattlePyramidEmptySquare_Text_2536F8,
    BattleFrontier_BattlePyramidEmptySquare_Text_25368B,
};

static const u8 *const gUnknown_08613D5C[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_254A0B,
    BattleFrontier_BattlePyramidEmptySquare_Text_2549AE,
    BattleFrontier_BattlePyramidEmptySquare_Text_25494D,
    BattleFrontier_BattlePyramidEmptySquare_Text_2548EB,
    BattleFrontier_BattlePyramidEmptySquare_Text_25488A,
    BattleFrontier_BattlePyramidEmptySquare_Text_254829,
    BattleFrontier_BattlePyramidEmptySquare_Text_2547C9,
    BattleFrontier_BattlePyramidEmptySquare_Text_254767,
};

static const u8 *const gUnknown_08613D7C[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_252F01,
    BattleFrontier_BattlePyramidEmptySquare_Text_252F3A,
    BattleFrontier_BattlePyramidEmptySquare_Text_252F73,
    BattleFrontier_BattlePyramidEmptySquare_Text_252FAC,
};

static const u8 *const gUnknown_08613D8C[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_253D3E,
    BattleFrontier_BattlePyramidEmptySquare_Text_253CE0,
    BattleFrontier_BattlePyramidEmptySquare_Text_253C87,
    BattleFrontier_BattlePyramidEmptySquare_Text_253C2C,
    BattleFrontier_BattlePyramidEmptySquare_Text_253BD2,
    BattleFrontier_BattlePyramidEmptySquare_Text_253B78,
    BattleFrontier_BattlePyramidEmptySquare_Text_253B1F,
    BattleFrontier_BattlePyramidEmptySquare_Text_253AC4,
    BattleFrontier_BattlePyramidEmptySquare_Text_253A69,
};

static const u8 *const gUnknown_08613DB0[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_254C3E,
    BattleFrontier_BattlePyramidEmptySquare_Text_254BF1,
    BattleFrontier_BattlePyramidEmptySquare_Text_254BAE,
    BattleFrontier_BattlePyramidEmptySquare_Text_254B69,
    BattleFrontier_BattlePyramidEmptySquare_Text_254B25,
    BattleFrontier_BattlePyramidEmptySquare_Text_254AE1,
    BattleFrontier_BattlePyramidEmptySquare_Text_254A9E,
    BattleFrontier_BattlePyramidEmptySquare_Text_254A59,
};

static const u8 *const gUnknown_08613DD0[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_252FE5,
    BattleFrontier_BattlePyramidEmptySquare_Text_253000,
    BattleFrontier_BattlePyramidEmptySquare_Text_25301B,
    BattleFrontier_BattlePyramidEmptySquare_Text_253036,
};

static const u8 *const gUnknown_08613DE0[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_253F6C,
    BattleFrontier_BattlePyramidEmptySquare_Text_253F34,
    BattleFrontier_BattlePyramidEmptySquare_Text_253EFA,
    BattleFrontier_BattlePyramidEmptySquare_Text_253EBE,
    BattleFrontier_BattlePyramidEmptySquare_Text_253E83,
    BattleFrontier_BattlePyramidEmptySquare_Text_253E48,
    BattleFrontier_BattlePyramidEmptySquare_Text_253E0E,
    BattleFrontier_BattlePyramidEmptySquare_Text_253DD2,
    BattleFrontier_BattlePyramidEmptySquare_Text_253D96,
};

static const u8 *const gUnknown_08613E04[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_254E6E,
    BattleFrontier_BattlePyramidEmptySquare_Text_254E27,
    BattleFrontier_BattlePyramidEmptySquare_Text_254DE0,
    BattleFrontier_BattlePyramidEmptySquare_Text_254D97,
    BattleFrontier_BattlePyramidEmptySquare_Text_254D4F,
    BattleFrontier_BattlePyramidEmptySquare_Text_254D07,
    BattleFrontier_BattlePyramidEmptySquare_Text_254CC0,
    BattleFrontier_BattlePyramidEmptySquare_Text_254C77,
};

static const u8 *const gUnknown_08613E24[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_253051,
    BattleFrontier_BattlePyramidEmptySquare_Text_25307C,
    BattleFrontier_BattlePyramidEmptySquare_Text_2530A7,
    BattleFrontier_BattlePyramidEmptySquare_Text_2530D2,
};

static const u8 *const gUnknown_08613E34[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_25422B,
    BattleFrontier_BattlePyramidEmptySquare_Text_2541DD,
    BattleFrontier_BattlePyramidEmptySquare_Text_25418D,
    BattleFrontier_BattlePyramidEmptySquare_Text_25413B,
    BattleFrontier_BattlePyramidEmptySquare_Text_2540EA,
    BattleFrontier_BattlePyramidEmptySquare_Text_254099,
    BattleFrontier_BattlePyramidEmptySquare_Text_254049,
    BattleFrontier_BattlePyramidEmptySquare_Text_253FF7,
    BattleFrontier_BattlePyramidEmptySquare_Text_253FA5,
};

static const u8 *const gUnknown_08613E58[] =
{
    BattleFrontier_BattlePyramidEmptySquare_Text_255068,
    BattleFrontier_BattlePyramidEmptySquare_Text_25502F,
    BattleFrontier_BattlePyramidEmptySquare_Text_254FF6,
    BattleFrontier_BattlePyramidEmptySquare_Text_254FBB,
    BattleFrontier_BattlePyramidEmptySquare_Text_254F81,
    BattleFrontier_BattlePyramidEmptySquare_Text_254F47,
    BattleFrontier_BattlePyramidEmptySquare_Text_254F0E,
    BattleFrontier_BattlePyramidEmptySquare_Text_254ED3,
};

static const u8 *const *const gUnknown_08613E78[] =
{
    gUnknown_08613C80,
    gUnknown_08613C90,
    gUnknown_08613CB4,
};

static const u8 *const *const gUnknown_08613E84[] =
{
    gUnknown_08613CD4,
    gUnknown_08613CE4,
    gUnknown_08613D08,
};

static const u8 *const *const gUnknown_08613E90[] =
{
    gUnknown_08613D28,
    gUnknown_08613D38,
    gUnknown_08613D5C,
};

static const u8 *const *const gUnknown_08613E9C[] =
{
    gUnknown_08613D7C,
    gUnknown_08613D8C,
    gUnknown_08613DB0,
};

static const u8 *const *const gUnknown_08613EA8[] =
{
    gUnknown_08613DD0,
    gUnknown_08613DE0,
    gUnknown_08613E04,
};

static const u8 *const *const gUnknown_08613EB4[] =
{
    gUnknown_08613E24,
    gUnknown_08613E34,
    gUnknown_08613E58,
};

static const u8 *const *const *const gUnknown_08613EC0[] =
{
    gUnknown_08613E78,
    gUnknown_08613E84,
    gUnknown_08613E90,
    gUnknown_08613E9C,
    gUnknown_08613EA8,
    gUnknown_08613EB4,
};

static const u8 gUnknown_08613ED8[] = {3, 4, 5, 6, 7, 8, 3, 4};

static void (* const sBattlePyramidFunctions[])(void) =
{
    sub_81A8E9C,
    sub_81A8F38,
    sub_81A9048,
    sub_81A9134,
    sub_81A917C,
    sub_81A91FC,
    sub_81A9254,
    sub_81A9290,
    sub_81A93C8,
    sub_81A9414,
    sub_81A9424,
    sub_81A9618,
    sub_81A966C,
    sub_81A9684,
    sub_81A975C,
    sub_81A97C8,
    sub_81A9828,
    sub_81A9834,
};

static const u16 gUnknown_08613F28[] = {ITEM_HP_UP, ITEM_PROTEIN, ITEM_IRON, ITEM_CALCIUM, ITEM_CARBOS, ITEM_ZINC};
static const u16 gUnknown_08613F34[] = {ITEM_BRIGHT_POWDER, ITEM_WHITE_HERB, ITEM_QUICK_CLAW, ITEM_LEFTOVERS, ITEM_MENTAL_HERB, ITEM_KINGS_ROCK, ITEM_FOCUS_BAND, ITEM_SCOPE_LENS, ITEM_CHOICE_BAND};

static const u8 gUnknown_08613F46[][4] =
{
    {0x01, 0x04, 0xff, 0xff},
    {0x00, 0x02, 0x05, 0xff},
    {0x01, 0x03, 0x06, 0xff},
    {0x02, 0x07, 0xff, 0xff},
    {0x00, 0x05, 0x08, 0xff},
    {0x01, 0x04, 0x06, 0x09},
    {0x02, 0x05, 0x07, 0x0a},
    {0x03, 0x06, 0x0b, 0xff},
    {0x04, 0x09, 0x0c, 0xff},
    {0x05, 0x08, 0x0a, 0x0d},
    {0x06, 0x09, 0x0b, 0x0e},
    {0x07, 0x0a, 0x0f, 0xff},
    {0x08, 0x0d, 0xff, 0xff},
    {0x09, 0x0c, 0x0e, 0xff},
    {0x0a, 0x0d, 0x0f, 0xff},
    {0x0b, 0x0e, 0xff, 0xff},
};

static const u8 sPickupPercentages[PICKUP_ITEMS_PER_ROUND] = {30, 40, 50, 60, 70, 80, 85, 90, 95, 100};

// code
void CallBattlePyramidFunction(void)
{
    sBattlePyramidFunctions[gSpecialVar_0x8004]();
}

static void sub_81A8E9C(void)
{
    bool32 isCurrent;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
    else
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;

    if (!isCurrent)
    {
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = 0;
        InitBagItems(lvlMode);
    }

    sub_81C4EEC();
    gTrainerBattleOpponent_A = 0;
    gBattleOutcome = 0;
}

static void sub_81A8F38(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E18;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_50];
        break;
    case 4:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.pyramidWinStreaks[FRONTIER_LVL_OPEN];
        break;
    case 5:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x1000;
        break;
    case 6:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x2000;
        break;
    }
}

static void sub_81A9048(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E18 = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x2000;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x2000);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x1000;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x1000);
        }
        break;
    case 7:
        gSaveBlock2Ptr->frontier.field_E2A = gSpecialVar_0x8006;
        break;
    }
}

static void sub_81A9134(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    save_serialize_map();
    TrySavingData(SAVE_LINK);
}

static void sub_81A917C(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > 41)
        gSaveBlock2Ptr->frontier.field_E18 = gUnknown_08613F34[Random() % ARRAY_COUNT(gUnknown_08613F34)];
    else
        gSaveBlock2Ptr->frontier.field_E18 = gUnknown_08613F28[Random() % ARRAY_COUNT(gUnknown_08613F28)];
}

static void sub_81A91FC(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E18, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E18, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E18 = 0;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void sub_81A9254(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gSaveBlock2Ptr->frontier.field_E22[i] = Random();

    gSaveBlock2Ptr->frontier.field_E2A = 0;
}

static void sub_81A9290(void)
{
    s32 i;
    s32 r7;
    s32 rand;
    u8 id;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 floor = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
    u32 round = (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7) % TOTAL_ROUNDS;

    if (round >= TOTAL_ROUNDS)
        round = TOTAL_ROUNDS - 1;

    id = sub_81AA9E4();
    r7 = (gSpecialVar_LastTalked - gUnknown_08613650[id].unk1) - 1;
    rand = gSaveBlock2Ptr->frontier.field_E22[r7 / 2];
    SeedRng2(rand);

    for (i = 0; i < r7 + 1; i++)
        rand = Random2() % 100;

    for (i = gUnknown_08613B3A[floor]; i < ARRAY_COUNT(gUnknown_08613ABC); i++)
    {
        if (rand < gUnknown_08613ABC[i][0])
            break;
    }

    if (lvlMode != FRONTIER_LVL_50)
        gSpecialVar_0x8000 = sPickupItemsLvlOpen[round][gUnknown_08613ABC[i][1]];
    else
        gSpecialVar_0x8000 = sPickupItemsLvl50[round][gUnknown_08613ABC[i][1]];

    gSpecialVar_0x8001 = 1;
}

static void sub_81A93C8(void)
{
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    s32 i = 0;

    for (;;)
    {
        if (events[i].localId == gSpecialVar_LastTalked)
        {
            events[i].x = 0x7FFF;
            events[i].y = 0x7FFF;
            break;
        }
        i++;
        if (events[i].localId == 0)
            break;
    }
}

static void sub_81A9414(void)
{
    gFacilityTrainers = gBattleFrontierTrainers;
}

static void sub_81A9424(void)
{
    s32 i;
    s32 var_24;
    u8 id;
    s32 class = 0;
    s32 r7 = 0;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;
    u16 trainerId = LocalIdToPyramidTrainerId(gEventObjects[gSelectedEventObject].localId);

    for (i = 0; i < ARRAY_COUNT(gUnknown_08613C1C); i++)
    {
        if (gUnknown_08613C1C[i][0] == gFacilityTrainers[trainerId].facilityClass)
        {
            class = gUnknown_08613C1C[i][1];
            break;
        }
    }

    var_24 = gUnknown_08613ED8[gEventObjects[gSelectedEventObject].localId - 1];
    i = 0;
    while (!i)
    {
        switch (var_24)
        {
        case 0:
            r7 = sub_81A9998(&var_24, 8, 0);
            i = 1;
            break;
        case 1:
            for (i = 0; i < sub_81AAA40(); i++)
            {
                if (events[i].graphicsId == EVENT_OBJ_GFX_ITEM_BALL && events[i].x != 0x7FFF && events[i].y != 0x7FFF)
                    r7++;
            }
            i = 1;
            break;
        case 2:
            id = sub_81AA9E4();
            r7 = gUnknown_08613650[id].unk1;
            for (i = 0; i < 8; i++)
            {
                if (gBitTable[i] & gSaveBlock2Ptr->frontier.field_E2A)
                    r7--;
            }
            i = 1;
            break;
        case 3:
            sub_81A9998(&var_24, 8, 2);
            break;
        case 4:
            sub_81A9998(&var_24, 8, 1);
            break;
        case 5:
            sub_81A9998(&var_24, 16, 2);
            break;
        case 6:
            sub_81A9998(&var_24, 16, 1);
            break;
        case 7:
            sub_81A9998(&var_24, 24, 2);
            break;
        case 8:
            sub_81A9998(&var_24, 24, 1);
            break;
        }
    }
    ShowFieldMessage(gUnknown_08613EC0[class][var_24][r7]);
}

static void sub_81A9618(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] < 999)
        gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode]++;
    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] > gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode])
        gSaveBlock2Ptr->frontier.pyramidRecordStreaks[lvlMode] = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode];
}

static void sub_81A966C(void)
{
    gSpecialVar_Result = InBattlePyramid();
}

static void sub_81A9684(void)
{
    switch (gSpecialVar_0x8006)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_E68 = gSpecialVar_0x8005;
        break;
    case 1:
        switch (gSpecialVar_Result)
        {
        case 0:
            if (!gPaletteFade.active)
            {
                if (gSaveBlock2Ptr->frontier.field_E68 >= 120)
                    gSaveBlock2Ptr->frontier.field_E68 = 120;
                else
                    PlaySE(gSpecialVar_0x8007);
                gSpecialVar_Result++;
            }
            break;
        case 1:
            if (gSpecialVar_0x8005 != 0)
            {
                gSpecialVar_0x8005--;
                gSaveBlock2Ptr->frontier.field_E68++;
                if (gSaveBlock2Ptr->frontier.field_E68 > 120)
                {
                    gSaveBlock2Ptr->frontier.field_E68 = 120;
                    gSpecialVar_Result++;
                }
                door_upload_tiles();
            }
            else
            {
                gSpecialVar_Result = 2;
            }
            break;
        case 2:
        default:
            break;
        }
        break;
    }
}

static void sub_81A975C(void)
{
    s32 i, j;
    u16 item = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (gSaveBlock2Ptr->frontier.selectedPartyMons[j] != 0 && gSaveBlock2Ptr->frontier.selectedPartyMons[j] - 1 == i)
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
        }
    }
}

static void sub_81A97C8(void)
{
    CreateTask(sub_81A97DC, 0);
}

static void sub_81A97DC(u8 taskId)
{
    if (gPaletteFade.active)
    {
        CpuCopy16(gUnknown_08D856C8[gSaveBlock2Ptr->frontier.curChallengeBattleNum], &gPlttBufferUnfaded[96], 32);
        DestroyTask(taskId);
    }
}

static void sub_81A9828(void)
{
    sub_809FDD4();
}

static void sub_81A9834(void)
{
    s32 i, j, k, l;

    for (i = 0; i < 3; i++)
    {
        s32 id = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        for (j = 0; j < 3; j++)
        {
            if (GetMonData(&gSaveBlock1Ptr->playerParty[id], MON_DATA_SPECIES, NULL) == GetMonData(&gPlayerParty[j], MON_DATA_SPECIES, NULL))
            {
                for (k = 0; k < MAX_MON_MOVES; k++)
                {
                    for (l = 0; l < MAX_MON_MOVES; l++)
                    {
                        if (GetMonData(&gSaveBlock1Ptr->playerParty[id], MON_DATA_MOVE1 + l, NULL) == GetMonData(&gPlayerParty[j], MON_DATA_MOVE1 + k, NULL))
                            break;
                    }
                    if (l == MAX_MON_MOVES)
                        SetMonMoveSlot(&gPlayerParty[j], MOVE_SKETCH, k);
                }
                gSaveBlock1Ptr->playerParty[id] = gPlayerParty[j];
                gSelectedOrderFromParty[j] = id + 1;
                break;
            }
        }
    }

    for (i = 0; i < 3; i++)
        gSaveBlock2Ptr->frontier.selectedPartyMons[i] = gSelectedOrderFromParty[i];
}

static u8 sub_81A9998(s32 *arg0, u8 arg1, u8 arg2)
{
    s32 i, j;
    u8 ret = 0;
    u16 *map = gBackupMapLayout.map;
    map += gBackupMapLayout.width * 7 + 7;

    for (i = 0; i < 32; map += 47, i++)
    {
        for (j = 0; j < 32; j++)
        {
            if ((map[j] & 0x3FF) == 0x28E)
            {
                j += 7 - gEventObjects[gSelectedEventObject].initialCoords.x;
                i += 7 - gEventObjects[gSelectedEventObject].initialCoords.y;
                if (j >= arg1 || j <= -arg1 || i >= arg1 || i <= -arg1 || arg2 == 0)
                {
                    if (j > 0 && i > 0)
                    {
                        if (j >= i)
                            ret = 2;
                        else
                            ret = 3;
                    }
                    else if (j < 0 && i < 0)
                    {
                        if (j > i)
                            ret = 0;
                        else
                            ret = 1;
                    }
                    else if (j == 0)
                    {
                        if (i > 0)
                            ret = 3;
                        else
                            ret = 0;
                    }
                    else if (i == 0)
                    {
                        if (j > 0)
                            ret = 2;
                        else
                            ret = 1;
                    }
                    else if (j < 0)
                    {
                        if (j + i > 0)
                            ret = 3;
                        else
                            ret = 1;
                    }
                    else
                    {
                        ret = (~(j + i) >= 0) ? 0 : 2;
                    }
                    *arg0 = 0;
                }
                else
                {
                    *arg0 = arg2;
                }
                return ret;
            }
        }
    }

    return ret;
}

u16 LocalIdToPyramidTrainerId(u8 localId)
{
    return gSaveBlock2Ptr->frontier.field_CB4[localId - 1];
}

bool8 GetBattlePyramidTrainerFlag(u8 eventId)
{
    return gSaveBlock2Ptr->frontier.field_E2A & gBitTable[gEventObjects[eventId].localId - 1];
}

void sub_81A9B04(void)
{
    sub_81A9B44(gTrainerBattleOpponent_A);
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        gSelectedEventObject = GetChosenApproachingTrainerEventObjectId(1);
        sub_81A9B44(gTrainerBattleOpponent_B);
    }
}

static void sub_81A9B44(u16 trainerId)
{
    s32 i;

    for (i = 0; i < 8; i++)
    {
        if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
            gSaveBlock2Ptr->frontier.field_E2A |= gBitTable[i];
    }

    gEventObjects[gSelectedEventObject].movementType = MOVEMENT_TYPE_WANDER_AROUND;
    gSaveBlock1Ptr->eventObjectTemplates[gSpecialVar_LastTalked - 1].movementType = MOVEMENT_TYPE_WANDER_AROUND;
    gEventObjects[gSelectedEventObject].initialCoords.x = gEventObjects[gSelectedEventObject].currentCoords.x;
    gEventObjects[gSelectedEventObject].initialCoords.y = gEventObjects[gSelectedEventObject].currentCoords.y;
}

void GenerateBattlePyramidWildMon(void)
{
    u8 name[POKEMON_NAME_LENGTH + 1];
    s32 i;
    const struct PyramidWildMon *wildMons;
    u32 id;
    u32 lvl = gSaveBlock2Ptr->frontier.lvlMode;
    u16 round = (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvl] / 7) % TOTAL_ROUNDS;

    if (round >= TOTAL_ROUNDS)
        round = TOTAL_ROUNDS - 1;

    if (lvl != FRONTIER_LVL_50)
        wildMons = sOpenLevelWildMonPointers[round];
    else
        wildMons = sLevel50WildMonPointers[round];

    id = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL) - 1;
    SetMonData(&gEnemyParty[0], MON_DATA_SPECIES, &wildMons[id].species);
    GetSpeciesName(name, wildMons[id].species);
    SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, &name);
    if (lvl != FRONTIER_LVL_50)
    {
        lvl = SetFacilityPtrsGetLevel();
        lvl -= wildMons[id].lvl;
        lvl = lvl - 5 + (Random() % 11);
    }
    else
    {
        lvl = wildMons[id].lvl - 5 + ((Random() % 11));
    }
    SetMonData(&gEnemyParty[0],
               MON_DATA_EXP,
               &gExperienceTables[gBaseStats[wildMons[id].species].growthRate][lvl]);

    switch (wildMons[id].abilityBit)
    {
    case 0:
    case 1:
        SetMonData(&gEnemyParty[0], MON_DATA_ALT_ABILITY, &wildMons[id].abilityBit);
        break;
    case 2:
    default:
        if (gBaseStats[wildMons[id].species].ability2)
        {
            i = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY, NULL) % 2;
            SetMonData(&gEnemyParty[0], MON_DATA_ALT_ABILITY, &i);
        }
        else
        {
            i = 0;
            SetMonData(&gEnemyParty[0], MON_DATA_ALT_ABILITY, &i);
        }
        break;
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(&gEnemyParty[0], wildMons[id].moves[i], i);

    if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvl] >= 140) // BUG: Reading outside the array as lvl was used for mon level instead of frontier lvl mode.
    {
        id = (Random() % 17) + 15;
        for (i = 0; i < NUM_STATS; i++)
            SetMonData(&gEnemyParty[0], MON_DATA_HP_IV + i, &id);
    }
    CalculateMonStats(&gEnemyParty[0]);
}

u8 GetPyramidRunMultiplier(void)
{
    u8 id = sub_81AA9E4();
    return gUnknown_08613650[id].runMultiplier;
}

u8 InBattlePyramid(void)
{
    if (gMapHeader.mapLayoutId == 361)
        return 1;
    else if (gMapHeader.mapLayoutId == 378)
        return 2;
    else
        return FALSE;
}

bool8 InBattlePyramid_(void)
{
    return (gMapHeader.mapLayoutId == 361 || gMapHeader.mapLayoutId == 378);
}

void sub_81A9E90(void)
{
    if (InBattlePyramid())
    {
        sub_81A9834();
        gSaveBlock2Ptr->frontier.field_CA8 = 2;
        VarSet(VAR_TEMP_E, 0);
        LoadPlayerParty();
    }
}

void sub_81A9EC8(void)
{
    if (InBattlePyramid())
        DoSoftReset();
}

void CopyPyramidTrainerSpeechBefore(u16 trainerId)
{
    FrontierSpeechToString(gFacilityTrainers[trainerId].speechBefore);
}

void CopyPyramidTrainerWinSpeech(u16 trainerId)
{
    FrontierSpeechToString(gFacilityTrainers[trainerId].speechWin);
}

void CopyPyramidTrainerLoseSpeech(u16 trainerId)
{
    FrontierSpeechToString(gFacilityTrainers[trainerId].speechLose);
}

u8 GetTrainerEncounterMusicIdInBattlePyramind(u16 trainerId)
{
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_08613B44); i++)
    {
        if (gUnknown_08613B44[i].class == gFacilityClassToTrainerClass[gFacilityTrainers[trainerId].facilityClass])
            return gUnknown_08613B44[i].music;
    }
    return 0;
}

static void sub_81A9F80(void)
{
    ScriptContext1_SetupScript(BattleFrontier_BattlePyramidEmptySquare_EventScript_252C88);
}

static u16 sub_81A9F90(u8 count)
{
    s32 i;
    u16 trainerId;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 challengeNum = gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7;
    u32 battleNum = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
    if (battleNum == 7)
    {
        do
        {
            trainerId = sub_8162548(challengeNum + 1, battleNum);
            for (i = 0; i < count; i++)
            {
                if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                    break;
            }
        } while (i != count);
    }
    else
    {
        do
        {
            trainerId = sub_8162548(challengeNum, battleNum);
            for (i = 0; i < count; i++)
            {
                if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                    break;
            }
        } while (i != count);
    }

    return trainerId;
}

void sub_81AA078(u16 *mapArg, u8 arg1)
{
    s32 j, k;
    s32 i;
    u8 var0, var1;
    u8 *allocated = AllocZeroed(0x10);

    sub_81AA96C(allocated);
    sub_81AA33C(&var0, &var1);
    for (i = 0; i < 16; i++)
    {
        u16 *map;
        s32 heightAdd, widthAdd;
        const struct MapLayout *mapLayout = gMapLayouts[allocated[i] + 0x169];
        const u16 *layoutMap = mapLayout->map;

        gBackupMapLayout.map = mapArg;
        gBackupMapLayout.width = mapLayout->width * 4 + 15;
        gBackupMapLayout.height = mapLayout->height * 4 + 14;
        map = mapArg;
        heightAdd = (((i / 4 * mapLayout->height) + 7) * (gBackupMapLayout.width));
        widthAdd = ((i % 4 * mapLayout->width) + 7);
        map += heightAdd + widthAdd;
        for (j = 0; j < mapLayout->height; j++)
        {
            for (k = 0; k < mapLayout->width; k++)
            {
                if ((layoutMap[k] & 0x3FF) != 0x28E)
                {
                    map[k] = layoutMap[k];
                }
                else if (i != var1)
                {
                    if (i == var0 && arg1 == 0)
                    {
                        gSaveBlock1Ptr->pos.x = (mapLayout->width * (i % 4)) + k;
                        gSaveBlock1Ptr->pos.y = (mapLayout->height * (i / 4)) + j;
                    }
                    map[k] = (layoutMap[k] & 0xFC00) | 0x28D;
                }
                else
                {
                    map[k] = layoutMap[k];
                }
            }
            map += 15 + (mapLayout->width * 4);
            layoutMap += mapLayout->width;
        }
    }
    mapheader_run_script_with_tag_x1();
    free(allocated);
}

void sub_81AA1D8(void)
{
    s32 i;
    u8 id;
    u8 var0, var1;

    for (i = 0; i < 8; i++)
        gSaveBlock2Ptr->frontier.field_CB4[i] = 0xFFFF;

    id = sub_81AA9E4();
    sub_81AA33C(&var0, &var1);
    CpuFill32(0, gSaveBlock1Ptr->eventObjectTemplates, sizeof(gSaveBlock1Ptr->eventObjectTemplates));
    for (i = 0; i < 2; i++)
    {
        u8 value;

        if (i == 0)
            value = gUnknown_08613650[id].unk3;
        else
            value = gUnknown_08613650[id].unk2;

        switch (value)
        {
        case 0:
            sub_81AA398(i);
            break;
        case 1:
            if (sub_81AA4D8(i, var0))
                sub_81AA398(i);
            break;
        case 2:
            if (sub_81AA4D8(i, var1))
                sub_81AA398(i);
            break;
        case 3:
            if (sub_81AA648(i, var0))
                sub_81AA398(i);
            break;
        case 4:
            if (sub_81AA648(i, var1))
                sub_81AA398(i);
            break;
        }
    }
}

void sub_81AA2F8(void)
{
    s32 i;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;

    for (i = 0; i < EVENT_OBJECT_TEMPLATES_COUNT; i++)
    {
        if (events[i].graphicsId != EVENT_OBJ_GFX_ITEM_BALL)
            events[i].script = BattleFrontier_BattlePyramidEmptySquare_EventScript_252C4F;
        else
            events[i].script = BattleFrontier_BattlePyramidEmptySquare_EventScript_252C6A;
    }
}

static void sub_81AA33C(u8 *var0, u8 *var1)
{
    *var0 = gSaveBlock2Ptr->frontier.field_E22[3] % 16;
    *var1 = gSaveBlock2Ptr->frontier.field_E22[0] % 16;

    if (*var0 == *var1)
    {
        *var0 = (gSaveBlock2Ptr->frontier.field_E22[3] + 1 ) % 16;
        *var1 = (gSaveBlock2Ptr->frontier.field_E22[0] + 15) % 16;
    }
}

static void sub_81AA398(u8 arg0)
{
    s32 i;
    s32 count;
    s32 var_28;
    s32 r4;
    u32 bits = 0;
    u8 id = sub_81AA9E4();
    u8 *allocated = AllocZeroed(0x10);

    sub_81AA96C(allocated);
    r4 = gSaveBlock2Ptr->frontier.field_E22[2] % 16;
    if (arg0 == 0)
    {
        count = gUnknown_08613650[id].unk1;
        var_28 = 0;
    }
    else
    {
        count = gUnknown_08613650[id].unk0;
        var_28 = gUnknown_08613650[id].unk1;
    }

    for (i = 0; i < count; i++)
    {
        do
        {
            do
            {
                if (bits & 1)
                {
                    if (!(gBitTable[r4] & gSaveBlock2Ptr->frontier.field_E22[3]))
                        bits |= 2;
                }
                else
                {
                    if (gBitTable[r4] & gSaveBlock2Ptr->frontier.field_E22[3])
                        bits |= 2;
                }
                if (++r4 >= 16)
                    r4 = 0;

                if (r4 == gSaveBlock2Ptr->frontier.field_E22[2] % 16)
                {
                    if (bits & 1)
                        bits |= 6;
                    else
                        bits |= 1;
                }
            } while (!(bits & 2));

        } while (!(bits & 4) && sub_81AA760(arg0, allocated, r4, var_28 + i));
        bits &= 1;
    }
    free(allocated);
}

static bool8 sub_81AA4D8(u8 arg0, u8 arg1)
{
    s32 i;
    s32 var_28;
    s32 r6 = 0;
    s32 r7 = 0;
    s32 var_34 = 0;
    s32 count;
    u8 id = sub_81AA9E4();
    u8 *allocated = AllocZeroed(0x10);

    sub_81AA96C(allocated);
    if (arg0 == 0)
    {
        count = gUnknown_08613650[id].unk1;
        var_28 = 0;
    }
    else
    {
        count = gUnknown_08613650[id].unk0;
        var_28 = gUnknown_08613650[id].unk1;
    }

    for (i = 0; i < count; i++)
    {
        if (r7 == 0)
        {
            if (sub_81AA760(arg0, allocated, arg1, var_28 + i))
                r7 = 1;
            else
                var_34++;
        }
        if (r7 & 1)
        {
            if (sub_81AA760(arg0, allocated, gUnknown_08613F46[arg1][r6], var_28 + i))
            {
                do
                {
                    r6++;
                    if (gUnknown_08613F46[arg1][r6] == 0xFF || r6 >= 4)
                        r6 = 0;
                    r7 += 2;
                } while (r7 >> 1 != 4 && sub_81AA760(arg0, allocated, gUnknown_08613F46[arg1][r6], var_28 + i));
                var_34++;
            }
            else
            {
                r6++;
                if (gUnknown_08613F46[arg1][r6] == 0xFF || r6 >= 4)
                    r6 = 0;
                var_34++;
            }
        }

        if (r7 >> 1 == 4)
            break;

        r7 &= 1;
    }
    // free(allocated); BUG: allocated memory not freed

    return (count / 2 > var_34);
}

static bool8 sub_81AA648(u8 arg0, u8 arg1)
{
    s32 i;
    s32 var_28;
    s32 r4 = 0;
    s32 r7 = 0;
    s32 r8 = 0;
    s32 count;
    u8 id = sub_81AA9E4();
    u8 *allocated = AllocZeroed(0x10);

    sub_81AA96C(allocated);
    if (arg0 == 0)
    {
        count = gUnknown_08613650[id].unk1;
        var_28 = 0;
    }
    else
    {
        count = gUnknown_08613650[id].unk0;
        var_28 = gUnknown_08613650[id].unk1;
    }

    for (i = 0; i < count; i++)
    {
        if (sub_81AA760(arg0, allocated, gUnknown_08613F46[arg1][r4], var_28 + i))
        {
            do
            {
                r4++;
                if (gUnknown_08613F46[arg1][r4] == 0xFF || r4 >= 4)
                    r4 = 0;
                r8++;
            } while (r8 != 4 && sub_81AA760(arg0, allocated, gUnknown_08613F46[arg1][r4], var_28 + i));
            r7++;
        }
        else
        {
            r4++;
            if (gUnknown_08613F46[arg1][r4] == 0xFF || r4 >= 4)
                r4 = 0;
            r7++;
        }

        if (r8 == 4)
            break;
    }
    // free(allocated); BUG: allocated memory not freed

    return (count / 2 > r7);
}

static bool8 sub_81AA760(u8 arg0, u8 *mapNums, u8 whichMap, u8 id)
{
    s32 i, j;

    if (gSaveBlock2Ptr->frontier.field_E22[0] & 1)
    {
        s32 minus1 = -1;
        for (i = 7; i > minus1; i--)
        {
            for (j = 7; j >= 0; j--)
            {
                if (!sub_81AA810(arg0, j, i, mapNums, whichMap, id))
                    return FALSE;
            }
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (!sub_81AA810(arg0, j, i, mapNums, whichMap, id))
                    return FALSE;
            }
        }
    }

    return TRUE;
}

static bool8 sub_81AA810(u8 arg0, u8 x, u8 y, u8 *mapNums, u8 whichMap, u8 id)
{
    s32 i, j;
    const struct MapHeader *mapHeader;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;

    mapHeader = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(BATTLE_PYRAMID_SQUARE01), mapNums[whichMap] + MAP_NUM(BATTLE_PYRAMID_SQUARE01));
    for (i = 0; i < mapHeader->events->eventObjectCount; i++)
    {
        if (mapHeader->events->eventObjects[i].x != x || mapHeader->events->eventObjects[i].y != y)
            continue;

        if (arg0 != 0 || mapHeader->events->eventObjects[i].graphicsId == EVENT_OBJ_GFX_ITEM_BALL)
        {
            if (arg0 != 1 || mapHeader->events->eventObjects[i].graphicsId != EVENT_OBJ_GFX_ITEM_BALL)
                continue;
        }

        for (j = 0; j < id; j++)
        {
            if (events[j].x == x + ((whichMap % 4) * 8) && events[j].y == y + ((whichMap / 4) * 8))
                break;
        }
        if (j != id)
            continue;

        events[id] = mapHeader->events->eventObjects[i];
        events[id].x += ((whichMap % 4) * 8);
        events[id].y += ((whichMap / 4) * 8);
        events[id].localId = id + 1;
        if (events[id].graphicsId != EVENT_OBJ_GFX_ITEM_BALL)
        {
            i = sub_81A9F90(id);
            events[id].graphicsId = GetBattleFacilityTrainerGfxId(i);
            gSaveBlock2Ptr->frontier.field_CB4[id] = i;
        }
        return FALSE;
    }

    return TRUE;
}

static void sub_81AA96C(u8 *mapNums)
{
    s32 i;
    s32 bits = (gSaveBlock2Ptr->frontier.field_E22[0]) | (gSaveBlock2Ptr->frontier.field_E22[1] << 16);
    u8 id = sub_81AA9E4();

    for (i = 0; i < 16; i++)
    {
        mapNums[i] = gUnknown_08613650[id].unk5[bits & 7];
        bits >>= 3;
        if (i == 7)
        {
            bits = (gSaveBlock2Ptr->frontier.field_E22[2]) | (gSaveBlock2Ptr->frontier.field_E22[3] << 16);
            bits >>= 8;
        }
    }
}

static u8 sub_81AA9E4(void)
{
    s32 i;
    s32 var = gSaveBlock2Ptr->frontier.field_E22[3] % 100;
    s32 battleNum = gSaveBlock2Ptr->frontier.curChallengeBattleNum;

    for (i = gUnknown_08613794[battleNum]; i < ARRAY_COUNT(gUnknown_08613750); i++)
    {
        if (var < gUnknown_08613750[i][0])
            return gUnknown_08613750[i][1];
    }
    return 0;
}

u8 sub_81AAA40(void)
{
    u8 i;
    struct EventObjectTemplate *events = gSaveBlock1Ptr->eventObjectTemplates;

    for (i = 0; i < 16; i++)
    {
        if (events[i].localId == 0)
            break;
    }

    return i;
}

static void InitBagItems(u8 lvlMode)
{
    s32 i;

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        gSaveBlock2Ptr->frontier.pyramidBag.itemId[lvlMode][i] = 0;
        gSaveBlock2Ptr->frontier.pyramidBag.quantity[lvlMode][i] = 0;
    }

    AddPyramidBagItem(ITEM_HYPER_POTION, 1);
    AddPyramidBagItem(ITEM_ETHER, 1);
}

u16 GetBattlePyramidPickupItemId(void)
{
    s32 rand;
    u32 i;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    s32 round = (gSaveBlock2Ptr->frontier.pyramidWinStreaks[lvlMode] / 7);

    if (round >= TOTAL_ROUNDS)
        round = TOTAL_ROUNDS - 1;

    rand = Random() % 100;

    for (i = 0; i < ARRAY_COUNT(sPickupPercentages); i++)
    {
        if (sPickupPercentages[i] > rand)
            break;
    }

    if (i >= PICKUP_ITEMS_PER_ROUND)
        i = PICKUP_ITEMS_PER_ROUND - 1;

    if (lvlMode != FRONTIER_LVL_50)
        return sPickupItemsLvlOpen[round][i];
    else
        return sPickupItemsLvl50[round][i];
}
