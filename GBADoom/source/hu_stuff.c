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
 * DESCRIPTION:  Heads-up displays
 *
 *-----------------------------------------------------------------------------
 */

// killough 5/3/98: remove unnecessary headers

#include "doomstat.h"
#include "hu_stuff.h"
#include "hu_lib.h"
#include "st_stuff.h" /* jff 2/16/98 need loc of status bar */
#include "w_wad.h"
#include "s_sound.h"
#include "dstrings.h"
#include "sounds.h"
#include "g_game.h"
#include "r_main.h"

#include "global_data.h"

// global heads up display controls

//
// Locally used constants, shortcuts.
//
// Ty 03/28/98 -
// These four shortcuts modifed to reflect char ** of mapnamesx[]
#define HU_TITLE  (mapnames[(_g->gameepisode-1)*9+_g->gamemap-1])
#define HU_TITLE2 (mapnames2[_g->gamemap-1])
#define HU_TITLEP (mapnamesp[_g->gamemap-1])
#define HU_TITLET (mapnamest[_g->gamemap-1])
#define HU_TITLEHEIGHT  1
#define HU_TITLEX 0
//jff 2/16/98 change 167 to ST_Y-1
// CPhipps - changed to ST_TY
// proff - changed to 200-ST_HEIGHT for stretching
#define HU_TITLEY ((160-ST_SCALED_HEIGHT) - 1 - _g->hu_font[0]->height)

//jff 2/16/98 add coord text widget coordinates
// proff - changed to SCREENWIDTH to 320 for stretching
#define HU_COORDX (320 - 13*_g->hu_font['A'-HU_FONTSTART].width)
//jff 3/3/98 split coord widget into three lines in upper right of screen
#define HU_COORDX_Y (1 + 0*_g->hu_font['A'-HU_FONTSTART].height)
#define HU_COORDY_Y (2 + 1*_g->hu_font['A'-HU_FONTSTART].height)
#define HU_COORDZ_Y (3 + 2*_g->hu_font['A'-HU_FONTSTART].height)

//jff 2/16/98 add ammo, health, armor widgets, 2/22/98 less gap
#define HU_GAPY 8
#define HU_HUDHEIGHT (6*HU_GAPY)
#define HU_HUDX 2
#define HU_HUDY (200-HU_HUDHEIGHT-1)
#define HU_MONSECX (HU_HUDX)
#define HU_MONSECY (HU_HUDY+0*HU_GAPY)
#define HU_KEYSX   (HU_HUDX)
//jff 3/7/98 add offset for graphic key widget
#define HU_KEYSGX  (HU_HUDX+4*_g->hu_font['A'-HU_FONTSTART].width)
#define HU_KEYSY   (HU_HUDY+1*HU_GAPY)
#define HU_WEAPX   (HU_HUDX)
#define HU_WEAPY   (HU_HUDY+2*HU_GAPY)
#define HU_AMMOX   (HU_HUDX)
#define HU_AMMOY   (HU_HUDY+3*HU_GAPY)
#define HU_HEALTHX (HU_HUDX)
#define HU_HEALTHY (HU_HUDY+4*HU_GAPY)
#define HU_ARMORX  (HU_HUDX)
#define HU_ARMORY  (HU_HUDY+5*HU_GAPY)

//jff 3/4/98 distributed HUD positions
#define HU_HUDX_LL 2
#define HU_HUDY_LL (200-2*HU_GAPY-1)
// proff/nicolas 09/20/98: Changed for high-res
#define HU_HUDX_LR (320-120)
#define HU_HUDY_LR (200-2*HU_GAPY-1)
// proff/nicolas 09/20/98: Changed for high-res
#define HU_HUDX_UR (320-96)
#define HU_HUDY_UR 2
#define HU_MONSECX_D (HU_HUDX_LL)
#define HU_MONSECY_D (HU_HUDY_LL+0*HU_GAPY)
#define HU_KEYSX_D   (HU_HUDX_LL)
#define HU_KEYSGX_D  (HU_HUDX_LL+4*_g->hu_font['A'-HU_FONTSTART].width)
#define HU_KEYSY_D   (HU_HUDY_LL+1*HU_GAPY)
#define HU_WEAPX_D   (HU_HUDX_LR)
#define HU_WEAPY_D   (HU_HUDY_LR+0*HU_GAPY)
#define HU_AMMOX_D   (HU_HUDX_LR)
#define HU_AMMOY_D   (HU_HUDY_LR+1*HU_GAPY)
#define HU_HEALTHX_D (HU_HUDX_UR)
#define HU_HEALTHY_D (HU_HUDY_UR+0*HU_GAPY)
#define HU_ARMORX_D  (HU_HUDX_UR)
#define HU_ARMORY_D  (HU_HUDY_UR+1*HU_GAPY)

//#define HU_INPUTTOGGLE  't' // not used                           // phares
#define HU_INPUTX HU_MSGX
#define HU_INPUTY (HU_MSGY + HU_MSGHEIGHT*(hu_font[0].height) +1)
#define HU_INPUTWIDTH 64
#define HU_INPUTHEIGHT  1

#define key_alt KEYD_RALT
#define key_shift KEYD_RSHIFT

//jff 2/16/98 hud supported automap colors added
const int hudcolor_titl = 5;  // color range of automap level title
//jff 2/16/98 hud text colors, controls added
const int hudcolor_mesg = 6;  // color range of scrolling messages

//jff 2/26/98 hud text colors, controls added

const int hud_msg_lines = 1;  // number of message lines in window



//
// Builtin map names.
// The actual names can be found in DStrings.h.
//
// Ty 03/27/98 - externalized map name arrays - now in d_deh.c
// and converted to arrays of pointers to char *
// See modified HUTITLEx macros
// DOOM shareware/registered/retail (Ultimate) names.
// CPhipps - const**const
const char *const mapnames[] =
{
  HUSTR_E1M1,
  HUSTR_E1M2,
  HUSTR_E1M3,
  HUSTR_E1M4,
  HUSTR_E1M5,
  HUSTR_E1M6,
  HUSTR_E1M7,
  HUSTR_E1M8,
  HUSTR_E1M9,

  HUSTR_E2M1,
  HUSTR_E2M2,
  HUSTR_E2M3,
  HUSTR_E2M4,
  HUSTR_E2M5,
  HUSTR_E2M6,
  HUSTR_E2M7,
  HUSTR_E2M8,
  HUSTR_E2M9,

  HUSTR_E3M1,
  HUSTR_E3M2,
  HUSTR_E3M3,
  HUSTR_E3M4,
  HUSTR_E3M5,
  HUSTR_E3M6,
  HUSTR_E3M7,
  HUSTR_E3M8,
  HUSTR_E3M9,

  HUSTR_E4M1,
  HUSTR_E4M2,
  HUSTR_E4M3,
  HUSTR_E4M4,
  HUSTR_E4M5,
  HUSTR_E4M6,
  HUSTR_E4M7,
  HUSTR_E4M8,
  HUSTR_E4M9,
};

// CPhipps - const**const
const char *const mapnames2[] = // DOOM 2 map names.
{
  HUSTR_1,
  HUSTR_2,
  HUSTR_3,
  HUSTR_4,
  HUSTR_5,
  HUSTR_6,
  HUSTR_7,
  HUSTR_8,
  HUSTR_9,
  HUSTR_10,
  HUSTR_11,

  HUSTR_12,
  HUSTR_13,
  HUSTR_14,
  HUSTR_15,
  HUSTR_16,
  HUSTR_17,
  HUSTR_18,
  HUSTR_19,
  HUSTR_20,

  HUSTR_21,
  HUSTR_22,
  HUSTR_23,
  HUSTR_24,
  HUSTR_25,
  HUSTR_26,
  HUSTR_27,
  HUSTR_28,
  HUSTR_29,
  HUSTR_30,
  HUSTR_31,
  HUSTR_32,
};

//CPhipps - const**const
const char *const mapnamesp[] = // Plutonia WAD map names.
{
  PHUSTR_1,
  PHUSTR_2,
  PHUSTR_3,
  PHUSTR_4,
  PHUSTR_5,
  PHUSTR_6,
  PHUSTR_7,
  PHUSTR_8,
  PHUSTR_9,
  PHUSTR_10,
  PHUSTR_11,

  PHUSTR_12,
  PHUSTR_13,
  PHUSTR_14,
  PHUSTR_15,
  PHUSTR_16,
  PHUSTR_17,
  PHUSTR_18,
  PHUSTR_19,
  PHUSTR_20,

  PHUSTR_21,
  PHUSTR_22,
  PHUSTR_23,
  PHUSTR_24,
  PHUSTR_25,
  PHUSTR_26,
  PHUSTR_27,
  PHUSTR_28,
  PHUSTR_29,
  PHUSTR_30,
  PHUSTR_31,
  PHUSTR_32,
};

// CPhipps - const**const
const char *const mapnamest[] = // TNT WAD map names.
{
  THUSTR_1,
  THUSTR_2,
  THUSTR_3,
  THUSTR_4,
  THUSTR_5,
  THUSTR_6,
  THUSTR_7,
  THUSTR_8,
  THUSTR_9,
  THUSTR_10,
  THUSTR_11,

  THUSTR_12,
  THUSTR_13,
  THUSTR_14,
  THUSTR_15,
  THUSTR_16,
  THUSTR_17,
  THUSTR_18,
  THUSTR_19,
  THUSTR_20,

  THUSTR_21,
  THUSTR_22,
  THUSTR_23,
  THUSTR_24,
  THUSTR_25,
  THUSTR_26,
  THUSTR_27,
  THUSTR_28,
  THUSTR_29,
  THUSTR_30,
  THUSTR_31,
  THUSTR_32,
};

//
// HU_Init()
//
// Initialize the heads-up display, text that overwrites the primary display
//
// Passed nothing, returns nothing
//
void HU_Init(void)
{
    int		i;
    int		j;
    char	buffer[9];

    // load the heads-up font
    j = HU_FONTSTART;
    for (i=0;i<HU_FONTSIZE;i++)
    {
        sprintf(buffer, "STCFN%.3d", j++);
        _g->hu_font[i] = (const patch_t *) W_CacheLumpName(buffer);
    }
}

//
// HU_Stop()
//
// Make the heads-up displays inactive
//
// Passed nothing, returns nothing
//
static void HU_Stop(void)
{
  _g->headsupactive = false;
}

//
// HU_Start(void)
//
// Create and initialize the heads-up widgets, software machines to
// maintain, update, and display information over the primary display
//
// This routine must be called after any change to the heads up configuration
// in order for the changes to take effect in the actual displays
//
// Passed nothing, returns nothing
//
void HU_Start(void)
{
  const char* s; /* cph - const */

  if (_g->headsupactive)                    // stop before starting
    HU_Stop();


  _g->message_on = false;
  _g->message_dontfuckwithme = false;

  // create the message widget
  // messages to player in upper-left of screen
  HUlib_initSText
  (
    &_g->w_message,
    HU_MSGX,
    HU_MSGY,
    HU_MSGHEIGHT,
    _g->hu_font,
    HU_FONTSTART,
    &_g->message_on
  );

  //jff 2/16/98 added some HUD widgets
  // create the map title widget - map title display in lower left of automap
  HUlib_initTextLine
  (
    &_g->w_title,
    HU_TITLEX,
    HU_TITLEY,
    _g->hu_font,
    HU_FONTSTART
  );

  // initialize the automap's level title widget
  if (_g->gamestate == GS_LEVEL) /* cph - stop SEGV here when not in level */
  switch (_g->gamemode)
  {
    case shareware:
    case registered:
    case retail:
      s = HU_TITLE;
      break;

    case commercial:
    default:  // Ty 08/27/98 - modified to check mission for TNT/Plutonia
      s = (_g->gamemission==pack_tnt)  ? HU_TITLET :
          (_g->gamemission==pack_plut) ? HU_TITLEP : HU_TITLE2;
      break;
  } else s = "";
  while (*s)
    HUlib_addCharToTextLine(&_g->w_title, *(s++));


  // now allow the heads-up display to run
  _g->headsupactive = true;

  HU_MoveHud();
}

//
// HU_MoveHud()
//
// Move the HUD display from distributed to compact mode or vice-versa
//
// Passed nothing, returns nothing
//
//jff 3/9/98 create this externally callable to avoid glitch
// when menu scatter's HUD due to delay in change of position
//
void HU_MoveHud(void)
{

}

//
// HU_Drawer()
//
// Draw all the pieces of the heads-up display
//
// Passed nothing, returns nothing
//
void HU_Drawer(void)
{
  // draw the automap widgets if automap is displayed
  if (_g->automapmode & am_active)
  {
    // map title
    HUlib_drawTextLine(&_g->w_title, false);
  }

  //jff 3/4/98 display last to give priority
  HU_Erase(); // jff 4/24/98 Erase current lines before drawing current
              // needed when screen not fullsize


  HUlib_drawSText(&_g->w_message);
}

//
// HU_Erase()
//
// Erase hud display lines that can be trashed by small screen display
//
// Passed nothing, returns nothing
//
void HU_Erase(void)
{
  // erase the message display or the message review display
    HUlib_eraseSText(&_g->w_message);

  // erase the automap title
  HUlib_eraseTextLine(&_g->w_title);
}

//
// HU_Ticker()
//
// Update the hud displays once per frame
//
// Passed nothing, returns nothing
//

void HU_Ticker(void)
{
    player_t* plr = &_g->player;        // killough 3/7/98

  // tick down message counter if message is up
  if (_g->message_counter && !--_g->message_counter)
  {
    _g->message_on = false;
  }


  // if messages on, or "Messages Off" is being displayed
  // this allows the notification of turning messages off to be seen
  if (_g->showMessages || _g->message_dontfuckwithme)
  {
    // display message if necessary
    if (plr->message)
    {
      //post the message to the message widget
      HUlib_addMessageToSText(&_g->w_message, 0, plr->message);

      // clear the message to avoid posting multiple times
      plr->message = 0;
      // note a message is displayed
      _g->message_on = true;
      // start the message persistence counter
      _g->message_counter = HU_MSGTIMEOUT;

      // clear the flag that "Messages Off" is being posted
      _g->message_dontfuckwithme = 0;
    }
  }
}


//
// HU_Responder()
//
// Responds to input events that affect the heads up displays
//
// Passed the event to respond to, returns true if the event was handled
//
boolean HU_Responder(event_t *ev)
{
    return false;
}
