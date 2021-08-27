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
 *  DOOM selection menu, options, episode etc. (aka Big Font menus)
 *  Sliders and icons. Kinda widget stuff.
 *  Setup Menus.
 *  Extended HELP screens.
 *  Dynamic HELP screen.
 *
 *-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <fcntl.h>

#include "doomdef.h"
#include "doomstat.h"
#include "dstrings.h"
#include "d_main.h"
#include "v_video.h"
#include "w_wad.h"
#include "r_main.h"
#include "hu_stuff.h"
#include "g_game.h"
#include "s_sound.h"
#include "sounds.h"
#include "m_menu.h"
#include "m_misc.h"
#include "lprintf.h"
#include "am_map.h"
#include "i_main.h"
#include "i_system.h"
#include "i_video.h"
#include "i_sound.h"

#include "global_data.h"

static void (*messageRoutine)(int response);

// we are going to be entering a savegame string

#define SKULLXOFF  -32
#define LINEHEIGHT  16

// graphic name of skulls

static const char skullName[2][9] = {"M_SKULL1","M_SKULL2"};


// end of externs added for setup menus

//
// PROTOTYPES
//
void M_NewGame(int choice);
void M_Episode(int choice);
void M_ChooseSkill(int choice);
void M_Options(int choice);
void M_EndGame(int choice);


void M_ChangeMessages(int choice);
void M_ChangeAlwaysRun(int choice);
void M_ChangeGamma(int choice);
void M_SfxVol(int choice);
void M_MusicVol(int choice);
void M_StartGame(int choice);
void M_Sound(int choice);

void M_DrawMainMenu(void);
void M_DrawNewGame(void);
void M_DrawEpisode(void);
void M_DrawOptions(void);
void M_DrawSound(void);

void M_SetupNextMenu(const menu_t *menudef);
void M_DrawThermo(int x,int y,int thermWidth,int thermDot);
void M_WriteText(int x, int y, const char *string);
int  M_StringWidth(const char *string);
int  M_StringHeight(const char *string);
void M_StartMessage(const char *string,void *routine,boolean input);
void M_ClearMenus (void);

// phares 3/30/98
// prototypes added to support Setup Menus and Extended HELP screens

void M_Setup(int choice);


// end of prototypes added to support Setup Menus and Extended HELP screens

/////////////////////////////////////////////////////////////////////////////
//
// DOOM MENUS
//

/////////////////////////////
//
// MAIN MENU
//

// main_e provides numerical values for which Big Font screen you're on

enum
{
  newgame = 0,
  options,
  main_end
};

//
// MainMenu is the definition of what the main menu Screen should look
// like. Each entry shows that the cursor can land on each item (1), the
// built-in graphic lump (i.e. "M_NGAME") that should be displayed,
// the program which takes over when an item is selected, and the hotkey
// associated with the item.
//

static const menuitem_t MainMenu[]=
{
  {1,"M_NGAME", M_NewGame},
  {1,"M_OPTION",M_Options}
};

static const menu_t MainDef =
{
  main_end,       // number of menu items
  MainMenu,       // table that defines menu items
  M_DrawMainMenu, // drawing routine
  97,64,          // initial cursor position
  NULL,0,
};

//
// M_DrawMainMenu
//

void M_DrawMainMenu(void)
{
  // CPhipps - patch drawing updated
  V_DrawNamePatch(94, 2, 0, "M_DOOM", CR_DEFAULT, VPT_STRETCH);
}

/////////////////////////////
//
// EPISODE SELECT
//

//
// episodes_e provides numbers for the episode menu items. The default is
// 4, to accomodate Ultimate Doom. If the user is running anything else,
// this is accounted for in the code.
//

enum
{
  ep1,
  ep2,
  ep3,
  ep4,
  ep_end
};


// The definitions of the Registered/Shareware Episodes menu

static const menuitem_t EpisodeMenu3[]=
{
  {1,"M_EPI1", M_Episode},
  {1,"M_EPI2", M_Episode},
  {1,"M_EPI3", M_Episode}
};

static const menu_t EpiDef3 =
{
  ep_end-1,        // # of menu items
  EpisodeMenu3,   // menuitem_t ->
  M_DrawEpisode, // drawing routine ->
  48,63,         // x,y
  &MainDef,0,
};

// The definitions of the Episodes menu

static const menuitem_t EpisodeMenu[]=
{
  {1,"M_EPI1", M_Episode},
  {1,"M_EPI2", M_Episode},
  {1,"M_EPI3", M_Episode},
  {1,"M_EPI4", M_Episode}
};

static const menu_t EpiDef =
{
  ep_end,        // # of menu items
  EpisodeMenu,   // menuitem_t ->
  M_DrawEpisode, // drawing routine ->
  48,63,         // x,y
  &MainDef,0,
};

// numerical values for the New Game menu items

enum
{
  killthings,
  toorough,
  hurtme,
  violence,
  nightmare,
  newg_end
};

// The definitions of the New Game menu

static const menuitem_t NewGameMenu[]=
{
  {1,"M_JKILL", M_ChooseSkill},
  {1,"M_ROUGH", M_ChooseSkill},
  {1,"M_HURT",  M_ChooseSkill},
  {1,"M_ULTRA", M_ChooseSkill},
  {1,"M_NMARE", M_ChooseSkill}
};

static const menu_t NewDef =
{
  newg_end,       // # of menu items
  NewGameMenu,    // menuitem_t ->
  M_DrawNewGame,  // drawing routine ->
  48,63,          // x,y
  &MainDef,0,
};

//
//    M_Episode
//

void M_DrawEpisode(void)
{
  // CPhipps - patch drawing updated
  V_DrawNamePatch(54, 38, 0, "M_EPISOD", CR_DEFAULT, VPT_STRETCH);
}

void M_Episode(int choice)
{
  if ( (_g->gamemode == shareware) && choice)
  {
    M_StartMessage(SWSTRING,NULL,false); // Ty 03/27/98 - externalized
    _g->itemOn = 0;
    return;
  }

  // Yet another hack...
  if ( (_g->gamemode == registered) && (choice > 2))
    {
    lprintf( LO_WARN,
     "M_Episode: 4th episode requires UltimateDOOM\n");
    choice = 0;
    }

  _g->epi = choice;
  M_SetupNextMenu(&NewDef);
  _g->itemOn = 2; //Set hurt me plenty as default difficulty
}

//
// M_NewGame
//

void M_DrawNewGame(void)
{
  // CPhipps - patch drawing updated
  V_DrawNamePatch(96, 14, 0, "M_NEWG", CR_DEFAULT, VPT_STRETCH);
  V_DrawNamePatch(54, 38, 0, "M_SKILL",CR_DEFAULT, VPT_STRETCH);
}

void M_NewGame(int choice)
{
    if ( _g->gamemode == commercial )
    {
		M_SetupNextMenu(&NewDef);
		_g->itemOn = 2; //Set hurt me plenty as default difficulty
	}else if( (_g->gamemode == shareware) || (_g->gamemode == registered) )
        M_SetupNextMenu(&EpiDef3);
    else
        M_SetupNextMenu(&EpiDef);
}

// CPhipps - static
static void M_VerifyNightmare(int ch)
{
    if (ch != key_enter)
        return;

    G_DeferedInitNew(nightmare,_g->epi+1,1);
}

void M_ChooseSkill(int choice)
{
    if (choice == nightmare)
    {   // Ty 03/27/98 - externalized
        M_StartMessage(NIGHTMARE,M_VerifyNightmare,true);
		_g->itemOn = 0;
    }
    else
    {
        G_DeferedInitNew(choice,_g->epi+1,1);
		M_ClearMenus ();
    }    
}

/////////////////////////////
//
// LOAD GAME MENU
//

// numerical values for the Load Game slots

enum
{
    load1,
    load2,
    load3,
    load4,
    load5,
    load6,
    load7,
    load8,
    load_end
};

/////////////////////////////
//
// OPTIONS MENU
//

// numerical values for the Options menu items

enum
{                                                   // phares 3/21/98
  endgame,
  messages,
  alwaysrun,
  gamma,
  soundvol,
  opt_end
};

// The definitions of the Options menu

static const menuitem_t OptionsMenu[]=
{
  // killough 4/6/98: move setup to be a sub-menu of OPTIONs
  {1,"M_ENDGAM", M_EndGame},
  {1,"M_MESSG",  M_ChangeMessages},
  {1,"M_ARUN",   M_ChangeAlwaysRun},
  {2,"M_GAMMA",   M_ChangeGamma},
  {1,"M_SVOL",   M_Sound}
};

const static menu_t OptionsDef =
{
  opt_end,
  OptionsMenu,
  M_DrawOptions,
  60,37,
  &MainDef,1,
};

//
// M_Options
//
static const char msgNames[2][9]  = {"M_MSGOFF","M_MSGON"};


void M_DrawOptions(void)
{
  // CPhipps - patch drawing updated
  // proff/nicolas 09/20/98 -- changed for hi-res
  V_DrawNamePatch(108, 15, 0, "M_OPTTTL", CR_DEFAULT, VPT_STRETCH);

  V_DrawNamePatch(OptionsDef.x + 120, OptionsDef.y+LINEHEIGHT*messages, 0,
      msgNames[_g->showMessages], CR_DEFAULT, VPT_STRETCH);

  V_DrawNamePatch(OptionsDef.x + 146, OptionsDef.y+LINEHEIGHT*alwaysrun, 0,
      msgNames[_g->alwaysRun], CR_DEFAULT, VPT_STRETCH);
	  
  M_DrawThermo(OptionsDef.x + 158, OptionsDef.y+LINEHEIGHT*gamma+2,6,_g->gamma);
}

void M_Options(int choice)
{
  M_SetupNextMenu(&OptionsDef);
}

/////////////////////////////
//
// SOUND VOLUME MENU
//

// numerical values for the Sound Volume menu items
// The 'empty' slots are where the sliding scales appear.

enum
{
  sfx_vol,
  sfx_empty1,
  music_vol,
  sfx_empty2,
  sound_end
};

// The definitions of the Sound Volume menu

static const menuitem_t SoundMenu[]=
{
  {2,"M_SFXVOL",M_SfxVol},
  {-1,"",0},
  {2,"M_MUSVOL",M_MusicVol},
  {-1,"",0}
};

static const menu_t SoundDef =
{
  sound_end,
  SoundMenu,
  M_DrawSound,
  80,64,
  &OptionsDef,4,
};

//
// Change Sfx & Music volumes
//

void M_DrawSound(void)
{
  // CPhipps - patch drawing updated
  V_DrawNamePatch(60, 38, 0, "M_SVOL", CR_DEFAULT, VPT_STRETCH);

  M_DrawThermo(SoundDef.x,SoundDef.y+LINEHEIGHT*(sfx_vol+1),16,_g->snd_SfxVolume);

  M_DrawThermo(SoundDef.x,SoundDef.y+LINEHEIGHT*(music_vol+1),16,_g->snd_MusicVolume);
}

void M_Sound(int choice)
{
  M_SetupNextMenu(&SoundDef);
}

void M_SfxVol(int choice)
{
  switch(choice)
    {
    case 0:
      if (_g->snd_SfxVolume)
        _g->snd_SfxVolume--;
      break;
    case 1:
      if (_g->snd_SfxVolume < 15)
        _g->snd_SfxVolume++;
      break;
    }

  S_SetSfxVolume(_g->snd_SfxVolume /* *8 */);
}

void M_MusicVol(int choice)
{
  switch(choice)
    {
    case 0:
      if (_g->snd_MusicVolume)
        _g->snd_MusicVolume--;
      break;
    case 1:
      if (_g->snd_MusicVolume < 15)
        _g->snd_MusicVolume++;
      break;
    }

  S_SetMusicVolume(_g->snd_MusicVolume /* *8 */);
}

/////////////////////////////
//
// M_EndGame
//

static void M_EndGameResponse(int ch)
{
  if (ch != key_enter)
    return;

  // killough 5/26/98: make endgame quit if recording or playing back demo
  if (_g->singledemo)
    G_CheckDemoStatus();

  M_ClearMenus ();
  D_StartTitle ();
}

void M_EndGame(int choice)
{
  M_StartMessage(ENDGAME,M_EndGameResponse,true); // Ty 03/27/98 - externalized
}

/////////////////////////////
//
//    Toggle messages on/off
//

void M_ChangeMessages(int choice)
{
  // warning: unused parameter `int choice'
  choice = 0;
  _g->showMessages = 1 - _g->showMessages;

  if (!_g->showMessages)
    _g->player.message = MSGOFF; // Ty 03/27/98 - externalized
  else
    _g->player.message = MSGON ; // Ty 03/27/98 - externalized

  _g->message_dontfuckwithme = true;
}


void M_ChangeAlwaysRun(int choice)
{
    // warning: unused parameter `int choice'
    choice = 0;
    _g->alwaysRun = 1 - _g->alwaysRun;

    if (!_g->alwaysRun)
      _g->player.message = RUNOFF; // Ty 03/27/98 - externalized
    else
      _g->player.message = RUNON ; // Ty 03/27/98 - externalized
}

void M_ChangeGamma(int choice)
{
	switch(choice)
    {
		case 0:
		  if (_g->gamma)
			_g->gamma--;
		  break;
		case 1:
		  if (_g->gamma < 5)
			_g->gamma++;
		  break;
    }
	V_SetPalLump(_g->gamma);
	V_SetPalette(0);
}

//
// End of Original Menus
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////
//
// General routines used by the Setup screens.
//

//
// M_InitDefaults()
//
// killough 11/98:
//
// This function converts all setup menu entries consisting of cfg
// variable names, into pointers to the corresponding default[]
// array entry. var.name becomes converted to var.def.
//

static void M_InitDefaults(void)
{

}

//
// End of Setup Screens.
//
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
//
// M_Responder
//
// Examines incoming keystrokes and button pushes and determines some
// action based on the state of the system.
//

boolean M_Responder (event_t* ev)
{
    int    ch;

    ch = -1; // will be changed to a legit char if we're going to use it here


    // Mouse input processing removed

    // Process keyboard input

    if (ev->type == ev_keydown)
    {
        ch = ev->data1;               // phares 4/11/98:
    }                             // down so you can get at the !,#,


    if (ch == -1)
        return false; // we can't use the event here

    // Take care of any messages that need input

    if (_g->messageToPrint)
    {
        if (_g->messageNeedsInput == true &&
                !(ch == ' ' || ch == 'n' || ch == 'y' || ch == key_escape || ch == key_fire || ch == key_enter)) // phares
            return false;

        _g->menuactive = _g->messageLastMenuActive;
        _g->messageToPrint = 0;
        if (messageRoutine)
            messageRoutine(ch);

        _g->menuactive = false;
        S_StartSound(NULL,sfx_swtchx);
        return true;
    }

    // Pop-up Main menu?

    if (!_g->menuactive)
    {
        if (ch == key_escape)                                     // phares
        {
            M_StartControlPanel ();
            S_StartSound(NULL,sfx_swtchn);
            return true;
        }
        return false;
    }

    // From here on, these navigation keys are used on the BIG FONT menus
    // like the Main Menu.

    if (ch == key_menu_down)                             // phares 3/7/98
    {
        do
        {
            if (_g->itemOn+1 > _g->currentMenu->numitems-1)
                _g->itemOn = 0;
            else
                _g->itemOn++;
            S_StartSound(NULL,sfx_pstop);
        }
        while(_g->currentMenu->menuitems[_g->itemOn].status==-1);
        return true;
    }

    if (ch == key_menu_up)                               // phares 3/7/98
    {
        do
        {
            if (!_g->itemOn)
                _g->itemOn = _g->currentMenu->numitems-1;
            else
                _g->itemOn--;
            S_StartSound(NULL,sfx_pstop);
        }
        while(_g->currentMenu->menuitems[_g->itemOn].status==-1);
        return true;
    }

    if (ch == key_menu_left)                             // phares 3/7/98
    {
        if (_g->currentMenu->menuitems[_g->itemOn].routine &&
                _g->currentMenu->menuitems[_g->itemOn].status == 2)
        {
            S_StartSound(NULL,sfx_stnmov);
            _g->currentMenu->menuitems[_g->itemOn].routine(0);
        }
        return true;
    }

    if (ch == key_menu_right)                            // phares 3/7/98
    {
        if (_g->currentMenu->menuitems[_g->itemOn].routine &&
                _g->currentMenu->menuitems[_g->itemOn].status == 2)
        {
            S_StartSound(NULL,sfx_stnmov);
            _g->currentMenu->menuitems[_g->itemOn].routine(1);
        }
        return true;
    }

    if (ch == key_menu_enter)                            // phares 3/7/98
    {
        if (_g->currentMenu->menuitems[_g->itemOn].routine &&
                _g->currentMenu->menuitems[_g->itemOn].status)
        {
            if (_g->currentMenu->menuitems[_g->itemOn].status == 2)
            {
                _g->currentMenu->menuitems[_g->itemOn].routine(1);   // right arrow
                S_StartSound(NULL,sfx_stnmov);
            }
            else
            {
                _g->currentMenu->menuitems[_g->itemOn].routine(_g->itemOn);
                S_StartSound(NULL,sfx_pistol);
            }
        }
        //jff 3/24/98 remember last skill selected
        // killough 10/98 moved to skill-specific functions
        return true;
    }

    if (ch == key_menu_escape)                           // phares 3/7/98
    {
        M_ClearMenus ();
        S_StartSound(NULL,sfx_swtchx);
        return true;
    }

	//Allow being able to go back in menus ~Kippykip
	if (ch == key_fire)                           // phares 3/7/98
    {
		//If the prevMenu == NULL (Such as main menu screen), then just get out of the menu altogether
		if(_g->currentMenu->prevMenu == NULL)
		{
			M_ClearMenus();
		}else //Otherwise, change to the parent menu and match the row used to get there.
		{
			short previtemOn = _g->currentMenu->previtemOn; //Temporarily store this so after menu change, we store the last row it was on.
			M_SetupNextMenu(_g->currentMenu->prevMenu);					
			_g->itemOn = previtemOn;
		}
        S_StartSound(NULL,sfx_swtchx);
        return true;		
    }
	
    return false;
}

//
// End of M_Responder
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
// General Routines
//
// This displays the Main menu and gets the menu screens rolling.
// Plus a variety of routines that control the Big Font menu display.
// Plus some initialization for game-dependant situations.

void M_StartControlPanel (void)
{
  // intro might call this repeatedly

  if (_g->menuactive)
    return;

  //jff 3/24/98 make default skill menu choice follow -skill or defaultskill
  //from command line or config file
  //
  // killough 10/98:
  // Fix to make "always floating" with menu selections, and to always follow
  // defaultskill, instead of -skill.

  _g->menuactive = 1;
  _g->currentMenu = &MainDef;         // JDC
}

//
// M_Drawer
// Called after the view has been rendered,
// but before it has been blitted.
//
// killough 9/29/98: Significantly reformatted source
//

void M_Drawer (void)
{
    // Horiz. & Vertically center string and print it.
    // killough 9/29/98: simplified code, removed 40-character width limit
    if (_g->messageToPrint)
    {
        /* cph - strdup string to writable memory */
        char *ms = strdup(_g->messageString);
        char *p = ms;

        int y = 80 - M_StringHeight(_g->messageString)/2;
        while (*p)
        {
            char *string = p, c;
            while ((c = *p) && *p != '\n')
                p++;
            *p = 0;
            M_WriteText(120 - M_StringWidth(string)/2, y, string);
            y += _g->hu_font[0]->height;
            if ((*p = c))
                p++;
        }
        free(ms);
    }
    else
        if (_g->menuactive)
        {
            int x,y,max,i;

            if (_g->currentMenu->routine)
                _g->currentMenu->routine();     // call Draw routine

            // DRAW MENU

            x = _g->currentMenu->x;
            y = _g->currentMenu->y;
            max = _g->currentMenu->numitems;

            for (i=0;i<max;i++)
            {
                if (_g->currentMenu->menuitems[i].name[0])
                    V_DrawNamePatch(x,y,0,_g->currentMenu->menuitems[i].name,
                                    CR_DEFAULT, VPT_STRETCH);
                y += LINEHEIGHT;
            }

            // DRAW SKULL

            // CPhipps - patch drawing updated
            V_DrawNamePatch(x + SKULLXOFF, _g->currentMenu->y - 5 + _g->itemOn*LINEHEIGHT,0,
                            skullName[_g->whichSkull], CR_DEFAULT, VPT_STRETCH);
        }
}

//
// M_ClearMenus
//
// Called when leaving the menu screens for the real world

void M_ClearMenus (void)
{
  _g->menuactive = 0;
  _g->itemOn = 0;
}

//
// M_SetupNextMenu
//
void M_SetupNextMenu(const menu_t *menudef)
{
  _g->currentMenu = menudef;
  _g->itemOn = 0;
}

/////////////////////////////
//
// M_Ticker
//
void M_Ticker (void)
{
  if (--_g->skullAnimCounter <= 0)
    {
      _g->whichSkull ^= 1;
      _g->skullAnimCounter = 8;
    }
}

/////////////////////////////
//
// Message Routines
//

void M_StartMessage (const char* string,void* routine,boolean input)
{
  _g->messageLastMenuActive = _g->menuactive;
  _g->messageToPrint = 1;
  _g->messageString = string;
  messageRoutine = routine;
  _g->messageNeedsInput = input;
  _g->menuactive = true;
  return;
}


/////////////////////////////
//
// Thermometer Routines
//

//
// M_DrawThermo draws the thermometer graphic for Mouse Sensitivity,
// Sound Volume, etc.
//
// proff/nicolas 09/20/98 -- changed for hi-res
// CPhipps - patch drawing updated
//
void M_DrawThermo(int x,int y,int thermWidth,int thermDot )
{
    int          xx;
    int           i;
    /*
   * Modification By Barry Mead to allow the Thermometer to have vastly
   * larger ranges. (the thermWidth parameter can now have a value as
   * large as 200.      Modified 1-9-2000  Originally I used it to make
   * the sensitivity range for the mouse better. It could however also
   * be used to improve the dynamic range of music and sound affect
   * volume controls for example.
   */
    int horizScaler; //Used to allow more thermo range for mouse sensitivity.
    thermWidth = (thermWidth > 200) ? 200 : thermWidth; //Clamp to 200 max
    horizScaler = (thermWidth > 23) ? (200 / thermWidth) : 8; //Dynamic range
    xx = x;

    int thermm_lump = W_GetNumForName("M_THERMM");

    V_DrawNamePatch(xx, y, 0, "M_THERML", CR_DEFAULT, VPT_STRETCH);

    xx += 8;
    for (i=0;i<thermWidth;i++)
    {
        V_DrawNumPatch(xx, y, 0, thermm_lump, CR_DEFAULT, VPT_STRETCH);
        xx += horizScaler;
    }

    xx += (8 - horizScaler);  /* make the right end look even */

    V_DrawNamePatch(xx, y, 0, "M_THERMR", CR_DEFAULT, VPT_STRETCH);
    V_DrawNamePatch((x+8)+thermDot*horizScaler,y,0,"M_THERMO",CR_DEFAULT,VPT_STRETCH);
}

/////////////////////////////
//
// String-drawing Routines
//

//
// Find string width from hu_font chars
//

int M_StringWidth(const char* string)
{
  int i, c, w = 0;
  for (i = 0;(size_t)i < strlen(string);i++)
    w += (c = toupper(string[i]) - HU_FONTSTART) < 0 || c >= HU_FONTSIZE ?
      4 : _g->hu_font[c]->width;
  return w;
}

//
//    Find string height from hu_font chars
//

int M_StringHeight(const char* string)
{
  int i, h, height = h = _g->hu_font[0]->height;
  for (i = 0;string[i];i++)            // killough 1/31/98
    if (string[i] == '\n')
      h += height;
  return h;
}

//
//    Write a string using the hu_font
//
void M_WriteText (int x,int y,const char* string)
{
    int   w;
    const char* ch;
    int   c;
    int   cx;
    int   cy;

    ch = string;
    cx = x;
    cy = y;

    while(1) {
        c = *ch++;
        if (!c)
            break;
        if (c == '\n') {
            cx = x;
            cy += 12;
            continue;
        }

        c = toupper(c) - HU_FONTSTART;
        if (c < 0 || c>= HU_FONTSIZE)
        {
            cx += 4;
            continue;
        }

        w = _g->hu_font[c]->width;
        V_DrawPatchNoScale(cx, cy, _g->hu_font[c]);
        cx+=w;
    }
}

/////////////////////////////
//
// Initialization Routines to take care of one-time setup
//

//
// M_Init
//
void M_Init(void)
{
  M_InitDefaults();                // killough 11/98
  _g->currentMenu = &MainDef;
  _g->menuactive = 0;
  _g->whichSkull = 0;
  _g->skullAnimCounter = 10;
  _g->messageToPrint = 0;
  _g->messageString = NULL;
  _g->messageLastMenuActive = _g->menuactive;

}

//
// End of General Routines
//
/////////////////////////////////////////////////////////////////////////////
