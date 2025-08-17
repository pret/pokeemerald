#include "gba/gba.h"
#include "spylog.h"
#include <stdarg.h>

/* mGBA debug regs */
#define REG_DEBUG_ENABLE  (*(vu16 *)0x4FFF780)
#define REG_DEBUG_FLAGS   (*(vu16 *)0x4FFF700)
#define REG_DEBUG_STRING  ((char *)0x4FFF600)

/* integer -> string */
static void SpyPrintInt(char *buf, int value) {
    char tmp[12];
    int i = 0, j, neg = 0;

    if (value < 0) { neg = 1; value = -value; }
    do {
        tmp[i++] = '0' + (value % 10);
        value /= 10;
    } while (value);
    if (neg) tmp[i++] = '-';

    for (j = 0; j < i; j++)
        buf[j] = tmp[i - j - 1];
    buf[i] = '\0';
}

void SpyMgbaOpen(void) {
    REG_DEBUG_ENABLE = 0xC0DE;
}

int SpyMgbaPrintf(int level, const char *fmt, ...) {
    char buf[256];   /* output buffer */
    char *out;       /* write cursor */
    va_list args;
    int written = 0;

    out = buf;
    va_start(args, fmt);

    while (*fmt) {
        if (*fmt == '%' && *(fmt+1)) {
            fmt++;
            if (*fmt == 's') {
                const char *s = va_arg(args, const char *);
                while (*s && out < buf + sizeof(buf) - 1) {
                    *out++ = *s++;
                }
            } else if (*fmt == 'd') {
                int val = va_arg(args, int);
                char numbuf[12];
                char *p;
                SpyPrintInt(numbuf, val);
                p = numbuf;
                while (*p && out < buf + sizeof(buf) - 1) {
                    *out++ = *p++;
                }
            } else if (*fmt == 'c') {
                *out++ = (char)va_arg(args, int);
            } else {
                *out++ = '%';
                *out++ = *fmt;
            }
        } else {
            *out++ = *fmt;
        }
        if (out >= buf + sizeof(buf) - 1)
            break;
        fmt++;
    }

    *out = '\0';
    va_end(args);

    /* write to mGBA */
    {
        char *dst = REG_DEBUG_STRING;
        char *src = buf;
        while (*src) {
            *dst++ = *src++;
        }
        *dst = '\0';
    }

    written = out - buf;
    REG_DEBUG_FLAGS = (1 << level);
    return written;
}
