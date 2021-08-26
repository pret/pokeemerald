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
 * DESCRIPTION:
 *      Moving object handling. Spawn functions.
 *
 *-----------------------------------------------------------------------------*/

#include "doomdef.h"
#include "doomstat.h"
#include "m_random.h"
#include "r_main.h"
#include "p_maputl.h"
#include "p_map.h"
#include "p_tick.h"
#include "sounds.h"
#include "st_stuff.h"
#include "hu_stuff.h"
#include "s_sound.h"
#include "info.h"
#include "g_game.h"
#include "p_inter.h"
#include "lprintf.h"

#include "global_data.h"




//
// P_ExplodeMissile
//

void P_ExplodeMissile (mobj_t* mo)
  {
  mo->momx = mo->momy = mo->momz = 0;

  P_SetMobjState (mo, mobjinfo[mo->type].deathstate);

  mo->tics -= P_Random()&3;

  if (mo->tics < 1)
    mo->tics = 1;

  mo->flags &= ~MF_MISSILE;

  if (mo->info->deathsound)
    S_StartSound (mo, mo->info->deathsound);
  }


//
// P_XYMovement
//
// Attempts to move something if it has momentum.
//

void P_XYMovement (mobj_t* mo)
{
    player_t *player;
    fixed_t xmove, ymove;

    if (!(mo->momx | mo->momy)) // Any momentum?
    {
        if (mo->flags & MF_SKULLFLY)
        {

            // the skull slammed into something

            mo->flags &= ~MF_SKULLFLY;
            mo->momz = 0;

            P_SetMobjState (mo, mo->info->spawnstate);
        }
        return;
    }

    player = mo->player;

    if (mo->momx > MAXMOVE)
        mo->momx = MAXMOVE;
    else if (mo->momx < -MAXMOVE)
        mo->momx = -MAXMOVE;

    if (mo->momy > MAXMOVE)
        mo->momy = MAXMOVE;
    else if (mo->momy < -MAXMOVE)
        mo->momy = -MAXMOVE;

    xmove = mo->momx;
    ymove = mo->momy;

    do
    {
        fixed_t ptryx, ptryy;
        // killough 8/9/98: fix bug in original Doom source:
        // Large negative displacements were never considered.
        // This explains the tendency for Mancubus fireballs
        // to pass through walls.
        // CPhipps - compatibility optioned

        if (xmove > MAXMOVE/2 || ymove > MAXMOVE/2 || ((xmove < -MAXMOVE/2 || ymove < -MAXMOVE/2)))
        {
            ptryx = mo->x + xmove/2;
            ptryy = mo->y + ymove/2;
            xmove >>= 1;
            ymove >>= 1;
        }
        else
        {
            ptryx = mo->x + xmove;
            ptryy = mo->y + ymove;
            xmove = ymove = 0;
        }

        // killough 3/15/98: Allow objects to drop off

        if (!P_TryMove (mo, ptryx, ptryy, true))
        {
            // blocked move

            if (player)   // try to slide along it
                P_SlideMove (mo);
            else
            {
                if (mo->flags & MF_MISSILE)
                {
                    // explode a missile

                    if (_g->ceilingline)
                    {
                        const sector_t* ceilingBackSector = LN_BACKSECTOR(_g->ceilingline);

                        if(ceilingBackSector && ceilingBackSector->ceilingpic == _g->skyflatnum)
                        {
                            if (mo->z > ceilingBackSector->ceilingheight)
                            {
                                // Hack to prevent missiles exploding
                                // against the sky.
                                // Does not handle sky floors.

                                P_RemoveMobj (mo);
                                return;
                            }
                        }
                    }

                    P_ExplodeMissile (mo);
                }
                else // whatever else it is, it is now standing still in (x,y)
                {
                    mo->momx = mo->momy = 0;
                }
            }
        }
    } while (xmove || ymove);

    // slow down

    /* no friction for missiles or skulls ever, no friction when airborne */
    if (mo->flags & (MF_MISSILE | MF_SKULLFLY) || mo->z > mo->floorz)
        return;

    /* killough 8/11/98: add bouncers
   * killough 9/15/98: add objects falling off ledges
   * killough 11/98: only include bouncers hanging off ledges
   */
    if ((mo->flags & MF_CORPSE) &&
            (mo->momx > FRACUNIT/4 || mo->momx < -FRACUNIT/4 ||
             mo->momy > FRACUNIT/4 || mo->momy < -FRACUNIT/4) &&
            mo->floorz != mo->subsector->sector->floorheight)
        return;  // do not stop sliding if halfway off a step with some momentum

    // killough 11/98:
    // Stop voodoo dolls that have come to rest, despite any
    // moving corresponding player, except in old demos:

    if (mo->momx > -STOPSPEED && mo->momx < STOPSPEED &&
            mo->momy > -STOPSPEED && mo->momy < STOPSPEED &&
            (!player || !(player->cmd.forwardmove | player->cmd.sidemove) ||
             (player->mo != mo)))
    {
        // if in a walking frame, stop moving

        // killough 10/98:
        // Don't affect main player when voodoo dolls stop, except in old demos:

        //    if ( player&&(unsigned)((player->mo->state - states)- S_PLAY_RUN1) < 4)
        //      P_SetMobjState (player->mo, S_PLAY);
        if (player && (unsigned)(player->mo->state - states - S_PLAY_RUN1) < 4
                && (player->mo == mo))
            P_SetMobjState(player->mo, S_PLAY);

        mo->momx = mo->momy = 0;

        /* killough 10/98: kill any bobbing momentum too (except in voodoo dolls)
       * cph - DEMOSYNC - needs compatibility check?
       */
        if (player && player->mo == mo)
            player->momx = player->momy = 0;
    }
    else
    {
        /* phares 3/17/98
       *
       * Friction will have been adjusted by friction thinkers for
       * icy or muddy floors. Otherwise it was never touched and
       * remained set at ORIG_FRICTION
       *
       * killough 8/28/98: removed inefficient thinker algorithm,
       * instead using touching_sectorlist in P_GetFriction() to
       * determine friction (and thus only when it is needed).
       *
       * killough 10/98: changed to work with new bobbing method.
       * Reducing player momentum is no longer needed to reduce
       * bobbing, so ice works much better now.
       *
       * cph - DEMOSYNC - need old code for Boom demos?
       */



        fixed_t friction = ORIG_FRICTION;

        mo->momx = FixedMul(mo->momx, friction);
        mo->momy = FixedMul(mo->momy, friction);

        /* killough 10/98: Always decrease player bobbing by ORIG_FRICTION.
       * This prevents problems with bobbing on ice, where it was not being
       * reduced fast enough, leading to all sorts of kludges being developed.
       */


        if (player && player->mo == mo)     /* Not voodoo dolls */
        {
            player->momx = FixedMul(player->momx, ORIG_FRICTION);
            player->momy = FixedMul(player->momy, ORIG_FRICTION);
        }
    }
}


//
// P_ZMovement
//
// Attempt vertical movement.

void P_ZMovement (mobj_t* mo)
{

  // check for smooth step up

  if (mo->player &&
      mo->player->mo == mo &&  // killough 5/12/98: exclude voodoo dolls
      mo->z < mo->floorz)
    {
    mo->player->viewheight -= mo->floorz-mo->z;
    mo->player->deltaviewheight = (VIEWHEIGHT - mo->player->viewheight)>>3;
    }

  // adjust altitude

  mo->z += mo->momz;

  if ((mo->flags & MF_FLOAT) && mo->target)

    // float down towards target if too close

    if (!((mo->flags ^ MF_FLOAT) & (MF_FLOAT | MF_SKULLFLY | MF_INFLOAT)) &&
  mo->target)     /* killough 11/98: simplify */
      {
  fixed_t delta;
  if (P_AproxDistance(mo->x - mo->target->x, mo->y - mo->target->y) <
      D_abs(delta = mo->target->z + (mo->height>>1) - mo->z)*3)
    mo->z += delta < 0 ? -FLOATSPEED : FLOATSPEED;
      }

  // clip movement

  if (mo->z <= mo->floorz)
    {
    // hit the floor

    /* Note (id):
     *  somebody left this after the setting momz to 0,
     *  kinda useless there.
     * cph - This was the a bug in the linuxdoom-1.10 source which
     *  caused it not to sync Doom 2 v1.9 demos. Someone
     *  added the above comment and moved up the following code. So
     *  demos would desync in close lost soul fights.
     * cph - revised 2001/04/15 -
     * This was a bug in the Doom/Doom 2 source; the following code
     *  is meant to make charging lost souls bounce off of floors, but it 
     *  was incorrectly placed after momz was set to 0.
     *  However, this bug was fixed in Doom95, Final/Ultimate Doom, and 
     *  the v1.10 source release (which is one reason why it failed to sync 
     *  some Doom2 v1.9 demos)
     * I've added a comp_soul compatibility option to make this behavior 
     *  selectable for PrBoom v2.3+. For older demos, we do this here only 
     *  if we're in a compatibility level above Doom 2 v1.9 (in which case we
     *  mimic the bug and do it further down instead)
     */

    if (mo->flags & MF_SKULLFLY)
      mo->momz = -mo->momz; // the skull slammed into something

    if (mo->momz < 0)
      {
    if (mo->player && /* killough 5/12/98: exclude voodoo dolls */
        mo->player->mo == mo && mo->momz < -GRAVITY*8)
      {
        // Squat down.
        // Decrease viewheight for a moment
        // after hitting the ground (hard),
        // and utter appropriate sound.

        mo->player->deltaviewheight = mo->momz>>3;
        if (mo->health > 0) /* cph - prevent "oof" when dead */
    S_StartSound (mo, sfx_oof);
      }
  mo->momz = 0;
      }
    mo->z = mo->floorz;

    if ( (mo->flags & MF_MISSILE) && !(mo->flags & MF_NOCLIP) )
      {
      P_ExplodeMissile (mo);
      return;
      }
    }
  else // still above the floor                                     // phares
    if (!(mo->flags & MF_NOGRAVITY))
      {
  if (!mo->momz)
    mo->momz = -GRAVITY;
        mo->momz -= GRAVITY;
      }

  if (mo->z + mo->height > mo->ceilingz)
    {
    /* cph 2001/04/15 - 
     * Lost souls were meant to bounce off of ceilings;
     *  new comp_soul compatibility option added
     */
    if (mo->flags & MF_SKULLFLY)
      mo->momz = -mo->momz; // the skull slammed into something

    // hit the ceiling

    if (mo->momz > 0)
      mo->momz = 0;

    mo->z = mo->ceilingz - mo->height;

    if ( (mo->flags & MF_MISSILE) && !(mo->flags & MF_NOCLIP) )
      {
      P_ExplodeMissile (mo);
      return;
      }
    }
  }

//
// P_NightmareRespawn
//

void P_NightmareRespawn(mobj_t* mobj)
{
    fixed_t      x;
    fixed_t      y;
    fixed_t      z;
    subsector_t* ss;
    mobj_t*      mo;

    /* haleyjd: stupid nightmare respawning bug fix
   *
   * 08/09/00: compatibility added, time to ramble :)
   * This fixes the notorious nightmare respawning bug that causes monsters
   * that didn't spawn at level startup to respawn at the point (0,0)
   * regardless of that point's nature. SMMU and Eternity need this for
   * script-spawned things like Halif Swordsmythe, as well.
   *
   * cph - copied from eternity, except comp_respawnfix becomes comp_respawn
   *   and the logic is reversed (i.e. like the rest of comp_ it *disables*
   *   the fix)
   */

    //ZLB: Everything respawns at its death point.
    //The spawnpoint is removed from the mobj.

    x = mobj->x;
    y = mobj->y;

    if(!x && !y)
    {
        return;
    }

    // something is occupying its position?

    if (!P_CheckPosition (mobj, x, y) )
        return; // no respwan

    // spawn a teleport fog at old spot
    // because of removal of the body?

    mo = P_SpawnMobj (mobj->x,
                      mobj->y,
                      mobj->subsector->sector->floorheight,
                      MT_TFOG);

    // initiate teleport sound

    S_StartSound (mo, sfx_telept);

    // spawn a teleport fog at the new spot

    ss = R_PointInSubsector (x,y);

    mo = P_SpawnMobj (x, y, ss->sector->floorheight , MT_TFOG);

    S_StartSound (mo, sfx_telept);

    // spawn the new monster

    //mthing = &mobj->spawnpoint;
    if (mobj->info->flags & MF_SPAWNCEILING)
        z = ONCEILINGZ;
    else
        z = ONFLOORZ;

    // inherit attributes from deceased one

    mo = P_SpawnMobj (x,y,z, mobj->type);
    mo->angle = mobj->angle;

    /* killough 11/98: transfer friendliness from deceased */
    mo->flags = (mo->flags & ~MF_FRIEND) | (mobj->flags & MF_FRIEND);

    mo->reactiontime = 18;

    // remove the old monster,

    P_RemoveMobj (mobj);
}

//Thinker function for stuff that doesn't need to do anything
//interesting.
//Just cycles through the states. Allows sprite animation to work.
void P_MobjBrainlessThinker(mobj_t* mobj)
{
    // cycle through states,
    // calling action functions at transitions

    if (mobj->tics != -1)
    {
        mobj->tics--;

        // you can cycle through multiple states in a tic

        if (!mobj->tics)
            P_SetMobjState (mobj, mobj->state->nextstate);
    }
}



static think_t P_ThinkerFunctionForType(mobjtype_t type, mobj_t* mobj)
{
    //Full thinking ability.
    if(type < MT_MISC0)
        return P_MobjThinker;

    //Just state cycles.
    if(mobj->tics != -1)
        return P_MobjBrainlessThinker;

    //No thinking at all.
    return NULL;
}

//
// P_SpawnMobj
//
mobj_t* P_SpawnMobj(fixed_t x,fixed_t y,fixed_t z,mobjtype_t type)
  {
  mobj_t*     mobj;
  const state_t*    st;
  const mobjinfo_t* info;

  mobj = Z_Malloc (sizeof(*mobj), PU_LEVEL, NULL);
  memset (mobj, 0, sizeof (*mobj));
  info = &mobjinfo[type];
  mobj->type = type;
  mobj->info = info;
  mobj->x = x;
  mobj->y = y;
  mobj->radius = info->radius;
  mobj->height = info->height;                                      // phares
  mobj->flags  = info->flags;

    if (type == MT_PLAYER)         // Except in old demos, players
      mobj->flags |= MF_FRIEND;    // are always friends.

  mobj->health = info->spawnhealth;

  if (_g->gameskill != sk_nightmare)
    mobj->reactiontime = info->reactiontime;

  // do not set the state with P_SetMobjState,
  // because action routines can not be called yet

  st = &states[info->spawnstate];

  mobj->state  = st;
  mobj->tics   = st->tics;
  mobj->sprite = st->sprite;
  mobj->frame  = st->frame;
  mobj->touching_sectorlist = NULL; // NULL head of sector list // phares 3/13/98

  // set subsector and/or block links

  P_SetThingPosition (mobj);

  mobj->dropoffz =           /* killough 11/98: for tracking dropoffs */
  mobj->floorz   = mobj->subsector->sector->floorheight;
  mobj->ceilingz = mobj->subsector->sector->ceilingheight;

  mobj->z = z == ONFLOORZ ? mobj->floorz : z == ONCEILINGZ ?
    mobj->ceilingz - mobj->height : z;

  mobj->thinker.function = P_ThinkerFunctionForType(type, mobj);

  mobj->target = mobj->tracer = mobj->lastenemy = NULL;
  P_AddThinker (&mobj->thinker);
  if (!((mobj->flags ^ MF_COUNTKILL) & (MF_FRIEND | MF_COUNTKILL)))
    _g->totallive++;
  return mobj;
  }

//
// P_RemoveMobj
//

void P_RemoveMobj (mobj_t* mobj)
{
  P_UnsetThingPosition (mobj);

  // Delete all nodes on the current sector_list               phares 3/16/98

  if (_g->sector_list)
    {
    P_DelSeclist(_g->sector_list);
    _g->sector_list = NULL;
    }

  // stop any playing sound

  S_StopSound (mobj);

  // killough 11/98:
  //
  // Remove any references to other mobjs.
  //
  // Older demos might depend on the fields being left alone, however,
  // if multiple thinkers reference each other indirectly before the
  // end of the current tic.
  // CPhipps - only leave dead references in old demos; I hope lxdoom_1 level
  // demos are rare and don't rely on this. I hope.

  if (!_g->demoplayback)
  {
    P_SetTarget(&mobj->target,    NULL);
    P_SetTarget(&mobj->tracer,    NULL);
    P_SetTarget(&mobj->lastenemy, NULL);
  }
  // free block

  P_RemoveThinker (&mobj->thinker);
}


/*
 * P_FindDoomedNum
 *
 * Finds a mobj type with a matching doomednum
 *
 * killough 8/24/98: rewrote to use hashing
 */

static PUREFUNC int P_FindDoomedNum(unsigned int type)
{
    // find which type to spawn
    for (int i=0 ; i< NUMMOBJTYPES ; i++)
    {
        if (type == mobjinfo[i].doomednum)
            return i;
    }

    return NUMMOBJTYPES;
}

//
// P_RespawnSpecials
//

void P_RespawnSpecials (void)
  {
  }

//
// P_SpawnPlayer
// Called when a player is spawned on the level.
// Most of the player structure stays unchanged
//  between levels.
//

void P_SpawnPlayer (int n, const mapthing_t* mthing)
  {
  player_t* p;
  fixed_t   x;
  fixed_t   y;
  fixed_t   z;
  mobj_t*   mobj;

  // not playing?

  if (!_g->playeringame)
    return;

  p = &_g->player;

  if (p->playerstate == PST_REBORN)
    G_PlayerReborn (mthing->type-1);

  /* cph 2001/08/14 - use the options field of memorised player starts to
   * indicate whether the start really exists in the level.
   */
  if (!mthing->options)
    I_Error("P_SpawnPlayer: attempt to spawn player at unavailable start point");
  
  x    = mthing->x << FRACBITS;
  y    = mthing->y << FRACBITS;
  z    = ONFLOORZ;
  mobj = P_SpawnMobj (x,y,z, MT_PLAYER);

  // set color translations for player sprites

  mobj->angle      = ANG45 * (mthing->angle/45);
  mobj->player     = p;
  mobj->health     = p->health;

  p->mo            = mobj;
  p->playerstate   = PST_LIVE;
  p->refire        = 0;
  p->message       = NULL;
  p->damagecount   = 0;
  p->bonuscount    = 0;
  p->extralight    = 0;
  p->fixedcolormap = 0;
  p->viewheight    = VIEWHEIGHT;

  p->momx = p->momy = 0;   // killough 10/98: initialize bobbing to 0.

  // setup gun psprite

  P_SetupPsprites (p);


  if (mthing->type-1 == 0)
    {
    ST_Start(); // wake up the status bar
    HU_Start(); // wake up the heads up text
    }
  }

/*
 * P_IsDoomnumAllowed()
 * Based on code taken from P_LoadThings() in src/p_setup.c  Return TRUE
 * if the thing in question is expected to be available in the gamemode used.
 */

boolean P_IsDoomnumAllowed(int doomnum)
{
  // Do not spawn cool, new monsters if !commercial
  if (_g->gamemode != commercial)
    switch(doomnum)
      {
      case 64:  // Archvile
      case 65:  // Former Human Commando
      case 66:  // Revenant
      case 67:  // Mancubus
      case 68:  // Arachnotron
      case 69:  // Hell Knight
      case 71:  // Pain Elemental
      case 84:  // Wolf SS
      case 88:  // Boss Brain
      case 89:  // Boss Shooter
        return false;
      }

  return true;
}

//
// P_SpawnMapThing
// The fields of the mapthing should
// already be in host byte order.
//

void P_SpawnMapThing (const mapthing_t* mthing)
  {
  int     i;
  //int     bit;
  mobj_t* mobj;
  fixed_t x;
  fixed_t y;
  fixed_t z;
  int options = mthing->options; /* cph 2001/07/07 - make writable copy */

  // killough 2/26/98: Ignore type-0 things as NOPs
  // phares 5/14/98: Ignore Player 5-8 starts (for now)

  switch(mthing->type)
    {
  case 0:
  case DEN_PLAYER5:
  case DEN_PLAYER6:
  case DEN_PLAYER7:
  case DEN_PLAYER8:
    return;
    }

  // killough 11/98: clear flags unused by Doom
  //
  // We clear the flags unused in Doom if we see flag mask 256 set, since
  // it is reserved to be 0 under the new scheme. A 1 in this reserved bit
  // indicates it's a Doom wad made by a Doom editor which puts 1's in
  // bits that weren't used in Doom (such as HellMaker wads). So we should
  // then simply ignore all upper bits.

  if (options & MTF_RESERVED)
  {
      lprintf(LO_WARN, "P_SpawnMapThing: correcting bad flags (%u) (thing type %d)\n",
        options, mthing->type);
    options &= MTF_EASY|MTF_NORMAL|MTF_HARD|MTF_AMBUSH|MTF_NOTSINGLE;
  }

  // check for players specially

  //Only care about start spot for player 1.
  if(mthing->type == 1)
  {
      _g->playerstarts[0] = *mthing;
      _g->playerstarts[0].options = 1;
      P_SpawnPlayer (0, &_g->playerstarts[0]);
      return;
  }

  // check for apropriate skill level

  /* jff "not single" thing flag */
  if (options & MTF_NOTSINGLE)
    return;

  // killough 11/98: simplify
  if (_g->gameskill == sk_baby || _g->gameskill == sk_easy ?
      !(options & MTF_EASY) :
      _g->gameskill == sk_hard || _g->gameskill == sk_nightmare ?
      !(options & MTF_HARD) : !(options & MTF_NORMAL))
    return;

  // find which type to spawn

  // killough 8/23/98: use table for faster lookup
  i = P_FindDoomedNum(mthing->type);

  // phares 5/16/98:
  // Do not abort because of an unknown thing. Ignore it, but post a
  // warning message for the player.

  if (i == NUMMOBJTYPES)
    {
        return;
    }

  x = mthing->x << FRACBITS;
  y = mthing->y << FRACBITS;

  if (mobjinfo[i].flags & MF_SPAWNCEILING)
    z = ONCEILINGZ;
  else
    z = ONFLOORZ;

  mobj = P_SpawnMobj (x,y,z, i);
  //mobj->spawnpoint = *mthing;

  if (mobj->tics > 0)
    mobj->tics = 1 + (P_Random () % mobj->tics);

  if (!(mobj->flags & MF_FRIEND) &&
      options & MTF_FRIEND)
    {
      mobj->flags |= MF_FRIEND;            // killough 10/98:
    }

  /* killough 7/20/98: exclude friends */
  if (!((mobj->flags ^ MF_COUNTKILL) & (MF_FRIEND | MF_COUNTKILL)))
    _g->totalkills++;

  if (mobj->flags & MF_COUNTITEM)
    _g->totalitems++;

  mobj->angle = ANG45 * (mthing->angle/45);
  if (options & MTF_AMBUSH)
    mobj->flags |= MF_AMBUSH;
  }


//
// GAME SPAWN FUNCTIONS
//

//
// P_SpawnPuff
//
void P_SpawnPuff(fixed_t x,fixed_t y,fixed_t z)
  {
  mobj_t* th;
  // killough 5/5/98: remove dependence on order of evaluation:
  int t = P_Random();
  z += (t - P_Random())<<10;

  th = P_SpawnMobj (x,y,z, MT_PUFF);
  th->momz = FRACUNIT;
  th->tics -= P_Random()&3;

  if (th->tics < 1)
    th->tics = 1;

  // don't make punches spark on the wall

  if (_g->attackrange == MELEERANGE)
    P_SetMobjState (th, S_PUFF3);
  }


//
// P_SpawnBlood
//
void P_SpawnBlood(fixed_t x,fixed_t y,fixed_t z,int damage)
  {
  mobj_t* th;
  // killough 5/5/98: remove dependence on order of evaluation:
  int t = P_Random();
  z += (t - P_Random())<<10;
  th = P_SpawnMobj(x,y,z, MT_BLOOD);
  th->momz = FRACUNIT*2;
  th->tics -= P_Random()&3;

  if (th->tics < 1)
    th->tics = 1;

  if (damage <= 12 && damage >= 9)
    P_SetMobjState (th,S_BLOOD2);
  else if (damage < 9)
    P_SetMobjState (th,S_BLOOD3);
  }


//
// P_CheckMissileSpawn
// Moves the missile forward a bit
//  and possibly explodes it right there.
//

void P_CheckMissileSpawn (mobj_t* th)
  {
  th->tics -= P_Random()&3;
  if (th->tics < 1)
    th->tics = 1;

  // move a little forward so an angle can
  // be computed if it immediately explodes

  th->x += (th->momx>>1);
  th->y += (th->momy>>1);
  th->z += (th->momz>>1);

  // killough 8/12/98: for non-missile objects (e.g. grenades)
  if (!(th->flags & MF_MISSILE))
    return;

  // killough 3/15/98: no dropoff (really = don't care for missiles)

  if (!P_TryMove (th, th->x, th->y, false))
    P_ExplodeMissile (th);
  }


//
// P_SpawnMissile
//

mobj_t* P_SpawnMissile(mobj_t* source,mobj_t* dest,mobjtype_t type)
  {
  mobj_t* th;
  angle_t an;
  int     dist;

  th = P_SpawnMobj (source->x,source->y,source->z + 4*8*FRACUNIT,type);

  if (th->info->seesound)
    S_StartSound (th, th->info->seesound);

  P_SetTarget(&th->target, source);    // where it came from
  an = R_PointToAngle2 (source->x, source->y, dest->x, dest->y);

  // fuzzy player

  if (dest->flags & MF_SHADOW)
    {  // killough 5/5/98: remove dependence on order of evaluation:
    int t = P_Random();
    an += (t - P_Random())<<20;
    }

  th->angle = an;
  an >>= ANGLETOFINESHIFT;
  th->momx = FixedMul (th->info->speed, finecosine[an]);
  th->momy = FixedMul (th->info->speed, finesine[an]);

  dist = P_AproxDistance (dest->x - source->x, dest->y - source->y);
  dist = dist / th->info->speed;

  if (dist < 1)
    dist = 1;

  th->momz = (dest->z - source->z) / dist;
  P_CheckMissileSpawn (th);

  return th;
  }


//
// P_SpawnPlayerMissile
// Tries to aim at a nearby monster
//

void P_SpawnPlayerMissile(mobj_t* source,mobjtype_t type)
{
  mobj_t *th;
  fixed_t x, y, z, slope = 0;

  // see which target is to be aimed at

  angle_t an = source->angle;

  // killough 7/19/98: autoaiming was not in original beta
    {
      // killough 8/2/98: prefer autoaiming at enemies
      unsigned int mask = MF_FRIEND;

      do
  {
    slope = P_AimLineAttack(source, an, 16*64*FRACUNIT, mask);
    if (!_g->linetarget)
      slope = P_AimLineAttack(source, an += 1<<26, 16*64*FRACUNIT, mask);
    if (!_g->linetarget)
      slope = P_AimLineAttack(source, an -= 2<<26, 16*64*FRACUNIT, mask);
    if (!_g->linetarget)
      an = source->angle, slope = 0;
  }
      while (mask && (mask=0, !_g->linetarget));  // killough 8/2/98
    }

  x = source->x;
  y = source->y;
  z = source->z + 4*8*FRACUNIT;

  th = P_SpawnMobj (x,y,z, type);

  if (th->info->seesound)
    S_StartSound (th, th->info->seesound);

  P_SetTarget(&th->target, source);
  th->angle = an;
  th->momx = FixedMul(th->info->speed,finecosine[an>>ANGLETOFINESHIFT]);
  th->momy = FixedMul(th->info->speed,finesine[an>>ANGLETOFINESHIFT]);
  th->momz = FixedMul(th->info->speed,slope);

  P_CheckMissileSpawn(th);
  }
