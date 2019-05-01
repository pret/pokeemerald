#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_gfx_sfx_util.h"
#include "battle_interface.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "contest.h"
#include "data.h"
#include "decompress.h"
#include "easy_chat.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "field_control_avatar.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu.h"
#include "item_use.h"
#include "link.h"
#include "link_rfu.h"
#include "mail.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "menu_specialized.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_jump.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "reshow_battle_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "start_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trade.h"
#include "union_room.h"
#include "window.h"
#include "constants/battle.h"
#include "constants/battle_frontier.h"
#include "constants/easy_chat.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"

enum
{
    CAN_LEARN_MOVE,
    CANNOT_LEARN_MOVE,
    ALREADY_KNOWS_MOVE,
    CANNOT_LEARN_MOVE_IS_EGG
};

struct Unk_Rodata1
{
    void (*unk0)(u8, u8, u8, u8, u8, u8);
    u8 unk4[24];
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
};

struct Struct203CEC4
{
    TaskFunc unk0;
    MainCallback exitCallback;
    u32 unk8_0:1;
    u32 unk8_1:3;
    u32 unk8_2:7;
    u32 unk9_0:7;
    u32 unkA_0:14;
    u8 unkC[3];
    u8 unkF[8];
    u8 unk17;
    u16 palBuffer[0xB0];
    u8 filler[0xA0];
    s16 data[16];
};

struct Struct203CEDC
{
    const struct Unk_Rodata1 *unk0;
    const u8 *unk4;
    u8 windowId;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
};

// EWRAM vars
static EWRAM_DATA struct Struct203CEC4 *gUnknown_0203CEC4 = NULL;
EWRAM_DATA struct Struct203CEC8 gUnknown_0203CEC8 = {0};
static EWRAM_DATA struct Struct203CEDC *gUnknown_0203CEDC = NULL;
static EWRAM_DATA u8 *gUnknown_0203CEE0 = NULL;
static EWRAM_DATA u8 *gUnknown_0203CEE4 = NULL;
EWRAM_DATA u8 gUnknown_0203CEE8 = 0;
EWRAM_DATA u8 gUnknown_0203CEE9 = 0;
EWRAM_DATA MainCallback gPostMenuFieldCallback = NULL;
static EWRAM_DATA u16 *gUnknown_0203CEF0 = 0;
static EWRAM_DATA u16 *gUnknown_0203CEF4 = 0;
EWRAM_DATA u8 gSelectedOrderFromParty[4] = {0};
static EWRAM_DATA u16 gUnknown_0203CEFC = 0;
static EWRAM_DATA u16 gUnknown_0203CEFE = 0; // unused
EWRAM_DATA u8 gUnknown_0203CF00[3] = {0};

// IWRAM common
void (*gUnknown_03006328)(u8, TaskFunc);

static void reset_brm(void);
static void PartyMenuInitCallback(void);
static bool8 PartyMenuSetup(void);
static void sub_81B209C(void);
static void PartyMenuExit(void);
static bool8 AllocPartyMenuBg(void);
static bool8 AllocPartyMiscGfx(void);
static void sub_81B239C(u8);
static void PartyMenuInitHelperStructs(u8);
static void LoadPartyMenuPokeballGfx(void);
static void LoadPartyMenuAilmentGfx(void);
static bool8 party_menu_add_per_mon_objects(void);
static bool8 RenderPartyMenuBoxes(void);
static void sub_81B0F28(void);
static void sub_81B2428(u8);
static void PartyMenuExitTask(u8);
static void FreePartyPointers(void);
static void PartyPaletteBufferCopy(u8);
static void sub_81B0CEC(u8);
static void UpdateSelectedPartyBox(struct Struct203CEDC *, u8);
static void sub_81B2720(u8);
static void DisplayPartyPokemonSelectForRelearner(u8);
static void DisplayPartyPokemonSelectForContest(u8);
static void DisplayPartyPokemonSelectForBattle(u8);
static void sub_81B0B98(u8);
static void DisplayPartyPokemonSelectHeldItemRelated(u8);
static bool8 sub_81B0BFC(u8);
static void DisplayPartyPokemonData(u8);
static void DisplayPartyPokemonNickname(struct Pokemon *, struct Struct203CEDC *, u8);
static void DisplayPartyPokemonLevelCheck(struct Pokemon *, struct Struct203CEDC *, u8);
static void DisplayPartyPokemonGenderNidoranCheck(struct Pokemon *, struct Struct203CEDC *, u8);
static void DisplayPartyPokemonHPCheck(struct Pokemon *, struct Struct203CEDC *, u8);
static void DisplayPartyPokemonMaxHPCheck(struct Pokemon *, struct Struct203CEDC *, u8);
static void DisplayPartyPokemonHPBarCheck(struct Pokemon *, struct Struct203CEDC *);
static void DisplayPartyPokemonOtherText(u8, struct Struct203CEDC *, u8);
static u8 sub_81B8830(void);
static bool8 GetBattleEntryEligibility(struct Pokemon *);
static bool8 sub_81B218C(u8);
static void DisplayPartyPokemonSelectToTeachMove(u8, u16, u8);
static u8 CanMonLearnTMTutor(struct Pokemon *, u16, u8);
static void DisplayPartyPokemonBarDetail(u8, const u8*, u8, const u8*);
static void DisplayPartyPokemonLevel(u8, struct Struct203CEDC *);
static void DisplayPartyPokemonGender(u8, u16, u8*, struct Struct203CEDC *);
static void DisplayPartyPokemonHP(u16, struct Struct203CEDC *);
static void DisplayPartyPokemonMaxHP(u16, struct Struct203CEDC *);
static void DisplayPartyPokemonHPBar(u16, u16, struct Struct203CEDC *);
static void party_menu_link_mon_icon_anim(u16, u32, struct Struct203CEDC *, u8, u32);
static void party_menu_link_mon_held_item_object(u16, u16, struct Struct203CEDC *);
static void party_menu_link_mon_pokeball_object(u16, struct Struct203CEDC *);
static void party_menu_link_mon_status_condition_object(u16, u8, struct Struct203CEDC *);
static void party_menu_held_item_object(struct Pokemon *, struct Struct203CEDC *);
static void party_menu_pokeball_object(struct Pokemon *, struct Struct203CEDC *);
static void party_menu_icon_anim(struct Pokemon *, struct Struct203CEDC *, u32);
static void party_menu_status_condition_object(struct Pokemon *, struct Struct203CEDC *);
static u8 sub_81B5F74(u8, u8);
static void sub_81B120C(void);
static u8 sub_81B5F34(u8, u8);
static void AnimateSelectedPartyIcon(u8, u8);
static void sub_81B5F98(u8, u8);
static u8 GetPartyBoxPalBitfield(u8, u8);
static bool8 PartyBoxPal_ParnterOrDisqualifiedInArena(u8);
static u8 sub_81B8F38(u8);
static void c3_0811FAB4(u8);
static void sub_81B9080(void);
static void sub_81B4F88(void);
static void sub_81B15D0(u8, s8*);
static void sub_81B140C(u8, s8*);
static u16 PartyMenuButtonHandler(s8*);
static s8* sub_81B13EC(void);
static bool8 sub_81B15A4(u8*);
static void sub_81B302C(u8*);
static void sub_81B9140(void);
static void sub_81B6794(u8);
static void sub_81B7E4C(u8);
static void sub_81B8474(u8);
static void sub_81B7FAC(u8);
static void sub_81B3938(u8);
static void sub_81B21AC(u8, u8);
static void sub_81B36FC(u8);
static void sub_81B407C(u8);
static void sub_81B2210(u8);
static bool8 sub_81B1660(u8);
static const u8* sub_81B88BC(void);
static void sub_81B16D4(u8);
static void sub_81B334C(void);
static void sub_81B1708(u8);
static void sub_81B1C1C(u8);
static void UpdateCurrentPartySelection(s8*, s8);
static void SetNewPartySelectTarget1(s8*, s8);
static void SetNewPartySelectTarget2(s8*, s8);
static s8 sub_81B1B00(s8, s8);
static void sub_81B3300(const u8*);
static void sub_81B1B8C(u8);
static void DisplayPartyPokemonHPCheck(struct Pokemon*, struct Struct203CEDC*, u8);
static void DisplayPartyPokemonHPBarCheck(struct Pokemon*, struct Struct203CEDC*);
static bool16 sub_81B2134(struct Pokemon*);
static bool16 sub_81B2164(struct Pokemon*);
static void sub_81B2248(u8);
static void sub_81B227C(u8);
static bool8 CanLearnTutorMove(u16, u8);
static u16 GetTutorMove(u8);
static bool8 sub_81B314C(void);
static void sub_81B3414(struct Pokemon*, u8);
static u8 sub_81B8A2C(struct Pokemon*);
static u8 sub_81B856C(s8);
static void sub_81B469C(u8);
static void HandleMenuInput(u8);
static void sub_81B3828(void);
static void pokemon_change_order(void);
static void sub_81B3894(void);
static void sub_81B3CC0(u8);
static void sub_81B3D48(u8);
static void swap_pokemon_and_oams(void);
static void sub_81B3E60(u8);
static void sub_81B41C4(void);
static void c2_8123744(void);
static void sub_81B452C(void);
static void sub_81B4350(u8);
static void sub_81B42D0(u8);
static void sub_81B43A8(u8);
static void sub_81B43DC(u8);
static void sub_81B44FC(u8);
static void sub_81B4578(void);
static void sub_81B4624(u8);
static void sub_81B5C94(struct Pokemon*, struct Struct203CEDC*);
static void sub_81B48A8(u8);
static void sub_81B48DC(u8);
static void sub_81B4988(u8);
static void sub_81B4A98(void);
static void sub_81B4AE0(void);
static void sub_81B4B6C(u8);
static void sub_81B4BA0(u8);
static void sub_81B4C60(u8);
static void sub_81B4C94(u8);
static bool8 sub_81B8A7C(void);
static void sub_81B53FC(u8);
static void sub_81B5430(u8);
static void task_brm_cancel_1_on_keypad_a_or_b(u8);
static void sub_81B5674(u8);
static void sub_81B57DC(void);
static void sub_81B5864(void);
static void sub_81B56A4(u8);
static void sub_81B56D8(u8);
static void task_launch_hm_phase_2(u8);
static u16 brm_get_selected_species(void);
static void sub_81B5B38(u8, struct Pokemon*);
static void UpdatePartyMonIconFrame(struct Sprite*);
static void UpdatePartyMonIconFrameAndBounce(struct Sprite*);
static void sub_81B5CB0(u16, struct Struct203CEDC*);
static void sub_81B5DF0(u8, u8);
static void sub_81B5E74(struct Sprite*);
static void party_menu_get_status_condition_and_update_object(struct Pokemon*, struct Struct203CEDC*);
static void party_menu_update_status_condition_object(u8, struct Struct203CEDC*);
static u8 sub_81B8984(void);
static void sub_81B6280(u8);
static void c2_815ABFC(void);
static void sub_81B672C(u8);
static u16 ItemEffectToMonEv(struct Pokemon*, u8);
static void ItemEffectToStatString(u8, u8*);
static void sub_81B6BB4(u8);
static void ether_effect_related_2(u8);
static void ether_effect_related(u8);
static void sub_81B6EB4(u8);
static void sub_81B6FF4(u8);
static void sub_81B6F60(u8);
static void sub_81B6F98(u8);
static void sub_81B77AC(u8);
static void sub_81B7028(u8);
static void sub_81B7088(u8);
static void sub_81B7230(u8);
static void sub_81B70B8(void);
static void sub_81B70F0(void);
static void sub_81B711C(u8);
static void sub_81B7154(u8);
static void sub_81B71D4(u8);
static void sub_81B7294(u8);
static void sub_81B72C8(u8);
static void sub_81B73E4(u8);
static void sub_81B79A0(struct Pokemon*, s16*);
static void sub_81B754C(u8, struct Pokemon*);
static void sub_81B75D4(u8);
static void sub_81B767C(u8);
static void sub_81B7634(u8);
static void sub_81B76C8(u8);
static void sub_81B7704(u8);
static void sub_81B7810(u8);
static void sub_81B787C(u8);
static void sub_81B7910(u8, u16);
static void sub_81B7A28(u8);
static void task_sacred_ash_party_loop(u8);
static void sub_81B7C10(u8);
static void sub_81B8044(u8);
static void sub_81B83B8(u8);
static void sub_81B82A0(u8);
static void sub_81B83F0(u16);
static void sub_81B814C(void);
static void sub_81B8088(u8);
static void sub_81B8104(u8);
static void sub_81B81A8(void);
static bool8 sub_81B841C(u16);
static void sub_81B8230(u8);
static void sub_81B82D4(u8);
static void sub_81B879C(u8);
static bool8 GetBattleEntryEligibility(struct Pokemon*);
static bool8 sub_81B8770(u8);
static u8 sub_81B8888(void);
static u8 sub_81B885C(void);
static void sub_81B87E8(u8);
static void sub_81B8C88(u8*, bool8);
static void sub_81B8D88(u8*, u8, u8);
static void sub_81B917C(u8);
static void sub_81B91B4(u8);
static void sub_81B9294(u8);
static void sub_81B9240(u8);
static void sub_81B9390(void);
static void task_hm_without_phase_2(u8);
static void sub_81B9424(u8);
static void sub_81B9470(void);
static void sub_81B94D0(u8);
static void sub_81B953C(u8);
static void sub_81B9588(void);
static void sub_81B9640(u8);
static void sub_81B97DC(struct Pokemon*, u8, u8);
static void BlitBitmapToPartyWindow_Default1(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f);
static void BlitBitmapToPartyWindow_Default2(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f);
static void CursorCb_Summary(u8 taskId);
static void CursorCb_Switch(u8 taskId);
static void CursorCb_Cancel1(u8 taskId);
static void CursorCb_Item(u8 taskId);
static void CursorCb_Give(u8 taskId);
static void CursorCb_TakeItem(u8 taskId);
static void CursorCb_Mail(u8 taskId);
static void CursorCb_Read(u8 taskId);
static void CursorCb_TakeMail(u8 taskId);
static void CursorCb_Cancel2(u8 taskId);
static void CursorCb_SendMon(u8 taskId);
static void CursorCb_Enter(u8 taskId);
static void CursorCb_NoEntry(u8 taskId);
static void CursorCb_Store(u8 taskId);
static void CursorCb_Register(u8 taskId);
static void CursorCb_Trade1(u8 taskId);
static void CursorCb_Trade2(u8 taskId);
static void CursorCb_Toss(u8 taskId);
static void CursorCb_FieldMove(u8 taskId);
static bool8 SetUpFieldMove_Surf(void);
static bool8 SetUpFieldMove_Fly(void);
static bool8 SetUpFieldMove_Waterfall(void);
static bool8 SetUpFieldMove_Dive(void);

// static const data
#include "data/pokemon/tutor_learnsets.h"

static const struct BgTemplate gUnknown_086156B8[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
};

static const struct Unk_Rodata1 gUnknown_086156C4[] =
{
    {BlitBitmapToPartyWindow_Default1, {0x18, 0xB, 0x28, 0xD, 0x20, 0x14, 0x20, 8, 0x40, 0x14, 8, 8, 0x26, 0x25, 0x18, 8, 0x35, 0x25, 0x18, 8, 0x18, 0x23, 0x30, 3}, 0xC, 0x22, 0x40, 0x10},
    {BlitBitmapToPartyWindow_Default2, {0x16, 3, 0x28, 0xD, 0x1E, 0xC, 0x20, 8, 0x3E, 0xC, 8, 8, 0x66, 0xC, 0x18, 8, 0x75, 0xC, 0x18, 8, 0x58, 0xA, 0x30, 3}, 0x4D, 4, 0x40, 0x10},
};

static const u8 gUnknown_08615704[][6][8] =
{
	{
		{16, 40, 20, 50, 50, 52, 16, 34},
		{104, 18, 108, 28, 136, 27, 102, 25},
		{104, 42, 108, 52, 136, 51, 102, 49},
		{104, 66, 108, 76, 136, 75, 102, 73},
		{104, 90, 108, 100, 136, 99, 102, 97},
		{104, 114, 108, 124, 136, 123, 102, 121},
	},
	{
		{16, 24, 20, 34, 50, 36, 16, 18},
		{16, 80, 20, 90, 50, 92, 16, 74},
		{104, 18, 108, 28, 136, 27, 102, 25},
		{104, 50, 108, 60, 136, 59, 102, 57},
		{104, 82, 108, 92, 136, 91, 102, 89},
		{104, 114, 108, 124, 136, 123, 102, 121},
	},
	{
		{16, 24, 20, 34, 50, 36, 16, 18},
		{16, 80, 20, 90, 50, 92, 16, 74},
		{104, 26, 106, 36, 136, 35, 102, 33},
		{104, 50, 106, 60, 136, 59, 102, 57},
		{104, 82, 106, 92, 136, 91, 102, 89},
		{104, 106, 106, 116, 136, 115, 102, 113},
	},
	{
		{16, 32, 20, 42, 50, 44, 16, 26},
		{104, 34, 106, 44, 136, 43, 102, 41},
		{104, 58, 106, 68, 136, 67, 102, 65},
		{16, 104, 20, 114, 50, 116, 16, 98},
		{104, 106, 106, 116, 136, 115, 102, 113},
		{104, 130, 106, 140, 136, 139, 102, 137},
	},
};

static const u32 gUnknown_086157C4[] = INCBIN_U32("graphics/interface/unknown_6157C4.bin");
static const u32 gUnknown_086157E0[] = INCBIN_U32("graphics/interface/unknown_6157E0.bin");

static const u8 gUnknown_086157FC[][3] =
{
	{0, 3, 2},
	{0, 1, 6},
	{0, 11, 12},
	{1, 2, 3},
	{1, 8, 9},
	{0, 1, 2},
};

static const struct WindowTemplate gUnknown_08615810[] =
{
	{
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 3,
		.width = 10,
		.height = 7,
		.paletteNum = 3,
		.baseBlock = 0x63,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 1,
		.width = 18,
		.height = 3,
		.paletteNum = 4,
		.baseBlock = 0xA9,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 4,
		.width = 18,
		.height = 3,
		.paletteNum = 5,
		.baseBlock = 0xDF,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 7,
		.width = 18,
		.height = 3,
		.paletteNum = 6,
		.baseBlock = 0x115,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 10,
		.width = 18,
		.height = 3,
		.paletteNum = 7,
		.baseBlock = 0x14B,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 13,
		.width = 18,
		.height = 3,
		.paletteNum = 8,
		.baseBlock = 0x181,
	},
	{
		.bg = 2,
		.tilemapLeft = 1,
		.tilemapTop = 15,
		.width = 28,
		.height = 4,
		.paletteNum = 14,
		.baseBlock = 0x1DF,
	},
	DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate gUnknown_08615850[] =
{
	{
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 1,
		.width = 10,
		.height = 7,
		.paletteNum = 3,
		.baseBlock = 0x63,
	},
	{
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 8,
		.width = 10,
		.height = 7,
		.paletteNum = 4,
		.baseBlock = 0xA9,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 1,
		.width = 18,
		.height = 3,
		.paletteNum = 5,
		.baseBlock = 0xEF,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 5,
		.width = 18,
		.height = 3,
		.paletteNum = 6,
		.baseBlock = 0x125,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 9,
		.width = 18,
		.height = 3,
		.paletteNum = 7,
		.baseBlock = 0x15B,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 13,
		.width = 18,
		.height = 3,
		.paletteNum = 8,
		.baseBlock = 0x191,
	},
	{
		.bg = 2,
		.tilemapLeft = 1,
		.tilemapTop = 15,
		.width = 28,
		.height = 4,
		.paletteNum = 14,
		.baseBlock = 0x1DF,
	},
	DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate gUnknown_08615890[] =
{
	{
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 1,
		.width = 10,
		.height = 7,
		.paletteNum = 3,
		.baseBlock = 0x63,
	},
	{
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 8,
		.width = 10,
		.height = 7,
		.paletteNum = 4,
		.baseBlock = 0xA9,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 2,
		.width = 18,
		.height = 3,
		.paletteNum = 5,
		.baseBlock = 0xEF,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 5,
		.width = 18,
		.height = 3,
		.paletteNum = 6,
		.baseBlock = 0x125,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 9,
		.width = 18,
		.height = 3,
		.paletteNum = 7,
		.baseBlock = 0x15B,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 12,
		.width = 18,
		.height = 3,
		.paletteNum = 8,
		.baseBlock = 0x191,
	},
	{
		.bg = 2,
		.tilemapLeft = 1,
		.tilemapTop = 15,
		.width = 28,
		.height = 4,
		.paletteNum = 14,
		.baseBlock = 0x1DF,
	},
	DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate gUnknown_086158D0[] =
{
	{
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 2,
		.width = 10,
		.height = 7,
		.paletteNum = 3,
		.baseBlock = 0x63,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 3,
		.width = 18,
		.height = 3,
		.paletteNum = 5,
		.baseBlock = 0xA9,
	},
	{
		.bg = 0,
		.tilemapLeft = 12,
		.tilemapTop = 6,
		.width = 18,
		.height = 3,
		.paletteNum = 6,
		.baseBlock = 0xDF,
	},
	{
		.bg = 2,
		.tilemapLeft = 1,
		.tilemapTop = 11,
		.width = 10,
		.height = 7,
		.paletteNum = 4,
		.baseBlock = 0x115,
	},
	{
		.bg = 2,
		.tilemapLeft = 12,
		.tilemapTop = 12,
		.width = 18,
		.height = 3,
		.paletteNum = 7,
		.baseBlock = 0x16B,
	},
	{
		.bg = 2,
		.tilemapLeft = 12,
		.tilemapTop = 15,
		.width = 18,
		.height = 3,
		.paletteNum = 8,
		.baseBlock = 0x1A1,
	},
	DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate gUnknown_08615908 =
{
	.bg = 0,
	.tilemapLeft = 24,
	.tilemapTop = 17,
	.width = 6,
	.height = 2,
	.paletteNum = 3,
	.baseBlock = 0x1C7,
};

static const struct WindowTemplate gUnknown_08615910 =
{
	.bg = 0,
	.tilemapLeft = 24,
	.tilemapTop = 18,
	.width = 6,
	.height = 2,
	.paletteNum = 3,
	.baseBlock = 0x1C7,
};

static const struct WindowTemplate gUnknown_08615918 =
{
	.bg = 0,
	.tilemapLeft = 24,
	.tilemapTop = 16,
	.width = 6,
	.height = 2,
	.paletteNum = 3,
	.baseBlock = 0x1D3,
};

static const struct WindowTemplate gUnknown_08615920 =
{
	.bg = 2,
	.tilemapLeft = 1,
	.tilemapTop = 17,
	.width = 21,
	.height = 2,
	.paletteNum = 15,
	.baseBlock = 0x24F,
};

static const struct WindowTemplate gUnknown_08615928 =
{
	.bg = 2,
	.tilemapLeft = 1,
	.tilemapTop = 17,
	.width = 16,
	.height = 2,
	.paletteNum = 15,
	.baseBlock = 0x279,
};

static const struct WindowTemplate gUnknown_08615930 =
{
	.bg = 2,
	.tilemapLeft = 1,
	.tilemapTop = 17,
	.width = 20,
	.height = 2,
	.paletteNum = 15,
	.baseBlock = 0x299,
};

static const struct WindowTemplate gUnknown_08615938 =
{
	.bg = 2,
	.tilemapLeft = 1,
	.tilemapTop = 17,
	.width = 18,
	.height = 2,
	.paletteNum = 15,
	.baseBlock = 0x299,
};

static const struct WindowTemplate gUnknown_08615940 =
{
	.bg = 2,
	.tilemapLeft = 1,
	.tilemapTop = 17,
	.width = 16,
	.height = 2,
	.paletteNum = 15,
	.baseBlock = 0x299,
};

static const struct WindowTemplate gUnknown_08615948 =
{
	.bg = 2,
	.tilemapLeft = 1,
	.tilemapTop = 15,
	.width = 20,
	.height = 4,
	.paletteNum = 15,
	.baseBlock = 0x299,
};

static const struct WindowTemplate gUnknown_08615950 =
{
	.bg = 2,
	.tilemapLeft = 23,
	.tilemapTop = 13,
	.width = 6,
	.height = 6,
	.paletteNum = 14,
	.baseBlock = 0x39D,
};

static const struct WindowTemplate gUnknown_08615958 =
{
	.bg = 2,
	.tilemapLeft = 21,
	.tilemapTop = 13,
	.width = 8,
	.height = 6,
	.paletteNum = 14,
	.baseBlock = 0x39D,
};

static const struct WindowTemplate gUnknown_08615960 =
{
	.bg = 2,
	.tilemapLeft = 19,
	.tilemapTop = 11,
	.width = 10,
	.height = 8,
	.paletteNum = 14,
	.baseBlock = 0x2E9,
};

static const struct WindowTemplate gUnknown_08615968 =
{
	.bg = 2,
	.tilemapLeft = 21,
	.tilemapTop = 9,
	.width = 5,
	.height = 4,
	.paletteNum = 14,
	.baseBlock = 0x2E9,
};

static const struct WindowTemplate gUnknown_08615970 =
{
	.bg = 2,
	.tilemapLeft = 19,
	.tilemapTop = 1,
	.width = 10,
	.height = 11,
	.paletteNum = 14,
	.baseBlock = 0x2E9,
};

// Unused.
static const struct WindowTemplate gUnknown_08615978 =
{
	.bg = 2,
	.tilemapLeft = 2,
	.tilemapTop = 15,
	.width = 27,
	.height = 4,
	.paletteNum = 14,
	.baseBlock = 0x1DF,
};

// Unused.
static const struct WindowTemplate gUnknown_08615980 =
{
	.bg = 2,
	.tilemapLeft = 0,
	.tilemapTop = 13,
	.width = 18,
	.height = 3,
	.paletteNum = 12,
	.baseBlock = 0x39D,
};

static const u8 gUnknown_08615988[] = {24, 25, 25, 25, 25, 25, 25, 25, 25, 26, 32, 33, 33, 33, 33, 33, 33, 33, 33, 34, 32, 33, 33, 33, 33, 33, 33, 33, 33, 34, 32, 33, 33, 33, 33, 33, 33, 33, 33, 34, 40, 59, 60, 58, 58, 58, 58, 58, 58, 61, 15, 16, 16, 16, 16, 16, 16, 16, 16, 17, 46, 47, 47, 47, 47, 47, 47, 47, 47, 48};
static const u8 gUnknown_086159CE[] = {24, 25, 25, 25, 25, 25, 25, 25, 25, 26, 32, 33, 33, 33, 33, 33, 33, 33, 33, 34, 32, 33, 33, 33, 33, 33, 33, 33, 33, 34, 32, 33, 33, 33, 33, 33, 33, 33, 33, 34, 40, 41, 41, 41, 41, 41, 41, 41, 41, 42, 15, 16, 16, 16, 16, 16, 16, 16, 16, 17, 46, 47, 47, 47, 47, 47, 47, 47, 47, 48};
static const u8 gUnknown_08615A14[] = {43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45, 49, 33, 33, 33, 33, 33, 33, 33, 33, 52, 53, 51, 51, 51, 51, 51, 51, 54, 55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57};
static const u8 gUnknown_08615A4A[] = {43, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 45, 49, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 50, 55, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 57};
static const u8 gUnknown_08615A80[] = {21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 23, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 37, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39};
static const u8 gUnknown_08615AB6[] = {11, 12};
static const u8 gUnknown_08615AB8[] = {9, 10};
static const u8 gUnknown_08615ABA[] = {4, 5, 6};
static const u8 gUnknown_08615ABD[] = {1, 7, 8};
static const u8 gUnknown_08615AC0[] = {1, 11, 12};
static const u8 gUnknown_08615AC3[] = {59, 60};
static const u8 gUnknown_08615AC5[] = {75, 76};
static const u8 gUnknown_08615AC7[] = {57, 58};
static const u8 gUnknown_08615AC9[] = {73, 74};
static const u8 gUnknown_08615ACB[] = {89, 90};
static const u8 gUnknown_08615ACD[] = {52, 53, 54};
static const u8 gUnknown_08615AD0[] = {68, 69, 70};
static const u8 gUnknown_08615AD3[] = {84, 85, 86};
static const u8 gUnknown_08615AD6[] = {116, 117, 118};
static const u8 gUnknown_08615AD9[] = {132, 133, 134};
static const u8 gUnknown_08615ADC[] = {148, 149, 150};
static const u8 gUnknown_08615ADF[] = {100, 101, 102};
static const u8 gUnknown_08615AE2[] = {49, 55, 56};
static const u8 gUnknown_08615AE5[] = {65, 71, 72};
static const u8 gUnknown_08615AE8[] = {81, 87, 88};
static const u8 gUnknown_08615AEB[] = {97, 103, 104};
static const u8 gUnknown_08615AEE[] = {161, 167, 168};
static const u8 gUnknown_08615AF1[] = {17, 27, 28};

static const u8 *const gUnknown_08615AF4[] =
{
    gUnknown_085E9E43,
    gUnknown_085EA010,
    gUnknown_085EA02A,
    gUnknown_085E9E55,
    gUnknown_085E9E64,
    gUnknown_085E9E79,
    gUnknown_085E9E8F,
    gUnknown_085E9EBC,
    gUnknown_085E9ED4,
    gUnknown_085E9EE9,
    gUnknown_085E9FDB,
    gUnknown_085EA046,
    gUnknown_085EA05B,
    gUnknown_085E9F01,
    gUnknown_085E9F58,
    gUnknown_085E9F6F,
    gUnknown_085E9F81,
    gUnknown_085E9F90,
    gUnknown_085E9FA7,
    gUnknown_085E9FC2,
    gText_EmptyString2,
    gUnknown_085E9EA6,
    gUnknown_085E9F16,
    gUnknown_085E9F2A,
    gUnknown_085E9F42,
    gUnknown_085E9FF9,
    gUnknown_085EA073,
};

static const u8 *const gUnknown_08615B60[] =
{
    gUnknown_085EA091,
    gUnknown_085EA099,
    gUnknown_085EA09E,
    gUnknown_085EA0A4,
    gUnknown_085EA0AB,
    gUnknown_085EA0E7,
    gUnknown_085EA0B1,
    gUnknown_085EA0B6,
    gUnknown_085EA0BF,
    gUnknown_085EA0C5,
    gUnknown_085EA0CF,
    gUnknown_085EA0D7,
    gUnknown_085EA0DC,
};

// Unknown unused data. Feel free to remove.
static const u16 gUnknown_08615B94[] =
{
    0x0108, 0x0151, 0x0160, 0x015b, 0x002e, 0x005c, 0x0102, 0x0153, 0x014b, 0x00ed, 0x00f1, 0x010d, 0x003a, 0x003b, 0x003f, 0x0071,
    0x00b6, 0x00f0, 0x00ca, 0x00db, 0x00da, 0x004c, 0x00e7, 0x0055, 0x0057, 0x0059, 0x00d8, 0x005b, 0x005e, 0x00f7, 0x0118, 0x0068,
    0x0073, 0x015f, 0x0035, 0x00bc, 0x00c9, 0x007e, 0x013d, 0x014c, 0x0103, 0x0107, 0x0122, 0x009c, 0x00d5, 0x00a8, 0x00d3, 0x011d,
    0x0121, 0x013b, 0x000f, 0x0013, 0x0039, 0x0046, 0x0094, 0x00f9, 0x007f, 0x0123,
};

enum
{
    MENU_SUMMARY,
    MENU_SWITCH,
    MENU_CANCEL1,
    MENU_ITEM,
    MENU_GIVE,
    MENU_TAKE_ITEM,
    MENU_MAIL,
    MENU_TAKE_MAIL,
    MENU_READ,
    MENU_CANCEL2,
    MENU_SHIFT,
    MENU_SEND_OUT,
    MENU_ENTER,
    MENU_NO_ENTRY,
    MENU_STORE,
    MENU_REGISTER,
    MENU_TRADE1,
    MENU_TRADE2,
    MENU_TOSS,
    MENU_FIELD_MOVES,
};

enum
{
    FIELD_MOVE_CUT,
    FIELD_MOVE_FLASH,
    FIELD_MOVE_ROCK_SMASH,
    FIELD_MOVE_STRENGTH,
    FIELD_MOVE_SURF,
    FIELD_MOVE_FLY,
    FIELD_MOVE_DIVE,
    FIELD_MOVE_WATERFALL,
    FIELD_MOVE_TELEPORT,
    FIELD_MOVE_DIG,
    FIELD_MOVE_SECRET_POWER,
    FIELD_MOVE_MILK_DRINK,
    FIELD_MOVE_SOFT_BOILED,
    FIELD_MOVE_SWEET_SCENT,
};

// What a weird choice of table termination;
#define FIELD_MOVE_TERMINATOR MOVE_SWORDS_DANCE

struct
{
    const u8 *text;
    TaskFunc func;
} static const sCursorOptions[] =
{
    [MENU_SUMMARY] = {gText_Summary5, CursorCb_Summary},
    [MENU_SWITCH] = {gText_Switch2, CursorCb_Switch},
    [MENU_CANCEL1] = {gText_Cancel2, CursorCb_Cancel1},
    [MENU_ITEM] = {gText_Item, CursorCb_Item},
    [MENU_GIVE] = {gMenuText_Give, CursorCb_Give},
    [MENU_TAKE_ITEM] = {gText_Take, CursorCb_TakeItem},
    [MENU_MAIL] = {gText_Mail, CursorCb_Mail},
    [MENU_TAKE_MAIL] = {gText_Take2, CursorCb_TakeMail},
    [MENU_READ] = {gText_Read2, CursorCb_Read},
    [MENU_CANCEL2] = {gText_Cancel2, CursorCb_Cancel2},
    [MENU_SHIFT] = {gText_Shift, CursorCb_SendMon},
    [MENU_SEND_OUT] = {gText_SendOut, CursorCb_SendMon},
    [MENU_ENTER] = {gText_Enter, CursorCb_Enter},
    [MENU_NO_ENTRY] = {gText_NoEntry, CursorCb_NoEntry},
    [MENU_STORE] = {gText_Store, CursorCb_Store},
    [MENU_REGISTER] = {gText_Register, CursorCb_Register},
    [MENU_TRADE1] = {gText_Trade4, CursorCb_Trade1},
    [MENU_TRADE2] = {gText_Trade4, CursorCb_Trade2},
    [MENU_TOSS] = {gMenuText_Toss, CursorCb_Toss},
    [MENU_FIELD_MOVES + FIELD_MOVE_CUT] = {gMoveNames[MOVE_CUT], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_FLASH] = {gMoveNames[MOVE_FLASH], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_ROCK_SMASH] = {gMoveNames[MOVE_ROCK_SMASH], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_STRENGTH] = {gMoveNames[MOVE_STRENGTH], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SURF] = {gMoveNames[MOVE_SURF], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_FLY] = {gMoveNames[MOVE_FLY], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_DIVE] = {gMoveNames[MOVE_DIVE], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_WATERFALL] = {gMoveNames[MOVE_WATERFALL], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_TELEPORT] = {gMoveNames[MOVE_TELEPORT], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_DIG] = {gMoveNames[MOVE_DIG], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SECRET_POWER] = {gMoveNames[MOVE_SECRET_POWER], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_MILK_DRINK] = {gMoveNames[MOVE_MILK_DRINK], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SOFT_BOILED] = {gMoveNames[MOVE_SOFT_BOILED], CursorCb_FieldMove},
    [MENU_FIELD_MOVES + FIELD_MOVE_SWEET_SCENT] = {gMoveNames[MOVE_SWEET_SCENT], CursorCb_FieldMove},
};

static const u8 gUnknown_08615D10[] = {0, 1, 2};
static const u8 gUnknown_08615D13[] = {10, 0, 2};
static const u8 gUnknown_08615D16[] = {11, 0, 2};
static const u8 gUnknown_08615D19[] = {0, 2};
static const u8 gUnknown_08615D1B[] = {12, 0, 2};
static const u8 gUnknown_08615D1E[] = {13, 0, 2};
static const u8 gUnknown_08615D21[] = {14, 0, 2};
static const u8 gUnknown_08615D24[] = {4, 5, 9};
static const u8 gUnknown_08615D27[] = {8, 7, 9};
static const u8 gUnknown_08615D2A[] = {15, 0, 2};
static const u8 gUnknown_08615D2D[] = {16, 0, 2};
static const u8 gUnknown_08615D30[] = {17, 0, 2};
static const u8 gUnknown_08615D33[] = {5, 18, 2};

static const u8 *const gUnknown_08615D38[] =
{
    NULL,
    gUnknown_08615D10,
    gUnknown_08615D13,
    gUnknown_08615D16,
    gUnknown_08615D1B,
    gUnknown_08615D1E,
    gUnknown_08615D21,
    gUnknown_08615D19,
    gUnknown_08615D24,
    gUnknown_08615D27,
    gUnknown_08615D2A,
    gUnknown_08615D2D,
    gUnknown_08615D30,
    gUnknown_08615D33,
};

static const u8 gUnknown_08615D70[] = {0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03};

static const u16 sFieldMoves[] =
{
    MOVE_CUT, MOVE_FLASH, MOVE_ROCK_SMASH, MOVE_STRENGTH, MOVE_SURF, MOVE_FLY, MOVE_DIVE, MOVE_WATERFALL, MOVE_TELEPORT,
    MOVE_DIG, MOVE_SECRET_POWER, MOVE_MILK_DRINK, MOVE_SOFT_BOILED, MOVE_SWEET_SCENT, FIELD_MOVE_TERMINATOR
};

struct
{
    bool8 (*fieldMoveFunc)(void);
    u8 msgId;
} static const sFieldMoveCursorCallbacks[] =
{
    [FIELD_MOVE_CUT] = {SetUpFieldMove_Cut, 0x07},
    [FIELD_MOVE_FLASH] = {SetUpFieldMove_Flash, 0x0d},
    [FIELD_MOVE_ROCK_SMASH] = {SetUpFieldMove_RockSmash, 0x0d},
    [FIELD_MOVE_STRENGTH] = {SetUpFieldMove_Strength, 0x0d},
    [FIELD_MOVE_SURF] = {SetUpFieldMove_Surf, 0x08},
    [FIELD_MOVE_FLY] = {SetUpFieldMove_Fly, 0x0d},
    [FIELD_MOVE_DIVE] = {SetUpFieldMove_Dive, 0x0d},
    [FIELD_MOVE_WATERFALL] = {SetUpFieldMove_Waterfall, 0x0d},
    [FIELD_MOVE_TELEPORT] = {SetUpFieldMove_Teleport, 0x0d},
    [FIELD_MOVE_DIG] = {SetUpFieldMove_Dig, 0x0d},
    [FIELD_MOVE_SECRET_POWER] = {SetUpFieldMove_SecretPower, 0x0d},
    [FIELD_MOVE_MILK_DRINK] = {SetUpFieldMove_SoftBoiled, 0x10},
    [FIELD_MOVE_SOFT_BOILED] = {SetUpFieldMove_SoftBoiled, 0x10},
    [FIELD_MOVE_SWEET_SCENT] = {SetUpFieldMove_SweetScent, 0x0d},
};

static const u8 *const gUnknown_08615E0C[] =
{
    gText_NotPkmnOtherTrainerWants,
    gText_ThatIsntAnEgg,
    gText_PkmnCantBeTradedNow,
    gText_PkmnCantBeTradedNow,
    gText_OtherTrainersPkmnCantBeTraded,
    gText_EggCantBeTradedNow,
    gText_OtherTrainerCantAcceptPkmn,
    gText_CantTradeWithTrainer,
    gText_CantTradeWithTrainer,
};

static const u32 gUnknown_08615E30[] = INCBIN_U32("graphics/interface/hold_icons.4bpp");
static const u16 gUnknown_08615E70[] = INCBIN_U16("graphics/interface/hold_icons.gbapal");

static const struct OamData gOamData_83765EC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd gSpriteAnim_83765F4[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_83765FC[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_8376604[] =
{
    gSpriteAnim_83765F4,
    gSpriteAnim_83765FC,
};

static const struct SpriteSheet gUnknown_08615EB0 =
{
    gUnknown_08615E30, sizeof(gUnknown_08615E30), 0xd750
};

static const struct SpritePalette gUnknown_08615EB8 =
{
    gUnknown_08615E70, 0xd750
};

static const struct SpriteTemplate gSpriteTemplate_8615EC0 =
{
    0xd750,
    0xd750,
    &gOamData_83765EC,
    gSpriteAnimTable_8376604,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const struct OamData sOamData_8615ED8 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_8615EE0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615EE8[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8615EF0[] =
{
    sSpriteAnim_8615EE0,
    sSpriteAnim_8615EE8
};

static const struct CompressedSpriteSheet gUnknown_08615EF8 =
{
    gPartyMenuPokeball_Gfx, 0x400, 0x04b0
};

static const struct CompressedSpritePalette gUnknown_08615F00 =
{
    gPartyMenuPokeball_Pal, 0x04b0
};

static const struct SpriteTemplate gSpriteTemplate_8615F08 =
{
    .tileTag = 0x04b0,
    .paletteTag = 0x04b0,
    .oam = &sOamData_8615ED8,
    .anims = sSpriteAnimTable_8615EF0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_8615F20 =
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
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_8615F28[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615F30[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615F38[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615F40[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615F48[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615F50[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8615F58[] =
{
    sSpriteAnim_8615F28,
    sSpriteAnim_8615F30,
    sSpriteAnim_8615F38,
    sSpriteAnim_8615F40,
    sSpriteAnim_8615F48,
    sSpriteAnim_8615F50
};

static const struct CompressedSpriteSheet gUnknown_08615F70 =
{
    gPartyMenuPokeballSmall_Gfx, 0x0300, 0x04b1
};

static const struct SpriteTemplate gSpriteTemplate_8615F78 =
{
    .tileTag = 1201,
    .paletteTag = 1200,
    .oam = &sOamData_8615F20,
    .anims = sSpriteAnimTable_8615F58,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_8615F90 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_8615F98[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615FA0[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615FA8[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615FB0[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615FB8[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615FC0[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615FC8[] =
{
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8615FD0[] =
{
    ANIMCMD_FRAME(28, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8615FD8[] =
{
    sSpriteAnim_8615F98,
    sSpriteAnim_8615FA0,
    sSpriteAnim_8615FA8,
    sSpriteAnim_8615FB0,
    sSpriteAnim_8615FB8,
    sSpriteAnim_8615FC0,
    sSpriteAnim_8615FC8,
    sSpriteAnim_8615FD0
};

static const struct CompressedSpriteSheet gUnknown_08615FF8 =
{
    gStatusGfx_Icons, 0x400, 1202
};

static const struct CompressedSpritePalette gUnknown_08616000 =
{
    gStatusPal_Icons, 1202
};

static const struct SpriteTemplate gSpriteTemplate_8616008 =
{
    .tileTag = 1202,
    .paletteTag = 1202,
    .oam = &sOamData_8615F90,
    .anims = sSpriteAnimTable_8615FD8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 gUnknown_08616020[] = {0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00};

// Unused table of pointers to strings of statistics.
static const u8 *const gUnknown_08616028[] =
{
    gText_HP4,
    gText_Attack3,
    gText_Defense3,
    gText_SpAtk4,
    gText_SpDef4,
    gText_Speed2
};

static const u16 gTMHMMoves[] =
{
    MOVE_FOCUS_PUNCH,
    MOVE_DRAGON_CLAW,
    MOVE_WATER_PULSE,
    MOVE_CALM_MIND,
    MOVE_ROAR,
    MOVE_TOXIC,
    MOVE_HAIL,
    MOVE_BULK_UP,
    MOVE_BULLET_SEED,
    MOVE_HIDDEN_POWER,
    MOVE_SUNNY_DAY,
    MOVE_TAUNT,
    MOVE_ICE_BEAM,
    MOVE_BLIZZARD,
    MOVE_HYPER_BEAM,
    MOVE_LIGHT_SCREEN,
    MOVE_PROTECT,
    MOVE_RAIN_DANCE,
    MOVE_GIGA_DRAIN,
    MOVE_SAFEGUARD,
    MOVE_FRUSTRATION,
    MOVE_SOLAR_BEAM,
    MOVE_IRON_TAIL,
    MOVE_THUNDERBOLT,
    MOVE_THUNDER,
    MOVE_EARTHQUAKE,
    MOVE_RETURN,
    MOVE_DIG,
    MOVE_PSYCHIC,
    MOVE_SHADOW_BALL,
    MOVE_BRICK_BREAK,
    MOVE_DOUBLE_TEAM,
    MOVE_REFLECT,
    MOVE_SHOCK_WAVE,
    MOVE_FLAMETHROWER,
    MOVE_SLUDGE_BOMB,
    MOVE_SANDSTORM,
    MOVE_FIRE_BLAST,
    MOVE_ROCK_TOMB,
    MOVE_AERIAL_ACE,
    MOVE_TORMENT,
    MOVE_FACADE,
    MOVE_SECRET_POWER,
    MOVE_REST,
    MOVE_ATTRACT,
    MOVE_THIEF,
    MOVE_STEEL_WING,
    MOVE_SKILL_SWAP,
    MOVE_SNATCH,
    MOVE_OVERHEAT,
    MOVE_CUT,
    MOVE_FLY,
    MOVE_SURF,
    MOVE_STRENGTH,
    MOVE_FLASH,
    MOVE_ROCK_SMASH,
    MOVE_WATERFALL,
    MOVE_DIVE,
};

// code
static void InitPartyMenu(u8 a, u8 b, u8 c, u8 d, u8 e, TaskFunc task, MainCallback callback)
{
    u16 i;

    reset_brm();
    gUnknown_0203CEC4 = Alloc(sizeof(struct Struct203CEC4));
    if (gUnknown_0203CEC4 == NULL)
    {
        SetMainCallback2(callback);
    }
    else
    {
        gUnknown_0203CEC8.unk8_0 = a;
        gUnknown_0203CEC8.exitCallback = callback;
        gUnknown_0203CEC8.unkB = c;
        gUnknown_0203CEC4->unkA_0 = e;
        gUnknown_0203CEC4->unk0 = task;
        gUnknown_0203CEC4->exitCallback = NULL;
        gUnknown_0203CEC4->unk8_1 = 0;
        gUnknown_0203CEC4->unk8_2 = 0xFF;
        gUnknown_0203CEC4->unk9_0 = 0xFF;

        if (a == 4)
            gUnknown_0203CEC4->unk8_0 = TRUE;
        else
            gUnknown_0203CEC4->unk8_0 = FALSE;

        if (b != 0xFF)
            gUnknown_0203CEC8.mode = b;

        for (i = 0; i <= 15; i++)
            gUnknown_0203CEC4->data[i] = 0;
        for (i = 0; i < 3; i++)
            gUnknown_0203CEC4->unkC[i] = 0xFF;

        if (d == 0)
            gUnknown_0203CEC8.unk9 = 0;
        else if (gUnknown_0203CEC8.unk9 > 5 || GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES) == SPECIES_NONE)
            gUnknown_0203CEC8.unk9 = 0; // wut why is this else if?

        gTextFlags.autoScroll = 0;
        CalculatePlayerPartyCount();
        SetMainCallback2(PartyMenuInitCallback);
    }
}

static void PartyMenuCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void PartyMenuVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void PartyMenuInitCallback(void)
{
    while (TRUE)
    {
        if (sub_81221EC() == TRUE || PartyMenuSetup() == TRUE || sub_81221AC() == TRUE)
            break;
    }
}

static bool8 PartyMenuSetup(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        clear_scheduled_bg_copies_to_vram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        if (!sub_81221AC())
            ResetTasks();
        gMain.state++;
        break;
    case 6:
        sub_81B209C();
        gMain.state++;
        break;
    case 7:
        if (!AllocPartyMenuBg())
        {
            PartyMenuExit();
            return TRUE;
        }
        else
        {
            gUnknown_0203CEC4->data[0] = 0;
            gMain.state++;
        }
        break;
    case 8:
        if (AllocPartyMiscGfx())
            gMain.state++;
        break;
    case 9:
        sub_81B239C(gUnknown_0203CEC8.mode);
        gMain.state++;
        break;
    case 10:
        PartyMenuInitHelperStructs(gUnknown_0203CEC8.mode);
        gUnknown_0203CEC4->data[0] = 0;
        gMain.state++;
        break;
    case 11:
        LoadHeldItemIcons();
        gMain.state++;
        break;
    case 12:
        LoadPartyMenuPokeballGfx();
        gMain.state++;
        break;
    case 13:
        LoadPartyMenuAilmentGfx();
        gMain.state++;
        break;
    case 14:
        LoadMonIconPalettes();
        gMain.state++;
        break;
    case 15:
        if (party_menu_add_per_mon_objects())
        {
            gUnknown_0203CEC4->data[0] = 0;
            gMain.state++;
        }
        break;
    case 16:
        if (RenderPartyMenuBoxes())
        {
            gUnknown_0203CEC4->data[0] = 0;
            gMain.state++;
        }
        break;
    case 17:
        sub_81B0F28();
        gMain.state++;
        break;
    case 18:
        sub_81B2428(gUnknown_0203CEC4->unk8_0);
        gMain.state++;
        break;
    case 19:
        gMain.state++;
        break;
    case 20:
        CreateTask(gUnknown_0203CEC4->unk0, 0);
        display_pokemon_menu_message(gUnknown_0203CEC4->unkA_0);
        gMain.state++;
        break;
    case 21:
        BlendPalettes(0xFFFFFFFF, 16, 0);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    case 22:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(PartyMenuVBlankCallback);
        SetMainCallback2(PartyMenuCallback);
        return TRUE;
    }
    return FALSE;
}

static void PartyMenuExit(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(PartyMenuExitTask, 0);
    SetVBlankCallback(PartyMenuVBlankCallback);
    SetMainCallback2(PartyMenuCallback);
}

static void PartyMenuExitTask(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(gUnknown_0203CEC8.exitCallback);
        FreePartyPointers();
        DestroyTask(taskId);
    }
}

static void reset_brm(void)
{
    gUnknown_0203CEC4 = NULL;
    gUnknown_0203CEE4 = NULL;
    gUnknown_0203CEDC = NULL;
    gUnknown_0203CEE0 = NULL;
}

static bool8 AllocPartyMenuBg(void)
{
    gUnknown_0203CEE4 = Alloc(0x800);
    if (gUnknown_0203CEE4 == NULL)
        return FALSE;

    memset(gUnknown_0203CEE4, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_086156B8, ARRAY_COUNT(gUnknown_086156B8));
    SetBgTilemapBuffer(1, gUnknown_0203CEE4);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 AllocPartyMiscGfx(void)
{
    int sizeout;

    switch (gUnknown_0203CEC4->data[0])
    {
    case 0:
        gUnknown_0203CEE0 = malloc_and_decompress(gPartyMenuMisc_Gfx, &sizeout);
        LoadBgTiles(1, gUnknown_0203CEE0, sizeout, 0);
        gUnknown_0203CEC4->data[0]++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            LZDecompressWram(gPartyMenuMisc_Tilemap, gUnknown_0203CEE4);
            gUnknown_0203CEC4->data[0]++;
        }
        break;
    case 2:
        LoadCompressedPalette(gPartyMenuMisc_Pal, 0, 0x160);
        CpuCopy16(gPlttBufferUnfaded, gUnknown_0203CEC4->palBuffer, 0x160);
        gUnknown_0203CEC4->data[0]++;
        break;
    case 3:
        PartyPaletteBufferCopy(4);
        gUnknown_0203CEC4->data[0]++;
        break;
    case 4:
        PartyPaletteBufferCopy(5);
        gUnknown_0203CEC4->data[0]++;
        break;
    case 5:
        PartyPaletteBufferCopy(6);
        gUnknown_0203CEC4->data[0]++;
        break;
    case 6:
        PartyPaletteBufferCopy(7);
        gUnknown_0203CEC4->data[0]++;
        break;
    case 7:
        PartyPaletteBufferCopy(8);
        gUnknown_0203CEC4->data[0]++;
        break;
    default:
        return TRUE;
    }
    return FALSE;
}

static void PartyPaletteBufferCopy(u8 offset)
{
    offset *= 16;
    CpuCopy16(&gPlttBufferUnfaded[0x30], &gPlttBufferUnfaded[offset], 32);
    CpuCopy16(&gPlttBufferUnfaded[0x30], &gPlttBufferFaded[offset], 32);
}

static void FreePartyPointers(void)
{
    if (gUnknown_0203CEC4)
        Free(gUnknown_0203CEC4);
    if (gUnknown_0203CEE4)
        Free(gUnknown_0203CEE4);
    if (gUnknown_0203CEE0)
        Free(gUnknown_0203CEE0);
    if (gUnknown_0203CEDC)
        Free(gUnknown_0203CEDC);
    FreeAllWindowBuffers();
}

static void PartyMenuInitHelperStructs(u8 a)
{
    u8 i;

    gUnknown_0203CEDC = Alloc(sizeof(struct Struct203CEDC[PARTY_SIZE]));

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gUnknown_0203CEDC[i].unk0 = &gUnknown_086156C4[1];
        gUnknown_0203CEDC[i].unk4 = gUnknown_08615704[a][i];
        gUnknown_0203CEDC[i].windowId = i;
        gUnknown_0203CEDC[i].unk9 = 0xFF;
        gUnknown_0203CEDC[i].unkA = 0xFF;
        gUnknown_0203CEDC[i].unkB = 0xFF;
        gUnknown_0203CEDC[i].unkC = 0xFF;
    }
    gUnknown_0203CEDC[0].unk0 = &gUnknown_086156C4[0];
    if (a == 3)
        gUnknown_0203CEDC[3].unk0 = &gUnknown_086156C4[0];
    else if (a != 0)
        gUnknown_0203CEDC[1].unk0 = &gUnknown_086156C4[0];
}

static void RenderPartyMenuBox(u8 slot)
{
    if (gUnknown_0203CEC8.unk8_0 == 5 && slot > 2)
    {
        sub_81B0CEC(slot);
        if (gUnknown_02022FF8[slot - 3].species == SPECIES_NONE)
            UpdateSelectedPartyBox(&gUnknown_0203CEDC[slot], 0x40);
        else
            UpdateSelectedPartyBox(&gUnknown_0203CEDC[slot], 8);
        CopyWindowToVram(gUnknown_0203CEDC[slot].windowId, 2);
        PutWindowTilemap(gUnknown_0203CEDC[slot].windowId);
        schedule_bg_copy_tilemap_to_vram(2);
    }
    else
    {
        if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) == SPECIES_NONE)
        {
            sub_81B2720(gUnknown_0203CEDC[slot].windowId);
            UpdateSelectedPartyBox(&gUnknown_0203CEDC[slot], 0x40);
            CopyWindowToVram(gUnknown_0203CEDC[slot].windowId, 2);
        }
        else
        {
            if (gUnknown_0203CEC8.unk8_0 == 7)
                DisplayPartyPokemonSelectForRelearner(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 2)
                DisplayPartyPokemonSelectForContest(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 4)
                DisplayPartyPokemonSelectForBattle(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 11)
                sub_81B0B98(slot);
            else if (gUnknown_0203CEC8.unk8_0 == 12)
                DisplayPartyPokemonSelectHeldItemRelated(slot);
            else if (!sub_81B0BFC(slot))
                DisplayPartyPokemonData(slot);

            if (gUnknown_0203CEC8.unk8_0 == 5)
                sub_81B0FCC(slot, 0);
            else if (gUnknown_0203CEC8.unk9 == slot)
                sub_81B0FCC(slot, 1);
            else
                sub_81B0FCC(slot, 0);
        }
        PutWindowTilemap(gUnknown_0203CEDC[slot].windowId);
        schedule_bg_copy_tilemap_to_vram(0);
    }
}

static void DisplayPartyPokemonData(u8 slot)
{
    if (GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG))
    {
        gUnknown_0203CEDC[slot].unk0->unk0(gUnknown_0203CEDC[slot].windowId, 0, 0, 0, 0, 1);
        DisplayPartyPokemonNickname(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
    }
    else
    {
        gUnknown_0203CEDC[slot].unk0->unk0(gUnknown_0203CEDC[slot].windowId, 0, 0, 0, 0, 0);
        DisplayPartyPokemonNickname(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        DisplayPartyPokemonLevelCheck(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        DisplayPartyPokemonGenderNidoranCheck(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        DisplayPartyPokemonHPCheck(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        DisplayPartyPokemonMaxHPCheck(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], 0);
        DisplayPartyPokemonHPBarCheck(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
    }
}

static void DisplayPartyPokemonSelectData(u8 slot, u8 stringID)
{
    struct Pokemon *mon = &gPlayerParty[slot];

    gUnknown_0203CEDC[slot].unk0->unk0(gUnknown_0203CEDC[slot].windowId, 0, 0, 0, 0, 1);
    DisplayPartyPokemonNickname(mon, &gUnknown_0203CEDC[slot], 0);
    if (!GetMonData(mon, MON_DATA_IS_EGG))
    {
        DisplayPartyPokemonLevelCheck(mon, &gUnknown_0203CEDC[slot], 0);
        DisplayPartyPokemonGenderNidoranCheck(mon, &gUnknown_0203CEDC[slot], 0);
    }
    DisplayPartyPokemonOtherText(stringID, &gUnknown_0203CEDC[slot], 0);
}

static void DisplayPartyPokemonSelectForBattle(u8 slot)
{
    u8 i;
    struct Pokemon *mon = &gPlayerParty[slot];
    u8 *ptr = gSelectedOrderFromParty;

    if (!GetBattleEntryEligibility(mon))
    {
        DisplayPartyPokemonSelectData(slot, 7);
        return;
    }
    else
    {
        for (i = 0; i < sub_81B8830(); i++)
        {
            if (ptr[i] != 0 && (ptr[i] - 1) == slot)
            {
                DisplayPartyPokemonSelectData(slot, i + 2);
                return;
            }
        }
        DisplayPartyPokemonSelectData(slot, 1);
    }
}

static void DisplayPartyPokemonSelectForContest(u8 slot)
{
    switch (sub_80DAE0C(&gPlayerParty[slot]))
    {
    case 0:
    case 3:
    case 4:
        DisplayPartyPokemonSelectData(slot, 7);
        break;
    case 1:
    case 2:
        DisplayPartyPokemonSelectData(slot, 6);
        break;
    }
}

static void DisplayPartyPokemonSelectForRelearner(u8 slot)
{
    if (GetNumberOfRelearnableMoves(&gPlayerParty[slot]) == 0)
        DisplayPartyPokemonSelectData(slot, 9);
    else
        DisplayPartyPokemonSelectData(slot, 8);
}

static void sub_81B0B98(u8 slot)
{
    if (sub_81B218C(slot) == TRUE)
        DisplayPartyPokemonSelectData(slot, 6);
    else
        DisplayPartyPokemonSelectData(slot, 7);
}

static void DisplayPartyPokemonSelectHeldItemRelated(u8 slot)
{
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM))
        DisplayPartyPokemonSelectData(slot, 11);
    else
        DisplayPartyPokemonSelectData(slot, 12);
}

static bool8 sub_81B0BFC(u8 slot)
{
    struct Pokemon *currentPokemon = &gPlayerParty[slot];
    u16 item = gSpecialVar_ItemId;

    if (gUnknown_0203CEC8.unkB == 12)
    {
        gSpecialVar_Result = FALSE;
        DisplayPartyPokemonSelectToTeachMove(slot, 0, gSpecialVar_0x8005);
    }
    else
    {
        if (gUnknown_0203CEC8.unkB != 3)
            return FALSE;

        switch (CheckIfItemIsTMHMOrEvolutionStone(item))
        {
        default:
            return FALSE;
        case 1:
            DisplayPartyPokemonSelectToTeachMove(slot, item, 0);
            break;
        case 2:
            if (!GetMonData(currentPokemon, MON_DATA_IS_EGG) && GetEvolutionTargetSpecies(currentPokemon, 3, item) != SPECIES_NONE)
                return FALSE;
            DisplayPartyPokemonSelectData(slot, 0);
            break;
        }
    }
    return TRUE;
}

static void DisplayPartyPokemonSelectToTeachMove(u8 slot, u16 item, u8 tutor)
{
    switch (CanMonLearnTMTutor(&gPlayerParty[slot], item, tutor))
    {
    case CANNOT_LEARN_MOVE:
    case CANNOT_LEARN_MOVE_IS_EGG:
        DisplayPartyPokemonSelectData(slot, 9);
        break;
    case ALREADY_KNOWS_MOVE:
        DisplayPartyPokemonSelectData(slot, 10);
        break;
    default:
        DisplayPartyPokemonSelectData(slot, 8);
        break;
    }
}

static void sub_81B0CEC(u8 slot)
{
    struct Struct203CEDC *structPtr = &gUnknown_0203CEDC[slot];
    u8 actualSlot = slot - 3;

    if (gUnknown_02022FF8[actualSlot].species == SPECIES_NONE)
    {
        sub_81B2720(structPtr->windowId);
    }
    else
    {
        structPtr->unk0->unk0(structPtr->windowId, 0, 0, 0, 0, 0);
        StringCopy(gStringVar1, gUnknown_02022FF8[actualSlot].nickname);
        StringGetEnd10(gStringVar1);
        sub_81DB52C(gStringVar1);
        DisplayPartyPokemonBarDetail(structPtr->windowId, gStringVar1, 0, structPtr->unk0->unk4);
        DisplayPartyPokemonLevel(gUnknown_02022FF8[actualSlot].level, structPtr);
        DisplayPartyPokemonGender(gUnknown_02022FF8[actualSlot].gender, gUnknown_02022FF8[actualSlot].species, gUnknown_02022FF8[actualSlot].nickname, structPtr);
        DisplayPartyPokemonHP(gUnknown_02022FF8[actualSlot].hp, structPtr);
        DisplayPartyPokemonMaxHP(gUnknown_02022FF8[actualSlot].maxhp, structPtr);
        DisplayPartyPokemonHPBar(gUnknown_02022FF8[actualSlot].hp, gUnknown_02022FF8[actualSlot].maxhp, structPtr);
    }
}

static bool8 RenderPartyMenuBoxes(void)
{
    RenderPartyMenuBox(gUnknown_0203CEC4->data[0]);
    if (++gUnknown_0203CEC4->data[0] == 6)
        return TRUE;
    else
        return FALSE;
}

static u8* GetPartyMiscGraphicsTile(u16 tileId)
{
    return &gUnknown_0203CEE0[tileId << 5];
}

static void party_menu_add_per_mon_objects_internal(u8 slot)
{
    u8 actualSlot;

    if (gUnknown_0203CEC8.unk8_0 == 5 && slot > 2)
    {
        u8 status;
        actualSlot = slot - 3;

        if (gUnknown_02022FF8[actualSlot].species != SPECIES_NONE)
        {
            party_menu_link_mon_icon_anim(gUnknown_02022FF8[actualSlot].species, gUnknown_02022FF8[actualSlot].personality, &gUnknown_0203CEDC[slot], 0, 0);
            party_menu_link_mon_held_item_object(gUnknown_02022FF8[actualSlot].species, gUnknown_02022FF8[actualSlot].heldItem, &gUnknown_0203CEDC[slot]);
            party_menu_link_mon_pokeball_object(gUnknown_02022FF8[actualSlot].species, &gUnknown_0203CEDC[slot]);
            if (gUnknown_02022FF8[actualSlot].hp == 0)
                status = AILMENT_FNT;
            else
                status = pokemon_ailments_get_primary(gUnknown_02022FF8[actualSlot].status);
            party_menu_link_mon_status_condition_object(gUnknown_02022FF8[actualSlot].species, status, &gUnknown_0203CEDC[slot]);
        }
    }
    else if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) != SPECIES_NONE)
    {
        party_menu_icon_anim(&gPlayerParty[slot], &gUnknown_0203CEDC[slot], slot);
        party_menu_held_item_object(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
        party_menu_pokeball_object(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
        party_menu_status_condition_object(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
    }
}

static bool8 party_menu_add_per_mon_objects(void)
{
    party_menu_add_per_mon_objects_internal(gUnknown_0203CEC4->data[0]);
    if (++gUnknown_0203CEC4->data[0] == 6)
        return TRUE;
    else
        return FALSE;
}

static void sub_81B0F28(void)
{
    if (gUnknown_0203CEC8.unk8_0 == 5)
    {
        FillBgTilemapBufferRect(1, 14, 23, 17, 7, 2, 1);
    }
    else
    {
        if (gUnknown_0203CEC4->unk8_0)
        {
            gUnknown_0203CEC4->unk8_2 = sub_81B5F74(0xBF, 0x88);
            sub_81B120C();
            gUnknown_0203CEC4->unk9_0 = sub_81B5F74(0xBF, 0x98);
        }
        else
        {
            gUnknown_0203CEC4->unk9_0 = sub_81B5F34(0xC6, 0x94);
        }
        sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
    }
}

void sub_81B0FCC(u8 slot, u8 b)
{
    u8 spriteId;

    switch (slot)
    {
    default:
        if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            UpdateSelectedPartyBox(&gUnknown_0203CEDC[slot], GetPartyBoxPalBitfield(slot, b));
            AnimateSelectedPartyIcon(gUnknown_0203CEDC[slot].unk9, b);
            sub_81B5F98(gUnknown_0203CEDC[slot].unkB, b);
        }
        return;
    case 6:
        if (b == 0)
            sub_8199C30(1, 23, 16, 7, 2, 1);
        else
            sub_8199C30(1, 23, 16, 7, 2, 2);
        spriteId = gUnknown_0203CEC4->unk8_2;
        break;
    case 7:
        if (!gUnknown_0203CEC4->unk8_0)
        {
            if (b == 0)
                sub_8199C30(1, 23, 17, 7, 2, 1);
            else
                sub_8199C30(1, 23, 17, 7, 2, 2);
        }
        else if (b == 0)
        {
            sub_8199C30(1, 23, 18, 7, 2, 1);
        }
        else
        {
            sub_8199C30(1, 23, 18, 7, 2, 2);
        }
        spriteId = gUnknown_0203CEC4->unk9_0;
        break;
    }
    sub_81B5F98(spriteId, b);
    schedule_bg_copy_tilemap_to_vram(1);
}

static u8 GetPartyBoxPalBitfield(u8 slot, u8 b)
{
    u8 returnVar = 0;

    if (b == 1)
        returnVar |= 1;
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HP) == 0)
        returnVar |= 2;
    if (PartyBoxPal_ParnterOrDisqualifiedInArena(slot) == TRUE)
        returnVar |= 8;
    if (gUnknown_0203CEC8.unkB == 9)
        returnVar |= 16;
    if (gUnknown_0203CEC8.unkB == 8)
    {
        if (slot == gUnknown_0203CEC8.unk9 || slot == gUnknown_0203CEC8.unkA)
            returnVar |= 4;
    }
    if (gUnknown_0203CEC8.unkB == 10 && slot == gUnknown_0203CEC8.unk9 )
        returnVar |= 32;

    return returnVar;
}

static bool8 PartyBoxPal_ParnterOrDisqualifiedInArena(u8 slot)
{
    if (gUnknown_0203CEC8.mode == 2 && (slot == 1 || slot == 4 || slot == 5))
        return TRUE;

    if (slot < 3 && (gBattleTypeFlags & BATTLE_TYPE_ARENA) && gMain.inBattle && (gBattleStruct->arenaLostPlayerMons >> sub_81B8F38(slot) & 1))
        return TRUE;

    return FALSE;
}

static void sub_81B120C(void)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_086157C4, 23, 16, 7, 2, 17);
    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_086157E0, 23, 18, 7, 2, 17);
    schedule_bg_copy_tilemap_to_vram(1);
}

bool8 IsMultiBattle(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gMain.inBattle)
        return TRUE;
    else
        return FALSE;
}

static void sub_81B1288(struct Pokemon *partySlot, struct Pokemon *pokemon)
{
    struct Pokemon *temp = Alloc(sizeof(struct Pokemon));

    *temp = *partySlot;
    *partySlot = *pokemon;
    *pokemon = *temp;

    Free(temp);
}

static void sub_81B12C0(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = c3_0811FAB4;
}

static void c3_0811FAB4(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203CEC8.unk8_0 == 1)
            sub_81B9080();

        if  (gUnknown_0203CEC4->exitCallback != NULL)
            SetMainCallback2(gUnknown_0203CEC4->exitCallback);
        else
            SetMainCallback2(gUnknown_0203CEC8.exitCallback);

        ResetSpriteData();
        FreePartyPointers();
        DestroyTask(taskId);
    }
}

u8 GetCursorSelectionMonId(void)
{
    return gUnknown_0203CEC8.unk9;
}

u8 sub_81B1360(void)
{
    return gUnknown_0203CEC8.unk8_0;
}

void sub_81B1370(u8 taskId)
{
    if (!gPaletteFade.active && sub_81221EC() != TRUE)
    {
        s8 *ptr = sub_81B13EC();

        switch (PartyMenuButtonHandler(ptr))
        {
        case 1:
            sub_81B140C(taskId, ptr);
            break;
        case 2:
            sub_81B15D0(taskId, ptr);
            break;
        case 8:
            if (gUnknown_0203CEC4->unk8_0)
            {
                PlaySE(SE_SELECT);
                sub_81B4F88();
            }
            break;
        }
    }
}

static s8* sub_81B13EC(void)
{
    if (gUnknown_0203CEC8.unkB == 8 || gUnknown_0203CEC8.unkB == 10)
        return &gUnknown_0203CEC8.unkA;
    else
        return &gUnknown_0203CEC8.unk9;
}

static void sub_81B140C(u8 taskId, s8 *ptr)
{
    if (*ptr == 6)
    {
        gUnknown_0203CEC8.unk4(taskId);
    }
    else
    {
        switch (gUnknown_0203CEC8.unkB - 3)
        {
        case 7:
            if (sub_81B15A4((u8*)ptr))
            {
                sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                sub_81615A8(taskId);
            }
            break;
        case 0:
            if (sub_81B15A4((u8*)ptr))
            {
                if (gUnknown_0203CEC8.unk8_0 == 1)
                    gUnknown_0203CEC4->exitCallback = sub_81B9140;

                sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                gUnknown_03006328(taskId, sub_81B6794);
            }
            break;
        case 9:
            if (sub_81B15A4((u8*)ptr))
            {
                PlaySE(SE_SELECT);
                sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                sub_81B7E4C(taskId);
            }
            break;
        case 4:
            if (sub_81B15A4((u8*)ptr))
            {
                PlaySE(SE_SELECT);
                sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                sub_81B8474(taskId);
            }
            break;
        case 2:
        case 3:
            if (sub_81B15A4((u8*)ptr))
            {
                PlaySE(SE_SELECT);
                sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
                sub_81B7FAC(taskId);
            }
            break;
        case 5:
            PlaySE(SE_SELECT);
            sub_81B3938(taskId);
            break;
        case 8:
            PlaySE(SE_SELECT);
            sub_81B12C0(taskId);
            break;
        case 10:
            if (sub_81B15A4((u8*)ptr))
            {
                sub_81B21AC(taskId, (u8)*ptr);
            }
            break;
        default:
        case 1:
        case 6:
            PlaySE(SE_SELECT);
            sub_81B36FC(taskId);
            break;
        }
    }
}

static bool8 sub_81B15A4(u8 *slotPtr)
{
    if (GetMonData(&gPlayerParty[*slotPtr], MON_DATA_IS_EGG) == TRUE)
    {
        PlaySE(SE_HAZURE);
        return FALSE;
    }
    return TRUE;
}

static void sub_81B15D0(u8 taskId, s8 *ptr)
{
    switch (gUnknown_0203CEC8.unkB)
    {
    case 1:
        PlaySE(SE_HAZURE);
        break;
    case 8:
    case 10:
        PlaySE(SE_SELECT);
        sub_81B407C(taskId);
        break;
    case 13:
        PlaySE(SE_SELECT);
        sub_81B2210(taskId);
        break;
    default:
        PlaySE(SE_SELECT);
        if (sub_81B1660(taskId) != TRUE)
        {
            if (!sub_81221AC())
                gSpecialVar_0x8004 = 7;
            gUnknown_0203CEE8 = 0;
            *ptr = 7;
            sub_81B12C0(taskId);
        }
        break;
    }
}

static bool8 sub_81B1660(u8 taskId)
{
    const u8* stringPtr = NULL;

    if (gUnknown_0203CEC8.unk8_0 == 2)
        stringPtr = gText_CancelParticipation;
    else if (gUnknown_0203CEC8.unk8_0 == 4)
        stringPtr = sub_81B88BC();

    if (stringPtr == NULL)
        return FALSE;

    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    StringExpandPlaceholders(gStringVar4, stringPtr);
    sub_81B1B5C(gStringVar4, 1);
    gTasks[taskId].func = sub_81B16D4;
    return TRUE;
}

static void sub_81B16D4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B1708;
    }
}

static void sub_81B1708(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        gUnknown_0203CEE8 = 0;
        gUnknown_0203CEC8.unk9 = 7;
        sub_81B8558();
        sub_81B12C0(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        sub_81B1C1C(taskId);
        break;
    }
}

static u16 PartyMenuButtonHandler(s8 *ptr)
{
    s8 movementDir;

    switch (gMain.newAndRepeatedKeys)
    {
    case DPAD_UP:
        movementDir = -1;
        break;
    case DPAD_DOWN:
        movementDir = 1;
        break;
    case DPAD_LEFT:
        movementDir = -2;
        break;
    case DPAD_RIGHT:
        movementDir = 2;
        break;
    default:
        switch (sub_812210C())
        {
        case 1:
            movementDir = -1;
            break;
        case 2:
            movementDir = 1;
            break;
        default:
            movementDir = 0;
            break;
        }
        break;
    }

    if (gMain.newKeys & START_BUTTON)
        return 8;

    if (movementDir)
    {
        UpdateCurrentPartySelection(ptr, movementDir);
        return 0;
    }

    if ((gMain.newKeys & A_BUTTON) && *ptr == 7)
        return 2;

    return gMain.newKeys & (A_BUTTON | B_BUTTON);
}

static void UpdateCurrentPartySelection(s8 *ptr, s8 movementDir)
{
    s8 slot = *ptr;
    u8 mode = gUnknown_0203CEC8.mode;

    if (mode == 0)
        SetNewPartySelectTarget1(ptr, movementDir);
    else
        SetNewPartySelectTarget2(ptr, movementDir);

    if (*ptr != slot)
    {
        PlaySE(SE_SELECT);
        sub_81B0FCC(slot, 0);
        sub_81B0FCC(*ptr, 1);
    }
}

static void SetNewPartySelectTarget1(s8 *ptr, s8 b)
{
    switch (b)
    {
    case -1:
        if (*ptr == 0)
        {
            *ptr = 7;
        }
        else if (*ptr == 6)
        {
            *ptr = gPlayerPartyCount - 1;
        }
        else if (*ptr == 7)
        {
            if (gUnknown_0203CEC4->unk8_0)
                *ptr = 6;
            else
                *ptr = gPlayerPartyCount - 1;
        }
        else
        {
            (*ptr)--;
        }
        break;
    case 1:
        if (*ptr == 7)
        {
            *ptr = 0;
        }
        else
        {
            if (*ptr == gPlayerPartyCount - 1)
            {
                if (gUnknown_0203CEC4->unk8_0)
                    *ptr = 6;
                else
                    *ptr = 7;
            }
            else
            {
                (*ptr)++;
            }
        }
        break;
    case 2:
        if (gPlayerPartyCount != 1 && *ptr == 0)
        {
            if (gUnknown_0203CEC4->unk8_1 == 0)
                *ptr = 1;
            else
                *ptr = gUnknown_0203CEC4->unk8_1;
        }
        break;
    case -2:
        if (*ptr != 0 && *ptr != 6 && *ptr != 7)
        {
            gUnknown_0203CEC4->unk8_1 = *ptr;
            *ptr = 0;
        }
        break;
    }
}

static void SetNewPartySelectTarget2(s8 *ptr, s8 b)
{
    s8 unk2 = b;

    switch (b)
    {
    case -1:
        if (*ptr == 0)
        {
            *ptr = 7;
            break;
        }
        else if (*ptr == 6)
        {
            *ptr = gPlayerPartyCount - 1;
            break;
        }
        else if (*ptr == 7)
        {
            if (gUnknown_0203CEC4->unk8_0)
            {
                *ptr = 6;
                break;
            }
            (*ptr)--;
        }
        unk2 = sub_81B1B00(*ptr, unk2);
        if (unk2 != -1)
            *ptr = unk2;
        break;
    case 1:
        if (*ptr == 6)
        {
            *ptr = 7;
        }
        else if (*ptr == 7)
        {
            *ptr = 0;
        }
        else
        {
            unk2 = sub_81B1B00(*ptr, 1);
            if (unk2 == -1)
            {
                if (gUnknown_0203CEC4->unk8_0)
                    *ptr = 6;
                else
                    *ptr = 7;
            }
            else
            {
                *ptr = unk2;
            }
        }
        break;
    case 2:
        if (*ptr == 0)
        {
            if (gUnknown_0203CEC4->unk8_1 == 3)
            {
                if (GetMonData(&gPlayerParty[3], MON_DATA_SPECIES) != SPECIES_NONE)
                    *ptr = 3;
            }
            else if (GetMonData(&gPlayerParty[2], MON_DATA_SPECIES) != SPECIES_NONE)
            {
                *ptr = 2;
            }
        }
        else if (*ptr == 1)
        {
            if (gUnknown_0203CEC4->unk8_1 == 5)
            {
                if (GetMonData(&gPlayerParty[5], MON_DATA_SPECIES) != SPECIES_NONE)
                    *ptr = 5;
            }
            else if (GetMonData(&gPlayerParty[4], MON_DATA_SPECIES) != SPECIES_NONE)
            {
                *ptr = 4;
            }
        }
        break;
    case -2:
        if (*ptr == 2 || *ptr == 3)
        {
            gUnknown_0203CEC4->unk8_1 = *ptr;
            *ptr = 0;
        }
        else if (*ptr == 4 || *ptr == 5)
        {
            gUnknown_0203CEC4->unk8_1 = *ptr;
            *ptr = 1;
        }
        break;
    }
}

static s8 sub_81B1B00(s8 a, s8 b)
{
    while (TRUE)
    {
        a += b;
        if ((u8)a >= 6)
            return -1;
        if (GetMonData(&gPlayerParty[a], MON_DATA_SPECIES) != SPECIES_NONE)
            return a;
    }
}

u8* GetMonNickname(struct Pokemon *mon, u8 *dest)
{
    GetMonData(mon, MON_DATA_NICKNAME, dest);
    return StringGetEnd10(dest);
}

u8 sub_81B1B5C(const u8* str, u8 b)
{
    u8 taskId;

    sub_81B3300(str);
    taskId = CreateTask(sub_81B1B8C, 1);
    gTasks[taskId].data[0] = b;
    return taskId;
}

static void sub_81B1B8C(u8 taskId)
{
    if (RunTextPrintersRetIsActive(6) != TRUE)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            ClearStdWindowAndFrameToTransparent(6, 0);
            ClearWindowTilemap(6);
        }
        DestroyTask(taskId);
    }
}

bool8 sub_81B1BD4(void)
{
    return FuncIsActiveTask(sub_81B1B8C);
}

static void sub_81B1BE8(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        display_pokemon_menu_message(0);
        gTasks[taskId].func = sub_81B1370;
    }
}

static void sub_81B1C1C(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        ClearStdWindowAndFrameToTransparent(6, 0);
        ClearWindowTilemap(6);
        if (sub_81221AC() == TRUE)
        {
            gTasks[taskId].func = sub_81B1BE8;
        }
        else
        {
            display_pokemon_menu_message(0);
            gTasks[taskId].func = sub_81B1370;
        }
    }
}

static void sub_81B1C84(struct Pokemon *mon, u16 item, u8 c, u8 unused)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_PkmnWasGivenItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_81B1CD0(struct Pokemon *mon, u16 item, u8 c)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_ReceivedItemFromPkmn);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_81B1D1C(struct Pokemon *mon, u16 item, u8 c)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_SwitchPkmnItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_81B1D68(u16 item, u16 item2, u8 c)
{
    CopyItemName(item, gStringVar1);
    CopyItemName(item2, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_SwitchedPkmnItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_81B1DB8(struct Pokemon *mon, u16 item)
{
    u8 itemBytes[2];

    if (ItemIsMail(item) == TRUE)
    {
        if (GiveMailToMon(mon, item) == 0xFF)
            return;
    }
    itemBytes[0] = item;
    itemBytes[1] = item >> 8;
    SetMonData(mon, MON_DATA_HELD_ITEM, itemBytes);
}

static u8 TryTakeMonItem(struct Pokemon* mon)
{
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (item == ITEM_NONE)
        return 0;
    if (AddBagItem(item, 1) == FALSE)
        return 1;

    item = ITEM_NONE;
    SetMonData(mon, MON_DATA_HELD_ITEM, &item);
    return 2;
}

static void pokemon_item_not_removed(u16 itemUnused)
{
    StringExpandPlaceholders(gStringVar4, gText_BagFullCouldNotRemoveItem);
}

static void sub_81B1E60(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[0] += data[2];
    data[3]--;
    SetMonData(&gPlayerParty[data[4]], MON_DATA_HP, &data[0]);
    DisplayPartyPokemonHPCheck(&gPlayerParty[data[4]], &gUnknown_0203CEDC[data[4]], 1);
    DisplayPartyPokemonHPBarCheck(&gPlayerParty[data[4]], &gUnknown_0203CEDC[data[4]]);
    if (data[3] == 0 || data[0] == 0 || data[0] == data[1])
    {
        if (data[0] > data[5])
            ConvertIntToDecimalStringN(gStringVar2, data[0] - data[5], 0, 3);
        SwitchTaskToFollowupFunc(taskId);
    }
}

void sub_81B1F18(u8 taskId, u8 slot, s8 c, s16 HPDifference, TaskFunc func)
{
    struct Pokemon *mon = &gPlayerParty[slot];
    s16 *data = gTasks[taskId].data;

    data[0] = GetMonData(mon, MON_DATA_HP);
    data[1] = GetMonData(mon, MON_DATA_MAX_HP);
    data[2] = c;
    data[3] = HPDifference;
    data[4] = slot;
    data[5] = data[0];
    SetTaskFuncWithFollowupFunc(taskId, sub_81B1E60, func);
}

static void sub_81B1FA8(u8 taskId, u8 b, u32 hp)
{
    s16 *data = gTasks[taskId].data;

    switch (b) // only case 0 is used
    {
        case 0:
            data[0] = hp;
            data[5] = hp;
            break;
        case 1:
            data[1] = hp;
            break;
        case 2:
            data[2] = hp;
            break;
        case 3:
            data[3] = hp;
            break;
        case 4:
            data[4] = hp;
            break;
        case 5:
            SetTaskFuncWithFollowupFunc(taskId, sub_81B1E60, (TaskFunc)hp); // >casting hp as a taskfunc
            break;
    }
}

u8 pokemon_ailments_get_primary(u32 status)
{
    if (status & STATUS1_PSN_ANY)
        return AILMENT_PSN;
    if (status & STATUS1_PARALYSIS)
        return AILMENT_PRZ;
    if (status & STATUS1_SLEEP)
        return AILMENT_SLP;
    if (status & STATUS1_FREEZE)
        return AILMENT_FRZ;
    if (status & STATUS1_BURN)
        return AILMENT_BRN;
    return AILMENT_NONE;
}

u8 GetMonAilment(struct Pokemon *mon)
{
    u8 ailment;

    if (GetMonData(mon, MON_DATA_HP) == 0)
        return AILMENT_FNT;
    ailment = pokemon_ailments_get_primary(GetMonData(mon, MON_DATA_STATUS));
    if (ailment != AILMENT_NONE)
        return ailment;
    if (CheckPartyPokerus(mon, 0))
        return AILMENT_PKRS;
    return AILMENT_NONE;
}

static void sub_81B209C(void)
{
    u16 *ptr;

    if (gUnknown_0203CEC8.unk8_0 == 11)
    {
        u8 i;

        ptr = &gUnknown_0203CEC8.unkE;
        gUnknown_0203CEC8.unkE = 0;
        if (gSpecialVar_0x8005 == 0)
        {
            for (i = 0; i < gPlayerPartyCount; i++)
                *ptr += sub_81B2134(&gPlayerParty[i]) << i;
        }
        else
        {
            for (i = 0; i < gPlayerPartyCount; i++)
                *ptr += sub_81B2164(&gPlayerParty[i]) << i;
        }
    }
}

static bool16 sub_81B2134(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && sub_802C908(GetMonData(mon, MON_DATA_SPECIES)))
        return TRUE;
    return FALSE;
}

// Dodrio Berry Picking select?

static bool16 sub_81B2164(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && GetMonData(mon, MON_DATA_SPECIES) == SPECIES_DODRIO)
        return TRUE;
    return FALSE;
}

static bool8 sub_81B218C(u8 slot)
{
    if (!((gUnknown_0203CEC8.unkE >> slot) & 1))
        return FALSE;
    return TRUE;
}

static void sub_81B21AC(u8 taskId, u8 slot)
{
    if (sub_81B218C(slot) == TRUE)
    {
        PlaySE(SE_SELECT);
        gSpecialVar_0x8004 = slot;
        sub_81B12C0(taskId);
    }
    else
    {
        PlaySE(SE_HAZURE);
        sub_81B1B5C(gText_PkmnCantParticipate, 0);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = sub_81B1C1C;
    }
}

static void sub_81B2210(u8 taskId)
{
    sub_81B1B5C(gText_CancelParticipation, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B2248;
}

static void sub_81B2248(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B227C;
    }
}

static void sub_81B227C(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        gSpecialVar_0x8004 = 7;
        sub_81B12C0(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        gTasks[taskId].func = sub_81B1C1C;
        break;
    }
}

static u8 CanMonLearnTMTutor(struct Pokemon *mon, u16 item, u8 tutor)
{
    u16 move;

    if (GetMonData(mon, MON_DATA_IS_EGG))
        return CANNOT_LEARN_MOVE_IS_EGG;

    if (item >= ITEM_TM01_FOCUS_PUNCH)
    {
        if (CanMonLearnTMHM(mon, item - ITEM_TM01_FOCUS_PUNCH))
            move = ItemIdToBattleMoveId(item);
        else
            return CANNOT_LEARN_MOVE;
        do {} while (0); // :morphon:
    }
    else if (CanLearnTutorMove(GetMonData(mon, MON_DATA_SPECIES), tutor) == FALSE)
    {
        return CANNOT_LEARN_MOVE;
    }
    else
    {
        move = GetTutorMove(tutor);
    }

    if (MonKnowsMove(mon, move) == TRUE)
        return ALREADY_KNOWS_MOVE;
    else
        return CAN_LEARN_MOVE;
}

static u16 GetTutorMove(u8 tutor)
{
    return gTutorMoves[tutor];
}

static bool8 CanLearnTutorMove(u16 species, u8 tutor)
{
    if (sTutorLearnsets[species] & (1 << tutor))
        return TRUE;
    else
        return FALSE;
}

static void sub_81B239C(u8 a)
{
    u8 i;

    switch (a)
    {
    case 0:
        InitWindows(gUnknown_08615810);
        break;
    case 1:
        InitWindows(gUnknown_08615850);
        break;
    case 2:
        InitWindows(gUnknown_08615890);
        break;
    default:
        InitWindows(gUnknown_086158D0);
        break;
    }
    DeactivateAllTextPrinters();
    for (i = 0; i < PARTY_SIZE; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    LoadUserWindowBorderGfx(0, 0x4F, 0xD0);
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xE0, 0x20);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
}

static void sub_81B2428(bool8 a)
{
    u8 firstWindowId;
    u8 windowId;
    u8 offset;
    u8 mainOffset;

    if (gUnknown_0203CEC8.unk8_0 != 5)
    {
        if (a == TRUE)
        {
            firstWindowId = AddWindow(&gUnknown_08615918);
            FillWindowPixelBuffer(firstWindowId, PIXEL_FILL(0));
            mainOffset = GetStringCenterAlignXOffset(0, gMenuText_Confirm, 48);
            AddTextPrinterParameterized4(firstWindowId, 0, mainOffset, 1, 0, 0, gUnknown_086157FC[0], -1, gMenuText_Confirm);
            PutWindowTilemap(firstWindowId);
            CopyWindowToVram(firstWindowId, 2);
            windowId = AddWindow(&gUnknown_08615910);
            offset = 0;
        }
        else
        {
            windowId = AddWindow(&gUnknown_08615908);
            offset = 3;
        }
        FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
        if (gUnknown_0203CEC8.unk8_0 != 10)
        {
            mainOffset = GetStringCenterAlignXOffset(0, gText_Cancel, 48);
            AddTextPrinterParameterized3(windowId, 0, mainOffset + offset, 1, gUnknown_086157FC[0], -1, gText_Cancel);
        }
        else
        {
            mainOffset = GetStringCenterAlignXOffset(0, gText_Cancel2, 48);
            AddTextPrinterParameterized3(windowId, 0, mainOffset + offset, 1, gUnknown_086157FC[0], -1, gText_Cancel2);
        }
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, 2);
        schedule_bg_copy_tilemap_to_vram(0);
    }
}

static u16* GetPartyMenuPaletteFromBuffer(u8 paletteId)
{
    return &gUnknown_0203CEC4->palBuffer[paletteId];
}

static void BlitBitmapToPartyWindow(u8 windowId, const u8 *b, u8 c, u8 x, u8 y, u8 width, u8 height)
{
    u8 *pixels = AllocZeroed(height * width * 32);
    u8 i, j;

    if (pixels != NULL)
    {
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
                CpuCopy16(GetPartyMiscGraphicsTile(b[x + j + ((y + i) * c)]), &pixels[(i * width + j) * 32], 32);
        }
        BlitBitmapToWindow(windowId, pixels, x * 8, y * 8, width * 8, height * 8);
        Free(pixels);
    }
}

static void BlitBitmapToPartyWindow_Default1(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f)
{
    if (width == 0 && height == 0)
    {
        width = 10;
        height = 7;
    }
    if (f == 0)
        BlitBitmapToPartyWindow(windowId, gUnknown_08615988, 10, x, y, width, height);
    else
        BlitBitmapToPartyWindow(windowId, gUnknown_086159CE, 10, x, y, width, height);
}

static void BlitBitmapToPartyWindow_Default2(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f)
{
    if (width == 0 && height == 0)
    {
        width = 18;
        height = 3;
    }
    if (f == 0)
        BlitBitmapToPartyWindow(windowId, gUnknown_08615A14, 18, x, y, width, height);
    else
        BlitBitmapToPartyWindow(windowId, gUnknown_08615A4A, 18, x, y, width, height);
}

static void sub_81B2720(u8 windowId)
{
    BlitBitmapToPartyWindow(windowId, gUnknown_08615A80, 18, 0, 0, 18, 3);
}

static void UpdateSelectedPartyBox(struct Struct203CEDC *ptr, u8 bitfield)
{
    u8 palNum = GetWindowAttribute(ptr->windowId, WINDOW_PALETTE_NUM) * 16;

    if (bitfield & 0x40)
    {
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AF1[0]), gUnknown_08615AC0[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AF1[1]), gUnknown_08615AC0[1] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AF1[2]), gUnknown_08615AC0[2] + palNum, 2);
    }
    else if (bitfield & 0x20)
    {
        if (bitfield & 1)
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (bitfield & 0x10)
    {
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[0]), gUnknown_08615ABD[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[1]), gUnknown_08615ABD[1] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[2]), gUnknown_08615ABD[2] + palNum, 2);
    }
    else if (bitfield & 4)
    {
        if (bitfield & 1)
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADF[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEE[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (bitfield & 2)
    {
        if (bitfield & 1)
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADC[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADC[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ADC[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD3[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD3[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD3[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE8[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE8[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE8[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (bitfield & 8)
    {
        if (bitfield & 1)
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD9[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD9[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD9[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
        else
        {
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD0[0]), gUnknown_08615ABA[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD0[1]), gUnknown_08615ABA[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD0[2]), gUnknown_08615ABA[2] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE5[0]), gUnknown_08615ABD[0] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE5[1]), gUnknown_08615ABD[1] + palNum, 2);
            LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE5[2]), gUnknown_08615ABD[2] + palNum, 2);
        }
    }
    else if (bitfield & 1)
    {
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD6[0]), gUnknown_08615ABA[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD6[1]), gUnknown_08615ABA[1] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AD6[2]), gUnknown_08615ABA[2] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[0]), gUnknown_08615ABD[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[1]), gUnknown_08615ABD[1] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AEB[2]), gUnknown_08615ABD[2] + palNum, 2);
    }
    else
    {
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ACD[0]), gUnknown_08615ABA[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ACD[1]), gUnknown_08615ABA[1] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ACD[2]), gUnknown_08615ABA[2] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE2[0]), gUnknown_08615ABD[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE2[1]), gUnknown_08615ABD[1] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AE2[2]), gUnknown_08615ABD[2] + palNum, 2);
    }
}

static void DisplayPartyPokemonBarDetail(u8 windowId, const u8 *str, u8 color, const u8 *align)
{
    AddTextPrinterParameterized3(windowId, 0, align[0], align[1], gUnknown_086157FC[color], 0, str);
}

static void DisplayPartyPokemonNickname(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];

    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c == 1)
            ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk4[0] >> 3, ptr->unk0->unk4[1] >> 3, ptr->unk0->unk4[2] >> 3, ptr->unk0->unk4[3] >> 3, 0);
        GetMonNickname(mon, nickname);
        DisplayPartyPokemonBarDetail(ptr->windowId, nickname, 0, ptr->unk0->unk4);
    }
}

static void DisplayPartyPokemonLevelCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        u8 ailment = GetMonAilment(mon);
        if (ailment == AILMENT_NONE || ailment == AILMENT_PKRS)
        {
            if (c != 0)
                ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk4[4] >> 3, (ptr->unk0->unk4[5] >> 3) + 1, ptr->unk0->unk4[6] >> 3, ptr->unk0->unk4[7] >> 3, 0);
            if (c != 2)
                DisplayPartyPokemonLevel(GetMonData(mon, MON_DATA_LEVEL), ptr);
        }
    }
}

static void DisplayPartyPokemonLevel(u8 level, struct Struct203CEDC *ptr)
{
    ConvertIntToDecimalStringN(gStringVar2, level, 0, 3);
    StringCopy(gStringVar1, gText_LevelSymbol);
    StringAppend(gStringVar1, gStringVar2);
    DisplayPartyPokemonBarDetail(ptr->windowId, gStringVar1, 0, &ptr->unk0->unk4[4]);
}

static void DisplayPartyPokemonGenderNidoranCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];

    if (c == 1)
        ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk4[8] >> 3, (ptr->unk0->unk4[9] >> 3) + 1, ptr->unk0->unk4[10] >> 3, ptr->unk0->unk4[11] >> 3, 0);
    GetMonNickname(mon, nickname);
    DisplayPartyPokemonGender(GetMonGender(mon), GetMonData(mon, MON_DATA_SPECIES), nickname, ptr);
}

static void DisplayPartyPokemonGender(u8 gender, u16 species, u8 *nickname, struct Struct203CEDC *ptr)
{
    u8 palNum = GetWindowAttribute(ptr->windowId, WINDOW_PALETTE_NUM) * 16;

    if (species == SPECIES_NONE)
        return;
    if ((species == SPECIES_NIDORAN_M || species == SPECIES_NIDORAN_F) && StringCompare(nickname, gSpeciesNames[species]) == 0)
        return;
    switch (gender)
    {
    case MON_MALE:
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC3[0]), gUnknown_08615AB6[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC3[1]), gUnknown_08615AB6[1] + palNum, 2);
        DisplayPartyPokemonBarDetail(ptr->windowId, gText_MaleSymbol, 2, &ptr->unk0->unk4[8]);
        break;
    case MON_FEMALE:
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC5[0]), gUnknown_08615AB6[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC5[1]), gUnknown_08615AB6[1] + palNum, 2);
        DisplayPartyPokemonBarDetail(ptr->windowId, gText_FemaleSymbol, 2, &ptr->unk0->unk4[8]);
        break;
    }
}

static void DisplayPartyPokemonHPCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk4[12] >> 3, (ptr->unk0->unk4[13] >> 3) + 1, ptr->unk0->unk4[14] >> 3, ptr->unk0->unk4[15] >> 3, 0);
        if (c != 2)
            DisplayPartyPokemonHP(GetMonData(mon, MON_DATA_HP), ptr);
    }
}

static void DisplayPartyPokemonHP(u16 hp, struct Struct203CEDC *ptr)
{
    u8 *strOut = ConvertIntToDecimalStringN(gStringVar1, hp, 1, 3);

    strOut[0] = CHAR_SLASH;
    strOut[1] = EOS;

    DisplayPartyPokemonBarDetail(ptr->windowId, gStringVar1, 0, &ptr->unk0->unk4[12]);
}

static void DisplayPartyPokemonMaxHPCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            ptr->unk0->unk0(ptr->windowId, (ptr->unk0->unk4[16] >> 3) + 1, (ptr->unk0->unk4[17] >> 3) + 1, ptr->unk0->unk4[18] >> 3, ptr->unk0->unk4[19] >> 3, 0);
        if (c != 2)
            DisplayPartyPokemonMaxHP(GetMonData(mon, MON_DATA_MAX_HP), ptr);
    }
}

static void DisplayPartyPokemonMaxHP(u16 maxhp, struct Struct203CEDC *ptr)
{
    ConvertIntToDecimalStringN(gStringVar2, maxhp, 1, 3);
    StringCopy(gStringVar1, gText_Slash);
    StringAppend(gStringVar1, gStringVar2);
    DisplayPartyPokemonBarDetail(ptr->windowId, gStringVar1, 0, &ptr->unk0->unk4[16]);
}

static void DisplayPartyPokemonHPBarCheck(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
        DisplayPartyPokemonHPBar(GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP), ptr);
}

static void DisplayPartyPokemonHPBar(u16 hp, u16 maxhp, struct Struct203CEDC *ptr)
{
    u8 palNum = GetWindowAttribute(ptr->windowId, WINDOW_PALETTE_NUM) * 16;
    u8 hpFraction;

    switch (GetHPBarLevel(hp, maxhp))
    {
    case HP_BAR_GREEN:
    case HP_BAR_FULL:
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC7[0]), gUnknown_08615AB8[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC7[1]), gUnknown_08615AB8[1] + palNum, 2);
        break;
    case HP_BAR_YELLOW:
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC9[0]), gUnknown_08615AB8[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615AC9[1]), gUnknown_08615AB8[1] + palNum, 2);
        break;
    default:
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ACB[0]), gUnknown_08615AB8[0] + palNum, 2);
        LoadPalette(GetPartyMenuPaletteFromBuffer(gUnknown_08615ACB[1]), gUnknown_08615AB8[1] + palNum, 2);
        break;
    }

    hpFraction = GetScaledHPFraction(hp, maxhp, ptr->unk0->unk4[22]);
    FillWindowPixelRect(ptr->windowId, gUnknown_08615AB8[1], ptr->unk0->unk4[20], ptr->unk0->unk4[21], hpFraction, 1);
    FillWindowPixelRect(ptr->windowId, gUnknown_08615AB8[0], ptr->unk0->unk4[20], ptr->unk0->unk4[21] + 1, hpFraction, 2);
    if (hpFraction != ptr->unk0->unk4[22])
    {
        // This appears to be an alternating fill
        FillWindowPixelRect(ptr->windowId, 0x0D, ptr->unk0->unk4[20] + hpFraction, ptr->unk0->unk4[21], ptr->unk0->unk4[22] - hpFraction, 1);
        FillWindowPixelRect(ptr->windowId, 0x02, ptr->unk0->unk4[20] + hpFraction, ptr->unk0->unk4[21] + 1, ptr->unk0->unk4[22] - hpFraction, 2);
    }
    CopyWindowToVram(ptr->windowId, 2);
}

static void DisplayPartyPokemonOtherText(u8 stringID, struct Struct203CEDC *ptr, u8 c)
{
    if (c != 0)
    {
        int unk = ((ptr->unk0->unk1C % 8) + ptr->unk0->unk1E + 7) / 8;
        int unk2 = ((ptr->unk0->unk1D % 8) + ptr->unk0->unk1F + 7) / 8;
        ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk1C >> 3, ptr->unk0->unk1D >> 3, unk, unk2, 1);
    }
    if (c != 2)
        AddTextPrinterParameterized3(ptr->windowId, 1, ptr->unk0->unk1C, ptr->unk0->unk1D, gUnknown_086157FC[0], 0, gUnknown_08615B60[stringID]);
}

static void sub_81B302C(u8 *ptr)
{
    if (*ptr != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(*ptr, 0);
        RemoveWindow(*ptr);
        *ptr = 0xFF;
        schedule_bg_copy_tilemap_to_vram(2);
    }
}

void display_pokemon_menu_message(u32 stringID)
{
    u8 *windowPtr = &gUnknown_0203CEC4->unkC[1];

    if (*windowPtr != 0xFF)
        sub_81B302C(windowPtr);

    if (stringID != 0x7F)
    {
        switch (stringID)
        {
        case 21:
            *windowPtr = AddWindow(&gUnknown_08615928);
            break;
        case 24:
            *windowPtr = AddWindow(&gUnknown_08615930);
            break;
        case 25:
            *windowPtr = AddWindow(&gUnknown_08615938);
            break;
        case 22:
        case 23:
            *windowPtr = AddWindow(&gUnknown_08615940);
            break;
        case 26:
            *windowPtr = AddWindow(&gUnknown_08615948);
            break;
        default:
            *windowPtr = AddWindow(&gUnknown_08615920);
            break;
        }
        if (stringID == 0)
        {
            if (gUnknown_0203CEC4->unk8_0)
                stringID = 2;
            else if (sub_81B314C() == FALSE)
                stringID = 1;
        }
        DrawStdFrameWithCustomTileAndPalette(*windowPtr, FALSE, 0x4F, 0xD);
        StringExpandPlaceholders(gStringVar4, gUnknown_08615AF4[stringID]);
        AddTextPrinterParameterized(*windowPtr, 1, gStringVar4, 0, 1, 0, 0);
        schedule_bg_copy_tilemap_to_vram(2);
    }
}

static bool8 sub_81B314C(void)
{
    struct Pokemon *party = gPlayerParty;
    u8 i;
    u8 j = 0;

    if (gUnknown_0203CEC8.unkB == 1)
        return TRUE;

    for (i = 0; i < 6; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE && (GetMonData(&party[i], MON_DATA_HP) != 0 || GetMonData(&party[i], MON_DATA_IS_EGG)))
            j++;
        if (j > 1)
            return TRUE;
    }
    return FALSE;
}

static u8 sub_81B31B0(u8 a)
{
    struct WindowTemplate window;
    u8 cursorDimension;
    u8 fontAttribute;
    u8 i;

    switch (a)
    {
    case 0:
        SetWindowTemplateFields(&window, 2, 19, 19 - (gUnknown_0203CEC4->unk17 * 2), 10, gUnknown_0203CEC4->unk17 * 2, 14, 0x2E9);
        break;
    case 1:
        window = gUnknown_08615950;
        break;
    case 2:
        window = gUnknown_08615958;
        break;
    default:
        window = gUnknown_08615960;
        break;
    }

    gUnknown_0203CEC4->unkC[0] = AddWindow(&window);
    DrawStdFrameWithCustomTileAndPalette(gUnknown_0203CEC4->unkC[0], FALSE, 0x4F, 13);
    if (a == 3)
        return gUnknown_0203CEC4->unkC[0];
    cursorDimension = GetMenuCursorDimensionByFont(1, 0);
    fontAttribute = GetFontAttribute(1, 2);

    for (i = 0; i < gUnknown_0203CEC4->unk17; i++)
    {
        u8 unk = (gUnknown_0203CEC4->unkF[i] > 18) ? 4 : 3;
        AddTextPrinterParameterized4(gUnknown_0203CEC4->unkC[0], 1, cursorDimension, (i * 16) + 1, fontAttribute, 0, gUnknown_086157FC[unk], 0, sCursorOptions[gUnknown_0203CEC4->unkF[i]].text);
    }

    InitMenuInUpperLeftCorner(gUnknown_0203CEC4->unkC[0], gUnknown_0203CEC4->unk17, 0, 1);
    schedule_bg_copy_tilemap_to_vram(2);

    return gUnknown_0203CEC4->unkC[0];
}

static void sub_81B3300(const u8 *text)
{
    DrawStdFrameWithCustomTileAndPalette(6, FALSE, 0x4F, 13);
    gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(6, 1, text, GetPlayerTextSpeedDelay(), 0, 2, 1, 3);
}

static void sub_81B334C(void)
{
    CreateYesNoMenu(&gUnknown_08615968, 0x4F, 13, 0);
}

static u8 sub_81B3364(void)
{
    gUnknown_0203CEC4->unkC[0] = AddWindow(&gUnknown_08615970);
    DrawStdFrameWithCustomTileAndPalette(gUnknown_0203CEC4->unkC[0], FALSE, 0x4F, 13);
    return gUnknown_0203CEC4->unkC[0];
}

static void sub_81B3394(void)
{
    ClearWindowTilemap(gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
}

static void sub_81B33B4(struct Pokemon *mons, u8 a, u8 b)
{
    u8 i;

    if (b == 0)
    {
        sub_81B3414(mons, a);
    }
    else
    {
        gUnknown_0203CEC4->unk17 = gUnknown_08615D70[b];
        for (i = 0; i < gUnknown_0203CEC4->unk17; i++)
            gUnknown_0203CEC4->unkF[i] = gUnknown_08615D38[b][i];
    }
}

static void sub_81B3414(struct Pokemon *mons, u8 a)
{
    u8 i, j;

    gUnknown_0203CEC4->unk17 = 0;
    AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 0);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        for (j = 0; sFieldMoves[j] != FIELD_MOVE_TERMINATOR; j++)
        {
            if (GetMonData(&mons[a], i + MON_DATA_MOVE1) == sFieldMoves[j])
            {
                AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, j + 19);
                break;
            }
        }
    }

    if (!InBattlePike())
    {
        if (GetMonData(&mons[1], MON_DATA_SPECIES) != SPECIES_NONE)
            AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 1);
        if (ItemIsMail(GetMonData(&mons[a], MON_DATA_HELD_ITEM)))
            AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 6);
        else
            AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 3);
    }
    AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 2);
}

static u8 sub_81B353C(struct Pokemon *mon)
{
    u32 returnVar;

    switch (gUnknown_0203CEC8.unk8_0)
    {
    case 0:
        if (InMultiBattleRoom() == TRUE || GetMonData(mon, MON_DATA_IS_EGG))
            returnVar = 1;
        else
            returnVar = 0;
        break;
    case 1:
        returnVar = sub_81B8A2C(mon);
        break;
    case 4:
        switch (sub_81B856C(gUnknown_0203CEC8.unk9))
        {
        default:
            returnVar = 7;
            break;
        case 0:
            returnVar = 4;
            break;
        case 1:
            returnVar = 5;
            break;
        }
        break;
    case 6:
        returnVar = (GetMonData(mon, MON_DATA_IS_EGG)) ? 7 : 6;
        break;
    case 8:
        returnVar = 10;
        break;
    case 9:
        returnVar = 11;
        break;
    case 10:
        returnVar = 12;
        break;
    case 12:
        returnVar = 13;
        break;
    default:
        returnVar = 0;
        break;
    }
    return returnVar;
}

static bool8 sub_81B3608(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item;

    GetMonNickname(mon, gStringVar1);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    if (gUnknown_0203CEC8.unk8_0 != 12)
    {
        sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, sub_81B353C(mon));
        sub_81B31B0(0);
        display_pokemon_menu_message(21);
    }
    else
    {
        item = GetMonData(mon, MON_DATA_HELD_ITEM);
        if (item != ITEM_NONE)
        {
            sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, sub_81B353C(mon));
            sub_81B31B0(1);
            CopyItemName(item, gStringVar2);
            display_pokemon_menu_message(26);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnNotHolding);
            sub_81B1B5C(gStringVar4, 1);
            schedule_bg_copy_tilemap_to_vram(2);
            gTasks[taskId].func = sub_81B469C;
            return FALSE;
        }
    }
    return TRUE;
}

static void sub_81B36FC(u8 taskId)
{
    if (sub_81B3608(taskId))
    {
        gTasks[taskId].data[0] = 0xFF;
        gTasks[taskId].func = HandleMenuInput;
    }
}

static void HandleMenuInput(u8 taskId)
{
    if (!gPaletteFade.active && sub_81221EC() != TRUE)
    {
        s8 input;
        s16 *data = gTasks[taskId].data;

        if (gUnknown_0203CEC4->unk17 <= 3)
            input = Menu_ProcessInputNoWrapAround_other();
        else
            input = ProcessMenuInput_other();

        data[0] = Menu_GetCursorPos();
        switch (input)
        {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_81B302C(&gUnknown_0203CEC4->unkC[2]);
            sCursorOptions[gUnknown_0203CEC4->unkF[gUnknown_0203CEC4->unk17 - 1]].func(taskId);
            break;
        default:
            sub_81B302C(&gUnknown_0203CEC4->unkC[2]);
            sCursorOptions[gUnknown_0203CEC4->unkF[input]].func(taskId);
            break;
        }
    }
}

static void CursorCb_Summary(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC4->exitCallback = sub_81B3828;
    sub_81B12C0(taskId);
}

static void sub_81B3828(void)
{
    if (gUnknown_0203CEC8.unk8_0 == 1)
    {
        pokemon_change_order();
        ShowPokemonSummaryScreen(PSS_MODE_UNK1, gPlayerParty, gUnknown_0203CEC8.unk9, gPlayerPartyCount - 1, sub_81B3894);
    }
    else
    {
        ShowPokemonSummaryScreen(PSS_MODE_NORMAL, gPlayerParty, gUnknown_0203CEC8.unk9, gPlayerPartyCount - 1, sub_81B3894);
    }
}

static void sub_81B3894(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    gUnknown_0203CEC8.unk9 = gLastViewedMonIndex;
    InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 21, sub_81B36FC, gUnknown_0203CEC8.exitCallback);
}

static void CursorCb_Switch(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC8.unkB = 8;
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    display_pokemon_menu_message(3);
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
    gUnknown_0203CEC8.unkA = gUnknown_0203CEC8.unk9;
    gTasks[taskId].func = sub_81B1370;
}

static void sub_81B3938(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 windowIds[2];

    if (gUnknown_0203CEC8.unkA == gUnknown_0203CEC8.unk9)
    {
        sub_81B407C(taskId);
    }
    else
    {
        windowIds[0] = gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].windowId;
        data[0] = GetWindowAttribute(windowIds[0], WINDOW_TILEMAP_LEFT);
        data[1] = GetWindowAttribute(windowIds[0], WINDOW_TILEMAP_TOP);
        data[2] = GetWindowAttribute(windowIds[0], WINDOW_WIDTH);
        data[3] = GetWindowAttribute(windowIds[0], WINDOW_HEIGHT);
        data[8] = 0;
        if (data[2] == 10)
            data[10] = -1;
        else
            data[10] = 1;
        windowIds[1] = gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].windowId;
        data[4] = GetWindowAttribute(windowIds[1], WINDOW_TILEMAP_LEFT);
        data[5] = GetWindowAttribute(windowIds[1], WINDOW_TILEMAP_TOP);
        data[6] = GetWindowAttribute(windowIds[1], WINDOW_WIDTH);
        data[7] = GetWindowAttribute(windowIds[1], WINDOW_HEIGHT);
        data[9] = 0;
        if (data[6] == 10)
            data[11] = -1;
        else
            data[11] = 1;
        gUnknown_0203CEF0 = Alloc(data[2] * (data[3] << 1));
        gUnknown_0203CEF4 = Alloc(data[6] * (data[7] << 1));
        sub_8199CBC(0, gUnknown_0203CEF0, data[0], data[1], data[2], data[3]);
        sub_8199CBC(0, gUnknown_0203CEF4, data[4], data[5], data[6], data[7]);
        ClearWindowTilemap(windowIds[0]);
        ClearWindowTilemap(windowIds[1]);
        gUnknown_0203CEC8.unkB = 9;
        sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
        sub_81B0FCC(gUnknown_0203CEC8.unkA, 1);
        sub_81B3CC0(taskId);
        gTasks[taskId].func = sub_81B3D48;
    }
}

static bool8 sub_81B3AD8(s16 a, s16 b, u8 *c, u8 *d, u8 *e)
{
    if ((a + b) < 0)
        return FALSE;
    if (a > 31)
        return FALSE;

    if (a < 0)
    {
        *c = a * -1;
        *d = 0;
        *e = b + a;
    }
    else
    {
        *c = 0;
        *d = a;
        if ((a + b) > 31)
            *e = 32 - a;
        else
            *e = b;

    }
    return TRUE;
}

static void sub_81B3B40(const void *rectSrc, s16 a, s16 b, s16 c, s16 d, s16 e)
{
    u8 f, g, h;

    if (sub_81B3AD8(a, c, &f, &g, &h))
    {
        FillBgTilemapBufferRect_Palette0(0, 0, g, b, h, d);
        if (sub_81B3AD8(a + e, c, &f, &g, &h))
            CopyRectToBgTilemapBufferRect(0, rectSrc, f, 0, c, d, g, b, h, d, 17, 0, 0);
    }
}

static void sub_81B3C0C(struct Struct203CEDC *ptr, s16 a)
{
    gSprites[ptr->unkB].pos2.x += a * 8;
    gSprites[ptr->unkA].pos2.x += a * 8;
    gSprites[ptr->unk9].pos2.x += a * 8;
    gSprites[ptr->unkC].pos2.x += a * 8;
}

static void sub_81B3C60(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[10] != 0)
        sub_81B3C0C(&gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], data[10]);
    if (data[11] != 0)
        sub_81B3C0C(&gUnknown_0203CEDC[gUnknown_0203CEC8.unkA], data[11]);
}

static void sub_81B3CC0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[10] != 0)
        sub_81B3B40(gUnknown_0203CEF0, data[0] + data[8], data[1], data[2], data[3], data[10]);
    if (data[11] != 0)
        sub_81B3B40(gUnknown_0203CEF4, data[4] + data[9], data[5], data[6], data[7], data[11]);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void sub_81B3D48(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 tilemapRelatedMaybe[2];

    sub_81B3CC0(taskId);
    sub_81B3C60(taskId);
    data[8] += data[10];
    data[9] += data[11];
    tilemapRelatedMaybe[0] = data[0] + data[8];
    tilemapRelatedMaybe[1] = data[4] + data[9];
    if (tilemapRelatedMaybe[0] > 33 && tilemapRelatedMaybe[1] > 33)
    {
        data[10] *= -1;
        data[11] *= -1;
        swap_pokemon_and_oams();
        DisplayPartyPokemonData(gUnknown_0203CEC8.unk9);
        DisplayPartyPokemonData(gUnknown_0203CEC8.unkA);
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].windowId);
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].windowId);
        sub_8199CBC(0, gUnknown_0203CEF0, data[0], data[1], data[2], data[3]);
        sub_8199CBC(0, gUnknown_0203CEF4, data[4], data[5], data[6], data[7]);
        ClearWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].windowId);
        ClearWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].windowId);
        gTasks[taskId].func = sub_81B3E60;
    }
}

static void sub_81B3E60(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    sub_81B3CC0(taskId);
    sub_81B3C60(taskId);
    if (data[10] == 0 && data[11] == 0)
    {
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].windowId);
        PutWindowTilemap(gUnknown_0203CEDC[gUnknown_0203CEC8.unkA].windowId);
        schedule_bg_copy_tilemap_to_vram(0);
        Free(gUnknown_0203CEF0);
        Free(gUnknown_0203CEF4);
        sub_81B407C(taskId);
    }
    else
    {
        data[8] += data[10];
        data[9] += data[11];
        if (data[8] == 0)
            data[10] = 0;
        if (data[9] == 0)
            data[11] = 0;
    }
}

static void oamt_swap_pos(u8 *spriteIdPtr1, u8 *spriteIdPtr2)
{
    u8 spriteIdBuffer = *spriteIdPtr1;
    u16 xBuffer1, yBuffer1, xBuffer2, yBuffer2;

    *spriteIdPtr1 = *spriteIdPtr2;
    *spriteIdPtr2 = spriteIdBuffer;
    xBuffer1 = gSprites[*spriteIdPtr1].pos1.x;
    yBuffer1 = gSprites[*spriteIdPtr1].pos1.y;
    xBuffer2 = gSprites[*spriteIdPtr1].pos2.x;
    yBuffer2 = gSprites[*spriteIdPtr1].pos2.y;
    gSprites[*spriteIdPtr1].pos1.x = gSprites[*spriteIdPtr2].pos1.x;
    gSprites[*spriteIdPtr1].pos1.y = gSprites[*spriteIdPtr2].pos1.y;
    gSprites[*spriteIdPtr1].pos2.x = gSprites[*spriteIdPtr2].pos2.x;
    gSprites[*spriteIdPtr1].pos2.y = gSprites[*spriteIdPtr2].pos2.y;
    gSprites[*spriteIdPtr2].pos1.x = xBuffer1;
    gSprites[*spriteIdPtr2].pos1.y = yBuffer1;
    gSprites[*spriteIdPtr2].pos2.x = xBuffer2;
    gSprites[*spriteIdPtr2].pos2.y = yBuffer2;
}

static void swap_pokemon_and_oams(void)
{
    struct Struct203CEDC *structPtrs[2];
    struct Pokemon *mon1, *mon2;
    struct Pokemon *monBuffer;

    structPtrs[0] = &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9];
    structPtrs[1] = &gUnknown_0203CEDC[gUnknown_0203CEC8.unkA];
    mon1 = &gPlayerParty[gUnknown_0203CEC8.unk9];
    mon2 = &gPlayerParty[gUnknown_0203CEC8.unkA];
    monBuffer = Alloc(sizeof(struct Pokemon));
    *monBuffer = *mon1;
    *mon1 = *mon2;
    *mon2 = *monBuffer;
    Free(monBuffer);
    oamt_swap_pos(&structPtrs[0]->unkB, &structPtrs[1]->unkB);
    oamt_swap_pos(&structPtrs[0]->unkA, &structPtrs[1]->unkA);
    oamt_swap_pos(&structPtrs[0]->unk9, &structPtrs[1]->unk9);
    oamt_swap_pos(&structPtrs[0]->unkC, &structPtrs[1]->unkC);
}

static void sub_81B407C(u8 taskId)
{
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    gUnknown_0203CEC8.unkB = 0;
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 0);
    gUnknown_0203CEC8.unk9 = gUnknown_0203CEC8.unkA;
    sub_81B0FCC(gUnknown_0203CEC8.unkA, 1);
    display_pokemon_menu_message(0);
    gTasks[taskId].func = sub_81B1370;
}

static void CursorCb_Cancel1(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    if (gUnknown_0203CEC8.unk8_0 == 6)
        display_pokemon_menu_message(15);
    else
        display_pokemon_menu_message(0);
    gTasks[taskId].func = sub_81B1370;
}

static void CursorCb_Item(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, 8);
    sub_81B31B0(1);
    display_pokemon_menu_message(24);
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = HandleMenuInput;
}

static void CursorCb_Give(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC4->exitCallback = sub_81B41C4;
    sub_81B12C0(taskId);
}

static void sub_81B41C4(void)
{
    if (InBattlePyramid() == FALSE)
        GoToBagMenu(RETURN_LOCATION_POKEMON_LIST, POCKETS_COUNT, c2_8123744);
    else
        sub_81C4F98(2, c2_8123744);
}

static void c2_8123744(void)
{
    if (gSpecialVar_ItemId == ITEM_NONE)
    {
        InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 0x7F, sub_81B36FC, gUnknown_0203CEC8.exitCallback);
    }
    else
    {
        gUnknown_0203CEFC = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_HELD_ITEM);
        if (gUnknown_0203CEFC != ITEM_NONE)
        {
            InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 0x7F, sub_81B4350, gUnknown_0203CEC8.exitCallback);
        }
        else if (ItemIsMail(gSpecialVar_ItemId))
        {
            RemoveBagItem(gSpecialVar_ItemId, 1);
            sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], gSpecialVar_ItemId);
            sub_81B452C();
        }
        else
        {
            InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 0x7F, sub_81B42D0, gUnknown_0203CEC8.exitCallback);
        }
    }
}

static void sub_81B42D0(u8 taskId)
{
    u16 item;

    if (!gPaletteFade.active)
    {
        item = gSpecialVar_ItemId;
        sub_81B1C84(&gPlayerParty[gUnknown_0203CEC8.unk9], item, 0, 0);
        sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], item);
        RemoveBagItem(item, 1);
        gTasks[taskId].func = sub_81B469C;
    }
}

static void sub_81B4350(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_81B1D1C(&gPlayerParty[gUnknown_0203CEC8.unk9], gUnknown_0203CEFC, 1);
        gTasks[taskId].func = sub_81B43A8;
    }
}

static void sub_81B43A8(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B43DC;
    }
}

static void sub_81B43DC(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        RemoveBagItem(gSpecialVar_ItemId, 1);
        if (AddBagItem(gUnknown_0203CEFC, 1) == FALSE)
        {
            AddBagItem(gSpecialVar_ItemId, 1);
            pokemon_item_not_removed(gUnknown_0203CEFC);
            sub_81B1B5C(gStringVar4, 0);
            gTasks[taskId].func = sub_81B1C1C;
        }
        else if (ItemIsMail(gSpecialVar_ItemId))
        {
            sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], gSpecialVar_ItemId);
            gTasks[taskId].func = sub_81B44FC;
        }
        else
        {
            sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], gSpecialVar_ItemId);
            sub_81B1D68(gSpecialVar_ItemId, gUnknown_0203CEFC, 1);
            gTasks[taskId].func = sub_81B469C;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        gTasks[taskId].func = sub_81B1C1C;
        break;
    }
}

static void sub_81B44FC(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        gUnknown_0203CEC4->exitCallback = sub_81B452C;
        sub_81B12C0(taskId);
    }
}

static void sub_81B452C(void)
{
    u8 mail = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_MAIL);

    DoEasyChatScreen(
    	EASY_CHAT_TYPE_MAIL,
    	gSaveBlock1Ptr->mail[mail].words,
    	sub_81B4578,
    	EASY_CHAT_PERSON_DISPLAY_NONE);
}

static void sub_81B4578(void)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (gSpecialVar_Result == FALSE)
    {
        TakeMailFromMon(mon);
        SetMonData(mon, MON_DATA_HELD_ITEM, &gUnknown_0203CEFC);
        RemoveBagItem(gUnknown_0203CEFC, 1);
        AddBagItem(item, 1);
        InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 0, sub_81B36FC, gUnknown_0203CEC8.exitCallback);
    }
    else
    {
        InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 0x7F, sub_81B4624, gUnknown_0203CEC8.exitCallback);
    }
}

static void sub_81B4624(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203CEFC == ITEM_NONE)
            sub_81B1C84(&gPlayerParty[gUnknown_0203CEC8.unk9], gSpecialVar_ItemId, 0, 0);
        else
            sub_81B1D68(gSpecialVar_ItemId, gUnknown_0203CEFC, 0);
        gTasks[taskId].func = sub_81B469C;
    }
}

static void sub_81B469C(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];

    if (sub_81B1BD4() != TRUE)
    {
        sub_81B5C94(mon, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9]);
        if (gUnknown_0203CEC8.unk8_0 == 12)
        {
            if (GetMonData(mon, MON_DATA_HELD_ITEM) != ITEM_NONE)
                DisplayPartyPokemonOtherText(11, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
            else
                DisplayPartyPokemonOtherText(12, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
        }
        sub_81B1C1C(taskId);
    }
}

static void CursorCb_TakeItem(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    switch (TryTakeMonItem(mon))
    {
    case 0:
        GetMonNickname(mon, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_PkmnNotHolding);
        sub_81B1B5C(gStringVar4, 1);
        break;
    case 1:
        pokemon_item_not_removed(item);
        sub_81B1B5C(gStringVar4, 1);
        break;
    default:
        sub_81B1CD0(mon, item, 1);
        break;
    }
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B469C;
}

static void CursorCb_Toss(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    if (item == ITEM_NONE)
    {
        GetMonNickname(mon, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_PkmnNotHolding);
        sub_81B1B5C(gStringVar4, 1);
        gTasks[taskId].func = sub_81B469C;
    }
    else
    {
        CopyItemName(item, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_ThrowAwayItem);
        sub_81B1B5C(gStringVar4, 1);
        gTasks[taskId].func = sub_81B48A8;
    }
}

static void sub_81B48A8(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B48DC;
    }
}

static void sub_81B48DC(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        CopyItemName(GetMonData(mon, MON_DATA_HELD_ITEM), gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_ItemThrownAway);
        sub_81B1B5C(gStringVar4, 0);
        gTasks[taskId].func = sub_81B4988;
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        gTasks[taskId].func = sub_81B1C1C;
        break;
    }
}

static void sub_81B4988(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];

    if (sub_81B1BD4() != TRUE)
    {
        u16 item = ITEM_NONE;

        SetMonData(mon, MON_DATA_HELD_ITEM, &item);
        sub_81B5C94(mon, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9]);
        DisplayPartyPokemonOtherText(12, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
        gTasks[taskId].func = sub_81B1C1C;
    }
}

static void CursorCb_Mail(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, 9);
    sub_81B31B0(2);
    display_pokemon_menu_message(25);
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = HandleMenuInput;
}

static void CursorCb_Read(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC4->exitCallback = sub_81B4A98;
    sub_81B12C0(taskId);
}

static void sub_81B4A98(void)
{
    ReadMail(&gSaveBlock1Ptr->mail[GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_MAIL)], sub_81B4AE0, 1);
}

static void sub_81B4AE0(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 21, sub_81B36FC, gUnknown_0203CEC8.exitCallback);
}

static void CursorCb_TakeMail(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B1B5C(gText_SendMailToPC, 1);
    gTasks[taskId].func = sub_81B4B6C;
}

static void sub_81B4B6C(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B4BA0;
    }
}

static void sub_81B4BA0(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        if (TakeMailFromMon2(&gPlayerParty[gUnknown_0203CEC8.unk9]) != 0xFF)
        {
            sub_81B1B5C(gText_MailSentToPC, 0);
            gTasks[taskId].func = sub_81B469C;
        }
        else
        {
            sub_81B1B5C(gText_PCMailboxFull, 0);
            gTasks[taskId].func = sub_81B1C1C;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        sub_81B1B5C(gText_MailMessageWillBeLost, 1);
        gTasks[taskId].func = sub_81B4C60;
        break;
    }
}

static void sub_81B4C60(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B4C94;
    }
}

static void sub_81B4C94(u8 taskId)
{
    u16 item;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        item = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_HELD_ITEM);
        if (AddBagItem(item, 1) == TRUE)
        {
            TakeMailFromMon(&gPlayerParty[gUnknown_0203CEC8.unk9]);
            sub_81B1B5C(gText_MailTakenFromPkmn, 0);
            gTasks[taskId].func = sub_81B469C;
        }
        else
        {
            pokemon_item_not_removed(item);
            sub_81B1B5C(gStringVar4, 0);
            gTasks[taskId].func = sub_81B1C1C;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        gTasks[taskId].func = sub_81B1C1C;
        break;
    }
}

static void CursorCb_Cancel2(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];

    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, sub_81B353C(mon));
    if (gUnknown_0203CEC8.unk8_0 != 12)
    {
        sub_81B31B0(0);
        display_pokemon_menu_message(21);
    }
    else
    {
        sub_81B31B0(1);
        CopyItemName(GetMonData(mon, MON_DATA_HELD_ITEM), gStringVar2);
        display_pokemon_menu_message(26);
    }
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = HandleMenuInput;
}

static void CursorCb_SendMon(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    if (sub_81B8A7C() == TRUE)
    {
        sub_81B12C0(taskId);
    }
    else
    {
        sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
        sub_81B1B5C(gStringVar4, 1);
        gTasks[taskId].func = sub_81B1C1C;
    }
}

static void CursorCb_Enter(u8 taskId)
{
    u8 unk;
    u8 i;

    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    unk = sub_81B8830();
    for (i = 0; i < unk; i++)
    {
        if (gSelectedOrderFromParty[i] == 0)
        {
            PlaySE(SE_SELECT);
            gSelectedOrderFromParty[i] = gUnknown_0203CEC8.unk9 + 1;
            DisplayPartyPokemonOtherText(i + 2, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
            if (i == (unk - 1))
                sub_81B4F88();
            display_pokemon_menu_message(0);
            gTasks[taskId].func = sub_81B1370;
            return;
        }
    }
    ConvertIntToDecimalStringN(gStringVar1, unk, 0, 1);
    StringExpandPlaceholders(gStringVar4, gText_NoMoreThanVar1Pkmn);
    PlaySE(SE_HAZURE);
    sub_81B1B5C(gStringVar4, 1);
    gTasks[taskId].func = sub_81B1C1C;
}

static void sub_81B4F88(void)
{
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 0);
    gUnknown_0203CEC8.unk9 = 6;
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
}

static void CursorCb_NoEntry(u8 taskId)
{
    u8 unk;
    u8 i, j;

    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    unk = sub_81B8830();
    for (i = 0; i < unk; i++)
    {
        if (gSelectedOrderFromParty[i] == (gUnknown_0203CEC8.unk9 + 1))
        {
            for (j = i; j < (unk - 1); j++)
                gSelectedOrderFromParty[j] = gSelectedOrderFromParty[j + 1];
            gSelectedOrderFromParty[j] = 0;
            break;
        }
    }
    DisplayPartyPokemonOtherText(1, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
    for (i = 0; i < (unk - 1); i++)
    {
        if (gSelectedOrderFromParty[i] != 0)
            DisplayPartyPokemonOtherText(i + 2, &gUnknown_0203CEDC[gSelectedOrderFromParty[i] - 1], 1);
    }
    display_pokemon_menu_message(0);
    gTasks[taskId].func = sub_81B1370;
}

static void CursorCb_Store(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B12C0(taskId);
}

static void CursorCb_Register(u8 taskId)
{
    u16 species2 = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES2);
    u16 species = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES);
    u8 obedience = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_OBEDIENCE);

    switch (sub_807A8D0(*(struct UnkLinkRfuStruct_02022B14Substruct *)sub_800F7DC(), species2, species, obedience))
    {
    case 1:
        StringExpandPlaceholders(gStringVar4, gText_PkmnCantBeTradedNow);
        break;
    case 2:
        StringExpandPlaceholders(gStringVar4, gText_EggCantBeTradedNow);
        break;
    default:
        PlaySE(SE_SELECT);
        sub_81B12C0(taskId);
        return;
    }
    PlaySE(SE_HAZURE);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    StringAppend(gStringVar4, gText_PauseUntilPress);
    sub_81B1B5C(gStringVar4, 1);
    gTasks[taskId].func = sub_81B1C1C;
}

static void CursorCb_Trade1(u8 taskId)
{
    u16 species2 = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES2);
    u16 species = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES);
    u8 obedience = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_OBEDIENCE);
    u32 stringId = sub_807A7E0(*(struct UnkLinkRfuStruct_02022B14Substruct *)sub_800F7DC(), gUnknown_02022C38, species2, gUnknown_02022C3C, gUnknown_02022C3E, species, obedience);

    if (stringId != 0)
    {
        StringExpandPlaceholders(gStringVar4, gUnknown_08615E0C[stringId - 1]);
        PlaySE(SE_HAZURE);
        sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
        sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
        StringAppend(gStringVar4, gText_PauseUntilPress);
        sub_81B1B5C(gStringVar4, 1);
        gTasks[taskId].func = sub_81B1C1C;
    }
    else
    {
        PlaySE(SE_SELECT);
        sub_81B12C0(taskId);
    }
}

static void CursorCb_Trade2(u8 taskId)
{
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    switch (sub_807A918(gPlayerParty, gUnknown_0203CEC8.unk9))
    {
    case 1:
        StringExpandPlaceholders(gStringVar4, gText_OnlyPkmnForBattle);
        break;
    case 2:
        StringExpandPlaceholders(gStringVar4, gText_PkmnCantBeTradedNow);
        break;
    case 3:
        StringExpandPlaceholders(gStringVar4, gText_EggCantBeTradedNow);
        break;
    default:
        PlaySE(SE_SELECT);
        GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gJPText_PutVar1IntoSpinner);
        sub_81B1B5C(gStringVar4, 1);
        gTasks[taskId].func = sub_81B53FC;
        return;
    }
    PlaySE(SE_HAZURE);
    StringAppend(gStringVar4, gText_PauseUntilPress);
    sub_81B1B5C(gStringVar4, 1);
    gTasks[taskId].func = sub_81B1C1C;
}

static void sub_81B53FC(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B5430;
    }
}

static void sub_81B5430(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        sub_81B12C0(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        sub_81B1C1C(taskId);
        break;
    }
}

static void CursorCb_FieldMove(u8 taskId)
{
    u8 fieldMove = gUnknown_0203CEC4->unkF[Menu_GetCursorPos()] - MENU_FIELD_MOVES;
    const struct MapHeader *mapHeader;

    PlaySE(SE_SELECT);
    if (sFieldMoveCursorCallbacks[fieldMove].fieldMoveFunc == NULL)
        return;

    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    if (sub_81221AC() == TRUE || InUnionRoom() == TRUE)
    {
        if (fieldMove == FIELD_MOVE_MILK_DRINK || fieldMove == FIELD_MOVE_SOFT_BOILED)
            display_pokemon_menu_message(13);
        else
            display_pokemon_menu_message(sFieldMoveCursorCallbacks[fieldMove].msgId);

        gTasks[taskId].func = task_brm_cancel_1_on_keypad_a_or_b;
    }
    else
    {
        // All field moves before WATERFALL are HMs.
        if (fieldMove <= FIELD_MOVE_WATERFALL && FlagGet(FLAG_BADGE01_GET + fieldMove) != TRUE)
        {
            sub_81B1B5C(gText_CantUseUntilNewBadge, 1);
            gTasks[taskId].func = sub_81B1C1C;
        }
        else if (sFieldMoveCursorCallbacks[fieldMove].fieldMoveFunc() == TRUE)
        {
            switch (fieldMove)
            {
            case FIELD_MOVE_MILK_DRINK:
            case FIELD_MOVE_SOFT_BOILED:
                sub_8161560(taskId);
                break;
            case FIELD_MOVE_TELEPORT:
                mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->lastHealLocation.mapGroup, gSaveBlock1Ptr->lastHealLocation.mapNum);
                sub_81245DC(gStringVar1, mapHeader->regionMapSectionId);
                StringExpandPlaceholders(gStringVar4, gText_ReturnToHealingSpot);
                sub_81B5674(taskId);
                gUnknown_0203CEC4->data[0] = fieldMove;
                break;
            case FIELD_MOVE_DIG:
                mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->escapeWarp.mapGroup, gSaveBlock1Ptr->escapeWarp.mapNum);
                sub_81245DC(gStringVar1, mapHeader->regionMapSectionId);
                StringExpandPlaceholders(gStringVar4, gText_EscapeFromHere);
                sub_81B5674(taskId);
                gUnknown_0203CEC4->data[0] = fieldMove;
                break;
            case FIELD_MOVE_FLY:
                gUnknown_0203CEC8.exitCallback = MCB2_FlyMap;
                sub_81B12C0(taskId);
                break;
            default:
                gUnknown_0203CEC8.exitCallback = CB2_ReturnToField;
                sub_81B12C0(taskId);
                break;
            }
        }
        else
        {
            switch (fieldMove)
            {
            case FIELD_MOVE_SURF:
                sub_81B5864();
                break;
            case FIELD_MOVE_FLASH:
                sub_81B57DC();
                break;
            default:
                display_pokemon_menu_message(sFieldMoveCursorCallbacks[fieldMove].msgId);
                break;
            }
            gTasks[taskId].func = task_brm_cancel_1_on_keypad_a_or_b;
        }
    }
}

static void sub_81B5674(u8 taskId)
{
    sub_81B1B5C(gStringVar4, 1);
    gTasks[taskId].func = sub_81B56A4;
}

static void sub_81B56A4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B56D8;
    }
}

static void sub_81B56D8(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        gUnknown_0203CEC8.exitCallback = CB2_ReturnToField;
        sub_81B12C0(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        gFieldCallback2 = NULL;
        gPostMenuFieldCallback = NULL;
        sub_81B1C1C(taskId);
        break;
    }
}

bool8 FieldCallback_PrepareFadeInFromMenu(void)
{
    pal_fill_black();
    CreateTask(task_launch_hm_phase_2, 8);
    return TRUE;
}

static void task_launch_hm_phase_2(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        gFieldEffectArguments[0] = brm_get_selected_species();
        gPostMenuFieldCallback();
        DestroyTask(taskId);
    }
}

static u16 brm_get_selected_species(void)
{
    return GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES);
}

static void task_brm_cancel_1_on_keypad_a_or_b(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
        CursorCb_Cancel1(taskId);
}

static void sub_81B57DC(void)
{
    if (FlagGet(FLAG_SYS_USE_FLASH) == TRUE)
        display_pokemon_menu_message(12);
    else
        display_pokemon_menu_message(13);
}

static void hm_surf_run_dp02scr(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_SURF);
}

static bool8 SetUpFieldMove_Surf(void)
{
    if (PartyHasMonWithSurf() == TRUE && IsPlayerFacingSurfableFishableWater() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = hm_surf_run_dp02scr;
        return TRUE;
    }
    return FALSE;
}

static void sub_81B5864(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        display_pokemon_menu_message(9);
    else
        display_pokemon_menu_message(8);
}

static bool8 SetUpFieldMove_Fly(void)
{
    if (Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
        return TRUE;
    else
        return FALSE;
}

void sub_81B58A8(void)
{
    InitPartyMenu(0, 0, 0, 1, 0, sub_81B1370, CB2_ReturnToFieldWithOpenMenu);
}

static void hm2_waterfall(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_WATERFALL);
}

static bool8 SetUpFieldMove_Waterfall(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    if (MetatileBehavior_IsWaterfall(MapGridGetMetatileBehaviorAt(x, y)) == TRUE && IsPlayerSurfingNorth() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = hm2_waterfall;
        return TRUE;
    }
    return FALSE;
}

static void sub_81B5958(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_DIVE);
}

static bool8 SetUpFieldMove_Dive(void)
{
    gFieldEffectArguments[1] = TrySetDiveWarp();
    if (gFieldEffectArguments[1] != 0)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = sub_81B5958;
        return TRUE;
    }
    return FALSE;
}

static void party_menu_icon_anim(struct Pokemon *mon, struct Struct203CEDC *ptr, u32 a)
{
    u32 bit = 1;
    u16 species2;

    if (IsMultiBattle() == TRUE && gMain.inBattle)
        bit = (gUnknown_08616020[a] ^ bit) ? 1 : 0;
    species2 = GetMonData(mon, MON_DATA_SPECIES2);
    party_menu_link_mon_icon_anim(species2, GetMonData(mon, MON_DATA_PERSONALITY), ptr, 1, bit);
    sub_81B5B38(ptr->unk9, mon);
}

static void party_menu_link_mon_icon_anim(u16 species, u32 pid, struct Struct203CEDC *ptr, u8 priority, u32 bit)
{
    if (species != SPECIES_NONE)
    {
        ptr->unk9 = CreateMonIcon(species, sub_80D3014, ptr->unk4[0], ptr->unk4[1], 4, pid, bit);
        gSprites[ptr->unk9].oam.priority = priority;
    }
}

static void sub_81B5A8C(u8 spriteId, u16 hp, u16 maxhp)
{
    switch (GetHPBarLevel(hp, maxhp))
    {
    case HP_BAR_FULL:
        sub_80D32C8(&gSprites[spriteId], 0);
        break;
    case HP_BAR_GREEN:
        sub_80D32C8(&gSprites[spriteId], 1);
        break;
    case HP_BAR_YELLOW:
        sub_80D32C8(&gSprites[spriteId], 2);
        break;
    case HP_BAR_RED:
        sub_80D32C8(&gSprites[spriteId], 3);
        break;
    default:
        sub_80D32C8(&gSprites[spriteId], 4);
        break;
    }
}

static void sub_81B5B38(u8 spriteId, struct Pokemon *mon)
{
    sub_81B5A8C(spriteId, GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP));
}

static void AnimateSelectedPartyIcon(u8 spriteId, u8 a)
{
    gSprites[spriteId].data[0] = 0;
    if (a == 0)
    {
        if (gSprites[spriteId].pos1.x == 16)
        {
            gSprites[spriteId].pos2.x = 0;
            gSprites[spriteId].pos2.y = -4;
        }
        else
        {
            gSprites[spriteId].pos2.x = -4;
            gSprites[spriteId].pos2.y = 0;
        }
        gSprites[spriteId].callback = UpdatePartyMonIconFrame;
    }
    else
    {
        gSprites[spriteId].pos2.x = 0;
        gSprites[spriteId].pos2.y = 0;
        gSprites[spriteId].callback = UpdatePartyMonIconFrameAndBounce;
    }
}

static void UpdatePartyMonIconFrameAndBounce(struct Sprite *sprite)
{
    u8 unk = UpdateMonIconFrame(sprite);

    if (unk != 0)
    {
        if (unk & 1)
            sprite->pos2.y = -3;
        else
            sprite->pos2.y = 1;
    }
}

static void UpdatePartyMonIconFrame(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

static void party_menu_held_item_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        ptr->unkA = CreateSprite(&gSpriteTemplate_8615EC0, ptr->unk4[2], ptr->unk4[3], 0);
        sub_81B5C94(mon, ptr);
    }
}

static void party_menu_link_mon_held_item_object(u16 species, u16 item, struct Struct203CEDC *ptr)
{
    if (species != SPECIES_NONE)
    {
        ptr->unkA = CreateSprite(&gSpriteTemplate_8615EC0, ptr->unk4[2], ptr->unk4[3], 0);
        gSprites[ptr->unkA].oam.priority = 0;
        sub_81B5CB0(item, ptr);
    }
}

static void sub_81B5C94(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    sub_81B5CB0(GetMonData(mon, MON_DATA_HELD_ITEM), ptr);
}

static void sub_81B5CB0(u16 item, struct Struct203CEDC *ptr)
{
    if (item == ITEM_NONE)
    {
        gSprites[ptr->unkA].invisible = TRUE;
    }
    else
    {
        if (ItemIsMail(item))
            StartSpriteAnim(&gSprites[ptr->unkA], 1);
        else
            StartSpriteAnim(&gSprites[ptr->unkA], 0);
        gSprites[ptr->unkA].invisible = FALSE;
    }
}

void LoadHeldItemIcons(void)
{
    LoadSpriteSheet(&gUnknown_08615EB0);
    LoadSpritePalette(&gUnknown_08615EB8);
}

void sub_81B5D4C(u8 *a, u8 *b, u8 c)
{
    u16 i;
    u16 item;

    switch (c)
    {
    case 0:
        for (i = 0; i < a[0]; i++)
        {
            item = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
            if (item != ITEM_NONE)
                sub_81B5DF0(b[i], ItemIsMail(item));
        }
        break;
    case 1:
        for (i = 0; i < a[1]; i++)
        {
            item = GetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM);
            if (item != ITEM_NONE)
                sub_81B5DF0(b[i + 6], ItemIsMail(item));
        }
        break;
    }
}

static void sub_81B5DF0(u8 spriteId, u8 isMail)
{
    u8 subpriority = gSprites[spriteId].subpriority;
    u8 newSpriteId = CreateSprite(&gSpriteTemplate_8615EC0, 250, 170, subpriority - 1);

    gSprites[newSpriteId].pos2.x = 4;
    gSprites[newSpriteId].pos2.y = 10;
    gSprites[newSpriteId].callback = sub_81B5E74;
    gSprites[newSpriteId].data[7] = spriteId;
    StartSpriteAnim(&gSprites[newSpriteId], isMail);
    gSprites[newSpriteId].callback(&gSprites[newSpriteId]);
}

static void sub_81B5E74(struct Sprite *sprite)
{
    u8 otherSpriteId = sprite->data[7];

    if (gSprites[otherSpriteId].invisible)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->pos1.x = gSprites[otherSpriteId].pos1.x + gSprites[otherSpriteId].pos2.x;
        sprite->pos1.y = gSprites[otherSpriteId].pos1.y + gSprites[otherSpriteId].pos2.y;
    }
}

static void party_menu_pokeball_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
        ptr->unkB = CreateSprite(&gSpriteTemplate_8615F08, ptr->unk4[6], ptr->unk4[7], 8);
}

static void party_menu_link_mon_pokeball_object(u16 species, struct Struct203CEDC *ptr)
{
    if (species != SPECIES_NONE)
    {
        ptr->unkB = CreateSprite(&gSpriteTemplate_8615F08, ptr->unk4[6], ptr->unk4[7], 8);
        gSprites[ptr->unkB].oam.priority = 0;
    }
}

static u8 sub_81B5F34(u8 x, u8 y)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_8615F08, x, y, 8);

    gSprites[spriteId].oam.priority = 2;
    return spriteId;
}

static u8 sub_81B5F74(u8 x, u8 y)
{
    return CreateSprite(&gSpriteTemplate_8615F78, x, y, 8);
}

static void sub_81B5F98(u8 spriteId, u8 a)
{
    StartSpriteAnim(&gSprites[spriteId], a);
}

static void sub_81B5FBC(u8 spriteId, u8 spriteId2, u8 a)
{
    if (a == 0)
    {
        StartSpriteAnim(&gSprites[spriteId], 2);
        StartSpriteAnim(&gSprites[spriteId2], 4);
        gSprites[spriteId].pos2.y = 0;
        gSprites[spriteId2].pos2.y = 0;
    }
    else
    {
        StartSpriteAnim(&gSprites[spriteId], 3);
        StartSpriteAnim(&gSprites[spriteId2], 5);
        gSprites[spriteId].pos2.y = -4;
        gSprites[spriteId2].pos2.y = 4;
    }
}

static void LoadPartyMenuPokeballGfx(void)
{
    LoadCompressedSpriteSheet(&gUnknown_08615EF8);
    LoadCompressedSpriteSheet(&gUnknown_08615F70);
    LoadCompressedSpritePalette(&gUnknown_08615F00);
}

static void party_menu_status_condition_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        ptr->unkC = CreateSprite(&gSpriteTemplate_8616008, ptr->unk4[4], ptr->unk4[5], 0);
        party_menu_get_status_condition_and_update_object(mon, ptr);
    }
}

static void party_menu_link_mon_status_condition_object(u16 species, u8 status, struct Struct203CEDC *ptr)
{
    if (species != SPECIES_NONE)
    {
        ptr->unkC = CreateSprite(&gSpriteTemplate_8616008, ptr->unk4[4], ptr->unk4[5], 0);
        party_menu_update_status_condition_object(status, ptr);
        gSprites[ptr->unkC].oam.priority = 0;
    }
}

static void party_menu_get_status_condition_and_update_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    party_menu_update_status_condition_object(GetMonAilment(mon), ptr);
}

static void party_menu_update_status_condition_object(u8 status, struct Struct203CEDC *ptr)
{
    switch (status)
    {
    case AILMENT_NONE:
    case AILMENT_PKRS:
        gSprites[ptr->unkC].invisible = TRUE;
        break;
    default:
        StartSpriteAnim(&gSprites[ptr->unkC], status - 1);
        gSprites[ptr->unkC].invisible = FALSE;
        break;
    }
}

static void LoadPartyMenuAilmentGfx(void)
{
    LoadCompressedSpriteSheet(&gUnknown_08615FF8);
    LoadCompressedSpritePalette(&gUnknown_08616000);
}

void sub_81B617C(void)
{
    MainCallback callback = c2_815ABFC;
    u8 doubleBattleStatus;
    bool8 inBattle;
    u8 i;
    u8 msgIdMaybe;
    TaskFunc task;

    if (gMain.inBattle)
    {
        inBattle = TRUE;
        doubleBattleStatus = sub_81B8984();
    }
    else
    {
        inBattle = FALSE;
        doubleBattleStatus = 0;
    }

    if (GetItemEffectType(gSpecialVar_ItemId) == ITEM_EFFECT_SACRED_ASH)
    {
        gUnknown_0203CEC8.unk9 = 0;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE && GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
            {
                gUnknown_0203CEC8.unk9 = i;
                break;
            }
        }
        task = sub_81B6280;
        msgIdMaybe = 0x7F;
    }
    else
    {
        if (GetPocketByItemId(gSpecialVar_ItemId) == POCKET_TM_HM)
            msgIdMaybe = 4;
        else
            msgIdMaybe = 5;

        task = sub_81B1370;
    }

    InitPartyMenu(inBattle, doubleBattleStatus, 3, 1, msgIdMaybe, task, callback);
}

static void c2_815ABFC(void)
{
    if (InBattlePyramid() == FALSE)
        GoToBagMenu(RETURN_LOCATION_UNCHANGED, POCKETS_COUNT, NULL);
    else
        sub_81C4F98(4, gPyramidBagCursorData.callback);
}

static void sub_81B6280(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203CEC8.unk8_0 == 1)
            gUnknown_0203CEC4->exitCallback = sub_81B9140;
        gUnknown_03006328(taskId, sub_81B6794);
    }
}

static bool8 IsHPRecoveryItem(u16 item)
{
    const u8 *effect;

    if (item == ITEM_ENIGMA_BERRY)
        effect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    else
        effect = gItemEffectTable[item - ITEM_POTION];

    if (effect[4] & ITEM4_HEAL_HP)
        return TRUE;
    else
        return FALSE;
}

static void GetMedicineItemEffectMessage(u16 item)
{
    switch (GetItemEffectType(item))
    {
    case ITEM_EFFECT_CURE_POISON:
        StringExpandPlaceholders(gStringVar4, gText_PkmnCuredOfPoison);
        break;
    case ITEM_EFFECT_CURE_SLEEP:
        StringExpandPlaceholders(gStringVar4, gText_PkmnWokeUp2);
        break;
    case ITEM_EFFECT_CURE_BURN:
        StringExpandPlaceholders(gStringVar4, gText_PkmnBurnHealed);
        break;
    case ITEM_EFFECT_CURE_FREEZE:
        StringExpandPlaceholders(gStringVar4, gText_PkmnThawedOut);
        break;
    case ITEM_EFFECT_CURE_PARALYSIS:
        StringExpandPlaceholders(gStringVar4, gText_PkmnCuredOfParalysis);
        break;
    case ITEM_EFFECT_CURE_CONFUSION:
        StringExpandPlaceholders(gStringVar4, gText_PkmnSnappedOutOfConfusion);
        break;
    case ITEM_EFFECT_CURE_INFATUATION:
        StringExpandPlaceholders(gStringVar4, gText_PkmnGotOverInfatuation);
        break;
    case ITEM_EFFECT_CURE_ALL_STATUS:
        StringExpandPlaceholders(gStringVar4, gText_PkmnBecameHealthy);
        break;
    case ITEM_EFFECT_HP_EV:
        StringCopy(gStringVar2, gText_HP3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_ATK_EV:
        StringCopy(gStringVar2, gText_Attack3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_DEF_EV:
        StringCopy(gStringVar2, gText_Defense3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_SPEED_EV:
        StringCopy(gStringVar2, gText_Speed2);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_SPATK_EV:
        StringCopy(gStringVar2, gText_SpAtk3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_SPDEF_EV:
        StringCopy(gStringVar2, gText_SpDef3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_PP_UP:
    case ITEM_EFFECT_PP_MAX:
        StringExpandPlaceholders(gStringVar4, gText_MovesPPIncreased);
        break;
    case ITEM_EFFECT_HEAL_PP:
        StringExpandPlaceholders(gStringVar4, gText_PPWasRestored);
        break;
    default:
        StringExpandPlaceholders(gStringVar4, gText_WontHaveEffect);
        break;
    }
}

static bool8 UsingHPEVItemOnShedinja(struct Pokemon *mon, u16 item)
{
    if (GetItemEffectType(item) == ITEM_EFFECT_HP_EV && GetMonData(mon, MON_DATA_SPECIES) == SPECIES_SHEDINJA)
        return FALSE;
    return TRUE;
}

static bool8 IsItemFlute(u16 item)
{
    if (item == ITEM_BLUE_FLUTE || item == ITEM_RED_FLUTE || item == ITEM_YELLOW_FLUTE)
        return TRUE;
    return FALSE;
}

static bool8 ExecuteTableBasedItemEffect__(u8 partyMonIndex, u16 item, u8 monMoveIndex)
{
    if (gMain.inBattle)
        return ExecuteTableBasedItemEffect(&gPlayerParty[partyMonIndex], item, sub_81B8F38(partyMonIndex), monMoveIndex);
    else
        return ExecuteTableBasedItemEffect(&gPlayerParty[partyMonIndex], item, partyMonIndex, monMoveIndex);
}

void ItemUseCB_Medicine(u8 taskId, TaskFunc task)
{
    u16 hp = 0;
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item = gSpecialVar_ItemId;
    bool8 canHeal;

    if (UsingHPEVItemOnShedinja(mon, item))
    {
        canHeal = IsHPRecoveryItem(item);
        if (canHeal == TRUE)
        {
            hp = GetMonData(mon, MON_DATA_HP);
            if (hp == GetMonData(mon, MON_DATA_MAX_HP))
                canHeal = FALSE;
        }
        if (ExecuteTableBasedItemEffect__(gUnknown_0203CEC8.unk9, item, 0))
        {
            iTriedHonestlyIDid:
            gUnknown_0203CEE8 = 0;
            PlaySE(SE_SELECT);
            sub_81B1B5C(gText_WontHaveEffect, 1);
            schedule_bg_copy_tilemap_to_vram(2);
            gTasks[taskId].func = task;
            return;
        }
    }
    else
    {
        goto iTriedHonestlyIDid;
    }
    gUnknown_0203CEE8 = 1;
    if (IsItemFlute(item) == FALSE)
    {
        PlaySE(SE_KAIFUKU);
        if (gUnknown_0203CEC8.unkB != 14)
            RemoveBagItem(item, 1);
    }
    else
    {
        PlaySE(SE_BIDORO);
    }
    party_menu_get_status_condition_and_update_object(mon, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9]);
    if (gSprites[gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].unkC].invisible)
        DisplayPartyPokemonLevelCheck(mon, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
    if (canHeal == TRUE)
    {
        if (hp == 0)
            sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
        sub_81B1F18(taskId, gUnknown_0203CEC8.unk9, 1, GetMonData(mon, MON_DATA_HP) - hp, sub_81B672C);
        sub_81B1FA8(taskId, 0, hp);
        return;
    }
    else
    {
        GetMonNickname(mon, gStringVar1);
        GetMedicineItemEffectMessage(item);
        sub_81B1B5C(gStringVar4, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = task;
    }
}

static void sub_81B672C(u8 taskId)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
    sub_81B1B5C(gStringVar4, 0);
    schedule_bg_copy_tilemap_to_vram(2);
    HandleBattleLowHpMusicChange();
    gTasks[taskId].func = sub_81B6794;
}

static void sub_81B6794(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        if (gUnknown_0203CEE8 == 0)
            gUnknown_0203CEC4->exitCallback = NULL;
        sub_81B12C0(taskId);
    }
}

void sub_81B67C8(u8 taskId, TaskFunc task)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item = gSpecialVar_ItemId;
    u8 effectType = GetItemEffectType(item);
    u16 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 relevantEV = ItemEffectToMonEv(mon, effectType);
    bool8 cannotUseEffect = ExecuteTableBasedItemEffect__(gUnknown_0203CEC8.unk9, item, 0);
    u16 newFriendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 newRelevantEV = ItemEffectToMonEv(mon, effectType);

    if (cannotUseEffect || (friendship == newFriendship && relevantEV == newRelevantEV))
    {
        gUnknown_0203CEE8 = 0;
        PlaySE(SE_SELECT);
        sub_81B1B5C(gText_WontHaveEffect, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = task;
    }
    else
    {
        gUnknown_0203CEE8 = 1;
        PlaySE(SE_KAIFUKU);
        RemoveBagItem(item, 1);
        GetMonNickname(mon, gStringVar1);
        ItemEffectToStatString(effectType, gStringVar2);
        if (friendship != newFriendship)
        {
            if (relevantEV != newRelevantEV)
                StringExpandPlaceholders(gStringVar4, gText_PkmnFriendlyBaseVar2Fell);
            else
                StringExpandPlaceholders(gStringVar4, gText_PkmnFriendlyBaseVar2CantFall);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnAdoresBaseVar2Fell);
        }
        sub_81B1B5C(gStringVar4, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = task;
    }
}

static u16 ItemEffectToMonEv(struct Pokemon *mon, u8 effectType)
{
    switch (effectType)
    {
    case ITEM_EFFECT_HP_EV:
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_SHEDINJA)
            return GetMonData(mon, MON_DATA_HP_EV);
        break;
    case ITEM_EFFECT_ATK_EV:
        return GetMonData(mon, MON_DATA_ATK_EV);
    case ITEM_EFFECT_DEF_EV:
        return GetMonData(mon, MON_DATA_DEF_EV);
    case ITEM_EFFECT_SPEED_EV:
        return GetMonData(mon, MON_DATA_SPEED_EV);
    case ITEM_EFFECT_SPATK_EV:
        return GetMonData(mon, MON_DATA_SPATK_EV);
    case ITEM_EFFECT_SPDEF_EV:
        return GetMonData(mon, MON_DATA_SPDEF_EV);
    }
    return 0;
}

static void ItemEffectToStatString(u8 effectType, u8 *dest)
{
    switch (effectType)
    {
    case ITEM_EFFECT_HP_EV:
        StringCopy(dest, gText_HP3);
        break;
    case ITEM_EFFECT_ATK_EV:
        StringCopy(dest, gText_Attack3);
        break;
    case ITEM_EFFECT_DEF_EV:
        StringCopy(dest, gText_Defense3);
        break;
    case ITEM_EFFECT_SPEED_EV:
        StringCopy(dest, gText_Speed2);
        break;
    case ITEM_EFFECT_SPATK_EV:
        StringCopy(dest, gText_SpAtk3);
        break;
    case ITEM_EFFECT_SPDEF_EV:
        StringCopy(dest, gText_SpDef3);
        break;
    }
}

static void sub_81B6A10(u8 slot)
{
    u8 i;
    u8 moveCount = 0;
    u8 fontId = 1;
    u8 windowId = sub_81B31B0(3);
    u16 move;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        move = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE1 + i);
        AddTextPrinterParameterized(windowId, fontId, gMoveNames[move], 8, (i * 16) + 1, 0xFF, NULL);
        if (move != MOVE_NONE)
            moveCount++;
    }
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, moveCount, 0);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void ether_effect_related_3(u8 taskId)
{
    s8 input = Menu_ProcessInput();

    if (input != MENU_NOTHING_CHOSEN)
    {
        if (input == MENU_B_PRESSED)
        {
            PlaySE(SE_SELECT);
            sub_81B6BB4(taskId);
        }
        else
        {
            sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
            ether_effect_related_2(taskId);
        }
    }
}

void dp05_ether(u8 taskId, TaskFunc task)
{
    const u8 *effect;
    u16 item = gSpecialVar_ItemId;

    if (item == ITEM_ENIGMA_BERRY)
        effect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    else
        effect = gItemEffectTable[item - ITEM_POTION];

    if (!(effect[4] & ITEM4_HEAL_PP_ONE))
    {
        gUnknown_0203CEC8.unkE = 0;
        ether_effect_related(taskId);
    }
    else
    {
        PlaySE(SE_SELECT);
        display_pokemon_menu_message(22);
        sub_81B6A10(gUnknown_0203CEC8.unk9);
        gTasks[taskId].func = ether_effect_related_3;
    }
}

static void ether_effect_related_2(u8 taskId)
{
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    gUnknown_0203CEC8.unkE = Menu_GetCursorPos();
    ether_effect_related(taskId);
}

static void sub_81B6BB4(u8 taskId)
{
    gTasks[taskId].func = sub_81B1370;
    gUnknown_0203CEC4->exitCallback = NULL;
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    display_pokemon_menu_message(5);
}

static void ether_effect_related(u8 taskId)
{
    u16 move = MOVE_NONE;
    s16 *moveslot = &gUnknown_0203CEC8.unkE;
    u16 item = gSpecialVar_ItemId;
    struct Struct203CEC8 *ptr = &gUnknown_0203CEC8;
    struct Pokemon *mon;

    if (ExecuteTableBasedItemEffect__(ptr->unk9, item, *moveslot))
    {
        gUnknown_0203CEE8 = 0;
        PlaySE(SE_SELECT);
        sub_81B1B5C(gText_WontHaveEffect, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = sub_81B6794;
    }
    else
    {
        gUnknown_0203CEE8 = 1;
        mon = &gPlayerParty[ptr->unk9];
        PlaySE(SE_KAIFUKU);
        RemoveBagItem(item, 1);
        move = GetMonData(mon, MON_DATA_MOVE1 + *moveslot);
        StringCopy(gStringVar1, gMoveNames[move]);
        GetMedicineItemEffectMessage(item);
        sub_81B1B5C(gStringVar4, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = sub_81B6794;
    }
}

void dp05_pp_up(u8 taskId, TaskFunc task)
{
    PlaySE(SE_SELECT);
    display_pokemon_menu_message(23);
    sub_81B6A10(gUnknown_0203CEC8.unk9);
    gTasks[taskId].func = ether_effect_related_3;
}

u16 ItemIdToBattleMoveId(u16 item)
{
    u16 tmNumber = item - ITEM_TM01_FOCUS_PUNCH;
    return gTMHMMoves[tmNumber];
}

bool8 IsMoveHm(u16 move)
{
    u8 i;

    for (i = 0; i < NUM_HIDDEN_MACHINES; i++)
    {
        if (gTMHMMoves[i + NUM_TECHNICAL_MACHINES] == move)
            return TRUE;
    }
    return FALSE;
}

bool8 MonKnowsMove(struct Pokemon *mon, u16 move)
{
    u8 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetMonData(mon, MON_DATA_MOVE1 + i) == move)
            return TRUE;
    }
    return FALSE;
}

static void sub_81B6D74(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_81B6D98(u8 taskId, const u8 *str)
{
    sub_81B6D74(str);
    gTasks[taskId].func = sub_81B6794;
}

// move[1] doesn't use constants cause I don't know if it's actually a move ID storage

void sub_81B6DC4(u8 taskId, TaskFunc task)
{
    struct Pokemon *mon;
    s16 *move;
    u16 item;

    PlaySE(SE_SELECT);
    mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    move = &gUnknown_0203CEC8.unkE;
    item = gSpecialVar_ItemId;
    GetMonNickname(mon, gStringVar1);
    move[0] = ItemIdToBattleMoveId(item);
    StringCopy(gStringVar2, gMoveNames[move[0]]);
    move[1] = 0;

    switch (CanMonLearnTMTutor(mon, item, 0))
    {
    case CANNOT_LEARN_MOVE:
        sub_81B6D98(taskId, gText_PkmnCantLearnMove);
        return;
    case ALREADY_KNOWS_MOVE:
        sub_81B6D98(taskId, gText_PkmnAlreadyKnows);
        return;
    }

    if (GiveMoveToMon(mon, move[0]) != 0xFFFF)
    {
        gTasks[taskId].func = sub_81B6EB4;
    }
    else
    {
        sub_81B6D74(gText_PkmnNeedsToReplaceMove);
        gTasks[taskId].func = sub_81B6FF4;
    }
}

static void sub_81B6EB4(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    s16 *move = &gUnknown_0203CEC8.unkE;
    u16 item = gSpecialVar_ItemId;

    if (move[1] == 0)
    {
        AdjustFriendship(mon, 4);
        if (item < ITEM_HM01_CUT)
            RemoveBagItem(item, 1);
    }
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move[0]]);
    StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B6F60;
}

static void sub_81B6F60(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        PlayFanfare(MUS_FANFA1);
        gTasks[taskId].func = sub_81B6F98;
    }
}

static void sub_81B6F98(u8 taskId)
{
    if (IsFanfareTaskInactive() && ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON)))
    {
        if (gUnknown_0203CEC8.unk10 == 1)
            sub_81B77AC(taskId);
        else
        {
            if (gUnknown_0203CEC8.unk10 == 2)
                gSpecialVar_Result = TRUE;
            sub_81B12C0(taskId);
        }
    }
}

static void sub_81B6FF4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B7028;
    }
}

static void sub_81B7028(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        sub_81B1B5C(gText_WhichMoveToForget, 1);
        gTasks[taskId].func = sub_81B7088;
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        sub_81B7230(taskId);
        break;
    }
}

static void sub_81B7088(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        gUnknown_0203CEC4->exitCallback = sub_81B70B8;
        sub_81B12C0(taskId);
    }
}

static void sub_81B70B8(void)
{
    ShowSelectMovePokemonSummaryScreen(gPlayerParty, gUnknown_0203CEC8.unk9, gPlayerPartyCount - 1, sub_81B70F0, gUnknown_0203CEC8.unkE);
}

static void sub_81B70F0(void)
{
    InitPartyMenu(0, 0, 0, 1, 0x7F, sub_81B711C, gUnknown_0203CEC8.exitCallback);
}

static void sub_81B711C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sub_81C1B94() != 4)
            sub_81B7154(taskId);
        else
            sub_81B7230(taskId);
    }
}

static void sub_81B7154(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 move = GetMonData(mon, MON_DATA_MOVE1 + sub_81C1B94());

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);
    sub_81B6D74(gText_12PoofForgotMove);
    gTasks[taskId].func = sub_81B71D4;
}

static void sub_81B71D4(u8 taskId)
{
    struct Pokemon *mon;
    u16 move;

    if (sub_81B1BD4() != TRUE)
    {
        mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
        RemoveMonPPBonus(mon, sub_81C1B94());
        move = gUnknown_0203CEC8.unkE;
        SetMonMoveSlot(mon, move, sub_81C1B94());
        sub_81B6EB4(taskId);
    }
}

static void sub_81B7230(u8 taskId)
{
    StringCopy(gStringVar2, gMoveNames[gUnknown_0203CEC8.unkE]);
    StringExpandPlaceholders(gStringVar4, gText_StopLearningMove2);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B7294;
}

static void sub_81B7294(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B72C8;
    }
}

static void sub_81B72C8(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, gMoveNames[gUnknown_0203CEC8.unkE]);
        StringExpandPlaceholders(gStringVar4, gText_MoveNotLearned);
        sub_81B1B5C(gStringVar4, 1);
        if (gUnknown_0203CEC8.unk10 == 1)
        {
            gTasks[taskId].func = sub_81B73E4;
        }
        else
        {
            if (gUnknown_0203CEC8.unk10 == 2)
                gSpecialVar_Result = FALSE;
            gTasks[taskId].func = sub_81B6794;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, gMoveNames[gUnknown_0203CEC8.unkE]);
        sub_81B6D74(gText_PkmnNeedsToReplaceMove);
        gTasks[taskId].func = sub_81B6FF4;
        break;
    }
}

static void sub_81B73E4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
        sub_81B77AC(taskId);
}

void dp05_rare_candy(u8 taskId, TaskFunc task)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    struct Struct203CEC4 *ptr = gUnknown_0203CEC4;
    s16 *arrayPtr = ptr->data;
    u16 *itemPtr = &gSpecialVar_ItemId;
    bool8 cannotUseEffect;

    if (GetMonData(mon, MON_DATA_LEVEL) != MAX_LEVEL)
    {
        sub_81B79A0(mon, arrayPtr);
        cannotUseEffect = ExecuteTableBasedItemEffect__(gUnknown_0203CEC8.unk9, *itemPtr, 0);
        sub_81B79A0(mon, &ptr->data[6]);
    }
    else
    {
        cannotUseEffect = TRUE;
    }
    PlaySE(SE_SELECT);
    if (cannotUseEffect)
    {
        gUnknown_0203CEE8 = 0;
        sub_81B1B5C(gText_WontHaveEffect, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = task;
    }
    else
    {
        gUnknown_0203CEE8 = 1;
        PlayFanfareByFanfareNum(0);
        sub_81B754C(gUnknown_0203CEC8.unk9, mon);
        RemoveBagItem(gSpecialVar_ItemId, 1);
        GetMonNickname(mon, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, GetMonData(mon, MON_DATA_LEVEL), 0, 3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnElevatedToLvVar2);
        sub_81B1B5C(gStringVar4, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = sub_81B75D4;
    }
}

static void sub_81B754C(u8 slot, struct Pokemon *mon)
{
    party_menu_get_status_condition_and_update_object(mon, &gUnknown_0203CEDC[slot]);
    if (gSprites[gUnknown_0203CEDC[slot].unkC].invisible)
        DisplayPartyPokemonLevelCheck(mon, &gUnknown_0203CEDC[slot], 1);
    DisplayPartyPokemonHPCheck(mon, &gUnknown_0203CEDC[slot], 1);
    DisplayPartyPokemonMaxHPCheck(mon, &gUnknown_0203CEDC[slot], 1);
    DisplayPartyPokemonHPBarCheck(mon, &gUnknown_0203CEDC[slot]);
    sub_81B5B38(gUnknown_0203CEDC[slot].unk9, mon);
    sub_81B0FCC(slot, 1);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void sub_81B75D4(u8 taskId)
{
    if (WaitFanfare(FALSE) && sub_81B1BD4() != TRUE && ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON)))
    {
        PlaySE(SE_SELECT);
        sub_81B767C(taskId);
        gTasks[taskId].func = sub_81B7634;
    }
}

static void sub_81B7634(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sub_81B76C8(taskId);
        gTasks[taskId].func = sub_81B7704;
    }
}

static void sub_81B767C(u8 taskId)
{
    s16 *arrayPtr = gUnknown_0203CEC4->data;

    arrayPtr[12] = sub_81B3364();
    DrawLevelUpWindowPg1(arrayPtr[12], arrayPtr, &arrayPtr[6], 1, 2, 3);
    CopyWindowToVram(arrayPtr[12], 2);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_81B76C8(u8 taskId)
{
    s16 *arrayPtr = gUnknown_0203CEC4->data;

    DrawLevelUpWindowPg2(arrayPtr[12], &arrayPtr[6], 1, 2, 3);
    CopyWindowToVram(arrayPtr[12], 2);
    schedule_bg_copy_tilemap_to_vram(2);
}

static void sub_81B7704(u8 taskId)
{
    u16 result;

    if (WaitFanfare(0) && ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON)))
    {
        sub_81B3394();
        result = MonTryLearningNewMove(&gPlayerParty[gUnknown_0203CEC8.unk9], 1);
        gUnknown_0203CEC8.unk10 = 1;
        switch (result)
        {
        case 0:
            sub_81B7810(taskId);
            break;
        case 0xFFFF:
            sub_81B787C(taskId);
            break;
        case 0xFFFE:
            gTasks[taskId].func = sub_81B77AC;
            break;
        default:
            sub_81B7910(taskId, result);
            break;
        }
    }
}

static void sub_81B77AC(u8 taskId)
{
    u16 result = MonTryLearningNewMove(&gPlayerParty[gUnknown_0203CEC8.unk9], 0);

    switch (result)
    {
    case 0:
        sub_81B7810(taskId);
        break;
    case 0xFFFF:
        sub_81B787C(taskId);
        break;
    case 0xFFFE:
        return;
    default:
        sub_81B7910(taskId, result);
        break;
    }
}

static void sub_81B7810(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 targetSpecies = GetEvolutionTargetSpecies(mon, 0, 0);

    if (targetSpecies != SPECIES_NONE)
    {
        FreePartyPointers();
        gCB2_AfterEvolution = gUnknown_0203CEC8.exitCallback;
        BeginEvolutionScene(mon, targetSpecies, 1, gUnknown_0203CEC8.unk9);
        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].func = sub_81B6794;
    }
}

static void sub_81B787C(u8 taskId)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
    StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
    StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gUnknown_0203CEC8.unkE = gMoveToLearn;
    gTasks[taskId].func = sub_81B6FF4;
}

static void sub_81B7910(u8 taskId, u16 move)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);
    StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gUnknown_0203CEC8.unkE = move;
    gTasks[taskId].func = sub_81B6F60;
}

static void sub_81B79A0(struct Pokemon *mon, s16 *data)
{
    data[0] = GetMonData(mon, MON_DATA_MAX_HP);
    data[1] = GetMonData(mon, MON_DATA_ATK);
    data[2] = GetMonData(mon, MON_DATA_DEF);
    data[4] = GetMonData(mon, MON_DATA_SPATK);
    data[5] = GetMonData(mon, MON_DATA_SPDEF);
    data[3] = GetMonData(mon, MON_DATA_SPEED);
}

void sub_81B79E8(u8 taskId, TaskFunc task)
{
    gUnknown_0203CEC4->data[0] = 0;
    gUnknown_0203CEC4->data[1] = 0;
    gUnknown_0203CEC4->data[2] = gUnknown_0203CEC8.unk9;
    sub_81B7A28(taskId);
}

static void sub_81B7A28(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 hp;

    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
    {
        gTasks[taskId].func = task_sacred_ash_party_loop;
        return;
    }

    hp = GetMonData(mon, MON_DATA_HP);
    if (ExecuteTableBasedItemEffect__(gUnknown_0203CEC8.unk9, gSpecialVar_ItemId, 0))
    {
        gTasks[taskId].func = task_sacred_ash_party_loop;
        return;
    }

    PlaySE(SE_KAIFUKU);
    party_menu_get_status_condition_and_update_object(mon, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9]);
    if (gSprites[gUnknown_0203CEDC[gUnknown_0203CEC8.unk9].unkC].invisible)
        DisplayPartyPokemonLevelCheck(mon, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
    sub_81B0FCC(gUnknown_0203CEC4->data[2], 0);
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
    sub_81B1F18(taskId, gUnknown_0203CEC8.unk9, 1, GetMonData(mon, MON_DATA_HP) - hp, sub_81B7C10);
    sub_81B1FA8(taskId, 0, hp);
    gUnknown_0203CEC4->data[0] = 1;
    gUnknown_0203CEC4->data[1] = 1;
}

static void task_sacred_ash_party_loop(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        if (gUnknown_0203CEC4->data[0] == 1)
        {
            gUnknown_0203CEC4->data[0] = 0;
            gUnknown_0203CEC4->data[2] = gUnknown_0203CEC8.unk9;
        }
        if (++(gUnknown_0203CEC8.unk9) == PARTY_SIZE)
        {
            if (gUnknown_0203CEC4->data[1] == 0)
            {
                gUnknown_0203CEE8 = 0;
                sub_81B1B5C(gText_WontHaveEffect, 1);
                schedule_bg_copy_tilemap_to_vram(2);
            }
            else
            {
                gUnknown_0203CEE8 = 1;
                RemoveBagItem(gSpecialVar_ItemId, 1);
            }
            gTasks[taskId].func = sub_81B6794;
            gUnknown_0203CEC8.unk9 = 0;
        }
        else
        {
            sub_81B7A28(taskId);
        }
    }
}

static void sub_81B7C10(u8 taskId)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
    sub_81B1B5C(gStringVar4, 0);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = task_sacred_ash_party_loop;
}

void sub_81B7C74(u8 taskId, TaskFunc task)
{
    PlaySE(SE_SELECT);
    gCB2_AfterEvolution = gUnknown_0203CEC8.exitCallback;
    if (ExecuteTableBasedItemEffect__(gUnknown_0203CEC8.unk9, gSpecialVar_ItemId, 0))
    {
        gUnknown_0203CEE8 = 0;
        sub_81B1B5C(gText_WontHaveEffect, 1);
        schedule_bg_copy_tilemap_to_vram(2);
        gTasks[taskId].func = task;
    }
    else
    {
        RemoveBagItem(gSpecialVar_ItemId, 1);
        FreePartyPointers();
    }
}

u8 GetItemEffectType(u16 item)
{
    const u8 *itemEffect;
    u32 statusCure;

    if (!ITEM_HAS_EFFECT(item))
        return ITEM_EFFECT_NONE;

    // Read the item's effect properties.
    if (item == ITEM_ENIGMA_BERRY)
        itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    else
        itemEffect = gItemEffectTable[item - ITEM_POTION];

    if ((itemEffect[0] & (ITEM0_HIGH_CRIT | ITEM0_X_ATTACK)) || itemEffect[1] || itemEffect[2] || (itemEffect[3] & ITEM3_MIST))
        return ITEM_EFFECT_X_ITEM;
    else if (itemEffect[0] & ITEM0_SACRED_ASH)
        return ITEM_EFFECT_SACRED_ASH;
    else if (itemEffect[3] & ITEM3_LEVEL_UP)
        return ITEM_EFFECT_RAISE_LEVEL;

    statusCure = itemEffect[3] & ITEM3_STATUS_ALL;
    if (statusCure || (itemEffect[0] >> 7))
    {
        if (statusCure == ITEM3_SLEEP)
            return ITEM_EFFECT_CURE_SLEEP;
        else if (statusCure == ITEM3_POISON)
            return ITEM_EFFECT_CURE_POISON;
        else if (statusCure == ITEM3_BURN)
            return ITEM_EFFECT_CURE_BURN;
        else if (statusCure == ITEM3_FREEZE)
            return ITEM_EFFECT_CURE_FREEZE;
        else if (statusCure == ITEM3_PARALYSIS)
            return ITEM_EFFECT_CURE_PARALYSIS;
        else if (statusCure == ITEM3_CONFUSION)
            return ITEM_EFFECT_CURE_CONFUSION;
        else if (itemEffect[0] >> 7 && !statusCure)
            return ITEM_EFFECT_CURE_INFATUATION;
        else
            return ITEM_EFFECT_CURE_ALL_STATUS;
    }

    if (itemEffect[4] & (ITEM4_REVIVE | ITEM4_HEAL_HP))
        return ITEM_EFFECT_HEAL_HP;
    else if (itemEffect[4] & ITEM4_EV_ATK)
        return ITEM_EFFECT_ATK_EV;
    else if (itemEffect[4] & ITEM4_EV_HP)
        return ITEM_EFFECT_HP_EV;
    else if (itemEffect[5] & ITEM5_EV_SPATK)
        return ITEM_EFFECT_SPATK_EV;
    else if (itemEffect[5] & ITEM5_EV_SPDEF)
        return ITEM_EFFECT_SPDEF_EV;
    else if (itemEffect[5] & ITEM5_EV_SPEED)
        return ITEM_EFFECT_SPEED_EV;
    else if (itemEffect[5] & ITEM5_EV_DEF)
        return ITEM_EFFECT_DEF_EV;
    else if (itemEffect[4] & ITEM4_EVO_STONE)
        return ITEM_EFFECT_EVO_STONE;
    else if (itemEffect[4] & ITEM4_PP_UP)
        return ITEM_EFFECT_PP_UP;
    else if (itemEffect[5] & ITEM5_PP_MAX)
        return ITEM_EFFECT_PP_MAX;
    else if (itemEffect[4] & (ITEM4_HEAL_PP_ALL | ITEM4_HEAL_PP_ONE))
        return ITEM_EFFECT_HEAL_PP;
    else
        return ITEM_EFFECT_NONE;
}

static void sub_81B7E4C(u8 taskId)
{
    struct Pokemon *mon;
    s16 *move;

    if (!gPaletteFade.active)
    {
        mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
        move = &gUnknown_0203CEC8.unkE;
        GetMonNickname(mon, gStringVar1);
        gUnknown_0203CEC8.unkE = GetTutorMove(gSpecialVar_0x8005);
        StringCopy(gStringVar2, gMoveNames[gUnknown_0203CEC8.unkE]);
        move[1] = 2;
        switch (CanMonLearnTMTutor(mon, 0, gSpecialVar_0x8005))
        {
        case CANNOT_LEARN_MOVE:
            sub_81B6D98(taskId, gText_PkmnCantLearnMove);
            return;
        case ALREADY_KNOWS_MOVE:
            sub_81B6D98(taskId, gText_PkmnAlreadyKnows);
            return;
        default:
            if (GiveMoveToMon(mon, gUnknown_0203CEC8.unkE) != 0xFFFF)
            {
                sub_81B6EB4(taskId);
                return;
            }
            break;
        }
        sub_81B6D74(gText_PkmnNeedsToReplaceMove);
        gTasks[taskId].func = sub_81B6FF4;
    }
}

void CB2_PartyMenuFromStartMenu(void)
{
    InitPartyMenu(0, 0, 0, 0, 0, sub_81B1370, CB2_ReturnToFieldWithOpenMenu);
}

void sub_81B7F60(void)
{
    MainCallback callback = (InBattlePyramid() == FALSE) ? c2_815ABFC : sub_81C4F84;
    InitPartyMenu(0, 0, 5, 0, 6, sub_81B1370, callback);
    gUnknown_0203CEC8.unkC = gSpecialVar_ItemId;
}

static void sub_81B7FAC(u8 taskId)
{
    gUnknown_0203CEFC = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_HELD_ITEM);
    if (gUnknown_0203CEFC == ITEM_NONE)
    {
        sub_81B8044(taskId);
    }
    else if (ItemIsMail(gUnknown_0203CEFC))
    {
        sub_81B83B8(taskId);
    }
    else
    {
        sub_81B1D1C(&gPlayerParty[gUnknown_0203CEC8.unk9], gUnknown_0203CEFC, 1);
        gTasks[taskId].func = sub_81B82A0;
    }
}

static void sub_81B8044(u8 taskId)
{
    if (ItemIsMail(gUnknown_0203CEC8.unkC))
    {
        sub_81B83F0(gUnknown_0203CEC8.unkC);
        gUnknown_0203CEC4->exitCallback = sub_81B814C;
        sub_81B12C0(taskId);
    }
    else
    {
        sub_81B8088(taskId);
    }
}

static void sub_81B8088(u8 taskId)
{
    u16 item;

    if (!gPaletteFade.active)
    {
        item = gUnknown_0203CEC8.unkC;
        sub_81B1C84(&gPlayerParty[gUnknown_0203CEC8.unk9], item, 0, 1);
        sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], item);
        sub_81B83F0(item);
        gTasks[taskId].func = sub_81B8104;
    }
}

static void sub_81B8104(u8 taskId)
{
    s8 slot = gUnknown_0203CEC8.unk9;

    if (sub_81B1BD4() != TRUE)
    {
        sub_81B5C94(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
        sub_81B12C0(taskId);
    }
}

static void sub_81B814C(void)
{
    u8 mail;

    sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], gUnknown_0203CEC8.unkC);
    mail = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_MAIL);
    DoEasyChatScreen(
    	EASY_CHAT_TYPE_MAIL,
    	gSaveBlock1Ptr->mail[mail].words,
    	sub_81B81A8,
    	EASY_CHAT_PERSON_DISPLAY_NONE);
}

static void sub_81B81A8(void)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (gSpecialVar_Result == FALSE)
    {
        TakeMailFromMon(mon);
        SetMonData(mon, MON_DATA_HELD_ITEM, &gUnknown_0203CEFC);
        RemoveBagItem(gUnknown_0203CEFC, 1);
        sub_81B841C(item);
        SetMainCallback2(gUnknown_0203CEC8.exitCallback);
    }
    else
    {
        InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 0x7F, sub_81B8230, gUnknown_0203CEC8.exitCallback);
    }
}

static void sub_81B8230(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203CEFC != ITEM_NONE)
            sub_81B1D68(gUnknown_0203CEC8.unkC, gUnknown_0203CEFC, 0);
        else
            sub_81B1C84(&gPlayerParty[gUnknown_0203CEC8.unk9], gUnknown_0203CEC8.unkC, 0, 1);
        gTasks[taskId].func = sub_81B8104;
    }
}

static void sub_81B82A0(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B82D4;
    }
}

static void sub_81B82D4(u8 taskId)
{
    u16 item;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        item = gUnknown_0203CEC8.unkC;
        sub_81B83F0(item);
        if (AddBagItem(gUnknown_0203CEFC, 1) == FALSE)
        {
            sub_81B841C(item);
            pokemon_item_not_removed(gUnknown_0203CEFC);
            sub_81B1B5C(gStringVar4, 0);
            gTasks[taskId].func = sub_81B8104;
        }
        else if (ItemIsMail(item))
        {
            gUnknown_0203CEC4->exitCallback = sub_81B814C;
            sub_81B12C0(taskId);
        }
        else
        {
            sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], item);
            sub_81B1D68(item, gUnknown_0203CEFC, 1);
            gTasks[taskId].func = sub_81B8104;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
    case 1:
        gTasks[taskId].func = sub_81B8104;
        break;
    }
}

static void sub_81B83B8(u8 taskId)
{
    sub_81B1B5C(gText_RemoveMailBeforeItem, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B8104;
}

static void sub_81B83F0(u16 item)
{
    if (gUnknown_0203CEC8.unkB == 6)
        RemovePCItem(item, 1);
    else
        RemoveBagItem(item, 1);
}

static bool8 sub_81B841C(u16 item)
{
    if (gUnknown_0203CEC8.unkB == 5)
        return AddBagItem(item, 1);
    else
        return AddPCItem(item, 1);
}

void sub_81B8448(void)
{
    InitPartyMenu(0, 0, 7, 0, 6, sub_81B1370, Mailbox_ReturnToMailListAfterDeposit);
}

static void sub_81B8474(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    struct MailStruct *mail;

    gUnknown_0203CEE8 = 0;
    mail = &gSaveBlock1Ptr->mail[playerPCItemPageInfo.itemsAbove + 6 + playerPCItemPageInfo.cursorPos];
    if (GetMonData(mon, MON_DATA_HELD_ITEM) != ITEM_NONE)
    {
        sub_81B1B5C(gText_PkmnHoldingItemCantHoldMail, 1);
    }
    else
    {
        GiveMailToMon2(mon, mail);
        ClearMailStruct(mail);
        sub_81B1B5C(gText_MailTransferredFromMailbox, 1);
    }
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B8104;
}

void InitChooseHalfPartyForBattle(u8 unused)
{
    sub_81B8558();
    InitPartyMenu(4, 0, 0, 0, 0, sub_81B1370, gMain.savedCallback);
    gUnknown_0203CEC8.unk4 = sub_81B879C;
}

void sub_81B8558(void)
{
    memset(gSelectedOrderFromParty, 0, sizeof(gSelectedOrderFromParty));
}

static u8 sub_81B856C(s8 slot)
{
    if (GetBattleEntryEligibility(&gPlayerParty[slot]) == FALSE)
        return 2;
    if (sub_81B8770(slot + 1) == TRUE)
        return 1;
    return 0;
}

static bool8 GetBattleEntryEligibility(struct Pokemon *mon)
{
    u16 i = 0;
    u16 species;

    if (GetMonData(mon, MON_DATA_IS_EGG)
        || GetMonData(mon, MON_DATA_LEVEL) > sub_81B8888()
        || (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY)
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY)
            && GetMonData(mon, MON_DATA_HELD_ITEM) != ITEM_NONE))
    {
        return FALSE;
    }

    switch (VarGet(VAR_FRONTIER_FACILITY)) // oddly the specific cases are beyond 6, turns out case 9 is apparently related to link battles
    {
    case 9:
        if (GetMonData(mon, MON_DATA_HP) != 0)
            return TRUE;
        return FALSE;
    case 8:
        return TRUE;
    default:
        species = GetMonData(mon, MON_DATA_SPECIES);
        for (; gFrontierBannedSpecies[i] != 0xFFFF; i++)
        {
            if (gFrontierBannedSpecies[i] == species)
                return FALSE;
        }
        return TRUE;
    }
}

static u8 sub_81B865C(void)
{
    u8 unk2;
    u8 i, j;
    u8 facility;
    struct Pokemon *party = gPlayerParty;
    u8 unk = sub_81B885C();
    u8 *order = gSelectedOrderFromParty;

    if (order[unk - 1] == 0)
    {
        if (unk == 1)
            return 14;
        ConvertIntToDecimalStringN(gStringVar1, unk, 0, 1);
        return 17;
    }

    facility = VarGet(VAR_FRONTIER_FACILITY);
    if (facility == 8 || facility == 9)
        return 0xFF;

    unk2 = sub_81B8830();
    for (i = 0; i < unk2 - 1; i++)
    {
        u16 species = GetMonData(&party[order[i] - 1], MON_DATA_SPECIES);
        u16 item = GetMonData(&party[order[i] - 1], MON_DATA_HELD_ITEM);
        for (j = i + 1; j < unk2; j++)
        {
            if (species == GetMonData(&party[order[j] - 1], MON_DATA_SPECIES))
                return 18;
            if (item != ITEM_NONE && item == GetMonData(&party[order[j] - 1], MON_DATA_HELD_ITEM))
                return 19;
        }
    }

    return 0xFF;
}

static bool8 sub_81B8770(u8 slot)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (gSelectedOrderFromParty[i] == slot)
            return TRUE;
    }
    return FALSE;
}

static void sub_81B879C(u8 taskId)
{
    u8 msgId = sub_81B865C();

    if (msgId != 0xFF)
    {
        PlaySE(SE_HAZURE);
        display_pokemon_menu_message(msgId);
        gTasks[taskId].func = sub_81B87E8;
    }
    else
    {
        PlaySE(SE_SELECT);
        sub_81B12C0(taskId);
    }
}

static void sub_81B87E8(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        display_pokemon_menu_message(0);
        gTasks[taskId].func = sub_81B1370;
    }
}

static u8 sub_81B8830(void)
{
    switch (VarGet(VAR_FRONTIER_FACILITY))
    {
    case 9:
        return 3;
    case 8:
        return 2;
    default:
        return gSpecialVar_0x8005;
    }
}

static u8 sub_81B885C(void)
{
    switch (VarGet(VAR_FRONTIER_FACILITY))
    {
    case 9:
        return 1;
    case 8:
        return 2;
    default:
        return gSpecialVar_0x8005;
    }
}

static u8 sub_81B8888(void)
{
    switch (VarGet(VAR_FRONTIER_FACILITY))
    {
    case 9:
        return 100;
    case 8:
        return 30;
    default:
        if (gSpecialVar_0x8004 == 0)
            return 50;
        return 100;
    }
}

static const u8* sub_81B88BC(void)
{
    u8 facilityNum = VarGet(VAR_FRONTIER_FACILITY);

    if (!(facilityNum != 8 && facilityNum != 9))
        return gText_CancelBattle;
    else if (facilityNum == FRONTIER_FACILITY_DOME && gSpecialVar_0x8005 == 2)
        return gText_ReturnToWaitingRoom;
    else
        return gText_CancelChallenge;
}

void sub_81B8904(u8 initArg, MainCallback callback)
{
    InitPartyMenu(initArg, 0, 0, 0, 0, sub_81B1370, callback);
}

void sub_81B892C(void)
{
    InitPartyMenu(0, 0, 12, 0, 4, sub_81B1370, CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void sub_81B8958(void)
{
    InitPartyMenu(11, 0, 13, 0, 1, sub_81B1370, CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

static u8 sub_81B8984(void)
{
    if (IsDoubleBattle() == FALSE)
        return 0;
    if (IsMultiBattle() == TRUE)
        return 2;
    return 1;
}

void OpenPartyMenuInBattle(u8 arg)
{
    InitPartyMenu(1, sub_81B8984(), arg, 0, 0, sub_81B1370, SetCB2ToReshowScreenAfterMenu);
    nullsub_35();
    pokemon_change_order();
}

void sub_81B89F0(void)
{
    InitPartyMenu(1, sub_81B8984(), 3, 0, 5, sub_81B1370, c2_815ABFC);
    nullsub_35();
    pokemon_change_order();
}

static u8 sub_81B8A2C(struct Pokemon *mon)
{
    if (GetMonData(&gPlayerParty[1], MON_DATA_SPECIES) != SPECIES_NONE && GetMonData(mon, MON_DATA_IS_EGG) == FALSE)
    {
        if (gUnknown_0203CEC8.unkB == 1)
            return 3;
        if (!(gBattleTypeFlags & BATTLE_TYPE_ARENA))
            return 2;
    }
    return 7;
}

static bool8 sub_81B8A7C(void)
{
    u8 slot = GetCursorSelectionMonId();
    u8 newSlot;
    u8 i;

    if (IsMultiBattle() == TRUE && (slot == 1 || slot == 4 || slot == 5))
    {
        StringCopy(gStringVar1, GetTrainerPartnerName());
        StringExpandPlaceholders(gStringVar4, gText_CantSwitchWithAlly);
        return FALSE;
    }
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HP) == 0)
    {
        GetMonNickname(&gPlayerParty[slot], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_PkmnHasNoEnergy);
        return FALSE;
    }
    for (i = 0; i < gBattlersCount; i++)
    {
        if (GetBattlerSide(i) == B_SIDE_PLAYER && sub_81B8F38(slot) == gBattlerPartyIndexes[i])
        {
            GetMonNickname(&gPlayerParty[slot], gStringVar1);
            StringExpandPlaceholders(gStringVar4, gText_PkmnAlreadyInBattle);
            return FALSE;
        }
    }
    if (GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG))
    {
        StringExpandPlaceholders(gStringVar4, gText_EggCantBattle);
        return FALSE;
    }
    if (sub_81B8F38(slot) == gBattleStruct->field_8B)
    {
        GetMonNickname(&gPlayerParty[slot], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_PkmnAlreadySelected);
        return FALSE;
    }
    if (gUnknown_0203CEC8.unkB == 4)
    {
        SetMonPreventsSwitchingString();
        return FALSE;
    }
    if (gUnknown_0203CEC8.unkB == 2)
    {
        u8 currBattler = gBattlerInMenuId;
        GetMonNickname(&gPlayerParty[pokemon_order_func(gBattlerPartyIndexes[currBattler])], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_PkmnCantSwitchOut);
        return FALSE;
    }
    gUnknown_0203CEE9 = sub_81B8F38(slot);
    gUnknown_0203CEE8 = 1;
    newSlot = pokemon_order_func(gBattlerPartyIndexes[gBattlerInMenuId]);
    sub_81B8FB0(newSlot, slot);
    sub_81B1288(&gPlayerParty[newSlot], &gPlayerParty[slot]);
    return TRUE;
}

void sub_81B8C68(void)
{
    sub_81B8C88(gUnknown_0203CF00, sub_806D7EC());
}

static void sub_81B8C88(u8 *ptr, bool8 multiplayerFlag)
{
    u8 partyIndexes[6];
    int i, j;

    if (IsMultiBattle() == TRUE)
    {
        if (multiplayerFlag)
        {
            ptr[0] = 0 | (3 << 4);
            ptr[1] = 5 | (4 << 4);
            ptr[2] = 2 | (1 << 4);
        }
        else
        {
            ptr[0] = 3 | (0 << 4);
            ptr[1] = 2 | (1 << 4);
            ptr[2] = 5 | (4 << 4);
        }
        return;
    }
    else if (IsDoubleBattle() == FALSE)
    {
        j = 1;
        partyIndexes[0] = gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (i != partyIndexes[0])
            {
                partyIndexes[j] = i;
                j++;
            }
        }
    }
    else
    {
        j = 2;
        partyIndexes[0] = gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)];
        partyIndexes[1] = gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (i != partyIndexes[0] && i != partyIndexes[1])
            {
                partyIndexes[j] = i;
                j++;
            }
        }
    }
    for (i = 0; i < 3; i++)
        ptr[i] = (partyIndexes[0 + (i * 2)] << 4) | partyIndexes[1 + (i * 2)];
}

void sub_81B8D64(u8 battlerId, u8 multiplayerFlag)
{
    sub_81B8D88(gBattleStruct->field_60[battlerId], multiplayerFlag, battlerId);
}

static void sub_81B8D88(u8 *ptr, bool8 multiplayerFlag, u8 battlerId)
{
    u8 partyIndexes[6];
    int i, j;
    u8 leftBattler;
    u8 rightBattler;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
    {
        leftBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        rightBattler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
    }
    else
    {
        leftBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        rightBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
    }

    if (IsMultiBattle() == TRUE)
    {
        if (multiplayerFlag)
        {
            ptr[0] = 0 | (3 << 4);
            ptr[1] = 5 | (4 << 4);
            ptr[2] = 2 | (1 << 4);
        }
        else
        {
            ptr[0] = 3 | (0 << 4);
            ptr[1] = 2 | (1 << 4);
            ptr[2] = 5 | (4 << 4);
        }
        return;
    }
    else if (IsDoubleBattle() == FALSE)
    {
        j = 1;
        partyIndexes[0] = gBattlerPartyIndexes[leftBattler];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (i != partyIndexes[0])
            {
                partyIndexes[j] = i;
                j++;
            }
        }
    }
    else
    {
        j = 2;
        partyIndexes[0] = gBattlerPartyIndexes[leftBattler];
        partyIndexes[1] = gBattlerPartyIndexes[rightBattler];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (i != partyIndexes[0] && i != partyIndexes[1])
            {
                partyIndexes[j] = i;
                j++;
            }
        }
    }

    for (i = 0; i < 3; i++)
        ptr[i] = (partyIndexes[0 + (i * 2)] << 4) | partyIndexes[1 + (i * 2)];
}

void sub_81B8E80(u8 battlerId, u8 unk, u8 arrayIndex)
{
    u8 possiblePartyIndexes[6];
    u8 unk2 = 0;
    int i, j;
    u8 *battleStructRelated;
    u8 possiblePartyIndexBuffer;

    if (IsMultiBattle())
    {
        battleStructRelated = gBattleStruct->field_60[battlerId];
        for (i = j = 0; i < 3; j++, i++)
        {
            possiblePartyIndexes[j] = battleStructRelated[i] >> 4;
            j++;
            possiblePartyIndexes[j] = battleStructRelated[i] & 0xF;
        }
        possiblePartyIndexBuffer = possiblePartyIndexes[arrayIndex];
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (possiblePartyIndexes[i] == unk)
            {
                unk2 = possiblePartyIndexes[i];
                possiblePartyIndexes[i] = possiblePartyIndexBuffer;
                break;
            }
        }
        if (i != PARTY_SIZE)
        {
            possiblePartyIndexes[arrayIndex] = unk2;
            battleStructRelated[0] = (possiblePartyIndexes[0] << 4) | possiblePartyIndexes[1];
            battleStructRelated[1] = (possiblePartyIndexes[2] << 4) | possiblePartyIndexes[3];
            battleStructRelated[2] = (possiblePartyIndexes[4] << 4) | possiblePartyIndexes[5];
        }
    }
}

static u8 sub_81B8F38(u8 slot)
{
    u8 modResult = slot & 1;
    u8 retVal;

    slot /= 2;
    if (modResult != 0)
        retVal = gUnknown_0203CF00[slot] & 0xF;
    else
        retVal = gUnknown_0203CF00[slot] >> 4;
    return retVal;
}

static void sub_81B8F6C(u8 slot, u8 setVal)
{
    bool32 modResult = slot & 1;

    slot /= 2;
    if (modResult != 0)
        gUnknown_0203CF00[slot] = (gUnknown_0203CF00[slot] & 0xF0) | setVal;
    else
        gUnknown_0203CF00[slot] = (gUnknown_0203CF00[slot] & 0xF) | (setVal << 4);
}

void sub_81B8FB0(u8 slot, u8 slot2)
{
    u8 valBuffer = sub_81B8F38(slot);
    sub_81B8F6C(slot, sub_81B8F38(slot2));
    sub_81B8F6C(slot2, valBuffer);
}

u8 pokemon_order_func(u8 slot)
{
    u8 i, j;

    for (j = i = 0; i < 3; j++, i++)
    {
        if ((gUnknown_0203CF00[i] >> 4) != slot)
        {
            j++;
            if ((gUnknown_0203CF00[i] & 0xF) == slot)
                return j;
        }
        else
        {
            return j;
        }
    }
    return 0;
}

static void pokemon_change_order(void)
{
    struct Pokemon *partyBuffer = Alloc(sizeof(gPlayerParty));
    u8 i;

    memcpy(partyBuffer, gPlayerParty, sizeof(gPlayerParty));
    for (i = 0; i < PARTY_SIZE; i++)
        memcpy(&gPlayerParty[pokemon_order_func(i)], &partyBuffer[i], sizeof(struct Pokemon));
    Free(partyBuffer);
}

static void sub_81B9080(void)
{
    struct Pokemon *partyBuffer = Alloc(sizeof(gPlayerParty));
    u8 i;

    memcpy(partyBuffer, gPlayerParty, sizeof(gPlayerParty));
    for (i = 0; i < PARTY_SIZE; i++)
        memcpy(&gPlayerParty[sub_81B8F38(i)], &partyBuffer[i], sizeof(struct Pokemon));
    Free(partyBuffer);
}

static void sub_81B90D0(void)
{
    u8 i;
    struct Pokemon *mon;
    u8 leadVal;

    for (i = 1; i < PARTY_SIZE; i++)
    {
        mon = &gPlayerParty[sub_81B8F38(i)];
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE && GetMonData(mon, MON_DATA_HP) != 0)
        {
            leadVal = sub_81B8F38(0);
            sub_81B8FB0(0, i);
            sub_81B1288(&gPlayerParty[leadVal], mon);
            break;
        }
    }
}

static void sub_81B9140(void)
{
    SetMainCallback2(SetCB2ToReshowScreenAfterMenu);
}

void sub_81B9150(void)
{
    InitPartyMenu(5, 3, 0, 0, 0x7F, sub_81B917C, gMain.savedCallback);
}

static void sub_81B917C(u8 taskId)
{
    gTasks[taskId].data[0] = 256;
    sub_81B9294(taskId);
    ChangeBgX(2, 0x10000, 0);
    gTasks[taskId].func = sub_81B91B4;
}

static void sub_81B91B4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 i;

    if (!gPaletteFade.active)
    {
        data[0] -= 8;
        sub_81B9294(taskId);
        if (data[0] == 0)
        {
            for (i = 3; i < PARTY_SIZE; i++)
            {
                if (gUnknown_02022FF8[i - 3].species != SPECIES_NONE)
                    AnimateSelectedPartyIcon(gUnknown_0203CEDC[i].unk9, 0);
            }
            PlaySE(SE_W231); // Harden SE?
            gTasks[taskId].func = sub_81B9240;
        }
    }
}

static void sub_81B9240(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (++data[0] == 0x100)
        sub_81B12C0(taskId);
}

static void sub_81B9270(u8 spriteId, s16 x)
{
    if (x >= 0)
        gSprites[spriteId].pos2.x = x;
}

static void sub_81B9294(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 i;

    for (i = 3; i < PARTY_SIZE; i++)
    {
        if (gUnknown_02022FF8[i - 3].species != SPECIES_NONE)
        {
            sub_81B9270(gUnknown_0203CEDC[i].unk9, data[0] - 8);
            sub_81B9270(gUnknown_0203CEDC[i].unkA, data[0] - 8);
            sub_81B9270(gUnknown_0203CEDC[i].unkB, data[0] - 8);
            sub_81B9270(gUnknown_0203CEDC[i].unkC, data[0] - 8);
        }
    }
    ChangeBgX(2, 0x800, 1);
}

void sub_81B9328(void)
{
    InitPartyMenu(6, 0, 0, 0, 15, sub_81B1370, sub_81B9390);
}

static void sub_81B9354(u8 arg1)
{
    gFieldCallback2 = hm_add_c3_without_phase_2;
    InitPartyMenu(arg1, 0, 11, 0, 0, sub_81B1370, CB2_ReturnToField);
}

static void sub_81B9390(void)
{
    gSpecialVar_0x8004 = GetCursorSelectionMonId();
    if (gSpecialVar_0x8004 >= PARTY_SIZE)
        gSpecialVar_0x8004 = 0xFF;
    gFieldCallback2 = hm_add_c3_without_phase_2;
    SetMainCallback2(CB2_ReturnToField);
}

bool8 hm_add_c3_without_phase_2(void) // might not be bool
{
    pal_fill_black();
    CreateTask(task_hm_without_phase_2, 10);
    return TRUE;
}

static void task_hm_without_phase_2(u8 taskId)
{
    if (IsWeatherNotFadingIn())
    {
        DestroyTask(taskId);
        ScriptContext2_Disable();
        EnableBothScriptContexts();
    }
}

void sub_81B9404(void)
{
    ScriptContext2_Enable();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(sub_81B9424, 10);
}

static void sub_81B9424(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        InitPartyMenu(2, 0, 11, 0, 0, sub_81B1370, sub_81B9470);
        DestroyTask(taskId);
    }
}

static void sub_81B9470(void)
{
    gContestMonPartyIndex = GetCursorSelectionMonId();
    if (gContestMonPartyIndex >= PARTY_SIZE)
        gContestMonPartyIndex = 0xFF;
    gSpecialVar_0x8004 = gContestMonPartyIndex;
    gFieldCallback2 = hm_add_c3_without_phase_2;
    SetMainCallback2(CB2_ReturnToField);
}

void sub_81B94B0(void)
{
    ScriptContext2_Enable();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(sub_81B94D0, 10);
}

static void sub_81B94D0(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        InitPartyMenu(3, 0, 11, 0, 0, sub_81B1370, sub_81B9390);
        DestroyTask(taskId);
    }
}

void sub_81B951C(void)
{
    ScriptContext2_Enable();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(sub_81B953C, 10);
}

static void sub_81B953C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        InitPartyMenu(7, 0, 11, 0, 0, sub_81B1370, sub_81B9588);
        DestroyTask(taskId);
    }
}

static void sub_81B9588(void)
{
    gSpecialVar_0x8004 = GetCursorSelectionMonId();
    if (gSpecialVar_0x8004 >= PARTY_SIZE)
        gSpecialVar_0x8004 = 0xFF;
    else
        gSpecialVar_0x8005 = GetNumberOfRelearnableMoves(&gPlayerParty[gSpecialVar_0x8004]);
    gFieldCallback2 = hm_add_c3_without_phase_2;
    SetMainCallback2(CB2_ReturnToField);
}

void sub_81B95E0(void)
{
    u8 i;

    gSpecialVar_Result = FALSE;
    for (i = 0; i < 3; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) != ITEM_NONE)
        {
            gSpecialVar_Result = TRUE;
            break;
        }
    }
}

void sub_81B9620(void)
{
    ScriptContext2_Enable();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(sub_81B9640, 10);
}

static void sub_81B9640(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        InitPartyMenu(12, 0, 0, 0, 0, sub_81B1370, sub_81B9390);
        DestroyTask(taskId);
    }
}

void sub_81B968C(void)
{
    ShowPokemonSummaryScreen(PSS_MODE_SELECT_MOVE, gPlayerParty, gSpecialVar_0x8004, gPlayerPartyCount - 1, CB2_ReturnToField);
    gFieldCallback = FieldCallback_ReturnToEventScript2;
}

void sub_81B96D0(void)
{
    u8 i;

    gSpecialVar_Result = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_MOVE1 + i) != ITEM_NONE)
            gSpecialVar_Result++;
    }
}

void sub_81B9718(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 move = GetMonData(mon, MON_DATA_MOVE1 + gSpecialVar_0x8005);

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);
}

void sub_81B9770(void)
{
    u16 i;

    SetMonMoveSlot(&gPlayerParty[gSpecialVar_0x8004], MOVE_NONE, gSpecialVar_0x8005);
    RemoveMonPPBonus(&gPlayerParty[gSpecialVar_0x8004], gSpecialVar_0x8005);
    for (i = gSpecialVar_0x8005; i < MAX_MON_MOVES - 1; i++)
        sub_81B97DC(&gPlayerParty[gSpecialVar_0x8004], i, i + 1);
}

static void sub_81B97DC(struct Pokemon *mon, u8 slotTo, u8 slotFrom)
{
    u16 move1 = GetMonData(mon, MON_DATA_MOVE1 + slotTo);
    u16 move0 = GetMonData(mon, MON_DATA_MOVE1 + slotFrom);
    u8 pp1 = GetMonData(mon, MON_DATA_PP1 + slotTo);
    u8 pp0 = GetMonData(mon, MON_DATA_PP1 + slotFrom);
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    u8 ppBonusMask1 = gPPUpGetMask[slotTo];
    u8 ppBonusMove1 = (ppBonuses & ppBonusMask1) >> (slotTo * 2);
    u8 ppBonusMask2 = gPPUpGetMask[slotFrom];
    u8 ppBonusMove2 = (ppBonuses & ppBonusMask2) >> (slotFrom * 2);
    ppBonuses &= ~ppBonusMask1;
    ppBonuses &= ~ppBonusMask2;
    ppBonuses |= (ppBonusMove1 << (slotFrom * 2)) + (ppBonusMove2 << (slotTo * 2));
    SetMonData(mon, MON_DATA_MOVE1 + slotTo, &move0);
    SetMonData(mon, MON_DATA_MOVE1 + slotFrom, &move1);
    SetMonData(mon, MON_DATA_PP1 + slotTo, &pp0);
    SetMonData(mon, MON_DATA_PP1 + slotFrom, &pp1);
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

void sub_81B98DC(void)
{
    if (GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_IS_EGG))
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

void sub_81B9918(void)
{
    u16 move;
    u32 i, j;

    gSpecialVar_Result = FALSE;
    move = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_MOVE1 + gSpecialVar_0x8005);
    if (move == MOVE_SURF)
    {
        for (i = 0; i < CalculatePlayerPartyCount(); i++)
        {
            if (i != gSpecialVar_0x8004)
            {
                for (j = 0; j < MAX_MON_MOVES; j++)
                {
                    if (GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j) == MOVE_SURF)
                        return;
                }
            }
        }
        if (AnyStorageMonWithMove(move) != TRUE)
            gSpecialVar_Result = TRUE;
    }
}
