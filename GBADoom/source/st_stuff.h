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
 *      Status bar code.
 *      Does the face/direction indicator animatin.
 *      Does palette indicators as well (red pain/berserk, bright pickup)
 *
 *-----------------------------------------------------------------------------*/

#ifndef __STSTUFF_H__
#define __STSTUFF_H__

#include "doomtype.h"
#include "d_event.h"

// Size of statusbar.
// Now sensitive for scaling.

// proff 08/18/98: Changed for high-res
#define ST_HEIGHT 32
#define ST_WIDTH  320
#define ST_Y      (160 - ST_HEIGHT)
#define ST_SCALED_HEIGHT ST_HEIGHT
#define ST_SCALED_WIDTH  SCREENWIDTH
#define ST_SCALED_Y      (SCREENHEIGHT - ST_SCALED_HEIGHT)


//
// STATUS BAR DATA
//

// Palette indices.
// For damage/bonus red-/gold-shifts
#define STARTREDPALS            1
#define STARTBONUSPALS          9
#define NUMREDPALS              8
#define NUMBONUSPALS            4
// Radiation suit, green shift.
#define RADIATIONPAL            13

// Location of status bar
#define ST_X                    0
#define ST_X2                   104

// proff 08/18/98: Changed for high-res
#define ST_FX                   (ST_X+143)
#define ST_FY                   (ST_Y+1)

// Should be set to patch width
//  for tall numbers later on
#define ST_TALLNUMWIDTH         (tallnum[0]->width)

// Number of status faces.
#define ST_NUMPAINFACES         5
#define ST_NUMSTRAIGHTFACES     3
#define ST_NUMTURNFACES         2
#define ST_NUMSPECIALFACES      3

#define ST_FACESTRIDE \
          (ST_NUMSTRAIGHTFACES+ST_NUMTURNFACES+ST_NUMSPECIALFACES)

#define ST_NUMEXTRAFACES        2

#define ST_NUMFACES \
          (ST_FACESTRIDE*ST_NUMPAINFACES+ST_NUMEXTRAFACES)

#define ST_TURNOFFSET           (ST_NUMSTRAIGHTFACES)
#define ST_OUCHOFFSET           (ST_TURNOFFSET + ST_NUMTURNFACES)
#define ST_EVILGRINOFFSET       (ST_OUCHOFFSET + 1)
#define ST_RAMPAGEOFFSET        (ST_EVILGRINOFFSET + 1)
#define ST_GODFACE              (ST_NUMPAINFACES*ST_FACESTRIDE)
#define ST_DEADFACE             (ST_GODFACE+1)

// proff 08/18/98: Changed for high-res
#define ST_FACESX               (ST_X+104)
#define ST_FACESY               (ST_Y)

#define ST_EVILGRINCOUNT        (2*TICRATE)
 //Fix Status bar face timing ~Kippykip
//#define ST_STRAIGHTFACECOUNT    (TICRATE*2)
#define ST_STRAIGHTFACECOUNT    (18)
#define ST_TURNCOUNT            (1*TICRATE)
#define ST_OUCHCOUNT            (1*TICRATE)
#define ST_RAMPAGEDELAY         (2*TICRATE)

#define ST_MUCHPAIN             20

// Location and size of statistics,
//  justified according to widget type.
// Problem is, within which space? STbar? Screen?
// Note: this could be read in by a lump.
//       Problem is, is the stuff rendered
//       into a buffer,
//       or into the frame buffer?
// I dunno, why don't you go and find out!!!  killough

// AMMO number pos.
#define ST_AMMOWIDTH            3
// proff 08/18/98: Changed for high-res
#define ST_AMMOX                (ST_X+32)
#define ST_AMMOY                (ST_Y+6)
//#define ST_AMMOX                44
//#define ST_AMMOY                171

// HEALTH number pos.
#define ST_HEALTHWIDTH          3
// proff 08/18/98: Changed for high-res
#define ST_HEALTHX              (ST_X+66)
#define ST_HEALTHY              (ST_Y+6)


// Weapon pos.
// proff 08/18/98: Changed for high-res
#define ST_ARMSX                (ST_X+82)
#define ST_ARMSY                (ST_Y+4)
#define ST_ARMSBGX              (ST_X+104)
#define ST_ARMSBGY              (ST_Y)

#define ST_ARMSXSPACE           8
#define ST_ARMSYSPACE           10

// Frags pos.
// proff 08/18/98: Changed for high-res
#define ST_FRAGSX               (ST_X+138)
#define ST_FRAGSY               (ST_Y+3)
//#define ST_FRAGSX               138
//#define ST_FRAGSY               171
#define ST_FRAGSWIDTH           2

// ARMOR number pos.
#define ST_ARMORWIDTH           3
// proff 08/18/98: Changed for high-res
#define ST_ARMORX               (ST_X+166)
#define ST_ARMORY               (ST_Y+6)


// Key icon positions.
#define ST_KEY0WIDTH            8
#define ST_KEY0HEIGHT           5
// proff 08/18/98: Changed for high-res
#define ST_KEY0X                (ST_X+178)
#define ST_KEY0Y                (ST_Y+3)

#define ST_KEY1WIDTH            ST_KEY0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_KEY1X                (ST_X+178)
#define ST_KEY1Y                (ST_Y+13)

#define ST_KEY2WIDTH            ST_KEY0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_KEY2X                (ST_X+178)
#define ST_KEY2Y                (ST_Y+23)


// Ammunition counter.
#define ST_AMMO0WIDTH           3
#define ST_AMMO0HEIGHT          6
// proff 08/18/98: Changed for high-res
#define ST_AMMO0X               (ST_X+220)
#define ST_AMMO0Y               (ST_Y+5)

#define ST_AMMO1WIDTH           ST_AMMO0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_AMMO1X               (ST_X+220)
#define ST_AMMO1Y               (ST_Y+11)

#define ST_AMMO2WIDTH           ST_AMMO0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_AMMO2X               (ST_X+220)
#define ST_AMMO2Y               (ST_Y+23)

#define ST_AMMO3WIDTH           ST_AMMO0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_AMMO3X               (ST_X+220)
#define ST_AMMO3Y               (ST_Y+17)


// Indicate maximum ammunition.
// Only needed because backpack exists.
#define ST_MAXAMMO0WIDTH        3
#define ST_MAXAMMO0HEIGHT       5
// proff 08/18/98: Changed for high-res
#define ST_MAXAMMO0X            (ST_X+238)
#define ST_MAXAMMO0Y            (ST_Y+5)

#define ST_MAXAMMO1WIDTH        ST_MAXAMMO0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_MAXAMMO1X            (ST_X+238)
#define ST_MAXAMMO1Y            (ST_Y+11)

#define ST_MAXAMMO2WIDTH        ST_MAXAMMO0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_MAXAMMO2X            (ST_X+238)
#define ST_MAXAMMO2Y            (ST_Y+23)

#define ST_MAXAMMO3WIDTH        ST_MAXAMMO0WIDTH
// proff 08/18/98: Changed for high-res
#define ST_MAXAMMO3X            (ST_X+238)
#define ST_MAXAMMO3Y            (ST_Y+17)




//
// STATUS BAR
//

// Called by main loop.
boolean ST_Responder(const event_t* ev);

// Called by main loop.
void ST_Ticker(void);

// Called by main loop.
void ST_Drawer(boolean st_statusbaron, boolean refresh);

// Called when the console player is spawned on each level.
void ST_Start(void);

// Called by startup code.
void ST_Init(void);

// States for status bar code.
typedef enum
{
  AutomapState,
  FirstPersonState
} st_stateenum_t;

// killough 5/2/98: moved from m_misc.c:

#endif
