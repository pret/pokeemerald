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
 *      Created by a sound utility.
 *      Kept as a sample, DOOM2 sounds.
 *
 *-----------------------------------------------------------------------------*/

// killough 5/3/98: reformatted

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "doomtype.h"
#include "sounds.h"

//
// Information about all the sfx
//

const sfxinfo_t S_sfx[] = {
  // S_sfx[0] needs to be a dummy for odd reasons.
  { "none", false,  0, 0, -1, 0},
  { "pistol", false, 64, 0, -1, 18 },
  { "shotgn", false, 64, 0, -1, 30 },
  { "sgcock", false, 64, 0, -1, 19 },
  { "dshtgn", false, 64, 0, -1, 28 },
  { "dbopn", false, 64, 0, -1, 6 },
  { "dbcls", false, 64, 0, -1, 7 },
  { "dbload", false, 64, 0, -1, 8 },
  { "plasma", false, 64, 0, -1, 18 },
  { "bfg", false, 64, 0, -1, 58 },
  { "sawup", false, 64, 0, -1, 52 },
  { "sawidl", false, 118, 0, -1, 24 },
  { "sawful", false, 64, 0, -1, 58 },
  { "sawhit", false, 64, 0, -1, 26 },
  { "rlaunc", false, 64, 0, -1, 49 },
  { "rxplod", false, 70, 0, -1, 46 },
  { "firsht", false, 70, 0, -1, 47 },
  { "firxpl", false, 70, 0, -1, 38 },
  { "pstart", false, 100, 0, -1, 26 },
  { "pstop", false, 100, 0, -1, 21 },
  { "doropn", false, 100, 0, -1, 44 },
  { "dorcls", false, 100, 0, -1, 45 },
  { "stnmov", false, 119, 0, -1, 10 },
  { "swtchn", false, 78, 0, -1, 20 },
  { "swtchx", false, 78, 0, -1, 18 },
  { "plpain", false, 96, 0, -1, 48 },
  { "dmpain", false, 96, 0, -1, 31 },
  { "popain", false, 96, 0, -1, 28 },
  { "vipain", false, 96, 0, -1, 34 },
  { "mnpain", false, 96, 0, -1, 37 },
  { "pepain", false, 96, 0, -1, 26 },
  { "slop", false, 78, 0, -1, 36 },
  { "itemup", true, 78, 0, -1, 7 },
  { "wpnup", true, 78, 0, -1, 19 },
  { "oof", false, 96, 0, -1, 13 },
  { "telept", false, 32, 0, -1, 49 },
  { "posit1", true, 98, 0, -1, 17 },
  { "posit2", true, 98, 0, -1, 36 },
  { "posit3", true, 98, 0, -1, 35 },
  { "bgsit1", true, 98, 0, -1, 44 },
  { "bgsit2", true, 98, 0, -1, 52 },
  { "sgtsit", true, 98, 0, -1, 36 },
  { "cacsit", true, 98, 0, -1, 55 },
  { "brssit", true, 94, 0, -1, 44 },
  { "cybsit", true, 92, 0, -1, 42 },
  { "spisit", true, 90, 0, -1, 40 },
  { "bspsit", true, 90, 0, -1, 35 },
  { "kntsit", true, 90, 0, -1, 44 },
  { "vilsit", true, 90, 0, -1, 57 },
  { "mansit", true, 90, 0, -1, 42 },
  { "pesit", true, 90, 0, -1, 39 },
  { "sklatk", false, 70, 0, -1, 28 },
  { "sgtatk", false, 70, 0, -1, 30 },
  { "skepch", false, 70, 0, -1, 10 },
  { "vilatk", false, 70, 0, -1, 54 },
  { "claw", false, 70, 0, -1, 21 },
  { "skeswg", false, 70, 0, -1, 8 },
  { "pldeth", false, 32, 0, -1, 35 },
  { "pdiehi", false, 32, 0, -1, 35 },
  { "podth1", false, 70, 0, -1, 41 },
  { "podth2", false, 70, 0, -1, 30 },
  { "podth3", false, 70, 0, -1, 35 },
  { "bgdth1", false, 70, 0, -1, 23 },
  { "bgdth2", false, 70, 0, -1, 30 },
  { "sgtdth", false, 70, 0, -1, 39 },
  { "cacdth", false, 70, 0, -1, 33 },
  { "skldth", false, 70, 0, -1, 13 },
  { "brsdth", false, 32, 0, -1, 35 },
  { "cybdth", false, 32, 0, -1, 53 },
  { "spidth", false, 32, 0, -1, 108 },
  { "bspdth", false, 32, 0, -1, 58 },
  { "vildth", false, 32, 0, -1, 40 },
  { "kntdth", false, 32, 0, -1, 23 },
  { "pedth", false, 32, 0, -1, 53 },
  { "skedth", false, 32, 0, -1, 47 },
  { "posact", true, 120, 0, -1, 34 },
  { "bgact", true, 120, 0, -1, 32 },
  { "dmact", true, 120, 0, -1, 38 },
  { "bspact", true, 100, 0, -1, 42 },
  { "bspwlk", true, 100, 0, -1, 17 },
  { "vilact", true, 100, 0, -1, 42 },
  { "noway", false, 78, 0, -1, 13 },
  { "barexp", false, 60, 0, -1, 59 },
  { "punch", false, 64, 0, -1, 8 },
  { "hoof", false, 70, 0, -1, 13 },
  { "metal", false, 70, 0, -1, 26 },
  { "chgun", false, 64, &S_sfx[sfx_pistol], 150, 18 },
  { "tink", false, 60, 0, -1, 1 },
  { "bdopn", false, 100, 0, -1, 14 },
  { "bdcls", false, 100, 0, -1, 14 },
  { "itmbk", false, 100, 0, -1, 18 },
  { "flame", false, 32, 0, -1, 36 },
  { "flamst", false, 32, 0, -1, 18 },
  { "getpow", false, 60, 0, -1, 26 },
  { "bospit", false, 70, 0, -1, 139 },
  { "boscub", false, 70, 0, -1, 39 },
  { "bossit", false, 70, 0, -1, 181 },
  { "bospn", false, 70, 0, -1, 137 },
  { "bosdth", false, 70, 0, -1, 132 },
  { "manatk", false, 70, 0, -1, 38 },
  { "mandth", false, 70, 0, -1, 69 },
  { "sssit", false, 70, 0, -1, 23 },
  { "ssdth", false, 70, 0, -1, 26 },
  { "keenpn", false, 70, 0, -1, 14 },
  { "keendt", false, 70, 0, -1, 28 },
  { "skeact", false, 70, 0, -1, 34 },
  { "skesit", false, 70, 0, -1, 38 },
  { "skeatk", false, 70, 0, -1, 47 },
  { "radio", false, 60, 0, -1, 8 },
};
