#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "m4a.h"
#include "main.h"
#include "palette.h"
#include "pokeball.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/rgb.h"

// iwram
int gUnknown_030062DC;
u16 gUnknown_030062E0;
u16 gUnknown_030062E4;

static void sub_8170660(u8);
static void sub_8170A38(u8);
static void sub_8170EF0(u8);
static void sub_8171104(struct Sprite *);
static void sub_8171030(u8);
static void sub_81710A8(u8);
static void sub_8171134(struct Sprite *);
static void sub_8171CAC(struct Sprite *);
static void sub_81711E8(struct Sprite *);
static void sub_8171240(struct Sprite *);
static void sub_817138C(struct Sprite *);
static void sub_81713D0(struct Sprite *);
static void sub_81717B4(struct Sprite *);
static void sub_81714D4(struct Sprite *);
static void sub_8171520(struct Sprite *);
static void sub_81717D8(struct Sprite *);
static void sub_8171AE4(struct Sprite *);
static void sub_81717F8(struct Sprite *);
static void sub_81719EC(struct Sprite *);
static void sub_81718D8(struct Sprite *);
static void sub_81719C0(struct Sprite *);
static void sub_8171D60(u8);
static void sub_8171AAC(struct Sprite *);
static void sub_8171BAC(struct Sprite *);
static void sub_8171CE8(struct Sprite *);
static void PokeBallOpenParticleAnimation_Step1(struct Sprite *);
static void PokeBallOpenParticleAnimation_Step2(struct Sprite *);
static void DestroyBallOpenAnimationParticle(struct Sprite *);
static void FanOutBallOpenParticles_Step1(struct Sprite *);
static void RepeatBallOpenParticleAnimation_Step1(struct Sprite *);
static void PremierBallOpenParticleAnimation_Step1(struct Sprite *);
static void sub_8172AB0(u8);
static void sub_8172B40(u8);
static void sub_8172B90(u8);
static void sub_8172FEC(u8);
static void sub_81731FC(struct Sprite *);
static void sub_8173250(struct Sprite *);
static void sub_81731B0(u8);
static void sub_817339C(struct Sprite *);
static void sub_81733D4(struct Sprite *);
static void sub_8173400(struct Sprite *);
static void PokeBallOpenParticleAnimation(u8);
static void GreatBallOpenParticleAnimation(u8);
static void SafariBallOpenParticleAnimation(u8);
static void UltraBallOpenParticleAnimation(u8);
static void MasterBallOpenParticleAnimation(u8);
static void DiveBallOpenParticleAnimation(u8);
static void RepeatBallOpenParticleAnimation(u8);
static void TimerBallOpenParticleAnimation(u8);
static void PremierBallOpenParticleAnimation(u8);
static void sub_817330C(struct Sprite *);

struct BallCaptureSuccessStarData
{
    s8 xOffset;
    s8 yOffset;
    s8 unk2;
};

static const struct BallCaptureSuccessStarData sBallCaptureSuccessStarData[] =
{
    {
        .xOffset = 10,
        .yOffset = 2,
        .unk2 = -3,
    },
    {
        .xOffset = 15,
        .yOffset = 0,
        .unk2 = -4,
    },
    {
        .xOffset = -10,
        .yOffset = 2,
        .unk2 = -4,
    },
};

#define TAG_PARTICLES_POKEBALL    65030
#define TAG_PARTICLES_GREATBALL   65031
#define TAG_PARTICLES_SAFARIBALL  65032
#define TAG_PARTICLES_ULTRABALL   65033
#define TAG_PARTICLES_MASTERBALL  65034
#define TAG_PARTICLES_NETBALL     65035
#define TAG_PARTICLES_DIVEBALL    65036
#define TAG_PARTICLES_NESTBALL    65037
#define TAG_PARTICLES_REPEATBALL  65038
#define TAG_PARTICLES_TIMERBALL   65039
#define TAG_PARTICLES_LUXURYBALL  65040
#define TAG_PARTICLES_PREMIERBALL 65041
#define TAG_PARTICLES_LEVELBALL   65042
#define TAG_PARTICLES_LUREBALL    65043
#define TAG_PARTICLES_MOONBALL    65044
#define TAG_PARTICLES_FRIENDBALL  65045
#define TAG_PARTICLES_LOVEBALL    65046
#define TAG_PARTICLES_HEAVYBALL   65047
#define TAG_PARTICLES_FASTBALL    65048
#define TAG_PARTICLES_SPORTBALL   65049
#define TAG_PARTICLES_DUSKBALL    65050
#define TAG_PARTICLES_QUICKBALL   65051
#define TAG_PARTICLES_HEALBALL    65052
#define TAG_PARTICLES_CHERISHBALL 65053
#define TAG_PARTICLES_PARKBALL    65054
#define TAG_PARTICLES_DREAMBALL   65065
#define TAG_PARTICLES_BEASTBALL   65056

static const u32 sNewParticlesGfx[] = INCBIN_U32("graphics/interface/ball/particles2.4bpp.lz");
static const u32 sNewParticlesPal[] = INCBIN_U32("graphics/interface/ball/particles2.gbapal.lz");

const struct CompressedSpriteSheet gBallParticleSpritesheets[] =
{
    [BALL_POKE] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_POKEBALL},
    [BALL_GREAT] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_GREATBALL},
    [BALL_SAFARI] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_SAFARIBALL},
    [BALL_ULTRA] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_ULTRABALL},
    [BALL_MASTER] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_MASTERBALL},
    [BALL_NET] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_NETBALL},
    [BALL_DIVE] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_DIVEBALL},
    [BALL_NEST] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_NESTBALL},
    [BALL_REPEAT] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_REPEATBALL},
    [BALL_TIMER] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_TIMERBALL},
    [BALL_LUXURY] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_LUXURYBALL},
    [BALL_PREMIER] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_PREMIERBALL},
    [BALL_LEVEL] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_LEVELBALL},
    [BALL_LURE] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_LUREBALL},
    [BALL_MOON] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_MOONBALL},
    [BALL_FRIEND] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_FRIENDBALL},
    [BALL_LOVE] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_LOVEBALL},
    [BALL_HEAVY] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_HEAVYBALL},
    [BALL_FAST] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_FASTBALL},
    [BALL_SPORT] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_SPORTBALL},
    [BALL_DUSK] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_DUSKBALL},
    [BALL_QUICK] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_QUICKBALL},
    [BALL_HEAL] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_HEALBALL},
    [BALL_CHERISH] = {sNewParticlesGfx, 0x100, TAG_PARTICLES_CHERISHBALL},
    [BALL_PARK] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_PARKBALL},
    [BALL_DREAM] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_DREAMBALL},
    [BALL_BEAST] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_BEASTBALL},
};

const struct CompressedSpritePalette gBallParticlePalettes[] =
{
    [BALL_POKE] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_POKEBALL},
    [BALL_GREAT] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_GREATBALL},
    [BALL_SAFARI] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_SAFARIBALL},
    [BALL_ULTRA] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_ULTRABALL},
    [BALL_MASTER] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_MASTERBALL},
    [BALL_NET] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_NETBALL},
    [BALL_DIVE] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_DIVEBALL},
    [BALL_NEST] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_NESTBALL},
    [BALL_REPEAT] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_REPEATBALL},
    [BALL_TIMER] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_TIMERBALL},
    [BALL_LUXURY] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_LUXURYBALL},
    [BALL_PREMIER] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_PREMIERBALL},
    [BALL_LEVEL] = {sNewParticlesPal, TAG_PARTICLES_LEVELBALL},
    [BALL_LURE] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_LUREBALL},
    [BALL_MOON] = {sNewParticlesPal, TAG_PARTICLES_MOONBALL},
    [BALL_FRIEND] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_FRIENDBALL},
    [BALL_LOVE] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_LOVEBALL},
    [BALL_HEAVY] = {sNewParticlesPal, TAG_PARTICLES_HEAVYBALL},
    [BALL_FAST] = {sNewParticlesPal, TAG_PARTICLES_FASTBALL},
    [BALL_SPORT] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_SPORTBALL},
    [BALL_DUSK] = {sNewParticlesPal, TAG_PARTICLES_DUSKBALL},
    [BALL_QUICK] = {sNewParticlesPal, TAG_PARTICLES_QUICKBALL},
    [BALL_HEAL] = {sNewParticlesPal, TAG_PARTICLES_HEALBALL},
    [BALL_CHERISH] = {sNewParticlesPal, TAG_PARTICLES_CHERISHBALL},
    [BALL_PARK] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_PARKBALL},
    [BALL_DREAM] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_DREAMBALL},
    [BALL_BEAST] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_BEASTBALL},
};

const union AnimCmd gAnim_RegularBall[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gAnim_MasterBall[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END,
};

const union AnimCmd gAnim_NetDiveBall[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

const union AnimCmd gAnim_NestBall[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_END,
};

const union AnimCmd gAnim_LuxuryPremierBall[] =
{
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gAnim_UltraRepeatTimerBall[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gAnims_BallParticles[] =
{
    gAnim_RegularBall,
    gAnim_MasterBall,
    gAnim_NetDiveBall,
    gAnim_NestBall,
    gAnim_LuxuryPremierBall,
    gAnim_UltraRepeatTimerBall,
};

const u8 gBallParticleAnimNums[] =
{
    [BALL_POKE] = 0,
    [BALL_GREAT] = 0,
    [BALL_SAFARI] = 0,
    [BALL_ULTRA] = 5,
    [BALL_MASTER] = 1,
    [BALL_NET] = 2,
    [BALL_DIVE] = 2,
    [BALL_NEST] = 3,
    [BALL_REPEAT] = 5,
    [BALL_TIMER] = 5,
    [BALL_LUXURY] = 4,
    [BALL_PREMIER] = 4,

    [BALL_LEVEL] = 5,
    [BALL_LURE] = 2,
    [BALL_MOON] = 4,
    [BALL_FRIEND] = 3,
    [BALL_LOVE] = 3,
    [BALL_HEAVY] = 0,
    [BALL_FAST] = 4,
    [BALL_SPORT] = 0,
    [BALL_DUSK] = 2,
    [BALL_QUICK] = 4,
    [BALL_HEAL] = 0,
    [BALL_CHERISH] = 0,
    [BALL_PARK] = 5,
    [BALL_DREAM] = 5,
    [BALL_BEAST] = 5,
};

const TaskFunc gBallParticleAnimationFuncs[] =
{
    [BALL_POKE] = PokeBallOpenParticleAnimation,
    [BALL_GREAT] = GreatBallOpenParticleAnimation,
    [BALL_SAFARI] = SafariBallOpenParticleAnimation,
    [BALL_ULTRA] = UltraBallOpenParticleAnimation,
    [BALL_MASTER] = MasterBallOpenParticleAnimation,
    [BALL_NET] = SafariBallOpenParticleAnimation,
    [BALL_DIVE] = DiveBallOpenParticleAnimation,
    [BALL_NEST] = UltraBallOpenParticleAnimation,
    [BALL_REPEAT] = RepeatBallOpenParticleAnimation,
    [BALL_TIMER] = TimerBallOpenParticleAnimation,
    [BALL_LUXURY] = GreatBallOpenParticleAnimation,
    [BALL_PREMIER] = PremierBallOpenParticleAnimation,

    // Todo: assign and possibly create different particles
    [BALL_LEVEL] = SafariBallOpenParticleAnimation,
    [BALL_LURE] = GreatBallOpenParticleAnimation,
    [BALL_MOON] = UltraBallOpenParticleAnimation,
    [BALL_FRIEND] = UltraBallOpenParticleAnimation,
    [BALL_LOVE] = GreatBallOpenParticleAnimation,
    [BALL_HEAVY] = GreatBallOpenParticleAnimation,
    [BALL_FAST] = GreatBallOpenParticleAnimation,
    [BALL_SPORT] = UltraBallOpenParticleAnimation,
    [BALL_DUSK] = UltraBallOpenParticleAnimation,
    [BALL_QUICK] = UltraBallOpenParticleAnimation,
    [BALL_HEAL] = PokeBallOpenParticleAnimation,
    [BALL_CHERISH] = MasterBallOpenParticleAnimation,
    [BALL_PARK] = UltraBallOpenParticleAnimation,
    [BALL_DREAM] = UltraBallOpenParticleAnimation,
    [BALL_BEAST] = UltraBallOpenParticleAnimation
};

const struct SpriteTemplate gBallParticlesSpriteTemplates[] =
{
    {
        .tileTag = TAG_PARTICLES_POKEBALL,
        .paletteTag = TAG_PARTICLES_POKEBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_GREATBALL,
        .paletteTag = TAG_PARTICLES_GREATBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_SAFARIBALL,
        .paletteTag = TAG_PARTICLES_SAFARIBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_ULTRABALL,
        .paletteTag = TAG_PARTICLES_ULTRABALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_MASTERBALL,
        .paletteTag = TAG_PARTICLES_MASTERBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_NETBALL,
        .paletteTag = TAG_PARTICLES_NETBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_DIVEBALL,
        .paletteTag = TAG_PARTICLES_DIVEBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_NESTBALL,
        .paletteTag = TAG_PARTICLES_NESTBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_REPEATBALL,
        .paletteTag = TAG_PARTICLES_REPEATBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_TIMERBALL,
        .paletteTag = TAG_PARTICLES_TIMERBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_LUXURYBALL,
        .paletteTag = TAG_PARTICLES_LUXURYBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_PREMIERBALL,
        .paletteTag = TAG_PARTICLES_PREMIERBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_LEVELBALL,
        .paletteTag = TAG_PARTICLES_LEVELBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_LUREBALL,
        .paletteTag = TAG_PARTICLES_LUREBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_MOONBALL,
        .paletteTag = TAG_PARTICLES_MOONBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_FRIENDBALL,
        .paletteTag = TAG_PARTICLES_FRIENDBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_LOVEBALL,
        .paletteTag = TAG_PARTICLES_LOVEBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_HEAVYBALL,
        .paletteTag = TAG_PARTICLES_HEAVYBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_FASTBALL,
        .paletteTag = TAG_PARTICLES_FASTBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_SPORTBALL,
        .paletteTag = TAG_PARTICLES_SPORTBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_DUSKBALL,
        .paletteTag = TAG_PARTICLES_DUSKBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_QUICKBALL,
        .paletteTag = TAG_PARTICLES_QUICKBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_HEALBALL,
        .paletteTag = TAG_PARTICLES_HEALBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_CHERISHBALL,
        .paletteTag = TAG_PARTICLES_CHERISHBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_PARKBALL,
        .paletteTag = TAG_PARTICLES_PARKBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_DREAMBALL,
        .paletteTag = TAG_PARTICLES_DREAMBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    {
        .tileTag = TAG_PARTICLES_BEASTBALL,
        .paletteTag = TAG_PARTICLES_BEASTBALL,
        .oam = &gUnknown_08524904,
        .anims = gAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

const u16 gBallOpenFadeColors[] =
{
    [BALL_POKE] = RGB(31, 22, 30),
    [BALL_GREAT] = RGB(16, 23, 30),
    [BALL_SAFARI] = RGB(23, 30, 20),
    [BALL_ULTRA] = RGB(31, 31, 15),
    [BALL_MASTER] = RGB(23, 20, 28),
    [BALL_NET] = RGB(21, 31, 25),
    [BALL_DIVE] = RGB(12, 25, 30),
    [BALL_NEST] = RGB(30, 27, 10),
    [BALL_REPEAT] = RGB(31, 24, 16),
    [BALL_TIMER] = RGB(29, 30, 30),
    [BALL_LUXURY] = RGB(31, 17, 10),
    [BALL_PREMIER] = RGB(31, 9, 10),

    // Todo, assign different colors
    [BALL_LEVEL] = RGB(24, 4, 4),
    [BALL_LURE] = RGB(9, 22, 27),
    [BALL_MOON] = RGB(30, 25, 8),
    [BALL_FRIEND] = RGB(17, 24, 7),
    [BALL_LOVE] = RGB(31, 19, 26),
    [BALL_HEAVY] = RGB(7, 11, 20),
    [BALL_FAST] = RGB(29, 17, 8),
    [BALL_SPORT] = RGB(31, 31, 15),
    [BALL_DUSK] = RGB(7, 1, 13),
    [BALL_QUICK] = RGB(16, 25, 30),
    [BALL_HEAL] = RGB(31, 23, 27),
    [BALL_CHERISH] = RGB(25, 4, 3),
    [BALL_PARK] = RGB(31, 31, 15),
    [BALL_DREAM] = RGB(31, 31, 15),
    [BALL_BEAST] = RGB(31, 31, 15),
};

const struct SpriteTemplate gPokeblockSpriteTemplate =
{
    .tileTag = ANIM_TAG_POKEBLOCK,
    .paletteTag = ANIM_TAG_POKEBLOCK,
    .oam = &gUnknown_0852490C,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_817330C,
};

const union AnimCmd gUnknown_085E5350[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_085E5358[] = {
    gUnknown_085E5350,
};

const struct SpriteTemplate gBattleAnimSpriteTemplate_085E535C =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gUnknown_08524914,
    .anims = gUnknown_085E5358,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_817330C,
};

extern const struct SpriteTemplate gUnknown_085CE388;
extern const struct SpriteTemplate gMiniTwinklingStarSpriteTemplate;

void unref_sub_8170478(u8 taskId)
{
    struct BattleAnimBgData unknownStruct;
    u8 healthBoxSpriteId;
    u8 battler;
    u8 spriteId1, spriteId2, spriteId3, spriteId4;

    battler = gBattleAnimAttacker;
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 0);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
    SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 1);
    SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];
    spriteId3 = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    spriteId4 = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    gSprites[healthBoxSpriteId].oam.priority = 1;
    gSprites[spriteId1].oam.priority = 1;
    gSprites[spriteId2].oam.priority = 1;
    gSprites[spriteId3] = gSprites[healthBoxSpriteId];
    gSprites[spriteId4] = gSprites[spriteId1];
    gSprites[spriteId3].oam.objMode = ST_OAM_OBJ_WINDOW;
    gSprites[spriteId4].oam.objMode = ST_OAM_OBJ_WINDOW;
    gSprites[spriteId3].callback = SpriteCallbackDummy;
    gSprites[spriteId4].callback = SpriteCallbackDummy;

    sub_80A6B30(&unknownStruct);
    AnimLoadCompressedBgTilemap(unknownStruct.bgId, gUnknown_08C2EA9C);
    AnimLoadCompressedBgGfx(unknownStruct.bgId, gUnknown_08C2EA50, unknownStruct.tilesOffset);
    LoadCompressedPalette(gCureBubblesPal, unknownStruct.paletteId << 4, 32);

    gBattle_BG1_X = -gSprites[spriteId3].pos1.x + 32;
    gBattle_BG1_Y = -gSprites[spriteId3].pos1.y - 32;
    gTasks[taskId].data[1] = 640;
    gTasks[taskId].data[0] = spriteId3;
    gTasks[taskId].data[2] = spriteId4;
    gTasks[taskId].func = sub_8170660;
}

static void sub_8170660(u8 taskId)
{
    u8 spriteId1, spriteId2;
    u8 battler;

    battler = gBattleAnimAttacker;
    gTasks[taskId].data[13] += gTasks[taskId].data[1];
    gBattle_BG1_Y += (u16)gTasks[taskId].data[13] >> 8;
    gTasks[taskId].data[13] &= 0xFF;

    switch (gTasks[taskId].data[15])
    {
    case 0:
        if (gTasks[taskId].data[11]++ > 1)
        {
            gTasks[taskId].data[11] = 0;
            gTasks[taskId].data[12]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[12], 16 - gTasks[taskId].data[12]));
            if (gTasks[taskId].data[12] == 8)
                gTasks[taskId].data[15]++;
        }
        break;
    case 1:
        if (++gTasks[taskId].data[10] == 30)
            gTasks[taskId].data[15]++;
        break;
    case 2:
        if (gTasks[taskId].data[11]++ > 1)
        {
            gTasks[taskId].data[11] = 0;
            gTasks[taskId].data[12]--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[12], 16 - gTasks[taskId].data[12]));
            if (gTasks[taskId].data[12] == 0)
            {
                sub_80A477C(0);
                gBattle_WIN0H = 0;
                gBattle_WIN0V = 0;
                SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
                SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
                if (!IsContest())
                    SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

                SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
                SetGpuReg(REG_OFFSET_BLDCNT, 0);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
                DestroySprite(&gSprites[gTasks[taskId].data[0]]);
                DestroySprite(&gSprites[gTasks[taskId].data[2]]);
                SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 0);
                spriteId1 = gSprites[gHealthboxSpriteIds[battler]].oam.affineParam;
                spriteId2 = gSprites[gHealthboxSpriteIds[battler]].data[5];
                gSprites[gHealthboxSpriteIds[battler]].oam.priority = 1;
                gSprites[spriteId1].oam.priority = 1;
                gSprites[spriteId2].oam.priority = 1;
                DestroyAnimVisualTask(taskId);
            }
        }
        break;
    }
}

static void sub_8170834(u8 *paletteId1, u8 *paletteId2, u8 battler)
{
    u8 healthBoxSpriteId;
    u8 spriteId1, spriteId2;
    u16 offset1, offset2;

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];
    *paletteId1 = AllocSpritePalette(0xD709);
    *paletteId2 = AllocSpritePalette(0xD70A);

    offset1 = (gSprites[healthBoxSpriteId].oam.paletteNum * 16) + 0x100;
    offset2 = (gSprites[spriteId2].oam.paletteNum * 16) + 0x100;
    LoadPalette(&gPlttBufferUnfaded[offset1], *paletteId1 * 16 + 0x100, 0x20);
    LoadPalette(&gPlttBufferUnfaded[offset2], *paletteId2 * 16 + 0x100, 0x20);

    gSprites[healthBoxSpriteId].oam.paletteNum = *paletteId1;
    gSprites[spriteId1].oam.paletteNum = *paletteId1;
    gSprites[spriteId2].oam.paletteNum = *paletteId2;
}

void sub_8170920(u8 taskId)
{
    u8 paletteId1, paletteId2;
    sub_8170834(&paletteId1, &paletteId2, gBattleAnimAttacker);
    DestroyAnimVisualTask(taskId);
}

static void sub_817094C(u8 battler)
{
    u8 healthBoxSpriteId;
    u8 spriteId1, spriteId2;
    u8 paletteId1, paletteId2;

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];

    FreeSpritePaletteByTag(0xD709);
    FreeSpritePaletteByTag(0xD70A);
    paletteId1 = IndexOfSpritePaletteTag(0xD6FF);
    paletteId2 = IndexOfSpritePaletteTag(0xD704);
    gSprites[healthBoxSpriteId].oam.paletteNum = paletteId1;
    gSprites[spriteId1].oam.paletteNum = paletteId1;
    gSprites[spriteId2].oam.paletteNum = paletteId2;
}

void sub_81709EC(u8 taskId)
{
    sub_817094C(gBattleAnimAttacker);
    DestroyAnimVisualTask(taskId);
}

void sub_8170A0C(u8 taskId)
{
    gTasks[taskId].data[10] = gBattleAnimArgs[0];
    gTasks[taskId].data[11] = gBattleAnimArgs[1];
    gTasks[taskId].func = sub_8170A38;
}

static void sub_8170A38(u8 taskId)
{
    u8 paletteNum;
    int paletteOffset, colorOffset;

    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0]++ >= gTasks[taskId].data[11])
    {
        gTasks[taskId].data[0] = 0;
        paletteNum = IndexOfSpritePaletteTag(0xD709);
        colorOffset = gTasks[taskId].data[10] == 0 ? 6 : 2;
        switch (gTasks[taskId].data[1])
        {
        case 0:
            gTasks[taskId].data[2] += 2;
            if (gTasks[taskId].data[2] > 16)
                gTasks[taskId].data[2] = 16;

            paletteOffset = paletteNum * 16 + 0x100;
            BlendPalette(paletteOffset + colorOffset, 1, gTasks[taskId].data[2], RGB(20, 27, 31));
            if (gTasks[taskId].data[2] == 16)
                gTasks[taskId].data[1]++;
            break;
        case 1:
            gTasks[taskId].data[2] -= 2;
            if (gTasks[taskId].data[2] < 0)
                gTasks[taskId].data[2] = 0;

            paletteOffset = paletteNum * 16 + 0x100;
            BlendPalette(paletteOffset + colorOffset, 1, gTasks[taskId].data[2], RGB(20, 27, 31));
            if (gTasks[taskId].data[2] == 0)
                DestroyAnimVisualTask(taskId);
            break;
        }
    }
}

void sub_8170B04(u8 taskId)
{
    u8 spriteId;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        gTasks[taskId].data[10] = 0x100;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[10] += 0x30;
        SetSpriteRotScale(spriteId, gTasks[taskId].data[10], gTasks[taskId].data[10], 0);
        SetBattlerSpriteYOffsetFromYScale(spriteId);
        if (gTasks[taskId].data[10] >= 0x2D0)
            gTasks[taskId].data[0]++;
        break;
    case 2:
        ResetSpriteRotScale(spriteId);
        gSprites[spriteId].invisible = 1;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_8170BB0(u8 taskId)
{
    u8 spriteId;
    u16 ball;
    u8 ballId;
    u8 x, y;
    u8 priority, subpriority;
    u32 selectedPalettes;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        ball = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_POKEBALL);
    else
        ball = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_POKEBALL);

    ballId = ItemIdToBallId(ball);
    switch (gTasks[taskId].data[0])
    {
    case 0:
        x = GetBattlerSpriteCoord(gBattleAnimAttacker, 0);
        y = GetBattlerSpriteCoord(gBattleAnimAttacker, 1);
        priority = gSprites[spriteId].oam.priority;
        subpriority = gSprites[spriteId].subpriority;
        gTasks[taskId].data[10] = AnimateBallOpenParticles(x, y + 32, priority, subpriority, ballId);
        selectedPalettes = sub_80A75AC(1, 0, 0, 0, 0, 0, 0);
        gTasks[taskId].data[11] = LaunchBallFadeMonTask(0, gBattleAnimAttacker, selectedPalettes, ballId);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gTasks[gTasks[taskId].data[10]].isActive && !gTasks[gTasks[taskId].data[11]].isActive)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

void sub_8170CFC(u8 taskId)
{
    u8 ballId = ItemIdToBallId(gLastUsedItem);
    LoadBallGfx(ballId);
    DestroyAnimVisualTask(taskId);
}

void sub_8170D24(u8 taskId)
{
    u8 ballId = ItemIdToBallId(gLastUsedItem);
    FreeBallGfx(ballId);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_IsBallBlockedByTrainer(u8 taskId)
{
    if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_TRAINER_BLOCK)
        gBattleAnimArgs[ARG_RET_ID] = -1;
    else
        gBattleAnimArgs[ARG_RET_ID] = 0;

    DestroyAnimVisualTask(taskId);
}

u8 ItemIdToBallId(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_MASTER_BALL:
        return BALL_MASTER;
    case ITEM_ULTRA_BALL:
        return BALL_ULTRA;
    case ITEM_GREAT_BALL:
        return BALL_GREAT;
    case ITEM_SAFARI_BALL:
        return BALL_SAFARI;
    case ITEM_NET_BALL:
        return BALL_NET;
    case ITEM_DIVE_BALL:
        return BALL_DIVE;
    case ITEM_NEST_BALL:
        return BALL_NEST;
    case ITEM_REPEAT_BALL:
        return BALL_REPEAT;
    case ITEM_TIMER_BALL:
        return BALL_TIMER;
    case ITEM_LUXURY_BALL:
        return BALL_LUXURY;
    case ITEM_PREMIER_BALL:
        return BALL_PREMIER;
    case ITEM_POKE_BALL:
        return BALL_POKE;
    case ITEM_LEVEL_BALL:
        return BALL_LEVEL;
    case ITEM_LURE_BALL:
        return BALL_LURE;
    case ITEM_MOON_BALL:
        return BALL_MOON;
    case ITEM_FRIEND_BALL:
        return BALL_FRIEND;
    case ITEM_LOVE_BALL:
        return BALL_LOVE;
    case ITEM_HEAVY_BALL:
        return BALL_HEAVY;
    case ITEM_FAST_BALL:
        return BALL_FAST;
    case ITEM_SPORT_BALL:
        return BALL_SPORT;
    case ITEM_DUSK_BALL:
        return BALL_DUSK;
    case ITEM_QUICK_BALL:
        return BALL_QUICK;
    case ITEM_HEAL_BALL:
        return BALL_HEAL;
    case ITEM_CHERISH_BALL:
        return BALL_CHERISH;
    case ITEM_PARK_BALL:
        return BALL_PARK;
    case ITEM_DREAM_BALL:
        return BALL_DREAM;
    case ITEM_BEAST_BALL:
        return BALL_BEAST;
    default:
        return BALL_POKE;
    }
}

void sub_8170E04(u8 taskId)
{
    u8 ballId;
    u8 spriteId;

    ballId = ItemIdToBallId(gLastUsedItem);
    spriteId = CreateSprite(&gBallSpriteTemplates[ballId], 32, 80, 29);
    gSprites[spriteId].data[0] = 34;
    gSprites[spriteId].data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
    gSprites[spriteId].data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 1) - 16;
    gSprites[spriteId].callback = sub_8171104;
    gBattleSpritesDataPtr->animationData->field_9_x2 = gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible;
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].func = sub_8170EF0;
}

static void sub_8170EF0(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];
    if ((u16)gSprites[spriteId].data[0] == 0xFFFF)
        DestroyAnimVisualTask(taskId);
}

void sub_8170F2C(u8 taskId)
{
    int x, y;
    u8 ballId;
    u8 subpriority;
    u8 spriteId;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        x = 32;
        y = 11;
    }
    else
    {
        x = 23;
        y = 5;
    }

    ballId = ItemIdToBallId(gLastUsedItem);
    subpriority = GetBattlerSpriteSubpriority(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)) + 1;
    spriteId = CreateSprite(&gBallSpriteTemplates[ballId], x + 32, y | 80, subpriority);
    gSprites[spriteId].data[0] = 34;
    gSprites[spriteId].data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, 0);
    gSprites[spriteId].data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, 1) - 16;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].callback = sub_8039E84;
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].func = sub_8171030;
}

static void sub_8171030(u8 taskId)
{
    if (gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].animCmdIndex == 1)
    {
        PlaySE12WithPanning(SE_NAGERU, 0);
        gSprites[gTasks[taskId].data[0]].callback = sub_8171104;
        CreateTask(sub_81710A8, 10);
        gTasks[taskId].func = sub_8170EF0;
    }
}

static void sub_81710A8(u8 taskId)
{
    if (gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].animEnded)
    {
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]], 0);
        DestroyTask(taskId);
    }
}

static void sub_8171104(struct Sprite *sprite)
{
    u16 temp = sprite->data[1];
    u16 temp2 = sprite->data[2];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = temp;
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = temp2;
    sprite->data[5] = -40;
    InitAnimArcTranslation(sprite);
    sprite->callback = sub_8171134;
}

static void sub_8171134(struct Sprite *sprite)
{
    int i;
    u8 ballId;

    if (TranslateAnimHorizontalArc(sprite))
    {
        if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_TRAINER_BLOCK)
        {
            sprite->callback = sub_8171CAC;
        }
        else
        {
            StartSpriteAnim(sprite, 1);
            sprite->pos1.x += sprite->pos2.x;
            sprite->pos1.y += sprite->pos2.y;
            sprite->pos2.x = 0;
            sprite->pos2.y = 0;

            for (i = 0; i < 8; i++)
                sprite->data[i] = 0;

            sprite->data[5] = 0;
            sprite->callback = sub_81711E8;

            ballId = ItemIdToBallId(gLastUsedItem);
            switch (ballId)
            {
            case 0 ... POKEBALL_COUNT - 1:
                AnimateBallOpenParticles(sprite->pos1.x, sprite->pos1.y - 5, 1, 28, ballId);
                LaunchBallFadeMonTask(0, gBattleAnimTarget, 14, ballId);
                break;
            }
        }
    }
}

static void sub_81711E8(struct Sprite *sprite)
{
    if (++sprite->data[5] == 10)
    {
        sprite->data[5] = CreateTask(TaskDummy, 50);
        sprite->callback = sub_8171240;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] = 0;
    }
}

static void sub_8171240(struct Sprite *sprite)
{
    u8 spriteId;
    u8 taskId;

    spriteId = gBattlerSpriteIds[gBattleAnimTarget];
    taskId = sprite->data[5];

    if (++gTasks[taskId].data[1] == 11)
        PlaySE(SE_SUIKOMU);

    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        gTasks[taskId].data[10] = 256;
        gUnknown_030062DC = 28;
        gUnknown_030062E4 = (gSprites[spriteId].pos1.y + gSprites[spriteId].pos2.y) - (sprite->pos1.y + sprite->pos2.y);
        gUnknown_030062E0 = (u32)(gUnknown_030062E4 * 256) / 28;
        gTasks[taskId].data[2] = gUnknown_030062E0;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[10] += 0x20;
        SetSpriteRotScale(spriteId, gTasks[taskId].data[10], gTasks[taskId].data[10], 0);
        gTasks[taskId].data[3] += gTasks[taskId].data[2];
        gSprites[spriteId].pos2.y = -gTasks[taskId].data[3] >> 8;
        if (gTasks[taskId].data[10] >= 0x480)
            gTasks[taskId].data[0]++;
        break;
    case 2:
        ResetSpriteRotScale(spriteId);
        gSprites[spriteId].invisible = 1;
        gTasks[taskId].data[0]++;
        break;
    default:
        if (gTasks[taskId].data[1] > 10)
        {
            DestroyTask(taskId);
            StartSpriteAnim(sprite, 2);
            sprite->data[5] = 0;
            sprite->callback = sub_817138C;
        }
        break;
    }
}

static void sub_817138C(struct Sprite *sprite)
{
    int angle;

    if (sprite->animEnded)
    {
        sprite->data[3] = 0;
        sprite->data[4] = 40;
        sprite->data[5] = 0;
        angle = 0;
        sprite->pos1.y += Cos(angle, 40);
        sprite->pos2.y = -Cos(angle, sprite->data[4]);
        sprite->callback = sub_81713D0;
    }
}

static void sub_81713D0(struct Sprite *sprite)
{
    bool8 lastBounce;
    int bounceCount;

    lastBounce = 0;

    switch (sprite->data[3] & 0xFF)
    {
    case 0:
        sprite->pos2.y = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] += (sprite->data[3] >> 8) + 4;
        if (sprite->data[5] >= 64)
        {
            sprite->data[4] -= 10;
            sprite->data[3] += 257;

            bounceCount = sprite->data[3] >> 8;
            if (bounceCount == 4)
                lastBounce = 1;

            // Play a different sound effect for each pokeball bounce.
            switch (bounceCount)
            {
            case 1:
                PlaySE(SE_KON);
                break;
            case 2:
                PlaySE(SE_KON2);
                break;
            case 3:
                PlaySE(SE_KON3);
                break;
            default:
                PlaySE(SE_KON4);
                break;
            }
        }
        break;
    case 1:
        sprite->pos2.y = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] -= (sprite->data[3] >> 8) + 4;
        if (sprite->data[5] <= 0)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= -0x100;
        }
        break;
    }

    if (lastBounce)
    {
        sprite->data[3] = 0;
        sprite->pos1.y += Cos(64, 40);
        sprite->pos2.y = 0;
        if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_NO_SHAKES)
        {
            sprite->data[5] = 0;
            sprite->callback = sub_81717B4;
        }
        else
        {
            sprite->callback = sub_81714D4;
            sprite->data[4] = 1;
            sprite->data[5] = 0;
        }
    }
}

static void sub_81714D4(struct Sprite *sprite)
{
    if (++sprite->data[3] == 31)
    {
        sprite->data[3] = 0;
        sprite->affineAnimPaused = 1;
        StartSpriteAffineAnim(sprite, 1);
        gBattleSpritesDataPtr->animationData->field_C = 0;
        sprite->callback = sub_8171520;
        PlaySE(SE_BOWA);
    }
}

static void sub_8171520(struct Sprite *sprite)
{
    s8 state;
    u16 var0;

    switch (sprite->data[3] & 0xFF)
    {
    case 0:
        if (gBattleSpritesDataPtr->animationData->field_C > 0xFF)
        {
            sprite->pos2.x += sprite->data[4];
            gBattleSpritesDataPtr->animationData->field_C &= 0xFF;
        }
        else
        {
            gBattleSpritesDataPtr->animationData->field_C += 0xB0;
        }

        sprite->data[5]++;
        sprite->affineAnimPaused = 0;
        var0 = sprite->data[5] + 7;
        if (var0 > 14)
        {
            gBattleSpritesDataPtr->animationData->field_C = 0;
            sprite->data[3]++;
            sprite->data[5] = 0;
        }
        break;
    case 1:
        if (++sprite->data[5] == 1)
        {
            sprite->data[5] = 0;
            sprite->data[4] = -sprite->data[4];
            sprite->data[3]++;
            sprite->affineAnimPaused = 0;
            if (sprite->data[4] < 0)
                ChangeSpriteAffineAnim(sprite, 2);
            else
                ChangeSpriteAffineAnim(sprite, 1);
        }
        else
        {
            sprite->affineAnimPaused = 1;
        }
        break;
    case 2:
        if (gBattleSpritesDataPtr->animationData->field_C > 0xFF)
        {
            sprite->pos2.x += sprite->data[4];
            gBattleSpritesDataPtr->animationData->field_C &= 0xFF;
        }
        else
        {
            gBattleSpritesDataPtr->animationData->field_C += 0xB0;
        }

        sprite->data[5]++;
        sprite->affineAnimPaused = 0;
        var0 = sprite->data[5] + 12;
        if (var0 > 24)
        {
            gBattleSpritesDataPtr->animationData->field_C = 0;
            sprite->data[3]++;
            sprite->data[5] = 0;
        }
        break;
    case 3:
        if (sprite->data[5]++ < 0)
        {
            sprite->affineAnimPaused = 1;
            break;
        }

        sprite->data[5] = 0;
        sprite->data[4] = -sprite->data[4];
        sprite->data[3]++;
        sprite->affineAnimPaused = 0;
        if (sprite->data[4] < 0)
            ChangeSpriteAffineAnim(sprite, 2);
        else
            ChangeSpriteAffineAnim(sprite, 1);
        // fall through
    case 4:
        if (gBattleSpritesDataPtr->animationData->field_C > 0xFF)
        {
            sprite->pos2.x += sprite->data[4];
            gBattleSpritesDataPtr->animationData->field_C &= 0xFF;
        }
        else
        {
            gBattleSpritesDataPtr->animationData->field_C += 0xB0;
        }

        sprite->data[5]++;
        sprite->affineAnimPaused = 0;
        var0 = sprite->data[5] + 4;
        if (var0 > 8)
        {
            gBattleSpritesDataPtr->animationData->field_C = 0;
            sprite->data[3]++;
            sprite->data[5] = 0;
            sprite->data[4] = -sprite->data[4];
        }
        break;
    case 5:
        sprite->data[3] += 0x100;
        state = sprite->data[3] >> 8;
        if (state == gBattleSpritesDataPtr->animationData->ballThrowCaseId)
        {
            sprite->affineAnimPaused = 1;
            sprite->callback = sub_81717B4;
        }
        else
        {
            if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_3_SHAKES_SUCCESS && state == 3)
            {
                sprite->callback = sub_81717D8;
                sprite->affineAnimPaused = 1;
            }
            else
            {
                sprite->data[3]++;
                sprite->affineAnimPaused = 1;
            }
        }
        break;
    case 6:
    default:
        if (++sprite->data[5] == 31)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= -0x100;
            StartSpriteAffineAnim(sprite, 3);
            if (sprite->data[4] < 0)
                StartSpriteAffineAnim(sprite, 2);
            else
                StartSpriteAffineAnim(sprite, 1);

            PlaySE(SE_BOWA);
        }
        break;
    }
}

static void sub_81717B4(struct Sprite *sprite)
{
    if (++sprite->data[5] == 31)
    {
        sprite->data[5] = 0;
        sprite->callback = sub_8171AE4;
    }
}

static void sub_81717D8(struct Sprite *sprite)
{
    sprite->animPaused = 1;
    sprite->callback = sub_81717F8;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

static void sub_81717F8(struct Sprite *sprite)
{
    u8 *battler = &gBattleAnimTarget;

    sprite->data[4]++;
    if (sprite->data[4] == 40)
    {
        PlaySE(SE_RG_GETTING);
        BlendPalettes(0x10000 << sprite->oam.paletteNum, 6, RGB(0, 0, 0));
        sub_81719EC(sprite);
    }
    else if (sprite->data[4] == 60)
    {
        BeginNormalPaletteFade(0x10000 << sprite->oam.paletteNum, 2, 6, 0, RGB(0, 0, 0));
    }
    else if (sprite->data[4] == 95)
    {
        gDoingBattleAnim = 0;
        UpdateOamPriorityInAllHealthboxes(1);
        m4aMPlayAllStop();
        PlaySE(MUS_RG_FAN6);
    }
    else if (sprite->data[4] == 315)
    {
        FreeOamMatrix(gSprites[gBattlerSpriteIds[*battler]].oam.matrixNum);
        DestroySprite(&gSprites[gBattlerSpriteIds[*battler]]);
        sprite->data[0] = 0;
        sprite->callback = sub_81718D8;
    }
}

static void sub_81718D8(struct Sprite *sprite)
{
    u8 paletteIndex;

    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = 0;
        sprite->data[2] = 0;
        sprite->oam.objMode = ST_OAM_OBJ_BLEND;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        paletteIndex = IndexOfSpritePaletteTag(sprite->template->paletteTag);
        BeginNormalPaletteFade(1 << (paletteIndex + 0x10), 0, 0, 16, RGB(31, 31, 31));
        sprite->data[0]++;
        break;
    case 1:
        if (sprite->data[1]++ > 0)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[2], sprite->data[2]));
            if (sprite->data[2] == 16)
                sprite->data[0]++;
        }
        break;
    case 2:
        sprite->invisible = 1;
        sprite->data[0]++;
        break;
    default:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            sprite->data[0] = 0;
            sprite->callback = sub_81719C0;
        }
        break;
    }
}

static void sub_81719C0(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->data[0] = -1;
    }
    else
    {
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

static void sub_81719EC(struct Sprite *sprite)
{
    u32 i;
    u8 subpriority;

    if (sprite->subpriority)
    {
        subpriority = sprite->subpriority - 1;
    }
    else
    {
        subpriority = 0;
        sprite->subpriority = 1;
    }

    sub_8171D60(4);
    for (i = 0; i < 3; i++)
    {
        u8 spriteId = CreateSprite(&gBallParticlesSpriteTemplates[4], sprite->pos1.x, sprite->pos1.y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = 24;
            gSprites[spriteId].data[2] = sprite->pos1.x + sBallCaptureSuccessStarData[i].xOffset;
            gSprites[spriteId].data[4] = sprite->pos1.y + sBallCaptureSuccessStarData[i].yOffset;
            gSprites[spriteId].data[5] = sBallCaptureSuccessStarData[i].unk2;
            InitAnimArcTranslation(&gSprites[spriteId]);
            gSprites[spriteId].callback = sub_8171AAC;
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[4]);
        }
    }
}

static void sub_8171AAC(struct Sprite *sprite)
{
    sprite->invisible = !sprite->invisible;
    if (TranslateAnimHorizontalArc(sprite))
        DestroySprite(sprite);
}

static void sub_8171AE4(struct Sprite *sprite)
{
    u8 ballId;

    StartSpriteAnim(sprite, 1);
    StartSpriteAffineAnim(sprite, 0);
    sprite->callback = sub_8171BAC;

    ballId = ItemIdToBallId(gLastUsedItem);
    switch (ballId)
    {
    case 0 ... POKEBALL_COUNT - 1:
        AnimateBallOpenParticles(sprite->pos1.x, sprite->pos1.y - 5, 1, 28, ballId);
        LaunchBallFadeMonTask(1, gBattleAnimTarget, 14, ballId);
        break;
    }

    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible = 0;
    StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]], 1);
    AnimateSprite(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]]);
    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] = 0x1000;
}

static void sub_8171BAC(struct Sprite *sprite)
{
    int next = FALSE;

    if (sprite->animEnded)
        sprite->invisible = 1;

    if (gSprites[gBattlerSpriteIds[gBattleAnimTarget]].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]], 0);
        next = TRUE;
    }
    else
    {
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] -= 288;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].pos2.y = gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] >> 8;
    }

    if (sprite->animEnded && next)
    {
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].pos2.y = 0;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible = gBattleSpritesDataPtr->animationData->field_9_x2;
        sprite->data[0] = 0;
        sprite->callback = sub_81719C0;
        gDoingBattleAnim = 0;
        UpdateOamPriorityInAllHealthboxes(1);
    }
}

static void sub_8171CAC(struct Sprite *sprite)
{
    int i;

    sprite->pos1.x += sprite->pos2.x;
    sprite->pos1.y += sprite->pos2.y;
    sprite->pos2.y = 0;
    sprite->pos2.x = 0;
    for (i = 0; i < 6; i++)
        sprite->data[i] = 0;

    sprite->callback = sub_8171CE8;
}

static void sub_8171CE8(struct Sprite *sprite)
{
    s16 var0 = sprite->data[0] + 0x800;
    s16 var1 = sprite->data[1] + 0x680;
    sprite->pos2.x -= var1 >> 8;
    sprite->pos2.y += var0 >> 8;
    sprite->data[0] = (sprite->data[0] + 0x800) & 0xFF;
    sprite->data[1] = (sprite->data[1] + 0x680) & 0xFF;

    if (sprite->pos1.y + sprite->pos2.y > 160
     || sprite->pos1.x + sprite->pos2.x < -8)
    {
        sprite->data[0] = 0;
        sprite->callback = sub_81719C0;
        gDoingBattleAnim = 0;
        UpdateOamPriorityInAllHealthboxes(1);
    }
}

static void sub_8171D60(u8 ballId)
{
    u8 taskId;

    if (GetSpriteTileStartByTag(gBallParticleSpritesheets[ballId].tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&gBallParticleSpritesheets[ballId]);
        LoadCompressedSpritePaletteUsingHeap(&gBallParticlePalettes[ballId]);
    }
}

u8 AnimateBallOpenParticles(u8 x, u8 y, u8 priority, u8 subpriority, u8 ballId)
{
    u8 taskId;

    sub_8171D60(ballId);
    taskId = CreateTask(gBallParticleAnimationFuncs[ballId], 5);
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = priority;
    gTasks[taskId].data[4] = subpriority;
    gTasks[taskId].data[15] = ballId;
    PlaySE(SE_BOWA2);

    return taskId;
}

void sub_8171E20(void)
{
    if (gMain.inBattle)
        gBattleSpritesDataPtr->animationData->field_A++;
}

static void PokeBallOpenParticleAnimation(u8 taskId)
{
    u8 spriteId;
    u8 x, y;
    u8 priority, subpriority;
    u8 ballId;
    u8 var0;

    ballId = gTasks[taskId].data[15];
    if (gTasks[taskId].data[0] < 16)
    {
        x = gTasks[taskId].data[1];
        y = gTasks[taskId].data[2];
        priority = gTasks[taskId].data[3];
        subpriority = gTasks[taskId].data[4];

        spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_8171E20();
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = PokeBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;

            var0 = (u8)gTasks[taskId].data[0];
            if (var0 >= 8)
                var0 -= 8;

            gSprites[spriteId].data[0] = var0 * 32;
        }

        if (gTasks[taskId].data[0] == 15)
        {
            if (!gMain.inBattle)
                gSprites[spriteId].data[7] = 1;

            DestroyTask(taskId);
            return;
        }
    }

    gTasks[taskId].data[0]++;
}

static void PokeBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
        sprite->callback = PokeBallOpenParticleAnimation_Step2;
    else
        sprite->data[1]--;
}

static void PokeBallOpenParticleAnimation_Step2(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[0], sprite->data[1]);
    sprite->pos2.y = Cos(sprite->data[0], sprite->data[1]);
    sprite->data[1] += 2;
    if (sprite->data[1] == 50)
        DestroyBallOpenAnimationParticle(sprite);
}

static void TimerBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_8171E20();
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 10;
            gSprites[spriteId].data[5] = 2;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void DiveBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_8171E20();
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 10;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 2;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

// Also used for Net Ball
static void SafariBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_8171E20();
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 4;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

// Also used for Nest Ball
static void UltraBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 10; i++)
    {
        spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_8171E20();
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 25;
            gSprites[spriteId].data[4] = 5;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

// Also used for Luxury Ball
static void GreatBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    if (gTasks[taskId].data[7])
    {
        gTasks[taskId].data[7]--;
    }
    else
    {
        ballId = gTasks[taskId].data[15];
        x = gTasks[taskId].data[1];
        y = gTasks[taskId].data[2];
        priority = gTasks[taskId].data[3];
        subpriority = gTasks[taskId].data[4];

        for (i = 0; i < 8; i++)
        {
            spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
            if (spriteId != MAX_SPRITES)
            {
                sub_8171E20();
                StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
                gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
                gSprites[spriteId].oam.priority = priority;
                gSprites[spriteId].data[0] = i * 32;
                gSprites[spriteId].data[4] = 8;
                gSprites[spriteId].data[5] = 2;
                gSprites[spriteId].data[6] = 2;
            }
        }

        gTasks[taskId].data[7] = 8;
        if (++gTasks[taskId].data[0] == 2)
        {
            if (!gMain.inBattle)
                gSprites[spriteId].data[7] = 1;

            DestroyTask(taskId);
        }
    }
}

static void FanOutBallOpenParticles_Step1(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[0], sprite->data[1]);
    sprite->pos2.y = Cos(sprite->data[0], sprite->data[2]);
    sprite->data[0] = (sprite->data[0] + sprite->data[4]) & 0xFF;
    sprite->data[1] += sprite->data[5];
    sprite->data[2] += sprite->data[6];
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

static void RepeatBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < POKEBALL_COUNT; i++)
    {
        spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_8171E20();
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = RepeatBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 21;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void RepeatBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[0], sprite->data[1]);
    sprite->pos2.y = Cos(sprite->data[0], Sin(sprite->data[0], sprite->data[2]));
    sprite->data[0] = (sprite->data[0] + 6) & 0xFF;
    sprite->data[1]++;
    sprite->data[2]++;
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

static void MasterBallOpenParticleAnimation(u8 taskId)
{
    u8 i, j;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 8; i++)
        {
            spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
            if (spriteId != MAX_SPRITES)
            {
                sub_8171E20();
                StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
                gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
                gSprites[spriteId].oam.priority = priority;
                gSprites[spriteId].data[0] = i * 32;
                gSprites[spriteId].data[4] = 8;

                if (j == 0)
                {
                    gSprites[spriteId].data[5] = 2;
                    gSprites[spriteId].data[6] = 1;
                }
                else
                {
                    gSprites[spriteId].data[5] = 1;
                    gSprites[spriteId].data[6] = 2;
                }
            }
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void PremierBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x, y, priority, subpriority, ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&gBallParticlesSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_8171E20();
            StartSpriteAnim(&gSprites[spriteId], gBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = PremierBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

static void PremierBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[0], sprite->data[1]);
    sprite->pos2.y = Cos(sprite->data[0], Sin(sprite->data[0] & 0x3F, sprite->data[2]));
    sprite->data[0] = (sprite->data[0] + 10) & 0xFF;
    sprite->data[1]++;
    sprite->data[2]++;
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

static void DestroyBallOpenAnimationParticle(struct Sprite *sprite)
{
    int i, j;

    if (!gMain.inBattle)
    {
        if (sprite->data[7] == 1)
            DestroySpriteAndFreeResources(sprite);
        else
            DestroySprite(sprite);
    }
    else
    {
        gBattleSpritesDataPtr->animationData->field_A--;
        if (gBattleSpritesDataPtr->animationData->field_A == 0)
        {
            for (i = 0; i < POKEBALL_COUNT; i++)
            {
                if (FuncIsActiveTask(gBallParticleAnimationFuncs[i]) == TRUE)
                    break;
            }

            if (i == POKEBALL_COUNT)
            {
                for (j = 0; j < POKEBALL_COUNT; j++)
                {
                    FreeSpriteTilesByTag(gBallParticleSpritesheets[j].tag);
                    FreeSpritePaletteByTag(gBallParticlePalettes[j].tag);
                }
            }

            DestroySprite(sprite);
        }
        else
        {
            DestroySprite(sprite);
        }
    }
}

u8 LaunchBallFadeMonTask(u8 unfadeLater, u8 battler, u32 selectedPalettes, u8 ballId)
{
    u8 taskId;

    taskId = CreateTask(sub_8172AB0, 5);
    gTasks[taskId].data[15] = ballId;
    gTasks[taskId].data[3] = battler;
    gTasks[taskId].data[10] = selectedPalettes;
    gTasks[taskId].data[11] = selectedPalettes >> 16;

    if (!unfadeLater)
    {
        BlendPalette(battler * 16 + 0x100, 16, 0, gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[1] = 1;
    }
    else
    {
        BlendPalette(battler * 16 + 0x100, 16, 16, gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[0] = 16;
        gTasks[taskId].data[1] = -1;
        gTasks[taskId].func = sub_8172B40;
    }

    BeginNormalPaletteFade(selectedPalettes, 0, 0, 16, RGB(31, 31, 31));
    return taskId;
}

static void sub_8172AB0(u8 taskId)
{
    u8 ballId = gTasks[taskId].data[15];

    if (gTasks[taskId].data[2] <= 16)
    {
        BlendPalette(gTasks[taskId].data[3] * 16 + 0x100, 16, gTasks[taskId].data[0], gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[0] += gTasks[taskId].data[1];
        gTasks[taskId].data[2]++;
    }
    else if (!gPaletteFade.active)
    {
        u32 selectedPalettes = (u16)gTasks[taskId].data[10] | ((u16)gTasks[taskId].data[11] << 16);
        BeginNormalPaletteFade(selectedPalettes, 0, 16, 0, RGB(31, 31, 31));
        DestroyTask(taskId);
    }
}

static void sub_8172B40(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u32 selectedPalettes = (u16)gTasks[taskId].data[10] | ((u16)gTasks[taskId].data[11] << 16);
        BeginNormalPaletteFade(selectedPalettes, 0, 16, 0, RGB(31, 31, 31));
        gTasks[taskId].func = sub_8172B90;
    }
}

static void sub_8172B90(u8 taskId)
{
    u8 ballId = gTasks[taskId].data[15];

    if (gTasks[taskId].data[2] <= 16)
    {
        BlendPalette(gTasks[taskId].data[3] * 16 + 0x100, 16, gTasks[taskId].data[0], gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[0] += gTasks[taskId].data[1];
        gTasks[taskId].data[2]++;
    }
    else
    {
        DestroyTask(taskId);
    }
}

void sub_8172BF0(u8 taskId)
{
    u8 spriteId;
    u32 x;
    u32 done = FALSE;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    switch (gTasks[taskId].data[10])
    {
    case 0:
        gTasks[taskId].data[11] = gBattleAnimArgs[0];
        gTasks[taskId].data[0] += 0x500;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gSprites[spriteId].pos2.x += gTasks[taskId].data[0] >> 8;
        else
            gSprites[spriteId].pos2.x -= gTasks[taskId].data[0] >> 8;

        gTasks[taskId].data[0] &= 0xFF;
        x = gSprites[spriteId].pos1.x + gSprites[spriteId].pos2.x + 32;
        if (x > 304)
            gTasks[taskId].data[10]++;
        break;
    case 1:
        LoadBattleMonGfxAndAnimate(gBattleAnimAttacker, gTasks[taskId].data[11], spriteId);
        gTasks[taskId].data[10]++;
        break;
    case 2:
        gTasks[taskId].data[0] += 0x500;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gSprites[spriteId].pos2.x -= gTasks[taskId].data[0] >> 8;
        else
            gSprites[spriteId].pos2.x += gTasks[taskId].data[0] >> 8;

        gTasks[taskId].data[0] &= 0xFF;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            if (gSprites[spriteId].pos2.x <= 0)
            {
                gSprites[spriteId].pos2.x = 0;
                done = TRUE;
            }
        }
        else
        {
            if (gSprites[spriteId].pos2.x >= 0)
            {
                gSprites[spriteId].pos2.x = 0;
                done = TRUE;
            }
        }

        if (done)
            DestroyAnimVisualTask(taskId);

        break;
    }
}

void sub_8172D98(u8 taskId)
{
    u8 spriteId;

    switch (gTasks[taskId].data[15])
    {
    case 0:
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == B_POSITION_OPPONENT_LEFT)
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        else
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        gTasks[taskId].data[15]++;
        break;
    case 1:
        if (gTasks[taskId].data[1]++ > 1)
        {
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - gTasks[taskId].data[0], gTasks[taskId].data[0]));
            if (gTasks[taskId].data[0] == 16)
                gTasks[taskId].data[15]++;
        }
        break;
    case 2:
        spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
        RequestDma3Fill(0, (void *)OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * TILE_SIZE_4BPP, 0x800, 1);
        ClearBehindSubstituteBit(gBattleAnimAttacker);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_IsAttackerBehindSubstitute(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].behindSubstitute;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_TargetToEffectBattler(u8 taskId)
{
    gBattleAnimTarget = gEffectBattler;
    DestroyAnimVisualTask(taskId);
}

void sub_8172EF0(u8 battler, struct Pokemon *mon)
{
    int isShiny;
    u32 otId, personality;
    u32 shinyValue;
    u8 taskId1, taskId2;

    isShiny = 0;
    gBattleSpritesDataPtr->healthBoxesData[battler].flag_x80 = 1;
    otId = GetMonData(mon, MON_DATA_OT_ID);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (IsBattlerSpriteVisible(battler))
    {
        shinyValue = HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality);
        if (shinyValue < 8)
            isShiny = TRUE;

        if (isShiny)
        {
            if (GetSpriteTileStartByTag(ANIM_TAG_GOLD_STARS) == 0xFFFF)
            {
                LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[ANIM_TAG_GOLD_STARS - ANIM_SPRITES_START]);
                LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[ANIM_TAG_GOLD_STARS - ANIM_SPRITES_START]);
            }

            taskId1 = CreateTask(sub_8172FEC, 10);
            taskId2 = CreateTask(sub_8172FEC, 10);
            gTasks[taskId1].data[0] = battler;
            gTasks[taskId2].data[0] = battler;
            gTasks[taskId1].data[1] = 0;
            gTasks[taskId2].data[1] = 1;
            return;
        }
    }

    gBattleSpritesDataPtr->healthBoxesData[battler].field_1_x1 = 1;
}

static void sub_8172FEC(u8 taskId)
{
    u8 battler;
    u8 x, y;
    u8 spriteId;
    u16 counter;
    s16 state;
    u8 pan;

    if (gTasks[taskId].data[13] < 60)
    {
        gTasks[taskId].data[13]++;
        return;
    }

    if (gBattleSpritesDataPtr->animationData->field_A)
        return;

    counter = gTasks[taskId].data[10]++;
    if (counter & 3)
        return;

    battler = gTasks[taskId].data[0];
    x = GetBattlerSpriteCoord(battler, 0);
    y = GetBattlerSpriteCoord(battler, 1);
    state = gTasks[taskId].data[11];
    if (state == 0)
    {
        spriteId = CreateSprite(&gUnknown_085CE388, x, y, 5);
    }
    else if (state >= 0 && gTasks[taskId].data[11] < 4)
    {
        spriteId = CreateSprite(&gMiniTwinklingStarSpriteTemplate, x, y, 5);
        gSprites[spriteId].oam.tileNum += 4;
    }
    else
    {
        spriteId = CreateSprite(&gMiniTwinklingStarSpriteTemplate, x, y, 5);
        gSprites[spriteId].oam.tileNum += 5;
    }

    if (gTasks[taskId].data[1] == 0)
    {
        gSprites[spriteId].callback = sub_81731FC;
    }
    else
    {
        gSprites[spriteId].callback = sub_8173250;
        gSprites[spriteId].pos2.x = -32;
        gSprites[spriteId].pos2.y = 32;
        gSprites[spriteId].invisible = 1;
        if (gTasks[taskId].data[11] == 0)
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                pan = -64;
            else
                pan = 63;

            PlaySE12WithPanning(SE_REAPOKE, pan);
        }
    }

    gSprites[spriteId].data[0] = taskId;
    gTasks[taskId].data[11]++;
    if (spriteId != MAX_SPRITES)
        gTasks[taskId].data[12]++;

    if (gTasks[taskId].data[11] == 5)
        gTasks[taskId].func = sub_81731B0;
}

static void sub_81731B0(u8 taskId)
{
    u8 battler;

    if (gTasks[taskId].data[12] == 0)
    {
        if (gTasks[taskId].data[1] == 1)
        {
            battler = gTasks[taskId].data[0];
            gBattleSpritesDataPtr->healthBoxesData[battler].field_1_x1 = 1;
        }

        DestroyTask(taskId);
    }
}

static void sub_81731FC(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[1], 24);
    sprite->pos2.y = Cos(sprite->data[1], 24);
    sprite->data[1] += 12;
    if (sprite->data[1] > 0xFF)
    {
        gTasks[sprite->data[0]].data[12]--;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

static void sub_8173250(struct Sprite *sprite)
{
    if (sprite->data[1] < 4)
    {
        sprite->data[1]++;
    }
    else
    {
        sprite->invisible = 0;
        sprite->pos2.x += 5;
        sprite->pos2.y -= 5;
        if (sprite->pos2.x > 32)
        {
            gTasks[sprite->data[0]].data[12]--;
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
    }
}

void AnimTask_LoadPokeblockGfx(u8 taskId)
{
    u8 paletteIndex;

    LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[ANIM_TAG_POKEBLOCK - ANIM_SPRITES_START]);
    LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[ANIM_TAG_POKEBLOCK - ANIM_SPRITES_START]);
    paletteIndex = IndexOfSpritePaletteTag(ANIM_TAG_POKEBLOCK); // unused
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FreePokeblockGfx(u8 taskId)
{
    FreeSpriteTilesByTag(ANIM_TAG_POKEBLOCK);
    FreeSpritePaletteByTag(ANIM_TAG_POKEBLOCK);
    DestroyAnimVisualTask(taskId);
}

static void sub_817330C(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, 0);
    sprite->data[0] = 30;
    sprite->data[2] = GetBattlerSpriteCoord(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), 0) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), 1) + gBattleAnimArgs[3];
    sprite->data[5] = -32;
    InitAnimArcTranslation(sprite);
    gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].callback = sub_8039E84;
    sprite->callback = sub_817339C;
}

static void sub_817339C(struct Sprite *sprite)
{
    if (gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].animCmdIndex == 1)
        sprite->callback = sub_81733D4;
}

static void sub_81733D4(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->data[0] = 0;
        sprite->invisible = 1;
        sprite->callback = sub_8173400;
    }
}

static void sub_8173400(struct Sprite *sprite)
{
    if (gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].animEnded)
    {
        if (++sprite->data[0] > 0)
        {
            StartSpriteAnim(&gSprites[gBattlerSpriteIds[gBattleAnimAttacker]], 0);
            DestroyAnimSprite(sprite);
        }
    }
}

void sub_817345C(u8 taskId)
{
    switch (gBattleAnimArgs[0])
    {
    case 0:
        gBattleAnimAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        gBattleAnimTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        break;
    case 1:
        gBattleAnimAttacker = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        gBattleAnimTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        break;
    }

    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetTrappedMoveAnimId(u8 taskId)
{
    if (gBattleSpritesDataPtr->animationData->animArg == MOVE_FIRE_SPIN)
        gBattleAnimArgs[0] = TRAP_ANIM_FIRE_SPIN;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_WHIRLPOOL)
        gBattleAnimArgs[0] = TRAP_ANIM_WHIRLPOOL;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_CLAMP)
        gBattleAnimArgs[0] = TRAP_ANIM_CLAMP;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_SAND_TOMB)
        gBattleAnimArgs[0] = TRAP_ANIM_SAND_TOMB;
    else
        gBattleAnimArgs[0] = TRAP_ANIM_BIND;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetBattlersFromArg(u8 taskId)
{
    gBattleAnimAttacker = gBattleSpritesDataPtr->animationData->animArg;
    gBattleAnimTarget = gBattleSpritesDataPtr->animationData->animArg >> 8;
    DestroyAnimVisualTask(taskId);
}
