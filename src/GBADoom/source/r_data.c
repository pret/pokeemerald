/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2002 by
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
 *      Preparation of data for rendering,
 *      generation of lookups, caching, retrieval by name.
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "w_wad.h"
#include "r_draw.h"
#include "r_main.h"
#include "r_sky.h"
#include "i_system.h"
#include "r_things.h"
#include "p_tick.h"
#include "lprintf.h"  // jff 08/03/98 - declaration of lprintf
#include "p_tick.h"

#include "global_data.h"

//
// Graphics.
// DOOM graphics for walls and sprites
// is stored in vertical runs of opaque pixels (posts).
// A column is composed of zero or more posts,
// a patch or sprite is composed of zero or more columns.
//

//
// Texture definition.
// Each texture is composed of one or more patches,
// with patches being lumps stored in the WAD.
// The lumps are referenced by number, and patched
// into the rectangular texture space using origin
// and possibly other attributes.
//

typedef struct
{
  short originx;
  short originy;
  short patch;
  short stepdir;         // unused in Doom but might be used in Phase 2 Boom
  short colormap;        // unused in Doom but might be used in Phase 2 Boom
} PACKEDATTR mappatch_t;


typedef struct
{
  char       name[8];
  char       pad2[4];      // unused
  short      width;
  short      height;
  char       pad[4];       // unused in Doom but might be used in Boom Phase 2
  short      patchcount;
  mappatch_t patches[1];
} PACKEDATTR maptexture_t;

// A maptexturedef_t describes a rectangular texture, which is composed
// of one or more mappatch_t structures that arrange graphic patches.


static const texture_t* R_LoadTexture(int texture_num)
{
    const byte* pnames = W_CacheLumpName("PNAMES");

    //Skip to list of names.
    pnames += 4;

    const int  *maptex1, *maptex2;
    int  numtextures1, numtextures2;
    const int *directory1, *directory2;


    maptex1 = W_CacheLumpName("TEXTURE1");
    numtextures1 = *maptex1;
    directory1 = maptex1+1;


    if (W_CheckNumForName("TEXTURE2") != -1)
    {
        maptex2 = W_CacheLumpName("TEXTURE2");
        numtextures2 = *maptex2;
        directory2 = maptex2+1;
    }
    else
    {
        maptex2 = NULL;
        numtextures2 = 0;
        directory2 = NULL;
    }

    int offset = 0;
    const int  *maptex = maptex1;

    if(texture_num < numtextures1)
    {
        offset = directory1[texture_num];
    }
    else if(maptex2 && ((texture_num-numtextures1) < numtextures2) )
    {
        maptex = maptex2;
        offset = directory2[texture_num-numtextures1];
    }
    else
    {
        I_Error("R_LoadTexture: Texture %d not in range.", texture_num);
    }

    const maptexture_t *mtexture = (const maptexture_t *) ((const byte *)maptex + offset);

    texture_t* texture = Z_Malloc(sizeof(const texture_t) + sizeof(const texpatch_t)*(mtexture->patchcount-1), PU_LEVEL, (void**)&textures[texture_num]);

    texture->width = mtexture->width;
    texture->height = mtexture->height;
    texture->patchcount = mtexture->patchcount;
    texture->name = mtexture->name;

    texpatch_t* patch = texture->patches;
    const mappatch_t* mpatch = mtexture->patches;

    texture->overlapped = 0;



    for (int j=0 ; j < texture->patchcount ; j++, mpatch++, patch++)
    {
        patch->originx = mpatch->originx;
        patch->originy = mpatch->originy;

        char pname[8];
        strncpy(pname, (const char*)&pnames[mpatch->patch * 8], 8);

        patch->patch = (const patch_t*)W_CacheLumpName(pname);
    }

    for (int j=0 ; j < texture->patchcount ; j++)
    {
        const texpatch_t* patch = &texture->patches[j];

        //Check for patch overlaps.
        int l1 = patch->originx;
        int r1 = l1 + patch->patch->width;

        for(int k = j+1; k < texture->patchcount; k++)
        {
            if(k == j)
                continue;

            const texpatch_t* p2 = &texture->patches[k];

            //Check for patch overlaps.
            int l2 = p2->originx;
            int r2 = l2 + p2->patch->width;

            if(r1 > l2 && l1 < r2)
            {
                texture->overlapped = 1;
                break;
            }
        }

        if(texture->overlapped)
            break;
    }

    int w;

    for (w=1; w*2 <= texture->width; w<<=1)
        ;
    texture->widthmask = w-1;

    textureheight[texture_num] = texture->height<<FRACBITS;

    texturetranslation[texture_num] = texture_num;

    textures[texture_num] = texture;

    return texture;
}

const texture_t* R_GetTexture(int texture)
{
    if(texture >= _g->numtextures)
        return NULL;

    if(textures[texture])
        return textures[texture];

    const texture_t* t = R_LoadTexture(texture);

    textures[texture] = t;

    return t;
}

static int R_GetTextureNumForName(const char* tex_name)
{
    const int  *maptex1, *maptex2;
    int  numtextures1;
    const int *directory1, *directory2;


    //Convert name to uppercase for comparison.
    char tex_name_upper[9];

    strncpy(tex_name_upper, tex_name, 8);
    tex_name_upper[8] = 0; //Ensure null terminated.

    strupr(tex_name_upper);

    if(_g->tex_lookup_last_name && (!strncmp(_g->tex_lookup_last_name, tex_name_upper, 8)))
    {
        return _g->tex_lookup_last_num;
    }

    maptex1 = W_CacheLumpName("TEXTURE1");
    numtextures1 = *maptex1;
    directory1 = maptex1+1;


    if (W_CheckNumForName("TEXTURE2") != -1)
    {
        maptex2 = W_CacheLumpName("TEXTURE2");
        directory2 = maptex2+1;
    }
    else
    {
        maptex2 = NULL;
        directory2 = NULL;
    }

    const int *directory = directory1;
    const int *maptex = maptex1;

    for (int i=0 ; i<_g->numtextures ; i++, directory++)
    {
        if (i == numtextures1)
        {
            // Start looking in second texture file.
            maptex = maptex2;
            directory = directory2;
        }

        int offset = *directory;

        const maptexture_t* mtexture = (const maptexture_t *) ( (const byte *)maptex + offset);

        if(!strncmp(tex_name_upper, mtexture->name, 8))
        {
            _g->tex_lookup_last_name = mtexture->name;
            _g->tex_lookup_last_num = i;
            return i;
        }

    }

    return -1;
}

int R_LoadTextureByName(const char* tex_name)
{
    if(tex_name[0] == '-')
        return NO_TEXTURE;

    int tnum = R_GetTextureNumForName(tex_name);

    if(tnum == -1)
    {
        printf("texture name: %s not found.\n", tex_name);
        return NO_TEXTURE;
    }


    R_GetTexture(tnum);

    return tnum;
}

//
// R_InitTextures
// Initializes the texture list
//  with the textures from the world map.
//

static void R_InitTextures()
{
    const int* mtex1 = W_CacheLumpName("TEXTURE1");
    int numtextures1 = *mtex1;

    int numtextures2 = 0;

    if (W_CheckNumForName("TEXTURE2") != -1)
    {
        const int* mtex2 = W_CacheLumpName("TEXTURE2");
        numtextures2 = *mtex2;
    }

    _g->numtextures = numtextures1 + numtextures2;

    textures = Z_Malloc(_g->numtextures*sizeof*textures, PU_STATIC, 0);
    memset(textures, 0, _g->numtextures*sizeof*textures);

    textureheight = Z_Malloc(_g->numtextures*sizeof*textureheight, PU_STATIC, 0);
    memset(textureheight, 0, _g->numtextures*sizeof*textureheight);

    texturetranslation = Z_Malloc((_g->numtextures+1)*sizeof*texturetranslation, PU_STATIC, 0);

    for (int i=0 ; i<_g->numtextures ; i++)
        texturetranslation[i] = i;
}

//
// R_InitFlats
//
static void R_InitFlats(void)
{
  int i;

  _g->firstflat = W_GetNumForName("F_START") + 1;
  _g->lastflat  = W_GetNumForName("F_END") - 1;
  _g->numflats  = _g->lastflat - _g->firstflat + 1;

  // Create translation table for global animation.
  // killough 4/9/98: make column offsets 32-bit;
  // clean up malloc-ing to use sizeof

  flattranslation =
    Z_Malloc((_g->numflats+1)*sizeof(*flattranslation), PU_STATIC, 0);

  for (i=0 ; i<_g->numflats ; i++)
    flattranslation[i] = i;
}

//
// R_InitSpriteLumps
// Finds the width and hoffset of all sprites in the wad,
// so the sprite does not need to be cached completely
// just for having the header info ready during rendering.
//
static void R_InitSpriteLumps(void)
{
  _g->firstspritelump = W_GetNumForName("S_START") + 1;
  _g->lastspritelump = W_GetNumForName("S_END") - 1;
  _g->numspritelumps = _g->lastspritelump - _g->firstspritelump + 1;
}

//
// R_InitColormaps
//
void R_InitColormaps (void)
{
    int lump = W_GetNumForName("COLORMAP");
    colormaps = W_CacheLumpNum(lump);
}

//
// R_InitData
// Locates all the lumps
//  that will be used by all views
// Must be called after W_Init.
//

void R_InitData(void)
{
  lprintf(LO_INFO, "Textures");
  R_InitTextures();
  lprintf(LO_INFO, "Flats");
  R_InitFlats();
  lprintf(LO_INFO, "Sprites");
  R_InitSpriteLumps();
  lprintf(LO_INFO, "Colormaps");
  R_InitColormaps();                    // killough 3/20/98
}

//
// R_FlatNumForName
// Retrieval, get a flat number for a flat name.
//
// killough 4/17/98: changed to use ns_flats namespace
//

int R_FlatNumForName(const char *name)    // killough -- const added
{
  int i = W_CheckNumForName(name);

  if (i == -1)
    I_Error("R_FlatNumForName: %.8s not found", name);
  return i - _g->firstflat;
}

//
// R_CheckTextureNumForName
// Check whether texture is available.
// Filter out NoTexture indicator.
//
// Rewritten by Lee Killough to use hash table for fast lookup. Considerably
// reduces the time needed to start new levels. See w_wad.c for comments on
// the hashing algorithm, which is also used for lump searches.
//
// killough 1/21/98, 1/31/98
//

int PUREFUNC R_CheckTextureNumForName (const char *name)
{
    // "NoTexture" marker.
    if (name[0] == '-')
        return 0;

    return R_GetTextureNumForName(name);
}
