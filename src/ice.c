#include "global.h"
#include "battle_anim.h"
#include "bg.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "palette.h"
#include "random.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"

struct HailStruct {
    s32 unk0:10;
    s32 unk1:10;
    s32 unk2:8;
    s32 unk3:4;
};

static void sub_810B6C4(struct Sprite *);
void sub_810B848(struct Sprite *);
void AnimIcePunchSwirlingParticle(struct Sprite *);
void AnimIceBeamParticle(struct Sprite *);
void AnimIceEffectParticle(struct Sprite *);
void AnimFlickerIceEffectParticle(struct Sprite *);
void AnimSwirlingSnowball_Step1(struct Sprite *);
void AnimSwirlingSnowball_Step2(struct Sprite *);
void AnimSwirlingSnowball_Step3(struct Sprite *);
void AnimSwirlingSnowball_End(struct Sprite *);
void AnimMoveParticleBeyondTarget(struct Sprite *);
void AnimWiggleParticleTowardsTarget(struct Sprite *);
void AnimWaveFromCenterOfTarget(struct Sprite *);
void InitSwirlingFogAnim(struct Sprite *);
void AnimSwirlingFogAnim(struct Sprite *);
void AnimThrowMistBall(struct Sprite *);
void InitPoisonGasCloudAnim(struct Sprite *);
void MovePoisonGasCloud(struct Sprite *);
void AnimHailBegin(struct Sprite *);
void AnimHailContinue(struct Sprite *);
void InitIceBallAnim(struct Sprite *);
void AnimThrowIceBall(struct Sprite *);
void InitIceBallParticle(struct Sprite *);
void AnimIceBallParticle(struct Sprite *);
void AnimTask_Haze2(u8);
void AnimTask_OverlayFogTiles(u8);
void AnimTask_Hail2(u8);
bool8 GenerateHailParticle(u8 hailStructId, u8 affineAnimNum, u8 taskId, u8 c);

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
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
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
    .oam = &gOamData_AffineDouble_ObjBlend_8x16,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595ACC,
    .callback = AnimIcePunchSwirlingParticle,
};

const struct SpriteTemplate gUnknown_08595AE8 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjBlend_8x8,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimIcePunchSwirlingParticle,
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
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595B10,
    .callback = AnimIceBeamParticle,
};

const struct SpriteTemplate gUnknown_08595B2C =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjBlend_8x8,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimIceBeamParticle,
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
    .oam = &gOamData_AffineNormal_ObjBlend_8x16,
    .anims = gUnknown_08595AA8,
    .images = NULL,
    .affineAnims = gUnknown_08595B64,
    .callback = AnimIceEffectParticle,
};

const struct SpriteTemplate gUnknown_08595B80 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineNormal_ObjBlend_8x8,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gUnknown_08595B64,
    .callback = AnimIceEffectParticle,
};

const struct SpriteTemplate gUnknown_08595B98 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gUnknown_08595AB0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSwirlingSnowball_Step1,
};

const struct SpriteTemplate gUnknown_08595BB0 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gUnknown_08595AB4,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveParticleBeyondTarget,
};

const struct SpriteTemplate gUnknown_08595BC8 =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gUnknown_08595AB0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMoveParticleBeyondTarget,
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
    .oam = &gOamData_AffineOff_ObjBlend_8x16,
    .anims = gUnknown_08595C00,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWaveFromCenterOfTarget,
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
    .oam = &gOamData_AffineOff_ObjBlend_32x16,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = InitSwirlingFogAnim,
};

const struct SpriteTemplate gUnknown_08595C44 =
{
    .tileTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .paletteTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .oam = &gOamData_AffineOff_ObjBlend_32x16,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = InitSwirlingFogAnim,
};

const u8 gUnknown_08595C5C[] =
{
    0, 1, 2, 2, 2, 2, 3, 4, 4, 4, 5, 6, 6, 6, 6, 7, 8, 8, 8, 9,
};

const struct SpriteTemplate gUnknown_08595C70 =
{
    .tileTag = ANIM_TAG_SMALL_BUBBLES,
    .paletteTag = ANIM_TAG_SMALL_BUBBLES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowMistBall,
};

const u8 gUnknown_08595C88[] =
{
    0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5,
};

const struct SpriteTemplate gUnknown_08595C9C =
{
    .tileTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .paletteTag = ANIM_TAG_PURPLE_GAS_CLOUD,
    .oam = &gOamData_AffineOff_ObjBlend_32x16,
    .anims = gUnknown_08595C28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = InitPoisonGasCloudAnim,
};

const struct HailStruct gUnknown_08595CB4[] =
{
    {100, 120, 0, 2},
    {85, 120, 0, 0},
    {242, 120, 1, 1},
    {66, 120, 2, 1},
    {182, 120, 3, 0},
    {60, 120, 0, 2},
    {214, 120, 1, 0},
    {113, 120, 0, 1},
    {210, 120, 3, 1},
    {38, 120, 2, 0},
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
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08595D1C,
    .callback = AnimHailBegin,
};

const struct SpriteTemplate gUnknown_08595D44 =
{
    .tileTag = ANIM_TAG_HAIL,
    .paletteTag = ANIM_TAG_HAIL,
    .oam = &gOamData_AffineNormal_ObjNormal_16x16,
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
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gUnknown_08595D78,
    .images = NULL,
    .affineAnims = gUnknown_08595DD0,
    .callback = InitIceBallAnim,
};

const struct SpriteTemplate gUnknown_08595DFC =
{
    .tileTag = ANIM_TAG_ICE_CRYSTALS,
    .paletteTag = ANIM_TAG_ICE_CRYSTALS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gUnknown_08595AAC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = InitIceBallParticle,
};

// probably unused
static void sub_810B6C4(struct Sprite *sprite)
{
    s16 targetX, targetY, attackerX, attackerY;

    sprite->oam.tileNum += 7;
    targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    attackerY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = gBattleAnimArgs[0] + attackerX;
    sprite->data[2] = gBattleAnimArgs[2] + targetX;
    sprite->data[3] = gBattleAnimArgs[1] + attackerY;
    sprite->data[4] = gBattleAnimArgs[3] + targetY;
    sub_80A64EC(sprite);

    for (;(targetX >= -32 && targetX <= 272) && (targetY >= -32 && targetY <= 192);
           targetX += sprite->data[1], targetY += sprite->data[2])
        ;

    sprite->data[1] = -sprite->data[1];
    sprite->data[2] = -sprite->data[2];
    for (;(attackerX >= -32 && attackerX <= 272) && (attackerY >= -32 && attackerY <= 192);
           attackerX += sprite->data[1], attackerY += sprite->data[2])
        ;

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
void AnimIcePunchSwirlingParticle(struct Sprite *sprite)
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
void AnimIceBeamParticle(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->data[2] -= gBattleAnimArgs[2];
    else
        sprite->data[2] += gBattleAnimArgs[2];

    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    sprite->data[0] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = StartAnimLinearTranslation;
}

// Animates the ice crystals at the end of Ice Punch, Ice Beam, Tri Attack,
// Weather Ball (Hail), Blizzard, and Powder Snow.
// arg 0: target x offset
// arg 1: target y offset
// arg 2: ??? unknown boolean
void AnimIceEffectParticle(struct Sprite *sprite)
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

    StoreSpriteCallbackInData6(sprite, AnimFlickerIceEffectParticle);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}

void AnimFlickerIceEffectParticle(struct Sprite *sprite)
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
void AnimSwirlingSnowball_Step1(struct Sprite *sprite)
{
    int i;
    s16 tempDataHolder[8];

    InitSpritePosToAnimAttacker(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[3] = sprite->pos1.y;

    if (!gBattleAnimArgs[5])
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
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
    StoreSpriteCallbackInData6(sprite, AnimSwirlingSnowball_Step2);
}

void AnimSwirlingSnowball_Step2(struct Sprite *sprite)
{
    s16 tempVar;

    sprite->pos1.x += sprite->pos2.x;
    sprite->pos1.y += sprite->pos2.y;
    sprite->pos2.y = 0;
    sprite->pos2.x = 0;
    sprite->data[0] = 128;

    tempVar = GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER ? 20 : -20;

    sprite->data[3] = Sin(sprite->data[0], tempVar);
    sprite->data[4] = Cos(sprite->data[0], 0xF);
    sprite->data[5] = 0;
    sprite->callback = AnimSwirlingSnowball_Step3;
    sprite->callback(sprite);
}

void AnimSwirlingSnowball_Step3(struct Sprite *sprite)
{
    s16 tempVar;
    tempVar = GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER ? 20 : -20;

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
        sprite->callback = AnimSwirlingSnowball_End;
    }
}

void AnimSwirlingSnowball_End(struct Sprite *sprite)
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
void AnimMoveParticleBeyondTarget(struct Sprite *sprite)
{
    int i;
    s16 tempDataHolder[8];

    InitSpritePosToAnimAttacker(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[3] = sprite->pos1.y;

    if (!gBattleAnimArgs[7])
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
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
    sprite->callback = AnimWiggleParticleTowardsTarget;
}

// Moves particles in a sine wave towards the target.
void AnimWiggleParticleTowardsTarget(struct Sprite *sprite)
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
void AnimWaveFromCenterOfTarget(struct Sprite *sprite)
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
void InitSwirlingFogAnim(struct Sprite *sprite)
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
    sprite->callback = AnimSwirlingFogAnim;
    sprite->callback(sprite);
}

// Animates swirling fog initialized by InitSwirlingFogAnim.
void AnimSwirlingFogAnim(struct Sprite *sprite)
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
void AnimTask_Haze1(u8 taskId)
{
    struct BattleAnimBgData animBg;

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

    sub_80A6B30(&animBg);
    LoadBgTiles(animBg.bgId, gWeatherFog1Tiles, 0x800, animBg.tilesOffset);
    sub_80A6D60(&animBg, gBattleAnimFogTilemap, 0);
    LoadPalette(&gUnknown_083970E8, animBg.paletteId * 16, 32);

    gTasks[taskId].func = AnimTask_Haze2;
}

void AnimTask_Haze2(u8 taskId)
{
    struct BattleAnimBgData animBg;

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
        sub_80A6B30(&animBg);
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
        break;
    }
}

// Throws the ball in Mist Ball.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: targey x offset
// arg 3: target y offset
// arg 4: duration
// arg 5: ??? unknown (seems to vibrate target mon somehow)
void AnimThrowMistBall(struct Sprite *sprite)
{
    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = TranslateAnimSpriteToTargetMonLocation;
}

// Displays misty background in Mist Ball.
void AnimTask_LoadMistTiles(u8 taskId)
{
    struct BattleAnimBgData animBg;

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

    sub_80A6B30(&animBg);
    LoadBgTiles(animBg.bgId, gWeatherFog1Tiles, 0x800, animBg.tilesOffset);
    sub_80A6D60(&animBg, gBattleAnimFogTilemap, 0);
    LoadPalette(&gUnknown_083970E8, animBg.paletteId * 16, 32);

    gTasks[taskId].data[15] = -1;
    gTasks[taskId].func = AnimTask_OverlayFogTiles;
}

void AnimTask_OverlayFogTiles(u8 taskId)
{
    struct BattleAnimBgData animBg;

    gBattle_BG1_X += gTasks[taskId].data[15];
    gBattle_BG1_Y += 0;

    switch (gTasks[taskId].data[12])
    {
    case 0:
        gTasks[taskId].data[9] += 1;
        gTasks[taskId].data[11] = gUnknown_08595C88[gTasks[taskId].data[9]];
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 17 - gTasks[taskId].data[11]));
        if (gTasks[taskId].data[11] == 5)
        {
            gTasks[taskId].data[12]++;
            gTasks[taskId].data[11] = 0;
        }
        break;
    case 1:
        if (++gTasks[taskId].data[11] == 0x51)
        {
            gTasks[taskId].data[11] = 5;
            gTasks[taskId].data[12]++;
        }
        break;
    case 2:
        if (++gTasks[taskId].data[10] == 4)
        {
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[11] -= 1;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[11], 16 - gTasks[taskId].data[11]));
            if (gTasks[taskId].data[11] == 0)
            {
                gTasks[taskId].data[12]++;
                gTasks[taskId].data[11] = 0;
            }
        }
        break;
    case 3:
        sub_80A6B30(&animBg);
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
        break;
    }
}

// Initializes gas clouds in the Poison Gas animation.
// arg 0: duration
// arg 1: ? target x offset
// arg 2: ? target y offset
// arg 3: ? swirl start x
// arg 4: ? swirl start y
// arg 5: ??? unknown
// arg 6: ??? unknown
// arg 7: ??? unknown boolean
void InitPoisonGasCloudAnim(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[0];

    if (GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) < GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2))
        sprite->data[7] = 0x8000;

    if ((gBattlerPositions[gBattleAnimTarget] & BIT_SIDE) == B_SIDE_PLAYER)
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];

        if ((sprite->data[7] & 0x8000) && (gBattlerPositions[gBattleAnimAttacker] & BIT_SIDE) == B_SIDE_PLAYER)
            sprite->subpriority = gSprites[GetAnimBattlerSpriteId(ANIM_TARGET)].subpriority + 1;

        sprite->data[6] = 1;
    }

    sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->pos1.y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    if (gBattleAnimArgs[7])
    {
        sprite->data[1] = sprite->pos1.x + gBattleAnimArgs[1];
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[3];
        sprite->data[3] = sprite->pos1.y + gBattleAnimArgs[2];
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[4];
        sprite->data[7] |= GetBattlerSpriteBGPriority(gBattleAnimTarget) << 8;
    }
    else
    {
        sprite->data[1] = sprite->pos1.x + gBattleAnimArgs[1];
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[3];
        sprite->data[3] = sprite->pos1.y + gBattleAnimArgs[2];
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + gBattleAnimArgs[4];
        sprite->data[7] |= GetBattlerSpriteBGPriority(gBattleAnimTarget) << 8;
    }

    if (IsContest())
    {
        sprite->data[6] = 1;
        sprite->subpriority = 0x80;
    }

    InitAnimLinearTranslation(sprite);
    sprite->callback = MovePoisonGasCloud;
}

void MovePoisonGasCloud(struct Sprite *sprite)
{
    int value;

    switch (sprite->data[7] & 0xFF)
    {
    case 0:
        AnimTranslateLinear(sprite);
        value = gSineTable[sprite->data[5]];
        sprite->pos2.x += value >> 4;
        if (sprite->data[6])
            sprite->data[5] = (sprite->data[5] - 8) & 0xFF;
        else
            sprite->data[5] = (sprite->data[5] + 8) & 0xFF;

        if (sprite->data[0] <= 0)
        {
            sprite->data[0] = 80;
            sprite->pos1.x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
            sprite->data[1] = sprite->pos1.x;
            sprite->data[2] = sprite->pos1.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->data[3] = sprite->pos1.y;
            sprite->data[4] = sprite->pos1.y + 29;
            sprite->data[7]++;
            if (IsContest())
                sprite->data[5] = 80;
            else if (GET_BATTLER_SIDE2(gBattleAnimTarget) != B_SIDE_PLAYER)
                sprite->data[5] = 204;
            else
                sprite->data[5] = 80;

            sprite->pos2.y = 0;
            value = gSineTable[sprite->data[5]];
            sprite->pos2.x = value >> 3;
            sprite->data[5] = (sprite->data[5] + 2) & 0xFF;
            InitAnimLinearTranslation(sprite);
        }
        break;
    case 1:
        AnimTranslateLinear(sprite);
        value = gSineTable[sprite->data[5]];
        sprite->pos2.x += value >> 3;
        sprite->pos2.y += (gSineTable[sprite->data[5] + 0x40] * -3) >> 8;
        if (!IsContest())
        {
            u16 var0 = sprite->data[5] - 0x40;
            if (var0 <= 0x7F)
                sprite->oam.priority = sprite->data[7] >> 8;
            else
                sprite->oam.priority = (sprite->data[7] >> 8) + 1;

            sprite->data[5] = (sprite->data[5] + 4) & 0xFF;
        }
        else
        {
            u16 var0 = sprite->data[5] - 0x40;
            if (var0 <= 0x7F)
                sprite->subpriority = 128;
            else
                sprite->subpriority = 140;

            sprite->data[5] = (sprite->data[5] - 4) & 0xFF;
        }

        if (sprite->data[0] <= 0)
        {
            sprite->data[0] = 0x300;
            sprite->data[1] = sprite->pos1.x += sprite->pos2.x;
            sprite->data[3] = sprite->pos1.y += sprite->pos2.y;
            sprite->data[4] = sprite->pos1.y + 4;
            if (IsContest())
                sprite->data[2] = -0x10;
            else if (GET_BATTLER_SIDE2(gBattleAnimTarget) != B_SIDE_PLAYER)
                sprite->data[2] = 0x100;
            else
                sprite->data[2] = -0x10;

            sprite->data[7]++;
            sprite->pos2.x = sprite->pos2.y = 0;
            sub_80A6FD4(sprite);
        }
        break;
    case 2:
        if (AnimTranslateLinear(sprite))
        {
            if (sprite->oam.affineMode & 1)
            {
                FreeOamMatrix(sprite->oam.matrixNum);
                sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
            }

            DestroySprite(sprite);
            gAnimVisualTaskCount--;
        }
        break;
    }
}

// Creates Hail.
void AnimTask_Hail1(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->func = AnimTask_Hail2;
}

void AnimTask_Hail2(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        if (++task->data[4] > 2)
        {
            task->data[4] = 0;
            task->data[5] = 0;
            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 1:
        if (task->data[5] == 0)
        {
            if (GenerateHailParticle(task->data[3], task->data[2], taskId, 1))
                task->data[1]++;

            if (++task->data[2] == 3)
            {
                if (++task->data[3] == 10)
                    task->data[0]++;
                else
                    task->data[0]--;
            }
            else
            {
                task->data[5] = 1;
            }

        }
        else
        {
            task->data[5]--;
        }
        break;
    case 2:
        if (task->data[1] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

bool8 GenerateHailParticle(u8 hailStructId, u8 affineAnimNum, u8 taskId, u8 c)
{
    u8 id;
    s16 battlerX, battlerY;
    s16 spriteX;
    bool8 possibleBool = FALSE;
    s8 unk = gUnknown_08595CB4[hailStructId].unk3;

    if (unk != 2)
    {
        id = GetBattlerAtPosition(gUnknown_08595CB4[hailStructId].unk2);
        if (IsBattlerSpriteVisible(id))
        {
            possibleBool = TRUE;
            battlerX = GetBattlerSpriteCoord(id, BATTLER_COORD_X_2);
            battlerY = GetBattlerSpriteCoord(id, BATTLER_COORD_Y_PIC_OFFSET);
            switch (unk)
            {
            case 0:
                battlerX -= GetBattlerSpriteCoordAttr(id, BATTLER_COORD_ATTR_WIDTH) / 6;
                battlerY -= GetBattlerSpriteCoordAttr(id, BATTLER_COORD_ATTR_HEIGHT) / 6;
                break;
            case 1:
                battlerX += GetBattlerSpriteCoordAttr(id, BATTLER_COORD_ATTR_WIDTH) / 6;
                battlerY += GetBattlerSpriteCoordAttr(id, BATTLER_COORD_ATTR_HEIGHT) / 6;
                break;
            }
        }
        else
        {
            battlerX = (gUnknown_08595CB4[hailStructId].unk0);
            battlerY = (gUnknown_08595CB4[hailStructId].unk1);
        }
    }
    else
    {
        battlerX = (gUnknown_08595CB4[hailStructId].unk0);
        battlerY = (gUnknown_08595CB4[hailStructId].unk1);
    }
    spriteX = battlerX - ((battlerY + 8) / 2);
    id = CreateSprite(&gUnknown_08595D2C, spriteX, -8, 18);
    if (id == MAX_SPRITES)
    {
        return FALSE;
    }
    else
    {
        StartSpriteAffineAnim(&gSprites[id], affineAnimNum);
        gSprites[id].data[0] = possibleBool;
        gSprites[id].data[3] = battlerX;
        gSprites[id].data[4] = battlerY;
        gSprites[id].data[5] = affineAnimNum;
        gSprites[id].data[6] = taskId;
        gSprites[id].data[7] = c;
        return TRUE;
    }
}

void AnimHailBegin(struct Sprite *sprite)
{
    u8 spriteId;

    sprite->pos1.x += 4;
    sprite->pos1.y += 8;

    if (sprite->pos1.x < sprite->data[3] && sprite->pos1.y < sprite->data[4])
        return;

    if (sprite->data[0] == 1 && sprite->data[5] == 0)
    {
        spriteId = CreateSprite(&gUnknown_08595B68,
                                sprite->data[3], sprite->data[4], sprite->subpriority);

        sprite->data[0] = spriteId;
        if (spriteId != 64)
        {
            gSprites[sprite->data[0]].callback = AnimHailContinue;
            gSprites[sprite->data[0]].data[6] = sprite->data[6];
            gSprites[sprite->data[0]].data[7] = sprite->data[7];
        }

        FreeOamMatrix(sprite->oam.matrixNum);
        DestroySprite(sprite);
    }
    else
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        FreeOamMatrix(sprite->oam.matrixNum);
        DestroySprite(sprite);
    }
}

void AnimHailContinue(struct Sprite *sprite)
{
    if (++sprite->data[0] == 20)
    {
        gTasks[sprite->data[6]].data[sprite->data[7]]--;
        FreeOamMatrix(sprite->oam.matrixNum);
        DestroySprite(sprite);
    }
}

// Initializes the animation for Ice Ball.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: target x offset
// arg 3: target y offset
// arg 4: duration
// arg 5: arc height (negative)
void InitIceBallAnim(struct Sprite *sprite)
{
    u8 animNum = gAnimDisableStructPtr->rolloutTimerStartValue - gAnimDisableStructPtr->rolloutTimer - 1;

    if (animNum > 4)
        animNum = 4;

    StartSpriteAffineAnim(sprite, animNum);
    InitSpritePosToAnimAttacker(sprite, 1);

    sprite->data[0] = gBattleAnimArgs[4];

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    sprite->data[5] = gBattleAnimArgs[5];

    InitAnimArcTranslation(sprite);

    sprite->callback = AnimThrowIceBall;
}

// Throws the ball of ice in Ice Ball.
void AnimThrowIceBall(struct Sprite *sprite)
{
    if (!TranslateAnimHorizontalArc(sprite))
        return;

    StartSpriteAnim(sprite, 1);
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Initializes the particles that scatter at the end of the Ice Ball animation.
void InitIceBallParticle(struct Sprite *sprite)
{
    s16 randA, randB;

    sprite->oam.tileNum += 8;
    InitSpritePosToAnimTarget(sprite, TRUE);

    randA = (Random2() & 0xFF) + 256;
    randB = Random2() & 0x1FF;

    if (randB > 0xFF)
        randB = 256 - randB;

    sprite->data[1] = randA;
    sprite->data[2] = randB;
    sprite->callback = AnimIceBallParticle;
}

// Animates the particles created by InitIceBallParticle.
void AnimIceBallParticle(struct Sprite *sprite)
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

// Counter for Ice Ball.
void AnimTask_GetRolloutCounter(u8 taskId)
{
    u8 arg = gBattleAnimArgs[0];

    gBattleAnimArgs[arg] = gAnimDisableStructPtr->rolloutTimerStartValue - gAnimDisableStructPtr->rolloutTimer - 1;
    DestroyAnimVisualTask(taskId);
}
