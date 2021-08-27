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
 *   the automap code
 *
 *-----------------------------------------------------------------------------
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "doomstat.h"
#include "st_stuff.h"
#include "r_main.h"
#include "p_setup.h"
#include "p_maputl.h"
#include "w_wad.h"
#include "v_video.h"
#include "p_spec.h"
#include "am_map.h"
#include "dstrings.h"
#include "lprintf.h"  // jff 08/03/98 - declaration of lprintf
#include "g_game.h"

#include "global_data.h"


static const int mapcolor_back = 247;    // map background
static const int mapcolor_grid = 104;    // grid lines color
static const int mapcolor_wall = 23;    // normal 1s wall color
static const int mapcolor_fchg = 55;    // line at floor height change color
static const int mapcolor_cchg = 215;    // line at ceiling height change color
static const int mapcolor_clsd = 208;    // line at sector with floor=ceiling color
static const int mapcolor_rdor = 175;    // red door color  (diff from keys to allow option)
static const int mapcolor_bdor = 204;    // blue door color (of enabling one but not other )
static const int mapcolor_ydor = 231;    // yellow door color
static const int mapcolor_tele = 119;    // teleporter line color
static const int mapcolor_secr = 252;    // secret sector boundary color
static const int mapcolor_exit = 0;    // jff 4/23/98 add exit line color
static const int mapcolor_unsn = 104;    // computer map unseen line color
static const int mapcolor_flat = 88;    // line with no floor/ceiling changes
static const int mapcolor_sngl = 208;    // single player arrow color
static const int map_secret_after = 0;




//jff 3/9/98 add option to not show secret sectors until entered
//jff 4/3/98 add symbols for "no-color" for disable and "black color" for black
#define NC 0
#define BC 247

// drawing stuff
#define FB    0


// how much the automap moves window per tic in frame-buffer coordinates
// moves 140 pixels in 1 second
#define F_PANINC  4
// how much zoom-in per tic
// goes to 2x in 1 second
#define M_ZOOMIN        ((int) (1.02*FRACUNIT))
// how much zoom-out per tic
// pulls out to 0.5x in 1 second
#define M_ZOOMOUT       ((int) (FRACUNIT/1.02))

#define PLAYERRADIUS    (16*(1<<MAPBITS)) // e6y

// translates between frame-buffer and map distances
#define FTOM(x) FixedMul(((x)<<16),_g->scale_ftom)
#define MTOF(x) (FixedMul((x),_g->scale_mtof)>>16)
// translates between frame-buffer and map coordinates
#define CXMTOF(x)  (_g->f_x + MTOF((x)- _g->m_x))
#define CYMTOF(y)  (_g->f_y + (_g->f_h - MTOF((y)- _g->m_y)))

typedef struct
{
    mpoint_t a, b;
} mline_t;

//
// The vector graphics for the automap.
//  A line drawing of the player pointing right,
//   starting from the middle.
//
#define R ((8*PLAYERRADIUS)/7)
static const mline_t player_arrow[] =
{
  { { -R+R/8, 0 }, { R, 0 } }, // -----
  { { R, 0 }, { R-R/2, R/4 } },  // ----->
  { { R, 0 }, { R-R/2, -R/4 } },
  { { -R+R/8, 0 }, { -R-R/8, R/4 } }, // >---->
  { { -R+R/8, 0 }, { -R-R/8, -R/4 } },
  { { -R+3*R/8, 0 }, { -R+R/8, R/4 } }, // >>--->
  { { -R+3*R/8, 0 }, { -R+R/8, -R/4 } }
};
#undef R
#define NUMPLYRLINES (sizeof(player_arrow)/sizeof(mline_t))



//
// AM_activateNewScale()
//
// Changes the map scale after zooming or translating
//
// Passed nothing, returns nothing
//
static void AM_activateNewScale(void)
{
    _g->m_x += _g->m_w/2;
    _g->m_y += _g->m_h/2;
    _g->m_w = FTOM(_g->f_w);
    _g->m_h = FTOM(_g->f_h);
    _g->m_x -= _g->m_w/2;
    _g->m_y -= _g->m_h/2;
    _g->m_x2 =  _g->m_x + _g->m_w;
    _g->m_y2 =  _g->m_y + _g->m_h;
}

//
// AM_findMinMaxBoundaries()
//
// Determines bounding box of all vertices,
// sets global variables controlling zoom range.
//
// Passed nothing, returns nothing
//
static void AM_findMinMaxBoundaries(void)
{
  int i;
  fixed_t a;
  fixed_t b;

  _g->min_x = _g->min_y =  INT_MAX;
  _g->max_x = _g->max_y = -INT_MAX;

  for (i=0;i<_g->numvertexes;i++)
  {
    if (_g->vertexes[i].x < _g->min_x)
      _g->min_x = _g->vertexes[i].x;
    else if (_g->vertexes[i].x > _g->max_x)
      _g->max_x = _g->vertexes[i].x;

    if (_g->vertexes[i].y < _g->min_y)
      _g->min_y = _g->vertexes[i].y;
    else if (_g->vertexes[i].y > _g->max_y)
      _g->max_y = _g->vertexes[i].y;
  }

  _g->max_w = (_g->max_x >>= FRACTOMAPBITS) - (_g->min_x >>= FRACTOMAPBITS);//e6y
  _g->max_h = (_g->max_y >>= FRACTOMAPBITS) - (_g->min_y >>= FRACTOMAPBITS);//e6y

  a = FixedDiv(_g->f_w<<FRACBITS, _g->max_w);
  b = FixedDiv(_g->f_h<<FRACBITS, _g->max_h);

  _g->min_scale_mtof = a < b ? a : b;
  _g->max_scale_mtof = FixedDiv(_g->f_h<<FRACBITS, 2*PLAYERRADIUS);
}

//
// AM_changeWindowLoc()
//
// Moves the map window by the global variables m_paninc.x, m_paninc.y
//
// Passed nothing, returns nothing
//
static void AM_changeWindowLoc(void)
{
  if ( _g->m_paninc.x ||  _g->m_paninc.y)
  {
    _g->automapmode &= ~am_follow;
    _g->f_oldloc.x = INT_MAX;
  }

   _g->m_x +=  _g->m_paninc.x;
   _g->m_y +=  _g->m_paninc.y;

  if ( _g->m_x + _g->m_w/2 > _g->max_x)
     _g->m_x = _g->max_x - _g->m_w/2;
  else if ( _g->m_x + _g->m_w/2 < _g->min_x)
     _g->m_x = _g->min_x - _g->m_w/2;

  if ( _g->m_y + _g->m_h/2 > _g->max_y)
     _g->m_y = _g->max_y - _g->m_h/2;
  else if ( _g->m_y + _g->m_h/2 < _g->min_y)
     _g->m_y = _g->min_y - _g->m_h/2;

   _g->m_x2 =  _g->m_x + _g->m_w;
   _g->m_y2 =  _g->m_y + _g->m_h;
}


//
// AM_initVariables()
//
// Initialize the variables for the automap
//
// Affects the automap global variables
// Status bar is notified that the automap has been entered
// Passed nothing, returns nothing
//
static void AM_initVariables(void)
{
  static const event_t st_notify = { ev_keyup, AM_MSGENTERED, 0, 0 };

  _g->automapmode |= am_active;

  _g->f_oldloc.x = INT_MAX;

   _g->m_paninc.x =  _g->m_paninc.y = 0;

  _g->m_w = FTOM(_g->f_w);
  _g->m_h = FTOM(_g->f_h);


   _g->m_x = (_g->player.mo->x >> FRACTOMAPBITS) - _g->m_w/2;//e6y
   _g->m_y = (_g->player.mo->y >> FRACTOMAPBITS) - _g->m_h/2;//e6y
  AM_changeWindowLoc();

  // inform the status bar of the change
  ST_Responder(&st_notify);
}

//
// AM_LevelInit()
//
// Initialize the automap at the start of a new level
// should be called at the start of every level
//
// Passed nothing, returns nothing
// Affects automap's global variables
//
// CPhipps - get status bar height from status bar code
static void AM_LevelInit(void)
{
  _g->f_x = _g->f_y = 0;
  _g->f_w = SCREENWIDTH*2;           // killough 2/7/98: get rid of finit_ vars
  _g->f_h = SCREENHEIGHT-ST_SCALED_HEIGHT;// to allow runtime setting of width/height

  AM_findMinMaxBoundaries();
  _g->scale_mtof = FixedDiv(_g->min_scale_mtof, (int) (0.7*FRACUNIT));
  if (_g->scale_mtof > _g->max_scale_mtof)
    _g->scale_mtof = _g->min_scale_mtof;
  _g->scale_ftom = FixedDiv(FRACUNIT, _g->scale_mtof);
}

//
// AM_Stop()
//
// Cease automap operations, unload patches, notify status bar
//
// Passed nothing, returns nothing
//
void AM_Stop (void)
{
    static const event_t st_notify = { 0, ev_keyup, AM_MSGEXITED, 0 };

    _g->automapmode  = 0;
    ST_Responder(&st_notify);
    _g->stopped = true;
}

//
// AM_Start()
//
// Start up automap operations,
//  if a new level, or game start, (re)initialize level variables
//  init map variables
//  load mark patches
//
// Passed nothing, returns nothing
//
void AM_Start(void)
{
  if (!_g->stopped)
    AM_Stop();

  _g->stopped = false;
  if (_g->lastlevel != _g->gamemap || _g->lastepisode != _g->gameepisode)
  {
    AM_LevelInit();
    _g->lastlevel = _g->gamemap;
    _g->lastepisode = _g->gameepisode;
  }
  AM_initVariables();
}

//
// AM_minOutWindowScale()
//
// Set the window scale to the maximum size
//
// Passed nothing, returns nothing
//
static void AM_minOutWindowScale(void)
{
  _g->scale_mtof = _g->min_scale_mtof;
  _g->scale_ftom = FixedDiv(FRACUNIT, _g->scale_mtof);
  AM_activateNewScale();
}

//
// AM_maxOutWindowScale(void)
//
// Set the window scale to the minimum size
//
// Passed nothing, returns nothing
//
static void AM_maxOutWindowScale(void)
{
  _g->scale_mtof = _g->max_scale_mtof;
  _g->scale_ftom = FixedDiv(FRACUNIT, _g->scale_mtof);
  AM_activateNewScale();
}

//
// AM_Responder()
//
// Handle events (user inputs) in automap mode
//
// Passed an input event, returns true if its handled
//
boolean AM_Responder
( event_t*  ev )
{
    int rc;
    int ch;                                                       // phares

    rc = false;

    if (!(_g->automapmode & am_active))
    {
        if (ev->type == ev_keydown && ev->data1 == key_map)         // phares
        {
            AM_Start ();
            rc = true;
        }
    }
    else if (ev->type == ev_keydown)
    {
        rc = true;
        ch = ev->data1;                                             // phares

        if (ch == key_map_right)                                    //    |
            if (!(_g->automapmode & am_follow))                           //    V
                _g->m_paninc.x = FTOM(F_PANINC);
            else
                rc = false;
        else if (ch == key_map_left)
            if (!(_g->automapmode & am_follow))
                _g->m_paninc.x = -FTOM(F_PANINC);
            else
                rc = false;
        else if (ch == key_map_up)
            if (!(_g->automapmode & am_follow))
                _g->m_paninc.y = FTOM(F_PANINC);
            else
                rc = false;
        else if (ch == key_map_down)
            if (!(_g->automapmode & am_follow))
                _g->m_paninc.y = -FTOM(F_PANINC);
            else
                rc = false;
        else if (ch == key_map)
        {
            if(_g->automapmode & am_overlay)
                AM_Stop ();
            else
                _g->automapmode |= (am_overlay | am_rotate | am_follow);
        }
        else if (ch == key_map_follow && _g->gamekeydown[key_use])
        {
            _g->automapmode ^= am_follow;     // CPhipps - put all automap mode stuff into one enum
            _g->f_oldloc.x = INT_MAX;
            // Ty 03/27/98 - externalized
            _g->player.message = (_g->automapmode & am_follow) ? AMSTR_FOLLOWON : AMSTR_FOLLOWOFF;
        }                                                         //    |
        else if (ch == key_map_zoomout)
        {
            _g->mtof_zoommul = M_ZOOMOUT;
            _g->ftom_zoommul = M_ZOOMIN;
        }
        else if (ch == key_map_zoomin)
        {
            _g->mtof_zoommul = M_ZOOMIN;
            _g->ftom_zoommul = M_ZOOMOUT;
        }
        else                                                        // phares
        {
            rc = false;
        }
    }
    else if (ev->type == ev_keyup)
    {
        rc = false;
        ch = ev->data1;
        if (ch == key_map_right)
        {
            if (!(_g->automapmode & am_follow))
                _g->m_paninc.x = 0;
        }
        else if (ch == key_map_left)
        {
            if (!(_g->automapmode & am_follow))
                _g->m_paninc.x = 0;
        }
        else if (ch == key_map_up)
        {
            if (!(_g->automapmode & am_follow))
                _g->m_paninc.y = 0;
        }
        else if (ch == key_map_down)
        {
            if (!(_g->automapmode & am_follow))
                _g->m_paninc.y = 0;
        }
        else if ((ch == key_map_zoomout) || (ch == key_map_zoomin))
        {
            _g->mtof_zoommul = FRACUNIT;
            _g->ftom_zoommul = FRACUNIT;
        }
    }
    return rc;
}

//
// AM_rotate()
//
// Rotation in 2D.
// Used to rotate player arrow line character.
//
// Passed the coordinates of a point, and an angle
// Returns the coordinates rotated by the angle
//
// CPhipps - made static & enhanced for automap rotation

static void AM_rotate(fixed_t* x,  fixed_t* y, angle_t a, fixed_t xorig, fixed_t yorig)
{
  fixed_t tmpx;

  //e6y
  xorig>>=FRACTOMAPBITS;
  yorig>>=FRACTOMAPBITS;

  tmpx =
    FixedMul(*x - xorig,finecosine[a>>ANGLETOFINESHIFT])
      - FixedMul(*y - yorig,finesine[a>>ANGLETOFINESHIFT]);

  *y   = yorig +
    FixedMul(*x - xorig,finesine[a>>ANGLETOFINESHIFT])
      + FixedMul(*y - yorig,finecosine[a>>ANGLETOFINESHIFT]);

  *x = tmpx + xorig;
}

//
// AM_changeWindowScale()
//
// Automap zooming
//
// Passed nothing, returns nothing
//
static void AM_changeWindowScale(void)
{
  // Change the scaling multipliers
  _g->scale_mtof = FixedMul(_g->scale_mtof, _g->mtof_zoommul);
  _g->scale_ftom = FixedDiv(FRACUNIT, _g->scale_mtof);

  if (_g->scale_mtof < _g->min_scale_mtof)
    AM_minOutWindowScale();
  else if (_g->scale_mtof > _g->max_scale_mtof)
    AM_maxOutWindowScale();
  else
    AM_activateNewScale();
}

//
// AM_doFollowPlayer()
//
// Turn on follow mode - the map scrolls opposite to player motion
//
// Passed nothing, returns nothing
//
static void AM_doFollowPlayer(void)
{
  if (_g->f_oldloc.x != _g->player.mo->x || _g->f_oldloc.y != _g->player.mo->y)
  {
     _g->m_x = FTOM(MTOF(_g->player.mo->x >> FRACTOMAPBITS)) - _g->m_w/2;//e6y
     _g->m_y = FTOM(MTOF(_g->player.mo->y >> FRACTOMAPBITS)) - _g->m_h/2;//e6y
     _g->m_x2 =  _g->m_x + _g->m_w;
     _g->m_y2 =  _g->m_y + _g->m_h;
    _g->f_oldloc.x = _g->player.mo->x;
    _g->f_oldloc.y = _g->player.mo->y;
  }
}

//
// AM_Ticker()
//
// Updates on gametic - enter follow mode, zoom, or change map location
//
// Passed nothing, returns nothing
//
void AM_Ticker (void)
{
  if (!(_g->automapmode & am_active))
    return;

  if (_g->automapmode & am_follow)
    AM_doFollowPlayer();

  // Change the zoom if necessary
  if (_g->ftom_zoommul != FRACUNIT)
    AM_changeWindowScale();

  // Change x,y location
  if ( _g->m_paninc.x ||  _g->m_paninc.y)
    AM_changeWindowLoc();
}

//
// AM_clipMline()
//
// Automap clipping of lines.
//
// Based on Cohen-Sutherland clipping algorithm but with a slightly
// faster reject and precalculated slopes. If the speed is needed,
// use a hash algorithm to handle the common cases.
//
// Passed the line's coordinates on map and in the frame buffer performs
// clipping on them in the lines frame coordinates.
// Returns true if any part of line was not clipped
//
static boolean AM_clipMline
( mline_t*  ml,
  fline_t*  fl )
{
  enum
  {
    LEFT    =1,
    RIGHT   =2,
    BOTTOM  =4,
    TOP     =8
  };

  register int outcode1 = 0;
  register int outcode2 = 0;
  register int outside;

  fpoint_t  tmp;
  int   dx;
  int   dy;


#define DOOUTCODE(oc, mx, my) \
  (oc) = 0; \
  if ((my) < 0) (oc) |= TOP; \
  else if ((my) >= _g->f_h) (oc) |= BOTTOM; \
  if ((mx) < 0) (oc) |= LEFT; \
  else if ((mx) >= _g->f_w) (oc) |= RIGHT;


  // do trivial rejects and outcodes
  if (ml->a.y >  _g->m_y2)
  outcode1 = TOP;
  else if (ml->a.y <  _g->m_y)
  outcode1 = BOTTOM;

  if (ml->b.y >  _g->m_y2)
  outcode2 = TOP;
  else if (ml->b.y <  _g->m_y)
  outcode2 = BOTTOM;

  if (outcode1 & outcode2)
  return false; // trivially outside

  if (ml->a.x <  _g->m_x)
  outcode1 |= LEFT;
  else if (ml->a.x >  _g->m_x2)
  outcode1 |= RIGHT;

  if (ml->b.x <  _g->m_x)
  outcode2 |= LEFT;
  else if (ml->b.x >  _g->m_x2)
  outcode2 |= RIGHT;

  if (outcode1 & outcode2)
  return false; // trivially outside

  // transform to frame-buffer coordinates.
  fl->a.x = CXMTOF(ml->a.x);
  fl->a.y = CYMTOF(ml->a.y);
  fl->b.x = CXMTOF(ml->b.x);
  fl->b.y = CYMTOF(ml->b.y);

  DOOUTCODE(outcode1, fl->a.x, fl->a.y)
  DOOUTCODE(outcode2, fl->b.x, fl->b.y)

  if (outcode1 & outcode2)
  return false;

  while (outcode1 | outcode2)
  {
    // may be partially inside box
    // find an outside point
    if (outcode1)
      outside = outcode1;
    else
      outside = outcode2;

    // clip to each side
    if (outside & TOP)
    {
      dy = fl->a.y - fl->b.y;
      dx = fl->b.x - fl->a.x;
      tmp.x = fl->a.x + (dx*(fl->a.y))/dy;
      tmp.y = 0;
    }
    else if (outside & BOTTOM)
    {
      dy = fl->a.y - fl->b.y;
      dx = fl->b.x - fl->a.x;
      tmp.x = fl->a.x + (dx*(fl->a.y-_g->f_h))/dy;
      tmp.y = _g->f_h-1;
    }
    else if (outside & RIGHT)
    {
      dy = fl->b.y - fl->a.y;
      dx = fl->b.x - fl->a.x;
      tmp.y = fl->a.y + (dy*(_g->f_w-1 - fl->a.x))/dx;
      tmp.x = _g->f_w-1;
    }
    else if (outside & LEFT)
    {
      dy = fl->b.y - fl->a.y;
      dx = fl->b.x - fl->a.x;
      tmp.y = fl->a.y + (dy*(-fl->a.x))/dx;
      tmp.x = 0;
    }

    if (outside == outcode1)
    {
      fl->a = tmp;
      DOOUTCODE(outcode1, fl->a.x, fl->a.y)
    }
    else
    {
      fl->b = tmp;
      DOOUTCODE(outcode2, fl->b.x, fl->b.y)
    }

    if (outcode1 & outcode2)
      return false; // trivially outside
  }

  return true;
}
#undef DOOUTCODE

//
// AM_drawMline()
//
// Clip lines, draw visible parts of lines.
//
// Passed the map coordinates of the line, and the color to draw it
// Color -1 is special and prevents drawing. Color 247 is special and
// is translated to black, allowing Color 0 to represent feature disable
// in the defaults file.
// Returns nothing.
//
static void AM_drawMline
( mline_t*  ml,
  int   color )
{
  fline_t fl;

  if (color==-1)  // jff 4/3/98 allow not drawing any sort of line
    return;       // by setting its color to -1
  if (color==247) // jff 4/3/98 if color is 247 (xparent), use black
    color=0;

  if (AM_clipMline(ml, &fl))
    V_DrawLine(&fl, color); // draws it on frame buffer using fb coords
}

//
// AM_drawGrid()
//
// Draws blockmap aligned grid lines.
//
// Passed the color to draw the grid lines
// Returns nothing
//
static void AM_drawGrid(int color)
{
  fixed_t x, y;
  fixed_t start, end;
  mline_t ml;

  // Figure out start of vertical gridlines
  start =  _g->m_x;
  if ((start-_g->bmaporgx)%(MAPBLOCKUNITS<<MAPBITS))//e6y
    start += (MAPBLOCKUNITS<<MAPBITS)//e6y
      - ((start-_g->bmaporgx)%(MAPBLOCKUNITS<<MAPBITS));//e6y
  end =  _g->m_x + _g->m_w;

  // draw vertical gridlines
  ml.a.y =  _g->m_y;
  ml.b.y =  _g->m_y+_g->m_h;
  for (x=start; x<end; x+=(MAPBLOCKUNITS<<MAPBITS))//e6y
  {
    ml.a.x = x;
    ml.b.x = x;
    AM_drawMline(&ml, color);
  }

  // Figure out start of horizontal gridlines
  start =  _g->m_y;
  if ((start-_g->bmaporgy)%(MAPBLOCKUNITS<<MAPBITS))//e6y
    start += (MAPBLOCKUNITS<<MAPBITS)//e6y
      - ((start-_g->bmaporgy)%(MAPBLOCKUNITS<<MAPBITS));//e6y
  end =  _g->m_y + _g->m_h;

  // draw horizontal gridlines
  ml.a.x =  _g->m_x;
  ml.b.x =  _g->m_x + _g->m_w;
  for (y=start; y<end; y+=(MAPBLOCKUNITS<<MAPBITS))//e6y
  {
    ml.a.y = y;
    ml.b.y = y;
    AM_drawMline(&ml, color);
  }
}

//
// AM_DoorColor()
//
// Returns the 'color' or key needed for a door linedef type
//
// Passed the type of linedef, returns:
//   -1 if not a keyed door
//    0 if a red key required
//    1 if a blue key required
//    2 if a yellow key required
//    3 if a multiple keys required
//
// jff 4/3/98 add routine to get color of generalized keyed door
//
static int AM_DoorColor(int type)
{
  if (GenLockedBase <= type && type< GenDoorBase)
  {
    type -= GenLockedBase;
    type = (type & LockedKey) >> LockedKeyShift;
    if (!type || type==7)
      return 3;  //any or all keys
    else return (type-1)%3;
  }
  switch (type)  // closed keyed door
  {
    case 26: case 32: case 99: case 133:
      /*bluekey*/
      return 1;
    case 27: case 34: case 136: case 137:
      /*yellowkey*/
      return 2;
    case 28: case 33: case 134: case 135:
      /*redkey*/
      return 0;
    default:
      return -1; //not a keyed door
  }
}

//
// Determines visible lines, draws them.
// This is LineDef based, not LineSeg based.
//
// jff 1/5/98 many changes in this routine
// backward compatibility not needed, so just changes, no ifs
// addition of clauses for:
//    doors opening, keyed door id, secret sectors,
//    teleports, exit lines, key things
// ability to suppress any of added features or lines with no height changes
//
// support for gamma correction in automap abandoned
//
// jff 4/3/98 changed mapcolor_xxxx=0 as control to disable feature
// jff 4/3/98 changed mapcolor_xxxx=-1 to disable drawing line completely
//
static void AM_drawWalls(void)
{
    int i;
    mline_t l;

    // draw the unclipped visible portions of all lines
    for (i=0;i<_g->numlines;i++)
    {
        l.a.x = _g->lines[i].v1.x >> FRACTOMAPBITS;//e6y
        l.a.y = _g->lines[i].v1.y >> FRACTOMAPBITS;//e6y
        l.b.x = _g->lines[i].v2.x >> FRACTOMAPBITS;//e6y
        l.b.y = _g->lines[i].v2.y >> FRACTOMAPBITS;//e6y


        const sector_t* backsector = LN_BACKSECTOR(&_g->lines[i]);
        const sector_t* frontsector = LN_FRONTSECTOR(&_g->lines[i]);

        const unsigned int line_special =  LN_SPECIAL(&_g->lines[i]);

        if (_g->automapmode & am_rotate)
        {
            AM_rotate(&l.a.x, &l.a.y, ANG90-_g->player.mo->angle, _g->player.mo->x, _g->player.mo->y);
            AM_rotate(&l.b.x, &l.b.y, ANG90-_g->player.mo->angle, _g->player.mo->x, _g->player.mo->y);
        }

        // if line has been seen or IDDT has been used
        if (_g->linedata[i].r_flags & ML_MAPPED)
        {
            if (_g->lines[i].flags & ML_DONTDRAW)
                continue;
            {
                /* cph - show keyed doors and lines */
                int amd;
                if ((mapcolor_bdor || mapcolor_ydor || mapcolor_rdor) &&
                        !(_g->lines[i].flags & ML_SECRET) &&    /* non-secret */
                        (amd = AM_DoorColor(line_special)) != -1
                        )
                {
                    {
                        switch (amd) /* closed keyed door */
                        {
                        case 1:
                            /*bluekey*/
                            AM_drawMline(&l,
                                         mapcolor_bdor? mapcolor_bdor : mapcolor_cchg);
                            continue;
                        case 2:
                            /*yellowkey*/
                            AM_drawMline(&l,
                                         mapcolor_ydor? mapcolor_ydor : mapcolor_cchg);
                            continue;
                        case 0:
                            /*redkey*/
                            AM_drawMline(&l,
                                         mapcolor_rdor? mapcolor_rdor : mapcolor_cchg);
                            continue;
                        case 3:
                            /*any or all*/
                            AM_drawMline(&l,
                                         mapcolor_clsd? mapcolor_clsd : mapcolor_cchg);
                            continue;
                        }
                    }
                }
            }
            if /* jff 4/23/98 add exit lines to automap */
            (
            mapcolor_exit &&
                    (
                        line_special==11 ||
                        line_special==52 ||
                        line_special==197 ||
                        line_special==51  ||
                        line_special==124 ||
                        line_special==198
                        )
                    ) {
                AM_drawMline(&l, mapcolor_exit); /* exit line */
                continue;
            }

            if(!backsector)
            {
                // jff 1/10/98 add new color for 1S secret sector boundary
                if (mapcolor_secr && //jff 4/3/98 0 is disable
                        (
                            (
                                map_secret_after &&
                                P_WasSecret(frontsector) &&
                                !P_IsSecret(frontsector)
                                )
                            ||
                            (
                                !map_secret_after &&
                                P_WasSecret(frontsector)
                                )
                            )
                        )
                    AM_drawMline(&l, mapcolor_secr); // line bounding secret sector
                else                               //jff 2/16/98 fixed bug
                    AM_drawMline(&l, mapcolor_wall); // special was cleared
            }
            else /* now for 2S lines */
            {
                // jff 1/10/98 add color change for all teleporter types
                if
                        (
                         mapcolor_tele && !(_g->lines[i].flags & ML_SECRET) &&
                         (line_special == 39 || line_special == 97 ||
                          line_special == 125 || line_special == 126)
                         )
                { // teleporters
                    AM_drawMline(&l, mapcolor_tele);
                }
                else if (_g->lines[i].flags & ML_SECRET)    // secret door
                {
                    AM_drawMline(&l, mapcolor_wall);      // wall color
                }
                else if
                        (
                         mapcolor_clsd &&
                         !(_g->lines[i].flags & ML_SECRET) &&    // non-secret closed door
                         ((backsector->floorheight==backsector->ceilingheight) ||
                          (frontsector->floorheight==frontsector->ceilingheight))
                         )
                {
                    AM_drawMline(&l, mapcolor_clsd);      // non-secret closed door
                } //jff 1/6/98 show secret sector 2S lines
                else if
                        (
                         mapcolor_secr && //jff 2/16/98 fixed bug
                         (                    // special was cleared after getting it
                                              (map_secret_after &&
                                               (
                                                   (P_WasSecret(frontsector)
                                                    && !P_IsSecret(frontsector)) ||
                                                   (P_WasSecret(backsector)
                                                    && !P_IsSecret(backsector))
                                                   )
                                               )
                                              ||  //jff 3/9/98 add logic to not show secret til after entered
                                              (   // if map_secret_after is true
                                                  !map_secret_after &&
                                                  (P_WasSecret(frontsector) ||
                                                   P_WasSecret(backsector))
                                                  )
                                              )
                         )
                {
                    AM_drawMline(&l, mapcolor_secr); // line bounding secret sector
                } //jff 1/6/98 end secret sector line change
                else if (backsector->floorheight !=
                         frontsector->floorheight)
                {
                    AM_drawMline(&l, mapcolor_fchg); // floor level change
                }
                else if (backsector->ceilingheight !=
                         frontsector->ceilingheight)
                {
                    AM_drawMline(&l, mapcolor_cchg); // ceiling level change
                }
            }
        } // now draw the lines only visible because the player has computermap
        else if (_g->player.powers[pw_allmap]) // computermap visible lines
        {
            if (!(_g->lines[i].flags & ML_DONTDRAW)) // invisible flag lines do not show
            {
                if
                        (
                         mapcolor_flat
                         ||
                         !backsector
                         ||
                         backsector->floorheight
                         != frontsector->floorheight
                         ||
                         backsector->ceilingheight
                         != frontsector->ceilingheight
                         )
                    AM_drawMline(&l, mapcolor_unsn);
            }
        }
    }
}

//
// AM_drawLineCharacter()
//
// Draws a vector graphic according to numerous parameters
//
// Passed the structure defining the vector graphic shape, the number
// of vectors in it, the scale to draw it at, the angle to draw it at,
// the color to draw it with, and the map coordinates to draw it at.
// Returns nothing
//
static void AM_drawLineCharacter
( const mline_t*  lineguy,
  int   lineguylines,
  fixed_t scale,
  angle_t angle,
  int   color,
  fixed_t x,
  fixed_t y )
{
  int   i;
  mline_t l;

  if (_g->automapmode & am_rotate) angle -= _g->player.mo->angle - ANG90; // cph

  for (i=0;i<lineguylines;i++)
  {
    l.a.x = lineguy[i].a.x;
    l.a.y = lineguy[i].a.y;

    if (scale)
    {
      l.a.x = FixedMul(scale, l.a.x);
      l.a.y = FixedMul(scale, l.a.y);
    }

    if (angle)
      AM_rotate(&l.a.x, &l.a.y, angle, 0, 0);

    l.a.x += x;
    l.a.y += y;

    l.b.x = lineguy[i].b.x;
    l.b.y = lineguy[i].b.y;

    if (scale)
    {
      l.b.x = FixedMul(scale, l.b.x);
      l.b.y = FixedMul(scale, l.b.y);
    }

    if (angle)
      AM_rotate(&l.b.x, &l.b.y, angle, 0, 0);

    l.b.x += x;
    l.b.y += y;

    AM_drawMline(&l, color);
  }
}

//
// AM_drawPlayers()
//
// Draws the player arrow in single player,
//
// Passed nothing, returns nothing
//
static void AM_drawPlayers(void)
{    

        AM_drawLineCharacter
                (
                    player_arrow,
                    NUMPLYRLINES,
                    0,
                    _g->player.mo->angle,
                    mapcolor_sngl,      //jff color
                    _g->player.mo->x >> FRACTOMAPBITS,//e6y
                    _g->player.mo->y >> FRACTOMAPBITS);//e6y

}

//
// AM_Drawer()
//
// Draws the entire automap
//
// Passed nothing, returns nothing
//
void AM_Drawer (void)
{
    // CPhipps - all automap modes put into one enum
    if (!(_g->automapmode & am_active)) return;

    if (!(_g->automapmode & am_overlay)) // cph - If not overlay mode, clear background for the automap
        V_FillRect(_g->f_x, _g->f_y, _g->f_w, _g->f_h, (byte)mapcolor_back); //jff 1/5/98 background default color

    if (_g->automapmode & am_grid)
        AM_drawGrid(mapcolor_grid);      //jff 1/7/98 grid default color
    AM_drawWalls();
    AM_drawPlayers();
}
