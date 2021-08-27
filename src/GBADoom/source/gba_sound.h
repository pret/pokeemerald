/*

	Header file for libgba bios sound functions

	Copyright (C) 2003-2005 by Dave Murphy.

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

//---------------------------------------------------------------------------------
#ifndef	_gba_sound_h_
#define	_gba_sound_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

#include "gba_base.h"

typedef struct {
	u16 type;
	u16 stat;
	u32 freq;
	u32 loop;
	u32 size;
	s8 data[1];
} ALIGN(4) WaveData;

typedef struct {
	u8 Status;
	u8 reserved1;
	u8 RightVol;
	u8 LeftVol;
	u8 Attack;
	u8 Decay;
	u8 Sustain;
	u8 Release;
	u8 reserved2[24];
	u32 fr;
	WaveData *wp;
	u32 reserved3[6];
} ALIGN(4) SoundChannel;

#define PCM_DMA_BUF 1584
#define MAX_DIRECTSOUND_CHANNELS 12

typedef struct {
	u32 ident;
	vu8 DmaCount;
	u8 reverb;
	u8 maxchn;
	u8 masvol;
	u8 freq;
	u8 mode;
	u8 r2[6];
	u32 r3[16];
	SoundChannel vchn[MAX_DIRECTSOUND_CHANNELS];
	s8 pcmbuf[PCM_DMA_BUF*2];
} ALIGN(4) SoundArea;

/*---------------------------------------------------------------------------------
	Control Registers
---------------------------------------------------------------------------------*/

#define SND1_R_ENABLE	(1<<8)		// Enable left & right speakers for each sound channel
#define SND1_L_ENABLE	(1<<12)
#define SND2_R_ENABLE	(1<<9)
#define SND2_L_ENABLE	(1<<13)
#define SND3_R_ENABLE	(1<<10)
#define SND3_L_ENABLE	(1<<14)
#define SND4_R_ENABLE	(1<<11)
#define SND4_L_ENABLE	(1<<15)

#define SNDA_VOL_50     (0<<2)
#define SNDA_VOL_100    (1<<2)
#define SNDB_VOL_50     (0<<3)
#define SNDB_VOL_100    (1<<3)
#define SNDA_R_ENABLE   (1<<8)
#define SNDA_L_ENABLE   (1<<9)
#define SNDA_RESET_FIFO (1<<11)
#define SNDB_R_ENABLE   (1<<12)
#define SNDB_L_ENABLE   (1<<13)
#define SNDB_RESET_FIFO (1<<15)


#define	REG_SOUNDCNT_L	(*((u16 volatile *) (REG_BASE + 0x080)))
#define	REG_SOUNDCNT_H	(*((u16 volatile *) (REG_BASE + 0x082)))
#define	REG_SOUNDCNT_X	(*((u16 volatile *) (REG_BASE + 0x084)))


#define	REG_SOUND1CNT_L	(*((u16 volatile *) (REG_BASE + 0x060)))
#define	REG_SOUND1CNT_H	(*((u16 volatile *) (REG_BASE + 0x062)))
#define	REG_SOUND1CNT_X	(*((u16 volatile *) (REG_BASE + 0x064)))

#define	REG_SOUND2CNT_L	(*((u16 volatile *) (REG_BASE + 0x068)))
#define	REG_SOUND2CNT_H	(*((u16 volatile *) (REG_BASE + 0x06C)))

#define	REG_SOUND3CNT_L	(*((u16 volatile *) (REG_BASE + 0x070)))
#define	REG_SOUND3CNT_H	(*((u16 volatile *) (REG_BASE + 0x072)))
#define	REG_SOUND3CNT_X	(*((u16 volatile *) (REG_BASE + 0x074)))

#define	REG_SOUND4CNT_L	(*((u16 volatile *) (REG_BASE + 0x078)))
#define	REG_SOUND4CNT_H	(*((u16 volatile *) (REG_BASE + 0x07C)))

#define	REG_SOUNDBIAS	(*((u16 volatile *) (REG_BASE + 0x088)))

#define	REG_FIFO_A		(*((u32 volatile *) (REG_BASE + 0x0A0)))
#define	REG_FIFO_B		(*((u32 volatile *) (REG_BASE + 0x0A4)))

#define	WAVE_RAM	((u16 volatile *)	(REG_BASE + 0x090))

#define	SOUND3_STEP32		(0<<5)	// Use two banks of 32 steps each
#define SOUND3_STEP64		(1<<5)	// Use one bank of 64 steps
#define SOUND3_SETBANK(n)	(n<<6)	// Bank to play 0 or 1 (non set bank is written to)
#define SOUND3_PLAY			(1<<7)	// Output sound
#define SOUND3_STOP			(0<<7)	// Stop sound output

//---------------------------------------------------------------------------------
// pin8 compatible sound macros 
//---------------------------------------------------------------------------------

/*---------------------------------------------------------------------------------
	DMG Sound Control (0x04000080)
fedcba9876543210
|||||||| ||| |||
|||||||| ||| +++- DMG left volume
|||||||| +++----- DMG right volume
|||||||+--------- Enable sqr1 on left
||||||+---------- Enable sqr2 on left
|||||+----------- Enable triangle on left
||||+------------ Enable noise on left
|||+------------- Enable sqr1 on right
||+-------------- Enable sqr2 on right
|+--------------- Enable triangle on right
+---------------- 
---------------------------------------------------------------------------------*/
#define DMGSNDCTRL         (*(volatile u16 *)0x04000080)
#define DMGSNDCTRL_LVOL(x) (x)
#define DMGSNDCTRL_RVOL(x) ((x) << 4)
#define DMGSNDCTRL_LSQR1   0x0100
#define DMGSNDCTRL_LSQR2   0x0200
#define DMGSNDCTRL_LTRI    0x0400
#define DMGSNDCTRL_LNOISE  0x0800
#define DMGSNDCTRL_RSQR1   0x1000
#define DMGSNDCTRL_RSQR2   0x2000
#define DMGSNDCTRL_RTRI    0x4000
#define DMGSNDCTRL_RNOISE  0x8000

/*---------------------------------------------------------------------------------
	Direct Sound Control (0x04000082)
-----------------------------------------------------------------------------------
fedcba9876543210
||||||||    ||||
||||||||    ||++- DMG sound output volume
||||||||    ||    (00: 25%; 01: 50%; 10: 100%)
||||||||    |+--- DSound A output volume (0: 50%; 1: 100%)
||||||||    +---- DSound B output volume (0: 50%; 1: 100%)
|||||||+--------- Enable DSound A on right
||||||+---------- Enable DSound A on left
|||||+----------- DSound A sample timer (0 or 1)
||||+------------ DSound A FIFO reset
|||+------------- Enable DSound B on right
||+-------------- Enable DSound B on left
|+--------------- DSound B sample timer (0 or 1)
+---------------- DSound B FIFO reset
---------------------------------------------------------------------------------*/
#define DSOUNDCTRL           (*(volatile u16 *)0x04000082)
#define DSOUNDCTRL_DMG25     0x0000
#define DSOUNDCTRL_DMG50     0x0001
#define DSOUNDCTRL_DMG100    0x0002
#define DSOUNDCTRL_A50       0x0000
#define DSOUNDCTRL_A100      0x0004
#define DSOUNDCTRL_B50       0x0000
#define DSOUNDCTRL_B100      0x0008
#define DSOUNDCTRL_AR        0x0100
#define DSOUNDCTRL_AL        0x0200
#define DSOUNDCTRL_ATIMER(x) ((x) << 10)
#define DSOUNDCTRL_ARESET    0x0800
#define DSOUNDCTRL_BR        0x1000
#define DSOUNDCTRL_BL        0x2000
#define DSOUNDCTRL_BTIMER(x) ((x) << 14)
#define DSOUNDCTRL_BRESET    0x8000

/*---------------------------------------------------------------------------------
 Sound Status (0x04000084)
-----------------------------------------------------------------------------------
Note that unlike NES's $4014, bits 0 to 3 of this register are
read-only.  They do not enable sound.

fedcba9876543210
        |   ||||
        |   |||+- Square 1 playing
        |   ||+-- Square 2 playing
        |   |+--- Triangle playing
        |   +---- Noise playing
        +-------- 0: save 10% battery power by turning off ALL sound;
                  1: play sound
---------------------------------------------------------------------------------*/
#define SNDSTAT        (*(volatile u16*)0x04000084)
#define SNDSTAT_SQR1   0x0001
#define SNDSTAT_SQR2   0x0002
#define SNDSTAT_TRI    0x0004
#define SNDSTAT_NOISE  0x0008
#define SNDSTAT_ENABLE 0x0080

/*---------------------------------------------------------------------------------
	Sound Bias: will not be documented.
-----------------------------------------------------------------------------------
fedcba9876543210
||    ||||||||||
||    ++++++++++- PWM bias
++--------------- Amplitude resolution
                  00: 9-bit at 32768 Hz
                  01: 8-bit at 65536 Hz (most common)
                  10: 7-bit at 131072 Hz
                  11: 6-bit at 262144 Hz

Do NOT use SNDBIAS directly.  To set the resolution, use
  SETSNDRES(1);
---------------------------------------------------------------------------------*/
#define SNDBIAS      (*(volatile u16 *)0x04000088)
#define SETSNDRES(x) SNDBIAS = (SNDBIAS & 0x3fff) | (x << 14)

#define DSOUND_FIFOA (*(volatile u32 *)0x040000a0)
#define DSOUND_FIFOB (*(volatile u32 *)0x040000a4)


/*---------------------------------------------------------------------------------
 Square 1 Sweep Register
---------------------------------------------------------------------------------

fedcba9876543210
         |||||||
         ||||+++- Sweep shifts (1 fastest; 7 slowest)
         |||+---- 0: Sweep up; 1: Sweep down

Write 0x0040 into this register to disable sweep.
---------------------------------------------------------------------------------*/
#define SQR1SWEEP   (*(volatile u16 *)0x04000060)
#define SQR1SWEEP_OFF 0x0008


/*---------------------------------------------------------------------------------
   Square 1 Control Register
   Square 2 Control Register
-----------------------------------------------------------------------------------
fedcba9876543210
||||||||||||||||
||||||||||++++++- Sound length (1 longest; 63: shortest)
||||||||++------- Duty cycle (00: 1/8; 01: 1/4; 10: 1/2; 11: 3/4)
|||||+++--------- Envelope step time (0: off; 1 fastest; 7 slowest)
||||+------------ Envelope direction (0: decrease; 1: increase)
++++------------- Volume
---------------------------------------------------------------------------------*/
#define SQR1CTRL    (*(volatile u16 *)0x04000062)
#define SQR2CTRL    (*(volatile u16 *)0x04000068)
#define SQR_DUTY(n) ((n) << 6)
#define SQR_VOL(n)  ((n) << 12)

/*---------------------------------------------------------------------------------
   Square 1 Frequency
   Square 2 Frequency
   Triangle Channel Frequency (0x04000074)
-----------------------------------------------------------------------------------
fedcba9876543210
||   |||||||||||
||   +++++++++++- frequency (131072 Hz/(2048-x)) (halved for tri channel)
|+--------------- 0: hold note; 1: use length
+---------------- 1: Reset channel
---------------------------------------------------------------------------------*/
#define SQR1FREQ      (*(volatile u16 *)0x04000064)
#define SQR2FREQ      (*(volatile u16 *)0x0400006c)
#define TRIFREQ       (*(volatile u16 *)0x04000074)
#define TRIFREQ_HOLD  0x0000
#define TRIFREQ_TIMED 0x4000
#define TRIFREQ_RESET 0x8000


/*---------------------------------------------------------------------------------
	Triangle Channel Control Register
-----------------------------------------------------------------------------------
fedcba9876543210
        |||
        ||+------ Bank mode (0: 2 banks of 32; 1: 1 bank of 64)
        |+------- Play this bank (and write other bank)
        +-------- Enable triangle channel
---------------------------------------------------------------------------------*/
#define TRICTRL         (*(volatile u16 *)0x04000070)
#define TRICTRL_2X32    0x0000
#define TRICTRL_1X64    0x0020
#define TRICTRL_BANK(x) ((x) << 6)
#define TRICTRL_ENABLE  0x0080

/*---------------------------------------------------------------------------------
	Triangle Channel Length/Volume (0x04000072)
-----------------------------------------------------------------------------------

fedcba9876543210
|||     ||||||||
|||     ++++++++- Length ((256-x)/256 seconds)
+++-------------- Volume (000: mute; 001: 100%; 010: 50%;
                          011: 25%; 100: 75%)
---------------------------------------------------------------------------------*/
#define TRILENVOL        (*(volatile u16 *)0x04000072)
#define TRILENVOL_LEN(x) (256 - (x))
#define TRILENVOL_MUTE   0x0000
#define TRILENVOL_25     0x6000
#define TRILENVOL_50     0x4000
#define TRILENVOL_75     0x8000
#define TRILENVOL_100    0x2000

#define TRIWAVERAM ((volatile u32 *)0x04000090)

//---------------------------------------------------------------------------------
//	Bios sound functions
//---------------------------------------------------------------------------------
static inline
void SoundDriverMain()		{ SystemCall(28); }
static inline
void SoundDriverVsync()		{ SystemCall(29); }
static inline
void SoundChannelClear()	{ SystemCall(30); }
static inline
void SoundDriverVsyncOff()	{ SystemCall(40); }
static inline
void SoundDriverVsyncOn()	{ SystemCall(41); }

void SoundDriverInit(SoundArea *sa);
void SoundDriverMode(u32 mode);

u32  MidiKey2Freq(WaveData *wa, u8 mk, u8 fp);

//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif //_gba_sound_h_
