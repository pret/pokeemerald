#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_scripts.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "math_util.h"
#include "menu.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "util.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#if IS_FRLG

#define INTRO_SPECIES SPECIES_NIDORAN_F

enum
{
    WIN_INTRO_TEXTBOX,
    WIN_INTRO_BOYGIRL,
    WIN_INTRO_YESNO,
    WIN_INTRO_NAMES,
    NUM_INTRO_WINDOWS,
};

struct OakSpeechResources
{
    void *oakSpeechBackgroundTiles;
    void *trainerPicTilemap;
    void *pikachuIntroTilemap;
    void *unused1;
    u16 hasPlayerBeenNamed;
    u16 currentPage;
    u16 windowIds[NUM_INTRO_WINDOWS];
    u8 textColor[3];
    u8 textSpeed;
    u8 unused2[0x1800];
    u8 bg2TilemapBuffer[0x400];
    u8 bg1TilemapBuffer[0x800];
};

static EWRAM_DATA struct OakSpeechResources *sOakSpeechResources = NULL;

static void Task_NewGameScene(u8);

static void ControlsGuide_LoadPage1(void);
static void Task_ControlsGuide_HandleInput(u8);
static void Task_ControlsGuide_ChangePage(u8);
static void Task_ControlsGuide_Clear(u8);

static void Task_PikachuIntro_LoadPage1(u8);
static void Task_PikachuIntro_HandleInput(u8);
static void Task_PikachuIntro_Clear(u8);

static void Task_OakSpeech_Init(u8);
static void Task_OakSpeech_WelcomeToTheWorld(u8);
static void Task_OakSpeech_ThisWorld(u8);
static void Task_OakSpeech_ReleaseNidoranFFromPokeBall(u8);
static void Task_OakSpeech_IsInhabitedFarAndWide(u8);
static void Task_OakSpeech_IStudyPokemon(u8);
static void Task_OakSpeech_ReturnNidoranFToPokeBall(u8);
static void Task_OakSpeech_TellMeALittleAboutYourself(u8);
static void Task_OakSpeech_FadeOutOak(u8);
static void Task_OakSpeech_AskPlayerGender(u8);
static void Task_OakSpeech_ShowGenderOptions(u8);
static void Task_OakSpeech_HandleGenderInput(u8);
static void Task_OakSpeech_ClearGenderWindows(u8);
static void Task_OakSpeech_LoadPlayerPic(u8);
static void Task_OakSpeech_YourNameWhatIsIt(u8);
static void Task_OakSpeech_FadeOutForPlayerNamingScreen(u8);
static void Task_OakSpeech_HandleRivalNameInput(u8);
static void Task_OakSpeech_DoNamingScreen(u8);
static void Task_OakSpeech_ConfirmName(u8);
static void Task_OakSpeech_HandleConfirmNameInput(u8);
static void Task_OakSpeech_FadeOutPlayerPic(u8);
static void Task_OakSpeech_FadeOutRivalPic(u8);
static void Task_OakSpeech_FadeInRivalPic(u8);
static void Task_OakSpeech_AskRivalsName(u8);
static void Task_OakSpeech_ReshowPlayersPic(u8);
static void Task_OakSpeech_LetsGo(u8);
static void Task_OakSpeech_FadeOutBGM(u8);
static void Task_OakSpeech_SetUpExitAnimation(u8);
static void Task_OakSpeech_SetUpShrinkPlayerPic(u8);
static void Task_OakSpeech_ShrinkPlayerPic(u8);
static void Task_OakSpeech_SetUpDestroyPlatformSprites(u8);
static void Task_OakSpeech_DestroyPlatformSprites(u8);
static void Task_OakSpeech_SetUpFadePlayerPicWhite(u8);
static void Task_OakSpeech_FadePlayerPicWhite(u8);
static void Task_OakSpeech_FadePlayerPicToBlack(u8);
static void Task_OakSpeech_WaitForFade(u8);
static void Task_OakSpeech_FreeResources(u8);

static void CB2_ReturnFromNamingScreen(void);
static void CreateNidoranFSprite(u8);
static void CreatePikachuOrPlatformSprites(u8, u8);
static void DestroyPikachuOrPlatformSprites(u8, u8);
static void LoadTrainerPic(u16, u16);
static void ClearTrainerPic(void);
static void CreateFadeInTask(u8, u8);
static void CreateFadeOutTask(u8, u8);
static void PrintNameChoiceOptions(u8, u8);
static void GetDefaultName(u8, u8);

extern const u8 gText_Controls[];
extern const u8 gText_Next[];
extern const u8 gText_NextBack[];
extern const struct OamData gOamData_AffineOff_ObjBlend_32x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_16x8;

static const u16 sOakSpeech_Background_Pals[] = INCGFX_U16("graphics/oak_speech/bg_tiles.png", ".gbapal"); // Shared by the Controls Guide, Pikachu Intro and Oak Speech scenes
static const u32 sControlsGuide_PikachuIntro_Background_Tiles[] = INCGFX_U32("graphics/oak_speech/bg_tiles.png", ".4bpp.smol");
static const u32 sPikachuIntro_Background_Tilemap[] = INCGFX_U32("graphics/oak_speech/pikachu_intro/tilemap.bin", ".smolTM");
static const u32 sOakSpeech_Background_Tiles[] = INCGFX_U32("graphics/oak_speech/oak_speech_bg.png", ".4bpp.smol");
static const u32 sOakSpeech_Background_Tilemap[] = INCGFX_U32("graphics/oak_speech/oak_speech_bg.bin", ".smolTM");
static const u16 sControlsGuide_Tilemap_Page2[] = INCBIN_U16("graphics/oak_speech/controls_guide_page_2.bin");
static const u16 sControlsGuide_Tilemap_Page3[] = INCBIN_U16("graphics/oak_speech/controls_guide_page_3.bin");
static const u16 sOakSpeech_Leaf_Pal[] = INCGFX_U16("graphics/oak_speech/leaf/pal.pal", ".gbapal");
static const u32 sOakSpeech_Leaf_Tiles[] = INCGFX_U32("graphics/oak_speech/leaf/pic.png", ".8bpp.smol");
static const u16 sOakSpeech_Red_Pal[] = INCGFX_U16("graphics/oak_speech/red/pal.pal", ".gbapal");
static const u32 sOakSpeech_Red_Tiles[] = INCGFX_U32("graphics/oak_speech/red/pic.png", ".8bpp.smol");
static const u16 sOakSpeech_Oak_Pal[] = INCGFX_U16("graphics/oak_speech/oak/pal.pal", ".gbapal");
static const u32 sOakSpeech_Oak_Tiles[] = INCGFX_U32("graphics/oak_speech/oak/pic.png", ".8bpp.smol");
static const u16 sOakSpeech_Rival_Pal[] = INCGFX_U16("graphics/oak_speech/rival/pal.pal", ".gbapal");
static const u32 sOakSpeech_Rival_Tiles[] = INCGFX_U32("graphics/oak_speech/rival/pic.png", ".8bpp.smol");
static const u16 sOakSpeech_Platform_Pal[] = INCGFX_U16("graphics/oak_speech/platform.pal", ".gbapal");
static const u16 sPikachuIntro_Pikachu_Pal[] = INCGFX_U16("graphics/oak_speech/pikachu_intro/pikachu.pal", ".gbapal");
static const u32 sOakSpeech_Platform_Gfx[] = INCGFX_U32("graphics/oak_speech/platform.png", ".4bpp.smol");
static const u32 sPikachuIntro_PikachuBody_Gfx[] = INCGFX_U32("graphics/oak_speech/pikachu_intro/body.png", ".4bpp.smol");
static const u32 sPikachuIntro_PikachuEars_Gfx[] = INCGFX_U32("graphics/oak_speech/pikachu_intro/ears.png", ".4bpp.smol");
static const u32 sPikachuIntro_PikachuEyes_Gfx[] = INCGFX_U32("graphics/oak_speech/pikachu_intro/eyes.png", ".4bpp.smol");

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 1,
        .baseTile = 0
    }
};

enum
{
    CONTROLS_GUIDE_PAGE_1_WINDOW,
    NUM_CONTROLS_GUIDE_PAGE_1_WINDOWS,
};

static const struct WindowTemplate sControlsGuide_WindowTemplate_Page1[NUM_CONTROLS_GUIDE_PAGE_1_WINDOWS + 1] =
{
    [CONTROLS_GUIDE_PAGE_1_WINDOW] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 7,
        .width = 30,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

enum
{
    CONTROLS_GUIDE_PAGES_2_3_WINDOW_TOP,
    CONTROLS_GUIDE_PAGES_2_3_WINDOW_MIDDLE,
    CONTROLS_GUIDE_PAGES_2_3_WINDOW_BOTTOM,
    NUM_CONTROLS_GUIDE_PAGES_2_3_WINDOWS,
};

static const struct WindowTemplate sControlsGuide_WindowTemplate_Page2[NUM_CONTROLS_GUIDE_PAGES_2_3_WINDOWS + 1] =
{
    [CONTROLS_GUIDE_PAGES_2_3_WINDOW_TOP] =
    {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 3,
        .width = 24,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [CONTROLS_GUIDE_PAGES_2_3_WINDOW_MIDDLE] =
    {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 10,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 146
    },
    [CONTROLS_GUIDE_PAGES_2_3_WINDOW_BOTTOM] =
    {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 243
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sControlsGuide_WindowTemplate_Page3[NUM_CONTROLS_GUIDE_PAGES_2_3_WINDOWS + 1] =
{
    [CONTROLS_GUIDE_PAGES_2_3_WINDOW_TOP] =
    {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 3,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [CONTROLS_GUIDE_PAGES_2_3_WINDOW_MIDDLE] =
    {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 8,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 98
    },
    [CONTROLS_GUIDE_PAGES_2_3_WINDOW_BOTTOM] =
    {
        .bg = 0,
        .tilemapLeft = 6,
        .tilemapTop = 13,
        .width = 24,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 195
    },
    DUMMY_WIN_TEMPLATE
};

enum
{
    CONTROLS_GUIDE_PAGE_1,
    CONTROLS_GUIDE_PAGE_2,
    CONTROLS_GUIDE_PAGE_3,
    NUM_CONTROLS_GUIDE_PAGES,
};

static const struct WindowTemplate *const sControlsGuide_WindowTemplates[NUM_CONTROLS_GUIDE_PAGES] =
{
    [CONTROLS_GUIDE_PAGE_1] = sControlsGuide_WindowTemplate_Page1,
    [CONTROLS_GUIDE_PAGE_2] = sControlsGuide_WindowTemplate_Page2,
    [CONTROLS_GUIDE_PAGE_3] = sControlsGuide_WindowTemplate_Page3
};

static const struct WindowTemplate sIntro_WindowTemplates[NUM_INTRO_WINDOWS + 1] =
{
    [WIN_INTRO_TEXTBOX] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 28,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WIN_INTRO_BOYGIRL] =
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 9,
        .width = 9,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 360
    },
    [WIN_INTRO_YESNO] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 360
    },
    [WIN_INTRO_NAMES] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 2,
        .width = 12,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

static const u8 sTextColor_White[] = { 0, 1, 2, 0 };
static const u8 sTextColor_DarkGray[] = { 0, 2, 3, 0 };

enum
{
    PIKACHU_INTRO_PAGE_1,
    PIKACHU_INTRO_PAGE_2,
    PIKACHU_INTRO_PAGE_3,
    NUM_PIKACHU_INTRO_PAGES,
};

static const u8 *const sPikachuIntro_Strings[NUM_PIKACHU_INTRO_PAGES] =
{
    [PIKACHU_INTRO_PAGE_1] = gPikachuIntro_Text_Page1,
    [PIKACHU_INTRO_PAGE_2] = gPikachuIntro_Text_Page2,
    [PIKACHU_INTRO_PAGE_3] = gPikachuIntro_Text_Page3
};

#define GFX_TAG_PLATFORM     0x1000
#define GFX_TAG_PIKACHU      0x1001
#define GFX_TAG_PIKACHU_EARS 0x1002
#define GFX_TAG_PIKACHU_EYES 0x1003

#define PAL_TAG_PLATFORM     0x1000
#define PAL_TAG_PIKACHU      0x1001

enum
{
    SPRITE_TYPE_PIKACHU,
    SPRITE_TYPE_PLATFORM,
};

enum
{
    PIKACHU_BODY_PLATFORM_LEFT,
    PIKACHU_EARS_PLATFORM_MIDDLE,
    PIKACHU_EYES_PLATFORM_RIGHT,
    NUM_PIKACHU_PLATFORM_SPRITES,
};

static const struct CompressedSpriteSheet sPikachuIntro_Pikachu_SpriteSheets[] =
{
    [PIKACHU_BODY_PLATFORM_LEFT] =
    {
        .data = sPikachuIntro_PikachuBody_Gfx,
        .size = 0x400,
        .tag = GFX_TAG_PIKACHU
    },
    [PIKACHU_EARS_PLATFORM_MIDDLE] =
    {
        .data = sPikachuIntro_PikachuEars_Gfx,
        .size = 0x200,
        .tag = GFX_TAG_PIKACHU_EARS
    },
    [PIKACHU_EYES_PLATFORM_RIGHT] =
    {
        .data = sPikachuIntro_PikachuEyes_Gfx,
        .size = 0x80,
        .tag = GFX_TAG_PIKACHU_EYES
    },
};

static const struct CompressedSpriteSheet sOakSpeech_Platform_SpriteSheet =
{
    .data = sOakSpeech_Platform_Gfx,
    .size = 0x600,
    .tag = GFX_TAG_PLATFORM
};

static const struct SpritePalette sPikachuIntro_Pikachu_SpritePalette =
{
    .data = sPikachuIntro_Pikachu_Pal,
    .tag = PAL_TAG_PIKACHU
};

static const struct SpritePalette sOakSpeech_Platform_SpritePalette =
{
    .data = sOakSpeech_Platform_Pal,
    .tag = PAL_TAG_PLATFORM
};

static const union AnimCmd sOakSpeech_PlatformLeft_Anim[] =
{
    ANIMCMD_FRAME( 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sOakSpeech_PlatformMiddle_Anim[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sOakSpeech_PlatformRight_Anim[] =
{
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sOakSpeech_PlatformLeft_Anims[] =
{
    sOakSpeech_PlatformLeft_Anim
};

static const union AnimCmd *const sOakSpeech_PlatformMiddle_Anims[] =
{
    sOakSpeech_PlatformMiddle_Anim
};

static const union AnimCmd *const sOakSpeech_PlatformRight_Anims[] =
{
    sOakSpeech_PlatformRight_Anim
};

static const struct SpriteTemplate sOakSpeech_Platform_SpriteTemplates[] =
{
    [PIKACHU_BODY_PLATFORM_LEFT] =
    {
        .tileTag = GFX_TAG_PLATFORM,
        .paletteTag = PAL_TAG_PLATFORM,
        .oam = &gOamData_AffineOff_ObjBlend_32x32,
        .anims = sOakSpeech_PlatformLeft_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    [PIKACHU_EARS_PLATFORM_MIDDLE] =
    {
        .tileTag = GFX_TAG_PLATFORM,
        .paletteTag = PAL_TAG_PLATFORM,
        .oam = &gOamData_AffineOff_ObjBlend_32x32,
        .anims = sOakSpeech_PlatformMiddle_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    [PIKACHU_EYES_PLATFORM_RIGHT] =
    {
        .tileTag = GFX_TAG_PLATFORM,
        .paletteTag = PAL_TAG_PLATFORM,
        .oam = &gOamData_AffineOff_ObjBlend_32x32,
        .anims = sOakSpeech_PlatformRight_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
};

static const union AnimCmd sPikachuIntro_PikachuBody_Anim[] =
{
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sPikachuIntro_PikachuEars_Anim[] =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sPikachuIntro_PikachuEyes_Anim[] =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(2,  8),
    ANIMCMD_FRAME(0,  8),
    ANIMCMD_FRAME(2,  8),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(2,  8),
    ANIMCMD_FRAME(0,  8),
    ANIMCMD_FRAME(2,  8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sPikachuIntro_PikachuBody_Anims[] =
{
    sPikachuIntro_PikachuBody_Anim
};

static const union AnimCmd *const sPikachuIntro_PikachuEars_Anims[] =
{
    sPikachuIntro_PikachuEars_Anim
};

static const union AnimCmd *const sPikachuIntro_PikachuEyes_Anims[] =
{
    sPikachuIntro_PikachuEyes_Anim
};

static const struct SpriteTemplate sPikachuIntro_Pikachu_SpriteTemplates[NUM_PIKACHU_PLATFORM_SPRITES] =
{
    [PIKACHU_BODY_PLATFORM_LEFT] =
    {
        .tileTag = GFX_TAG_PIKACHU,
        .paletteTag = PAL_TAG_PIKACHU,
        .oam = &gOamData_AffineOff_ObjNormal_32x32,
        .anims = sPikachuIntro_PikachuBody_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    [PIKACHU_EARS_PLATFORM_MIDDLE] =
    {
        .tileTag = GFX_TAG_PIKACHU_EARS,
        .paletteTag = PAL_TAG_PIKACHU,
        .oam = &gOamData_AffineOff_ObjNormal_32x16,
        .anims = sPikachuIntro_PikachuEars_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    [PIKACHU_EYES_PLATFORM_RIGHT] =
    {
        .tileTag = GFX_TAG_PIKACHU_EYES,
        .paletteTag = PAL_TAG_PIKACHU,
        .oam = &gOamData_AffineOff_ObjNormal_16x8,
        .anims = sPikachuIntro_PikachuEyes_Anims,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    }
};

#define CONTROLS_GUIDE_STRINGS_PER_PAGE 3

static const u8 *const sControlsGuide_Pages2And3_Strings[CONTROLS_GUIDE_STRINGS_PER_PAGE * 2] =
{
    // Page 2
    gControlsGuide_Text_DPad,
    gControlsGuide_Text_AButton,
    gControlsGuide_Text_BButton,
    // Page 3
    gControlsGuide_Text_StartButton,
    gControlsGuide_Text_SelectButton,
    gControlsGuide_Text_LRButtons
};

static const u8 *const sMaleNameChoices[] =
{
#if defined(FIRERED)
    gNameChoice_Red,
    gNameChoice_Fire,
    gNameChoice_Ash,
    gNameChoice_Kene,
    gNameChoice_Geki,
#else
    gNameChoice_Green,
    gNameChoice_Leaf,
    gNameChoice_Gary,
    gNameChoice_Kaz,
    gNameChoice_Toru,
#endif
    gNameChoice_Jak,
    gNameChoice_Janne,
    gNameChoice_Jonn,
    gNameChoice_Kamon,
    gNameChoice_Karl,
    gNameChoice_Taylor,
    gNameChoice_Oscar,
    gNameChoice_Hiro,
    gNameChoice_Max,
    gNameChoice_Jon,
    gNameChoice_Ralph,
    gNameChoice_Kay,
    gNameChoice_Tosh,
    gNameChoice_Roak
};

static const u8 *const sFemaleNameChoices[] =
{
#if defined(FIRERED)
    gNameChoice_Red,
    gNameChoice_Fire,
#else
    gNameChoice_Green,
    gNameChoice_Leaf,
#endif
    gNameChoice_Omi,
    gNameChoice_Jodi,
    gNameChoice_Amanda,
    gNameChoice_Hillary,
    gNameChoice_Makey,
    gNameChoice_Michi,
    gNameChoice_Paula,
    gNameChoice_June,
    gNameChoice_Cassie,
    gNameChoice_Rey,
    gNameChoice_Seda,
    gNameChoice_Kiko,
    gNameChoice_Mina,
    gNameChoice_Norie,
    gNameChoice_Sai,
    gNameChoice_Momo,
    gNameChoice_Suzi
};

static const u8 *const sRivalNameChoices[] =
{
#if defined(FIRERED)
    gNameChoice_Green,
    gNameChoice_Gary,
    gNameChoice_Kaz,
    gNameChoice_Toru
#else
    gNameChoice_Red,
    gNameChoice_Ash,
    gNameChoice_Kene,
    gNameChoice_Geki
#endif
};

enum
{
    MALE_PLAYER_PIC,
    FEMALE_PLAYER_PIC,
    RIVAL_PIC,
    OAK_PIC
};

static void VBlankCB_NewGameScene(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_NewGameScene(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void StartNewGameSceneFrlg(void)
{
    gPlttBufferUnfaded[0] = RGB_BLACK;
    gPlttBufferFaded[0]   = RGB_BLACK;
    CreateTask(Task_NewGameScene, 0);
    SetMainCallback2(CB2_NewGameScene);
}

#define tSpriteTimer                data[0]
#define tTrainerPicPosX             data[1]
#define tTrainerPicFadeState        data[2]
#define tTimer                      data[3]
#define tNidoranFSpriteId           data[4]
#define tTextCursorSpriteId         data[5]
#define tPokeBallSpriteId           data[6]
#define tPikachuPlatformSpriteId(i) data[7 + i] // Pikachu and the platform are built of three sprites,
                                 // data[8]     // so these are used to hold their sprite IDs
                                 // data[9]     //
#define tMenuWindowId               data[13]
#define tTextboxWindowId            data[14]
#define tDelta                      data[15]

static void Task_NewGameScene(u8 taskId)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, 0, PLTT + sizeof(u16), PLTT_SIZE - 2);
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTempTileDataBuffers();
        break;
    case 1:
        sOakSpeechResources = AllocZeroed(sizeof(*sOakSpeechResources));
        CreateMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A, MON_SPR_GFX_MODE_NORMAL);
        break;
    case 2:
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(1, sOakSpeechResources->bg1TilemapBuffer);
        SetBgTilemapBuffer(2, sOakSpeechResources->bg2TilemapBuffer);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        gSpriteCoordOffsetX = 0;
        gSpriteCoordOffsetY = 0;
        break;
    case 4:
        gPaletteFade.bufferTransferDisabled = TRUE;
        InitStandardTextBoxWindows();
        InitTextBoxGfxAndPrinters();
        Menu_LoadStdPalAt(BG_PLTT_ID(13));
        LoadPalette(sOakSpeech_Background_Pals, BG_PLTT_ID(0), sizeof(sOakSpeech_Background_Pals));
        LoadPalette(GetTextWindowPalette(2) + 15, BG_PLTT_ID(0), PLTT_SIZEOF(1));
        break;
    case 5:
        sOakSpeechResources->textSpeed = GetPlayerTextSpeedDelay();
        gTextFlags.canABSpeedUpPrint = TRUE;
        DecompressAndCopyTileDataToVram(1, sControlsGuide_PikachuIntro_Background_Tiles, 0, 0, 0);
        break;
    case 6:
        if (FreeTempTileDataBuffersIfPossible())
            return;
        ClearDialogWindowAndFrame(WIN_INTRO_TEXTBOX, TRUE);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 32);
        CopyBgTilemapBufferToVram(1);
        break;
    case 7:
        HofPCTopBar_AddWindow(0, 30, 0, 13, 0x1C4);
        FillBgTilemapBufferRect_Palette0(1, 0xD00F, 0,  0, 30, 2);
        FillBgTilemapBufferRect_Palette0(1, 0xD002, 0,  2, 30, 1);
        FillBgTilemapBufferRect_Palette0(1, 0xD00E, 0, 19, 30, 1);
        ControlsGuide_LoadPage1();
        gPaletteFade.bufferTransferDisabled = FALSE;
        gTasks[taskId].tTextCursorSpriteId = CreateTextCursorSprite(0, 230, 149, 0, 0);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        break;
    case 10:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        SetVBlankCallback(VBlankCB_NewGameScene);
        PlayBGM(MUS_RG_NEW_GAME_INSTRUCT);
        gTasks[taskId].func = Task_ControlsGuide_HandleInput;
        gMain.state = 0;
        return;
    }

    gMain.state++;
}

static void ControlsGuide_LoadPage1(void)
{
    HofPCTopBar_PrintPair(gText_Controls, gText_Next, FALSE, 0, TRUE);
    sOakSpeechResources->windowIds[0] = AddWindow(sControlsGuide_WindowTemplates[sOakSpeechResources->currentPage]);
    PutWindowTilemap(sOakSpeechResources->windowIds[0]);
    FillWindowPixelBuffer(sOakSpeechResources->windowIds[0], PIXEL_FILL(0));
    AddTextPrinterParameterized4(sOakSpeechResources->windowIds[0], FONT_NORMAL, 2, 0, 1, 1, sTextColor_White, 0, gControlsGuide_Text_Intro);
    CopyWindowToVram(sOakSpeechResources->windowIds[0], COPYWIN_FULL);
    FillBgTilemapBufferRect_Palette0(1, 0x3000, 1, 3, 5, 16);
    CopyBgTilemapBufferToVram(1);
}

static void Task_ControlsGuide_LoadPage(u8 taskId)
{
    u8 currWindow = 0;
    u8 page2Or3 = sOakSpeechResources->currentPage - 1; // 0 if page 2, 1 if page 3
    if (sOakSpeechResources->currentPage == CONTROLS_GUIDE_PAGE_1)
    {
        ControlsGuide_LoadPage1();
    }
    else
    {
        HofPCTopBar_Print(gText_NextBack, 0, TRUE);
        for (currWindow = CONTROLS_GUIDE_PAGES_2_3_WINDOW_TOP; currWindow < NUM_CONTROLS_GUIDE_PAGES_2_3_WINDOWS; currWindow++)
        {
            sOakSpeechResources->windowIds[currWindow] = AddWindow(&sControlsGuide_WindowTemplates[sOakSpeechResources->currentPage][currWindow]);
            PutWindowTilemap(sOakSpeechResources->windowIds[currWindow]);
            FillWindowPixelBuffer(sOakSpeechResources->windowIds[currWindow], PIXEL_FILL(0));
            AddTextPrinterParameterized4(sOakSpeechResources->windowIds[currWindow], FONT_NORMAL, 6, 0, 1, 1, sTextColor_White, 0, sControlsGuide_Pages2And3_Strings[currWindow + page2Or3 * CONTROLS_GUIDE_STRINGS_PER_PAGE]);
            CopyWindowToVram(sOakSpeechResources->windowIds[currWindow], COPYWIN_FULL);
        }

        if (sOakSpeechResources->currentPage == CONTROLS_GUIDE_PAGE_2)
            CopyToBgTilemapBufferRect(1, sControlsGuide_Tilemap_Page2, 1, 3, 5, 16);
        else // CONTROLS_GUIDE_PAGE_3
            CopyToBgTilemapBufferRect(1, sControlsGuide_Tilemap_Page3, 1, 3, 5, 16);
        CopyBgTilemapBufferToVram(1);
    }
    BeginNormalPaletteFade(PALETTES_OBJECTS | 0xDFFF, -1, 16, 0, GetTextWindowPalette(2)[15]);
    gTasks[taskId].func = Task_ControlsGuide_HandleInput;
}

static void Task_ControlsGuide_HandleInput(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (JOY_NEW((A_BUTTON | B_BUTTON)))
        {
            if (JOY_NEW(A_BUTTON))
            {
                gTasks[taskId].tDelta = 1;

                if (sOakSpeechResources->currentPage < CONTROLS_GUIDE_PAGE_3)
                    BeginNormalPaletteFade(PALETTES_OBJECTS | 0xDFFF, -1, 0, 16, GetTextWindowPalette(2)[15]);
            }
            else // B_BUTTON
            {
                if (sOakSpeechResources->currentPage == CONTROLS_GUIDE_PAGE_1)
                    return;

                gTasks[taskId].tDelta = -1;
                BeginNormalPaletteFade(PALETTES_OBJECTS | 0xDFFF, -1, 0, 16, GetTextWindowPalette(2)[15]);
            }

            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_ControlsGuide_ChangePage;
        }
    }
}

static void Task_ControlsGuide_ChangePage(u8 taskId)
{
    u8 numWindows = 0;
    u8 i;

    if (!gPaletteFade.active)
    {
        switch (sOakSpeechResources->currentPage)
        {
        case CONTROLS_GUIDE_PAGE_1:
            numWindows = NUM_CONTROLS_GUIDE_PAGE_1_WINDOWS;
            break;
        case CONTROLS_GUIDE_PAGE_2:
        case CONTROLS_GUIDE_PAGE_3:
            numWindows = NUM_CONTROLS_GUIDE_PAGES_2_3_WINDOWS;
            break;
        }
        sOakSpeechResources->currentPage += gTasks[taskId].tDelta;
        if (sOakSpeechResources->currentPage < NUM_CONTROLS_GUIDE_PAGES)
        {
            for (i = 0; i < numWindows; i++)
            {
                FillWindowPixelBuffer(sOakSpeechResources->windowIds[i], PIXEL_FILL(0));
                ClearWindowTilemap(sOakSpeechResources->windowIds[i]);
                CopyWindowToVram(sOakSpeechResources->windowIds[i], COPYWIN_FULL);
                RemoveWindow(sOakSpeechResources->windowIds[i]);
                sOakSpeechResources->windowIds[i] = 0;
            }
            gTasks[taskId].func = Task_ControlsGuide_LoadPage;
        }
        else
        {
            BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, 0);
            gTasks[taskId].func = Task_ControlsGuide_Clear;
        }
    }
}

#undef tDelta

static void Task_ControlsGuide_Clear(u8 taskId)
{
    u8 i = 0;
    if (!gPaletteFade.active)
    {
        for (i = 0; i < NUM_CONTROLS_GUIDE_PAGES_2_3_WINDOWS; i++)
        {
            FillWindowPixelBuffer(sOakSpeechResources->windowIds[i], PIXEL_FILL(0));
            ClearWindowTilemap(sOakSpeechResources->windowIds[i]);
            CopyWindowToVram(sOakSpeechResources->windowIds[i], COPYWIN_FULL);
            RemoveWindow(sOakSpeechResources->windowIds[i]);
            sOakSpeechResources->windowIds[i] = 0;
        }
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 2, 30, 18);
        CopyBgTilemapBufferToVram(1);
        DestroyTextCursorSprite(gTasks[taskId].tTextCursorSpriteId);
        sOakSpeechResources->windowIds[0] = RGB_BLACK;
        LoadPalette(sOakSpeechResources->windowIds, BG_PLTT_ID(0), PLTT_SIZEOF(1));
        gTasks[taskId].tTimer = 32;
        gTasks[taskId].func = Task_PikachuIntro_LoadPage1;
    }
}

enum
{
    PIKACHU_INTRO_SET_GPU_REGS,
    PIKACHU_INTRO_HANDLE_INPUT,
    PIKACHU_INTRO_PRINT_PAGE_TEXT,
    PIKACHU_INTRO_FADE_IN_PAGE,
    PIKACHU_INTRO_EXIT,
};

#define tBlendTarget data[15]

static void Task_PikachuIntro_LoadPage1(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u32 size = 0;

    if (tTimer != 0)
    {
        tTimer--;
    }
    else
    {
        PlayBGM(MUS_RG_NEW_GAME_INTRO);
        HofPCTopBar_Clear();
        HofPCTopBar_Print(gText_Next, 0, 1);
        sOakSpeechResources->pikachuIntroTilemap = malloc_and_decompress(sPikachuIntro_Background_Tilemap, &size);
        CopyToBgTilemapBufferRect(1, sOakSpeechResources->pikachuIntroTilemap, 0, 2, 30, 19);
        CopyBgTilemapBufferToVram(1);
        Free(sOakSpeechResources->pikachuIntroTilemap);
        sOakSpeechResources->pikachuIntroTilemap = NULL;
        tTextboxWindowId = AddWindow(&sIntro_WindowTemplates[WIN_INTRO_TEXTBOX]);
        PutWindowTilemap(tTextboxWindowId);
        FillWindowPixelBuffer(tTextboxWindowId, PIXEL_FILL(0));
        CopyWindowToVram(tTextboxWindowId, COPYWIN_FULL);
        sOakSpeechResources->currentPage = PIKACHU_INTRO_PAGE_1;
        gMain.state = PIKACHU_INTRO_SET_GPU_REGS;
        tBlendTarget = 16;
        AddTextPrinterParameterized4(tTextboxWindowId, FONT_NORMAL, 3, 5, 1, 0, sTextColor_DarkGray, 0, sPikachuIntro_Strings[PIKACHU_INTRO_PAGE_1]);
        tTextCursorSpriteId = CreateTextCursorSprite(0, 226, 145, 0, 0);
        gSprites[tTextCursorSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[tTextCursorSpriteId].oam.priority = 0;
        CreatePikachuOrPlatformSprites(taskId, SPRITE_TYPE_PIKACHU);
        BeginNormalPaletteFade(PALETTES_ALL, 2, 16, 0, 0);
        gTasks[taskId].func = Task_PikachuIntro_HandleInput;
    }
}

static void Task_PikachuIntro_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (gMain.state)
    {
    case PIKACHU_INTRO_SET_GPU_REGS:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
            SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(16, DISPLAY_HEIGHT));
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_CLR | WININ_WIN0_OBJ);
            SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
            gMain.state = PIKACHU_INTRO_HANDLE_INPUT;
        }
        break;
    case PIKACHU_INTRO_HANDLE_INPUT:
        if (JOY_NEW((A_BUTTON | B_BUTTON)))
        {
            if (JOY_NEW(A_BUTTON))
            {
                sOakSpeechResources->currentPage++;
            }
            else // B_BUTTON
            {
                if (sOakSpeechResources->currentPage != PIKACHU_INTRO_PAGE_1)
                    sOakSpeechResources->currentPage--;
                else
                    break;
            }
            PlaySE(SE_SELECT);
            if (sOakSpeechResources->currentPage == NUM_PIKACHU_INTRO_PAGES)
            {
                gMain.state = PIKACHU_INTRO_EXIT;
            }
            else
            {
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1);
                SetGpuReg(REG_OFFSET_BLDALPHA, (16 - tBlendTarget) | tBlendTarget);
                gMain.state++;
            }
        }
        break;
    case PIKACHU_INTRO_PRINT_PAGE_TEXT:
        tBlendTarget -= 2;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tBlendTarget, 16 - tBlendTarget));
        if (tBlendTarget <= 0)
        {
            FillWindowPixelBuffer(tTextboxWindowId, PIXEL_FILL(0));
            AddTextPrinterParameterized4(tTextboxWindowId, FONT_NORMAL, 3, 5, 1, 0, sTextColor_DarkGray, 0, sPikachuIntro_Strings[sOakSpeechResources->currentPage]);
            if (sOakSpeechResources->currentPage == PIKACHU_INTRO_PAGE_1)
            {
                HofPCTopBar_Clear();
                HofPCTopBar_Print(gText_Next, 0, 1);
            }
            else
            {
                HofPCTopBar_Clear();
                HofPCTopBar_Print(gText_NextBack, 0, 1);
            }
            gMain.state++;
        }
        break;
    case PIKACHU_INTRO_FADE_IN_PAGE:
        tBlendTarget += 2;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tBlendTarget, 16 - tBlendTarget));
        if (tBlendTarget >= 16)
        {
            tBlendTarget = 16;
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            gMain.state = PIKACHU_INTRO_HANDLE_INPUT;
        }
        break;
    case PIKACHU_INTRO_EXIT:
        DestroyTextCursorSprite(gTasks[taskId].tTextCursorSpriteId);
        PlayBGM(MUS_RG_NEW_GAME_EXIT);
        tBlendTarget = 24;
        gMain.state++;
        break;
    default:
        if (tBlendTarget != 0)
        {
            tBlendTarget--;
        }
        else
        {
            gMain.state = 0;
            sOakSpeechResources->currentPage = 0;
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
            BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_PikachuIntro_Clear;
        }
        break;
    }
}

#undef tBlendTarget

static void Task_PikachuIntro_Clear(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        HofPCTopBar_RemoveWindow();
        FillWindowPixelBuffer(tTextboxWindowId, PIXEL_FILL(0));
        ClearWindowTilemap(tTextboxWindowId);
        CopyWindowToVram(tTextboxWindowId, COPYWIN_FULL);
        RemoveWindow(tTextboxWindowId);
        tTextboxWindowId = 0;
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(1);
        DestroyPikachuOrPlatformSprites(taskId, SPRITE_TYPE_PIKACHU);
        tTimer = 80;
        gTasks[taskId].func = Task_OakSpeech_Init;
    }
}

static void Task_OakSpeech_Init(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u32 size = 0;
    if (tTimer != 0)
    {
        tTimer--;
    }
    else
    {
        sOakSpeechResources->oakSpeechBackgroundTiles = malloc_and_decompress(sOakSpeech_Background_Tiles, &size);
        LoadBgTiles(1, sOakSpeechResources->oakSpeechBackgroundTiles, size, 0);
        CopyToBgTilemapBuffer(1, sOakSpeech_Background_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CreateNidoranFSprite(taskId);
        LoadTrainerPic(OAK_PIC, 0);
        CreatePikachuOrPlatformSprites(taskId, SPRITE_TYPE_PLATFORM);
        PlayBGM(MUS_RG_ROUTE24);
        BeginNormalPaletteFade(PALETTES_ALL, 5, 16, 0, RGB_BLACK);
        tTimer = 80;
        ShowBg(2);
        gTasks[taskId].func = Task_OakSpeech_WelcomeToTheWorld;
    }
}

static inline void OakSpeechPrintMessage(const u8 *str, u8 speed, bool32 isStringVar4)
{
    DrawDialogueFrame(WIN_INTRO_TEXTBOX, FALSE);
    if (!isStringVar4)
    {
        StringExpandPlaceholders(gStringVar4, str);
        AddTextPrinterParameterized2(WIN_INTRO_TEXTBOX, FONT_MALE, gStringVar4, speed, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    }
    else
    {
        AddTextPrinterParameterized2(WIN_INTRO_TEXTBOX, FONT_MALE, str, speed, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    }
    CopyWindowToVram(WIN_INTRO_TEXTBOX, COPYWIN_FULL);
}

static void Task_OakSpeech_WelcomeToTheWorld(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        if (tTimer != 0)
        {
            tTimer--;
        }
        else
        {
            OakSpeechPrintMessage(gOakSpeech_Text_WelcomeToTheWorld, sOakSpeechResources->textSpeed, FALSE);
            gTasks[taskId].func = Task_OakSpeech_ThisWorld;
        }
    }
}

static void Task_OakSpeech_ThisWorld(u8 taskId)
{
    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        OakSpeechPrintMessage(gOakSpeech_Text_ThisWorld, sOakSpeechResources->textSpeed, FALSE);
        gTasks[taskId].tTimer = 30;
        gTasks[taskId].func = Task_OakSpeech_ReleaseNidoranFFromPokeBall;
    }
}

static void Task_OakSpeech_ReleaseNidoranFFromPokeBall(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 spriteId;

    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        if (tTimer != 0)
            tTimer--;
        spriteId = gTasks[taskId].tNidoranFSpriteId;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].tSpriteTimer = 0;
        CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 100, 66, 0, 0, 32, 0xFFFF1FFF, INTRO_SPECIES);
        gTasks[taskId].func = Task_OakSpeech_IsInhabitedFarAndWide;
        gTasks[taskId].tTimer = 0;
    }
}

static void Task_OakSpeech_IsInhabitedFarAndWide(u8 taskId)
{
    if (IsCryFinished())
    {
        if (gTasks[taskId].tTimer >= 96)
            gTasks[taskId].func = Task_OakSpeech_IStudyPokemon;
    }
    if (gTasks[taskId].tTimer < 0x4000)
    {
        gTasks[taskId].tTimer++;
        if (gTasks[taskId].tTimer == 32)
        {
            OakSpeechPrintMessage(gOakSpeech_Text_IsInhabitedFarAndWide, sOakSpeechResources->textSpeed, FALSE);
            PlayCry_Normal(INTRO_SPECIES, 0);
        }
    }
}

static void Task_OakSpeech_IStudyPokemon(u8 taskId)
{
    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        OakSpeechPrintMessage(gOakSpeech_Text_IStudyPokemon, sOakSpeechResources->textSpeed, FALSE);
        gTasks[taskId].func = Task_OakSpeech_ReturnNidoranFToPokeBall;
    }
}

static void Task_OakSpeech_ReturnNidoranFToPokeBall(u8 taskId)
{
    u8 spriteId;

    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        ClearDialogWindowAndFrame(WIN_INTRO_TEXTBOX, TRUE);
        spriteId = gTasks[taskId].tNidoranFSpriteId;
        gTasks[taskId].tPokeBallSpriteId = CreateTradePokeballSprite(spriteId, gSprites[spriteId].oam.paletteNum, 100, 66, 0, 0, 32, 0xFFFF1F3F);
        gTasks[taskId].tTimer = 48;
        gTasks[taskId].tSpriteTimer = 64;
        gTasks[taskId].func = Task_OakSpeech_TellMeALittleAboutYourself;
    }
}

static void Task_OakSpeech_TellMeALittleAboutYourself(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tSpriteTimer != 0)
    {
        if (tSpriteTimer < 24)
            gSprites[tNidoranFSpriteId].y--;
        tSpriteTimer--;
    }
    else
    {
        if (tTimer == 48)
        {
            DestroySprite(&gSprites[tNidoranFSpriteId]);
            DestroySprite(&gSprites[tPokeBallSpriteId]);
        }
        if (tTimer != 0)
        {
            tTimer--;
        }
        else
        {
            OakSpeechPrintMessage(gOakSpeech_Text_TellMeALittleAboutYourself, sOakSpeechResources->textSpeed, FALSE);
            gTasks[taskId].func = Task_OakSpeech_FadeOutOak;
        }
    }
}

static void Task_OakSpeech_FadeOutOak(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        ClearDialogWindowAndFrame(WIN_INTRO_TEXTBOX, 1);
        CreateFadeInTask(taskId, 2);
        tTimer = 48;
        gTasks[taskId].func = Task_OakSpeech_AskPlayerGender;
    }
}

static void Task_OakSpeech_AskPlayerGender(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        if (tTimer != 0)
        {
            tTimer--;
        }
        else
        {
            tTrainerPicPosX = -60;
            ClearTrainerPic();
            OakSpeechPrintMessage(gOakSpeech_Text_AskPlayerGender, sOakSpeechResources->textSpeed, FALSE);
            gTasks[taskId].func = Task_OakSpeech_ShowGenderOptions;
        }
    }
}

static void Task_OakSpeech_ShowGenderOptions(u8 taskId)
{
    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        gTasks[taskId].tMenuWindowId = AddWindow(&sIntro_WindowTemplates[WIN_INTRO_BOYGIRL]);
        PutWindowTilemap(gTasks[taskId].tMenuWindowId);
        DrawStdFrameWithCustomTileAndPalette(gTasks[taskId].tMenuWindowId, TRUE, STD_WINDOW_BASE_TILE_NUM, 14);
        FillWindowPixelBuffer(gTasks[taskId].tMenuWindowId, PIXEL_FILL(1));
        sOakSpeechResources->textColor[0] = 1;
        sOakSpeechResources->textColor[1] = 2;
        sOakSpeechResources->textColor[2] = 3;
        AddTextPrinterParameterized3(gTasks[taskId].tMenuWindowId, FONT_NORMAL, 8, 1, sOakSpeechResources->textColor, 0, gText_Boy);
        sOakSpeechResources->textColor[0] = 1;
        sOakSpeechResources->textColor[1] = 2;
        sOakSpeechResources->textColor[2] = 3;
        AddTextPrinterParameterized3(gTasks[taskId].tMenuWindowId, FONT_NORMAL, 8, 17, sOakSpeechResources->textColor, 0, gText_Girl);
        InitMenuNormal(gTasks[taskId].tMenuWindowId, FONT_NORMAL, 0, 1, GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT) + 2, 2, 0);
        CopyWindowToVram(gTasks[taskId].tMenuWindowId, COPYWIN_FULL);
        gTasks[taskId].func = Task_OakSpeech_HandleGenderInput;
    }
}

static void Task_OakSpeech_HandleGenderInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrap();
    switch (input)
    {
    case 0: // BOY
        gSaveBlock2Ptr->playerGender = MALE;
        break;
    case 1: // GIRL
        gSaveBlock2Ptr->playerGender = FEMALE;
        break;
    case MENU_B_PRESSED:
    case MENU_NOTHING_CHOSEN:
        return;
    }
    gTasks[taskId].func = Task_OakSpeech_ClearGenderWindows;

}

static void Task_OakSpeech_ClearGenderWindows(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ClearStdWindowAndFrameToTransparent(tMenuWindowId, TRUE);
    RemoveWindow(tMenuWindowId);
    tMenuWindowId = WIN_INTRO_TEXTBOX;
    ClearDialogWindowAndFrame(tMenuWindowId, TRUE);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
    gTasks[taskId].func = Task_OakSpeech_LoadPlayerPic;
}

static void Task_OakSpeech_LoadPlayerPic(u8 taskId)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        LoadTrainerPic(MALE_PLAYER_PIC, 0);
    else
        LoadTrainerPic(FEMALE_PLAYER_PIC, 0);
    CreateFadeOutTask(taskId, 2);
    gTasks[taskId].tTimer = 32;
    gTasks[taskId].func = Task_OakSpeech_YourNameWhatIsIt;
}

static void Task_OakSpeech_YourNameWhatIsIt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        if (tTimer != 0)
        {
            tTimer--;
        }
        else
        {
            tTrainerPicPosX = 0;
            OakSpeechPrintMessage(gOakSpeech_Text_YourNameWhatIsIt, sOakSpeechResources->textSpeed, FALSE);
            gTasks[taskId].func = Task_OakSpeech_FadeOutForPlayerNamingScreen;
        }
    }
}

static void Task_OakSpeech_FadeOutForPlayerNamingScreen(u8 taskId)
{
    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sOakSpeechResources->hasPlayerBeenNamed = FALSE;
        gTasks[taskId].func = Task_OakSpeech_DoNamingScreen;
    }
}

static void Task_OakSpeech_MoveRivalDisplayNameOptions(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        if (tTrainerPicPosX > -60)
        {
            tTrainerPicPosX -= 2;
            gSpriteCoordOffsetX += 2;
            ChangeBgX(2, 0x200, BG_COORD_SUB);
        }
        else
        {
            tTrainerPicPosX = -60;
            PrintNameChoiceOptions(taskId, sOakSpeechResources->hasPlayerBeenNamed);
            gTasks[taskId].func = Task_OakSpeech_HandleRivalNameInput;
        }
    }
}

static void Task_OakSpeech_RepeatNameQuestion(u8 taskId)
{
    PrintNameChoiceOptions(taskId, sOakSpeechResources->hasPlayerBeenNamed);
    if (sOakSpeechResources->hasPlayerBeenNamed == FALSE)
        OakSpeechPrintMessage(gOakSpeech_Text_YourNameWhatIsIt, 0, FALSE);
    else
        OakSpeechPrintMessage(gOakSpeech_Text_YourRivalsNameWhatWasIt, 0, FALSE);
    gTasks[taskId].func = Task_OakSpeech_HandleRivalNameInput;
}

#define tNameNotConfirmed data[15]

static void Task_OakSpeech_HandleRivalNameInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 input = Menu_ProcessInput();
    switch (input)
    {
    case 0: // NEW NAME
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_OakSpeech_DoNamingScreen;
        break;
    case 1: // Default name options
    case 2: //
    case 3: //
    case 4: //
        PlaySE(SE_SELECT);
        ClearStdWindowAndFrameToTransparent(tMenuWindowId, TRUE);
        RemoveWindow(tMenuWindowId);
        GetDefaultName(sOakSpeechResources->hasPlayerBeenNamed, input - 1);
        tNameNotConfirmed = TRUE;
        gTasks[taskId].func = Task_OakSpeech_ConfirmName;
        break;
    case MENU_B_PRESSED:
        break;
    }
}

static void Task_OakSpeech_DoNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        GetDefaultName(sOakSpeechResources->hasPlayerBeenNamed, 0);
        if (sOakSpeechResources->hasPlayerBeenNamed == FALSE)
        {
            DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnFromNamingScreen);
        }
        else
        {
            ClearStdWindowAndFrameToTransparent(gTasks[taskId].tMenuWindowId, TRUE);
            RemoveWindow(gTasks[taskId].tMenuWindowId);
            DoNamingScreen(NAMING_SCREEN_RIVAL, gSaveBlock1Ptr->rivalName, 0, 0, 0, CB2_ReturnFromNamingScreen);
        }
        DestroyPikachuOrPlatformSprites(taskId, SPRITE_TYPE_PLATFORM);
        FreeAllWindowBuffers();
    }
}

static void Task_OakSpeech_ConfirmName(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        if (tNameNotConfirmed == TRUE)
        {
            if (sOakSpeechResources->hasPlayerBeenNamed == FALSE)
                StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_SoYourNameIsPlayer);
            else
                StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_ConfirmRivalName);
            OakSpeechPrintMessage(gStringVar4, sOakSpeechResources->textSpeed, TRUE);
            tNameNotConfirmed = FALSE;
            tTimer = 25;
        }
        else if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
        {
            if (tTimer != 0)
            {
                tTimer--;
            }
            else
            {
                CreateYesNoMenuAtPos(&sIntro_WindowTemplates[WIN_INTRO_YESNO], FONT_NORMAL, 0, 2, STD_WINDOW_BASE_TILE_NUM, 14, 0);
                gTasks[taskId].func = Task_OakSpeech_HandleConfirmNameInput;
            }
        }
    }
}

static void Task_OakSpeech_HandleConfirmNameInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    switch (input)
    {
    case 0: // YES
        PlaySE(SE_SELECT);
        gTasks[taskId].tTimer = 40;
        if (sOakSpeechResources->hasPlayerBeenNamed == FALSE)
        {
            ClearDialogWindowAndFrame(WIN_INTRO_TEXTBOX, TRUE);
            CreateFadeInTask(taskId, 2);
            gTasks[taskId].func = Task_OakSpeech_FadeOutPlayerPic;
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_RememberRivalsName);
            OakSpeechPrintMessage(gStringVar4, sOakSpeechResources->textSpeed, TRUE);
            gTasks[taskId].func = Task_OakSpeech_FadeOutRivalPic;
        }
        break;
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        if (sOakSpeechResources->hasPlayerBeenNamed == FALSE)
            gTasks[taskId].func = Task_OakSpeech_FadeOutForPlayerNamingScreen;
        else
            gTasks[taskId].func = Task_OakSpeech_RepeatNameQuestion;
        break;
    }
}

static void Task_OakSpeech_FadeOutPlayerPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        ClearTrainerPic();
        if (tTimer != 0)
            tTimer--;
        else
            gTasks[taskId].func = Task_OakSpeech_FadeInRivalPic;
    }
}

static void Task_OakSpeech_FadeOutRivalPic(u8 taskId)
{
    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        ClearDialogWindowAndFrame(WIN_INTRO_TEXTBOX, TRUE);
        CreateFadeInTask(taskId, 2);
        gTasks[taskId].func = Task_OakSpeech_ReshowPlayersPic;
    }
}

static void Task_OakSpeech_FadeInRivalPic(u8 taskId)
{
    ChangeBgX(2, 0, BG_COORD_SET);
    gTasks[taskId].tTrainerPicPosX = 0;
    gSpriteCoordOffsetX = 0;
    LoadTrainerPic(RIVAL_PIC, 0);
    CreateFadeOutTask(taskId, 2);
    gTasks[taskId].func = Task_OakSpeech_AskRivalsName;
}

static void Task_OakSpeech_AskRivalsName(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        OakSpeechPrintMessage(gOakSpeech_Text_WhatWasHisName, sOakSpeechResources->textSpeed, FALSE);
        sOakSpeechResources->hasPlayerBeenNamed = TRUE;
        gTasks[taskId].func = Task_OakSpeech_MoveRivalDisplayNameOptions;
    }
}

static void Task_OakSpeech_ReshowPlayersPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTrainerPicFadeState != 0)
    {
        ClearTrainerPic();
        if (tTimer != 0)
        {
            tTimer--;
        }
        else
        {
            if (gSaveBlock2Ptr->playerGender == MALE)
                LoadTrainerPic(MALE_PLAYER_PIC, 0);
            else
                LoadTrainerPic(FEMALE_PLAYER_PIC, 0);
            gTasks[taskId].tTrainerPicPosX = 0;
            gSpriteCoordOffsetX = 0;
            ChangeBgX(2, 0, BG_COORD_SET);
            CreateFadeOutTask(taskId, 2);
            gTasks[taskId].func = Task_OakSpeech_LetsGo;
        }
    }
}

static void Task_OakSpeech_LetsGo(u8 taskId)
{
    if (gTasks[taskId].tTrainerPicFadeState != 0)
    {
        StringExpandPlaceholders(gStringVar4, gOakSpeech_Text_LetsGo);
        OakSpeechPrintMessage(gStringVar4, sOakSpeechResources->textSpeed, TRUE);
        gTasks[taskId].tTimer = 30;
        gTasks[taskId].func = Task_OakSpeech_FadeOutBGM;
    }
}

static void Task_OakSpeech_FadeOutBGM(u8 taskId)
{
    if (!IsTextPrinterActiveOnWindow(WIN_INTRO_TEXTBOX))
    {
        if (gTasks[taskId].tTimer != 0)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            FadeOutBGM(4);
            gTasks[taskId].func = Task_OakSpeech_SetUpExitAnimation;
        }
    }
}

// The sOakSpeechResources struct's currentPage field is reused below as a timer for shrinking the player pic
#define shrinkTimer currentPage

static void Task_OakSpeech_SetUpExitAnimation(u8 taskId)
{
    sOakSpeechResources->shrinkTimer = 0;
    Task_OakSpeech_SetUpDestroyPlatformSprites(taskId);
    Task_OakSpeech_SetUpFadePlayerPicWhite(taskId);
    Task_OakSpeech_SetUpShrinkPlayerPic(taskId);
}

#define tPlayerPicFadeOutTimer data[0]
#define tScaleDelta            data[2]
#define tPlayerIsShrunk        data[15]

static void Task_OakSpeech_SetUpShrinkPlayerPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    SetBgAttribute(2, BG_ATTR_WRAPAROUND, 1);
    tPlayerPicFadeOutTimer = 0;
    data[1] = 0; // assigned, but never read
    tScaleDelta = 256;
    tPlayerIsShrunk = FALSE;
    gTasks[taskId].func = Task_OakSpeech_ShrinkPlayerPic;
}

static void Task_OakSpeech_ShrinkPlayerPic(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 x, y;
    u16 oldScaleDelta;

    sOakSpeechResources->shrinkTimer++;
    if (sOakSpeechResources->shrinkTimer % 20 == 0)
    {
        if (sOakSpeechResources->shrinkTimer == 40)
            PlaySE(SE_WARP_IN);
        oldScaleDelta = tScaleDelta;
        tScaleDelta -= 32;
        x = MathUtil_Inv16(oldScaleDelta - 8);
        y = MathUtil_Inv16(tScaleDelta - 16);
        SetBgAffine(2, 0x7800, 0x5400, 120, 84, x, y, 0);
        if (tScaleDelta <= 96)
        {
            tPlayerIsShrunk = TRUE;
            tPlayerPicFadeOutTimer = 36;
            gTasks[taskId].func = Task_OakSpeech_FadePlayerPicToBlack;
        }
    }
}

#define tBGFadeStarted data[1]

static void Task_OakSpeech_SetUpDestroyPlatformSprites(u8 taskId)
{
    u8 taskId2 = CreateTask(Task_OakSpeech_DestroyPlatformSprites, 1);
    s16 *data = gTasks[taskId2].data;
    data[0] = 0; // assigned, but never read
    tBGFadeStarted = 0;
    data[2] = 0; // assigned, but never read
    data[15] = 0; // assigned, but never read
    BeginNormalPaletteFade(PALETTES_OBJECTS | 0x0FCF, 4, 0, 16, RGB_BLACK);
}

static void Task_OakSpeech_DestroyPlatformSprites(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        if (tBGFadeStarted != 0)
        {
            DestroyTask(taskId);
            // As this function's taskId is in fact taskId2 above, in
            // Task_OakSpeech_SetUpDestroyPlatformSprites, the platform sprite
            // IDs have not been assigned to this task's data[7], data[8] and
            // data[9].
            // As a result, the function below will only delete the sprite with
            // ID 0.
            // This can be verified by looking at the sprite viewer in an
            // emulator at the end of the Oak speech.
            DestroyPikachuOrPlatformSprites(taskId, SPRITE_TYPE_PLATFORM);
        }
        else
        {
            tBGFadeStarted++;
            BeginNormalPaletteFade(0x0000 | 0xF000, 0, 0, 16, RGB_BLACK);
        }
    }
}

#undef tBGFadeStarted

#define tPlayerPicFadeWhiteTimer data[0]
#define tUnderflowingTimer       data[1]
#define tSecondaryTimer          data[2]
#define tBlendCoefficient        data[14]

static void Task_OakSpeech_SetUpFadePlayerPicWhite(u8 taskId)
{
    u8 taskId2 = CreateTask(Task_OakSpeech_FadePlayerPicWhite, 2);
    s16 *data = gTasks[taskId2].data;
    tPlayerPicFadeWhiteTimer = 8;
    tUnderflowingTimer = 0;
    tSecondaryTimer = 8;
    tBlendCoefficient = 0;
    data[15] = 0; // assigned, but never read
}

static void Task_OakSpeech_FadePlayerPicWhite(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 i;

    if (tPlayerPicFadeWhiteTimer != 0)
    {
        tPlayerPicFadeWhiteTimer--;
    }
    else
    {
        if (tUnderflowingTimer <= 0 && tSecondaryTimer != 0)
            tSecondaryTimer--;
        BlendPalette(BG_PLTT_ID(4), 0x20, tBlendCoefficient, RGB_WHITE);
        tBlendCoefficient++;
        tUnderflowingTimer--;
        tPlayerPicFadeWhiteTimer = tSecondaryTimer;
        if (tBlendCoefficient > 14)
        {
            for (i = 0; i < 32; i++)
            {
                gPlttBufferFaded[i + BG_PLTT_ID(4)] = RGB_WHITE;
                gPlttBufferUnfaded[i + BG_PLTT_ID(4)] = RGB_WHITE;
            }
            DestroyTask(taskId);
        }
    }
}

static void Task_OakSpeech_FadePlayerPicToBlack(u8 taskId)
{
    if (gTasks[taskId].tPlayerPicFadeOutTimer != 0)
    {
        gTasks[taskId].tPlayerPicFadeOutTimer--;
    }
    else
    {
        BeginNormalPaletteFade(0x0000 | 0x0030, 2, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_OakSpeech_WaitForFade;
    }
}

static void Task_OakSpeech_WaitForFade(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OakSpeech_FreeResources;
}

static void Task_OakSpeech_FreeResources(u8 taskId)
{
    FreeAllWindowBuffers();
    DestroyMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A);
    Free(sOakSpeechResources);
    sOakSpeechResources = NULL;
    gTextFlags.canABSpeedUpPrint = FALSE;
    SetMainCallback2(CB2_NewGame);
    DestroyTask(taskId);
}

static void CB2_ReturnFromNamingScreen(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        DmaFill16(3, 0, VRAM, VRAM_SIZE);
        DmaFill32(3, 0, OAM, OAM_SIZE);
        DmaFill16(3, RGB_BLACK, PLTT + sizeof(u16), PLTT_SIZE - sizeof(u16));
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTempTileDataBuffers();
        break;
    case 1:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(1, sOakSpeechResources->bg1TilemapBuffer);
        SetBgTilemapBuffer(2, sOakSpeechResources->bg2TilemapBuffer);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        break;
    case 2:
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        break;
    case 3:
        FreeAllWindowBuffers();
        InitStandardTextBoxWindows();
        InitTextBoxGfxAndPrinters();
        // Below is reading 48 colors beyond the background palette (into the tiles that follow it).
        // This color range is used by the player and rival pic, which will overwrite them with the correct colors.
#ifdef BUGFIX
        LoadPalette(sOakSpeech_Background_Pals, BG_PLTT_ID(0), sizeof(sOakSpeech_Background_Pals));
#else
        LoadPalette(sOakSpeech_Background_Pals, BG_PLTT_ID(0), sizeof(sOakSpeech_Background_Pals) + PLTT_SIZEOF(48));
#endif
        break;
    case 4:
        DecompressAndCopyTileDataToVram(1, sOakSpeech_Background_Tiles, 0, 0, 0);
        break;
    case 5:
        if (FreeTempTileDataBuffersIfPossible())
            return;
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 30, 20);
        CopyToBgTilemapBuffer(1, sOakSpeech_Background_Tilemap, 0, 0);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        break;
    case 6:
        taskId = CreateTask(Task_OakSpeech_ConfirmName, 0);
        if (sOakSpeechResources->hasPlayerBeenNamed == FALSE)
        {
            if (gSaveBlock2Ptr->playerGender == MALE)
                LoadTrainerPic(MALE_PLAYER_PIC, 0);
            else
                LoadTrainerPic(FEMALE_PLAYER_PIC, 0);
        }
        else
        {
            LoadTrainerPic(RIVAL_PIC, 0);
        }
        gTasks[taskId].tTrainerPicPosX = -60;
        gSpriteCoordOffsetX += 60;
        ChangeBgX(2, 0xFFFFC400, BG_COORD_SET);
        CreatePikachuOrPlatformSprites(taskId, SPRITE_TYPE_PLATFORM);
        gTasks[taskId].tNameNotConfirmed = TRUE;
        break;
    case 7:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_NewGameScene);
        gTextFlags.canABSpeedUpPrint = TRUE;
        SetMainCallback2(CB2_NewGameScene);
        return;
    }

    gMain.state++;
}

static void CreateNidoranFSprite(u8 taskId)
{
    u8 spriteId;

    LoadSpecialPokePic(MonSpritesGfxManager_GetSpritePtr(MON_SPR_GFX_MANAGER_A, 0), INTRO_SPECIES, 0, TRUE);
    LoadSpritePaletteWithTag(GetMonSpritePalFromSpeciesAndPersonality(INTRO_SPECIES, 0, 0), INTRO_SPECIES);
    SetMultiuseSpriteTemplateToPokemon(INTRO_SPECIES, 0);
    spriteId = CreateSprite(&gMultiuseSpriteTemplate, 96, 96, 1);
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].invisible = TRUE;
    gTasks[taskId].tNidoranFSpriteId = spriteId;
}

#define sBodySpriteId data[0]

static void SpriteCB_Pikachu(struct Sprite *sprite)
{
    sprite->y2 = gSprites[sprite->sBodySpriteId].animCmdIndex;
}

static void CreatePikachuOrPlatformSprites(u8 taskId, u8 spriteType)
{
    u8 spriteId;
    u8 i = 0;

    switch (spriteType)
    {
    case SPRITE_TYPE_PIKACHU:
        LoadCompressedSpriteSheet(&sPikachuIntro_Pikachu_SpriteSheets[PIKACHU_BODY_PLATFORM_LEFT]);
        LoadCompressedSpriteSheet(&sPikachuIntro_Pikachu_SpriteSheets[PIKACHU_EARS_PLATFORM_MIDDLE]);
        LoadCompressedSpriteSheet(&sPikachuIntro_Pikachu_SpriteSheets[PIKACHU_EYES_PLATFORM_RIGHT]);
        LoadSpritePalette(&sPikachuIntro_Pikachu_SpritePalette);
        spriteId = CreateSprite(&sPikachuIntro_Pikachu_SpriteTemplates[PIKACHU_BODY_PLATFORM_LEFT], 16, 17, 2);
        gSprites[spriteId].oam.priority = 0;
        gTasks[taskId].tPikachuPlatformSpriteId(PIKACHU_BODY_PLATFORM_LEFT) = spriteId;
        spriteId = CreateSprite(&sPikachuIntro_Pikachu_SpriteTemplates[PIKACHU_EARS_PLATFORM_MIDDLE], 16, 9, 3);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].sBodySpriteId = gTasks[taskId].tPikachuPlatformSpriteId(PIKACHU_BODY_PLATFORM_LEFT);
        gSprites[spriteId].callback = SpriteCB_Pikachu;
        gTasks[taskId].tPikachuPlatformSpriteId(PIKACHU_EARS_PLATFORM_MIDDLE) = spriteId;
        spriteId = CreateSprite(&sPikachuIntro_Pikachu_SpriteTemplates[PIKACHU_EYES_PLATFORM_RIGHT], 24, 13, 1);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].sBodySpriteId = gTasks[taskId].tPikachuPlatformSpriteId(PIKACHU_BODY_PLATFORM_LEFT);
        gSprites[spriteId].callback = SpriteCB_Pikachu;
        gTasks[taskId].tPikachuPlatformSpriteId(PIKACHU_EYES_PLATFORM_RIGHT) = spriteId;
        break;
    case SPRITE_TYPE_PLATFORM:
        LoadCompressedSpriteSheet(&sOakSpeech_Platform_SpriteSheet);
        LoadSpritePalette(&sOakSpeech_Platform_SpritePalette);
        for (i = PIKACHU_BODY_PLATFORM_LEFT; i < NUM_PIKACHU_PLATFORM_SPRITES; i++)
        {
            spriteId = CreateSprite(&sOakSpeech_Platform_SpriteTemplates[i], i * 32 + 88, 112, 1);
            gSprites[spriteId].oam.priority = 2;
            gSprites[spriteId].animPaused = TRUE;
            gSprites[spriteId].coordOffsetEnabled = TRUE;
            gTasks[taskId].tPikachuPlatformSpriteId(i) = spriteId;
        }
        break;
    }
}

static void DestroyPikachuOrPlatformSprites(u8 taskId, u8 spriteType)
{
    u8 i;
    for (i = PIKACHU_BODY_PLATFORM_LEFT; i < NUM_PIKACHU_PLATFORM_SPRITES; i++)
        DestroySprite(&gSprites[gTasks[taskId].tPikachuPlatformSpriteId(i)]);

    switch (spriteType)
    {
    case SPRITE_TYPE_PIKACHU:
        FreeSpriteTilesByTag(GFX_TAG_PIKACHU_EYES);
        FreeSpriteTilesByTag(GFX_TAG_PIKACHU_EARS);
        FreeSpriteTilesByTag(GFX_TAG_PIKACHU);
        FreeSpritePaletteByTag(PAL_TAG_PIKACHU);
        break;
    case SPRITE_TYPE_PLATFORM:
        FreeSpriteTilesByTag(GFX_TAG_PLATFORM);
        FreeSpritePaletteByTag(PAL_TAG_PLATFORM);
        break;
    }
}

static void LoadTrainerPic(u16 whichPic, u16 tileOffset)
{
    u32 i;

    switch (whichPic)
    {
    case MALE_PLAYER_PIC:
        LoadPalette(sOakSpeech_Red_Pal, BG_PLTT_ID(4), sizeof(sOakSpeech_Red_Pal));
        DecompressDataWithHeaderVram(sOakSpeech_Red_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    case FEMALE_PLAYER_PIC:
        LoadPalette(sOakSpeech_Leaf_Pal, BG_PLTT_ID(4), sizeof(sOakSpeech_Leaf_Pal));
        DecompressDataWithHeaderVram(sOakSpeech_Leaf_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    case RIVAL_PIC:
        LoadPalette(sOakSpeech_Rival_Pal, BG_PLTT_ID(6), sizeof(sOakSpeech_Rival_Pal));
        DecompressDataWithHeaderVram(sOakSpeech_Rival_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    case OAK_PIC:
        LoadPalette(sOakSpeech_Oak_Pal, BG_PLTT_ID(6), sizeof(sOakSpeech_Oak_Pal));
        DecompressDataWithHeaderVram(sOakSpeech_Oak_Tiles, (void *)VRAM + 0x600 + tileOffset);
        break;
    default:
        return;
    }

    sOakSpeechResources->trainerPicTilemap = AllocZeroed(0x60);
    for (i = 0; i < 0x60; i++)
        ((u8 *)sOakSpeechResources->trainerPicTilemap)[i] = i;
    FillBgTilemapBufferRect(2, 0, 0, 0, 32, 32, 16);
    CopyRectToBgTilemapBufferRect(2, sOakSpeechResources->trainerPicTilemap, 0, 0, 8, 12, 11, 2, 8, 12, 16, (tileOffset / 64) + 24, 0);
    CopyBgTilemapBufferToVram(2);
    Free(sOakSpeechResources->trainerPicTilemap);
    sOakSpeechResources->trainerPicTilemap = 0;
}

static void ClearTrainerPic(void)
{
    FillBgTilemapBufferRect(2, 0, 11, 1, 8, 12, 16);
    CopyBgTilemapBufferToVram(2);
}

#define tParentTaskId data[0]
#define tBlendTarget1 data[1]
#define tBlendTarget2 data[2]
#define tUnusedState  data[3]
#define tFadeTimer    data[4]

static void Task_SlowFadeIn(u8 taskId)
{
    u8 i = 0;
    if (gTasks[taskId].tBlendTarget1 == 0)
    {
        gTasks[gTasks[taskId].tParentTaskId].tTrainerPicFadeState = 1;
        DestroyTask(taskId);
        for (i = PIKACHU_BODY_PLATFORM_LEFT; i < NUM_PIKACHU_PLATFORM_SPRITES; i++)
            gSprites[gTasks[taskId].tPikachuPlatformSpriteId(i)].invisible = TRUE;
    }
    else
    {
        if (gTasks[taskId].tFadeTimer != 0)
        {
            gTasks[taskId].tFadeTimer--;
        }
        else
        {
            gTasks[taskId].tFadeTimer = gTasks[taskId].tTimer;
            gTasks[taskId].tBlendTarget1--;
            gTasks[taskId].tBlendTarget2++;
            if (gTasks[taskId].tBlendTarget1 == 8)
            {
                for (i = PIKACHU_BODY_PLATFORM_LEFT; i < NUM_PIKACHU_PLATFORM_SPRITES; i++)
                    gSprites[gTasks[taskId].tPikachuPlatformSpriteId(i)].invisible ^= TRUE;
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].tBlendTarget2 * 256) + gTasks[taskId].tBlendTarget1);
        }
    }
}

static void CreateFadeInTask(u8 taskId, u8 delay)
{
    u8 taskId2;
    u8 i = 0;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tTrainerPicFadeState = 0;
    taskId2 = CreateTask(Task_SlowFadeIn, 0);
    gTasks[taskId2].tParentTaskId = taskId;
    gTasks[taskId2].tBlendTarget1 = 16;
    gTasks[taskId2].tBlendTarget2 = 0;
    gTasks[taskId2].tUnusedState = delay; // assigned, but never read
    gTasks[taskId2].tFadeTimer = delay;
    for (i = PIKACHU_BODY_PLATFORM_LEFT; i < NUM_PIKACHU_PLATFORM_SPRITES; i++)
        gTasks[taskId2].tPikachuPlatformSpriteId(i) = gTasks[taskId].tPikachuPlatformSpriteId(i);
}

static void Task_SlowFadeOut(u8 taskId)
{
    u8 i = 0;

    if (gTasks[taskId].tBlendTarget1 == 16)
    {
        if (!gPaletteFade.active)
        {
            gTasks[gTasks[taskId].tParentTaskId].tTrainerPicFadeState = 1;
            DestroyTask(taskId);
        }
    }
    else
    {
        if (gTasks[taskId].tFadeTimer != 0)
        {
            gTasks[taskId].tFadeTimer--;
        }
        else
        {
            gTasks[taskId].tFadeTimer = gTasks[taskId].tTimer;
            gTasks[taskId].tBlendTarget1 += 2;
            gTasks[taskId].tBlendTarget2 -= 2;
            if (gTasks[taskId].tBlendTarget1 == 8)
            {
                for (i = PIKACHU_BODY_PLATFORM_LEFT; i < NUM_PIKACHU_PLATFORM_SPRITES; i++)
                    gSprites[gTasks[taskId].tPikachuPlatformSpriteId(i)].invisible ^= TRUE;
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (gTasks[taskId].tBlendTarget2 * 256) + gTasks[taskId].tBlendTarget1);
        }
    }
}

static void CreateFadeOutTask(u8 taskId, u8 delay)
{
    u8 taskId2;
    u8 i = 0;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tTrainerPicFadeState = 0;

    taskId2 = CreateTask(Task_SlowFadeOut, 0);
    gTasks[taskId2].tParentTaskId = taskId;
    gTasks[taskId2].tBlendTarget1 = 0;
    gTasks[taskId2].tBlendTarget2 = 16;
    gTasks[taskId2].tUnusedState = delay; // assigned, but never read
    gTasks[taskId2].tFadeTimer = delay;
    for (i = PIKACHU_BODY_PLATFORM_LEFT; i < NUM_PIKACHU_PLATFORM_SPRITES; i++)
        gTasks[taskId2].tPikachuPlatformSpriteId(i) = gTasks[taskId].tPikachuPlatformSpriteId(i);
}

static void PrintNameChoiceOptions(u8 taskId, u8 hasPlayerBeenNamed)
{
    s16 *data = gTasks[taskId].data;
    const u8 *const *textPtrs;
    u8 i;

    tMenuWindowId = AddWindow(&sIntro_WindowTemplates[WIN_INTRO_NAMES]);
    PutWindowTilemap(tMenuWindowId);
    DrawStdFrameWithCustomTileAndPalette(tMenuWindowId, 1, STD_WINDOW_BASE_TILE_NUM, 14);
    FillWindowPixelBuffer(gTasks[taskId].tMenuWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(tMenuWindowId, FONT_NORMAL, gOtherText_NewName, 8, 1, 0, NULL);
    if (hasPlayerBeenNamed == FALSE)
        textPtrs = gSaveBlock2Ptr->playerGender == MALE ? sMaleNameChoices : sFemaleNameChoices;
    else
        textPtrs = sRivalNameChoices;
    for (i = 0; i < ARRAY_COUNT(sRivalNameChoices); i++)
        AddTextPrinterParameterized(tMenuWindowId, FONT_NORMAL, textPtrs[i], 8, 16 * (i + 1) + 1, 0, NULL);
    InitMenuNormal(tMenuWindowId, FONT_NORMAL, 0, 1, 16, 5, 0);
    CopyWindowToVram(tMenuWindowId, COPYWIN_FULL);
}

static void GetDefaultName(u8 hasPlayerBeenNamed, u8 nameChoice)
{
    const u8 *src;
    u8 *dest;
    u8 i;
    if (hasPlayerBeenNamed == FALSE)
    {
        if (gSaveBlock2Ptr->playerGender == MALE)
            src = sMaleNameChoices[Random() % ARRAY_COUNT(sMaleNameChoices)];
        else
            src = sFemaleNameChoices[Random() % ARRAY_COUNT(sFemaleNameChoices)];
        dest = gSaveBlock2Ptr->playerName;
    }
    else
    {
        src = sRivalNameChoices[nameChoice];
        dest = gSaveBlock1Ptr->rivalName;
    }
    for (i = 0; i < PLAYER_NAME_LENGTH && src[i] != EOS; i++)
        dest[i] = src[i];
    for (; i < PLAYER_NAME_LENGTH + 1; i++)
        dest[i] = EOS;
}

#undef tSpriteTimer
#undef tTrainerPicPosX
#undef tTrainerPicFadeState
#undef tTimer
#undef tNidoranFSpriteId
#undef tTextCursorSpriteId
#undef tPokeBallSpriteId
#undef tMenuWindowId
#undef tTextboxWindowId
#undef tDelta
#undef tPlayerPicFadeOutTimer
#undef tScaleDelta
#undef tPlayerIsShrunk
#undef shrinkTimer
#undef tPlayerPicFadeWhiteTimer
#undef tUnderflowingTimer
#undef tSecondaryTimer
#undef tBlendCoefficient
#undef tNameNotConfirmed
#undef sBodySpriteId
#undef tParentTaskId
#undef tBlendTarget1
#undef tBlendTarget2
#undef tUnusedState
#undef tFadeTimer

#endif // IS_FRLG
