#ifndef GUARD_MYSTERY_GIFT_H
#define GUARD_MYSTERY_GIFT_H

extern bool8 gGiftIsFromEReader;

u16 GetMysteryGiftBaseBlock(void);
void c2_mystery_gift_e_reader_run(void);
void PrintMysteryGiftOrEReaderTopMenu(bool8 isJapanese, bool32 usePickOkCancel);
void MG_DrawCheckerboardPattern(u32 bg);
void MainCB_FreeAllBuffersAndReturnToInitTitleScreen(void);
bool32 MG_PrintTextOnWindow1AndWaitButton(u8 *textState, const u8 *str);
void AddTextPrinterToWindow1(const u8 *src);
void c2_ereader(void);
void c2_mystery_gift(void);
void MG_DrawTextBorder(u8 windowId);
s8 mevent_message_print_and_prompt_yes_no(u8 *textState, u16 *windowId, bool8 yesNoBoxPlacement, const u8 *str);

#endif //GUARD_MYSTERY_GIFT_H
