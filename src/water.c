#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle.h"
#include "constants/rgb.h"

void sub_810721C(struct Sprite *);
void sub_8107228(struct Sprite *);
void sub_8107260(struct Sprite *);
void sub_8107380(struct Sprite *);
void sub_8107408(struct Sprite *);
void sub_8107430(struct Sprite *);
void sub_810744C(struct Sprite *);
void sub_81074E4(struct Sprite *);
void sub_81075EC(struct Sprite *);
void sub_8107674(struct Sprite *);
void sub_8107730(struct Sprite *);
void sub_81077A4(struct Sprite *);
void sub_81077C0(struct Sprite *);
void sub_8107894(struct Sprite *);
void sub_81078D0(struct Sprite *);
void sub_810790C(struct Sprite *);
void sub_8108034(struct Sprite *);
void sub_8108098(struct Sprite *);
void sub_810851C(struct Sprite *);
void sub_81087C0(struct Sprite *);
void sub_810886C(struct Sprite *);
void sub_8108B2C(struct Sprite *);
void sub_8108B94(struct Sprite *);
void sub_8108BE0(struct Sprite *);
void sub_8108C08(struct Sprite *);
void sub_8108C54(struct Sprite *);
void AnimWaterPulseRing_Step(struct Sprite *);
void sub_810756C(u8);
void sub_81076F4(u8);
void sub_8107B84(u8);
void sub_8107CC4(u8);
void sub_8107D58(u8);
void sub_8108140(u8);
void sub_810862C(u8);
void sub_8108978(u8);
u8 sub_8108384(void);
void sub_8108408(struct Task*, u8);
void sub_810871C(struct Task*, u8);
void sub_8108AC0(struct Task*);
void sub_8108D54(struct Sprite*, int, int);

extern const union AffineAnimCmd *const gGrowingRingAffineAnimTable[];
extern const union AffineAnimCmd *const gUnknown_08596208[];
extern const union AnimCmd *const gUnknown_08595AB8[];

// what is this?
const u8 gUnknown_8593C80[] = INCBIN_U8("graphics/unknown/unknown_593C80.4bpp");
const u8 gUnknown_8593FFC[] = INCBIN_U8("graphics/unknown/unknown_593FFC.bin");

const union AnimCmd gUnknown_08594FFC[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(24, 6),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(40, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_0859501C[] =
{
    gUnknown_08594FFC,
};

const struct SpriteTemplate gUnknown_08595020 =
{
    .tileTag = ANIM_TAG_RAIN_DROPS,
    .paletteTag = ANIM_TAG_RAIN_DROPS,
    .oam = &gOamData_AffineOff_ObjNormal_16x32,
    .anims = gUnknown_0859501C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810721C,
};

const union AffineAnimCmd gUnknown_08595038[] =
{
    AFFINEANIMCMD_FRAME(0xFFFB, 0xFFFB, 0, 10),
    AFFINEANIMCMD_FRAME(0x5, 0x5, 0, 10),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gUnknown_08595050[] =
{
    gUnknown_08595038,
};

const union AnimCmd gUnknown_08595054[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595064[] =
{
    gUnknown_08595054,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_8595068 =
{
    .tileTag = ANIM_TAG_BUBBLE,
    .paletteTag = ANIM_TAG_BUBBLE,
    .oam = &gOamData_AffineNormal_ObjBlend_16x16,
    .anims = gUnknown_08595064,
    .images = NULL,
    .affineAnims = gUnknown_08595050,
    .callback = sub_8107260,
};

const union AnimCmd gUnknown_08595080[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595088[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595090[] =
{
    gUnknown_08595080,
    gUnknown_08595088,
};

const union AffineAnimCmd gUnknown_08595098[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x60, 0x60, 0, 1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085950B0[] =
{
    gUnknown_08595098,
};

// Multi-colored rings used in Aurora Beam.
const struct SpriteTemplate gUnknown_085950B4 =
{
    .tileTag = ANIM_TAG_RAINBOW_RINGS,
    .paletteTag = ANIM_TAG_RAINBOW_RINGS,
    .oam = &gOamData_AffineDouble_ObjNormal_8x16,
    .anims = gUnknown_08595090,
    .images = NULL,
    .affineAnims = gUnknown_085950B0,
    .callback = sub_810744C,
};

const union AnimCmd gUnknown_085950CC[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_085950E0[] =
{
    gUnknown_085950CC,
};

const struct SpriteTemplate gUnknown_085950E4 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_085950FC =
{
    .tileTag = ANIM_TAG_BROWN_ORB,
    .paletteTag = ANIM_TAG_BROWN_ORB,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_08595114 =
{
    .tileTag = ANIM_TAG_GLOWY_RED_ORB,
    .paletteTag = ANIM_TAG_GLOWY_RED_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_0859512C =
{
    .tileTag = ANIM_TAG_GLOWY_GREEN_ORB,
    .paletteTag = ANIM_TAG_GLOWY_GREEN_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const union AnimCmd gUnknown_08595144[] =
{
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gUnknown_08595154[] =
{
    gUnknown_08595144,
};

const struct SpriteTemplate gUnknown_08595158 =
{
    .tileTag = ANIM_TAG_SMALL_EMBER,
    .paletteTag = ANIM_TAG_SMALL_EMBER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gUnknown_08595154,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81075EC,
};

const struct SpriteTemplate gUnknown_08595170 =
{
    .tileTag = ANIM_TAG_BLUE_RING,
    .paletteTag = ANIM_TAG_BLUE_RING,
    .oam = &gOamData_AffineDouble_ObjNormal_16x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gGrowingRingAffineAnimTable,
    .callback = sub_81075EC,
};

const union AffineAnimCmd gUnknown_08595188[] =
{
    AFFINEANIMCMD_FRAME(0x3, 0x3, 10, 50),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 10),
    AFFINEANIMCMD_FRAME(0xFFEC, 0xFFEC, -10, 20),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085951A8[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085951B8[] =
{
    gUnknown_08595188,
};

const union AffineAnimCmd *const gUnknown_085951BC[] =
{
    gUnknown_085951A8,
};

const struct SpriteTemplate gUnknown_085951C0 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gUnknown_085951B8,
    .callback = sub_8107730,
};

const struct SpriteTemplate gUnknown_085951D8 =
{
    .tileTag = ANIM_TAG_WATER_ORB,
    .paletteTag = ANIM_TAG_WATER_ORB,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = gUnknown_085950E0,
    .images = NULL,
    .affineAnims = gUnknown_085951BC,
    .callback = sub_81077C0,
};

const union AnimCmd gUnknown_085951F0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_085951F8[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595200[] =
{
    gUnknown_085951F0,
};

const union AnimCmd *const gUnknown_08595204[] =
{
    gUnknown_085951F8,
};

const struct SpriteTemplate gUnknown_08595208 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjBlend_16x16,
    .anims = gUnknown_08595200,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowProjectile,
};

const struct SpriteTemplate gUnknown_08595220 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineDouble_ObjBlend_16x16,
    .anims = gUnknown_08595204,
    .images = NULL,
    .affineAnims = gUnknown_08596208,
    .callback = sub_8107894,
};

const struct SpriteTemplate gUnknown_08595238 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gUnknown_08595AB8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81078D0,
};

const struct SpriteTemplate gUnknown_08595250 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108034,
};

const struct SpriteTemplate gUnknown_08595268 =
{
    .tileTag = ANIM_TAG_GLOWY_BLUE_ORB,
    .paletteTag = ANIM_TAG_GLOWY_BLUE_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_810851C,
};

const union AnimCmd gUnknown_08595280[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595288[] =
{
    ANIMCMD_FRAME(9, 1),
    ANIMCMD_END,
};

const union AnimCmd gUnknown_08595290[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_08595298[] =
{
    gUnknown_08595280,
    gUnknown_08595288,
};

const union AnimCmd *const gUnknown_085952A0[] =
{
    gUnknown_08595290,
};

const union AffineAnimCmd gUnknown_085952A4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF6, 0xFFF6, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085952BC[] =
{
    AFFINEANIMCMD_FRAME(0xE0, 0xE0, 0, 0),
    AFFINEANIMCMD_FRAME(0xFFF8, 0xFFF8, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_085952D4[] =
{
    AFFINEANIMCMD_FRAME(0x150, 0x150, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 15),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_085952EC[] =
{
    gUnknown_085952A4,
    gUnknown_085952BC,
};

const union AffineAnimCmd *const gUnknown_085952F4[] =
{
    gUnknown_085952D4,
};

const struct SpriteTemplate gUnknown_085952F8 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gUnknown_08595298,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8108BE0,
};

const struct SpriteTemplate gUnknown_08595310 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjNormal_8x8,
    .anims = gUnknown_08595298,
    .images = NULL,
    .affineAnims = gUnknown_085952EC,
    .callback = sub_8108C54,
};

const struct SpriteTemplate gUnknown_08595328 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gUnknown_085952A0,
    .images = NULL,
    .affineAnims = gUnknown_085952F4,
    .callback = sub_80A8EE4,
};

extern const struct SpriteTemplate gUnknown_08597388;

void AnimTask_CreateRaindrops(u8 taskId)
{
    u8 x, y;

    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[1] = gBattleAnimArgs[0];
        gTasks[taskId].data[2] = gBattleAnimArgs[1];
        gTasks[taskId].data[3] = gBattleAnimArgs[2];
    }
    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] % gTasks[taskId].data[2] == 1)
    {
        x = Random2() % 240;
        y = Random2() % 80;
        CreateSprite(&gUnknown_08595020, x, y, 4);
    }
    if (gTasks[taskId].data[0] == gTasks[taskId].data[3])
        DestroyAnimVisualTask(taskId);
}

void sub_810721C(struct Sprite *sprite)
{
    sprite->callback = sub_8107228;
}

void sub_8107228(struct Sprite *sprite)
{
    if (++sprite->data[0] <= 13)
    {
        sprite->pos2.x++;
        sprite->pos2.y += 4;
    }
    if (sprite->animEnded)
        DestroySprite(sprite);
}

void sub_8107260(struct Sprite *sprite)
{
    u8 spriteId;

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2) - gBattleAnimArgs[0];
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3) + gBattleAnimArgs[1];
        sprite->animPaused = TRUE;
    }
    else
    {
        sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 2) + gBattleAnimArgs[0];
        sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 3) + gBattleAnimArgs[1];
        sprite->animPaused = TRUE;
    }
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[6];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    InitAnimLinearTranslation(sprite);
    spriteId = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    sprite->data[5] = spriteId;
    sprite->pos1.x -= Sin((u8)gBattleAnimArgs[4], gBattleAnimArgs[2]);
    sprite->pos1.y -= Cos((u8)gBattleAnimArgs[4], gBattleAnimArgs[3]);
    gSprites[spriteId].data[0] = gBattleAnimArgs[2];
    gSprites[spriteId].data[1] = gBattleAnimArgs[3];
    gSprites[spriteId].data[2] = gBattleAnimArgs[5];
    gSprites[spriteId].data[3] = (u8)gBattleAnimArgs[4] * 256;
    gSprites[spriteId].data[4] = gBattleAnimArgs[6];
    sprite->callback = sub_8107380;
    sprite->callback(sprite);
}

void sub_8107380(struct Sprite *sprite)
{
    u8 otherSpriteId = sprite->data[5];
    u8 timer = gSprites[otherSpriteId].data[4];
    u16 trigIndex = gSprites[otherSpriteId].data[3];

    sprite->data[0] = 1;
    AnimTranslateLinear(sprite);
    sprite->pos2.x += Sin(trigIndex >> 8, gSprites[otherSpriteId].data[0]);
    sprite->pos2.y += Cos(trigIndex >> 8, gSprites[otherSpriteId].data[1]);
    gSprites[otherSpriteId].data[3] = trigIndex + gSprites[otherSpriteId].data[2];
    if (--timer != 0)
    {
        gSprites[otherSpriteId].data[4] = timer;
    }
    else
    {
        sprite->callback = sub_8107408;
        DestroySprite(&gSprites[otherSpriteId]);
    }
}

void sub_8107408(struct Sprite *sprite)
{
    sprite->animPaused = FALSE;
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, sub_8107430);
}

void sub_8107430(struct Sprite *sprite)
{
    sprite->data[0] = 10;
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

void sub_810744C(struct Sprite *sprite)
{
    s16 unkArg;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        unkArg = -gBattleAnimArgs[2];
    else
        unkArg = gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2) + unkArg;
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3) + gBattleAnimArgs[3];
    InitAnimLinearTranslation(sprite);
    sprite->callback = sub_81074E4;
    sprite->affineAnimPaused = TRUE;
    sprite->callback(sprite);
}

void sub_81074E4(struct Sprite *sprite)
{
    if ((u16)gBattleAnimArgs[ARG_RET_ID] == 0xFFFF)
    {
        StartSpriteAnim(sprite, 1);
        sprite->affineAnimPaused = FALSE;
    }
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
}

void sub_8107528(u8 taskId)
{
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[2] = IndexOfSpritePaletteTag(ANIM_TAG_RAINBOW_RINGS) * 16 + 256;
    gTasks[taskId].func = sub_810756C;
}

#ifdef NONMATCHING
void sub_810756C(u8 taskId)
{
    int i;
    u16 palIndex;
    u16 *palPtr1;
    u16 *palPtr2;
    u16 rgbBuffer;

    if (++gTasks[taskId].data[10] == 3)
    {
        gTasks[taskId].data[10] = 0;
        palIndex = gTasks[taskId].data[2] + 1;
        palPtr1 = &gPlttBufferFaded[palIndex];
        rgbBuffer = *palPtr1;
        palPtr2 = &palPtr1[1];
        for (i = 0; i < 7; i++)
            palPtr1[i] = palPtr2[i];
        gPlttBufferFaded[palIndex + 7] = rgbBuffer;
    }
    if (++gTasks[taskId].data[11] == gTasks[taskId].data[0])
        DestroyAnimVisualTask(taskId);
}
#else
NAKED
void sub_810756C(u8 taskId)
{
    asm_unified("push {r4-r7,lr}\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	ldr r1, =gTasks\n\
	lsls r0, r4, 2\n\
	adds r0, r4\n\
	lsls r0, 3\n\
	adds r2, r0, r1\n\
	ldrh r0, [r2, 0x1C]\n\
	adds r0, 0x1\n\
	strh r0, [r2, 0x1C]\n\
	lsls r0, 16\n\
	asrs r0, 16\n\
	mov r12, r1\n\
	cmp r0, 0x3\n\
	bne _081075BE\n\
	movs r0, 0\n\
	strh r0, [r2, 0x1C]\n\
	ldrh r0, [r2, 0xC]\n\
	adds r0, 0x1\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	ldr r1, =gPlttBufferFaded\n\
	lsls r0, r5, 1\n\
	adds r0, r1\n\
	ldrh r6, [r0]\n\
	adds r7, r1, 0\n\
	adds r3, r0, 0x2\n\
	movs r1, 0x6\n\
	adds r2, r0, 0\n\
_081075A8:\n\
	ldrh r0, [r3]\n\
	strh r0, [r2]\n\
	adds r3, 0x2\n\
	adds r2, 0x2\n\
	subs r1, 0x1\n\
	cmp r1, 0\n\
	bge _081075A8\n\
	adds r0, r5, 0x7\n\
	lsls r0, 1\n\
	adds r0, r7\n\
	strh r6, [r0]\n\
_081075BE:\n\
	lsls r0, r4, 2\n\
	adds r0, r4\n\
	lsls r0, 3\n\
	add r0, r12\n\
	ldrh r1, [r0, 0x1E]\n\
	adds r1, 0x1\n\
	strh r1, [r0, 0x1E]\n\
	lsls r1, 16\n\
	asrs r1, 16\n\
	movs r2, 0x8\n\
	ldrsh r0, [r0, r2]\n\
	cmp r1, r0\n\
	bne _081075DE\n\
	adds r0, r4, 0\n\
	bl DestroyAnimVisualTask\n\
_081075DE:\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

void sub_81075EC(struct Sprite *sprite)
{
    u16 retArg;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = 30;
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = 0xD200 / sprite->data[0];
    sprite->data[7] = gBattleAnimArgs[3];
    retArg = gBattleAnimArgs[ARG_RET_ID];
    if (gBattleAnimArgs[ARG_RET_ID] > 127)
    {
        sprite->data[6] = (retArg - 127) * 256;
        sprite->data[7] = -sprite->data[7];
    }
    else
    {
        sprite->data[6] = retArg * 256;
    }
    sprite->callback = sub_8107674;
    sprite->callback(sprite);
}

void sub_8107674(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
        DestroyAnimSprite(sprite);
    sprite->pos2.y += Sin(sprite->data[6] >> 8, sprite->data[7]);
    if ((sprite->data[6] + sprite->data[5]) >> 8 > 127)
    {
        sprite->data[6] = 0;
        sprite->data[7] = -sprite->data[7];
    }
    else
    {
        sprite->data[6] += sprite->data[5];
    }
}

void sub_81076C8(u8 taskId)
{
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gBattleAnimArgs[ARG_RET_ID] = 0;
    gTasks[taskId].func = sub_81076F4;
}

void sub_81076F4(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = (gBattleAnimArgs[ARG_RET_ID] + 3) & 0xFF;
    if (--gTasks[taskId].data[0] == 0)
        DestroyAnimVisualTask(taskId);
}

void sub_8107730(struct Sprite *sprite)
{
    u8 priority;

    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1);
    sprite->pos2.y = -10;
    priority = GetBattlerSpriteSubpriority(gBattleAnimAttacker);
    if (!IsContest())
    {
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        {
            sprite->pos2.x = 10;
            sprite->subpriority = priority + 2;
        }
        else
        {
            sprite->pos2.x = -10;
            sprite->subpriority = priority - 2;
        }
    }
    else
    {
        sprite->pos2.x = -10;
        sprite->subpriority = priority + 2;
    }
    sprite->callback = sub_81077A4;
}

void sub_81077A4(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        DestroyAnimSprite(sprite);
}

void sub_81077C0(struct Sprite *sprite)
{
    bool8 animType;
    u8 coordType;
    if (GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget))
    {
        gBattleAnimArgs[0] *= -1;
        if (GetBattlerPosition(gBattleAnimAttacker) == B_POSITION_PLAYER_LEFT || GetBattlerPosition(gBattleAnimAttacker) == B_POSITION_OPPONENT_LEFT)
            gBattleAnimArgs[0] *= -1;
    }
    if ((gBattleAnimArgs[5] & 0xFF00) == 0)
        animType = TRUE;
    else
        animType = FALSE;
    if ((u8)gBattleAnimArgs[5] == 0)
        coordType = 3;
    else
        coordType = 1;
    InitSpritePosToAnimAttacker(sprite, animType);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 2) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, coordType) + gBattleAnimArgs[3];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void sub_8107894(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = sprite->pos1.x + gBattleAnimArgs[2];
    sprite->data[4] = sprite->pos1.y + gBattleAnimArgs[4];
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

void sub_81078D0(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3])
        InitSpritePosToAnimTarget(sprite, TRUE);
    else
        InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[7] = gBattleAnimArgs[2];
    sprite->callback = sub_810790C;
}

void sub_810790C(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 11) & 0xFF;
    sprite->pos2.x = Sin(sprite->data[0], 4);
    sprite->data[1] += 48;
    sprite->pos2.y = -(sprite->data[1] >> 8);
    if (--sprite->data[7] == -1)
        DestroyAnimSprite(sprite);
}

#ifdef NONMATCHING
void AnimTask_CreateSurfWave(u8 taskId)
{
    struct BattleAnimBgData animBg;
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 1);
    sub_80A6B30(&animBg);
    if (!IsContest())
    {
        SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
            AnimLoadCompressedBgTilemap(animBg.bgId, gUnknown_08D95E00);
        else
            AnimLoadCompressedBgTilemap(animBg.bgId, gUnknown_08D960D0);
    }
    else
    {
        sub_80A6D60(&animBg, gUnknown_08D963A4, 1);
    }
    AnimLoadCompressedBgGfx(animBg.bgId, gBattleAnimBgImage_Surf, animBg.tilesOffset);
    if (gBattleAnimArgs[0] == 0)
        LoadCompressedPalette(gBattleAnimBgPalette_Surf, animBg.paletteId * 16, 32);
    else
        LoadCompressedPalette(gBattleAnimBackgroundImageMuddyWater_Pal, animBg.paletteId * 16, 32);
    taskId2 = CreateTask(sub_8107D58, gTasks[taskId].priority + 1);
    gTasks[taskId].data[15] = taskId2;
    gTasks[taskId2].data[0] = 0;
    gTasks[taskId2].data[1] = 0x1000;
    gTasks[taskId2].data[2] = 0x1000;
    if (IsContest())
    {
        gBattle_BG1_X = -80;
        gBattle_BG1_Y = -48;
        gTasks[taskId].data[0] = 2;
        gTasks[taskId].data[1] = 1;
        gTasks[taskId2].data[3] = 0;
    }
    else if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
    {
        gBattle_BG1_X = -224;
        gBattle_BG1_Y = 256;
        gTasks[taskId].data[0] = 2;
        gTasks[taskId].data[1] = -1;
        gTasks[taskId2].data[3] = 1;
    }
    else
    {
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = -48;
        gTasks[taskId].data[0] = -2;
        gTasks[taskId].data[1] = 1;
        gTasks[taskId2].data[3] = 0;
    }
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    if (gTasks[taskId2].data[3] == 0)
    {
        gTasks[taskId2].data[4] = 48;
        gTasks[taskId2].data[5] = 112;
    }
    else
    {
        gTasks[taskId2].data[4] = 0;
        gTasks[taskId2].data[5] = 0;
    }
    gTasks[taskId].data[6] = 1;
    gTasks[taskId].func = sub_8107B84;
}
#else
NAKED
void AnimTask_CreateSurfWave(u8 taskId)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x10\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r10, r0\n\
	ldr r1, =0x00003f42\n\
	movs r0, 0x50\n\
	bl SetGpuReg\n\
	movs r1, 0x80\n\
	lsls r1, 5\n\
	movs r0, 0x52\n\
	bl SetGpuReg\n\
	movs r0, 0x1\n\
	movs r1, 0x4\n\
	movs r2, 0x1\n\
	bl SetAnimBgAttribute\n\
	movs r0, 0x1\n\
	movs r1, 0\n\
	movs r2, 0x1\n\
	bl SetAnimBgAttribute\n\
	mov r0, sp\n\
	bl sub_80A6B30\n\
	bl IsContest\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	bne _081079E0\n\
	movs r0, 0x1\n\
	movs r1, 0x3\n\
	movs r2, 0x1\n\
	bl SetAnimBgAttribute\n\
	ldr r0, =gBattleAnimAttacker\n\
	ldrb r0, [r0]\n\
	bl GetBattlerSide\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r0, 0x1\n\
	bne _081079D0\n\
	mov r0, sp\n\
	ldrb r0, [r0, 0x9]\n\
	ldr r1, =gUnknown_08D95E00\n\
	bl AnimLoadCompressedBgTilemap\n\
	b _081079EA\n\
	.pool\n\
_081079D0:\n\
	mov r0, sp\n\
	ldrb r0, [r0, 0x9]\n\
	ldr r1, =gUnknown_08D960D0\n\
	bl AnimLoadCompressedBgTilemap\n\
	b _081079EA\n\
	.pool\n\
_081079E0:\n\
	ldr r1, =gUnknown_08D963A4\n\
	mov r0, sp\n\
	movs r2, 0x1\n\
	bl sub_80A6D60\n\
_081079EA:\n\
	mov r0, sp\n\
	ldrb r0, [r0, 0x9]\n\
	ldr r1, =gBattleAnimBgImage_Surf\n\
	mov r2, sp\n\
	ldrh r2, [r2, 0xA]\n\
	bl AnimLoadCompressedBgGfx\n\
	ldr r0, =gBattleAnimArgs\n\
	movs r1, 0\n\
	ldrsh r0, [r0, r1]\n\
	cmp r0, 0\n\
	bne _08107A24\n\
	ldr r0, =gBattleAnimBgPalette_Surf\n\
	mov r1, sp\n\
	ldrb r1, [r1, 0x8]\n\
	lsls r1, 4\n\
	movs r2, 0x20\n\
	bl LoadCompressedPalette\n\
	b _08107A32\n\
	.pool\n\
_08107A24:\n\
	ldr r0, =gBattleAnimBackgroundImageMuddyWater_Pal\n\
	mov r1, sp\n\
	ldrb r1, [r1, 0x8]\n\
	lsls r1, 4\n\
	movs r2, 0x20\n\
	bl LoadCompressedPalette\n\
_08107A32:\n\
	ldr r0, =sub_8107D58\n\
	ldr r4, =gTasks\n\
	mov r2, r10\n\
	lsls r5, r2, 2\n\
	adds r1, r5, r2\n\
	lsls r1, 3\n\
	adds r6, r1, r4\n\
	ldrb r1, [r6, 0x7]\n\
	adds r1, 0x1\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	bl CreateTask\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r8, r0\n\
	movs r0, 0\n\
	mov r9, r0\n\
	mov r1, r8\n\
	strh r1, [r6, 0x26]\n\
	mov r2, r8\n\
	lsls r0, r2, 2\n\
	add r0, r8\n\
	lsls r0, 3\n\
	adds r7, r0, r4\n\
	mov r0, r9\n\
	strh r0, [r7, 0x8]\n\
	movs r0, 0x80\n\
	lsls r0, 5\n\
	strh r0, [r7, 0xA]\n\
	strh r0, [r7, 0xC]\n\
	bl IsContest\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	cmp r4, 0\n\
	beq _08107AB4\n\
	ldr r1, =0x0000ffb0\n\
	adds r0, r1, 0\n\
	ldr r2, =gBattle_BG1_X\n\
	strh r0, [r2]\n\
	adds r1, 0x20\n\
	adds r0, r1, 0\n\
	ldr r2, =gBattle_BG1_Y\n\
	strh r0, [r2]\n\
	movs r0, 0x2\n\
	strh r0, [r6, 0x8]\n\
	movs r0, 0x1\n\
	strh r0, [r6, 0xA]\n\
	mov r0, r9\n\
	strh r0, [r7, 0xE]\n\
	b _08107B0E\n\
	.pool\n\
_08107AB4:\n\
	ldr r0, =gBattleAnimAttacker\n\
	ldrb r0, [r0]\n\
	bl GetBattlerSide\n\
	lsls r0, 24\n\
	lsrs r1, r0, 24\n\
	cmp r1, 0x1\n\
	bne _08107AF8\n\
	ldr r2, =0x0000ff20\n\
	adds r0, r2, 0\n\
	ldr r2, =gBattle_BG1_X\n\
	strh r0, [r2]\n\
	movs r2, 0x80\n\
	lsls r2, 1\n\
	adds r0, r2, 0\n\
	ldr r2, =gBattle_BG1_Y\n\
	strh r0, [r2]\n\
	movs r0, 0x2\n\
	strh r0, [r6, 0x8]\n\
	ldr r0, =0x0000ffff\n\
	strh r0, [r6, 0xA]\n\
	strh r1, [r7, 0xE]\n\
	b _08107B0E\n\
	.pool\n\
_08107AF8:\n\
	ldr r0, =gBattle_BG1_X\n\
	strh r4, [r0]\n\
	ldr r1, =0x0000ffd0\n\
	adds r0, r1, 0\n\
	ldr r2, =gBattle_BG1_Y\n\
	strh r0, [r2]\n\
	ldr r0, =0x0000fffe\n\
	strh r0, [r6, 0x8]\n\
	movs r0, 0x1\n\
	strh r0, [r6, 0xA]\n\
	strh r4, [r7, 0xE]\n\
_08107B0E:\n\
	ldr r0, =gBattle_BG1_X\n\
	ldrh r1, [r0]\n\
	movs r0, 0x14\n\
	bl SetGpuReg\n\
	ldr r2, =gBattle_BG1_Y\n\
	ldrh r1, [r2]\n\
	movs r0, 0x16\n\
	bl SetGpuReg\n\
	ldr r1, =gTasks\n\
	mov r2, r8\n\
	lsls r0, r2, 2\n\
	add r0, r8\n\
	lsls r0, 3\n\
	adds r1, r0, r1\n\
	movs r2, 0xE\n\
	ldrsh r0, [r1, r2]\n\
	cmp r0, 0\n\
	bne _08107B54\n\
	movs r0, 0x30\n\
	strh r0, [r1, 0x10]\n\
	movs r0, 0x70\n\
	b _08107B58\n\
	.pool\n\
_08107B54:\n\
	movs r0, 0\n\
	strh r0, [r1, 0x10]\n\
_08107B58:\n\
	strh r0, [r1, 0x12]\n\
	ldr r1, =gTasks\n\
	mov r2, r10\n\
	adds r0, r5, r2\n\
	lsls r0, 3\n\
	adds r0, r1\n\
	movs r1, 0x1\n\
	strh r1, [r0, 0x14]\n\
	ldr r1, =sub_8107B84\n\
	str r1, [r0]\n\
	add sp, 0x10\n\
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

#ifdef NONMATCHING
void sub_8107B84(u8 taskId)
{
    struct BattleAnimBgData animBg;
    u8 i;
    u16 rgbBuffer;
    u16 *BGptrX = &gBattle_BG1_X;
    u16 *BGptrY = &gBattle_BG1_Y;
    s16 unkUse;
    u32 palOffset;
    u16 palNum;

    *BGptrX += gTasks[taskId].data[0];
    *BGptrY += gTasks[taskId].data[1];
    sub_80A6B30(&animBg);
    gTasks[taskId].data[2] += gTasks[taskId].data[1];
    if (++gTasks[taskId].data[5] == 4)
    {
        rgbBuffer = gPlttBufferFaded[animBg.paletteId * 16 + 7];
        for (i = 6; i != 0; i--)
        {
            palNum = animBg.paletteId * 16;
            palOffset = 1 + i;
            gPlttBufferFaded[palNum + palOffset] = gPlttBufferFaded[palNum + palOffset - 1];
        }
        gPlttBufferFaded[animBg.paletteId * 16 + 1] = rgbBuffer;
        gTasks[taskId].data[5] = 0;
    }
    if (++gTasks[taskId].data[6] > 1)
    {
        gTasks[taskId].data[6] = 0;
        unkUse = ++gTasks[taskId].data[3];
        if (unkUse <= 13)
        {
            gTasks[gTasks[taskId].data[15]].data[1] = unkUse | ((16 - unkUse) * 256);
            gTasks[taskId].data[4]++;
        }
        if (gTasks[taskId].data[3] > 54)
        {
            unkUse = --gTasks[taskId].data[4];
            gTasks[gTasks[taskId].data[15]].data[1] = unkUse | ((16 - unkUse) * 256);
        }
    }
    if (!(gTasks[gTasks[taskId].data[15]].data[1] & 0x1F))
    {
        gTasks[taskId].data[0] = gTasks[gTasks[taskId].data[15]].data[1] & 0x1F;
        gTasks[taskId].func = sub_8107CC4;
    }
}
#else
NAKED
void sub_8107B84(u8 taskId)
{
    asm_unified("push {r4-r7,lr}\n\
	sub sp, 0x10\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	ldr r1, =gBattle_BG1_X\n\
	ldr r2, =gBattle_BG1_Y\n\
	ldr r0, =gTasks\n\
	lsls r4, r5, 2\n\
	adds r4, r5\n\
	lsls r4, 3\n\
	adds r4, r0\n\
	ldrh r0, [r4, 0x8]\n\
	ldrh r3, [r1]\n\
	adds r0, r3\n\
	strh r0, [r1]\n\
	ldrh r0, [r4, 0xA]\n\
	ldrh r1, [r2]\n\
	adds r0, r1\n\
	strh r0, [r2]\n\
	mov r0, sp\n\
	bl sub_80A6B30\n\
	ldrh r0, [r4, 0xA]\n\
	ldrh r3, [r4, 0xC]\n\
	adds r0, r3\n\
	strh r0, [r4, 0xC]\n\
	ldrh r0, [r4, 0x12]\n\
	adds r0, 0x1\n\
	strh r0, [r4, 0x12]\n\
	lsls r0, 16\n\
	asrs r0, 16\n\
	cmp r0, 0x4\n\
	bne _08107C18\n\
	ldr r1, =gPlttBufferFaded\n\
	mov r0, sp\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 4\n\
	adds r0, 0x7\n\
	lsls r0, 1\n\
	adds r0, r1\n\
	ldrh r6, [r0]\n\
	movs r2, 0x6\n\
	adds r7, r1, 0\n\
	adds r3, r7, 0\n\
	mov r4, sp\n\
_08107BDE:\n\
	ldrb r0, [r4, 0x8]\n\
	lsls r0, 4\n\
	adds r1, r2, 0x1\n\
	adds r0, r1\n\
	lsls r1, r0, 1\n\
	adds r1, r3\n\
	subs r0, 0x1\n\
	lsls r0, 1\n\
	adds r0, r3\n\
	ldrh r0, [r0]\n\
	strh r0, [r1]\n\
	subs r0, r2, 0x1\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	cmp r2, 0\n\
	bne _08107BDE\n\
	mov r0, sp\n\
	ldrb r0, [r0, 0x8]\n\
	lsls r0, 4\n\
	adds r0, 0x1\n\
	lsls r0, 1\n\
	adds r0, r7\n\
	strh r6, [r0]\n\
	ldr r1, =gTasks\n\
	lsls r0, r5, 2\n\
	adds r0, r5\n\
	lsls r0, 3\n\
	adds r0, r1\n\
	strh r2, [r0, 0x12]\n\
_08107C18:\n\
	ldr r1, =gTasks\n\
	lsls r2, r5, 2\n\
	adds r0, r2, r5\n\
	lsls r0, 3\n\
	adds r3, r0, r1\n\
	ldrh r0, [r3, 0x14]\n\
	adds r0, 0x1\n\
	strh r0, [r3, 0x14]\n\
	lsls r0, 16\n\
	asrs r0, 16\n\
	adds r4, r1, 0\n\
	adds r6, r2, 0\n\
	cmp r0, 0x1\n\
	ble _08107C86\n\
	movs r0, 0\n\
	strh r0, [r3, 0x14]\n\
	ldrh r0, [r3, 0xE]\n\
	adds r2, r0, 0x1\n\
	strh r2, [r3, 0xE]\n\
	lsls r0, r2, 16\n\
	asrs r0, 16\n\
	cmp r0, 0xD\n\
	bgt _08107C62\n\
	movs r1, 0x26\n\
	ldrsh r0, [r3, r1]\n\
	lsls r1, r0, 2\n\
	adds r1, r0\n\
	lsls r1, 3\n\
	adds r1, r4\n\
	movs r0, 0x10\n\
	subs r0, r2\n\
	lsls r0, 8\n\
	orrs r2, r0\n\
	strh r2, [r1, 0xA]\n\
	ldrh r0, [r3, 0x10]\n\
	adds r0, 0x1\n\
	strh r0, [r3, 0x10]\n\
_08107C62:\n\
	movs r1, 0xE\n\
	ldrsh r0, [r3, r1]\n\
	cmp r0, 0x36\n\
	ble _08107C86\n\
	ldrh r2, [r3, 0x10]\n\
	subs r2, 0x1\n\
	strh r2, [r3, 0x10]\n\
	movs r1, 0x26\n\
	ldrsh r0, [r3, r1]\n\
	lsls r1, r0, 2\n\
	adds r1, r0\n\
	lsls r1, 3\n\
	adds r1, r4\n\
	movs r0, 0x10\n\
	subs r0, r2\n\
	lsls r0, 8\n\
	orrs r2, r0\n\
	strh r2, [r1, 0xA]\n\
_08107C86:\n\
	adds r0, r6, r5\n\
	lsls r0, 3\n\
	adds r2, r0, r4\n\
	movs r3, 0x26\n\
	ldrsh r1, [r2, r3]\n\
	lsls r0, r1, 2\n\
	adds r0, r1\n\
	lsls r0, 3\n\
	adds r0, r4\n\
	ldrh r0, [r0, 0xA]\n\
	movs r3, 0x1F\n\
	ands r3, r0\n\
	cmp r3, 0\n\
	bne _08107CA8\n\
	strh r3, [r2, 0x8]\n\
	ldr r0, =sub_8107CC4\n\
	str r0, [r2]\n\
_08107CA8:\n\
	add sp, 0x10\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n");
}
#endif

void sub_8107CC4(u8 taskId)
{
    u16 *BGptrX = &gBattle_BG1_X;
    u16 *BGptrY = &gBattle_BG1_Y;
    if (gTasks[taskId].data[0] == 0)
    {
        sub_80A6C68(1);
        sub_80A6C68(2);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);
        *BGptrX = 0;
        *BGptrY = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        gTasks[gTasks[taskId].data[15]].data[15] = -1;
        DestroyAnimVisualTask(taskId);
    }
}

void sub_8107D58(u8 taskId)
{
    s16 i;
    struct ScanlineEffectParams params;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        for (i = 0; i < task->data[4]; i++)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[2];
        for (i = task->data[4]; i < task->data[5]; i++)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[1];
        for (i = task->data[5]; i < 160; i++)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[2];

        if (task->data[4] == 0)
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[1];
        else
            gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[1][i] = task->data[2];

        params.dmaDest = (vu16 *)REG_ADDR_BLDALPHA;
        params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
        params.initState = 1;
        params.unused9 = 0;
        ScanlineEffect_SetParams(params);
        task->data[0]++;
        break;
    case 1:
        if (task->data[3] == 0)
        {
            if (--task->data[4] <= 0)
            {
                task->data[4] = 0;
                task->data[0]++;
            }
        }
        else if (++task->data[5] > 111)
        {
            task->data[0]++;
        }

        for (i = 0; i < task->data[4]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];
        for (i = task->data[4]; i < task->data[5]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[1];
        for (i = task->data[5]; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];
        break;
    case 2:
        for (i = 0; i < task->data[4]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];
        for (i = task->data[4]; i < task->data[5]; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[1];
        for (i = task->data[5]; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = task->data[2];

        if (task->data[15] == -1)
        {
            ScanlineEffect_Stop();
            DestroyTask(taskId);
        }
        break;
    }
}

void sub_8108034(struct Sprite *sprite)
{
    s16 randData;
    s16 randData2;

    sprite->oam.tileNum += 8;
    InitSpritePosToAnimTarget(sprite, TRUE);
    randData = (Random2() & 0xFF) | 256;
    randData2 = (Random2() & 0x1FF);
    if (randData2 > 255)
        randData2 = 256 - randData2;
    sprite->data[1] = randData;
    sprite->data[2] = randData2;
    sprite->callback = sub_8108098;
}

void sub_8108098(struct Sprite *sprite)
{
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    if (sprite->data[1] & 1)
        sprite->pos2.x = -(sprite->data[3] >> 8);
    else
        sprite->pos2.x = sprite->data[3] >> 8;
    sprite->pos2.y = sprite->data[4] >> 8;
    if (++sprite->data[0] == 21)
        DestroyAnimSprite(sprite);
}

void sub_81080E4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[5] = gSprites[task->data[15]].pos1.y;
    task->data[1] = sub_8108384();
    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = sub_8108140;
}

void sub_8108140(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        sub_80A805C(task, task->data[15], 0x100, 0x100, 224, 0x200, 32);
        task->data[0]++;
    case 1:
        if (++task->data[3] > 1)
        {
            task->data[3] = 0;
            if (++task->data[4] & 1)
            {
                gSprites[task->data[15]].pos2.x = 3;
                gSprites[task->data[15]].pos1.y++;
            }
            else
            {
                gSprites[task->data[15]].pos2.x = -3;
            }
        }
        if (sub_80A80C8(task) == 0)
        {
            SetBattlerSpriteYOffsetFromYScale(task->data[15]);
            gSprites[task->data[15]].pos2.x = 0;
            task->data[3] = 0;
            task->data[4] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        if (++task->data[3] > 4)
        {
            sub_80A805C(task, task->data[15], 224, 0x200, 384, 224, 8);
            task->data[3] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        if (sub_80A80C8(task) == 0)
        {
            task->data[3] = 0;
            task->data[4] = 0;
            task->data[0]++;
        }
        break;
    case 4:
        sub_8108408(task, taskId);
        task->data[0]++;
    case 5:
        if (++task->data[3] > 1)
        {
            task->data[3] = 0;
            if (++task->data[4] & 1)
                gSprites[task->data[15]].pos2.y += 2;
            else
                gSprites[task->data[15]].pos2.y -= 2;
            if (task->data[4] == 10)
            {
                sub_80A805C(task, task->data[15], 384, 224, 0x100, 0x100, 8);
                task->data[3] = 0;
                task->data[4] = 0;
                task->data[0]++;
            }
        }
        break;
    case 6:
        gSprites[task->data[15]].pos1.y--;
        if (sub_80A80C8(task) == 0)
        {
            ResetSpriteRotScale(task->data[15]);
            gSprites[task->data[15]].pos1.y = task->data[5];
            task->data[4] = 0;
            task->data[0]++;
        }
        break;
    case 7:
        if (task->data[2] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

u8 sub_8108384(void)
{
    u8 i;
    u16 hp;
    u16 maxhp;
    u16 partyIndex;
    struct Pokemon *slot;

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        partyIndex = gBattlerPartyIndexes[gBattleAnimAttacker];
        slot =  &gPlayerParty[partyIndex];
        maxhp = GetMonData(slot, MON_DATA_MAX_HP);
        hp = GetMonData(slot, MON_DATA_HP);
        maxhp /= 4;
    }
    else
    {
        partyIndex = gBattlerPartyIndexes[gBattleAnimAttacker];
        slot =  &gEnemyParty[partyIndex];
        maxhp = GetMonData(slot, MON_DATA_MAX_HP);
        hp = GetMonData(slot, MON_DATA_HP);
        maxhp /= 4;
    }
    for (i = 0; i < 3; i++)
    {
        if (hp < maxhp * (i + 1))
            return i;
    }
    return 3;
}

void sub_8108408(struct Task *task, u8 taskId)
{
    s16 i;
    s16 attackerCoordX = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    s16 attackerCoordY = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    s16 trigIndex = 172;
    u8 subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
    s16 increment = 4 - task->data[1];
    u8 spriteId;

    if (increment <= 0)
        increment = 1;
    for (i = 0; i < 20; i += increment)
    {
        spriteId = CreateSprite(&gUnknown_08595268, attackerCoordX, attackerCoordY, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[1] = i;
            gSprites[spriteId].data[2] = attackerCoordX * 16;
            gSprites[spriteId].data[3] = attackerCoordY * 16;
            gSprites[spriteId].data[4] = Cos(trigIndex, 64);
            gSprites[spriteId].data[5] = Sin(trigIndex, 64);
            gSprites[spriteId].data[6] = taskId;
            gSprites[spriteId].data[7] = 2;
            if (task->data[2] & 1)
                sub_810851C(&gSprites[spriteId]);
            task->data[2]++;
        }
        trigIndex = (trigIndex + increment * 2);
        trigIndex &= 0xFF;
    }
}

void sub_810851C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[4] += (sprite->data[1] % 6) * 3;
        sprite->data[5] += (sprite->data[1] % 3) * 3;
        sprite->data[0]++;
    case 1:
        sprite->data[2] += sprite->data[4];
        sprite->data[3] += sprite->data[5];
        sprite->pos1.x = sprite->data[2] >> 4;
        sprite->pos1.y = sprite->data[3] >> 4;
        if (sprite->pos1.x < -8 || sprite->pos1.x > 248 || sprite->pos1.y < -8 || sprite->pos1.y > 120)
        {
            gTasks[sprite->data[6]].data[sprite->data[7]]--;
            DestroySprite(sprite);
        }
        break;
    }
}

void sub_81085C8(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[1] = sub_8108384();
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        task->data[4] = 136;
        task->data[6] = 40;
    }
    else
    {
        task->data[4] = 16;
        task->data[6] = 80;
    }
    task->data[5] = 98;
    task->data[7] = task->data[4] + 49;
    task->data[12] = task->data[1] * 5 + 5;
    task->func = sub_810862C;
}

void sub_810862C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u8 taskId2;

    switch (task->data[0])
    {
    case 0:
        if (++task->data[2] > 2)
        {
            task->data[2] = 0;
            sub_810871C(task, taskId);
        }
        if (task->data[10] != 0 && task->data[13] == 0)
        {
            gBattleAnimArgs[0] = 1;
            gBattleAnimArgs[1] = 0;
            gBattleAnimArgs[2] = 12;
            taskId2 = CreateTask(sub_81152DC, 80);
            if (taskId2 != 0xFF)
            {
                gTasks[taskId2].func(taskId2);
                gAnimVisualTaskCount++;
            }
            gBattleAnimArgs[0] = 3;
            taskId2 = CreateTask(sub_81152DC, 80);
            if (taskId2 != 0xFF)
            {
                gTasks[taskId2].func(taskId2);
                gAnimVisualTaskCount++;
            }
            task->data[13] = 1;
        }
        if (task->data[11] >= task->data[12])
            task->data[0]++;
        break;
    case 1:
        if (task->data[9] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_810871C(struct Task *task, u8 taskId)
{
    u16 yPosArg = ((gSineTable[task->data[8]] + 3) >> 4) + task->data[6];
    u8 spriteId = CreateSprite(&gUnknown_08595268, task->data[7], 0, 0);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].callback = sub_81087C0;
        gSprites[spriteId].data[5] = yPosArg;
        gSprites[spriteId].data[6] = taskId;
        gSprites[spriteId].data[7] = 9;
        task->data[9]++;
    }
    task->data[11]++;
    task->data[8] = (task->data[8] + 39) & 0xFF;
    task->data[7] = ((task->data[7] * 0x41c64e6d + 0x3039) % task->data[5]) + task->data[4];
}

void sub_81087C0(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->pos1.y += 8;
        if (sprite->pos1.y >= sprite->data[5])
        {
            gTasks[sprite->data[6]].data[10] = 1;
            sprite->data[1] = CreateSprite(&gUnknown_08597388, sprite->pos1.x, sprite->pos1.y, 1);
            if (sprite->data[1] != MAX_SPRITES)
            {
                StartSpriteAffineAnim(&gSprites[sprite->data[1]], 3);
                gSprites[sprite->data[1]].data[6] = sprite->data[6];
                gSprites[sprite->data[1]].data[7] = sprite->data[7];
                gSprites[sprite->data[1]].callback = sub_810886C;
            }
            DestroySprite(sprite);
        }
    }
}

void sub_810886C(struct Sprite *sprite)
{
    if (++sprite->data[1] > 1)
    {
        sprite->data[1] = 0;
        sprite->invisible ^= 1;
        if (++sprite->data[2] == 12)
        {
            gTasks[sprite->data[6]].data[sprite->data[7]]--;
            FreeOamMatrix(sprite->oam.matrixNum);
            DestroySprite(sprite);
        }
    }
}

void sub_81088E4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[3] = GetBattlerSpriteCoord(gBattleAnimAttacker, 2);
    task->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, 3);
    task->data[7] = (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER) ? 1 : -1;
    if (IsContest())
        task->data[7] *= -1;
    task->data[5] = task->data[3] + task->data[7] * 8;
    task->data[6] = task->data[4] - task->data[7] * 8;
    task->data[9] = -32;
    task->data[1] = 0;
    task->data[0] = 0;
    task->func = sub_8108978;
}

void sub_8108978(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        sub_8108AC0(task);
        if (task->data[10] != 0)
            task->data[0]++;
        break;
    case 1:
        sub_8108AC0(task);
        if (++task->data[1] > 16)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        sub_8108AC0(task);
        task->data[5] += task->data[7] * 6;
        if (!(task->data[5] >= -16 && task->data[5] <= 256))
        {
            if (++task->data[12] > 2)
            {
                task->data[13] = 1;
                task->data[0] = 6;
                task->data[1] = 0;
            }
            else
            {
                task->data[1] = 0;
                task->data[0]++;
            }
        }
        break;
    case 3:
        sub_8108AC0(task);
        task->data[6] -= task->data[7] * 2;
        if (++task->data[1] > 7)
            task->data[0]++;
        break;
    case 4:
        sub_8108AC0(task);
        task->data[5] -= task->data[7] * 6;
        if (!(task->data[5] >= -16 && task->data[5] <= 256))
        {
            task->data[12]++;
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 5:
        sub_8108AC0(task);
        task->data[6] -= task->data[7] * 2;
        if (++task->data[1] > 7)
            task->data[0] = 2;
        break;
    case 6:
        if (task->data[8] == 0)
            task->data[0]++;
        break;
    default:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_8108AC0(struct Task *task)
{
    u8 spriteId;

    if (++task->data[2] > 1)
    {
        task->data[2] = 0;
        spriteId = CreateSprite(&gUnknown_08595268, task->data[3], task->data[4], 10);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = 16;
            gSprites[spriteId].data[2] = task->data[5];
            gSprites[spriteId].data[4] = task->data[6];
            gSprites[spriteId].data[5] = task->data[9];
            InitAnimArcTranslation(&gSprites[spriteId]);
            gSprites[spriteId].callback = sub_8108B2C;
            task->data[8]++;
        }
    }
}

void sub_8108B2C(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        sprite->data[0] = 6;
        sprite->data[2] = (Random2() & 0x1F) - 16 + sprite->pos1.x;
        sprite->data[4] = (Random2() & 0x1F) - 16 + sprite->pos1.y;
        sprite->data[5] = ~(Random2() & 7);
        InitAnimArcTranslation(sprite);
        sprite->callback = sub_8108B94;
    }
}

void sub_8108B94(struct Sprite *sprite)
{
    u16 i;

    if (TranslateAnimHorizontalArc(sprite))
    {
        for (i = 0; i < NUM_TASKS; i++)
        {
            if (gTasks[i].func == sub_8108978)
            {
                gTasks[i].data[10] = 1;
                gTasks[i].data[8]--;
                DestroySprite(sprite);
            }
        }
    }
}

void sub_8108BE0(struct Sprite *sprite)
{
    sprite->pos1.x = gBattleAnimArgs[0];
    sprite->pos1.y = gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->callback = sub_8108C08;
}

void sub_8108C08(struct Sprite *sprite)
{
    sprite->data[4] -= sprite->data[0];
    sprite->pos2.y = sprite->data[4] / 10;
    sprite->data[5] = (sprite->data[5] + sprite->data[1]) & 0xFF;
    sprite->pos2.x = Sin(sprite->data[5], sprite->data[2]);
    if (--sprite->data[3] == 0)
        DestroyAnimSprite(sprite);
}

void sub_8108C54(struct Sprite *sprite)
{
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    sprite->pos2.x = sprite->data[3] >> 7;
    sprite->pos2.y = sprite->data[4] >> 7;
    if (--sprite->data[0] == 0)
    {
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void AnimWaterPulseRing(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, 2);
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 3);
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->callback = AnimWaterPulseRing_Step;
}

void AnimWaterPulseRing_Step(struct Sprite *sprite)
{
    int xDiff = sprite->data[1] - sprite->pos1.x;
    int yDiff = sprite->data[2] - sprite->pos1.y;

    sprite->pos2.x = (sprite->data[0] * xDiff) / sprite->data[3];
    sprite->pos2.y = (sprite->data[0] * yDiff) / sprite->data[3];
    if (++sprite->data[5] == sprite->data[4])
    {
        sprite->data[5] = 0;
        sub_8108D54(sprite, xDiff, yDiff);
    }
    if (sprite->data[3] == sprite->data[0])
        DestroyAnimSprite(sprite);
    sprite->data[0]++;
}

#ifdef NONMATCHING
void sub_8108D54(struct Sprite *sprite, int xDiff, int yDiff)
{
    s16 something = sprite->data[0] / 2;
    s16 combinedX = sprite->pos1.x + sprite->pos2.x;
    s16 combinedY = sprite->pos1.y + sprite->pos2.y;
    s16 randomSomethingY = yDiff + (Random2() % 10) - 5;
    s16 randomSomethingX = -xDiff + (Random2() % 10) - 5;
    s16 i;
    u8 spriteId;

    for (i = 0; i <= 0; i++)
    {
        spriteId = CreateSprite(&gUnknown_08595310, combinedX, combinedY + something, 130);
        gSprites[spriteId].data[0] = 20;
        gSprites[spriteId].data[1] = randomSomethingY;
        gSprites[spriteId].subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
        if (randomSomethingX < 0)
            gSprites[spriteId].data[2] = -randomSomethingX;
        else
            gSprites[spriteId].data[2] = randomSomethingX;
    }
    for (i = 0; i <= 0; i++)
    {
        spriteId = CreateSprite(&gUnknown_08595310, combinedX, combinedY - something, 130);
        gSprites[spriteId].data[0] = 20;
        gSprites[spriteId].data[1] = randomSomethingY;
        gSprites[spriteId].subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
        if (randomSomethingX > 0)
            gSprites[spriteId].data[2] = -randomSomethingX;
        else
            gSprites[spriteId].data[2] = randomSomethingX;
    }
}
#else
NAKED
void sub_8108D54(struct Sprite *sprite, int xDiff, int yDiff)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x18\n\
	adds r4, r1, 0\n\
	adds r5, r2, 0\n\
	movs r2, 0x2E\n\
	ldrsh r1, [r0, r2]\n\
	lsrs r2, r1, 31\n\
	adds r1, r2\n\
	lsls r1, 15\n\
	lsrs r1, 16\n\
	str r1, [sp]\n\
	ldrh r1, [r0, 0x24]\n\
	ldrh r3, [r0, 0x20]\n\
	adds r1, r3\n\
	lsls r1, 16\n\
	lsrs r1, 16\n\
	mov r8, r1\n\
	ldrh r1, [r0, 0x26]\n\
	ldrh r0, [r0, 0x22]\n\
	adds r1, r0\n\
	lsls r1, 16\n\
	lsrs r1, 16\n\
	mov r10, r1\n\
	bl Random2\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0xA\n\
	bl __umodsi3\n\
	adds r0, r5, r0\n\
	subs r0, 0x5\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	mov r9, r0\n\
	bl Random2\n\
	negs r4, r4\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0xA\n\
	bl __umodsi3\n\
	adds r4, r0\n\
	subs r4, 0x5\n\
	lsls r4, 16\n\
	lsrs r7, r4, 16\n\
	movs r6, 0\n\
	mov r0, r8\n\
	lsls r0, 16\n\
	mov r8, r0\n\
	mov r1, r10\n\
	lsls r1, 16\n\
	str r1, [sp, 0xC]\n\
	ldr r2, [sp]\n\
	lsls r2, 16\n\
	str r2, [sp, 0x10]\n\
	asrs r1, 16\n\
	lsls r0, r7, 16\n\
	asrs r5, r0, 16\n\
	str r0, [sp, 0x14]\n\
	negs r3, r5\n\
	str r3, [sp, 0x4]\n\
	asrs r0, r2, 16\n\
	adds r1, r0\n\
	lsls r1, 16\n\
	mov r10, r1\n\
_08108DE2:\n\
	ldr r0, =gUnknown_08595310\n\
	mov r2, r8\n\
	asrs r1, r2, 16\n\
	mov r3, r10\n\
	asrs r2, r3, 16\n\
	movs r3, 0x82\n\
	bl CreateSprite\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	ldr r1, =gSprites\n\
	lsls r0, r2, 4\n\
	adds r0, r2\n\
	lsls r0, 2\n\
	adds r4, r0, r1\n\
	movs r0, 0x14\n\
	strh r0, [r4, 0x2E]\n\
	mov r0, r9\n\
	strh r0, [r4, 0x30]\n\
	ldr r0, =gBattleAnimAttacker\n\
	ldrb r0, [r0]\n\
	bl GetBattlerSpriteSubpriority\n\
	subs r0, 0x1\n\
	adds r1, r4, 0\n\
	adds r1, 0x43\n\
	strb r0, [r1]\n\
	cmp r5, 0\n\
	bge _08108E30\n\
	mov r1, sp\n\
	ldrh r1, [r1, 0x4]\n\
	strh r1, [r4, 0x32]\n\
	b _08108E32\n\
	.pool\n\
_08108E30:\n\
	strh r7, [r4, 0x32]\n\
_08108E32:\n\
	lsls r0, r6, 16\n\
	movs r2, 0x80\n\
	lsls r2, 9\n\
	adds r0, r2\n\
	lsrs r6, r0, 16\n\
	cmp r0, 0\n\
	ble _08108DE2\n\
	movs r6, 0\n\
	ldr r3, [sp, 0xC]\n\
	asrs r1, r3, 16\n\
	ldr r0, [sp, 0x14]\n\
	asrs r5, r0, 16\n\
	negs r2, r5\n\
	str r2, [sp, 0x8]\n\
	ldr r3, [sp, 0x10]\n\
	asrs r0, r3, 16\n\
	subs r1, r0\n\
	lsls r1, 16\n\
	mov r10, r1\n\
_08108E58:\n\
	ldr r0, =gUnknown_08595310\n\
	mov r2, r8\n\
	asrs r1, r2, 16\n\
	mov r3, r10\n\
	asrs r2, r3, 16\n\
	movs r3, 0x82\n\
	bl CreateSprite\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	ldr r1, =gSprites\n\
	lsls r0, r2, 4\n\
	adds r0, r2\n\
	lsls r0, 2\n\
	adds r4, r0, r1\n\
	movs r0, 0x14\n\
	strh r0, [r4, 0x2E]\n\
	mov r0, r9\n\
	strh r0, [r4, 0x30]\n\
	ldr r0, =gBattleAnimAttacker\n\
	ldrb r0, [r0]\n\
	bl GetBattlerSpriteSubpriority\n\
	subs r0, 0x1\n\
	adds r1, r4, 0\n\
	adds r1, 0x43\n\
	strb r0, [r1]\n\
	cmp r5, 0\n\
	ble _08108EA8\n\
	mov r1, sp\n\
	ldrh r1, [r1, 0x8]\n\
	strh r1, [r4, 0x32]\n\
	b _08108EAA\n\
	.pool\n\
_08108EA8:\n\
	strh r7, [r4, 0x32]\n\
_08108EAA:\n\
	lsls r0, r6, 16\n\
	movs r2, 0x80\n\
	lsls r2, 9\n\
	adds r0, r2\n\
	lsrs r6, r0, 16\n\
	cmp r0, 0\n\
	ble _08108E58\n\
	add sp, 0x18\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n");
}
#endif
