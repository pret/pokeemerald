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
 *      The status bar widget code.
 *
 *-----------------------------------------------------------------------------*/

#include "doomdef.h"
#include "doomstat.h"
#include "v_video.h"
#include "w_wad.h"
#include "st_stuff.h"
#include "st_lib.h"
#include "r_main.h"
#include "lprintf.h"
#include "global_data.h"

#include "gba_functions.h"

//
// STlib_init()
//
void STlib_init(void)
{
  // cph - no longer hold STMINUS pointer
}

//
// STlib_initNum()
//
// Initializes an st_number_t widget
//
// Passed the widget, its position, the patches for the digits, a pointer
// to the value displayed, a pointer to the on/off control, and the width
// Returns nothing
//
void STlib_initNum
(st_number_t* n,
  int x,
  int y,
  const patch_t **pl,
  int* num,
  boolean* on,
  int     width )
{
  n->x  = x;
  n->y  = y;
  n->oldnum = 0;
  n->width  = width;
  n->num  = num;
  n->on = on;
  n->p  = pl;
}

/*
 * STlib_drawNum()
 *
 * A fairly efficient way to draw a number based on differences from the
 * old number.
 *
 * Passed a st_number_t widget, a color range for output, and a flag
 * indicating whether refresh is needed.
 * Returns nothing
 *
 * jff 2/16/98 add color translation to digit output
 * cphipps 10/99 - const pointer to colour trans table, made function static
 */
static void STlib_drawNum
( st_number_t*  n,
  int cm,
  boolean refresh )
{

  int   numdigits = n->width;
  int   num = *n->num;

  int   w = n->p[0]->width;
  int   x = n->x;

  int   neg;

  // CPhipps - compact some code, use num instead of *n->num
  if ((neg = (n->oldnum = num) < 0))
  {
    if (numdigits == 2 && num < -9)
      num = -9;
    else if (numdigits == 3 && num < -99)
      num = -99;

    num = -num;
  }

  // clear the area
  x = n->x - numdigits*w;

  // if non-number, do not draw it
  if (num == 1994)
    return;

  x = n->x;

  //jff 2/16/98 add color translation to digit output
  // in the special case of 0, you draw 0
  if (!num)
    // CPhipps - patch drawing updated, reformatted
    V_DrawPatchNoScale(x - w, n->y, n->p[0]);

  // draw the new number
  //jff 2/16/98 add color translation to digit output
  while (num && numdigits--)
  {
    // CPhipps - patch drawing updated, reformatted
    x -= w;
    V_DrawPatchNoScale(x, n->y, n->p[num % 10]);
    num /= 10;
  }
}

/*
 * STlib_updateNum()
 *
 * Draws a number conditionally based on the widget's enable
 *
 * Passed a number widget, the output color range, and a refresh flag
 * Returns nothing
 *
 * jff 2/16/98 add color translation to digit output
 * cphipps 10/99 - make that pointer const
 */
void STlib_updateNum
( st_number_t*    n,
  int cm,
  boolean   refresh )
{
  if (*n->on) STlib_drawNum(n, cm, refresh);
}

//
// STlib_initPercent()
//
// Initialize a st_percent_t number with percent sign widget
//
// Passed a st_percent_t widget, the position, the digit patches, a pointer
// to the number to display, a pointer to the enable flag, and patch
// for the percent sign.
// Returns nothing.
//
void STlib_initPercent
(st_percent_t* p,
  int x,
  int y,
  const patch_t** pl,
  int* num,
  boolean* on,
  const patch_t *percent )
{
  STlib_initNum(&p->n, x, y, pl, num, on, 3);
  p->p = percent;
}

/*
 * STlib_updatePercent()
 *
 * Draws a number/percent conditionally based on the widget's enable
 *
 * Passed a precent widget, the output color range, and a refresh flag
 * Returns nothing
 *
 * jff 2/16/98 add color translation to digit output
 * cphipps - const for pointer to the colour translation table
 */

void STlib_updatePercent(st_percent_t* per, int cm, int refresh)
{
    STlib_updateNum(&per->n, cm, refresh);
    //V_DrawPatchNoScale(per->n.x, per->n.y, per->p); - Percentage is in the GBA Doom II Hud graphic ~Kippykip
}

//
// STlib_initMultIcon()
//
// Initialize a st_multicon_t widget, used for a multigraphic display
// like the status bar's keys.
//
// Passed a st_multicon_t widget, the position, the graphic patches, a pointer
// to the numbers representing what to display, and pointer to the enable flag
// Returns nothing.
//
void STlib_initMultIcon
(st_multicon_t* i,
  int x,
  int y,
  const patch_t **il,
  int* inum,
  boolean* on )
{
  i->x  = x;
  i->y  = y;
  i->oldinum  = -1;
  i->inum = inum;
  i->on = on;
  i->p  = il;
}

//
// STlib_updateMultIcon()
//
// Draw a st_multicon_t widget, used for a multigraphic display
// like the status bar's keys. Displays each when the control
// numbers change or refresh is true
//
// Passed a st_multicon_t widget, and a refresh flag
// Returns nothing.
//
void STlib_updateMultIcon
( st_multicon_t*  mi,
  boolean   refresh )
{
    int w;
    int h;
    int x;
    int y;

    if(!mi->p)
        return;

    if (*mi->inum != -1)  // killough 2/16/98: redraw only if != -1
		V_DrawPatchNoScale(mi->x, mi->y, mi->p[*mi->inum]);

    mi->oldinum = *mi->inum;

}

//
// STlib_initBinIcon()
//
// Initialize a st_binicon_t widget, used for a multinumber display
// like the status bar's weapons, that are present or not.
//
// Passed a st_binicon_t widget, the position, the digit patches, a pointer
// to the flags representing what is displayed, and pointer to the enable flag
// Returns nothing.
//
void STlib_initBinIcon
( st_binicon_t* b,
  int x,
  int y,
  const patch_t* i,
  boolean* val,
  boolean* on )
{
  b->x  = x;
  b->y  = y;
  b->oldval = 0;
  b->val  = val;
  b->on = on;
  b->p  = i;
}

//
// STlib_updateBinIcon()
//
// DInitialize a st_binicon_t widget, used for a multinumber display
// like the status bar's weapons, that are present or not.
//
// Draw a st_binicon_t widget, used for a multinumber display
// like the status bar's weapons that are present or not. Displays each
// when the control flag changes or refresh is true
//
// Passed a st_binicon_t widget, and a refresh flag
// Returns nothing.
//
void STlib_updateBinIcon
( st_binicon_t*   bi,
  boolean   refresh )
{
  int     x;
  int     y;
  int     w;
  int     h;

  if (*bi->on && (bi->oldval != *bi->val || refresh))
  {
    x = bi->x - bi->p->leftoffset;
    y = bi->y - bi->p->topoffset;
    w = bi->p->width;
    h = bi->p->height;

    if (*bi->val)
      V_DrawPatch(bi->x, bi->y, ST_FG, bi->p);

    bi->oldval = *bi->val;
  }
}

void ST_refreshBackground(void)
{
    if (_g->st_statusbaron)
    {
        const unsigned int st_offset = ((SCREENHEIGHT-ST_SCALED_HEIGHT)*120);

        CpuBlockCopy(&_g->screens[0].data[st_offset], _g->stbarbg, _g->stbar_len);
    }
}
