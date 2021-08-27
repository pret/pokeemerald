/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2001 by
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
 *      Handles WAD file header, directory, lump I/O.
 *
 *-----------------------------------------------------------------------------
 */

// use config.h if autoconf made one -- josh
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <fcntl.h>

#include "doomstat.h"
#include "d_net.h"
#include "doomtype.h"
#include "i_system.h"

#include "doom_iwad.h"

#ifdef __GNUG__
#pragma implementation "w_wad.h"
#endif
#include "w_wad.h"
#include "lprintf.h"

#include "global_data.h"

//
// GLOBALS
//
void ExtractFileBase (const char *path, char *dest)
{
    const char *src = path + strlen(path) - 1;
    int length;

    // back up until a \ or the start
    while (src != path && src[-1] != ':' // killough 3/22/98: allow c:filename
           && *(src-1) != '\\'
           && *(src-1) != '/')
    {
        src--;
    }

    // copy up to eight characters
    memset(dest,0,8);
    length = 0;

    while ((*src) && (*src != '.') && (++length<9))
    {
        *dest++ = toupper(*src);
        *src++;
    }
    /* cph - length check removed, just truncate at 8 chars.
   * If there are 8 or more chars, we'll copy 8, and no zero termination
   */
}

//
// LUMP BASED ROUTINES.
//

//
// W_AddFile
// All files are optional, but at least one file must be
//  found (PWAD, if all required lumps are present).
// Files with a .wad extension are wadlink files
//  with multiple lumps.
// Other files are single lumps with the base filename
//  for the lump name.
//
// Reload hack removed by Lee Killough
// CPhipps - source is an enum
//
// proff - changed using pointer to wadfile_info_t
static void W_AddFile()
{
    const wadinfo_t* header;
    filelump_t  *fileinfo;


    if(doom_iwad && (doom_iwad_len > 0))
    {
        header = (wadinfo_t*)&doom_iwad[0];

        if (strncmp(header->identification,"IWAD",4))
            I_Error("W_AddFile: Wad file doesn't have IWAD id");

        _g->numlumps = header->numlumps;
    }
}

//Return -1 if not found.
//Set lump ptr if found.

static int PUREFUNC FindLumpByName(const char* name, const filelump_t** lump)
{
    const wadinfo_t* header;
    const filelump_t  *fileinfo;

    if(doom_iwad && (doom_iwad_len > 0))
    {
        header = (const wadinfo_t*)&doom_iwad[0];

        fileinfo = (filelump_t*)&doom_iwad[header->infotableofs];

        int_64_t nameint = 0;
        strncpy((char*)&nameint, name, 8);

        for(int i = header->numlumps - 1; i >= 0; i--)
        {
            //This is a bit naughty with alignment.
            //For x86 doesn't matter because unaligned loads
            //are fine.
            //On ARM, unaligned loads are not fine but since it
            //doesn't have a 64bit load, the compiler will generate
            //32 bit loads. These vars are 32 aligned.

            int_64_t nameint2 = *(int_64_t*)fileinfo[i].name;

            if(nameint == nameint2)
            {
                *lump = &fileinfo[i];
                return i;
            }
        }
    }

    *lump = NULL;
    return -1;
}

static const filelump_t* PUREFUNC FindLumpByNum(int num)
{
    const wadinfo_t* header;
    const filelump_t  *fileinfo;

    if(num < 0)
        return NULL;

    if(doom_iwad && (doom_iwad_len > 0))
    {
        header = (const wadinfo_t*)&doom_iwad[0];

        if(num >= header->numlumps)
            return NULL;

        fileinfo = (const filelump_t*)&doom_iwad[header->infotableofs];

        return &fileinfo[num];
    }

    return NULL;
}

//
// W_CheckNumForName
// Returns -1 if name not found.
//
// Rewritten by Lee Killough to use hash table for performance. Significantly
// cuts down on time -- increases Doom performance over 300%. This is the
// single most important optimization of the original Doom sources, because
// lump name lookup is used so often, and the original Doom used a sequential
// search. For large wads with > 1000 lumps this meant an average of over
// 500 were probed during every search. Now the average is under 2 probes per
// search. There is no significant benefit to packing the names into longwords
// with this new hashing algorithm, because the work to do the packing is
// just as much work as simply doing the string comparisons with the new
// algorithm, which minimizes the expected number of comparisons to under 2.
//
// killough 4/17/98: add namespace parameter to prevent collisions
// between different resources such as flats, sprites, colormaps
//

int PUREFUNC W_CheckNumForName(const char *name)
{
    const filelump_t* lump = NULL;

    return FindLumpByName(name, &lump);
}

// W_GetNumForName
// Calls W_CheckNumForName, but bombs out if not found.
//
int PUREFUNC W_GetNumForName(const char* name)     // killough -- const added
{
    int i = W_CheckNumForName (name);

    if (i == -1)
        I_Error("W_GetNumForName: %.8s not found", name);

    return i;
}

const char* PUREFUNC W_GetNameForNum(int lump)
{
    const filelump_t* l = FindLumpByNum(lump);

    if(l)
    {
        return l->name;
    }

    return NULL;
}



// W_Init
// Loads each of the files in the wadfiles array.
// All files are optional, but at least one file
//  must be found.
// Files with a .wad extension are idlink files
//  with multiple lumps.
// Other files are single lumps with the base filename
//  for the lump name.
// Lump names can appear multiple times.
// The name searcher looks backwards, so a later file
//  does override all earlier ones.
//
// CPhipps - modified to use the new wadfiles array
//

void W_Init(void)
{
    // CPhipps - start with nothing

    _g->numlumps = 0;

    W_AddFile();

    if (!_g->numlumps)
        I_Error ("W_Init: No files found");
}

//
// W_LumpLength
// Returns the buffer size needed to load the given lump.
//

int PUREFUNC W_LumpLength(int lump)
{
    const filelump_t* l = FindLumpByNum(lump);

    if(l)
    {
        return l->size;
    }

    I_Error ("W_LumpLength: %i >= numlumps",lump);

    return 0;
}

static const void* PUREFUNC W_GetLumpPtr(int lump)
{
    const filelump_t* l = FindLumpByNum(lump);

    if(l)
    {
        return (const void*)&doom_iwad[l->filepos];
    }

    return NULL;
}

const void* PUREFUNC W_CacheLumpNum(int lump)
{
    return W_GetLumpPtr(lump);
}
