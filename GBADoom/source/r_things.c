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
 *  Refresh of things, i.e. objects represented by sprites.
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "w_wad.h"
#include "r_main.h"
#include "r_segs.h"
#include "r_draw.h"
#include "r_things.h"
#include "v_video.h"
#include "lprintf.h"

#include "global_data.h"



//
// Sprite rotation 0 is facing the viewer,
//  rotation 1 is one angle turn CLOCKWISE around the axis.
// This is not the same as the angle,
//  which increases counter clockwise (protractor).
// There was a lot of stuff grabbed wrong, so I changed it...
//


//
// INITIALIZATION FUNCTIONS
//


//
// R_InstallSpriteLump
// Local function for R_InitSprites.
//

static void R_InstallSpriteLump(int lump, unsigned frame,
                                unsigned rotation, boolean flipped)
{
  if (frame >= MAX_SPRITE_FRAMES || rotation > 8)
    I_Error("R_InstallSpriteLump: Bad frame characters in lump %i", lump);

  if ((int) frame > _g->maxframe)
    _g->maxframe = frame;


  if (rotation == 0)
  {    // the lump should be used for all rotations
      int r;

      _g->sprtemp[frame].flipmask = 0;

      for (r=0 ; r<8 ; r++)
      {
          if (_g->sprtemp[frame].lump[r]==-1)
          {
              _g->sprtemp[frame].lump[r] = lump - _g->firstspritelump;

              if(flipped)
                _g->sprtemp[frame].flipmask |= (1 << r);

              _g->sprtemp[frame].rotate = false; //jff 4/24/98 if any subbed, rotless
          }
      }
      return;
  }

  // the lump is only used for one rotation

  if (_g->sprtemp[frame].lump[--rotation] == -1)
  {
      _g->sprtemp[frame].lump[rotation] = lump - _g->firstspritelump;

      if(flipped)
        _g->sprtemp[frame].flipmask |= (1 << rotation);
      else
        _g->sprtemp[frame].flipmask &= (~(1 << rotation));

      _g->sprtemp[frame].rotate = true; //jff 4/24/98 only change if rot used
  }
}

//
// R_InitSpriteDefs
// Pass a null terminated list of sprite names
// (4 chars exactly) to be used.
//
// Builds the sprite rotation matrixes to account
// for horizontally flipped sprites.
//
// Will report an error if the lumps are inconsistent.
// Only called at startup.
//
// Sprite lump names are 4 characters for the actor,
//  a letter for the frame, and a number for the rotation.
//
// A sprite that is flippable will have an additional
//  letter/number appended.
//
// The rotation character can be 0 to signify no rotations.
//
// 1/25/98, 1/31/98 killough : Rewritten for performance
//
// Empirically verified to have excellent hash
// properties across standard Doom sprites:

#define R_SpriteNameHash(s) ((unsigned)((s)[0]-((s)[1]*3-(s)[3]*2-(s)[2])*2))

static void R_InitSpriteDefs(const char * const * namelist)
{
  size_t numentries = _g->lastspritelump-_g->firstspritelump+1;
  struct { int index, next; } *hash;
  int i;

  if (!numentries || !*namelist)
    return;

  // count the number of sprite names
  for (i=0; namelist[i]; i++)
    ;

  _g->numsprites = i;

  _g->sprites = Z_Malloc(_g->numsprites *sizeof(*_g->sprites), PU_STATIC, NULL);

  memset(_g->sprites, 0, _g->numsprites *sizeof(*_g->sprites));

  // Create hash table based on just the first four letters of each sprite
  // killough 1/31/98

  hash = malloc(sizeof(*hash)*numentries); // allocate hash table

  for (i=0; (size_t)i<numentries; i++)             // initialize hash table as empty
    hash[i].index = -1;

  for (i=0; (size_t)i<numentries; i++)             // Prepend each sprite to hash chain
    {                                      // prepend so that later ones win
      const char* sn = W_GetNameForNum(i+_g->firstspritelump);

      int j = R_SpriteNameHash(sn) % numentries;
      hash[i].next = hash[j].index;
      hash[j].index = i;
    }

  // scan all the lump names for each of the names,
  //  noting the highest frame letter.

  for (i=0 ; i<_g->numsprites ; i++)
    {
      const char *spritename = namelist[i];
      int j = hash[R_SpriteNameHash(spritename) % numentries].index;

      if (j >= 0)
        {
          memset(_g->sprtemp, -1, sizeof(_g->sprtemp));
          _g->maxframe = -1;
          do
            {
              const char* sn = W_GetNameForNum(j + _g->firstspritelump);

              // Fast portable comparison -- killough
              // (using int pointer cast is nonportable):

              if (!((sn[0] ^ spritename[0]) |
                    (sn[1] ^ spritename[1]) |
                    (sn[2] ^ spritename[2]) |
                    (sn[3] ^ spritename[3])))
                {
                  R_InstallSpriteLump(j+_g->firstspritelump,
                                      sn[4] - 'A',
                                      sn[5] - '0',
                                      false);
                  if (sn[6])
                    R_InstallSpriteLump(j+_g->firstspritelump,
                                        sn[6] - 'A',
                                        sn[7] - '0',
                                        true);
                }
            }
          while ((j = hash[j].next) >= 0);

          // check the frames that were found for completeness
          if ((_g->sprites[i].numframes = ++_g->maxframe))  // killough 1/31/98
            {
              int frame;
              for (frame = 0; frame < _g->maxframe; frame++)
                switch ((int) _g->sprtemp[frame].rotate)
                  {
                  case -1:
                    // no rotations were found for that frame at all
                    I_Error ("R_InitSprites: No patches found "
                             "for %.8s frame %c", namelist[i], frame+'A');
                    break;

                  case 0:
                    // only the first rotation is needed
                    break;

                  case 1:
                    // must have all 8 frames
                    {
                      int rotation;
                      for (rotation=0 ; rotation<8 ; rotation++)
                        if (_g->sprtemp[frame].lump[rotation] == -1)
                          I_Error ("R_InitSprites: Sprite %.8s frame %c "
                                   "is missing rotations",
                                   namelist[i], frame+'A');
                      break;
                    }
                  }
              // allocate space for the frames present and copy sprtemp to it
              _g->sprites[i].spriteframes =
                Z_Malloc (_g->maxframe * sizeof(spriteframe_t), PU_STATIC, NULL);
              memcpy (_g->sprites[i].spriteframes, _g->sprtemp,
                      _g->maxframe*sizeof(spriteframe_t));
            }
        }
    }
  free(hash);             // free hash table
}

//
// GAME FUNCTIONS
//


//
// R_InitSprites
// Called at program start.
//

void R_InitSprites(const char * const *namelist)
{
  R_InitSpriteDefs(namelist);
}





