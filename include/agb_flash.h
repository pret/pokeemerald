#ifndef GUARD_AGB_FLASH_H
#define GUARD_AGB_FLASH_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

u16 SetFlashTimerIntr(u8 timerNum, void (**intrFunc)(void));
u16 IdentifyFlash(void);
u32 ProgramFlashSectorAndVerify(u16 sectorNum, u8 *src);

#endif //GUARD_AGB_FLASH_H
