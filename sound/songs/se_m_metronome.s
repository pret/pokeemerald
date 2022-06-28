	.include "MPlayDef.s"

	.equ	se_m_metronome_grp, voicegroup128
	.equ	se_m_metronome_pri, 4
	.equ	se_m_metronome_rev, 0
	.equ	se_m_metronome_mvl, 127
	.equ	se_m_metronome_key, 0
	.equ	se_m_metronome_tbs, 1
	.equ	se_m_metronome_exg, 0
	.equ	se_m_metronome_cmp, 1

	.section .rodata
	.global	se_m_metronome
	.align	2

@********************** Track  1 **********************@

se_m_metronome_1:
	.byte	KEYSH , se_m_metronome_key+0
	.byte	TEMPO , 150*se_m_metronome_tbs/2
	.byte		VOICE , 37
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 115*se_m_metronome_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N15   , En3 , v127
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+14
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+25
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+46
	.byte	W10
	.byte	FINE

@******************************************************@
	.align	2

se_m_metronome:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_metronome_pri	@ Priority
	.byte	se_m_metronome_rev	@ Reverb.

	.word	se_m_metronome_grp

	.word	se_m_metronome_1

	.end
