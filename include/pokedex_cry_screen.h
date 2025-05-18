#ifndef GUARD_POKEDEX_CRY_SCREEN_H
#define GUARD_POKEDEX_CRY_SCREEN_H

struct CryScreenWindow
{
    u16 unk0; // Assigned to val that's never read
    u8 unk2;  // Never read
    u8 paletteNo;
    u8 xPos;
    u8 yPos;
};

extern u8 gDexCryScreenState;

bool8 LoadCryWaveformWindow(struct CryScreenWindow *window, u8 windowId);
void UpdateCryWaveformWindow(u8 windowId);
void CryScreenPlayButton(u16 species);
bool8 LoadCryMeter(struct CryScreenWindow *window, u8 windowId);
void FreeCryScreen(void);

#endif
