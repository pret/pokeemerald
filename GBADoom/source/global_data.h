#ifndef GLOBAL_DATA_H
#define GLOBAL_DATA_H

#include "doomstat.h"
#include "doomdef.h"
#include "m_fixed.h"
#include "am_map.h"
#include "g_game.h"
#include "hu_lib.h"
#include "hu_stuff.h"
#include "r_defs.h"
#include "i_sound.h"
#include "m_menu.h"
#include "p_spec.h"
#include "p_enemy.h"
#include "p_map.h"
#include "p_maputl.h"

#include "p_mobj.h"
#include "p_tick.h"

#include "r_draw.h"
#include "r_main.h"
#include "r_plane.h"
#include "r_things.h"

#include "s_sound.h"

#include "st_lib.h"
#include "st_stuff.h"

#include "v_video.h"

#include "w_wad.h"

#include "wi_stuff.h"


typedef struct globals_t
{
#ifndef GLOBAL_DEFS_H
#define GLOBAL_DEFS_H

//******************************************************************************
//am_map.c
//******************************************************************************

enum automapmode_e automapmode; // Mode that the automap is in

// location of window on screen
int  f_x;
int  f_y;

// size of window on screen
int  f_w;
int  f_h;

mpoint_t m_paninc;    // how far the window pans each tic (map coords)

fixed_t m_x, m_y;     // LL x,y window location on the map (map coords)
fixed_t m_x2, m_y2;   // UR x,y window location on the map (map coords)

//
// width/height of window on map (map coords)
//
fixed_t  m_w;
fixed_t  m_h;

// based on level size
fixed_t  min_x;
fixed_t  min_y;
fixed_t  max_x;
fixed_t  max_y;

fixed_t  max_w;          // max_x-min_x,
fixed_t  max_h;          // max_y-min_y

fixed_t  min_scale_mtof; // used to tell when to stop zooming out
fixed_t  max_scale_mtof; // used to tell when to stop zooming in

// old location used by the Follower routine
mpoint_t f_oldloc;

// used by MTOF to scale from map-to-frame-buffer coords
fixed_t scale_mtof;
// used by FTOM to scale from frame-buffer-to-map coords (=1/scale_mtof)
fixed_t scale_ftom;

int lastlevel, lastepisode;

boolean stopped;

fixed_t mtof_zoommul; // how far the window zooms each tic (map coords)
fixed_t ftom_zoommul; // how far the window zooms each tic (fb coords)

//******************************************************************************
//d_client.c
//******************************************************************************

ticcmd_t         netcmd;
int maketic;
int lastmadetic;

//******************************************************************************
//d_main.c
//******************************************************************************

// wipegamestate can be set to -1 to force a wipe on the next draw
gamestate_t    wipegamestate;
gamestate_t oldgamestate;

int  demosequence;         // killough 5/2/98: made static
int  pagetic;
int pagelump; // CPhipps - const

boolean singletics; // debug flag to cancel adaptiveness
boolean advancedemo;

unsigned int gamma;

//fps counter stuff

unsigned int fps_timebefore;
unsigned int fps_frames;
unsigned int fps_framerate;
boolean fps_show;

//******************************************************************************
//doomstat.c
//******************************************************************************

// Game Mode - identify IWAD as shareware, retail etc.
GameMode_t gamemode;
GameMission_t   gamemission;


//******************************************************************************
//f_finale.c
//******************************************************************************


// Stage of animation:
//  0 = text, 1 = art screen, 2 = character cast
int finalestage; // cph -
int finalecount; // made static
const char*   finaletext; // cph -
const char*   finaleflat; // made static const

int             castnum;
int             casttics;
const state_t*  caststate;
int             castframes;
int             castonmelee;


int midstage;                 // whether we're in "mid-stage"
int  laststage;

boolean         castattacking;
boolean         castdeath;

//******************************************************************************
//f_wipe.c
//******************************************************************************

int wipe_tick;

//******************************************************************************
//g_game.c
//******************************************************************************

const byte *demobuffer;   /* cph - only used for playback */
int demolength; // check for overrun (missing DEMOMARKER)

const byte *demo_p;

gameaction_t    gameaction;
gamestate_t     gamestate;
skill_t         gameskill;

int             gameepisode;
int             gamemap;

player_t        player;

int             starttime;     // for comparative timing purposes

int             gametic;
int             basetic;       /* killough 9/29/98: for demo sync */
int             totalkills, totallive, totalitems, totalsecret;    // for intermission
int             demover;
wbstartstruct_t wminfo;               // parms for world map / intermission
int             totalleveltimes;      // CPhipps - total time for all completed levels
int             longtics;


// CPhipps - made lots of key/button state vars static
boolean gamekeydown[NUMKEYS];
int     turnheld;       // for accelerative turning

// Game events info
buttoncode_t special_event; // Event triggered by local player, to send

gamestate_t prevgamestate;

skill_t d_skill;
int     d_episode;
int     d_map;

byte  savegameslot;         // Slot to load if gameaction == ga_loadgame


boolean secretexit;

boolean         respawnmonsters;
boolean         paused;
// CPhipps - moved *_loadgame vars here
boolean command_loadgame;

boolean         usergame;      // ok to save / end game
boolean         timingdemo;    // if true, exit with report on completion
boolean         playeringame;
boolean         demoplayback;
boolean         singledemo;           // quit after playing a demo from cmdline
boolean         haswolflevels;// jff 4/18/98 wolf levels present


//******************************************************************************
//hu_stuff.c
//******************************************************************************

// font sets
const patch_t* hu_font[HU_FONTSIZE];

// widgets
hu_textline_t  w_title;
hu_stext_t     w_message;
int        message_counter;

boolean    message_on;
boolean    message_dontfuckwithme;
boolean    headsupactive;

//******************************************************************************
//i_audio.c
//******************************************************************************

boolean sound_inited;

unsigned int music_looping;
unsigned int music_volume;
unsigned int music_init;

int lasttimereply;
int basetime;



//******************************************************************************
//i_video.c
//******************************************************************************

const unsigned char* current_pallete;
const unsigned char* pallete_lump;
int newpal;

//******************************************************************************
//m_cheat.c
//******************************************************************************

unsigned int cheat_buffer;

//******************************************************************************
//m_menu.c
//******************************************************************************

//
// defaulted values
//
int showMessages;    // Show messages has default, 0 = off, 1 = on

int alwaysRun;

int messageToPrint;  // 1 = message to be printed

// CPhipps - static const
const char* messageString; // ...and here is the message string!

int messageLastMenuActive;

int saveSlot;        // which slot to save in
// old save description before edit

const menu_t* currentMenu; // current menudef

int epi;

short itemOn;           // menu item skull is on (for Big Font menus)
short skullAnimCounter; // skull animation counter
short whichSkull;       // which skull to draw (he blinks)

boolean menuactive;    // The menus are up
boolean messageNeedsInput; // timed message = no input from user

char savegamestrings[8][8];


//******************************************************************************
//m_random.c
//******************************************************************************

int	rndindex;
int	prndindex;


//******************************************************************************
//p_ceiling.c
//******************************************************************************

// the list of ceilings moving currently, including crushers
ceilinglist_t *activeceilings;

//******************************************************************************
//p_enemy.c
//******************************************************************************

mobj_t *current_actor;

fixed_t dropoff_deltax, dropoff_deltay, floorz;

int current_allaround;

mobj_t* corpsehit;
fixed_t viletryx;
fixed_t viletryy;

// killough 2/7/98: Remove limit on icon landings:
mobj_t **braintargets;
int    numbraintargets_alloc;
int    numbraintargets;

brain_t brain;   // killough 3/26/98: global state of boss brain

//******************************************************************************
//p_map.c
//******************************************************************************

/* killough 8/2/98: for more intelligent autoaiming */
uint_64_t aim_flags_mask;

mobj_t    *tmthing;
fixed_t   tmx;
fixed_t   tmy;

int pe_x; // Pain Elemental position for Lost Soul checks // phares
int pe_y; // Pain Elemental position for Lost Soul checks // phares
int ls_x; // Lost Soul position for Lost Soul checks      // phares
int ls_y; // Lost Soul position for Lost Soul checks      // phares

// The tm* items are used to hold information globally, usually for
// line or object intersection checking

fixed_t   tmbbox[4];  // bounding box for line intersection checks
fixed_t   tmfloorz;   // floor you'd hit if free to fall
fixed_t   tmceilingz; // ceiling of sector you're in
fixed_t   tmdropoffz; // dropoff on other side of line you're crossing

// keep track of the line that lowers the ceiling,
// so missiles don't explode against sky hack walls

const line_t    *ceilingline;
const line_t        *blockline;    /* killough 8/11/98: blocking linedef */
const line_t        *floorline;    /* killough 8/1/98: Highest touched floor */
int         tmunstuck;     /* killough 8/1/98: whether to allow unsticking */

// keep track of special lines as they are hit,
// but don't process them until the move is proven valid

// 1/11/98 killough: removed limit on special lines crossed
const line_t *spechit[4];                // new code -- killough

int numspechit;

// Temporary holder for thing_sectorlist threads
msecnode_t* sector_list;                             // phares 3/16/98

/* killough 8/2/98: make variables static */
fixed_t   bestslidefrac;
const line_t*   bestslideline;
mobj_t*   slidemo;
fixed_t   tmxmove;
fixed_t   tmymove;

mobj_t*   linetarget; // who got hit (or NULL)
mobj_t*   shootthing;

// Height if not aiming up or down
fixed_t   shootz;

int       la_damage;
fixed_t   attackrange;

fixed_t   aimslope;

// slopes to top and bottom of target
// killough 4/20/98: make static instead of using ones in p_sight.c

fixed_t  topslope;
fixed_t  bottomslope;

mobj_t *bombsource, *bombspot;
int bombdamage;

mobj_t*   usething;

// If "floatok" true, move would be ok
// if within "tmfloorz - tmceilingz".
boolean   floatok;

/* killough 11/98: if "felldown" true, object was pushed down ledge */
boolean   felldown;

boolean crushchange, nofit;

boolean telefrag;   /* killough 8/9/98: whether to telefrag at exit */



//******************************************************************************
//p_maputl.c
//******************************************************************************

fixed_t opentop;
fixed_t openbottom;
fixed_t openrange;
fixed_t lowfloor;

// moved front and back outside P-LineOpening and changed    // phares 3/7/98
// them to these so we can pick up the new friction value
// in PIT_CheckLine()
sector_t *openfrontsector; // made global                    // phares
sector_t *openbacksector;  // made global

divline_t trace;


// 1/11/98 killough: Intercept limit removed
intercept_t intercepts[MAXINTERCEPTS];
intercept_t* intercept_p;

//******************************************************************************
//p_mobj.c
//******************************************************************************

//******************************************************************************
//p_plats.c
//******************************************************************************

platlist_t *activeplats;       // killough 2/14/98: made global again


//******************************************************************************
//p_pspr.c
//******************************************************************************

fixed_t bulletslope;

//******************************************************************************
//p_setup.c
//******************************************************************************


//
// MAP related Lookup tables.
// Store VERTEXES, LINEDEFS, SIDEDEFS, etc.
//

int      numvertexes;
const vertex_t *vertexes;

int      numsegs;
const seg_t    *segs;

int      numsectors;
sector_t *sectors;


int      numsubsectors;
subsector_t *subsectors;



int      numlines;
const line_t   *lines;
linedata_t* linedata;


int      numsides;
side_t   *sides;

// BLOCKMAP
// Created from axis aligned bounding box
// of the map, a rectangular array of
// blocks of size ...
// Used to speed up collision detection
// by spatial subdivision in 2D.
//
// Blockmap size.

int       bmapwidth, bmapheight;  // size in mapblocks

// killough 3/1/98: remove blockmap limit internally:
const short      *blockmap;              // was short -- killough

// offsets in blockmap are from here
const short      *blockmaplump;          // was short -- killough

fixed_t   bmaporgx, bmaporgy;     // origin of block map

mobj_t    **blocklinks;           // for thing chains

//
// REJECT
// For fast sight rejection.
// Speeds up enemy AI by skipping detailed
//  LineOf Sight calculation.
// Without the special effect, this could
// be used as a PVS lookup as well.
//

int rejectlump;// cph - store reject lump num if cached
const byte *rejectmatrix; // cph - const*

// Maintain single and multi player starting spots.
mapthing_t playerstarts[MAXPLAYERS];


//******************************************************************************
//p_sight.c
//******************************************************************************

los_t los; // cph - made static

//******************************************************************************
//p_spec.c
//******************************************************************************

anim_t*     lastanim;
anim_t		anims[MAXANIMS];

pusher_t* tmpusher; // pusher structure for blockmap searches


//******************************************************************************
//p_switch.c
//******************************************************************************

short switchlist[MAXSWITCHES * 2];
int   numswitches;                           // killough

button_t  buttonlist[MAXBUTTONS];


//******************************************************************************
//p_tick.c
//******************************************************************************

int leveltime; // tics in game play for par

// killough 8/29/98: we maintain several separate threads, each containing
// a special class of thinkers, to allow more efficient searches.
thinker_t thinkerclasscap[th_all+1];

//******************************************************************************
//p_user.c
//******************************************************************************

boolean onground; // whether player is on ground or in air


//******************************************************************************
//r_bsp.c
//******************************************************************************


//******************************************************************************
//r_data.c
//******************************************************************************

int       firstflat, lastflat, numflats;
int       firstspritelump, lastspritelump, numspritelumps;
int       numtextures;

//Store last lookup and return that if they match.
const char* tex_lookup_last_name;
int tex_lookup_last_num;


//******************************************************************************
//r_draw.c
//******************************************************************************


int fuzzpos;

//******************************************************************************
//r_draw.c
//******************************************************************************

unsigned short validcount;         // increment every time a check is made



player_t *viewplayer;

// killough 3/20/98, 4/4/98: end dynamic colormaps



//******************************************************************************
//r_patch.c
//******************************************************************************


//******************************************************************************
//r_plane.c
//******************************************************************************

visplane_t *visplanes[MAXVISPLANES];   // killough
visplane_t *freetail;                  // killough
visplane_t **freehead;     // killough



// Clip values are the solid pixel bounding the range.
//  floorclip starts out SCREENHEIGHT
//  ceilingclip starts out -1


// killough 2/8/98: make variables static



//******************************************************************************
//r_segs.c
//******************************************************************************

//
// regular wall
//
drawseg_t drawsegs[MAXDRAWSEGS];

short openings[MAXOPENINGS];
short* lastopening;



//******************************************************************************
//r_sky.c
//******************************************************************************

//
// sky mapping
//
int skyflatnum;
int skytexture;


//******************************************************************************
//r_things.c
//******************************************************************************

// variables used to look up and range check thing_t sprites patches

spritedef_t *sprites;
int numsprites;


spriteframe_t sprtemp[MAX_SPRITE_FRAMES];
int maxframe;

vissprite_t vissprites[MAXVISSPRITES];
vissprite_t* vissprite_ptrs[MAXVISSPRITES*2];  // killough



//******************************************************************************
//s_sound.c
//******************************************************************************

// the set of channels available
channel_t *channels;

// These are not used, but should be (menu).
// Maximum volume of a sound effect.
// Internal default is max out of 0-15.
int snd_SfxVolume;

// Maximum volume of music. Useless so far.
int snd_MusicVolume;

// music currently being played
int mus_playing;

//jff 3/17/98 to keep track of last IDMUS specified music num
int idmusnum;

// whether songs are mus_paused
boolean mus_paused;

//******************************************************************************
//st_stuff.c
//******************************************************************************

// main player in game
player_t *plyr;


unsigned int st_needrefresh;

// 0-9, tall numbers
const patch_t* tallnum[10];

// 0-9, short, yellow (,different!) numbers
const patch_t* shortnum[10];

// tall % sign
const patch_t* tallpercent;

const patch_t* keys[NUMCARDS];

// face status patches
const patch_t* faces[ST_NUMFACES];

//e6y: status bar background
const patch_t* stbarbg;
unsigned int stbar_len;


// weapon ownership patches
const patch_t* arms[6][2];

// ready-weapon widget
st_number_t w_ready;

// health widget
st_percent_t st_health;

// weapon ownership widgets
st_multicon_t w_arms[6];

// face status widget
st_multicon_t w_faces;

// keycard widgets
st_multicon_t w_keyboxes[3];

// ammo widgets
st_number_t w_ammo[4];

// max ammo widgets
st_number_t w_maxammo[4];

// armor widget
st_percent_t  st_armor;

// used to use appopriately pained face
int      st_oldhealth;

// used for evil grin
boolean  oldweaponsowned[NUMWEAPONS];

 // count until face changes
int      st_facecount;

// current face index, used by w_faces
int      st_faceindex;

// holds key-type for each key box on bar
int      keyboxes[3];

// a random number per tick
int      st_randomnumber;

int st_palette;

// whether left-side main status bar is active
boolean st_statusbaron;

//******************************************************************************
//v_video.c
//******************************************************************************

// Each screen is [SCREENWIDTH*SCREENHEIGHT];
screeninfo_t screens[NUM_SCREENS];

//******************************************************************************
//w_wad.c
//******************************************************************************

int        numlumps;         // killough

//******************************************************************************
//wi_stuff.c
//******************************************************************************

// used to accelerate or skip a stage
int   acceleratestage;           // killough 3/28/98: made global

// wbs->pnum
int    me;

 // specifies current state
stateenum_t  state;

// contains information passed into intermission
wbstartstruct_t* wbs;

wbplayerstruct_t* plrs;  // wbs->plyr[]

// used for general timing
int    cnt;

// used for timing of background animation
int    bcnt;

int    cnt_time;
int    cnt_total_time;
int    cnt_par;
int    cnt_pause;

// 0-9 graphic
const patch_t* num[10];

int  sp_state;

int cnt_kills;
int cnt_items;
int cnt_secret;

boolean snl_pointeron;


//******************************************************************************
#endif // GLOBAL_DEFS_H

} globals_t;

void InitGlobals();

extern globals_t* _g;

#endif // GLOBAL_DATA_H
