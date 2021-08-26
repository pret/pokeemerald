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
 *      Rendering main loop and setup functions,
 *       utility functions (BSP, geometry, trigonometry).
 *      See tables.c, too.
 *
 *-----------------------------------------------------------------------------*/

//This is to keep the codesize under control.
//This whole file needs to fit within IWRAM.
#pragma GCC optimize ("Os")


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef __arm__
    #include <time.h>
#endif

#include "doomstat.h"
#include "d_net.h"
#include "w_wad.h"
#include "r_main.h"
#include "r_things.h"
#include "r_plane.h"
#include "r_draw.h"
#include "m_bbox.h"
#include "r_sky.h"
#include "v_video.h"
#include "lprintf.h"
#include "st_stuff.h"
#include "i_main.h"
#include "i_system.h"
#include "g_game.h"
#include "m_random.h"

#include "global_data.h"

#include "gba_functions.h"


//#define static

//*****************************************
//These are unused regions of VRAM.
//We can store things in here to free space
//in IWRAM.
//*****************************************

#ifndef __arm__
static byte vram1_spare[2560];
static byte vram2_spare[2560];
static byte vram3_spare[1024];
#else
    #define vram1_spare ((byte*)0x6000000+0x9600)
    #define vram2_spare ((byte*)0x600A000+0x9600)
    #define vram3_spare ((byte*)0x7000000)
#endif

//Stuff alloc'd in OAM memory.

//512 bytes.
static unsigned int* columnCacheEntries = (unsigned int*)&vram3_spare[0];

//240 bytes.
short* floorclip = (short*)&vram3_spare[512];

//240 bytes.
short* ceilingclip = (short*)&vram3_spare[512+240];



//Stuff alloc'd in VRAM1 memory.

//580 bytes
const fixed_t* yslope_vram = (const fixed_t*)&vram1_spare[0];

//480 bytes
const fixed_t* distscale_vram = (const fixed_t*)&vram1_spare[580];

//484 bytes.
const angle_t* xtoviewangle_vram = (const angle_t*)&vram1_spare[580+480];

#define yslope yslope_vram
#define distscale distscale_vram
#define xtoviewangle xtoviewangle_vram

//*****************************************
//Column cache stuff.
//GBA has 16kb of Video Memory for columns
//*****************************************

#ifndef __arm__
static byte columnCache[128*128];
#else
    #define columnCache ((byte*)0x6014000)
#endif



//*****************************************
//Globals.
//*****************************************

int numnodes;
const mapnode_t *nodes;

fixed_t  viewx, viewy, viewz;

angle_t  viewangle;

static byte solidcol[MAX_SCREENWIDTH];

static byte spanstart[MAX_SCREENHEIGHT];                // killough 2/8/98


static const seg_t     *curline;
static side_t    *sidedef;
static const line_t    *linedef;
static sector_t  *frontsector;
static sector_t  *backsector;
static drawseg_t *ds_p;

static visplane_t *floorplane, *ceilingplane;
static int             rw_angle1;

static angle_t         rw_normalangle; // angle to line origin
static fixed_t         rw_distance;

static int      rw_stopx;

static fixed_t  rw_scale;
static fixed_t  rw_scalestep;

static int      worldtop;
static int      worldbottom;

static int didsolidcol; /* True if at least one column was marked solid */

// True if any of the segs textures might be visible.
static boolean  segtextured;
static boolean  markfloor;      // False if the back side is the same plane.
static boolean  markceiling;
static boolean  maskedtexture;
static int      toptexture;
static int      bottomtexture;
static int      midtexture;

static fixed_t  rw_midtexturemid;
static fixed_t  rw_toptexturemid;
static fixed_t  rw_bottomtexturemid;

const lighttable_t *fullcolormap;
const lighttable_t *colormaps;

const lighttable_t* fixedcolormap;

int extralight;                           // bumped light from gun blasts
draw_vars_t drawvars;

static short   *mfloorclip;   // dropoff overflow
static short   *mceilingclip; // dropoff overflow
static fixed_t spryscale;
static fixed_t sprtopscreen;

static angle_t  rw_centerangle;
static fixed_t  rw_offset;
static int      rw_lightlevel;

static short      *maskedtexturecol; // dropoff overflow

const texture_t **textures; // proff - 04/05/2000 removed static for OpenGL
fixed_t   *textureheight; //needed for texture pegging (and TFE fix - killough)

short       *flattranslation;             // for global animation
short       *texturetranslation;

fixed_t basexscale, baseyscale;

fixed_t  viewcos, viewsin;

static fixed_t  topfrac;
static fixed_t  topstep;
static fixed_t  bottomfrac;
static fixed_t  bottomstep;

static fixed_t  pixhigh;
static fixed_t  pixlow;

static fixed_t  pixhighstep;
static fixed_t  pixlowstep;

static int      worldhigh;
static int      worldlow;

static lighttable_t current_colormap[256];
static const lighttable_t* current_colormap_ptr;

static fixed_t planeheight;

size_t num_vissprite;


//*****************************************
// Constants
//*****************************************

const int viewheight = SCREENHEIGHT-ST_SCALED_HEIGHT;
const int centery = (SCREENHEIGHT-ST_SCALED_HEIGHT)/2;
static const int centerxfrac = (SCREENWIDTH/2) << FRACBITS;
static const int centeryfrac = ((SCREENHEIGHT-ST_SCALED_HEIGHT)/2) << FRACBITS;

const fixed_t projection = (SCREENWIDTH/2) << FRACBITS;

static const fixed_t projectiony = ((SCREENHEIGHT * (SCREENWIDTH/2) * 320) / 200) / SCREENWIDTH * FRACUNIT;

static const fixed_t pspritescale = FRACUNIT*SCREENWIDTH/320;
static const fixed_t pspriteiscale = FRACUNIT*320/SCREENWIDTH;

static const fixed_t pspriteyscale = (((SCREENHEIGHT*SCREENWIDTH)/SCREENWIDTH) << FRACBITS) / 200;
static const fixed_t pspriteyiscale = ((UINT_MAX) / ((((SCREENHEIGHT*SCREENWIDTH)/SCREENWIDTH) << FRACBITS) / 200));


static const angle_t clipangle = 537395200; //xtoviewangle[0];

static const int skytexturemid = 100*FRACUNIT;
static const fixed_t skyiscale = (FRACUNIT*200)/((SCREENHEIGHT-ST_HEIGHT)+16);


//********************************************
// On the GBA we exploit that an 8 bit write
// will mirror to the upper 8 bits too.
// it saves an OR and Shift per pixel.
//********************************************
#ifdef __arm__
    typedef byte pixel;
#else
    typedef unsigned short pixel;
#endif

//********************************************
// This goes here as we want the Thumb code
// to BX to ARM as Thumb long mul is very slow.
//********************************************
inline fixed_t CONSTFUNC FixedMul(fixed_t a, fixed_t b)
{
    return (fixed_t)((int_64_t) a*b >> FRACBITS);
}

// killough 5/3/98: reformatted

static CONSTFUNC int SlopeDiv(unsigned num, unsigned den)
{
    den = den >> 8;

    if (den == 0)
        return SLOPERANGE;

    const unsigned int ans = FixedApproxDiv(num << 3, den) >> FRACBITS;

    return (ans <= SLOPERANGE) ? ans : SLOPERANGE;
}

//
// R_PointOnSide
// Traverse BSP (sub) tree,
//  check point against partition plane.
// Returns side 0 (front) or 1 (back).
//
// killough 5/2/98: reformatted
//

static PUREFUNC int R_PointOnSide(fixed_t x, fixed_t y, const mapnode_t *node)
{
    fixed_t dx = (fixed_t)node->dx << FRACBITS;
    fixed_t dy = (fixed_t)node->dy << FRACBITS;

    fixed_t nx = (fixed_t)node->x << FRACBITS;
    fixed_t ny = (fixed_t)node->y << FRACBITS;

    if (!dx)
        return x <= nx ? node->dy > 0 : node->dy < 0;

    if (!dy)
        return y <= ny ? node->dx < 0 : node->dx > 0;

    x -= nx;
    y -= ny;

    // Try to quickly decide by looking at sign bits.
    if ((dy ^ dx ^ x ^ y) < 0)
        return (dy ^ x) < 0;  // (left is negative)

    return FixedMul(y, node->dx) >= FixedMul(node->dy, x);
}

//
// R_PointInSubsector
//
// killough 5/2/98: reformatted, cleaned up

subsector_t *R_PointInSubsector(fixed_t x, fixed_t y)
{
    int nodenum = numnodes-1;

    // special case for trivial maps (single subsector, no nodes)
    if (numnodes == 0)
        return _g->subsectors;

    while (!(nodenum & NF_SUBSECTOR))
        nodenum = nodes[nodenum].children[R_PointOnSide(x, y, nodes+nodenum)];
    return &_g->subsectors[nodenum & ~NF_SUBSECTOR];
}

//
// R_PointToAngle
// To get a global angle from cartesian coordinates,
//  the coordinates are flipped until they are in
//  the first octant of the coordinate system, then
//  the y (<=x) is scaled and divided by x to get a
//  tangent (slope) value which is looked up in the
//  tantoangle[] table.
//


CONSTFUNC angle_t R_PointToAngle2(fixed_t vx, fixed_t vy, fixed_t x, fixed_t y)
{
    x -= vx;
    y -= vy;

    if ( (!x) && (!y) )
        return 0;

    if (x>= 0)
    {
        // x >=0
        if (y>= 0)
        {
            // y>= 0

            if (x>y)
            {
                // octant 0
                return tantoangle[ SlopeDiv(y,x)];
            }
            else
            {
                // octant 1
                return ANG90-1-tantoangle[ SlopeDiv(x,y)];
            }
        }
        else
        {
            // y<0
            y = -y;

            if (x>y)
            {
                // octant 8
                return -tantoangle[SlopeDiv(y,x)];
            }
            else
            {
                // octant 7
                return ANG270+tantoangle[ SlopeDiv(x,y)];
            }
        }
    }
    else
    {
        // x<0
        x = -x;

        if (y>= 0)
        {
            // y>= 0
            if (x>y)
            {
                // octant 3
                return ANG180-1-tantoangle[ SlopeDiv(y,x)];
            }
            else
            {
                // octant 2
                return ANG90+ tantoangle[ SlopeDiv(x,y)];
            }
        }
        else
        {
            // y<0
            y = -y;

            if (x>y)
            {
                // octant 4
                return ANG180+tantoangle[ SlopeDiv(y,x)];
            }
            else
            {
                // octant 5
                return ANG270-1-tantoangle[ SlopeDiv(x,y)];
            }
        }
    }
}

static CONSTFUNC angle_t R_PointToAngle(fixed_t x, fixed_t y)
{
    return R_PointToAngle2(viewx, viewy, x, y);
}


// killough 5/2/98: move from r_main.c, made static, simplified

static CONSTFUNC fixed_t R_PointToDist(fixed_t x, fixed_t y)
{
    fixed_t dx = D_abs(x - viewx);
    fixed_t dy = D_abs(y - viewy);

    if (dy > dx)
    {
        fixed_t t = dx;
        dx = dy;
        dy = t;
    }

    return FixedApproxDiv(dx, finesine[(tantoangle[FixedApproxDiv(dy,dx) >> DBITS] + ANG90) >> ANGLETOFINESHIFT]);
}

static const lighttable_t* R_ColourMap(int lightlevel)
{
    if (fixedcolormap)
        return fixedcolormap;
    else
    {
        if (curline)
        {
            if (curline->v1.y == curline->v2.y)
                lightlevel -= 1 << LIGHTSEGSHIFT;
            else if (curline->v1.x == curline->v2.x)
                lightlevel += 1 << LIGHTSEGSHIFT;
        }

        lightlevel += (extralight +_g->gamma) << LIGHTSEGSHIFT;

        int cm = ((256-lightlevel)>>2) - 24;

        if(cm >= NUMCOLORMAPS)
            cm = NUMCOLORMAPS-1;
        else if(cm < 0)
            cm = 0;

        return fullcolormap + cm*256;
    }
}


//Load a colormap into IWRAM.
static const lighttable_t* R_LoadColorMap(int lightlevel)
{
    const lighttable_t* lm = R_ColourMap(lightlevel);

    if(current_colormap_ptr != lm)
    {
        BlockCopy(current_colormap, lm, 256);
        current_colormap_ptr = lm;
    }

    return current_colormap;
}

//
// A column is a vertical slice/span from a wall texture that,
//  given the DOOM style restrictions on the view orientation,
//  will always have constant z depth.
// Thus a special case loop for very fast rendering can
//  be used. It has also been used with Wolfenstein 3D.
//

#pragma GCC push_options
#pragma GCC optimize ("Ofast")

#define COLEXTRABITS 9
#define COLBITS (FRACBITS + COLEXTRABITS)

inline static void R_DrawColumnPixel(pixel* dest, const byte* source, const byte* colormap, unsigned int frac)
{
#ifdef __arm__
    *dest = colormap[source[frac>>COLBITS]];
#else
    unsigned int color = colormap[source[frac>>COLBITS]];

    *dest = (color | (color << 8));
#endif
}

static void R_DrawColumn (const draw_column_vars_t *dcvars)
{
    int count = (dcvars->yh - dcvars->yl) + 1;

    // Zero length, column does not exceed a pixel.
    if (count <= 0)
        return;

    const byte *source = dcvars->source;
    const byte *colormap = dcvars->colormap;

    unsigned short* dest = drawvars.byte_topleft + ScreenYToOffset(dcvars->yl) + dcvars->x;

    const unsigned int		fracstep = (dcvars->iscale << COLEXTRABITS);
    unsigned int frac = (dcvars->texturemid + (dcvars->yl - centery)*dcvars->iscale) << COLEXTRABITS;

    // Inner loop that does the actual texture mapping,
    //  e.g. a DDA-lile scaling.
    // This is as fast as it gets.

    unsigned int l = (count >> 4);

    while(l--)
    {
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;

        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;

        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;

        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
    }

    unsigned int r = (count & 15);

    switch(r)
    {
        case 15:    R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 14:    R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 13:    R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 12:    R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 11:    R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 10:    R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 9:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 8:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 7:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 6:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 5:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 4:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 3:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 2:     R_DrawColumnPixel(dest, source, colormap, frac); dest+=SCREENWIDTH; frac+=fracstep;
        case 1:     R_DrawColumnPixel(dest, source, colormap, frac);
    }
}



#define FUZZOFF (SCREENWIDTH)
#define FUZZTABLE 50

static const int fuzzoffset[FUZZTABLE] =
{
    FUZZOFF,-FUZZOFF,FUZZOFF,-FUZZOFF,FUZZOFF,FUZZOFF,-FUZZOFF,
    FUZZOFF,FUZZOFF,-FUZZOFF,FUZZOFF,FUZZOFF,FUZZOFF,-FUZZOFF,
    FUZZOFF,FUZZOFF,FUZZOFF,-FUZZOFF,-FUZZOFF,-FUZZOFF,-FUZZOFF,
    FUZZOFF,-FUZZOFF,-FUZZOFF,FUZZOFF,FUZZOFF,FUZZOFF,FUZZOFF,-FUZZOFF,
    FUZZOFF,-FUZZOFF,FUZZOFF,FUZZOFF,-FUZZOFF,-FUZZOFF,FUZZOFF,
    FUZZOFF,-FUZZOFF,-FUZZOFF,-FUZZOFF,-FUZZOFF,FUZZOFF,FUZZOFF,
    FUZZOFF,FUZZOFF,-FUZZOFF,FUZZOFF,FUZZOFF,-FUZZOFF,FUZZOFF
};

//
// Framebuffer postprocessing.
// Creates a fuzzy image by copying pixels
//  from adjacent ones to left and right.
// Used with an all black colormap, this
//  could create the SHADOW effect,
//  i.e. spectres and invisible players.
//
static void R_DrawFuzzColumn (const draw_column_vars_t *dcvars)
{
    int dc_yl = dcvars->yl;
    int dc_yh = dcvars->yh;

    // Adjust borders. Low...
    if (dc_yl <= 0)
        dc_yl = 1;

    // .. and high.
    if (dc_yh >= viewheight-1)
        dc_yh = viewheight - 2;

    int count = (dc_yh - dc_yl) + 1;

    // Zero length, column does not exceed a pixel.
    if (count <= 0)
        return;

    const byte* colormap = &fullcolormap[6*256];

    unsigned short* dest = drawvars.byte_topleft + ScreenYToOffset(dc_yl) + dcvars->x;

    unsigned int fuzzpos = _g->fuzzpos;

    do
    {        
        R_DrawColumnPixel((pixel*)dest, &dest[fuzzoffset[fuzzpos]], colormap, 0); dest += SCREENWIDTH;  fuzzpos++;

        if(fuzzpos >= 50)
            fuzzpos = 0;

    } while(--count);

    _g->fuzzpos = fuzzpos;
}

#pragma GCC pop_options



//
// R_DrawMaskedColumn
// Used for sprites and masked mid textures.
// Masked means: partly transparent, i.e. stored
//  in posts/runs of opaque pixels.
//
static void R_DrawMaskedColumn(R_DrawColumn_f colfunc, draw_column_vars_t *dcvars, const column_t *column)
{
    const fixed_t basetexturemid = dcvars->texturemid;

    const int fclip_x = mfloorclip[dcvars->x];
    const int cclip_x = mceilingclip[dcvars->x];

    while (column->topdelta != 0xff)
    {
        // calculate unclipped screen coordinates for post
        const int topscreen = sprtopscreen + spryscale*column->topdelta;
        const int bottomscreen = topscreen + spryscale*column->length;

        int yh = (bottomscreen-1)>>FRACBITS;
        int yl = (topscreen+FRACUNIT-1)>>FRACBITS;

        if(yh >= fclip_x)
            yh = fclip_x - 1;

        if(yl <= cclip_x)
            yl = cclip_x + 1;

        // killough 3/2/98, 3/27/98: Failsafe against overflow/crash:
        if (yh < viewheight && yl <= yh)
        {
            dcvars->source =  (const byte*)column + 3;

            dcvars->texturemid = basetexturemid - (column->topdelta<<FRACBITS);

            dcvars->yh = yh;
            dcvars->yl = yl;

            // Drawn by either R_DrawColumn
            //  or (SHADOW) R_DrawFuzzColumn.
            colfunc (dcvars);
        }

        column = (const column_t *)((const byte *)column + column->length + 4);
    }

    dcvars->texturemid = basetexturemid;
}

//
// R_DrawVisSprite
//  mfloorclip and mceilingclip should also be set.
//
// CPhipps - new wad lump handling, *'s to const*'s
static void R_DrawVisSprite(const vissprite_t *vis)
{
    fixed_t  frac;

    R_DrawColumn_f colfunc;
    draw_column_vars_t dcvars;

    R_SetDefaultDrawColumnVars(&dcvars);

    dcvars.colormap = vis->colormap;

    // killough 4/11/98: rearrange and handle translucent sprites
    // mixed with translucent/non-translucenct 2s normals

    if (!dcvars.colormap)   // NULL colormap = shadow draw
        colfunc = R_DrawFuzzColumn;    // killough 3/14/98
    else
    {
        if (vis->mobjflags & MF_TRANSLATION)
        {
            colfunc = R_DrawTranslatedColumn;
            dcvars.translation = translationtables +
                    ((vis->mobjflags & MF_TRANSLATION) >> (MF_TRANSSHIFT-8) );
        }
        else
            colfunc = R_DrawColumn; // killough 3/14/98, 4/11/98
    }

    // proff 11/06/98: Changed for high-res
    dcvars.iscale = vis->iscale;
    dcvars.texturemid = vis->texturemid;
    frac = vis->startfrac;

    spryscale = vis->scale;
    sprtopscreen = centeryfrac - FixedMul(dcvars.texturemid, spryscale);


    const patch_t *patch = vis->patch;

    for (dcvars.x=vis->x1 ; dcvars.x<=vis->x2 ; dcvars.x++, frac += vis->xiscale)
    {
        const column_t* column = (const column_t *) ((const byte *)patch + patch->columnofs[frac >> FRACBITS]);

        R_DrawMaskedColumn(colfunc, &dcvars, column);
    }
}

static const column_t* R_GetColumn(const texture_t* texture, int texcolumn)
{
    const unsigned int patchcount = texture->patchcount;
    const unsigned int widthmask = texture->widthmask;

    const int xc = texcolumn & widthmask;

    if(patchcount == 1)
    {
        //simple texture.
        const patch_t* patch = texture->patches[0].patch;

        return (const column_t *) ((const byte *)patch + patch->columnofs[xc]);
    }
    else
    {
        unsigned int i = 0;

        do
        {
            const texpatch_t* patch = &texture->patches[i];

            const patch_t* realpatch = patch->patch;

            const int x1 = patch->originx;

            if(xc < x1)
                continue;

            const int x2 = x1 + realpatch->width;

            if(xc < x2)
                return (const column_t *)((const byte *)realpatch + realpatch->columnofs[xc-x1]);

        } while(++i < patchcount);
    }

    return NULL;
}


static const texture_t* R_GetOrLoadTexture(int tex_num)
{
    const texture_t* tex = textures[tex_num];

    if(!tex)
        tex = R_GetTexture(tex_num);

    return tex;
}


//
// R_RenderMaskedSegRange
//

static void R_RenderMaskedSegRange(const drawseg_t *ds, int x1, int x2)
{
    int      texnum;
    draw_column_vars_t dcvars;

    R_SetDefaultDrawColumnVars(&dcvars);

    // Calculate light table.
    // Use different light tables
    //   for horizontal / vertical / diagonal. Diagonal?

    curline = ds->curline;  // OPTIMIZE: get rid of LIGHTSEGSHIFT globally

    frontsector = SG_FRONTSECTOR(curline);
    backsector = SG_BACKSECTOR(curline);

    texnum = _g->sides[curline->sidenum].midtexture;
    texnum = texturetranslation[texnum];

    // killough 4/13/98: get correct lightlevel for 2s normal textures
    rw_lightlevel = frontsector->lightlevel;

    maskedtexturecol = ds->maskedtexturecol;

    rw_scalestep = ds->scalestep;
    spryscale = ds->scale1 + (x1 - ds->x1)*rw_scalestep;
    mfloorclip = ds->sprbottomclip;
    mceilingclip = ds->sprtopclip;

    // find positioning
    if (_g->lines[curline->linenum].flags & ML_DONTPEGBOTTOM)
    {
        dcvars.texturemid = frontsector->floorheight > backsector->floorheight
                ? frontsector->floorheight : backsector->floorheight;
        dcvars.texturemid = dcvars.texturemid + textureheight[texnum] - viewz;
    }
    else
    {
        dcvars.texturemid =frontsector->ceilingheight<backsector->ceilingheight
                ? frontsector->ceilingheight : backsector->ceilingheight;
        dcvars.texturemid = dcvars.texturemid - viewz;
    }

    dcvars.texturemid += (_g->sides[curline->sidenum].rowoffset << FRACBITS);

    const texture_t* texture = R_GetOrLoadTexture(texnum);

    dcvars.colormap = R_LoadColorMap(rw_lightlevel);

    // draw the columns
    for (dcvars.x = x1 ; dcvars.x <= x2 ; dcvars.x++, spryscale += rw_scalestep)
    {
        const int xc = maskedtexturecol[dcvars.x];

        if (xc != SHRT_MAX) // dropoff overflow
        {
            sprtopscreen = centeryfrac - FixedMul(dcvars.texturemid, spryscale);

            dcvars.iscale = FixedReciprocal((unsigned)spryscale);

            // draw the texture
            const column_t* column = R_GetColumn(texture, xc);

            R_DrawMaskedColumn(R_DrawColumn, &dcvars, column);

            maskedtexturecol[dcvars.x] = SHRT_MAX; // dropoff overflow
        }
    }

    curline = NULL; /* cph 2001/11/18 - must clear curline now we're done with it, so R_ColourMap doesn't try using it for other things */
}


// killough 5/2/98: reformatted

static PUREFUNC int R_PointOnSegSide(fixed_t x, fixed_t y, const seg_t *line)
{
    const fixed_t lx = line->v1.x;
    const fixed_t ly = line->v1.y;
    const fixed_t ldx = line->v2.x - lx;
    const fixed_t ldy = line->v2.y - ly;

    if (!ldx)
        return x <= lx ? ldy > 0 : ldy < 0;

    if (!ldy)
        return y <= ly ? ldx < 0 : ldx > 0;

    x -= lx;
    y -= ly;

    // Try to quickly decide by looking at sign bits.
    if ((ldy ^ ldx ^ x ^ y) < 0)
        return (ldy ^ x) < 0;          // (left is negative)

    return FixedMul(y, ldx>>FRACBITS) >= FixedMul(ldy>>FRACBITS, x);
}


//
// R_DrawSprite
//

static void R_DrawSprite (const vissprite_t* spr)
{
    short* clipbot = floorclip;
    short* cliptop = ceilingclip;

    fixed_t scale;
    fixed_t lowscale;

    for (int x = spr->x1 ; x<=spr->x2 ; x++)
    {
        clipbot[x] = viewheight;
        cliptop[x] = -1;
    }


    // Scan drawsegs from end to start for obscuring segs.
    // The first drawseg that has a greater scale is the clip seg.

    // Modified by Lee Killough:
    // (pointer check was originally nonportable
    // and buggy, by going past LEFT end of array):

    const drawseg_t* drawsegs  =_g->drawsegs;

    for (const drawseg_t* ds = ds_p; ds-- > drawsegs; )  // new -- killough
    {
        // determine if the drawseg obscures the sprite
        if (ds->x1 > spr->x2 || ds->x2 < spr->x1 || (!ds->silhouette && !ds->maskedtexturecol))
            continue;      // does not cover sprite

        const int r1 = ds->x1 < spr->x1 ? spr->x1 : ds->x1;
        const int r2 = ds->x2 > spr->x2 ? spr->x2 : ds->x2;

        if (ds->scale1 > ds->scale2)
        {
            lowscale = ds->scale2;
            scale = ds->scale1;
        }
        else
        {
            lowscale = ds->scale1;
            scale = ds->scale2;
        }

        if (scale < spr->scale || (lowscale < spr->scale && !R_PointOnSegSide (spr->gx, spr->gy, ds->curline)))
        {
            if (ds->maskedtexturecol)       // masked mid texture?
                R_RenderMaskedSegRange(ds, r1, r2);

            continue;               // seg is behind sprite
        }

        // clip this piece of the sprite
        // killough 3/27/98: optimized and made much shorter

        if (ds->silhouette & SIL_BOTTOM && spr->gz < ds->bsilheight) //bottom sil
        {
            for (int x = r1; x <= r2; x++)
            {
                if (clipbot[x] == viewheight)
                    clipbot[x] = ds->sprbottomclip[x];
            }

        }

        if (ds->silhouette & SIL_TOP && spr->gzt > ds->tsilheight)   // top sil
        {
            for (int x=r1; x <= r2; x++)
            {
                if (cliptop[x] == -1)
                    cliptop[x] = ds->sprtopclip[x];
            }
        }
    }

    // all clipping has been performed, so draw the sprite
    mfloorclip = clipbot;
    mceilingclip = cliptop;
    R_DrawVisSprite (spr);
}


//
// R_DrawPSprite
//

static void R_DrawPSprite (pspdef_t *psp, int lightlevel)
{
    int           x1, x2;
    spritedef_t   *sprdef;
    spriteframe_t *sprframe;
    boolean       flip;
    vissprite_t   *vis;
    vissprite_t   avis;
    int           width;
    fixed_t       topoffset;

    // decide which patch to use
    sprdef = &_g->sprites[psp->state->sprite];

    sprframe = &sprdef->spriteframes[psp->state->frame & FF_FRAMEMASK];

    flip = (boolean) SPR_FLIPPED(sprframe, 0);

    const patch_t* patch = W_CacheLumpNum(sprframe->lump[0]+_g->firstspritelump);
    // calculate edges of the shape
    fixed_t       tx;
    tx = psp->sx-160*FRACUNIT;

    tx -= patch->leftoffset<<FRACBITS;
    x1 = (centerxfrac + FixedMul (tx, pspritescale))>>FRACBITS;

    tx += patch->width<<FRACBITS;
    x2 = ((centerxfrac + FixedMul (tx, pspritescale) ) >>FRACBITS) - 1;

    width = patch->width;
    topoffset = patch->topoffset<<FRACBITS;



    // off the side
    if (x2 < 0 || x1 > SCREENWIDTH)
        return;

    // store information in a vissprite
    vis = &avis;
    vis->mobjflags = 0;
    // killough 12/98: fix psprite positioning problem
    vis->texturemid = (BASEYCENTER<<FRACBITS) /* +  FRACUNIT/2 */ -
            (psp->sy-topoffset);
    vis->x1 = x1 < 0 ? 0 : x1;
    vis->x2 = x2 >= SCREENWIDTH ? SCREENWIDTH-1 : x2;
    // proff 11/06/98: Added for high-res
    vis->scale = pspriteyscale;
    vis->iscale = pspriteyiscale;

    if (flip)
    {
        vis->xiscale = - pspriteiscale;
        vis->startfrac = (width<<FRACBITS)-1;
    }
    else
    {
        vis->xiscale = pspriteiscale;
        vis->startfrac = 0;
    }

    if (vis->x1 > x1)
        vis->startfrac += vis->xiscale*(vis->x1-x1);

    vis->patch = patch;

    if (_g->viewplayer->powers[pw_invisibility] > 4*32 || _g->viewplayer->powers[pw_invisibility] & 8)
        vis->colormap = NULL;                    // shadow draw
    else if (fixedcolormap)
        vis->colormap = fixedcolormap;           // fixed color
    else if (psp->state->frame & FF_FULLBRIGHT)
        vis->colormap = fullcolormap;            // full bright // killough 3/20/98
    else
        vis->colormap = R_LoadColorMap(lightlevel);  // local light

    R_DrawVisSprite(vis);
}



//
// R_DrawPlayerSprites
//

static void R_DrawPlayerSprites(void)
{
  int i, lightlevel = _g->viewplayer->mo->subsector->sector->lightlevel;
  pspdef_t *psp;

  // clip to screen bounds
  mfloorclip = screenheightarray;
  mceilingclip = negonearray;

  // add all active psprites
  for (i=0, psp=_g->viewplayer->psprites; i<NUMPSPRITES; i++,psp++)
    if (psp->state)
      R_DrawPSprite (psp, lightlevel);
}


//
// R_SortVisSprites
//
// Rewritten by Lee Killough to avoid using unnecessary
// linked lists, and to use faster sorting algorithm.
//

//#define bcopyp(d, s, n) memcpy(d, s, (n) * sizeof(void *))
#define bcopyp(d, s, n) BlockCopy(d, s, (n) * sizeof(void *))

// killough 9/2/98: merge sort

static void msort(vissprite_t **s, vissprite_t **t, int n)
{
  if (n >= 16)
    {
      int n1 = n/2, n2 = n - n1;
      vissprite_t **s1 = s, **s2 = s + n1, **d = t;

      msort(s1, t, n1);
      msort(s2, t, n2);

      while ((*s1)->scale > (*s2)->scale ?
             (*d++ = *s1++, --n1) : (*d++ = *s2++, --n2));

      if (n2)
        bcopyp(d, s2, n2);
      else
        bcopyp(d, s1, n1);

      bcopyp(s, t, n);
    }
  else
    {
      int i;
      for (i = 1; i < n; i++)
        {
          vissprite_t *temp = s[i];
          if (s[i-1]->scale < temp->scale)
            {
              int j = i;
              while ((s[j] = s[j-1])->scale < temp->scale && --j);
              s[j] = temp;
            }
        }
    }
}

static void R_SortVisSprites (void)
{
    int i = num_vissprite;

    if (i)
    {
        while (--i>=0)
            _g->vissprite_ptrs[i] = _g->vissprites+i;

        // killough 9/22/98: replace qsort with merge sort, since the keys
        // are roughly in order to begin with, due to BSP rendering.

        msort(_g->vissprite_ptrs, _g->vissprite_ptrs + num_vissprite, num_vissprite);
    }
}

//
// R_DrawMasked
//

static void R_DrawMasked(void)
{
    int i;
    drawseg_t *ds;
    drawseg_t* drawsegs = _g->drawsegs;


    R_SortVisSprites();

    // draw all vissprites back to front
    for (i = num_vissprite ;--i>=0; )
        R_DrawSprite(_g->vissprite_ptrs[i]);         // killough

    // render any remaining masked mid textures

    // Modified by Lee Killough:
    // (pointer check was originally nonportable
    // and buggy, by going past LEFT end of array):
    for (ds=ds_p ; ds-- > drawsegs ; )  // new -- killough
        if (ds->maskedtexturecol)
            R_RenderMaskedSegRange(ds, ds->x1, ds->x2);

    R_DrawPlayerSprites ();
}


//
// R_DrawSpan
// With DOOM style restrictions on view orientation,
//  the floors and ceilings consist of horizontal slices
//  or spans with constant z depth.
// However, rotation around the world z axis is possible,
//  thus this mapping, while simpler and faster than
//  perspective correct texture mapping, has to traverse
//  the texture at an angle in all but a few cases.
// In consequence, flats are not stored by column (like walls),
//  and the inner loop has to step in texture space u and v.
//

#pragma GCC push_options
#pragma GCC optimize ("Ofast")

inline static void R_DrawSpanPixel(pixel* dest, const byte* source, const byte* colormap, unsigned int position)
{
#ifdef __arm__
    *dest = colormap[source[((position >> 4) & 0x0fc0) | (position >> 26)]];
#else
    unsigned int color = colormap[source[((position >> 4) & 0x0fc0) | (position >> 26)]];

    *dest = (color | (color << 8));
#endif
}

static void R_DrawSpan(unsigned int y, unsigned int x1, unsigned int x2, const draw_span_vars_t *dsvars)
{
    unsigned int count = (x2 - x1);

    const byte *source = dsvars->source;
    const byte *colormap = dsvars->colormap;

    unsigned short* dest = drawvars.byte_topleft + ScreenYToOffset(y) + x1;

    const unsigned int step = dsvars->step;
    unsigned int position = dsvars->position;

    unsigned int l = (count >> 4);

    while(l--)
    {
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;

        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;

        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;

        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
    }

    unsigned int r = (count & 15);

    switch(r)
    {
        case 15:    R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 14:    R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 13:    R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 12:    R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 11:    R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 10:    R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 9:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 8:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 7:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 6:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 5:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 4:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 3:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 2:     R_DrawSpanPixel(dest, source, colormap, position); dest++; position+=step;
        case 1:     R_DrawSpanPixel(dest, source, colormap, position);
    }
}

#pragma GCC pop_options

static void R_MapPlane(unsigned int y, unsigned int x1, unsigned int x2, draw_span_vars_t *dsvars)
{    
    const fixed_t distance = FixedMul(planeheight, yslope[y]);
    dsvars->step = ((FixedMul(distance,basexscale) << 10) & 0xffff0000) | ((FixedMul(distance,baseyscale) >> 6) & 0x0000ffff);

    fixed_t length = FixedMul (distance, distscale[x1]);
    angle_t angle = (viewangle + xtoviewangle[x1])>>ANGLETOFINESHIFT;

    // killough 2/28/98: Add offsets
    unsigned int xfrac =  viewx + FixedMul(finecosine[angle], length);
    unsigned int yfrac = -viewy - FixedMul(finesine[angle],   length);

    dsvars->position = ((xfrac << 10) & 0xffff0000) | ((yfrac >> 6)  & 0x0000ffff);

    R_DrawSpan(y, x1, x2, dsvars);
}

//
// R_MakeSpans
//

static void R_MakeSpans(int x, unsigned int t1, unsigned int b1, unsigned int t2, unsigned int b2, draw_span_vars_t *dsvars)
{
    for (; t1 < t2 && t1 <= b1; t1++)
        R_MapPlane(t1, spanstart[t1], x, dsvars);

    for (; b1 > b2 && b1 >= t1; b1--)
        R_MapPlane(b1, spanstart[b1], x, dsvars);

    while (t2 < t1 && t2 <= b2)
        spanstart[t2++] = x;

    while (b2 > b1 && b2 >= t2)
        spanstart[b2--] = x;
}



// New function, by Lee Killough

static void R_DoDrawPlane(visplane_t *pl)
{
    register int x;
    draw_column_vars_t dcvars;

    R_SetDefaultDrawColumnVars(&dcvars);

    if (pl->minx <= pl->maxx)
    {
        if (pl->picnum == _g->skyflatnum)
        { // sky flat

            // Normal Doom sky, only one allowed per level
            dcvars.texturemid = skytexturemid;    // Default y-offset

          /* Sky is always drawn full bright, i.e. colormaps[0] is used.
           * Because of this hack, sky is not affected by INVUL inverse mapping.
           * Until Boom fixed this. Compat option added in MBF. */

            if (!(dcvars.colormap = fixedcolormap))
                dcvars.colormap = fullcolormap;          // killough 3/20/98

            // proff 09/21/98: Changed for high-res
            dcvars.iscale = skyiscale;

            const texture_t* tex = R_GetOrLoadTexture(_g->skytexture);

            // killough 10/98: Use sky scrolling offset
            for (x = pl->minx; (dcvars.x = x) <= pl->maxx; x++)
            {
                if ((dcvars.yl = pl->top[x]) != -1 && dcvars.yl <= (dcvars.yh = pl->bottom[x])) // dropoff overflow
                {
                    int xc = ((viewangle + xtoviewangle[x]) >> ANGLETOSKYSHIFT);

                    const column_t* column = R_GetColumn(tex, xc);

                    dcvars.source = (const byte*)column + 3;
                    R_DrawColumn(&dcvars);
                }
            }
        }
        else
        {     // regular flat

            draw_span_vars_t dsvars;

            dsvars.source = W_CacheLumpNum(_g->firstflat + flattranslation[pl->picnum]);
            dsvars.colormap = R_LoadColorMap(pl->lightlevel);

            planeheight = D_abs(pl->height-viewz);

            const int stop = pl->maxx + 1;

            pl->top[pl->minx-1] = pl->top[stop] = 0xff; // dropoff overflow

            for (x = pl->minx ; x <= stop ; x++)
            {
                R_MakeSpans(x,pl->top[x-1],pl->bottom[x-1], pl->top[x],pl->bottom[x], &dsvars);
            }
        }
    }
}




//*******************************************

//
// R_ScaleFromGlobalAngle
// Returns the texture mapping scale
//  for the current line (horizontal span)
//  at the given angle.
// rw_distance must be calculated first.
//
// killough 5/2/98: reformatted, cleaned up
// CPhipps - moved here from r_main.c

static fixed_t R_ScaleFromGlobalAngle(angle_t visangle)
{
  int     anglea = ANG90 + (visangle-viewangle);
  int     angleb = ANG90 + (visangle-rw_normalangle);

  int     den = FixedMul(rw_distance, finesine[anglea>>ANGLETOFINESHIFT]);

// proff 11/06/98: Changed for high-res
  fixed_t num = FixedMul(projectiony, finesine[angleb>>ANGLETOFINESHIFT]);

  return den > num>>16 ? (num = FixedDiv(num, den)) > 64*FRACUNIT ?
    64*FRACUNIT : num < 256 ? 256 : num : 64*FRACUNIT;
}


//
// R_NewVisSprite
//

static vissprite_t *R_NewVisSprite(void)
{
    if (num_vissprite >= MAXVISSPRITES)
    {
#ifdef RANGECHECK
        I_Error("Vissprite overflow.");
#endif
        return NULL;
    }


    return _g->vissprites + num_vissprite++;
}


//
// R_ProjectSprite
// Generates a vissprite for a thing if it might be visible.
//

static void R_ProjectSprite (mobj_t* thing, int lightlevel)
{
    const fixed_t fx = thing->x;
    const fixed_t fy = thing->y;
    const fixed_t fz = thing->z;

    const fixed_t tr_x = fx - viewx;
    const fixed_t tr_y = fy - viewy;

    const fixed_t tz = FixedMul(tr_x,viewcos)-(-FixedMul(tr_y,viewsin));

    // thing is behind view plane?
    if (tz < MINZ)
        return;

    //Too far away. Always draw Cyberdemon and Spiderdemon. They are big sprites!
    if( (tz > MAXZ) && (thing->type != MT_CYBORG) && (thing->type != MT_SPIDER) )
        return;

    fixed_t tx = -(FixedMul(tr_y,viewcos)+(-FixedMul(tr_x,viewsin)));

    // too far off the side?
    if (D_abs(tx)>(tz<<2))
        return;

    // decide which patch to use for sprite relative to player
    const spritedef_t* sprdef = &_g->sprites[thing->sprite];
    const spriteframe_t* sprframe = &sprdef->spriteframes[thing->frame & FF_FRAMEMASK];

    unsigned int rot = 0;

    if (sprframe->rotate)
    {
        // choose a different rotation based on player view
        angle_t ang = R_PointToAngle(fx, fy);
        rot = (ang-thing->angle+(unsigned)(ANG45/2)*9)>>29;
    }

    const boolean flip = (boolean)SPR_FLIPPED(sprframe, rot);
    const patch_t* patch = W_CacheLumpNum(sprframe->lump[rot] + _g->firstspritelump);

    /* calculate edges of the shape
     * cph 2003/08/1 - fraggle points out that this offset must be flipped
     * if the sprite is flipped; e.g. FreeDoom imp is messed up by this. */
    if (flip)
        tx -= (patch->width - patch->leftoffset) << FRACBITS;
    else
        tx -= patch->leftoffset << FRACBITS;

    const fixed_t xscale = FixedDiv(projection, tz);

    fixed_t xl = (centerxfrac + FixedMul(tx,xscale));

    // off the side?
    if(xl > (SCREENWIDTH << FRACBITS))
        return;

    fixed_t xr = (centerxfrac + FixedMul(tx + (patch->width << FRACBITS),xscale)) - FRACUNIT;

    // off the side?
    if(xr < 0)
        return;

    //Too small.
    if(xr <= (xl + (FRACUNIT >> 2)))
        return;


    const int x1 = (xl >> FRACBITS);
    const int x2 = (xr >> FRACBITS);

    // store information in a vissprite
    vissprite_t* vis = R_NewVisSprite ();

    //No more vissprites.
    if(!vis)
        return;

    vis->mobjflags = thing->flags;
    // proff 11/06/98: Changed for high-res
    vis->scale = FixedDiv(projectiony, tz);
    vis->iscale = tz >> 7;
    vis->patch = patch;
    vis->gx = fx;
    vis->gy = fy;
    vis->gz = fz;
    vis->gzt = fz + (patch->topoffset << FRACBITS);                          // killough 3/27/98
    vis->texturemid = vis->gzt - viewz;
    vis->x1 = x1 < 0 ? 0 : x1;
    vis->x2 = x2 >= SCREENWIDTH ? SCREENWIDTH-1 : x2;


    //const fixed_t iscale = FixedDiv (FRACUNIT, xscale);

    //It simplifies to this.
    //const fixed_t iscale = tz / 60;

    //This is a cheap divide by 60.
    //const fixed_t iscale = (((uint_64_t)tz * 0x8889) >> 16) >> 5;
    const fixed_t iscale = ((tz >> 6) + (tz >> 10)); // -> x/64 + x/1024 is very close to x/60. (Delta -0.4%)

    if (flip)
    {
        vis->startfrac = (patch->width<<FRACBITS)-1;
        vis->xiscale = -iscale;
    }
    else
    {
        vis->startfrac = 0;
        vis->xiscale = iscale;
    }

    if (vis->x1 > x1)
        vis->startfrac += vis->xiscale*(vis->x1-x1);

    // get light level
    if (thing->flags & MF_SHADOW)
        vis->colormap = NULL;             // shadow draw
    else if (fixedcolormap)
        vis->colormap = fixedcolormap;      // fixed map
    else if (thing->frame & FF_FULLBRIGHT)
        vis->colormap = fullcolormap;     // full bright  // killough 3/20/98
    else
    {      // diminished light
        vis->colormap = R_ColourMap(lightlevel);
    }
}

//
// R_AddSprites
// During BSP traversal, this adds sprites by sector.
//
// killough 9/18/98: add lightlevel as parameter, fixing underwater lighting
static void R_AddSprites(subsector_t* subsec, int lightlevel)
{
  sector_t* sec=subsec->sector;
  mobj_t *thing;

  // BSP is traversed by subsector.
  // A sector might have been split into several
  //  subsectors during BSP building.
  // Thus we check whether its already added.

  if (sec->validcount == _g->validcount)
    return;

  // Well, now it will be done.
  sec->validcount = _g->validcount;

  // Handle all things in sector.

  for (thing = sec->thinglist; thing; thing = thing->snext)
    R_ProjectSprite(thing, lightlevel);
}

//
// R_FindPlane
//
// killough 2/28/98: Add offsets


// New function, by Lee Killough

static visplane_t *new_visplane(unsigned hash)
{
    visplane_t *check = _g->freetail;

    if (!check)
        check = Z_Calloc(1, sizeof(visplane_t), PU_LEVEL, NULL);
    else
    {
        if (!(_g->freetail = _g->freetail->next))
            _g->freehead = &_g->freetail;
    }

    check->next = _g->visplanes[hash];
    _g->visplanes[hash] = check;

    return check;
}

static visplane_t *R_FindPlane(fixed_t height, int picnum, int lightlevel)
{
    visplane_t *check;
    unsigned hash;                      // killough

    if (picnum == _g->skyflatnum)
        height = lightlevel = 0;         // killough 7/19/98: most skies map together

    // New visplane algorithm uses hash table -- killough
    hash = visplane_hash(picnum,lightlevel,height);

    for (check=_g->visplanes[hash]; check; check=check->next)  // killough
        if (height == check->height &&
                picnum == check->picnum &&
                lightlevel == check->lightlevel)
            return check;

    check = new_visplane(hash);         // killough

    check->height = height;
    check->picnum = picnum;
    check->lightlevel = lightlevel;
    check->minx = SCREENWIDTH; // Was SCREENWIDTH -- killough 11/98
    check->maxx = -1;

    BlockSet(check->top, UINT_MAX, sizeof(check->top));

    check->modified = 0;

    return check;
}

/*
 * R_DupPlane
 *
 * cph 2003/04/18 - create duplicate of existing visplane and set initial range
 */
static visplane_t *R_DupPlane(const visplane_t *pl, int start, int stop)
{
    unsigned hash = visplane_hash(pl->picnum, pl->lightlevel, pl->height);
    visplane_t *new_pl = new_visplane(hash);

    new_pl->height = pl->height;
    new_pl->picnum = pl->picnum;
    new_pl->lightlevel = pl->lightlevel;
    new_pl->minx = start;
    new_pl->maxx = stop;

    BlockSet(new_pl->top, UINT_MAX, sizeof(new_pl->top));

    new_pl->modified = false;

    return new_pl;
}


//
// R_CheckPlane
//
static visplane_t *R_CheckPlane(visplane_t *pl, int start, int stop)
{
    int intrl, intrh, unionl, unionh, x;

    if (start < pl->minx)
        intrl   = pl->minx, unionl = start;
    else
        unionl  = pl->minx,  intrl = start;

    if (stop  > pl->maxx)
        intrh   = pl->maxx, unionh = stop;
    else
        unionh  = pl->maxx, intrh  = stop;

    for (x=intrl ; x <= intrh && pl->top[x] == 0xff; x++) // dropoff overflow
        ;

    if (x > intrh) { /* Can use existing plane; extend range */
        pl->minx = unionl; pl->maxx = unionh;
        return pl;
    } else /* Cannot use existing plane; create a new one */
        return R_DupPlane(pl,start,stop);
}

static void R_DrawColumnInCache(const column_t* patch, byte* cache, int originy, int cacheheight)
{
    while (patch->topdelta != 0xff)
    {
        const byte* source = (const byte *)patch + 3;
        int count = patch->length;
        int position = originy + patch->topdelta;

        if (position < 0)
        {
            count += position;
            position = 0;
        }

        if (position + count > cacheheight)
            count = cacheheight - position;

        if (count > 0)
            ByteCopy(cache + position, source, count);

        patch = (const column_t *)(  (const byte *)patch + patch->length + 4);
    }
}

/*
 * Draw a column of pixels of the specified texture.
 * If the texture is simple (1 patch, full height) then just draw
 * straight from const patch_t*.
*/

#define CACHE_WAYS 4

#define CACHE_MASK (CACHE_WAYS-1)
#define CACHE_STRIDE (128 / CACHE_WAYS)
#define CACHE_KEY_MASK (CACHE_STRIDE-1)

#define CACHE_ENTRY(c, t) ((c << 16 | t))

#define CACHE_HASH(c, t) (((c >> 1) ^ t) & CACHE_KEY_MASK)

static unsigned int FindColumnCacheItem(unsigned int texture, unsigned int column)
{
    //static unsigned int looks, peeks;
    //looks++;

    unsigned int cx = CACHE_ENTRY(column, texture);

    unsigned int key = CACHE_HASH(column, texture);

    unsigned int* cc = (unsigned int*)&columnCacheEntries[key];

    unsigned int i = key;

    do
    {
        //peeks++;
        unsigned int cy = *cc;

        if((cy == cx) || (cy == 0))
            return i;

        cc+=CACHE_STRIDE;
        i+=CACHE_STRIDE;

    } while(i < 128);


    //No space. Random eviction.
    return ((M_Random() & CACHE_MASK) * CACHE_STRIDE) + key;
}


static const byte* R_ComposeColumn(const unsigned int texture, const texture_t* tex, int texcolumn, unsigned int iscale)
{
    //static int total, misses;

    int colmask = 0xfffe;

    if(tex->width > 8)
    {
        if(iscale > (4 << FRACBITS))
            colmask = 0xfff0;
        else if(iscale > (3 << FRACBITS))
            colmask = 0xfff8;
        else if (iscale > (2 << FRACBITS))
            colmask = 0xfffc;
    }

    const int xc = (texcolumn & colmask) & tex->widthmask;

    unsigned int cachekey = FindColumnCacheItem(texture, xc);

    byte* colcache = &columnCache[cachekey*128];
    unsigned int cacheEntry = columnCacheEntries[cachekey];

    //total++;

    if(cacheEntry != CACHE_ENTRY(xc, texture))
    {
        //misses++;
        byte tmpCache[128];


        columnCacheEntries[cachekey] = CACHE_ENTRY(xc, texture);

        unsigned int i = 0;
        unsigned int patchcount = tex->patchcount;

        do
        {
            const texpatch_t* patch = &tex->patches[i];

            const patch_t* realpatch = patch->patch;

            const int x1 = patch->originx;

            if(xc < x1)
                continue;

            const int x2 = x1 + realpatch->width;

            if(xc < x2)
            {
                const column_t* patchcol = (const column_t *)((const byte *)realpatch + realpatch->columnofs[xc-x1]);

                R_DrawColumnInCache (patchcol,
                                     tmpCache,
                                     patch->originy,
                                     tex->height);

            }

        } while(++i < patchcount);

        //Block copy will drop low 2 bits of len.
        BlockCopy(colcache, tmpCache, (tex->height + 3));
    }

    return colcache;
}

static void R_DrawSegTextureColumn(unsigned int texture, int texcolumn, draw_column_vars_t* dcvars)
{
    const texture_t* tex = R_GetOrLoadTexture(texture);

    if(tex->overlapped == 0)
    {
        const column_t* column = R_GetColumn(tex, texcolumn);

        dcvars->source = (const byte*)column + 3;
    }
    else
    {
        dcvars->source = R_ComposeColumn(texture, tex, texcolumn, dcvars->iscale);
    }

    R_DrawColumn (dcvars);
}

//
// R_RenderSegLoop
// Draws zero, one, or two textures (and possibly a masked texture) for walls.
// Can draw or mark the starting pixel of floor and ceiling textures.
// CALLED: CORE LOOPING ROUTINE.
//

#define HEIGHTBITS 12
#define HEIGHTUNIT (1<<HEIGHTBITS)

static void R_RenderSegLoop (int rw_x)
{
    draw_column_vars_t dcvars;
    fixed_t  texturecolumn = 0;   // shut up compiler warning

    R_SetDefaultDrawColumnVars(&dcvars);

    dcvars.colormap = R_LoadColorMap(rw_lightlevel);

    for ( ; rw_x < rw_stopx ; rw_x++)
    {
        // mark floor / ceiling areas

        int yh = bottomfrac>>HEIGHTBITS;
        int yl = (topfrac+HEIGHTUNIT-1)>>HEIGHTBITS;

        int cc_rwx = ceilingclip[rw_x];
        int fc_rwx = floorclip[rw_x];

        // no space above wall?
        int bottom,top = cc_rwx+1;

        if (yl < top)
            yl = top;

        if (markceiling)
        {
            bottom = yl-1;

            if (bottom >= fc_rwx)
                bottom = fc_rwx-1;

            if (top <= bottom)
            {
                ceilingplane->top[rw_x] = top;
                ceilingplane->bottom[rw_x] = bottom;
                ceilingplane->modified = 1;
            }
            // SoM: this should be set here
            cc_rwx = bottom;
        }

        bottom = fc_rwx-1;
        if (yh > bottom)
            yh = bottom;

        if (markfloor)
        {

            top  = yh < cc_rwx ? cc_rwx : yh;

            if (++top <= bottom)
            {
                floorplane->top[rw_x] = top;
                floorplane->bottom[rw_x] = bottom;
                floorplane->modified = 1;
            }
            // SoM: This should be set here to prevent overdraw
            fc_rwx = top;
        }

        // texturecolumn and lighting are independent of wall tiers
        if (segtextured)
        {
            // calculate texture offset
            angle_t angle =(rw_centerangle+xtoviewangle[rw_x])>>ANGLETOFINESHIFT;

            texturecolumn = rw_offset-FixedMul(finetangent[angle],rw_distance);

            texturecolumn >>= FRACBITS;

            dcvars.x = rw_x;

            dcvars.iscale = FixedReciprocal((unsigned)rw_scale);
        }

        // draw the wall tiers
        if (midtexture)
        {

            dcvars.yl = yl;     // single sided line
            dcvars.yh = yh;
            dcvars.texturemid = rw_midtexturemid;
            //

            R_DrawSegTextureColumn(midtexture, texturecolumn, &dcvars);

            cc_rwx = viewheight;
            fc_rwx = -1;
        }
        else
        {

            // two sided line
            if (toptexture)
            {
                // top wall
                int mid = pixhigh>>HEIGHTBITS;
                pixhigh += pixhighstep;

                if (mid >= fc_rwx)
                    mid = fc_rwx-1;

                if (mid >= yl)
                {
                    dcvars.yl = yl;
                    dcvars.yh = mid;
                    dcvars.texturemid = rw_toptexturemid;

                    R_DrawSegTextureColumn(toptexture, texturecolumn, &dcvars);

                    cc_rwx = mid;
                }
                else
                    cc_rwx = yl-1;
            }
            else  // no top wall
            {

                if (markceiling)
                    cc_rwx = yl-1;
            }

            if (bottomtexture)          // bottom wall
            {
                int mid = (pixlow+HEIGHTUNIT-1)>>HEIGHTBITS;
                pixlow += pixlowstep;

                // no space above wall?
                if (mid <= cc_rwx)
                    mid = cc_rwx+1;

                if (mid <= yh)
                {
                    dcvars.yl = mid;
                    dcvars.yh = yh;
                    dcvars.texturemid = rw_bottomtexturemid;

                    R_DrawSegTextureColumn(bottomtexture, texturecolumn, &dcvars);

                    fc_rwx = mid;
                }
                else
                    fc_rwx = yh+1;
            }
            else        // no bottom wall
            {
                if (markfloor)
                    fc_rwx = yh+1;
            }

            // cph - if we completely blocked further sight through this column,
            // add this info to the solid columns array for r_bsp.c
            if ((markceiling || markfloor) && (fc_rwx <= cc_rwx + 1))
            {
                solidcol[rw_x] = 1;
                didsolidcol = 1;
            }

            // save texturecol for backdrawing of masked mid texture
            if (maskedtexture)
                maskedtexturecol[rw_x] = texturecolumn;
        }

        rw_scale += rw_scalestep;
        topfrac += topstep;
        bottomfrac += bottomstep;

        floorclip[rw_x] = fc_rwx;
        ceilingclip[rw_x] = cc_rwx;
    }
}

static boolean R_CheckOpenings(const int start)
{
    int pos = _g->lastopening - _g->openings;
    int need = (rw_stopx - start)*4 + pos;

#ifdef RANGECHECK
    if(need > MAXOPENINGS)
        I_Error("Openings overflow. Need = %d", need);
#endif

    return need <= MAXOPENINGS;
}

//
// R_StoreWallRange
// A wall segment will be drawn
//  between start and stop pixels (inclusive).
//
static void R_StoreWallRange(const int start, const int stop)
{
    fixed_t hyp;
    angle_t offsetangle;

    // don't overflow and crash
    if (ds_p == &_g->drawsegs[MAXDRAWSEGS])
    {
#ifdef RANGECHECK
        I_Error("Drawsegs overflow.");
#endif
        return;
    }


    linedata_t* linedata = &_g->linedata[curline->linenum];

    // mark the segment as visible for auto map
    linedata->r_flags |= ML_MAPPED;

    sidedef = &_g->sides[curline->sidenum];
    linedef = &_g->lines[curline->linenum];

    // calculate rw_distance for scale calculation
    rw_normalangle = curline->angle + ANG90;

    offsetangle = rw_normalangle-rw_angle1;

    if (D_abs(offsetangle) > ANG90)
        offsetangle = ANG90;

    hyp = (viewx==curline->v1.x && viewy==curline->v1.y)?
                0 : R_PointToDist (curline->v1.x, curline->v1.y);

    rw_distance = FixedMul(hyp, finecosine[offsetangle>>ANGLETOFINESHIFT]);

    int rw_x = ds_p->x1 = start;
    ds_p->x2 = stop;
    ds_p->curline = curline;
    rw_stopx = stop+1;

    //Openings overflow. Nevermind.
    if(!R_CheckOpenings(start))
        return;

    // calculate scale at both ends and step
    ds_p->scale1 = rw_scale = R_ScaleFromGlobalAngle (viewangle + xtoviewangle[start]);

    if (stop > start)
    {
        ds_p->scale2 = R_ScaleFromGlobalAngle (viewangle + xtoviewangle[stop]);
        ds_p->scalestep = rw_scalestep = IDiv32(ds_p->scale2-rw_scale, stop-start);
    }
    else
        ds_p->scale2 = ds_p->scale1;

    // calculate texture boundaries
    //  and decide if floor / ceiling marks are needed

    worldtop = frontsector->ceilingheight - viewz;
    worldbottom = frontsector->floorheight - viewz;

    midtexture = toptexture = bottomtexture = maskedtexture = 0;
    ds_p->maskedtexturecol = NULL;

    if (!backsector)
    {
        // single sided line
        midtexture = texturetranslation[sidedef->midtexture];

        // a single sided line is terminal, so it must mark ends
        markfloor = markceiling = true;

        if (linedef->flags & ML_DONTPEGBOTTOM)
        {         // bottom of texture at bottom
            fixed_t vtop = frontsector->floorheight + textureheight[sidedef->midtexture];
            rw_midtexturemid = vtop - viewz;
        }
        else        // top of texture at top
            rw_midtexturemid = worldtop;

        rw_midtexturemid += FixedMod( (sidedef->rowoffset << FRACBITS), textureheight[midtexture]);

        ds_p->silhouette = SIL_BOTH;
        ds_p->sprtopclip = screenheightarray;
        ds_p->sprbottomclip = negonearray;
        ds_p->bsilheight = INT_MAX;
        ds_p->tsilheight = INT_MIN;
    }
    else      // two sided line
    {
        ds_p->sprtopclip = ds_p->sprbottomclip = NULL;
        ds_p->silhouette = 0;

        if(linedata->r_flags & RF_CLOSED)
        { /* cph - closed 2S line e.g. door */
            // cph - killough's (outdated) comment follows - this deals with both
            // "automap fixes", his and mine
            // killough 1/17/98: this test is required if the fix
            // for the automap bug (r_bsp.c) is used, or else some
            // sprites will be displayed behind closed doors. That
            // fix prevents lines behind closed doors with dropoffs
            // from being displayed on the automap.

            ds_p->silhouette = SIL_BOTH;
            ds_p->sprbottomclip = negonearray;
            ds_p->bsilheight = INT_MAX;
            ds_p->sprtopclip = screenheightarray;
            ds_p->tsilheight = INT_MIN;

        }
        else
        { /* not solid - old code */

            if (frontsector->floorheight > backsector->floorheight)
            {
                ds_p->silhouette = SIL_BOTTOM;
                ds_p->bsilheight = frontsector->floorheight;
            }
            else
                if (backsector->floorheight > viewz)
                {
                    ds_p->silhouette = SIL_BOTTOM;
                    ds_p->bsilheight = INT_MAX;
                }

            if (frontsector->ceilingheight < backsector->ceilingheight)
            {
                ds_p->silhouette |= SIL_TOP;
                ds_p->tsilheight = frontsector->ceilingheight;
            }
            else
                if (backsector->ceilingheight < viewz)
                {
                    ds_p->silhouette |= SIL_TOP;
                    ds_p->tsilheight = INT_MIN;
                }
        }

        worldhigh = backsector->ceilingheight - viewz;
        worldlow = backsector->floorheight - viewz;

        // hack to allow height changes in outdoor areas
        if (frontsector->ceilingpic == _g->skyflatnum && backsector->ceilingpic == _g->skyflatnum)
            worldtop = worldhigh;

        markfloor = worldlow != worldbottom
                || backsector->floorpic != frontsector->floorpic
                || backsector->lightlevel != frontsector->lightlevel
                ;

        markceiling = worldhigh != worldtop
                || backsector->ceilingpic != frontsector->ceilingpic
                || backsector->lightlevel != frontsector->lightlevel
                ;

        if (backsector->ceilingheight <= frontsector->floorheight || backsector->floorheight >= frontsector->ceilingheight)
            markceiling = markfloor = true;   // closed door

        if (worldhigh < worldtop)   // top texture
        {
            toptexture = texturetranslation[sidedef->toptexture];
            rw_toptexturemid = linedef->flags & ML_DONTPEGTOP ? worldtop :
                                                                        backsector->ceilingheight+textureheight[sidedef->toptexture]-viewz;
            rw_toptexturemid += FixedMod( (sidedef->rowoffset << FRACBITS), textureheight[toptexture]);
        }

        if (worldlow > worldbottom) // bottom texture
        {
            bottomtexture = texturetranslation[sidedef->bottomtexture];
            rw_bottomtexturemid = linedef->flags & ML_DONTPEGBOTTOM ? worldtop : worldlow;

            rw_bottomtexturemid += FixedMod( (sidedef->rowoffset << FRACBITS), textureheight[bottomtexture]);
        }

        // allocate space for masked texture tables
        if (sidedef->midtexture)    // masked midtexture
        {
            maskedtexture = true;
            ds_p->maskedtexturecol = maskedtexturecol = _g->lastopening - rw_x;
            _g->lastopening += rw_stopx - rw_x;
        }
    }

    // calculate rw_offset (only needed for textured lines)
    segtextured = ((midtexture | toptexture | bottomtexture | maskedtexture) > 0);

    if (segtextured)
    {
        rw_offset = FixedMul (hyp, -finesine[offsetangle >>ANGLETOFINESHIFT]);

        rw_offset += (sidedef->textureoffset << FRACBITS) + curline->offset;

        rw_centerangle = ANG90 + viewangle - rw_normalangle;

        rw_lightlevel = frontsector->lightlevel;
    }

    // if a floor / ceiling plane is on the wrong side of the view
    // plane, it is definitely invisible and doesn't need to be marked.
    if (frontsector->floorheight >= viewz)       // above view plane
        markfloor = false;
    if (frontsector->ceilingheight <= viewz &&
            frontsector->ceilingpic != _g->skyflatnum)   // below view plane
        markceiling = false;

    // calculate incremental stepping values for texture edges
    worldtop >>= 4;
    worldbottom >>= 4;

    topstep = -FixedMul (rw_scalestep, worldtop);
    topfrac = (centeryfrac>>4) - FixedMul (worldtop, rw_scale);

    bottomstep = -FixedMul (rw_scalestep,worldbottom);
    bottomfrac = (centeryfrac>>4) - FixedMul (worldbottom, rw_scale);

    if (backsector)
    {
        worldhigh >>= 4;
        worldlow >>= 4;

        if (worldhigh < worldtop)
        {
            pixhigh = (centeryfrac>>4) - FixedMul (worldhigh, rw_scale);
            pixhighstep = -FixedMul (rw_scalestep,worldhigh);
        }
        if (worldlow > worldbottom)
        {
            pixlow = (centeryfrac>>4) - FixedMul (worldlow, rw_scale);
            pixlowstep = -FixedMul (rw_scalestep,worldlow);
        }
    }

    // render it
    if (markceiling)
    {
        if (ceilingplane)   // killough 4/11/98: add NULL ptr checks
            ceilingplane = R_CheckPlane (ceilingplane, rw_x, rw_stopx-1);
        else
            markceiling = 0;
    }

    if (markfloor)
    {
        if (floorplane)     // killough 4/11/98: add NULL ptr checks
            /* cph 2003/04/18  - ceilingplane and floorplane might be the same
       * visplane (e.g. if both skies); R_CheckPlane doesn't know about
       * modifications to the plane that might happen in parallel with the check
       * being made, so we have to override it and split them anyway if that is
       * a possibility, otherwise the floor marking would overwrite the ceiling
       * marking, resulting in HOM. */
            if (markceiling && ceilingplane == floorplane)
                floorplane = R_DupPlane (floorplane, rw_x, rw_stopx-1);
            else
                floorplane = R_CheckPlane (floorplane, rw_x, rw_stopx-1);
        else
            markfloor = 0;
    }

    didsolidcol = 0;
    R_RenderSegLoop(rw_x);

    /* cph - if a column was made solid by this wall, we _must_ save full clipping info */
    if (backsector && didsolidcol)
    {
        if (!(ds_p->silhouette & SIL_BOTTOM))
        {
            ds_p->silhouette |= SIL_BOTTOM;
            ds_p->bsilheight = backsector->floorheight;
        }
        if (!(ds_p->silhouette & SIL_TOP))
        {
            ds_p->silhouette |= SIL_TOP;
            ds_p->tsilheight = backsector->ceilingheight;
        }
    }

    // save sprite clipping info
    if ((ds_p->silhouette & SIL_TOP || maskedtexture) && !ds_p->sprtopclip)
    {
        ByteCopy(_g->lastopening, ceilingclip+start, sizeof(short)*(rw_stopx-start));
        ds_p->sprtopclip = _g->lastopening - start;
        _g->lastopening += rw_stopx - start;
    }

    if ((ds_p->silhouette & SIL_BOTTOM || maskedtexture) && !ds_p->sprbottomclip)
    {
        ByteCopy(_g->lastopening, floorclip+start, sizeof(short)*(rw_stopx-start));
        ds_p->sprbottomclip = _g->lastopening - start;
        _g->lastopening += rw_stopx - start;
    }

    if (maskedtexture && !(ds_p->silhouette & SIL_TOP))
    {
        ds_p->silhouette |= SIL_TOP;
        ds_p->tsilheight = INT_MIN;
    }

    if (maskedtexture && !(ds_p->silhouette & SIL_BOTTOM))
    {
        ds_p->silhouette |= SIL_BOTTOM;
        ds_p->bsilheight = INT_MAX;
    }

    ds_p++;
}


// killough 1/18/98 -- This function is used to fix the automap bug which
// showed lines behind closed doors simply because the door had a dropoff.
//
// cph - converted to R_RecalcLineFlags. This recalculates all the flags for
// a line, including closure and texture tiling.

static void R_RecalcLineFlags(void)
{
    linedata_t* linedata = &_g->linedata[linedef->lineno];

    const side_t* side = &_g->sides[curline->sidenum];

    linedata->r_validcount = (_g->gametic & 0xffff);

    /* First decide if the line is closed, normal, or invisible */
    if (!(linedef->flags & ML_TWOSIDED)
            || backsector->ceilingheight <= frontsector->floorheight
            || backsector->floorheight >= frontsector->ceilingheight
            || (
                // if door is closed because back is shut:
                backsector->ceilingheight <= backsector->floorheight

                // preserve a kind of transparent door/lift special effect:
                && (backsector->ceilingheight >= frontsector->ceilingheight ||
                    side->toptexture)

                && (backsector->floorheight <= frontsector->floorheight ||
                    side->bottomtexture)

                // properly render skies (consider door "open" if both ceilings are sky):
                && (backsector->ceilingpic !=_g->skyflatnum ||
                    frontsector->ceilingpic!=_g->skyflatnum)
                )
            )
        linedata->r_flags = (RF_CLOSED | (linedata->r_flags & ML_MAPPED));
    else
    {
        // Reject empty lines used for triggers
        //  and special events.
        // Identical floor and ceiling on both sides,
        // identical light levels on both sides,
        // and no middle texture.
        // CPhipps - recode for speed, not certain if this is portable though
        if (backsector->ceilingheight != frontsector->ceilingheight
                || backsector->floorheight != frontsector->floorheight
                || side->midtexture
                || backsector->ceilingpic != frontsector->ceilingpic
                || backsector->floorpic != frontsector->floorpic
                || backsector->lightlevel != frontsector->lightlevel)
        {
            linedata->r_flags = (linedata->r_flags & ML_MAPPED); return;
        } else
            linedata->r_flags = (RF_IGNORE | (linedata->r_flags & ML_MAPPED));
    }
}



// CPhipps -
// R_ClipWallSegment
//
// Replaces the old R_Clip*WallSegment functions. It draws bits of walls in those
// columns which aren't solid, and updates the solidcol[] array appropriately

static void R_ClipWallSegment(int first, int last, boolean solid)
{
    byte *p;
    while (first < last)
    {
        if (solidcol[first])
        {
            if (!(p = ByteFind(solidcol+first, 0, last-first)))
                return; // All solid

            first = p - solidcol;
        }
        else
        {
            int to;
            if (!(p = ByteFind(solidcol+first, 1, last-first)))
                to = last;
            else
                to = p - solidcol;

            R_StoreWallRange(first, to-1);

            if (solid)
            {
                //memset(solidcol+first,1,to-first);
                ByteSet(solidcol+first, 1, to-first);
            }

            first = to;
        }
    }
}

//
// R_ClearClipSegs
//

//
// R_AddLine
// Clips the given segment
// and adds any visible pieces to the line list.
//

static void R_AddLine (const seg_t *line)
{
    int      x1;
    int      x2;
    angle_t  angle1;
    angle_t  angle2;
    angle_t  span;
    angle_t  tspan;

    curline = line;

    angle1 = R_PointToAngle (line->v1.x, line->v1.y);
    angle2 = R_PointToAngle (line->v2.x, line->v2.y);

    // Clip to view edges.
    span = angle1 - angle2;

    // Back side, i.e. backface culling
    if (span >= ANG180)
        return;

    // Global angle needed by segcalc.
    rw_angle1 = angle1;
    angle1 -= viewangle;
    angle2 -= viewangle;

    tspan = angle1 + clipangle;
    if (tspan > 2*clipangle)
    {
        tspan -= 2*clipangle;

        // Totally off the left edge?
        if (tspan >= span)
            return;

        angle1 = clipangle;
    }

    tspan = clipangle - angle2;
    if (tspan > 2*clipangle)
    {
        tspan -= 2*clipangle;

        // Totally off the left edge?
        if (tspan >= span)
            return;
        angle2 = 0-clipangle;
    }

    // The seg is in the view range,
    // but not necessarily visible.

    angle1 = (angle1+ANG90)>>ANGLETOFINESHIFT;
    angle2 = (angle2+ANG90)>>ANGLETOFINESHIFT;

    // killough 1/31/98: Here is where "slime trails" can SOMETIMES occur:
    x1 = viewangletox[angle1];
    x2 = viewangletox[angle2];

    // Does not cross a pixel?
    if (x1 >= x2)       // killough 1/31/98 -- change == to >= for robustness
        return;

    backsector = SG_BACKSECTOR(line);

    /* cph - roll up linedef properties in flags */
    linedef = &_g->lines[curline->linenum];
    linedata_t* linedata = &_g->linedata[linedef->lineno];

    if (linedata->r_validcount != (_g->gametic & 0xffff))
        R_RecalcLineFlags();

    if (linedata->r_flags & RF_IGNORE)
    {
        return;
    }
    else
        R_ClipWallSegment (x1, x2, linedata->r_flags & RF_CLOSED);
}

//
// R_Subsector
// Determine floor/ceiling planes.
// Add sprites of things in sector.
// Draw one or more line segments.
//
// killough 1/31/98 -- made static, polished

static void R_Subsector(int num)
{
    int         count;
    const seg_t       *line;
    subsector_t *sub;

    sub = &_g->subsectors[num];
    frontsector = sub->sector;
    count = sub->numlines;
    line = &_g->segs[sub->firstline];

    if(frontsector->floorheight < viewz)
    {
        floorplane = R_FindPlane(frontsector->floorheight,
                                     frontsector->floorpic,
                                     frontsector->lightlevel                // killough 3/16/98
                                     );
    }
    else
    {
        floorplane = NULL;
    }


    if(frontsector->ceilingheight > viewz || (frontsector->ceilingpic == _g->skyflatnum))
    {
        ceilingplane = R_FindPlane(frontsector->ceilingheight,     // killough 3/8/98
                                       frontsector->ceilingpic,
                                       frontsector->lightlevel
                                       );
    }
    else
    {
        ceilingplane = NULL;
    }

    R_AddSprites(sub, frontsector->lightlevel);
    while (count--)
    {
        R_AddLine (line);
        line++;
        curline = NULL; /* cph 2001/11/18 - must clear curline now we're done with it, so R_ColourMap doesn't try using it for other things */
    }
}

//
// R_CheckBBox
// Checks BSP node/subtree bounding box.
// Returns true
//  if some part of the bbox might be visible.
//

static const byte checkcoord[12][4] = // killough -- static const
{
  {3,0,2,1},
  {3,0,2,0},
  {3,1,2,0},
  {0},
  {2,0,2,1},
  {0,0,0,0},
  {3,1,3,0},
  {0},
  {2,0,3,1},
  {2,1,3,1},
  {2,1,3,0}
};

// killough 1/28/98: static // CPhipps - const parameter, reformatted
static boolean R_CheckBBox(const short *bspcoord)
{
    angle_t angle1, angle2;

    {
        int        boxpos;
        const byte* check;

        // Find the corners of the box
        // that define the edges from current viewpoint.
        boxpos = (viewx <= ((fixed_t)bspcoord[BOXLEFT]<<FRACBITS) ? 0 : viewx < ((fixed_t)bspcoord[BOXRIGHT]<<FRACBITS) ? 1 : 2) +
                (viewy >= ((fixed_t)bspcoord[BOXTOP]<<FRACBITS) ? 0 : viewy > ((fixed_t)bspcoord[BOXBOTTOM]<<FRACBITS) ? 4 : 8);

        if (boxpos == 5)
            return true;

        check = checkcoord[boxpos];
        angle1 = R_PointToAngle (((fixed_t)bspcoord[check[0]]<<FRACBITS), ((fixed_t)bspcoord[check[1]]<<FRACBITS)) - viewangle;
        angle2 = R_PointToAngle (((fixed_t)bspcoord[check[2]]<<FRACBITS), ((fixed_t)bspcoord[check[3]]<<FRACBITS)) - viewangle;
    }

    // cph - replaced old code, which was unclear and badly commented
    // Much more efficient code now
    if ((signed)angle1 < (signed)angle2)
    { /* it's "behind" us */
        /* Either angle1 or angle2 is behind us, so it doesn't matter if we
     * change it to the corect sign
     */
        if ((angle1 >= ANG180) && (angle1 < ANG270))
            angle1 = INT_MAX; /* which is ANG180-1 */
        else
            angle2 = INT_MIN;
    }

    if ((signed)angle2 >= (signed)clipangle) return false; // Both off left edge
    if ((signed)angle1 <= -(signed)clipangle) return false; // Both off right edge
    if ((signed)angle1 >= (signed)clipangle) angle1 = clipangle; // Clip at left edge
    if ((signed)angle2 <= -(signed)clipangle) angle2 = 0-clipangle; // Clip at right edge

    // Find the first clippost
    //  that touches the source post
    //  (adjacent pixels are touching).
    angle1 = (angle1+ANG90)>>ANGLETOFINESHIFT;
    angle2 = (angle2+ANG90)>>ANGLETOFINESHIFT;
    {
        int sx1 = viewangletox[angle1];
        int sx2 = viewangletox[angle2];
        //    const cliprange_t *start;

        // Does not cross a pixel.
        if (sx1 == sx2)
            return false;

        if (!ByteFind(solidcol+sx1, 0, sx2-sx1)) return false;
        // All columns it covers are already solidly covered
    }

    return true;
}

//Render a BSP subsector if bspnum is a leaf node.
//Return false if bspnum is frame node.





static boolean R_RenderBspSubsector(int bspnum)
{
    // Found a subsector?
    if (bspnum & NF_SUBSECTOR)
    {
        if (bspnum == -1)
            R_Subsector (0);
        else
            R_Subsector (bspnum & (~NF_SUBSECTOR));

        return true;
    }

    return false;
}

// RenderBSPNode
// Renders all subsectors below a given node,
//  traversing subtree recursively.
// Just call with BSP root.

//Non recursive version.
//constant stack space used and easier to
//performance profile.
#define MAX_BSP_DEPTH 128

static void R_RenderBSPNode(int bspnum)
{
    int stack[MAX_BSP_DEPTH];
    int sp = 0;

    const mapnode_t* bsp;
    int side = 0;

    while(true)
    {
        //Front sides.
        while (!R_RenderBspSubsector(bspnum))
        {
            if(sp == MAX_BSP_DEPTH)
                break;

            bsp = &nodes[bspnum];
            side = R_PointOnSide (viewx, viewy, bsp);

            stack[sp++] = bspnum;
            stack[sp++] = side;

            bspnum = bsp->children[side];
        }

        if(sp == 0)
        {
            //back at root node and not visible. All done!
            return;
        }

        //Back sides.
        side = stack[--sp];
        bspnum = stack[--sp];
        bsp = &nodes[bspnum];

        // Possibly divide back space.
        //Walk back up the tree until we find
        //a node that has a visible backspace.
        while(!R_CheckBBox (bsp->bbox[side^1]))
        {
            if(sp == 0)
            {
                //back at root node and not visible. All done!
                return;
            }

            //Back side next.
            side = stack[--sp];
            bspnum = stack[--sp];

            bsp = &nodes[bspnum];
        }

        bspnum = bsp->children[side^1];
    }
}


static void R_ClearDrawSegs(void)
{
    ds_p = _g->drawsegs;
}

static void R_ClearClipSegs (void)
{
    BlockSet(solidcol, 0, SCREENWIDTH);
}

//
// R_ClearSprites
// Called at frame start.
//

static void R_ClearSprites(void)
{
    num_vissprite = 0;            // killough
}

//
// RDrawPlanes
// At the end of each frame.
//

static void R_DrawPlanes (void)
{
    for (int i=0; i<MAXVISPLANES; i++)
    {
        visplane_t *pl = _g->visplanes[i];

        while(pl)
        {
            if(pl->modified)
                R_DoDrawPlane(pl);

            pl = pl->next;
        }
    }
}

//
// R_ClearPlanes
// At begining of frame.
//

static void R_ClearPlanes(void)
{
    int i;

    // opening / clipping determination
    for (i=0 ; i<SCREENWIDTH ; i++)
        floorclip[i] = viewheight, ceilingclip[i] = -1;


    for (i=0;i<MAXVISPLANES;i++)    // new code -- killough
        for (*_g->freehead = _g->visplanes[i], _g->visplanes[i] = NULL; *_g->freehead; )
            _g->freehead = &(*_g->freehead)->next;

    _g->lastopening = _g->openings;

    // scale will be unit scale at SCREENWIDTH/2 distance
    //basexscale = FixedDiv (viewsin,projection);
    //baseyscale = FixedDiv (viewcos,projection);

    basexscale = FixedMul(viewsin,iprojection);
    baseyscale = FixedMul(viewcos,iprojection);
}

//
// R_RenderView
//
void R_RenderPlayerView (player_t* player)
{
    R_SetupFrame (player);

    // Clear buffers.
    R_ClearClipSegs ();
    R_ClearDrawSegs ();
    R_ClearPlanes ();
    R_ClearSprites ();

    // The head node is the last node output.
    R_RenderBSPNode (numnodes-1);

    R_DrawPlanes ();

    R_DrawMasked ();
}

void V_DrawPatchNoScale(int x, int y, const patch_t* patch)
{
    y -= patch->topoffset;
    x -= patch->leftoffset;

    byte* desttop = (byte*)_g->screens[0].data;
    desttop += (ScreenYToOffset(y) << 1) + x;

    unsigned int width = patch->width;

    for (unsigned int col = 0; col < width; col++, desttop++)
    {
        const column_t* column = (const column_t*)((const byte*)patch + patch->columnofs[col]);

        unsigned int odd_addr = (unsigned int)desttop & 1;

        byte* desttop_even = (byte*)((unsigned int)desttop & 0xfffffffe);

        // step through the posts in a column
        while (column->topdelta != 0xff)
        {
            const byte* source = (const byte*)column + 3;
            byte* dest = desttop_even + (ScreenYToOffset(column->topdelta) << 1);

            unsigned int count = column->length;


            while (count--)
            {
                unsigned int color = *source++;
                unsigned short* dest16 = (unsigned short*)dest;

                unsigned int old = *dest16;

                //The GBA must write in 16bits.
                if(odd_addr)
                    *dest16 = (old & 0xff) | (color << 8);
                else
                    *dest16 = ((color & 0xff) | (old & 0xff00));

                dest += 240;
            }

            column = (const column_t*)((const byte*)column + column->length + 4);
        }
    }
}






//
// P_DivlineSide
// Returns side 0 (front), 1 (back), or 2 (on).
//
// killough 4/19/98: made static, cleaned up

static int P_DivlineSide(fixed_t x, fixed_t y, const divline_t *node)
{
  fixed_t left, right;
  return
    !node->dx ? x == node->x ? 2 : x <= node->x ? node->dy > 0 : node->dy < 0 :
    !node->dy ? (y) == node->y ? 2 : y <= node->y ? node->dx < 0 : node->dx > 0 :
    (right = ((y - node->y) >> FRACBITS) * (node->dx >> FRACBITS)) <
    (left  = ((x - node->x) >> FRACBITS) * (node->dy >> FRACBITS)) ? 0 :
    right == left ? 2 : 1;
}

//
// P_CrossSubsector
// Returns true
//  if strace crosses the given subsector successfully.
//
// killough 4/19/98: made static and cleaned up

static boolean P_CrossSubsector(int num)
{
    const seg_t *seg = _g->segs + _g->subsectors[num].firstline;
    int count;
    fixed_t opentop = 0, openbottom = 0;
    const sector_t *front = NULL, *back = NULL;

    for (count = _g->subsectors[num].numlines; --count >= 0; seg++)
    { // check lines
        int linenum = seg->linenum;

        const line_t *line = &_g->lines[linenum];
        divline_t divl;

        // allready checked other side?
        if(_g->linedata[linenum].validcount == _g->validcount)
            continue;

        _g->linedata[linenum].validcount = _g->validcount;

        if (line->bbox[BOXLEFT] > _g->los.bbox[BOXRIGHT ] ||
                line->bbox[BOXRIGHT] < _g->los.bbox[BOXLEFT  ] ||
                line->bbox[BOXBOTTOM] > _g->los.bbox[BOXTOP   ] ||
                line->bbox[BOXTOP]    < _g->los.bbox[BOXBOTTOM])
            continue;

        // cph - do what we can before forced to check intersection
        if (line->flags & ML_TWOSIDED)
        {

            // no wall to block sight with?
            if ((front = SG_FRONTSECTOR(seg))->floorheight == (back = SG_BACKSECTOR(seg))->floorheight && front->ceilingheight == back->ceilingheight)
                continue;

            // possible occluder
            // because of ceiling height differences
            opentop = front->ceilingheight < back->ceilingheight ?
                        front->ceilingheight : back->ceilingheight ;

            // because of floor height differences
            openbottom = front->floorheight > back->floorheight ?
                        front->floorheight : back->floorheight ;

            // cph - reject if does not intrude in the z-space of the possible LOS
            if ((opentop >= _g->los.maxz) && (openbottom <= _g->los.minz))
                continue;
        }

        // Forget this line if it doesn't cross the line of sight
        const vertex_t *v1,*v2;

        v1 = &line->v1;
        v2 = &line->v2;

        if (P_DivlineSide(v1->x, v1->y, &_g->los.strace) == P_DivlineSide(v2->x, v2->y, &_g->los.strace))
            continue;

        divl.dx = v2->x - (divl.x = v1->x);
        divl.dy = v2->y - (divl.y = v1->y);

        // line isn't crossed?
        if (P_DivlineSide(_g->los.strace.x, _g->los.strace.y, &divl) == P_DivlineSide(_g->los.t2x, _g->los.t2y, &divl))
            continue;


        // cph - if bottom >= top or top < minz or bottom > maxz then it must be
        // solid wrt this LOS
        if (!(line->flags & ML_TWOSIDED) || (openbottom >= opentop) ||
                (opentop < _g->los.minz) || (openbottom > _g->los.maxz))
            return false;

        // crosses a two sided line
        /* cph 2006/07/15 - oops, we missed this in 2.4.0 & .1;
       *  use P_InterceptVector2 for those compat levels only. */
        fixed_t frac = P_InterceptVector2(&_g->los.strace, &divl);

        if (front->floorheight != back->floorheight)
        {
            fixed_t slope = FixedDiv(openbottom - _g->los.sightzstart , frac);
            if (slope > _g->los.bottomslope)
                _g->los.bottomslope = slope;
        }

        if (front->ceilingheight != back->ceilingheight)
        {
            fixed_t slope = FixedDiv(opentop - _g->los.sightzstart , frac);
            if (slope < _g->los.topslope)
                _g->los.topslope = slope;
        }

        if (_g->los.topslope <= _g->los.bottomslope)
            return false;               // stop

    }
    // passed the subsector ok
    return true;
}

boolean P_CrossBSPNode(int bspnum)
{
    while (!(bspnum & NF_SUBSECTOR))
    {
        const mapnode_t *bsp = nodes + bspnum;

        divline_t dl;
        dl.x = ((fixed_t)bsp->x << FRACBITS);
        dl.y = ((fixed_t)bsp->y << FRACBITS);
        dl.dx = ((fixed_t)bsp->dx << FRACBITS);
        dl.dy = ((fixed_t)bsp->dy << FRACBITS);

        int side,side2;
        side = P_DivlineSide(_g->los.strace.x,_g->los.strace.y,&dl)&1;
        side2= P_DivlineSide(_g->los.t2x, _g->los.t2y, &dl);

        if (side == side2)
            bspnum = bsp->children[side]; // doesn't touch the other side
        else         // the partition plane is crossed here
            if (!P_CrossBSPNode(bsp->children[side]))
                return 0;  // cross the starting side
            else
                bspnum = bsp->children[side^1];  // cross the ending side
    }
    return P_CrossSubsector(bspnum == -1 ? 0 : bspnum & ~NF_SUBSECTOR);
}



//
// P_MobjThinker
//

void P_NightmareRespawn(mobj_t* mobj);
void P_XYMovement (mobj_t* mo);
void P_ZMovement (mobj_t* mo);


//
// P_SetMobjState
// Returns true if the mobj is still present.
//

boolean P_SetMobjState(mobj_t* mobj, statenum_t state)
{
    const state_t*	st;

    do
    {
        if (state == S_NULL)
        {
            mobj->state = (state_t *) S_NULL;
            P_RemoveMobj (mobj);
            return false;
        }

        st = &states[state];
        mobj->state = st;
        mobj->tics = st->tics;
        mobj->sprite = st->sprite;
        mobj->frame = st->frame;

        // Modified handling.
        // Call action functions when the state is set
        if(st->action)
        {
            if(!(_g->player.cheats & CF_ENEMY_ROCKETS))
            {
                st->action(mobj);
            }
            else
            {
                if(mobj->info->missilestate && (state >= mobj->info->missilestate) && (state < mobj->info->painstate))
                    A_CyberAttack(mobj);
                else
                    st->action(mobj);
            }
        }

        state = st->nextstate;

    } while (!mobj->tics);

    return true;
}



void P_MobjThinker (mobj_t* mobj)
{
    // killough 11/98:
    // removed old code which looked at target references
    // (we use pointer reference counting now)

    // momentum movement
    if (mobj->momx | mobj->momy || mobj->flags & MF_SKULLFLY)
    {
        P_XYMovement(mobj);
        if (mobj->thinker.function != P_MobjThinker) // cph - Must've been removed
            return;       // killough - mobj was removed
    }

    if (mobj->z != mobj->floorz || mobj->momz)
    {
        P_ZMovement(mobj);
        if (mobj->thinker.function != P_MobjThinker) // cph - Must've been removed
            return;       // killough - mobj was removed
    }

    // cycle through states,
    // calling action functions at transitions

    if (mobj->tics != -1)
    {
        mobj->tics--;

        // you can cycle through multiple states in a tic

        if (!mobj->tics)
            if (!P_SetMobjState (mobj, mobj->state->nextstate) )
                return;     // freed itself
    }
    else
    {

        // check for nightmare respawn

        if (! (mobj->flags & MF_COUNTKILL) )
            return;

        if (!_g->respawnmonsters)
            return;

        mobj->movecount++;

        if (mobj->movecount < 12*35)
            return;

        if (_g->leveltime & 31)
            return;

        if (P_Random () > 4)
            return;

        P_NightmareRespawn (mobj);
    }

}


//
// P_RunThinkers
//
// killough 4/25/98:
//
// Fix deallocator to stop using "next" pointer after node has been freed
// (a Doom bug).
//
// Process each thinker. For thinkers which are marked deleted, we must
// load the "next" pointer prior to freeing the node. In Doom, the "next"
// pointer was loaded AFTER the thinker was freed, which could have caused
// crashes.
//
// But if we are not deleting the thinker, we should reload the "next"
// pointer after calling the function, in case additional thinkers are
// added at the end of the list.
//
// killough 11/98:
//
// Rewritten to delete nodes implicitly, by making currentthinker
// external and using P_RemoveThinkerDelayed() implicitly.
//

void P_RunThinkers (void)
{
    thinker_t* th = thinkercap.next;
    thinker_t* th_end = &thinkercap;

    while(th != th_end)
    {
        thinker_t* th_next = th->next;
        if(th->function)
            th->function(th);

        th = th_next;
    }
}



static int I_GetTime_e32(void)
{
    int thistimereply = *((unsigned short*)(0x400010C));

    return thistimereply;
}


int I_GetTime(void)
{
    int thistimereply;

#ifndef __arm__

    clock_t now = clock();

    thistimereply = (int)((double)now / ((double)CLOCKS_PER_SEC / (double)TICRATE));
#else
    thistimereply = I_GetTime_e32();
#endif

    if (thistimereply < _g->lasttimereply)
    {
        _g->basetime -= 0xffff;
    }

    _g->lasttimereply = thistimereply;


    /* Fix for time problem */
    if (!_g->basetime)
    {
        _g->basetime = thistimereply;
        thistimereply = 0;
    }
    else
    {
        thistimereply -= _g->basetime;
    }

    return thistimereply;
}


