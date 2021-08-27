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
 *  Event information structures.
 *
 *-----------------------------------------------------------------------------*/


#ifndef __D_EVENT__
#define __D_EVENT__


#include "doomtype.h"


//
// Event handling.
//

// Input event types.
typedef enum
{
  ev_keydown,
  ev_keyup,
  ev_mouse,
  ev_joystick
} evtype_t;

// Event structure.
typedef struct
{
  evtype_t  type;
  int       data1;    // keys / mouse/joystick buttons
  int       data2;    // mouse/joystick x move
  int       data3;    // mouse/joystick y move
} event_t;


typedef enum
{
  ga_nothing,
  ga_loadlevel,
  ga_newgame,
  ga_loadgame,
  ga_savegame,
  ga_playdemo,
  ga_completed,
  ga_victory,
  ga_worlddone,
} gameaction_t;



//
// Button/action code definitions.
//
typedef enum
{
  // Press "Fire".
  BT_ATTACK       = 1,

  // Use button, to open doors, activate switches.
  BT_USE          = 2,

  // Flag: game events, not really buttons.
  BT_SPECIAL      = 128,
  BT_SPECIALMASK  = 3,

  // Flag, weapon change pending.
  // If true, the next 4 bits hold weapon num.
  BT_CHANGE       = 4,

  // The 4bit weapon mask and shift, convenience.
//BT_WEAPONMASK   = (8+16+32),
  BT_WEAPONMASK   = (8+16+32+64), // extended to pick up SSG        // phares
  BT_WEAPONSHIFT  = 3,

  // Special events
  BTS_LOADGAME    = 0, // Loads a game
  // Pause the game.
  BTS_PAUSE       = 1,
  // Save the game at each console.
  BTS_SAVEGAME    = 2,
  BTS_RESTARTLEVEL= 3, // Restarts the current level

  // Savegame slot numbers occupy the second byte of buttons.
  BTS_SAVEMASK    = (4+8+16),
  BTS_SAVESHIFT   = 2,

} buttoncode_t;


#endif
