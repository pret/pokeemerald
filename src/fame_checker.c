#include "global.h"
#include "constants/songs.h"
#include "event_data.h"
#include "event_scripts.h"
#include "graphics.h"
#include "battle.h"
#include "battle_setup.h"
#include "menu.h"
#include "trainer_pokemon_sprites.h"
#include "scanline_effect.h"
#include "item_menu.h"
#include "list_menu.h"
#include "task.h"
#include "event_object_movement.h"
#include "text_window.h"
#include "fame_checker.h"
#include "strings.h"
#include "constants/event_objects.h"

// #define SPRITETAG_SELECTOR_CURSOR 1000
// #define SPRITETAG_QUESTION_MARK 1001
// #define SPRITETAG_SPINNING_POKEBALL 1002
// #define SPRITETAG_SCROLL_INDICATORS 1004
// #define SPRITETAG_DAISY 1006 // TODO: Investigate, seems to be used for other NPCs (e.g. Fan Club Chairman)
// #define SPRITETAG_FUJI 1007
// #define SPRITETAG_OAK 1008
// #define SPRITETAG_BILL 1009

// #define FC_NONTRAINER_START 0xFE00

// struct FameCheckerData
// {
//     MainCallback savedCallback;
//     u16 listMenuTopIdx;
//     u8 scrollIndicatorPairTaskId;
//     u8 personHasUnlockedPanels:1;
//     u8 inPickMode:1;
//     u8 numUnlockedPersons:6;
//     u8 listMenuTaskId;
//     u8 listMenuCurIdx;
//     u8 listMenuTopIdx2;
//     u8 listMenuDrawnSelIdx;
//     u8 unlockedPersons[NUM_FAMECHECKER_PERSONS + 1];
//     u8 spriteIds[6];
//     u8 viewingFlavorText:1;
//     u8 unk_23_1:1; // unused
//     u8 pickModeOverCancel:1;
// };

// static EWRAM_DATA u16 * sBg3TilemapBuffer = NULL;
// static EWRAM_DATA u16 * sBg1TilemapBuffer = NULL;
// static EWRAM_DATA u16 * sBg2TilemapBuffer = NULL;
// static EWRAM_DATA struct FameCheckerData * sFameCheckerData = NULL;
// static EWRAM_DATA struct ListMenuItem * sListMenuItems = NULL;
// static EWRAM_DATA s32 sLastMenuIdx = 0;

// COMMON_DATA struct ListMenuTemplate gFameChecker_ListMenuTemplate = {0};
// COMMON_DATA u8 gIconDescriptionBoxIsOpen = 0;

// static void MainCB2_LoadFameChecker(void);
// static void LoadUISpriteSheetsAndPalettes(void);
// static void Task_WaitFadeOnInit(u8 taskId);
// static void Task_TopMenuHandleInput(u8 taskId);
// static bool8 TryExitPickMode(u8 taskId);
// static void MessageBoxPrintEmptyText(void);
// static void Task_EnterPickMode(u8 taskId);
// static void Task_ExitPickMode(u8 taskId);
// static void Task_FlavorTextDisplayHandleInput(u8 taskId);
// static void FC_MoveSelectorCursor(u8 taskId, s8 dx, s8 dy);
// static void GetPickModeText(void);
// static void PrintSelectedNameInBrightGreen(u8 taskId);
// static void WipeMsgBoxAndTransfer(void);
// static void Setup_DrawMsgAndListBoxes(void);
// static void FC_PutWindowTilemapAndCopyWindowToVramMode3(u8 windowId);
// static bool8 SetMessageSelectorIconObjMode(u8 taskId, u8 objMode);
// static void Task_StartToCloseFameChecker(u8 taskId);
// static void Task_DestroyAssetsAndCloseFameChecker(u8 taskId);
// static void FC_DestroyWindow(u8 windowId);
// static void PrintUIHelp(u8 state);
// static bool8 CreateAllFlavorTextIcons(u8 who);
// static void FCSetup_ClearVideoRegisters(void);
// static void FCSetup_ResetTasksAndSpriteResources(void);
// static void FCSetup_TurnOnDisplay(void);
// static void FCSetup_ResetBGCoords(void);
// static bool8 HasUnlockedAllFlavorTextsForCurrentPerson(void);
// static void FreeSelectionCursorSpriteResources(void);
// static u8 CreateFlavorTextIconSelectorCursorSprite(s16 where);
// static void SpriteCB_DestroyFlavorTextIconSelectorCursor(struct Sprite *sprite);
// static void FreeQuestionMarkSpriteResources(void);
// static u8 PlaceQuestionMarkTile(u8 x, u8 y);
// static void FreeSpinningPokeballSpriteResources(void);
// static u8 CreateSpinningPokeballSprite(void);
// static void SpriteCB_DestroySpinningPokeball(struct Sprite *sprite);
// static void FreeNonTrainerPicTiles(void);
// static u8 CreatePersonPicSprite(u8 fcPersonIdx);
// static void DestroyPersonPicSprite(u8 taskId, u16 who);
// static void UpdateIconDescriptionBox(u8 whichText);
// static void UpdateIconDescriptionBoxOff(void);
// static void FC_CreateListMenu(void);
// static void SpriteCB_FCSpinningPokeball(struct Sprite *sprite);
// static void InitListMenuTemplate(void);
// static void FC_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu * list);
// static void Task_SwitchToPickMode(u8 taskId);
// static void PrintCancelDescription(void);
// static void FC_DoMoveCursor(s32 itemIndex, bool8 onInit);
// static u8 FC_PopulateListMenu(void);
// static void FC_PutWindowTilemapAndCopyWindowToVramMode3_2(u8 windowId);
// static void FC_CreateScrollIndicatorArrowPair(void);
// static void FreeListMenuSelectorArrowPairResources(void);
// static u16 FameCheckerGetCursorY(void);
// static void HandleFlavorTextModeSwitch(bool8 state);
// static void Task_FCOpenOrCloseInfoBox(u8 taskId);
// static void UpdateInfoBoxTilemap(u8 bg, s16 state);
// static void PlaceListMenuCursor(bool8 isActive);

// static const u16 sFameCheckerTilemap[] = INCBIN_U16("graphics/fame_checker/tilemap1.bin");
// static const u8 sQuestionMarkSpriteGfx[] = INCBIN_U8("graphics/fame_checker/question_mark.4bpp");
// static const u8 sSpinningPokeballSpriteGfx[] = INCBIN_U8("graphics/fame_checker/spinning_pokeball.4bpp");
// static const u16 sSpinningPokeballSpritePalette[] = INCBIN_U16("graphics/fame_checker/spinning_pokeball.gbapal");
// static const u8 sSelectorCursorSpriteGfx[] = INCBIN_U8("graphics/fame_checker/cursor.4bpp");
// static const u16 sSelectorCursorSpritePalette[] = INCBIN_U16("graphics/fame_checker/cursor.gbapal");
// static const u8 sFujiSpriteGfx[] = INCBIN_U8("graphics/fame_checker/mr_fuji.4bpp");
// static const u16 sFujiSpritePalette[] = INCBIN_U16("graphics/fame_checker/mr_fuji.gbapal");
// static const u8 sBillSpriteGfx[] = INCBIN_U8("graphics/fame_checker/bill.4bpp");
// static const u16 sBillSpritePalette[] = INCBIN_U16("graphics/fame_checker/bill.gbapal");
// static const u8 sDaisySpriteGfx[] = INCBIN_U8("graphics/fame_checker/daisy.4bpp");
// static const u16 sDaisySpritePalette[] = INCBIN_U16("graphics/fame_checker/daisy.gbapal");
// static const u8 sOakSpriteGfx[] = INCBIN_U8("graphics/fame_checker/prof_oak.4bpp");
// static const u16 sOakSpritePalette[] = INCBIN_U16("graphics/fame_checker/prof_oak.gbapal");
// static const u16 sSilhouettePalette[] = INCBIN_U16("graphics/fame_checker/silhouette.gbapal");

// static const u8 sTextColor_White[3]  = {0, 1, 2};
// static const u8 sTextColor_DkGrey[3] = {0, 2, 3};
// static const u8 sTextColor_Green[3]  = {0, 6, 7};

// #define FAME_CHECKER_PROF_OAK  (FC_NONTRAINER_START + 0)
// #define FAME_CHECKER_DAISY_OAK (FC_NONTRAINER_START + 1)
// #define FAME_CHECKER_BILL      (FC_NONTRAINER_START + 2)
// #define FAME_CHECKER_MR_FUJI   (FC_NONTRAINER_START + 3)

// static const u16 sTrainerIdxs[] = {
//     [FAMECHECKER_OAK]      = FAME_CHECKER_PROF_OAK,
//     [FAMECHECKER_DAISY]    = FAME_CHECKER_DAISY_OAK,
//     [FAMECHECKER_BROCK]    = TRAINER_LEADER_BROCK,
//     [FAMECHECKER_MISTY]    = TRAINER_LEADER_MISTY,
//     [FAMECHECKER_LTSURGE]  = TRAINER_LEADER_LT_SURGE,
//     [FAMECHECKER_ERIKA]    = TRAINER_LEADER_ERIKA,
//     [FAMECHECKER_KOGA]     = TRAINER_LEADER_KOGA,
//     [FAMECHECKER_SABRINA]  = TRAINER_LEADER_SABRINA,
//     [FAMECHECKER_BLAINE]   = TRAINER_LEADER_BLAINE,
//     [FAMECHECKER_LORELEI]  = TRAINER_ELITE_FOUR_LORELEI,
//     [FAMECHECKER_BRUNO]    = TRAINER_ELITE_FOUR_BRUNO,
//     [FAMECHECKER_AGATHA]   = TRAINER_ELITE_FOUR_AGATHA,
//     [FAMECHECKER_LANCE]    = TRAINER_ELITE_FOUR_LANCE,
//     [FAMECHECKER_BILL]     = FAME_CHECKER_BILL,
//     [FAMECHECKER_MRFUJI]   = FAME_CHECKER_MR_FUJI,
//     [FAMECHECKER_GIOVANNI] = TRAINER_BOSS_GIOVANNI
// };

// static const u8 *const sNonTrainerNamePointers[] = {
//     gFameCheckerOakName,
//     gFameCheckerDaisyName,
//     gFameCheckerBillName,
//     gFameCheckerMrFujiName
// };

// static const u8 sFameCheckerTrainerPicIdxs[] = {
//     [FAMECHECKER_OAK]      = TRAINER_PIC_CAMPER,
//     [FAMECHECKER_DAISY]    = TRAINER_PIC_LASS,
//     [FAMECHECKER_BROCK]    = TRAINER_PIC_LEADER_BROCK,
//     [FAMECHECKER_MISTY]    = TRAINER_PIC_LEADER_MISTY,
//     [FAMECHECKER_LTSURGE]  = TRAINER_PIC_LEADER_LT_SURGE,
//     [FAMECHECKER_ERIKA]    = TRAINER_PIC_LEADER_ERIKA,
//     [FAMECHECKER_KOGA]     = TRAINER_PIC_LEADER_KOGA,
//     [FAMECHECKER_SABRINA]  = TRAINER_PIC_LEADER_SABRINA,
//     [FAMECHECKER_BLAINE]   = TRAINER_PIC_LEADER_BLAINE,
//     [FAMECHECKER_LORELEI]  = TRAINER_PIC_ELITE_FOUR_LORELEI,
//     [FAMECHECKER_BRUNO]    = TRAINER_PIC_ELITE_FOUR_BRUNO,
//     [FAMECHECKER_AGATHA]   = TRAINER_PIC_ELITE_FOUR_AGATHA,
//     [FAMECHECKER_LANCE]    = TRAINER_PIC_ELITE_FOUR_LANCE,
//     [FAMECHECKER_BILL]     = TRAINER_PIC_PSYCHIC_M,
//     [FAMECHECKER_MRFUJI]   = TRAINER_PIC_GENTLEMAN,
//     [FAMECHECKER_GIOVANNI] = TRAINER_PIC_LEADER_GIOVANNI,
// };

// static const u8 sFameCheckerTrainerGenders_Unused[] = {
//     [FAMECHECKER_OAK]      = MALE,
//     [FAMECHECKER_DAISY]    = FEMALE,
//     [FAMECHECKER_BROCK]    = MALE,
//     [FAMECHECKER_MISTY]    = FEMALE,
//     [FAMECHECKER_LTSURGE]  = MALE,
//     [FAMECHECKER_ERIKA]    = FEMALE,
//     [FAMECHECKER_KOGA]     = MALE,
//     [FAMECHECKER_SABRINA]  = FEMALE,
//     [FAMECHECKER_BLAINE]   = MALE,
//     [FAMECHECKER_LORELEI]  = FEMALE,
//     [FAMECHECKER_BRUNO]    = MALE,
//     [FAMECHECKER_AGATHA]   = FEMALE,
//     [FAMECHECKER_LANCE]    = MALE,
//     [FAMECHECKER_BILL]     = MALE,
//     [FAMECHECKER_MRFUJI]   = MALE,
//     [FAMECHECKER_GIOVANNI] = MALE,
// };

// static const u8 *const sFameCheckerNameAndQuotesPointers[2 * NUM_FAMECHECKER_PERSONS] =
// {
//     gFameCheckerPersonName_ProfOak,
//     gFameCheckerPersonName_Daisy,
//     gFameCheckerPersonName_Brock,
//     gFameCheckerPersonName_Misty,
//     gFameCheckerPersonName_LtSurge,
//     gFameCheckerPersonName_Erika,
//     gFameCheckerPersonName_Koga,
//     gFameCheckerPersonName_Sabrina,
//     gFameCheckerPersonName_Blaine,
//     gFameCheckerPersonName_Lorelei,
//     gFameCheckerPersonName_Bruno,
//     gFameCheckerPersonName_Agatha,
//     gFameCheckerPersonName_Lance,
//     gFameCheckerPersonName_Bill,
//     gFameCheckerPersonName_MrFuji,
//     gFameCheckerPersonName_Giovanni,

//     gFameCheckerPersonQuote_ProfOak,
//     gFameCheckerPersonQuote_Daisy,
//     gFameCheckerPersonQuote_Brock,
//     gFameCheckerPersonQuote_Misty,
//     gFameCheckerPersonQuote_LtSurge,
//     gFameCheckerPersonQuote_Erika,
//     gFameCheckerPersonQuote_Koga,
//     gFameCheckerPersonQuote_Sabrina,
//     gFameCheckerPersonQuote_Blaine,
//     gFameCheckerPersonQuote_Lorelei,
//     gFameCheckerPersonQuote_Bruno,
//     gFameCheckerPersonQuote_Agatha,
//     gFameCheckerPersonQuote_Lance,
//     gFameCheckerPersonQuote_Bill,
//     gFameCheckerPersonQuote_MrFuji,
//     gFameCheckerPersonQuote_Giovanni
// };

// static const u8 *const sFameCheckerFlavorTextPointers[] = {
//     gFameCheckerFlavorText_ProfOak0, gFameCheckerFlavorText_ProfOak1, gFameCheckerFlavorText_ProfOak2, gFameCheckerFlavorText_ProfOak3, gFameCheckerFlavorText_ProfOak4, gFameCheckerFlavorText_ProfOak5,
//     gFameCheckerFlavorText_Daisy0, gFameCheckerFlavorText_Daisy1, gFameCheckerFlavorText_Daisy2, gFameCheckerFlavorText_Daisy3, gFameCheckerFlavorText_Daisy4, gFameCheckerFlavorText_Daisy5,
//     gFameCheckerFlavorText_Brock0, gFameCheckerFlavorText_Brock1, gFameCheckerFlavorText_Brock2, gFameCheckerFlavorText_Brock3, gFameCheckerFlavorText_Brock4, gFameCheckerFlavorText_Brock5,
//     gFameCheckerFlavorText_Misty0, gFameCheckerFlavorText_Misty1, gFameCheckerFlavorText_Misty2, gFameCheckerFlavorText_Misty3, gFameCheckerFlavorText_Misty4, gFameCheckerFlavorText_Misty5,
//     gFameCheckerFlavorText_LtSurge0, gFameCheckerFlavorText_LtSurge1, gFameCheckerFlavorText_LtSurge2, gFameCheckerFlavorText_LtSurge3, gFameCheckerFlavorText_LtSurge4, gFameCheckerFlavorText_LtSurge5,
//     gFameCheckerFlavorText_Erika0, gFameCheckerFlavorText_Erika1, gFameCheckerFlavorText_Erika2, gFameCheckerFlavorText_Erika3, gFameCheckerFlavorText_Erika4, gFameCheckerFlavorText_Erika5,
//     gFameCheckerFlavorText_Koga0, gFameCheckerFlavorText_Koga1, gFameCheckerFlavorText_Koga2, gFameCheckerFlavorText_Koga3, gFameCheckerFlavorText_Koga4, gFameCheckerFlavorText_Koga5,
//     gFameCheckerFlavorText_Sabrina0, gFameCheckerFlavorText_Sabrina1, gFameCheckerFlavorText_Sabrina2, gFameCheckerFlavorText_Sabrina3, gFameCheckerFlavorText_Sabrina4, gFameCheckerFlavorText_Sabrina5,
//     gFameCheckerFlavorText_Blaine0, gFameCheckerFlavorText_Blaine1, gFameCheckerFlavorText_Blaine2, gFameCheckerFlavorText_Blaine3, gFameCheckerFlavorText_Blaine4, gFameCheckerFlavorText_Blaine5,
//     gFameCheckerFlavorText_Lorelei0, gFameCheckerFlavorText_Lorelei1, gFameCheckerFlavorText_Lorelei2, gFameCheckerFlavorText_Lorelei3, gFameCheckerFlavorText_Lorelei4, gFameCheckerFlavorText_Lorelei5,
//     gFameCheckerFlavorText_Bruno0, gFameCheckerFlavorText_Bruno1, gFameCheckerFlavorText_Bruno2, gFameCheckerFlavorText_Bruno3, gFameCheckerFlavorText_Bruno4, gFameCheckerFlavorText_Bruno5,
//     gFameCheckerFlavorText_Agatha0, gFameCheckerFlavorText_Agatha1, gFameCheckerFlavorText_Agatha2, gFameCheckerFlavorText_Agatha3, gFameCheckerFlavorText_Agatha4, gFameCheckerFlavorText_Agatha5,
//     gFameCheckerFlavorText_Lance0, gFameCheckerFlavorText_Lance1, gFameCheckerFlavorText_Lance2, gFameCheckerFlavorText_Lance3, gFameCheckerFlavorText_Lance4, gFameCheckerFlavorText_Lance5,
//     gFameCheckerFlavorText_Bill0, gFameCheckerFlavorText_Bill1, gFameCheckerFlavorText_Bill2, gFameCheckerFlavorText_Bill3, gFameCheckerFlavorText_Bill4, gFameCheckerFlavorText_Bill5,
//     gFameCheckerFlavorText_MrFuji0, gFameCheckerFlavorText_MrFuji1, gFameCheckerFlavorText_MrFuji2, gFameCheckerFlavorText_MrFuji3, gFameCheckerFlavorText_MrFuji4, gFameCheckerFlavorText_MrFuji5,
//     gFameCheckerFlavorText_Giovanni0, gFameCheckerFlavorText_Giovanni1, gFameCheckerFlavorText_Giovanni2, gFameCheckerFlavorText_Giovanni3, gFameCheckerFlavorText_Giovanni4, gFameCheckerFlavorText_Giovanni5
// };

// static const u8 sFameCheckerArrayNpcGraphicsIds[] = {
//     // OAK
//     OBJ_EVENT_GFX_SIGN,
//     OBJ_EVENT_GFX_PROF_OAK,
//     OBJ_EVENT_GFX_WORKER_F,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_AGATHA,
//     OBJ_EVENT_GFX_SCIENTIST,
//     // DAISY
//     OBJ_EVENT_GFX_SCIENTIST,
//     OBJ_EVENT_GFX_WORKER_F,
//     OBJ_EVENT_GFX_GENTLEMAN,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_OLD_WOMAN_FRLG,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     // BROCK
//     OBJ_EVENT_GFX_GYM_SIGN,
//     OBJ_EVENT_GFX_BROCK,
//     OBJ_EVENT_GFX_FAT_MAN_FRLG,
//     OBJ_EVENT_GFX_BOY,
//     OBJ_EVENT_GFX_BALDING_MAN,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     // MISTY
//     OBJ_EVENT_GFX_GYM_SIGN,
//     OBJ_EVENT_GFX_MISTY,
//     OBJ_EVENT_GFX_SWIMMER_M_WATER,
//     OBJ_EVENT_GFX_CAMPER_FRLG,
//     OBJ_EVENT_GFX_BEAUTY_FRLG,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     // LTSURGE
//     OBJ_EVENT_GFX_GYM_SIGN,
//     OBJ_EVENT_GFX_LT_SURGE,
//     OBJ_EVENT_GFX_GENTLEMAN,
//     OBJ_EVENT_GFX_GENTLEMAN,
//     OBJ_EVENT_GFX_SAILOR_FRLG,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     // ERIKA
//     OBJ_EVENT_GFX_GYM_SIGN,
//     OBJ_EVENT_GFX_ERIKA,
//     OBJ_EVENT_GFX_LASS_FRLG,
//     OBJ_EVENT_GFX_BEAUTY_FRLG,
//     OBJ_EVENT_GFX_ERIKA,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     // KOGA
//     OBJ_EVENT_GFX_GYM_SIGN,
//     OBJ_EVENT_GFX_KOGA,
//     OBJ_EVENT_GFX_ROCKER,
//     OBJ_EVENT_GFX_LASS_FRLG,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_BALDING_MAN,
//     // SABRINA
//     OBJ_EVENT_GFX_GYM_SIGN,
//     OBJ_EVENT_GFX_MAN,
//     OBJ_EVENT_GFX_SABRINA,
//     OBJ_EVENT_GFX_SABRINA,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_COOLTRAINER_M,
//     // BLAINE
//     OBJ_EVENT_GFX_GYM_SIGN,
//     OBJ_EVENT_GFX_BLAINE,
//     OBJ_EVENT_GFX_SCIENTIST,
//     OBJ_EVENT_GFX_WOMAN_2_FRLG,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     // LORELEI
//     OBJ_EVENT_GFX_LORELEI,
//     OBJ_EVENT_GFX_LORELEI,
//     OBJ_EVENT_GFX_OLD_MAN_1,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_LITTLE_GIRL_FRLG,
//     OBJ_EVENT_GFX_OLD_WOMAN_FRLG,
//     // BRUNO
//     OBJ_EVENT_GFX_BRUNO,
//     OBJ_EVENT_GFX_BRUNO,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_BLACK_BELT_FRLG,
//     OBJ_EVENT_GFX_BEAUTY_FRLG,
//     OBJ_EVENT_GFX_BLACK_BELT_FRLG,
//     // AGATHA
//     OBJ_EVENT_GFX_AGATHA,
//     OBJ_EVENT_GFX_BLACK_BELT_FRLG,
//     OBJ_EVENT_GFX_BLACK_BELT_FRLG,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_AGATHA,
//     OBJ_EVENT_GFX_OLD_WOMAN_FRLG,
//     // LANCE
//     OBJ_EVENT_GFX_LANCE,
//     OBJ_EVENT_GFX_LANCE,
//     OBJ_EVENT_GFX_CRUSH_GIRL,
//     OBJ_EVENT_GFX_WOMAN_1_FRLG,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_COOLTRAINER_M,
//     // BILL
//     OBJ_EVENT_GFX_BLUE,
//     OBJ_EVENT_GFX_YOUNGSTER_FRLG,
//     OBJ_EVENT_GFX_OLD_MAN_1,
//     OBJ_EVENT_GFX_CELIO,
//     OBJ_EVENT_GFX_CELIO,
//     OBJ_EVENT_GFX_CELIO,
//     // MRFUJI
//     OBJ_EVENT_GFX_LITTLE_GIRL_FRLG,
//     OBJ_EVENT_GFX_ROCKET_M,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_BALDING_MAN,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     OBJ_EVENT_GFX_CLIPBOARD,
//     // GIOVANNI
//     OBJ_EVENT_GFX_GIOVANNI,
//     OBJ_EVENT_GFX_SCIENTIST,
//     OBJ_EVENT_GFX_SCIENTIST,
//     OBJ_EVENT_GFX_GIOVANNI,
//     OBJ_EVENT_GFX_GYM_GUY,
//     OBJ_EVENT_GFX_SCIENTIST
// };

// static const u8 *const sFlavorTextOriginLocationTexts[] = {
//     gFameCheckerFlavorTextOriginLocation_ProfOak0, gFameCheckerFlavorTextOriginLocation_ProfOak1, gFameCheckerFlavorTextOriginLocation_ProfOak2, gFameCheckerFlavorTextOriginLocation_ProfOak3, gFameCheckerFlavorTextOriginLocation_ProfOak4, gFameCheckerFlavorTextOriginLocation_ProfOak5,
//     gFameCheckerFlavorTextOriginLocation_Daisy0, gFameCheckerFlavorTextOriginLocation_Daisy1, gFameCheckerFlavorTextOriginLocation_Daisy2, gFameCheckerFlavorTextOriginLocation_Daisy3, gFameCheckerFlavorTextOriginLocation_Daisy4, gFameCheckerFlavorTextOriginLocation_Daisy5,
//     gFameCheckerFlavorTextOriginLocation_Brock0, gFameCheckerFlavorTextOriginLocation_Brock1, gFameCheckerFlavorTextOriginLocation_Brock2, gFameCheckerFlavorTextOriginLocation_Brock3, gFameCheckerFlavorTextOriginLocation_Brock4, gFameCheckerFlavorTextOriginLocation_Brock5,
//     gFameCheckerFlavorTextOriginLocation_Misty0, gFameCheckerFlavorTextOriginLocation_Misty1, gFameCheckerFlavorTextOriginLocation_Misty2, gFameCheckerFlavorTextOriginLocation_Misty3, gFameCheckerFlavorTextOriginLocation_Misty4, gFameCheckerFlavorTextOriginLocation_Misty5,
//     gFameCheckerFlavorTextOriginLocation_LtSurge0, gFameCheckerFlavorTextOriginLocation_LtSurge1, gFameCheckerFlavorTextOriginLocation_LtSurge2, gFameCheckerFlavorTextOriginLocation_LtSurge3, gFameCheckerFlavorTextOriginLocation_LtSurge4, gFameCheckerFlavorTextOriginLocation_LtSurge5,
//     gFameCheckerFlavorTextOriginLocation_Erika0, gFameCheckerFlavorTextOriginLocation_Erika1, gFameCheckerFlavorTextOriginLocation_Erika2, gFameCheckerFlavorTextOriginLocation_Erika3, gFameCheckerFlavorTextOriginLocation_Erika4, gFameCheckerFlavorTextOriginLocation_Erika5,
//     gFameCheckerFlavorTextOriginLocation_Koga0, gFameCheckerFlavorTextOriginLocation_Koga1, gFameCheckerFlavorTextOriginLocation_Koga2, gFameCheckerFlavorTextOriginLocation_Koga3, gFameCheckerFlavorTextOriginLocation_Koga4, gFameCheckerFlavorTextOriginLocation_Koga5,
//     gFameCheckerFlavorTextOriginLocation_Sabrina0, gFameCheckerFlavorTextOriginLocation_Sabrina1, gFameCheckerFlavorTextOriginLocation_Sabrina2, gFameCheckerFlavorTextOriginLocation_Sabrina3, gFameCheckerFlavorTextOriginLocation_Sabrina4, gFameCheckerFlavorTextOriginLocation_Sabrina5,
//     gFameCheckerFlavorTextOriginLocation_Blaine0, gFameCheckerFlavorTextOriginLocation_Blaine1, gFameCheckerFlavorTextOriginLocation_Blaine2, gFameCheckerFlavorTextOriginLocation_Blaine3, gFameCheckerFlavorTextOriginLocation_Blaine4, gFameCheckerFlavorTextOriginLocation_Blaine5,
//     gFameCheckerFlavorTextOriginLocation_Lorelei0, gFameCheckerFlavorTextOriginLocation_Lorelei1, gFameCheckerFlavorTextOriginLocation_Lorelei2, gFameCheckerFlavorTextOriginLocation_Lorelei3, gFameCheckerFlavorTextOriginLocation_Lorelei4, gFameCheckerFlavorTextOriginLocation_Lorelei5,
//     gFameCheckerFlavorTextOriginLocation_Bruno0, gFameCheckerFlavorTextOriginLocation_Bruno1, gFameCheckerFlavorTextOriginLocation_Bruno2, gFameCheckerFlavorTextOriginLocation_Bruno3, gFameCheckerFlavorTextOriginLocation_Bruno4, gFameCheckerFlavorTextOriginLocation_Bruno5,
//     gFameCheckerFlavorTextOriginLocation_Agatha0, gFameCheckerFlavorTextOriginLocation_Agatha1, gFameCheckerFlavorTextOriginLocation_Agatha2, gFameCheckerFlavorTextOriginLocation_Agatha3, gFameCheckerFlavorTextOriginLocation_Agatha4, gFameCheckerFlavorTextOriginLocation_Agatha5,
//     gFameCheckerFlavorTextOriginLocation_Lance0, gFameCheckerFlavorTextOriginLocation_Lance1, gFameCheckerFlavorTextOriginLocation_Lance2, gFameCheckerFlavorTextOriginLocation_Lance3, gFameCheckerFlavorTextOriginLocation_Lance4, gFameCheckerFlavorTextOriginLocation_Lance5,
//     gFameCheckerFlavorTextOriginLocation_Bill0, gFameCheckerFlavorTextOriginLocation_Bill1, gFameCheckerFlavorTextOriginLocation_Bill2, gFameCheckerFlavorTextOriginLocation_Bill3, gFameCheckerFlavorTextOriginLocation_Bill4, gFameCheckerFlavorTextOriginLocation_Bill5,
//     gFameCheckerFlavorTextOriginLocation_MrFuji0, gFameCheckerFlavorTextOriginLocation_MrFuji1, gFameCheckerFlavorTextOriginLocation_MrFuji2, gFameCheckerFlavorTextOriginLocation_MrFuji3, gFameCheckerFlavorTextOriginLocation_MrFuji4, gFameCheckerFlavorTextOriginLocation_MrFuji5,
//     gFameCheckerFlavorTextOriginLocation_Giovanni0, gFameCheckerFlavorTextOriginLocation_Giovanni1, gFameCheckerFlavorTextOriginLocation_Giovanni2, gFameCheckerFlavorTextOriginLocation_Giovanni3, gFameCheckerFlavorTextOriginLocation_Giovanni4, gFameCheckerFlavorTextOriginLocation_Giovanni5
// };

// static const u8 *const sFlavorTextOriginObjectNameTexts[] = {
//     gFameCheckerFlavorTextOriginObjectName_ProfOak0, gFameCheckerFlavorTextOriginObjectName_ProfOak1, gFameCheckerFlavorTextOriginObjectName_ProfOak2, gFameCheckerFlavorTextOriginObjectName_ProfOak3, gFameCheckerFlavorTextOriginObjectName_ProfOak4, gFameCheckerFlavorTextOriginObjectName_ProfOak5,
//     gFameCheckerFlavorTextOriginObjectName_Daisy0, gFameCheckerFlavorTextOriginObjectName_Daisy1, gFameCheckerFlavorTextOriginObjectName_Daisy2, gFameCheckerFlavorTextOriginObjectName_Daisy3, gFameCheckerFlavorTextOriginObjectName_Daisy4, gFameCheckerFlavorTextOriginObjectName_Daisy5,
//     gFameCheckerFlavorTextOriginObjectName_Brock0, gFameCheckerFlavorTextOriginObjectName_Brock1, gFameCheckerFlavorTextOriginObjectName_Brock2, gFameCheckerFlavorTextOriginObjectName_Brock3, gFameCheckerFlavorTextOriginObjectName_Brock4, gFameCheckerFlavorTextOriginObjectName_Brock5,
//     gFameCheckerFlavorTextOriginObjectName_Misty0, gFameCheckerFlavorTextOriginObjectName_Misty1, gFameCheckerFlavorTextOriginObjectName_Misty2, gFameCheckerFlavorTextOriginObjectName_Misty3, gFameCheckerFlavorTextOriginObjectName_Misty4, gFameCheckerFlavorTextOriginObjectName_Misty5,
//     gFameCheckerFlavorTextOriginObjectName_LtSurge0, gFameCheckerFlavorTextOriginObjectName_LtSurge1, gFameCheckerFlavorTextOriginObjectName_LtSurge2, gFameCheckerFlavorTextOriginObjectName_LtSurge3, gFameCheckerFlavorTextOriginObjectName_LtSurge4, gFameCheckerFlavorTextOriginObjectName_LtSurge5,
//     gFameCheckerFlavorTextOriginObjectName_Erika0, gFameCheckerFlavorTextOriginObjectName_Erika1, gFameCheckerFlavorTextOriginObjectName_Erika2, gFameCheckerFlavorTextOriginObjectName_Erika3, gFameCheckerFlavorTextOriginObjectName_Erika4, gFameCheckerFlavorTextOriginObjectName_Erika5,
//     gFameCheckerFlavorTextOriginObjectName_Koga0, gFameCheckerFlavorTextOriginObjectName_Koga1, gFameCheckerFlavorTextOriginObjectName_Koga2, gFameCheckerFlavorTextOriginObjectName_Koga3, gFameCheckerFlavorTextOriginObjectName_Koga4, gFameCheckerFlavorTextOriginObjectName_Koga5,
//     gFameCheckerFlavorTextOriginObjectName_Sabrina0, gFameCheckerFlavorTextOriginObjectName_Sabrina1, gFameCheckerFlavorTextOriginObjectName_Sabrina2, gFameCheckerFlavorTextOriginObjectName_Sabrina3, gFameCheckerFlavorTextOriginObjectName_Sabrina4, gFameCheckerFlavorTextOriginObjectName_Sabrina5,
//     gFameCheckerFlavorTextOriginObjectName_Blaine0, gFameCheckerFlavorTextOriginObjectName_Blaine1, gFameCheckerFlavorTextOriginObjectName_Blaine2, gFameCheckerFlavorTextOriginObjectName_Blaine3, gFameCheckerFlavorTextOriginObjectName_Blaine4, gFameCheckerFlavorTextOriginObjectName_Blaine5,
//     gFameCheckerFlavorTextOriginObjectName_Lorelei0, gFameCheckerFlavorTextOriginObjectName_Lorelei1, gFameCheckerFlavorTextOriginObjectName_Lorelei2, gFameCheckerFlavorTextOriginObjectName_Lorelei3, gFameCheckerFlavorTextOriginObjectName_Lorelei4, gFameCheckerFlavorTextOriginObjectName_Lorelei5,
//     gFameCheckerFlavorTextOriginObjectName_Bruno0, gFameCheckerFlavorTextOriginObjectName_Bruno1, gFameCheckerFlavorTextOriginObjectName_Bruno2, gFameCheckerFlavorTextOriginObjectName_Bruno3, gFameCheckerFlavorTextOriginObjectName_Bruno4, gFameCheckerFlavorTextOriginObjectName_Bruno5,
//     gFameCheckerFlavorTextOriginObjectName_Agatha0, gFameCheckerFlavorTextOriginObjectName_Agatha1, gFameCheckerFlavorTextOriginObjectName_Agatha2, gFameCheckerFlavorTextOriginObjectName_Agatha3, gFameCheckerFlavorTextOriginObjectName_Agatha4, gFameCheckerFlavorTextOriginObjectName_Agatha5,
//     gFameCheckerFlavorTextOriginObjectName_Lance0, gFameCheckerFlavorTextOriginObjectName_Lance1, gFameCheckerFlavorTextOriginObjectName_Lance2, gFameCheckerFlavorTextOriginObjectName_Lance3, gFameCheckerFlavorTextOriginObjectName_Lance4, gFameCheckerFlavorTextOriginObjectName_Lance5,
//     gFameCheckerFlavorTextOriginObjectName_Bill0, gFameCheckerFlavorTextOriginObjectName_Bill1, gFameCheckerFlavorTextOriginObjectName_Bill2, gFameCheckerFlavorTextOriginObjectName_Bill3, gFameCheckerFlavorTextOriginObjectName_Bill4, gFameCheckerFlavorTextOriginObjectName_Bill5,
//     gFameCheckerFlavorTextOriginObjectName_MrFuji0, gFameCheckerFlavorTextOriginObjectName_MrFuji1, gFameCheckerFlavorTextOriginObjectName_MrFuji2, gFameCheckerFlavorTextOriginObjectName_MrFuji3, gFameCheckerFlavorTextOriginObjectName_MrFuji4, gFameCheckerFlavorTextOriginObjectName_MrFuji5,
//     gFameCheckerFlavorTextOriginObjectName_Giovanni0, gFameCheckerFlavorTextOriginObjectName_Giovanni1, gFameCheckerFlavorTextOriginObjectName_Giovanni2, gFameCheckerFlavorTextOriginObjectName_Giovanni3, gFameCheckerFlavorTextOriginObjectName_Giovanni4, gFameCheckerFlavorTextOriginObjectName_Giovanni5
// };

// static const struct SpriteSheet sUISpriteSheets[] = {
//     {sSelectorCursorSpriteGfx,   0x400, SPRITETAG_SELECTOR_CURSOR},
//     {sQuestionMarkSpriteGfx,     0x100, SPRITETAG_QUESTION_MARK},
//     {sSpinningPokeballSpriteGfx, 0x1e0, SPRITETAG_SPINNING_POKEBALL},
//     {sDaisySpriteGfx,            0x800, SPRITETAG_DAISY},
//     {sFujiSpriteGfx,             0x800, SPRITETAG_FUJI},
//     {sOakSpriteGfx,              0x800, SPRITETAG_OAK},
//     {sBillSpriteGfx,             0x800, SPRITETAG_BILL},
//     {}
// };

// static const struct SpritePalette sUISpritePalettes[] = {
//     {sSelectorCursorSpritePalette, SPRITETAG_SELECTOR_CURSOR},
//     {sSpinningPokeballSpritePalette, SPRITETAG_SPINNING_POKEBALL},
//     {}
// };

// static const struct BgTemplate sUIBgTemplates[4] = {
//     {
//         .bg = 3,
//         .charBaseIndex = 3,
//         .mapBaseIndex =  30,
//         .screenSize = 0,
//         .paletteMode = FALSE,
//         .priority = 3,
//         .baseTile = 0x000
//     },
//     {
//         .bg = 2,
//         .charBaseIndex = 3,
//         .mapBaseIndex =  27,
//         .screenSize = 0,
//         .paletteMode = FALSE,
//         .priority = 2,
//         .baseTile = 0x000
//     },
//     {
//         .bg = 1,
//         .charBaseIndex = 3,
//         .mapBaseIndex =  28,
//         .screenSize = 1,
//         .paletteMode = FALSE,
//         .priority = 0,
//         .baseTile = 0x000
//     },
//     {
//         .bg = 0,
//         .charBaseIndex = 0,
//         .mapBaseIndex =  31,
//         .screenSize = 0,
//         .paletteMode = FALSE,
//         .priority = 2,
//         .baseTile = 0x000
//     },
// };

// static const struct WindowTemplate sUIWindowTemplates[] = {
//     [FCWINDOWID_LIST] = {
//         .bg = 0,
//         .tilemapLeft = 1,
//         .tilemapTop = 3,
//         .width = 8,
//         .height = 10,
//         .paletteNum = 15,
//         .baseBlock = 20
//     },
//     [FCWINDOWID_UIHELP] = {
//         .bg = 0,
//         .tilemapLeft = 6,
//         .tilemapTop = 0,
//         .width = 24,
//         .height = 2,
//         .paletteNum = 15,
//         .baseBlock = 20 + 8 * 10
//     },
//     [FCWINDOWID_MSGBOX] = {
//         .bg = 0,
//         .tilemapLeft = 2,
//         .tilemapTop = 15,
//         .width = 26,
//         .height = 4,
//         .paletteNum = 15,
//         .baseBlock = 20 + 8 * 10 + 24 * 2
//     },
//     [FCWINDOWID_ICONDESC] = {
//         .bg = 0,
//         .tilemapLeft = 15,
//         .tilemapTop = 10,
//         .width = 11,
//         .height = 4,
//         .paletteNum = 15,
//         .baseBlock = 20 + 8 * 10 + 24 * 2 + 26 * 4
//     },
//     DUMMY_WIN_TEMPLATE
// };

// static const union AnimCmd sSelectorCursorAnim0[] = {
//     ANIMCMD_FRAME( 0, 15),
//     ANIMCMD_FRAME(16, 15),
//     ANIMCMD_JUMP(0)
// };

// static const union AnimCmd *const sSelectorCursorAnims[] = {
//     sSelectorCursorAnim0
// };

// static const struct OamData sSelectorCursorOamData = {
//     .size = 2,
//     .priority = 2
// };

// static const struct SpriteTemplate sSpriteTemplate_SelectorCursor = {
//     SPRITETAG_SELECTOR_CURSOR, SPRITETAG_SELECTOR_CURSOR, &sSelectorCursorOamData, sSelectorCursorAnims, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
// };

// static const u8 sUnused[8] = {}; // ???

// static const struct OamData sQuestionMarkTileOamData = {
//     .shape = ST_OAM_V_RECTANGLE,
//     .size = 2,
//     .priority = 2
// };

// static const union AnimCmd sQuestionMarkTileAnim0[] = {
//     ANIMCMD_FRAME( 0, 10),
//     ANIMCMD_END
// };

// static const union AnimCmd *const sQuestionMarkTileAnims[] = {
//     sQuestionMarkTileAnim0
// };

// static const struct SpriteTemplate sQuestionMarkTileSpriteTemplate = {
//     SPRITETAG_QUESTION_MARK, 0xffff, &sQuestionMarkTileOamData, sQuestionMarkTileAnims, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
// };

// static const union AnimCmd sSpinningPokeballAnim0[] = {
//     ANIMCMD_FRAME( 0, 10),
//     ANIMCMD_END
// };

// static const union AnimCmd *const sSpinningPokeballAnims[] = {
//     sSpinningPokeballAnim0
// };

// static const struct OamData sSpinningPokeballOamData = {
//     .affineMode = ST_OAM_AFFINE_NORMAL,
//     .size = 2
// };

// static const union AffineAnimCmd sSpinningPokeballAffineAnim0[] = {
//     AFFINEANIMCMD_FRAME(0, 0, 4, 20),
//     AFFINEANIMCMD_JUMP(0)
// };

// static const union AffineAnimCmd *const sSpinningPokeballAffineAnims[] = {
//     sSpinningPokeballAffineAnim0
// };

// static const struct SpriteTemplate sSpinningPokeballSpriteTemplate = {
//     SPRITETAG_SPINNING_POKEBALL, SPRITETAG_SPINNING_POKEBALL, &sSpinningPokeballOamData, sSpinningPokeballAnims, NULL, sSpinningPokeballAffineAnims, SpriteCB_FCSpinningPokeball
// };

// static const union AnimCmd sDaisyFujiOakBillAnim0[] = {
//     ANIMCMD_FRAME( 0, 15),
//     ANIMCMD_END
// };

// static const union AnimCmd *const sDaisyFujiOakBillAnims[] = {
//     sDaisyFujiOakBillAnim0
// };

// static const struct OamData sDaisyFujiOakBillOamData = {
//     .size = 3
// };

// static const struct SpriteTemplate sDaisySpriteTemplate = {
//     SPRITETAG_DAISY, 0xffff, &sDaisyFujiOakBillOamData, sDaisyFujiOakBillAnims, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
// };

// static const struct SpriteTemplate sFujiSpriteTemplate = {
//     SPRITETAG_FUJI, 0xffff, &sDaisyFujiOakBillOamData, sDaisyFujiOakBillAnims, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
// };

// static const struct SpriteTemplate sOakSpriteTemplate = {
//     SPRITETAG_OAK, 0xffff, &sDaisyFujiOakBillOamData, sDaisyFujiOakBillAnims, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
// };

// static const struct SpriteTemplate sBillSpriteTemplate = {
//     SPRITETAG_BILL, 0xffff, &sDaisyFujiOakBillOamData, sDaisyFujiOakBillAnims, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
// };

// static void FC_VBlankCallback(void)
// {
//     LoadOam();
//     ProcessSpriteCopyRequests();
//     TransferPlttBuffer();
// }

// static void MainCB2_FameCheckerMain(void)
// {
//     RunTasks();
//     AnimateSprites();
//     BuildOamBuffer();
//     UpdatePaletteFade();
// }

// void UseFameChecker(MainCallback savedCallback)
// {
//     SetVBlankCallback(NULL);
//     sFameCheckerData = AllocZeroed(sizeof(struct FameCheckerData));
//     sFameCheckerData->savedCallback = savedCallback;
//     sFameCheckerData->listMenuCurIdx = 0;
//     sFameCheckerData->listMenuTopIdx2 = 0;
//     sFameCheckerData->listMenuDrawnSelIdx = 0;
//     sFameCheckerData->viewingFlavorText = FALSE;
//     PlaySE(SE_M_SWIFT);
//     SetMainCallback2(MainCB2_LoadFameChecker);
// }

// static void MainCB2_LoadFameChecker(void)
// {
//     switch (gMain.state)
//     {
//         case 0:
//             SetVBlankCallback(NULL);
//             FCSetup_ClearVideoRegisters();
//             gMain.state++;
//             break;
//         case 1:
//             FCSetup_ResetTasksAndSpriteResources();
//             gMain.state++;
//             break;
//         case 2:
//             sBg3TilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);     // 256x256
//             sBg1TilemapBuffer = AllocZeroed(BG_SCREEN_SIZE * 2); // 512x256
//             sBg2TilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);     // 256x256
//             ResetBgsAndClearDma3BusyFlags(0);
//             InitBgsFromTemplates(0, sUIBgTemplates, NELEMS(sUIBgTemplates));
//             SetBgTilemapBuffer(3, sBg3TilemapBuffer);
//             SetBgTilemapBuffer(2, sBg2TilemapBuffer);
//             SetBgTilemapBuffer(1, sBg1TilemapBuffer);
//             FCSetup_ResetBGCoords();
//             gMain.state++;
//             break;
//         case 3:
//             LoadBgTiles(3, gFameCheckerBgTiles, sizeof(gFameCheckerBgTiles), 0);
//             CopyToBgTilemapBufferRect(3, gFameCheckerBg3Tilemap, 0, 0, 32, 32);
//             LoadPalette(&gFameCheckerBgPals[0], BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
//             LoadPalette(&gFameCheckerBgPals[16], BG_PLTT_ID(1), PLTT_SIZE_4BPP);
//             CopyToBgTilemapBufferRect(2, gFameCheckerBg2Tilemap, 0, 0, 32, 32);
//             CopyToBgTilemapBufferRect_ChangePalette(1, sFameCheckerTilemap, 30, 0, 32, 32, 0x11);
//             LoadPalette(GetTextWindowPalette(2), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
//             gMain.state++;
//             break;
//         case 4:
//             if (IsDma3ManagerBusyWithBgCopy() != TRUE)
//             {
//                 ShowBg(0);
//                 ShowBg(1);
//                 ShowBg(2);
//                 ShowBg(3);
//                 CopyBgTilemapBufferToVram(3);
//                 CopyBgTilemapBufferToVram(2);
//                 CopyBgTilemapBufferToVram(1);
//                 gMain.state++;
//             }
//             break;
//         case 5:
//             InitWindows(sUIWindowTemplates);
//             DeactivateAllTextPrinters();
//             Setup_DrawMsgAndListBoxes();
//             sListMenuItems = AllocZeroed(17 * sizeof(struct ListMenuItem));
//             FC_CreateListMenu();
//             gMain.state++;
//             break;
//         case 6:
//             LoadUISpriteSheetsAndPalettes();
//             CreateAllFlavorTextIcons(FAMECHECKER_OAK);
//             WipeMsgBoxAndTransfer();
//             BeginNormalPaletteFade(PALETTES_ALL,0, 16, 0, 0);
//             gMain.state++;
//             break;
//         case 7:
//             FCSetup_TurnOnDisplay();
//             SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG0 | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD);
//             SetGpuReg(REG_OFFSET_BLDALPHA, 0x07);
//             SetGpuReg(REG_OFFSET_BLDY, 0x08);
//             SetVBlankCallback(FC_VBlankCallback);
//             sFameCheckerData->listMenuTopIdx = 0;
//             FC_CreateScrollIndicatorArrowPair();
//             UpdateInfoBoxTilemap(1, 4);
//             CreateTask(Task_WaitFadeOnInit, 0x08);
//             SetMainCallback2(MainCB2_FameCheckerMain);
//             gMain.state = 0;
//             break;
//     }
// }

// static void LoadUISpriteSheetsAndPalettes(void)
// {
//     LoadSpriteSheets(sUISpriteSheets);
//     LoadSpritePalettes(sUISpritePalettes);
// }

// static void Task_WaitFadeOnInit(u8 taskId)
// {
//     if (!gPaletteFade.active)
//         gTasks[taskId].func = Task_TopMenuHandleInput;
// }

// static void Task_TopMenuHandleInput(u8 taskId)
// {
//     u16 cursorPos;
//     u8 i;
//     struct Task *task = &gTasks[taskId];
//     s16 * data = gTasks[taskId].data;
//     if (FindTaskIdByFunc(Task_FCOpenOrCloseInfoBox) == 0xFF)
//     {
//         RunTextPrinters();
//         if ((JOY_NEW(SELECT_BUTTON)) && !sFameCheckerData->inPickMode && sFameCheckerData->savedCallback != CB2_BagMenuFromStartMenu)
//             task->func = Task_StartToCloseFameChecker;
//         else if (JOY_NEW(START_BUTTON))
//         {
//             cursorPos = FameCheckerGetCursorY();
//             if (TryExitPickMode(taskId) == TRUE)
//             {
//                 PlaySE(SE_M_LOCK_ON);
//             }
//             else if (cursorPos != sFameCheckerData->numUnlockedPersons - 1) // anything but CANCEL
//             {
//                 PlaySE(SE_M_LOCK_ON);
//                 FillWindowPixelRect(FCWINDOWID_ICONDESC, PIXEL_FILL(0), 0, 0, 88, 32);
//                 FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_ICONDESC);
//                 UpdateInfoBoxTilemap(2, 4);
//                 UpdateInfoBoxTilemap(1, 5);
//                 PrintUIHelp(1);
//                 task->data[2] = CreatePersonPicSprite(sFameCheckerData->unlockedPersons[cursorPos]);
//                 gSprites[task->data[2]].x2 = 0xF0;
//                 gSprites[task->data[2]].data[0] = 1;
//                 task->data[3] = CreateSpinningPokeballSprite();
//                 gSprites[task->data[3]].x2 = 0xF0;
//                 gSprites[task->data[3]].data[0] = 1;
//                 task->func = Task_EnterPickMode;
//             }
//         }
//         else if (JOY_NEW(A_BUTTON))
//         {
//             cursorPos = ListMenu_ProcessInput(0);
//             if (cursorPos == sFameCheckerData->numUnlockedPersons - 1) // CANCEL
//                 task->func = Task_StartToCloseFameChecker;
//             else if (sFameCheckerData->inPickMode)
//             {
//                 if (!IsTextPrinterActive(2) && HasUnlockedAllFlavorTextsForCurrentPerson() == TRUE)
//                     GetPickModeText();
//             }
//             else if (sFameCheckerData->personHasUnlockedPanels)
//             {
//                 PlaySE(SE_SELECT);
//                 task->data[0] = CreateFlavorTextIconSelectorCursorSprite(task->data[1]);
//                 for (i = 0; i < 6; i++)
//                 {
//                     if (i != task->data[1])
//                         SetMessageSelectorIconObjMode(sFameCheckerData->spriteIds[i], ST_OAM_OBJ_BLEND);
//                 }
//                 gIconDescriptionBoxIsOpen = 0xFF;
//                 PlaceListMenuCursor(FALSE);
//                 PrintUIHelp(2);
//                 if (gSprites[sFameCheckerData->spriteIds[task->data[1]]].data[1] != 0xFF) // not a ? tile
//                 {
//                     PrintSelectedNameInBrightGreen(taskId);
//                     UpdateIconDescriptionBox(data[1]);
//                 }
//                 FreeListMenuSelectorArrowPairResources();
//                 task->func = Task_FlavorTextDisplayHandleInput;
//             }
//         }
//         else if (JOY_NEW(B_BUTTON))
//         {
//             if (TryExitPickMode(taskId) != TRUE)
//                 task->func = Task_StartToCloseFameChecker;
//         }
//         else
//             ListMenu_ProcessInput(0);
//     }
// }

// static bool8 TryExitPickMode(u8 taskId)
// {
//     struct Task *task = &gTasks[taskId];
//     if (sFameCheckerData->inPickMode)
//     {
//         gSprites[task->data[2]].data[0] = 2;
//         gSprites[task->data[2]].x2 += 10;
//         gSprites[task->data[3]].data[0] = 2;
//         gSprites[task->data[3]].x2 += 10;
//         WipeMsgBoxAndTransfer();
//         task->func = Task_ExitPickMode;
//         MessageBoxPrintEmptyText();
//         sFameCheckerData->pickModeOverCancel = FALSE;
//         return TRUE;
//     }
//     return FALSE;
// }

// static void MessageBoxPrintEmptyText(void)
// {
//     AddTextPrinterParameterized2(FCWINDOWID_MSGBOX, FONT_NORMAL, gFameCheckerText_ClearTextbox, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
// }

// static void Task_EnterPickMode(u8 taskId)
// {
//     struct Task *task = &gTasks[taskId];
//     if (gSprites[task->data[2]].data[0] == 0)
//     {
//         GetPickModeText();
//         sFameCheckerData->inPickMode = TRUE;
//         task->func = Task_TopMenuHandleInput;
//     }
//     else
//         ChangeBgX(1, 0xA00, 1);
// }

// static void Task_ExitPickMode(u8 taskId)
// {
//     struct Task *task = &gTasks[taskId];
//     if (GetBgX(1) != 0)
//         ChangeBgX(1, 0xA00, 2);
//     else
//         ChangeBgX(1, 0x000, 0);
//     if (gSprites[task->data[2]].data[0] == 0)
//     {
//         if (sFameCheckerData->personHasUnlockedPanels)
//             PrintUIHelp(0);
//         UpdateInfoBoxTilemap(1, 4);
//         UpdateInfoBoxTilemap(2, 2);
//         sFameCheckerData->inPickMode = FALSE;
//         DestroyPersonPicSprite(taskId, FameCheckerGetCursorY());
//         task->func = Task_TopMenuHandleInput;
//         gSprites[task->data[3]].callback = SpriteCB_DestroySpinningPokeball;
//     }
// }

// static void Task_FlavorTextDisplayHandleInput(u8 taskId)
// {
//     struct Task *task = &gTasks[taskId];
//     s16 *data = gTasks[taskId].data;

//     RunTextPrinters();
//     if (JOY_NEW(A_BUTTON) && !IsTextPrinterActive(2))
//     {
//         u8 spriteId = sFameCheckerData->spriteIds[data[1]];
//         if (gSprites[spriteId].data[1] != 0xFF)
//             PrintSelectedNameInBrightGreen(taskId);
//     }
//     if (JOY_NEW(B_BUTTON))
//     {
//         u8 i;
//         PlaySE(SE_SELECT);
//         for (i = 0; i < 6; i++)
//             SetMessageSelectorIconObjMode(sFameCheckerData->spriteIds[i], ST_OAM_OBJ_NORMAL);
//         WipeMsgBoxAndTransfer();
//         gSprites[task->data[0]].callback = SpriteCB_DestroyFlavorTextIconSelectorCursor;
//         if (gIconDescriptionBoxIsOpen != 0xFF)
//             UpdateIconDescriptionBoxOff();
//         PlaceListMenuCursor(TRUE);
//         PrintUIHelp(0);
//         FC_CreateScrollIndicatorArrowPair();
//         MessageBoxPrintEmptyText();
//         task->func = Task_TopMenuHandleInput;
//     }
//     else if (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_DOWN))
//     {
//         if (task->data[1] >= 3)
//         {
//             task->data[1] -= 3;
//             FC_MoveSelectorCursor(taskId, 0, -0x1b);
//         }
//         else
//         {
//             task->data[1] += 3;
//             FC_MoveSelectorCursor(taskId, 0, +0x1b);
//         }
//     }
//     else if (JOY_NEW(DPAD_LEFT))
//     {
//         if (task->data[1] == 0 || task->data[1] % 3 == 0)
//         {
//             task->data[1] += 2;
//             FC_MoveSelectorCursor(taskId, +0x5e, 0);
//         }
//         else
//         {
//             task->data[1]--;
//             FC_MoveSelectorCursor(taskId, -0x2f, 0);
//         }
//     }
//     else if (JOY_NEW(DPAD_RIGHT))
//     {
//         if ((task->data[1] + 1) % 3 == 0)
//         {
//             task->data[1] -= 2;
//             FC_MoveSelectorCursor(taskId, -0x5e, 0);
//         }
//         else
//         {
//             task->data[1]++;
//             FC_MoveSelectorCursor(taskId, +0x2f, 0);
//         }
//     }
// }

// static void FC_MoveSelectorCursor(u8 taskId, s8 dx, s8 dy)
// {
//     u8 i;
//     s16 *data = gTasks[taskId].data;
//     PlaySE(SE_M_SWAGGER2);
//     gSprites[data[0]].x += dx;
//     gSprites[data[0]].y += dy;
//     for (i = 0; i < 6; i++)
//         SetMessageSelectorIconObjMode(sFameCheckerData->spriteIds[i], ST_OAM_OBJ_BLEND);
//     FillWindowPixelRect(FCWINDOWID_MSGBOX, PIXEL_FILL(1), 0, 0, 0xd0, 0x20);
//     MessageBoxPrintEmptyText();
//     if (SetMessageSelectorIconObjMode(sFameCheckerData->spriteIds[data[1]], ST_OAM_OBJ_NORMAL) == TRUE)
//     {
//         PrintSelectedNameInBrightGreen(taskId);
//         UpdateIconDescriptionBox(data[1]);
//     }
//     else if (gIconDescriptionBoxIsOpen != 0xFF)
//         UpdateIconDescriptionBoxOff();
// }

// static void GetPickModeText(void)
// {
//     s32 whichText = 0;
//     u16 who = FameCheckerGetCursorY();
//     if (gSaveBlock1Ptr->fameChecker[sFameCheckerData->unlockedPersons[who]].pickState != FCPICKSTATE_COLORED)
//     {
//         WipeMsgBoxAndTransfer();
//         MessageBoxPrintEmptyText();
//     }
//     else
//     {
//         FillWindowPixelRect(FCWINDOWID_MSGBOX, PIXEL_FILL(1), 0, 0, 0xd0, 0x20);
//         if (HasUnlockedAllFlavorTextsForCurrentPerson() == TRUE)
//             whichText = NUM_FAMECHECKER_PERSONS;
//         StringExpandPlaceholders(gStringVar4, sFameCheckerNameAndQuotesPointers[sFameCheckerData->unlockedPersons[who] + whichText]);
//         AddTextPrinterParameterized2(FCWINDOWID_MSGBOX, FONT_NORMAL, gStringVar4, GetPlayerTextSpeedDelay(), NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
//         FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_MSGBOX);
//     }
// }

// static void PrintSelectedNameInBrightGreen(u8 taskId)
// {
//     s16 *data = gTasks[taskId].data;
//     u16 cursorPos = FameCheckerGetCursorY();
//     FillWindowPixelRect(FCWINDOWID_MSGBOX, PIXEL_FILL(1), 0, 0, 0xd0, 0x20);
//     StringExpandPlaceholders(gStringVar4, sFameCheckerFlavorTextPointers[sFameCheckerData->unlockedPersons[cursorPos] * 6 + data[1]]);
//     AddTextPrinterParameterized2(FCWINDOWID_MSGBOX, FONT_NORMAL, gStringVar4, GetPlayerTextSpeedDelay(), NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_MSGBOX);
// }

// static void WipeMsgBoxAndTransfer(void)
// {
//     FillWindowPixelRect(FCWINDOWID_MSGBOX, PIXEL_FILL(1), 0, 0, 0xd0, 0x20);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_MSGBOX);
// }

// static void Setup_DrawMsgAndListBoxes(void)
// {
//     LoadMessageBoxAndBorderGfx();
//     DrawDialogueFrame(FCWINDOWID_MSGBOX, TRUE);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_MSGBOX);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_LIST);
// }

// static void FC_PutWindowTilemapAndCopyWindowToVramMode3(u8 windowId)
// {
//     PutWindowTilemap(windowId);
//     CopyWindowToVram(windowId, COPYWIN_FULL);
// }

// static bool8 SetMessageSelectorIconObjMode(u8 spriteId, u8 objMode)
// {
//     if (gSprites[spriteId].data[1] != 0xFF)
//     {
//         gSprites[spriteId].oam.objMode = objMode;
//         return TRUE;
//     }
//     return FALSE;
// }

// static void Task_StartToCloseFameChecker(u8 taskId)
// {
//     PlaySE(SE_M_SWIFT);
//     BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, 0);
//     gTasks[taskId].func = Task_DestroyAssetsAndCloseFameChecker;
// }

// static void Task_DestroyAssetsAndCloseFameChecker(u8 taskId)
// {
//     u8 i;

//     if (!gPaletteFade.active)
//     {
//         if (sFameCheckerData->inPickMode)
//         {
//             DestroyPersonPicSprite(taskId, FameCheckerGetCursorY());
//             FreeSpriteOamMatrix(&gSprites[gTasks[taskId].data[3]]);
//             DestroySprite(&gSprites[gTasks[taskId].data[3]]);
//         }
//         for (i = 0; i < 6; i++)
//         {
//             DestroySprite(&gSprites[sFameCheckerData->spriteIds[i]]);
//         }
//         FreeNonTrainerPicTiles();
//         FreeSpinningPokeballSpriteResources();
//         FreeSelectionCursorSpriteResources();
//         FreeQuestionMarkSpriteResources();
//         FreeListMenuSelectorArrowPairResources();
//         SetMainCallback2(sFameCheckerData->savedCallback);
//         DestroyListMenuTask(sFameCheckerData->listMenuTaskId, NULL, NULL);
//         Free(sBg3TilemapBuffer);
//         Free(sBg1TilemapBuffer);
//         Free(sBg2TilemapBuffer);
//         Free(sFameCheckerData);
//         Free(sListMenuItems);
//         FC_DestroyWindow(FCWINDOWID_LIST);
//         FC_DestroyWindow(FCWINDOWID_UIHELP);
//         FC_DestroyWindow(FCWINDOWID_MSGBOX);
//         FC_DestroyWindow(FCWINDOWID_ICONDESC);
//         FreeAllWindowBuffers();
//         DestroyTask(taskId);
//     }
// }

// static void FC_DestroyWindow(u8 windowId)
// {
//     FillWindowPixelBuffer(windowId, 0);
//     ClearWindowTilemap(windowId);
//     CopyWindowToVram(windowId, COPYWIN_GFX);
//     RemoveWindow(windowId);
// }

// static u8 AdjustGiovanniIndexIfBeatenInGym(u8 a0)
// {
//     if (HasTrainerBeenFought(TRAINER_LEADER_GIOVANNI) == TRUE)
//     {
//         if (a0 == 9)
//             return FAMECHECKER_GIOVANNI;
//         if (a0 > 9)
//             return a0 - 1;
//     }
//     return a0;
// }

// static void PrintUIHelp(u8 state)
// {
//     s32 width;
//     const u8 * src = gFameCheckerText_MainScreenUI;
//     if (state != 0)
//     {
//         src = gFameCheckerText_FlavorTextUI;
//         if (state == 1)
//             src = gFameCheckerText_PickScreenUI;
//     }
//     width = GetStringWidth(FONT_SMALL, src, 0);
//     FillWindowPixelRect(FCWINDOWID_UIHELP, PIXEL_FILL(0), 0, 0, 0xc0, 0x10);
//     AddTextPrinterParameterized4(FCWINDOWID_UIHELP, FONT_SMALL, 188 - width, 0, 0, 2, sTextColor_White, -1, src);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_UIHELP);
// }

// static void DestroyAllFlavorTextIcons(void)
// {
//     u8 i;
//     for (i = 0; i < 6; i++)
//     {
//         DestroySprite(&gSprites[sFameCheckerData->spriteIds[i]]);
//     }
// }

// static bool8 CreateAllFlavorTextIcons(u8 who)
// {
//     bool8 result = FALSE;
//     u8 i;
//     for (i = 0; i < 6; i++)
//     {
//         if ((gSaveBlock1Ptr->fameChecker[sFameCheckerData->unlockedPersons[who]].flavorTextFlags >> i) & 1)
//         {
//             sFameCheckerData->spriteIds[i] = CreateFameCheckerObject(
//                 sFameCheckerArrayNpcGraphicsIds[sFameCheckerData->unlockedPersons[who] * 6 + i],
//                 i,
//                 47 * (i % 3) + 0x72,
//                 27 * (i / 3) + 0x2F
//             );
//             result = TRUE;
//         }
//         else
//         {
//             sFameCheckerData->spriteIds[i] = PlaceQuestionMarkTile(
//                 47 * (i % 3) + 0x72,
//                 27 * (i / 3) + 0x1F
//             );
//             gSprites[sFameCheckerData->spriteIds[i]].data[1] = 0xFF;
//         }
//     }
//     if (result == TRUE)
//     {
//         sFameCheckerData->personHasUnlockedPanels = TRUE;
//         if (sFameCheckerData->inPickMode)
//             PrintUIHelp(1);
//         else
//             PrintUIHelp(0);
//     }
//     else
//     {
//         sFameCheckerData->personHasUnlockedPanels = FALSE;
//         PrintUIHelp(1);
//     }
//     return result;
// }

// void ResetFameChecker(void)
// {
//     u8 i;
//     for (i = 0; i < NUM_FAMECHECKER_PERSONS; i++)
//     {
//         gSaveBlock1Ptr->fameChecker[i].pickState = FCPICKSTATE_NO_DRAW;
//         gSaveBlock1Ptr->fameChecker[i].flavorTextFlags = 0;
//         gSaveBlock1Ptr->fameChecker[i].unk_0_E = 0;
//     }
//     gSaveBlock1Ptr->fameChecker[FAMECHECKER_OAK].pickState = FCPICKSTATE_COLORED;
// }

// void FullyUnlockFameChecker(void)
// {
//     u8 i, j;
//     for (i = 0; i < NUM_FAMECHECKER_PERSONS; i++)
//     {
//         gSaveBlock1Ptr->fameChecker[i].pickState = FCPICKSTATE_COLORED;
//         for (j = 0; j < 6; j++)
//         {
//             gSaveBlock1Ptr->fameChecker[i].flavorTextFlags |= (1 << j);
//         }
//     }
// }

// static void FCSetup_ClearVideoRegisters(void)
// {
//     void *vram = (void *)VRAM;
//     DmaClearLarge16(3, vram, VRAM_SIZE, 0x1000);
//     DmaClear32(3, OAM, OAM_SIZE);
//     DmaClear16(3, PLTT, PLTT_SIZE);
//     SetGpuReg(REG_OFFSET_DISPCNT,  0);
//     SetGpuReg(REG_OFFSET_BG0CNT,   0);
//     SetGpuReg(REG_OFFSET_BG0HOFS,  0);
//     SetGpuReg(REG_OFFSET_BG0VOFS,  0);
//     SetGpuReg(REG_OFFSET_BG1CNT,   0);
//     SetGpuReg(REG_OFFSET_BG1HOFS,  0);
//     SetGpuReg(REG_OFFSET_BG1VOFS,  0);
//     SetGpuReg(REG_OFFSET_BG2CNT,   0);
//     SetGpuReg(REG_OFFSET_BG2HOFS,  0);
//     SetGpuReg(REG_OFFSET_BG2VOFS,  0);
//     SetGpuReg(REG_OFFSET_BG3CNT,   0);
//     SetGpuReg(REG_OFFSET_BG3HOFS,  0);
//     SetGpuReg(REG_OFFSET_BG3VOFS,  0);
//     SetGpuReg(REG_OFFSET_WIN0H,    0);
//     SetGpuReg(REG_OFFSET_WIN0V,    0);
//     SetGpuReg(REG_OFFSET_WININ,    0);
//     SetGpuReg(REG_OFFSET_WINOUT,   0);
//     SetGpuReg(REG_OFFSET_BLDCNT,   0);
//     SetGpuReg(REG_OFFSET_BLDALPHA, 0);
//     SetGpuReg(REG_OFFSET_BLDY,     0);
// }

// static void FCSetup_ResetTasksAndSpriteResources(void)
// {
//     ScanlineEffect_Stop();
//     ResetTasks();
//     ResetSpriteData();
//     ResetAllPicSprites();
//     ResetPaletteFade();
//     InitObjectEventPalettes(0);
//     gReservedSpritePaletteCount = 7;

// }

// static void FCSetup_TurnOnDisplay(void)
// {
//     SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON);
// }

// static void FCSetup_ResetBGCoords(void)
// {
//     ChangeBgX(0, 0, 0);
//     ChangeBgY(0, 0, 0);
//     ChangeBgX(1, 0, 0);
//     ChangeBgY(1, 0, 0);
//     ChangeBgX(2, 0, 0);
//     ChangeBgY(2, 0, 0);
//     ChangeBgX(3, 0, 0);
//     ChangeBgY(3, 0, 0);
// }

void SetFlavorTextFlagFromSpecialVars(void)
{
    // if (gSpecialVar_0x8004 < NUM_FAMECHECKER_PERSONS && gSpecialVar_0x8005 < 6)
    // {
    //     gSaveBlock1Ptr->fameChecker[gSpecialVar_0x8004].flavorTextFlags |= (1 << gSpecialVar_0x8005);
    //     gSpecialVar_0x8005 = FCPICKSTATE_SILHOUETTE;
    //     UpdatePickStateFromSpecialVar8005();
    // }
}

void UpdatePickStateFromSpecialVar8005(void)
{
    // if (gSpecialVar_0x8004 < NUM_FAMECHECKER_PERSONS && gSpecialVar_0x8005 < 3)
    // {
    //     if (gSpecialVar_0x8005 == FCPICKSTATE_NO_DRAW)
    //         return;
    //     if (   gSpecialVar_0x8005 == FCPICKSTATE_SILHOUETTE
    //         && gSaveBlock1Ptr->fameChecker[gSpecialVar_0x8004].pickState == FCPICKSTATE_COLORED
    //        )
    //         return;
    //     gSaveBlock1Ptr->fameChecker[gSpecialVar_0x8004].pickState = gSpecialVar_0x8005;
    // }
}

// static bool8 HasUnlockedAllFlavorTextsForCurrentPerson(void)
// {
//     u8 i;
//     u8 who = sFameCheckerData->unlockedPersons[FameCheckerGetCursorY()];
//     for (i = 0; i < 6; i++)
//     {
//         if (!((gSaveBlock1Ptr->fameChecker[who].flavorTextFlags >> i) & 1))
//             return FALSE;
//     }
//     return TRUE;
// }

// static void FreeSelectionCursorSpriteResources(void)
// {
//     FreeSpriteTilesByTag(SPRITETAG_SELECTOR_CURSOR);
//     FreeSpritePaletteByTag(SPRITETAG_SELECTOR_CURSOR);
// }

// static u8 CreateFlavorTextIconSelectorCursorSprite(s16 where)
// {
//     s16 y =  34 + 27 * (where >= 3);
//     s16 x = 114 + 47 * (where %  3);
//     return CreateSprite(&sSpriteTemplate_SelectorCursor, x, y, 0);
// }

// static void SpriteCB_DestroyFlavorTextIconSelectorCursor(struct Sprite *sprite)
// {
//     DestroySprite(sprite);
// }

// static void FreeQuestionMarkSpriteResources(void)
// {
//     FreeSpriteTilesByTag(SPRITETAG_QUESTION_MARK);
// }

// static u8 PlaceQuestionMarkTile(u8 x, u8 y)
// {
//     u8 spriteId = CreateSprite(&sQuestionMarkTileSpriteTemplate, x, y, 8);
//     gSprites[spriteId].oam.priority = 2;
//     gSprites[spriteId].oam.paletteNum = 2;
//     return spriteId;
// }

// static void FreeSpinningPokeballSpriteResources(void)
// {
//     FreeSpriteTilesByTag(SPRITETAG_SPINNING_POKEBALL);
//     FreeSpritePaletteByTag(SPRITETAG_SPINNING_POKEBALL);
// }

// static u8 CreateSpinningPokeballSprite(void)
// {
//     return CreateSprite(&sSpinningPokeballSpriteTemplate, 0xe2, 0x42, 0);
// }

// static void SpriteCB_DestroySpinningPokeball(struct Sprite *sprite)
// {
//     FreeSpriteOamMatrix(sprite);
//     DestroySprite(sprite);
// }

// static void FreeNonTrainerPicTiles(void)
// {
//     FreeSpriteTilesByTag(SPRITETAG_DAISY);
//     FreeSpriteTilesByTag(SPRITETAG_FUJI);
//     FreeSpriteTilesByTag(SPRITETAG_OAK);
//     FreeSpriteTilesByTag(SPRITETAG_BILL);
// }

// static void SpriteCB_FCSpinningPokeball(struct Sprite *sprite)
// {
//     if (sprite->data[0] == 1)
//     {
//         if (sprite->x2 - 10 < 0)
//         {
//             sprite->x2 = 0;
//             sprite->data[0] = 0;
//         }
//         else
//             sprite->x2 -= 10;
//     }
//     else if (sprite->data[0] == 2)
//     {
//         if (sprite->x2 > 240)
//         {
//             sprite->x2 = 240;
//             sprite->data[0] = 0;
//         }
//         else
//             sprite->x2 += 10;
//     }
// }

// #define PERSON_PAL_NUM 6
// #define PERSON_X  148
// #define PERSON_Y   66

// static u8 CreatePersonPicSprite(u8 fcPersonIdx)
// {
//     u8 spriteId;
//     if (fcPersonIdx == FAMECHECKER_DAISY)
//     {
//         spriteId = CreateSprite(&sDaisySpriteTemplate, PERSON_X, PERSON_Y, 0);
//         LoadPalette(sDaisySpritePalette, OBJ_PLTT_ID(PERSON_PAL_NUM), sizeof(sDaisySpritePalette));
//         gSprites[spriteId].oam.paletteNum = PERSON_PAL_NUM;
//     }
//     else if (fcPersonIdx == FAMECHECKER_MRFUJI)
//     {
//         spriteId = CreateSprite(&sFujiSpriteTemplate, PERSON_X, PERSON_Y, 0);
//         LoadPalette(sFujiSpritePalette, OBJ_PLTT_ID(PERSON_PAL_NUM), sizeof(sFujiSpritePalette));
//         gSprites[spriteId].oam.paletteNum = PERSON_PAL_NUM;
//     }
//     else if (fcPersonIdx == FAMECHECKER_OAK)
//     {
//         spriteId = CreateSprite(&sOakSpriteTemplate, PERSON_X, PERSON_Y, 0);
//         LoadPalette(sOakSpritePalette, OBJ_PLTT_ID(PERSON_PAL_NUM), sizeof(sOakSpritePalette));
//         gSprites[spriteId].oam.paletteNum = PERSON_PAL_NUM;
//     }
//     else if (fcPersonIdx == FAMECHECKER_BILL)
//     {
//         spriteId = CreateSprite(&sBillSpriteTemplate, PERSON_X, PERSON_Y, 0);
//         LoadPalette(sBillSpritePalette, OBJ_PLTT_ID(PERSON_PAL_NUM), sizeof(sBillSpritePalette));
//         gSprites[spriteId].oam.paletteNum = PERSON_PAL_NUM;
//     }
//     else
//     {
//         spriteId = CreateTrainerPicSprite(sFameCheckerTrainerPicIdxs[fcPersonIdx], TRUE, PERSON_X, PERSON_Y, PERSON_PAL_NUM, TAG_NONE);
//     }
//     gSprites[spriteId].callback = SpriteCB_FCSpinningPokeball;
//     if (gSaveBlock1Ptr->fameChecker[fcPersonIdx].pickState == FCPICKSTATE_SILHOUETTE)
//         LoadPalette(sSilhouettePalette, OBJ_PLTT_ID(PERSON_PAL_NUM), sizeof(sSilhouettePalette));
//     return spriteId;
// }

// static void DestroyPersonPicSprite(u8 taskId, u16 who)
// {
//     s16 * data = gTasks[taskId].data;
//     u16 who_copy = who;
//     if (who == sFameCheckerData->numUnlockedPersons - 1)
//         who_copy = who - 1;
//     if (   sFameCheckerData->unlockedPersons[who_copy] == FAMECHECKER_DAISY
//         || sFameCheckerData->unlockedPersons[who_copy] == FAMECHECKER_MRFUJI
//         || sFameCheckerData->unlockedPersons[who_copy] == FAMECHECKER_OAK
//         || sFameCheckerData->unlockedPersons[who_copy] == FAMECHECKER_BILL
//     )
//         DestroySprite(&gSprites[data[2]]);
//     else
//         FreeAndDestroyTrainerPicSprite(data[2]);
// }

// static void UpdateIconDescriptionBox(u8 whichText)
// {
//     s32 width;
//     u32 idx = 6 * sFameCheckerData->unlockedPersons[FameCheckerGetCursorY()] + whichText;
//     HandleFlavorTextModeSwitch(TRUE);
//     gIconDescriptionBoxIsOpen = 1;
//     FillWindowPixelRect(FCWINDOWID_ICONDESC, PIXEL_FILL(0), 0, 0, 0x58, 0x20);
//     width = (0x54 - GetStringWidth(FONT_SMALL, sFlavorTextOriginLocationTexts[idx], 0)) / 2;
//     AddTextPrinterParameterized4(FCWINDOWID_ICONDESC, FONT_SMALL, width, 0, 0, 2, sTextColor_DkGrey, -1, sFlavorTextOriginLocationTexts[idx]);
//     StringExpandPlaceholders(gStringVar1, sFlavorTextOriginObjectNameTexts[idx]);
//     width = (0x54 - GetStringWidth(FONT_SMALL, gStringVar1, 0)) / 2;
//     AddTextPrinterParameterized4(FCWINDOWID_ICONDESC, FONT_SMALL, width, 10, 0, 2, sTextColor_DkGrey, -1, gStringVar1);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_ICONDESC);
// }

// static void UpdateIconDescriptionBoxOff(void)
// {
//     HandleFlavorTextModeSwitch(FALSE);
//     gIconDescriptionBoxIsOpen = 0xFF;
// }

// static void FC_CreateListMenu(void)
// {
//     InitListMenuTemplate();
//     sFameCheckerData->numUnlockedPersons = FC_PopulateListMenu();
//     sFameCheckerData->listMenuTaskId = ListMenuInit(&gFameChecker_ListMenuTemplate, 0, 0);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3_2(FCWINDOWID_LIST);
// }

// static void InitListMenuTemplate(void)
// {
//     gFameChecker_ListMenuTemplate.items = sListMenuItems;
//     gFameChecker_ListMenuTemplate.moveCursorFunc = FC_MoveCursorFunc;
//     gFameChecker_ListMenuTemplate.itemPrintFunc = NULL;
//     gFameChecker_ListMenuTemplate.totalItems = 1;
//     gFameChecker_ListMenuTemplate.maxShowed = 1;
//     gFameChecker_ListMenuTemplate.windowId = FCWINDOWID_LIST;
//     gFameChecker_ListMenuTemplate.header_X = 0;
//     gFameChecker_ListMenuTemplate.item_X = 8;
//     gFameChecker_ListMenuTemplate.cursor_X = 0;
//     gFameChecker_ListMenuTemplate.upText_Y = 4;
//     gFameChecker_ListMenuTemplate.cursorPal = 2;
//     gFameChecker_ListMenuTemplate.fillValue = 0;
//     gFameChecker_ListMenuTemplate.cursorShadowPal = 3;
//     gFameChecker_ListMenuTemplate.lettersSpacing = 0;
//     gFameChecker_ListMenuTemplate.itemVerticalPadding = 0;
//     gFameChecker_ListMenuTemplate.scrollMultiple = 0;
//     gFameChecker_ListMenuTemplate.fontId = FONT_NORMAL;
//     gFameChecker_ListMenuTemplate.cursorKind = 0;
// }

// static void FC_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
// {
//     u16 listMenuTopIdx;
//     u8 taskId;
//     u16 personIdx;
//     sLastMenuIdx = 0;
//     personIdx = sFameCheckerData->listMenuTopIdx2 + sFameCheckerData->listMenuDrawnSelIdx;
//     FC_DoMoveCursor(itemIndex, onInit);
//     taskId = FindTaskIdByFunc(Task_TopMenuHandleInput);
//     if (taskId != 0xFF)
//     {
//         struct Task *task = &gTasks[taskId];
//         PlaySE(SE_SELECT);
//         task->data[1] = 0;
//         ListMenuGetScrollAndRow(sFameCheckerData->listMenuTaskId, &listMenuTopIdx, NULL);
//         sFameCheckerData->listMenuTopIdx = listMenuTopIdx;
//         if (itemIndex != sFameCheckerData->numUnlockedPersons - 1)
//         {
//             DestroyAllFlavorTextIcons();
//             CreateAllFlavorTextIcons(itemIndex);
//             if (sFameCheckerData->inPickMode)
//             {
//                 if (!sFameCheckerData->pickModeOverCancel)
//                 {
//                     DestroyPersonPicSprite(taskId, personIdx);
//                     sLastMenuIdx = itemIndex;
//                     task->func = Task_SwitchToPickMode;
//                 }
//                 else
//                 {
//                     gSprites[task->data[2]].invisible = FALSE;
//                     sFameCheckerData->pickModeOverCancel = FALSE;
//                     gSprites[task->data[2]].data[0] = 0;
//                     GetPickModeText();
//                 }
//             }
//             else
//             {
//                 FillWindowPixelRect(FCWINDOWID_MSGBOX, PIXEL_FILL(1), 0, 0, 0xd0, 0x20);
//                 FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_MSGBOX);
//             }
//         }
//         else
//         {
//             PrintCancelDescription();
//             if (sFameCheckerData->inPickMode)
//             {
//                 gSprites[task->data[2]].invisible = TRUE;
//                 sFameCheckerData->pickModeOverCancel = TRUE;
//             }
//             else
//             {
//                 u8 i;
//                 for (i = 0; i < 6; i++)
//                 {
//                     gSprites[sFameCheckerData->spriteIds[i]].invisible = TRUE;
//                 }
//             }
//         }
//     }
// }

// static void Task_SwitchToPickMode(u8 taskId)
// {
//     struct Task *task = &gTasks[taskId];
//     task->data[2] = CreatePersonPicSprite(sFameCheckerData->unlockedPersons[sLastMenuIdx]);
//     gSprites[task->data[2]].data[0] = 0;
//     GetPickModeText();
//     task->func = Task_TopMenuHandleInput;
// }

// static void PrintCancelDescription(void)
// {
//     FillWindowPixelRect(FCWINDOWID_MSGBOX, PIXEL_FILL(1), 0, 0, 0xd0, 0x20);
//     AddTextPrinterParameterized2(FCWINDOWID_MSGBOX, FONT_NORMAL, gFameCheckerText_FameCheckerWillBeClosed, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
//     FC_PutWindowTilemapAndCopyWindowToVramMode3(FCWINDOWID_MSGBOX);
// }

// static void FC_DoMoveCursor(s32 itemIndex, bool8 onInit)
// {
//     u16 listY;
//     u16 cursorY;
//     u16 who;
//     ListMenuGetScrollAndRow(sFameCheckerData->listMenuTaskId, &listY, &cursorY);
//     who = listY + cursorY;
//     AddTextPrinterParameterized4(FCWINDOWID_LIST, FONT_NORMAL, 8, 14 * cursorY + 4, 0, 0, sTextColor_Green, 0, sListMenuItems[itemIndex].name);
//     if (!onInit)
//     {
//         if (listY < sFameCheckerData->listMenuTopIdx2)
//             sFameCheckerData->listMenuDrawnSelIdx++;
//         else if (listY > sFameCheckerData->listMenuTopIdx2 && who != sFameCheckerData->numUnlockedPersons - 1)
//             sFameCheckerData->listMenuDrawnSelIdx--;
//         AddTextPrinterParameterized4(FCWINDOWID_LIST, FONT_NORMAL, 8, 14 * sFameCheckerData->listMenuDrawnSelIdx + 4, 0, 0, sTextColor_DkGrey, 0, sListMenuItems[sFameCheckerData->listMenuCurIdx].name);

//     }
//     sFameCheckerData->listMenuCurIdx = itemIndex;
//     sFameCheckerData->listMenuDrawnSelIdx = cursorY;
//     sFameCheckerData->listMenuTopIdx2 = listY;
// }

// static u8 FC_PopulateListMenu(void)
// {
//     u8 nitems = 0;
//     u8 i;

//     for (i = 0; i < NUM_FAMECHECKER_PERSONS; i++)
//     {
//         u8 fameCheckerIdx = AdjustGiovanniIndexIfBeatenInGym(i);
//         if (gSaveBlock1Ptr->fameChecker[fameCheckerIdx].pickState != FCPICKSTATE_NO_DRAW)
//         {
//             if (sTrainerIdxs[fameCheckerIdx] < FC_NONTRAINER_START)
//             {
//                 sListMenuItems[nitems].name = GetTrainerClassNameFromId(sTrainerIdxs[fameCheckerIdx]);
//                 sListMenuItems[nitems].id = nitems;
//             }
//             else
//             {
//                 sListMenuItems[nitems].name = sNonTrainerNamePointers[sTrainerIdxs[fameCheckerIdx] - FC_NONTRAINER_START];
//                 sListMenuItems[nitems].id = nitems;
//             }
//             sFameCheckerData->unlockedPersons[nitems] = fameCheckerIdx;
//             nitems++;
//         }
//     }
//     sListMenuItems[nitems].name = gFameCheckerText_Cancel;
//     sListMenuItems[nitems].id = nitems;
//     sFameCheckerData->unlockedPersons[nitems] = 0xFF;
//     nitems++;
//     gFameChecker_ListMenuTemplate.totalItems = nitems;
//     if (nitems < 5)
//         gFameChecker_ListMenuTemplate.maxShowed = nitems;
//     else
//         gFameChecker_ListMenuTemplate.maxShowed = 5;
//     return nitems;
// }

// static void FC_PutWindowTilemapAndCopyWindowToVramMode3_2(u8 windowId)
// {
//     PutWindowTilemap(windowId);
//     CopyWindowToVram(windowId, COPYWIN_FULL);
// }

// static void FC_CreateScrollIndicatorArrowPair(void)
// {
//     struct ScrollArrowsTemplate template = {
//           2,
//           40,
//           26,
//           3,
//           40,
//           100,
//           0,
//           0,
//           SPRITETAG_SCROLL_INDICATORS,
//           0xFFFF,
//           1,
//     };

//     if (sFameCheckerData->numUnlockedPersons > 5)
//     {
//         template.fullyUpThreshold = 0;
//         template.fullyDownThreshold = sFameCheckerData->numUnlockedPersons - 5;
//         sFameCheckerData->scrollIndicatorPairTaskId = AddScrollIndicatorArrowPair(&template, &sFameCheckerData->listMenuTopIdx);
//     }
// }

// static void FreeListMenuSelectorArrowPairResources(void)
// {
//     if (sFameCheckerData->numUnlockedPersons > 5)
//         RemoveScrollIndicatorArrowPair(sFameCheckerData->scrollIndicatorPairTaskId);
// }

// static u16 FameCheckerGetCursorY(void)
// {
//     u16 listY, cursorY;
//     ListMenuGetScrollAndRow(sFameCheckerData->listMenuTaskId, &listY, &cursorY);
//     return listY + cursorY;
// }

// static void HandleFlavorTextModeSwitch(bool8 state)
// {
//     if (sFameCheckerData->viewingFlavorText != state)
//     {
//         u8 taskId = FindTaskIdByFunc(Task_FCOpenOrCloseInfoBox);
//         if (taskId == 0xFF)
//             taskId = CreateTask(Task_FCOpenOrCloseInfoBox, 8);
//         gTasks[taskId].data[0] = 0;
//         gTasks[taskId].data[1] = 4;
//         if (state == TRUE)
//         {
//             gTasks[taskId].data[2] = 1;
//             sFameCheckerData->viewingFlavorText = TRUE;
//         }
//         else
//         {
//             gTasks[taskId].data[2] = 4;
//             sFameCheckerData->viewingFlavorText = FALSE;
//         }
//     }
// }

// static void Task_FCOpenOrCloseInfoBox(u8 taskId)
// {
//     struct Task *task = &gTasks[taskId];
//     switch (task->data[0])
//     {
//         case 0:
//             if (--task->data[1] == 0)
//             {
//                 UpdateInfoBoxTilemap(1, 0);
//                 task->data[1] = 4;
//                 task->data[0]++;
//             }
//             break;
//         case 1:
//             if (--task->data[1] == 0)
//             {
//                 UpdateInfoBoxTilemap(1, task->data[2]);
//                 DestroyTask(taskId);
//             }
//             break;
//     }
// }

// static void UpdateInfoBoxTilemap(u8 bg, s16 state)
// {
//     if (state == 0 || state == 3)
//     {
//         FillBgTilemapBufferRect(bg, 0x8C, 14, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0xA1, 15, 10, 10,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x8D, 25, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x8E, 26, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x8F, 14, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x00, 15, 11, 11,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x90, 26, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x91, 14, 12,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0xA3, 15, 12, 10,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x92, 25, 12,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x93, 26, 12,  1,  1, 1);
//     }
//     else if (state == 1)
//     {
//         FillBgTilemapBufferRect(bg, 0x9B, 14, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x9C, 15, 10, 11,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x96, 26, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x9D, 14, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x00, 15, 11, 11,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x90, 26, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x9E, 14, 12,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x9F, 15, 12, 11,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x99, 26, 12,  1,  1, 1);
//     }
//     else if (state == 2)
//     {
//         FillBgTilemapBufferRect(bg, 0x94, 14, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x95, 15, 10, 11,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x96, 26, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x8F, 14, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x9A, 15, 11, 11,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x90, 26, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x97, 14, 12,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x98, 15, 12, 11,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x99, 26, 12,  1,  1, 1);
//     }
//     else if (state == 4)
//     {
//         FillBgTilemapBufferRect(bg, 0x83, 14, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0xA0, 15, 10, 10,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x84, 25, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x85, 26, 10,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x86, 14, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0xA2, 15, 11, 10,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x87, 25, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x88, 26, 11,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x83, 14, 12,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0xA0, 15, 12, 10,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x84, 25, 12,  1,  1, 1);
//         FillBgTilemapBufferRect(bg, 0x85, 26, 12,  1,  1, 1);
//     }
//     else if (state == 5)
//     {
//         FillBgTilemapBufferRect(bg, 0x00, 14, 10, 13,  3, 1);
//     }
//     CopyBgTilemapBufferToVram(bg);
// }

// static void PlaceListMenuCursor(bool8 isActive)
// {
//     u16 cursorY = ListMenuGetYCoordForPrintingArrowCursor(sFameCheckerData->listMenuTaskId);
//     if (isActive == TRUE)
//         AddTextPrinterParameterized4(FCWINDOWID_LIST, FONT_NORMAL, 0, cursorY, 0, 0, sTextColor_DkGrey, 0, gText_SelectorArrow2);
//     else
//         AddTextPrinterParameterized4(FCWINDOWID_LIST, FONT_NORMAL, 0, cursorY, 0, 0, sTextColor_White, 0, gText_SelectorArrow2);
// }
