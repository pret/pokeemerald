#include "global.h"
#include "battle.h"
#include "pokemon.h"
#include "battle_interface.h"
#include "sprite.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "battle_controllers.h"
#include "sound.h"
#include "songs.h"
#include "decompress.h"
#include "task.h"
#include "util.h"
#include "gpu_regs.h"
#include "battle_message.h"
#include "species.h"
#include "pokedex.h"
#include "palette.h"
#include "international_string_util.h"
#include "safari_zone.h"

extern bool8 IsDoubleBattle(void);
extern u8 gBanksByIdentity[BATTLE_BANKS_COUNT];
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gNoOfAllBanks;
extern u8 gHealthBoxesIds[BATTLE_BANKS_COUNT];

extern const u8 * const gNatureNamePointers[];
extern const u8 gText_Slash[];

// this file's functions
void sub_8072924(struct Sprite *sprite);
void sub_80728B4(struct Sprite *sprite);
const u32 *GetHealthboxElementGfxPtr(u8 elementId);
u32 AddTextPrinterAndCreateWindowOnHealthbox(const u8 *str, u32 x, u32 y, u32 arg3, u32 *windowId);
void sub_8075198(void *objVram, u32 windowTileData, u32 arg2);
void sub_80751E4(void *objVram, u32 windowTileData, u32 arg2);
void RemoveWindowOnHealthbox(u32 windowId);
void sub_8075170(void *dest, u32 arg1, u32 arg2);
void UpdateHpTextInHealthboxInDoubles(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent);
void sub_807513C(void *dest, u32 arg1, u32 arg2);
void UpdateStatusIconInHealthbox(u8 healthboxSpriteId);
void sub_80741C8(struct Sprite *sprite);
void sub_8073E08(u8 taskId);
void sub_8073F98(u8 taskId);
void sub_8073E64(u8 taskId);
void sub_8074158(struct Sprite *sprite);
void sub_8074090(struct Sprite *sprite);
u8 GetStatusIconForBankId(u8 statusElementId, u8 bank);
void sub_8074AA0(u8 bank, u8 healthboxSpriteId, u8 whichBar, u8 arg3);

// const rom data
const struct OamData gUnknown_0832C138 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

extern const struct SubspriteTable gUnknown_0832C28C[2];

static const struct SpriteTemplate gUnknown_0832C140[2] =
{
    {
        .tileTag = 0xD6FF,
        .paletteTag = 0xD6FF,
        .oam = &gUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = 0xd700,
        .paletteTag = 0xD6FF,
        .oam = &gUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    }
};

static const struct SpriteTemplate gUnknown_0832C170[2] =
{
    {
        .tileTag = 0xd701,
        .paletteTag = 0xD6FF,
        .oam = &gUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    {
        .tileTag = 0xd702,
        .paletteTag = 0xD6FF,
        .oam = &gUnknown_0832C138,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    }
};

static const struct SpriteTemplate gUnknown_0832C1A0 =
{
    .tileTag = 0xd70b,
    .paletteTag = 0xd6ff,
    .oam = &gUnknown_0832C138,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct OamData gUnknown_0832C1B8 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate gUnknown_0832C1C0[4] =
{
    {
        .tileTag = 0xd704,
        .paletteTag = 0xd704,
        .oam = &gUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    },
    {
        .tileTag = 0xd705,
        .paletteTag = 0xd704,
        .oam = &gUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    },
    {
        .tileTag = 0xd706,
        .paletteTag = 0xd704,
        .oam = &gUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    },
    {
        .tileTag = 0xd707,
        .paletteTag = 0xd704,
        .oam = &gUnknown_0832C1B8,
        .anims = gDummySpriteAnimTable,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = sub_80728B4
    }
};

extern const u8 gUnknown_0832C3C4[0x14];
extern const u8 gUnknown_0832C3D8[0x14];
extern const u32 gHealthboxElementsGfxTable[][8];
extern const struct CompressedSpriteSheet gUnknown_0832C334;
extern const struct SpriteSheet gUnknown_0832C34C;
extern const struct SpritePalette gUnknown_0832C33C;
extern const struct SpritePalette gUnknown_0832C344;
extern const struct SpriteTemplate gUnknown_0832C364[2];
extern const struct SpriteTemplate gUnknown_0832C394[2];
extern const struct SubspriteTable gUnknown_0832C2C4;
extern const struct SubspriteTable gUnknown_0832C2CC;
extern const u16 gBattleInterfaceStatusIcons_DynPals[];

u8 sub_8072304(void)
{
    return 9;
}

#ifdef NONMATCHING
void sub_8072308(s16 arg0, u16 *arg1, u8 arg2)
{
    s8 i, j;
    s8 array[4];

    for (i = 0; i < 4; i++)
        array[i] = 0;

    i = 3;
    while (1)
    {
        if (arg0 < 0)
            break;

        array[i] = arg0 % 10;
        arg0 /= 10;
        i--;
    }

    for (j = i; j > -1; j--)
    {
        array[j] = -1;
    }

    if (array[3] == -1)
        array[3] = 0;

    if (arg2 == 0)
    {
        for (i = 0; i < 4; i++)
        {
            if (array[i] == -1)
            {
                arg1[i] &= 0xFC00;
                arg1[i] |= 0x1E;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= 0x1E;
            }
            else
            {
                arg1[i] &= 0xFC00;
                arg1[i] |= array[i] + 0x14;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= array[i] + 0x34;
            }
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (array[i] == -1)
            {
                arg1[i] &= 0xFC00;
                arg1[i] |= 0x1E;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= 0x1E;
            }
            else
            {
                arg1[i] &= 0xFC00;
                arg1[i] |= array[i] + 0x14;

                arg1[i + 0x20] &= 0xFC00;
                arg1[i + 0x20] |= array[i] + 0x34;
            }
        }
    }
}

#else
__attribute__((naked))
void sub_8072308(s16 arg0, u16 *arg1, u8 arg2)
{
    asm(".syntax unified\n\
        	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x4\n\
	adds r7, r1, 0\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	mov r10, r2\n\
	movs r3, 0\n\
	movs r2, 0\n\
_08072324:\n\
	lsls r0, r3, 24\n\
	asrs r0, 24\n\
	mov r3, sp\n\
	adds r1, r3, r0\n\
	strb r2, [r1]\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r3, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x3\n\
	ble _08072324\n\
	movs r3, 0x3\n\
	movs r0, 0x1\n\
	negs r0, r0\n\
	mov r9, r0\n\
	mov r8, sp\n\
_08072344:\n\
	lsls r0, r5, 16\n\
	asrs r6, r0, 16\n\
	cmp r6, 0\n\
	ble _08072372\n\
	lsls r4, r3, 24\n\
	asrs r4, 24\n\
	mov r1, sp\n\
	adds r5, r1, r4\n\
	adds r0, r6, 0\n\
	movs r1, 0xA\n\
	bl __modsi3\n\
	strb r0, [r5]\n\
	adds r0, r6, 0\n\
	movs r1, 0xA\n\
	bl __divsi3\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	subs r4, 0x1\n\
	lsls r4, 24\n\
	lsrs r3, r4, 24\n\
	b _08072344\n\
_08072372:\n\
	lsls r1, r3, 24\n\
	asrs r0, r1, 24\n\
	cmp r0, r9\n\
	ble _08072396\n\
	movs r4, 0xFF\n\
	movs r3, 0x1\n\
	negs r3, r3\n\
_08072380:\n\
	asrs r2, r1, 24\n\
	mov r5, sp\n\
	adds r1, r5, r2\n\
	ldrb r0, [r1]\n\
	orrs r0, r4\n\
	strb r0, [r1]\n\
	subs r2, 0x1\n\
	lsls r1, r2, 24\n\
	asrs r0, r1, 24\n\
	cmp r0, r3\n\
	bgt _08072380\n\
_08072396:\n\
	mov r1, r8\n\
	ldrb r0, [r1, 0x3]\n\
	cmp r0, 0xFF\n\
	bne _080723A2\n\
	movs r0, 0\n\
	strb r0, [r1, 0x3]\n\
_080723A2:\n\
	mov r2, r10\n\
	cmp r2, 0\n\
	bne _08072432\n\
	movs r3, 0\n\
	movs r1, 0\n\
	movs r6, 0xFC\n\
	lsls r6, 8\n\
	movs r5, 0x1E\n\
	mov r12, r5\n\
_080723B4:\n\
	lsls r1, 24\n\
	asrs r2, r1, 24\n\
	mov r0, sp\n\
	adds r5, r0, r2\n\
	ldrb r0, [r5]\n\
	mov r8, r1\n\
	cmp r0, 0xFF\n\
	bne _080723EA\n\
	lsls r1, r2, 1\n\
	adds r1, r7\n\
	ldrh r2, [r1]\n\
	adds r0, r6, 0\n\
	ands r0, r2\n\
	mov r2, r12\n\
	orrs r0, r2\n\
	strh r0, [r1]\n\
	lsls r3, 24\n\
	asrs r1, r3, 23\n\
	adds r1, r7\n\
	adds r1, 0x40\n\
	ldrh r2, [r1]\n\
	adds r0, r6, 0\n\
	ands r0, r2\n\
	mov r5, r12\n\
	orrs r0, r5\n\
	strh r0, [r1]\n\
	b _0807241A\n\
_080723EA:\n\
	lsls r2, 1\n\
	adds r2, r7\n\
	ldrh r0, [r2]\n\
	adds r1, r6, 0\n\
	ands r1, r0\n\
	ldrb r0, [r5]\n\
	adds r0, 0x14\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	lsls r4, r3, 24\n\
	asrs r3, r4, 24\n\
	lsls r2, r3, 1\n\
	adds r2, r7\n\
	adds r2, 0x40\n\
	ldrh r0, [r2]\n\
	adds r1, r6, 0\n\
	ands r1, r0\n\
	mov r5, sp\n\
	adds r0, r5, r3\n\
	ldrb r0, [r0]\n\
	adds r0, 0x34\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	adds r3, r4, 0\n\
_0807241A:\n\
	movs r0, 0x80\n\
	lsls r0, 17\n\
	add r0, r8\n\
	lsrs r1, r0, 24\n\
	movs r2, 0x80\n\
	lsls r2, 17\n\
	adds r0, r3, r2\n\
	lsrs r3, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x3\n\
	ble _080723B4\n\
	b _08072496\n\
_08072432:\n\
	movs r3, 0\n\
	movs r4, 0xFC\n\
	lsls r4, 8\n\
	movs r6, 0x1E\n\
_0807243A:\n\
	lsls r1, r3, 24\n\
	asrs r2, r1, 24\n\
	mov r3, sp\n\
	adds r5, r3, r2\n\
	ldrb r0, [r5]\n\
	adds r3, r1, 0\n\
	cmp r0, 0xFF\n\
	bne _08072466\n\
	lsls r1, r2, 1\n\
	adds r1, r7\n\
	ldrh r2, [r1]\n\
	adds r0, r4, 0\n\
	ands r0, r2\n\
	orrs r0, r6\n\
	strh r0, [r1]\n\
	adds r1, 0x40\n\
	ldrh r2, [r1]\n\
	adds r0, r4, 0\n\
	ands r0, r2\n\
	orrs r0, r6\n\
	strh r0, [r1]\n\
	b _08072488\n\
_08072466:\n\
	lsls r2, 1\n\
	adds r2, r7\n\
	ldrh r0, [r2]\n\
	adds r1, r4, 0\n\
	ands r1, r0\n\
	ldrb r0, [r5]\n\
	adds r0, 0x14\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
	adds r2, 0x40\n\
	ldrh r0, [r2]\n\
	adds r1, r4, 0\n\
	ands r1, r0\n\
	ldrb r0, [r5]\n\
	adds r0, 0x34\n\
	orrs r1, r0\n\
	strh r1, [r2]\n\
_08072488:\n\
	movs r5, 0x80\n\
	lsls r5, 17\n\
	adds r0, r3, r5\n\
	lsrs r3, r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0x3\n\
	ble _0807243A\n\
_08072496:\n\
	add sp, 0x4\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
        .syntax divided");
}

#endif // NONMATCHING

void sub_80724A8(s16 arg0, s16 arg1, u16 *arg2)
{
    arg2[4] = 0x1E;
    sub_8072308(arg1, arg2, 0);
    sub_8072308(arg0, arg2 + 5, 1);
}

u8 CreateBankHealthboxSprites(u8 bank)
{
    s16 data6 = 0;
    u8 healthboxSpriteId_1, healthboxSpriteId_2;
    u8 unkSpriteId;
    struct Sprite *unkSpritePtr;

    if (!IsDoubleBattle())
    {
        if (GetBankSide(bank) == SIDE_PLAYER)
        {
            healthboxSpriteId_1 = CreateSprite(&gUnknown_0832C140[0], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&gUnknown_0832C140[0], 240, 160, 1);

            gSprites[healthboxSpriteId_1].oam.shape = 0;

            gSprites[healthboxSpriteId_2].oam.shape = 0;
            gSprites[healthboxSpriteId_2].oam.tileNum += 64;
        }
        else
        {
            healthboxSpriteId_1 = CreateSprite(&gUnknown_0832C170[0], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&gUnknown_0832C170[0], 240, 160, 1);

            gSprites[healthboxSpriteId_2].oam.tileNum += 32;

            data6 = 2;
        }
        gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;
        gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;
        gSprites[healthboxSpriteId_2].callback = sub_8072924;
    }
    else
    {
        if (GetBankSide(bank) == SIDE_PLAYER)
        {
            healthboxSpriteId_1 = CreateSprite(&gUnknown_0832C140[GetBankIdentity(bank) / 2], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&gUnknown_0832C140[GetBankIdentity(bank) / 2], 240, 160, 1);

            gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;

            gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;
            gSprites[healthboxSpriteId_2].oam.tileNum += 32;
            gSprites[healthboxSpriteId_2].callback = sub_8072924;

            data6 = 1;
        }
        else
        {
            healthboxSpriteId_1 = CreateSprite(&gUnknown_0832C170[GetBankIdentity(bank) / 2], 240, 160, 1);
            healthboxSpriteId_2 = CreateSpriteAtEnd(&gUnknown_0832C170[GetBankIdentity(bank) / 2], 240, 160, 1);

            gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;

            gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;
            gSprites[healthboxSpriteId_2].oam.tileNum += 32;
            gSprites[healthboxSpriteId_2].callback = sub_8072924;

            data6 = 2;
        }
    }

    unkSpriteId = CreateSpriteAtEnd(&gUnknown_0832C1C0[gBanksByIdentity[bank]], 140, 60, 0);
    unkSpritePtr = &gSprites[unkSpriteId];
    SetSubspriteTables(unkSpritePtr, &gUnknown_0832C28C[GetBankSide(bank)]);
    unkSpritePtr->subspriteMode = 2;
    unkSpritePtr->oam.priority = 1;

    CpuCopy32(GetHealthboxElementGfxPtr(1), (void*)(OBJ_VRAM0 + unkSpritePtr->oam.tileNum * 32), 64);

    gSprites[healthboxSpriteId_1].data5 = unkSpriteId;
    gSprites[healthboxSpriteId_1].data6 = bank;
    gSprites[healthboxSpriteId_1].invisible = 1;

    gSprites[healthboxSpriteId_2].invisible = 1;

    unkSpritePtr->data5 = healthboxSpriteId_1;
    unkSpritePtr->data6 = data6;
    unkSpritePtr->invisible = 1;

    return healthboxSpriteId_1;
}

u8 CreateSafariPlayerHealthboxSprites(void)
{
    u8 healthboxSpriteId_1, healthboxSpriteId_2;

    healthboxSpriteId_1 = CreateSprite(&gUnknown_0832C1A0, 240, 160, 1);
    healthboxSpriteId_2 = CreateSpriteAtEnd(&gUnknown_0832C1A0, 240, 160, 1);

    gSprites[healthboxSpriteId_1].oam.shape = 0;
    gSprites[healthboxSpriteId_2].oam.shape = 0;

    gSprites[healthboxSpriteId_2].oam.tileNum += 64;

    gSprites[healthboxSpriteId_1].oam.affineParam = healthboxSpriteId_2;
    gSprites[healthboxSpriteId_2].data5 = healthboxSpriteId_1;

    gSprites[healthboxSpriteId_2].callback = sub_8072924;

    return healthboxSpriteId_1;
}

const u32 *GetHealthboxElementGfxPtr(u8 elementId)
{
    return gHealthboxElementsGfxTable[elementId];
}

void sub_80728B4(struct Sprite *sprite)
{
    u8 var = sprite->data5;

    switch (sprite->data6)
    {
    case 0:
        sprite->pos1.x = gSprites[var].pos1.x + 16;
        sprite->pos1.y = gSprites[var].pos1.y;
        break;
    case 1:
        sprite->pos1.x = gSprites[var].pos1.x + 16;
        sprite->pos1.y = gSprites[var].pos1.y;
        break;
    case 2:
    default:
        sprite->pos1.x = gSprites[var].pos1.x + 8;
        sprite->pos1.y = gSprites[var].pos1.y;
        break;
    }

    sprite->pos2.x = gSprites[var].pos2.x;
    sprite->pos2.y = gSprites[var].pos2.y;
}

void sub_8072924(struct Sprite *sprite)
{
    u8 otherSpriteId = sprite->data5;

    sprite->pos1.x = gSprites[otherSpriteId].pos1.x + 64;
    sprite->pos1.y = gSprites[otherSpriteId].pos1.y;

    sprite->pos2.x = gSprites[otherSpriteId].pos2.x;
    sprite->pos2.y = gSprites[otherSpriteId].pos2.y;
}

void SetBattleBarStruct(u8 bank, u8 healthboxSpriteId, u32 maxVal, u32 currVal, bool32 isDoubleBattle)
{
    gBattleSpritesDataPtr->battleBars[bank].healthboxSpriteId = healthboxSpriteId;
    gBattleSpritesDataPtr->battleBars[bank].maxValue = maxVal;
    gBattleSpritesDataPtr->battleBars[bank].currentValue = currVal;
    gBattleSpritesDataPtr->battleBars[bank].isDoubleBattle = isDoubleBattle;
    gBattleSpritesDataPtr->battleBars[bank].field_10 = -32768;
}

void SetHealthboxSpriteInvisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = 1;
    gSprites[gSprites[healthboxSpriteId].data5].invisible = 1;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = 1;
}

void SetHealthboxSpriteVisible(u8 healthboxSpriteId)
{
    gSprites[healthboxSpriteId].invisible = 0;
    gSprites[gSprites[healthboxSpriteId].data5].invisible = 0;
    gSprites[gSprites[healthboxSpriteId].oam.affineParam].invisible = 0;
}

static void UpdateSpritePos(u8 spriteId, s16 x, s16 y)
{
    gSprites[spriteId].pos1.x = x;
    gSprites[spriteId].pos1.y = y;
}

void DestoryHealthboxSprite(u8 healthboxSpriteId)
{
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].oam.affineParam]);
    DestroySprite(&gSprites[gSprites[healthboxSpriteId].data5]);
    DestroySprite(&gSprites[healthboxSpriteId]);
}

void nullsub_30(u8 healthboxSpriteId, bool8 isDoubleBattleBankOnly)
{

}

void UpdateOamPriorityInAllHealthboxes(u8 priority)
{
    s32 i;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        u8 healthboxSpriteId_1 = gHealthBoxesIds[i];
        u8 healthboxSpriteId_2 = gSprites[gHealthBoxesIds[i]].oam.affineParam;
        u8 healthboxSpriteId_3 = gSprites[gHealthBoxesIds[i]].data5;

        gSprites[healthboxSpriteId_1].oam.priority = priority;
        gSprites[healthboxSpriteId_2].oam.priority = priority;
        gSprites[healthboxSpriteId_3].oam.priority = priority;
    }
}

void SetBankHealthboxSpritePos(u8 bank)
{
    s16 x = 0, y = 0;

    if (!IsDoubleBattle())
    {
        if (GetBankSide(bank) != SIDE_PLAYER)
            x = 44, y = 30;
        else
            x = 158, y = 88;
    }
    else
    {
        switch (GetBankIdentity(bank))
        {
        case IDENTITY_PLAYER_MON1:
            x = 159, y = 76;
            break;
        case IDENTITY_PLAYER_MON2:
            x = 171, y = 101;
            break;
        case IDENTITY_OPPONENT_MON1:
            x = 44, y = 19;
            break;
        case IDENTITY_OPPONENT_MON2:
            x = 32, y = 44;
            break;
        }
    }

    UpdateSpritePos(gHealthBoxesIds[bank], x, y);
}

void UpdateLvlInHealthbox(u8 healthboxSpriteId, u8 lvl)
{
    u32 windowId, windowTileData, spriteTileNum;
    u8 text[16];
    u32 xPos, var1;
    void *objVram;

    text[0] = 0xF9;
    text[1] = 5;

    xPos = (u32) ConvertIntToDecimalStringN(text + 2, lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
    // Alright, that part was unmatchable. It's basically doing:
    // xPos = 5 * (3 - (u32)(&text[2]));
    xPos--;
    xPos--;
    xPos -= ((u32)(text));
    var1 = (3 - xPos);
    xPos = 4 * var1;
    xPos += var1;

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, xPos, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        objVram = (void*)(OBJ_VRAM0);
        if (!IsDoubleBattle())
            objVram += spriteTileNum + 0x820;
        else
            objVram += spriteTileNum + 0x420;
    }
    else
    {
        objVram = (void*)(OBJ_VRAM0);
        objVram += spriteTileNum + 0x400;
    }
    sub_8075198(objVram, windowTileData, 3);
    RemoveWindowOnHealthbox(windowId);
}

void UpdateHpTextInHealthbox(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent)
{
    u32 windowId, windowTileData, spriteTileNum;
    u8 text[32];
    void *objVram;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER && !IsDoubleBattle())
    {
        spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;
        if (maxOrCurrent) // singles, max
        {
            ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 0, 5, 2, &windowId);
            objVram = (void*)(OBJ_VRAM0);
            objVram += spriteTileNum + 0xB40;
            sub_8075170(objVram, windowTileData, 2);
            RemoveWindowOnHealthbox(windowId);
        }
        else // singles, current
        {
            ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text[3] = CHAR_SLASH;
            text[4] = EOS;
            windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 4, 5, 2, &windowId);
            objVram = (void*)(OBJ_VRAM0);
            objVram += spriteTileNum + 0x3E0;
            sub_8075170(objVram, windowTileData, 1);
            objVram = (void*)(OBJ_VRAM0);
            objVram += spriteTileNum + 0xB00;
            sub_8075170(objVram, windowTileData + 0x20, 2);
            RemoveWindowOnHealthbox(windowId);
        }

    }
    else
    {
        u8 bank;

        memcpy(text, gUnknown_0832C3C4, sizeof(gUnknown_0832C3C4));
        bank = gSprites[healthboxSpriteId].data6;
        if (IsDoubleBattle() == TRUE || GetBankSide(bank) == SIDE_OPPONENT)
        {
            UpdateHpTextInHealthboxInDoubles(healthboxSpriteId, value, maxOrCurrent);
        }
        else
        {
            u32 var;
            u8 i;

            if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
            {
                if (!maxOrCurrent)
                    var = 29;
                else
                    var = 89;
            }
            else
            {
                if (!maxOrCurrent)
                    var = 20;
                else
                    var = 48;
            }

            ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            RenderTextFont9(gMonSpritesGfxPtr->fontPixels, 9, text);

            for (i = 0; i < 3; i++)
            {
                CpuCopy32(&gMonSpritesGfxPtr->fontPixels[i * 64 + 32],
                          (void*)((OBJ_VRAM0) + 32 * (gSprites[healthboxSpriteId].oam.tileNum + var + i)),
                          0x20);
            }
        }
    }
}

void UpdateHpTextInHealthboxInDoubles(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent)
{
    u32 windowId, windowTileData, spriteTileNum;
    u8 text[32];
    void *objVram;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        if (gBattleSpritesDataPtr->bankData[gSprites[healthboxSpriteId].data6].hpNumbersNoBars) // don't print text if only bars are visible
        {
            spriteTileNum = gSprites[gSprites[healthboxSpriteId].data5].oam.tileNum * 32;
            objVram = (void*)(OBJ_VRAM0) + spriteTileNum;

            if (maxOrCurrent) // doubles, max hp
            {
                ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
                windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 0, 5, 0, &windowId);
                sub_8075170((void*)(OBJ_VRAM0) + spriteTileNum + 0xC0, windowTileData, 2);
                RemoveWindowOnHealthbox(windowId);
                CpuCopy32(GetHealthboxElementGfxPtr(0x74),
                          (void*)(OBJ_VRAM0 + 0x680) + (gSprites[healthboxSpriteId].oam.tileNum * 32),
                           0x20);
            }
            else
            {
                ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
                text[3] = CHAR_SLASH;
                text[4] = EOS;
                windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, 4, 5, 0, &windowId);
                sub_807513C(objVram, 0, 3);
                sub_8075170((void*)(OBJ_VRAM0 + 0x60) + spriteTileNum, windowTileData, 3);
                RemoveWindowOnHealthbox(windowId);
            }
        }
    }
    else
    {
        u8 bank;

        memcpy(text, gUnknown_0832C3D8, sizeof(gUnknown_0832C3D8));
        bank = gSprites[healthboxSpriteId].data6;

        if (gBattleSpritesDataPtr->bankData[bank].hpNumbersNoBars) // don't print text if only bars are visible
        {
            u8 var = 4;
            u8 r7;
            u8 *txtPtr;
            u8 i;

            if (!maxOrCurrent)
                var = 0;

            r7 = gSprites[healthboxSpriteId].data5;
            txtPtr = ConvertIntToDecimalStringN(text + 6, value, STR_CONV_MODE_RIGHT_ALIGN, 3);
            if (!maxOrCurrent)
                StringCopy(txtPtr, gText_Slash);
            RenderTextFont9(gMonSpritesGfxPtr->fontPixels, 9, text);

            for (i = var; i < var + 3; i++)
            {
                if (i < 3)
                {
                    CpuCopy32(&gMonSpritesGfxPtr->fontPixels[((i - var) * 64) + 32],
                          (void*)((OBJ_VRAM0) + 32 * (1 + gSprites[r7].oam.tileNum + i)),
                          0x20);
                }
                else
                {
                    CpuCopy32(&gMonSpritesGfxPtr->fontPixels[((i - var) * 64) + 32],
                          (void*)((OBJ_VRAM0 + 0x20) + 32 * (i + gSprites[r7].oam.tileNum)),
                          0x20);
                }
            }

            if (!maxOrCurrent)
            {
                CpuCopy32(&gMonSpritesGfxPtr->fontPixels[224],
                          (void*)((OBJ_VRAM0) + ((gSprites[r7].oam.tileNum + 4) * 32)),
                          0x20);
                CpuFill32(0, (void*)((OBJ_VRAM0) + (gSprites[r7].oam.tileNum * 32)), 0x20);
            }
            else
            {
                if (GetBankSide(bank) == SIDE_PLAYER) // impossible to reach part, because the bank is from the opponent's side
                {
                    CpuCopy32(GetHealthboxElementGfxPtr(0x74),
                          (void*)(OBJ_VRAM0) + ((gSprites[healthboxSpriteId].oam.tileNum + 52) * 32),
                           0x20);
                }
            }
        }
    }
}

void sub_80730D4(u8 healthboxSpriteId, struct Pokemon *mon)
{
    u8 text[20];
    s32 j, var2;
    u8 *fontPixels;
    u8 i, var, nature, healthboxSpriteId_2;

    memcpy(text, gUnknown_0832C3C4, sizeof(gUnknown_0832C3C4));
    fontPixels = &gMonSpritesGfxPtr->fontPixels[0x520 + (GetBankIdentity(gSprites[healthboxSpriteId].data6) * 384)];
    var = 5;
    nature = GetNature(mon);
    StringCopy(text + 6, gNatureNamePointers[nature]);
    RenderTextFont9(fontPixels, 9, text);

    for (j = 6, i = 0; i < var; i++, j++)
    {
        u8 elementId;

        if ((text[j] >= 55 && text[j] <= 74) || (text[j] >= 135 && text[j] <= 154))
            elementId = 44;
        else if ((text[j] >= 75 && text[j] <= 79) || (text[j] >= 155 && text[j] <= 159))
            elementId = 45;
        else
            elementId = 43;

        CpuCopy32(GetHealthboxElementGfxPtr(elementId), fontPixels + (i * 64), 0x20);
    }

    for (j = 1; j < var + 1; j++)
    {
        var2 = (gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * 32;
        CpuCopy32(fontPixels, (void*)(OBJ_VRAM0) + (var2), 0x20);
        fontPixels += 0x20;

        var2 = (8 + gSprites[healthboxSpriteId].oam.tileNum + (j - (j / 8 * 8)) + (j / 8 * 64)) * 32;
        CpuCopy32(fontPixels, (void*)(OBJ_VRAM0) + (var2), 0x20);
        fontPixels += 0x20;
    }

    healthboxSpriteId_2 = gSprites[healthboxSpriteId].data5;
    ConvertIntToDecimalStringN(text + 6, gBattleStruct->field_7C, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(text + 9, gBattleStruct->field_7B, STR_CONV_MODE_RIGHT_ALIGN, 2);
    text[5] = CHAR_SPACE;
    text[8] = CHAR_SLASH;
    RenderTextFont9(gMonSpritesGfxPtr->fontPixels, 9, text);

    j = healthboxSpriteId_2; // needed to match for some reason
    for (j = 0; j < 5; j++)
    {
        if (j <= 1)
        {
            CpuCopy32(&gMonSpritesGfxPtr->fontPixels[0x40 * j + 0x20],
                      (void*)(OBJ_VRAM0) + (gSprites[healthboxSpriteId_2].oam.tileNum + 2 + j) * 32,
                      32);
        }
        else
        {
            CpuCopy32(&gMonSpritesGfxPtr->fontPixels[0x40 * j + 0x20],
                      (void*)(OBJ_VRAM0 + 0xC0) + (j + gSprites[healthboxSpriteId_2].oam.tileNum) * 32,
                      32);
        }
    }
}

void SwapHpBarsWithHpText(void)
{
    s32 i;
    u8 spriteId;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (gSprites[gHealthBoxesIds[i]].callback == SpriteCallbackDummy
         && GetBankSide(i) != SIDE_OPPONENT
         && (IsDoubleBattle() || GetBankSide(i) != SIDE_PLAYER))
        {
            bool8 noBars;

            gBattleSpritesDataPtr->bankData[i].hpNumbersNoBars ^= 1;
            noBars = gBattleSpritesDataPtr->bankData[i].hpNumbersNoBars;
            if (GetBankSide(i) == SIDE_PLAYER)
            {
                if (!IsDoubleBattle())
                    continue;
                if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    continue;

                if (noBars == TRUE) // bars to text
                {
                    spriteId = gSprites[gHealthBoxesIds[i]].data5;

                    CpuFill32(0, (void*)(OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * 32), 0x100);
                    UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gPlayerParty[gBattlePartyID[i]], MON_DATA_HP), 0);
                    UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gPlayerParty[gBattlePartyID[i]], MON_DATA_MAX_HP), 1);
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthBoxesIds[i]);
                    UpdateHealthboxAttribute(gHealthBoxesIds[i], &gPlayerParty[gBattlePartyID[i]], HEALTHBOX_HEALTH_BAR);
                    CpuCopy32(GetHealthboxElementGfxPtr(0x75), (void*)(OBJ_VRAM0 + 0x680 + gSprites[gHealthBoxesIds[i]].oam.tileNum * 32), 32);
                }
            }
            else
            {
                if (noBars == TRUE) // bars to text
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                    {
                        sub_80730D4(gHealthBoxesIds[i], &gEnemyParty[gBattlePartyID[i]]);
                    }
                    else
                    {
                        spriteId = gSprites[gHealthBoxesIds[i]].data5;

                        CpuFill32(0, (void *)(OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * 32), 0x100);
                        UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gEnemyParty[gBattlePartyID[i]], MON_DATA_HP), 0);
                        UpdateHpTextInHealthboxInDoubles(gHealthBoxesIds[i], GetMonData(&gEnemyParty[gBattlePartyID[i]], MON_DATA_MAX_HP), 1);
                    }
                }
                else // text to bars
                {
                    UpdateStatusIconInHealthbox(gHealthBoxesIds[i]);
                    UpdateHealthboxAttribute(gHealthBoxesIds[i], &gEnemyParty[gBattlePartyID[i]], HEALTHBOX_HEALTH_BAR);
                    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
                        UpdateHealthboxAttribute(gHealthBoxesIds[i], &gEnemyParty[gBattlePartyID[i]], HEALTHBOX_NICK);
                }
            }
            gSprites[gHealthBoxesIds[i]].data7 ^= 1;
        }
    }
}

u8 CreatePartyStatusSummarySprites(u8 bank, struct HpAndStatus *partyInfo, u8 arg2, bool8 isBattleStart)
{
    bool8 isOpponent;
    s16 bar_X, bar_Y, bar_pos2_X, bar_data0;
    s32 i, j, var;
    u8 barSpriteId;
    u8 ballIconSpritesIds[6];
    u8 taskId;

    if (!arg2 || GetBankIdentity(bank) != IDENTITY_OPPONENT_MON2)
    {
        if (GetBankSide(bank) == SIDE_PLAYER)
        {
            isOpponent = FALSE;
            bar_X = 136, bar_Y = 96;
            bar_pos2_X = 100;
            bar_data0 = -5;
        }
        else
        {
            isOpponent = TRUE;

            if (!arg2 || !IsDoubleBattle())
                bar_X = 104, bar_Y = 40;
            else
                bar_X = 104, bar_Y = 16;

            bar_pos2_X = -100;
            bar_data0 = 5;
        }
    }
    else
    {
        isOpponent = TRUE;
        bar_X = 104, bar_Y = 40;
        bar_pos2_X = -100;
        bar_data0 = 5;
    }

    LoadCompressedObjectPicUsingHeap(&gUnknown_0832C334);
    LoadSpriteSheet(&gUnknown_0832C34C);
    LoadSpritePalette(&gUnknown_0832C33C);
    LoadSpritePalette(&gUnknown_0832C344);

    barSpriteId = CreateSprite(&gUnknown_0832C364[isOpponent], bar_X, bar_Y, 10);
    SetSubspriteTables(&gSprites[barSpriteId], &gUnknown_0832C2C4);
    gSprites[barSpriteId].pos2.x = bar_pos2_X;
    gSprites[barSpriteId].data0 = bar_data0;

    if (isOpponent)
    {
        gSprites[barSpriteId].pos1.x -= 96;
        gSprites[barSpriteId].oam.matrixNum = 8;
    }
    else
    {
        gSprites[barSpriteId].pos1.x += 96;
    }

    for (i = 0; i < 6; i++)
    {
        ballIconSpritesIds[i] = CreateSpriteAtEnd(&gUnknown_0832C394[isOpponent], bar_X, bar_Y - 4, 9);

        if (!isBattleStart)
            gSprites[ballIconSpritesIds[i]].callback = sub_80741C8;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].pos2.x = 0;
            gSprites[ballIconSpritesIds[i]].pos2.y = 0;
        }

        gSprites[ballIconSpritesIds[i]].data0 = barSpriteId;

        if (!isOpponent)
        {
            gSprites[ballIconSpritesIds[i]].pos1.x += 10 * i + 24;
            gSprites[ballIconSpritesIds[i]].data1 = i * 7 + 10;
            gSprites[ballIconSpritesIds[i]].pos2.x = 120;
        }
        else
        {
            gSprites[ballIconSpritesIds[i]].pos1.x -= 10 * (5 - i) + 24;
            gSprites[ballIconSpritesIds[i]].data1 = (6 - i) * 7 + 10;
            gSprites[ballIconSpritesIds[i]].pos2.x = -120;
        }

        gSprites[ballIconSpritesIds[i]].data2 = isOpponent;
    }

    if (GetBankSide(bank) == SIDE_PLAYER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < 6; i++)
            {
                if (partyInfo[i].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data7 = 1;
                }
                else if (partyInfo[i].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0) // mon with major status
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
            }
        }
        else
        {
            for (i = 0, var = 5, j = 0; j < 6; j++)
            {
                if (partyInfo[j].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data7 = 1;
                    var--;
                    continue;
                }
                else if (partyInfo[j].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->field_2A0 & gBitTable[j]) // hmm...?
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0) // mon with major status
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 2;
                }
                i++;
            }
        }
    }
    else
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_TWO_OPPONENTS))
        {
            for (var = 5, i = 0; i < 6; i++)
            {
                if (partyInfo[i].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[var]].data7 = 1;
                }
                else if (partyInfo[i].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 3;
                }
                else if (partyInfo[i].status != 0) // mon with major status
                {
                    gSprites[ballIconSpritesIds[var]].oam.tileNum += 2;
                }
                var--;
            }
        }
        else
        {
            for (var = 0, i = 0, j = 0; j < 6; j++)
            {
                if (partyInfo[j].hp == 0xFFFF) // empty slot or an egg
                {
                    gSprites[ballIconSpritesIds[i]].oam.tileNum += 1;
                    gSprites[ballIconSpritesIds[i]].data7 = 1;
                    i++;
                    continue;
                }
                else if (partyInfo[j].hp == 0) // fainted mon
                {
                    gSprites[ballIconSpritesIds[5 - var]].oam.tileNum += 3;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_ARENA && gBattleStruct->field_2A1 & gBitTable[j]) // hmm...?
                {
                    gSprites[ballIconSpritesIds[5 - var]].oam.tileNum += 3;
                }
                else if (partyInfo[j].status != 0) // mon with major status
                {
                    gSprites[ballIconSpritesIds[5 - var]].oam.tileNum += 2;
                }
                var++;
            }
        }
    }

    taskId = CreateTask(TaskDummy, 5);
    gTasks[taskId].data[0] = bank;
    gTasks[taskId].data[1] = barSpriteId;

    for (i = 0; i < 6; i++)
        gTasks[taskId].data[3 + i] = ballIconSpritesIds[i];

    gTasks[taskId].data[10] = isBattleStart;

    if (isBattleStart)
    {
        gBattleSpritesDataPtr->animationData->field_9_x1C++;
    }

    PlaySE12WithPanning(SE_TB_START, 0);
    return taskId;
}

void sub_8073C30(u8 taskId)
{
    u8 sp[6];
    u8 r7;
    u8 r10;
    u8 bank;
    s32 i;

    r7 = gTasks[taskId].data[10];
    r10 = gTasks[taskId].data[1];
    bank = gTasks[taskId].data[0];

    for (i = 0; i < 6; i++)
        sp[i] = gTasks[taskId].data[3 + i];

    SetGpuReg(REG_OFFSET_BLDCNT, 0x3F40);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0x10);

    gTasks[taskId].data[15] = 16;

    for (i = 0; i < 6; i++)
        gSprites[sp[i]].oam.objMode = 1;

    gSprites[r10].oam.objMode = 1;

    if (r7 != 0)
    {
        for (i = 0; i < 6; i++)
        {
            if (GetBankSide(bank) != SIDE_PLAYER)
            {
                gSprites[sp[5 - i]].data1 = 7 * i;
                gSprites[sp[5 - i]].data3 = 0;
                gSprites[sp[5 - i]].data4 = 0;
                gSprites[sp[5 - i]].callback = sub_8074158;
            }
            else
            {
                gSprites[sp[i]].data1 = 7 * i;
                gSprites[sp[i]].data3 = 0;
                gSprites[sp[i]].data4 = 0;
                gSprites[sp[i]].callback = sub_8074158;
            }
        }
        gSprites[r10].data0 /= 2;
        gSprites[r10].data1 = 0;
        gSprites[r10].callback = sub_8074090;
        SetSubspriteTables(&gSprites[r10], &gUnknown_0832C2CC);
        gTasks[taskId].func = sub_8073E08;
    }
    else
    {
        gTasks[taskId].func = sub_8073F98;
    }
}

void sub_8073E08(u8 taskId)
{
    u16 temp = gTasks[taskId].data[11]++;

    if (!(temp & 1))
    {
        gTasks[taskId].data[15]--;
        if (gTasks[taskId].data[15] < 0)
            return;

        SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].data[15]) | ((16 - gTasks[taskId].data[15]) << 8));
    }
    if (gTasks[taskId].data[15] == 0)
        gTasks[taskId].func = sub_8073E64;
}

void sub_8073E64(u8 taskId)
{
    u8 sp[6];
    s32 i;

    u8 bank = gTasks[taskId].data[0];
    gTasks[taskId].data[15]--;
    if (gTasks[taskId].data[15] == -1)
    {
        u8 var = gTasks[taskId].data[1];

        for (i = 0; i < 6; i++)
            sp[i] = gTasks[taskId].data[3 + i];

        gBattleSpritesDataPtr->animationData->field_9_x1C--;
        if (!gBattleSpritesDataPtr->animationData->field_9_x1C)
        {
            DestroySpriteAndFreeResources(&gSprites[var]);
            DestroySpriteAndFreeResources(&gSprites[sp[0]]);
        }
        else
        {
            FreeSpriteOamMatrix(&gSprites[var]);
            DestroySprite(&gSprites[var]);
            FreeSpriteOamMatrix(&gSprites[sp[0]]);
            DestroySprite(&gSprites[sp[0]]);
        }

        for (i = 1; i < 6; i++)
            DestroySprite(&gSprites[sp[i]]);
    }
    else if (gTasks[taskId].data[15] == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x1 = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

void sub_8073F98(u8 taskId)
{
    u8 sp[6];
    s32 i;

    u8 bank = gTasks[taskId].data[0];
    gTasks[taskId].data[15]--;
    if (gTasks[taskId].data[15] >= 0)
    {
        SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].data[15]) | ((16 - gTasks[taskId].data[15]) << 8));
    }
    else if (gTasks[taskId].data[15] == -1)
    {
        u8 var = gTasks[taskId].data[1];

        for (i = 0; i < 6; i++)
            sp[i] = gTasks[taskId].data[3 + i];

        DestroySpriteAndFreeResources(&gSprites[var]);
        DestroySpriteAndFreeResources(&gSprites[sp[0]]);

        for (i = 1; i < 6; i++)
            DestroySprite(&gSprites[sp[i]]);
    }
    else if (gTasks[taskId].data[15] == -3)
    {
        gBattleSpritesDataPtr->healthBoxesData[bank].flag_x1 = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyTask(taskId);
    }
}

void sub_8074078(struct Sprite *sprite)
{
    if (sprite->pos2.x != 0)
        sprite->pos2.x += sprite->data0;
}

void sub_8074090(struct Sprite *sprite)
{
    sprite->data1 += 32;
    if (sprite->data0 > 0)
        sprite->pos2.x += sprite->data1 >> 4;
    else
        sprite->pos2.x -= sprite->data1 >> 4;
    sprite->data1 &= 0xF;
}

void sub_80740C4(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;
    s8 pan;

    if (sprite->data1 > 0)
    {
        sprite->data1--;
        return;
    }
    var1 = sprite->data2;
    var2 = sprite->data3;
    var2 += 56;
    sprite->data3 = var2 & 0xFFF0;
    if (var1 != 0)
    {
        sprite->pos2.x += var2 >> 4;
        if (sprite->pos2.x > 0)
            sprite->pos2.x = 0;
    }
    else
    {
        sprite->pos2.x -= var2 >> 4;
        if (sprite->pos2.x < 0)
            sprite->pos2.x = 0;
    }
    if (sprite->pos2.x == 0)
    {
        pan = 63;
        if (var1 != 0)
            pan = -64;
        if (sprite->data7 != 0)
            PlaySE2WithPanning(SE_TB_KARA, pan);
        else
            PlaySE1WithPanning(SE_TB_KON, pan);
        sprite->callback = SpriteCallbackDummy;
    }
}

void sub_8074158(struct Sprite *sprite)
{
    u8 var1;
    u16 var2;

    if (sprite->data1 > 0)
    {
        sprite->data1--;
        return;
    }
    var1 = sprite->data2;
    var2 = sprite->data3;
    var2 += 56;
    sprite->data3 = var2 & 0xFFF0;
    if (var1 != 0)
        sprite->pos2.x += var2 >> 4;
    else
        sprite->pos2.x -= var2 >> 4;
    if (sprite->pos2.x + sprite->pos1.x > 248
     || sprite->pos2.x + sprite->pos1.x < -8)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}

void sub_80741C8(struct Sprite *sprite)
{
    u8 barSpriteId = sprite->data0;

    sprite->pos2.x = gSprites[barSpriteId].pos2.x;
    sprite->pos2.y = gSprites[barSpriteId].pos2.y;
}

extern const u8 gText_HighlightDarkGrey[];
extern const u8 gText_DynColor2[];
extern const u8 gText_DynColor2Male[];
extern const u8 gText_DynColor1Female[];
extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];

void UpdateNickInHealthbox(u8 healthboxSpriteId, struct Pokemon *mon)
{
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    void *ptr;
    const u8 *genderTxt;
    u32 windowId, windowTileData, spriteTileNum;
    u16 species;
    u8 gender;

    StringCopy(gDisplayedStringBattle, gText_HighlightDarkGrey);
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    StringGetEnd10(nickname);
    ptr = StringAppend(gDisplayedStringBattle, nickname);

    gender = GetMonGender(mon);
    species = GetMonData(mon, MON_DATA_SPECIES);

    if ((species == SPECIES_NIDORAN_F || species == SPECIES_NIDORAN_M) && StringCompare(nickname, gSpeciesNames[species]) == 0)
        gender = 100;

    // AddTextPrinterAndCreateWindowOnHealthbox's arguments are the same in all 3 cases.
    // It's possible they may have been different in early development phases.
    switch (gender)
    {
    default:
        StringCopy(ptr, gText_DynColor2);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    case MON_MALE:
        StringCopy(ptr, gText_DynColor2Male);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    case MON_FEMALE:
        StringCopy(ptr, gText_DynColor1Female);
        windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gDisplayedStringBattle, 0, 3, 2, &windowId);
        break;
    }

    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        sub_8075198((void*)(0x6010040 + spriteTileNum), windowTileData, 6);
        ptr = (void*)(OBJ_VRAM0);
        if (!IsDoubleBattle())
            ptr += spriteTileNum + 0x800;
        else
            ptr += spriteTileNum + 0x400;
        sub_8075198(ptr, windowTileData + 0xC0, 1);
    }
    else
    {
        sub_8075198((void*)(0x6010020 + spriteTileNum), windowTileData, 7);
    }

    RemoveWindowOnHealthbox(windowId);
}

void TryAddPokeballIconToHealthbox(u8 healthboxSpriteId, bool8 noStatus)
{
    u8 bank, healthboxSpriteId_2;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
        return;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return;

    bank = gSprites[healthboxSpriteId].data6;
    if (GetBankSide(bank) == SIDE_PLAYER)
        return;
    if (!GetSetPokedexFlag(SpeciesToNationalPokedexNum(GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_SPECIES)), FLAG_GET_CAUGHT))
        return;

    healthboxSpriteId_2 = gSprites[healthboxSpriteId].data5;

    if (noStatus)
        CpuCopy32(GetHealthboxElementGfxPtr(0x46), (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId_2].oam.tileNum + 8) * 32), 32);
    else
        CpuFill32(0, (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId_2].oam.tileNum + 8) * 32), 32);
}

void UpdateStatusIconInHealthbox(u8 healthboxSpriteId)
{
    s32 i;
    u8 bank, healthboxSpriteId_2;
    u32 status, pltAdder;
    const u32 *statusGfxPtr;
    s16 tileNumAdder;
    u8 statusPalId;

    bank = gSprites[healthboxSpriteId].data6;
    healthboxSpriteId_2 = gSprites[healthboxSpriteId].data5;
    if (GetBankSide(bank) == SIDE_PLAYER)
    {
        status = GetMonData(&gPlayerParty[gBattlePartyID[bank]], MON_DATA_STATUS);
        if (!IsDoubleBattle())
            tileNumAdder = 0x1A;
        else
            tileNumAdder = 0x12;
    }
    else
    {
        status = GetMonData(&gEnemyParty[gBattlePartyID[bank]], MON_DATA_STATUS);
        tileNumAdder = 0x11;
    }

    if (status & STATUS_SLEEP)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(0x1B, bank));
        statusPalId = 2;
    }
    else if (status & STATUS_PSN_ANY)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(0x15, bank));
        statusPalId = 0;
    }
    else if (status & STATUS_BURN)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(0x21, bank));
        statusPalId = 4;
    }
    else if (status & STATUS_FREEZE)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(0x1E, bank));
        statusPalId = 3;
    }
    else if (status & STATUS_PARALYSIS)
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(GetStatusIconForBankId(0x18, bank));
        statusPalId = 1;
    }
    else
    {
        statusGfxPtr = GetHealthboxElementGfxPtr(0x27);

        for (i = 0; i < 3; i++)
            CpuCopy32(statusGfxPtr, (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder + i) * 32), 32);

        if (!gBattleSpritesDataPtr->bankData[bank].hpNumbersNoBars)
            CpuCopy32(GetHealthboxElementGfxPtr(1), (void *)(OBJ_VRAM0 + gSprites[healthboxSpriteId_2].oam.tileNum * 32), 64);

        TryAddPokeballIconToHealthbox(healthboxSpriteId, TRUE);
        return;
    }

    pltAdder = gSprites[healthboxSpriteId].oam.paletteNum * 16;
    pltAdder += bank + 12;

    FillPalette(gBattleInterfaceStatusIcons_DynPals[statusPalId], pltAdder + 0x100, 2);
    CpuCopy16(gPlttBufferUnfaded + 0x100 + pltAdder, (void*)(OBJ_PLTT + pltAdder * 2), 2);
    CpuCopy32(statusGfxPtr, (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId].oam.tileNum + tileNumAdder) * 32), 96);
    if (IsDoubleBattle() == TRUE || GetBankSide(bank) == SIDE_OPPONENT)
    {
        if (!gBattleSpritesDataPtr->bankData[bank].hpNumbersNoBars)
        {
            CpuCopy32(GetHealthboxElementGfxPtr(0), (void*)(OBJ_VRAM0 + gSprites[healthboxSpriteId_2].oam.tileNum * 32), 32);
            CpuCopy32(GetHealthboxElementGfxPtr(0x41), (void*)(OBJ_VRAM0 + (gSprites[healthboxSpriteId_2].oam.tileNum + 1) * 32), 32);
        }
    }
    TryAddPokeballIconToHealthbox(healthboxSpriteId, FALSE);
}

u8 GetStatusIconForBankId(u8 statusElementId, u8 bank)
{
    u8 ret = statusElementId;

    switch (statusElementId)
    {
    case 21:
        if (bank == 0)
            ret = 21;
        else if (bank == 1)
            ret = 71;
        else if (bank == 2)
            ret = 86;
        else
            ret = 101;
        break;
    case 24:
        if (bank == 0)
            ret = 24;
        else if (bank == 1)
            ret = 74;
        else if (bank == 2)
            ret = 89;
        else
            ret = 104;
        break;
    case 27:
        if (bank == 0)
            ret = 27;
        else if (bank == 1)
            ret = 77;
        else if (bank == 2)
            ret = 92;
        else
            ret = 107;
        break;
    case 30:
        if (bank == 0)
            ret = 30;
        else if (bank == 1)
            ret = 80;
        else if (bank == 2)
            ret = 95;
        else
            ret = 110;
        break;
    case 33:
        if (bank == 0)
            ret = 33;
        else if (bank == 1)
            ret = 83;
        else if (bank == 2)
            ret = 98;
        else
            ret = 113;
        break;
    }
    return ret;
}

extern const u8 gText_SafariBalls[];
extern const u8 gText_SafariBallLeft[];

void UpdateSafariBallsTextOnHealthbox(u8 healthboxSpriteId)
{
    u32 windowId, windowTileData, spriteTileNum;

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(gText_SafariBalls, 0, 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;
    sub_8075198((void*)(OBJ_VRAM0 + 0x40) + spriteTileNum, windowTileData, 6);
    sub_8075198((void*)(OBJ_VRAM0 + 0x800) + spriteTileNum, windowTileData + 0xC0, 2);
    RemoveWindowOnHealthbox(windowId);
}

void UpdateLeftNoOfBallsTextOnHealthbox(u8 healthboxSpriteId)
{
    u8 text[16];
    u8 *txtPtr;
    u32 windowId, windowTileData, spriteTileNum;

    txtPtr = StringCopy(text, gText_SafariBallLeft);
    ConvertIntToDecimalStringN(txtPtr, gNumSafariBalls, STR_CONV_MODE_LEFT_ALIGN, 2);

    windowTileData = AddTextPrinterAndCreateWindowOnHealthbox(text, GetStringRightAlignXOffset(0, text, 0x2F), 3, 2, &windowId);
    spriteTileNum = gSprites[healthboxSpriteId].oam.tileNum * 32;
    sub_80751E4((void*)(OBJ_VRAM0 + 0x2C0) + spriteTileNum, windowTileData, 2);
    sub_80751E4((void*)(OBJ_VRAM0 + 0xA00) + spriteTileNum, windowTileData + 0x40, 4);
    RemoveWindowOnHealthbox(windowId);
}

extern void LoadBattleBarGfx(u8 arg0);

void UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId)
{
    u32 maxHp, currHp;
    u8 bank = gSprites[healthboxSpriteId].data6;

    if (elementId == HEALTHBOX_ALL && !IsDoubleBattle())
        GetBankSide(bank); // pointless function call

    if (GetBankSide(gSprites[healthboxSpriteId].data6) == SIDE_PLAYER)
    {
        u8 isDoubles;

        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (elementId == HEALTHBOX_CURRENT_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_HP), 0);
        if (elementId == HEALTHBOX_MAX_HP || elementId == HEALTHBOX_ALL)
            UpdateHpTextInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_MAX_HP), 1);
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(bank, healthboxSpriteId, maxHp, currHp, FALSE);
            sub_8074AA0(bank, healthboxSpriteId, 0, 0);
        }
        isDoubles = IsDoubleBattle();
        if (!isDoubles && (elementId == HEALTHBOX_EXP_BAR || elementId == HEALTHBOX_ALL))
        {
            u16 species;
            u32 exp, currLevelExp, currExpBarValue, maxExpBarValue;
            u8 level;

            LoadBattleBarGfx(3);
            species = GetMonData(mon, MON_DATA_SPECIES);
            level = GetMonData(mon, MON_DATA_LEVEL);
            exp = GetMonData(mon, MON_DATA_EXP);
            currLevelExp = gExperienceTables[gBaseStats[species].growthRate][level];
            currExpBarValue = exp - currLevelExp;
            maxExpBarValue = gExperienceTables[gBaseStats[species].growthRate][level + 1] - currLevelExp;
            SetBattleBarStruct(bank, healthboxSpriteId, maxExpBarValue, currExpBarValue, isDoubles);
            sub_8074AA0(bank, healthboxSpriteId, 1, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT)
            UpdateSafariBallsTextOnHealthbox(healthboxSpriteId);
        if (elementId == HEALTHBOX_SAFARI_ALL_TEXT || elementId == HEALTHBOX_SAFARI_BALLS_TEXT)
            UpdateLeftNoOfBallsTextOnHealthbox(healthboxSpriteId);
    }
    else
    {
        if (elementId == HEALTHBOX_LEVEL || elementId == HEALTHBOX_ALL)
            UpdateLvlInHealthbox(healthboxSpriteId, GetMonData(mon, MON_DATA_LEVEL));
        if (elementId == HEALTHBOX_HEALTH_BAR || elementId == HEALTHBOX_ALL)
        {
            LoadBattleBarGfx(0);
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            currHp = GetMonData(mon, MON_DATA_HP);
            SetBattleBarStruct(bank, healthboxSpriteId, maxHp, currHp, FALSE);
            sub_8074AA0(bank, healthboxSpriteId, 0, 0);
        }
        if (elementId == HEALTHBOX_NICK || elementId == HEALTHBOX_ALL)
            UpdateNickInHealthbox(healthboxSpriteId, mon);
        if (elementId == HEALTHBOX_STATUS_ICON || elementId == HEALTHBOX_ALL)
            UpdateStatusIconInHealthbox(healthboxSpriteId);
    }
}
