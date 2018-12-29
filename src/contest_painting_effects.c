#include "global.h"
#include "contest_painting_effects.h"
#include "contest_painting.h"
#include "constants/rgb.h"

extern u8 gUnknown_03006164;
extern u16 (*gUnknown_03006168)[][32];
extern u8 gUnknown_0300616C;
extern u8 gUnknown_03006170;
extern u8 gUnknown_03006174;
extern u8 gUnknown_03006178;
extern u8 gUnknown_0300617C;
extern u8 gUnknown_03006180;

// this file's functions
void sub_8125230(void);
void sub_81252E8(void);
void sub_81254E0(void);
void sub_8125630(void);
void sub_8125448(void);
void sub_81257F8(void);
void sub_81258A0(void);
void sub_81256C8(void);
void sub_8125250(void);
void sub_81253A4(u8);
void sub_81250B8(u8);
void sub_8125170(u8);
void sub_8125954(u16);
u16 ConvertColorToGrayscale(u16*);
u16 sub_8125E18(u16*, u16*, u16*);
u16 ConvertCoolColor(u16*, u8);
u16 ConvertToBlackOrWhite(u16*);
u16 sub_8125C98(u16*, u16*);
u16 InvertColor(u16*);
u16 sub_8125F38(u16*, u16*, u16*);
u16 sub_8125CF4(u16*, u16*);
u16 GetCoolColorFromPersonality(u8);

void sub_8124F2C(struct Unk030061A0 *info)
{
    gUnknown_03006168 = info->var_4;
    gUnknown_0300617C = info->var_1F;
    gUnknown_03006164 = info->var_19;
    gUnknown_03006178 = info->var_1A;
    gUnknown_03006174 = info->var_1B;
    gUnknown_0300616C = info->var_1C;
    gUnknown_03006180 = info->var_1D;
    gUnknown_03006170 = info->var_1E;
    switch (info->var_0)
    {
    case 2:
        sub_8125230();
        break;
    case 8:
        sub_81252E8();
        break;
    case 9:
        sub_81254E0();
        sub_81253A4(gUnknown_0300617C);
        break;
    case 10:
        sub_81254E0();
        sub_8125630();
        sub_8125448();
    case 31:
        sub_8125630();
        break;
    case 11:
        sub_81254E0();
        sub_81257F8();
        sub_81257F8();
        sub_81258A0();
        sub_8125448();
        break;
    case 13:
        sub_81256C8();
        break;
    case 30:
        sub_81254E0();
        break;
    case 32:
        sub_81257F8();
        break;
    case 33:
        sub_81258A0();
        break;
    case 6:
        sub_8125250();
        sub_81250B8(3);
        break;
    case 36:
        sub_81254E0();
        sub_81257F8();
        sub_81258A0();
        sub_8125448();
        sub_81252E8();
        sub_81252E8();
        sub_81250B8(2);
        sub_8125170(4);
        break;
    }
}

void sub_81250B8(u8 a0) // it changes palette someway somehow... .__.
{
    u8 i, j;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16* var2 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        u16* pal = &var2[gUnknown_03006164];
        for (j = 0; j < gUnknown_03006174; j++, pal++)
        {
            if (!(0x8000 & *pal))
            {
                u8 val = (31 & *pal);
                val += a0;
                if (val > 31)
                    val = 31;

                *pal = RGB2(val, val, val);
            }
        }
    }
}

void sub_8125170(u8 a0)
{
    u8 i, j;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16* var2 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        u16* pal = &var2[gUnknown_03006164];
        for (j = 0; j < gUnknown_03006174; j++, pal++)
        {
            if (!(0x8000 & *pal))
            {
                u8 val = (31 & *pal);
                if (val > 31 - a0)
                    val = 31 - (a0 >> 1);

                *pal = RGB2(val, val, val);
            }
        }
    }
}

void sub_8125230(void)
{
    u32 i;
    for (i = 0; i < 3200; i++)
        sub_8125954(i);
}

void sub_8125250(void)
{
    u8 i, j;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16* var2 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        u16* color = &var2[gUnknown_03006164];
        for (j = 0; j < gUnknown_03006174; j++, color++)
        {
            if (!(0x8000 & *color))
            {
                *color = ConvertColorToGrayscale(color);
            }
        }
    }
}

void sub_81252E8(void)
{
    u8 i, j;

    for (i = 0; i < gUnknown_03006174; i++)
    {
        u16* var0 = &(*gUnknown_03006168)[0][gUnknown_03006178 * gUnknown_03006180];
        u16* palette = &var0[gUnknown_03006164 + i];
        u16 color = *palette;

        j = 1;
        palette += gUnknown_03006180;
        while (j < gUnknown_0300616C - 1)
        {
            if (!(0x8000 & *palette))
            {
                *palette = sub_8125E18(&color, palette, palette + gUnknown_03006180);
                color = *palette;
            }

            j++;
            palette += gUnknown_03006180;
        }
    }
}

void sub_81253A4(u8 arg0)
{
    u8 i, j;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16* var0 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        u16* color = &var0[gUnknown_03006164];
        for (j = 0; j < gUnknown_03006174; j++, color++)
        {
            if (!(0x8000 & *color))
            {
                *color = ConvertCoolColor(color, arg0);
            }
        }
    }
}

void sub_8125448(void)
{
    u8 i, j;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16* var0 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        u16* color = &var0[gUnknown_03006164];
        for (j = 0; j < gUnknown_03006174; j++, color++)
        {
            if (!(0x8000 & *color))
            {
                *color = ConvertToBlackOrWhite(color);
            }
        }
    }
}

void sub_81254E0(void)
{
    u8 i, j;
    u16 *palette;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16 *var0 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        palette = &var0[gUnknown_03006164];
        *palette = sub_8125C98(palette, palette + 1);
        for (j = 1, palette = palette + 1; j < gUnknown_03006174 - 1; j++, palette++)
        {
            *palette = sub_8125C98(palette, palette + 1);
            *palette = sub_8125C98(palette, palette - 1);
        }

        *palette = sub_8125C98(palette, palette - 1);
    }

    for (j = 0; j < gUnknown_03006174; j++)
    {
        u16 *var0 = &(*gUnknown_03006168)[0][gUnknown_03006178 * gUnknown_03006180];
        palette = &var0[gUnknown_03006164 + j];
        *palette = sub_8125C98(palette, palette + gUnknown_03006180);
        for (i = 1, palette = palette + gUnknown_03006180; i < gUnknown_0300616C - 1; i++, palette += gUnknown_03006180)
        {
            *palette = sub_8125C98(palette, palette + gUnknown_03006180);
            *palette = sub_8125C98(palette, palette - gUnknown_03006180);
        }

        *palette = sub_8125C98(palette, palette - gUnknown_03006180);
    }
}

void sub_8125630(void)
{
    u8 i, j;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16 *var0 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        u16 *color = &var0[gUnknown_03006164];
        for (j = 0; j < gUnknown_03006174; j++, color++)
        {
            if (!(0x8000 & *color))
            {
                *color = InvertColor(color);
            }
        }
    }
}

void sub_81256C8(void)
{
    u8 i, j;
    u16 *palette;
    u16 color;

    palette = (*gUnknown_03006168)[0];
    for (i = 0; i < 64; i++)
    {
        for (j = 0; j < 64; j++, palette++)
        {
            if (!(0x8000 & *palette))
            {
                *palette = InvertColor(palette);
            }
        }
    }

    for (j = 0; j < 64; j++)
    {
        palette = &(*gUnknown_03006168)[0][j];
        color = *palette;
        *palette = 0x8000;
        for (i = 1, palette += 64; i < 63; i++, palette += 64)
        {
            if (!(0x8000 & *palette))
            {
                *palette = sub_8125F38(&color, palette, palette + 64);
                color = *palette;
            }
        }

        *palette = 0x8000;
        palette = &(*gUnknown_03006168)[0][j];
        color = *palette;
        *palette = 0x8000;
        for (i = 1, palette += 64; i < 63; i++, palette += 64)
        {
            if (!(0x8000 & *palette))
            {
                *palette = sub_8125F38(&color, palette, palette + 64);
                color = *palette;
            }
        }

        *palette = 0x8000;
    }

    palette = (*gUnknown_03006168)[0];
    for (i = 0; i < 64; i++)
    {
        for (j = 0; j < 64; j++, palette++)
        {
            if (!(0x8000 & *palette))
            {
                *palette = InvertColor(palette);
            }
        }
    }
}

void sub_81257F8(void)
{
    u8 i, j;

    for (i = 0; i < gUnknown_0300616C; i++)
    {
        u16 *var0 = &(*gUnknown_03006168)[0][(gUnknown_03006178 + i) * gUnknown_03006180];
        u16 *palette = &var0[gUnknown_03006164];
        u16 color = *palette;
        for (j = 1, palette++; j < gUnknown_03006174 - 1; j++, palette++)
        {
            if (!(0x8000 & *palette))
            {
                *palette = sub_8125CF4(&color, palette);
                color = *palette;
            }
        }
    }
}

void sub_81258A0(void)
{
    u8 i, j;

    for (i = 0; i < gUnknown_03006174; i++)
    {
        u16* var0 = &(*gUnknown_03006168)[0][gUnknown_03006178 * gUnknown_03006180];
        u16* palette = &var0[gUnknown_03006164 + i];
        u16 color = *palette;
        for (j = 1, palette += gUnknown_03006180; j < gUnknown_0300616C - 1; j++, palette += gUnknown_03006180)
        {
            if (!(0x8000 & *palette))
            {
                *palette = sub_8125CF4(&color, palette);
                color = *palette;
            }
        }
    }
}

struct Unk8125954
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
};

extern const u8 gUnknown_085A1F94[][3];

void sub_8125954(u16 arg0)
{
    u8 i;
    u8 r5, r9;
    struct Unk8125954 unkStruct[6];

    unkStruct[0].unk0 = gUnknown_085A1F94[arg0][0];
    unkStruct[0].unk1 = gUnknown_085A1F94[arg0][1];
    unkStruct[0].unk2 = (gUnknown_085A1F94[arg0][2] >> 3) & 7;

    r9 = (gUnknown_085A1F94[arg0][2] >> 1) & 3;
    r5 = gUnknown_085A1F94[arg0][2] & 1;
    for (i = 1; i < unkStruct[0].unk2; i++)
    {
        if (!r5)
        {
            unkStruct[i].unk0 = unkStruct[0].unk0 - i;
            unkStruct[i].unk1 = unkStruct[0].unk1 + i;
        }
        else
        {
            unkStruct[i].unk0 = unkStruct[0].unk0 + 1;
            unkStruct[i].unk1 = unkStruct[0].unk1 - 1;
        }

        if (unkStruct[i].unk0 > 63 || unkStruct[i].unk1 > 63)
        {
            unkStruct[0].unk2 = i - 1;
            break;
        }

        unkStruct[i].unk2 = unkStruct[0].unk2 - i;
    }

    for (i = 0; i < unkStruct[0].unk2; i++)
    {
        u16 *pal = &(*gUnknown_03006168)[unkStruct[i].unk1 * 2][unkStruct[i].unk0];

        if (!(0x8000 & *pal))
        {
            u16 r = (*pal) & 0x1F;
            u16 g = (*pal >> 5) & 0x1F;
            u16 b = (*pal >> 10) & 0x1F;

            switch (r9)
            {
            case 0:
            case 1:
                switch (((gUnknown_085A1F94[arg0][2] >> 3) & 7) % 3)
                {
                case 0:
                    if (r >= unkStruct[i].unk2)
                        r -= unkStruct[i].unk2;
                    else
                        r = 0;
                    break;
                case 1:
                    if (g >= unkStruct[i].unk2)
                        g -= unkStruct[i].unk2;
                    else
                        g = 0;
                    break;
                case 2:
                    if (b >= unkStruct[i].unk2)
                        b -= unkStruct[i].unk2;
                    else
                        b = 0;
                    break;
                }
                break;
            case 2:
            case 3:
                r += unkStruct[i].unk2;
                g += unkStruct[i].unk2;
                b += unkStruct[i].unk2;
                if (r > 31)
                    r = 31;
                if (g > 31)
                    g = 31;
                if (b > 31)
                    b = 31;
                break;
            }

            *pal = RGB2(r, g, b);
        }
    }
}

u16 ConvertColorToGrayscale(u16 *color)
{
    s32 clr = *color;
    s32 r = clr & 0x1F;
    s32 g = (clr >> 5) & 0x1F;
    s32 b = (clr >> 10) & 0x1F;
    s32 gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;
    return RGB2(gray, gray, gray);
}

// The dark colors are the colored edges of the Cool painting effect.
// Everything else is white.
u16 ConvertCoolColor(u16 *color, u8 personality)
{
    u16 red = *color & 0x1F;
    u16 green = (*color >> 5) & 0x1F;
    u16 blue = (*color >> 10) & 0x1F;

    if (red < 17 && green < 17 && blue < 17)
        return GetCoolColorFromPersonality(personality);
    else
        return RGB_WHITE;
}

// Based on the given value, which comes from the first 8 bits of
// the mon's personality value, return a color.
u16 GetCoolColorFromPersonality(u8 personality)
{
    u16 red = 0;
    u16 green = 0;
    u16 blue = 0;
    u8 strength = (personality / 6) % 3;
    u8 colorType = personality % 6;

    switch (colorType)
    {
    case 0:
        // Teal color
        green = 21 - strength;
        blue = green;
        red = 0;
        break;
    case 1:
        // Yellow color
        blue = 0;
        red = 21 - strength;
        green = red;
        break;
    case 2:
        // Purple color
        blue = 21 - strength;
        green = 0;
        red = blue;
        break;
    case 3:
        // Red color
        blue = 0;
        green = 0;
        red = 23 - strength;
        break;
    case 4:
        // Blue color
        blue = 23 - strength;
        green = 0;
        red = 0;
        break;
    case 5:
        // Green color
        blue = 0;
        green = 23 - strength;
        red = 0;
        break;
    }

    return RGB2(red, green, blue);
}

u16 ConvertToBlackOrWhite(u16 *color)
{
    u16 red = *color & 0x1F;
    u16 green = (*color >> 5) & 0x1F;
    u16 blue = (*color >> 10) & 0x1F;

    if (red < 17 && green < 17 && blue < 17)
        return RGB_BLACK;
    else
        return RGB_WHITE;
}

u16 sub_8125C98(u16 *colorA, u16 *colorB)
{
    if (*colorA)
    {
        if (*colorA & 0x8000)
            return 0x8000;
        if (*colorB & 0x8000)
            return RGB_BLACK;

        return *colorA;
    }

    return RGB_BLACK;
}

u16 InvertColor(u16 *color)
{
    u16 red = *color & 0x1F;
    u16 green = (*color >> 5) & 0x1F;
    u16 blue = (*color >> 10) & 0x1F;

    red = 31 - red;
    green = 31 - green;
    blue = 31 - blue;

    return RGB2(red, green, blue);
}

u16 sub_8125CF4(u16 *a0, u16 *a1)
{
    u16 sp0[2][3];
    u16 spC[3];
    u8 r4;
    u16 r2;
    u16 r, g, b;

    if (*a0 == *a1)
        return *a1;

    sp0[0][0] = (*a0 >> 0) & 0x1F;
    sp0[0][1] = (*a0 >> 5) & 0x1F;
    sp0[0][2] = (*a0 >> 10) & 0x1F;
    sp0[1][0] = (*a1 >> 0) & 0x1F;
    sp0[1][1] = (*a1 >> 5) & 0x1F;
    sp0[1][2] = (*a1 >> 10) & 0x1F;

    if (sp0[0][0] > 25 && sp0[0][1] > 25 && sp0[0][2] > 25)
        return *a1;
    if (sp0[1][0] > 25 && sp0[1][1] > 25 && sp0[1][2] > 25)
        return *a1;

    for (r4 = 0; r4 < 3; r4++)
    {
        if (sp0[0][r4] > sp0[1][r4])
            spC[r4] = sp0[0][r4] - sp0[1][r4];
        else
            spC[r4] = sp0[1][r4] - sp0[0][r4];
    }

    if (spC[0] >= spC[1])
    {
        if (spC[0] >= spC[2])
            r2 = spC[0];
        else if (spC[1] >= spC[2])
            r2 = spC[1];
        else
            r2 = spC[2];
    }
    else
    {
        if (spC[1] >= spC[2])
            r2 = spC[1];
        else if (spC[2] >= spC[0])
            r2 = spC[2];
        else
            r2 = spC[0];
    }

    r = (sp0[1][0] * (31 - r2 / 2)) / 31;
    g = (sp0[1][1] * (31 - r2 / 2)) / 31;
    b = (sp0[1][2] * (31 - r2 / 2)) / 31;
    return RGB2(r, g, b);
}

u16 sub_8125E18(u16 * a0, u16 * a1, u16 * a2)
{
    u16 red, green, blue;
    u16 avg0, avg1, avg2;
    u16 diff1, diff2;
    u32 minimum;
    u16 factor;

    if (*a0 == *a1 && *a2 == *a1)
        return *a1;

    red = (*a1 >> 0) & 0x1F;
    green = (*a1 >> 5) & 0x1F;
    blue = (*a1 >> 10) & 0x1F;

    avg0 = (((*a0 >> 0) & 0x1F) + ((*a0 >> 5) & 0x1F) + ((*a0 >> 10) & 0x1F)) / 3;
    avg1 = (((*a1 >> 0) & 0x1F) + ((*a1 >> 5) & 0x1F) + ((*a1 >> 10) & 0x1F)) / 3;
    avg2 = (((*a2 >> 0) & 0x1F) + ((*a2 >> 5) & 0x1F) + ((*a2 >> 10) & 0x1F)) / 3;

    if (avg0 == avg1 && avg2 == avg1)
        return *a1;

    if (avg0 > avg1)
        diff1 = avg0 - avg1;
    else
        diff1 = avg1 - avg0;

    if (avg2 > avg1)
        diff2 = avg2 - avg1;
    else
        diff2 = avg1 - avg2;

    if (diff1 >= diff2)
        minimum = diff1;
    else
        minimum = diff2;

    factor = 31 - minimum / 2;
    red = red * factor / 31;
    green = green * factor / 31;
    blue = blue * factor / 31;
    return RGB2(red, green, blue);
}

u16 sub_8125F38(u16 *a0, u16 *a1, u16 *a2)
{
    u16 red, green, blue;
    u16 avg0, avg1, avg2;
    u16 diff1, diff2;
    u32 minimum;
    u16 factor;

    if (*a0 == *a1 && *a2 == *a1)
        return *a1;

    red = (*a1 >> 0) & 0x1F;
    green = (*a1 >> 5) & 0x1F;
    blue = (*a1 >> 10) & 0x1F;

    avg0 = (((*a0 >> 0) & 0x1F) + ((*a0 >> 5) & 0x1F) + ((*a0 >> 10) & 0x1F)) / 3;
    avg1 = (((*a1 >> 0) & 0x1F) + ((*a1 >> 5) & 0x1F) + ((*a1 >> 10) & 0x1F)) / 3;
    avg2 = (((*a2 >> 0) & 0x1F) + ((*a2 >> 5) & 0x1F) + ((*a2 >> 10) & 0x1F)) / 3;

    if (avg0 == avg1 && avg2 == avg1)
        return *a1;

    if (avg0 > avg1)
        diff1 = avg0 - avg1;
    else
        diff1 = avg1 - avg0;

    if (avg2 > avg1)
        diff2 = avg2 - avg1;
    else
        diff2 = avg1 - avg2;

    if (diff1 >= diff2)
        minimum = diff1;
    else
        minimum = diff2;

    factor = 31 - minimum;
    red = red * factor / 31;
    green = green * factor / 31;
    blue = blue * factor / 31;
    return RGB2(red, green, blue);
}

/*
void sub_8126058(struct Unk030061A0 *arg0)
{
    u16 i, j, k;
    u8 r5 = arg0->var_1D >> 3;
    u8 var_24 = arg0->var_1E >> 3;
    u16 (*var_2C)[][32] = arg0->var_4;
    u32 var_28 = arg0->var_10;

    if (arg0->var_16 == 2)
    {
        for (i = 0; i < var_24; i++)
        {
            for (j = 0; j < r5; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    (*var_2C)[][];
                }
            }
        }
    }
}
*/
