/****************************************************************************
 *                                                          __              *
 *                ____ ___  ____ __  ______ ___  ____  ____/ /              *
 *               / __ `__ \/ __ `/ |/ / __ `__ \/ __ \/ __  /               *
 *              / / / / / / /_/ />  </ / / / / / /_/ / /_/ /                *
 *             /_/ /_/ /_/\__,_/_/|_/_/ /_/ /_/\____/\__,_/                 *
 *                                                                          *
 *                             GBA Definitions                              *
 *                                                                          *
 *         Copyright (c) 2008, Mukunda Johnson (mukunda@maxmod.org)         *
 *                                                                          *
 * Permission to use, copy, modify, and/or distribute this software for any *
 * purpose with or without fee is hereby granted, provided that the above   *
 * copyright notice and this permission notice appear in all copies.        *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES *
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF         *
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  *
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   *
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN    *
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  *
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.           *
 ****************************************************************************/

#ifndef MAXMOD_H
#define MAXMOD_H

#include "mm_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// precalculated mix buffer lengths (in bytes)
#define MM_MIXLEN_8KHZ		544		// (8121 hz)
#define MM_MIXLEN_10KHZ		704		// (10512 hz)	
#define MM_MIXLEN_13KHZ		896		// (13379 hz)	
#define MM_MIXLEN_16KHZ		1056	// (15768 hz)
#define MM_MIXLEN_18KHZ 	1216	// (18157 hz)
#define MM_MIXLEN_21KHZ 	1408	// (21024 hz)
#define MM_MIXLEN_27KHZ		1792	// (26758 hz)
#define MM_MIXLEN_31KHZ		2112	// (31536 hz)

// measurements of channel types (bytes)
#define MM_SIZEOF_MODCH		40
#define MM_SIZEOF_ACTCH		28
#define MM_SIZEOF_MIXCH		24

/****************************************************************************
 * mmInitDefault( mm_addr soundbank, mm_word number_of_channels )
 *
 * Initialize Maxmod with default settings.
 ****************************************************************************/
 
void mmInitDefault( mm_addr soundbank, mm_word number_of_channels );

/****************************************************************************
 * mmInit( mm_gba_system* setup )
 *
 * Initialize system. Call once at startup.
 ****************************************************************************/
 
void mmInit( mm_gba_system* setup );

/****************************************************************************
 * mmVBlank()
 *
 * Must be linked to the VBlank IRQ.
 ****************************************************************************/
 
void mmVBlank( void );

/****************************************************************************
 * mmSetVBlankHandler( void* function )
 *
 * Install user vblank handler
 *
 * function : Pointer to your VBlank handler.
 ****************************************************************************/

void mmSetVBlankHandler( void* function );

/****************************************************************************
 * mmSetEventHandler( mm_callback handler )
 *
 * Install handler to receive song events.
 ****************************************************************************/

void mmSetEventHandler( mm_callback handler );

/****************************************************************************
 * mmFrame()
 *
 * Work routine. _Must_ be called every frame.
 ****************************************************************************/
 
void mmFrame( void ) __attribute((long_call));



/****************************************************************************
 *
 * Module Playback
 *
 ****************************************************************************/



/****************************************************************************
 * mmStart( mm_word id, mm_pmode mode )
 *
 * Start module playback.
 *
 * id : ID of module to play.
 * mode : Playback mode (loop/once)
 ****************************************************************************/

void mmStart( mm_word id, mm_pmode mode );

/****************************************************************************
 * mmPause()
 *
 * Pause module playback, resume with mmResume().
 ****************************************************************************/
 
void mmPause( void );

/****************************************************************************
 * mmResume()
 *
 * Resume module playback, pause with mmPause().
 ****************************************************************************/
 
void mmResume( void );

/****************************************************************************
 * mmStop()
 *
 * Stop module playback. start again with mmStart().
 ****************************************************************************/

void mmStop( void );

/****************************************************************************
 * mmGetPosition()
 *
 * Get playback position.
 ****************************************************************************/

mm_word mmGetPosition( void );

/****************************************************************************
 * mmPosition()
 *
 * Set playback position.
 *
 * position: New position in the module sequence.
 ****************************************************************************/

void mmPosition( mm_word position );

/****************************************************************************
 * mmSetPosition()
 *
 * Set playback position (alias for mmPosition()).
 *
 * position: New position in the module sequence.
 ****************************************************************************/

inline void mmSetPosition( mm_word position )
{
    mmPosition( position );
}

/****************************************************************************
 * mmActive()
 *
 * Returns nonzero if module is playing.
 ****************************************************************************/

int  mmActive( void );

/****************************************************************************
 * mmJingle( mm_word module_ID )
 *
 * Play module as jingle. Jingles are limited to 4 channels only.
 *
 * module_ID : ID of moudle (defined in soundbank header)
 ****************************************************************************/
 
void mmJingle( mm_word module_ID );

/****************************************************************************
 * mmActiveSub()
 *
 * Returns nonzero if a jingle is actively playing.
 ****************************************************************************/

int  mmActiveSub( void );

/****************************************************************************
 * mmSetModuleVolume( mm_word volume )
 * mmSetJingleVolume( mm_word volume )
 *
 * Set volume scaler for music/jingles.
 *
 * volume : 0->1024 = silent..normal
 ****************************************************************************/

void mmSetModuleVolume( mm_word volume );
void mmSetJingleVolume( mm_word volume );

/*****************************************************************
 * mmSetModuleTempo( mm_word tempo )
 *
 * Set tempo of playback.
 *
 * tempo : Fixed point (Q10) value representing tempo.
 *         Range = 0x200 -> 0x800 = 0.5 -> 2.0
 *****************************************************************/

void mmSetModuleTempo( mm_word tempo );

/*****************************************************************
 * mmSetModulePitch( mm_word pitch )
 *
 * Set pitch of playback.
 *
 * pitch : Range = 0x200 -> 0x800 = 0.5 -> 2.0
 *****************************************************************/
 
void mmSetModulePitch( mm_word pitch );

/****************************************************************************
 * mmPlayModule( mm_word address, mm_word mode, mm_word layer )
 *
 * Play direct MAS file
 ****************************************************************************/
 
void mmPlayModule( mm_word address, mm_word mode, mm_word layer );



/****************************************************************************
 *
 * Sound Effects
 *
 ****************************************************************************/



/****************************************************************************
 * mmEffect( mm_word sample_ID )
 *
 * Play a sound effect at its default frequency with full volume and
 * centered panning.
 *
 * sample_ID : Sound effect ID. (defined in soundbank header)
 ****************************************************************************/

mm_sfxhand mmEffect( mm_word sample_ID );

/****************************************************************************
 * mmEffectEx( mm_sound_effect* sound )
 *
 * Play a sound effect with all parameters.
 *
 * sound : Sound effect attributes.
 ****************************************************************************/

mm_sfxhand mmEffectEx( mm_sound_effect* sound );

/****************************************************************************
 * mmEffectVolume( mm_sfxhand handle, mm_word volume )
 *
 * Set the volume of a sound effect.
 *
 * handle : Sound effect handle.
 * volume : 0->65535
 ****************************************************************************/
 
void mmEffectVolume( mm_sfxhand handle, mm_word volume );

/****************************************************************************
 * mmEffectPanning( mm_sfxhand handle, mm_word panning )
 *
 * Set the panning of a sound effect.
 *
 * handle : Sound effect handle.
 * panning : 0->255 = left..right
 ****************************************************************************/
 
void mmEffectPanning( mm_sfxhand handle, mm_byte panning );

/****************************************************************************
 * mmEffectRate( mm_sfxhand handle, mm_word rate )
 *
 * Set the playback rate of an effect.
 *
 * handle : Sound effect handle.
 * rate: 6.10 factor
 ****************************************************************************/
 
void mmEffectRate( mm_sfxhand handle, mm_word rate );

/****************************************************************************
 * mmEffectScaleRate( mm_sfxhand handle, mm_word factor )
 *
 * Scale the playback rate of an effect.
 *
 * handle : Sound effect handle.
 * factor : 6.10 fixed point factor.
 ****************************************************************************/
 
void mmEffectScaleRate( mm_sfxhand handle, mm_word factor );

/****************************************************************************
 * mmEffectActive( mm_sfxhand handle )
 *
 * Indicates if a sound effect is active or not.
 *
 * handle : Sound effect handle.
 ****************************************************************************/

mm_bool mmEffectActive( mm_sfxhand handle );

/****************************************************************************
 * mmEffectCancel( mm_sfxhand handle )
 *
 * Stop sound effect.
 *
 * handle : Sound effect handle.
 ****************************************************************************/

void mmEffectCancel( mm_sfxhand handle );

/****************************************************************************
 * mmEffectRelease( mm_sfxhand handle )
 *
 * Release sound effect (invalidate handle and allow interruption)
 *
 * handle : Sound effect handle.
 ****************************************************************************/
 
void mmEffectRelease( mm_sfxhand handle );

/****************************************************************************
 * mmSetEffectsVolume( mm_word volume )
 *
 * Set master volume scale for effect playback.
 *
 * volume : 0->1024 representing 0%->100% volume
 ****************************************************************************/

void mmSetEffectsVolume( mm_word volume );

/****************************************************************************
 * mmEffectCancelAll()
 *
 * Stop all sound effects
 ****************************************************************************/
 
void mmEffectCancelAll();



#ifdef __cplusplus
}
#endif

/****************************************************************************
 * Playback events
 ****************************************************************************/

//---------------------------------------------------------------------------
// This happens when Maxmod reads a SFx (or mod/xm EFx) effect from a module
// It will store 'x' in param_b
//---------------------------------------------------------------------------
#define MMCB_SONGMESSAGE	0x2A
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// A module has finished playing
// param == 0 if main module, ==1 otherwise
//---------------------------------------------------------------------------
#define MMCB_SONGFINISHED	0x2B
//---------------------------------------------------------------------------

/****************************************************************************
 * etc...
 ****************************************************************************/

extern mm_byte	mp_mix_seg;			// current mixing segment
extern mm_word	mp_writepos;		// mixer's write position

#endif