
// Includes
#include "global.h"
#include "main.h"
#include "species.h"
#include "malloc.h"
#include "easy_chat.h"
#include "mail_data.h"
#include "mail.h"

// Static type declarations

struct UnkMailStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:2;
    u8 unk_0_4:4;
};

struct MailLayout
{
    u8 var0;
    u8 var1;
    u8 var2;
    u8 var3_0:4;
    u8 var3_4:4;
    struct UnkMailStruct *var4;
    u32 var8;
};

struct Unk203A134
{
    /*0x0000*/ u8 filler_0000[0x20c];
    /*0x020C*/ MainCallback callback;
    /*0x0210*/ u8 filler_0210[4];
    /*0x0214*/ struct MailStruct *mail;
    /*0x0218*/ bool8 flag;
    /*0x0219*/ u8 filler_0219[1];
    /*0x021a*/ u8 mailType;
    /*0x021b*/ u8 unk_021b;
    /*0x021c*/ u8 unk_021c;
    /*0x021d*/ u8 language;
    /*0x021e*/ bool8 playerIsSender;
    /*0x0220*/ void (*parserSingle)(u8 *dest, u16 word);
    /*0x0224*/ void (*parserMultiple)(u8 *dest, const u16 *src, u16 length1, u16 length2);
    /*0x0228*/ const struct MailLayout *layout;
    /*0x022c*/ u8 filler_022C[0x2000];
};

struct MailGraphics
{
    u16 (*palette)[];
    u8 (*tiles)[];
    u8 (*tileMap)[];
    u16 var0C;
    u16 var0E;
    u16 color10;
    u16 color12;
};

// Static RAM declarations

EWRAM_DATA struct Unk203A134 *gUnknown_0203A134;

// Static ROM declarations

void sub_81219F0(void);

// .rodata

extern const struct MailLayout gUnknown_0859F3B4[];
extern const struct MailLayout gUnknown_0859F458[];

// .text

void sub_8121478(struct MailStruct *mail, MainCallback callback, bool8 flag) {
    u16 buffer[2];
    u16 species;

    gUnknown_0203A134 = calloc(1, sizeof(struct Unk203A134));
    gUnknown_0203A134->language = LANGUAGE_ENGLISH;
    gUnknown_0203A134->playerIsSender = TRUE;
    gUnknown_0203A134->parserSingle = CopyEasyChatWord;
    gUnknown_0203A134->parserMultiple = ConvertEasyChatWordsToString;
    if (mail->itemId >= ITEM_ORANGE_MAIL && mail->itemId <= ITEM_RETRO_MAIL) {
        gUnknown_0203A134->mailType = mail->itemId - ITEM_ORANGE_MAIL;
    }
    else
    {
        gUnknown_0203A134->mailType = 0;
        flag = FALSE;
    }
    switch (gUnknown_0203A134->playerIsSender)
    {
        case FALSE:
        default:
            gUnknown_0203A134->layout = &gUnknown_0859F3B4[gUnknown_0203A134->mailType];
            break;
        case TRUE:
            gUnknown_0203A134->layout = &gUnknown_0859F458[gUnknown_0203A134->mailType];
            break;
    }
    species = sub_80D45E8(mail->species, buffer);
    if (species >= SPECIES_BULBASAUR && species < NUM_SPECIES)
    {
        switch (gUnknown_0203A134->mailType)
        {
            default:
                gUnknown_0203A134->unk_021b = 0;
                break;
            case ITEM_BEAD_MAIL - ITEM_ORANGE_MAIL:
                gUnknown_0203A134->unk_021b = 1;
                break;
            case ITEM_DREAM_MAIL - ITEM_ORANGE_MAIL:
                gUnknown_0203A134->unk_021b = 2;
                break;
        }
    }
    else
    {
        gUnknown_0203A134->unk_021b = 0;
    }
    gUnknown_0203A134->mail = mail;
    gUnknown_0203A134->callback = callback;
    gUnknown_0203A134->flag = flag;
    SetMainCallback2(sub_81219F0);
}
