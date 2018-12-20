#include "global.h"
#include "battle_anim.h"
#include "bg.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"

extern void sub_810B684(struct Sprite *);
extern void sub_810B6C4(struct Sprite *);
extern void sub_810B848(struct Sprite *);
extern void sub_810B8AC(struct Sprite *);
extern void sub_810B8EC(struct Sprite *);
extern void sub_810B974(struct Sprite *);
extern void sub_810B9E8(struct Sprite *);
extern void sub_810BA24(struct Sprite *);
extern void sub_810BB60(struct Sprite *);
extern void sub_810BBC8(struct Sprite *);
extern void sub_810BC4C(struct Sprite *);
extern void sub_810BC94(struct Sprite *);
extern void sub_810BDD8(struct Sprite *);
extern void sub_810BE48(struct Sprite *);
extern void sub_810BED0(struct Sprite *);
extern void sub_810C008(struct Sprite *);
extern void sub_810C2F0(struct Sprite *);
extern void sub_810C560(struct Sprite *);
extern void sub_810CB58(struct Sprite *);
extern void sub_80A8EE4(struct Sprite *);
extern void unc_080B06FC(struct Sprite *);
extern void sub_810CD4C(struct Sprite *);
void sub_810C164(u8);

const union AnimCmd gUnknown_08595A48[] =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 5, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595A54[] =
{
    gUnknown_08595A48,
};

// unknown sprite template
const struct SpriteTemplate gUnknown_08595A58 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B6C4,
};

const union AnimCmd gUnknown_08595A70[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A78[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A80[] =
{
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A88[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A90[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595A98[] =
{
    ANIMCMD_FRAME(12, 6),
    ANIMCMD_FRAME(13, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595AA4[] =
{
    gUnknown_08595A70,
};

const union AnimCmd *const gUnknown_08595AA8[] =
{
    gUnknown_08595A78,
};

const union AnimCmd *const gUnknown_08595AAC[] =
{
    gUnknown_08595A80,
};

const union AnimCmd *const gUnknown_08595AB0[] =
{
    gUnknown_08595A88,
};

const union AnimCmd *const gUnknown_08595AB4[] =
{
    gUnknown_08595A90,
};

const union AnimCmd *const gUnknown_08595AB8[] =
{
    gUnknown_08595A98,
};

const union AffineAnimCmd gUnknown_08595ABC[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 40, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08595ACC[] =
{
    gUnknown_08595ABC,
};

const struct SpriteTemplate gUnknown_08595AD0 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524B24,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595ACC,
    .callback = sub_810B8AC,
};

const struct SpriteTemplate gUnknown_08595AE8 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524A24,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B8AC,
};

const union AffineAnimCmd gUnknown_08595B00[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 10, 1),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08595B10[] =
{
    gUnknown_08595B00,
};

const struct SpriteTemplate gUnknown_08595B14 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524AC4,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595B10,
    .callback = sub_810B8EC,
};

const struct SpriteTemplate gUnknown_08595B2C =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524A24,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810B8EC,
};

const union AffineAnimCmd gUnknown_08595B44[] =
{
    AFFINEANIMCMD_FRAME(0xCE, 0xCE, 0, 0),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 10),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 6),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595B64[] =
{
    gUnknown_08595B44,
};

const struct SpriteTemplate gUnknown_08595B68 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524AC4,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595B64,
    .callback = sub_810B974,
};

const struct SpriteTemplate gUnknown_08595B80 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524A84,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gUnknown_08595B64,
    .callback = sub_810B974,
};

const struct SpriteTemplate gUnknown_08595B98 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595AB0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BA24,
};

const struct SpriteTemplate gUnknown_08595BB0 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_0852490C,
    .anims = gUnknown_08595AB4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BC94,
};

const struct SpriteTemplate gUnknown_08595BC8 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595AB0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BC94,
};

const union AnimCmd gUnknown_08595BE0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595C00[] =
{
    gUnknown_08595BE0,
};

const struct SpriteTemplate gUnknown_08595C04 =
{
    .tileTag = ANIM_TAG_ICE_SPIKES,
    .paletteTag = ANIM_TAG_ICE_SPIKES,
    .oam = &gUnknown_08524A64,
    .anims = gUnknown_08595C00,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BE48,
};

const union AnimCmd gUnknown_08595C1C[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595C28[] =
{
    gUnknown_08595C1C,
};

const struct SpriteTemplate gUnknown_08595C2C =
{
    .tileTag = ANIM_TAG_MIST_CLOUD,
    .paletteTag = ANIM_TAG_MIST_CLOUD,
    .oam = &gUnknown_08524A54,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BED0,
};

const struct SpriteTemplate gUnknown_08595C44 =
{
    .tileTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .paletteTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .oam = &gUnknown_08524A54,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810BED0,
};

const u8 gUnknown_08595C5C[] =
{
    0, 1, 2, 2, 2, 2, 3, 4, 4, 4, 5, 6, 6, 6, 6, 7, 8, 8, 8, 9,
};

const struct SpriteTemplate gUnknown_08595C70 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810C2F0,
};

const u8 gUnknown_08595C88[] =
{
    0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5,
};

const struct SpriteTemplate gUnknown_08595C9C =
{
    .tileTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .paletteTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .oam = &gUnknown_08524A54,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810C560,
};

const u8 gUnknown_08595CB4[][4] =
{
    {0x64, 0xE0, 0x01, 0x20},
    {0x55, 0xE0, 0x01, 0x00},
    {0xF2, 0xE0, 0x11, 0x10},
    {0x42, 0xE0, 0x21, 0x10},
    {0xB6, 0xE0, 0x31, 0x00},
    {0x3C, 0xE0, 0x01, 0x20},
    {0xD6, 0xE0, 0x11, 0x00},
    {0x71, 0xE0, 0x01, 0x10},
    {0xD2, 0xE0, 0x31, 0x10},
    {0x26, 0xE0, 0x21, 0x00},
};

const union AffineAnimCmd gUnknown_08595CDC[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595CEC[] =
{
    AFFINEANIMCMD_FRAME(0xF0, 0xF0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595CFC[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595D0C[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595D1C[] =
{
    gUnknown_08595CDC,
    gUnknown_08595CEC,
    gUnknown_08595CFC,
};

const union AffineAnimCmd *const gUnknown_08595D28[] =
{
    gUnknown_08595D0C,
};

const struct SpriteTemplate gUnknown_08595D2C =
{
    .tileTag = ANIM_TAG_HAIL,
    .paletteTag = ANIM_TAG_HAIL,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595D1C,
    .callback = sub_810CB58,
};

const struct SpriteTemplate gUnknown_08595D44 =
{
    .tileTag = ANIM_TAG_HAIL,
    .paletteTag = ANIM_TAG_HAIL,
    .oam = &gUnknown_0852496C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595D28,
    .callback = sub_80A8EE4,
};

const union AnimCmd gUnknown_08595D5C[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595D64[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595D78[] =
{
    gUnknown_08595D5C,
    gUnknown_08595D64,
};

const union AffineAnimCmd gUnknown_08595D80[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595D90[] =
{
    AFFINEANIMCMD_FRAME(0x118, 0x118, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595DA0[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595DB0[] =
{
    AFFINEANIMCMD_FRAME(0x180, 0x180, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_08595DC0[] =
{
    AFFINEANIMCMD_FRAME(0x1C0, 0x1C0, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08595DD0[] =
{
    gUnknown_08595D80,
    gUnknown_08595D90,
    gUnknown_08595DA0,
    gUnknown_08595DB0,
    gUnknown_08595DC0,
};

const struct SpriteTemplate gUnknown_08595DE4 =
{
    .tileTag = ANIM_TAG_ICE_CHUNK,
    .paletteTag = ANIM_TAG_ICE_CHUNK,
    .oam = &gUnknown_085249D4,
    .anims = gUnknown_08595D78,
    .images = NULL,
    .affineAnims = gUnknown_08595DD0,
    .callback = unc_080B06FC,
};

const struct SpriteTemplate gUnknown_08595DFC =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gUnknown_08524904,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810CD4C,
};

extern const struct SpriteTemplate gUnknown_085956C0;

bool8 sub_810B614(struct Task *task, u8 taskId)
{
    u8 spriteId = CreateSprite(&gUnknown_085956C0, task->data[13], task->data[14], task->data[12]);
    
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].callback = sub_810B684;
        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 10;
        task->data[10]++;
    }
    if (task->data[14] >= task->data[15])
        return TRUE;
    task->data[14] += 32;
    return FALSE;
}

void sub_810B684(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        DestroySprite(sprite);
    }
}

// unused
#ifdef NONMATCHING
void sub_810B6C4(struct Sprite *sprite)
{
    s16 targetX, targetY, attackerX, attackerY;
    s16 i;
    
    sprite->oam.tileNum += 7;
    targetX = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    targetY = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    attackerY = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gBattleAnimArgs[0] + attackerX;
    sprite->data[2] = gBattleAnimArgs[2] + targetX;
    sprite->data[3] = gBattleAnimArgs[1] + attackerY;
    sprite->data[4] = gBattleAnimArgs[3] + targetY;
    sub_80A64EC(sprite);
    while ((targetX >= -32 && targetX <= 272) && (targetY >= -32 && targetY <= 192))
    {
        targetX += sprite->data[1];
        targetY += sprite->data[2];
    }
    sprite->data[1] = -sprite->data[1];
    sprite->data[2] = -sprite->data[2];
    while ((attackerX >= -32 && attackerX <= 272) && (attackerY >= -32 && attackerY <= 192))
    {
        attackerX += sprite->data[1];
        attackerY += sprite->data[2];
    }
    sprite->pos1.x = attackerX;
    sprite->pos1.y = attackerY;
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = attackerX;
    sprite->data[2] = targetX;
    sprite->data[3] = attackerY;
    sprite->data[4] = targetY;
    sub_80A64EC(sprite);
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->data[4] = gBattleAnimArgs[6];
    sprite->callback = sub_810B848;
}
#else
NAKED
void sub_810B6C4(struct Sprite *sprite)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x4\n\
	adds r5, r0, 0\n\
	ldrh r2, [r5, 0x4]\n\
	lsls r1, r2, 22\n\
	lsrs r1, 22\n\
	adds r1, 0x7\n\
	ldr r3, =0x000003ff\n\
	adds r0, r3, 0\n\
	ands r1, r0\n\
	ldr r0, =0xfffffc00\n\
	ands r0, r2\n\
	orrs r0, r1\n\
	strh r0, [r5, 0x4]\n\
	ldr r4, =gBattleAnimTarget\n\
	ldrb r0, [r4]\n\
	movs r1, 0x2\n\
	bl GetBattlerSpriteCoord\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r9, r0\n\
	ldrb r0, [r4]\n\
	movs r1, 0x3\n\
	bl GetBattlerSpriteCoord\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r8, r0\n\
	ldr r4, =gBattleAnimAttacker\n\
	ldrb r0, [r4]\n\
	movs r1, 0x2\n\
	bl GetBattlerSpriteCoord\n\
	lsls r0, 24\n\
	lsrs r3, r0, 24\n\
	ldrb r0, [r4]\n\
	movs r1, 0x3\n\
	str r3, [sp]\n\
	bl GetBattlerSpriteCoord\n\
	lsls r0, 24\n\
	lsrs r6, r0, 24\n\
	ldr r1, =gBattleAnimArgs\n\
	ldrh r0, [r1, 0x8]\n\
	strh r0, [r5, 0x2E]\n\
	ldrh r0, [r1]\n\
	ldr r3, [sp]\n\
	adds r0, r3\n\
	strh r0, [r5, 0x30]\n\
	ldrh r0, [r1, 0x4]\n\
	mov r4, r9\n\
	adds r0, r4, r0\n\
	strh r0, [r5, 0x32]\n\
	ldrh r0, [r1, 0x2]\n\
	adds r0, r6\n\
	strh r0, [r5, 0x34]\n\
	ldrh r0, [r1, 0x6]\n\
	mov r7, r8\n\
	adds r0, r7, r0\n\
	strh r0, [r5, 0x36]\n\
	adds r0, r5, 0\n\
	bl sub_80A64EC\n\
	adds r4, 0x20\n\
	movs r0, 0x98\n\
	lsls r0, 1\n\
	mov r12, r0\n\
	ldr r3, [sp]\n\
	cmp r4, r12\n\
	bhi _0810B79E\n\
	adds r0, r7, 0\n\
	adds r0, 0x20\n\
	ldrh r1, [r5, 0x30]\n\
	ldrh r2, [r5, 0x32]\n\
	cmp r0, 0xE0\n\
	bhi _0810B79E\n\
	adds r4, r1, 0\n\
	mov r10, r12\n\
_0810B76A:\n\
	mov r7, r9\n\
	lsls r1, r7, 16\n\
	asrs r1, 16\n\
	adds r1, r4\n\
	lsls r1, 16\n\
	mov r7, r8\n\
	lsls r0, r7, 16\n\
	asrs r0, 16\n\
	adds r0, r2\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	mov r8, r0\n\
	lsrs r0, r1, 16\n\
	mov r9, r0\n\
	movs r7, 0x80\n\
	lsls r7, 14\n\
	adds r1, r7\n\
	lsrs r1, 16\n\
	cmp r1, r10\n\
	bhi _0810B79E\n\
	mov r1, r8\n\
	lsls r0, r1, 16\n\
	adds r0, r7\n\
	lsrs r0, 16\n\
	cmp r0, 0xE0\n\
	bls _0810B76A\n\
_0810B79E:\n\
	ldrh r0, [r5, 0x30]\n\
	negs r7, r0\n\
	strh r7, [r5, 0x30]\n\
	ldrh r0, [r5, 0x32]\n\
	negs r4, r0\n\
	strh r4, [r5, 0x32]\n\
	lsls r0, r3, 16\n\
	movs r1, 0x80\n\
	lsls r1, 14\n\
	adds r0, r1\n\
	lsrs r0, 16\n\
	movs r2, 0x98\n\
	lsls r2, 1\n\
	mov r12, r2\n\
	ldr r1, =gBattleAnimArgs\n\
	mov r10, r1\n\
	cmp r0, r12\n\
	bhi _0810B80A\n\
	lsls r1, r6, 16\n\
	movs r2, 0x80\n\
	lsls r2, 14\n\
	adds r0, r1, r2\n\
	b _0810B802\n\
	.pool\n\
_0810B7E0:\n\
	lsls r1, r3, 16\n\
	asrs r1, 16\n\
	adds r1, r7\n\
	lsls r1, 16\n\
	asrs r0, r2, 16\n\
	adds r0, r4\n\
	lsls r0, 16\n\
	lsrs r6, r0, 16\n\
	lsrs r3, r1, 16\n\
	movs r0, 0x80\n\
	lsls r0, 14\n\
	adds r1, r0\n\
	lsrs r1, 16\n\
	cmp r1, r12\n\
	bhi _0810B80A\n\
	lsls r1, r6, 16\n\
	adds r0, r1, r0\n\
_0810B802:\n\
	lsrs r0, 16\n\
	adds r2, r1, 0\n\
	cmp r0, 0xE0\n\
	bls _0810B7E0\n\
_0810B80A:\n\
	strh r3, [r5, 0x20]\n\
	strh r6, [r5, 0x22]\n\
	mov r1, r10\n\
	ldrh r0, [r1, 0x8]\n\
	strh r0, [r5, 0x2E]\n\
	strh r3, [r5, 0x30]\n\
	mov r2, r9\n\
	strh r2, [r5, 0x32]\n\
	strh r6, [r5, 0x34]\n\
	mov r3, r8\n\
	strh r3, [r5, 0x36]\n\
	adds r0, r5, 0\n\
	bl sub_80A64EC\n\
	mov r7, r10\n\
	ldrh r0, [r7, 0xA]\n\
	strh r0, [r5, 0x34]\n\
	ldrh r0, [r7, 0xC]\n\
	strh r0, [r5, 0x36]\n\
	ldr r0, =sub_810B848\n\
	str r0, [r5, 0x1C]\n\
	add sp, 0x4\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

void sub_810B848(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
    {
        sprite->data[5] += sprite->data[1];
        sprite->data[6] += sprite->data[2];
        sprite->pos2.x = sprite->data[5];
        sprite->pos2.y = sprite->data[6];
        sprite->pos2.x += Sin(sprite->data[7], sprite->data[3]);
        sprite->pos2.y += Sin(sprite->data[7], sprite->data[3]);
        sprite->data[7] = (sprite->data[7] + sprite->data[4]) & 0xFF;
        sprite->data[0]--;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Animates the swirling ice crystals in Ice Punch.
// arg 0: initial position angle around circle (0-256)
void sub_810B8AC(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = 60;
    sprite->data[2] = 9;
    sprite->data[3] = 30;
    sprite->data[4] = -512;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteInGrowingCircleOverDuration;
    sprite->callback(sprite);
}

// Animates the ice particles in Ice Beam.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x offset
// arg 3: target y offset
// arg 4: duration
void sub_810B8EC(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->data[2] -= gBattleAnimArgs[2];
    else
        sprite->data[2] += gBattleAnimArgs[2];

    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3) + gBattleAnimArgs[3];
    sprite->data[0] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = StartAnimLinearTranslation;
}

// Animates the ice crystals at the end of Ice Punch, Ice Beam, Tri Attack, 
// Weather Ball (Hail), Blizzard, and Powder Snow.
// arg 0: target x offset
// arg 1: target y offset
// arg 2: ??? unknown boolean
void sub_810B974(struct Sprite *sprite)
{
    if (gBattleAnimArgs[2] == 0)
    {
        InitSpritePosToAnimTarget(sprite, TRUE);
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, 1, &sprite->pos1.x, &sprite->pos1.y);
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gBattleAnimArgs[0] = -gBattleAnimArgs[0];

        sprite->pos1.x += gBattleAnimArgs[0];
        sprite->pos1.y += gBattleAnimArgs[1];
    }

    StoreSpriteCallbackInData6(sprite, sub_810B9E8);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

void sub_810B9E8(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
    sprite->data[0] += 1;
    if (sprite->data[0] == 20)
        DestroySpriteAndMatrix(sprite);
}

// Animates the small snowballs that swirl around the target in Blizzard and Icy Wind.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x offset
// arg 3: target y offset
// arg 4: particle speed
// arg 5: multiple targets? (boolean)
void sub_810BA24(struct Sprite *sprite)
{
    int i;
    s16 tempDataHolder[8];

    InitSpritePosToAnimAttacker(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[3] = sprite->pos1.y;

    if (!gBattleAnimArgs[5])
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3) + gBattleAnimArgs[3];
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, 1, &sprite->data[2], &sprite->data[4]);
    }

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->data[2] -= gBattleAnimArgs[2];
    else
        sprite->data[2] += gBattleAnimArgs[2];

    for (i = 0; i < 8; i++)
        tempDataHolder[i] = sprite->data[i];

    InitAnimFastLinearTranslationWithSpeed(sprite);
    sprite->data[1] ^= 1;
    sprite->data[2] ^= 1;

    while (1)
    {
        sprite->data[0] = 1;
        AnimFastTranslateLinear(sprite);

        if ((u32)(sprite->pos1.x + sprite->pos2.x + 16) > 272
         || sprite->pos1.y + sprite->pos2.y > 160
         || sprite->pos1.y + sprite->pos2.y < -16)
            break;
    }

    sprite->pos1.x += sprite->pos2.x;
    sprite->pos1.y += sprite->pos2.y;
    sprite->pos2.y = 0;
    sprite->pos2.x = 0;

    for (i = 0; i < 8; i++)
        sprite->data[i] = tempDataHolder[i];

    sprite->callback = sub_80A718C;
    StoreSpriteCallbackInData6(sprite, sub_810BB60);
}

void sub_810BB60(struct Sprite *sprite)
{
    s16 tempVar;

    sprite->pos1.x += sprite->pos2.x;
    sprite->pos1.y += sprite->pos2.y;
    sprite->pos2.y = 0;
    sprite->pos2.x = 0;
    sprite->data[0] = 128;

    tempVar = GetBattlerSide(gBattleAnimAttacker) != 0 ? 20 : -20;

    sprite->data[3] = Sin(sprite->data[0], tempVar);
    sprite->data[4] = Cos(sprite->data[0], 0xF);
    sprite->data[5] = 0;
    sprite->callback = sub_810BBC8;
    sprite->callback(sprite);
}

void sub_810BBC8(struct Sprite *sprite)
{
    s16 tempVar;
    tempVar = GetBattlerSide(gBattleAnimAttacker) != 0 ? 20 : -20;

    if (sprite->data[5] <= 31)
    {
        sprite->pos2.x = Sin(sprite->data[0], tempVar) - sprite->data[3];
        sprite->pos2.y = Cos(sprite->data[0], 15)      - sprite->data[4];
        sprite->data[0] = (sprite->data[0] + 16) & 0xFF;
        sprite->data[5] += 1;
    }
    else
    {
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        sprite->pos2.y = 0;
        sprite->pos2.x = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 0;
        sprite->callback = sub_810BC4C;
    }
}

void sub_810BC4C(struct Sprite *sprite)
{
    sprite->data[0] = 1;
    AnimFastTranslateLinear(sprite);

    if ((u32)(sprite->pos1.x + sprite->pos2.x + 16) > 272
     || sprite->pos1.y + sprite->pos2.y > 256
     || sprite->pos1.y + sprite->pos2.y < -16)
        DestroyAnimSprite(sprite);
}

// Moves particles towards the target mon and off the screen. Used to animate
// the large snowballs in Blizzard and the small snowballs in Powder Snow.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x offset
// arg 3: target y offset
// arg 4: speed
// arg 5: wave amplitude
// arg 6: wave frequency
// arg 7: multiple targets? (boolean)
void sub_810BC94(struct Sprite *sprite)
{
    int i;
    s16 tempDataHolder[8];

    InitSpritePosToAnimAttacker(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[3] = sprite->pos1.y;

    if (!gBattleAnimArgs[7])
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, 1, &sprite->data[2], &sprite->data[4]);
    }

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->data[2] -= gBattleAnimArgs[2];
    else
        sprite->data[2] += gBattleAnimArgs[2];

    sprite->data[4] += gBattleAnimArgs[3];
    InitAnimFastLinearTranslationWithSpeed(sprite);
    for (i = 0; i < 8; i++)
        tempDataHolder[i] = sprite->data[i];

    sprite->data[1] ^= 1;
    sprite->data[2] ^= 1;

    while (1)
    {
        sprite->data[0] = 1;
        AnimFastTranslateLinear(sprite);
        if ((u32)(sprite->pos1.x + sprite->pos2.x + 16) > 272
         || sprite->pos1.y + sprite->pos2.y > 160
         || sprite->pos1.y + sprite->pos2.y < -16)
            break;
    }

    sprite->pos1.x += sprite->pos2.x;
    sprite->pos1.y += sprite->pos2.y;
    sprite->pos2.y = 0;
    sprite->pos2.x = 0;

    for (i = 0; i < 8; i++)
        sprite->data[i] = tempDataHolder[i];

    sprite->data[5] = gBattleAnimArgs[5];
    sprite->data[6] = gBattleAnimArgs[6];
    sprite->callback = sub_810BDD8;
}

// Moves particles in a sine wave towards the target.
void sub_810BDD8(struct Sprite *sprite)
{
    AnimFastTranslateLinear(sprite);
    if (sprite->data[0] == 0)
        sprite->data[0] = 1;

    sprite->pos2.y += Sin(sprite->data[7], sprite->data[5]);
    sprite->data[7] = (sprite->data[7] + sprite->data[6]) & 0xFF;
    if (sprite->data[0] == 1)
    {
        if ((u32)(sprite->pos1.x + sprite->pos2.x + 16) > 272
         || sprite->pos1.y + sprite->pos2.y > 160
         || sprite->pos1.y + sprite->pos2.y < -16)
            DestroyAnimSprite(sprite);
    }
}

// Animates the ice pilar wave used by Icy Wind.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: ??? unknown boolean
void sub_810BE48(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        if (gBattleAnimArgs[2] == 0)
        {
            InitSpritePosToAnimTarget(sprite, FALSE);
        }
        else
        {
            SetAverageBattlerPositions(gBattleAnimTarget, 0, &sprite->pos1.x, &sprite->pos1.y);

            if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
                gBattleAnimArgs[0] = -gBattleAnimArgs[0];

            sprite->pos1.x += gBattleAnimArgs[0];
            sprite->pos1.y += gBattleAnimArgs[1];
        }

        sprite->data[0]++; 
    }
    else
    {
        if (sprite->animEnded)
            DestroyAnimSprite(sprite);
    }
}

// Animates the fog that swirls around the mon in Mist and Smog.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: change in y pixels per rotation
// arg 3: duration
// arg 4: animate on opponent? (boolean)
// arg 5: ??? unknown boolean
void sub_810BED0(struct Sprite *sprite)
{
    s16 tempVar;
    u8  battler;

    if (gBattleAnimArgs[4] == 0)
    {
        if (gBattleAnimArgs[5] == 0)
        {
            InitSpritePosToAnimAttacker(sprite, FALSE);
        }
        else
        {
            SetAverageBattlerPositions(gBattleAnimAttacker, 0, &sprite->pos1.x, &sprite->pos1.y);
            if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER) 
                sprite->pos1.x -= gBattleAnimArgs[0];
            else 
                sprite->pos1.x += gBattleAnimArgs[0];

            sprite->pos1.y += gBattleAnimArgs[1];
        }

        battler = gBattleAnimAttacker;
    }
    else 
    {
        if (gBattleAnimArgs[5] == 0)
        {
            InitSpritePosToAnimTarget(sprite, FALSE);
        }
        else 
        {
            SetAverageBattlerPositions(gBattleAnimTarget, 0, &sprite->pos1.x, &sprite->pos1.y);
            if (GetBattlerSide(gBattleAnimTarget) != B_SIDE_PLAYER)
                sprite->pos1.x -= gBattleAnimArgs[0];
            else 
                sprite->pos1.x += gBattleAnimArgs[0];

            sprite->pos1.y += gBattleAnimArgs[1];
        }

        battler = gBattleAnimTarget;
    }

    sprite->data[7] = battler;
    if (gBattleAnimArgs[5] == 0 || !IsDoubleBattle()) 
        tempVar = 0x20;
    else
        tempVar = 0x40;

    sprite->data[6] = tempVar;
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->pos1.y += 8;

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = sprite->pos1.x;
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = sprite->pos1.y + gBattleAnimArgs[2];

    InitAnimLinearTranslation(sprite);

    sprite->data[5] = 64;
    sprite->callback = sub_810C008;
    sprite->callback(sprite);
}

// Animates swirling fog initialized by InitSwirlingFogAnim.
void sub_810C008(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->pos2.x += Sin(sprite->data[5], sprite->data[6]);
        sprite->pos2.y += Cos(sprite->data[5], -6);

        if ((u16)(sprite->data[5] - 64) <= 0x7F)
            sprite->oam.priority = GetBattlerSpriteBGPriority(sprite->data[7]); 
        else
            sprite->oam.priority = GetBattlerSpriteBGPriority(sprite->data[7]) + 1;

        sprite->data[5] = (sprite->data[5] + 3) & 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Fades mons to black and places foggy overlay in Haze.
void sub_810C0A0(u8 taskId)
{
    struct UnknownAnimStruct2 subStruct;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);

    if (!IsContest())
        SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

    sub_80A6B30(&subStruct);
    LoadBgTiles(subStruct.bgId, gWeatherFog1Tiles, 0x800, subStruct.tilesOffset);
    sub_80A6D60(&subStruct, gBattleAnimFogTilemap, 0);
    LoadPalette(&gUnknown_083970E8, subStruct.unk8 * 16, 32);
    
    gTasks[taskId].func = sub_810C164;
}

void sub_810C164(u8 taskId)
{
    struct UnknownAnimStruct2 subStruct;

    gBattle_BG1_X += -1;
    gBattle_BG1_Y += 0;

    switch (gTasks[taskId].data[12])
    {
        case 0:
            if (++gTasks[taskId].data[10] == 4)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[9]++;
                gTasks[taskId].data[11] = gUnknown_08595C5C[gTasks[taskId].data[9]];

                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
                if (gTasks[taskId].data[11] == 9)
                {
                    gTasks[taskId].data[12]++;
                    gTasks[taskId].data[11] = 0;
                }
            }
            break;
        case 1:
            if (++gTasks[taskId].data[11] == 0x51)
            {
                gTasks[taskId].data[11] = 9;
                gTasks[taskId].data[12]++;
            }
            break;
        case 2:
            if (++gTasks[taskId].data[10] == 4)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[11]--;

                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
                if (gTasks[taskId].data[11] == 0)
                {
                    gTasks[taskId].data[12]++;
                    gTasks[taskId].data[11] = 0;
                }
            }
            break;
        case 3:
            sub_80A6B30(&subStruct);
            sub_80A6C68(1);
            sub_80A6C68(2);
            
            gTasks[taskId].data[12]++;
            
            // fall through
        case 4:
            if (!IsContest())
                SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

            gBattle_BG1_X = 0;
            gBattle_BG1_Y = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
            SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
            DestroyAnimVisualTask(taskId);
    }
} 

// Throws the ball in Mist Ball.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: targey x offset
// arg 3: target y offset
// arg 4: duration
// arg 5: ??? unknown (seems to vibrate target mon somehow)
void sub_810C2F0(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    sprite->callback = TranslateAnimSpriteToTargetMonLocation;
}
