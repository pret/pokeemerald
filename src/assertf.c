#include <alloca.h>
#include <stdarg.h>
#include "global.h"
#include "bg.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "constants/characters.h"
#include "constants/rgb.h"

enum Mode { MODE_ASSERTF, MODE_FATALF };
#define MODE_COUNT 2

struct BitUnPackArgs
{
    u16 compressedSize;
    u8 compressedBits;
    u8 decompressedBits;
    u32 dataOffset:31;
    u32 offsetZeros:1;
};

extern void BitUnPack(const void *src, void *dest, const struct BitUnPackArgs *);

static const u16 sPltts[MODE_COUNT][2] =
{
    INCGFX_U16("graphics/crash_screen/assertf.pal", ".gbapal"),
    INCGFX_U16("graphics/crash_screen/fatalf.pal", ".gbapal"),
};

static const u32 sGlyphs1BPP[] = INCGFX_U32("graphics/crash_screen/font.png", ".1bpp");

enum
{
    GLYPH_SPACE,
    GLYPH_UNDERSCORE,
    GLYPH_PERIOD,
    GLYPH_COLON,
    GLYPH_SLASH,
    GLYPH_A,
    GLYPH_0 = GLYPH_A + 26,
};

static const struct BitUnPackArgs sBitUnPack1BPP =
{
    .compressedSize = sizeof(sGlyphs1BPP),
    .compressedBits = 1,
    .decompressedBits = 4,
    .dataOffset = 0,
    .offsetZeros = FALSE,
};

#define TILE0_OFFSET ((32 * 20 * sizeof(u16)) / TILE_SIZE_4BPP)

static bool32 Putc(u32 *x, u32 *y, char c)
{
    if (c == '\n')
        goto newline;

    u32 glyph;
    if ('a' <= c && c <= 'z')
        glyph = GLYPH_A + c - 'a';
    else if ('A' <= c && c <= 'Z')
        glyph = GLYPH_A + c - 'A';
    else if ('0' <= c && c <= '9')
        glyph = GLYPH_0 + c - '0';
    else if (c == ' ')
        glyph = GLYPH_SPACE;
    else if (c == '.')
        glyph = GLYPH_PERIOD;
    else if (c == ':')
        glyph = GLYPH_COLON;
    else if (c == '/')
        glyph = GLYPH_SLASH;
    else
        glyph = GLYPH_UNDERSCORE;
    ((vu16 *)VRAM)[*x + *y * 32] = TILE0_OFFSET + glyph;

    *x += 1;
    if (*x == 30)
    {
newline:
        *x = 0;
        *y += 1;
    }

    return *y < 18;
}

static bool32 Puti(u32 *x, u32 *y, s32 i)
{
    if (i < 0)
    {
        if (!Putc(x, y, '-'))
            return FALSE;
        return Puti(x, y, -i);
    }
    else if (i == 0)
    {
        return Putc(x, y, '0');
    }

    u8 digits[9]; // floor(log10(INT_MAX))

    u32 n = 0;
    while (i)
    {
        digits[n++] = i % 10;
        i /= 10;
    }

    while (n > 0)
    {
        n--;
        if (!Putc(x, y, '0' + digits[n]))
            return FALSE;
    }

    return TRUE;
}

static bool32 Putp(u32 *x, u32 *y, const void *p)
{
    uintptr_t address = (uintptr_t)p;
    u8 digits[8];

    for (u32 n = 0; n < 8; n++)
    {
        digits[n] = address % 16;
        address /= 16;
    }

    for (u32 n = 0; n < 8; n++)
    {
        u32 d = digits[7 - n];

        // Most addresses are 7-digit, so elide the 8th if it's zero.
        if (n == 0 && d == 0)
            continue;

        if (0 <= d && d <= 9)
        {
            if (!Putc(x, y, '0' + d))
                return FALSE;
        }
        else
        {
            if (!Putc(x, y, 'A' + d - 10))
                return FALSE;
        }
    }

    return TRUE;
}

static bool32 Puts(u32 *x, u32 *y, s32 n, const char *s)
{
    while (n-- > 0 && *s != '\0')
    {
        if (!Putc(x, y, *s++))
            return FALSE;
    }
    return TRUE;
}

static bool32 PutS(u32 *x, u32 *y, s32 n, const u8 *s)
{
    while (n-- > 0 && *s != EOS)
    {
        char c;
        if (CHAR_a <= *s && *s <= CHAR_z)
            c = 'A' + *s - CHAR_a;
        else if (CHAR_A <= *s && *s <= CHAR_Z)
            c = 'A' + *s - CHAR_A;
        else if (CHAR_0 <= *s && *s <= CHAR_9)
            c = '0' + *s - CHAR_0;
        else if (*s == ' ')
            c = ' ';
        else if (*s == '.')
            c = '.';
        else if (*s == ':')
            c = ':';
        else
            c = '_';

        s++;
        if (!Putc(x, y, c))
            return FALSE;
    }
    return TRUE;
}

static bool32 Putx(u32 *x, u32 *y, unsigned u)
{
    u8 digits[8];

    u32 n = 0;
    while (u)
    {
        digits[n++] = u % 16;
        u /= 16;
    }

    while (n > 0)
    {
        n--;
        if (0 <= digits[n] && digits[n] <= 9)
        {
            if (!Putc(x, y, '0' + digits[n]))
                return FALSE;
        }
        else
        {
            if (!Putc(x, y, 'A' + digits[n] - 10))
                return FALSE;
        }
    }

    return TRUE;
}

// This printf renders directly into VRAM rather than into a buffer.
static void Vprintf(enum Mode mode, const void *return1, const void *return0, const char *fmt, va_list va)
{
    u32 x, y;
    s32 n;

    if (mode == MODE_ASSERTF)
    {
        x = 3;
        y = 19;
        static const char footer[] = "Press START to continue.";
        for (u32 i = 0; i < sizeof(footer) - 1; i++)
            Putc(&x, &y, footer[i]);
    }

    x = 0;
    y = 0;
    while (TRUE)
    {
        if (fmt[0] == '.' && fmt[1] == '*')
        {
            fmt += 2;
            n = va_arg(va, int);
        }
        else
        {
            n = INT_MAX;
        }

        char c = *fmt++;
        if (c == '\0')
        {
            break;
        }
        else if (c == '%')
        {
            char f = *fmt++;
            switch (f)
            {
            case '%':
                if (!Putc(&x, &y, '%'))
                    return;
                break;
            case 'c':
                if (!Putc(&x, &y, va_arg(va, int)))
                    return;
                break;
            case 'C':
                if (!PutS(&x, &y, 1, &(u8) { va_arg(va, unsigned) }))
                    return;
                break;
            case 'd':
                if (!Puti(&x, &y, va_arg(va, int)))
                    return;
                break;
            case 'p':
                if (!Putp(&x, &y, va_arg(va, const void *)))
                    return;
                break;
            case 's':
                if (!Puts(&x, &y, n, va_arg(va, const char *)))
                    return;
                break;
            case 'S':
                if (!PutS(&x, &y, n, va_arg(va, const u8 *)))
                    return;
                break;
            case 'x':
                if (!Putx(&x, &y, va_arg(va, unsigned)))
                    return;
                break;
            }
        }
        else
        {
            if (!Putc(&x, &y, c))
                return;
        }
    }

    if (!Puts(&x, &y, INT_MAX, "\n  in: "))
        return;
    if (!Putp(&x, &y, return1))
        return;
    if (!Puts(&x, &y, INT_MAX, "\n  in: "))
        return;
    if (!Putp(&x, &y, return0))
        return;
}

static void BusyWaitForVBlank(void)
{
    // Interrupts are disabled so we have to busy loop to wait for
    // v-blanks.
    while (REG_VCOUNT < 160)
        ;
}

struct Backup
{
    bool8 onHeap;
    u8 ime;
    u16 soundcnt_l;
    u16 soundcnt_h;
    u16 dispcnt;
    u16 bg0cnt;
    u16 bgPltt[2];
    u8 vram[32 * 20 * sizeof(u16) + TILE_SIZE_4BPP + 4 * sizeof(sGlyphs1BPP)];
};

/* Blue Screen of Death style screen that displays the error message and
 * hijacks the main loop until the start button is pressed. */
static void CrashScreen(enum Mode mode, const void *return1, const void *return0, const char *fmt, va_list va)
{
    // Backup and override hardware state.
    struct Backup *backup = NULL;

    // Allocate on heap if possible.
    if (!backup)
    {
        backup = AllocUnchecked(sizeof(*backup));
        if (backup)
            backup->onHeap = TRUE;
    }

    // Allocate on stack if possible.
    if (!backup)
    {
        extern char __iwram_end[];
        size_t stack_free = (char *)__builtin_frame_address(0) - __iwram_end;
        if (stack_free > sizeof(*backup) + 128)
        {
            backup = alloca(sizeof(*backup));
            backup->onHeap = FALSE;
        }
    }

    if (!backup)
    {
        // TODO: What to do?
        return;
    }

    backup->ime = REG_IME;
    REG_IME = 0;
    m4aMPlayStop(&gMPlayInfo_BGM);
    m4aMPlayStop(&gMPlayInfo_SE1);
    m4aMPlayStop(&gMPlayInfo_SE2);
    m4aMPlayStop(&gMPlayInfo_SE3);
    backup->soundcnt_l = REG_SOUNDCNT_L;
    REG_SOUNDCNT_L = 0;
    backup->soundcnt_h = REG_SOUNDCNT_H;
    REG_SOUNDCNT_H = REG_SOUNDCNT_H & ~(SOUND_A_RIGHT_OUTPUT | SOUND_A_LEFT_OUTPUT | SOUND_B_RIGHT_OUTPUT | SOUND_B_LEFT_OUTPUT);
    backup->dispcnt = REG_DISPCNT;
    REG_DISPCNT = 0;
    backup->bg0cnt = REG_BG0CNT;
    REG_BG0CNT = BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(0) | BGCNT_TXT256x256;
    REG_BG0HOFS = 0; // NOTE: REG_BG0HOFS is write-only.
    REG_BG0VOFS = 0; // NOTE: REG_BG0VOFS is write-only.
    memcpy(backup->bgPltt, (void *)BG_PLTT, sizeof(backup->bgPltt));
    memcpy((void *)BG_PLTT, sPltts[mode], sizeof(backup->bgPltt));
    CpuFastCopy((void *)VRAM, &backup->vram, sizeof(backup->vram));
    for (u32 i = 0; i < 32 * 20; i++)
        ((vu16 *)VRAM)[i] = TILE0_OFFSET;
    BitUnPack(sGlyphs1BPP, (void *)(VRAM + TILE_OFFSET_4BPP(TILE0_OFFSET)), &sBitUnPack1BPP);

    Vprintf(mode, return1, return0, fmt, va);

    BusyWaitForVBlank();
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_BG0_ON;

    if (mode == MODE_FATALF)
    {
        while (TRUE)
        {
            gMain.intrCheck &= ~INTR_FLAG_VBLANK;
            VBlankIntrWait();
        }
    }

    u16 prevKeyinput = ~REG_KEYINPUT;
    enum { WAIT_FOR_PRESS, WAIT_FOR_RELEASE } state = WAIT_FOR_PRESS;
    while (TRUE)
    {
        BusyWaitForVBlank();

        // Exit when start is pressed.
        u16 keyinput = ~REG_KEYINPUT;
        if (state == WAIT_FOR_PRESS)
        {
            if (!(prevKeyinput & START_BUTTON) && (keyinput & START_BUTTON))
                state = WAIT_FOR_RELEASE;
        }
        else if (state == WAIT_FOR_RELEASE)
        {
            if ((prevKeyinput & START_BUTTON) && !(keyinput & START_BUTTON))
                break;
        }
        prevKeyinput = keyinput;
    }

    // Restore backup.
    REG_DISPCNT = 0;
    CpuFastCopy(&backup->vram, (void *)VRAM, sizeof(backup->vram));
    memcpy((void *)BG_PLTT, backup->bgPltt, sizeof(backup->bgPltt));
    // Best-effort, restore BG0HOFS/BG0VOFS from one of GF's caches.
    REG_BG0VOFS = GetBgY(0);
    REG_BG0HOFS = GetBgX(0);
    REG_BG0CNT = backup->bg0cnt;
    REG_DISPCNT = backup->dispcnt;
    REG_SOUNDCNT_H = backup->soundcnt_h;
    REG_SOUNDCNT_L = backup->soundcnt_l;
    m4aMPlayContinue(&gMPlayInfo_SE3);
    m4aMPlayContinue(&gMPlayInfo_SE2);
    m4aMPlayContinue(&gMPlayInfo_SE1);
    m4aMPlayContinue(&gMPlayInfo_BGM);
    REG_IME = backup->ime;

    if (backup->onHeap)
        Free(backup);
}

void AssertfCrashScreen(const void *return1, const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    CrashScreen(MODE_ASSERTF, return1, __builtin_return_address(0), fmt, va);
    va_end(va);
}

_Noreturn void FatalfCrashScreen(const void *return1, const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    CrashScreen(MODE_FATALF, return1, __builtin_return_address(0), fmt, va);
    va_end(va);

    while (TRUE); // Unreachable: infinite loop in 'CrashScreen'.
}
