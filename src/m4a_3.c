#include "gba/m4a_internal.h"

extern const u8 gCgb3Vol[];

void CgbSound(void)
{
    s32 ch;
    struct CgbChannel *channels;
    s32 evAdd;
    s32 prevC15;
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu8 *nrx0ptr;
    vu8 *nrx1ptr;
    vu8 *nrx2ptr;
    vu8 *nrx3ptr;
    vu8 *nrx4ptr;

    // Most comparision operations that cast to s8 perform 'and' by 0xFF.
    int xFF = 0xff;

    if (soundInfo->c15)
        soundInfo->c15--;
    else
        soundInfo->c15 = 14;

    for (ch = 1, channels = soundInfo->cgbChans; ch <= 4; ch++, channels++)
    {
        if (!(channels->sf & 0xc7))
            continue;

        switch (ch)
        {
        case 1:
            nrx0ptr = (vu8 *)(REG_ADDR_NR10);
            nrx1ptr = (vu8 *)(REG_ADDR_NR11);
            nrx2ptr = (vu8 *)(REG_ADDR_NR12);
            nrx3ptr = (vu8 *)(REG_ADDR_NR13);
            nrx4ptr = (vu8 *)(REG_ADDR_NR14);
            break;
        case 2:
            nrx0ptr = (vu8 *)(REG_ADDR_NR10+1);
            nrx1ptr = (vu8 *)(REG_ADDR_NR21);
            nrx2ptr = (vu8 *)(REG_ADDR_NR22);
            nrx3ptr = (vu8 *)(REG_ADDR_NR23);
            nrx4ptr = (vu8 *)(REG_ADDR_NR24);
            break;
        case 3:
            nrx0ptr = (vu8 *)(REG_ADDR_NR30);
            nrx1ptr = (vu8 *)(REG_ADDR_NR31);
            nrx2ptr = (vu8 *)(REG_ADDR_NR32);
            nrx3ptr = (vu8 *)(REG_ADDR_NR33);
            nrx4ptr = (vu8 *)(REG_ADDR_NR34);
            break;
        default:
            nrx0ptr = (vu8 *)(REG_ADDR_NR30+1);
            nrx1ptr = (vu8 *)(REG_ADDR_NR41);
            nrx2ptr = (vu8 *)(REG_ADDR_NR42);
            nrx3ptr = (vu8 *)(REG_ADDR_NR43);
            nrx4ptr = (vu8 *)(REG_ADDR_NR44);
            break;
        }

        prevC15 = soundInfo->c15;
        evAdd = *nrx2ptr;

        if (channels->sf & 0x80)
        {
            if (!(channels->sf & 0x40))
            {
                channels->sf = 3;
                channels->mo = 3;
                CgbModVol(channels);
                switch (ch)
                {
                case 1:
                    *nrx0ptr = channels->sw;
                    // fallthrough
                case 2:
                    *nrx1ptr = ((u32)channels->wp << 6) + channels->le;
                    goto loc_82E0E30;
                    break;
                case 3:
                    if ((u32)channels->wp != channels->cp)
                    {
                        *nrx0ptr = 0x40;
                        REG_WAVE_RAM0 = channels->wp[0];
                        REG_WAVE_RAM1 = channels->wp[1];
                        REG_WAVE_RAM2 = channels->wp[2];
                        REG_WAVE_RAM3 = channels->wp[3];
                        channels->cp = (u32)channels->wp;
                    }
                    *nrx0ptr = 0;
                    *nrx1ptr = channels->le;
                    if (channels->le)
                        channels->n4 = -64;
                    else
                        channels->n4 = -128;
                    break;
                default:
                    *nrx1ptr = channels->le;
                    *nrx3ptr = (u32)channels->wp << 3;
                loc_82E0E30:
                    evAdd = channels->at + 8;
                    if (channels->le)
                        channels->n4 = 64;
                    else
                        channels->n4 = 0;
                    break;
                }
                channels->ec = channels->at;
                if ((s8)(channels->at & xFF))
                {
                    channels->ev = 0;
                    goto EC_MINUS;
                }
                else
                {
                    goto loc_82E0F96;
                }
            }
            else
            {
                goto loc_82E0E82;
            }
        }
        else if (channels->sf & 0x04)
        {
            channels->echoLength--;
            if ((s8)(channels->echoLength & xFF) <= 0)
            {
            loc_82E0E82:
                CgbOscOff(ch);
                channels->sf = 0;
                goto LAST_LABEL;
            }
            goto loc_82E0FD6;
        }
        else if ((channels->sf & 0x40) && (channels->sf & 0x03))
        {
            channels->sf &= 0xfc;
            channels->ec = channels->re;
            if ((s8)(channels->re & xFF))
            {
                channels->mo |= 1;
                if (ch != 3)
                {
                    evAdd = channels->re;
                }
                goto EC_MINUS;
            }
            else
            {
                goto loc_82E0F02;
            }
        }
        else
        {
        loc_82E0ED0:
            if (channels->ec == 0)
            {
                if (ch == 3)
                {
                    channels->mo |= 1;
                }
                CgbModVol(channels);
                if ((channels->sf & 0x3) == 0)
                {
                    channels->ev--;
                    if ((s8)(channels->ev & xFF) <= 0)
                    {
                    loc_82E0F02:
                        channels->ev = ((channels->eg * channels->echoVolume) + 0xFF) >> 8;
                        if (channels->ev)
                        {
                            channels->sf |= 0x4;
                            channels->mo |= 1;
                            if (ch != 3)
                            {
                                evAdd = 8;
                            }
                            goto loc_82E0FD6;
                        }
                        else
                        {
                            goto loc_82E0E82;
                        }
                    }
                    else
                    {
                        channels->ec = channels->re;
                    }
                }
                else if ((channels->sf & 0x3) == 1)
                {
                loc_82E0F3A:
                    channels->ev = channels->sg;
                    channels->ec = 7;
                }
                else if ((channels->sf & 0x3) == 2)
                {
                    int ev, sg;

                    channels->ev--;
                    ev = (s8)(channels->ev & xFF);
                    sg = (s8)(channels->sg);
                    if (ev <= sg)
                    {
                    loc_82E0F5A:
                        if (channels->su == 0)
                        {
                            channels->sf &= 0xfc;
                            goto loc_82E0F02;
                        }
                        else
                        {
                            channels->sf--;
                            channels->mo |= 1;
                            if (ch != 3)
                            {
                                evAdd = 8;
                            }
                            goto loc_82E0F3A;
                        }
                    }
                    else
                    {
                        channels->ec = channels->de;
                    }
                }
                else
                {
                    channels->ev++;
                    if ((u8)(channels->ev & xFF) >= channels->eg)
                    {
                    loc_82E0F96:
                        channels->sf--;
                        channels->ec = channels->de;
                        if ((u8)(channels->ec & xFF))
                        {
                            channels->mo |= 1;
                            channels->ev = channels->eg;
                            if (ch != 3)
                            {
                                evAdd = channels->de;
                            }
                        }
                        else
                        {
                            goto loc_82E0F5A;
                        }
                    }
                    else
                    {
                        channels->ec = channels->at;
                    }
                }
            }
        }

    EC_MINUS:
        channels->ec--;
        if (prevC15 == 0)
        {
            prevC15--;
            goto loc_82E0ED0;
        }

    loc_82E0FD6:
        if (channels->mo & 0x2)
        {
            if (ch < 4 && (channels->ty & 0x08))
            {
                int biasH = REG_SOUNDBIAS_H;

                if (biasH < 64)
                {
                    channels->fr = (channels->fr + 2) & 0x7fc;
                }
                else if (biasH < 128)
                {
                    channels->fr = (channels->fr + 1) & 0x7fe;
                }
            }
            if (ch != 4)
            {
                *nrx3ptr = channels->fr;
            }
            else
            {
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->fr;
            }
            channels->n4 = (channels->n4 & 0xC0) + (*((u8*)(&channels->fr) + 1));
            *nrx4ptr = (s8)(channels->n4 & xFF);
        }

        if (channels->mo & 1)
        {
            REG_NR51 = (REG_NR51 & ~channels->panMask) | channels->pan;
            if (ch == 3)
            {
                *nrx2ptr = gCgb3Vol[channels->ev];
                if (channels->n4 & 0x80)
                {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= 0x7f;
                }
            }
            else
            {
                evAdd &= 0xf;
                *nrx2ptr = (channels->ev << 4) + evAdd;
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                {
                    *nrx4ptr = channels->n4 | 0x80;
                }
            }
        }

    LAST_LABEL:
        channels->mo = 0;
    }
}
