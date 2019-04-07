#include "global.h"
#include "alloc.h"
#include "link.h"
#include "main.h"
#include "palette.h"
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
    MainCallback unk0;
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
    u8 filler34[0x6];
    u16 unk3A;
    u8 filler3C[0x6];
    u16 unk42;
    u8 unk44;
    u8 filler45[0x1];
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
bool32 sub_802B248(void);
bool32 sub_802B2D4(void);
bool32 sub_802B368(void);
bool32 sub_802B3D4(void);
bool32 sub_802B4CC(void);
bool32 sub_802B5C8(void);
bool32 sub_802B664(void);
bool32 sub_802B6B8(void);
bool32 sub_802B720(void);
bool32 sub_802B29C(void);
bool32 sub_802B31C(void);
bool32 sub_802B3B4(void);
bool32 sub_802B470(void);
bool32 sub_802B568(void);
bool32 sub_802B628(void);
bool32 sub_802B664(void);
bool32 sub_802B704(void);
bool32 sub_802B720(void);
bool32 sub_802B7E0(void);
bool32 sub_802B8CC(void);
void sub_802BD84(u8 taskId);
void sub_802BE60(TaskFunc func, u8 taskPriority);
void sub_802BE80(void);
void sub_802C0B8(void);
void sub_802C0E8(void);
void sub_802C1DC(void);
void sub_802C43C(void);
bool32 sub_802C538(void);
bool32 sub_802C70C(void);
void sub_802D074(void *);
void sub_802D0AC(void);
int sub_802D0F0(void);
void sub_802E138(struct PokemonJump1_82E4 *, u8 *);
bool32 sub_802E1BC(struct PokemonJump1_82E4 *, struct Unk802B078 *);
void sub_802E234(struct PokemonJump1_82E4 *, u8 , u16);
bool32 sub_802E264(struct PokemonJump1_82E4 *, int, u8 *, u16 *);
bool32 sub_802E2D0(struct PokemonJump1_82E4 *, int);
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
            gUnknown_02022CFC->unk0 = callback;
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

void sub_802AA48(void)
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

#ifdef NONMATCHING
void sub_802AB20(void)
{
    int i;
    s16 index;

    for (i = 0; i < 5; i++)
    {
        index = sub_802AC00(gUnknown_02022CFC->unk82A8[i].species);
        gUnknown_02022CFC->unk82E4[i].unkC = gPkmnJumpSpecies[index].unk2;
    }

    gUnknown_02022CFC->unk83AC = &gUnknown_02022CFC->unk82E4[gUnknown_02022CFC->unk6];
}
#else
NAKED
void sub_802AB20(void)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r8\n\
    push {r7}\n\
    ldr r7, =gUnknown_02022CFC\n\
    movs r6, 0\n\
    movs r5, 0\n\
    ldr r0, =gPkmnJumpSpecies\n\
    mov r8, r0\n\
    movs r4, 0x4\n\
_0802AB32:\n\
    ldr r0, [r7]\n\
    adds r0, r5\n\
    ldr r1, =0x000082a8\n\
    adds r0, r1\n\
    ldrh r0, [r0]\n\
    bl sub_802AC00\n\
    lsls r0, 16\n\
    ldr r1, [r7]\n\
    adds r1, r6\n\
    asrs r0, 14\n\
    add r0, r8\n\
    ldrh r0, [r0, 0x2]\n\
    ldr r2, =0x000082f0\n\
    adds r1, r2\n\
    strh r0, [r1]\n\
    adds r6, 0x28\n\
    adds r5, 0xC\n\
    subs r4, 0x1\n\
    cmp r4, 0\n\
    bge _0802AB32\n\
    ldr r0, =gUnknown_02022CFC\n\
    ldr r1, [r0]\n\
    ldr r0, =0x000083ac\n\
    adds r3, r1, r0\n\
    ldrb r2, [r1, 0x6]\n\
    lsls r0, r2, 2\n\
    adds r0, r2\n\
    lsls r0, 3\n\
    ldr r2, =0x000082e4\n\
    adds r0, r2\n\
    adds r1, r0\n\
    str r1, [r3]\n\
    pop {r3}\n\
    mov r8, r3\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING

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
            sub_800E0E8();
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

bool32 sub_802B248(void)
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

bool32 sub_802B29C(void)
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

bool32 sub_802B2D4(void)
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

bool32 sub_802B31C(void)
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

bool32 sub_802B368(void)
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

bool32 sub_802B3B4(void)
{
    if (!sub_802B8CC())
        ;
    else if (sub_802C538())
        return TRUE;
    else
        sub_802C0B8();

    return FALSE;
}
