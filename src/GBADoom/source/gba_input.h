/*

	Header file for libgba input functions

	Copyright 2003-2004 by Dave Murphy.

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Library General Public
	License as published by the Free Software Foundation; either
	version 2 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Library General Public License for more details.

	You should have received a copy of the GNU Library General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
	USA.

	Please report all bugs and problems through the bug tracker at
	"http://sourceforge.net/tracker/?group_id=114505&atid=668551".


*/

/*! \file gba_input.h
    \brief gba inout support functions.

*/

//---------------------------------------------------------------------------------
#ifndef _gba_input_h_
#define _gba_input_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------
#include "gba_base.h"

/*! \def REG_KEYINPUT

    \brief Keypad status register.

*/
#define REG_KEYINPUT	*(vu16*)(REG_BASE + 0x130)  // Key Input
/*! \def REG_KEYCNT

    \brief Keypad interrupt control register.

*/
#define REG_KEYCNT		*(vu16*)(REG_BASE + 0x132)  // Key Control
/*! \enum KEYPAD_BITS

	\brief bit values for keypad buttons
*/
typedef enum KEYPAD_BITS {
	KEY_A		=	(1<<0),	/*!< keypad A button */
	KEY_B		=	(1<<1),	/*!< keypad B button */
	KEY_SELECT	=	(1<<2),	/*!< keypad SELECT button */
	KEY_START	=	(1<<3),	/*!< keypad START button */
	KEY_RIGHT	=	(1<<4),	/*!< dpad RIGHT */
	KEY_LEFT	=	(1<<5),	/*!< dpad LEFT */
	KEY_UP		=	(1<<6),	/*!< dpad UP */
	KEY_DOWN	=	(1<<7),	/*!< dpad DOWN */
	KEY_R		=	(1<<8),	/*!< Right shoulder button */
	KEY_L		=	(1<<9),	/*!< Left shoulder button */

	KEYIRQ_ENABLE	=	(1<<14),	/*!< Enable keypad interrupt */
	KEYIRQ_OR		=	(0<<15),	/*!< interrupt logical OR mode */
	KEYIRQ_AND		=	(1<<15),	/*!< interrupt logical AND mode */
	DPAD 		=	(KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT) /*!< mask all dpad buttons */
} KEYPAD_BITS;


/*! \fn scanKeys()
	\brief obtain the current keypad states.

	Call this function once per main loop in order to use the keypad functions.
*/
void scanKeys(void);
/*! \fn u16 keysDown()
	\brief obtain the current keypad pressed state.

	Returns the keys which have been pressed since the last call to KeysDown(), the keys are reset on this call.
	Keys which are pressed will not be reported again until they are released.
*/
u16	keysDown();
/*! \fn u16 keysDownRepeat()
	\brief obtain the current keypad pressed state with repeat.

*/
u16	keysDownRepeat();
/*! \fn u16 keysUp()
	\brief obtain the current keypad released.

	Returns the keys which have been pressed since the last call to KeysDown(), the keys are reset on this call.
	Keys which are pressed will not be reported again until they have been held for the times specified using SetRepeat().
*/
u16 keysUp();
/*! \fn u16 keysHeld()
	\brief obtain the current keypad held state.

	Returns the keys which have been pressed since the last call to KeysUp(), the keys are reset on this call.
	Keys which are released will not be reported again until they are pressed.
*/
u16 keysHeld();


/*! \fn setRepeat(int SetDelay, int SetRepeat)
	\brief Set the repeat parameters for KeyDownRepeat.
	\param SetDelay The count before the key starts to repeat
	\param SetRepeat The count at which the key will repeat

	The counts are updated on each call to ScanKeys(), the rates are dependent on how often that function is called.
*/
void setRepeat( int SetDelay, int SetRepeat);

//---------------------------------------------------------------------------------
#ifdef __cplusplus
	}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif // _gba_input_h_
//---------------------------------------------------------------------------------
