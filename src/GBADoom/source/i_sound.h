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
 *      System interface, sound.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __I_SOUND__
#define __I_SOUND__

#include "sounds.h"
#include "doomtype.h"

// Init at program start...
void I_InitSound(void);

// ... shut down and relase at program termination.
void I_ShutdownSound(void);

//
//  SFX I/O
//


// Starts a sound in a particular sound channel.
int I_StartSound(int id, int channel, int vol, int sep);


//
//  MUSIC I/O
//
void I_InitMusic(void);

// Volume.
void I_SetMusicVolume(int volume);

// PAUSE game handling.
void I_PauseSong(int handle);
void I_ResumeSong(int handle);

// Called by anything that wishes to start music.
//  plays a song, and when the song is done,
//  starts playing it again in an endless loop.
// Horrible thing to do, considering.
void I_PlaySong(int handle, int looping);

// Stops a song over 3 seconds.
void I_StopSong(int handle);

// CPhipps - put these in config file
extern const int snd_samplerate;


typedef struct
{
    const char* data;
    const char* enddata;
    int vol;

} channel_info_t;

#define MUSIC_BUFFER_SAMPLES 2048
#define MAX_CHANNELS    8


#endif
