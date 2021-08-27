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
 *      Simple basic typedefs, isolated here to make it easier
 *       separating modules.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __DOOMTYPE__
#define __DOOMTYPE__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef __BYTEBOOL__
#define __BYTEBOOL__
/* Fixed to use builtin bool type with C++. */
#ifdef __cplusplus
typedef bool boolean;
#else
typedef enum {false, true} boolean;
#endif
typedef unsigned char byte;
#endif

//e6y
#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif
#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif

/* cph - Wrapper for the long long type, as Win32 used a different name.
 * Except I don't know what to test as it's compiler specific
 * Proff - I fixed it */

#ifdef __WINS__
	#define int_64_t  __int64
	#define uint_64_t unsigned __int64
#else
	#define int_64_t  long long
	#define uint_64_t unsigned long long
#endif

//typedef _int64 int_64_t;
//typedef unsigned _int64 uint_64_t;
// define compiled-specific long-long contstant notation here
#define LONGLONG(num) (uint_64_t)num
#undef PATH_MAX
#define PATH_MAX 1024

#ifdef __GNUC__
#define CONSTFUNC __attribute__((const))
#define PUREFUNC __attribute__((pure))
#define NORETURN __attribute__ ((noreturn))
#else
#define CONSTFUNC
#define PUREFUNC
#define NORETURN
#endif

/* CPhipps - use limits.h instead of depreciated values.h */
#include <limits.h>

/* cph - from v_video.h, needed by gl_struct.h */
enum patch_translation_e {
  VPT_NONE    = 0, // Normal
  VPT_FLIP    = 1, // Flip image horizontally
  VPT_TRANS   = 2, // Translate image via a translation table
  VPT_STRETCH = 4, // Stretch to compensate for high-res
};

#endif
