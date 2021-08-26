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
 *   DOOM strings, by language.
 *   Note:  In BOOM, some new strings hav ebeen defined that are
 *          not found in the French version.  A better approach is
 *          to create a BEX text-replacement file for other
 *          languages since any language can be supported that way
 *          without recompiling the program.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __DSTRINGS__
#define __DSTRINGS__

/* All important printed strings.
 * Language selection (message strings).
 * Use -DFRENCH etc.
 */

#ifdef FRENCH
#include "d_french.h"
#else
#include "d_englsh.h"
#endif

/* Note this is not externally modifiable through DEH/BEX
 * Misc. other strings.
 * #define SAVEGAMENAME  "boomsav"      * killough 3/22/98 *
 * Ty 05/04/98 - replaced with a modifiable string, see d_deh.c
 */

/*
 * File locations,
 *  relative to current position.
 * Path names are OS-sensitive.
 */
#define DEVMAPS "devmaps"
#define DEVDATA "devdata"


/* Not done in french?
 * QuitDOOM messages *
 * killough 1/18/98:
 * replace hardcoded limit with extern var (silly hack, I know)
 */

#include <stddef.h>

#endif
