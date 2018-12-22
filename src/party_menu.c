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
#include "data2.h"
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
#include "fldeff_softboiled.h"
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
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "pokenav.h"
#include "region_map.h"
#include "reshow_battle_screen.h"
#include "rom_8011DC0.h"
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
#include "window.h"
#include "constants/battle.h"
#include "constants/battle_frontier.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"

enum {
    CAN_LEARN_MOVE,
    CANNOT_LEARN_MOVE,
    ALREADY_KNOWS_MOVE,
    CANNOT_LEARN_MOVE_IS_EGG
};

struct Unk_Rodata1 {
    void (*unk0)(u8, u8, u8, u8, u8, u8);
    u8 unk4[24];
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
};

struct Struct203CEC4 {
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

struct Struct203CEDC {
    struct Unk_Rodata1 *unk0;
    u8 *unk4;
    u8 windowId;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
};

struct Struct8615C08 {
    const u8 *textPtr;
    TaskFunc func;
};

struct Struct8615D9C {
    bool8 (*fieldMoveFunc)(void);
    u8 msgID;
};

EWRAM_DATA struct Struct203CEC4 *gUnknown_0203CEC4 = NULL;
EWRAM_DATA struct Struct203CEC8 gUnknown_0203CEC8 = {0};
EWRAM_DATA struct Struct203CEDC *gUnknown_0203CEDC = NULL;
EWRAM_DATA u8 *gUnknown_0203CEE0 = NULL;
EWRAM_DATA u8 *gUnknown_0203CEE4 = NULL;
EWRAM_DATA u8 gUnknown_0203CEE8 = 0;
EWRAM_DATA u8 gUnknown_0203CEE9 = 0;
EWRAM_DATA MainCallback gPostMenuFieldCallback = NULL;
EWRAM_DATA u16 *gUnknown_0203CEF0 = 0;
EWRAM_DATA u16 *gUnknown_0203CEF4 = 0;
EWRAM_DATA u8 gSelectedOrderFromParty[4] = {0};
EWRAM_DATA u16 gUnknown_0203CEFC = 0;
EWRAM_DATA u16 gUnknown_0203CEFE = 0; // unused
EWRAM_DATA u8 gUnknown_0203CF00[3] = {0};

// BELOW TO BE CONVERTED TO C

extern u32 gUnknown_08615048[]; // tutor compatibility table
extern struct BgTemplate gUnknown_086156B8[];
extern struct Unk_Rodata1 gUnknown_086156C4[2];
// extern struct Unk_Rodata1 gUnknown_086156E4;
extern u8 gUnknown_08615704[][6][8];
extern u8 gUnknown_086157C4[];
extern u8 gUnknown_086157E0[];
extern const u8 gUnknown_086157FC[][3];
extern struct WindowTemplate gUnknown_08615810[];
extern struct WindowTemplate gUnknown_08615850[];
extern struct WindowTemplate gUnknown_086158D0[];
extern struct WindowTemplate gUnknown_08615890[];
extern struct WindowTemplate gUnknown_08615908;
extern struct WindowTemplate gUnknown_08615910;
extern struct WindowTemplate gUnknown_08615918;
extern struct WindowTemplate gUnknown_08615920;
extern struct WindowTemplate gUnknown_08615928;
extern struct WindowTemplate gUnknown_08615930;
extern struct WindowTemplate gUnknown_08615938;
extern struct WindowTemplate gUnknown_08615940;
extern struct WindowTemplate gUnknown_08615948;
extern struct WindowTemplate gUnknown_08615950;
extern struct WindowTemplate gUnknown_08615958;
extern struct WindowTemplate gUnknown_08615960;
extern struct WindowTemplate gUnknown_08615968;
extern struct WindowTemplate gUnknown_08615970;
extern u8 gUnknown_08615988[];
extern u8 gUnknown_086159CE[];
extern u8 gUnknown_08615A14[];
extern u8 gUnknown_08615A4A[];
extern u8 gUnknown_08615A80[];
extern u8 gUnknown_08615AB6[];
extern u8 gUnknown_08615AB8[];
extern u8 gUnknown_08615ABA[];
extern u8 gUnknown_08615ABD[];
extern u8 gUnknown_08615AC0[];
extern u8 gUnknown_08615AC3[];
extern u8 gUnknown_08615AC5[];
extern u8 gUnknown_08615AC7[];
extern u8 gUnknown_08615AC9[];
extern u8 gUnknown_08615ACB[];
extern u8 gUnknown_08615ACD[];
extern u8 gUnknown_08615AD0[];
extern u8 gUnknown_08615AD3[];
extern u8 gUnknown_08615AD6[];
extern u8 gUnknown_08615AD9[];
extern u8 gUnknown_08615ADC[];
extern u8 gUnknown_08615ADF[];
extern u8 gUnknown_08615AE2[];
extern u8 gUnknown_08615AE5[];
extern u8 gUnknown_08615AE8[];
extern u8 gUnknown_08615AEB[];
extern u8 gUnknown_08615AEE[];
extern u8 gUnknown_08615AF1[];
extern const u8 *gUnknown_08615AF4[];
extern const u8 *gUnknown_08615B60[];
extern struct Struct8615C08 gUnknown_08615C08[];
extern u8 *gUnknown_08615D38[];
extern u8 gUnknown_08615D70[];
extern const u16 gUnknown_08615D7E[];
extern const struct Struct8615D9C gUnknown_08615D9C[];
extern const u8 *gUnknown_08615E0C[];
extern const struct SpriteSheet gUnknown_08615EB0;
extern const struct SpritePalette gUnknown_08615EB8;
extern struct SpriteTemplate gSpriteTemplate_8615EC0;
extern const struct CompressedSpriteSheet gUnknown_08615EF8;
extern const struct CompressedSpritePalette gUnknown_08615F00;
extern struct SpriteTemplate gSpriteTemplate_8615F08;
extern const struct CompressedSpriteSheet gUnknown_08615F70;
extern struct SpriteTemplate gSpriteTemplate_8615F78;
extern const struct CompressedSpriteSheet gUnknown_08615FF8;
extern const struct CompressedSpritePalette gUnknown_08616000;
extern struct SpriteTemplate gSpriteTemplate_8616008;
extern u8 gUnknown_08616020[];
extern u16 gUnknown_08616040[];

// ABOVE TO BE CONVERTED TO C

extern void (*gUnknown_03006328)(u8, TaskFunc);

void reset_brm(void);
void PartyMenuInitCallback(void);
bool8 PartyMenuSetup(void);
void sub_81B209C(void);
void PartyMenuExit(void);
bool8 AllocPartyMenuBg(void);
bool8 AllocPartyMiscGfx(void);
void sub_81B239C(u8);
void PartyMenuInitHelperStructs(u8);
void LoadHeldItemIcons(void);
void LoadPartyMenuPokeballGfx(void);
void LoadPartyMenuAilmentGfx(void);
bool8 party_menu_add_per_mon_objects(void);
bool8 RenderPartyMenuBoxes(void);
void sub_81B0F28(void);
void sub_81B2428(u8);
void display_pokemon_menu_message(u32);
void PartyMenuExitTask(u8);
void FreePartyPointers(void);
void PartyPaletteBufferCopy(u8);
void sub_81B0CEC(u8);
void UpdateSelectedPartyBox(struct Struct203CEDC *, u8);
void sub_81B2720(u8);
void DisplayPartyPokemonSelectForRelearner(u8);
void DisplayPartyPokemonSelectForContest(u8);
void DisplayPartyPokemonSelectForBattle(u8);
void sub_81B0B98(u8);
void DisplayPartyPokemonSelectHeldItemRelated(u8);
bool8 sub_81B0BFC(u8);
void DisplayPartyPokemonData(u8);
void sub_81B0FCC(u8, u8);
void DisplayPartyPokemonNickname(struct Pokemon *, struct Struct203CEDC *, u8);
void DisplayPartyPokemonLevelCheck(struct Pokemon *, struct Struct203CEDC *, u8);
void DisplayPartyPokemonGenderNidoranCheck(struct Pokemon *, struct Struct203CEDC *, u8);
void DisplayPartyPokemonHPCheck(struct Pokemon *, struct Struct203CEDC *, u8);
void DisplayPartyPokemonMaxHPCheck(struct Pokemon *, struct Struct203CEDC *, u8);
void DisplayPartyPokemonHPBarCheck(struct Pokemon *, struct Struct203CEDC *);
void DisplayPartyPokemonOtherText(u8, struct Struct203CEDC *, u8);
u8 sub_81B8830(void);
bool8 GetBattleEntryEligibility(struct Pokemon *);
bool8 sub_81B218C(u8);
void DisplayPartyPokemonSelectToTeachMove(u8, u16, u8);
u8 CanPartyPokemonLearnTMTutor(struct Pokemon *, u16, u8);
void DisplayPartyPokemonBarDetail(u8, const u8*, u8, u8*);
void DisplayPartyPokemonLevel(u8, struct Struct203CEDC *);
void DisplayPartyPokemonGender(u8, u16, u8*, struct Struct203CEDC *);
void DisplayPartyPokemonHP(u16, struct Struct203CEDC *);
void DisplayPartyPokemonMaxHP(u16, struct Struct203CEDC *);
void DisplayPartyPokemonHPBar(u16, u16, struct Struct203CEDC *);
void party_menu_link_mon_icon_anim(u16, u32, struct Struct203CEDC *, u8, u32);
void party_menu_link_mon_held_item_object(u16, u16, struct Struct203CEDC *);
void party_menu_link_mon_pokeball_object(u16, struct Struct203CEDC *);
void party_menu_link_mon_status_condition_object(u16, u8, struct Struct203CEDC *);
void party_menu_held_item_object(struct Pokemon *, struct Struct203CEDC *);
void party_menu_pokeball_object(struct Pokemon *, struct Struct203CEDC *);
void party_menu_icon_anim(struct Pokemon *, struct Struct203CEDC *, u32);
void party_menu_status_condition_object(struct Pokemon *, struct Struct203CEDC *);
u8 sub_81B5F74(u8, u8);
void sub_81B120C(void);
u8 sub_81B5F34(u8, u8);
void AnimateSelectedPartyIcon(u8, u8);
void sub_81B5F98(u8, u8);
u8 GetPartyBoxPalBitfield(u8, u8);
bool8 PartyBoxPal_ParnterOrDisqualifiedInArena(u8);
u8 sub_81B8F38(u8);
void c3_0811FAB4(u8);
void sub_81B9080(void);
void sub_81B4F88(void);
void sub_81B15D0(u8, s8*);
void sub_81B140C(u8, s8*);
u16 PartyMenuButtonHandler(s8*);
s8* sub_81B13EC(void);
bool8 sub_81B15A4(u8*);
void sub_81B302C(u8*);
void sub_81B9140(void);
void sub_81B6794(u8);
void sub_81B7E4C(u8);
void sub_81B8474(u8);
void sub_81B7FAC(u8);
void sub_81B3938(u8);
void sub_81B21AC(u8, u8);
void sub_81B36FC(u8);
void sub_81B407C(u8);
void sub_81B2210(u8);
bool8 sub_81B1660(u8);
const u8* sub_81B88BC(void);
u8 sub_81B1B5C(const u8*, u8);
void sub_81B16D4(u8);
void sub_81B334C(void);
void sub_81B1708(u8);
bool8 sub_81B1BD4(void);
void sub_81B1C1C(u8);
void sub_81B8558(void);
void UpdateCurrentPartySelection(s8*, s8);
void SetNewPartySelectTarget1(s8*, s8);
void SetNewPartySelectTarget2(s8*, s8);
s8 sub_81B1B00(s8, s8);
void sub_81B3300(const u8*);
void sub_81B1B8C(u8);
void DisplayPartyPokemonHPCheck(struct Pokemon*, struct Struct203CEDC*, u8);
void DisplayPartyPokemonHPBarCheck(struct Pokemon*, struct Struct203CEDC*);
bool16 sub_81B2134(struct Pokemon*);
bool16 sub_81B2164(struct Pokemon*);
void sub_81B2248(u8);
void sub_81B227C(u8);
bool8 sub_81B2370(u16, u8);
u16 sub_81B2360(u8);
bool8 sub_81B314C(void);
void sub_81B3414(struct Pokemon*, u8);
u8 sub_81B8A2C(struct Pokemon*);
u8 sub_81B856C(s8);
void sub_81B469C(u8);
void sub_81B3730(u8);
void sub_81B3828(void);
void pokemon_change_order(void);
void sub_81B3894(void);
void sub_81B3CC0(u8);
void sub_81B3D48(u8);
void swap_pokemon_and_oams(void);
void sub_81B3E60(u8);
void sub_81B41C4(void);
void c2_8123744(void);
void sub_81B452C(void);
void sub_81B4350(u8);
void sub_81B42D0(u8);
void sub_81B43A8(u8);
void sub_81B43DC(u8);
void sub_81B44FC(u8);
void sub_81B4578(void);
void sub_81B4624(u8);
void sub_81B5C94(struct Pokemon*, struct Struct203CEDC*);
void sub_81B48A8(u8);
void sub_81B48DC(u8);
void sub_81B4988(u8);
void sub_81B4A98(void);
void sub_81B4AE0(void);
void sub_81B4B6C(u8);
void sub_81B4BA0(u8);
void sub_81B4C60(u8);
void sub_81B4C94(u8);
bool8 sub_81B8A7C(void);
void sub_81B53FC(u8);
void sub_81B5430(u8);
void task_brm_cancel_1_on_keypad_a_or_b(u8);
void sub_81B5674(u8);
void sub_81B57DC(void);
void sub_81B5864(void);
void sub_81B56A4(u8);
void sub_81B56D8(u8);
void task_launch_hm_phase_2(u8);
u16 brm_get_selected_species(void);
void sub_81B5B38(u8, struct Pokemon*);
void UpdatePartyMonIconFrame(struct Sprite*);
void UpdatePartyMonIconFrameAndBounce(struct Sprite*);
void sub_81B5CB0(u16, struct Struct203CEDC*);
void sub_81B5DF0(u8, u8);
void sub_81B5E74(struct Sprite*);
void party_menu_get_status_condition_and_update_object(struct Pokemon*, struct Struct203CEDC*);
void party_menu_update_status_condition_object(u8, struct Struct203CEDC*);
u8 sub_81B8984(void);
void sub_81B6280(u8);
void c2_815ABFC(void);
u8 GetItemEffectType(u16);
void sub_81B672C(u8);
u16 sub_81B691C(struct Pokemon*, u8);
void option_menu_get_string(u8, u8*);
void sub_81B6BB4(u8);
void ether_effect_related_2(u8);
void ether_effect_related(u8);
void sub_81B6EB4(u8);
void sub_81B6FF4(u8);
void sub_81B6F60(u8);
void sub_81B6F98(u8);
void sub_81B77AC(u8);
void sub_81B7028(u8);
void sub_81B7088(u8);
void sub_81B7230(u8);
void sub_81B70B8(void);
void sub_81B70F0(void);
void sub_81B711C(u8);
void sub_81B7154(u8);
void sub_81B71D4(u8);
void sub_81B7294(u8);
void sub_81B72C8(u8);
void sub_81B73E4(u8);
void sub_81B79A0(struct Pokemon*, s16*);
void sub_81B754C(u8, struct Pokemon*);
void sub_81B75D4(u8);
void sub_81B767C(u8);
void sub_81B7634(u8);
void sub_81B76C8(u8);
void sub_81B7704(u8);
void sub_81B7810(u8);
void sub_81B787C(u8);
void sub_81B7910(u8, u16);
void sub_81B7A28(u8);
void task_sacred_ash_party_loop(u8);
void sub_81B7C10(u8);
void sub_81B8044(u8);
void sub_81B83B8(u8);
void sub_81B82A0(u8);
void sub_81B83F0(u16);
void sub_81B814C(void);
void sub_81B8088(u8);
void sub_81B8104(u8);
void sub_81B81A8(void);
bool8 sub_81B841C(u16);
void sub_81B8230(u8);
void sub_81B82D4(u8);
void sub_81B879C(u8);
void sub_81B8558(void);
bool8 GetBattleEntryEligibility(struct Pokemon*);
bool8 sub_81B8770(u8);
u8 sub_81B8888(void);
u8 sub_81B885C(void);
void sub_81B87E8(u8);
u8 pokemon_order_func(u8);
void sub_81B8FB0(u8, u8);
void sub_81B8C88(u8*, bool8);
void sub_81B8D88(u8*, u8, u8);
void sub_81B917C(u8);
void sub_81B91B4(u8);
void sub_81B9294(u8);
void sub_81B9240(u8);
void sub_81B9390(void);
void task_hm_without_phase_2(u8);
void sub_81B9424(u8);
void sub_81B9470(void);
void sub_81B94D0(u8);
void sub_81B953C(u8);
void sub_81B9588(void);
void sub_81B9640(u8);
void sub_81B97DC(struct Pokemon*, u8, u8);

void InitPartyMenu(u8 a, u8 b, u8 c, u8 d, u8 e, TaskFunc task, MainCallback callback)
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
            gUnknown_0203CEC4->unkC[i] |= 0xFF;

        if (d == 0)
            gUnknown_0203CEC8.unk9 = 0;
        else if (gUnknown_0203CEC8.unk9 > 5 || GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES) == SPECIES_NONE)
            gUnknown_0203CEC8.unk9 = 0; // wut why is this else if?

        gTextFlags.autoScroll = 0;
        CalculatePlayerPartyCount();
        SetMainCallback2(PartyMenuInitCallback);
    }
}

void PartyMenuCallback(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void PartyMenuVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void PartyMenuInitCallback(void)
{
    while (TRUE)
    {
        if (sub_81221EC() == TRUE || PartyMenuSetup() == TRUE || sub_81221AC() == TRUE)
            break;
    }
}

bool8 PartyMenuSetup(void)
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

void PartyMenuExit(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(PartyMenuExitTask, 0);
    SetVBlankCallback(PartyMenuVBlankCallback);
    SetMainCallback2(PartyMenuCallback);
}

void PartyMenuExitTask(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(gUnknown_0203CEC8.exitCallback);
        FreePartyPointers();
        DestroyTask(taskId);
    }
}

void reset_brm(void)
{
    gUnknown_0203CEC4 = NULL;
    gUnknown_0203CEE4 = NULL;
    gUnknown_0203CEDC = NULL;
    gUnknown_0203CEE0 = NULL;
}

bool8 AllocPartyMenuBg(void)
{
    gUnknown_0203CEE4 = Alloc(0x800);
    if (gUnknown_0203CEE4 == NULL)
        return FALSE;
    memset(gUnknown_0203CEE4, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_086156B8, 3);
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

bool8 AllocPartyMiscGfx(void)
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

void PartyPaletteBufferCopy(u8 offset)
{
    offset *= 16;
    CpuCopy16(&gPlttBufferUnfaded[0x30], &gPlttBufferUnfaded[offset], 32);
    CpuCopy16(&gPlttBufferUnfaded[0x30], &gPlttBufferFaded[offset], 32);
}

void FreePartyPointers(void)
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

void PartyMenuInitHelperStructs(u8 a)
{
    u8 i;

    gUnknown_0203CEDC = Alloc(sizeof(struct Struct203CEDC[PARTY_SIZE]));

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gUnknown_0203CEDC[i].unk0 = &gUnknown_086156C4[1];
        gUnknown_0203CEDC[i].unk4 = gUnknown_08615704[a][i];
        gUnknown_0203CEDC[i].windowId = i;
        gUnknown_0203CEDC[i].unk9 |= 0xFF;
        gUnknown_0203CEDC[i].unkA |= 0xFF;
        gUnknown_0203CEDC[i].unkB |= 0xFF;
        gUnknown_0203CEDC[i].unkC |= 0xFF;
    }
    gUnknown_0203CEDC[0].unk0 = &gUnknown_086156C4[0];
    if (a == 3)
        gUnknown_0203CEDC[3].unk0 = &gUnknown_086156C4[0];
    else if (a != 0)
        gUnknown_0203CEDC[1].unk0 = &gUnknown_086156C4[0];
}

void RenderPartyMenuBox(u8 slot)
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

void DisplayPartyPokemonData(u8 slot)
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

void DisplayPartyPokemonSelectData(u8 slot, u8 stringID)
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

void DisplayPartyPokemonSelectForBattle(u8 slot)
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

void DisplayPartyPokemonSelectForContest(u8 slot)
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

void DisplayPartyPokemonSelectForRelearner(u8 slot)
{
    if (GetNumberOfRelearnableMoves(&gPlayerParty[slot]) == 0)
        DisplayPartyPokemonSelectData(slot, 9);
    else
        DisplayPartyPokemonSelectData(slot, 8);
}

void sub_81B0B98(u8 slot)
{
    if (sub_81B218C(slot) == TRUE)
        DisplayPartyPokemonSelectData(slot, 6);
    else
        DisplayPartyPokemonSelectData(slot, 7);
}

void DisplayPartyPokemonSelectHeldItemRelated(u8 slot)
{
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM))
        DisplayPartyPokemonSelectData(slot, 11);
    else
        DisplayPartyPokemonSelectData(slot, 12);
}

bool8 sub_81B0BFC(u8 slot)
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

void DisplayPartyPokemonSelectToTeachMove(u8 slot, u16 item, u8 tutor)
{
    switch (CanPartyPokemonLearnTMTutor(&gPlayerParty[slot], item, tutor))
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

void sub_81B0CEC(u8 slot)
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

bool8 RenderPartyMenuBoxes(void)
{
    RenderPartyMenuBox(gUnknown_0203CEC4->data[0]);
    if (++gUnknown_0203CEC4->data[0] == 6)
        return TRUE;
    return FALSE;
}

u8* GetPartyMiscGraphicsTile(u16 tileId)
{
    return &gUnknown_0203CEE0[tileId << 5];
}

void party_menu_add_per_mon_objects_internal(u8 slot)
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

bool8 party_menu_add_per_mon_objects(void)
{
    party_menu_add_per_mon_objects_internal(gUnknown_0203CEC4->data[0]);
    if (++gUnknown_0203CEC4->data[0] == 6)
        return TRUE;
    return FALSE;
}

void sub_81B0F28(void)
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

u8 GetPartyBoxPalBitfield(u8 slot, u8 b)
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

bool8 PartyBoxPal_ParnterOrDisqualifiedInArena(u8 slot)
{
    if (gUnknown_0203CEC8.mode == 2 && (slot == 1 || slot == 4 || slot == 5))
        return TRUE;

    if (slot < 3 && (gBattleTypeFlags & BATTLE_TYPE_ARENA) && gMain.inBattle && (gBattleStruct->arenaLostPlayerMons >> sub_81B8F38(slot) & 1))
        return TRUE;

    return FALSE;
}

void sub_81B120C(void)
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

void sub_81B1288(struct Pokemon *partySlot, struct Pokemon *pokemon)
{
    struct Pokemon *temp = Alloc(sizeof(struct Pokemon));

    *temp = *partySlot;
    *partySlot = *pokemon;
    *pokemon = *temp;

    Free(temp);
}

void sub_81B12C0(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = c3_0811FAB4;
}

void c3_0811FAB4(u8 taskId)
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
        }
    }
}

s8* sub_81B13EC(void)
{
    if (gUnknown_0203CEC8.unkB == 8 || gUnknown_0203CEC8.unkB == 10)
        return &gUnknown_0203CEC8.unkA;
    return &gUnknown_0203CEC8.unk9;
}

void sub_81B140C(u8 taskId, s8 *ptr)
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

bool8 sub_81B15A4(u8 *slotPtr)
{
    if (GetMonData(&gPlayerParty[*slotPtr], MON_DATA_IS_EGG) == TRUE)
    {
        PlaySE(SE_HAZURE);
        return FALSE;
    }
    return TRUE;
}

void sub_81B15D0(u8 taskId, s8 *ptr)
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

bool8 sub_81B1660(u8 taskId)
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

void sub_81B16D4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B1708;
    }
}

void sub_81B1708(u8 taskId)
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

u16 PartyMenuButtonHandler(s8 *ptr)
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

#ifdef NONMATCHING
void UpdateCurrentPartySelection(s8 *ptr, s8 movementDir)
{
    s8 slot = *ptr;

    if (gUnknown_0203CEC8.mode == 0)
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
#else
NAKED
void UpdateCurrentPartySelection(s8 *ptr, s8 b)
{
    asm_unified("push {r4,r5,lr}\n\
	adds r5, r0, 0\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	ldrb r4, [r5]\n\
	ldr r0, =gUnknown_0203CEC8\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 26\n\
	lsrs r0, 30\n\
	cmp r0, 0\n\
	bne _081B1820\n\
	lsls r1, 24\n\
	asrs r1, 24\n\
	adds r0, r5, 0\n\
	bl SetNewPartySelectTarget1\n\
	b _081B182A\n\
	.pool\n\
_081B1820:\n\
	lsls r1, 24\n\
	asrs r1, 24\n\
	adds r0, r5, 0\n\
	bl SetNewPartySelectTarget2\n\
_081B182A:\n\
	movs r1, 0\n\
	ldrsb r1, [r5, r1]\n\
	lsls r4, 24\n\
	asrs r0, r4, 24\n\
	cmp r1, r0\n\
	beq _081B184C\n\
	movs r0, 0x5\n\
	bl PlaySE\n\
	lsrs r0, r4, 24\n\
	movs r1, 0\n\
	bl sub_81B0FCC\n\
	ldrb r0, [r5]\n\
	movs r1, 0x1\n\
	bl sub_81B0FCC\n\
_081B184C:\n\
	pop {r4,r5}\n\
	pop {r0}\n\
	bx r0\n");
}
#endif

#ifdef NONMATCHING
void SetNewPartySelectTarget1(s8 *ptr, s8 b)
{
    u8 r0r2;

    switch (b)
    {
        case -1:
            r0r2 = *ptr;
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
                *ptr = r0r2 - 1;
            }
            break;
        case 1:
            r0r2 = *ptr;
            if (*ptr != 7)
            {
                if ((u32)*ptr == gPlayerPartyCount - 1)
                {
                    if (gUnknown_0203CEC4->unk8_0)
                        *ptr = 6;
                    else
                        *ptr = 7;
                }
                else
                {
                    *ptr = r0r2 + 1;
                }
            }
            else
            {
                *ptr = 0;
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
#else
NAKED
void SetNewPartySelectTarget1(s8 *ptr, s8 b)
{
    asm_unified("push {r4,lr}\n\
	adds r4, r0, 0\n\
	lsls r1, 24\n\
	asrs r1, 24\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	cmp r1, r0\n\
	beq _081B187A\n\
	cmp r1, r0\n\
	bgt _081B1870\n\
	subs r0, 0x1\n\
	cmp r1, r0\n\
	beq _081B1924\n\
	b _081B1952\n\
_081B1870:\n\
	cmp r1, 0x1\n\
	beq _081B18C0\n\
	cmp r1, 0x2\n\
	beq _081B18F8\n\
	b _081B1952\n\
_081B187A:\n\
	ldrb r0, [r4]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	cmp r1, 0\n\
	bne _081B1888\n\
	movs r0, 0x7\n\
	b _081B1950\n\
_081B1888:\n\
	cmp r1, 0x6\n\
	bne _081B1898\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	b _081B1950\n\
	.pool\n\
_081B1898:\n\
	cmp r1, 0x7\n\
	bne _081B18BC\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B18B0\n\
	movs r0, 0x6\n\
	b _081B1950\n\
	.pool\n\
_081B18B0:\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	b _081B1950\n\
	.pool\n\
_081B18BC:\n\
	subs r0, 0x1\n\
	b _081B1950\n\
_081B18C0:\n\
	ldrb r2, [r4]\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0x7\n\
	beq _081B194E\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	cmp r1, r0\n\
	bne _081B18F4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B18F0\n\
	movs r0, 0x6\n\
	b _081B1950\n\
	.pool\n\
_081B18F0:\n\
	movs r0, 0x7\n\
	b _081B1950\n\
_081B18F4:\n\
	adds r0, r2, 0x1\n\
	b _081B1950\n\
_081B18F8:\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x1\n\
	beq _081B1952\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	bne _081B1952\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 28\n\
	lsrs r0, 29\n\
	cmp r0, 0\n\
	bne _081B1950\n\
	movs r0, 0x1\n\
	b _081B1950\n\
	.pool\n\
_081B1924:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	beq _081B1952\n\
	cmp r0, 0x6\n\
	beq _081B1952\n\
	cmp r0, 0x7\n\
	beq _081B1952\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r3, [r0]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	movs r0, 0x7\n\
	ands r1, r0\n\
	lsls r1, 1\n\
	ldrb r2, [r3, 0x8]\n\
	movs r0, 0xF\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, 0x8]\n\
_081B194E:\n\
	movs r0, 0\n\
_081B1950:\n\
	strb r0, [r4]\n\
_081B1952:\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
    .pool\n");
}
#endif

#ifdef NONMATCHING
void SetNewPartySelectTarget2(s8 *ptr, s8 b)
{
    u8 unk;
    s8 unk2 = b;
    u8 unk3;

    switch (b)
    {
        case -1:
            unk = *ptr;
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
                {
                    *ptr = 6;
                }
                else
                {
                    *ptr = unk - 1;
                    unk2 = sub_81B1B00(*ptr, unk2);
                    if (unk2 != -1)
                        *ptr = unk2;
                }
            }
            else
            {
                unk2 = sub_81B1B00(*ptr, unk2);
                if (unk2 != -1)
                    *ptr = unk2;
            }
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
            unk3 = *ptr - 2;
            if (unk3 <= 1)
            {
                gUnknown_0203CEC4->unk8_1 = *ptr;
                *ptr = 0;
            }
            else
            {
                unk3 = *ptr - 4;
                if (unk3 <= 1)
                {
                    gUnknown_0203CEC4->unk8_1 = *ptr;
                    *ptr = 1;
                }
            }
            break;
    }
}
#else
NAKED
void SetNewPartySelectTarget2(s8 *ptr, s8 b)
{
    asm_unified("push {r4-r6,lr}\n\
	adds r4, r0, 0\n\
	lsls r1, 24\n\
	lsrs r2, r1, 24\n\
	asrs r5, r1, 24\n\
	movs r6, 0x1\n\
	negs r6, r6\n\
	cmp r5, r6\n\
	beq _081B1988\n\
	cmp r5, r6\n\
	bgt _081B197E\n\
	movs r0, 0x2\n\
	negs r0, r0\n\
	cmp r5, r0\n\
	bne _081B197C\n\
	b _081B1A9C\n\
_081B197C:\n\
	b _081B1AF4\n\
_081B197E:\n\
	cmp r5, 0x1\n\
	beq _081B19E4\n\
	cmp r5, 0x2\n\
	beq _081B1A24\n\
	b _081B1AF4\n\
_081B1988:\n\
	ldrb r1, [r4]\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	bne _081B1996\n\
	movs r0, 0x7\n\
	b _081B1AF2\n\
_081B1996:\n\
	cmp r0, 0x6\n\
	bne _081B19A8\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	subs r0, 0x1\n\
	b _081B1AF2\n\
	.pool\n\
_081B19A8:\n\
	cmp r0, 0x7\n\
	bne _081B19C4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B19C0\n\
	movs r0, 0x6\n\
	b _081B1AF2\n\
	.pool\n\
_081B19C0:\n\
	subs r0, r1, 0x1\n\
	strb r0, [r4]\n\
_081B19C4:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	lsls r1, r2, 24\n\
	asrs r1, 24\n\
	bl sub_81B1B00\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	asrs r0, 24\n\
	movs r1, 0x1\n\
	negs r1, r1\n\
	cmp r0, r1\n\
	bne _081B19E0\n\
	b _081B1AF4\n\
_081B19E0:\n\
	strb r2, [r4]\n\
	b _081B1AF4\n\
_081B19E4:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0x6\n\
	bne _081B19F0\n\
	movs r0, 0x7\n\
	b _081B1AF2\n\
_081B19F0:\n\
	cmp r0, 0x7\n\
	bne _081B19F8\n\
	movs r0, 0\n\
	b _081B1AF2\n\
_081B19F8:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	movs r1, 0x1\n\
	bl sub_81B1B00\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, r6\n\
	bne _081B19E0\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 31\n\
	cmp r0, 0\n\
	beq _081B1A20\n\
	movs r0, 0x6\n\
	b _081B1AF2\n\
	.pool\n\
_081B1A20:\n\
	movs r0, 0x7\n\
	b _081B1AF2\n\
_081B1A24:\n\
	movs r0, 0\n\
	ldrsb r0, [r4, r0]\n\
	cmp r0, 0\n\
	bne _081B1A5C\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 28\n\
	lsrs r6, r0, 29\n\
	cmp r6, 0x3\n\
	bne _081B1A54\n\
	ldr r0, =gPlayerParty + 300\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	beq _081B1AF4\n\
	strb r6, [r4]\n\
	b _081B1AF4\n\
	.pool\n\
_081B1A54:\n\
	ldr r0, =gPlayerParty + 200\n\
	b _081B1A70\n\
	.pool\n\
_081B1A5C:\n\
	cmp r0, 0x1\n\
	bne _081B1AF4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r0, [r0]\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 28\n\
	lsrs r5, r0, 29\n\
	cmp r5, 0x5\n\
	bne _081B1A88\n\
	ldr r0, =gPlayerParty + 500\n\
_081B1A70:\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	beq _081B1AF4\n\
	strb r5, [r4]\n\
	b _081B1AF4\n\
	.pool\n\
_081B1A88:\n\
	ldr r0, =gPlayerParty + 400\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	beq _081B1AF4\n\
	movs r0, 0x4\n\
	b _081B1AF2\n\
	.pool\n\
_081B1A9C:\n\
	ldrb r1, [r4]\n\
	subs r0, r1, 0x2\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0x1\n\
	bhi _081B1ACC\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r3, [r0]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	movs r0, 0x7\n\
	ands r1, r0\n\
	lsls r1, 1\n\
	ldrb r2, [r3, 0x8]\n\
	movs r0, 0xF\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, 0x8]\n\
	movs r0, 0\n\
	b _081B1AF2\n\
	.pool\n\
_081B1ACC:\n\
	subs r0, r1, 0x4\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0x1\n\
	bhi _081B1AF4\n\
	ldr r0, =gUnknown_0203CEC4\n\
	ldr r3, [r0]\n\
	movs r1, 0\n\
	ldrsb r1, [r4, r1]\n\
	movs r0, 0x7\n\
	ands r1, r0\n\
	lsls r1, 1\n\
	ldrb r2, [r3, 0x8]\n\
	movs r0, 0xF\n\
	negs r0, r0\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strb r0, [r3, 0x8]\n\
	movs r0, 0x1\n\
_081B1AF2:\n\
	strb r0, [r4]\n\
_081B1AF4:\n\
	pop {r4-r6}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

s8 sub_81B1B00(s8 a, s8 b)
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

void sub_81B1B8C(u8 taskId)
{
    if (RunTextPrintersRetIsActive(6) != TRUE)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            sub_8198070(6, 0);
            ClearWindowTilemap(6);
        }
        DestroyTask(taskId);
    }
}

bool8 sub_81B1BD4(void)
{
    return FuncIsActiveTask(sub_81B1B8C);
}

void sub_81B1BE8(u8 taskId)
{
    if (sub_81221EC() != TRUE)
    {
        display_pokemon_menu_message(0);
        gTasks[taskId].func = sub_81B1370;
    }
}

void sub_81B1C1C(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_8198070(6, 0);
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

void sub_81B1C84(struct Pokemon *mon, u16 item, u8 c, u8 unused)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_PkmnWasGivenItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1CD0(struct Pokemon *mon, u16 item, u8 c)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_RecievedItemFromPkmn);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1D1C(struct Pokemon *mon, u16 item, u8 c)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_SwitchPkmnItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1D68(u16 item, u16 item2, u8 c)
{
    CopyItemName(item, gStringVar1);
    CopyItemName(item2, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_SwitchedPkmnItem);
    sub_81B1B5C(gStringVar4, c);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B1DB8(struct Pokemon *mon, u16 item)
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

u8 sub_81B1E00(struct Pokemon* mon)
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

void pokemon_item_not_removed(u16 itemUnused)
{
    StringExpandPlaceholders(gStringVar4, gText_BagFullCouldNotRemoveItem);
}

void sub_81B1E60(u8 taskId)
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

void sub_81B1FA8(u8 taskId, u8 b, u32 hp)
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

u8 sub_81B205C(struct Pokemon *mon)
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

void sub_81B209C(void)
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

bool16 sub_81B2134(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && sub_802C908(GetMonData(mon, MON_DATA_SPECIES)))
        return TRUE;
    return FALSE;
}

// Dodrio Berry Picking select?

bool16 sub_81B2164(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && GetMonData(mon, MON_DATA_SPECIES) == SPECIES_DODRIO)
        return TRUE;
    return FALSE;
}

bool8 sub_81B218C(u8 slot)
{
    if (!((gUnknown_0203CEC8.unkE >> slot) & 1))
        return FALSE;
    return TRUE;
}

void sub_81B21AC(u8 taskId, u8 slot)
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

void sub_81B2210(u8 taskId)
{
    sub_81B1B5C(gText_CancelParticipation, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B2248;
}

void sub_81B2248(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B227C;
    }
}

void sub_81B227C(u8 taskId)
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

u8 CanPartyPokemonLearnTMTutor(struct Pokemon *mon, u16 item, u8 tutor)
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
    else if (sub_81B2370(GetMonData(mon, MON_DATA_SPECIES), tutor) == FALSE)
    {
        return CANNOT_LEARN_MOVE;
    }
    else
    {
        move = sub_81B2360(tutor);
    }

    if (pokemon_has_move(mon, move) == TRUE)
        return ALREADY_KNOWS_MOVE;
    return CAN_LEARN_MOVE;
}

u16 sub_81B2360(u8 tutor)
{
    return gUnknown_0861500C[tutor];
}

bool8 sub_81B2370(u16 species, u8 tutor)
{
    if (gUnknown_08615048[species] & (1 << tutor))
        return TRUE;
    return FALSE;
}

void sub_81B239C(u8 a)
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
        FillWindowPixelBuffer(i, 0);
    LoadUserWindowBorderGfx(0, 0x4F, 0xD0);
    LoadPalette(GetOverworldTextboxPalettePtr(), 0xE0, 0x20);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
}

void sub_81B2428(bool8 a)
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
            FillWindowPixelBuffer(firstWindowId, 0);
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
        FillWindowPixelBuffer(windowId, 0);
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

u16* GetPartyMenuPaletteFromBuffer(u8 paletteId)
{
    return &gUnknown_0203CEC4->palBuffer[paletteId];
}

void BlitBitmapToPartyWindow(u8 windowId, u8 *b, u8 c, u8 x, u8 y, u8 width, u8 height)
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

void BlitBitmapToPartyWindow_Default1(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f)
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

void BlitBitmapToPartyWindow_Default2(u8 windowId, u8 x, u8 y, u8 width, u8 height, u8 f)
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

void sub_81B2720(u8 windowId)
{
    BlitBitmapToPartyWindow(windowId, gUnknown_08615A80, 18, 0, 0, 18, 3);
}

void UpdateSelectedPartyBox(struct Struct203CEDC *ptr, u8 bitfield)
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

void DisplayPartyPokemonBarDetail(u8 windowId, const u8 *str, u8 color, u8 *align)
{
    AddTextPrinterParameterized3(windowId, 0, align[0], align[1], gUnknown_086157FC[color], 0, str);
}

void DisplayPartyPokemonNickname(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
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

void DisplayPartyPokemonLevelCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        u8 ailment = sub_81B205C(mon);
        if (ailment == AILMENT_NONE || ailment == AILMENT_PKRS)
        {
            if (c != 0)
                ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk4[4] >> 3, (ptr->unk0->unk4[5] >> 3) + 1, ptr->unk0->unk4[6] >> 3, ptr->unk0->unk4[7] >> 3, 0);
            if (c != 2)
                DisplayPartyPokemonLevel(GetMonData(mon, MON_DATA_LEVEL), ptr);
        }
    }
}

void DisplayPartyPokemonLevel(u8 level, struct Struct203CEDC *ptr)
{
    ConvertIntToDecimalStringN(gStringVar2, level, 0, 3);
    StringCopy(gStringVar1, gText_LevelSymbol);
    StringAppend(gStringVar1, gStringVar2);
    DisplayPartyPokemonBarDetail(ptr->windowId, gStringVar1, 0, &ptr->unk0->unk4[4]);
}

void DisplayPartyPokemonGenderNidoranCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];

    if (c == 1)
        ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk4[8] >> 3, (ptr->unk0->unk4[9] >> 3) + 1, ptr->unk0->unk4[10] >> 3, ptr->unk0->unk4[11] >> 3, 0);
    GetMonNickname(mon, nickname);
    DisplayPartyPokemonGender(GetMonGender(mon), GetMonData(mon, MON_DATA_SPECIES), nickname, ptr);
}

void DisplayPartyPokemonGender(u8 gender, u16 species, u8 *nickname, struct Struct203CEDC *ptr)
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

void DisplayPartyPokemonHPCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk4[12] >> 3, (ptr->unk0->unk4[13] >> 3) + 1, ptr->unk0->unk4[14] >> 3, ptr->unk0->unk4[15] >> 3, 0);
        if (c != 2)
            DisplayPartyPokemonHP(GetMonData(mon, MON_DATA_HP), ptr);
    }
}

void DisplayPartyPokemonHP(u16 hp, struct Struct203CEDC *ptr)
{
    u8 *strOut = ConvertIntToDecimalStringN(gStringVar1, hp, 1, 3);

    strOut[0] = CHAR_SLASH;
    strOut[1] = EOS;

    DisplayPartyPokemonBarDetail(ptr->windowId, gStringVar1, 0, &ptr->unk0->unk4[12]);
}

void DisplayPartyPokemonMaxHPCheck(struct Pokemon *mon, struct Struct203CEDC *ptr, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            ptr->unk0->unk0(ptr->windowId, (ptr->unk0->unk4[16] >> 3) + 1, (ptr->unk0->unk4[17] >> 3) + 1, ptr->unk0->unk4[18] >> 3, ptr->unk0->unk4[19] >> 3, 0);
        if (c != 2)
            DisplayPartyPokemonMaxHP(GetMonData(mon, MON_DATA_MAX_HP), ptr);
    }
}

void DisplayPartyPokemonMaxHP(u16 maxhp, struct Struct203CEDC *ptr)
{
    ConvertIntToDecimalStringN(gStringVar2, maxhp, 1, 3);
    StringCopy(gStringVar1, gText_Slash);
    StringAppend(gStringVar1, gStringVar2);
    DisplayPartyPokemonBarDetail(ptr->windowId, gStringVar1, 0, &ptr->unk0->unk4[16]);
}

void DisplayPartyPokemonHPBarCheck(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
        DisplayPartyPokemonHPBar(GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP), ptr);
}

void DisplayPartyPokemonHPBar(u16 hp, u16 maxhp, struct Struct203CEDC *ptr)
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
        FillWindowPixelRect(ptr->windowId, 13, ptr->unk0->unk4[20] + hpFraction, ptr->unk0->unk4[21], ptr->unk0->unk4[22] - hpFraction, 1);
        FillWindowPixelRect(ptr->windowId, 2, ptr->unk0->unk4[20] + hpFraction, ptr->unk0->unk4[21] + 1, ptr->unk0->unk4[22] - hpFraction, 2);
    }
    CopyWindowToVram(ptr->windowId, 2);
}

#ifdef NONMATCHING
void DisplayPartyPokemonOtherText(u8 stringID, struct Struct203CEDC *ptr, u8 c)
{
    if (c != 0)
    {
        int unk = ((ptr->unk0->unk1C & 7) + ptr->unk0->unk1E + 7) / 8;
        int unk2 = ((ptr->unk0->unk1D & 7) + ptr->unk0->unk1F + 7) / 8;
        ptr->unk0->unk0(ptr->windowId, ptr->unk0->unk1C >> 3, ptr->unk0->unk1D >> 3, unk, unk2, 1);
    }
    if (c != 2)
        AddTextPrinterParameterized3(ptr->windowId, 1, ptr->unk0->unk1C, ptr->unk0->unk1D, gUnknown_086157FC[0], 0, gUnknown_08615B60[stringID]);
}
#else
NAKED
void DisplayPartyPokemonOtherText(u8 stringID, struct Struct203CEDC *ptr, u8 c)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0xC\n\
	adds r6, r1, 0\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r8, r0\n\
	lsls r2, 24\n\
	lsrs r7, r2, 24\n\
	cmp r7, 0\n\
	beq _081B2FF2\n\
	ldr r5, [r6]\n\
	ldrb r1, [r5, 0x1C]\n\
	movs r4, 0x7\n\
	adds r0, r1, 0\n\
	ands r0, r4\n\
	ldrb r2, [r5, 0x1E]\n\
	adds r0, r2\n\
	adds r3, r0, 0x7\n\
	asrs r3, 3\n\
	ldrb r2, [r5, 0x1D]\n\
	adds r0, r2, 0\n\
	ands r0, r4\n\
	ldrb r4, [r5, 0x1F]\n\
	adds r0, r4\n\
	adds r4, r0, 0x7\n\
	ldrb r0, [r6, 0x8]\n\
	lsrs r1, 3\n\
	lsrs r2, 3\n\
	lsrs r4, 3\n\
	str r4, [sp]\n\
	movs r4, 0x1\n\
	str r4, [sp, 0x4]\n\
	ldr r4, [r5]\n\
	bl _call_via_r4\n\
_081B2FF2:\n\
	cmp r7, 0x2\n\
	beq _081B3018\n\
	ldrb r0, [r6, 0x8]\n\
	ldr r1, [r6]\n\
	ldrb r2, [r1, 0x1C]\n\
	ldrb r3, [r1, 0x1D]\n\
	ldr r1, =gUnknown_086157FC\n\
	str r1, [sp]\n\
	movs r1, 0\n\
	str r1, [sp, 0x4]\n\
	ldr r4, =gUnknown_08615B60\n\
	mov r5, r8\n\
	lsls r1, r5, 2\n\
	adds r1, r4\n\
	ldr r1, [r1]\n\
	str r1, [sp, 0x8]\n\
	movs r1, 0x1\n\
	bl AddTextPrinterParameterized3\n\
_081B3018:\n\
	add sp, 0xC\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

void sub_81B302C(u8 *ptr)
{
    if (*ptr != 0xFF)
    {
        sub_8198070(*ptr, 0);
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
        SetWindowBorderStyle(*windowPtr, FALSE, 0x4F, 0xD);
        StringExpandPlaceholders(gStringVar4, gUnknown_08615AF4[stringID]);
        AddTextPrinterParameterized(*windowPtr, 1, gStringVar4, 0, 1, 0, 0);
        schedule_bg_copy_tilemap_to_vram(2);
    }
}

bool8 sub_81B314C(void)
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

u8 sub_81B31B0(u8 a)
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
    SetWindowBorderStyle(gUnknown_0203CEC4->unkC[0], FALSE, 0x4F, 13);
    if (a == 3)
        return gUnknown_0203CEC4->unkC[0];
    cursorDimension = GetMenuCursorDimensionByFont(1, 0);
    fontAttribute = GetFontAttribute(1, 2);

    for (i = 0; i < gUnknown_0203CEC4->unk17; i++)
    {
        u8 unk = (gUnknown_0203CEC4->unkF[i] > 18) ? 4 : 3;
        AddTextPrinterParameterized4(gUnknown_0203CEC4->unkC[0], 1, cursorDimension, (i * 16) + 1, fontAttribute, 0, gUnknown_086157FC[unk], 0, gUnknown_08615C08[gUnknown_0203CEC4->unkF[i]].textPtr);
    }

    InitMenuInUpperLeftCorner(gUnknown_0203CEC4->unkC[0], gUnknown_0203CEC4->unk17, 0, 1);
    schedule_bg_copy_tilemap_to_vram(2);

    return gUnknown_0203CEC4->unkC[0];
}

void sub_81B3300(const u8 *text)
{
    SetWindowBorderStyle(6, FALSE, 0x4F, 13);
    gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(6, 1, text, GetPlayerTextSpeedDelay(), 0, 2, 1, 3);
}

void sub_81B334C(void)
{
    CreateYesNoMenu(&gUnknown_08615968, 0x4F, 13, 0);
}

u8 sub_81B3364(void)
{
    gUnknown_0203CEC4->unkC[0] = AddWindow(&gUnknown_08615970);
    SetWindowBorderStyle(gUnknown_0203CEC4->unkC[0], FALSE, 0x4F, 13);
    return gUnknown_0203CEC4->unkC[0];
}

void sub_81B3394(void)
{
    ClearWindowTilemap(gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
}

void sub_81B33B4(struct Pokemon *mons, u8 a, u8 b)
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

void sub_81B3414(struct Pokemon *mons, u8 a)
{
    u8 i, j;

    gUnknown_0203CEC4->unk17 = 0;
    AppendToList(gUnknown_0203CEC4->unkF, &gUnknown_0203CEC4->unk17, 0);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        for (j = 0; gUnknown_08615D7E[j] != MOVE_SWORDS_DANCE; j++)
        {
            if (GetMonData(&mons[a], i + MON_DATA_MOVE1) == gUnknown_08615D7E[j])
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

u8 sub_81B353C(struct Pokemon *mon)
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

bool8 sub_81B3608(u8 taskId)
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

void sub_81B36FC(u8 taskId)
{
    if (sub_81B3608(taskId))
    {
        gTasks[taskId].data[0] = 0xFF;
        gTasks[taskId].func = sub_81B3730;
    }
}

void sub_81B3730(u8 taskId)
{
    s16 *data;
    s8 input;

    if (gPaletteFade.active == FALSE && sub_81221EC() != TRUE)
    {
        data = gTasks[taskId].data;
        if (gUnknown_0203CEC4->unk17 <= 3)
            input = Menu_ProcessInputNoWrapAround_other();
        else
            input = ProcessMenuInput_other();
        data[0] = Menu_GetCursorPos();
        if (input != MENU_NOTHING_CHOSEN)
        {
            if (input == MENU_B_PRESSED)
            {
                PlaySE(SE_SELECT);
                sub_81B302C(&gUnknown_0203CEC4->unkC[2]);
                gUnknown_08615C08[gUnknown_0203CEC4->unkF[gUnknown_0203CEC4->unk17 - 1]].func(taskId);
            }
            else
            {
                sub_81B302C(&gUnknown_0203CEC4->unkC[2]);
                gUnknown_08615C08[gUnknown_0203CEC4->unkF[input]].func(taskId);
            }
        }
    }
}

void sub_81B37FC(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC4->exitCallback = sub_81B3828;
    sub_81B12C0(taskId);
}

void sub_81B3828(void)
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

void sub_81B3894(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    gUnknown_0203CEC8.unk9 = gUnknown_0203CF20;
    InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 21, sub_81B36FC, gUnknown_0203CEC8.exitCallback);
}

void brm_switch(u8 taskId)
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

void sub_81B3938(u8 taskId)
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

#ifdef NONMATCHING
bool8 sub_81B3AD8(s16 a, s16 b, u8 *c, u8 *d, u8 *e)
{

    if ((a + b) < 0 || a > 31)
    {
        return FALSE;
    }
    if (a < 0)
    {
        *c = -a;
        *d = 0;
        *e = a + b;
        return TRUE;
    }
    else
    {
        *c = 0;
        *d = a;
        if ((a + b) > 31)
            *e = 32 - a;
        else
            *e = b;
        return TRUE;
    }

}
#else
NAKED
bool8 sub_81B3AD8(s16 a, s16 b, u8 *c, u8 *d, u8 *e)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	adds r6, r2, 0\n\
	mov r12, r3\n\
	ldr r7, [sp, 0x18]\n\
	lsls r0, 16\n\
	lsrs r3, r0, 16\n\
	adds r5, r3, 0\n\
	lsls r1, 16\n\
	lsrs r2, r1, 16\n\
	mov r8, r2\n\
	lsls r0, r3, 16\n\
	asrs r1, r0, 16\n\
	lsls r0, r2, 16\n\
	asrs r0, 16\n\
	adds r4, r1, r0\n\
	cmp r4, 0\n\
	blt _081B3B02\n\
	cmp r1, 0x1F\n\
	ble _081B3B06\n\
_081B3B02:\n\
	movs r0, 0\n\
	b _081B3B34\n\
_081B3B06:\n\
	cmp r1, 0\n\
	bge _081B3B1A\n\
	negs r0, r1\n\
	strb r0, [r6]\n\
	movs r0, 0\n\
	mov r1, r12\n\
	strb r0, [r1]\n\
	adds r0, r2, r3\n\
	strb r0, [r7]\n\
	b _081B3B32\n\
_081B3B1A:\n\
	movs r0, 0\n\
	strb r0, [r6]\n\
	mov r0, r12\n\
	strb r5, [r0]\n\
	cmp r4, 0x1F\n\
	ble _081B3B2E\n\
	movs r0, 0x20\n\
	subs r0, r5\n\
	strb r0, [r7]\n\
	b _081B3B32\n\
_081B3B2E:\n\
	mov r1, r8\n\
	strb r1, [r7]\n\
_081B3B32:\n\
	movs r0, 0x1\n\
_081B3B34:\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n");
}
#endif

void sub_81B3B40(const void *rectSrc, s16 a, s16 b, s16 c, s16 d, s16 e)
{
    u8 f, g, h;

    if (sub_81B3AD8(a, c, &f, &g, &h))
    {
        FillBgTilemapBufferRect_Palette0(0, 0, g, b, h, d);
        if (sub_81B3AD8(a + e, c, &f, &g, &h))
            CopyRectToBgTilemapBufferRect(0, rectSrc, f, 0, c, d, g, b, h, d, 17, 0, 0);
    }
}

void sub_81B3C0C(struct Struct203CEDC *ptr, s16 a)
{
    gSprites[ptr->unkB].pos2.x += a * 8;
    gSprites[ptr->unkA].pos2.x += a * 8;
    gSprites[ptr->unk9].pos2.x += a * 8;
    gSprites[ptr->unkC].pos2.x += a * 8;
}

void sub_81B3C60(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[10] != 0)
        sub_81B3C0C(&gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], data[10]);
    if (data[11] != 0)
        sub_81B3C0C(&gUnknown_0203CEDC[gUnknown_0203CEC8.unkA], data[11]);
}

void sub_81B3CC0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[10] != 0)
        sub_81B3B40(gUnknown_0203CEF0, data[0] + data[8], data[1], data[2], data[3], data[10]);
    if (data[11] != 0)
        sub_81B3B40(gUnknown_0203CEF4, data[4] + data[9], data[5], data[6], data[7], data[11]);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_81B3D48(u8 taskId)
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

void sub_81B3E60(u8 taskId)
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

void oamt_swap_pos(u8 *spriteIdPtr1, u8 *spriteIdPtr2)
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

void swap_pokemon_and_oams(void)
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

void sub_81B407C(u8 taskId)
{
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    gUnknown_0203CEC8.unkB = 0;
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 0);
    gUnknown_0203CEC8.unk9 = gUnknown_0203CEC8.unkA;
    sub_81B0FCC(gUnknown_0203CEC8.unkA, 1);
    display_pokemon_menu_message(0);
    gTasks[taskId].func = sub_81B1370;
}

void brm_cancel_1(u8 taskId)
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

void sub_81B4134(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, 8);
    sub_81B31B0(1);
    display_pokemon_menu_message(24);
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = sub_81B3730;
}

void sub_81B4198(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC4->exitCallback = sub_81B41C4;
    sub_81B12C0(taskId);
}

void sub_81B41C4(void)
{
    if (InBattlePyramid() == FALSE)
        GoToBagMenu(RETURN_LOCATION_POKEMON_LIST, POCKETS_COUNT, c2_8123744);
    else
        sub_81C4F98(2, c2_8123744);
}

void c2_8123744(void)
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

void sub_81B42D0(u8 taskId)
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

void sub_81B4350(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sub_81B1D1C(&gPlayerParty[gUnknown_0203CEC8.unk9], gUnknown_0203CEFC, 1);
        gTasks[taskId].func = sub_81B43A8;
    }
}

void sub_81B43A8(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B43DC;
    }
}

void sub_81B43DC(u8 taskId)
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

void sub_81B44FC(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        gUnknown_0203CEC4->exitCallback = sub_81B452C;
        sub_81B12C0(taskId);
    }
}

void sub_81B452C(void)
{
    u8 mail = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_MAIL);

    sub_811A20C(4, gSaveBlock1Ptr->mail[mail].words, sub_81B4578, 3);
}

void sub_81B4578(void)
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

void sub_81B4624(u8 taskId)
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

void sub_81B469C(u8 taskId)
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

void sub_81B4724(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    switch (sub_81B1E00(mon))
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

void sub_81B47E0(u8 taskId)
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

void sub_81B48A8(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B48DC;
    }
}

void sub_81B48DC(u8 taskId)
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

void sub_81B4988(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 itemClear;

    if (sub_81B1BD4() != TRUE)
    {
        itemClear = ITEM_NONE;
        SetMonData(mon, MON_DATA_HELD_ITEM, &itemClear);
        sub_81B5C94(mon, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9]);
        DisplayPartyPokemonOtherText(12, &gUnknown_0203CEDC[gUnknown_0203CEC8.unk9], 1);
        gTasks[taskId].func = sub_81B1C1C;
    }
}

void sub_81B4A08(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B33B4(gPlayerParty, gUnknown_0203CEC8.unk9, 9);
    sub_81B31B0(2);
    display_pokemon_menu_message(25);
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = sub_81B3730;
}

void sub_81B4A6C(u8 taskId)
{
    PlaySE(SE_SELECT);
    gUnknown_0203CEC4->exitCallback = sub_81B4A98;
    sub_81B12C0(taskId);
}

void sub_81B4A98(void)
{
    ReadMail(&gSaveBlock1Ptr->mail[GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_MAIL)], sub_81B4AE0, 1);
}

void sub_81B4AE0(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    InitPartyMenu(gUnknown_0203CEC8.unk8_0, 0xFF, gUnknown_0203CEC8.unkB, 1, 21, sub_81B36FC, gUnknown_0203CEC8.exitCallback);
}

void brm_take_2(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    sub_81B1B5C(gText_SendMailToPC, 1);
    gTasks[taskId].func = sub_81B4B6C;
}

void sub_81B4B6C(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B4BA0;
    }
}

void sub_81B4BA0(u8 taskId)
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

void sub_81B4C60(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B4C94;
    }
}

void sub_81B4C94(u8 taskId)
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

void sub_81B4D78(u8 taskId)
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
    gTasks[taskId].func = sub_81B3730;
}

void brm_shift_sendout(u8 taskId)
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

void sub_81B4E8C(u8 taskId)
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

void sub_81B4F88(void)
{
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 0);
    gUnknown_0203CEC8.unk9 = 6;
    sub_81B0FCC(gUnknown_0203CEC8.unk9, 1);
}

void sub_81B4FA8(u8 taskId)
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

void sub_81B50AC(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B12C0(taskId);
}

void sub_81B50C8(u8 taskId)
{
    u16 species2 = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES2);
    u16 species = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES);
    u8 obedience = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_OBEDIENCE);

    switch (sub_807A8D0(*(u32 *)sub_800F7DC() /* dirty cast, probably needs to be changed */, species2, species, obedience))
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

void brm_trade_1(u8 taskId)
{
    u16 species2 = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES2);
    u16 species = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES);
    u8 obedience = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_OBEDIENCE);
    u32 stringId = sub_807A7E0(*(u32 *)sub_800F7DC() /* dirty cast, probably needs to be changed */, *(u32 *)&gUnknown_02022C38 /* dirty cast, probably needs to be changed */, species2, gUnknown_02022C3C, gUnknown_02022C3E, species, obedience);

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

void sub_81B52E4(u8 taskId)
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

void sub_81B53FC(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B5430;
    }
}

void sub_81B5430(u8 taskId)
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

void sub_81B5470(u8 taskId)
{
    u8 fieldMove = gUnknown_0203CEC4->unkF[Menu_GetCursorPos()] - 19;
    struct MapHeader const *mapHeader;
    u8 fieldMove2;

    PlaySE(SE_SELECT);
    if (gUnknown_08615D9C[fieldMove].fieldMoveFunc != NULL)
    {
        sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
        sub_81B302C(&gUnknown_0203CEC4->unkC[1]);
        if (sub_81221AC() == TRUE || InUnionRoom() == TRUE)
        {
            fieldMove2 = fieldMove - 11;
            if (fieldMove2 <= 1)
                display_pokemon_menu_message(13);
            else
                display_pokemon_menu_message(gUnknown_08615D9C[fieldMove].msgID);
            gTasks[taskId].func = task_brm_cancel_1_on_keypad_a_or_b;
        }
        else
        {
            if (fieldMove <= 7 && FlagGet(FLAG_BADGE01_GET + fieldMove) != TRUE)
            {
                sub_81B1B5C(gText_CantUseUntilNewBadge, 1);
                gTasks[taskId].func = sub_81B1C1C;
            }
            else if (gUnknown_08615D9C[fieldMove].fieldMoveFunc() == TRUE)
            {
                switch (fieldMove - 5)
                {
                    case 6:
                    case 7:
                        sub_8161560(taskId);
                        break;
                    case 3:
                        mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->lastHealLocation.mapGroup, gSaveBlock1Ptr->lastHealLocation.mapNum);
                        sub_81245DC(gStringVar1, mapHeader->regionMapSectionId);
                        StringExpandPlaceholders(gStringVar4, gText_ReturnToHealingSpot);
                        sub_81B5674(taskId);
                        gUnknown_0203CEC4->data[0] = fieldMove;
                        break;
                    case 4:
                        mapHeader = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->warp4.mapGroup, gSaveBlock1Ptr->warp4.mapNum);
                        sub_81245DC(gStringVar1, mapHeader->regionMapSectionId);
                        StringExpandPlaceholders(gStringVar4, gText_EscapeFromHere);
                        sub_81B5674(taskId);
                        gUnknown_0203CEC4->data[0] = fieldMove;
                        break;
                    case 0:
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
                    case 4:
                        sub_81B5864();
                        break;
                    case 1:
                        sub_81B57DC();
                        break;
                    default:
                        display_pokemon_menu_message(gUnknown_08615D9C[fieldMove].msgID);
                        break;
                }
                gTasks[taskId].func = task_brm_cancel_1_on_keypad_a_or_b;
            }
        }
    }
}

void sub_81B5674(u8 taskId)
{
    sub_81B1B5C(gStringVar4, 1);
    gTasks[taskId].func = sub_81B56A4;
}

void sub_81B56A4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B56D8;
    }
}

void sub_81B56D8(u8 taskId)
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

void task_launch_hm_phase_2(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        gFieldEffectArguments[0] = brm_get_selected_species();
        gPostMenuFieldCallback();
        DestroyTask(taskId);
    }
}

u16 brm_get_selected_species(void)
{
    return GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_SPECIES);
}

void task_brm_cancel_1_on_keypad_a_or_b(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
        brm_cancel_1(taskId);
}

void sub_81B57DC(void)
{
    if (FlagGet(FLAG_SYS_USE_FLASH) == TRUE)
        display_pokemon_menu_message(12);
    else
        display_pokemon_menu_message(13);
}

void hm_surf_run_dp02scr(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_SURF);
}

bool8 sub_81B5820(void)
{
    if (PartyHasMonWithSurf() == TRUE && IsPlayerFacingSurfableFishableWater() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = hm_surf_run_dp02scr;
        return TRUE;
    }
    return FALSE;
}

void sub_81B5864(void)
{
    if (TestPlayerAvatarFlags(8))
        display_pokemon_menu_message(9);
    else
        display_pokemon_menu_message(8);
}

bool8 sub_81B5884(void)
{
    if (Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
        return TRUE;
    return FALSE;
}

void sub_81B58A8(void)
{
    InitPartyMenu(0, 0, 0, 1, 0, sub_81B1370, CB2_ReturnToFieldWithOpenMenu);
}

void hm2_waterfall(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_WATERFALL);
}

bool8 hm_prepare_waterfall(void)
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

void sub_81B5958(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_DIVE);
}

bool8 sub_81B5974(void)
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

void party_menu_icon_anim(struct Pokemon *mon, struct Struct203CEDC *ptr, u32 a)
{
    u32 bit = 1;
    u16 species2;

    if (IsMultiBattle() == TRUE && gMain.inBattle)
        bit = (gUnknown_08616020[a] ^ bit) ? 1 : 0;
    species2 = GetMonData(mon, MON_DATA_SPECIES2);
    party_menu_link_mon_icon_anim(species2, GetMonData(mon, MON_DATA_PERSONALITY), ptr, 1, bit);
    sub_81B5B38(ptr->unk9, mon);
}

void party_menu_link_mon_icon_anim(u16 species, u32 pid, struct Struct203CEDC *ptr, u8 priority, u32 bit)
{
    if (species != SPECIES_NONE)
    {
        ptr->unk9 = CreateMonIcon(species, sub_80D3014, ptr->unk4[0], ptr->unk4[1], 4, pid, bit);
        gSprites[ptr->unk9].oam.priority = priority;
    }
}

void sub_81B5A8C(u8 spriteId, u16 hp, u16 maxhp)
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

void sub_81B5B38(u8 spriteId, struct Pokemon *mon)
{
    sub_81B5A8C(spriteId, GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP));
}

void AnimateSelectedPartyIcon(u8 spriteId, u8 a)
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

void UpdatePartyMonIconFrameAndBounce(struct Sprite *sprite)
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

void UpdatePartyMonIconFrame(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

void party_menu_held_item_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        ptr->unkA = CreateSprite(&gSpriteTemplate_8615EC0, ptr->unk4[2], ptr->unk4[3], 0);
        sub_81B5C94(mon, ptr);
    }
}

void party_menu_link_mon_held_item_object(u16 species, u16 item, struct Struct203CEDC *ptr)
{
    if (species != SPECIES_NONE)
    {
        ptr->unkA = CreateSprite(&gSpriteTemplate_8615EC0, ptr->unk4[2], ptr->unk4[3], 0);
        gSprites[ptr->unkA].oam.priority = 0;
        sub_81B5CB0(item, ptr);
    }
}

void sub_81B5C94(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    sub_81B5CB0(GetMonData(mon, MON_DATA_HELD_ITEM), ptr);
}

void sub_81B5CB0(u16 item, struct Struct203CEDC *ptr)
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

void sub_81B5DF0(u8 spriteId, u8 isMail)
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

void sub_81B5E74(struct Sprite *sprite)
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

void party_menu_pokeball_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
        ptr->unkB = CreateSprite(&gSpriteTemplate_8615F08, ptr->unk4[6], ptr->unk4[7], 8);
}

void party_menu_link_mon_pokeball_object(u16 species, struct Struct203CEDC *ptr)
{
    if (species != SPECIES_NONE)
    {
        ptr->unkB = CreateSprite(&gSpriteTemplate_8615F08, ptr->unk4[6], ptr->unk4[7], 8);
        gSprites[ptr->unkB].oam.priority = 0;
    }
}

u8 sub_81B5F34(u8 x, u8 y)
{
    u8 spriteId = CreateSprite(&gSpriteTemplate_8615F08, x, y, 8);

    gSprites[spriteId].oam.priority = 2;
    return spriteId;
}

u8 sub_81B5F74(u8 x, u8 y)
{
    return CreateSprite(&gSpriteTemplate_8615F78, x, y, 8);
}

void sub_81B5F98(u8 spriteId, u8 a)
{
    StartSpriteAnim(&gSprites[spriteId], a);
}

void sub_81B5FBC(u8 spriteId, u8 spriteId2, u8 a)
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

void LoadPartyMenuPokeballGfx(void)
{
    LoadCompressedSpriteSheet(&gUnknown_08615EF8);
    LoadCompressedSpriteSheet(&gUnknown_08615F70);
    LoadCompressedSpritePalette(&gUnknown_08615F00);
}

void party_menu_status_condition_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        ptr->unkC = CreateSprite(&gSpriteTemplate_8616008, ptr->unk4[4], ptr->unk4[5], 0);
        party_menu_get_status_condition_and_update_object(mon, ptr);
    }
}

void party_menu_link_mon_status_condition_object(u16 species, u8 status, struct Struct203CEDC *ptr)
{
    if (species != SPECIES_NONE)
    {
        ptr->unkC = CreateSprite(&gSpriteTemplate_8616008, ptr->unk4[4], ptr->unk4[5], 0);
        party_menu_update_status_condition_object(status, ptr);
        gSprites[ptr->unkC].oam.priority = 0;
    }
}

void party_menu_get_status_condition_and_update_object(struct Pokemon *mon, struct Struct203CEDC *ptr)
{
    party_menu_update_status_condition_object(sub_81B205C(mon), ptr);
}

void party_menu_update_status_condition_object(u8 status, struct Struct203CEDC *ptr)
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

void LoadPartyMenuAilmentGfx(void)
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
    u8 msgIDMaybe;
    register TaskFunc task asm("r0");

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
    if (GetItemEffectType(gSpecialVar_ItemId) == 10)
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
        msgIDMaybe = 0x7F;
    }
    else
    {
        msgIDMaybe = (GetPocketByItemId(gSpecialVar_ItemId) == POCKET_TM_HM) ? 4 : 5;
        task = sub_81B1370;
    }
    InitPartyMenu(inBattle, doubleBattleStatus, 3, 1, msgIDMaybe, task, callback);
}

void c2_815ABFC(void)
{
    if (InBattlePyramid() == FALSE)
        GoToBagMenu(RETURN_LOCATION_UNCHANGED, POCKETS_COUNT, NULL);
    else
        sub_81C4F98(4, gPyramidBagCursorData.callback);
}

void sub_81B6280(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203CEC8.unk8_0 == 1)
            gUnknown_0203CEC4->exitCallback = sub_81B9140;
        gUnknown_03006328(taskId, sub_81B6794);
    }
}

bool8 IsHPRecoveryItem(u16 item)
{
    const u8 *effect;

    if (item == ITEM_ENIGMA_BERRY)
        effect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    else
        effect = gItemEffectTable[item - ITEM_POTION];
    if ((effect[4] & 4) != 0)
        return TRUE;
    return FALSE;
}

void GetMedicineItemEffectMessage(u16 item)
{
    switch (GetItemEffectType(item) - 3)
    {
        case 0:
            StringExpandPlaceholders(gStringVar4, gText_PkmnCuredOfPoison);
            break;
        case 1:
            StringExpandPlaceholders(gStringVar4, gText_PkmnWokeUp2);
            break;
        case 2:
            StringExpandPlaceholders(gStringVar4, gText_PkmnBurnHealed);
            break;
        case 3:
            StringExpandPlaceholders(gStringVar4, gText_PkmnThawedOut);
            break;
        case 4:
            StringExpandPlaceholders(gStringVar4, gText_PkmnCuredOfParalysis);
            break;
        case 5:
            StringExpandPlaceholders(gStringVar4, gText_PkmnSnappedOutOfConfusion);
            break;
        case 6:
            StringExpandPlaceholders(gStringVar4, gText_PkmnGotOverInfatuation);
            break;
        case 8:
            StringExpandPlaceholders(gStringVar4, gText_PkmnBecameHealthy);
            break;
        case 10:
            StringCopy(gStringVar2, gText_HP3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
            break;
        case 9:
            StringCopy(gStringVar2, gText_Attack3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
            break;
        case 14:
            StringCopy(gStringVar2, gText_Defense3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
            break;
        case 13:
            StringCopy(gStringVar2, gText_Speed2);
            StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
            break;
        case 11:
            StringCopy(gStringVar2, gText_SpAtk3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
            break;
        case 12:
            StringCopy(gStringVar2, gText_SpDef3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
            break;
        case 16:
        case 17:
            StringExpandPlaceholders(gStringVar4, gText_MovesPPIncreased);
            break;
        case 18:
            StringExpandPlaceholders(gStringVar4, gText_PPWasRestored);
            break;
        default:
            StringExpandPlaceholders(gStringVar4, gText_WontHaveEffect);
            break;
    }
}

bool8 UsingHPEVItemOnShedinja(struct Pokemon *mon, u16 item)
{
    if (GetItemEffectType(item) == 13 && GetMonData(mon, MON_DATA_SPECIES) == SPECIES_SHEDINJA)
        return FALSE;
    return TRUE;
}

bool8 IsBlueYellowRedFlute(u16 item)
{
    if (item == ITEM_BLUE_FLUTE || item == ITEM_RED_FLUTE || item == ITEM_YELLOW_FLUTE)
        return TRUE;
    return FALSE;
}

bool8 ExecuteTableBasedItemEffect__(u8 partyMonIndex, u16 item, u8 monMoveIndex)
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
    if (IsBlueYellowRedFlute(item) == FALSE)
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

void sub_81B672C(u8 taskId)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
    sub_81B1B5C(gStringVar4, 0);
    schedule_bg_copy_tilemap_to_vram(2);
    HandleBattleLowHpMusicChange();
    gTasks[taskId].func = sub_81B6794;
}

void sub_81B6794(u8 taskId)
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
    u16 relevantEV = sub_81B691C(mon, effectType);
    bool8 cannotUseEffect = ExecuteTableBasedItemEffect__(gUnknown_0203CEC8.unk9, item, 0);
    u16 newFriendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 newRelevantEV = sub_81B691C(mon, effectType);

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
        option_menu_get_string(effectType, gStringVar2);
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

u16 sub_81B691C(struct Pokemon *mon, u8 effectType)
{
    switch (effectType)
    {
        case 13:
            if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_SHEDINJA)
                return GetMonData(mon, MON_DATA_HP_EV);
            break;
        case 12:
            return GetMonData(mon, MON_DATA_ATK_EV);
        case 17:
            return GetMonData(mon, MON_DATA_DEF_EV);
        case 16:
            return GetMonData(mon, MON_DATA_SPEED_EV);
        case 14:
            return GetMonData(mon, MON_DATA_SPATK_EV);
        case 15:
            return GetMonData(mon, MON_DATA_SPDEF_EV);
    }
    return 0;
}

void option_menu_get_string(u8 effectType, u8 *dest)
{
    switch (effectType)
    {
        case 13:
            StringCopy(dest, gText_HP3);
            break;
        case 12:
            StringCopy(dest, gText_Attack3);
            break;
        case 17:
            StringCopy(dest, gText_Defense3);
            break;
        case 16:
            StringCopy(dest, gText_Speed2);
            break;
        case 14:
            StringCopy(dest, gText_SpAtk3);
            break;
        case 15:
            StringCopy(dest, gText_SpDef3);
            break;
    }
}

void sub_81B6A10(u8 slot)
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

void ether_effect_related_3(u8 taskId)
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

void dp05_ether(u8 taskId, TaskFunc unused)
{
    const u8 *effect;
    u16 item = gSpecialVar_ItemId;

    if (item == ITEM_ENIGMA_BERRY)
        effect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    else
        effect = gItemEffectTable[item - ITEM_POTION];
    if ((effect[4] & 0x10) == 0)
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

void ether_effect_related_2(u8 taskId)
{
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    gUnknown_0203CEC8.unkE = Menu_GetCursorPos();
    ether_effect_related(taskId);
}

void sub_81B6BB4(u8 taskId)
{
    gTasks[taskId].func = sub_81B1370;
    gUnknown_0203CEC4->exitCallback = NULL;
    sub_81B302C(&gUnknown_0203CEC4->unkC[0]);
    display_pokemon_menu_message(5);
}

void ether_effect_related(u8 taskId)
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

void dp05_pp_up(u8 taskId, TaskFunc unused)
{
    PlaySE(SE_SELECT);
    display_pokemon_menu_message(23);
    sub_81B6A10(gUnknown_0203CEC8.unk9);
    gTasks[taskId].func = ether_effect_related_3;
}

u16 ItemIdToBattleMoveId(u16 item)
{
    u16 tmNumber = item - ITEM_TM01_FOCUS_PUNCH;
    return gUnknown_08616040[tmNumber];
}

bool8 sub_81B6D14(u16 move)
{
    u8 i;

    for (i = 0; i < NUM_HIDDEN_MACHINES; i++)
    {
        if (gUnknown_08616040[i + NUM_TECHNICAL_MACHINES] == move)
            return TRUE;
    }
    return FALSE;
}

bool8 pokemon_has_move(struct Pokemon *mon, u16 move)
{
    u8 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetMonData(mon, MON_DATA_MOVE1 + i) == move)
            return TRUE;
    }
    return FALSE;
}

void sub_81B6D74(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B6D98(u8 taskId, const u8 *str)
{
    sub_81B6D74(str);
    gTasks[taskId].func = sub_81B6794;
}

// move[1] doesn't use constants cause I don't know if it's actually a move ID storage

void sub_81B6DC4(u8 taskId, TaskFunc unused)
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
    switch (CanPartyPokemonLearnTMTutor(mon, item, 0))
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

void sub_81B6EB4(u8 taskId)
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

void sub_81B6F60(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        PlayFanfare(MUS_FANFA1);
        gTasks[taskId].func = sub_81B6F98;
    }
}

void sub_81B6F98(u8 taskId)
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

void sub_81B6FF4(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B7028;
    }
}

void sub_81B7028(u8 taskId)
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

void sub_81B7088(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        gUnknown_0203CEC4->exitCallback = sub_81B70B8;
        sub_81B12C0(taskId);
    }
}

void sub_81B70B8(void)
{
    ShowSelectMovePokemonSummaryScreen(gPlayerParty, gUnknown_0203CEC8.unk9, gPlayerPartyCount - 1, sub_81B70F0, gUnknown_0203CEC8.unkE);
}

void sub_81B70F0(void)
{
    InitPartyMenu(0, 0, 0, 1, 0x7F, sub_81B711C, gUnknown_0203CEC8.exitCallback);
}

void sub_81B711C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sub_81C1B94() != 4)
            sub_81B7154(taskId);
        else
            sub_81B7230(taskId);
    }
}

void sub_81B7154(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 move = GetMonData(mon, MON_DATA_MOVE1 + sub_81C1B94());

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);
    sub_81B6D74(gText_12PoofForgotMove);
    gTasks[taskId].func = sub_81B71D4;
}

void sub_81B71D4(u8 taskId)
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

void sub_81B7230(u8 taskId)
{
    StringCopy(gStringVar2, gMoveNames[gUnknown_0203CEC8.unkE]);
    StringExpandPlaceholders(gStringVar4, gText_StopLearningMove2);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B7294;
}

void sub_81B7294(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B72C8;
    }
}

void sub_81B72C8(u8 taskId)
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

void sub_81B73E4(u8 taskId)
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

void sub_81B754C(u8 slot, struct Pokemon *mon)
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

void sub_81B75D4(u8 taskId)
{
    if (WaitFanfare(FALSE) && sub_81B1BD4() != TRUE && ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON)))
    {
        PlaySE(SE_SELECT);
        sub_81B767C(taskId);
        gTasks[taskId].func = sub_81B7634;
    }
}

void sub_81B7634(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sub_81B76C8(taskId);
        gTasks[taskId].func = sub_81B7704;
    }
}

void sub_81B767C(u8 taskId)
{
    s16 *arrayPtr = gUnknown_0203CEC4->data;

    arrayPtr[12] = sub_81B3364();
    sub_81D3640(arrayPtr[12], arrayPtr, &arrayPtr[6], 1, 2, 3);
    CopyWindowToVram(arrayPtr[12], 2);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B76C8(u8 taskIdUnused)
{
    s16 *arrayPtr = gUnknown_0203CEC4->data;

    sub_81D3784(arrayPtr[12], &arrayPtr[6], 1, 2, 3);
    CopyWindowToVram(arrayPtr[12], 2);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81B7704(u8 taskId)
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

void sub_81B77AC(u8 taskId)
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

void sub_81B7810(u8 taskId)
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

void sub_81B787C(u8 taskId)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
    StringCopy(gStringVar2, gMoveNames[gMoveToLearn]);
    StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gUnknown_0203CEC8.unkE = gMoveToLearn;
    gTasks[taskId].func = sub_81B6FF4;
}

void sub_81B7910(u8 taskId, u16 move)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unk9], gStringVar1);
    StringCopy(gStringVar2, gMoveNames[move]);
    StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
    sub_81B1B5C(gStringVar4, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gUnknown_0203CEC8.unkE = move;
    gTasks[taskId].func = sub_81B6F60;
}

void sub_81B79A0(struct Pokemon *mon, s16 *data)
{
    data[0] = GetMonData(mon, MON_DATA_MAX_HP);
    data[1] = GetMonData(mon, MON_DATA_ATK);
    data[2] = GetMonData(mon, MON_DATA_DEF);
    data[4] = GetMonData(mon, MON_DATA_SPATK);
    data[5] = GetMonData(mon, MON_DATA_SPDEF);
    data[3] = GetMonData(mon, MON_DATA_SPEED);
}

void sub_81B79E8(u8 taskId, TaskFunc unused)
{
    gUnknown_0203CEC4->data[0] = 0;
    gUnknown_0203CEC4->data[1] = 0;
    gUnknown_0203CEC4->data[2] = gUnknown_0203CEC8.unk9;
    sub_81B7A28(taskId);
}

#ifdef NONMATCHING
void sub_81B7A28(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
    u16 hp;

    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        hp = GetMonData(mon, MON_DATA_HP);
        if (ExecuteTableBasedItemEffect__(gUnknown_0203CEC8.unk9, gSpecialVar_ItemId, 0))
        {
            gTasks[taskId].func = task_sacred_ash_party_loop;
            return;
        }
    }
    else
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
#else
NAKED
void sub_81B7A28(u8 taskId)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0x4\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	mov r8, r4\n\
	ldr r6, =gUnknown_0203CEC8\n\
	movs r1, 0x9\n\
	ldrsb r1, [r6, r1]\n\
	movs r0, 0x64\n\
	muls r1, r0\n\
	ldr r0, =gPlayerParty\n\
	adds r5, r1, r0\n\
	adds r0, r5, 0\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r0, 0\n\
	beq _081B7A6E\n\
	adds r0, r5, 0\n\
	movs r1, 0x39\n\
	bl GetMonData\n\
	lsls r0, 16\n\
	lsrs r7, r0, 16\n\
	ldrb r0, [r6, 0x9]\n\
	ldr r1, =gSpecialVar_ItemId\n\
	ldrh r1, [r1]\n\
	movs r2, 0\n\
	bl ExecuteTableBasedItemEffect__\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _081B7A94\n\
_081B7A6E:\n\
	ldr r0, =gTasks\n\
	lsls r1, r4, 2\n\
	adds r1, r4\n\
	lsls r1, 3\n\
	adds r1, r0\n\
	ldr r0, =task_sacred_ash_party_loop\n\
	str r0, [r1]\n\
	b _081B7B2A\n\
	.pool\n\
_081B7A94:\n\
	movs r0, 0x1\n\
	bl PlaySE\n\
	ldr r4, =gUnknown_0203CEDC\n\
	movs r0, 0x9\n\
	ldrsb r0, [r6, r0]\n\
	lsls r0, 4\n\
	ldr r1, [r4]\n\
	adds r1, r0\n\
	adds r0, r5, 0\n\
	bl party_menu_get_status_condition_and_update_object\n\
	ldr r2, =gSprites\n\
	movs r0, 0x9\n\
	ldrsb r0, [r6, r0]\n\
	ldr r1, [r4]\n\
	lsls r0, 4\n\
	adds r3, r0, r1\n\
	ldrb r1, [r3, 0xC]\n\
	lsls r0, r1, 4\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r0, r2\n\
	adds r0, 0x3E\n\
	ldrb r0, [r0]\n\
	lsls r0, 29\n\
	cmp r0, 0\n\
	bge _081B7AD6\n\
	adds r0, r5, 0\n\
	adds r1, r3, 0\n\
	movs r2, 0x1\n\
	bl DisplayPartyPokemonLevelCheck\n\
_081B7AD6:\n\
	ldr r4, =gUnknown_0203CEC4\n\
	ldr r0, [r4]\n\
	movs r1, 0x87\n\
	lsls r1, 2\n\
	adds r0, r1\n\
	ldrb r0, [r0]\n\
	movs r1, 0\n\
	bl sub_81B0FCC\n\
	ldrb r0, [r6, 0x9]\n\
	movs r1, 0x1\n\
	bl sub_81B0FCC\n\
	adds r0, r5, 0\n\
	movs r1, 0x39\n\
	bl GetMonData\n\
	adds r3, r0, 0\n\
	subs r3, r7\n\
	lsls r3, 16\n\
	asrs r3, 16\n\
	ldrb r1, [r6, 0x9]\n\
	ldr r0, =sub_81B7C10\n\
	str r0, [sp]\n\
	mov r0, r8\n\
	movs r2, 0x1\n\
	bl sub_81B1F18\n\
	mov r0, r8\n\
	movs r1, 0\n\
	adds r2, r7, 0\n\
	bl sub_81B1FA8\n\
	ldr r0, [r4]\n\
	movs r2, 0x86\n\
	lsls r2, 2\n\
	adds r1, r0, r2\n\
	movs r2, 0x1\n\
	strh r2, [r1]\n\
	ldr r1, =0x0000021a\n\
	adds r0, r1\n\
	strh r2, [r0]\n\
_081B7B2A:\n\
	add sp, 0x4\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

void task_sacred_ash_party_loop(u8 taskId)
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

void sub_81B7C10(u8 taskId)
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
#ifndef NONMATCHING
    register u8 itemEffect0 asm("r1");
    register u8 itemEffect3 asm("r3");
    register u32 itemEffect0_r0 asm("r0"); // u32 to prevent shifting when transferring itemEffect0 to this
    u8 mask;
#else
#define itemEffect0 itemEffect[0]
#define itemEffect3 itemEffect[3]
#define mask 0x3F
#endif

    if (!IS_POKEMON_ITEM(item))
    {
        return 22;
    }
    else
    {
        // Read the item's effect properties.
        if (item == ITEM_ENIGMA_BERRY)
        {
            itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
        }
        else
        {
            itemEffect = gItemEffectTable[item - ITEM_POTION];
        }

#ifndef NONMATCHING
        itemEffect0 = itemEffect[0];
        mask = 0x3F;
#endif

        if ((itemEffect0 & mask) || itemEffect[1] || itemEffect[2])
        {
            return 0;
        }
#ifndef NONMATCHING
        itemEffect3 = itemEffect[3];
#endif
        if (itemEffect3 & 0x80)
        {
            return 0;
        }
        else if (itemEffect0 & 0x40)
        {
            return 10;
        }
        else if (itemEffect3 & 0x40)
        {
            return 1;
        }
        else if ((itemEffect3 & mask) || (itemEffect0 >> 7))
        {
            if ((itemEffect3 & mask) == 0x20)
            {
                return 4;
            }
            else if ((itemEffect3 & mask) == 0x10)
            {
                return 3;
            }
            else if ((itemEffect3 & mask) == 0x8)
            {
                return 5;
            }
            else if ((itemEffect3 & mask) == 0x4)
            {
                return 6;
            }
            else if ((itemEffect3 & mask) == 0x2)
            {
                return 7;
            }
            else if ((itemEffect3 & mask) == 0x1)
            {
                return 8;
            }
            // alternate fakematching
            // itemEffect0_r0 = itemEffect0 >> 7;
            // asm(""); // increase live length for greg
            // if ((itemEffect0_r0 != 0) && (itemEffect3 & mask) == 0)
#ifndef NONMATCHING
            else if (((itemEffect0_r0 = itemEffect0 >> 7) != 0) && (itemEffect3 & mask) == 0)
#else
            else if (((itemEffect[0] >> 7) != 0) && (itemEffect[3] & 0x3F) == 0)
#endif
            {
                return 9;
            }
            else
            {
                return 11;
            }
        }
        else if (itemEffect[4] & 0x44)
        {
            return 2;
        }
        else if (itemEffect[4] & 0x2)
        {
            return 12;
        }
        else if (itemEffect[4] & 0x1)
        {
            return 13;
        }
        else if (itemEffect[5] & 0x8)
        {
            return 14;
        }
        else if (itemEffect[5] & 0x4)
        {
            return 15;
        }
        else if (itemEffect[5] & 0x2)
        {
            return 16;
        }
        else if (itemEffect[5] & 0x1)
        {
            return 17;
        }
        else if (itemEffect[4] & 0x80)
        {
            return 18;
        }
        else if (itemEffect[4] & 0x20)
        {
            return 19;
        }
        else if (itemEffect[5] & 0x10)
        {
            return 20;
        }
        else if (itemEffect[4] & 0x18)
        {
            return 21;
        }
        return 22;
    }
#ifdef NONMATCHING
#undef itemEffect0
#undef itemEffect3
#undef mask
#endif
}

void sub_81B7E4C(u8 taskId)
{
    struct Pokemon *mon;
    s16 *move;

    if (!gPaletteFade.active)
    {
        mon = &gPlayerParty[gUnknown_0203CEC8.unk9];
        move = &gUnknown_0203CEC8.unkE;
        GetMonNickname(mon, gStringVar1);
        gUnknown_0203CEC8.unkE = sub_81B2360(gSpecialVar_0x8005);
        StringCopy(gStringVar2, gMoveNames[gUnknown_0203CEC8.unkE]);
        move[1] = 2;
        switch (CanPartyPokemonLearnTMTutor(mon, 0, gSpecialVar_0x8005))
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

void sub_81B7FAC(u8 taskId)
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

void sub_81B8044(u8 taskId)
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

void sub_81B8088(u8 taskId)
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

void sub_81B8104(u8 taskId)
{
    s8 slot = gUnknown_0203CEC8.unk9;

    if (sub_81B1BD4() != TRUE)
    {
        sub_81B5C94(&gPlayerParty[slot], &gUnknown_0203CEDC[slot]);
        sub_81B12C0(taskId);
    }
}

void sub_81B814C(void)
{
    u8 mail;

    sub_81B1DB8(&gPlayerParty[gUnknown_0203CEC8.unk9], gUnknown_0203CEC8.unkC);
    mail = GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_MAIL);
    sub_811A20C(4, gSaveBlock1Ptr->mail[mail].words, sub_81B81A8, 3);
}

void sub_81B81A8(void)
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

void sub_81B8230(u8 taskId)
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

void sub_81B82A0(u8 taskId)
{
    if (sub_81B1BD4() != TRUE)
    {
        sub_81B334C();
        gTasks[taskId].func = sub_81B82D4;
    }
}

void sub_81B82D4(u8 taskId)
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

void sub_81B83B8(u8 taskId)
{
    sub_81B1B5C(gText_RemoveMailBeforeItem, 1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81B8104;
}

void sub_81B83F0(u16 item)
{
    if (gUnknown_0203CEC8.unkB == 6)
        RemovePCItem(item, 1);
    else
        RemoveBagItem(item, 1);
}

bool8 sub_81B841C(u16 item)
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

void sub_81B8474(u8 taskId)
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

void sub_81B8518(u8 unused)
{
    sub_81B8558();
    InitPartyMenu(4, 0, 0, 0, 0, sub_81B1370, gMain.savedCallback);
    gUnknown_0203CEC8.unk4 = sub_81B879C;
}

void sub_81B8558(void)
{
    memset(gSelectedOrderFromParty, 0, ARRAY_COUNT(gSelectedOrderFromParty));
}

u8 sub_81B856C(s8 slot)
{
    if (GetBattleEntryEligibility(&gPlayerParty[slot]) == FALSE)
        return 2;
    if (sub_81B8770(slot + 1) == TRUE)
        return 1;
    return 0;
}

bool8 GetBattleEntryEligibility(struct Pokemon *mon)
{
    u16 i = 0;
    u16 species;

    if (GetMonData(mon, MON_DATA_IS_EGG) || GetMonData(mon, MON_DATA_LEVEL) > sub_81B8888() ||
    (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY) &&
    gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY) &&
    GetMonData(mon, MON_DATA_HELD_ITEM) != ITEM_NONE))
        return FALSE;
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

#ifdef NONMATCHING
u8 sub_81B865C(void)
{
    u8 unk = sub_81B885C();
    u8 unk2;
    u8 i, j;
    u16 species;
    u16 item;
    u8 facilityNum;

    if (gSelectedOrderFromParty[unk - 1] == 0)
    {
        if (unk == 1)
            return 14;
        ConvertIntToDecimalStringN(gStringVar1, unk, 0, 1);
        return 17;
    }
    facilityNum = VarGet(VAR_FRONTIER_FACILITY);
    if (facilityNum != 8 && facilityNum != 9)
    {
        unk2 = sub_81B8830();
        for (i = 0; i < (unk2 - 1); i++)
        {
            species = GetMonData(&gPlayerParty[gSelectedOrderFromParty[i - 1]], MON_DATA_SPECIES);
            item = GetMonData(&gPlayerParty[gSelectedOrderFromParty[i - 1]], MON_DATA_HELD_ITEM);
            for (j = i + 1; j < unk2; j++)
            {
                if (species == GetMonData(&gPlayerParty[gSelectedOrderFromParty[j - 1]], MON_DATA_SPECIES))
                    return 18;
                if (item != ITEM_NONE && item == GetMonData(&gPlayerParty[gSelectedOrderFromParty[j - 1]], MON_DATA_HELD_ITEM))
                    return 19;
            }
        }
    }
    return 0xFF;
}
#else
NAKED
u8 sub_81B865C(void)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	bl sub_81B885C\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	adds r1, r2, 0\n\
	ldr r3, =gSelectedOrderFromParty\n\
	adds r0, r2, r3\n\
	subs r0, 0x1\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	bne _081B869C\n\
	cmp r2, 0x1\n\
	bne _081B8688\n\
	movs r0, 0xE\n\
	b _081B8758\n\
	.pool\n\
_081B8688:\n\
	ldr r0, =gStringVar1\n\
	movs r2, 0\n\
	movs r3, 0x1\n\
	bl ConvertIntToDecimalStringN\n\
	movs r0, 0x11\n\
	b _081B8758\n\
	.pool\n\
_081B869C:\n\
	ldr r0, =0x000040cf\n\
	bl VarGet\n\
	lsls r0, 24\n\
	movs r1, 0xF8\n\
	lsls r1, 24\n\
	adds r0, r1\n\
	lsrs r0, 24\n\
	cmp r0, 0x1\n\
	bhi _081B86C0\n\
	b _081B8756\n\
	.pool\n\
_081B86B8:\n\
	movs r0, 0x12\n\
	b _081B8758\n\
_081B86BC:\n\
	movs r0, 0x13\n\
	b _081B8758\n\
_081B86C0:\n\
	bl sub_81B8830\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r8, r0\n\
	movs r5, 0\n\
	b _081B8750\n\
_081B86CE:\n\
	ldr r3, =gSelectedOrderFromParty\n\
	adds r4, r3, r5\n\
	ldrb r0, [r4]\n\
	movs r1, 0x64\n\
	muls r0, r1\n\
	subs r0, 0x64\n\
	ldr r3, =gPlayerParty\n\
	adds r0, r3, r0\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	mov r10, r0\n\
	ldrb r0, [r4]\n\
	movs r1, 0x64\n\
	muls r0, r1\n\
	subs r0, 0x64\n\
	ldr r3, =gPlayerParty\n\
	adds r0, r3, r0\n\
	movs r1, 0xC\n\
	bl GetMonData\n\
	lsls r0, 16\n\
	lsrs r6, r0, 16\n\
	adds r1, r5, 0x1\n\
	lsls r0, r1, 24\n\
	lsrs r4, r0, 24\n\
	mov r9, r1\n\
	cmp r4, r8\n\
	bcs _081B8748\n\
	movs r7, 0x64\n\
_081B870E:\n\
	ldr r0, =gSelectedOrderFromParty\n\
	adds r5, r0, r4\n\
	ldrb r0, [r5]\n\
	muls r0, r7\n\
	subs r0, 0x64\n\
	ldr r1, =gPlayerParty\n\
	adds r0, r1, r0\n\
	movs r1, 0xB\n\
	bl GetMonData\n\
	cmp r10, r0\n\
	beq _081B86B8\n\
	cmp r6, 0\n\
	beq _081B873E\n\
	ldrb r0, [r5]\n\
	muls r0, r7\n\
	subs r0, 0x64\n\
	ldr r3, =gPlayerParty\n\
	adds r0, r3, r0\n\
	movs r1, 0xC\n\
	bl GetMonData\n\
	cmp r6, r0\n\
	beq _081B86BC\n\
_081B873E:\n\
	adds r0, r4, 0x1\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	cmp r4, r8\n\
	bcc _081B870E\n\
_081B8748:\n\
	mov r1, r9\n\
	lsls r0, r1, 24\n\
	lsrs r5, r0, 24\n\
	mov r0, r8\n\
_081B8750:\n\
	subs r0, 0x1\n\
	cmp r5, r0\n\
	blt _081B86CE\n\
_081B8756:\n\
	movs r0, 0xFF\n\
_081B8758:\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1\n\
	.pool\n");
}
#endif

bool8 sub_81B8770(u8 slot)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (gSelectedOrderFromParty[i] == slot)
            return TRUE;
    }
    return FALSE;
}

void sub_81B879C(u8 taskId)
{
    u8 msgID = sub_81B865C();

    if (msgID != 0xFF)
    {
        PlaySE(SE_HAZURE);
        display_pokemon_menu_message(msgID);
        gTasks[taskId].func = sub_81B87E8;
    }
    else
    {
        PlaySE(SE_SELECT);
        sub_81B12C0(taskId);
    }
}

void sub_81B87E8(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        display_pokemon_menu_message(0);
        gTasks[taskId].func = sub_81B1370;
    }
}

u8 sub_81B8830(void)
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

u8 sub_81B885C(void)
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

u8 sub_81B8888(void)
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

const u8* sub_81B88BC(void)
{
    u8 facilityNum = VarGet(VAR_FRONTIER_FACILITY);

    if (!(facilityNum != 8 && facilityNum != 9))
        return gText_CancelBattle;
    if (facilityNum == FRONTIER_FACILITY_DOME && gSpecialVar_0x8005 == 2)
        return gText_ReturnToWaitingRoom;
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

u8 sub_81B8984(void)
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

u8 sub_81B8A2C(struct Pokemon *mon)
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

bool8 sub_81B8A7C(void)
{
    u8 slot = GetCursorSelectionMonId();
    u8 newSlot;
    u8 i;
    u8 neededToMatch;

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
        neededToMatch = gBattlerInMenuId;
        GetMonNickname(&gPlayerParty[pokemon_order_func(gBattlerPartyIndexes[neededToMatch])], gStringVar1);
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

void sub_81B8C88(u8 *ptr, bool8 multiplayerFlag)
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

void sub_81B8D64(u8 battlerPosition, u8 multiplayerFlag)
{
    sub_81B8D88(gBattleStruct->field_60[battlerPosition], multiplayerFlag, battlerPosition);
}

void sub_81B8D88(u8 *ptr, bool8 multiplayerFlag, u8 battlerPosition)
{
    u8 partyIndexes[6];
    int i, j;
    u8 leftBattler;
    u8 rightBattler;

    if (GetBattlerSide(battlerPosition) == B_SIDE_PLAYER)
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

void sub_81B8E80(u8 battlerPosition, u8 unk, u8 arrayIndex)
{
    u8 possiblePartyIndexes[6];
    u8 unk2 = 0;
    int i, j;
    u8 *battleStructRelated;
    u8 possiblePartyIndexBuffer;

    if (IsMultiBattle())
    {
        battleStructRelated = gBattleStruct->field_60[battlerPosition];
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

u8 sub_81B8F38(u8 slot)
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

void sub_81B8F6C(u8 slot, u8 setVal)
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

void pokemon_change_order(void)
{
    struct Pokemon *partyBuffer = Alloc(sizeof(gPlayerParty));
    u8 i;

    memcpy(partyBuffer, gPlayerParty, sizeof(gPlayerParty));
    for (i = 0; i < PARTY_SIZE; i++)
        memcpy(&gPlayerParty[pokemon_order_func(i)], &partyBuffer[i], sizeof(struct Pokemon));
    Free(partyBuffer);
}

void sub_81B9080(void)
{
    struct Pokemon *partyBuffer = Alloc(sizeof(gPlayerParty));
    u8 i;

    memcpy(partyBuffer, gPlayerParty, sizeof(gPlayerParty));
    for (i = 0; i < PARTY_SIZE; i++)
        memcpy(&gPlayerParty[sub_81B8F38(i)], &partyBuffer[i], sizeof(struct Pokemon));
    Free(partyBuffer);
}

void sub_81B90D0(void)
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

void sub_81B9140(void)
{
    SetMainCallback2(SetCB2ToReshowScreenAfterMenu);
}

void sub_81B9150(void)
{
    InitPartyMenu(5, 3, 0, 0, 0x7F, sub_81B917C, gMain.savedCallback);
}

void sub_81B917C(u8 taskId)
{
    gTasks[taskId].data[0] = 256;
    sub_81B9294(taskId);
    ChangeBgX(2, 0x10000, 0);
    gTasks[taskId].func = sub_81B91B4;
}

void sub_81B91B4(u8 taskId)
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

void sub_81B9240(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (++data[0] == 0x100)
        sub_81B12C0(taskId);
}

void sub_81B9270(u8 spriteId, s16 x)
{
    if (x >= 0)
        gSprites[spriteId].pos2.x = x;
}

void sub_81B9294(u8 taskId)
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

void sub_81B9354(u8 arg1)
{
    gFieldCallback2 = hm_add_c3_without_phase_2;
    InitPartyMenu(arg1, 0, 11, 0, 0, sub_81B1370, CB2_ReturnToField);
}

void sub_81B9390(void)
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

void task_hm_without_phase_2(u8 taskId)
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

void sub_81B9424(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        InitPartyMenu(2, 0, 11, 0, 0, sub_81B1370, sub_81B9470);
        DestroyTask(taskId);
    }
}

void sub_81B9470(void)
{
    gUnknown_02039F24 = GetCursorSelectionMonId();
    if (gUnknown_02039F24 >= PARTY_SIZE)
        gUnknown_02039F24 = 0xFF;
    gSpecialVar_0x8004 = gUnknown_02039F24;
    gFieldCallback2 = hm_add_c3_without_phase_2;
    SetMainCallback2(CB2_ReturnToField);
}

void sub_81B94B0(void)
{
    ScriptContext2_Enable();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(sub_81B94D0, 10);
}

void sub_81B94D0(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
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

void sub_81B953C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        InitPartyMenu(7, 0, 11, 0, 0, sub_81B1370, sub_81B9588);
        DestroyTask(taskId);
    }
}

void sub_81B9588(void)
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

void sub_81B9640(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        overworld_free_bg_tilemaps();
        InitPartyMenu(12, 0, 0, 0, 0, sub_81B1370, sub_81B9390);
        DestroyTask(taskId);
    }
}

void sub_81B968C(void)
{
    ShowPokemonSummaryScreen(PSS_MODE_SELECT_MOVE, gPlayerParty, gSpecialVar_0x8004, gPlayerPartyCount - 1, CB2_ReturnToField);
    gFieldCallback = sub_80AF168;
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

void sub_81B97DC(struct Pokemon *mon, u8 slotTo, u8 slotFrom)
{
    u16 move1 = GetMonData(mon, MON_DATA_MOVE1 + slotTo);
    u16 move0 = GetMonData(mon, MON_DATA_MOVE1 + slotFrom);
    u8 pp1 = GetMonData(mon, MON_DATA_PP1 + slotTo);
    u8 pp0 = GetMonData(mon, MON_DATA_PP1 + slotFrom);
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
    u8 ppBonusMask1 = gUnknown_08329D22[slotTo];
    u8 ppBonusMove1 = (ppBonuses & ppBonusMask1) >> (slotTo * 2);
    u8 ppBonusMask2 = gUnknown_08329D22[slotFrom];
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
