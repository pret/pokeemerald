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
 *  Intermission screens.
 *
 *-----------------------------------------------------------------------------
 */

#include "doomstat.h"
#include "m_random.h"
#include "w_wad.h"
#include "g_game.h"
#include "r_main.h"
#include "v_video.h"
#include "wi_stuff.h"
#include "s_sound.h"
#include "sounds.h"
#include "lprintf.h"  // jff 08/03/98 - declaration of lprintf
#include "r_draw.h"

#include "global_data.h"

//
// Data needed to add patches to full screen intermission pics.
// Patches are statistics messages, and animations.
// Loads of by-pixel layout and placement, offsets etc.
//

//
// Different vetween registered DOOM (1994) and
//  Ultimate DOOM - Final edition (retail, 1995?).
// This is supposedly ignored for commercial
//  release (aka DOOM II), which had 34 maps
//  in one episode. So there.
#define NUMEPISODES 4
#define NUMMAPS     9


// Not used
// in tics
//U #define PAUSELEN    (TICRATE*2)
//U #define SCORESTEP    100
//U #define ANIMPERIOD    32
// pixel distance from "(YOU)" to "PLAYER N"
//U #define STARDIST  10
//U #define WK 1


// GLOBAL LOCATIONS
#define WI_TITLEY      2
#define WI_SPACINGY   33

// SINGLE-PLAYER STUFF
#define SP_STATSX     50
#define SP_STATSY     50

#define SP_TIMEX      8
// proff/nicolas 09/20/98 -- changed for hi-res
#define SP_TIMEY      160
//#define SP_TIMEY      (SCREENHEIGHT-32)


// NET GAME STUFF
#define NG_STATSY     50
#define NG_STATSX     (32 + V_NamePatchWidth(star)/2 + 32*!dofrags)

#define NG_SPACINGX   64


// Used to display the frags matrix at endgame
// DEATHMATCH STUFF
#define DM_MATRIXX    42
#define DM_MATRIXY    68

#define DM_SPACINGX   40

#define DM_TOTALSX   269

#define DM_KILLERSX   10
#define DM_KILLERSY  100
#define DM_VICTIMSX    5
#define DM_VICTIMSY   50

typedef struct
{
  int   x;       // x/y coordinate pair structure
  int   y;
} point_t;

static const point_t lnodes[NUMEPISODES][NUMMAPS] =
{
  // Episode 0 World Map
  {
    { 185, 164 }, // location of level 0 (CJ)
    { 148, 143 }, // location of level 1 (CJ)
    { 69, 122 },  // location of level 2 (CJ)
    { 209, 102 }, // location of level 3 (CJ)
    { 116, 89 },  // location of level 4 (CJ)
    { 166, 55 },  // location of level 5 (CJ)
    { 71, 56 },   // location of level 6 (CJ)
    { 135, 29 },  // location of level 7 (CJ)
    { 71, 24 }    // location of level 8 (CJ)
  },

  // Episode 1 World Map should go here
  {
    { 254, 25 },  // location of level 0 (CJ)
    { 97, 50 },   // location of level 1 (CJ)
    { 188, 64 },  // location of level 2 (CJ)
    { 128, 78 },  // location of level 3 (CJ)
    { 214, 92 },  // location of level 4 (CJ)
    { 133, 130 }, // location of level 5 (CJ)
    { 208, 136 }, // location of level 6 (CJ)
    { 148, 140 }, // location of level 7 (CJ)
    { 235, 158 }  // location of level 8 (CJ)
  },

  // Episode 2 World Map should go here
  {
    { 156, 168 }, // location of level 0 (CJ)
    { 48, 154 },  // location of level 1 (CJ)
    { 174, 95 },  // location of level 2 (CJ)
    { 265, 75 },  // location of level 3 (CJ)
    { 130, 48 },  // location of level 4 (CJ)
    { 279, 23 },  // location of level 5 (CJ)
    { 198, 48 },  // location of level 6 (CJ)
    { 140, 25 },  // location of level 7 (CJ)
    { 281, 136 }  // location of level 8 (CJ)
  }
};




//
// GENERAL DATA
//

//
// Locally used stuff.
//
#define FB 0


// States for single-player
#define SP_KILLS    0
#define SP_ITEMS    2
#define SP_SECRET   4
#define SP_FRAGS    6
#define SP_TIME     8
#define SP_PAR      ST_TIME

#define SP_PAUSE    1

// in seconds
#define SHOWNEXTLOCDELAY  4
//#define SHOWLASTLOCDELAY  SHOWNEXTLOCDELAY

//
//  GRAPHICS
//

// You Are Here graphic
static const char* const yah[2] = { "WIURH0", "WIURH1" };

// splat
static const char* const splat = "WISPLAT";

// %, : graphics
static const char percent[] = {"WIPCNT"};
static const char colon[] = {"WICOLON"};



// minus sign
static const char wiminus[] = {"WIMINUS"};

// "Finished!" graphics
static const char finished[] = {"WIF"};

// "Entering" graphic
static const char entering[] = {"WIENTER"};

// "secret"
static const char sp_secret[] = {"WISCRT2"};

// "Kills", "Scrt", "Items", "Frags"
static const char kills[] = {"WIOSTK"};
static const char items[] = {"WIOSTI"};

// Time sucks.
static const char time1[] = {"WITIME"};
static const char par[] = {"WIPAR"};
static const char sucks[] = {"WISUCKS"};

// "Total", your face, your dead face
static const char total[] = {"WIMSTT"};


//
// CODE
//

static void WI_endNetgameStats(void);
#define WI_endStats WI_endNetgameStats


// ====================================================================
// CPhipps - WI_endNetgameStats
// Purpose: Clean up coop game stats
// Args:    none
// Returns: void
//
static void WI_endNetgameStats(void)
{
    _g->cnt_kills = -1;
    _g->cnt_secret = -1;
    _g->cnt_items = -1;
}


/* ====================================================================
 * WI_levelNameLump
 * Purpore: Returns the name of the graphic lump containing the name of
 *          the given level.
 * Args:    Episode and level, and buffer (must by 9 chars) to write to
 * Returns: void
 */
void WI_levelNameLump(int epis, int map, char* buf)
{
  if (_g->gamemode == commercial)
  {
    sprintf(buf, "CWILV%2.2d", map);
  }
  else
  {
    sprintf(buf, "WILV%d%d", epis, map);
  }
}

// ====================================================================
// WI_slamBackground
// Purpose: Put the full-screen background up prior to patches
// Args:    none
// Returns: void
//
static void WI_slamBackground(void)
{
  char  name[9];  // limited to 8 characters

  if (_g->gamemode == commercial || (_g->gamemode == retail && _g->wbs->epsd == 3))
    strcpy(name, "INTERPIC");
  else
    sprintf(name, "WIMAP%d", _g->wbs->epsd);

  // background
  V_DrawNamePatch(0, 0, FB, name, CR_DEFAULT, VPT_STRETCH);
}


// ====================================================================
// WI_Responder
// Purpose: Draw animations on intermission background screen
// Args:    ev    -- event pointer, not actually used here.
// Returns: False -- dummy routine
//
// The ticker is used to detect keys
//  because of timing issues in netgames.
boolean WI_Responder(event_t* ev)
{
  return false;
}


// ====================================================================
// WI_drawLF
// Purpose: Draw the "Finished" level name before showing stats
// Args:    none
// Returns: void
//
void WI_drawLF(void)
{
  int y = WI_TITLEY;
  char lname[9];

  // draw <LevelName>
  /* cph - get the graphic lump name and use it */
  WI_levelNameLump(_g->wbs->epsd, _g->wbs->last, lname);
  // CPhipps - patch drawing updated
  V_DrawNamePatch((320 - V_NamePatchWidth(lname))/2, y,
     FB, lname, CR_DEFAULT, VPT_STRETCH);

  // draw "Finished!"
  y += (5*V_NamePatchHeight(lname))/4;

  // CPhipps - patch drawing updated
  V_DrawNamePatch((320 - V_NamePatchWidth(finished))/2, y,
     FB, finished, CR_DEFAULT, VPT_STRETCH);
}


// ====================================================================
// WI_drawEL
// Purpose: Draw introductory "Entering" and level name
// Args:    none
// Returns: void
//
void WI_drawEL(void)
{
  int y = WI_TITLEY;
  char lname[9];

  /* cph - get the graphic lump name */
  WI_levelNameLump(_g->wbs->epsd, _g->wbs->next, lname);

  // draw "Entering"
  // CPhipps - patch drawing updated
  V_DrawNamePatch((320 - V_NamePatchWidth(entering))/2,
      y, FB, entering, CR_DEFAULT, VPT_STRETCH);

  // draw level
  y += (5*V_NamePatchHeight(lname))/4;

  // CPhipps - patch drawing updated
  V_DrawNamePatch((320 - V_NamePatchWidth(lname))/2, y, FB,
     lname, CR_DEFAULT, VPT_STRETCH);
}


/* ====================================================================
 * WI_drawOnLnode
 * Purpose: Draw patches at a location based on episode/map
 * Args:    n   -- index to map# within episode
 *          c[] -- array of names of patches to be drawn
 * Returns: void
 */
void
WI_drawOnLnode  // draw stuff at a location by episode/map#
( int   n,
  const char* const c[] )
{
  int   i;
  boolean fits = false;

  i = 0;
  do
  {
    int            left;
    int            top;
    int            right;
    int            bottom;
    const patch_t* patch = W_CacheLumpName(c[i]);

    left = lnodes[_g->wbs->epsd][n].x - patch->leftoffset;
    top = lnodes[_g->wbs->epsd][n].y - patch->topoffset;
    right = left + patch->width;
    bottom = top + patch->height;

    if (left >= 0
       && right < 320
       && top >= 0
       && bottom < 200)
    {
      fits = true;
    }
    else
    {
      i++;
    }
  } while (!fits && i!=2);

  if (fits && i<2)
  {
    // CPhipps - patch drawing updated
    V_DrawNamePatch(lnodes[_g->wbs->epsd][n].x, lnodes[_g->wbs->epsd][n].y,
       FB, c[i], CR_DEFAULT, VPT_STRETCH);
  }
  else
  {
    // DEBUG
    //jff 8/3/98 use logical output routine
    lprintf(LO_DEBUG,"Could not place patch on level %d", n+1);
  }
}


// ====================================================================
// WI_initAnimatedBack
// Purpose: Initialize pointers and styles for background animation
// Args:    none
// Returns: void
//
void WI_initAnimatedBack(void)
{

}


// ====================================================================
// WI_updateAnimatedBack
// Purpose: Figure out what animation we do on this iteration
// Args:    none
// Returns: void
//
void WI_updateAnimatedBack(void)
{

}


// ====================================================================
// WI_drawAnimatedBack
// Purpose: Actually do the animation (whew!)
// Args:    none
// Returns: void
//
void WI_drawAnimatedBack(void)
{

}


// ====================================================================
// WI_drawNum
// Purpose: Draws a number.  If digits > 0, then use that many digits
//          minimum, otherwise only use as many as necessary
// Args:    x, y   -- location
//          n      -- the number to be drawn
//          digits -- number of digits minimum or zero
// Returns: new x position after drawing (note we are going to the left)
// CPhipps - static
static int WI_drawNum (int x, int y, int n, int digits)
{
  int   fontwidth = _g->num[0]->width;
  int   neg;
  int   temp;

  if (digits < 0)
  {
    if (!n)
    {
      // make variable-length zeros 1 digit long
      digits = 1;
    }
    else
    {
      // figure out # of digits in #
      digits = 0;
      temp = n;

      while (temp)
      {
        temp /= 10;
        digits++;
      }
    }
  }

  neg = n < 0;
  if (neg)
    n = -n;

  // if non-number, do not draw it
  if (n == 1994)
    return 0;

  // draw the new number
  while (digits--)
  {
    x -= fontwidth;
    // CPhipps - patch drawing updated
    V_DrawPatch(x, y, FB, _g->num[ n % 10 ]);
    n /= 10;
  }

  // draw a minus sign if necessary
  if (neg)
    // CPhipps - patch drawing updated
    V_DrawNamePatch(x-=8, y, FB, wiminus, CR_DEFAULT, VPT_STRETCH);

  return x;
}


// ====================================================================
// WI_drawPercent
// Purpose: Draws a percentage, really just a call to WI_drawNum
//          after putting a percent sign out there
// Args:    x, y   -- location
//          p      -- the percentage value to be drawn, no negatives
// Returns: void
// CPhipps - static
static void WI_drawPercent(int x, int y, int p)
{
  if (p < 0)
    return;

  // CPhipps - patch drawing updated
  V_DrawNamePatch(x, y, FB, percent, CR_DEFAULT, VPT_STRETCH);
  WI_drawNum(x, y, p, -1);
}


// ====================================================================
// WI_drawTime
// Purpose: Draws the level completion time or par time, or "Sucks"
//          if 1 hour or more
// Args:    x, y   -- location
//          t      -- the time value to be drawn
// Returns: void
//
// CPhipps - static
//         - largely rewritten to display hours and use slightly better algorithm

static void WI_drawTime(int x, int y, int t)
{
  int   n;

  if (t<0)
    return;

  if (t < 100*60*60)
    for(;;) {
      n = t % 60;
      t /= 60;
      x = WI_drawNum(x, y, n, (t || n>9) ? 2 : 1) - V_NamePatchWidth(colon);

      // draw
      if (t)
  // CPhipps - patch drawing updated
        V_DrawNamePatch(x, y, FB, colon, CR_DEFAULT, VPT_STRETCH);
      else break;
    }
  else // "sucks" (maybe should be "addicted", even I've never had a 100 hour game ;)
    V_DrawNamePatch(x - V_NamePatchWidth(sucks),
        y, FB, sucks, CR_DEFAULT, VPT_STRETCH);
}


// ====================================================================
// WI_End
// Purpose: Unloads data structures (inverse of WI_Start)
// Args:    none
// Returns: void
//
void WI_End(void)
{
    WI_endStats();
}


// ====================================================================
// WI_initNoState
// Purpose: Clear state, ready for end of level activity
// Args:    none
// Returns: void
//
void WI_initNoState(void)
{
  _g->state = NoState;
  _g->acceleratestage = 0;
  _g->cnt = 10;
}


// ====================================================================
// WI_drawTimeStats
// Purpose: Put the times on the screen
// Args:    time, total time, par time, in seconds
// Returns: void
//
// cph - pulled from WI_drawStats below

static void WI_drawTimeStats(int cnt_time, int cnt_total_time, int cnt_par)
{
  V_DrawNamePatch(SP_TIMEX, SP_TIMEY, FB, time1, CR_DEFAULT, VPT_STRETCH);
  WI_drawTime(320/2 - SP_TIMEX, SP_TIMEY, cnt_time);

  V_DrawNamePatch(SP_TIMEX, (SP_TIMEY+200)/2, FB, total, CR_DEFAULT, VPT_STRETCH);
  WI_drawTime(320/2 - SP_TIMEX, (SP_TIMEY+200)/2, cnt_total_time);

  // Ty 04/11/98: redid logic: should skip only if with pwad but
  // without deh patch
  // killough 2/22/98: skip drawing par times on pwads
  // Ty 03/17/98: unless pars changed with deh patch

    if (_g->wbs->epsd < 3)
    {
      V_DrawNamePatch(320/2 + SP_TIMEX, SP_TIMEY, FB, par, CR_DEFAULT, VPT_STRETCH);
      WI_drawTime(320 - SP_TIMEX, SP_TIMEY, cnt_par);
    }

}

// ====================================================================
// WI_updateNoState
// Purpose: Cycle until end of level activity is done
// Args:    none
// Returns: void
//
void WI_updateNoState(void)
{

  WI_updateAnimatedBack();

  if (!--_g->cnt)
    G_WorldDone();
}

// ====================================================================
// WI_initShowNextLoc
// Purpose: Prepare to show the next level's location
// Args:    none
// Returns: void
//
void WI_initShowNextLoc(void)
{
  if ((_g->gamemode != commercial) && (_g->gamemap == 8)) {
    G_WorldDone();
    return;
  }

  _g->state = ShowNextLoc;
  _g->acceleratestage = 0;
  
  // e6y: That was pretty easy - only a HEX editor and luck
  // There is no more desync on ddt-tas.zip\e4tux231.lmp
  // --------- tasdoom.idb ---------
  // .text:00031194 loc_31194:      ; CODE XREF: WI_updateStats+3A9j
  // .text:00031194                 mov     ds:state, 1
  // .text:0003119E                 mov     ds:acceleratestage, 0
  // .text:000311A8                 mov     ds:cnt, 3Ch
  // nowhere no hide
    _g->cnt = SHOWNEXTLOCDELAY * TICRATE;

  WI_initAnimatedBack();
}


// ====================================================================
// WI_updateShowNextLoc
// Purpose: Prepare to show the next level's location
// Args:    none
// Returns: void
//
void WI_updateShowNextLoc(void)
{
  WI_updateAnimatedBack();

  if (!--_g->cnt || _g->acceleratestage)
    WI_initNoState();
  else
    _g->snl_pointeron = (_g->cnt & 31) < 20;
}


// ====================================================================
// WI_drawShowNextLoc
// Purpose: Show the next level's location on animated backgrounds
// Args:    none
// Returns: void
//
void WI_drawShowNextLoc(void)
{
    int   i;
    int   last;

    WI_slamBackground();

    // draw animated background
    WI_drawAnimatedBack();

    if ( _g->gamemode != commercial)
    {
        if (_g->wbs->epsd > 2)
        {
            WI_drawEL();  // "Entering..." if not E1 or E2
            return;
        }

        last = (_g->wbs->last == 8) ? _g->wbs->next - 1 : _g->wbs->last;

        // draw a splat on taken cities.
        for (i=0 ; i<=last ; i++)
            WI_drawOnLnode(i, &splat);

        // splat the secret level?
        if (_g->wbs->didsecret)
            WI_drawOnLnode(8, &splat);

        // draw flashing ptr
        if (_g->snl_pointeron)
            WI_drawOnLnode(_g->wbs->next, yah);
    }

    // draws which level you are entering..
    if ( (_g->gamemode != commercial)
         || _g->wbs->next != 30)  // check for MAP30 end game
        WI_drawEL();
}

// ====================================================================
// WI_drawNoState
// Purpose: Draw the pointer and next location
// Args:    none
// Returns: void
//
void WI_drawNoState(void)
{
  _g->snl_pointeron = true;
  WI_drawShowNextLoc();
}

// ====================================================================
// WI_fragSum
// Purpose: Calculate frags for this player based on the current totals
//          of all the other players.  Subtract self-frags.
// Args:    playernum -- the player to be calculated
// Returns: the total frags for this player
//
int WI_fragSum(int playernum)
{
  int   i;
  int   frags = 0;

  // JDC hack - negative frags.
  frags -= _g->plrs[playernum].frags[playernum];

  return frags;
}



// ====================================================================
// WI_initStats
// Purpose: Get ready for single player stats
// Args:    none
// Returns: void
// Comment: Seems like we could do all these stats in a more generic
//          set of routines that weren't duplicated for dm, coop, sp
//



void WI_initStats(void)
{
  _g->state = StatCount;
  _g->acceleratestage = 0;
  _g->sp_state = 1;

  _g->cnt_kills = -1;
  _g->cnt_secret = -1;
  _g->cnt_items = -1;

  _g->cnt_time = _g->cnt_par = _g->cnt_total_time = -1;
  _g->cnt_pause = TICRATE;

  WI_initAnimatedBack();
}

// ====================================================================
// WI_updateStats
// Purpose: Calculate solo stats
// Args:    none
// Returns: void
//
void WI_updateStats(void)
{
  WI_updateAnimatedBack();

  if (_g->acceleratestage && _g->sp_state != 10)
  {
    _g->acceleratestage = 0;
    _g->cnt_kills = (_g->plrs[_g->me].skills * 100) / _g->wbs->maxkills;
    _g->cnt_items = (_g->plrs[_g->me].sitems * 100) / _g->wbs->maxitems;

    // killough 2/22/98: Make secrets = 100% if maxsecret = 0:
    _g->cnt_secret = (_g->wbs->maxsecret ?
      (_g->plrs[_g->me].ssecret * 100) / _g->wbs->maxsecret : 100);

    _g->cnt_total_time = _g->wbs->totaltimes / TICRATE;
    _g->cnt_time = _g->plrs[_g->me].stime / TICRATE;
    _g->cnt_par = _g->wbs->partime / TICRATE;
    S_StartSound(0, sfx_barexp);
    _g->sp_state = 10;
  }

  if (_g->sp_state == 2)
  {
    _g->cnt_kills += 2;

    if (!(_g->bcnt&3))
      S_StartSound(0, sfx_pistol);

    if (_g->cnt_kills >= (_g->plrs[_g->me].skills * 100) / _g->wbs->maxkills)
    {
      _g->cnt_kills = (_g->plrs[_g->me].skills * 100) / _g->wbs->maxkills;
      S_StartSound(0, sfx_barexp);
      _g->sp_state++;
    }
  }
  else if (_g->sp_state == 4)
  {
    _g->cnt_items += 2;

    if (!(_g->bcnt&3))
      S_StartSound(0, sfx_pistol);

    if (_g->cnt_items >= (_g->plrs[_g->me].sitems * 100) / _g->wbs->maxitems)
    {
      _g->cnt_items = (_g->plrs[_g->me].sitems * 100) / _g->wbs->maxitems;
      S_StartSound(0, sfx_barexp);
      _g->sp_state++;
    }
  }
  else if (_g->sp_state == 6)
  {
    _g->cnt_secret += 2;

    if (!(_g->bcnt&3))
      S_StartSound(0, sfx_pistol);

    // killough 2/22/98: Make secrets = 100% if maxsecret = 0:
    if (_g->cnt_secret >= (_g->wbs->maxsecret ? (_g->plrs[_g->me].ssecret * 100) / _g->wbs->maxsecret : 100))
    {
      _g->cnt_secret = (_g->wbs->maxsecret ?
        (_g->plrs[_g->me].ssecret * 100) / _g->wbs->maxsecret : 100);
      S_StartSound(0, sfx_barexp);
      _g->sp_state++;
    }
  }
  else if (_g->sp_state == 8)
  {
    if (!(_g->bcnt&3))
      S_StartSound(0, sfx_pistol);

    _g->cnt_time += 3;

    if (_g->cnt_time >= _g->plrs[_g->me].stime / TICRATE)
      _g->cnt_time = _g->plrs[_g->me].stime / TICRATE;

    _g->cnt_total_time += 3;

    if (_g->cnt_total_time >= _g->wbs->totaltimes / TICRATE)
      _g->cnt_total_time = _g->wbs->totaltimes / TICRATE;

    _g->cnt_par += 3;

    if (_g->cnt_par >= _g->wbs->partime / TICRATE)
    {
      _g->cnt_par = _g->wbs->partime / TICRATE;

      if ((_g->cnt_time >= _g->plrs[_g->me].stime / TICRATE) && (_g->cnt_total_time >= _g->wbs->totaltimes / TICRATE))
      {
        S_StartSound(0, sfx_barexp);
        _g->sp_state++;
      }
    }
  }
  else if (_g->sp_state == 10)
  {
    if (_g->acceleratestage)
    {
      S_StartSound(0, sfx_sgcock);

      if (_g->gamemode == commercial)
        WI_initNoState();
      else
        WI_initShowNextLoc();
    }
  }
  else if (_g->sp_state & 1)
  {
    if (!--_g->cnt_pause)
    {
      _g->sp_state++;
      _g->cnt_pause = TICRATE;
    }
  }
}

// ====================================================================
// WI_drawStats
// Purpose: Put the solo stats on the screen
// Args:    none
// Returns: void
//
// proff/nicolas 09/20/98 -- changed for hi-res
// CPhipps - patch drawing updated
void WI_drawStats(void)
{
  // line height
  int lh;

  lh = (3*_g->num[0]->height)/2;

  WI_slamBackground();

  // draw animated background
  WI_drawAnimatedBack();

  WI_drawLF();

  V_DrawNamePatch(SP_STATSX, SP_STATSY, FB, kills, CR_DEFAULT, VPT_STRETCH);
  if (_g->cnt_kills)
    WI_drawPercent(320 - SP_STATSX, SP_STATSY, _g->cnt_kills);

  V_DrawNamePatch(SP_STATSX, SP_STATSY+lh, FB, items, CR_DEFAULT, VPT_STRETCH);
  if (_g->cnt_items)
    WI_drawPercent(320 - SP_STATSX, SP_STATSY+lh, _g->cnt_items);

  V_DrawNamePatch(SP_STATSX, SP_STATSY+2*lh, FB, sp_secret, CR_DEFAULT, VPT_STRETCH);
  if (_g->cnt_secret)
    WI_drawPercent(320 - SP_STATSX, SP_STATSY+2*lh, _g->cnt_secret);

  WI_drawTimeStats(_g->cnt_time, _g->cnt_total_time, _g->cnt_par);
}

// ====================================================================
// WI_checkForAccelerate
// Purpose: See if the player has hit either the attack or use key
//          or mouse button.  If so we set acceleratestage to 1 and
//          all those display routines above jump right to the end.
// Args:    none
// Returns: void
//
void WI_checkForAccelerate(void)
{
  int   i;
  player_t  *player = &_g->player;

    if (_g->playeringame)
    {
      if (player->cmd.buttons & BT_ATTACK)
      {
        if (!player->attackdown)
          _g->acceleratestage = 1;
        player->attackdown = true;
      }
      else
        player->attackdown = false;

      if (player->cmd.buttons & BT_USE)
      {
        if (!player->usedown)
          _g->acceleratestage = 1;
        player->usedown = true;
      }
      else
        player->usedown = false;
    }
}

// ====================================================================
// WI_Ticker
// Purpose: Do various updates every gametic, for stats, animation,
//          checking that intermission music is running, etc.
// Args:    none
// Returns: void
//
void WI_Ticker(void)
{
  // counter for general background animation
  _g->bcnt++;

  if (_g->bcnt == 1)
  {
    // intermission music
    if ( _g->gamemode == commercial )
      S_ChangeMusic(mus_dm2int, true);
    else
      S_ChangeMusic(mus_inter, true);
  }

  WI_checkForAccelerate();

  switch (_g->state)
  {
    case StatCount:
         WI_updateStats();
         break;

    case ShowNextLoc:
         WI_updateShowNextLoc();
         break;

    case NoState:
         WI_updateNoState();
         break;
  }
}

/* ====================================================================
 * WI_loadData
 * Purpose: Initialize intermission data such as background graphics,
 *          patches, map names, etc.
 * Args:    none
 * Returns: void
 *
 * CPhipps - modified for new wad lump handling.
 *         - no longer preload most graphics, other funcs can use
 *           them by name
 */

void WI_loadData(void)
{
  int   i;
  char  name[9];  // limited to 8 characters



  for (i=0;i<10;i++)
  {
    // numbers 0-9
    sprintf(name, "WINUM%d", i);

    _g->num[i] = W_CacheLumpName(name);
  }
}


// ====================================================================
// WI_Drawer
// Purpose: Call the appropriate stats drawing routine depending on
//          what kind of game is being played (DM, coop, solo)
// Args:    none
// Returns: void
//
void WI_Drawer (void)
{
  switch (_g->state)
  {
    case StatCount:
           WI_drawStats();
         break;

    case ShowNextLoc:
         WI_drawShowNextLoc();
         break;

    case NoState:
         WI_drawNoState();
         break;
  }
}


// ====================================================================
// WI_initVariables
// Purpose: Initialize the intermission information structure
//          Note: wbstartstruct_t is defined in d_player.h
// Args:    wbstartstruct -- pointer to the structure with the data
// Returns: void
//
void WI_initVariables(wbstartstruct_t* wbstartstruct)
{

  _g->wbs = wbstartstruct;

  _g->acceleratestage = 0;
  _g->cnt = _g->bcnt = 0;
  _g->me = _g->wbs->pnum;
  _g->plrs = _g->wbs->plyr;

  if (!_g->wbs->maxkills)
    _g->wbs->maxkills = 1;  // probably only useful in MAP30

  if (!_g->wbs->maxitems)
    _g->wbs->maxitems = 1;

  if ( _g->gamemode != retail )
    if (_g->wbs->epsd > 2)
      _g->wbs->epsd -= 3;
}

// ====================================================================
// WI_Start
// Purpose: Call the various init routines
//          Note: wbstartstruct_t is defined in d_player.h
// Args:    wbstartstruct -- pointer to the structure with the
//          intermission data
// Returns: void
//
void WI_Start(wbstartstruct_t* wbstartstruct)
{
  WI_initVariables(wbstartstruct);
  WI_loadData();

    WI_initStats();
}
