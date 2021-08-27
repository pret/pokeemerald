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
 *      Refresh/rendering module, shared data struct definitions.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __R_DEFS__
#define __R_DEFS__

// Screenwidth.
#include "doomdef.h"

// Some more or less basic data types
// we depend on.
#include "m_fixed.h"

// We rely on the thinker data struct
// to handle sound origins in sectors.
#include "d_think.h"

// SECTORS do store MObjs anyway.
#include "p_mobj.h"

#ifdef __GNUG__
#pragma interface
#endif

// Silhouette, needed for clipping Segs (mainly)
// and sprites representing things.
#define SIL_NONE    0
#define SIL_BOTTOM  1
#define SIL_TOP     2
#define SIL_BOTH    3

#define MAXDRAWSEGS   192

#define MAXOPENINGS (SCREENWIDTH*16)

#define MAXVISSPRITES 96

//
// INTERNAL MAP TYPES
//  used by play and refresh
//

//
// Your plain vanilla vertex.
// Note: transformed values not buffered locally,
// like some DOOM-alikes ("wt", "WebView") do.
//
typedef struct
{
  fixed_t x, y;
} vertex_t;

// Each sector has a degenmobj_t in its center for sound origin purposes.
typedef struct
{
  fixed_t x;
  fixed_t y;
} degenmobj_t;

//
// The SECTORS record, at runtime.
// Stores things/mobjs.
//

typedef struct
{
  fixed_t floorheight;
  fixed_t ceilingheight;

  mobj_t *soundtarget;   // thing that made a sound (or null)
  degenmobj_t soundorg;  // origin for any sounds played by the sector
  int validcount;        // if == validcount, already checked
  mobj_t *thinglist;     // list of mobjs in sector


  // thinker_t for reversable actions
  void *floordata;    // jff 2/22/98 make thinkers on
  void *ceilingdata;  // floors, ceilings, lighting,

  // list of mobjs that are at least partially in the sector
  // thinglist is a subset of touching_thinglist
  struct msecnode_s *touching_thinglist;               // phares 3/14/98

  const struct line_s **lines;

  short linecount;

  short floorpic;
  short ceilingpic;

  short lightlevel;
  short special;
  short oldspecial;      //jff 2/16/98 remembers if sector WAS secret (automap)
  short tag;

  short soundtraversed;    // 0 = untraversed, 1,2 = sndlines-1

} sector_t;

//
// The SideDef.
//

typedef struct
{
    sector_t* sector;      // Sector the SideDef is facing.

    short textureoffset; // add this to the calculated texture column
    short rowoffset;     // add this to the calculated texture top

    short toptexture;      // Texture indices. We do not maintain names here.
    short bottomtexture;
    short midtexture;
} side_t;

//
// Move clipping aid for LineDefs.
//
typedef enum
{
  ST_HORIZONTAL,
  ST_VERTICAL,
  ST_POSITIVE,
  ST_NEGATIVE
} slopetype_t;

typedef enum
{                 // cph:
    RF_TOP_TILE  = 1,     // Upper texture needs tiling
    RF_MID_TILE = 2,     // Mid texture needs tiling
    RF_BOT_TILE = 4,     // Lower texture needs tiling
    RF_IGNORE   = 8,     // Renderer can skip this line
    RF_CLOSED   =16,     // Line blocks view
    RF_MAPPED   =32      // Seen so show on automap.
} r_flags;

//Runtime mutable data for lines.
typedef struct linedata_s
{
    unsigned short validcount;        // if == validcount, already checked
    unsigned short r_validcount;      // cph: if == gametic, r_flags already done

    short special;
    short r_flags;
} linedata_t;

typedef struct line_s
{
    vertex_t v1;
    vertex_t v2;     // Vertices, from v1 to v2.
    unsigned int lineno;         //line number.

    fixed_t dx, dy;        // Precalculated v2 - v1 for side checking.

    unsigned short sidenum[2];        // Visual appearance: SideDefs.
    fixed_t bbox[4];        //Line bounding box.

    unsigned short flags;           // Animation related.
    short const_special;
    short tag;
    short slopetype; // To aid move clipping.

} line_t;

#define LN_FRONTSECTOR(l) (_g->sides[(l)->sidenum[0]].sector)
#define LN_BACKSECTOR(l) ((l)->sidenum[1] != NO_INDEX ? _g->sides[(l)->sidenum[1]].sector : NULL)

#define LN_SPECIAL(l) (_g->linedata[(l)->lineno].special)
#define LN_VCOUNT(l) (_g->linedata[(l)->lineno].validcount)
#define LN_RVCOUNT(l) (_g->linedata[(l)->lineno].r_validcount)
#define LN_RFLAGS(l) (_g->linedata[(l)->lineno].r_flags)


// phares 3/14/98
//
// Sector list node showing all sectors an object appears in.
//
// There are two threads that flow through these nodes. The first thread
// starts at touching_thinglist in a sector_t and flows through the m_snext
// links to find all mobjs that are entirely or partially in the sector.
// The second thread starts at touching_sectorlist in an mobj_t and flows
// through the m_tnext links to find all sectors a thing touches. This is
// useful when applying friction or push effects to sectors. These effects
// can be done as thinkers that act upon all objects touching their sectors.
// As an mobj moves through the world, these nodes are created and
// destroyed, with the links changed appropriately.
//
// For the links, NULL means top or end of list.

typedef struct msecnode_s
{
  sector_t          *m_sector; // a sector containing this object
  struct mobj_s     *m_thing;  // this object
  struct msecnode_s *m_tprev;  // prev msecnode_t for this thing
  struct msecnode_s *m_tnext;  // next msecnode_t for this thing
  struct msecnode_s *m_sprev;  // prev msecnode_t for this sector
  struct msecnode_s *m_snext;  // next msecnode_t for this sector
  boolean visited; // killough 4/4/98, 4/7/98: used in search algorithms
} msecnode_t;

//
// The LineSeg.
//

/*
typedef struct
{
  vertex_t *v1, *v2;
  fixed_t offset;
  angle_t angle;
  side_t* sidedef;
  const line_t* linedef;

  // Sector references.
  // Could be retrieved from linedef, too
  // (but that would be slower -- killough)
  // backsector is NULL for one sided lines

  sector_t *frontsector, *backsector;
} seg_t;
*/

//
// The LineSeg.
//
typedef struct
{
    vertex_t v1;
    vertex_t v2;            // Vertices, from v1 to v2.

    fixed_t offset;
    angle_t angle;

    unsigned short sidenum;
    unsigned short linenum;

    unsigned short frontsectornum;
    unsigned short backsectornum;
} seg_t;

#define SG_FRONTSECTOR(s) ((s)->frontsectornum != NO_INDEX ? &_g->sectors[(s)->frontsectornum] : NULL)
#define SG_BACKSECTOR(s) ((s)->backsectornum != NO_INDEX ? &_g->sectors[(s)->backsectornum] : NULL)

//
// A SubSector.
// References a Sector.
// Basically, this is a list of LineSegs,
//  indicating the visible walls that define
//  (all or some) sides of a convex BSP leaf.
//

typedef struct subsector_s
{
  sector_t *sector;
  unsigned short numlines, firstline;
} subsector_t;

//
// OTHER TYPES
//

// This could be wider for >8 bit display.
// Indeed, true color support is posibble
// precalculating 24bpp lightmap/colormap LUT.
// from darkening PLAYPAL to all black.
// Could use even more than 32 levels.

typedef byte  lighttable_t;

//
// Masked 2s linedefs
//

typedef struct drawseg_s
{
  const seg_t *curline;
  int x1, x2;
  fixed_t scale1, scale2, scalestep;
  int silhouette;                       // 0=none, 1=bottom, 2=top, 3=both
  fixed_t bsilheight;                   // do not clip sprites above this
  fixed_t tsilheight;                   // do not clip sprites below this

  // Pointers to lists for sprite clipping,
  // all three adjusted so [x1] is first value.

  short *sprtopclip, *sprbottomclip;
  short *maskedtexturecol; // dropoff overflow
} drawseg_t;

// Patches.
// A patch holds one or more columns.
// Patches are used for sprites and all masked pictures,
// and we compose textures from the TEXTURE1/2 lists
// of patches.
typedef struct
{
    short		width;		// bounding box size
    short		height;
    short		leftoffset;	// pixels to the left of origin
    short		topoffset;	// pixels below the origin
    int			columnofs[8];	// only [width] used
    // the [0] is &columnofs[width]
} patch_t;


// posts are runs of non masked source pixels
typedef struct
{
    byte		topdelta;	// -1 is the last post in a column
    byte		length; 	// length data bytes follows
} post_t;

// column_t is a list of 0 or more post_t, (byte)-1 terminated
typedef post_t	column_t;

//
// A vissprite_t is a thing that will be drawn during a refresh.
// i.e. a sprite object that is partly visible.
//

typedef struct vissprite_s
{
  short x1, x2;
  fixed_t gx, gy;              // for line side calculation
  fixed_t gz, gzt;             // global bottom / top for silhouette clipping
  fixed_t startfrac;           // horizontal position of x1
  fixed_t scale;
  fixed_t xiscale;             // negative if flipped
  fixed_t texturemid;
  fixed_t iscale;

  const patch_t* patch;

  unsigned int mobjflags;

  // for color translation and shadow draw, maxbright frames as well
  const lighttable_t *colormap;

} vissprite_t;

//
// Sprites are patches with a special naming convention
//  so they can be recognized by R_InitSprites.
// The base name is NNNNFx or NNNNFxFx, with
//  x indicating the rotation, x = 0, 1-7.
// The sprite and frame specified by a thing_t
//  is range checked at run time.
// A sprite is a patch_t that is assumed to represent
//  a three dimensional object and may have multiple
//  rotations pre drawn.
// Horizontal flipping is used to save space,
//  thus NNNNF2F5 defines a mirrored patch.
// Some sprites will only have one picture used
// for all views: NNNNF0
//

typedef struct
{
  // Lump to use for view angles 0-7.
  short lump[8];

  // Flip bit (1 = flip) to use for view angles 0-7.
  //byte  flip[8];
  byte flipmask;

  // If false use 0 for any position.
  // Note: as eight entries are available,
  //  we might as well insert the same name eight times.
  boolean rotate;

} spriteframe_t;

#define SPR_FLIPPED(s, r) (s->flipmask & (1 << r))

//
// A sprite definition:
//  a number of animation frames.
//

typedef struct
{
  int numframes;
  spriteframe_t *spriteframes;
} spritedef_t;

//
// Now what is a visplane, anyway?
//
// Go to http://classicgaming.com/doom/editing/ to find out -- killough
//

typedef struct visplane
{
  struct visplane *next;        // Next visplane in hash chain -- killough
  short picnum, lightlevel;
  short minx, maxx;
  fixed_t height;
  unsigned int modified;

  //byte		pad1;
  // Here lies the rub for all
  //  dynamic resize/change of resolution.
  byte		top[SCREENWIDTH];
  byte		pad2;
  byte		pad3;
  // See above.
  byte		bottom[SCREENWIDTH];
  byte		pad4;

} visplane_t;

#endif
