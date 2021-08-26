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
 *  Switches, buttons. Two-state animation. Exits.
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "w_wad.h"
#include "r_main.h"
#include "p_spec.h"
#include "g_game.h"
#include "s_sound.h"
#include "sounds.h"
#include "lprintf.h"

#include "global_data.h"



static const switchlist_t alphSwitchList[] =
{
    // Doom shareware episode 1 switches
    {"SW1BRCOM",	"SW2BRCOM",	1},
    {"SW1BRN1",	"SW2BRN1",	1},
    {"SW1BRN2",	"SW2BRN2",	1},
    {"SW1BRNGN",	"SW2BRNGN",	1},
    {"SW1BROWN",	"SW2BROWN",	1},
    {"SW1COMM",	"SW2COMM",	1},
    {"SW1COMP",	"SW2COMP",	1},
    {"SW1DIRT",	"SW2DIRT",	1},
    {"SW1EXIT",	"SW2EXIT",	1},
    {"SW1GRAY",	"SW2GRAY",	1},
    {"SW1GRAY1",	"SW2GRAY1",	1},
    {"SW1METAL",	"SW2METAL",	1},
    {"SW1PIPE",	"SW2PIPE",	1},
    {"SW1SLAD",	"SW2SLAD",	1},
    {"SW1STARG",	"SW2STARG",	1},
    {"SW1STON1",	"SW2STON1",	1},
    {"SW1STON2",	"SW2STON2",	1},
    {"SW1STONE",	"SW2STONE",	1},
    {"SW1STRTN",	"SW2STRTN",	1},

    // Doom registered episodes 2&3 switches
    {"SW1BLUE",	"SW2BLUE",	2},
    {"SW1CMT",		"SW2CMT",	2},
    {"SW1GARG",	"SW2GARG",	2},
    {"SW1GSTON",	"SW2GSTON",	2},
    {"SW1HOT",		"SW2HOT",	2},
    {"SW1LION",	"SW2LION",	2},
    {"SW1SATYR",	"SW2SATYR",	2},
    {"SW1SKIN",	"SW2SKIN",	2},
    {"SW1VINE",	"SW2VINE",	2},
    {"SW1WOOD",	"SW2WOOD",	2},

    // Doom II switches
    {"SW1PANEL",	"SW2PANEL",	3},
    {"SW1ROCK",	"SW2ROCK",	3},
    {"SW1MET2",	"SW2MET2",	3},
    {"SW1WDMET",	"SW2WDMET",	3},
    {"SW1BRIK",	"SW2BRIK",	3},
    {"SW1MOD1",	"SW2MOD1",	3},
    {"SW1ZIM",		"SW2ZIM",	3},
    {"SW1STON6",	"SW2STON6",	3},
    {"SW1TEK",		"SW2TEK",	3},
    {"SW1MARB",	"SW2MARB",	3},
    {"SW1SKULL",	"SW2SKULL",	3},

    {"\0",		"\0",		0}
};


//
// P_InitSwitchList
// Only called at game initialization.
//
void P_InitSwitchList(void)
{
    int		i;
    int		index;
    int		episode;

    episode = 1;

    if (_g->gamemode == registered || _g->gamemode == retail)
        episode = 2;
    else
        if ( _g->gamemode == commercial )
            episode = 3;

    for (index = 0,i = 0;i < MAXSWITCHES;i++)
    {
        if (!alphSwitchList[i].episode)
        {
            _g->numswitches = index/2;
            _g->switchlist[index] = -1;
            break;
        }

        if (alphSwitchList[i].episode <= episode)
        {
            _g->switchlist[index++] = R_CheckTextureNumForName(alphSwitchList[i].name1);
            _g->switchlist[index++] = R_CheckTextureNumForName(alphSwitchList[i].name2);
        }
    }
}
//
// P_StartButton()
//
// Start a button (retriggerable switch) counting down till it turns off.
//
// Passed the linedef the button is on, which texture on the sidedef contains
// the button, the texture number of the button, and the time the button is
// to remain active in gametics.
// No return.
//
static void P_StartButton
( const line_t*       line,
  bwhere_e      w,
  int           texture,
  int           time )
{
  int           i;

  // See if button is already pressed
  for (i = 0;i < MAXBUTTONS;i++)
    if (_g->buttonlist[i].btimer && _g->buttonlist[i].line == line)
      return;

  for (i = 0;i < MAXBUTTONS;i++)
    if (!_g->buttonlist[i].btimer)    // use first unused element of list
    {
      _g->buttonlist[i].line = line;
      _g->buttonlist[i].where = w;
      _g->buttonlist[i].btexture = texture;
      _g->buttonlist[i].btimer = time;
      /* use sound origin of line itself - no need to compatibility-wrap
       * as the popout code gets it wrong whatever its value */
      _g->buttonlist[i].soundorg = &LN_FRONTSECTOR(line)->soundorg;
      return;
    }

  I_Error("P_StartButton: no button slots left!");
}

//
// P_ChangeSwitchTexture()
//
// Function that changes switch wall texture on activation.
//
// Passed the line which the switch is on, and whether its retriggerable.
// If not retriggerable, this function clears the line special to insure that
//
// No return
//
void P_ChangeSwitchTexture
( const line_t*       line,
  int           useAgain )
{
  /* Rearranged a bit to avoid too much code duplication */
  int     i, sound;
  short   *texture, *ttop, *tmid, *tbot;
  bwhere_e position;

  ttop = &_g->sides[line->sidenum[0]].toptexture;
  tmid = &_g->sides[line->sidenum[0]].midtexture;
  tbot = &_g->sides[line->sidenum[0]].bottomtexture;

  sound = sfx_swtchn;

  /* don't zero line->special until after exit switch test */
  if (!useAgain)
    LN_SPECIAL(line) = 0;

  /* search for a texture to change */
  texture = NULL; position = 0;
  for (i = 0;i < _g->numswitches*2;i++) { /* this could be more efficient... */
    if (_g->switchlist[i] == *ttop) {
      texture = ttop; position = top; break;
    } else if (_g->switchlist[i] == *tmid) {
      texture = tmid; position = middle; break;
    } else if (_g->switchlist[i] == *tbot) {
      texture = tbot; position = bottom; break;
    }
  }
  if (texture == NULL)
    return; /* no switch texture was found to change */
  *texture = _g->switchlist[i^1];

  S_StartSound2(&LN_FRONTSECTOR(line)->soundorg, sound);

  if (useAgain)
    P_StartButton(line, position, _g->switchlist[i], BUTTONTIME);
}


//
// P_UseSpecialLine
//
//
// Called when a thing uses (pushes) a special line.
// Only the front sides of lines are usable.
// Dispatches to the appropriate linedef function handler.
//
// Passed the thing using the line, the line being used, and the side used
// Returns true if a thinker was created
//
boolean
P_UseSpecialLine
( mobj_t*       thing,
  const line_t*       line,
  int           side )
{

  // e6y
  // b.m. side test was broken in boom201
  if ((_g->demoplayback ? (_g->demover != 201) : (true)))
  if (side) //jff 6/1/98 fix inadvertent deletion of side test
    return false;

  //jff 02/04/98 add check here for generalized floor/ceil mover
  {
    // pointer to line function is NULL by default, set non-null if
    // line special is push or switch generalized linedef type
    int (*linefunc)(const line_t *line)=NULL;

    // check each range of generalized linedefs
    if ((unsigned)LN_SPECIAL(line) >= GenEnd)
    {
      // Out of range for GenFloors
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenFloorBase)
    {
      if (!thing->player)
        if ((LN_SPECIAL(line) & FloorChange) || !(LN_SPECIAL(line) & FloorModel))
          return false; // FloorModel is "Allow Monsters" if FloorChange is 0
      if (!line->tag && ((LN_SPECIAL(line)&6)!=6)) //jff 2/27/98 all non-manual
        return false;                         // generalized types require tag
      linefunc = EV_DoGenFloor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenCeilingBase)
    {
      if (!thing->player)
        if ((LN_SPECIAL(line) & CeilingChange) || !(LN_SPECIAL(line) & CeilingModel))
          return false;   // CeilingModel is "Allow Monsters" if CeilingChange is 0
      if (!line->tag && ((LN_SPECIAL(line)&6)!=6)) //jff 2/27/98 all non-manual
        return false;                         // generalized types require tag
      linefunc = EV_DoGenCeiling;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenDoorBase)
    {
      if (!thing->player)
      {
        if (!(LN_SPECIAL(line) & DoorMonster))
          return false;   // monsters disallowed from this door
        if (line->flags & ML_SECRET) // they can't open secret doors either
          return false;
      }
      if (!line->tag && ((LN_SPECIAL(line)&6)!=6)) //jff 3/2/98 all non-manual
        return false;                         // generalized types require tag
      linefunc = EV_DoGenDoor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenLockedBase)
    {
      if (!thing->player)
        return false;   // monsters disallowed from unlocking doors
      if (!P_CanUnlockGenDoor(line,thing->player))
        return false;
      if (!line->tag && ((LN_SPECIAL(line)&6)!=6)) //jff 2/27/98 all non-manual
        return false;                         // generalized types require tag

      linefunc = EV_DoGenLockedDoor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenLiftBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & LiftMonster))
          return false; // monsters disallowed
      if (!line->tag && ((LN_SPECIAL(line)&6)!=6)) //jff 2/27/98 all non-manual
        return false;                         // generalized types require tag
      linefunc = EV_DoGenLift;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenStairsBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & StairMonster))
          return false; // monsters disallowed
      if (!line->tag && ((LN_SPECIAL(line)&6)!=6)) //jff 2/27/98 all non-manual
        return false;                         // generalized types require tag
      linefunc = EV_DoGenStairs;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenCrusherBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & CrusherMonster))
          return false; // monsters disallowed
      if (!line->tag && ((LN_SPECIAL(line)&6)!=6)) //jff 2/27/98 all non-manual
        return false;                         // generalized types require tag
      linefunc = EV_DoGenCrusher;
    }

    if (linefunc)
      switch((LN_SPECIAL(line) & TriggerType) >> TriggerTypeShift)
      {
        case PushOnce:
          if (!side)
            if (linefunc(line))
              LN_SPECIAL(line) = 0;
          return true;
        case PushMany:
          if (!side)
            linefunc(line);
          return true;
        case SwitchOnce:
          if (linefunc(line))
            P_ChangeSwitchTexture(line,0);
          return true;
        case SwitchMany:
          if (linefunc(line))
            P_ChangeSwitchTexture(line,1);
          return true;
        default:  // if not a switch/push type, do nothing here
          return false;
      }
  }

  // Switches that other things can activate.
  if (!thing->player)
  {
    // never open secret doors
    if (line->flags & ML_SECRET)
      return false;

    switch(LN_SPECIAL(line))
    {
      case 1:         // MANUAL DOOR RAISE
      case 32:        // MANUAL BLUE
      case 33:        // MANUAL RED
      case 34:        // MANUAL YELLOW
      //jff 3/5/98 add ability to use teleporters for monsters
      case 195:       // switch teleporters
      case 174:
      case 210:       // silent switch teleporters
      case 209:
        break;

      default:
        return false;
    }
  }

  if (!P_CheckTag(line))  //jff 2/27/98 disallow zero tag on some types
    return false;

  // Dispatch to handler according to linedef type
  switch (LN_SPECIAL(line))
  {
    // Manual doors, push type with no tag
    case 1:             // Vertical Door
    case 26:            // Blue Door/Locked
    case 27:            // Yellow Door /Locked
    case 28:            // Red Door /Locked

    case 31:            // Manual door open
    case 32:            // Blue locked door open
    case 33:            // Red locked door open
    case 34:            // Yellow locked door open

    case 117:           // Blazing door raise
    case 118:           // Blazing door open
      EV_VerticalDoor (line, thing);
      break;

    // Switches (non-retriggerable)
    case 7:
      // Build Stairs
      if (EV_BuildStairs(line,build8))
        P_ChangeSwitchTexture(line,0);
      break;

    case 9:
      // Change Donut
      if (EV_DoDonut(line))
        P_ChangeSwitchTexture(line,0);
      break;

    case 11:
      /* Exit level
       * killough 10/98: prevent zombies from exiting levels
       */
      if (thing->player && thing->player->health <= 0)
      {
        S_StartSound(thing, sfx_noway);
        return false;
      }

      P_ChangeSwitchTexture(line,0);
      G_ExitLevel ();
      break;

    case 14:
      // Raise Floor 32 and change texture
      if (EV_DoPlat(line,raiseAndChange,32))
        P_ChangeSwitchTexture(line,0);
      break;

    case 15:
      // Raise Floor 24 and change texture
      if (EV_DoPlat(line,raiseAndChange,24))
        P_ChangeSwitchTexture(line,0);
      break;

    case 18:
      // Raise Floor to next highest floor
      if (EV_DoFloor(line, raiseFloorToNearest))
        P_ChangeSwitchTexture(line,0);
      break;

    case 20:
      // Raise Plat next highest floor and change texture
      if (EV_DoPlat(line,raiseToNearestAndChange,0))
        P_ChangeSwitchTexture(line,0);
      break;

    case 21:
      // PlatDownWaitUpStay
      if (EV_DoPlat(line,downWaitUpStay,0))
        P_ChangeSwitchTexture(line,0);
      break;

    case 23:
      // Lower Floor to Lowest
      if (EV_DoFloor(line,lowerFloorToLowest))
        P_ChangeSwitchTexture(line,0);
      break;

    case 29:
      // Raise Door
      if (EV_DoDoor(line,normal))
        P_ChangeSwitchTexture(line,0);
      break;

    case 41:
      // Lower Ceiling to Floor
      if (EV_DoCeiling(line,lowerToFloor))
        P_ChangeSwitchTexture(line,0);
      break;

    case 71:
      // Turbo Lower Floor
      if (EV_DoFloor(line,turboLower))
        P_ChangeSwitchTexture(line,0);
      break;

    case 49:
      // Ceiling Crush And Raise
      if (EV_DoCeiling(line,crushAndRaise))
        P_ChangeSwitchTexture(line,0);
      break;

    case 50:
      // Close Door
      if (EV_DoDoor(line,dclose))
        P_ChangeSwitchTexture(line,0);
      break;

    case 51:
      /* Secret EXIT
       * killough 10/98: prevent zombies from exiting levels
       */
      if (thing->player && thing->player->health <= 0)
      {
        S_StartSound(thing, sfx_noway);
        return false;
      }

      P_ChangeSwitchTexture(line,0);
      G_SecretExitLevel ();
      break;

    case 55:
      // Raise Floor Crush
      if (EV_DoFloor(line,raiseFloorCrush))
        P_ChangeSwitchTexture(line,0);
      break;

    case 101:
      // Raise Floor
      if (EV_DoFloor(line,raiseFloor))
        P_ChangeSwitchTexture(line,0);
      break;

    case 102:
      // Lower Floor to Surrounding floor height
      if (EV_DoFloor(line,lowerFloor))
        P_ChangeSwitchTexture(line,0);
      break;

    case 103:
      // Open Door
      if (EV_DoDoor(line,dopen))
        P_ChangeSwitchTexture(line,0);
      break;

    case 111:
      // Blazing Door Raise (faster than TURBO!)
      if (EV_DoDoor (line,blazeRaise))
        P_ChangeSwitchTexture(line,0);
      break;

    case 112:
      // Blazing Door Open (faster than TURBO!)
      if (EV_DoDoor (line,blazeOpen))
        P_ChangeSwitchTexture(line,0);
      break;

    case 113:
      // Blazing Door Close (faster than TURBO!)
      if (EV_DoDoor (line,blazeClose))
        P_ChangeSwitchTexture(line,0);
      break;

    case 122:
      // Blazing PlatDownWaitUpStay
      if (EV_DoPlat(line,blazeDWUS,0))
        P_ChangeSwitchTexture(line,0);
      break;

    case 127:
      // Build Stairs Turbo 16
      if (EV_BuildStairs(line,turbo16))
        P_ChangeSwitchTexture(line,0);
      break;

    case 131:
      // Raise Floor Turbo
      if (EV_DoFloor(line,raiseFloorTurbo))
        P_ChangeSwitchTexture(line,0);
      break;

    case 133:
      // BlzOpenDoor BLUE
    case 135:
      // BlzOpenDoor RED
    case 137:
      // BlzOpenDoor YELLOW
      if (EV_DoLockedDoor (line,blazeOpen,thing))
        P_ChangeSwitchTexture(line,0);
      break;

    case 140:
      // Raise Floor 512
      if (EV_DoFloor(line,raiseFloor512))
        P_ChangeSwitchTexture(line,0);
      break;

      // killough 1/31/98: factored out compatibility check;
      // added inner switch, relaxed check to demo_compatibility

    default:
        switch (LN_SPECIAL(line))
        {
          //jff 1/29/98 added linedef types to fill all functions out so that
          // all possess SR, S1, WR, W1 types

          case 158:
            // Raise Floor to shortest lower texture
            // 158 S1  EV_DoFloor(raiseToTexture), CSW(0)
            if (EV_DoFloor(line,raiseToTexture))
              P_ChangeSwitchTexture(line,0);
            break;

          case 159:
            // Raise Floor to shortest lower texture
            // 159 S1  EV_DoFloor(lowerAndChange)
            if (EV_DoFloor(line,lowerAndChange))
              P_ChangeSwitchTexture(line,0);
            break;

          case 160:
            // Raise Floor 24 and change
            // 160 S1  EV_DoFloor(raiseFloor24AndChange)
            if (EV_DoFloor(line,raiseFloor24AndChange))
              P_ChangeSwitchTexture(line,0);
            break;

          case 161:
            // Raise Floor 24
            // 161 S1  EV_DoFloor(raiseFloor24)
            if (EV_DoFloor(line,raiseFloor24))
              P_ChangeSwitchTexture(line,0);
            break;

          case 162:
            // Moving floor min n to max n
            // 162 S1  EV_DoPlat(perpetualRaise,0)
            if (EV_DoPlat(line,perpetualRaise,0))
              P_ChangeSwitchTexture(line,0);
            break;

          case 163:
            // Stop Moving floor
            // 163 S1  EV_DoPlat(perpetualRaise,0)
            EV_StopPlat(line);
            P_ChangeSwitchTexture(line,0);
            break;

          case 164:
            // Start fast crusher
            // 164 S1  EV_DoCeiling(fastCrushAndRaise)
            if (EV_DoCeiling(line,fastCrushAndRaise))
              P_ChangeSwitchTexture(line,0);
            break;

          case 165:
            // Start slow silent crusher
            // 165 S1  EV_DoCeiling(silentCrushAndRaise)
            if (EV_DoCeiling(line,silentCrushAndRaise))
              P_ChangeSwitchTexture(line,0);
            break;

          case 166:
            // Raise ceiling, Lower floor
            // 166 S1 EV_DoCeiling(raiseToHighest), EV_DoFloor(lowerFloortoLowest)
            if (EV_DoCeiling(line, raiseToHighest) ||
                EV_DoFloor(line, lowerFloorToLowest))
              P_ChangeSwitchTexture(line,0);
            break;

          case 167:
            // Lower floor and Crush
            // 167 S1 EV_DoCeiling(lowerAndCrush)
            if (EV_DoCeiling(line, lowerAndCrush))
              P_ChangeSwitchTexture(line,0);
            break;

          case 168:
            // Stop crusher
            // 168 S1 EV_CeilingCrushStop()
            if (EV_CeilingCrushStop(line))
              P_ChangeSwitchTexture(line,0);
            break;

          case 169:
            // Lights to brightest neighbor sector
            // 169 S1  EV_LightTurnOn(0)
            EV_LightTurnOn(line,0);
            P_ChangeSwitchTexture(line,0);
            break;

          case 170:
            // Lights to near dark
            // 170 S1  EV_LightTurnOn(35)
            EV_LightTurnOn(line,35);
            P_ChangeSwitchTexture(line,0);
            break;

          case 171:
            // Lights on full
            // 171 S1  EV_LightTurnOn(255)
            EV_LightTurnOn(line,255);
            P_ChangeSwitchTexture(line,0);
            break;

          case 172:
            // Start Lights Strobing
            // 172 S1  EV_StartLightStrobing()
            EV_StartLightStrobing(line);
            P_ChangeSwitchTexture(line,0);
            break;

          case 173:
            // Lights to Dimmest Near
            // 173 S1  EV_TurnTagLightsOff()
            EV_TurnTagLightsOff(line);
            P_ChangeSwitchTexture(line,0);
            break;

          case 174:
            // Teleport
            // 174 S1  EV_Teleport(side,thing)
            if (EV_Teleport(line,side,thing))
              P_ChangeSwitchTexture(line,0);
            break;

          case 175:
            // Close Door, Open in 30 secs
            // 175 S1  EV_DoDoor(close30ThenOpen)
            if (EV_DoDoor(line,close30ThenOpen))
              P_ChangeSwitchTexture(line,0);
            break;

          case 189: //jff 3/15/98 create texture change no motion type
            // Texture Change Only (Trigger)
            // 189 S1 Change Texture/Type Only
            if (EV_DoChange(line,trigChangeOnly))
              P_ChangeSwitchTexture(line,0);
            break;

          case 203:
            // Lower ceiling to lowest surrounding ceiling
            // 203 S1 EV_DoCeiling(lowerToLowest)
            if (EV_DoCeiling(line,lowerToLowest))
              P_ChangeSwitchTexture(line,0);
            break;

          case 204:
            // Lower ceiling to highest surrounding floor
            // 204 S1 EV_DoCeiling(lowerToMaxFloor)
            if (EV_DoCeiling(line,lowerToMaxFloor))
              P_ChangeSwitchTexture(line,0);
            break;

          case 209:
            // killough 1/31/98: silent teleporter
            //jff 209 S1 SilentTeleport
            if (EV_SilentTeleport(line, side, thing))
              P_ChangeSwitchTexture(line,0);
            break;

          case 241: //jff 3/15/98 create texture change no motion type
            // Texture Change Only (Numeric)
            // 241 S1 Change Texture/Type Only
            if (EV_DoChange(line,numChangeOnly))
              P_ChangeSwitchTexture(line,0);
            break;

          case 221:
            // Lower floor to next lowest floor
            // 221 S1 Lower Floor To Nearest Floor
            if (EV_DoFloor(line,lowerFloorToNearest))
              P_ChangeSwitchTexture(line,0);
            break;

          case 229:
            // Raise elevator next floor
            // 229 S1 Raise Elevator next floor
            if (EV_DoElevator(line,elevateUp))
              P_ChangeSwitchTexture(line,0);
            break;

          case 233:
            // Lower elevator next floor
            // 233 S1 Lower Elevator next floor
            if (EV_DoElevator(line,elevateDown))
              P_ChangeSwitchTexture(line,0);
            break;

          case 237:
            // Elevator to current floor
            // 237 S1 Elevator to current floor
            if (EV_DoElevator(line,elevateCurrent))
              P_ChangeSwitchTexture(line,0);
            break;


          // jff 1/29/98 end of added S1 linedef types

          //jff 1/29/98 added linedef types to fill all functions out so that
          // all possess SR, S1, WR, W1 types

          case 78: //jff 3/15/98 create texture change no motion type
            // Texture Change Only (Numeric)
            // 78 SR Change Texture/Type Only
            if (EV_DoChange(line,numChangeOnly))
              P_ChangeSwitchTexture(line,1);
            break;

          case 176:
            // Raise Floor to shortest lower texture
            // 176 SR  EV_DoFloor(raiseToTexture), CSW(1)
            if (EV_DoFloor(line,raiseToTexture))
              P_ChangeSwitchTexture(line,1);
            break;

          case 177:
            // Raise Floor to shortest lower texture
            // 177 SR  EV_DoFloor(lowerAndChange)
            if (EV_DoFloor(line,lowerAndChange))
              P_ChangeSwitchTexture(line,1);
            break;

          case 178:
            // Raise Floor 512
            // 178 SR  EV_DoFloor(raiseFloor512)
            if (EV_DoFloor(line,raiseFloor512))
              P_ChangeSwitchTexture(line,1);
            break;

          case 179:
            // Raise Floor 24 and change
            // 179 SR  EV_DoFloor(raiseFloor24AndChange)
            if (EV_DoFloor(line,raiseFloor24AndChange))
              P_ChangeSwitchTexture(line,1);
            break;

          case 180:
            // Raise Floor 24
            // 180 SR  EV_DoFloor(raiseFloor24)
            if (EV_DoFloor(line,raiseFloor24))
              P_ChangeSwitchTexture(line,1);
            break;

          case 181:
            // Moving floor min n to max n
            // 181 SR  EV_DoPlat(perpetualRaise,0)

            EV_DoPlat(line,perpetualRaise,0);
            P_ChangeSwitchTexture(line,1);
            break;

          case 182:
            // Stop Moving floor
            // 182 SR  EV_DoPlat(perpetualRaise,0)
            EV_StopPlat(line);
            P_ChangeSwitchTexture(line,1);
            break;

          case 183:
            // Start fast crusher
            // 183 SR  EV_DoCeiling(fastCrushAndRaise)
            if (EV_DoCeiling(line,fastCrushAndRaise))
              P_ChangeSwitchTexture(line,1);
            break;

          case 184:
            // Start slow crusher
            // 184 SR  EV_DoCeiling(crushAndRaise)
            if (EV_DoCeiling(line,crushAndRaise))
              P_ChangeSwitchTexture(line,1);
            break;

          case 185:
            // Start slow silent crusher
            // 185 SR  EV_DoCeiling(silentCrushAndRaise)
            if (EV_DoCeiling(line,silentCrushAndRaise))
              P_ChangeSwitchTexture(line,1);
            break;

          case 186:
            // Raise ceiling, Lower floor
            // 186 SR EV_DoCeiling(raiseToHighest), EV_DoFloor(lowerFloortoLowest)
            if (EV_DoCeiling(line, raiseToHighest) ||
                EV_DoFloor(line, lowerFloorToLowest))
              P_ChangeSwitchTexture(line,1);
            break;

          case 187:
            // Lower floor and Crush
            // 187 SR EV_DoCeiling(lowerAndCrush)
            if (EV_DoCeiling(line, lowerAndCrush))
              P_ChangeSwitchTexture(line,1);
            break;

          case 188:
            // Stop crusher
            // 188 SR EV_CeilingCrushStop()
            if (EV_CeilingCrushStop(line))
              P_ChangeSwitchTexture(line,1);
            break;

          case 190: //jff 3/15/98 create texture change no motion type
            // Texture Change Only (Trigger)
            // 190 SR Change Texture/Type Only
            if (EV_DoChange(line,trigChangeOnly))
              P_ChangeSwitchTexture(line,1);
            break;

          case 191:
            // Lower Pillar, Raise Donut
            // 191 SR  EV_DoDonut()
            if (EV_DoDonut(line))
              P_ChangeSwitchTexture(line,1);
            break;

          case 192:
            // Lights to brightest neighbor sector
            // 192 SR  EV_LightTurnOn(0)
            EV_LightTurnOn(line,0);
            P_ChangeSwitchTexture(line,1);
            break;

          case 193:
            // Start Lights Strobing
            // 193 SR  EV_StartLightStrobing()
            EV_StartLightStrobing(line);
            P_ChangeSwitchTexture(line,1);
            break;

          case 194:
            // Lights to Dimmest Near
            // 194 SR  EV_TurnTagLightsOff()
            EV_TurnTagLightsOff(line);
            P_ChangeSwitchTexture(line,1);
            break;

          case 195:
            // Teleport
            // 195 SR  EV_Teleport(side,thing)
            if (EV_Teleport(line,side,thing))
              P_ChangeSwitchTexture(line,1);
            break;

          case 196:
            // Close Door, Open in 30 secs
            // 196 SR  EV_DoDoor(close30ThenOpen)
            if (EV_DoDoor(line,close30ThenOpen))
              P_ChangeSwitchTexture(line,1);
            break;

          case 205:
            // Lower ceiling to lowest surrounding ceiling
            // 205 SR EV_DoCeiling(lowerToLowest)
            if (EV_DoCeiling(line,lowerToLowest))
              P_ChangeSwitchTexture(line,1);
            break;

          case 206:
            // Lower ceiling to highest surrounding floor
            // 206 SR EV_DoCeiling(lowerToMaxFloor)
            if (EV_DoCeiling(line,lowerToMaxFloor))
              P_ChangeSwitchTexture(line,1);
            break;

          case 210:
            // killough 1/31/98: silent teleporter
            //jff 210 SR SilentTeleport
            if (EV_SilentTeleport(line, side, thing))
              P_ChangeSwitchTexture(line,1);
            break;

          case 211: //jff 3/14/98 create instant toggle floor type
            // Toggle Floor Between C and F Instantly
            // 211 SR Toggle Floor Instant
            if (EV_DoPlat(line,toggleUpDn,0))
              P_ChangeSwitchTexture(line,1);
            break;

          case 222:
            // Lower floor to next lowest floor
            // 222 SR Lower Floor To Nearest Floor
            if (EV_DoFloor(line,lowerFloorToNearest))
              P_ChangeSwitchTexture(line,1);
            break;

          case 230:
            // Raise elevator next floor
            // 230 SR Raise Elevator next floor
            if (EV_DoElevator(line,elevateUp))
              P_ChangeSwitchTexture(line,1);
            break;

          case 234:
            // Lower elevator next floor
            // 234 SR Lower Elevator next floor
            if (EV_DoElevator(line,elevateDown))
              P_ChangeSwitchTexture(line,1);
            break;

          case 238:
            // Elevator to current floor
            // 238 SR Elevator to current floor
            if (EV_DoElevator(line,elevateCurrent))
              P_ChangeSwitchTexture(line,1);
            break;

          case 258:
            // Build stairs, step 8
            // 258 SR EV_BuildStairs(build8)
            if (EV_BuildStairs(line,build8))
              P_ChangeSwitchTexture(line,1);
            break;

          case 259:
            // Build stairs, step 16
            // 259 SR EV_BuildStairs(turbo16)
            if (EV_BuildStairs(line,turbo16))
              P_ChangeSwitchTexture(line,1);
            break;

          // 1/29/98 jff end of added SR linedef types

        }
      break;

    // Buttons (retriggerable switches)
    case 42:
      // Close Door
      if (EV_DoDoor(line,dclose))
        P_ChangeSwitchTexture(line,1);
      break;

    case 43:
      // Lower Ceiling to Floor
      if (EV_DoCeiling(line,lowerToFloor))
        P_ChangeSwitchTexture(line,1);
      break;

    case 45:
      // Lower Floor to Surrounding floor height
      if (EV_DoFloor(line,lowerFloor))
        P_ChangeSwitchTexture(line,1);
      break;

    case 60:
      // Lower Floor to Lowest
      if (EV_DoFloor(line,lowerFloorToLowest))
        P_ChangeSwitchTexture(line,1);
      break;

    case 61:
      // Open Door
      if (EV_DoDoor(line,dopen))
        P_ChangeSwitchTexture(line,1);
      break;

    case 62:
      // PlatDownWaitUpStay
      if (EV_DoPlat(line,downWaitUpStay,1))
        P_ChangeSwitchTexture(line,1);
      break;

    case 63:
      // Raise Door
      if (EV_DoDoor(line,normal))
        P_ChangeSwitchTexture(line,1);
      break;

    case 64:
      // Raise Floor to ceiling
      if (EV_DoFloor(line,raiseFloor))
        P_ChangeSwitchTexture(line,1);
      break;

    case 66:
      // Raise Floor 24 and change texture
      if (EV_DoPlat(line,raiseAndChange,24))
        P_ChangeSwitchTexture(line,1);
      break;

    case 67:
      // Raise Floor 32 and change texture
      if (EV_DoPlat(line,raiseAndChange,32))
        P_ChangeSwitchTexture(line,1);
      break;

    case 65:
      // Raise Floor Crush
      if (EV_DoFloor(line,raiseFloorCrush))
        P_ChangeSwitchTexture(line,1);
      break;

    case 68:
      // Raise Plat to next highest floor and change texture
      if (EV_DoPlat(line,raiseToNearestAndChange,0))
        P_ChangeSwitchTexture(line,1);
      break;

    case 69:
      // Raise Floor to next highest floor
      if (EV_DoFloor(line, raiseFloorToNearest))
        P_ChangeSwitchTexture(line,1);
      break;

    case 70:
      // Turbo Lower Floor
      if (EV_DoFloor(line,turboLower))
        P_ChangeSwitchTexture(line,1);
      break;

    case 114:
      // Blazing Door Raise (faster than TURBO!)
      if (EV_DoDoor (line,blazeRaise))
        P_ChangeSwitchTexture(line,1);
      break;

    case 115:
      // Blazing Door Open (faster than TURBO!)
      if (EV_DoDoor (line,blazeOpen))
        P_ChangeSwitchTexture(line,1);
      break;

    case 116:
      // Blazing Door Close (faster than TURBO!)
      if (EV_DoDoor (line,blazeClose))
        P_ChangeSwitchTexture(line,1);
      break;

    case 123:
      // Blazing PlatDownWaitUpStay
      if (EV_DoPlat(line,blazeDWUS,0))
        P_ChangeSwitchTexture(line,1);
      break;

    case 132:
      // Raise Floor Turbo
      if (EV_DoFloor(line,raiseFloorTurbo))
        P_ChangeSwitchTexture(line,1);
      break;

    case 99:
      // BlzOpenDoor BLUE
    case 134:
      // BlzOpenDoor RED
    case 136:
      // BlzOpenDoor YELLOW
      if (EV_DoLockedDoor (line,blazeOpen,thing))
        P_ChangeSwitchTexture(line,1);
      break;

    case 138:
      // Light Turn On
      EV_LightTurnOn(line,255);
      P_ChangeSwitchTexture(line,1);
      break;

    case 139:
      // Light Turn Off
      EV_LightTurnOn(line,35);
      P_ChangeSwitchTexture(line,1);
      break;
  }
  return true;
}
