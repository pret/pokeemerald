#ifndef GUARD_WEATHER_H
#define GUARD_WEATHER_H

void fade_screen(u8, s8);

void SetSav1Weather(u32);
u8 GetSav1Weather(void);
void sub_80AEDBC(void);

void DoCurrentWeather(void);

#endif // GUARD_WEATHER_H
