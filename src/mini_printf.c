/*
 * The Minimal snprintf() implementation
 *
 * Copyright (c) 2013,2014 Michal Ludvig <michal@logix.cz>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the auhor nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * mini-printf courtesy of https://github.com/mludvig/mini-printf
 * stripped to reduce file size for agb needs
 */

#include "mini_printf.h"
#include "gba/types.h"
#include "gba/defines.h"
#include "config/general.h"
#include "constants/characters.h"
#include "string_util.h"

#ifndef NDEBUG

struct mini_buff
{
    char *buffer, *pbuffer;
    u32 buffer_len;
};

static inline char mini_pchar_decode(char encoded)
{
    char ret = '?';
    if (encoded >= CHAR_a && encoded <= CHAR_z)
        ret = encoded-(CHAR_a-'a'); // lower-case characters
    else if (encoded >= CHAR_A && encoded <= CHAR_Z)
        ret = encoded-(CHAR_A-'A'); // upper-case characters
    else if (encoded >= CHAR_0 && encoded <= CHAR_9)
        ret = encoded-(CHAR_0-'0'); // numbers
    else if (encoded == CHAR_SPACE)
        ret = ' '; // space
    else if (encoded == CHAR_EXCL_MARK)
        ret = '!'; // exclamation point
    else if (encoded == CHAR_QUESTION_MARK)
        ret = '?'; // question mark
    else if (encoded == CHAR_PERIOD)
        ret = '.'; // period
    else if (encoded == CHAR_DBL_QUOTE_LEFT || encoded == CHAR_DBL_QUOTE_RIGHT)
        ret = '"'; // double quote
    else if (encoded == CHAR_SGL_QUOTE_LEFT || encoded == CHAR_SGL_QUOTE_RIGHT)
        ret = '\''; // single quote
    else if (encoded == CHAR_CURRENCY)
        ret = '$'; // currency mark (pokemonies in game, dollar sign in logs)
    else if (encoded == CHAR_COMMA)
        ret = ','; // comma
    else if (encoded == CHAR_MULT_SIGN)
        ret = '#'; // pound, hashtag, octothorpe, whatever
    else if (encoded == CHAR_SLASH)
        ret = '/'; // slash
    else if (encoded == CHAR_LESS_THAN)
        ret = '<'; // less than sign
    else if (encoded == CHAR_GREATER_THAN)
        ret = '>'; // greater than sign
    else if (encoded == CHAR_PERCENT)
        ret = '%'; // percentage
    else if (encoded == CHAR_LEFT_PAREN)
        ret = '('; // opening parentheses
    else if (encoded == CHAR_RIGHT_PAREN)
        ret = ')'; // closing parentheses
    return ret;
}

static s32 _putsAscii(char *s, s32 len, void *buf)
{
    char *p0;
    s32 i;
    struct mini_buff *b;

    if (!buf)
        return len;

    b = buf;
    p0 = b->buffer;

    /* Copy to buffer */
    for (i = 0; i < len; i++)
    {
        if(b->pbuffer == b->buffer + b->buffer_len - 1)
        {
            break;
        }
        *(b->pbuffer ++) = s[i];
    }
    *(b->pbuffer) = 0;
    return b->pbuffer - p0;
}

static s32 _putsEncoded(char *s, s32 len, void *buf)
{
    char *p0;
    s32 i;
    struct mini_buff *b;

    if (!buf)
        return len;

    b = buf;
    p0 = b->buffer;

    /* Copy to buffer */
    for (i = 0; i < len; i++)
    {
        if(b->pbuffer == b->buffer + b->buffer_len - 1)
        {
            break;
        }
        *(b->pbuffer ++) = mini_pchar_decode(s[i]);
    }
    *(b->pbuffer) = 0;
    return b->pbuffer - p0;
}

static s32 mini_strlen(const char *s)
{
    s32 len = 0;
    while (s[len] != '\0') len++;
    return len;
}

static s32 mini_itoa(s32 value, u32 radix, s32 uppercase, bool32 unsig, char *buffer)
{
    char *pbuffer = buffer;
    s32 negative = 0;
    s32 i, len;

    /* No support for unusual radixes. */
    if (radix > 16)
        return 0;

    if (value < 0 && !unsig)
    {
        negative = 1;
        value = -value;
    }

    /* This builds the string back to front ... */
    do
    {
        s32 digit = value % radix;
        *(pbuffer++) = (digit < 10 ? '0' + digit : (uppercase ? 'A' : 'a') + digit - 10);
        value /= radix;
    } while (value > 0);

    if (negative)
        *(pbuffer++) = '-';

    *(pbuffer) = '\0';

    /* ... now we reverse it (could do it recursively but will
     * conserve the stack space) */
    len = (pbuffer - buffer);
    for (i = 0; i < len / 2; i++)
    {
        char j = buffer[i];
        buffer[i] = buffer[len-i-1];
        buffer[len-i-1] = j;
    }

    return len;
}

static s32 mini_pad(char* ptr, s32 len, char pad_char, s32 pad_to, char *buffer)
{
    s32 i;
    bool32 overflow = FALSE;
    char * pbuffer = buffer;
    if(pad_to == 0)
        pad_to = len;
    if (len > pad_to)
    {
        len = pad_to;
        overflow = TRUE;
    }
    for(i = pad_to - len; i > 0; i --)
    {
        *(pbuffer++) = pad_char;
    }
    for(i = len; i > 0; i --)
    {
        *(pbuffer++) = *(ptr++);
    }
    len = pbuffer - buffer;
    if(overflow)
    {
        for (i = 0; i < 3 && pbuffer > buffer; i ++)
        {
            *(pbuffer-- - 1) = '*';
        }
    }
    return len;
}

s32 mini_vsnprintf(char *buffer, u32 buffer_len, const char *fmt, va_list va)
{
    struct mini_buff b;
    s32 n;
    b.buffer = buffer;
    b.pbuffer = buffer;
    b.buffer_len = buffer_len;
    if (buffer_len == 0)
        buffer = NULL;
    n = mini_vpprintf((buffer != NULL) ? &b : NULL, fmt, va);
    if (buffer == NULL)
        return n;
    return b.pbuffer - b.buffer;
}

s32 mini_vpprintf(void* buf, const char *fmt, va_list va)
{
    char bf[24];
    char bf2[24];
    char ch;
    s32 n;
    n = 0;
    while ((ch=*(fmt++)))
    {
        s32 len;
        if (ch != '%')
        {
            len = 1;
            len = _putsAscii(&ch, len, buf);
        } else
        {
            char pad_char = ' ';
            s32 pad_to = 0;
            char l = 0;
            char *ptr;

            ch=*(fmt++);

            /* Zero padding requested */
            if (ch == '0')
                pad_char = '0';
            while (ch >= '0' && ch <= '9')
            {
                pad_to = pad_to * 10 + (ch - '0');
                ch= *(fmt++);
            }
            if(pad_to > (s32) sizeof(bf))
            {
                pad_to = sizeof(bf);
            }
            if (ch == 'l')
            {
                l = 1;
                ch=*(fmt++);
            }

            switch (ch)
            {
                case 0:
                    goto end;
                case 'u':
                case 'd':
                    if(l)
                    {
                        len = mini_itoa(va_arg(va, u32), 10, 0, (ch=='u'), bf2);
                    } else
                    {
                        if(ch == 'u')
                        {
                            len = mini_itoa((u32) va_arg(va, u32), 10, 0, 1, bf2);
                        }
                        else
                        {
                            len = mini_itoa((s32) va_arg(va, s32), 10, 0, 0, bf2);
                        }
                    }
                    len = mini_pad(bf2, len, pad_char, pad_to, bf);
                    len = _putsAscii(bf, len, buf);
                    break;

                case 'x':
                case 'X':
                    if(l)
                    {
                        len = mini_itoa(va_arg(va, u32), 16, (ch=='X'), 1, bf2);
                    }
                    else
                    {
                        len = mini_itoa((u32) va_arg(va, u32), 16, (ch=='X'), 1, bf2);
                    }
                    len = mini_pad(bf2, len, pad_char, pad_to, bf);
                    len = _putsAscii(bf, len, buf);
                    break;

                case 'c' :
                    ch = (char)(va_arg(va, s32));
                    len = mini_pad(&ch, 1, pad_char, pad_to, bf);
                    len = _putsAscii(bf, len, buf);
                    break;

                case 's' :
                    ptr = va_arg(va, char*);
                    len = mini_strlen(ptr);
                    if (pad_to > 0)
                    {
                        len = mini_pad(ptr, len, pad_char, pad_to, bf);
                        len = _putsAscii(bf, len, buf);
                    } else
                    {
                        len = _putsAscii(ptr, len, buf);
                    }
                    break;
                case 'S' : // preproc encoded string handler
                    ptr = va_arg(va, char*);
                    len = StringLength((u8*)ptr);
                    if (pad_to > 0)
                    {
                        len = mini_pad(ptr, len, pad_char, pad_to, bf);
                        len = _putsEncoded(bf, len, buf);
                    } else
                    {
                        len = _putsEncoded(ptr, len, buf);
                    }
                    break;
                default:
                    len = 1;
                    len = _putsAscii(&ch, len, buf);
                    break;
            }
        }
        n = n + len;
    }
end:
    return n;
}

#endif
