#ifndef GUARD_MYSTERY_GIFT_MENU_H
#define GUARD_MYSTERY_GIFT_MENU_H

extern bool8 gGiftIsFromEReader;

u16 GetMysteryGiftBaseBlock(void);
void CB2_MysteryGiftEReader(void);
void PrintMysteryGiftOrEReaderHeader(bool8 isJapanese, bool32 usePickOkCancel);
void MG_DrawCheckerboardPattern(u32 bg);
void MainCB_FreeAllBuffersAndReturnToInitTitleScreen(void);
bool32 PrintMysteryGiftMenuMessage(u8 *textState, const u8 *str);
void MG_AddMessageTextPrinter(const u8 *src);
void CB2_InitEReader(void);
void CB2_InitMysteryGift(void);
void MG_DrawTextBorder(u8 windowId);
s8 DoMysteryGiftYesNo(u8 *textState, u16 *windowId, bool8 yesNoBoxPlacement, const u8 *str);

#endif //GUARD_MYSTERY_GIFT_MENU_H
