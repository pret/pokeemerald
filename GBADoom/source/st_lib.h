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
 *  The status bar widget definitions and prototypes
 *
 *-----------------------------------------------------------------------------*/

#ifndef __STLIB__
#define __STLIB__

// We are referring to patches.
#include "r_defs.h"
#include "v_video.h"  // color ranges

//
// Background and foreground screen numbers
//
#define ST_BG 1
#define ST_FG 0

//
// Typedefs of widgets
//

// Number widget

typedef struct
{
  // upper right-hand corner
  //  of the number (right-justified)
  int   x;
  int   y;

  // max # of digits in number
  int width;

  // last number value
  int   oldnum;

  // pointer to current value
  int*  num;

  // pointer to boolean stating
  //  whether to update number
  boolean*  on;

  // list of patches for 0-9
  const patch_t** p;

} st_number_t;

// Percent widget ("child" of number widget,
//  or, more precisely, contains a number widget.)
typedef struct
{
  // number information
  st_number_t   n;

  // percent sign graphic
  const patch_t*    p;
} st_percent_t;

// Multiple Icon widget
typedef struct
{
  // center-justified location of icons
  int     x;
  int     y;

  // last icon number
  int     oldinum;

  // pointer to current icon
  int*    inum;

  // pointer to boolean stating
  //  whether to update icon
  boolean*    on;

  // list of icons
  const patch_t**   p;

} st_multicon_t;

// Binary Icon widget

typedef struct
{
  // center-justified location of icon
  int     x;
  int     y;

  // last icon value
  boolean oldval;

  // pointer to current icon status
  boolean*    val;

  // pointer to boolean
  //  stating whether to update icon
  boolean*    on;

  const patch_t*    p;  // icon
  int     data;   // user data
} st_binicon_t;

//
// Widget creation, access, and update routines
//

// Initializes widget library.
// More precisely, initialize STMINUS,
//  everything else is done somewhere else.
//
void STlib_init(void);

// Number widget routines
void STlib_initNum
(st_number_t* n,
  int x,
  int y,
  const patch_t **pl,
  int* num,
  boolean* on,
  int width );

void STlib_updateNum
( st_number_t* n,
  int cm,
  boolean refresh );


// Percent widget routines
void STlib_initPercent
( st_percent_t* p,
  int x,
  int y,
  const patch_t** pl,
  int* num,
  boolean* on,
  const patch_t* percent );


void STlib_updatePercent
( st_percent_t* per,
  int cm,
  int refresh );


// Multiple Icon widget routines
void STlib_initMultIcon
( st_multicon_t* mi,
  int x,
  int y,
  const patch_t**   il,
  int* inum,
  boolean* on );


void STlib_updateMultIcon
( st_multicon_t* mi,
  boolean refresh );

// Binary Icon widget routines

void STlib_initBinIcon
( st_binicon_t* b,
  int x,
  int y,
  const patch_t* i,
  boolean* val,
  boolean* on );

void STlib_updateBinIcon
( st_binicon_t* bi,
  boolean refresh );

void ST_refreshBackground(void);


#endif
