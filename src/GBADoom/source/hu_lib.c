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
 * DESCRIPTION:  heads-up text and input code
 *
 *-----------------------------------------------------------------------------
 */

#include "doomdef.h"
#include "doomstat.h"
#include "v_video.h"
#include "m_swap.h"
#include "hu_lib.h"
#include "hu_stuff.h"
#include "r_main.h"
#include "r_draw.h"

#include "global_data.h"

////////////////////////////////////////////////////////
//
// Basic text line widget
//
////////////////////////////////////////////////////////

//
// HUlib_clearTextLine()
//
// Blank the internal text line in a hu_textline_t widget
//
// Passed a hu_textline_t, returns nothing
//
void HUlib_clearTextLine(hu_textline_t* t)
{
  t->linelen =         // killough 1/23 98: support multiple lines
    t->len = 0;
  t->l[0] = 0;
  t->needsupdate = true;
}

//
// HUlib_initTextLine()
//
// Initialize a hu_textline_t widget. Set the position, font, start char
// of the font, and color range to be used.
//
// Passed a hu_textline_t, and the values used to initialize
// Returns nothing
//
void HUlib_initTextLine(hu_textline_t* t, int x, int y, const patch_t* f, int sc)
  //jff 2/16/98 add color range parameter
{
  t->x = x;
  t->y = y;
  t->f = f;
  t->sc = sc;
  HUlib_clearTextLine(t);
}

//
// HUlib_addCharToTextLine()
//
// Adds a character at the end of the text line in a hu_textline_t widget
//
// Passed the hu_textline_t and the char to add
// Returns false if already at length limit, true if the character added
//
boolean HUlib_addCharToTextLine
( hu_textline_t*  t,
  char      ch )
{
  // killough 1/23/98 -- support multiple lines
  if (t->linelen == HU_MAXLINELENGTH)
    return false;
  else
  {
    t->linelen++;
    if (ch == '\n')
      t->linelen=0;

    t->l[t->len++] = ch;
    t->l[t->len] = 0;
    t->needsupdate = 4;
    return true;
  }

}

//
// HUlib_drawTextLine()
//
// Draws a hu_textline_t widget
//
// Passed the hu_textline_t and flag whether to draw a cursor
// Returns nothing
//
void HUlib_drawTextLine
( hu_textline_t* l,
  boolean drawcursor )
{

    int     i;
    int     w;
    int     x;
    unsigned char c;
    int y = l->y;           // killough 1/18/98 -- support multiple lines

    // draw the new stuff
    x = l->x;
    for (i=0;i<l->len;i++)
    {
        c = toupper(l->l[i]); //jff insure were not getting a cheap toupper conv.

        if (c=='\n')         // killough 1/18/98 -- support multiple lines
            x=0,y+=8;
        else if (c=='\t')    // killough 1/23/98 -- support tab stops
            x=x-x%80+80;
        else  if (c != ' ' && c >= l->sc && c <= '_')
        {
            w = l->f[c - l->sc]->width;
            if (x+w > 240)
                break;
            // killough 1/18/98 -- support multiple lines:
            // CPhipps - patch drawing updated
            V_DrawPatchNoScale(x, y, l->f[c - l->sc]);
            x += w;
        }
        else
        {
            x += 4;
            if (x >= 240)
                break;
        }
    }

    // draw the cursor if requested
    if (drawcursor && x + l->f['_' - l->sc]->width <= BASE_WIDTH)
    {
        // killough 1/18/98 -- support multiple lines
        // CPhipps - patch drawing updated
        V_DrawPatch(x, y, HU_FG, l->f['_' - l->sc]);
    }
}

//
// HUlib_eraseTextLine()
//
// Erases a hu_textline_t widget when screen border is behind text
// Sorta called by HU_Erase and just better darn get things straight
//
// Passed the hu_textline_t
// Returns nothing
//
void HUlib_eraseTextLine(hu_textline_t* l)
{
  if (l->needsupdate)
      l->needsupdate--;
}

////////////////////////////////////////////////////////
//
// Player message widget (up to 4 lines of text)
//
////////////////////////////////////////////////////////

//
// HUlib_initSText()
//
// Initialize a hu_stext_t widget. Set the position, number of lines, font,
// start char of the font, and color range to be used, and whether enabled.
//
// Passed a hu_stext_t, and the values used to initialize
// Returns nothing
//
void HUlib_initSText
( hu_stext_t* s,
  int   x,
  int   y,
  int   h,
  const patch_t* font,
  int   startchar,  boolean*  on )
{

  int i;

  s->h = h;
  s->on = on;
  s->laston = true;
  s->cl = 0;
  for (i=0;i<h;i++)
    HUlib_initTextLine
    (
      &s->l[i],
      x,
      y - i*(font[0].height+1),
      font,
      startchar
    );
}

//
// HUlib_addLineToSText()
//
// Adds a blank line to a hu_stext_t widget
//
// Passed a hu_stext_t
// Returns nothing
//
static void HUlib_addLineToSText(hu_stext_t* s)
{

  int i;

  // add a clear line
  if (++s->cl == s->h)
    s->cl = 0;
  HUlib_clearTextLine(&s->l[s->cl]);

  // everything needs updating
  for (i=0 ; i<s->h ; i++)
    s->l[i].needsupdate = 4;

}

//
// HUlib_addMessageToSText()
//
// Adds a message line with prefix to a hu_stext_t widget
//
// Passed a hu_stext_t, the prefix string, and a message string
// Returns nothing
//
void HUlib_addMessageToSText(hu_stext_t* s, const char* prefix, const char* msg)
{
  HUlib_addLineToSText(s);
    if (prefix)
      while (*prefix)
        HUlib_addCharToTextLine(&s->l[s->cl], *(prefix++));

  while (*msg)
    HUlib_addCharToTextLine(&s->l[s->cl], *(msg++));
}

//
// HUlib_drawSText()
//
// Displays a hu_stext_t widget
//
// Passed a hu_stext_t
// Returns nothing
//
void HUlib_drawSText(hu_stext_t* s)
{
  int i, idx;
  hu_textline_t *l;

  if (!*s->on)
    return; // if not on, don't draw

  // draw everything
  for (i=0 ; i<s->h ; i++)
  {
    idx = s->cl - i;
    if (idx < 0)
      idx += s->h; // handle queue of lines

    l = &s->l[idx];

    // need a decision made here on whether to skip the draw
    HUlib_drawTextLine(l, false); // no cursor, please
  }
}

//
// HUlib_eraseSText()
//
// Erases a hu_stext_t widget, when the screen is not fullsize
//
// Passed a hu_stext_t
// Returns nothing
//
void HUlib_eraseSText(hu_stext_t* s)
{
  int i;

  for (i=0 ; i<s->h ; i++)
  {
    if (s->laston && !*s->on)
       s->l[i].needsupdate = 4;
    HUlib_eraseTextLine(&s->l[i]);
  }
  s->laston = *s->on;
}
