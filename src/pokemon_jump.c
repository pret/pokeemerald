#include "global.h"
#include "alloc.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "trig.h"
#include "pokemon.h"
#include "pokemon_jump.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"

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
    u8 unk70;
    u8 unk71;
    u16 unk72;
    u16 unk74;
    u32 unk78;
    u8 unk7C[MAX_RFU_PLAYERS];
    u8 unk81[MAX_RFU_PLAYERS];
    u8 unk86[MAX_RFU_PLAYERS];
    u8 unk8B[MAX_RFU_PLAYERS];
    u16 unk90[MAX_RFU_PLAYERS];
    u16 unk9A[MAX_RFU_PLAYERS];
    void **unkA4;
    u8 fillerA8[0x8200];
    struct PokemonJump1_MonInfo unk82A8[MAX_RFU_PLAYERS];
    struct PokemonJump1_82E4 unk82E4[MAX_RFU_PLAYERS];
    struct PokemonJump1_82E4 *unk83AC;
};

struct PokemonJumpMons
{
    u16 species;
    u16 unk2;
};

struct Unk802B078
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    int unk8;
};


struct PokemonJump2
{
    u8 filler0[0xE];
    u8 unkE;
    u8 unkF;
    u8 filler10[0x8198];
    struct Sprite *unk81A8[MAX_RFU_PLAYERS];
    struct Sprite *unk81BC[MAX_RFU_PLAYERS];
    struct Sprite *unk81D0[8];
    u8 filler81F0[0xC];
    u8 unk81FC[MAX_RFU_PLAYERS];
};

static void sub_802AA60(struct PokemonJump1 *);
void sub_802AA94(struct PokemonJump1 *);
void sub_802AB20(void);
static void sub_802AB98(void);
static s16 sub_802AC00(u16 species);
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
static bool32 sub_802C70C(void);
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
void sub_802DC9C(u32);
void sub_802D074(void *);
void sub_802D0AC(void);
void sub_802D0C8(int);
int sub_802D0F0(void);
void sub_802D764(void);
bool32 sub_802D788(void);
void sub_802D7E8(u16, u16);
void sub_802D884(u16);
void sub_802D8FC(u16);
bool32 sub_802D974(void);
void sub_802DA14(void);
void sub_802DC80(int, s8);
void sub_802DD88(u8);
bool32 sub_802DA44(void);
void sub_802DD64(int);
s8 sub_802DA8C(void);
int sub_802DCCC(u8);
void sub_802DD74(u16);
void sub_802DDA0(u8);
int sub_802DDB8(int);
void sub_802DDCC(void);
void sub_802DDE0(void);
void sub_802DDF4(int);
int sub_802DE08(void);
void sub_802E0AC(struct PokemonJump1_MonInfo *);
bool32 sub_802E0D0(int, struct PokemonJump1_MonInfo *);
void sub_802E138(struct PokemonJump1_82E4 *, u8 *);
bool32 sub_802E1BC(struct PokemonJump1_82E4 *, struct Unk802B078 *);
void sub_802E234(struct PokemonJump1_82E4 *, u8 , u16);
bool32 sub_802E264(struct PokemonJump1_82E4 *, int, u8 *, u16 *);
bool32 sub_802E2D0(struct PokemonJump1_82E4 *, int);
int sub_802E354(int, u16, u16);
void sub_802E3A8(void);

extern struct PokemonJump1 *gUnknown_02022CFC;
extern struct PokemonJump2 *gUnknown_02022D00;

const struct PokemonJumpMons gPkmnJumpSpecies[] =
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

bool32 (* const gUnknown_082FB5F4[])(void) =
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

bool32 (* const gUnknown_082FB618[])(void) =
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

extern const u16 gUnknown_082FB63C[];
extern const u16 gUnknown_082FB64C[4];
extern const u16 gUnknown_082FB654[];
extern const s8 gUnknown_082FB65C[][48];
extern const int gUnknown_082FB6EC[];
extern const int gUnknown_082FB714[];
extern const u16 gUnknown_082FB704[8];
extern const struct CompressedSpriteSheet gUnknown_082FBE08[5];
extern const struct SpritePalette gUnknown_082FBE30[2];
extern const struct SpriteTemplate gUnknown_082FBE40;
extern const struct SpriteTemplate gUnknown_082FC00C;
extern const s16 gUnknown_082FBE58[];
extern const s16 gUnknown_082FBEA8[8];
extern const struct SpriteTemplate gUnknown_082FBEB8[4];

void sub_802A9A8(u16 partyIndex, MainCallback callback)
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
    arg0->unk70 = 5;
    arg0->unk72 = 0;
    sub_802AB20();
    sub_802AA94(arg0);
    if (arg0->unk5 == MAX_RFU_PLAYERS)
        sub_802E3A8();
}

void sub_802AA94(struct PokemonJump1 *arg0)
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
    arg0->unk78 = 0;
    arg0->unk71 = 0;
    arg0->unk74 = 0;
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

void sub_802AB20(void)
{
    int i, index;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        index = sub_802AC00(gUnknown_02022CFC->unk82A8[i].species);
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

static s16 sub_802AC00(u16 species)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(gPkmnJumpSpecies); i++)
    {
        if (gPkmnJumpSpecies[i].species == species)
            return i;
    }

    return -1;
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
            FadeOutAndPlayNewMapMusic(MUS_RG_JUMP, 8);
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

    gUnknown_02022CFC->unk70 = arg0;
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

        if (gUnknown_02022CFC->unk82E4[i].unk18 && gUnknown_02022CFC->unk8B[i] == gUnknown_02022CFC->unk70)
            count++;
    }

    if (count == gUnknown_02022CFC->unk5 - 1)
        gUnknown_02022CFC->unk49 = 1;
}

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
        if (!gUnknown_082FB5F4[gUnknown_02022CFC->unk70]())
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
    gUnknown_02022CFC->unk70 = arg0;
    gUnknown_02022CFC->unk8 = 0;
    gUnknown_02022CFC->unkA = 0;
    gUnknown_02022CFC->unk48 = 1;
    gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6].unk18 = 0;
}

static void sub_802B078(void)
{
    int i;
    u16 var0;
    struct Unk802B078 sp0;

    var0 = gUnknown_02022CFC->unk82E4[0].unk10;
    if (sub_802E1BC(gUnknown_02022CFC->unk82E4, &sp0))
    {
        if (gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6].unk18 == 1
         && sp0.unk0 != gUnknown_02022CFC->unk70)
        {
            sub_802B044(sp0.unk0);
        }

        if (gUnknown_02022CFC->unk78 != sp0.unk8)
        {
            gUnknown_02022CFC->unk78 = sp0.unk8;
            gUnknown_02022CFC->unk5C = 1;
            gUnknown_02022CFC->unk71 = sp0.unk1;
            if (gUnknown_02022CFC->unk71)
                gUnknown_02022CFC->unk4D = 1;
            else
                gUnknown_02022CFC->unk4D = 0;
        }

        gUnknown_02022CFC->unk72 = sp0.unk2;
        gUnknown_02022CFC->unk74 = sp0.unk4;
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

static void sub_802B194(u8 taskId)
{
    sub_802B078();
    if (gUnknown_02022CFC->unk48)
    {
        if (!gUnknown_082FB618[gUnknown_02022CFC->unk70]())
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
        sub_802E234(&gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6], gUnknown_02022CFC->unk70, gUnknown_02022CFC->unk42);

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
            gUnknown_02022CFC->unk72 = gUnknown_02022CFC->unk4A;
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
        gUnknown_02022CFC->unk24 = gUnknown_02022CFC->unk72;
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
        gUnknown_02022CFC->unk4A = gUnknown_02022CFC->unk72;
        gUnknown_02022CFC->unk8++;
        // fall through
    case 1:
        if (sub_802C70C())
            return FALSE;
        break;
    }

    return TRUE;
}

static bool32 sub_802B368(void)
{
    if (!sub_802B8CC())
    {
        gUnknown_02022CFC->unk72 = gUnknown_02022CFC->unk4A;
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
                gUnknown_02022CFC->unk72 = sub_802C7E0();
                gUnknown_02022CFC->unk4C = 7;
            }
            else if (gUnknown_02022CFC->unk74 >= 200)
            {
                gUnknown_02022CFC->unk72 = gUnknown_02022CFC->unkE;
                gUnknown_02022CFC->unk4C = 8;
            }
            else
            {
                gUnknown_02022CFC->unk72 = gUnknown_02022CFC->unkE;
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
            sub_802E354(gUnknown_02022CFC->unk78, gUnknown_02022CFC->unk74, gUnknown_02022CFC->unk72);
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
            sub_802E354(gUnknown_02022CFC->unk78, gUnknown_02022CFC->unk74, gUnknown_02022CFC->unk72);
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
            gUnknown_02022CFC->unk72 = gUnknown_02022CFC->unk24;
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
            gUnknown_02022CFC->unk72 = gUnknown_02022CFC->unkE;
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
        sub_802E354(gUnknown_02022CFC->unk78, gUnknown_02022CFC->unk74, gUnknown_02022CFC->unk72);
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
        if (sub_802C70C())
        {
            CreateTask(sub_8153688, 6);
            gUnknown_02022CFC->unk8++;
        }
        break;
    case 3:
        if (!FuncIsActiveTask(sub_8153688))
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
    int var0;

    switch (gUnknown_02022CFC->unkA)
    {
    case 0:
        sub_802D0C8(2);
        sub_802DDE0();
        gUnknown_02022CFC->unkA++;
        break;
    case 1:
        var0 = sub_802D0F0();
        if (!var0)
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
        if (gMain.newKeys & A_BUTTON)
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
            gUnknown_02022CFC->unk71 = 0;
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
        sub_802C808(gUnknown_02022CFC->unk72, &gUnknown_02022CFC->unk3E, &gUnknown_02022CFC->unk40);
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
        if (gMain.newKeys & (A_BUTTON | B_BUTTON) || gUnknown_02022CFC->unk3C > 180)
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
            sub_800AC34();
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
    // The number 1103515245 comes from the example implementation of rand and srand
    gUnknown_02022CFC->unk24 = gUnknown_02022CFC->unk24 * 1103515245 + 24691;
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

static void sub_802C1DC(void)
{
    if (gUnknown_02022CFC->unk5C)
    {
        sub_802DD64(gUnknown_02022CFC->unk78);
        gUnknown_02022CFC->unk5C = 0;
        if (gUnknown_02022CFC->unk4D)
        {
            int index = sub_802DCCC(gUnknown_02022CFC->unk71);
            PlaySE(gUnknown_082FB654[index - 2]);
            gUnknown_02022CFC->unk4D = 0;
        }
    }

    sub_802DD74(gUnknown_02022CFC->unk74);
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
        PlaySE(SE_RG_NAWAMISS);
    else if (whichSound & 0x1)
        PlaySE(SE_DANSA);
}

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
            gUnknown_02022CFC->unk71 = 0;
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
            gUnknown_02022CFC->unk71 = 0;
            if (gUnknown_02022CFC->unk74 < 9999)
                gUnknown_02022CFC->unk74++;

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
    gUnknown_02022CFC->unk78 += arg0;
    gUnknown_02022CFC->unk5C = 1;
    if (gUnknown_02022CFC->unk78 >= 99990)
        gUnknown_02022CFC->unk78 = 99990;
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

static bool32 sub_802C70C(void)
{
    return !gUnknown_03005000.unk_124.unk_8c2 && !gUnknown_03005000.unk_9e8.unk_232;
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

    gUnknown_02022CFC->unk71 = flags;
    if (flags)
        gUnknown_02022CFC->unk4D = 1;

    return count;
}

static void sub_802C780(void)
{
    gUnknown_02022CFC->unk44 = 0;
}

static int sub_802C790(int arg0)
{
    return gUnknown_082FB6EC[arg0];
}

static void sub_802C7A0(u16 arg0)
{
    if (arg0 > gUnknown_02022CFC->unkE)
        gUnknown_02022CFC->unkE = arg0;
}

static bool32 sub_802C7BC(void)
{
    if (gUnknown_02022CFC->unk78 >= gUnknown_082FB714[0])
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

NAKED
static u16 sub_802C838(void)
{
    asm_unified("\n\
    push {r4-r6,lr}\n\
    movs r5, 0\n\
    movs r4, 0\n\
    ldr r3, =gUnknown_02022CFC\n\
    ldr r0, [r3]\n\
    ldr r2, =gUnknown_082FB714\n\
    ldr r1, [r0, 0x78]\n\
    ldr r0, [r2]\n\
    cmp r1, r0\n\
    bcc _0802C874\n\
    ldr r5, [r2, 0x4]\n\
    adds r6, r3, 0\n\
    adds r3, r2, 0x4\n\
_0802C852:\n\
    adds r3, 0x8\n\
    adds r2, 0x8\n\
    adds r4, 0x1\n\
    cmp r4, 0x4\n\
    bhi _0802C874\n\
    ldr r0, [r6]\n\
    ldr r1, [r0, 0x78]\n\
    ldr r0, [r2]\n\
    cmp r1, r0\n\
    bcc _0802C874\n\
    ldr r5, [r3]\n\
    b _0802C852\n\
    .pool\n\
_0802C874:\n\
    lsls r0, r5, 16\n\
    lsrs r0, 16\n\
    pop {r4-r6}\n\
    pop {r1}\n\
    bx r1");
}

static u16 sub_802C880(u16 item, u16 quantity)
{
    while (quantity && !CheckBagHasSpace(item, quantity))
        quantity--;

    return quantity;
}

u16 sub_802C8AC(void)
{
    return GetLinkPlayerCount();
}

u16 sub_802C8BC(void)
{
    return gUnknown_02022CFC->unk6;
}

struct PokemonJump1_MonInfo *sub_802C8C8(u8 multiplayerId)
{
    return &gUnknown_02022CFC->unk82A8[multiplayerId];
}

u8 *sub_802C8E8(u8 multiplayerId)
{
    return gUnknown_02022CFC->unk82E4[multiplayerId].unk1C;
}

bool32 sub_802C908(u16 species)
{
    return sub_802AC00(species) > -1;
}

void sub_802C920(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_HAS_SPECIES))
        {
            u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            if (sub_802C908(species))
            {
                gSpecialVar_Result = 1;
                return;
            }
        }
    }

    gSpecialVar_Result = 0;
}

void sub_802C974(struct PokemonJump2 *arg0)
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

void sub_802C9D4(struct PokemonJump2 *arg0, struct PokemonJump1_MonInfo *jumpMon, u16 x, u16 y, u8 multiplayerId)
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
            &gMonFrontPicTable[jumpMon->species],
            buffer,
            jumpMon->species,
            jumpMon->personality);

        spriteSheet.data = buffer;
        spriteSheet.tag = multiplayerId;
        spriteSheet.size = 0x800;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetFrontSpritePalFromSpeciesAndPersonality(jumpMon->species, jumpMon->otId, jumpMon->personality);
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

void sub_802CB14(struct PokemonJump2 *arg0, int multiplayerId)
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

void sub_802CBF0(struct PokemonJump2 *arg0, int multiplayerId)
{
    arg0->unk81A8[multiplayerId]->callback = sub_802CC40;
    arg0->unk81A8[multiplayerId]->pos2.y = 0;
    sub_802C9BC(arg0->unk81A8[multiplayerId]);
}

bool32 sub_802CC18(struct PokemonJump2 *arg0, int multiplayerId)
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

void sub_802CC88(struct PokemonJump2 *arg0, int multiplayerId)
{
    sub_802C9BC(arg0->unk81A8[multiplayerId]);
    arg0->unk81A8[multiplayerId]->callback = sub_802CD08;
}

void sub_802CCB0(struct PokemonJump2 *arg0)
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

void sub_802CD3C(struct PokemonJump2 *arg0)
{
    int i;
    u16 numPlayers = sub_802C8AC();
    for (i = 0; i < numPlayers; i++)
        arg0->unk81A8[i]->subpriority = arg0->unk81FC[i];
}

void sub_802CD70(struct PokemonJump2 *arg0, int multiplayerId)
{
    sub_802C9BC(arg0->unk81A8[multiplayerId]);
    arg0->unk81A8[multiplayerId]->callback = sub_802CDD4;
}

bool32 sub_802CD98(struct PokemonJump2 *arg0)
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
        PlaySE(SE_JITE_PYOKO);
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

void sub_802CE48(struct PokemonJump2 *arg0, s16 x, s16 y, u8 multiplayerId)
{
    u8 spriteId = CreateSprite(&gUnknown_082FC00C, x, y, 1);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].invisible = 1;
        arg0->unk81BC[multiplayerId] = &gSprites[spriteId];
    }
}

// void sub_802CE9C(struct PokemonJump2 *arg0)
// {
//     int i;
//     int count;
//     u8 spriteId;

//     count = 0;
//     for (i = 0; i < 4; i++)
//     {
//         spriteId = CreateSprite(&gUnknown_082FBEB8[i], gUnknown_082FBEA8[count], gUnknown_082FBE58[i * 10], 2);
//         arg0->unk81D0[count] = &gSprites[spriteId];
//         count++;
//     }

//     for (i = 0; i < 4; i++)
//     {
//         spriteId = CreateSprite(&gUnknown_082FBEB8[i], gUnknown_082FBEA8[count], gUnknown_082FBE58[i * 10], 2);
//         arg0->unk81D0[count] = &gSprites[spriteId];
//         arg0->unk81D0[count]->hFlip = 1;
//         count++;
//     }
// }
