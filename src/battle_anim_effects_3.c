#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "contest.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/weather.h"

extern const struct SpriteTemplate gThoughtBubbleSpriteTemplate;

static void AnimBlackSmoke(struct Sprite *);
static void AnimBlackSmoke_Step(struct Sprite *);
static void AnimWhiteHalo(struct Sprite *);
static void AnimWhiteHalo_Step1(struct Sprite *);
static void AnimWhiteHalo_Step2(struct Sprite *);
static void AnimTealAlert(struct Sprite *);
static void AnimMeanLookEye(struct Sprite *);
static void AnimMeanLookEye_Step1(struct Sprite *);
static void AnimMeanLookEye_Step2(struct Sprite *);
static void AnimMeanLookEye_Step3(struct Sprite *);
static void AnimMeanLookEye_Step4(struct Sprite *);
static void AnimSpikes(struct Sprite *);
static void AnimSpikes_Step1(struct Sprite *);
static void AnimSpikes_Step2(struct Sprite *);
static void AnimLeer(struct Sprite *);
static void AnimLetterZ(struct Sprite *);
static void AnimFang(struct Sprite *);
static void AnimSpotlight(struct Sprite *);
static void AnimSpotlight_Step1(struct Sprite *);
static void AnimSpotlight_Step2(struct Sprite *);
static void AnimClappingHand(struct Sprite *);
static void AnimClappingHand_Step(struct Sprite *);
static void AnimClappingHand2(struct Sprite *);
static void AnimRapidSpin(struct Sprite *);
static void AnimRapidSpin_Step(struct Sprite *);
static void AnimTriAttackTriangle(struct Sprite *);
static void AnimBatonPassPokeball(struct Sprite *);
static void AnimWishStar(struct Sprite *);
static void AnimWishStar_Step(struct Sprite *);
static void AnimMiniTwinklingStar(struct Sprite *);
static void AnimMiniTwinklingStar_Step(struct Sprite *);
static void AnimSwallowBlueOrb(struct Sprite *);
static void AnimGreenStar(struct Sprite *);
static void AnimGreenStar_Step1(struct Sprite *);
static void AnimGreenStar_Step2(struct Sprite *);
static void AnimGreenStar_Callback(struct Sprite *);
static void AnimWeakFrustrationAngerMark(struct Sprite *);
static void AnimSweetScentPetal(struct Sprite *);
static void AnimSweetScentPetal_Step(struct Sprite *);
static void AnimPainSplitProjectile(struct Sprite *);
static void AnimFlatterConfetti(struct Sprite *);
static void AnimFlatterConfetti_Step(struct Sprite *);
static void AnimFlatterSpotlight(struct Sprite *);
static void AnimFlatterSpotlight_Step(struct Sprite *);
static void AnimReversalOrb(struct Sprite *);
static void AnimReversalOrb_Step(struct Sprite *);
static void AnimYawnCloud(struct Sprite *);
static void AnimYawnCloud_Step(struct Sprite *);
static void AnimSmokeBallEscapeCloud(struct Sprite *);
static void AnimFacadeSweatDrop(struct Sprite *);
static void AnimRoarNoiseLine(struct Sprite *);
static void AnimRoarNoiseLine_Step(struct Sprite *);
static void AnimGlareEyeDot(struct Sprite *);
static void AnimAssistPawprint(struct Sprite *);
static void AnimSmellingSaltsHand(struct Sprite *);
static void AnimSmellingSaltsHand_Step(struct Sprite *);
static void AnimSmellingSaltExclamation(struct Sprite *);
static void AnimSmellingSaltExclamation_Step(struct Sprite *);
static void AnimHelpingHandClap(struct Sprite *);
static void AnimHelpingHandClap_Step(struct Sprite *);
static void AnimForesightMagnifyingGlass(struct Sprite *);
static void AnimForesightMagnifyingGlass_Step(struct Sprite *);
static void AnimMeteorMashStar(struct Sprite *);
static void AnimMeteorMashStar_Step(struct Sprite *sprite);
static void AnimBlockX(struct Sprite *);
static void AnimBlockX_Step(struct Sprite *);
static void AnimUnusedItemBagSteal(struct Sprite *);
static void AnimKnockOffStrike(struct Sprite *);
static void AnimKnockOffStrike_Step(struct Sprite *sprite);
static void AnimRecycle(struct Sprite *);
static void AnimRecycle_Step(struct Sprite *);
static void SetPsychicBackground_Step(u8);
static void FadeScreenToWhite_Step(u8);
static void RapinSpinMonElevation_Step(u8);
static void TormentAttacker_Step(u8);
static void TormentAttacker_Callback(struct Sprite *);
static void AnimTask_RockMonBackAndForth_Step(u8);
static void AnimTask_FlailMovement_Step(u8);
static void AnimTask_RolePlaySilhouette_Step1(u8);
static void AnimTask_RolePlaySilhouette_Step2(u8);
static void AnimTask_AcidArmor_Step(u8);
static void AnimTask_DeepInhale_Step(u8);
static void AnimTask_SquishAndSweatDroplets_Step(u8);
static void CreateSweatDroplets(u8, bool8);
static void AnimTask_FacadeColorBlend_Step(u8);
static void AnimTask_GlareEyeDots_Step(u8);
static void GetGlareEyeDotCoords(s16, s16, s16, s16, u8, u8, s16 *, s16 *);
static void AnimTask_BarrageBall_Step(u8);
static void AnimTask_SmellingSaltsSquish_Step(u8);
static void AnimTask_HelpingHandAttackerMovement_Step(u8);
static void AnimTask_MonToSubstituteDoll(u8);
static void AnimTask_OdorSleuthMovementWaitFinish(u8);
static void MoveOdorSleuthClone(struct Sprite *);
static void AnimTask_TeeterDanceMovement_Step(u8);
static void AnimTask_SlackOffSquish_Step(u8);

const union AnimCmd gScratchAnimCmds[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gScratchAnimTable[] =
{
    gScratchAnimCmds,
};

const struct SpriteTemplate gScratchSpriteTemplate =
{
    .tileTag = ANIM_TAG_SCRATCH,
    .paletteTag = ANIM_TAG_SCRATCH,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gScratchAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gBlackSmokeSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLACK_SMOKE,
    .paletteTag = ANIM_TAG_BLACK_SMOKE,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlackSmoke,
};

const struct SpriteTemplate gBlackBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLACK_BALL,
    .paletteTag = ANIM_TAG_BLACK_BALL,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimThrowProjectile,
};

const union AnimCmd gOpeningEyeAnimCmds[] =
{
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(32, 40),
    ANIMCMD_END,
};

const union AnimCmd *const gOpeningEyeAnimTable[] =
{
    gOpeningEyeAnimCmds,
};

const struct SpriteTemplate gOpeningEyeSpriteTemplate =
{
    .tileTag = ANIM_TAG_OPENING_EYE,
    .paletteTag = ANIM_TAG_OPENING_EYE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gOpeningEyeAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const struct SpriteTemplate gWhiteHaloSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROUND_WHITE_HALO,
    .paletteTag = ANIM_TAG_ROUND_WHITE_HALO,
    .oam = &gOamData_AffineOff_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWhiteHalo,
};

const struct SpriteTemplate gTealAlertSpriteTemplate =
{
    .tileTag = ANIM_TAG_TEAL_ALERT,
    .paletteTag = ANIM_TAG_TEAL_ALERT,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimTealAlert,
};

const union AffineAnimCmd gMeanLookEyeAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x180, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(-0x20, 0x18, 0, 5),
    AFFINEANIMCMD_FRAME(0x18, -0x20, 0, 5),
    AFFINEANIMCMD_JUMP(1),
};

const union AffineAnimCmd gMeanLookEyeAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x30, 0x30, 0, 0),
    AFFINEANIMCMD_FRAME(0x20, 0x20, 0, 6),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gMeanLookEyeAffineAnimTable[] =
{
    gMeanLookEyeAffineAnimCmds1,
    gMeanLookEyeAffineAnimCmds2,
};

const struct SpriteTemplate gMeanLookEyeSpriteTemplate =
{
    .tileTag = ANIM_TAG_EYE,
    .paletteTag = ANIM_TAG_EYE,
    .oam = &gOamData_AffineDouble_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gMeanLookEyeAffineAnimTable,
    .callback = AnimMeanLookEye,
};

const struct SpriteTemplate gSpikesSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPIKES,
    .paletteTag = ANIM_TAG_SPIKES,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpikes,
};

const union AnimCmd gLeerAnimCmds[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gLeerAnimTable[] =
{
    gLeerAnimCmds,
};

const struct SpriteTemplate gLeerSpriteTemplate =
{
    .tileTag = ANIM_TAG_LEER,
    .paletteTag = ANIM_TAG_LEER,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gLeerAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimLeer,
};

const union AnimCmd gLetterZAnimCmds[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gLetterZAnimTable[] =
{
    gLetterZAnimCmds,
};

const union AffineAnimCmd gLetterZAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(-7, -7, -3, 16),
    AFFINEANIMCMD_FRAME(7, 7, 3, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gLetterZAffineAnimTable[] =
{
    gLetterZAffineAnimCmds,
};

const struct SpriteTemplate gLetterZSpriteTemplate =
{
    .tileTag = ANIM_TAG_LETTER_Z,
    .paletteTag = ANIM_TAG_LETTER_Z,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gLetterZAnimTable,
    .images = NULL,
    .affineAnims = gLetterZAffineAnimTable,
    .callback = AnimLetterZ,
};

const union AnimCmd gFangAnimCmds[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 16),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gFangAnimTable[] =
{
    gFangAnimCmds,
};

const union AffineAnimCmd gFangAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_FRAME(-0x20, -0x20, 0, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gFangAffineAnimTable[] =
{
    gFangAffineAnimCmds,
};

const struct SpriteTemplate gFangSpriteTemplate =
{
    .tileTag = ANIM_TAG_FANG_ATTACK,
    .paletteTag = ANIM_TAG_FANG_ATTACK,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gFangAnimTable,
    .images = NULL,
    .affineAnims = gFangAffineAnimTable,
    .callback = AnimFang,
};

const union AffineAnimCmd gSpotlightAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x0, 0, 20),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSpotlightAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x140, 0x180, 0, 0),
    AFFINEANIMCMD_FRAME(-0x10, 0x0, 0, 19),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gSpotlightAffineAnimTable[] =
{
    gSpotlightAffineAnimCmds1,
    gSpotlightAffineAnimCmds2,
};

const struct SpriteTemplate gSpotlightSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpotlightAffineAnimTable,
    .callback = AnimSpotlight,
};

const struct SpriteTemplate gClappingHandSpriteTemplate =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimClappingHand,
};

const struct SpriteTemplate gClappingHand2SpriteTemplate =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimClappingHand2,
};

const union AnimCmd gRapidSpinAnimCmds[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gRapidSpinAnimTable[] =
{
    gRapidSpinAnimCmds,
};

const struct SpriteTemplate gRapidSpinSpriteTemplate =
{
    .tileTag = ANIM_TAG_RAPID_SPIN,
    .paletteTag = ANIM_TAG_RAPID_SPIN,
    .oam = &gOamData_AffineOff_ObjNormal_32x16,
    .anims = gRapidSpinAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRapidSpin,
};

static const union AffineAnimCmd sAffineAnims_Torment[] =
{
    AFFINEANIMCMD_FRAME(-12, 8, 0, 4),
    AFFINEANIMCMD_FRAME(20, -20, 0, 4),
    AFFINEANIMCMD_FRAME(-8, 12, 0, 4),
    AFFINEANIMCMD_END,
};

const union AnimCmd gTriAttackTriangleAnimCmds[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd *const gTriAttackTriangleAnimTable[] =
{
    gTriAttackTriangleAnimCmds,
};

const union AffineAnimCmd gTriAttackTriangleAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 5, 40),
    AFFINEANIMCMD_FRAME(0, 0, 10, 10),
    AFFINEANIMCMD_FRAME(0, 0, 15, 10),
    AFFINEANIMCMD_FRAME(0, 0, 20, 40),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gTriAttackTriangleAffineAnimTable[] =
{
    gTriAttackTriangleAffineAnimCmds,
};

const struct SpriteTemplate gTriAttackTriangleSpriteTemplate =
{
    .tileTag = ANIM_TAG_TRI_ATTACK_TRIANGLE,
    .paletteTag = ANIM_TAG_TRI_ATTACK_TRIANGLE,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gTriAttackTriangleAnimTable,
    .images = NULL,
    .affineAnims = gTriAttackTriangleAffineAnimTable,
    .callback = AnimTriAttackTriangle,
};

const union AnimCmd gEclipsingOrbAnimCmds[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_FRAME(32, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_END,
};

const union AnimCmd *const gEclipsingOrbAnimTable[] =
{
    gEclipsingOrbAnimCmds,
};

const struct SpriteTemplate gEclipsingOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_ECLIPSING_ORB,
    .paletteTag = ANIM_TAG_ECLIPSING_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gEclipsingOrbAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSpriteOnMonPos,
};

const union AffineAnimCmd DefenseCurlDeformMonAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(-12, 20, 0, 8),
    AFFINEANIMCMD_FRAME(12, -20, 0, 8),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gBatonPassPokeballSpriteTemplate =
{
    .tileTag = ANIM_TAG_POKEBALL,
    .paletteTag = ANIM_TAG_POKEBALL,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBatonPassPokeball,
};

const struct SpriteTemplate gWishStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWishStar,
};

const struct SpriteTemplate gMiniTwinklingStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMiniTwinklingStar,
};

const union AffineAnimCmd gStockpileDeformMonAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(8, -8, 0, 12),
    AFFINEANIMCMD_FRAME(-16, 16, 0, 12),
    AFFINEANIMCMD_FRAME(8, -8, 0, 12),
    AFFINEANIMCMD_LOOP(1),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gSpitUpDeformMonAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 6, 0, 20),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(0, -18, 0, 6),
    AFFINEANIMCMD_FRAME(-18, -18, 0, 3),
    AFFINEANIMCMD_FRAME(0, 0, 0, 15),
    AFFINEANIMCMD_FRAME(4, 4, 0, 13),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gSwallowBlueOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLUE_ORB,
    .paletteTag = ANIM_TAG_BLUE_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSwallowBlueOrb,
};

const union AffineAnimCmd gSwallowDeformMonAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 6, 0, 20),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(7, -30, 0, 6),
    AFFINEANIMCMD_FRAME(0, 0, 0, 20),
    AFFINEANIMCMD_FRAME(-2, 3, 0, 20),
    AFFINEANIMCMD_END,
};

const s8 gMorningSunLightBeamCoordsTable[] =
{
    0xE8,
    0x18,
    0xFC,
    0x00,
};

const union AnimCmd gGreenStarAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gGreenStarAnimCmds2[] =
{
    ANIMCMD_FRAME(8, 6),
    ANIMCMD_END,
};

const union AnimCmd gGreenStarAnimCmds3[] =
{
    ANIMCMD_FRAME(12, 6),
    ANIMCMD_END,
};

const union AnimCmd *const gGreenStarAnimTable[] =
{
    gGreenStarAnimCmds1,
    gGreenStarAnimCmds2,
    gGreenStarAnimCmds3,
};

const struct SpriteTemplate gGreenStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_GREEN_STAR,
    .paletteTag = ANIM_TAG_GREEN_STAR,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gGreenStarAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGreenStar,
};

const s8 gDoomDesireLightBeamCoordTable[] =
{
    0x78,
    0x50,
    0x28,
    0x00,
};

const u8 gDoomDesireLightBeamDelayTable[] =
{
    0,
    0,
    0,
    0,
    50,
};

const union AffineAnimCmd gStrongFrustrationAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, -15, 0, 7),
    AFFINEANIMCMD_FRAME(0, 15, 0, 7),
    AFFINEANIMCMD_LOOP(2),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gWeakFrustrationAngerMarkSpriteTemplate =
{
    .tileTag = ANIM_TAG_ANGER,
    .paletteTag = ANIM_TAG_ANGER,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimWeakFrustrationAngerMark,
};

const union AnimCmd gSweetScentPetalAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(3, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .vFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .vFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gSweetScentPetalAnimCmds2[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gSweetScentPetalAnimCmds3[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd *const gSweetScentPetalAnimCmdTable[] =
{
    gSweetScentPetalAnimCmds1,
    gSweetScentPetalAnimCmds2,
    gSweetScentPetalAnimCmds3,
};

const struct SpriteTemplate gSweetScentPetalSpriteTemplate =
{
    .tileTag = ANIM_TAG_PINK_PETAL,
    .paletteTag = ANIM_TAG_PINK_PETAL,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gSweetScentPetalAnimCmdTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSweetScentPetal,
};

static const u16 sUnusedPalette[] = INCBIN_U16("graphics/battle_anims/unused/unknown.gbapal");

const union AnimCmd gPainSplitAnimCmds[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 9),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

const union AnimCmd *const gPainSplitAnimCmdTable[] =
{
    gPainSplitAnimCmds,
};

const struct SpriteTemplate gPainSplitProjectileSpriteTemplate =
{
    .tileTag = ANIM_TAG_PAIN_SPLIT,
    .paletteTag = ANIM_TAG_PAIN_SPLIT,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gPainSplitAnimCmdTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimPainSplitProjectile,
};

const struct SpriteTemplate gFlatterConfettiSpriteTemplate =
{
    .tileTag = ANIM_TAG_CONFETTI,
    .paletteTag = ANIM_TAG_CONFETTI,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFlatterConfetti,
};

const struct SpriteTemplate gFlatterSpotlightSpriteTemplate =
{
    .tileTag = ANIM_TAG_SPOTLIGHT,
    .paletteTag = ANIM_TAG_SPOTLIGHT,
    .oam = &gOamData_AffineDouble_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSpotlightAffineAnimTable,
    .callback = AnimFlatterSpotlight,
};

const struct SpriteTemplate gReversalOrbSpriteTemplate =
{
    .tileTag = ANIM_TAG_BLUE_ORB,
    .paletteTag = ANIM_TAG_BLUE_ORB,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimReversalOrb,
};

const union AffineAnimCmd gDeepInhaleAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(16, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, -3, 0, 16),
    AFFINEANIMCMD_FRAME(4, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(-5, 3, 0, 16),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gYawnCloudAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gYawnCloudAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gYawnCloudAffineAnimCmds3[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_FRAME(-8, -8, 0, 8),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gYawnCloudAffineAnimTable[] =
{
    gYawnCloudAffineAnimCmds1,
    gYawnCloudAffineAnimCmds2,
    gYawnCloudAffineAnimCmds3,
};

const struct SpriteTemplate gYawnCloudSpriteTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gYawnCloudAffineAnimTable,
    .callback = AnimYawnCloud,
};

const union AffineAnimCmd gSmokeBallEscapeCloudAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gSmokeBallEscapeCloudAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0xC0, 0xC0, 0, 0),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gSmokeBallEscapeCloudAffineAnimCmds3[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(4, 6, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -6, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gSmokeBallEscapeCloudAffineAnimCmds4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(8, 10, 0, 30),
    AFFINEANIMCMD_FRAME(-8, -10, 0, 16),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gSmokeBallEscapeCloudAffineAnimTable[] =
{
    gSmokeBallEscapeCloudAffineAnimCmds1,
    gSmokeBallEscapeCloudAffineAnimCmds2,
    gSmokeBallEscapeCloudAffineAnimCmds3,
    gSmokeBallEscapeCloudAffineAnimCmds4,
};

const struct SpriteTemplate gSmokeBallEscapeCloudSpriteTemplate =
{
    .tileTag = ANIM_TAG_PINK_CLOUD,
    .paletteTag = ANIM_TAG_PINK_CLOUD,
    .oam = &gOamData_AffineDouble_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gSmokeBallEscapeCloudAffineAnimTable,
    .callback = AnimSmokeBallEscapeCloud,
};

const union AffineAnimCmd gFacadeSquishAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(-16, 16, 0, 6),
    AFFINEANIMCMD_FRAME(16, -16, 0, 12),
    AFFINEANIMCMD_FRAME(-16, 16, 0, 6),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gFacadeSweatDropSpriteTemplate =
{
    .tileTag = ANIM_TAG_SWEAT_DROP,
    .paletteTag = ANIM_TAG_SWEAT_DROP,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimFacadeSweatDrop,
};

const u16 gFacadeBlendColors[] = {
    RGB(28, 25,  1),
    RGB(28, 21,  5),
    RGB(27, 18,  8),
    RGB(27, 14, 11),
    RGB(26, 10, 15),
    RGB(26,  7, 18),
    RGB(25,  3, 21),
    RGB(25,  0, 25),
    RGB(25,  0, 23),
    RGB(25,  0, 20),
    RGB(25,  0, 16),
    RGB(25,  0, 13),
    RGB(26,  0, 10),
    RGB(26,  0,  6),
    RGB(26,  0,  3),
    RGB(27,  0,  0),
    RGB(27,  1,  0),
    RGB(27,  5,  0),
    RGB(27,  9,  0),
    RGB(27, 12,  0),
    RGB(28, 16,  0),
    RGB(28, 19,  0),
    RGB(28, 23,  0),
    RGB(29, 27,  0),
};

const union AnimCmd gRoarNoiseLineAnimCmds1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gRoarNoiseLineAnimCmds2[] =
{
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(48, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gRoarNoiseLineAnimTable[] =
{
    gRoarNoiseLineAnimCmds1,
    gRoarNoiseLineAnimCmds2,
};

const struct SpriteTemplate gRoarNoiseLineSpriteTemplate =
{
    .tileTag = ANIM_TAG_NOISE_LINE,
    .paletteTag = ANIM_TAG_NOISE_LINE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gRoarNoiseLineAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimRoarNoiseLine,
};

const struct SpriteTemplate gGlareEyeDotSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMALL_RED_EYE,
    .paletteTag = ANIM_TAG_SMALL_RED_EYE,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimGlareEyeDot,
};

const struct SpriteTemplate gAssistPawprintSpriteTemplate =
{
    .tileTag = ANIM_TAG_PAW_PRINT,
    .paletteTag = ANIM_TAG_PAW_PRINT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimAssistPawprint,
};

const union AffineAnimCmd gBarrageBallAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gBarrageBallAffineAnimCmds2[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 24),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gBarrageBallAffineAnimTable[] =
{
    gBarrageBallAffineAnimCmds1,
    gBarrageBallAffineAnimCmds2,
};

const struct SpriteTemplate gBarrageBallSpriteTemplate =
{
    .tileTag = ANIM_TAG_RED_BALL,
    .paletteTag = ANIM_TAG_RED_BALL,
    .oam = &gOamData_AffineNormal_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gBarrageBallAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate gSmellingSaltsHandSpriteTemplate =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmellingSaltsHand,
};

const union AffineAnimCmd gSmellingSaltsSquishAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, -16, 0, 6),
    AFFINEANIMCMD_FRAME(0, 16, 0, 6),
    AFFINEANIMCMD_END,
};

const struct SpriteTemplate gSmellingSaltExclamationSpriteTemplate =
{
    .tileTag = ANIM_TAG_SMELLINGSALT_EFFECT,
    .paletteTag = ANIM_TAG_SMELLINGSALT_EFFECT,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimSmellingSaltExclamation,
};

const struct SpriteTemplate gHelpingHandClapSpriteTemplate =
{
    .tileTag = ANIM_TAG_TAG_HAND,
    .paletteTag = ANIM_TAG_TAG_HAND,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimHelpingHandClap,
};

const struct SpriteTemplate gForesightMagnifyingGlassSpriteTemplate =
{
    .tileTag = ANIM_TAG_MAGNIFYING_GLASS,
    .paletteTag = ANIM_TAG_MAGNIFYING_GLASS,
    .oam = &gOamData_AffineOff_ObjBlend_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimForesightMagnifyingGlass,
};

const struct SpriteTemplate gMeteorMashStarSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimMeteorMashStar,
};

static const struct SpriteTemplate sUnusedStarBurstSpriteTemplate =
{
    .tileTag = ANIM_TAG_GOLD_STARS,
    .paletteTag = ANIM_TAG_GOLD_STARS,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimParticleBurst,
};

const struct SpriteTemplate gBlockXSpriteTemplate =
{
    .tileTag = ANIM_TAG_X_SIGN,
    .paletteTag = ANIM_TAG_X_SIGN,
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimBlockX,
};

static const struct SpriteTemplate sUnusedItemBagStealSpriteTemplate =
{
    .tileTag = ANIM_TAG_ITEM_BAG,
    .paletteTag = ANIM_TAG_ITEM_BAG,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = AnimUnusedItemBagSteal,
};

const union AnimCmd gKnockOffStrikeAnimCmds[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

const union AnimCmd *const gKnockOffStrikeAnimTable[] =
{
    gKnockOffStrikeAnimCmds,
};

const union AffineAnimCmd gKnockOffStrikeAffineanimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gKnockOffStrikeAffineanimCmds2[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 4, 8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gKnockOffStrikeAffineAnimTable[] =
{
    gKnockOffStrikeAffineanimCmds1,
    gKnockOffStrikeAffineanimCmds2,
};

const struct SpriteTemplate gKnockOffStrikeSpriteTemplate =
{
    .tileTag = ANIM_TAG_SLAM_HIT_2,
    .paletteTag = ANIM_TAG_SLAM_HIT_2,
    .oam = &gOamData_AffineNormal_ObjNormal_64x64,
    .anims = gKnockOffStrikeAnimTable,
    .images = NULL,
    .affineAnims = gKnockOffStrikeAffineAnimTable,
    .callback = AnimKnockOffStrike,
};

const union AffineAnimCmd gRecycleSpriteAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -4, 64),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd *const gRecycleSpriteAffineAnimTable[] =
{
    gRecycleSpriteAffineAnimCmds,
};

const struct SpriteTemplate gRecycleSpriteTemplate =
{
    .tileTag = ANIM_TAG_RECYCLE,
    .paletteTag = ANIM_TAG_RECYCLE,
    .oam = &gOamData_AffineNormal_ObjBlend_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gRecycleSpriteAffineAnimTable,
    .callback = AnimRecycle,
};

const union AffineAnimCmd gSlackOffSquishAffineAnimCmds[] =
{
    AFFINEANIMCMD_FRAME(0, 16, 0, 4),
    AFFINEANIMCMD_FRAME(-2, 0, 0, 8),
    AFFINEANIMCMD_FRAME(0, 4, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, 0, 24),
    AFFINEANIMCMD_FRAME(1, -5, 0, 16),
    AFFINEANIMCMD_END,
};

static void AnimBlackSmoke(struct Sprite *sprite)
{
    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];

    if (!gBattleAnimArgs[3])
        sprite->data[0] = gBattleAnimArgs[2];
    else
        sprite->data[0] = -gBattleAnimArgs[2];

    sprite->data[1] = gBattleAnimArgs[4];
    sprite->callback = AnimBlackSmoke_Step;
}

static void AnimBlackSmoke_Step(struct Sprite *sprite)
{
    if (sprite->data[1] > 0)
    {
        sprite->x2 = sprite->data[2] >> 8;
        sprite->data[2] += sprite->data[0];
        sprite->invisible ^= 1;
        sprite->data[1]--;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

void AnimTask_SmokescreenImpact(u8 taskId)
{
    SmokescreenImpact(
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + 8,
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + 8,
        FALSE);
    DestroyAnimVisualTask(taskId);
}

static void AnimWhiteHalo(struct Sprite *sprite)
{
    sprite->data[0] = 90;
    sprite->callback = WaitAnimForDuration;
    sprite->data[1] = 7;
    StoreSpriteCallbackInData6(sprite, AnimWhiteHalo_Step1);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[1], 16 - sprite->data[1]));
}

static void AnimWhiteHalo_Step1(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[1], 16 - sprite->data[1]));
    if (--sprite->data[1] < 0)
    {
        sprite->invisible = TRUE;
        sprite->callback = AnimWhiteHalo_Step2;
    }
}

static void AnimWhiteHalo_Step2(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

static void AnimTealAlert(struct Sprite *sprite)
{
    u16 rotation;
    u8 x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    u8 y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    InitSpritePosToAnimTarget(sprite, TRUE);

    rotation = ArcTan2Neg(sprite->x - x, sprite->y - y);
    rotation += 0x6000;
    if (IsContest())
        rotation += 0x4000;

    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = x;
    sprite->data[4] = y;
    sprite->callback = StartAnimLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimMeanLookEye(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    sprite->data[0] = 4;
    sprite->callback = AnimMeanLookEye_Step1;
}

static void AnimMeanLookEye_Step1(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[0], 16 - sprite->data[0]));

    if (sprite->data[1])
        sprite->data[0]--;
    else
        sprite->data[0]++;

    if (sprite->data[0] == 15 || sprite->data[0] == 4)
        sprite->data[1] ^= 1;

    if (sprite->data[2]++ > 70)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        StartSpriteAffineAnim(sprite, 1);
        sprite->data[2] = 0;
        sprite->invisible = TRUE;
        sprite->affineAnimPaused = 1;
        sprite->callback = AnimMeanLookEye_Step2;
    }
}

static void AnimMeanLookEye_Step2(struct Sprite *sprite)
{
    if (sprite->data[2]++ > 9)
    {
        sprite->invisible = FALSE;
        sprite->affineAnimPaused = 0;
        if (sprite->affineAnimEnded)
            sprite->callback = AnimMeanLookEye_Step3;
    }
}

static void AnimMeanLookEye_Step3(struct Sprite *sprite)
{
    switch (sprite->data[3])
    {
    case 0:
    case 1:
        sprite->x2 = 1;
        sprite->y2 = 0;
        break;
    case 2:
    case 3:
        sprite->x2 = -1;
        sprite->y2 = 0;
        break;
    case 4:
    case 5:
        sprite->x2 = 0;
        sprite->y2 = 1;
        break;
    case 6:
    default:
        sprite->x2 = 0;
        sprite->y2 = -1;
        break;
    }

    if (++sprite->data[3] > 7)
        sprite->data[3] = 0;

    if (sprite->data[4]++ > 15)
    {
        sprite->data[0] = 16;
        sprite->data[1] = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[0], 0));
        sprite->callback = AnimMeanLookEye_Step4;
    }
}

static void AnimMeanLookEye_Step4(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[0], 16 - sprite->data[0]));

    if (sprite->data[1]++ > 1)
    {
        sprite->data[0]--;
        sprite->data[1] = 0;
    }

    if (sprite->data[0] == 0)
        sprite->invisible = TRUE;

    if (sprite->data[0] < 0)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimSprite(sprite);
    }
}

void AnimTask_SetPsychicBackground(u8 taskId)
{
    gTasks[taskId].func = SetPsychicBackground_Step;
    gAnimVisualTaskCount--;
}

static void SetPsychicBackground_Step(u8 taskId)
{
    int i;
    u16 lastColor;
    u8 paletteIndex = GetBattleBgPaletteNum();

    if (++gTasks[taskId].data[5] == 4)
    {
        lastColor = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i + 1] = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i];

        gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 1] = lastColor;
        gTasks[taskId].data[5] = 0;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyTask(taskId);
}

void AnimTask_FadeScreenToWhite(u8 taskId)
{
    gTasks[taskId].func = FadeScreenToWhite_Step;
    gAnimVisualTaskCount--;
}

static void FadeScreenToWhite_Step(u8 taskId)
{
    int i;
    u16 lastColor;
    u8 paletteIndex = GetBattleBgPaletteNum();

    if (++gTasks[taskId].data[5] == 4)
    {
        lastColor = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i + 1] = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i];
        gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 1] = lastColor;

        lastColor = gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + i + 1] = gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + i];
        gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + 1] = lastColor;

        gTasks[taskId].data[5] = 0;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyTask(taskId);
}

static void AnimSpikes(struct Sprite *sprite)
{
    s16 x, y;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &x, &y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = x + gBattleAnimArgs[2];
    sprite->data[4] = y + gBattleAnimArgs[3];
    sprite->data[5] = -50;

    InitAnimArcTranslation(sprite);
    sprite->callback = AnimSpikes_Step1;
}

static void AnimSpikes_Step1(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->data[0] = 30;
        sprite->data[1] = 0;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimSpikes_Step2);
    }
}

static void AnimSpikes_Step2(struct Sprite *sprite)
{
    if (sprite->data[1] & 1)
        sprite->invisible ^= 1;

    if (++sprite->data[1] == 16)
        DestroyAnimSprite(sprite);
}

static void AnimLeer(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimLetterZ(struct Sprite *sprite)
{
    int var0;
    if (sprite->data[0] == 0)
    {
        SetSpriteCoordsToAnimAttackerCoords(sprite);
        SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
        if (!IsContest())
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            {
                sprite->data[1] = gBattleAnimArgs[2];
                sprite->data[2] = gBattleAnimArgs[3];
            }
            else
            {
                sprite->data[1] = -1 * gBattleAnimArgs[2];
                sprite->data[2] = -1 * gBattleAnimArgs[3];
            }
        }
        else
        {
            sprite->data[1] = -1 * gBattleAnimArgs[2];
            sprite->data[2] = gBattleAnimArgs[3];
        }
    }

    sprite->data[0]++;
    var0 = (sprite->data[0] * 20) & 0xFF;
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    sprite->x2 = sprite->data[3] / 2;
    sprite->y2 = Sin(var0 & 0xFF, 5) + (sprite->data[4] / 2);

    if ((u16)(sprite->x + sprite->x2) > DISPLAY_WIDTH)
        DestroyAnimSprite(sprite);
}

static void AnimFang(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

void AnimTask_IsTargetPlayerSide(u8 taskId)
{
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT)
        gBattleAnimArgs[ARG_RET_ID] = FALSE;
    else
        gBattleAnimArgs[ARG_RET_ID] = TRUE;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_IsHealingMove(u8 taskId)
{
    if (gAnimMoveDmg > 0)
        gBattleAnimArgs[ARG_RET_ID] = FALSE;
    else
        gBattleAnimArgs[ARG_RET_ID] = TRUE;

    DestroyAnimVisualTask(taskId);
}

static void AnimSpotlight(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);

    InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->invisible = TRUE;
    sprite->callback = AnimSpotlight_Step1;
}

static void AnimSpotlight_Step1(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->invisible = FALSE;
        if (sprite->affineAnimEnded)
            sprite->data[0]++;
        break;
    case 1:
    case 3:
        sprite->data[1] += 117;
        sprite->x2 = sprite->data[1] >> 8;
        if (++sprite->data[2] == 21)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[1] -= 117;
        sprite->x2 = sprite->data[1] >> 8;
        if (++sprite->data[2] == 41)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 4:
        ChangeSpriteAffineAnim(sprite, 1);
        sprite->data[0]++;
        break;
    case 5:
        if (sprite->affineAnimEnded)
        {
            sprite->invisible = TRUE;
            sprite->callback = AnimSpotlight_Step2;
        }
        break;
    }
}

static void AnimSpotlight_Step2(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
    DestroyAnimSprite(sprite);
}

static void AnimClappingHand(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    }

    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->oam.tileNum += 16;

    if (gBattleAnimArgs[2] == 0)
    {
        sprite->oam.matrixNum = ST_OAM_HFLIP;
        sprite->x2 = -12;
        sprite->data[1] = 2;
    }
    else
    {
        sprite->x2 = 12;
        sprite->data[1] = -2;
    }

    sprite->data[0] = gBattleAnimArgs[4];

    if (sprite->data[3] != 255)
        sprite->data[3] = gBattleAnimArgs[2];

    sprite->callback = AnimClappingHand_Step;
}

static void AnimClappingHand_Step(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->x2 += sprite->data[1];
        if (sprite->x2 == 0)
        {
            sprite->data[2]++;
            if (sprite->data[3] == 0)
            {
                PlaySE1WithPanning(SE_M_ENCORE, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
            }
        }
    }
    else
    {
        sprite->x2 -= sprite->data[1];
        if (abs(sprite->x2) == 12)
        {
            sprite->data[0]--;
            sprite->data[2]--;
        }

    }

    if (sprite->data[0] == 0)
        DestroyAnimSprite(sprite);
}

static void AnimClappingHand2(struct Sprite *sprite)
{
    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->data[3] = 255;
    AnimClappingHand(sprite);
}

void AnimTask_CreateSpotlight(u8 taskId)
{
    if (IsContest())
    {
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
        gBattle_WIN1H = WIN_RANGE(152, DISPLAY_WIDTH);
        gBattle_WIN1V = WIN_RANGE(0, DISPLAY_HEIGHT);
        SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN0H);
        SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN0V);
    }
    else
    {
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
        gBattle_WIN1H = WIN_RANGE(0, DISPLAY_WIDTH);
        gBattle_WIN1V = WIN_RANGE(120, DISPLAY_HEIGHT);
        SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
        SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
    }

    DestroyAnimVisualTask(taskId);
}

void AnimTask_RemoveSpotlight(u8 taskId)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
    if (!IsContest())
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);

    DestroyAnimVisualTask(taskId);
}

static void AnimRapidSpin(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    }

    sprite->y2 = gBattleAnimArgs[2];

    sprite->data[0] = (sprite->y2 > gBattleAnimArgs[3]);
    sprite->data[1] = 0;
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->callback = AnimRapidSpin_Step;
}

static void AnimRapidSpin_Step(struct Sprite *sprite)
{
    sprite->data[1] = (sprite->data[1] + sprite->data[2]) & 0xFF;
    sprite->x2 = gSineTable[sprite->data[1]] >> 4;
    sprite->y2 += sprite->data[3];

    if (sprite->data[0])
    {
        if (sprite->y2 < sprite->data[4])
            DestroyAnimSprite(sprite);
    }
    else
    {
        if (sprite->y2 > sprite->data[4])
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_RapinSpinMonElevation(u8 taskId)
{
    s16 var0;
    u8 toBG2;
    s16 var2;
    int var3;
    int var4;
    s16 i;
    struct ScanlineEffectParams scanlineParams;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[0])
    {
        var0 = GetBattlerYCoordWithElevation(gBattleAnimAttacker);
        toBG2 = GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker);
    }
    else
    {
        var0 = GetBattlerYCoordWithElevation(gBattleAnimTarget);
        toBG2 = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);
    }

    task->data[0] = var0 + 36;
    task->data[1] = task->data[0];
    task->data[2] = var0 - 33;
    if (task->data[2] < 0)
        task->data[2] = 0;

    task->data[3] = task->data[0];
    task->data[4] = 8;
    task->data[5] = gBattleAnimArgs[1];
    task->data[6] = 0;
    task->data[7] = 0;

    if (toBG2 == 1)
    {
        var3 = gBattle_BG1_X;
        task->data[8] = var3;
        var4 = var3 + DISPLAY_WIDTH;
    }
    else
    {
        var3 = gBattle_BG2_X;
        task->data[8] = var3;
        var4 = var3 + DISPLAY_WIDTH;
    }

    task->data[9] = var4;
    task->data[10] = gBattleAnimArgs[2];

    if (!gBattleAnimArgs[2])
    {
        task->data[11] = var4;
        var2 = task->data[8];
    }
    else
    {
        task->data[11] = var3;
        var2 = task->data[9];
    }

    task->data[15] = 0;

    i = task->data[2];
    while (i <= task->data[3])
    {
        gScanlineEffectRegBuffers[0][i] = var2;
        gScanlineEffectRegBuffers[1][i] = var2;
        i++;
    }

    if (toBG2 == 1)
        scanlineParams.dmaDest = &REG_BG1HOFS;
    else
        scanlineParams.dmaDest = &REG_BG2HOFS;

    scanlineParams.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    scanlineParams.initState = 1;
    scanlineParams.unused9 = 0;
    ScanlineEffect_SetParams(scanlineParams);

    task->func = RapinSpinMonElevation_Step;
}

static void RapinSpinMonElevation_Step(u8 taskId)
{
    s16 i;
    struct Task *task = &gTasks[taskId];

    task->data[0] -= task->data[5];
    if (task->data[0] < task->data[2])
        task->data[0] = task->data[2];

    if (task->data[4] == 0)
    {
        task->data[1] -= task->data[5];
        if (task->data[1] < task->data[2])
        {
            task->data[1] = task->data[2];
            task->data[15] = 1;
        }
    }
    else
    {
        task->data[4]--;
    }

    if (++task->data[6] > 1)
    {
        task->data[6] = 0;
        task->data[7] = task->data[7] == 0 ? 1 : 0;

        if (task->data[7])
            task->data[12] = task->data[8];
        else
            task->data[12] = task->data[9];
    }

    i = task->data[0];
    while (i < task->data[1])
    {
        gScanlineEffectRegBuffers[0][i] = task->data[12];
        gScanlineEffectRegBuffers[1][i] = task->data[12];
        i++;
    }

    i = task->data[1];
    while (i <= task->data[3])
    {
        gScanlineEffectRegBuffers[0][i] = task->data[11];
        gScanlineEffectRegBuffers[1][i] = task->data[11];
        i++;
    }

    if (task->data[15])
    {
        if (task->data[10])
            gScanlineEffect.state = 3;

        DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_TormentAttacker(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    task->data[3] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    task->data[4] = 32;
    task->data[5] = -20;
    task->data[6] = 0;
    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->func = TormentAttacker_Step;
}

static void TormentAttacker_Step(u8 taskId)
{
    int var0, var1;
    s16 x, y;
    u16 i, j;
    u8 spriteId;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        var0 = task->data[2];
        if (task->data[1] & 1)
        {
            var1 = task->data[4];
            x = var0 - var1;
        }
        else
        {
            var1 = task->data[4];
            x = var0 + var1;
        }

        y = task->data[3] + task->data[5];
        spriteId = CreateSprite(&gThoughtBubbleSpriteTemplate, x, y, 6 - task->data[1]);
        PlaySE12WithPanning(SE_M_METRONOME, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));

        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].hFlip = task->data[1] & 1;
            gSprites[spriteId].callback = SpriteCallbackDummy;
        }

        if (task->data[1] & 1)
        {
            task->data[4] -= 6;
            task->data[5] -= 6;
        }

        PrepareAffineAnimInTaskData(task, task->data[15], sAffineAnims_Torment);
        task->data[1]++;
        task->data[0] = 1;
        break;
    case 1:
        if (!RunAffineAnimFromTaskData(task))
        {
            if (task->data[1] == 6)
            {
                task->data[6] = 8;
                task->data[0] = 3;
            }
            else
            {
                if (task->data[1] <= 2)
                    task->data[6] = 10;
                else
                    task->data[6] = 0;

                task->data[0] = 2;
            }
        }
        break;
    case 2:
        if (task->data[6] != 0)
            task->data[6]--;
        else
            task->data[0] = 0;
        break;
    case 3:
        if (task->data[6] != 0)
            task->data[6]--;
        else
            task->data[0] = 4;
        break;
    case 4:
        for (i = 0, j = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].template == &gThoughtBubbleSpriteTemplate)
            {
                gSprites[i].data[0] = taskId;
                gSprites[i].data[1] = 6;
                StartSpriteAnim(&gSprites[i], 2);
                gSprites[i].callback = TormentAttacker_Callback;

                if (++j == 6)
                    break;
            }
        }

        task->data[6] = j;
        task->data[0] = 5;
        break;
    case 5:
        if (task->data[6] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void TormentAttacker_Callback(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gTasks[sprite->data[0]].data[sprite->data[1]]--;
        DestroySprite(sprite);
    }
}

static void AnimTriAttackTriangle(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
        InitSpritePosToAnimAttacker(sprite, FALSE);

    if (++sprite->data[0] < 40)
    {
        u16 var = sprite->data[0];
        if ((var & 1) == 0)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }

    if (sprite->data[0] > 30)
        sprite->invisible = FALSE;

    if (sprite->data[0] == 61)
    {
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 20;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->callback = StartAnimLinearTranslation;
    }
}

void AnimTask_DefenseCurlDeformMon(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), DefenseCurlDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimBatonPassPokeball(struct Sprite *sprite)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    switch (sprite->data[0])
    {
    case 0:
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        sprite->data[1] = 256;
        sprite->data[2] = 256;
        sprite->data[0]++;
        break;
    case 1:
        sprite->data[1] += 96;
        sprite->data[2] -= 26;
        SetSpriteRotScale(spriteId, sprite->data[1], sprite->data[2], 0);

        if (++sprite->data[3] == 5)
            sprite->data[0]++;
        // fall through
    case 2:
        sprite->data[1] += 96;
        sprite->data[2] += 48;
        SetSpriteRotScale(spriteId, sprite->data[1], sprite->data[2], 0);

        if (++sprite->data[3] == 9)
        {
            sprite->data[3] = 0;
            gSprites[spriteId].invisible = TRUE;
            ResetSpriteRotScale(spriteId);
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->y2 -= 6;
        if (sprite->y + sprite->y2 < -32)
            DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimWishStar(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x = -16;
    else
        sprite->x = DISPLAY_WIDTH + 16;

    sprite->y = 0;
    sprite->callback = AnimWishStar_Step;
}

static void AnimWishStar_Step(struct Sprite *sprite)
{
    u32 newX;

    sprite->data[0] += 72;
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x2 = sprite->data[0] >> 4;
    else
        sprite->x2 = -(sprite->data[0] >> 4);

    sprite->data[1] += 16;
    sprite->y2 += sprite->data[1] >> 8;

    if (++sprite->data[2] % 3 == 0)
    {
        CreateSpriteAndAnimate(
            &gMiniTwinklingStarSpriteTemplate,
            sprite->x + sprite->x2,
            sprite->y + sprite->y2,
            sprite->subpriority + 1);
    }

    newX = sprite->x + sprite->x2 + 32;
    if (newX > DISPLAY_WIDTH + 64)
        DestroyAnimSprite(sprite);
}

static void AnimMiniTwinklingStar(struct Sprite *sprite)
{
    u8 rand;
    s8 y;

    rand = Random2() & 3;
    if (rand == 0)
        sprite->oam.tileNum += 4;
    else
        sprite->oam.tileNum += 5;

    y = Random2() & 7;
    if (y > 3)
        y = -y;

    sprite->y2 = y;
    sprite->callback = AnimMiniTwinklingStar_Step;
}

static void AnimMiniTwinklingStar_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] < 30)
    {
        if (++sprite->data[1] == 2)
        {
            sprite->invisible ^= 1;
            sprite->data[1] = 0;
        }
    }
    else
    {
        if (sprite->data[1] == 2)
            sprite->invisible = FALSE;

        if (sprite->data[1] == 3)
        {
            sprite->invisible = TRUE;
            sprite->data[1] = -1;
        }

        sprite->data[1]++;
    }

    if (sprite->data[0] > 60)
        DestroySprite(sprite);
}

void AnimTask_StockpileDeformMon(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gStockpileDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_SpitUpDeformMon(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gSpitUpDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

static void AnimSwallowBlueOrb(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        InitSpritePosToAnimAttacker(sprite, FALSE);
        sprite->data[1] = 0x900;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->data[0]++;
        break;
    case 1:
        sprite->y2 -= sprite->data[1] >> 8;
        sprite->data[1] -= 96;
        if (sprite->y + sprite->y2 > sprite->data[2])
            DestroyAnimSprite(sprite);
        break;
    }
}

void AnimTask_SwallowDeformMon(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gSwallowDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_TransformMon(u8 taskId)
{
    int i, j;
    u8 position;
    struct BattleAnimBgData animBg;
    u8 *dest;
    u8 *src;
    u16 *bgTilemap;
    u16 stretch;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
            SetAnimBgAttribute(1, BG_ANIM_MOSAIC, 1);
        else
            SetAnimBgAttribute(2, BG_ANIM_MOSAIC, 1);

        gTasks[taskId].data[10] = gBattleAnimArgs[0];
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (gTasks[taskId].data[2]++ > 1)
        {
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].data[1]++;
            stretch = gTasks[taskId].data[1];
            SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 4) | stretch);
            if (stretch == 15)
                gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        HandleSpeciesGfxDataChange(gBattleAnimAttacker, gBattleAnimTarget, gTasks[taskId].data[10]);
        GetBgDataForTransform(&animBg, gBattleAnimAttacker);

        if (IsContest())
            position = B_POSITION_PLAYER_LEFT;
        else
            position = GetBattlerPosition(gBattleAnimAttacker);

        src = gMonSpritesGfxPtr->sprites.ptr[position] + (gBattleMonForms[gBattleAnimAttacker] << 11);
        dest = animBg.bgTiles;
        CpuCopy32(src, dest, MON_PIC_SIZE);
        LoadBgTiles(1, animBg.bgTiles, 0x800, animBg.tilesOffset);
        if (IsContest())
        {
            if (IsSpeciesNotUnown(gContestResources->moveAnim->species) != IsSpeciesNotUnown(gContestResources->moveAnim->targetSpecies))
            {
                bgTilemap = (u16 *)animBg.bgTilemap;
                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        u16 temp = bgTilemap[j + i * 0x20];
                        bgTilemap[j + i * 0x20] = bgTilemap[(7 - j) + i * 0x20];
                        bgTilemap[(7 - j) + i * 0x20] = temp;
                    }
                }

                for (i = 0; i < 8; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                       bgTilemap[j + i * 0x20] ^= 0x400;
                    }
                }
            }

            if (IsSpeciesNotUnown(gContestResources->moveAnim->targetSpecies))
                gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].affineAnims = gAffineAnims_BattleSpriteContest;
            else
                gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].affineAnims = gAffineAnims_BattleSpriteOpponentSide;

            StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimAttacker]], BATTLER_AFFINE_NORMAL);
        }

        gTasks[taskId].data[0]++;
        break;
    case 3:
        if (gTasks[taskId].data[2]++ > 1)
        {
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].data[1]--;
            stretch = gTasks[taskId].data[1];
            SetGpuReg(REG_OFFSET_MOSAIC, (stretch << 4) | stretch);

            if (stretch == 0)
                gTasks[taskId].data[0]++;
        }
        break;
    case 4:
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
            SetAnimBgAttribute(1, BG_ANIM_MOSAIC, 0);
        else
            SetAnimBgAttribute(2, BG_ANIM_MOSAIC, 0);

        if (!IsContest())
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
            {
                if (gTasks[taskId].data[10] == 0)
                    SetBattlerShadowSpriteCallback(gBattleAnimAttacker, gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].transformSpecies);
            }
        }

        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_IsMonInvisible(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].invisible;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_CastformGfxDataChange(u8 taskId)
{
    HandleSpeciesGfxDataChange(gBattleAnimAttacker, gBattleAnimTarget, TRUE);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_MorningSunLightBeam(u8 taskId)
{
    struct BattleAnimBgData animBg;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

        GetBattleAnimBg1Data(&animBg);
        AnimLoadCompressedBgTilemapHandleContest(&animBg, &gBattleAnimMaskTilemap_LightBeam, FALSE);
        if (IsContest())
        {
            gBattle_BG1_X = -56;
            gBattle_BG1_Y = 0;
        }
        else
        {
            if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
                gBattle_BG1_X = -135;
            else
                gBattle_BG1_X = -10;

            gBattle_BG1_Y = 0;
        }

        AnimLoadCompressedBgGfx(animBg.bgId, gBattleAnimMaskImage_LightBeam, animBg.tilesOffset);
        LoadCompressedPalette(gBattleAnimMaskPalette_LightBeam, BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);

        gTasks[taskId].data[10] = gBattle_BG1_X;
        gTasks[taskId].data[11] = gBattle_BG1_Y;

        gTasks[taskId].data[0]++;
        PlaySE12WithPanning(SE_M_MORNING_SUN, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
        break;
    case 1:
        if (gTasks[taskId].data[4]++ > 0)
        {
            gTasks[taskId].data[4] = 0;
            if (++gTasks[taskId].data[1] > 12)
                gTasks[taskId].data[1] = 12;

            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));

            if (gTasks[taskId].data[1] == 12)
                gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        if (--gTasks[taskId].data[1] < 0)
            gTasks[taskId].data[1] = 0;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));

        if (!gTasks[taskId].data[1])
        {
            gBattle_BG1_X = gMorningSunLightBeamCoordsTable[gTasks[taskId].data[2]] + gTasks[taskId].data[10];
            if (++gTasks[taskId].data[2] == 4)
                gTasks[taskId].data[0] = 4;
            else
                gTasks[taskId].data[0] = 3;
        }
        break;
    case 3:
        if (++gTasks[taskId].data[3] == 4)
        {
            gTasks[taskId].data[3] = 0;
            gTasks[taskId].data[0] = 1;
            PlaySE12WithPanning(SE_M_MORNING_SUN, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
        }
        break;
    case 4:
        GetBattleAnimBg1Data(&animBg);
        ClearBattleAnimBg(animBg.bgId);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimGreenStar(struct Sprite *sprite)
{
    s16 xOffset;
    u8 spriteId1;
    u8 spriteId2;

    xOffset = Random2();
    xOffset &= 0x3F;
    if (xOffset > 31)
        xOffset = 32 - xOffset;

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + xOffset;
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + 32;
    sprite->data[1] = gBattleAnimArgs[0];
    sprite->data[2] = gBattleAnimArgs[1];

    spriteId1 = CreateSprite(&gGreenStarSpriteTemplate, sprite->x, sprite->y, sprite->subpriority + 1);
    spriteId2 = CreateSprite(&gGreenStarSpriteTemplate, sprite->x, sprite->y, sprite->subpriority + 1);
    StartSpriteAnim(&gSprites[spriteId1], 1);
    StartSpriteAnim(&gSprites[spriteId2], 2);

    gSprites[spriteId1].data[1] = gBattleAnimArgs[0];
    gSprites[spriteId1].data[2] = gBattleAnimArgs[1];
    gSprites[spriteId2].data[1] = gBattleAnimArgs[0];
    gSprites[spriteId2].data[2] = gBattleAnimArgs[1];
    gSprites[spriteId1].data[7] = -1;
    gSprites[spriteId2].data[7] = -1;
    gSprites[spriteId1].invisible = TRUE;
    gSprites[spriteId2].invisible = TRUE;
    gSprites[spriteId1].callback = AnimGreenStar_Callback;
    gSprites[spriteId2].callback = AnimGreenStar_Callback;

    sprite->data[6] = spriteId1;
    sprite->data[7] = spriteId2;
    sprite->callback = AnimGreenStar_Step1;
}

static void AnimGreenStar_Step1(struct Sprite *sprite)
{
    s16 delta = sprite->data[3] + sprite->data[2];
    sprite->y2 -= delta >> 8;
    sprite->data[3] += sprite->data[2];
    sprite->data[3] &= 0xFF;
    if (sprite->data[4] == 0 && sprite->y2 < -8)
    {
        gSprites[sprite->data[6]].invisible = FALSE;
        sprite->data[4]++;
    }

    if (sprite->data[4] == 1 && sprite->y2 < -16)
    {
        gSprites[sprite->data[7]].invisible = FALSE;
        sprite->data[4]++;
    }

    if (--sprite->data[1] == -1)
    {
        sprite->invisible = TRUE;
        sprite->callback = AnimGreenStar_Step2;
    }
}

static void AnimGreenStar_Step2(struct Sprite *sprite)
{
    if (gSprites[sprite->data[6]].callback == SpriteCallbackDummy
     && gSprites[sprite->data[7]].callback == SpriteCallbackDummy)
    {
        DestroySprite(&gSprites[sprite->data[6]]);
        DestroySprite(&gSprites[sprite->data[7]]);
        DestroyAnimSprite(sprite);
    }
}

static void AnimGreenStar_Callback(struct Sprite *sprite)
{
    if (!sprite->invisible)
    {
        s16 delta = sprite->data[3] + sprite->data[2];
        sprite->y2 -= delta >> 8;
        sprite->data[3] += sprite->data[2];
        sprite->data[3] &= 0xFF;
        if (--sprite->data[1] == -1)
        {
            sprite->invisible = TRUE;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void AnimTask_DoomDesireLightBeam(u8 taskId)
{
    struct BattleAnimBgData animBg;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(3, 13));
        SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

        GetBattleAnimBg1Data(&animBg);
        AnimLoadCompressedBgTilemapHandleContest(&animBg, &gBattleAnimMaskTilemap_LightBeam, FALSE);
        if (IsContest())
        {
            gBattle_BG1_X = -56;
            gBattle_BG1_Y = 0;
        }
        else
        {
            u8 position = GetBattlerPosition(gBattleAnimTarget);
            if (IsDoubleBattle() == TRUE)
            {
                if (position == B_POSITION_OPPONENT_LEFT)
                    gBattle_BG1_X = -155;
                if (position == B_POSITION_OPPONENT_RIGHT)
                    gBattle_BG1_X = -115;
                if (position == B_POSITION_PLAYER_LEFT)
                    gBattle_BG1_X = 14;
                if (position == B_POSITION_PLAYER_RIGHT)
                    gBattle_BG1_X = -20;
            }
            else
            {
                if (position == B_POSITION_OPPONENT_LEFT)
                    gBattle_BG1_X = -135;
                if (position == B_POSITION_PLAYER_LEFT)
                    gBattle_BG1_X = -10;
            }

            gBattle_BG1_Y = 0;
        }

        AnimLoadCompressedBgGfx(animBg.bgId, gBattleAnimMaskImage_LightBeam, animBg.tilesOffset);
        LoadCompressedPalette(gBattleAnimMaskPalette_LightBeam, BG_PLTT_ID(animBg.paletteId), PLTT_SIZE_4BPP);
        gTasks[taskId].data[10] = gBattle_BG1_X;
        gTasks[taskId].data[11] = gBattle_BG1_Y;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[3] = 0;
        if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT)
            gBattle_BG1_X = gTasks[taskId].data[10] + gDoomDesireLightBeamCoordTable[gTasks[taskId].data[2]];
        else
            gBattle_BG1_X = gTasks[taskId].data[10] - gDoomDesireLightBeamCoordTable[gTasks[taskId].data[2]];

        if (++gTasks[taskId].data[2] == 5)
            gTasks[taskId].data[0] = 5;
        else
            gTasks[taskId].data[0]++;
        break;
    case 2:
        if (--gTasks[taskId].data[1] <= 4)
            gTasks[taskId].data[1] = 5;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(3, gTasks[taskId].data[1]));
        if (gTasks[taskId].data[1] == 5)
            gTasks[taskId].data[0]++;
        break;
    case 3:
        if (++gTasks[taskId].data[3] > gDoomDesireLightBeamDelayTable[gTasks[taskId].data[2]])
            gTasks[taskId].data[0]++;
        break;
    case 4:
        if (++gTasks[taskId].data[1] > 13)
            gTasks[taskId].data[1] = 13;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(3, gTasks[taskId].data[1]));
        if (gTasks[taskId].data[1] == 13)
            gTasks[taskId].data[0] = 1;
        break;
    case 5:
        GetBattleAnimBg1Data(&animBg);
        ClearBattleAnimBg(animBg.bgId);
        if (!IsContest())
            SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Briefly vertically grows and shrinks the attacking mon's sprite.
// No args.
void AnimTask_StrongFrustrationGrowAndShrink(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gStrongFrustrationAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

// Animates an anger mark near the mon's head.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
static void AnimWeakFrustrationAngerMark(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        InitSpritePosToAnimAttacker(sprite, FALSE);
        sprite->data[0]++;
    }
    else if (sprite->data[0]++ > 20)
    {
        sprite->data[1] += 160;
        sprite->data[2] += 128;

        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            sprite->x2 = -(sprite->data[1] >> 8);
        else
            sprite->x2 = sprite->data[1] >> 8;

        sprite->y2 += sprite->data[2] >> 8;
        if (sprite->y2 > 64)
            DestroyAnimSprite(sprite);
    }
}

// Rocks the mon back and forth. This is done on a pivot so it is done via rotation.
// arg 0: which battler
// arg 1: number of rocks
// arg 2: rotation speed increase
void AnimTask_RockMonBackAndForth(u8 taskId)
{
    u8 side;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[1])
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    if (gBattleAnimArgs[2] < 0)
        gBattleAnimArgs[2] = 0;
    if (gBattleAnimArgs[2] > 2)
        gBattleAnimArgs[2] = 2;

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 8 - (2 * gBattleAnimArgs[2]);
    task->data[4] = 0x100 + (gBattleAnimArgs[2] * 128);
    task->data[5] = gBattleAnimArgs[2] + 2;
    task->data[6] = gBattleAnimArgs[1] - 1;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        side = GetBattlerSide(gBattleAnimAttacker);
    else
        side = GetBattlerSide(gBattleAnimTarget);

    if (side == B_SIDE_OPPONENT)
    {
        task->data[4] *= -1;
        task->data[5] *= -1;
    }

    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = AnimTask_RockMonBackAndForth_Step;
}

static void AnimTask_RockMonBackAndForth_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        gSprites[task->data[15]].x2 += task->data[5];
        task->data[2] -= task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3])
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 1:
        gSprites[task->data[15]].x2 -= task->data[5];
        task->data[2] += task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3] * 2)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        gSprites[task->data[15]].x2 += task->data[5];
        task->data[2] -= task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3])
        {
            if (task->data[6])
            {
                task->data[6]--;
                task->data[1] = 0;
                task->data[0] = 0;
            }
            else
            {
                task->data[0]++;
            }
        }
        break;
    case 3:
        ResetSpriteRotScale(task->data[15]);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Floats a petal across the screen towards the target mon's side.
// arg 0: initial y pixel offset
// arg 1: sprite anim num
// arg 2: unused
static void AnimSweetScentPetal(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x = 0;
        sprite->y = gBattleAnimArgs[0];
    }
    else
    {
        sprite->x = DISPLAY_WIDTH;
        sprite->y = gBattleAnimArgs[0] - 30;
    }

    sprite->data[2] = gBattleAnimArgs[2];
    StartSpriteAnim(sprite, gBattleAnimArgs[1]);
    sprite->callback = AnimSweetScentPetal_Step;
}

static void AnimSweetScentPetal_Step(struct Sprite *sprite)
{
    sprite->data[0] += 3;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x += 5;
        sprite->y -= 1;

        if (sprite->x > DISPLAY_WIDTH)
            DestroyAnimSprite(sprite);

        sprite->y2 = Sin(sprite->data[0] & 0xFF, 16);
    }
    else
    {
        sprite->x -= 5;
        sprite->y += 1;

        if (sprite->x < 0)
            DestroyAnimSprite(sprite);

        sprite->y2 = Cos(sprite->data[0] & 0xFF, 16);
    }
}

// Moves the mon sprite in a flailing back-and-forth motion.
// arg 0: which battler
void AnimTask_FlailMovement(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[12] = 0x20;
    task->data[13] = 0x40;
    task->data[14] = 0x800;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);

    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = AnimTask_FlailMovement_Step;
}

static void AnimTask_FlailMovement_Step(u8 taskId)
{
    int temp;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[2] += 0x200;
        if (task->data[2] >= task->data[14])
        {
            s16 diff = task->data[14] - task->data[2];
            s16 div = diff / (task->data[14] * 2);
            s16 mod = diff % (task->data[14] * 2);

            if ((div & 1) == 0)
            {
                task->data[2] = task->data[14] - mod;
                task->data[0] = 1;
            }
            else
            {
                task->data[2] = mod - task->data[14];
            }
        }
        break;
    case 1:
        task->data[2] -= 0x200;
        if (task->data[2] <= -task->data[14])
        {
            s16 diff = task->data[14] - task->data[2];
            s16 div = diff / (task->data[14] * 2);
            s16 mod = diff % (task->data[14] * 2);

            if ((1 & div) == 0)
            {
                task->data[2] = mod - task->data[14];
                task->data[0] = 0;
            }
            else
            {
                task->data[2] = task->data[14] - mod;
            }
        }
        break;
    case 2:
        ResetSpriteRotScale(task->data[15]);
        DestroyAnimVisualTask(taskId);
        return;
    }

    SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
    SetBattlerSpriteYOffsetFromRotation(task->data[15]);
    gSprites[task->data[15]].x2 = -(((temp = task->data[2]) >= 0 ? task->data[2] : temp + 63) >> 6);

    if (++task->data[1] > 8)
    {
        if (task->data[12])
        {
            task->data[12]--;
            task->data[14] -= task->data[13];
            if (task->data[14] < 16)
                task->data[14] = 16;
        }
        else
        {
            task->data[0] = 2;
        }
    }
}

// Makes a spark-like projectile fall on top of the mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: which battler
static void AnimPainSplitProjectile(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        {
            sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        }

        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[1] = 0x80;
        sprite->data[2] = 0x300;
        sprite->data[3] = gBattleAnimArgs[1];
        sprite->data[0]++;
    }
    else
    {
        sprite->x2 = sprite->data[1] >> 8;
        sprite->y2 += sprite->data[2] >> 8;
        if (sprite->data[4] == 0 && sprite->y2 > -sprite->data[3])
        {
            sprite->data[4] = 1;
            sprite->data[2] = (-sprite->data[2] / 3) * 2;
        }

        sprite->data[1] += 192;
        sprite->data[2] += 128;
        if (sprite->animEnded)
            DestroyAnimSprite(sprite);
    }
}

// Performs one of several affine transformations on the mon sprite.
// arg 0: which battler
// arg 1: which transformation
void AnimTask_PainSplitMovement(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].data[0] == 0)
    {
        if (gBattleAnimArgs[0] == ANIM_ATTACKER)
            gTasks[taskId].data[11] = gBattleAnimAttacker;
        else
            gTasks[taskId].data[11] = gBattleAnimTarget;

        spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
        gTasks[taskId].data[10] = spriteId;
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);

        switch (gBattleAnimArgs[1])
        {
        case 0:
            SetSpriteRotScale(spriteId, 0xE0, 0x140, 0);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            break;
        case 1:
            SetSpriteRotScale(spriteId, 0xD0, 0x130, 0xF00);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            if (IsContest() || GetBattlerSide(gTasks[taskId].data[11]) == B_SIDE_PLAYER)
                gSprites[spriteId].y2 += 16;
            break;
        case 2:
            SetSpriteRotScale(spriteId, 0xD0, 0x130, 0xF100);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            if (IsContest() || GetBattlerSide(gTasks[taskId].data[11]) == B_SIDE_PLAYER)
                gSprites[spriteId].y2 += 16;
            break;
        }

        gSprites[spriteId].x2 = 2;
        gTasks[taskId].data[0]++;
    }
    else
    {
        spriteId = gTasks[taskId].data[10];
        if (++gTasks[taskId].data[2] == 3)
        {
            gTasks[taskId].data[2] = 0;
            gSprites[spriteId].x2 = -gSprites[spriteId].x2;
        }

        if (++gTasks[taskId].data[1] == 13)
        {
            ResetSpriteRotScale(spriteId);
            gSprites[spriteId].x2 = 0;
            gSprites[spriteId].y2 = 0;
            DestroyAnimVisualTask(taskId);
        }
    }
}

// Move a piece of confetti in a slightly-random speed across the screen.
// arg 0: which battler the confetti starts from
static void AnimFlatterConfetti(struct Sprite *sprite)
{
    u8 tileOffset;
    int rand1;
    int rand2;

    tileOffset = Random2() % 12;
    sprite->oam.tileNum += tileOffset;
    rand1 = Random2() & 0x1FF;
    rand2 = Random2() & 0xFF;

    if (rand1 & 1)
        sprite->data[0] = 0x5E0 + rand1;
    else
        sprite->data[0] = 0x5E0 - rand1;

    if (rand2 & 1)
        sprite->data[1] = 0x480 + rand2;
    else
        sprite->data[1] = 0x480 - rand2;

    sprite->data[2] = gBattleAnimArgs[0];
    if (sprite->data[2] == ANIM_ATTACKER)
        sprite->x = -8;
    else
        sprite->x = DISPLAY_WIDTH + 8;

    sprite->y = 104;
    sprite->callback = AnimFlatterConfetti_Step;
}

static void AnimFlatterConfetti_Step(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->x2 += sprite->data[0] >> 8;
        sprite->y2 -= sprite->data[1] >> 8;
    }
    else
    {
        sprite->x2 -= sprite->data[0] >> 8;
        sprite->y2 -= sprite->data[1] >> 8;
    }

    sprite->data[0] -= 22;
    sprite->data[1] -= 48;
    if (sprite->data[0] < 0)
        sprite->data[0] = 0;

    if (++sprite->data[3] == 31)
        DestroyAnimSprite(sprite);
}

// Uses a spotlight sprite as a light mask to illuminate the target mon. The spotlight grows and shrinks.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration of fully-opened spotlight
static void AnimFlatterSpotlight(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);

    sprite->data[0] = gBattleAnimArgs[2];
    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->invisible = TRUE;
    sprite->callback = AnimFlatterSpotlight_Step;
}

static void AnimFlatterSpotlight_Step(struct Sprite *sprite)
{
    switch (sprite->data[1])
    {
    case 0:
        sprite->invisible = FALSE;
        if (sprite->affineAnimEnded)
            sprite->data[1]++;
        break;
    case 1:
        if (--sprite->data[0] == 0)
        {
            ChangeSpriteAffineAnim(sprite, 1);
            sprite->data[1]++;
        }
        break;
    case 2:
        if (sprite->affineAnimEnded)
        {
            sprite->invisible = TRUE;
            sprite->data[1]++;
        }
        break;
    case 3:
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
        SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
        DestroyAnimSprite(sprite);
        break;
    }
}

// Spins an orb around the attacking mon, while its path radius grows and shrinks.
// arg 0: duration
// arg 1: initial wave offset
static void AnimReversalOrb(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->callback = AnimReversalOrb_Step;
    sprite->callback(sprite);
}

static void AnimReversalOrb_Step(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->y2 = Cos(sprite->data[1], sprite->data[3] >> 8);
    sprite->data[1] = (sprite->data[1] + 9) & 0xFF;

    if ((u16)sprite->data[1] < 64 || sprite->data[1] > 195)
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
    else
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) + 1;

    if (!sprite->data[5])
    {
        sprite->data[2] += 0x400;
        sprite->data[3] += 0x100;
        sprite->data[4]++;
        if (sprite->data[4] == sprite->data[0])
        {
            sprite->data[4] = 0;
            sprite->data[5] = 1;
        }
    }
    else if (sprite->data[5] == 1)
    {
        sprite->data[2] -= 0x400;
        sprite->data[3] -= 0x100;
        sprite->data[4]++;
        if (sprite->data[4] == sprite->data[0])
            DestroyAnimSprite(sprite);
    }
}

// Copies the target mon's sprite, and makes a white silhouette that shrinks away.
void AnimTask_RolePlaySilhouette(u8 taskId)
{
    bool8 isBackPic;
    u32 personality;
    u32 otId;
    u16 species;
    s16 xOffset;
    u32 priority;
    u8 spriteId;
    s16 coord1, coord2;

    GetAnimBattlerSpriteId(ANIM_ATTACKER);
    if (IsContest())
    {
        isBackPic = TRUE;
        personality = gContestResources->moveAnim->targetPersonality;
        otId = gContestResources->moveAnim->otId;
        species = gContestResources->moveAnim->targetSpecies;
        xOffset = 20;
        priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            isBackPic = FALSE;
            personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_OT_ID);
            if (gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies == SPECIES_NONE)
            {
                if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
                else
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
            }
            else
            {
                species = gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies;
            }

            xOffset = 20;
            priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
        }
        else
        {
            isBackPic = TRUE;
            personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_OT_ID);
            if (gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies == SPECIES_NONE)
            {
                if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
                else
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
            }
            else
            {
                species = gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies;
            }

            xOffset = -20;
            priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
        }
    }

    coord1 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    coord2 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    spriteId = CreateAdditionalMonSpriteForMoveAnim(species, isBackPic, 0, coord1 + xOffset, coord2, 5, personality, otId, gBattleAnimTarget, TRUE);

    gSprites[spriteId].oam.priority = priority;
    gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
    FillPalette(RGB_WHITE, OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
    gSprites[spriteId].oam.priority = priority;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));

    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].func = AnimTask_RolePlaySilhouette_Step1;
}

static void AnimTask_RolePlaySilhouette_Step1(u8 taskId)
{
    if (gTasks[taskId].data[10]++ > 1)
    {
        gTasks[taskId].data[10] = 0;
        gTasks[taskId].data[1]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1], 16 - gTasks[taskId].data[1]));
        if (gTasks[taskId].data[1] == 10)
        {
            gTasks[taskId].data[10] = 256;
            gTasks[taskId].data[11] = 256;
            gTasks[taskId].func = AnimTask_RolePlaySilhouette_Step2;
        }
    }
}

static void AnimTask_RolePlaySilhouette_Step2(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];
    gTasks[taskId].data[10] -= 16;
    gTasks[taskId].data[11] += 128;
    gSprites[spriteId].oam.affineMode |= ST_OAM_AFFINE_DOUBLE_MASK;
    TrySetSpriteRotScale(&gSprites[spriteId], TRUE, gTasks[taskId].data[10], gTasks[taskId].data[11], 0);
    if (++gTasks[taskId].data[12] == 9)
    {
        ResetSpriteRotScale_PreserveAffine(&gSprites[spriteId]);
        DestroySpriteAndFreeResources_(&gSprites[spriteId]);
        gTasks[taskId].func = DestroyAnimVisualTaskAndDisableBlend;
    }
}

// Performs a wavy transformation on the mon's sprite, and fades out.
// arg 0: which battler
void AnimTask_AcidArmor(u8 taskId)
{
    u8 battler;
    u16 bgX, bgY;
    s16 y, i;
    struct ScanlineEffectParams scanlineParams;
    struct Task *task = &gTasks[taskId];

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 16;
    task->data[4] = 0;
    task->data[5] = battler;
    task->data[6] = 32;
    task->data[7] = 0;
    task->data[8] = 24;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        task->data[8] *= -1;

    task->data[13] = GetBattlerYCoordWithElevation(battler) - 34;
    if (task->data[13] < 0)
        task->data[13] = 0;

    task->data[14] = task->data[13] + 66;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    if (GetBattlerSpriteBGPriorityRank(battler) == 1)
    {
        scanlineParams.dmaDest = &REG_BG1HOFS;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1);
        bgX = gBattle_BG1_X;
        bgY = gBattle_BG1_Y;
    }
    else
    {
        scanlineParams.dmaDest = &REG_BG2HOFS;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG2);
        bgX = gBattle_BG2_X;
        bgY = gBattle_BG2_Y;
    }

    for (y = 0, i = 0; y < 160; y++, i += 2)
    {
        gScanlineEffectRegBuffers[0][i] = bgX;
        gScanlineEffectRegBuffers[1][i] = bgX;
        gScanlineEffectRegBuffers[0][i + 1] = bgY;
        gScanlineEffectRegBuffers[1][i + 1] = bgY;
    }

    scanlineParams.dmaControl = SCANLINE_EFFECT_DMACNT_32BIT;
    scanlineParams.initState = 1;
    scanlineParams.unused9 = 0;
    ScanlineEffect_SetParams(scanlineParams);
    task->func = AnimTask_AcidArmor_Step;
}

static void AnimTask_AcidArmor_Step(u8 taskId)
{
    struct Task *task;
    s16 var1;
    s16 var2;
    s16 bgX, bgY;
    s16 offset;
    s16 var0;
    s16 i;
    s16 sineIndex;
    s16 var3;

    task = &gTasks[taskId];
    if (GetBattlerSpriteBGPriorityRank(task->data[5]) == 1)
    {
        bgX = gBattle_BG1_X;
        bgY = gBattle_BG1_Y;
    }
    else
    {
        bgX = gBattle_BG2_X;
        bgY = gBattle_BG2_Y;
    }

    switch (task->data[0])
    {
    case 0:
        offset = task->data[14] * 2;
        var1 = 0;
        var2 = 0;
        i = 0;
        task->data[1] = (task->data[1] + 2) & 0xFF;
        sineIndex = task->data[1];
        task->data[9] = 0x7E0 / task->data[6];
        task->data[10] = -((task->data[7] * 2) / task->data[9]);
        task->data[11] = task->data[7];
        var3 = task->data[11] >> 5;
        task->data[12] = var3;
        var0 = task->data[14];
        while (var0 > task->data[13])
        {
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][offset + 1] = (i - var2) + bgY;
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][offset] = bgX + var3 + (gSineTable[sineIndex] >> 5);
            sineIndex = (sineIndex + 10) & 0xFF;
            task->data[11] += task->data[10];
            var3 = task->data[11] >> 5;
            task->data[12] = var3;

            i++;
            offset -= 2;
            var1 += task->data[6];
            var2 = var1 >> 5;
            var0--;
        }

        var0 *= 2;
        while (var0 >= 0)
        {
            gScanlineEffectRegBuffers[0][var0] = bgX + DISPLAY_WIDTH;
            gScanlineEffectRegBuffers[1][var0] = bgX + DISPLAY_WIDTH;
            var0 -= 2;
        }

        if (++task->data[6] > 63)
        {
            task->data[6] = 64;
            task->data[2]++;
            if (task->data[2] & 1)
                task->data[3]--;
            else
                task->data[4]++;

            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[3], task->data[4]));
            if (task->data[3] == 0 && task->data[4] == 16)
            {
                task->data[2] = 0;
                task->data[3] = 0;
                task->data[0]++;
            }
        }
        else
        {
            task->data[7] += task->data[8];
        }
        break;
    case 1:
        if (++task->data[2] > 12)
        {
            gScanlineEffect.state = 3;
            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        task->data[2]++;
        if (task->data[2] & 1)
            task->data[3]++;
        else
            task->data[4]--;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[3], task->data[4]));
        if (task->data[3] == 16 && task->data[4] == 0)
        {
            task->data[2] = 0;
            task->data[3] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Runs an affine animation that makes it look like the mon is inhaling deeply.
// arg 0: which battler
void AnimTask_DeepInhale(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    PrepareAffineAnimInTaskData(&gTasks[taskId], task->data[15], gDeepInhaleAffineAnimCmds);
    task->func = AnimTask_DeepInhale_Step;
}

static void AnimTask_DeepInhale_Step(u8 taskId)
{
    u16 var0;

    struct Task *task = &gTasks[taskId];
    var0 = task->data[0];
    task->data[0]++;
    var0 -= 20;
    if (var0 < 23)
    {
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            task->data[2]++;
            if (task->data[2] & 1)
                gSprites[task->data[15]].x2 = 1;
            else
                gSprites[task->data[15]].x2 = -1;
        }
    }
    else
    {
        gSprites[task->data[15]].x2 = 0;
    }

    if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
        DestroyAnimVisualTask(taskId);
}

static void InitYawnCloudPosition(struct Sprite *sprite, s16 startX, s16 startY, s16 destX, s16 destY, u16 duration)
{
    sprite->x = startX;
    sprite->y = startY;
    sprite->data[4] = startX << 4;
    sprite->data[5] = startY << 4;
    sprite->data[6] = ((destX - startX) << 4) / duration;
    sprite->data[7] = ((destY - startY) << 4) / duration;
}

static void UpdateYawnCloudPosition(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[6];
    sprite->data[5] += sprite->data[7];
    sprite->x = sprite->data[4] >> 4;
    sprite->y = sprite->data[5] >> 4;
}

// Drifts a cloud in a wavy path towards the target mon.
// arg 0: which affine anim
static void AnimYawnCloud(struct Sprite *sprite)
{
    s16 destX = sprite->x;
    s16 destY = sprite->y;

    SetSpriteCoordsToAnimAttackerCoords(sprite);
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[0]);
    InitYawnCloudPosition(sprite, sprite->x, sprite->y, destX, destY, 64);
    sprite->data[0] = 0;
    sprite->callback = AnimYawnCloud_Step;
}

static void AnimYawnCloud_Step(struct Sprite *sprite)
{
    int index;

    sprite->data[0]++;
    index = (sprite->data[0] * 8) & 0xFF;
    UpdateYawnCloudPosition(sprite);
    sprite->y2 = Sin(index, 8);
    if (sprite->data[0] > 58)
    {
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            sprite->invisible = sprite->data[2] & 1;
            if (sprite->data[2] > 3)
                DestroySpriteAndMatrix(sprite);
        }
    }
}

// Animates a cloud coming from the smoke ball.
// arg 0: ?
// arg 1: initial x pixel offset
// arg 2: initial y pixel offset
// arg 3: time until destroyed
static void AnimSmokeBallEscapeCloud(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[3];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[0]);
    if (GetBattlerSide(gBattleAnimTarget) != B_SIDE_PLAYER)
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    sprite->callback = DestroyAnimSpriteAfterTimer;
}

static void AnimTask_SlideMonForFocusBand_Step2(u8 taskId)
{
    u16 var0 = 0;
    u16 var1 = 0;

    gTasks[taskId].data[0]--;
    if ((gTasks[taskId].data[6] & 0x8000) && (--gTasks[taskId].data[1] == -1))
    {
        if (gTasks[taskId].data[9] == 0)
        {
            gTasks[taskId].data[9] = gTasks[taskId].data[4];
            gTasks[taskId].data[4] = -gTasks[taskId].data[4];
        }
        else
        {
            gTasks[taskId].data[9] = 0;
        }

        if (gTasks[taskId].data[10] == 0)
        {
            gTasks[taskId].data[10] = gTasks[taskId].data[5];
            gTasks[taskId].data[5] = -gTasks[taskId].data[5];
        }
        else
        {
            gTasks[taskId].data[10] = 0;
        }

        gTasks[taskId].data[1] = gTasks[taskId].data[13];
    }

    var0 = gTasks[taskId].data[7];
    var1 = gTasks[taskId].data[8];
    if (gTasks[taskId].data[2] & 0x8000)
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] - (var0 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] + (var0 >> 8);

    if (gTasks[taskId].data[3] & 0x8000)
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] - (var1 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] + (var1 >> 8);

    if (gTasks[taskId].data[0] < 1)
    {
        DestroyTask(taskId);
        gAnimVisualTaskCount--;
    }
}

static void AnimTask_SlideMonForFocusBand_Step1(u8 taskId)
{
    u16 var0 = 0;
    u16 var1 = 0;

    gTasks[taskId].data[0]--;
    if ((gTasks[taskId].data[6] & 0x8000) && (--gTasks[taskId].data[1] == -1))
    {
        if (gTasks[taskId].data[9] == 0)
        {
            gTasks[taskId].data[9] = gTasks[taskId].data[4];
            gTasks[taskId].data[4] = -gTasks[taskId].data[4];
        }
        else
        {
            gTasks[taskId].data[9] = var0;
        }

        if (gTasks[taskId].data[10] == 0)
        {
            gTasks[taskId].data[10] = gTasks[taskId].data[5];
            gTasks[taskId].data[5] = -gTasks[taskId].data[5];
        }
        else
        {
            gTasks[taskId].data[10] = 0;
        }

        gTasks[taskId].data[1] = gTasks[taskId].data[13];
    }

    var0 = (gTasks[taskId].data[2] & 0x7FFF) + gTasks[taskId].data[7];
    var1 = (gTasks[taskId].data[3] & 0x7FFF) + gTasks[taskId].data[8];
    if (gTasks[taskId].data[2] & 0x8000)
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] - (var0 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] + (var0 >> 8);

    if (gTasks[taskId].data[3] & 0x8000)
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] - (var1 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] + (var1 >> 8);

    gTasks[taskId].data[7] = var0;
    gTasks[taskId].data[8] = var1;
    if (gTasks[taskId].data[0] < 1)
    {
        gTasks[taskId].data[0] = 30;
        gTasks[taskId].data[13] = 0;
        gTasks[taskId].func = AnimTask_SlideMonForFocusBand_Step2;
    }
}

void AnimTask_SlideMonForFocusBand(u8 taskId)
{
    gTasks[taskId].data[15] = gBattlerSpriteIds[gBattleAnimAttacker];
    gTasks[taskId].data[14] = gBattleAnimArgs[0];
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[13] = gBattleAnimArgs[6];
    if (gBattleAnimArgs[3])
        gTasks[taskId].data[6] = gTasks[taskId].data[6] | -0x8000;

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gTasks[taskId].data[2] = gBattleAnimArgs[1];
        gTasks[taskId].data[3] = gBattleAnimArgs[2];
    }
    else
    {
        if (gBattleAnimArgs[1] & 0x8000)
            gTasks[taskId].data[2] = gBattleAnimArgs[1] & 0x7FFF;
        else
            gTasks[taskId].data[2] = gBattleAnimArgs[1] | -0x8000;

        if (gBattleAnimArgs[2] & 0x8000)
            gTasks[taskId].data[3] = gBattleAnimArgs[2] & 0x7FFF;
        else
            gTasks[taskId].data[3] = gBattleAnimArgs[2] | -0x8000;
    }

    gTasks[taskId].data[8] = 0;
    gTasks[taskId].data[7] = 0;
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = gBattleAnimArgs[5];
    gTasks[taskId].func = AnimTask_SlideMonForFocusBand_Step1;
}

#define IDX_ACTIVE_SPRITES 2  // Used by the sprite callback to modify the number of active sprites

// Task data for AnimTask_SquishAndSweatDroplets
#define tState           data[0]
#define tTimer           data[1]
#define tActiveSprites   data[IDX_ACTIVE_SPRITES]
#define tNumSquishes     data[3]
#define tBaseX           data[4]
#define tBaseY           data[5]
#define tSubpriority     data[6]
// data[7]-data[15] used by PrepareAffineAnimInTaskData
#define tBattlerSpriteId data[15]

// Sprite data for AnimFacadeSweatDrop
#define sTimer            data[0]
#define sVelocX           data[1]
#define sVelocY           data[2]
#define sTaskId           data[3]
#define sActiveSpritesIdx data[4]

// Squishes the mon vertically and emits sweat droplets a few times.
// arg 0: battler
// arg 1: num squishes
void AnimTask_SquishAndSweatDroplets(u8 taskId)
{
    u8 battler;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[1])
        DestroyAnimVisualTask(taskId);

    task->tState = 0;
    task->tTimer = 0;
    task->tActiveSprites = 0;
    task->tNumSquishes = gBattleAnimArgs[1];
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    task->tBaseX = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
    task->tBaseY = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y);
    task->tSubpriority = GetBattlerSpriteSubpriority(battler);
    task->tBattlerSpriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    PrepareAffineAnimInTaskData(task, task->tBattlerSpriteId, gFacadeSquishAffineAnimCmds);
    task->func = AnimTask_SquishAndSweatDroplets_Step;
}

static void AnimTask_SquishAndSweatDroplets_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tTimer++;
        if (task->tTimer == 6)
            CreateSweatDroplets(taskId, TRUE);

        if (task->tTimer == 18)
            CreateSweatDroplets(taskId, FALSE);

        if (!RunAffineAnimFromTaskData(task))
        {
            if (--task->tNumSquishes == 0)
            {
                // Animation is finished
                task->tState++;
            }
            else
            {
                // Animation continues, more droplet sprites to create
                task->tTimer = 0;
                PrepareAffineAnimInTaskData(task, task->tBattlerSpriteId, gFacadeSquishAffineAnimCmds);
            }
        }
        break;
    case 1:
        // Wait for sprites to be destroyed before ending task
        if (task->tActiveSprites == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void CreateSweatDroplets(u8 taskId, bool8 lowerDroplets)
{
    u8 i;
    s8 xOffset, yOffset;
    struct Task *task;
    s16 xCoords[4];
    s16 yCoords[2];

    task = &gTasks[taskId];
    if (!lowerDroplets)
    {
        xOffset = 18;
        yOffset = -20;
    }
    else
    {
        xOffset = 30;
        yOffset = 20;
    }

    xCoords[0] = task->tBaseX - xOffset;
    xCoords[1] = task->tBaseX - xOffset - 4;
    xCoords[2] = task->tBaseX + xOffset;
    xCoords[3] = task->tBaseX + xOffset + 4;
    yCoords[0] = task->tBaseY + yOffset;
    yCoords[1] = task->tBaseY + yOffset + 6;

    for (i = 0; i < 4; i++)
    {
        u8 spriteId = CreateSprite(&gFacadeSweatDropSpriteTemplate, xCoords[i], yCoords[i & 1], task->tSubpriority - 5);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].sTimer = 0;
            gSprites[spriteId].sVelocX = i < 2 ? -2 : 2; // First two travel left, remaining travel right
            gSprites[spriteId].sVelocY = -1;
            gSprites[spriteId].sTaskId = taskId;
            gSprites[spriteId].sActiveSpritesIdx = IDX_ACTIVE_SPRITES;
            task->tActiveSprites++;
        }
    }
}

static void AnimFacadeSweatDrop(struct Sprite *sprite)
{
    sprite->x += sprite->sVelocX;
    sprite->y += sprite->sVelocY;
    if (++sprite->sTimer > 6)
    {
        gTasks[sprite->sTaskId].data[sprite->sActiveSpritesIdx]--;
        DestroySprite(sprite);
    }
}

#undef IDX_ACTIVE_SPRITES
#undef tState
#undef tTimer
#undef tActiveSprites
#undef tNumSquishes
#undef tBaseX
#undef tBaseY
#undef tSubpriority
#undef tBattlerSpriteId
#undef sTimer
#undef sVelocX
#undef sVelocY
#undef sTaskId
#undef sActiveSpritesIdx

// Blends the mon sprite's color with a rotating set of colors.
// arg 0: battler
// arg 1: duration
void AnimTask_FacadeColorBlend(u8 taskId)
{
    u8 spriteId;

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    gTasks[taskId].data[2] = OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum);
    gTasks[taskId].func = AnimTask_FacadeColorBlend_Step;
}

static void AnimTask_FacadeColorBlend_Step(u8 taskId)
{
    if (gTasks[taskId].data[1])
    {
        BlendPalette(gTasks[taskId].data[2], 16, 8, gFacadeBlendColors[gTasks[taskId].data[0]]);
        if (++gTasks[taskId].data[0] > 23)
            gTasks[taskId].data[0] = 0;

        gTasks[taskId].data[1]--;
    }
    else
    {
        BlendPalette(gTasks[taskId].data[2], 16, 0, RGB_BLACK);
        DestroyAnimVisualTask(taskId);
    }
}

// The sliding circle effect used by Refresh and Aromatherapy
void AnimTask_StatusClearedEffect(u8 taskId)
{
    StartMonScrollingBgMask(
        taskId,
        0,
        0x1A0,
        gBattleAnimAttacker,
        gBattleAnimArgs[0],
        10,
        2,
        30,
        gCureBubblesGfx,
        gCureBubblesTilemap,
        gCureBubblesPal);
}

// Moves a noise line from the mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: which direction (0 = upward, 1 = downward, 2 = horizontal)
static void AnimRoarNoiseLine(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[1];
    if (gBattleAnimArgs[2] == 0)
    {
        sprite->data[0] = 0x280;
        sprite->data[1] = -0x280;
    }
    else if (gBattleAnimArgs[2] == 1)
    {
        sprite->vFlip = 1;
        sprite->data[0] = 0x280;
        sprite->data[1] = 0x280;
    }
    else
    {
        StartSpriteAnim(sprite, 1);
        sprite->data[0] = 0x280;
    }

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->data[0] = -sprite->data[0];
        sprite->hFlip = 1;
    }

    sprite->callback = AnimRoarNoiseLine_Step;
}

static void AnimRoarNoiseLine_Step(struct Sprite *sprite)
{
    sprite->data[6] += sprite->data[0];
    sprite->data[7] += sprite->data[1];
    sprite->x2 = sprite->data[6] >> 8;
    sprite->y2 = sprite->data[7] >> 8;
    if (++sprite->data[5] == 14)
        DestroyAnimSprite(sprite);
}

#define IDX_ACTIVE_SPRITES 10  // Used by the sprite callback to modify the number of active sprites

// Task data for AnimTask_GlareEyeDots
#define tState         data[0]
#define tTimer         data[1]
#define tPairNum       data[2]
#define tPairMax       data[5]
#define tDotOffset     data[6]
#define tIsContest     data[7]
#define tActiveSprites data[IDX_ACTIVE_SPRITES]
#define tStartX        data[11]
#define tStartY        data[12]
#define tEndX          data[13]
#define tEndY          data[14]

// Sprite data for AnimGlareEyeDot
#define sTimer            data[0]
#define sTaskId           data[1]
#define sActiveSpritesIdx data[2]

// Makes a series of dots in a trail from the attacker to the target.
// arg 0: unused
void AnimTask_GlareEyeDots(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (IsContest())
    {
        task->tPairMax = 8;
        task->tDotOffset = 3;
        task->tIsContest = TRUE;
    }
    else
    {
        task->tPairMax = 12;
        task->tDotOffset = 3;
        task->tIsContest = FALSE;
    }

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        task->tStartX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_HEIGHT) / 4;
    else
        task->tStartX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) - GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_HEIGHT) / 4;

    task->tStartY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) - GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_HEIGHT) / 4;
    task->tEndX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->tEndY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    task->func = AnimTask_GlareEyeDots_Step;
}

static void AnimTask_GlareEyeDots_Step(u8 taskId)
{
    u8 i;
    s16 x, y;
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        // Wait to create next pair of dots
        if (++task->tTimer > 3)
        {
            task->tTimer = 0;
            GetGlareEyeDotCoords(
                task->tStartX,
                task->tStartY,
                task->tEndX,
                task->tEndY,
                task->tPairMax,
                task->tPairNum,
                &x,
                &y);

            // Create dot pair
            for (i = 0; i < 2; i++)
            {
                u8 spriteId = CreateSprite(&gGlareEyeDotSpriteTemplate, x, y, 35);
                if (spriteId != MAX_SPRITES)
                {
                    if (!task->tIsContest)
                    {
                        if (i == 0)
                            gSprites[spriteId].x2 = gSprites[spriteId].y2 = -task->tDotOffset;
                        else
                            gSprites[spriteId].x2 = gSprites[spriteId].y2 = task->tDotOffset;
                    }
                    else
                    {
                        if (i == 0)
                        {
                            gSprites[spriteId].x2 = -task->tDotOffset;
                            gSprites[spriteId].y2 = task->tDotOffset;
                        }
                        else
                        {
                            gSprites[spriteId].x2 = task->tDotOffset;
                            gSprites[spriteId].y2 = -task->tDotOffset;
                        }
                    }

                    gSprites[spriteId].sTimer = 0;
                    gSprites[spriteId].sTaskId = taskId;
                    gSprites[spriteId].sActiveSpritesIdx = IDX_ACTIVE_SPRITES;
                    task->tActiveSprites++;
                }
            }

            if (task->tPairNum == task->tPairMax)
                task->tState++;

            task->tPairNum++;
        }
        break;
    case 1:
        // Wait for sprites to be destroyed before ending task
        if (task->tActiveSprites == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void GetGlareEyeDotCoords(s16 startX, s16 startY, s16 endX, s16 endY, u8 pairMax, u8 pairNum, s16 *x, s16 *y)
{
    int x2;
    int y2;

    if (pairNum == 0)
    {
        *x = startX;
        *y = startY;
        return;
    }

    if (pairNum >= pairMax)
    {
        *x = endX;
        *y = endY;
        return;
    }

    pairMax--;
    x2 = (startX << 8) + pairNum * (((endX - startX) << 8) / pairMax);
    y2 = (startY << 8) + pairNum * (((endY - startY) << 8) / pairMax);
    *x = x2 >> 8;
    *y = y2 >> 8;
}

static void AnimGlareEyeDot(struct Sprite *sprite)
{
    if (++sprite->sTimer > 36)
    {
        gTasks[sprite->sTaskId].data[sprite->sActiveSpritesIdx]--;
        DestroySprite(sprite);
    }
}

#undef IDX_ACTIVE_SPRITES
#undef tState
#undef tTimer
#undef tPairNum
#undef tPairMax
#undef tDotOffset
#undef tIsContest
#undef tActiveSprites
#undef tStartX
#undef tStartY
#undef tEndX
#undef tEndY
#undef sTimer
#undef sTaskId
#undef sActiveSpritesIdx

// Moves a pawprint in a straight line.
// arg 0: initial x position
// arg 1: initial y position
// arg 2: destination x position
// arg 3: destination y position
// arg 4: duration
static void AnimAssistPawprint(struct Sprite *sprite)
{
    sprite->x = gBattleAnimArgs[0];
    sprite->y = gBattleAnimArgs[1];
    sprite->data[2] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[0] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = InitAndRunAnimFastLinearTranslation;
}

// Moves a ball in an arc twoards the target, and rotates the ball while arcing.
// No args.
void AnimTask_BarrageBall(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[11] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    task->data[12] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    task->data[13] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->data[14] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_HEIGHT) / 4;
    task->data[15] = CreateSprite(&gBarrageBallSpriteTemplate, task->data[11], task->data[12], GetBattlerSpriteSubpriority(gBattleAnimTarget) - 5);
    if (task->data[15] != MAX_SPRITES)
    {
        gSprites[task->data[15]].data[0] = 16;
        gSprites[task->data[15]].data[2] = task->data[13];
        gSprites[task->data[15]].data[4] = task->data[14];
        gSprites[task->data[15]].data[5] = -32;
        InitAnimArcTranslation(&gSprites[task->data[15]]);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
            StartSpriteAffineAnim(&gSprites[task->data[15]], 1);

        task->func = AnimTask_BarrageBall_Step;
    }
    else
    {
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimTask_BarrageBall_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            TranslateAnimHorizontalArc(&gSprites[task->data[15]]);
            if (++task->data[2] > 7)
                task->data[0]++;
        }
        break;
    case 1:
        if (TranslateAnimHorizontalArc(&gSprites[task->data[15]]))
        {
            task->data[1] = 0;
            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            task->data[2]++;
            gSprites[task->data[15]].invisible = task->data[2] & 1;
            if (task->data[2] == 16)
            {
                FreeOamMatrix(gSprites[task->data[15]].oam.matrixNum);
                DestroySprite(&gSprites[task->data[15]]);
                task->data[0]++;
            }
        }
        break;
    case 3:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Moves a hand back and forth in a squishing motion.
// arg 0: which battler
// arg 1: horizontal flip
// arg 2: num squishes
static void AnimSmellingSaltsHand(struct Sprite *sprite)
{
    u8 battler;

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    sprite->oam.tileNum += 16;
    sprite->data[6] = gBattleAnimArgs[2];
    sprite->data[7] = gBattleAnimArgs[1] == 0 ? -1 : 1;
    sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET);
    if (gBattleAnimArgs[1] == 0)
    {
        sprite->oam.matrixNum |= ST_OAM_HFLIP;
        sprite->x = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_LEFT) - 8;
    }
    else
    {
        sprite->x = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_RIGHT) + 8;
    }

    sprite->callback = AnimSmellingSaltsHand_Step;
}

static void AnimSmellingSaltsHand_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            sprite->x2 += sprite->data[7];
            if (++sprite->data[2] == 12)
                sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] == 8)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->x2 -= sprite->data[7] * 4;
        if (++sprite->data[1] == 6)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->x2 += sprite->data[7] * 3;
        if (++sprite->data[1] == 8)
        {
            if (--sprite->data[6])
            {
                sprite->data[1] = 0;
                sprite->data[0]--;
            }
            else
            {
                DestroyAnimSprite(sprite);
            }
        }
        break;
    }
}

// Squishes the mon horizontally a few times.
// arg 0: which mon
// arg 1: number of squishes
void AnimTask_SmellingSaltsSquish(u8 taskId)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        gTasks[taskId].data[0] = gBattleAnimArgs[1];
        gTasks[taskId].data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
        PrepareAffineAnimInTaskData(&gTasks[taskId], gTasks[taskId].data[15], gSmellingSaltsSquishAffineAnimCmds);
        gTasks[taskId].func = AnimTask_SmellingSaltsSquish_Step;
    }
}

static void AnimTask_SmellingSaltsSquish_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (++task->data[1] > 1)
    {
        task->data[1] = 0;
        if (!(task->data[2] & 1))
            gSprites[task->data[15]].x2 = 2;
        else
            gSprites[task->data[15]].x2 = -2;
    }

    if (!RunAffineAnimFromTaskData(task))
    {
        gSprites[task->data[15]].x2 = 0;
        if (--task->data[0])
        {
            PrepareAffineAnimInTaskData(&gTasks[taskId], gTasks[taskId].data[15], gSmellingSaltsSquishAffineAnimCmds);
            task->data[1] = 0;
            task->data[2] = 0;
        }
        else
        {
            DestroyAnimVisualTask(taskId);
        }
    }
}

// Blinks an exclamation image over the mon a few times.
// arg 0: which mon
// arg 1: blink delay
// arg 2: number of blinks
static void AnimSmellingSaltExclamation(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_TOP);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_TOP);
    }

    if (sprite->y < 8)
        sprite->y = 8;

    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->data[2] = 0;
    sprite->data[3] = gBattleAnimArgs[2];
    sprite->callback = AnimSmellingSaltExclamation_Step;
}

static void AnimSmellingSaltExclamation_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] >= sprite->data[1])
    {
        sprite->data[0] = 0;
        sprite->data[2] = (sprite->data[2] + 1) & 1;
        sprite->invisible = sprite->data[2];
        if (sprite->data[2] && --sprite->data[3] == 0)
            DestroyAnimSprite(sprite);
    }
}

// Claps a hand several times.
// arg 0: which hand
// arg 1:
static void AnimHelpingHandClap(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->oam.matrixNum |= ST_OAM_HFLIP;
        sprite->x = 100;
        sprite->data[7] = 1;
    }
    else
    {
        sprite->x = 140;
        sprite->data[7] = -1;
    }

    sprite->y = 56;
    sprite->callback = AnimHelpingHandClap_Step;
}

static void AnimHelpingHandClap_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->y -= sprite->data[7] * 2;
        if (sprite->data[1] & 1)
            sprite->x -= sprite->data[7] * 2;

        if (++sprite->data[1] == 9)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] == 4)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[1]++;
        sprite->y += sprite->data[7] * 3;
        sprite->x2 = sprite->data[7] * (gSineTable[sprite->data[1] * 10] >> 3);
        if (sprite->data[1] == 12)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        if (++sprite->data[1] == 2)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 4:
        sprite->data[1]++;
        sprite->y -= sprite->data[7] * 3;
        sprite->x2 = sprite->data[7] * (gSineTable[sprite->data[1] * 10] >> 3);
        if (sprite->data[1] == 12)
            sprite->data[0]++;
        break;
    case 5:
        sprite->data[1]++;
        sprite->y += sprite->data[7] * 3;
        sprite->x2 = sprite->data[7] * (gSineTable[sprite->data[1] * 10] >> 3);
        if (sprite->data[1] == 15)
            sprite->oam.tileNum += 16;

        if (sprite->data[1] == 18)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 6:
        sprite->x += sprite->data[7] * 6;
        if (++sprite->data[1] == 9)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 7:
        sprite->x += sprite->data[7] * 2;
        if (++sprite->data[1] == 1)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 8:
        sprite->x -= sprite->data[7] * 3;
        if (++sprite->data[1] == 5)
            DestroyAnimSprite(sprite);
        break;
    }
}

// Repeatedly moves the attacking mon in a horizontal lunging motion.
// No args.
void AnimTask_HelpingHandAttackerMovement(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    if (!IsContest())
    {
        if (IsDoubleBattle() == TRUE)
        {
            int attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
            int partnerX = GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimAttacker), BATTLER_COORD_X);
            if (attackerX > partnerX)
                task->data[14] = 1;
            else
                task->data[14] = -1;
        }
        else
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
                task->data[14] = -1;
            else
                task->data[14] = 1;
        }
    }
    else
    {
        task->data[14] = 1;
    }

    task->func = AnimTask_HelpingHandAttackerMovement_Step;
}

static void AnimTask_HelpingHandAttackerMovement_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] == 13)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 1:
        gSprites[task->data[15]].x2 -= task->data[14] * 3;
        if (++task->data[1] == 6)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        gSprites[task->data[15]].x2 += task->data[14] * 3;
        if (++task->data[1] == 6)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        if (++task->data[1] == 2)
        {
            task->data[1] = 0;
            if (task->data[2] == 0)
            {
                task->data[2]++;
                task->data[0] = 1;
            }
            else
            {
                task->data[0]++;
            }
        }
        break;
    case 4:
        gSprites[task->data[15]].x2 += task->data[14];
        if (++task->data[1] == 3)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 5:
        if (++task->data[1] == 6)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 6:
        gSprites[task->data[15]].x2 -= task->data[14] * 4;
        if (++task->data[1] == 5)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 7:
        gSprites[task->data[15]].x2 += task->data[14] * 4;
        if (++task->data[1] == 5)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 8:
        gSprites[task->data[15]].x2 = 0;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Moves a magnifying glass around in straight lines.
// arg 0: magnifying glass target mon
static void AnimForesightMagnifyingGlass(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        InitSpritePosToAnimAttacker(sprite, TRUE);
        sprite->data[7] = gBattleAnimAttacker;
    }
    else
    {
        sprite->data[7] = gBattleAnimTarget;
    }

    if (GetBattlerSide(sprite->data[7]) == B_SIDE_OPPONENT)
        sprite->oam.matrixNum = ST_OAM_HFLIP;

    sprite->oam.priority = GetBattlerSpriteBGPriority(sprite->data[7]);
    sprite->oam.objMode = ST_OAM_OBJ_BLEND;
    sprite->callback = AnimForesightMagnifyingGlass_Step;
}

static void AnimForesightMagnifyingGlass_Step(struct Sprite *sprite)
{
    u16 x, y;

    switch (sprite->data[5])
    {
    case 0:
        switch (sprite->data[6])
        {
        default:
            sprite->data[6] = 0;
        case 0:
        case 4:
            x = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_RIGHT) - 4;
            y = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_BOTTOM) - 4;
            break;
        case 1:
            x = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_RIGHT) - 4;
            y = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_TOP) + 4;
            break;
        case 2:
            x = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_LEFT) + 4;
            y = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_BOTTOM) - 4;
            break;
        case 3:
            x = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_LEFT) + 4;
            y = GetBattlerSpriteCoordAttr(sprite->data[7], BATTLER_COORD_ATTR_TOP) - 4;
            break;
        case 5:
            x = GetBattlerSpriteCoord(sprite->data[7], BATTLER_COORD_X_2);
            y = GetBattlerSpriteCoord(sprite->data[7], BATTLER_COORD_Y_PIC_OFFSET);
            break;
        }

        if (sprite->data[6] == 4)
            sprite->data[0] = 24;
        else if (sprite->data[6] == 5)
            sprite->data[0] = 6;
        else
            sprite->data[0] = 12;

        sprite->data[1] = sprite->x;
        sprite->data[2] = x;
        sprite->data[3] = sprite->y;
        sprite->data[4] = y;
        InitAnimLinearTranslation(sprite);
        sprite->data[5]++;
        break;
    case 1:
        if (AnimTranslateLinear(sprite))
        {
            switch (sprite->data[6])
            {
            default:
                sprite->x += sprite->x2;
                sprite->y += sprite->y2;
                sprite->y2 = 0;
                sprite->x2 = 0;
                sprite->data[0] = 0;
                sprite->data[5]++;
                sprite->data[6]++;
                break;
            case 4:
                sprite->x += sprite->x2;
                sprite->y += sprite->y2;
                sprite->y2 = 0;
                sprite->x2 = 0;
                sprite->data[5] = 0;
                sprite->data[6]++;
                break;
            case 5:
                sprite->data[0] = 0;
                sprite->data[1] = 16;
                sprite->data[2] = 0;
                sprite->data[5] = 3;
                break;
            }
        }
        break;
    case 2:
        if (++sprite->data[0] == 4)
            sprite->data[5] = 0;
        break;
    case 3:
        if (!(sprite->data[0] & 1))
            sprite->data[1]--;
        else
            sprite->data[2]++;

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[1], sprite->data[2]));
        if (++sprite->data[0] == 32)
        {
            sprite->invisible = TRUE;
            sprite->data[5]++;
        }
        break;
    case 4:
        DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimMeteorMashStar_Step(struct Sprite *sprite)
{
    sprite->x2 = ((sprite->data[2] - sprite->data[0]) * sprite->data[5]) / sprite->data[4];
    sprite->y2 = ((sprite->data[3] - sprite->data[1]) * sprite->data[5]) / sprite->data[4];
    if (!(sprite->data[5] & 1))
    {
        CreateSprite(
            &gMiniTwinklingStarSpriteTemplate,
            sprite->x + sprite->x2,
            sprite->y + sprite->y2, 5);
    }

    if (sprite->data[5] == sprite->data[4])
        DestroyAnimSprite(sprite);

    sprite->data[5]++;
}

// Moves a shooting star across the screen that leaves little twinkling stars behind its path.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: destination x pixel offset
// arg 3: destination y pixel offset
// arg 4: duration
static void AnimMeteorMashStar(struct Sprite *sprite)
{
    s16 UNUSED y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    s16 UNUSED x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER || IsContest())
    {
        sprite->data[0] = sprite->x - gBattleAnimArgs[0];
        sprite->data[2] = sprite->x - gBattleAnimArgs[2];
    }
    else
    {
        sprite->data[0] = sprite->x + gBattleAnimArgs[0];
        sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    }

    sprite->data[1] = sprite->y + gBattleAnimArgs[1];
    sprite->data[3] = sprite->y + gBattleAnimArgs[3];
    sprite->data[4] = gBattleAnimArgs[4];
    sprite->x = sprite->data[0];
    sprite->y = sprite->data[1];
    sprite->callback = AnimMeteorMashStar_Step;
}

void AnimTask_MonToSubstitute(u8 taskId)
{
    int i;
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    if (gTasks[taskId].data[0] == 0)
    {
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        gTasks[taskId].data[1] = 0x100;
        gTasks[taskId].data[2] = 0x100;
        gTasks[taskId].data[0]++;
    }
    else if (gTasks[taskId].data[0] == 1)
    {
        gTasks[taskId].data[1] += 0x60;
        gTasks[taskId].data[2] -= 0xD;
        SetSpriteRotScale(spriteId, gTasks[taskId].data[1], gTasks[taskId].data[2], 0);
        if (++gTasks[taskId].data[3] == 9)
        {
            gTasks[taskId].data[3] = 0;
            ResetSpriteRotScale(spriteId);
            gSprites[spriteId].invisible = TRUE;
            gTasks[taskId].data[0]++;
        }
    }
    else
    {
        LoadBattleMonGfxAndAnimate(gBattleAnimAttacker, FALSE, spriteId);
        if (IsContest())
        {
            gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].affineAnims = gAffineAnims_BattleSpriteContest;
            StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimAttacker]], BATTLER_AFFINE_NORMAL);
        }

        for (i = 0; i < NUM_TASK_DATA; i++)
            gTasks[taskId].data[i] = 0;

        gTasks[taskId].func = AnimTask_MonToSubstituteDoll;
    }
}

static void AnimTask_MonToSubstituteDoll(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gSprites[spriteId].y2 = -200;
        gSprites[spriteId].x2 = 200;
        gSprites[spriteId].invisible = FALSE;
        gTasks[taskId].data[10] = 0;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[10] += 112;
        gSprites[spriteId].y2 += gTasks[taskId].data[10] >> 8;
        if (gSprites[spriteId].y + gSprites[spriteId].y2 >= -32)
            gSprites[spriteId].x2 = 0;

        if (gSprites[spriteId].y2 > 0)
            gSprites[spriteId].y2 = 0;

        if (gSprites[spriteId].y2 == 0)
        {
            PlaySE12WithPanning(SE_M_BUBBLE2, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
            gTasks[taskId].data[10] -= 0x800;
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        gTasks[taskId].data[10] -= 112;
        if (gTasks[taskId].data[10] < 0)
            gTasks[taskId].data[10] = 0;

        gSprites[spriteId].y2 -= gTasks[taskId].data[10] >> 8;
        if (gTasks[taskId].data[10] == 0)
            gTasks[taskId].data[0]++;
        break;
    case 3:
        gTasks[taskId].data[10] += 112;
        gSprites[spriteId].y2 += gTasks[taskId].data[10] >> 8;
        if (gSprites[spriteId].y2 > 0)
            gSprites[spriteId].y2 = 0;

        if (gSprites[spriteId].y2 == 0)
        {
            PlaySE12WithPanning(SE_M_BUBBLE2, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
            DestroyAnimVisualTask(taskId);
        }
        break;
    }
}

// Moves down an X that flickers and disappears.
// No args.
static void AnimBlockX(struct Sprite *sprite)
{
    s16 y;

    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 2;
        y = -144;
    }
    else
    {
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + 2;
        y = -96;
    }

    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->y2 = y;
    sprite->callback = AnimBlockX_Step;
}

static void AnimBlockX_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->y2 += 10;
        if (sprite->y2 >= 0)
        {
            PlaySE12WithPanning(SE_M_SKETCH, BattleAnimAdjustPanning(SOUND_PAN_TARGET));
            sprite->y2 = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        sprite->data[1] += 4;
        sprite->y2 = -(gSineTable[sprite->data[1]] >> 3);
        if (sprite->data[1] > 0x7F)
        {
            PlaySE12WithPanning(SE_M_SKETCH, BattleAnimAdjustPanning(SOUND_PAN_TARGET));
            sprite->data[1] = 0;
            sprite->y2 = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[1] += 6;
        sprite->y2 = -(gSineTable[sprite->data[1]] >> 4);
        if (sprite->data[1] > 0x7F)
        {
            sprite->data[1] = 0;
            sprite->y2 = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        if (++sprite->data[1] > 8)
        {
            PlaySE12WithPanning(SE_M_LEER, BattleAnimAdjustPanning(SOUND_PAN_TARGET));
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 4:
        if (++sprite->data[1] > 8)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            sprite->invisible = sprite->data[2] & 1;
            if (sprite->data[2] == 7)
                DestroyAnimSprite(sprite);
        }
        break;
    }
}

// Quickly moves two clones of the target mon back and forth.
// No args.
void AnimTask_OdorSleuthMovement(u8 taskId)
{
    s16 spriteId1, spriteId2;

    if (IsContest())
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    spriteId1 = CloneBattlerSpriteWithBlend(ANIM_TARGET);
    if (spriteId1 < 0)
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    spriteId2 = CloneBattlerSpriteWithBlend(ANIM_TARGET);
    if (spriteId2 < 0)
    {
        DestroySpriteWithActiveSheet(&gSprites[spriteId1]);
        DestroyAnimVisualTask(taskId);
        return;
    }

    gSprites[spriteId2].x2 += 24;
    gSprites[spriteId1].x2 -= 24;
    gSprites[spriteId2].data[0] = 0;
    gSprites[spriteId1].data[0] = 0;
    gSprites[spriteId2].data[1] = 0;
    gSprites[spriteId1].data[1] = 0;
    gSprites[spriteId2].data[2] = 0;
    gSprites[spriteId1].data[2] = 0;
    gSprites[spriteId2].data[3] = 16;
    gSprites[spriteId1].data[3] = -16;
    gSprites[spriteId2].data[4] = 0;
    gSprites[spriteId1].data[4] = 128;
    gSprites[spriteId2].data[5] = 24;
    gSprites[spriteId1].data[5] = 24;
    gSprites[spriteId2].data[6] = taskId;
    gSprites[spriteId1].data[6] = taskId;
    gSprites[spriteId2].data[7] = 0;
    gSprites[spriteId1].data[7] = 0;
    gTasks[taskId].data[0] = 2;

    if (!gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].invisible)
    {
        gSprites[spriteId2].invisible = FALSE;
        gSprites[spriteId1].invisible = TRUE;
    }
    else
    {
        gSprites[spriteId2].invisible = TRUE;
        gSprites[spriteId1].invisible = TRUE;
    }

    gSprites[spriteId2].oam.objMode = ST_OAM_OBJ_NORMAL;
    gSprites[spriteId1].oam.objMode = ST_OAM_OBJ_NORMAL;
    gSprites[spriteId2].callback = MoveOdorSleuthClone;
    gSprites[spriteId1].callback = MoveOdorSleuthClone;
    gTasks[taskId].func = AnimTask_OdorSleuthMovementWaitFinish;
}

static void AnimTask_OdorSleuthMovementWaitFinish(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
        DestroyAnimVisualTask(taskId);
}

static void MoveOdorSleuthClone(struct Sprite *sprite)
{
    if (++sprite->data[1] > 1)
    {
        sprite->data[1] = 0;
        if (!gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].invisible)
            sprite->invisible ^= 1;
    }

    sprite->data[4] = sprite->data[4] + sprite->data[3];
    sprite->data[4] &= 0xFF;
    sprite->x2 = Cos(sprite->data[4], sprite->data[5]);
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[2] == 60)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[2] > 0)
        {
            sprite->data[2] = 0;
            sprite->data[5] -= 2;
            if (sprite->data[5] < 0)
            {
                gTasks[sprite->data[6]].data[sprite->data[7]]--;
                DestroySpriteWithActiveSheet(sprite);
            }
        }
        break;
    }
}

void AnimTask_GetReturnPowerLevel(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = 0;
    if (gAnimFriendship < 60)
        gBattleAnimArgs[ARG_RET_ID] = 0;
    if (gAnimFriendship > 60 && gAnimFriendship < 92)
        gBattleAnimArgs[ARG_RET_ID] = 1;
    if (gAnimFriendship > 91 && gAnimFriendship < 201)
        gBattleAnimArgs[ARG_RET_ID] = 2;
    if (gAnimFriendship > 200)
        gBattleAnimArgs[ARG_RET_ID] = 3;

    DestroyAnimVisualTask(taskId);
}

// Makes the mon run out of screen, run past the opposing mon, and return to its original position.
// No args.
void AnimTask_SnatchOpposingMonMove(u8 taskId)
{
    u8 spriteId, spriteId2;
    int personality;
    int otId;
    u16 species;
    u8 subpriority;
    bool8 isBackPic;
    s16 x;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        gTasks[taskId].data[1] += 0x800;
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            gSprites[spriteId].x2 += (gTasks[taskId].data[1] >> 8);
        else
            gSprites[spriteId].x2 -= (gTasks[taskId].data[1] >> 8);

        gTasks[taskId].data[1] &= 0xFF;
        x = gSprites[spriteId].x + gSprites[spriteId].x2;
        if (x < -32 || x > DISPLAY_WIDTH + 32)
        {
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (IsContest())
        {
            personality = gContestResources->moveAnim->personality;
            otId = gContestResources->moveAnim->otId;
            species = gContestResources->moveAnim->species;
            subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker);
            isBackPic = FALSE;
            x = -32;
        }
        else
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            {
                personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_PERSONALITY);
                otId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_OT_ID);
                if (gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].transformSpecies == SPECIES_NONE)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_SPECIES);
                else
                    species = gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].transformSpecies;

                subpriority = gSprites[GetAnimBattlerSpriteId(ANIM_TARGET)].subpriority + 1;
                isBackPic = FALSE;
                x = DISPLAY_WIDTH + 32;
            }
            else
            {
                personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_PERSONALITY);
                otId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_OT_ID);
                if (gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].transformSpecies == SPECIES_NONE)
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_SPECIES);
                else
                    species = gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].transformSpecies;

                subpriority = gSprites[GetAnimBattlerSpriteId(ANIM_TARGET)].subpriority - 1;
                isBackPic = TRUE;
                x = -32;
            }
        }

        spriteId2 = CreateAdditionalMonSpriteForMoveAnim(species, isBackPic, 0, x, GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y), subpriority, personality, otId, gBattleAnimAttacker, FALSE);
        if (gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].transformSpecies != SPECIES_NONE)
            BlendPalette(OBJ_PLTT_ID(gSprites[spriteId2].oam.paletteNum), 16, 6, RGB_WHITE);

        gTasks[taskId].data[15] = spriteId2;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        spriteId2 = gTasks[taskId].data[15];
        gTasks[taskId].data[1] += 0x800;
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            gSprites[spriteId2].x2 -= (gTasks[taskId].data[1] >> 8);
        else
            gSprites[spriteId2].x2 += (gTasks[taskId].data[1] >> 8);

        gTasks[taskId].data[1] &= 0xFF;
        x = gSprites[spriteId2].x + gSprites[spriteId2].x2;
        if (gTasks[taskId].data[14] == 0)
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            {
                if (x < GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X))
                {
                    gTasks[taskId].data[14]++;
                    gBattleAnimArgs[7] = 0xFFFF;
                }
            }
            else
            {
                if (x > GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X))
                {
                    gTasks[taskId].data[14]++;
                    gBattleAnimArgs[7] = 0xFFFF;
                }
            }
        }

        if (x < -32 || x > DISPLAY_WIDTH + 32)
        {
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
        }
        break;
    case 3:
        spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        spriteId2 = gTasks[taskId].data[15];
        DestroySpriteAndFreeResources_(&gSprites[spriteId2]);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            gSprites[spriteId].x2 = -gSprites[spriteId].x - 32;
        else
            gSprites[spriteId].x2 = DISPLAY_WIDTH + 32 - gSprites[spriteId].x;

        gTasks[taskId].data[0]++;
        break;
    case 4:
        spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        gTasks[taskId].data[1] += 0x800;
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        {
            gSprites[spriteId].x2 += (gTasks[taskId].data[1] >> 8);
            if (gSprites[spriteId].x2 + gSprites[spriteId].x >= GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X))
                gSprites[spriteId].x2 = 0;
        }
        else
        {
            gSprites[spriteId].x2 -= (gTasks[taskId].data[1] >> 8);
            if (gSprites[spriteId].x2 + gSprites[spriteId].x <= GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X))
                gSprites[spriteId].x2 = 0;
        }

        gTasks[taskId].data[1] &= 0xFF;
        if (gSprites[spriteId].x2 == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimUnusedItemBagSteal(struct Sprite *sprite)
{
    switch (sprite->data[7])
    {
    case 0:
        if (gBattleAnimArgs[7] == -1)
        {
            PlaySE12WithPanning(SE_M_VITAL_THROW, BattleAnimAdjustPanning(SOUND_PAN_TARGET));
            sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + 16;
            sprite->data[0] = -32;
            sprite->data[7]++;
            sprite->invisible = FALSE;
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT && !IsContest())
                sprite->subpriority = gSprites[GetAnimBattlerSpriteId(ANIM_TARGET)].subpriority - 1;
        }
        else
        {
            sprite->invisible = TRUE;
        }
        break;
    case 1:
        sprite->y2 = Sin(sprite->data[1], sprite->data[0]);
        sprite->data[1] += 5;
        if (sprite->data[1] > 0x7F)
        {
            sprite->data[0] = sprite->data[0] / 2;
            sprite->data[3]++;
            sprite->data[1] -= 0x7F;
        }

        sprite->data[2] += 0x100;
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            sprite->x2 -= (sprite->data[2] >> 8);
        else
            sprite->x2 += (sprite->data[2] >> 8);

        sprite->data[2] &= 0xFF;
        if (sprite->data[3] == 2)
            DestroyAnimSprite(sprite);
        break;
    }
}

// Quickly moves the mon towards its partner and back.
// No args.
void AnimTask_SnatchPartnerMove(u8 taskId)
{
    s16 attackerX, targetX;
    u8 spriteId;

    switch (gTasks[taskId].data[15])
    {
    case 0:
        attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        gTasks[taskId].data[0] = 6;
        if (attackerX > targetX)
            gTasks[taskId].data[0] *= -1;

        gTasks[taskId].data[1] = attackerX;
        gTasks[taskId].data[2] = targetX;
        gTasks[taskId].data[15]++;
        break;
    case 1:
        spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
        gSprites[spriteId].x2 += gTasks[taskId].data[0];
        if (gTasks[taskId].data[0] > 0)
        {
            if (gSprites[spriteId].x + gSprites[spriteId].x2 >= gTasks[taskId].data[2])
                gTasks[taskId].data[15]++;
        }
        else
        {
            if (gSprites[spriteId].x + gSprites[spriteId].x2 <= gTasks[taskId].data[2])
                gTasks[taskId].data[15]++;
        }
        break;
    case 2:
        gTasks[taskId].data[0] *= -1;
        gTasks[taskId].data[15]++;
        break;
    case 3:
        spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
        gSprites[spriteId].x2 += gTasks[taskId].data[0];
        if (gTasks[taskId].data[0] < 0)
        {
            if (gSprites[spriteId].x + gSprites[spriteId].x2 <= gTasks[taskId].data[1])
                gTasks[taskId].data[15]++;
        }
        else
        {
            if (gSprites[spriteId].x + gSprites[spriteId].x2 >= gTasks[taskId].data[1])
                gTasks[taskId].data[15]++;
        }
        break;
    case 4:
    default:
        spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
        gSprites[spriteId].x2 = 0;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

// Moves the mon's sprite back and forth in an unpredictable swaying motion.
// No args.
void AnimTask_TeeterDanceMovement(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[3] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->data[4] = GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER ? 1 : -1;
    task->data[6] = gSprites[task->data[3]].y;
    task->data[5] = gSprites[task->data[3]].x;
    task->data[9] = 0;
    task->data[11] = 0;
    task->data[10] = 1;
    task->data[12] = 0;
    task->func = AnimTask_TeeterDanceMovement_Step;
}

static void AnimTask_TeeterDanceMovement_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        task->data[11] += 8;
        task->data[11] &= 0xFF;
        gSprites[task->data[3]].x2 = gSineTable[task->data[11]] >> 5;
        task->data[9] += 2;
        task->data[9] &= 0xFF;
        gSprites[task->data[3]].x = (gSineTable[task->data[9]] >> 3) * task->data[4] + task->data[5];
        if (task->data[9] == 0)
        {
            gSprites[task->data[3]].x = task->data[5];
            task->data[0]++;
        }
        break;
    case 1:
        task->data[11] += 8;
        task->data[11] &= 0xFF;
        gSprites[task->data[3]].x2 = gSineTable[task->data[11]] >> 5;
        if (task->data[11] == 0)
        {
            gSprites[task->data[3]].x2 = 0;
            task->data[0]++;
        }
        break;
    case 2:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimKnockOffStrike_Step(struct Sprite *sprite)
{
    // These two cases are identical.
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        sprite->data[1] += sprite->data[0];
        sprite->data[1] &= 0xFF;
    }
    else
    {
        sprite->data[1] += sprite->data[0];
        sprite->data[1] &= 0xFF;
    }

    sprite->x2 = Cos(sprite->data[1], 20);
    sprite->y2 = Sin(sprite->data[1], 20);
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);

    sprite->data[2]++;
}

// Animates a strike that swipes downard at the target mon.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
static void AnimKnockOffStrike(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        sprite->x -= gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[0] = -11;
        sprite->data[1] = 192;
        StartSpriteAffineAnim(sprite, 1);
    }
    else
    {
        sprite->data[0] = 11;
        sprite->data[1] = 192;
        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }

    sprite->callback = AnimKnockOffStrike_Step;
}

// Gradually fades a rotating recyle arrow sprite in and back out.
// No args.
static void AnimRecycle(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_TOP);
    if (sprite->y < 16)
        sprite->y = 16;

    sprite->data[6] = 0;
    sprite->data[7] = 16;
    sprite->callback = AnimRecycle_Step;
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
}

static void AnimRecycle_Step(struct Sprite *sprite)
{
    switch (sprite->data[2])
    {
    case 0:
        if (++sprite->data[0] > 1)
        {
            sprite->data[0] = 0;
            if (!(sprite->data[1] & 1))
            {
                if (sprite->data[6] < 16)
                    sprite->data[6]++;
            }
            else
            {
                if (sprite->data[7] != 0)
                    sprite->data[7]--;
            }

            sprite->data[1]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
            if (sprite->data[7] == 0)
                sprite->data[2]++;
        }
        break;
    case 1:
        if (++sprite->data[0] == 10)
        {
            sprite->data[0] = 0;
            sprite->data[1] = 0;
            sprite->data[2]++;
        }
        break;
    case 2:
        if (++sprite->data[0] > 1)
        {
            sprite->data[0] = 0;
            if (!(sprite->data[1] & 1))
            {
                if (sprite->data[6] != 0)
                    sprite->data[6]--;
            }
            else
            {
                if (sprite->data[7] < 16)
                    sprite->data[7]++;
            }

            sprite->data[1]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
            if (sprite->data[7] == 16)
                sprite->data[2]++;
        }
        break;
    case 3:
        DestroySpriteAndMatrix(sprite);
        break;
    }
}

void AnimTask_GetWeather(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_NONE;
    if (gWeatherMoveAnim & B_WEATHER_SUN)
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_SUN;
    else if (gWeatherMoveAnim & B_WEATHER_RAIN)
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_RAIN;
    else if (gWeatherMoveAnim & B_WEATHER_SANDSTORM)
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_SANDSTORM;
    else if (gWeatherMoveAnim & B_WEATHER_HAIL)
        gBattleAnimArgs[ARG_RET_ID] = ANIM_WEATHER_HAIL;

    DestroyAnimVisualTask(taskId);
}

// Squishes the mon sprite vertically, and shakes it back and forth.
// arg 0: which battler
void AnimTask_SlackOffSquish(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    PrepareAffineAnimInTaskData(task, task->data[15], gSlackOffSquishAffineAnimCmds);
    task->func = AnimTask_SlackOffSquish_Step;
}

static void AnimTask_SlackOffSquish_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] > 16 && gTasks[taskId].data[0] < 40)
    {
        if (++task->data[1] > 2)
        {
            task->data[1] = 0;
            task->data[2]++;
            if (!(task->data[2] & 1))
                gSprites[task->data[15]].x2 = -1;
            else
                gSprites[task->data[15]].x2 = 1;
        }
    }
    else
    {
        gSprites[task->data[15]].x2 = 0;
    }

    if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
        DestroyAnimVisualTask(taskId);
}
