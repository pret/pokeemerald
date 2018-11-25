#include "global.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "berry.h"
#include "contest.h"
#include "contest_link_80F57C4.h"
#include "contest_painting.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "script_menu.h"
#include "sprite.h"
#include "string_util.h"
#include "tv.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/vars.h"

extern const u16 gEventObjectPalette8[];
extern const u16 gEventObjectPalette17[];
extern const u16 gEventObjectPalette33[];
extern const u16 gEventObjectPalette34[];
extern const struct CompressedSpriteSheet gMonFrontPicTable[];

extern u8 gSelectedOrderFromParty[];

const u8 gUnknown_0858D8EC[] = { 3, 4, 5, 14 };

static void sub_80F8EE8(u8 taskId);
static void sub_80F9088(u8 taskId);
static void sub_80F9460(void);
static void sub_80F94B8(void);

void SetContestTrainerGfxIds(void)
{
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_0 - VARS_START] = gContestMons[0].trainerGfxId;
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_1 - VARS_START] = gContestMons[1].trainerGfxId;
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_2 - VARS_START] = gContestMons[2].trainerGfxId;
}

void sub_80F8814(void)
{
    u16 var1;
    u8 var0 = gSpecialVar_0x8005;
    switch (var0)
    {
    case 0:
        var1 = 3;
        break;
    case 1:
        var1 = 4;
        break;
    case 2:
        var1 = 5;
        break;
    default:
        var1 = 100;
        break;
    }

    gSpecialVar_0x8004 = var1;
}

void sub_80F8850(void)
{
    sub_80F8264();
    sub_80F8290();
    sub_80F8438();
}

void sub_80F8864(void)
{
    int contestWinner;
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        contestWinner = 8;
        break;
    case CONTEST_CATEGORY_BEAUTY:
        contestWinner = 9;
        break;
    case CONTEST_CATEGORY_CUTE:
        contestWinner = 10;
        break;
    case CONTEST_CATEGORY_SMART:
        contestWinner = 11;
        break;
    case CONTEST_CATEGORY_TOUGH:
    default:
        contestWinner = 12;
        break;
    }

    if (!gSaveBlock1Ptr->contestWinners[contestWinner].species)
        gSpecialVar_0x8004 = 0;
    else
        gSpecialVar_0x8004 = 1;
}

void sub_80F88DC(void)
{
    sub_80DEDA8(0xFF);
}

void sub_80F88E8(void)
{
    if (gContestFinalStandings[gContestPlayerMonIndex] == 0
     && gSpecialVar_ContestRank == 3
     && gUnknown_02039F08[gContestPlayerMonIndex] >= 800)
    {
        gSpecialVar_0x8004 = 1;
    }
    else
    {
        gSpecialVar_0x8004 = 0;
    }
}

u8 sub_80F8940(void)
{
    int i;
    u8 var0 = 0;

    for (i = 0; i < 5; i++)
    {
        if (gSaveBlock1Ptr->contestWinners[8 + i].species)
            var0++;
    }

    return var0;
}

#ifdef NONMATCHING
void sub_80F8970(void)
{
    s16 sp[4];
    int i, j;
    s16 condition;
    u8 var2;
    u8 var1;
    s8 var0;
    u8 r7;

    for (i = 0; i < 4; i++)
        sp[i] = gContestMonConditions[i];


    for (i = 0; i < 3; i++)
    {
        for (j = 3; j > i; j--)
        {
            if (sp[j - 1] < sp[j])
            {
                int temp = sp[j];
                sp[j] = sp[j - 1];
                sp[j - 1] = temp;
            }
        }
    }

    condition = sp[gSpecialVar_0x8006];
    var0 = 0;
    var1 = 0;
    for (i = 0; i < 4; i++)
    {
        if (sp[i] == condition)
        {
            var0++;
            if (i == gSpecialVar_0x8006)
                var1 = var0;
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (sp[i] == condition)
            break;
    }

    r7 = i;
    var2 = var1;
    for (i = 0; i < 4; i++)
    {
        if (condition == gContestMonConditions[i])
        {
            if (var2 == 1)
                break;
            var2--;
        }
    }

    StringCopy(gStringVar1, gContestMons[i].nickname);
    StringCopy(gStringVar2, gContestMons[i].trainerName);
    sub_81DB5AC(gStringVar2);

    if (var0 == 1 || var1 == var0)
        gSpecialVar_0x8006 = r7;
    else
        gSpecialVar_0x8006 = r7 + 4;
}
#else
NAKED
void sub_80F8970(void)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x8\n\
    ldr r0, =gContestMonConditions\n\
    mov r12, r0\n\
    ldr r1, =gSpecialVar_0x8006\n\
    mov r9, r1\n\
    ldr r2, =gContestMons + 2\n\
    mov r10, r2\n\
    mov r2, r12\n\
    mov r1, sp\n\
    movs r6, 0x3\n\
_080F898E:\n\
    ldrh r0, [r2]\n\
    strh r0, [r1]\n\
    adds r2, 0x2\n\
    adds r1, 0x2\n\
    subs r6, 0x1\n\
    cmp r6, 0\n\
    bge _080F898E\n\
    movs r6, 0\n\
_080F899E:\n\
    movs r1, 0x3\n\
    cmp r1, r6\n\
    ble _080F89C8\n\
_080F89A4:\n\
    subs r5, r1, 0x1\n\
    lsls r0, r5, 1\n\
    mov r4, sp\n\
    adds r3, r4, r0\n\
    lsls r0, r1, 1\n\
    adds r2, r4, r0\n\
    ldrh r4, [r3]\n\
    movs r7, 0\n\
    ldrsh r1, [r3, r7]\n\
    movs r7, 0\n\
    ldrsh r0, [r2, r7]\n\
    cmp r1, r0\n\
    bge _080F89C2\n\
    strh r4, [r2]\n\
    strh r0, [r3]\n\
_080F89C2:\n\
    adds r1, r5, 0\n\
    cmp r1, r6\n\
    bgt _080F89A4\n\
_080F89C8:\n\
    adds r6, 0x1\n\
    cmp r6, 0x2\n\
    ble _080F899E\n\
    mov r2, r9\n\
    ldrh r0, [r2]\n\
    lsls r0, 1\n\
    add r0, sp\n\
    ldrh r0, [r0]\n\
    movs r2, 0\n\
    mov r8, r2\n\
    movs r6, 0\n\
    lsls r0, 16\n\
    asrs r4, r0, 16\n\
    adds r3, r0, 0\n\
    mov r1, sp\n\
    mov r5, r9\n\
_080F89E8:\n\
    movs r7, 0\n\
    ldrsh r0, [r1, r7]\n\
    cmp r0, r4\n\
    bne _080F8A02\n\
    lsls r0, r2, 24\n\
    movs r2, 0x80\n\
    lsls r2, 17\n\
    adds r0, r2\n\
    lsrs r2, r0, 24\n\
    ldrh r7, [r5]\n\
    cmp r6, r7\n\
    bne _080F8A02\n\
    mov r8, r2\n\
_080F8A02:\n\
    adds r1, 0x2\n\
    adds r6, 0x1\n\
    cmp r6, 0x3\n\
    ble _080F89E8\n\
    movs r6, 0\n\
    mov r0, sp\n\
    movs r1, 0\n\
    ldrsh r0, [r0, r1]\n\
    asrs r1, r3, 16\n\
    lsls r2, 24\n\
    mov r9, r2\n\
    cmp r0, r1\n\
    beq _080F8A30\n\
    adds r2, r1, 0\n\
    mov r1, sp\n\
_080F8A20:\n\
    adds r1, 0x2\n\
    adds r6, 0x1\n\
    cmp r6, 0x3\n\
    bgt _080F8A30\n\
    movs r4, 0\n\
    ldrsh r0, [r1, r4]\n\
    cmp r0, r2\n\
    bne _080F8A20\n\
_080F8A30:\n\
    lsls r0, r6, 24\n\
    lsrs r7, r0, 24\n\
    mov r2, r8\n\
    movs r6, 0\n\
    asrs r1, r3, 16\n\
    mov r5, r12\n\
    movs r4, 0\n\
    ldrsh r0, [r5, r4]\n\
    b _080F8A66\n\
    .pool\n\
_080F8A50:\n\
    subs r0, r2, 0x1\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
_080F8A56:\n\
    adds r6, 0x1\n\
    cmp r6, 0x3\n\
    bgt _080F8A6E\n\
    lsls r0, r6, 1\n\
    add r0, r12\n\
    asrs r1, r3, 16\n\
    movs r5, 0\n\
    ldrsh r0, [r0, r5]\n\
_080F8A66:\n\
    cmp r1, r0\n\
    bne _080F8A56\n\
    cmp r2, 0x1\n\
    bne _080F8A50\n\
_080F8A6E:\n\
    lsls r4, r6, 6\n\
    mov r0, r10\n\
    adds r1, r4, r0\n\
    ldr r0, =gStringVar1\n\
    bl StringCopy\n\
    ldr r5, =gStringVar2\n\
    mov r0, r10\n\
    adds r0, 0xB\n\
    adds r4, r0\n\
    adds r0, r5, 0\n\
    adds r1, r4, 0\n\
    bl StringCopy\n\
    adds r0, r5, 0\n\
    bl sub_81DB5AC\n\
    mov r1, r9\n\
    asrs r0, r1, 24\n\
    cmp r0, 0x1\n\
    beq _080F8A9C\n\
    cmp r8, r0\n\
    bne _080F8AB0\n\
_080F8A9C:\n\
    ldr r0, =gSpecialVar_0x8006\n\
    strh r7, [r0]\n\
    b _080F8AB6\n\
    .pool\n\
_080F8AB0:\n\
    ldr r1, =gSpecialVar_0x8006\n\
    adds r0, r7, 0x4\n\
    strh r0, [r1]\n\
_080F8AB6:\n\
    add sp, 0x8\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING

static void ShowContestWinnerCleanup(void)
{
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ShowContestWinner(void)
{
    SetMainCallback2(sub_812FDEC);
    gMain.savedCallback = ShowContestWinnerCleanup;
}

void sub_80F8AFC(void)
{
    int i;

    if (gIsLinkContest & 1)
    {
        for (i = 0; i < gUnknown_02039F30; i++)
        {
            int version = (u8)gLinkPlayers[i].version;
            if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[i].gender == MALE)
                    gContestMons[i].trainerGfxId = EVENT_OBJ_GFX_LINK_RS_BRENDAN;
                else
                    gContestMons[i].trainerGfxId = EVENT_OBJ_GFX_LINK_RS_MAY;
            }
        }

        VarSet(VAR_OBJ_GFX_ID_0, gContestMons[0].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_1, gContestMons[1].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_2, gContestMons[2].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_3, gContestMons[3].trainerGfxId);
    }
}

void sub_80F8B94(void)
{
    int i;
    u8 eventObjectId;
    int version;
    struct Sprite *sprite;

    gReservedSpritePaletteCount = 12;
    if (gIsLinkContest & 1)
    {
        for (i = 0; i < gUnknown_02039F30; i++)
        {
            eventObjectId = GetEventObjectIdByLocalIdAndMap(gUnknown_0858D8EC[i], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            sprite = &gSprites[gEventObjects[eventObjectId].spriteId];
            sprite->oam.paletteNum = 6 + i;
            version = (u8)gLinkPlayers[i].version;
            if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[i].gender == MALE)
                    LoadPalette(gEventObjectPalette33, 0x160 + i * 0x10, 0x20);
                else
                    LoadPalette(gEventObjectPalette34, 0x160 + i * 0x10, 0x20);
            }
            else
            {
                if (gLinkPlayers[i].gender == MALE)
                    LoadPalette(gEventObjectPalette8, 0x160 + i * 0x10, 0x20);
                else
                    LoadPalette(gEventObjectPalette17, 0x160 + i * 0x10, 0x20);
            }
        }
    }
}

u8 GiveMonArtistRibbon(void)
{
    u8 hasArtistRibbon;

    hasArtistRibbon = GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_ARTIST_RIBBON);
    if (!hasArtistRibbon && gContestFinalStandings[gContestPlayerMonIndex] == 0 && gSpecialVar_ContestRank == 3
     && gUnknown_02039F08[gContestPlayerMonIndex] >= 800)
    {
        hasArtistRibbon = 1;
        SetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_ARTIST_RIBBON, &hasArtistRibbon);
        if (GetRibbonCount(&gPlayerParty[gUnknown_02039F24]) > 4)
            sub_80EE4DC(&gPlayerParty[gUnknown_02039F24], MON_DATA_ARTIST_RIBBON);
        
        return 1;
    }
    else
    {
        return 0;
    }
}

u8 sub_80F8D24(void)
{
    return 0;
}

void ShowContestEntryMonPic(void)
{
    const struct CompressedSpritePalette *palette;
    u32 personality, otId;
    u16 species;
    u8 spriteId;
    u8 taskId;
    u8 left, top;

    if (FindTaskIdByFunc(sub_80F8EE8) == 0xFF)
    {
        AllocateMonSpritesGfx();
        left = 10;
        top = 3;
        species = gContestMons[gSpecialVar_0x8006].species;
        personality = gContestMons[gSpecialVar_0x8006].personality;
        otId = gContestMons[gSpecialVar_0x8006].otId;
        taskId = CreateTask(sub_80F8EE8, 0x50);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = species;
        if (gSpecialVar_0x8006 == gContestPlayerMonIndex)
            HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);
        else
            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);

        palette = GetMonSpritePalStructFromOtIdPersonality(species, otId, personality);
        LoadCompressedObjectPalette(palette);
        SetMultiuseSpriteTemplateToPokemon(species, 1);
        gMultiuseSpriteTemplate.paletteTag = palette->tag;
        spriteId = CreateSprite(&gMultiuseSpriteTemplate, (left + 1) * 8 + 32, (top * 8) + 40, 0);

        if (gIsLinkContest & 1)
        {
            if (!(gIsLinkContest & 4))
                DoMonFrontSpriteAnimation(&gSprites[spriteId], species, FALSE, 0);
        }
        else
        {
            DoMonFrontSpriteAnimation(&gSprites[spriteId], species, FALSE, 0);
        }

        gTasks[taskId].data[2] = spriteId;
        gTasks[taskId].data[3] = left;
        gTasks[taskId].data[4] = top;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
    }
}

void sub_80F8EB8(void)
{
    u8 taskId = FindTaskIdByFunc(sub_80F8EE8);
    if (taskId != 0xFF)
    {
        gTasks[taskId].data[0]++;
        FreeMonSpritesGfx();
    }
}

static void sub_80F8EE8(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct Sprite *sprite;

    switch(task->data[0])
    {
    case 0:
        task->data[0]++;
        break;
    case 1:
        task->data[5] = CreateWindowFromRect(10, 3, 8, 8);
        SetStandardWindowBorderStyle(task->data[5], 1);
        task->data[0]++;
        break;
    case 2:
        break;
    case 3:
        sprite = &gSprites[task->data[2]];
        FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(sprite->oam.paletteNum));

        if(sprite->oam.affineMode)
            FreeOamMatrix(sprite->oam.matrixNum);

        DestroySprite(sprite);
        task->data[0]++;
        break;
    case 4:
        sub_80E2A78(gTasks[taskId].data[5]);
        DestroyTask(taskId);
        break;
    }
}

void ScriptGetMultiplayerId(void)
{
    if ((gIsLinkContest & 1) && gUnknown_02039F30 == 4 && !(gIsLinkContest & 2))
        gSpecialVar_Result = GetMultiplayerId();
    else
        gSpecialVar_Result = 4;
}

void ScriptRandom(void)
{
    u16 random;
    u16 *scriptPtr;

    if (gIsLinkContest & 1)
    {
        gContestRngValue = 1103515245 * gContestRngValue + 24691;
        random = gContestRngValue >> 16;
        scriptPtr = &gSpecialVar_Result;
    }
    else
    {
        scriptPtr = &gSpecialVar_Result;
        random = Random();
    }
    *scriptPtr = random % *scriptPtr;
}

u16 sub_80F903C(void)
{
    gContestRngValue = 1103515245 * gContestRngValue + 24691;
    return gContestRngValue >> 16;
}

u8 sub_80F905C(void)
{
    if (gIsLinkContest & 2)
    {
        CreateTask(sub_80F9088, 5);
        return 1;
    }
    else
    {
        return 0;
    }
}

static void sub_80F9088(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (sub_800A520())
        {
            sub_800ADF8();
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        gTasks[taskId].data[0]++;
        break;
    default:
        if (sub_800A520() == 1)
        {
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
        break;
    }
}

void sub_80F90DC(void)
{
    if (gIsLinkContest & 2)
    {
        if (gReceivedRemoteLinkPlayers)
        {
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(8, 8);
        }
    }
}

void sub_80F910C(void)
{
    if (gIsLinkContest & 2)
    {
        if (gReceivedRemoteLinkPlayers)
            sub_800E084();
    }
}

u8 sub_80F9134(void)
{
    if (gIsLinkContest & 4)
        return 1;
    else
        return 0;
}

void sub_80F9154(void)
{
    gIsLinkContest = 0;
}

u8 sub_80F9160(void)
{
    if (gIsLinkContest & 2)
        return 1;
    else
        return 0;
}

void HealPlayerParty(void)
{
    u8 i, j;
    u8 ppBonuses;
    u8 arg[4];

    // restore HP.
    for(i = 0; i < gPlayerPartyCount; i++)
    {
        u16 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, arg);
        ppBonuses = GetMonData(&gPlayerParty[i], MON_DATA_PP_BONUSES);

        // restore PP.
        for(j = 0; j < 4; j++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j), ppBonuses, j);
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, arg);
        }

        // since status is u32, the four 0 assignments here are probably for safety to prevent undefined data from reaching SetMonData.
        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, arg);
    }
}

u8 ScriptGiveMon(u16 species, u8 level, u16 item, u32 unused1, u32 unused2, u8 unused3)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;

    CreateMon(&mon, species, level, 32, 0, 0, 0, 0);
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(&mon);
    nationalDexNum = SpeciesToNationalPokedexNum(species);

    switch(sentToPc)
    {
    case 0:
    case 1:
        GetSetPokedexFlag(nationalDexNum, 2);
        GetSetPokedexFlag(nationalDexNum, 3);
        break;
    }
    return sentToPc;
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    return GiveMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case 0:
        gSpecialVar_Result = 0;
        break;
    case 1:
        gSpecialVar_Result = 1;
        break;
    case 2:
        gSpecialVar_Result = 2;
        break;
    }
}

static bool8 CheckPartyMonHasHeldItem(u16 item)
{
    int i;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 sub_80F9370(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY);
    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, u16 item)
{
    u8 heldItem[2];

    ZeroEnemyPartyMons();
    CreateMon(&gEnemyParty[0], species, level, 0x20, 0, 0, 0, 0);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot)
{
    if (monIndex > PARTY_SIZE)
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

void sub_80F9438(void)
{
    gMain.savedCallback = sub_80F9460;
    VarSet(VAR_FRONTIER_FACILITY, 9); // this isn't a valid frontier facility id (??)
    sub_81B8518(0);
}

static void sub_80F9460(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = 0;
        break;
    default:
        gSpecialVar_Result = 1;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void sub_80F9490(void)
{
    gMain.savedCallback = sub_80F94B8;
    sub_81B8518(gSpecialVar_0x8004 + 1);
}

static void sub_80F94B8(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = 0;
        break;
    default:
        gSpecialVar_Result = 1;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[4];
    int i;

    CpuFill32(0, party, sizeof party);

    // copy the selected pokemon according to the order.
    for (i = 0; i < 4; i++)
        if (gSelectedOrderFromParty[i]) // as long as the order keeps going (did the player select 1 mon? 2? 3?), do not stop
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1]; // index is 0 based, not literal

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    // overwrite the first 4 with the order copied to.
    for (i = 0; i < 4; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}
