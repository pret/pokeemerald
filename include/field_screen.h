#ifndef GUARD_FIELD_SCREEN_H
#define GUARD_FIELD_SCREEN_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void pal_fill_black(void);
bool8 IsWeatherNotFadingIn(void);
void sub_80AF168(void);
void sub_80AF2B4(u8 taskId);
void UpdateWeatherPerDay(u16 days);
void sub_80AC3D0(void);
void sub_80AC3E4(void);
void PreservePaletteInWeather(u8);
void sub_80AF128(void);

#endif //GUARD_FIELD_SCREEN_H
