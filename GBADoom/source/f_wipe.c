/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *      Mission begin melt/wipe screen special effect.
 *
 *-----------------------------------------------------------------------------
 */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "z_zone.h"
#include "doomdef.h"
#include "i_video.h"
#include "v_video.h"
#include "m_random.h"
#include "f_wipe.h"
#include "global_data.h"

#ifdef __arm__
    #include <gba.h>
#endif

//
// SCREEN WIPE PACKAGE
//

int wipe_StartScreen(void)
{
    _g->wipe_tick = 0;
    return 0;
}

int wipe_EndScreen(void)
{
    _g->wipe_tick = 0;
    return 0;
}

// killough 3/5/98: reformatted and cleaned up
int wipe_ScreenWipe(int ticks)
{
    unsigned int wipepos;

    //Do a pageflip on the 16th tick.
    boolean pageflip = (_g->wipe_tick < 16) &&  (_g->wipe_tick + ticks >= 16);

    _g->wipe_tick += ticks;

    int wipeticks = _g->wipe_tick;

    if(wipeticks >= 32)
    {
        wipeticks = 32;
        wipepos = 0;
    }
    else if(wipeticks < 16)
    {
        wipepos = wipeticks;
    }
    else //16->31
    {
        wipepos = 31 - wipeticks;
    }

#ifdef __arm__
    REG_BLDCNT = 0xc4;
    REG_BLDY = wipepos;

    VBlankIntrWait();
#endif

    if(pageflip)
         I_FinishUpdate();

    if(wipeticks >= 32)
    {
#ifdef __arm__
        REG_BLDCNT = 0;
#endif
        return 1;
    }

    return 0;
}
