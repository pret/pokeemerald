#include "global.h"
#include "alloc.h"
#include "item.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
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
    u8 filler1C[0xC];
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
    u8 filler10[0x4];
    int unk14;
    int unk18;
    int unk1C;
    u8 filler20[0x4];
    int unk24;
    u8 filler28[0x4];
    int unk2C;
    u32 unk30;
    u8 filler34[0x2];
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
    u8 filler4E[0x6];
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
    int unk78;
    u8 unk7C[5];
    u8 filler81[0xA];
    u8 unk8B[5];
    u16 unk90[5];
    u16 unk9A[5];
    void **unkA4;
    u8 fillerA8[0x8200];
    struct PokemonJump1_MonInfo unk82A8[5];
    struct PokemonJump1_82E4 unk82E4[5];
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

static void sub_802AA60(struct PokemonJump1 *);
void sub_802AA94(struct PokemonJump1 *);
void sub_802AB20(void);
static void sub_802AB98(void);
s16 sub_802AC00(u16);
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
void sub_802BD84(u8 taskId);
void sub_802BE60(TaskFunc func, u8 taskPriority);
void sub_802BE80(void);
void sub_802BEA0(void);
void sub_802BEE4(void);
void sub_802C0B8(void);
void sub_802C0E8(void);
void sub_802C114(void);
void sub_802C164(void);
void sub_802C1DC(void);
bool32 sub_802C130(u16);
void sub_802C260(void);
void sub_802C270(void);
void sub_802C43C(void);
void sub_802C808(u16, u16 *, u16 *);
bool32 sub_802C538(void);
bool32 sub_802C650(void);
bool32 sub_802C5DC(void);
bool32 sub_802C70C(void);
bool32 sub_802C7BC(void);
u16 sub_802C7E0(void);
u16 sub_802C880(u16, u16);
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
bool32 sub_802DA44(void);
void sub_802DD64(int);
s8 sub_802DA8C(void);
void sub_802DDA0(u8);
int sub_802DDB8(int);
void sub_802DDCC(void);
void sub_802DDE0(void);
void sub_802DDF4(int);
int sub_802DE08(void);
void sub_802E138(struct PokemonJump1_82E4 *, u8 *);
bool32 sub_802E1BC(struct PokemonJump1_82E4 *, struct Unk802B078 *);
void sub_802E234(struct PokemonJump1_82E4 *, u8 , u16);
bool32 sub_802E264(struct PokemonJump1_82E4 *, int, u8 *, u16 *);
bool32 sub_802E2D0(struct PokemonJump1_82E4 *, int);
int sub_802E354(int, u16, u16);
void sub_802E3A8(void);

extern struct PokemonJump1 *gUnknown_02022CFC;

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
    if (arg0->unk5 == 5)
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

    for (i = 0; i < 5; i++)
    {
        arg0->unk7C[i] = 0;
        arg0->unk9A[i] = 0;
    }
}

void sub_802AB20(void)
{
    int i, index;

    for (i = 0; i < 5; i++)
    {
        index = sub_802AC00(gUnknown_02022CFC->unk82A8[i].species);
        gUnknown_02022CFC->unk82E4[i].unkC = gPkmnJumpSpecies[index].unk2;
    }

    gUnknown_02022CFC->unk83AC = &gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6];
}

static void sub_802AB98(void)
{
    int i;

    for (i = 0; i < 5; i++)
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

s16 sub_802AC00(u16 species)
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

void sub_802AE14(int arg0)
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
