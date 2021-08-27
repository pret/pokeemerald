/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2006 by
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
 *  DOOM graphics stuff for SDL
 *
 *-----------------------------------------------------------------------------
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <math.h>

#include "doomstat.h"
#include "doomdef.h"
#include "doomtype.h"
#include "v_video.h"
#include "r_draw.h"
#include "d_main.h"
#include "d_event.h"
#include "i_video.h"
#include "i_sound.h"
#include "z_zone.h"
#include "s_sound.h"
#include "sounds.h"
#include "w_wad.h"
#include "st_stuff.h"
#include "lprintf.h"

#include "i_system_e32.h"

#include "global_data.h"

//
// I_StartTic
//

void I_StartTic (void)
{
    I_ProcessKeyEvents();
}

//
// I_StartFrame
//
void I_StartFrame (void)
{

}


boolean I_StartDisplay(void)
{
    unsigned short* backbuffer = I_GetBackBuffer();

    _g->screens[0].data = backbuffer;

    // Same with base row offset.
    drawvars.byte_topleft = backbuffer;

    return true;
}

void I_EndDisplay(void)
{

}


//
// I_InitInputs
//

static void I_InitInputs(void)
{

}
/////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Palette stuff.
//
static void I_UploadNewPalette(int pal)
{
  // This is used to replace the current 256 colour cmap with a new one
  // Used by 256 colour PseudoColor modes
  
    if(!_g->pallete_lump)
    {
        _g->pallete_lump = W_CacheLumpName("PLAYPAL");
    }

    _g->current_pallete = &_g->pallete_lump[pal*256*3];

    I_SetPallete_e32(_g->current_pallete);
}

//////////////////////////////////////////////////////////////////////////////
// Graphics API

void I_ShutdownGraphics(void)
{
}

//
// I_UpdateNoBlit
//
void I_UpdateNoBlit (void)
{
}

//
// I_FinishUpdate
//
#define NO_PALETTE_CHANGE 1000

void I_FinishUpdate (void)
{
    if (_g->newpal != NO_PALETTE_CHANGE)
	{
        I_UploadNewPalette(_g->newpal);
        _g->newpal = NO_PALETTE_CHANGE;
	}

    I_FinishUpdate_e32(_g->screens[0].data, _g->current_pallete, SCREENWIDTH, SCREENHEIGHT);
}

//
// I_SetPalette
//
void I_SetPalette (int pal)
{
    _g->newpal = pal;
}


void I_PreInitGraphics(void)
{
	I_InitScreen_e32();
}

// CPhipps -
// I_SetRes
// Sets the screen resolution
void I_SetRes(void)
{
    //backbuffer
    _g->screens[0].width = SCREENWIDTH;
    _g->screens[0].height = SCREENHEIGHT;

    lprintf(LO_INFO,"I_SetRes: Using resolution %dx%d", SCREENWIDTH, SCREENHEIGHT);
}

void I_InitGraphics(void)
{
    static int    firsttime=1;

    if (firsttime)
    {
        firsttime = 0;

        lprintf(LO_INFO, "I_InitGraphics: %dx%d", SCREENWIDTH, SCREENHEIGHT);

        /* Set the video mode */
        I_UpdateVideoMode();

        /* Initialize the input system */
        I_InitInputs();

        I_CreateBackBuffer_e32();
    }
}

void I_UpdateVideoMode(void)
{
  lprintf(LO_INFO, "I_SetRes: %dx%d", SCREENWIDTH, SCREENHEIGHT);
  I_SetRes();

  lprintf(LO_INFO, "R_InitBuffer:");
  R_InitBuffer();
}
