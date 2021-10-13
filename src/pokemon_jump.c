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

struct PokemonJump1_MonInfo
{
    u16 species;
    u32 otId;
    u32 personality;
};

struct PokemonJump1_82E4
{
    int unk0;
    int unk4;
    u8 filler8[0x4];
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    int unk14;
    int unk18;
    u8 unk1C[11];
};

struct PokemonJump2
{
    int unk0;
    u16 unk4;
    u8 unk6;
    u8 filler7[0xa - 0x7];
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u16 filler10;
    u16 unk12;
    u16 unk14;
    u32 unk18;
    u16 unk1C[5];
    u8 txtBuff[2][0x40];
    u8 strBuff[0x100];
    u16 tilemapBuffer[(0x81a8 - 0x1a6) / 2]; // 0x1A6
    struct Sprite *unk81A8[MAX_RFU_PLAYERS];
    struct Sprite *unk81BC[MAX_RFU_PLAYERS];
    struct Sprite *unk81D0[8];
    u8 filler81F0[0xC];
    u8 unk81FC[MAX_RFU_PLAYERS];
};

struct PokemonJump1Sub
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    u32 unk8;
};

struct PokemonJump1
{
    MainCallback returnCallback;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    int unk10;
    u32 unk14;
    u32 unk18;
    int unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    int unk2C;
    u32 unk30;
    u16 unk34;
    u16 unk36;
    u8 filler38[0x2];
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u16 unk40;
    u16 unk42;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 isLeader;
    u8 unk48;
    u8 unk49;
    u16 unk4A;
    u8 unk4C;
    u8 unk4D;
    u16 unk4E;
    u8 unk50;
    u8 unk51;
    u8 filler52[0x2];
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    struct PokemonJump1Sub unk70;
    u8 unk7C[MAX_RFU_PLAYERS];
    u8 unk81[MAX_RFU_PLAYERS];
    u8 unk86[MAX_RFU_PLAYERS];
    u8 unk8B[MAX_RFU_PLAYERS];
    u16 unk90[MAX_RFU_PLAYERS];
    u16 unk9A[MAX_RFU_PLAYERS];
    struct PokemonJump2 unkA4;
    struct PokemonJump1_MonInfo unk82A8[MAX_RFU_PLAYERS];
    struct PokemonJump1_82E4 unk82E4[MAX_RFU_PLAYERS];
    struct PokemonJump1_82E4 *unk83AC;
};

struct PokemonJumpMons
{
    u16 species;
    u16 unk2;
};

static void sub_802AA60(struct PokemonJump1 *);
static void sub_802AA94(struct PokemonJump1 *);
static void sub_802AB20(void);
static void sub_802AB98(void);
static s16 GetPokemonJumpSpeciesIdx(u16 species);
static void sub_802AC2C(struct PokemonJump1_MonInfo *monInfo, struct Pokemon *mon);
static void sub_802AC6C(void);
static void sub_802ACA0(u8 taskId);
static void sub_802AF80(u8 taskId);
static void sub_802B008(void);
static void sub_802B194(u8 taskId);
static void sub_802B1FC(void);
static bool32 sub_802B248(void);
static bool32 sub_802B2D4(void);
static bool32 sub_802B368(void);
static bool32 sub_802B3D4(void);
static bool32 sub_802B470(void);
static bool32 sub_802B4CC(void);
static bool32 sub_802B568(void);
static bool32 sub_802B5C8(void);
static bool32 sub_802B628(void);
static bool32 sub_802B664(void);
static bool32 sub_802B6B8(void);
static bool32 sub_802B704(void);
static bool32 sub_802B720(void);
static bool32 sub_802B7E0(void);
static bool32 sub_802B8CC(void);
static bool32 sub_802B964(void);
static bool32 sub_802B29C(void);
static bool32 sub_802B31C(void);
static bool32 sub_802B3B4(void);
static bool32 sub_802BA58(void);
static bool32 sub_802BB84(void);
static bool32 sub_802BC60(void);
static bool32 sub_802BD30(void);
static void sub_802BD84(u8 taskId);
static void sub_802BE60(TaskFunc func, u8 taskPriority);
static void sub_802BE80(void);
static void sub_802BEA0(void);
static void sub_802BEE4(void);
static int sub_802BF48(void);
static void sub_802BF7C(void);
static int sub_802C098(void);
static void sub_802C0B8(void);
static void sub_802C0E8(void);
static void sub_802C114(void);
static bool32 sub_802C130(u16);
static void sub_802C164(void);
static void sub_802C1DC(void);
static void sub_802C240(void);
static void sub_802C260(void);
static void sub_802C270(void);
static void sub_802C280(void);
static void sub_802C398(int);
static void sub_802C43C(void);
static bool32 sub_802C538(void);
static bool32 sub_802C5DC(void);
static bool32 sub_802C618(void);
static bool32 sub_802C650(void);
static void sub_802C688(int);
static int sub_802C6B0(void);
static bool32 AreLinkQueuesEmpty(void);
static int sub_802C73C(u8 *);
static void sub_802C780(void);
static int sub_802C790(int);
static void sub_802C7A0(u16);
static bool32 sub_802C7BC(void);
static u16 sub_802C7E0(void);
static void sub_802C808(u16, u16 *, u16 *);
static u16 sub_802C818(void);
static u16 sub_802C838(void);
static u16 sub_802C880(u16 item, u16 quantity);
static void sub_802CB7C(struct Sprite *sprite);
static void sub_802CC40(struct Sprite *sprite);
static void sub_802CD08(struct Sprite *sprite);
static void sub_802CDD4(struct Sprite *sprite);
static void sub_802DC9C(int id);
static void sub_802D074(struct PokemonJump2 *);
static void sub_802D0BC(struct PokemonJump2 *);
static void sub_802D0AC(void);
static void sub_802D0C8(int);
static bool32 sub_802D0F0(void);
static void sub_802D764(void);
static bool32 sub_802D788(void);
static void sub_802D7E8(u16 itemId, u16 quantity);
static void sub_802D884(u16 itemId);
static void sub_802D8FC(u16 itemId);
static bool32 sub_802D974(void);
static void sub_802DA14(void);
static void sub_802DC80(u32 id, s16 y);
static void sub_802DD88(u8 multiplayerId);
static bool32 sub_802DA44(void);
static void sub_802DD64(int);
static s8 sub_802DA8C(void);
static int sub_802DCCC(u8 flags);
static void sub_802DD74(u16);
static void sub_802DDA0(u8 multiplayerId);
static int sub_802DDB8(int multiplayerId);
static void sub_802DDCC(void);
static void sub_802DDE0(void);
static void sub_802DDF4(int);
static int sub_802DE08(void);
static void sub_802E0AC(struct PokemonJump1_MonInfo *arg0);
static bool32 sub_802E0D0(int multiplayerId, struct PokemonJump1_MonInfo *arg0);
static void sub_802E138(struct PokemonJump1_82E4 *arg0, struct PokemonJump1Sub *arg1);
static bool32 sub_802E1BC(struct PokemonJump1_82E4 *arg0, struct PokemonJump1Sub *arg1);
static void sub_802E234(struct PokemonJump1_82E4 *arg0, u8 arg1, u16 arg2);
static bool32 sub_802E264(struct PokemonJump1_82E4 *arg0, int multiplayerId, u8 *arg2, u16 *arg3);
static bool32 sub_802E2D0(struct PokemonJump1_82E4 *arg0, int multiplayerId);
static bool32 sub_802E354(u32 jumpScore, u16 jumpsInRow, u16 excellentsInRow);
static void sub_802E3A8(void);
static void sub_802D12C(u8 taskId);
static void sub_802E00C(u8 arg0);
static void sub_802E090(u8 taskId);
static void sub_802D150(void);
static void sub_802DD08(void);
static void sub_802DB8C(void);
static void sub_802DBF8(void);
static void sub_802DE1C(void);
static void sub_802DFD4(void);
static void sub_802D108(void (*func)(void));
static void sub_802DF70(bool32 arg0);
static u32 sub_802DA9C(u32 left, u32 top, u32 width, u32 height);
static void sub_802DB18(u16 left, u16 top, u8 cursorPos);
static void sub_802D150(void);
static void sub_802D2E4(void);
static void sub_802D350(void);
static void sub_802D3BC(void);
static void sub_802D448(void);
static void sub_802D4F4(void);
static void sub_802D598(void);
static void sub_802D5E4(void);
static void sub_802D72C(void);
static void sub_802D688(void);
static void Task_ShowPokemonJumpRecords(u8 taskId);
static void sub_802E500(u16 windowId, int width);
static void TruncateToFirstWordOnly(u8 *str);

EWRAM_DATA static struct PokemonJump1 *gUnknown_02022CFC = NULL;
EWRAM_DATA static struct PokemonJump2 *gUnknown_02022D00 = NULL;

static const struct PokemonJumpMons gPkmnJumpSpecies[] =
{
    { .species = SPECIES_BULBASAUR,  .unk2 = 2, },
    { .species = SPECIES_CHARMANDER, .unk2 = 1, },
    { .species = SPECIES_SQUIRTLE,   .unk2 = 0, },
    { .species = SPECIES_CATERPIE,   .unk2 = 1, },
    { .species = SPECIES_METAPOD,    .unk2 = 1, },
    { .species = SPECIES_WEEDLE,     .unk2 = 1, },
    { .species = SPECIES_KAKUNA,     .unk2 = 1, },
    { .species = SPECIES_RATTATA,    .unk2 = 1, },
    { .species = SPECIES_RATICATE,   .unk2 = 1, },
    { .species = SPECIES_PIKACHU,    .unk2 = 0, },
    { .species = SPECIES_SANDSHREW,  .unk2 = 0, },
    { .species = SPECIES_NIDORAN_F,  .unk2 = 0, },
    { .species = SPECIES_NIDORAN_M,  .unk2 = 0, },
    { .species = SPECIES_CLEFAIRY,   .unk2 = 0, },
    { .species = SPECIES_VULPIX,     .unk2 = 0, },
    { .species = SPECIES_JIGGLYPUFF, .unk2 = 2, },
    { .species = SPECIES_ODDISH,     .unk2 = 2, },
    { .species = SPECIES_PARAS,      .unk2 = 1, },
    { .species = SPECIES_MEOWTH,     .unk2 = 0, },
    { .species = SPECIES_PSYDUCK,    .unk2 = 2, },
    { .species = SPECIES_MANKEY,     .unk2 = 1, },
    { .species = SPECIES_GROWLITHE,  .unk2 = 1, },
    { .species = SPECIES_POLIWAG,    .unk2 = 2, },
    { .species = SPECIES_BELLSPROUT, .unk2 = 2, },
    { .species = SPECIES_SHELLDER,   .unk2 = 1, },
    { .species = SPECIES_KRABBY,     .unk2 = 1, },
    { .species = SPECIES_EXEGGCUTE,  .unk2 = 2, },
    { .species = SPECIES_CUBONE,     .unk2 = 0, },
    { .species = SPECIES_DITTO,      .unk2 = 2, },
    { .species = SPECIES_EEVEE,      .unk2 = 0, },
    { .species = SPECIES_OMANYTE,    .unk2 = 1, },
    { .species = SPECIES_KABUTO,     .unk2 = 1, },
    { .species = SPECIES_CHIKORITA,  .unk2 = 2, },
    { .species = SPECIES_CYNDAQUIL,  .unk2 = 1, },
    { .species = SPECIES_TOTODILE,   .unk2 = 0, },
    { .species = SPECIES_SPINARAK,   .unk2 = 1, },
    { .species = SPECIES_PICHU,      .unk2 = 0, },
    { .species = SPECIES_CLEFFA,     .unk2 = 0, },
    { .species = SPECIES_IGGLYBUFF,  .unk2 = 2, },
    { .species = SPECIES_TOGEPI,     .unk2 = 2, },
    { .species = SPECIES_MAREEP,     .unk2 = 0, },
    { .species = SPECIES_BELLOSSOM,  .unk2 = 2, },
    { .species = SPECIES_MARILL,     .unk2 = 2, },
    { .species = SPECIES_SUNKERN,    .unk2 = 2, },
    { .species = SPECIES_WOOPER,     .unk2 = 2, },
    { .species = SPECIES_PINECO,     .unk2 = 2, },
    { .species = SPECIES_SNUBBULL,   .unk2 = 0, },
    { .species = SPECIES_SHUCKLE,    .unk2 = 2, },
    { .species = SPECIES_TEDDIURSA,  .unk2 = 0, },
    { .species = SPECIES_SLUGMA,     .unk2 = 2, },
    { .species = SPECIES_SWINUB,     .unk2 = 0, },
    { .species = SPECIES_HOUNDOUR,   .unk2 = 1, },
    { .species = SPECIES_PHANPY,     .unk2 = 0, },
    { .species = SPECIES_PORYGON2,   .unk2 = 0, },
    { .species = SPECIES_TYROGUE,    .unk2 = 1, },
    { .species = SPECIES_SMOOCHUM,   .unk2 = 2, },
    { .species = SPECIES_ELEKID,     .unk2 = 1, },
    { .species = SPECIES_MAGBY,      .unk2 = 1, },
    { .species = SPECIES_LARVITAR,   .unk2 = 1, },
    { .species = SPECIES_TREECKO,    .unk2 = 1, },
    { .species = SPECIES_TORCHIC,    .unk2 = 2, },
    { .species = SPECIES_MUDKIP,     .unk2 = 0, },
    { .species = SPECIES_MARSHTOMP,  .unk2 = 0, },
    { .species = SPECIES_POOCHYENA,  .unk2 = 1, },
    { .species = SPECIES_ZIGZAGOON,  .unk2 = 0, },
    { .species = SPECIES_LINOONE,    .unk2 = 0, },
    { .species = SPECIES_WURMPLE,    .unk2 = 1, },
    { .species = SPECIES_SILCOON,    .unk2 = 2, },
    { .species = SPECIES_CASCOON,    .unk2 = 2, },
    { .species = SPECIES_LOTAD,      .unk2 = 2, },
    { .species = SPECIES_SEEDOT,     .unk2 = 1, },
    { .species = SPECIES_RALTS,      .unk2 = 0, },
    { .species = SPECIES_KIRLIA,     .unk2 = 0, },
    { .species = SPECIES_SURSKIT,    .unk2 = 2, },
    { .species = SPECIES_SHROOMISH,  .unk2 = 2, },
    { .species = SPECIES_NINCADA,    .unk2 = 1, },
    { .species = SPECIES_WHISMUR,    .unk2 = 0, },
    { .species = SPECIES_AZURILL,    .unk2 = 2, },
    { .species = SPECIES_SKITTY,     .unk2 = 0, },
    { .species = SPECIES_SABLEYE,    .unk2 = 0, },
    { .species = SPECIES_MAWILE,     .unk2 = 0, },
    { .species = SPECIES_ARON,       .unk2 = 1, },
    { .species = SPECIES_MEDITITE,   .unk2 = 2, },
    { .species = SPECIES_ELECTRIKE,  .unk2 = 1, },
    { .species = SPECIES_PLUSLE,     .unk2 = 1, },
    { .species = SPECIES_MINUN,      .unk2 = 1, },
    { .species = SPECIES_VOLBEAT,    .unk2 = 0, },
    { .species = SPECIES_ILLUMISE,   .unk2 = 0, },
    { .species = SPECIES_ROSELIA,    .unk2 = 2, },
    { .species = SPECIES_GULPIN,     .unk2 = 2, },
    { .species = SPECIES_NUMEL,      .unk2 = 2, },
    { .species = SPECIES_TORKOAL,    .unk2 = 2, },
    { .species = SPECIES_SPOINK,     .unk2 = 0, },
    { .species = SPECIES_TRAPINCH,   .unk2 = 2, },
    { .species = SPECIES_CACNEA,     .unk2 = 2, },
    { .species = SPECIES_ANORITH,    .unk2 = 1, },
    { .species = SPECIES_WYNAUT,     .unk2 = 0, },
    { .species = SPECIES_SNORUNT,    .unk2 = 0, },
    { .species = SPECIES_CLAMPERL,   .unk2 = 1, },
    { .species = SPECIES_BAGON,      .unk2 = 1, },
};

void StartPokemonJump(u16 partyIndex, MainCallback callback)
{
    u8 taskId;

    if (gReceivedRemoteLinkPlayers)
    {
        gUnknown_02022CFC = Alloc(sizeof(*gUnknown_02022CFC));
        if (gUnknown_02022CFC)
        {
            ResetTasks();
            taskId = CreateTask(sub_802ACA0, 1);
            gUnknown_02022CFC->unk8 = 0;
            gUnknown_02022CFC->returnCallback = callback;
            gUnknown_02022CFC->unk4 = taskId;
            gUnknown_02022CFC->unk6 = GetMultiplayerId();
            sub_802AC2C(&gUnknown_02022CFC->unk82A8[gUnknown_02022CFC->unk6], &gPlayerParty[partyIndex]);
            sub_802AA60(gUnknown_02022CFC);
            SetWordTaskArg(taskId, 2, (u32)gUnknown_02022CFC);
            SetMainCallback2(sub_802AC6C);
            return;
        }
    }

    SetMainCallback2(callback);
}

static void sub_802AA48(void)
{
    sub_802D0AC();
    Free(gUnknown_02022CFC);
}

static void sub_802AA60(struct PokemonJump1 *arg0)
{
    arg0->unk5 = GetLinkPlayerCount();
    arg0->unk70.unk0 = 5;
    arg0->unk70.unk2 = 0;
    sub_802AB20();
    sub_802AA94(arg0);
    if (arg0->unk5 == MAX_RFU_PLAYERS)
        sub_802E3A8();
}

static void sub_802AA94(struct PokemonJump1 *arg0)
{
    int i;

    arg0->unk14 = 6;
    arg0->unk18 = 6;
    arg0->unk4A = 0;
    arg0->unk1C = 0;
    arg0->unk5C = 0;
    arg0->isLeader = GetMultiplayerId() == 0;
    arg0->unk8 = 0;
    arg0->unkA = 0;
    arg0->unkC = 0;
    arg0->unkE = 0;
    arg0->unk58 = 0;
    arg0->unk3A = 0;
    arg0->unk44 = 0;
    arg0->unk54 = 0;
    arg0->unk46 = 0;
    arg0->unk49 = 0;
    arg0->unk48 = 1;
    arg0->unk70.unk8 = 0;
    arg0->unk70.unk1 = 0;
    arg0->unk70.unk4 = 0;
    arg0->unk60 = 1;
    arg0->unk4D = 0;
    arg0->unk68 = 0;
    arg0->unk64 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    sub_802AB98();
    sub_802C0E8();

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        arg0->unk7C[i] = 0;
        arg0->unk9A[i] = 0;
    }
}

static void sub_802AB20(void)
{
    int i, index;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        index = GetPokemonJumpSpeciesIdx(gUnknown_02022CFC->unk82A8[i].species);
        gUnknown_02022CFC->unk82E4[i].unkC = gPkmnJumpSpecies[index].unk2;
    }

    gUnknown_02022CFC->unk83AC = &gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6];
}

static void sub_802AB98(void)
{
    int i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        gUnknown_02022CFC->unk82E4[i].unkE = 0;
        gUnknown_02022CFC->unk82E4[i].unk10 = 0;
        gUnknown_02022CFC->unk82E4[i].unk12 = 0;
        gUnknown_02022CFC->unk82E4[i].unk0 = 0;
        gUnknown_02022CFC->unk82E4[i].unk4 = 0x7FFFFFFF;
        gUnknown_02022CFC->unk82E4[i].unk14 = 0;
        gUnknown_02022CFC->unk8B[i] = 9;
    }
}

static s16 GetPokemonJumpSpeciesIdx(u16 species)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(gPkmnJumpSpecies); i++)
    {
        if (gPkmnJumpSpecies[i].species == species)
            return i;
    }

    return -1; // species isnt allowed
}

static void sub_802AC2C(struct PokemonJump1_MonInfo *monInfo, struct Pokemon *mon)
{
    monInfo->species = GetMonData(mon, MON_DATA_SPECIES);
    monInfo->otId = GetMonData(mon, MON_DATA_OT_ID);
    monInfo->personality = GetMonData(mon, MON_DATA_PERSONALITY);
}

static void sub_802AC58(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void sub_802AC6C(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_802AC84(TaskFunc func)
{
    gUnknown_02022CFC->unk4 = CreateTask(func, 1);
    gUnknown_02022CFC->unk8 = 0;
}

static void sub_802ACA0(u8 taskId)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        sub_802BE60(sub_802BD84, 5);
        FadeOutMapMusic(4);
        gUnknown_02022CFC->unk8++;
        break;
    case 1:
        if (!FuncIsActiveTask(sub_802BD84))
        {
            sub_802D074(&gUnknown_02022CFC->unkA4);
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 2:
        if (!sub_802D0F0() && IsNotWaitingForBGMStop() == TRUE)
        {
            FadeOutAndPlayNewMapMusic(MUS_RG_POKE_JUMP, 8);
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            SetVBlankCallback(sub_802AC58);
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            gUnknown_02022CFC->unk7 = 0;
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 5:
        gUnknown_02022CFC->unk7++;
        if (gUnknown_02022CFC->unk7 >= 20)
        {
            if (gUnknown_02022CFC->isLeader)
                sub_802AC84(sub_802AF80);
            else
                sub_802AC84(sub_802B194);

            sub_802BE80();
            DestroyTask(taskId);
        }
        break;
    }
}

static void sub_802AE14(int arg0)
{
    if (arg0 == 0)
    {
        gUnknown_02022CFC->unk30 = 0x1111;
        gUnknown_02022CFC->unk2C = 1;
    }
    else
    {
        gUnknown_02022CFC->unk30 = (1 << (arg0 - 1)) - 1;
        gUnknown_02022CFC->unk2C = 0;
    }
}

static void sub_802AE50(u8 arg0)
{
    int i;

    gUnknown_02022CFC->unk70.unk0 = arg0;
    gUnknown_02022CFC->unk8 = 0;
    gUnknown_02022CFC->unkA = 0;
    gUnknown_02022CFC->unk48 = 1;
    gUnknown_02022CFC->unk49 = 0;
    for (i = 1; i < gUnknown_02022CFC->unk5; i++)
        gUnknown_02022CFC->unk82E4[i].unk18 = 0;
}

static void sub_802AEA4(void)
{
    int i;
    int count;
    u16 var0;
    u8 var1;
    u16 var2;

    for (i = 1, count = 0; i < gUnknown_02022CFC->unk5; i++)
    {
        var0 = gUnknown_02022CFC->unk82E4[i].unk10;
        if (sub_802E264(&gUnknown_02022CFC->unk82E4[i], i, &var1, &var2))
        {
            gUnknown_02022CFC->unk90[i] = var2;
            gUnknown_02022CFC->unk8B[i] = var1;
            gUnknown_02022CFC->unk82E4[i].unk12 = var0;
        }

        if (gUnknown_02022CFC->unk82E4[i].unk18 && gUnknown_02022CFC->unk8B[i] == gUnknown_02022CFC->unk70.unk0)
            count++;
    }

    if (count == gUnknown_02022CFC->unk5 - 1)
        gUnknown_02022CFC->unk49 = 1;
}

static bool32 (* const gUnknown_082FB5F4[])(void) =
{
    sub_802B248,
    sub_802B2D4,
    sub_802B368,
    sub_802B3D4,
    sub_802B4CC,
    sub_802B5C8,
    sub_802B664,
    sub_802B6B8,
    sub_802B720,
};

static void sub_802AF80(u8 taskId)
{
    sub_802AEA4();
    sub_802C43C();
    if (!gUnknown_02022CFC->unk48 && gUnknown_02022CFC->unk49)
    {
        sub_802AE50(gUnknown_02022CFC->unk4C);
        sub_802AE14(3);
    }

    if (gUnknown_02022CFC->unk48 == 1)
    {
        if (!gUnknown_082FB5F4[gUnknown_02022CFC->unk70.unk0]())
        {
            gUnknown_02022CFC->unk48 = 0;
            gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6].unk18 = 1;
        }
    }

    sub_802C1DC();
    sub_802B008();
}

static void sub_802B008(void)
{
    if (!gUnknown_02022CFC->unk2C)
        sub_802E138(gUnknown_02022CFC->unk82E4, &gUnknown_02022CFC->unk70);

    if (gUnknown_02022CFC->unk30 != 0x1111)
    {
        gUnknown_02022CFC->unk2C++;
        gUnknown_02022CFC->unk2C &= gUnknown_02022CFC->unk30;
    }
}

static void sub_802B044(u8 arg0)
{
    gUnknown_02022CFC->unk70.unk0 = arg0;
    gUnknown_02022CFC->unk8 = 0;
    gUnknown_02022CFC->unkA = 0;
    gUnknown_02022CFC->unk48 = 1;
    gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6].unk18 = 0;
}

static void sub_802B078(void)
{
    int i;
    u16 var0;
    struct PokemonJump1Sub sp0;

    var0 = gUnknown_02022CFC->unk82E4[0].unk10;
    if (sub_802E1BC(gUnknown_02022CFC->unk82E4, &sp0))
    {
        if (gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6].unk18 == 1
         && sp0.unk0 != gUnknown_02022CFC->unk70.unk0)
        {
            sub_802B044(sp0.unk0);
        }

        if (gUnknown_02022CFC->unk70.unk8 != sp0.unk8)
        {
            gUnknown_02022CFC->unk70.unk8 = sp0.unk8;
            gUnknown_02022CFC->unk5C = 1;
            gUnknown_02022CFC->unk70.unk1 = sp0.unk1;
            if (gUnknown_02022CFC->unk70.unk1)
                gUnknown_02022CFC->unk4D = 1;
            else
                gUnknown_02022CFC->unk4D = 0;
        }

        gUnknown_02022CFC->unk70.unk2 = sp0.unk2;
        gUnknown_02022CFC->unk70.unk4 = sp0.unk4;
        gUnknown_02022CFC->unk82E4[0].unk12 = var0;
    }

    for (i = 1; i < gUnknown_02022CFC->unk5; i++)
    {
        if (i != gUnknown_02022CFC->unk6)
        {
            var0 = gUnknown_02022CFC->unk82E4[i].unk10;
            if (sub_802E2D0(&gUnknown_02022CFC->unk82E4[i], i))
                gUnknown_02022CFC->unk82E4[i].unk12 = var0;
        }
    }
}

static bool32 (* const gUnknown_082FB618[])(void) =
{
    sub_802B29C,
    sub_802B31C,
    sub_802B3B4,
    sub_802B470,
    sub_802B568,
    sub_802B628,
    sub_802B664,
    sub_802B704,
    sub_802B720,
};

static void sub_802B194(u8 taskId)
{
    sub_802B078();
    if (gUnknown_02022CFC->unk48)
    {
        if (!gUnknown_082FB618[gUnknown_02022CFC->unk70.unk0]())
        {
            gUnknown_02022CFC->unk48 = 0;
            gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6].unk18 = 1;
            sub_802AE14(3);
        }
    }

    sub_802C1DC();
    sub_802B1FC();
}

static void sub_802B1FC(void)
{
    if (!gUnknown_02022CFC->unk2C)
        sub_802E234(&gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6], gUnknown_02022CFC->unk70.unk0, gUnknown_02022CFC->unk42);

    if (gUnknown_02022CFC->unk30 != 0x1111)
    {
        gUnknown_02022CFC->unk2C++;
        gUnknown_02022CFC->unk2C &= gUnknown_02022CFC->unk30;
    }
}

static bool32 sub_802B248(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802AE14(3);
        gUnknown_02022CFC->unk8++;
        // fall through
    case 1:
        if (!sub_802B7E0())
        {
            gUnknown_02022CFC->unk70.unk2 = gUnknown_02022CFC->unk4A;
            gUnknown_02022CFC->unk4C = 1;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 sub_802B29C(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802AE14(0);
        gUnknown_02022CFC->unk24 = gUnknown_02022CFC->unk70.unk2;
        gUnknown_02022CFC->unk8++;
        // fall through
    case 1:
        return sub_802B7E0();
    }

    return TRUE;
}

static bool32 sub_802B2D4(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802C0E8();
        sub_802AE14(5);
        gUnknown_02022CFC->unk8++;
        break;
    case 1:
        if (gUnknown_02022CFC->unk49)
        {
            gUnknown_02022CFC->unk4C = 2;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 sub_802B31C(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802C0E8();
        sub_802AE14(0);
        gUnknown_02022CFC->unk4A = gUnknown_02022CFC->unk70.unk2;
        gUnknown_02022CFC->unk8++;
        // fall through
    case 1:
        if (AreLinkQueuesEmpty())
            return FALSE;
        break;
    }

    return TRUE;
}

static bool32 sub_802B368(void)
{
    if (!sub_802B8CC())
    {
        gUnknown_02022CFC->unk70.unk2 = gUnknown_02022CFC->unk4A;
        gUnknown_02022CFC->unk4C = 1;
    }
    else if (sub_802C538())
    {
        return TRUE;
    }
    else
    {
        sub_802C0B8();
        gUnknown_02022CFC->unk4C = 3;
    }

    return FALSE;
}

static bool32 sub_802B3B4(void)
{
    if (!sub_802B8CC())
        ;
    else if (sub_802C538())
        return TRUE;
    else
        sub_802C0B8();

    return FALSE;
}

static bool32 sub_802B3D4(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802C538();
        if (sub_802C5DC())
            gUnknown_02022CFC->unk8++;
        break;
    case 1:
        if (!sub_802B964())
        {
            if (sub_802C7BC())
            {
                gUnknown_02022CFC->unk70.unk2 = sub_802C7E0();
                gUnknown_02022CFC->unk4C = 7;
            }
            else if (gUnknown_02022CFC->unk70.unk4 >= 200)
            {
                gUnknown_02022CFC->unk70.unk2 = gUnknown_02022CFC->unkE;
                gUnknown_02022CFC->unk4C = 8;
            }
            else
            {
                gUnknown_02022CFC->unk70.unk2 = gUnknown_02022CFC->unkE;
                gUnknown_02022CFC->unk4C = 4;
            }

            gUnknown_02022CFC->unk8++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool32 sub_802B470(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        if (!sub_802C538())
            sub_802C0B8();
        if (sub_802C5DC())
            gUnknown_02022CFC->unk8++;
        break;
    case 1:
        if (!sub_802B964())
        {
            gUnknown_02022CFC->unk8++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static bool32 sub_802B4CC(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802AE14(4);
        gUnknown_02022CFC->unk8++;
        // fall through
    case 1:
        if (!sub_802BB84())
        {
            sub_802E354(gUnknown_02022CFC->unk70.unk8, gUnknown_02022CFC->unk70.unk4, gUnknown_02022CFC->unk70.unk2);
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 2:
        if (gUnknown_02022CFC->unk49)
        {
            if (sub_802C650())
                gUnknown_02022CFC->unk4C = 5;
            else
                gUnknown_02022CFC->unk4C = 6;

            gUnknown_02022CFC->unk8++;
            return FALSE;
        }
        break;
    case 3:
        return FALSE;
    }

    return TRUE;
}

static bool32 sub_802B568(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802AE14(0);
        gUnknown_02022CFC->unk8++;
        // fall through
    case 1:
        if (!sub_802BB84())
        {
            sub_802E354(gUnknown_02022CFC->unk70.unk8, gUnknown_02022CFC->unk70.unk4, gUnknown_02022CFC->unk70.unk2);
            gUnknown_02022CFC->unk42 = gUnknown_02022CFC->unk45;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 sub_802B5C8(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        if (!sub_802BD30())
            gUnknown_02022CFC->unk8++;
        break;
    case 1:
        if (gUnknown_02022CFC->unk49)
        {
            sub_802AA94(gUnknown_02022CFC);
            gUnknown_02022CFC->unk24 = Random();
            gUnknown_02022CFC->unk70.unk2 = gUnknown_02022CFC->unk24;
            gUnknown_02022CFC->unk4C = 0;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 sub_802B628(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        if (!sub_802BD30())
        {
            sub_802AA94(gUnknown_02022CFC);
            gUnknown_02022CFC->unk8++;
            return FALSE;
        }
        break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

static bool32 sub_802B664(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        gUnknown_02022CFC->unk8 = 1;
        break;
    case 1:
        sub_802AE14(0);
        gUnknown_02022CFC->unk8++;
        break;
    case 2:
        if (!sub_802BC60())
        {
            SetMainCallback2(gUnknown_02022CFC->returnCallback);
            sub_802AA48();
        }
        break;
    }

    return TRUE;
}

static bool32 sub_802B6B8(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802AE14(4);
        gUnknown_02022CFC->unk8++;
        break;
    case 1:
        if (!sub_802BA58())
        {
            gUnknown_02022CFC->unk70.unk2 = gUnknown_02022CFC->unkE;
            gUnknown_02022CFC->unk4C = 8;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 sub_802B704(void)
{
    sub_802AE14(0);
    if (!sub_802BA58())
        return FALSE;
    else
        return TRUE;
}

static bool32 sub_802B720(void)
{
    switch (gUnknown_02022CFC->unk8)
    {
    case 0:
        sub_802E354(gUnknown_02022CFC->unk70.unk8, gUnknown_02022CFC->unk70.unk4, gUnknown_02022CFC->unk70.unk2);
        sub_802D0C8(5);
        gUnknown_02022CFC->unk8++;
        break;
    case 1:
        if (!sub_802D0F0())
        {
            sub_802AE14(0);
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 2:
        if (AreLinkQueuesEmpty())
        {
            CreateTask(Task_LinkSave, 6);
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 3:
        if (!FuncIsActiveTask(Task_LinkSave))
        {
            sub_802DA14();
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 4:
        if (!sub_802DA44())
        {
            gUnknown_02022CFC->unk4C = 4;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

static bool32 sub_802B7E0(void)
{
    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        sub_802D0C8(2);
        sub_802DDE0();
        gUnknown_02022CFC->unkA++;
        break;
    case 1:
        if (!sub_802D0F0())
        {
            sub_802DDF4(gUnknown_02022CFC->unk6);
            gUnknown_02022CFC->unk3C = 0;
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 2:
        if (++gUnknown_02022CFC->unk3C > 120)
        {
            sub_802D0C8(3);
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 3:
        if (sub_802D0F0() != 1 && sub_802DE08() != 1)
            gUnknown_02022CFC->unkA++;
        break;
    case 4:
        sub_802D0C8(9);
        gUnknown_02022CFC->unkA++;
        break;
    case 5:
        if (!sub_802D0F0())
        {
            sub_802C260();
            sub_802D764();
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 6:
        if (!sub_802D788())
        {
            sub_802C270();
            sub_802BEA0();
            gUnknown_02022CFC->unkA++;
            return FALSE;
        }
        break;
    case 7:
        return FALSE;
    }

    return TRUE;
}

static bool32 sub_802B8CC(void)
{
    sub_802BEE4();
    if (gUnknown_02022CFC->unk36)
    {
        gUnknown_02022CFC->unk36 = 0;
        return FALSE;
    }

    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        if (sub_802C130(0))
            gUnknown_02022CFC->unkA++;
        else
            break;
        // fall through
    case 1:
        if (JOY_NEW(A_BUTTON))
        {
            sub_802C164();
            sub_802AE14(3);
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 2:
        if (sub_802C130(1) == TRUE)
            gUnknown_02022CFC->unkA++;
        break;
    case 3:
        if (sub_802C130(0) == TRUE)
            gUnknown_02022CFC->unkA = 0;
        break;
    }

    return TRUE;
}

static bool32 sub_802B964(void)
{
    int i;

    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        for (i = 0; i < gUnknown_02022CFC->unk5; i++)
        {
            if (sub_802DDB8(i) == 1)
                return TRUE;
        }

        gUnknown_02022CFC->unkA++;
        break;
    case 1:
        for (i = 0; i < gUnknown_02022CFC->unk5; i++)
        {
            if (gUnknown_02022CFC->unk82E4[i].unk10 == 2)
                sub_802DDA0(i);
        }

        sub_802D0C8(1);
        gUnknown_02022CFC->unk3C = 0;
        gUnknown_02022CFC->unkA++;
        break;
    case 2:
        if (++gUnknown_02022CFC->unk3C > 100)
        {
            sub_802D0C8(3);
            gUnknown_02022CFC->unk3C = 0;
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 3:
        if (!sub_802D0F0())
        {
            sub_802DDCC();
            gUnknown_02022CFC->unk70.unk1 = 0;
            sub_802C114();
            gUnknown_02022CFC->unkA++;
            return FALSE;
        }
        break;
    case 4:
        return FALSE;
    }

    return TRUE;
}

static bool32 sub_802BA58(void)
{
    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        sub_802C808(gUnknown_02022CFC->unk70.unk2, &gUnknown_02022CFC->unk3E, &gUnknown_02022CFC->unk40);
        sub_802D7E8(gUnknown_02022CFC->unk3E, gUnknown_02022CFC->unk40);
        gUnknown_02022CFC->unkA++;
        break;
    case 1:
    case 4:
        if (!sub_802D974())
        {
            gUnknown_02022CFC->unk3C = 0;
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 2:
    case 5:
        gUnknown_02022CFC->unk3C++;
        if (JOY_NEW(A_BUTTON | B_BUTTON) || gUnknown_02022CFC->unk3C > 180)
        {
            sub_802DA14();
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 3:
        if (!sub_802DA44())
        {
            gUnknown_02022CFC->unk40 = sub_802C880(gUnknown_02022CFC->unk3E, gUnknown_02022CFC->unk40);
            if (gUnknown_02022CFC->unk40 && AddBagItem(gUnknown_02022CFC->unk3E, gUnknown_02022CFC->unk40))
            {
                if (!CheckBagHasSpace(gUnknown_02022CFC->unk3E, 1))
                {
                    sub_802D884(gUnknown_02022CFC->unk3E);
                    gUnknown_02022CFC->unkA = 4;
                }
                else
                {
                    gUnknown_02022CFC->unkA = 6;
                    break;
                }
            }
            else
            {
                sub_802D8FC(gUnknown_02022CFC->unk3E);
                gUnknown_02022CFC->unkA = 4;
            }
        }
        break;
    case 6:
        if (!sub_802DA44())
            return FALSE;
        break;
    }

    return TRUE;
}

static bool32 sub_802BB84(void)
{
    s8 input;

    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        sub_802D0C8(4);
        gUnknown_02022CFC->unkA++;
        break;
    case 1:
        if (!sub_802D0F0())
            gUnknown_02022CFC->unkA++;
        break;
    case 2:
        input = sub_802DA8C();
        switch (input)
        {
        case MENU_B_PRESSED:
        case 1:
            gUnknown_02022CFC->unk45 = 1;
            sub_802D0C8(6);
            gUnknown_02022CFC->unkA++;
            break;
        case 0:
            gUnknown_02022CFC->unk45 = 2;
            sub_802D0C8(6);
            gUnknown_02022CFC->unkA++;
            break;
        }
        break;
    case 3:
        if (!sub_802D0F0())
            gUnknown_02022CFC->unkA++;
        break;
    case 4:
        sub_802D0C8(8);
        gUnknown_02022CFC->unkA++;
        break;
    case 5:
        if (!sub_802D0F0())
        {
            gUnknown_02022CFC->unkA++;
            return FALSE;
        }
        break;
    case 6:
        return FALSE;
    }

    return TRUE;
}

static bool32 sub_802BC60(void)
{
    int var0;

    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        sub_802DA14();
        gUnknown_02022CFC->unkA++;
        break;
    case 1:
        if (!sub_802DA44())
        {
            sub_802D0C8(7);
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 2:
        var0 = sub_802D0F0();
        if (!var0)
        {
            gUnknown_02022CFC->unk3C = var0;
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 3:
        if (++gUnknown_02022CFC->unk3C > 120)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            SetCloseLinkCallback();
            gUnknown_02022CFC->unkA++;
        }
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
            return FALSE;
        break;
    }

    return TRUE;
}

static bool32 sub_802BD30(void)
{
    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        sub_802DA14();
        sub_802DD64(0);
        gUnknown_02022CFC->unkA++;
        break;
    case 1:
        if (!sub_802DA44())
        {
            gUnknown_02022CFC->unkA++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

static void sub_802BD84(u8 taskId)
{
    int i;
    s16 *taskData = gTasks[taskId].data;
    struct PokemonJump1 *ptr = (struct PokemonJump1 *)GetWordTaskArg(taskId, 14);

    switch (taskData[0])
    {
    case 0:
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            taskData[i + 2] = 0;

        taskData[0]++;
        // fall through
    case 1:
        sub_802E0AC(&ptr->unk82A8[ptr->unk6]);
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
        {
            if (!taskData[i + 2] && sub_802E0D0(i, &ptr->unk82A8[i]))
            {
                StringCopy(ptr->unk82E4[i].unk1C, gLinkPlayers[i].name);
                taskData[i + 2] = 1;
                taskData[1]++;
                if (taskData[1] == ptr->unk5)
                {
                    sub_802AB20();
                    DestroyTask(taskId);
                    break;
                }
            }
        }
        break;
    }
}

static void sub_802BE60(TaskFunc func, u8 taskPriority)
{
    u8 taskId = CreateTask(func, taskPriority);
    SetWordTaskArg(taskId, 14, (u32)gUnknown_02022CFC);
}

static void sub_802BE80(void)
{
    gUnknown_02022CFC->unk4A = 0;
    gUnknown_02022CFC->unk14 = 6;
    gUnknown_02022CFC->unk34 = 0;
    gUnknown_02022CFC->unk1C = 0;
    gUnknown_02022CFC->unk36 = 0;
    gUnknown_02022CFC->unk10 = 0;
}

static void sub_802BEA0(void)
{
    gUnknown_02022CFC->unk4A = 0;
    gUnknown_02022CFC->unk34 = 0x6FF;
    gUnknown_02022CFC->unk14 = 7;
    gUnknown_02022CFC->unk36 = 0;
    gUnknown_02022CFC->unk10 = 0;
    gUnknown_02022CFC->unk51 = 0;
    gUnknown_02022CFC->unk50 = 0;
    gUnknown_02022CFC->unk20 = 0;
    gUnknown_02022CFC->unk4E = 0;
    gUnknown_02022CFC->unk6C = 0;
    sub_802BF7C();
}

static void sub_802BEE4(void)
{
    if (gUnknown_02022CFC->unk46)
    {
        gUnknown_02022CFC->unk4A++;
        gUnknown_02022CFC->unk34 += sub_802BF48();
        if (gUnknown_02022CFC->unk34 >= 0x9FF)
            gUnknown_02022CFC->unk34 -= 0x9FF;

        gUnknown_02022CFC->unk18 = gUnknown_02022CFC->unk14;
        gUnknown_02022CFC->unk14 = gUnknown_02022CFC->unk34 >> 8;
        if (gUnknown_02022CFC->unk14 > 6 && gUnknown_02022CFC->unk18 < 7)
        {
            gUnknown_02022CFC->unk36++;
            sub_802BF7C();
        }
    }
}

static int sub_802BF48(void)
{
    int result;

    if (gUnknown_02022CFC->unk10)
        return 0;

    result = gUnknown_02022CFC->unk1C;
    if (gUnknown_02022CFC->unk34 <= 0x5FF)
    {
        gUnknown_02022CFC->unk20 += 80;
        result += gUnknown_02022CFC->unk20 >> 8;
    }

    return result;
}

static const u16 gUnknown_082FB63C[] = {0x1a, 0x1f, 0x24, 0x29, 0x2e, 0x33, 0x38, 0x3d};
static const u16 gUnknown_082FB64C[] = {0, 1, 1, 2};

static void sub_802BF7C(void)
{
    int var0;

    gUnknown_02022CFC->unk20 = 0;
    if (gUnknown_02022CFC->unk4E)
    {
        gUnknown_02022CFC->unk4E--;
        if (gUnknown_02022CFC->unk6C)
        {
            if (sub_802C098() % 4 != 0)
            {
                gUnknown_02022CFC->unk1C = gUnknown_02022CFC->unk28;
            }
            else
            {
                if (gUnknown_02022CFC->unk28 > 54)
                    gUnknown_02022CFC->unk1C = 30;
                else
                    gUnknown_02022CFC->unk1C = 82;
            }
        }
    }
    else
    {
        if (!(gUnknown_02022CFC->unk50 & 8))
        {
            gUnknown_02022CFC->unk28 = gUnknown_082FB63C[gUnknown_02022CFC->unk50] + (gUnknown_02022CFC->unk51 * 7);
            gUnknown_02022CFC->unk4E = gUnknown_082FB64C[sub_802C098() % ARRAY_COUNT(gUnknown_082FB64C)] + 2;
            gUnknown_02022CFC->unk50++;
        }
        else
        {
            if (gUnknown_02022CFC->unk50 == 8)
            {
                if (gUnknown_02022CFC->unk51 < 3)
                    gUnknown_02022CFC->unk51++;
                else
                    gUnknown_02022CFC->unk6C = 1;
            }

            var0 = gUnknown_082FB63C[15 - gUnknown_02022CFC->unk50];
            gUnknown_02022CFC->unk28 = var0 + (gUnknown_02022CFC->unk51 * 7);
            if (++gUnknown_02022CFC->unk50 > 15)
            {
                if (sub_802C098() % 4 == 0)
                    gUnknown_02022CFC->unk28 -= 5;

                gUnknown_02022CFC->unk50 = 0;
            }
        }

        gUnknown_02022CFC->unk1C = gUnknown_02022CFC->unk28;
    }
}

static int sub_802C098(void)
{
    gUnknown_02022CFC->unk24 = ISO_RANDOMIZE1(gUnknown_02022CFC->unk24);
    return gUnknown_02022CFC->unk24 >> 16;
}

static void sub_802C0B8(void)
{
    gUnknown_02022CFC->unk10 = 1;
    gUnknown_02022CFC->unk14 = 6;
    gUnknown_02022CFC->unk34 = 0x5FF;
    sub_802C270();
}

static int sub_802C0DC(void)
{
    return gUnknown_02022CFC->unk10;
}

static void sub_802C0E8(void)
{
    int i;
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        gUnknown_02022CFC->unk82E4[i].unk14 = 0;
}

static void sub_802C114(void)
{
    gUnknown_02022CFC->unk83AC->unk10 = 0;
    gUnknown_02022CFC->unk83AC->unk12 = 0;
}

static bool32 sub_802C130(u16 arg0)
{
    if (gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6].unk10 == arg0)
        return TRUE;
    else
        return FALSE;
}

static void sub_802C164(void)
{
    gUnknown_02022CFC->unk83AC->unkE = gUnknown_02022CFC->unk4A;
    gUnknown_02022CFC->unk83AC->unk12 = gUnknown_02022CFC->unk83AC->unk10;
    gUnknown_02022CFC->unk83AC->unk10 = 1;
}

static void sub_802C18C(void)
{
    gUnknown_02022CFC->unk83AC->unk12 = gUnknown_02022CFC->unk83AC->unk10;
    gUnknown_02022CFC->unk83AC->unk10 = 2;
    gUnknown_02022CFC->unk83AC->unkE = gUnknown_02022CFC->unk4A;
    gUnknown_02022CFC->unk83AC->unk14 = 2;
}

static void sub_802C1BC(void)
{
    gUnknown_02022CFC->unk83AC->unk12 = gUnknown_02022CFC->unk83AC->unk10;
    gUnknown_02022CFC->unk83AC->unk10 = 0;
}

static const u16 gUnknown_082FB654[] = {SE_SHOP, SE_SHINY, SE_M_MORNING_SUN, SE_RG_POKE_JUMP_SUCCESS};

static void sub_802C1DC(void)
{
    if (gUnknown_02022CFC->unk5C)
    {
        sub_802DD64(gUnknown_02022CFC->unk70.unk8);
        gUnknown_02022CFC->unk5C = 0;
        if (gUnknown_02022CFC->unk4D)
        {
            int index = sub_802DCCC(gUnknown_02022CFC->unk70.unk1);
            PlaySE(gUnknown_082FB654[index - 2]);
            gUnknown_02022CFC->unk4D = 0;
        }
    }

    sub_802DD74(gUnknown_02022CFC->unk70.unk4);
    sub_802C280();
    sub_802C240();
}

static void sub_802C240(void)
{
    if (gUnknown_02022CFC->unk46)
        sub_802DC9C(gUnknown_02022CFC->unk14);
}

static void sub_802C260(void)
{
    gUnknown_02022CFC->unk46 = 0;
}

static void sub_802C270(void)
{
    gUnknown_02022CFC->unk46 = 1;
}

static void sub_802C280(void)
{
    int i;
    int whichSound = 0;
    int numLinkPlayers = gUnknown_02022CFC->unk5;

    for (i = 0; i < numLinkPlayers; i++)
    {
        switch (gUnknown_02022CFC->unk82E4[i].unk10)
        {
        case 0:
            sub_802DC80(i, 0);
            break;
        case 1:
            if (gUnknown_02022CFC->unk82E4[i].unk12 != 1 || gUnknown_02022CFC->unk82E4[i].unkE != gUnknown_02022CFC->unk9A[i])
            {
                if (i == gUnknown_02022CFC->unk6)
                    gUnknown_02022CFC->unk82E4[i].unk12 = 1;

                whichSound |= 0x1;
                gUnknown_02022CFC->unk82E4[i].unk4 = 0x7FFFFFFF;
                gUnknown_02022CFC->unk9A[i] = gUnknown_02022CFC->unk82E4[i].unkE;
            }

            sub_802C398(i);
            break;
        case 2:
            if (gUnknown_02022CFC->unk82E4[i].unk12 != 2)
            {
                if (i == gUnknown_02022CFC->unk6)
                    gUnknown_02022CFC->unk82E4[i].unk12 = 2;

                whichSound |= 0x2;
                sub_802DD88(i);
            }
            break;
        }
    }

    if (whichSound & 0x2)
        PlaySE(SE_RG_POKE_JUMP_FAILURE);
    else if (whichSound & 0x1)
        PlaySE(SE_LEDGE);
}

static const s8 gUnknown_082FB65C[][48] =
{
    {-3, -6, -8, -10, -13, -15, -17, -19, -21, -23, -25, -27, -28, -29, -30, -30, -30, -28, -27,
    -26, -25, -23, -22, -20, -18, -17, -15, -13, -11, -8, -6, -4, -1},

    {-3, -6, -9, -11, -14, -16, -18, -20, -22, -24, -26, -28, -29, -30, -30, -28, -26, -24, -22,
    -20, -18, -16, -14, -11, -9, -6, -4, -1},

    {-3, -6, -9, -11, -13, -15, -17, -19, -21, -23, -25, -27, -28, -29, -30, -30, -30, -30, -29,
    -29, -28, -28, -27, -27, -26, -25, -24, -22, -20, -18, -16, -14,
    -12, -11, -9, -6, -4, -1},
};

static void sub_802C398(int multiplayerId)
{
    int var0;
    int var1;
    struct PokemonJump1_82E4 *player;

    if (gUnknown_02022CFC->unk68)
        return;

    player = &gUnknown_02022CFC->unk82E4[multiplayerId];
    if (player->unk4 != 0x7FFFFFFF)
    {
        player->unk4++;
        var0 = player->unk4;
    }
    else
    {
        var0 = gUnknown_02022CFC->unk4A - player->unkE;
        if (var0 >= 65000)
        {
            var0 -= 65000;
            var0 += gUnknown_02022CFC->unk4A;
        }

        player->unk4 = var0;
    }

    if (var0 < 4)
        return;

    var0 -= 4;
    if (var0 < 48)
        var1 = gUnknown_082FB65C[player->unkC][var0];
    else
        var1 = 0;

    sub_802DC80(multiplayerId, var1);
    if (!var1 && multiplayerId == gUnknown_02022CFC->unk6)
        sub_802C1BC();

    player->unk0 = var1;
}

static void sub_802C43C(void)
{
    if (gUnknown_02022CFC->unk14 == 8 && gUnknown_02022CFC->unk18 == 7)
    {
        if (gUnknown_02022CFC->unk58 == 0)
        {
            sub_802C780();
            gUnknown_02022CFC->unk54 = 0;
            gUnknown_02022CFC->unk58 = 1;
            gUnknown_02022CFC->unk70.unk1 = 0;
        }
        else
        {
            if (gUnknown_02022CFC->unk54 == 5)
            {
                gUnknown_02022CFC->unkC++;
                sub_802C7A0(gUnknown_02022CFC->unkC);
            }
            else
            {
                gUnknown_02022CFC->unkC = 0;
            }

            if (gUnknown_02022CFC->unk54 > 1)
            {
                gUnknown_02022CFC->unk64 = 1;
                memcpy(gUnknown_02022CFC->unk86, gUnknown_02022CFC->unk81, sizeof(u8) * MAX_RFU_PLAYERS);
            }

            sub_802C780();
            gUnknown_02022CFC->unk54 = 0;
            gUnknown_02022CFC->unk58 = 1;
            gUnknown_02022CFC->unk70.unk1 = 0;
            if (gUnknown_02022CFC->unk70.unk4 < 9999)
                gUnknown_02022CFC->unk70.unk4++;

            sub_802C688(10);
            sub_802AE14(3);
        }
    }

    if (gUnknown_02022CFC->unk64 && (sub_802C618() == TRUE || !gUnknown_02022CFC->unk14))
    {
        int var0 = sub_802C73C(gUnknown_02022CFC->unk86);
        sub_802C688(sub_802C790(var0));
        sub_802AE14(3);
        gUnknown_02022CFC->unk64 = 0;
    }

    if (gUnknown_02022CFC->unk58)
    {
        int var1 = sub_802C6B0();
        if (var1 > gUnknown_02022CFC->unk54)
        {
            gUnknown_02022CFC->unk54 = var1;
            memcpy(gUnknown_02022CFC->unk81, gUnknown_02022CFC->unk7C, sizeof(u8) * MAX_RFU_PLAYERS);
        }
    }
}

static bool32 sub_802C538(void)
{
    int i;

    if (gUnknown_02022CFC->unk14 == 6 && !gUnknown_02022CFC->unk83AC->unk0)
    {
        if (gUnknown_02022CFC->unk83AC->unk12 == 1 && sub_802C0DC() == 1)
        {
            gUnknown_02022CFC->unk83AC->unk14 = 1;
        }
        else
        {
            sub_802C18C();
            sub_802AE14(3);
        }
    }

    if (gUnknown_02022CFC->unk14 == 7
     && gUnknown_02022CFC->unk18 == 6
     && gUnknown_02022CFC->unk83AC->unk10 != 2)
    {
        gUnknown_02022CFC->unk83AC->unk14 = 1;
        sub_802AE14(3);
    }

    for (i = 0; i < gUnknown_02022CFC->unk5; i++)
    {
        if (gUnknown_02022CFC->unk82E4[i].unk10 == 2)
            return FALSE;
    }

    return TRUE;
}

static bool32 sub_802C5DC(void)
{
    int i;
    int numPlayers = gUnknown_02022CFC->unk5;
    int count = 0;
    for (i = 0; i < numPlayers; i++)
    {
        if (gUnknown_02022CFC->unk82E4[i].unk14)
            count++;
    }

    return count == numPlayers;
}

static bool32 sub_802C618(void)
{
    int i;
    for (i = 0; i < gUnknown_02022CFC->unk5; i++)
    {
        if (gUnknown_02022CFC->unk82E4[i].unk14 != 1)
            return FALSE;
    }

    return TRUE;
}

static bool32 sub_802C650(void)
{
    int i;

    if (gUnknown_02022CFC->unk45 == 1)
        return FALSE;

    for (i = 1; i < gUnknown_02022CFC->unk5; i++)
    {
        if (gUnknown_02022CFC->unk90[i] == 1)
            return FALSE;
    }

    return TRUE;
}

static void sub_802C688(int arg0)
{
    gUnknown_02022CFC->unk70.unk8 += arg0;
    gUnknown_02022CFC->unk5C = 1;
    if (gUnknown_02022CFC->unk70.unk8 >= 99990)
        gUnknown_02022CFC->unk70.unk8 = 99990;
}

static int sub_802C6B0(void)
{
    int i;
    int count = 0;
    int numPlayers = gUnknown_02022CFC->unk5;

    for (i = 0; i < numPlayers; i++)
    {
        if (gUnknown_02022CFC->unk82E4[i].unk0 == -30)
        {
            gUnknown_02022CFC->unk7C[i] = 1;
            count++;
        }
        else
        {
            gUnknown_02022CFC->unk7C[i] = 0;
        }
    }

    return count;
}

static bool32 AreLinkQueuesEmpty(void)
{
    return !Rfu.recvQueue.count && !Rfu.sendQueue.count;
}

static int sub_802C73C(u8 *arg0)
{
    int i;
    int flags;
    int count;

    for (i = 0, flags = 0, count = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (arg0[i])
        {
            flags |= 1 << i;
            count++;
        }
    }

    gUnknown_02022CFC->unk70.unk1 = flags;
    if (flags)
        gUnknown_02022CFC->unk4D = 1;

    return count;
}

static void sub_802C780(void)
{
    gUnknown_02022CFC->unk44 = 0;
}

static const int gUnknown_082FB6EC[] = {0, 0, 0x32, 0x64, 0xc8, 0x1f4};

static int sub_802C790(int arg0)
{
    return gUnknown_082FB6EC[arg0];
}

static void sub_802C7A0(u16 arg0)
{
    if (arg0 > gUnknown_02022CFC->unkE)
        gUnknown_02022CFC->unkE = arg0;
}

static const u16 gUnknown_082FB704[] = {0x8a, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93};
static const u32 gUnknown_082FB714[][2] =
{
    {0x1388, 1},
    {0x1f40, 2},
    {0x2ee0, 3},
    {0x3e80, 4},
    {0x4e20, 5},
};

static bool32 sub_802C7BC(void)
{
    if (gUnknown_02022CFC->unk70.unk8 >= gUnknown_082FB714[0][0])
        return TRUE;
    else
        return FALSE;
}

static u16 sub_802C7E0(void)
{
    u16 lo = sub_802C818();
    u16 hi = sub_802C838();
    return (hi << 12) | (lo & 0xFFF);
}

static void sub_802C808(u16 arg0, u16 *arg1, u16 *arg2)
{
    *arg2 = arg0 >> 12;
    *arg1 = arg0 & 0xFFF;
}

static u16 sub_802C818(void)
{
    u16 index = Random() % ARRAY_COUNT(gUnknown_082FB704);
    return gUnknown_082FB704[index];
}

static u16 sub_802C838(void)
{
    u32 val, i;

    val = 0;
    for (i = 0; i < 5; i++)
    {
        if (gUnknown_02022CFC->unk70.unk8 < gUnknown_082FB714[i][0])
            break;
        else if (1)
            val = gUnknown_082FB714[i][1];
        else
            break;
    }

    return val;
}

static u16 sub_802C880(u16 item, u16 quantity)
{
    while (quantity && !CheckBagHasSpace(item, quantity))
        quantity--;

    return quantity;
}

static u16 sub_802C8AC(void)
{
    return GetLinkPlayerCount();
}

static u16 sub_802C8BC(void)
{
    return gUnknown_02022CFC->unk6;
}

static struct PokemonJump1_MonInfo *sub_802C8C8(u8 multiplayerId)
{
    return &gUnknown_02022CFC->unk82A8[multiplayerId];
}

static u8 *sub_802C8E8(u8 multiplayerId)
{
    return gUnknown_02022CFC->unk82E4[multiplayerId].unk1C;
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

// Large group of data.
static const u16 gPkmnJumpPal1[] = INCBIN_U16("graphics/link_games/pkmnjump_pal1.gbapal");
static const u16 gPkmnJumpPal2[] = INCBIN_U16("graphics/link_games/pkmnjump_pal2.gbapal");

static const u32 gPkmnJumpRopeGfx1[] = INCBIN_U32("graphics/link_games/pkmnjump_rope1.4bpp.lz");
static const u32 gPkmnJumpRopeGfx2[] = INCBIN_U32("graphics/link_games/pkmnjump_rope2.4bpp.lz");
static const u32 gPkmnJumpRopeGfx3[] = INCBIN_U32("graphics/link_games/pkmnjump_rope3.4bpp.lz");
static const u32 gPkmnJumpRopeGfx4[] = INCBIN_U32("graphics/link_games/pkmnjump_rope4.4bpp.lz");

static const u32 gPkmnJumpStarGfx[] = INCBIN_U32("graphics/link_games/pkmnjump_star.4bpp.lz");

static const struct CompressedSpriteSheet gUnknown_082FBE08[] =
{
    {gPkmnJumpRopeGfx1, 0x600, 5},
    {gPkmnJumpRopeGfx2, 0x0c00, 6},
    {gPkmnJumpRopeGfx3, 0x0600, 7},
    {gPkmnJumpRopeGfx4, 0x0600, 8},
    {gPkmnJumpStarGfx, 0x0200, 10},
};

static const struct SpritePalette gUnknown_082FBE30[] =
{
    {gPkmnJumpPal1, 5},
    {gPkmnJumpPal2, 6},
};

// Forward declarations.
static const struct OamData sOamData_82FBEC8;
static const struct SpriteTemplate gUnknown_082FBF78;
static const struct SpriteTemplate gUnknown_082FBF90;
static const struct SpriteTemplate gUnknown_082FBFA8;
static const struct SpriteTemplate gUnknown_082FBFC0;

static const struct SpriteTemplate gUnknown_082FBE40 =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_82FBEC8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const s16 gUnknown_082FBE58[][10] =
{
    {0x60, 0x60, 0x60, 0x72, 0x78, 0x78, 0x78, 0x72, 0x60, 0x60},
    {0x46, 0x50, 0x60, 0x72, 0x78, 0x80, 0x78, 0x72, 0x60, 0x50},
    {0x32, 0x48, 0x60, 0x72, 0x80, 0x88, 0x80, 0x72, 0x60, 0x48},
    {0x2a, 0x48, 0x60, 0x72, 0x80, 0x88, 0x80, 0x72, 0x60, 0x48},
};

static const s16 gUnknown_082FBEA8[] = {0x10, 0x28, 0x48, 0x68, 0x88, 0xa8, 0xc8, 0xe0};

static const struct SpriteTemplate *const gUnknown_082FBEB8[] =
{
    &gUnknown_082FBF78,
    &gUnknown_082FBF90,
    &gUnknown_082FBFA8,
    &gUnknown_082FBFC0,
};

static const struct OamData sOamData_82FBEC8 =
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

static const struct OamData sOamData_82FBED0 =
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

static const struct OamData sOamData_82FBED8 =
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

static const struct OamData sOamData_82FBEE0 =
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

static const union AnimCmd sSpriteAnim_82FBEE8[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBEF0[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBEF8[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF00[] =
{
    ANIMCMD_FRAME(24, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF08[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF10[] =
{
    ANIMCMD_FRAME(40, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF18[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF20[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF28[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF30[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF38[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBF40[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_82FBF48[] =
{
    sSpriteAnim_82FBEE8,
    sSpriteAnim_82FBEF0,
    sSpriteAnim_82FBEF8,
    sSpriteAnim_82FBF00,
    sSpriteAnim_82FBF08,
    sSpriteAnim_82FBF10
};

static const union AnimCmd *const sSpriteAnimTable_82FBF60[] =
{
    sSpriteAnim_82FBF18,
    sSpriteAnim_82FBF20,
    sSpriteAnim_82FBF28,
    sSpriteAnim_82FBF30,
    sSpriteAnim_82FBF38,
    sSpriteAnim_82FBF40
};

static const struct SpriteTemplate gUnknown_082FBF78 =
{
    .tileTag = 5,
    .paletteTag = 5,
    .oam = &sOamData_82FBED0,
    .anims = sSpriteAnimTable_82FBF48,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gUnknown_082FBF90 =
{
    .tileTag = 6,
    .paletteTag = 5,
    .oam = &sOamData_82FBED8,
    .anims = sSpriteAnimTable_82FBF60,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gUnknown_082FBFA8 =
{
    .tileTag = 7,
    .paletteTag = 5,
    .oam = &sOamData_82FBEE0,
    .anims = sSpriteAnimTable_82FBF48,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gUnknown_082FBFC0 =
{
    .tileTag = 8,
    .paletteTag = 5,
    .oam = &sOamData_82FBEE0,
    .anims = sSpriteAnimTable_82FBF48,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_82FBFD8 =
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

static const union AnimCmd sSpriteAnim_82FBFE0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FBFE8[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_82FC004[] =
{
    sSpriteAnim_82FBFE0,
    sSpriteAnim_82FBFE8
};

static const struct SpriteTemplate gUnknown_082FC00C =
{
    .tileTag = 10,
    .paletteTag = 5,
    .oam = &sOamData_82FBFD8,
    .anims = sSpriteAnimTable_82FC004,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// Back to code
static void sub_802C974(struct PokemonJump2 *arg0)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_082FBE08); i++)
        LoadCompressedSpriteSheet(&gUnknown_082FBE08[i]);

    for (i = 0; i < ARRAY_COUNT(gUnknown_082FBE30); i++)
        LoadSpritePalette(&gUnknown_082FBE30[i]);

    arg0->unkE = IndexOfSpritePaletteTag(5);
    arg0->unkF = IndexOfSpritePaletteTag(6);
}

static void sub_802C9BC(struct Sprite *sprite)
{
    int i;
    for (i = 0; i < 8; i++)
        sprite->data[i] = 0;
}

static void sub_802C9D4(struct PokemonJump2 *arg0, struct PokemonJump1_MonInfo *jumpMon, s16 x, s16 y, u8 multiplayerId)
{
    struct SpriteTemplate spriteTemplate;
    struct SpriteSheet spriteSheet;
    struct CompressedSpritePalette spritePalette;
    u8 *buffer;
    u8 *unusedBuffer;
    u8 subpriority;
    u8 spriteId;

    spriteTemplate = gUnknown_082FBE40;
    buffer = Alloc(0x2000);
    unusedBuffer = Alloc(0x800);
    if (multiplayerId == sub_802C8BC())
        subpriority = 3;
    else
        subpriority = multiplayerId + 4;

    if (buffer && unusedBuffer)
    {
        HandleLoadSpecialPokePic(
            &gMonStillFrontPicTable[jumpMon->species],
            buffer,
            jumpMon->species,
            jumpMon->personality);

        spriteSheet.data = buffer;
        spriteSheet.tag = multiplayerId;
        spriteSheet.size = 0x800;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetMonSpritePalFromSpeciesAndPersonality(jumpMon->species, jumpMon->otId, jumpMon->personality);
        spritePalette.tag = multiplayerId;
        LoadCompressedSpritePalette(&spritePalette);

        Free(buffer);
        Free(unusedBuffer);

        spriteTemplate.tileTag += multiplayerId;
        spriteTemplate.paletteTag += multiplayerId;
        spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            arg0->unk81A8[multiplayerId] = &gSprites[spriteId];
            arg0->unk81FC[multiplayerId] = subpriority;
            return;
        }
    }

    arg0->unk81A8[multiplayerId] = NULL;
}

static void sub_802CB14(struct PokemonJump2 *arg0, int multiplayerId)
{
    sub_802C9BC(arg0->unk81BC[multiplayerId]);
    arg0->unk81BC[multiplayerId]->data[7] = arg0->unk81A8[multiplayerId] - gSprites;
    arg0->unk81BC[multiplayerId]->invisible = 0;
    arg0->unk81BC[multiplayerId]->pos1.y = 96;
    arg0->unk81BC[multiplayerId]->callback = sub_802CB7C;
    StartSpriteAnim(arg0->unk81BC[multiplayerId], 1);
}

static void sub_802CB7C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (sprite->animEnded)
        {
            sprite->invisible = 1;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    case 1:
        sprite->pos1.y--;
        sprite->data[1]++;
        if (sprite->pos1.y <= 72)
        {
            sprite->pos1.y = 72;
            sprite->data[0]++;
        }
        break;
    case 2:
        if (++sprite->data[1] >= 48)
        {
            sprite->invisible = 1;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void sub_802CBF0(struct PokemonJump2 *arg0, int multiplayerId)
{
    arg0->unk81A8[multiplayerId]->callback = sub_802CC40;
    arg0->unk81A8[multiplayerId]->pos2.y = 0;
    sub_802C9BC(arg0->unk81A8[multiplayerId]);
}

static bool32 sub_802CC18(struct PokemonJump2 *arg0, int multiplayerId)
{
    return arg0->unk81A8[multiplayerId]->callback == sub_802CC40;
}

static void sub_802CC40(struct Sprite *sprite)
{
    if (++sprite->data[1] > 1)
    {
        if (++sprite->data[2] & 1)
            sprite->pos2.y = 2;
        else
            sprite->pos2.y = -2;

        sprite->data[1] = 0;
    }

    if (sprite->data[2] > 12)
    {
        sprite->pos2.y = 0;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_802CC88(struct PokemonJump2 *arg0, int multiplayerId)
{
    sub_802C9BC(arg0->unk81A8[multiplayerId]);
    arg0->unk81A8[multiplayerId]->callback = sub_802CD08;
}

static void sub_802CCB0(struct PokemonJump2 *arg0)
{
    int i;
    u16 numPlayers = sub_802C8AC();
    for (i = 0; i < numPlayers; i++)
    {
        if (arg0->unk81A8[i]->callback == sub_802CD08)
        {
            arg0->unk81A8[i]->invisible = 0;
            arg0->unk81A8[i]->callback = SpriteCallbackDummy;
            arg0->unk81A8[i]->subpriority = 10;
        }
    }
}

static void sub_802CD08(struct Sprite *sprite)
{
    if (++sprite->data[0] > 3)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
    }
}

static void sub_802CD3C(struct PokemonJump2 *arg0)
{
    int i;
    u16 numPlayers = sub_802C8AC();
    for (i = 0; i < numPlayers; i++)
        arg0->unk81A8[i]->subpriority = arg0->unk81FC[i];
}

static void sub_802CD70(struct PokemonJump2 *arg0, int multiplayerId)
{
    sub_802C9BC(arg0->unk81A8[multiplayerId]);
    arg0->unk81A8[multiplayerId]->callback = sub_802CDD4;
}

static bool32 sub_802CD98(struct PokemonJump2 *arg0)
{
    int i;
    u16 numPlayers = sub_802C8AC();
    for (i = 0; i < numPlayers; i++)
    {
        if (arg0->unk81A8[i]->callback == sub_802CDD4)
            return TRUE;
    }

    return FALSE;
}

static void sub_802CDD4(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        PlaySE(SE_BIKE_HOP);
        sprite->data[1] = 0;
        sprite->data[0]++;
        // fall through
    case 1:
        sprite->data[1] += 4;
        if (sprite->data[1] > 0x7F)
            sprite->data[1] = 0;

        sprite->pos2.y = -(gSineTable[sprite->data[1]] >> 3);
        if (sprite->data[1] == 0)
        {
            if (++sprite->data[2] < 2)
                sprite->data[0] = 0;
            else
                sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

static void sub_802CE48(struct PokemonJump2 *arg0, s16 x, s16 y, u8 multiplayerId)
{
    u8 spriteId = CreateSprite(&gUnknown_082FC00C, x, y, 1);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].invisible = 1;
        arg0->unk81BC[multiplayerId] = &gSprites[spriteId];
    }
}

static void sub_802CE9C(struct PokemonJump2 *arg0)
{
    int i;
    int count;
    u8 spriteId;

    count = 0;
    for (i = 0; i < 4; i++)
    {
        spriteId = CreateSprite(gUnknown_082FBEB8[i], gUnknown_082FBEA8[count], gUnknown_082FBE58[i][0], 2);
        arg0->unk81D0[count] = &gSprites[spriteId];
        count++;
    }

    for (i = 3; i >= 0; i--)
    {
        spriteId = CreateSprite(gUnknown_082FBEB8[i], gUnknown_082FBEA8[count], gUnknown_082FBE58[i][0], 2);
        arg0->unk81D0[count] = &gSprites[spriteId];
        arg0->unk81D0[count]->hFlip = 1;
        count++;
    }
}

static void sub_802CF50(struct PokemonJump2 *arg0, int arg1)
{
    int i, count, palNum;
    int priority;

    if (arg1 > 5)
    {
        arg1 = 10 - arg1;
        priority = 3;
        palNum = arg0->unkF;
    }
    else
    {
        priority = 2;
        palNum = arg0->unkE;
    }

    count = 0;
    for (i = 0; i < 4; i++)
    {
        arg0->unk81D0[count]->pos1.y = gUnknown_082FBE58[i][arg1];
        arg0->unk81D0[count]->oam.priority = priority;
        arg0->unk81D0[count]->oam.paletteNum = palNum;
        StartSpriteAnim(arg0->unk81D0[count], arg1);
        count++;
    }

    for (i = 3; i >= 0; i--)
    {
        arg0->unk81D0[count]->pos1.y = gUnknown_082FBE58[i][arg1];
        arg0->unk81D0[count]->oam.priority = priority;
        arg0->unk81D0[count]->oam.paletteNum = palNum;
        StartSpriteAnim(arg0->unk81D0[count], arg1);
        count++;
    }
}

static void sub_802D044(struct PokemonJump2 *arg0)
{
    StartMinigameCountdown(9, 7, 120, 80, 0);
    sub_802CD3C(arg0);
}

static bool32 sub_802D068(void)
{
    return IsMinigameCountdownRunning();
}

static void sub_802D074(struct PokemonJump2 *arg0)
{
    u8 taskId;

    gUnknown_02022D00 = arg0;
    sub_802D0BC(gUnknown_02022D00);
    taskId = CreateTask(sub_802D12C, 3);
    gUnknown_02022D00->unk6 = taskId;
    SetWordTaskArg(gUnknown_02022D00->unk6, 2, (u32) gUnknown_02022D00);
    sub_802D108(sub_802D150);
}

static void sub_802D0AC(void)
{
    FreeAllWindowBuffers();
    DigitObjUtil_Free();
}

static void sub_802D0BC(struct PokemonJump2 *arg0)
{
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk12 = 0xFF;
}

// Gfx
static const u16 gPkmnJumpPal3[] = INCBIN_U16("graphics/link_games/pkmnjump_pal3.gbapal");

static const u16 gPkmnJumpBgPal[] = INCBIN_U16("graphics/link_games/pkmnjump_bg.gbapal");
static const u32 gPkmnJumpBgGfx[] = INCBIN_U32("graphics/link_games/pkmnjump_bg.4bpp.lz");
static const u32 gPkmnJumpBgTilemap[] = INCBIN_U32("graphics/link_games/pkmnjump_bg.bin.lz");

static const u16 gPkmnJumpVenusaurPal[] = INCBIN_U16("graphics/link_games/pkmnjump_venusaur.gbapal");
static const u32 gPkmnJumpVenusaurGfx[] = INCBIN_U32("graphics/link_games/pkmnjump_venusaur.4bpp.lz");
static const u32 gPkmnJumpVenusaurTilemap[] = INCBIN_U32("graphics/link_games/pkmnjump_venusaur.bin.lz");

static const u16 gPkmnJumpResultsPal[] = INCBIN_U16("graphics/link_games/pkmnjump_results.gbapal");
static const u32 gPkmnJumpResultsGfx[] = INCBIN_U32("graphics/link_games/pkmnjump_results.4bpp.lz");
static const u32 gPkmnJumpResultsTilemap[] = INCBIN_U32("graphics/link_games/pkmnjump_results.bin.lz");

static const struct BgTemplate gUnknown_082FE164[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 27,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate gUnknown_082FE174[] =
{
    {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 0,
        .width = 6,
        .height = 2,
        .paletteNum = 2,
        .baseBlock = 0x13,
    },
    {
        .bg = 0,
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
} static const gUnknown_082FE18C[] =
{
    {0x00, sub_802D150},
    {0x01, sub_802D2E4},
    {0x02, sub_802D350},
    {0x03, sub_802D3BC},
    {0x04, sub_802D448},
    {0x05, sub_802D4F4},
    {0x06, sub_802D598},
    {0x07, sub_802D5E4},
    {0x09, sub_802D72C},
    {0x08, sub_802D688},
};

static void sub_802D0C8(int arg0)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_082FE18C); i++)
    {
        if (gUnknown_082FE18C[i].id == arg0)
            sub_802D108(gUnknown_082FE18C[i].func);
    }
}

static bool32 sub_802D0F0(void)
{
    return (gUnknown_02022D00->unk0 != 1);
}

static void sub_802D108(void (*func)(void))
{
    SetWordTaskArg(gUnknown_02022D00->unk6, 0, (u32) func);
    gUnknown_02022D00->unk4 = 0;
    gUnknown_02022D00->unk0 = 0;
}

static void sub_802D12C(u8 taskId)
{
    if (!gUnknown_02022D00->unk0)
    {
        void (*func)(void) = (void *)(GetWordTaskArg(taskId, 0));

        func();
    }
}

static void sub_802D150(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_082FE164, ARRAY_COUNT(gUnknown_082FE164));
        InitWindows(gUnknown_082FE174);
        ResetTempTileDataBuffers();
        sub_802C974(gUnknown_02022D00);
        sub_802DD08();
        LoadPalette(gPkmnJumpBgPal, 0, 0x20);
        DecompressAndCopyTileDataToVram(3, gPkmnJumpBgGfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(3, gPkmnJumpBgTilemap, 0, 0, 1);
        LoadPalette(gPkmnJumpVenusaurPal, 0x30, 0x20);
        DecompressAndCopyTileDataToVram(2, gPkmnJumpVenusaurGfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(2, gPkmnJumpVenusaurTilemap, 0, 0, 1);
        LoadPalette(gPkmnJumpResultsPal, 0x10, 0x20);
        DecompressAndCopyTileDataToVram(1, gPkmnJumpResultsGfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(1, gPkmnJumpResultsTilemap, 0, 0, 1);
        LoadPalette(gPkmnJumpPal3, 0x20, 0x20);
        SetBgTilemapBuffer(0, gUnknown_02022D00->tilemapBuffer);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        sub_802DB8C();
        sub_802DD64(0);
        sub_8098C6C(0, 1, 0xE0);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(1);
        ResetBgPositions();
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            sub_802DBF8();
            sub_802CE9C(gUnknown_02022D00);
            sub_802CF50(gUnknown_02022D00, 6);
            ShowBg(3);
            ShowBg(0);
            ShowBg(2);
            HideBg(1);
            gUnknown_02022D00->unk4++;
        }
        break;
    case 2:
        gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D2E4(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        sub_802DE1C();
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_802DF70(FALSE);
            gUnknown_02022D00->unk4++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_802DFD4();
            gUnknown_02022D00->unk4++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D350(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        sub_802DE1C();
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_802DF70(TRUE);
            gUnknown_02022D00->unk4++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_802DFD4();
            gUnknown_02022D00->unk4++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D3BC(void)
{
    int i, numPlayers;

    numPlayers = sub_802C8AC();
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        for (i = 0; i < numPlayers; i++)
            ClearWindowTilemap(gUnknown_02022D00->unk1C[i]);

        CopyBgTilemapBufferToVram(0);
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            for (i = 0; i < numPlayers; i++)
                RemoveWindow(gUnknown_02022D00->unk1C[i]);

            gUnknown_02022D00->unk0 = 1;
        }
        break;
    }
}

static void sub_802D448(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        gUnknown_02022D00->unk12 = sub_802DA9C(1, 8, 20, 2);
        AddTextPrinterParameterized(gUnknown_02022D00->unk12, 1, gText_WantToPlayAgain2, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_02022D00->unk12, 2);
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022D00->unk12);
            DrawTextBorderOuter(gUnknown_02022D00->unk12, 1, 14);
            sub_802DB18(23, 7, 0);
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022D00->unk4++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D4F4(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        gUnknown_02022D00->unk12 = sub_802DA9C(2, 7, 26, 4);
        AddTextPrinterParameterized(gUnknown_02022D00->unk12, 1, gText_SavingDontTurnOffPower, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_02022D00->unk12, 2);
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022D00->unk12);
            DrawTextBorderOuter(gUnknown_02022D00->unk12, 1, 14);
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022D00->unk4++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D598(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        sub_802DA14();
        sub_8198C78();
        CopyBgTilemapBufferToVram(0);
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!sub_802DA44() && !IsDma3ManagerBusyWithBgCopy())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D5E4(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        gUnknown_02022D00->unk12 = sub_802DA9C(2, 8, 22, 4);
        AddTextPrinterParameterized(gUnknown_02022D00->unk12, 1, gText_SomeoneDroppedOut2, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_02022D00->unk12, 2);
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022D00->unk12);
            DrawTextBorderOuter(gUnknown_02022D00->unk12, 1, 14);
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022D00->unk4++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D688(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        gUnknown_02022D00->unk12 = sub_802DA9C(7, 10, 16, 2);
        AddTextPrinterParameterized(gUnknown_02022D00->unk12, 1, gText_CommunicationStandby4, 0, 1, TEXT_SPEED_FF, NULL);
        CopyWindowToVram(gUnknown_02022D00->unk12, 2);
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022D00->unk12);
            DrawTextBorderOuter(gUnknown_02022D00->unk12, 1, 14);
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022D00->unk4++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D72C(void)
{
    switch (gUnknown_02022D00->unk4)
    {
    case 0:
        sub_802D044(gUnknown_02022D00);
        gUnknown_02022D00->unk4++;
        break;
    case 1:
        if (!sub_802D068())
            gUnknown_02022D00->unk0 = 1;
        break;
    }
}

static void sub_802D764(void)
{
    gUnknown_02022D00->unkA = 0;
    gUnknown_02022D00->unkB = 0;
    gUnknown_02022D00->unkC = 6;
    sub_802DC9C(gUnknown_02022D00->unkC);
}

static bool32 sub_802D788(void)
{
    switch (gUnknown_02022D00->unkA)
    {
    case 0:
        gUnknown_02022D00->unkB++;
        if (gUnknown_02022D00->unkB > 10)
        {
            gUnknown_02022D00->unkB = 0;
            gUnknown_02022D00->unkC++;
            if (gUnknown_02022D00->unkC >= 10)
            {
                gUnknown_02022D00->unkC = 0;
                gUnknown_02022D00->unkA++;
            }
        }
        sub_802DC9C(gUnknown_02022D00->unkC);
        if (gUnknown_02022D00->unkC != 7)
            break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

static void sub_802D7E8(u16 itemId, u16 quantity)
{
    CopyItemNameHandlePlural(itemId, gUnknown_02022D00->txtBuff[0], quantity);
    ConvertIntToDecimalStringN(gUnknown_02022D00->txtBuff[1], quantity, STR_CONV_MODE_LEFT_ALIGN, 1);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gUnknown_02022D00->txtBuff[0]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gUnknown_02022D00->txtBuff[1]);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gUnknown_02022D00->strBuff, gText_AwesomeWonF701F700);
    gUnknown_02022D00->unk12 = sub_802DA9C(4, 8, 22, 4);
    AddTextPrinterParameterized(gUnknown_02022D00->unk12, 1, gUnknown_02022D00->strBuff, 0, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(gUnknown_02022D00->unk12, 2);
    gUnknown_02022D00->unk14 = MUS_LEVEL_UP;
    gUnknown_02022D00->unkD = 0;
}

static void sub_802D884(u16 itemId)
{
    CopyItemName(itemId, gUnknown_02022D00->txtBuff[0]);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gUnknown_02022D00->txtBuff[0]);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gUnknown_02022D00->strBuff, gText_FilledStorageSpace2);
    gUnknown_02022D00->unk12 = sub_802DA9C(4, 8, 22, 4);
    AddTextPrinterParameterized(gUnknown_02022D00->unk12, 1, gUnknown_02022D00->strBuff, 0, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(gUnknown_02022D00->unk12, 2);
    gUnknown_02022D00->unk14 = 0;
    gUnknown_02022D00->unkD = 0;
}

static void sub_802D8FC(u16 itemId)
{
    CopyItemName(itemId, gUnknown_02022D00->txtBuff[0]);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gUnknown_02022D00->txtBuff[0]);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gUnknown_02022D00->strBuff, gText_CantHoldMore);
    gUnknown_02022D00->unk12 = sub_802DA9C(4, 9, 22, 2);
    AddTextPrinterParameterized(gUnknown_02022D00->unk12, 1, gUnknown_02022D00->strBuff, 0, 1, TEXT_SPEED_FF, NULL);
    CopyWindowToVram(gUnknown_02022D00->unk12, 2);
    gUnknown_02022D00->unk14 = 0;
    gUnknown_02022D00->unkD = 0;
}

static bool32 sub_802D974(void)
{
    switch (gUnknown_02022D00->unkD)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(gUnknown_02022D00->unk12);
            DrawTextBorderOuter(gUnknown_02022D00->unk12, 1, 14);
            CopyBgTilemapBufferToVram(0);
            gUnknown_02022D00->unkD++;
        }
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            break;
        if (gUnknown_02022D00->unk14 == 0)
        {
            gUnknown_02022D00->unkD += 2;
            return FALSE;
        }
        PlayFanfare(gUnknown_02022D00->unk14);
        gUnknown_02022D00->unkD++;
    case 2:
        if (!IsFanfareTaskInactive())
            break;
        gUnknown_02022D00->unkD++;
    case 3:
        return FALSE;
    }

    return TRUE;
}

static void sub_802DA14(void)
{
    if (gUnknown_02022D00->unk12 != 0xFF)
    {
        rbox_fill_rectangle(gUnknown_02022D00->unk12);
        CopyWindowToVram(gUnknown_02022D00->unk12, 1);
        gUnknown_02022D00->unkD = 0;
    }
}

// Can't match this without the ugly GOTO, oh well.
static bool32 sub_802DA44(void)
{
    if (gUnknown_02022D00->unk12 == 0xFF)
    {
    RET_FALSE:
        return FALSE;
    }

    if (gUnknown_02022D00->unkD == 0)
    {
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            RemoveWindow(gUnknown_02022D00->unk12);
            gUnknown_02022D00->unk12 = 0xFF;
            gUnknown_02022D00->unkD++;
            goto RET_FALSE;
        }
    }
    else if (gUnknown_02022D00->unkD == 1)
        goto RET_FALSE;

    return TRUE;
}

static s8 sub_802DA8C(void)
{
    return Menu_ProcessInputNoWrapClearOnChoose();
}

static u32 sub_802DA9C(u32 left, u32 top, u32 width, u32 height)
{
    u32 windowId;
    struct WindowTemplate window;

    window.bg = 0;
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

static void sub_802DB18(u16 left, u16 top, u8 cursorPos)
{
    struct WindowTemplate window;
    u8 a = cursorPos;

    window.bg = 0;
    window.tilemapLeft = left;
    window.tilemapTop = top;
    window.width = 6;
    window.height = 4;
    window.paletteNum = 2;
    window.baseBlock = 0x2B;

    CreateYesNoMenu(&window, 1, 0xD, a);
}

static void sub_802DB8C(void)
{
    u8 color[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};

    PutWindowTilemap(0);
    PutWindowTilemap(1);
    FillWindowPixelBuffer(0, 0);
    FillWindowPixelBuffer(1, 0);
    AddTextPrinterParameterized3(0, 0, 0, 1, color, 0, gText_SpacePoints2);
    AddTextPrinterParameterized3(1, 0, 0, 1, color, 0, gText_SpaceTimes3);
}

static const u8 gUnknown_082FE1DF[] = {2, 2, 0, 0, 1, 1, 1, 0, 0, 2, 0, 0, 0};

static const struct CompressedSpriteSheet gUnknown_082FE1EC = {gUnknown_082FF1F8, 0, 0x320};
static const struct SpritePalette gUnknown_082FE1F4 = {gUnknown_082FF1D8, 0x320};

static const u16 gUnknown_082FE1FC[] = {0x06, 0x08, 0x10, 0x08};
static const u16 gUnknown_082FE204[] = {0x06, 0x08, 0x0b, 0x06, 0x10, 0x08};
static const u16 gUnknown_082FE210[] = {0x02, 0x06, 0x06, 0x08, 0x10, 0x08, 0x14, 0x06};
static const u16 gUnknown_082FE220[] = {0x02, 0x06, 0x06, 0x08, 0x0b, 0x06, 0x10, 0x08, 0x14, 0x06};

static const u16 *const gUnknown_082FE234[] =
{
    gUnknown_082FE1FC,
    gUnknown_082FE204,
    gUnknown_082FE210,
    gUnknown_082FE220,
};

static const s16 gUnknown_082FE244[] = {0x0058, 0x0098};
static const s16 gUnknown_082FE248[] = {0x0058, 0x0078, 0x0098};
static const s16 gUnknown_082FE24E[] = {0x0038, 0x0058, 0x0098, 0x00b8};
static const s16 gUnknown_082FE256[] = {0x0038, 0x0058, 0x0078, 0x0098, 0x00b8};

static const s16 *const gUnknown_082FE260[] =
{
    gUnknown_082FE244,
    gUnknown_082FE248,
    gUnknown_082FE24E,
    gUnknown_082FE256,
};

static void sub_802DBF8(void)
{
    int i, y, playersCount = sub_802C8AC();
    const s16 *xCoords = gUnknown_082FE260[playersCount - 2];

    for (i = 0; i < playersCount; i++)
    {
        struct PokemonJump1_MonInfo *info = sub_802C8C8(i);

        y = gMonFrontPicCoords[info->species].y_offset;
        sub_802C9D4(gUnknown_02022D00, info, *xCoords, y + 112, i);
        sub_802CE48(gUnknown_02022D00, *xCoords, 112, i);
        xCoords++;
    }
}

static void sub_802DC80(u32 id, s16 y)
{
    gUnknown_02022D00->unk81A8[id]->pos2.y = y;
}

static void sub_802DC9C(int id)
{
    sub_802CF50(gUnknown_02022D00, id);
    ChangeBgY(2, (gUnknown_082FE1DF[id] * 5) << 0xD, 0);
}

static int sub_802DCCC(u8 flags)
{
    int i, count;

    for (i = 0, count = 0; i < 5; i++)
    {
        if (flags & 1)
        {
            sub_802CB14(gUnknown_02022D00, i);
            count++;
        }
        flags >>= 1;
    }

    sub_802E00C(count - 2);
    return count;
}

static void sub_802DD08(void)
{
    struct DigitObjUtilTemplate template;
    struct DigitObjUtilTemplate *ptr = &template; // This temp variable is needed to match, don't ask me why.

    ptr->shape = SPRITE_SHAPE(8x8);
    ptr->size = SPRITE_SIZE(8x8);
    ptr->strConvMode = 0;
    ptr->priority = 1;
    ptr->oamCount = 5;
    ptr->xDelta = 8;
    ptr->x = 108;
    ptr->y = 6;
    ptr->spriteSheet = (void*) &gUnknown_082FE1EC;
    ptr->spritePal = &gUnknown_082FE1F4;

    DigitObjUtil_Init(2);
    DigitObjUtil_CreatePrinter(0, 0, ptr);

    template.oamCount = 4;
    template.x = 30;
    template.y = 6;
    DigitObjUtil_CreatePrinter(1, 0, &template);
}

static void sub_802DD64(int arg0)
{
    DigitObjUtil_PrintNumOn(0, arg0);
}

static void sub_802DD74(u16 arg0)
{
    DigitObjUtil_PrintNumOn(1, arg0);
}

static void sub_802DD88(u8 multiplayerId)
{
    sub_802CBF0(gUnknown_02022D00, multiplayerId);
}

static void sub_802DDA0(u8 multiplayerId)
{
    sub_802CC88(gUnknown_02022D00, multiplayerId);
}

static int sub_802DDB8(int multiplayerId)
{
    return sub_802CC18(gUnknown_02022D00, multiplayerId);
}

static void sub_802DDCC(void)
{
    sub_802CCB0(gUnknown_02022D00);
}

static void sub_802DDE0(void)
{
    sub_802CD3C(gUnknown_02022D00);
}

static void sub_802DDF4(int multiplayerId)
{
    sub_802CD70(gUnknown_02022D00, multiplayerId);
}

static int sub_802DE08(void)
{
    return sub_802CD98(gUnknown_02022D00);
}

static void sub_802DE1C(void)
{
    struct WindowTemplate window;
    int i, playersCount = sub_802C8AC();
    const u16 *winCoords = gUnknown_082FE234[playersCount - 2];

    window.bg = 0;
    window.width = 8;
    window.height = 2;
    window.paletteNum = 2;
    window.baseBlock = 0x2B;

    for (i = 0; i < playersCount; i++)
    {
        window.tilemapLeft = winCoords[0];
        window.tilemapTop = winCoords[1];
        gUnknown_02022D00->unk1C[i] = AddWindow(&window);
        ClearWindowTilemap(gUnknown_02022D00->unk1C[i]);
        window.baseBlock += 0x10;
        winCoords += 2;
    }

    CopyBgTilemapBufferToVram(0);
}

static void sub_802DED8(int multiplayerId, u8 clr1, u8 clr2, u8 clr3)
{
    u32 x;
    u8 colors[3] = {clr1, clr2, clr3};

    FillWindowPixelBuffer(gUnknown_02022D00->unk1C[multiplayerId], 0);
    x = 64 - GetStringWidth(1, sub_802C8E8(multiplayerId), -1);
    x /= 2;
    AddTextPrinterParameterized3(gUnknown_02022D00->unk1C[multiplayerId], 1, x, 1, colors, -1, sub_802C8E8(multiplayerId));
    CopyWindowToVram(gUnknown_02022D00->unk1C[multiplayerId], 2);
}

static void sub_802DF70(bool32 arg0)
{
    int i, var, playersCount = sub_802C8AC();

    if (!arg0)
    {
        for (i = 0; i < playersCount; i++)
            sub_802DED8(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY);
    }
    else
    {
        var = sub_802C8BC();
        for (i = 0; i < playersCount; i++)
        {
            if (var != i)
                sub_802DED8(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY);
            else
                sub_802DED8(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED);
        }
    }
}

static void sub_802DFD4(void)
{
    int i, playersCount = sub_802C8AC();

    for (i = 0; i < playersCount; i++)
        PutWindowTilemap(gUnknown_02022D00->unk1C[i]);
    CopyBgTilemapBufferToVram(0);
}

static void sub_802E00C(u8 arg0)
{
    gUnknown_02022D00->unk18 = 0;
    ChangeBgX(1, (arg0 / 2) << 16, 0);
    ChangeBgY(1, (((arg0 % 2) << 8) - 40) << 8, 0);
    ShowBg(1);
    CreateTask(sub_802E090, 4);
}

static bool32 sub_802E058(void)
{
    if (gUnknown_02022D00->unk18 >= 32)
    {
        return FALSE;
    }
    else
    {
        ChangeBgY(1, 128, 1);
        if (++gUnknown_02022D00->unk18 >= 32)
            HideBg(1);
        return TRUE;
    }
}

static void sub_802E090(u8 taskId)
{
    if (!sub_802E058())
        DestroyTask(taskId);
}

struct MonInfoPacket
{
    u8 id; // packet id
    u16 species;
    u32 personality;
    u32 otId;
};

static void sub_802E0AC(struct PokemonJump1_MonInfo *arg0)
{
    struct MonInfoPacket packet;
    packet.id = 1,
    packet.species = arg0->species,
    packet.otId = arg0->otId,
    packet.personality = arg0->personality,
    Rfu_SendPacket(&packet);
}

static bool32 sub_802E0D0(int multiplayerId, struct PokemonJump1_MonInfo *arg0)
{
    struct MonInfoPacket packet;

    if ((gRecvCmds[multiplayerId][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id == 1)
    {
        arg0->species = packet.species;
        arg0->otId = packet.otId;
        arg0->personality = packet.personality;
        return TRUE;
    }

    return FALSE;
}

struct UnkPacket2
{
    u8 id; // packet id
    u32 unk4;
    u32 unk8;
};

static void sub_802E120(u32 arg0)
{
    struct UnkPacket2 packet;
    packet.id = 2;
    packet.unk4 = arg0;
    Rfu_SendPacket(&packet);
}

struct UnkPacket3
{
    u8 id; // packet id
    u8 unk1;
    u8 unk2;
    u8 unk3_0:5;
    u8 unk3_1:3;
    u16 unk4;
    u16 unk6;
    u32 unk8_0:15;
    u32 unk8_1:17;
};

static void sub_802E138(struct PokemonJump1_82E4 *arg0, struct PokemonJump1Sub *arg1)
{
    struct UnkPacket3 packet;
    packet.id = 3;
    packet.unk8_1 = arg1->unk8;
    packet.unk3_0 = arg1->unk1;
    packet.unk1 = arg1->unk0;
    packet.unk6 = arg1->unk2;
    packet.unk8_0 = arg1->unk4;
    packet.unk2 = arg0->unk10;
    packet.unk3_1 = arg0->unk14;
    packet.unk4 = arg0->unkE;
    Rfu_SendPacket(&packet);
}

static bool32 sub_802E1BC(struct PokemonJump1_82E4 *arg0, struct PokemonJump1Sub *arg1)
{
    struct UnkPacket3 packet;

    if ((gRecvCmds[0][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[0][1], sizeof(packet));
    if (packet.id != 3)
        return FALSE;

    arg1->unk8 = packet.unk8_1;
    arg1->unk1 = packet.unk3_0;
    arg1->unk0 = packet.unk1;
    arg1->unk2 = packet.unk6;
    arg1->unk4 = packet.unk8_0;
    arg0->unk10 = packet.unk2;
    arg0->unk14 = packet.unk3_1;
    arg0->unkE = packet.unk4;
    return TRUE;
}

struct UnkPacket4
{
    u8 id; // packet id
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u16 unk4;
    u8 unk6;
    u16 unk8;
};

static void sub_802E234(struct PokemonJump1_82E4 *arg0, u8 arg1, u16 arg2)
{
    struct UnkPacket4 packet;
    packet.id = 4;
    packet.unk1 = arg0->unk10;
    packet.unk2 = arg0->unk14;
    packet.unk3 = arg0->unk18;
    packet.unk4 = arg0->unkE;
    packet.unk6 = arg1;
    packet.unk8 = arg2;
    Rfu_SendPacket(&packet);
}

static bool32 sub_802E264(struct PokemonJump1_82E4 *arg0, int multiplayerId, u8 *arg2, u16 *arg3)
{
    struct UnkPacket4 packet;

    if ((gRecvCmds[multiplayerId][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id != 4)
        return FALSE;

    arg0->unk10 = packet.unk1;
    arg0->unk14 = packet.unk2;
    arg0->unk18 = packet.unk3;
    arg0->unkE = packet.unk4;
    *arg2 = packet.unk6;
    *arg3 = packet.unk8;
    return TRUE;
}

static bool32 sub_802E2D0(struct PokemonJump1_82E4 *arg0, int multiplayerId)
{
    struct UnkPacket4 packet;

    if ((gRecvCmds[multiplayerId][0] & 0xFF00) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id != 4)
        return FALSE;

    arg0->unk10 = packet.unk1;
    arg0->unk14 = packet.unk2;
    arg0->unk18 = packet.unk3;
    arg0->unkE = packet.unk4;
    return TRUE;
}

static struct PokemonJumpResults *sub_802E32C(void)
{
    return &gSaveBlock2Ptr->pokeJump;
}

void ResetPokeJumpResults(void)
{
    struct PokemonJumpResults *pokeJump = sub_802E32C();
    pokeJump->jumpsInRow = 0;
    pokeJump->bestJumpScore = 0;
    pokeJump->excellentsInRow = 0;
    pokeJump->field6 = 0;
    pokeJump->field8 = 0;
    pokeJump->field2 = 0;
}

static bool32 sub_802E354(u32 jumpScore, u16 jumpsInRow, u16 excellentsInRow)
{
    struct PokemonJumpResults *pokeJump = sub_802E32C();
    bool32 ret = FALSE;

    if (pokeJump->bestJumpScore < jumpScore && jumpScore <= 99990)
        pokeJump->bestJumpScore = jumpScore, ret = TRUE;
    if (pokeJump->jumpsInRow < jumpsInRow && jumpsInRow <= 9999)
        pokeJump->jumpsInRow = jumpsInRow, ret = TRUE;
    if (pokeJump->excellentsInRow < excellentsInRow && excellentsInRow <= 9999)
        pokeJump->excellentsInRow = excellentsInRow, ret = TRUE;

    return ret;
}

static void sub_802E3A8(void)
{
    struct PokemonJumpResults *pokeJump = sub_802E32C();
    if (pokeJump->field6 < 9999)
        pokeJump->field6++;
}

void ShowPokemonJumpRecords(void)
{
    u8 taskId = CreateTask(Task_ShowPokemonJumpRecords, 0);
    Task_ShowPokemonJumpRecords(taskId);
}

static const struct WindowTemplate gUnknown_082FE270 =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 9,
    .paletteNum = 15,
    .baseBlock = 0x1,
};

static const u8 *const gUnknown_082FE278[] = {gText_JumpsInARow, gText_BestScore2, gText_ExcellentsInARow};

static void Task_ShowPokemonJumpRecords(u8 taskId)
{
    struct WindowTemplate window;
    int i, width, widthCurr;
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        window = gUnknown_082FE270;
        width = GetStringWidth(1, gText_PkmnJumpRecords, 0);
        for (i = 0; i < ARRAY_COUNT(gUnknown_082FE278); i++)
        {
            widthCurr = GetStringWidth(1, gUnknown_082FE278[i], 0) + 38;
            if (widthCurr > width)
                width = widthCurr;
        }
        width = (width + 7) / 8;
        if (width & 1)
            width++;
        window.tilemapLeft = (30 - width) / 2;
        window.width = width;
        data[1] = AddWindow(&window);
        sub_802E500(data[1], width);
        CopyWindowToVram(data[1], 3);
        data[0]++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            data[0]++;
        break;
    case 2:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            rbox_fill_rectangle(data[1]);
            CopyWindowToVram(data[1], 1);
            data[0]++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            RemoveWindow(data[1]);
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
        break;
    }
}

static void sub_802E500(u16 windowId, int width)
{
    int i, x;
    int results[3];
    struct PokemonJumpResults *pokeJump = sub_802E32C();
    results[0] = pokeJump->jumpsInRow;
    results[1] = pokeJump->bestJumpScore;
    results[2] = pokeJump->excellentsInRow;

    LoadUserWindowBorderGfx_(windowId, 0x21D, 0xD0);
    DrawTextBorderOuter(windowId, 0x21D, 0xD);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, 1, gText_PkmnJumpRecords, GetStringCenterAlignXOffset(1, gText_PkmnJumpRecords, width * 8), 1, TEXT_SPEED_FF, NULL);
    for (i = 0; i < ARRAY_COUNT(gUnknown_082FE278); i++)
    {
        AddTextPrinterParameterized(windowId, 1, gUnknown_082FE278[i], 0, 25 + (i * 16), TEXT_SPEED_FF, NULL);
        ConvertIntToDecimalStringN(gStringVar1, results[i], STR_CONV_MODE_LEFT_ALIGN, 5);
        TruncateToFirstWordOnly(gStringVar1);
        x = (width * 8) - GetStringWidth(1, gStringVar1, 0);
        AddTextPrinterParameterized(windowId, 1, gStringVar1, x, 25 + (i * 16), TEXT_SPEED_FF, NULL);
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
