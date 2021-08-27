/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2004 by
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
 * DESCRIPTION:  none
 *  The original Doom description was none, basically because this file
 *  has everything. This ties up the game logic, linking the menu and
 *  input code to the underlying game by creating & respawning players,
 *  building game tics, calling the underlying thing logic.
 *
 *-----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "doomstat.h"
#include "d_net.h"
#include "f_finale.h"
#include "m_misc.h"
#include "m_menu.h"
#include "m_random.h"
#include "p_setup.h"
#include "p_tick.h"
#include "p_map.h"
#include "d_main.h"
#include "wi_stuff.h"
#include "hu_stuff.h"
#include "st_stuff.h"
#include "am_map.h"
#include "w_wad.h"
#include "r_main.h"
#include "r_draw.h"
#include "p_map.h"
#include "s_sound.h"
#include "dstrings.h"
#include "sounds.h"
#include "r_data.h"
#include "r_sky.h"
#include "p_inter.h"
#include "g_game.h"
#include "lprintf.h"
#include "i_main.h"
#include "i_system.h"

#include "global_data.h"

#include "gba_functions.h"

//
// controls (have defaults)
//

const int     key_right = KEYD_RIGHT;
const int     key_left = KEYD_LEFT;
const int     key_up = KEYD_UP;
const int     key_down = KEYD_DOWN;
const int     key_menu_right = KEYD_RIGHT;                                      // phares 3/7/98
const int     key_menu_left = KEYD_LEFT;                                       //     |
const int     key_menu_up = KEYD_UP;                                         //     V
const int     key_menu_down = KEYD_DOWN;
const int     key_menu_escape = KEYD_START;                                     //     |
const int     key_menu_enter = KEYD_A;                                      // phares 3/7/98
const int     key_strafeleft = KEYD_L;
const int     key_straferight = KEYD_R;
//Match Doom II GBA retail controls ~ Kippykip
const int     key_fire = KEYD_B; 
const int     key_use = KEYD_A;
const int     key_speed = KEYD_A;
const int     key_escape = KEYD_START;                           // phares 4/13/98
const int     key_enter = KEYD_A;
const int     key_map_right = KEYD_RIGHT;
const int     key_map_left = KEYD_LEFT;
const int     key_map_up = KEYD_UP;
const int     key_map_down = KEYD_DOWN;
const int     key_map = KEYD_SELECT;
const int     key_map_follow = KEYD_A;
const int     key_map_zoomin = KEYD_R;
const int     key_map_zoomout = KEYD_L;
                                          // phares

#define MAXPLMOVE   (forwardmove[1])
#define TURBOTHRESHOLD  0x32
#define SLOWTURNTICS  6
#define QUICKREVERSE (short)32768 // 180 degree reverse                    // phares

static const fixed_t forwardmove[2] = {0x19, 0x32};
static const fixed_t sidemove[2]    = {0x18, 0x28};
static const fixed_t angleturn[3]   = {640, 1280, 320};  // + slow turn

static const byte* G_ReadDemoHeader(const byte* demo_p, size_t size, boolean failonerror);


const unsigned int settings_cookie = 0xbaddead1;

typedef struct gba_save_data_t
{
    int save_present;
    skill_t gameskill;
    int gameepisode;
    int gamemap;
    int totalleveltimes;
    int alwaysRun;
    int gamma;

    int weaponowned[NUMWEAPONS];
    int ammo[NUMAMMO];
    int maxammo[NUMAMMO];
} gba_save_data_t;



const unsigned int settings_sram_offset = sizeof(gba_save_data_t) * 8;

//
// G_BuildTiccmd
// Builds a ticcmd from all of the available inputs
// or reads it from the demo buffer.
// If recording a demo, write it out
//
static inline signed char fudgef(signed char b)
{
  static int c;
  if (!b || _g->longtics) return b;
  if (++c & 0x1f) return b;
  b |= 1; if (b>2) b-=2;
  return b;
}

static inline signed short fudgea(signed short b)
{
  if (!b || !_g->longtics) return b;
  b |= 1; if (b>2) b-=2;
  return b;
}


void G_BuildTiccmd(ticcmd_t* cmd)
{
    int speed;
    int tspeed;
    int forward;
    int side;
    int newweapon;                                          // phares
    /* cphipps - remove needless I_BaseTiccmd call, just set the ticcmd to zero */
    memset(cmd,0,sizeof*cmd);

    //Use button negates the always run setting.
    speed = (_g->gamekeydown[key_use] ^ _g->alwaysRun);

    forward = side = 0;

    // use two stage accelerative turning
    // on the keyboard and joystick
    if (_g->gamekeydown[key_right] || _g->gamekeydown[key_left])
        _g->turnheld ++;
    else
        _g->turnheld = 0;

    if (_g->turnheld < SLOWTURNTICS)
        tspeed = 2;             // slow turn
    else
        tspeed = speed;

    // let movement keys cancel each other out

    if (_g->gamekeydown[key_right])
        cmd->angleturn -= angleturn[tspeed];
    if (_g->gamekeydown[key_left])
        cmd->angleturn += angleturn[tspeed];

    if (_g->gamekeydown[key_up])
        forward += forwardmove[speed];
    if (_g->gamekeydown[key_down])
        forward -= forwardmove[speed];

    if (_g->gamekeydown[key_straferight])
        side += sidemove[speed];

    if (_g->gamekeydown[key_strafeleft])
        side -= sidemove[speed];

    if (_g->gamekeydown[key_fire])
        cmd->buttons |= BT_ATTACK;

    if (_g->gamekeydown[key_use])
    {
        cmd->buttons |= BT_USE;
    }

    // Toggle between the top 2 favorite weapons.                   // phares
    // If not currently aiming one of these, switch to              // phares
    // the favorite. Only switch if you possess the weapon.         // phares

    // killough 3/22/98:
    //
    // Perform automatic weapons switch here rather than in p_pspr.c,
    // except in demo_compatibility mode.
    //
    // killough 3/26/98, 4/2/98: fix autoswitch when no weapons are left

    if(_g->gamekeydown[key_use] && _g->gamekeydown[key_straferight])
    {
        newweapon = P_WeaponCycleUp(&_g->player);
        side -= sidemove[speed]; //Hack cancel strafe.
    }

    else if(_g->gamekeydown[key_use] && _g->gamekeydown[key_strafeleft])
    {
        newweapon = P_WeaponCycleDown(&_g->player);
        side += sidemove[speed]; //Hack cancel strafe.
    }
    else if ((_g->player.attackdown && !P_CheckAmmo(&_g->player)))
        newweapon = P_SwitchWeapon(&_g->player);           // phares
    else
    {                                 // phares 02/26/98: Added gamemode checks
        newweapon = wp_nochange;

        // killough 3/22/98: For network and demo consistency with the
        // new weapons preferences, we must do the weapons switches here
        // instead of in p_user.c. But for old demos we must do it in
        // p_user.c according to the old rules. Therefore demo_compatibility
        // determines where the weapons switch is made.

        // killough 2/8/98:
        // Allow user to switch to fist even if they have chainsaw.
        // Switch to fist or chainsaw based on preferences.
        // Switch to shotgun or SSG based on preferences.

        {
            const player_t *player = &_g->player;

            // only select chainsaw from '1' if it's owned, it's
            // not already in use, and the player prefers it or
            // the fist is already in use, or the player does not
            // have the berserker strength.

            if (newweapon==wp_fist && player->weaponowned[wp_chainsaw] &&
                    player->readyweapon!=wp_chainsaw &&
                    (player->readyweapon==wp_fist ||
                     !player->powers[pw_strength] ||
                     P_WeaponPreferred(wp_chainsaw, wp_fist)))
                newweapon = wp_chainsaw;

            // Select SSG from '3' only if it's owned and the player
            // does not have a shotgun, or if the shotgun is already
            // in use, or if the SSG is not already in use and the
            // player prefers it.

            if (newweapon == wp_shotgun && _g->gamemode == commercial &&
                    player->weaponowned[wp_supershotgun] &&
                    (!player->weaponowned[wp_shotgun] ||
                     player->readyweapon == wp_shotgun ||
                     (player->readyweapon != wp_supershotgun &&
                      P_WeaponPreferred(wp_supershotgun, wp_shotgun))))
                newweapon = wp_supershotgun;
        }
        // killough 2/8/98, 3/22/98 -- end of weapon selection changes
    }

    if (newweapon != wp_nochange)
    {
        cmd->buttons |= BT_CHANGE;
        cmd->buttons |= newweapon<<BT_WEAPONSHIFT;
    }

    if (forward > MAXPLMOVE)
        forward = MAXPLMOVE;
    else if (forward < -MAXPLMOVE)
        forward = -MAXPLMOVE;
    if (side > MAXPLMOVE)
        side = MAXPLMOVE;
    else if (side < -MAXPLMOVE)
        side = -MAXPLMOVE;

    cmd->forwardmove += fudgef((signed char)forward);
    cmd->sidemove += side;
    cmd->angleturn = fudgea(cmd->angleturn);

    // CPhipps - special events (game new/load/save/pause)
    if (_g->special_event & BT_SPECIAL) {
        cmd->buttons = _g->special_event;
        _g->special_event = 0;
    }
}

//
// G_RestartLevel
//

void G_RestartLevel(void)
{
  _g->special_event = BT_SPECIAL | (BTS_RESTARTLEVEL & BT_SPECIALMASK);
}

#include "z_bmalloc.h"
//
// G_DoLoadLevel
//

static void G_DoLoadLevel (void)
{
  // Set the sky map.
  // First thing, we have a dummy sky texture name,
  //  a flat. The data is in the WAD only because
  //  we look for an actual index, instead of simply
  //  setting one.

  _g->skyflatnum = R_FlatNumForName ( SKYFLATNAME );

  // DOOM determines the sky texture to be used
  // depending on the current episode, and the game version.
  if (_g->gamemode == commercial)
    // || gamemode == pack_tnt   //jff 3/27/98 sorry guys pack_tnt,pack_plut
    // || gamemode == pack_plut) //aren't gamemodes, this was matching retail
    {
      _g->skytexture = R_LoadTextureByName("SKY3");
      if (_g->gamemap < 12)
        _g->skytexture = R_LoadTextureByName ("SKY1");
      else
        if (_g->gamemap < 21)
          _g->skytexture = R_LoadTextureByName ("SKY2");
    }
  else //jff 3/27/98 and lets not forget about DOOM and Ultimate DOOM huh?
    switch (_g->gameepisode)
      {
      case 1:
        _g->skytexture = R_LoadTextureByName ("SKY1");
        break;
      case 2:
        _g->skytexture = R_LoadTextureByName ("SKY2");
        break;
      case 3:
        _g->skytexture = R_LoadTextureByName ("SKY3");
        break;
      case 4: // Special Edition sky
        _g->skytexture = R_LoadTextureByName ("SKY4");
        break;
      }//jff 3/27/98 end sky setting fix

  /* cph 2006/07/31 - took out unused levelstarttic variable */

  if (_g->wipegamestate == GS_LEVEL)
    _g->wipegamestate = -1;             // force a wipe

  _g->gamestate = GS_LEVEL;


  if (_g->playeringame && _g->player.playerstate == PST_DEAD)
    _g->player.playerstate = PST_REBORN;

  memset (_g->player.frags,0,sizeof(_g->player.frags));


  // initialize the msecnode_t freelist.                     phares 3/25/98
  // any nodes in the freelist are gone by now, cleared
  // by Z_FreeTags() when the previous level ended or player
  // died.

  {
    DECLARE_BLOCK_MEMORY_ALLOC_ZONE(secnodezone);
    NULL_BLOCK_MEMORY_ALLOC_ZONE(secnodezone);
      //extern msecnode_t *headsecnode; // phares 3/25/98
      //headsecnode = NULL;
  }

  P_SetupLevel (_g->gameepisode, _g->gamemap, 0, _g->gameskill);

  _g->gameaction = ga_nothing;
  Z_CheckHeap ();

  // clear cmd building stuff
  memset (_g->gamekeydown, 0, sizeof(_g->gamekeydown));

  _g->special_event = 0; _g->paused = false;

  // killough 5/13/98: in case netdemo has consoleplayer other than green
  ST_Start();
  HU_Start();
}


//
// G_Responder
// Get info needed to make ticcmd_ts for the players.
//

boolean G_Responder (event_t* ev)
{
    // any other key pops up menu if in demos
    //
    // killough 8/2/98: enable automap in -timedemo demos
    //
    // killough 9/29/98: make any key pop up menu regardless of
    // which kind of demo, and allow other events during playback

    if (_g->gameaction == ga_nothing && (_g->demoplayback || _g->gamestate == GS_DEMOSCREEN))
    {

        // killough 10/98:
        // Don't pop up menu, if paused in middle
        // of demo playback, or if automap active.
        // Don't suck up keys, which may be cheats

        return _g->gamestate == GS_DEMOSCREEN &&
                !(_g->paused & 2) && !(_g->automapmode & am_active) &&
                ((ev->type == ev_keydown) ||
                 (ev->type == ev_mouse && ev->data1) ||
                 (ev->type == ev_joystick && ev->data1)) ?
                    M_StartControlPanel(), true : false;
        }



        if (_g->gamestate == GS_FINALE && F_Responder(ev))
            return true;  // finale ate the event

        switch (ev->type)
        {
            case ev_keydown:

                if (ev->data1 <NUMKEYS)
                    _g->gamekeydown[ev->data1] = true;
                return true;    // eat key down events

            case ev_keyup:
                if (ev->data1 <NUMKEYS)
                    _g->gamekeydown[ev->data1] = false;
                return false;   // always let key up events filter down

            default:
                break;
        }
        return false;
    }

//
// G_Ticker
// Make ticcmd_ts for the players.
//

  void G_Ticker (void)
  {
      P_MapStart();
      if(_g->playeringame && _g->player.playerstate == PST_REBORN)
          G_DoReborn (0);
      P_MapEnd();

      // do things to change the game state
      while (_g->gameaction != ga_nothing)
      {
          switch (_g->gameaction)
          {
          case ga_loadlevel:
              _g->player.playerstate = PST_REBORN;
              G_DoLoadLevel ();
              break;
          case ga_newgame:
              G_DoNewGame ();
              break;
          case ga_playdemo:
              G_DoPlayDemo ();
              break;
          case ga_completed:
              G_DoCompleted ();
              break;
          case ga_victory:
              F_StartFinale ();
              break;
          case ga_worlddone:
              G_DoWorldDone ();
              break;
          case ga_nothing:
              break;
          }
      }

      if (_g->paused & 2 || (!_g->demoplayback && _g->menuactive))
          _g->basetic++;  // For revenant tracers and RNG -- we must maintain sync
      else {
          if (_g->playeringame)
          {
              ticcmd_t *cmd = &_g->player.cmd;

              memcpy(cmd, &_g->netcmd, sizeof *cmd);

              if (_g->demoplayback)
                  G_ReadDemoTiccmd (cmd);
          }


          if (_g->playeringame)
          {
              if (_g->player.cmd.buttons & BT_SPECIAL)
              {
                  switch (_g->player.cmd.buttons & BT_SPECIALMASK)
                  {
                  case BTS_PAUSE:
                      _g->paused ^= 1;
                      if (_g->paused)
                          S_PauseSound ();
                      else
                          S_ResumeSound ();
                      break;

                      // CPhipps - Restart the level
                  case BTS_RESTARTLEVEL:
                      if (_g->demoplayback)
                          break;     // CPhipps - Ignore in demos or old games
                      _g->gameaction = ga_loadlevel;
                      break;
                  }
                  _g->player.cmd.buttons = 0;
              }
          }
      }

      // cph - if the gamestate changed, we may need to clean up the old gamestate
      if (_g->gamestate != _g->prevgamestate) {
          switch (_g->prevgamestate) {
          case GS_LEVEL:
              // This causes crashes at level end - Neil Stevens
              // The crash is because the sounds aren't stopped before freeing them
              // the following is a possible fix
              // This fix does avoid the crash wowever, with this fix in, the exit
              // switch sound is cut off
              // S_Stop();
              // Z_FreeTags(PU_LEVEL, PU_PURGELEVEL-1);
              break;
          case GS_INTERMISSION:
              WI_End();
          default:
              break;
          }
          _g->prevgamestate = _g->gamestate;
      }

      // e6y
      // do nothing if a pause has been pressed during playback
      // pausing during intermission can cause desynchs without that
      if (_g->paused & 2 && _g->gamestate != GS_LEVEL)
          return;

      // do main actions
      switch (_g->gamestate)
      {
      case GS_LEVEL:
          P_Ticker ();
          ST_Ticker ();
          AM_Ticker ();
          HU_Ticker ();
          break;

      case GS_INTERMISSION:
          WI_Ticker ();
          break;

      case GS_FINALE:
          F_Ticker ();
          break;

      case GS_DEMOSCREEN:
          D_PageTicker ();
          break;
      }
  }

//
// PLAYER STRUCTURE FUNCTIONS
// also see P_SpawnPlayer in P_Things
//

//
// G_PlayerFinishLevel
// Can when a player completes a level.
//

static void G_PlayerFinishLevel(int player)
{
  player_t *p = &_g->player;
  memset(p->powers, 0, sizeof p->powers);
  memset(p->cards, 0, sizeof p->cards);
  p->mo = NULL;           // cph - this is allocated PU_LEVEL so it's gone
  p->extralight = 0;      // cancel gun flashes
  p->fixedcolormap = 0;   // cancel ir gogles
  p->damagecount = 0;     // no palette changes
  p->bonuscount = 0;
}

//
// G_PlayerReborn
// Called after a player dies
// almost everything is cleared and initialized
//

void G_PlayerReborn (int player)
{
  player_t *p;
  int i;
  int frags[MAXPLAYERS];
  int killcount;
  int itemcount;
  int secretcount;

  memcpy (frags, _g->player.frags, sizeof frags);
  killcount = _g->player.killcount;
  itemcount = _g->player.itemcount;
  secretcount = _g->player.secretcount;

  p = &_g->player;

  // killough 3/10/98,3/21/98: preserve cheats across idclev
  {
    int cheats = p->cheats;
    memset (p, 0, sizeof(*p));
    p->cheats = cheats;
  }

  memcpy(_g->player.frags, frags, sizeof(_g->player.frags));
  _g->player.killcount = killcount;
  _g->player.itemcount = itemcount;
  _g->player.secretcount = secretcount;

  p->usedown = p->attackdown = true;  // don't do anything immediately
  p->playerstate = PST_LIVE;
  p->health = initial_health;  // Ty 03/12/98 - use dehacked values
  p->readyweapon = p->pendingweapon = wp_pistol;
  p->weaponowned[wp_fist] = true;
  p->weaponowned[wp_pistol] = true;
  p->ammo[am_clip] = initial_bullets; // Ty 03/12/98 - use dehacked values

  for (i=0 ; i<NUMAMMO ; i++)
    p->maxammo[i] = maxammo[i];
}

//
// G_DoReborn
//

void G_DoReborn (int playernum)
{
    _g->gameaction = ga_loadlevel;      // reload the level from scratch
}

// DOOM Par Times
const int pars[4][10] = {
  {0},
  {0,30,75,120,90,165,180,180,30,165},
  {0,90,90,90,120,90,360,240,30,170},
  {0,90,45,90,150,90,90,165,30,135}
};

// DOOM II Par Times
const int cpars[32] = {
  30,90,120,120,90,150,120,120,270,90,  //  1-10
  210,150,150,150,210,150,420,150,210,150,  // 11-20
  240,150,180,150,150,300,330,420,300,180,  // 21-30
  120,30          // 31-32
};


void G_ExitLevel (void)
{
  _g->secretexit = false;
  _g->gameaction = ga_completed;
}

// Here's for the german edition.
// IF NO WOLF3D LEVELS, NO SECRET EXIT!

void G_SecretExitLevel (void)
{
  if (_g->gamemode!=commercial || _g->haswolflevels)
    _g->secretexit = true;
  else
    _g->secretexit = false;
  _g->gameaction = ga_completed;
}

//
// G_DoCompleted
//

void G_DoCompleted (void)
{
  _g->gameaction = ga_nothing;

    if (_g->playeringame)
      G_PlayerFinishLevel(0);        // take away cards and stuff

  if (_g->automapmode & am_active)
    AM_Stop();

  if (_g->gamemode != commercial) // kilough 2/7/98
    switch(_g->gamemap)
      {
  // cph - Remove ExM8 special case, so it gets summary screen displayed
      case 9:
          _g->player.didsecret = true;
        break;
      }

  _g->wminfo.didsecret = _g->player.didsecret;
  _g->wminfo.epsd = _g->gameepisode -1;
  _g->wminfo.last = _g->gamemap -1;

  // wminfo.next is 0 biased, unlike gamemap
  if (_g->gamemode == commercial)
    {
      if (_g->secretexit)
        switch(_g->gamemap)
          {
          case 15:
            _g->wminfo.next = 30; break;
          case 31:
            _g->wminfo.next = 31; break;
          }
      else
        switch(_g->gamemap)
          {
          case 31:
          case 32:
            _g->wminfo.next = 15; break;
          default:
            _g->wminfo.next = _g->gamemap;
          }
    }
  else
    {
      if (_g->secretexit)
        _g->wminfo.next = 8;  // go to secret level
      else
        if (_g->gamemap == 9)
          {
            // returning from secret level
            switch (_g->gameepisode)
              {
              case 1:
                _g->wminfo.next = 3;
                break;
              case 2:
                _g->wminfo.next = 5;
                break;
              case 3:
                _g->wminfo.next = 6;
                break;
              case 4:
                _g->wminfo.next = 2;
                break;
              }
          }
        else
          _g->wminfo.next = _g->gamemap;          // go to next level
    }

  _g->wminfo.maxkills = _g->totalkills;
  _g->wminfo.maxitems = _g->totalitems;
  _g->wminfo.maxsecret = _g->totalsecret;
  _g->wminfo.maxfrags = 0;

  if ( _g->gamemode == commercial )
    _g->wminfo.partime = TICRATE*cpars[_g->gamemap-1];
  else
    _g->wminfo.partime = TICRATE*pars[_g->gameepisode][_g->gamemap];

  _g->wminfo.pnum = 0;


      _g->wminfo.plyr[0].in = _g->playeringame;
      _g->wminfo.plyr[0].skills = _g->player.killcount;
      _g->wminfo.plyr[0].sitems = _g->player.itemcount;
      _g->wminfo.plyr[0].ssecret = _g->player.secretcount;
      _g->wminfo.plyr[0].stime = _g->leveltime;
      memcpy (_g->wminfo.plyr[0].frags, _g->player.frags,
              sizeof(_g->wminfo.plyr[0].frags));

  /* cph - modified so that only whole seconds are added to the totalleveltimes
   *  value; so our total is compatible with the "naive" total of just adding
   *  the times in seconds shown for each level. Also means our total time
   *  will agree with Compet-n.
   */
  _g->wminfo.totaltimes = (_g->totalleveltimes += (_g->leveltime - _g->leveltime%35));

  _g->gamestate = GS_INTERMISSION;
  _g->automapmode &= ~am_active;

  // lmpwatch.pl engine-side demo testing support
  // print "FINISHED: <mapname>" when the player exits the current map
  if (nodrawers && (_g->demoplayback || _g->timingdemo)) {
    if (_g->gamemode == commercial)
      lprintf(LO_INFO, "FINISHED: MAP%02d\n", _g->gamemap);
    else
      lprintf(LO_INFO, "FINISHED: E%dM%d\n", _g->gameepisode, _g->gamemap);
  }

  WI_Start (&_g->wminfo);
}

//
// G_WorldDone
//

void G_WorldDone (void)
{
  _g->gameaction = ga_worlddone;

  if (_g->secretexit)
    _g->player.didsecret = true;

  if (_g->gamemode == commercial)
    {
      switch (_g->gamemap)
        {
        case 15:
        case 31:
          if (!_g->secretexit)
            break;
        case 6:
        case 11:
        case 20:
        case 30:
          F_StartFinale ();
          break;
        }
    }
  else if (_g->gamemap == 8)
    _g->gameaction = ga_victory; // cph - after ExM8 summary screen, show victory stuff
}

void G_DoWorldDone (void)
{
  _g->idmusnum = -1;             //jff 3/17/98 allow new level's music to be loaded
  _g->gamestate = GS_LEVEL;
  _g->gamemap = _g->wminfo.next+1;
  G_DoLoadLevel();
  _g->gameaction = ga_nothing;
}

// killough 2/28/98: A ridiculously large number
// of players, the most you'll ever need in a demo
// or savegame. This is used to prevent problems, in
// case more players in a game are supported later.

#define MIN_MAXPLAYERS 32


// CPhipps - size of version header
#define VERSIONSIZE   16

void G_DeferedInitNew(skill_t skill, int episode, int map)
{
  _g->d_skill = skill;
  _g->d_episode = episode;
  _g->d_map = map;
  _g->gameaction = ga_newgame;
}

// killough 3/1/98: function to reload all the default parameter
// settings before a new game begins

void G_ReloadDefaults(void)
{
  // killough 3/1/98: Initialize options based on config file
  // (allows functions above to load different values for demos
  // and savegames without messing up defaults).

  _g->demoplayback = false;
  _g->singledemo = false;            // killough 9/29/98: don't stop after 1 demo
}

void G_DoNewGame (void)
{
  G_ReloadDefaults();            // killough 3/1/98
  G_InitNew (_g->d_skill, _g->d_episode, _g->d_map);
  _g->gameaction = ga_nothing;

  //jff 4/26/98 wake up the status bar in case were coming out of a DM demo
  ST_Start();
}

//
// G_InitNew
// Can be called by the startup code or the menu task,
// consoleplayer, displayplayer, playeringame[] should be set.
//

void G_InitNew(skill_t skill, int episode, int map)
{
  if (_g->paused)
    {
      _g->paused = false;
      S_ResumeSound();
    }

  if (skill > sk_nightmare)
    skill = sk_nightmare;

  if (episode < 1)
    episode = 1;

  if (_g->gamemode == retail)
    {
      if (episode > 4)
        episode = 4;
    }
  else
    if (_g->gamemode == shareware)
      {
        if (episode > 1)
          episode = 1; // only start episode 1 on shareware
      }
    else
      if (episode > 3)
        episode = 3;

  if (map < 1)
    map = 1;
  if (map > 9 && _g->gamemode != commercial)
    map = 9;

  M_ClearRandom();

  _g->respawnmonsters = skill == sk_nightmare;

  _g->player.playerstate = PST_REBORN;

  _g->usergame = true;                // will be set false if a demo
  _g->paused = false;
  _g->automapmode &= ~am_active;
  _g->gameepisode = episode;
  _g->gamemap = map;
  _g->gameskill = skill;

  _g->totalleveltimes = 0; // cph

  G_DoLoadLevel ();
}

//
// DEMO RECORDING
//

#define DEMOMARKER    0x80

void G_ReadDemoTiccmd (ticcmd_t* cmd)
{
  unsigned char at; // e6y: tasdoom stuff

  if (*_g->demo_p == DEMOMARKER)
    G_CheckDemoStatus();      // end of demo data stream
  else if (_g->demoplayback && _g->demo_p + (_g->longtics?5:4) > _g->demobuffer + _g->demolength)
  {
    lprintf(LO_WARN, "G_ReadDemoTiccmd: missing DEMOMARKER\n");
    G_CheckDemoStatus();
  }
  else
    {
      cmd->forwardmove = ((signed char)*_g->demo_p++);
      cmd->sidemove = ((signed char)*_g->demo_p++);
      if (!_g->longtics) {
        cmd->angleturn = ((unsigned char)(at = *_g->demo_p++))<<8;
      } else {
    unsigned int lowbyte = (unsigned char)*_g->demo_p++;
        cmd->angleturn = (((signed int)(*_g->demo_p++))<<8) + lowbyte;
      }
      cmd->buttons = (unsigned char)*_g->demo_p++;
    }
}


/* Same, but read instead of write
 * cph - const byte*'s
 */

const byte *G_ReadOptions(const byte *demo_p)
{
  const byte *target = demo_p + GAME_OPTION_SIZE;

  return target;
}

//
// G_PlayDemo
//

static const char *defdemoname;

void G_DeferedPlayDemo (const char* name)
{
  defdemoname = name;
  _g->gameaction = ga_playdemo;
}

static int demolumpnum = -1;

//e6y: Check for overrun
static boolean CheckForOverrun(const byte *start_p, const byte *current_p, size_t maxsize, size_t size, boolean failonerror)
{
  size_t pos = current_p - start_p;
  if (pos + size > maxsize)
  {
    if (failonerror)
      I_Error("G_ReadDemoHeader: wrong demo header\n");
    else
      return true;
  }
  return false;
}

static const byte* G_ReadDemoHeader(const byte *demo_p, size_t size, boolean failonerror)
{
  skill_t skill;
  int episode, map;

  // e6y
  // The local variable should be used instead of demobuffer,
  // because demobuffer can be uninitialized
  const byte *header_p = demo_p;

  _g->basetic = _g->gametic;  // killough 9/29/98

  // killough 2/22/98, 2/28/98: autodetect old demos and act accordingly.
  // Old demos turn on demo_compatibility => compatibility; new demos load
  // compatibility flag, and other flags as well, as a part of the demo.

  //e6y: check for overrun
  if (CheckForOverrun(header_p, demo_p, size, 1, failonerror))
    return NULL;

  _g->demover = *demo_p++;
  _g->longtics = 0;

  // e6y
  // Handling of unrecognized demo formats
  // Versions up to 1.2 use a 7-byte header - first byte is a skill level.
  // Versions after 1.2 use a 13-byte header - first byte is a demoversion.
  // BOOM's demoversion starts from 200
  if (!((_g->demover >=   0  && _g->demover <=   4) ||
        (_g->demover >= 104  && _g->demover <= 111) ||
        (_g->demover >= 200  && _g->demover <= 214)))
  {
    I_Error("G_ReadDemoHeader: Unknown demo format %d.", _g->demover);
  }

  if (_g->demover < 200)     // Autodetect old demos
    {
      if (_g->demover >= 111) _g->longtics = 1;

      // killough 3/2/98: force these variables to be 0 in demo_compatibility

      // killough 3/6/98: rearrange to fix savegame bugs (moved fastparm,
      // respawnparm, nomonsters flags to G_LoadOptions()/G_SaveOptions())

      if ((skill=_g->demover) >= 100)         // For demos from versions >= 1.4
        {
          //e6y: check for overrun
          if (CheckForOverrun(header_p, demo_p, size, 8, failonerror))
            return NULL;

          skill = *demo_p++;
          episode = *demo_p++;
          map = *demo_p++;
          demo_p++;
          demo_p++;
          demo_p++;
          demo_p++;
          demo_p++;
        }
      else
        {
          //e6y: check for overrun
          if (CheckForOverrun(header_p, demo_p, size, 2, failonerror))
            return NULL;

          episode = *demo_p++;
          map = *demo_p++;
        }

    }
  else    // new versions of demos
    {
      demo_p += 6;               // skip signature;
      switch (_g->demover) {
      case 200: /* BOOM */
      case 201:
        //e6y: check for overrun
        if (CheckForOverrun(header_p, demo_p, size, 1, failonerror))
          return NULL;
	  break;
      case 202:
        //e6y: check for overrun
        if (CheckForOverrun(header_p, demo_p, size, 1, failonerror))
          return NULL;

	  break;
      case 203:
	/* LxDoom or MBF - determine from signature
	 * cph - load compatibility level */
	switch (*(header_p + 2)) {
	case 'B': /* LxDoom */
	  /* cph - DEMOSYNC - LxDoom demos recorded in compatibility modes support dropped */
	  break;
	case 'M':
	  demo_p++;
	  break;
	}
	break;
      case 210:
	demo_p++;
	break;
      case 211:
	demo_p++;
	break;
      case 212:
	demo_p++;
	break;
      case 213:
	demo_p++;
	break;
      case 214:
        _g->longtics = 1;
	demo_p++;
	break;
      }
      //e6y: check for overrun
      if (CheckForOverrun(header_p, demo_p, size, 5, failonerror))
        return NULL;

      skill = *demo_p++;
      episode = *demo_p++;
      map = *demo_p++;
      demo_p++;
      demo_p++;

      //e6y: check for overrun
      if (CheckForOverrun(header_p, demo_p, size, GAME_OPTION_SIZE, failonerror))
        return NULL;

      demo_p = G_ReadOptions(demo_p);  // killough 3/1/98: Read game options

      if (_g->demover == 200)              // killough 6/3/98: partially fix v2.00 demos
        demo_p += 256-GAME_OPTION_SIZE;
    }

      //e6y: check for overrun
      if (CheckForOverrun(header_p, demo_p, size, MAXPLAYERS, failonerror))
        return NULL;

        _g->playeringame = *demo_p++;
      demo_p += MIN_MAXPLAYERS - MAXPLAYERS;

    _g->player.cheats = 0;

  return demo_p;
}

void G_DoPlayDemo(void)
{
  char basename[9];

  ExtractFileBase(defdemoname,basename);           // killough
  basename[8] = 0;

  /* cph - store lump number for unlocking later */
  demolumpnum = W_GetNumForName(basename);
  _g->demobuffer = W_CacheLumpNum(demolumpnum);
  _g->demolength = W_LumpLength(demolumpnum);

  _g->demo_p = G_ReadDemoHeader(_g->demobuffer, _g->demolength, true);

  _g->gameaction = ga_nothing;
  _g->usergame = false;

  _g->demoplayback = true;

  _g->starttime = I_GetTime();
}

/* G_CheckDemoStatus
 *
 * Called after a death or level completion to allow demos to be cleaned up
 * Returns true if a new demo loop action will take place
 */
boolean G_CheckDemoStatus (void)
{
  if (_g->timingdemo)
    {
      int endtime = I_GetTime();
      // killough -- added fps information and made it work for longer demos:
      unsigned realtics = endtime-_g->starttime;
      I_Error ("Timed %u gametics in %u realtics = %-.1f frames per second",
               (unsigned) _g->gametic,realtics,
               (unsigned) _g->gametic * (double) TICRATE / realtics);
    }

  if (_g->demoplayback)
    {
      if (_g->singledemo)
        exit(0);  // killough

      if (demolumpnum != -1)
      {
  demolumpnum = -1;
      }
      G_ReloadDefaults();    // killough 3/1/98
      D_AdvanceDemo ();
      return true;
    }
  return false;
}

