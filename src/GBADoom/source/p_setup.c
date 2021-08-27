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
 *  Do all the WAD I/O, get map description,
 *  set up initial state and misc. LUTs.
 *
 *-----------------------------------------------------------------------------*/

#include <math.h>

#include "doomstat.h"
#include "m_bbox.h"
#include "g_game.h"
#include "w_wad.h"
#include "r_main.h"
#include "r_things.h"
#include "p_maputl.h"
#include "p_map.h"
#include "p_setup.h"
#include "p_spec.h"
#include "p_tick.h"
#include "p_enemy.h"
#include "s_sound.h"
#include "lprintf.h" //jff 10/6/98 for debug outputs
#include "v_video.h"

#include "global_data.h"

//
// P_LoadVertexes
//
// killough 5/3/98: reformatted, cleaned up
//
static void P_LoadVertexes (int lump)
{
  // Determine number of lumps:
  //  total lump length / vertex record length.
  _g->numvertexes = W_LumpLength(lump) / sizeof(vertex_t);

  // Allocate zone memory for buffer.
  _g->vertexes = W_CacheLumpNum(lump);

}

//
// P_LoadSegs
//
// killough 5/3/98: reformatted, cleaned up

static void P_LoadSegs (int lump)
{
    _g->numsegs = W_LumpLength(lump) / sizeof(seg_t);
    _g->segs = (const seg_t *)W_CacheLumpNum(lump);

    if (!_g->numsegs)
      I_Error("P_LoadSegs: no segs in level");
}

//
// P_LoadSubsectors
//
// killough 5/3/98: reformatted, cleaned up

static void P_LoadSubsectors (int lump)
{
  /* cph 2006/07/29 - make data a const mapsubsector_t *, so the loop below is simpler & gives no constness warnings */
  const mapsubsector_t *data;
  int  i;

  _g->numsubsectors = W_LumpLength (lump) / sizeof(mapsubsector_t);
  _g->subsectors = Z_Calloc(_g->numsubsectors,sizeof(subsector_t),PU_LEVEL,0);
  data = (const mapsubsector_t *)W_CacheLumpNum(lump);

  if ((!data) || (!_g->numsubsectors))
    I_Error("P_LoadSubsectors: no subsectors in level");

  for (i=0; i<_g->numsubsectors; i++)
  {
    _g->subsectors[i].numlines  = (unsigned short)SHORT(data[i].numsegs );
    _g->subsectors[i].firstline = (unsigned short)SHORT(data[i].firstseg);
  }
}

//
// P_LoadSectors
//
// killough 5/3/98: reformatted, cleaned up

static void P_LoadSectors (int lump)
{
  const byte *data; // cph - const*
  int  i;

  _g->numsectors = W_LumpLength (lump) / sizeof(mapsector_t);
  _g->sectors = Z_Calloc (_g->numsectors,sizeof(sector_t),PU_LEVEL,0);
  data = W_CacheLumpNum (lump); // cph - wad lump handling updated

  for (i=0; i<_g->numsectors; i++)
    {
      sector_t *ss = _g->sectors + i;
      const mapsector_t *ms = (const mapsector_t *) data + i;

      ss->floorheight = SHORT(ms->floorheight)<<FRACBITS;
      ss->ceilingheight = SHORT(ms->ceilingheight)<<FRACBITS;
      ss->floorpic = R_FlatNumForName(ms->floorpic);
      ss->ceilingpic = R_FlatNumForName(ms->ceilingpic);

      ss->lightlevel = SHORT(ms->lightlevel);
      ss->special = SHORT(ms->special);
      ss->oldspecial = SHORT(ms->special);
      ss->tag = SHORT(ms->tag);

      ss->thinglist = NULL;
      ss->touching_thinglist = NULL;            // phares 3/14/98
    }
}


//
// P_LoadNodes
//
// killough 5/3/98: reformatted, cleaned up

static void P_LoadNodes (int lump)
{
  numnodes = W_LumpLength (lump) / sizeof(mapnode_t);
  nodes = W_CacheLumpNum (lump); // cph - wad lump handling updated

  if ((!nodes) || (!numnodes))
  {
    // allow trivial maps
    if (_g->numsubsectors == 1)
      lprintf(LO_INFO,
          "P_LoadNodes: trivial map (no nodes, one subsector)\n");
    else
      I_Error("P_LoadNodes: no nodes in level");
  }
}


/*
 * P_LoadThings
 *
 * killough 5/3/98: reformatted, cleaned up
 * cph 2001/07/07 - don't write into the lump cache, especially non-idepotent
 * changes like byte order reversals. Take a copy to edit.
 */

static void P_LoadThings (int lump)
{
  int  i, numthings = W_LumpLength (lump) / sizeof(mapthing_t);
  const mapthing_t *data = W_CacheLumpNum (lump);

  if ((!data) || (!numthings))
    I_Error("P_LoadThings: no things in level");

  for (i=0; i<numthings; i++)
    {
      mapthing_t mt = data[i];

      mt.x = SHORT(mt.x);
      mt.y = SHORT(mt.y);
      mt.angle = SHORT(mt.angle);
      mt.type = SHORT(mt.type);
      mt.options = SHORT(mt.options);

      if (!P_IsDoomnumAllowed(mt.type))
        continue;

      // Do spawn all other stuff.
      P_SpawnMapThing(&mt);
    }
}

//
// P_LoadLineDefs
// Also counts secret lines for intermissions.
//        ^^^
// ??? killough ???
// Does this mean secrets used to be linedef-based, rather than sector-based?
//
// killough 4/4/98: split into two functions, to allow sidedef overloading
//
// killough 5/3/98: reformatted, cleaned up

static void P_LoadLineDefs (int lump)
{
    int  i;

    _g->numlines = W_LumpLength (lump) / sizeof(line_t);
    _g->lines = W_CacheLumpNum (lump);

    _g->linedata = Z_Calloc(_g->numlines,sizeof(linedata_t),PU_LEVEL,0);

    for (i=0; i<_g->numlines; i++)
    {
        _g->linedata[i].special = _g->lines[i].const_special;
    }
}

// killough 4/4/98: delay using sidedefs until they are loaded
// killough 5/3/98: reformatted, cleaned up

static void P_LoadLineDefs2(int lump)
{
    /*
  int i = _g->numlines;
  register line_t *ld = _g->lines;
  for (;i--;ld++)
    {
      ld->frontsector = _g->sides[ld->sidenum[0]].sector; //e6y: Can't be NO_INDEX here
      ld->backsector  = ld->sidenum[1]!=NO_INDEX ? _g->sides[ld->sidenum[1]].sector : 0;
    }
    */
}

//
// P_LoadSideDefs
//
// killough 4/4/98: split into two functions

static void P_LoadSideDefs (int lump)
{
  _g->numsides = W_LumpLength(lump) / sizeof(mapsidedef_t);
  _g->sides = Z_Calloc(_g->numsides,sizeof(side_t),PU_LEVEL,0);
}

// killough 4/4/98: delay using texture names until
// after linedefs are loaded, to allow overloading.
// killough 5/3/98: reformatted, cleaned up

static void P_LoadSideDefs2(int lump)
{
    const byte *data = W_CacheLumpNum(lump); // cph - const*, wad lump handling updated
    int  i;

    for (i=0; i<_g->numsides; i++)
    {
        register const mapsidedef_t *msd = (const mapsidedef_t *) data + i;
        register side_t *sd = _g->sides + i;
        register sector_t *sec;

        sd->textureoffset = msd->textureoffset;
        sd->rowoffset = msd->rowoffset;

        { /* cph 2006/09/30 - catch out-of-range sector numbers; use sector 0 instead */
            unsigned short sector_num = SHORT(msd->sector);
            if (sector_num >= _g->numsectors)
            {
                lprintf(LO_WARN,"P_LoadSideDefs2: sidedef %i has out-of-range sector num %u\n", i, sector_num);
                sector_num = 0;
            }
            sd->sector = sec = &_g->sectors[sector_num];
        }

        sd->midtexture = msd->midtexture;
        sd->toptexture = msd->toptexture;
        sd->bottomtexture = msd->bottomtexture;

        R_GetTexture(sd->midtexture);
        R_GetTexture(sd->toptexture);
        R_GetTexture(sd->bottomtexture);
    }
}

//
// jff 10/6/98
// New code added to speed up calculation of internal blockmap
// Algorithm is order of nlines*(ncols+nrows) not nlines*ncols*nrows
//

#define blkshift 7               /* places to shift rel position for cell num */
#define blkmask ((1<<blkshift)-1)/* mask for rel position within cell */
#define blkmargin 0              /* size guardband around map used */
                                 // jff 10/8/98 use guardband>0
                                 // jff 10/12/98 0 ok with + 1 in rows,cols

typedef struct linelist_t        // type used to list lines in each block
{
  long num;
  struct linelist_t *next;
} linelist_t;

//
// P_LoadBlockMap
//
// killough 3/1/98: substantially modified to work
// towards removing blockmap limit (a wad limitation)
//
// killough 3/30/98: Rewritten to remove blockmap limit,
// though current algorithm is brute-force and unoptimal.
//

static void P_LoadBlockMap (int lump)
{
    _g->blockmaplump = W_CacheLumpNum(lump);

    _g->bmaporgx = _g->blockmaplump[0]<<FRACBITS;
    _g->bmaporgy = _g->blockmaplump[1]<<FRACBITS;
    _g->bmapwidth = _g->blockmaplump[2];
    _g->bmapheight = _g->blockmaplump[3];


    // clear out mobj chains - CPhipps - use calloc
    _g->blocklinks = Z_Calloc (_g->bmapwidth*_g->bmapheight,sizeof(*_g->blocklinks),PU_LEVEL,0);

    _g->blockmap = _g->blockmaplump+4;
}

//
// P_LoadReject - load the reject table, padding it if it is too short
// totallines must be the number returned by P_GroupLines()
// an underflow will be padded with zeroes, or a doom.exe z_zone header
// 
// this function incorporates e6y's RejectOverrunAddInt code:
// e6y: REJECT overrun emulation code
// It's emulated successfully if the size of overflow no more than 16 bytes.
// No more desync on teeth-32.wad\teeth-32.lmp.
// http://www.doomworld.com/vb/showthread.php?s=&threadid=35214

static void P_LoadReject(int lumpnum)
{
  _g->rejectlump = lumpnum + ML_REJECT;
  _g->rejectmatrix = W_CacheLumpNum(_g->rejectlump);
}

//
// P_GroupLines
// Builds sector line lists and subsector sector numbers.
// Finds block bounding boxes for sectors.
//
// killough 5/3/98: reformatted, cleaned up
// cph 18/8/99: rewritten to avoid O(numlines * numsectors) section
// It makes things more complicated, but saves seconds on big levels
// figgi 09/18/00 -- adapted for gl-nodes

// cph - convenient sub-function
static void P_AddLineToSector(const line_t* li, sector_t* sector)
{
  sector->lines[sector->linecount++] = li;
}

// modified to return totallines (needed by P_LoadReject)
static int P_GroupLines (void)
{
    register const line_t *li;
    register sector_t *sector;
    int i,j, total = _g->numlines;

    // figgi
    for (i=0 ; i<_g->numsubsectors ; i++)
    {
        const seg_t *seg = &_g->segs[_g->subsectors[i].firstline];
        _g->subsectors[i].sector = NULL;
        for(j=0; j<_g->subsectors[i].numlines; j++)
        {
            if(seg->sidenum != NO_INDEX)
            {
                _g->subsectors[i].sector = _g->sides[seg->sidenum].sector;
                break;
            }
            seg++;
        }
        if(_g->subsectors[i].sector == NULL)
            I_Error("P_GroupLines: Subsector a part of no sector!\n");
    }

    // count number of lines in each sector
    for (i=0,li=_g->lines; i<_g->numlines; i++, li++)
    {
        LN_FRONTSECTOR(li)->linecount++;
        if (LN_BACKSECTOR(li) && LN_BACKSECTOR(li) != LN_FRONTSECTOR(li))
        {
            LN_BACKSECTOR(li)->linecount++;
            total++;
        }
    }

    {  // allocate line tables for each sector
        const line_t **linebuffer = Z_Malloc(total*sizeof(line_t *), PU_LEVEL, 0);

        // e6y: REJECT overrun emulation code
        // moved to P_LoadReject

        for (i=0, sector = _g->sectors; i<_g->numsectors; i++, sector++)
        {
            sector->lines = linebuffer;
            linebuffer += sector->linecount;
            sector->linecount = 0;
        }
    }

    // Enter those lines
    for (i=0,li=_g->lines; i<_g->numlines; i++, li++)
    {
        P_AddLineToSector(li, LN_FRONTSECTOR(li));
        if (LN_BACKSECTOR(li) && LN_BACKSECTOR(li) != LN_FRONTSECTOR(li))
            P_AddLineToSector(li, LN_BACKSECTOR(li));
    }

    for (i=0, sector = _g->sectors; i<_g->numsectors; i++, sector++)
    {
        fixed_t bbox[4];
        M_ClearBox(bbox);

        for(int l = 0; l < sector->linecount; l++)
        {
            M_AddToBox (bbox, sector->lines[l]->v1.x, sector->lines[l]->v1.y);
            M_AddToBox (bbox, sector->lines[l]->v2.x, sector->lines[l]->v2.y);
        }

        sector->soundorg.x = bbox[BOXRIGHT]/2+bbox[BOXLEFT]/2;
        sector->soundorg.y = bbox[BOXTOP]/2+bbox[BOXBOTTOM]/2;
    }

    return total; // this value is needed by the reject overrun emulation code
}


void P_FreeLevelData()
{
    R_ResetPlanes();

    Z_FreeTags(PU_LEVEL, PU_PURGELEVEL-1);

    free(_g->braintargets);
    _g->braintargets = NULL;
    _g->numbraintargets_alloc = _g->numbraintargets = 0;
}

//
// P_SetupLevel
//
// killough 5/3/98: reformatted, cleaned up

void P_SetupLevel(int episode, int map, int playermask, skill_t skill)
{
  int   i;
  char  lumpname[9];
  int   lumpnum;

  _g->totallive = _g->totalkills = _g->totalitems = _g->totalsecret = _g->wminfo.maxfrags = 0;
  _g->wminfo.partime = 180;

  for (i=0; i<MAXPLAYERS; i++)
    _g->player.killcount = _g->player.secretcount = _g->player.itemcount = 0;

  // Initial height of PointOfView will be set by player think.
  _g->player.viewz = 1;

  // Make sure all sounds are stopped before Z_FreeTags.
  S_Start();

  P_FreeLevelData();

  //Load the sky texture.
  R_GetTexture(_g->skytexture);

  if (_g->rejectlump != -1)
  { // cph - unlock the reject table
    _g->rejectlump = -1;
  }

  P_InitThinkers();

  // if working with a devlopment map, reload it
  //    W_Reload ();     killough 1/31/98: W_Reload obsolete

  // find map name
  if (_g->gamemode == commercial)
  {
    sprintf(lumpname, "MAP%02d", map);           // killough 1/24/98: simplify
  }
  else
  {
    sprintf(lumpname, "E%dM%d", episode, map);   // killough 1/24/98: simplify
  }

  lumpnum = W_GetNumForName(lumpname);

  _g->leveltime = 0; _g->totallive = 0;

  P_LoadVertexes  (lumpnum+ML_VERTEXES);
  P_LoadSectors   (lumpnum+ML_SECTORS);
  P_LoadSideDefs  (lumpnum+ML_SIDEDEFS);
  P_LoadLineDefs  (lumpnum+ML_LINEDEFS);
  P_LoadSideDefs2 (lumpnum+ML_SIDEDEFS);
  P_LoadLineDefs2 (lumpnum+ML_LINEDEFS);
  P_LoadBlockMap  (lumpnum+ML_BLOCKMAP);


    P_LoadSubsectors(lumpnum + ML_SSECTORS);
    P_LoadNodes(lumpnum + ML_NODES);
    P_LoadSegs(lumpnum + ML_SEGS);

    P_GroupLines();

  // reject loading and underflow padding separated out into new function
  // P_GroupLines modified to return a number the underflow padding needs
  P_LoadReject(lumpnum);

  // Note: you don't need to clear player queue slots --
  // a much simpler fix is in g_game.c -- killough 10/98

  /* cph - reset all multiplayer starts */
  memset(_g->playerstarts,0,sizeof(_g->playerstarts));

  for (i = 0; i < MAXPLAYERS; i++)
    _g->player.mo = NULL;

  P_MapStart();

  P_LoadThings(lumpnum+ML_THINGS);

  {
      if (_g->playeringame && !_g->player.mo)
        I_Error("P_SetupLevel: missing player %d start\n", i+1);
  }

  // killough 3/26/98: Spawn icon landings:
  if (_g->gamemode==commercial)
    P_SpawnBrainTargets();

  // set up world state
  P_SpawnSpecials();

  P_MapEnd();

}

//
// P_Init
//
void P_Init (void)
{
    lprintf(LO_INFO, "P_InitSwitchList");
    P_InitSwitchList();

    lprintf(LO_INFO, "P_InitPicAnims");
    P_InitPicAnims();

    lprintf(LO_INFO, "R_InitSprites");
    R_InitSprites(sprnames);
}
