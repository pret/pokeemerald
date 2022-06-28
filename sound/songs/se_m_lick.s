	.include "MPlayDef.s"

	.equ	se_m_lick_grp, voicegroup128
	.equ	se_m_lick_pri, 4
	.equ	se_m_lick_rev, 0
	.equ	se_m_lick_mvl, 127
	.equ	se_m_lick_key, 0
	.equ	se_m_lick_tbs, 1
	.equ	se_m_lick_exg, 0
	.equ	se_m_lick_cmp, 1

	.section .rodata
	.global	se_m_lick
	.align	2

@********************** Track  1 **********************@

se_m_lick_1:
	.byte	KEYSH , se_m_lick_key+0
	.byte	TEMPO , 150*se_m_lick_tbs/2
	.byte		VOICE , 31
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_lick_mvl/mxv
	.byte		BEND  , c_v-5
	.byte		N32   , Cn3 , v127
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-13
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-25
	.byte	W02
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-39
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+3
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte	W02
	.byte		PAN   , c_v-4
	.byte		VOL   , 102*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		VOL   , 97*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+14
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		VOL   , 92*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+18
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		VOL   , 88*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+17
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		VOL   , 81*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 64*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+4
	.byte		VOL   , 49*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+14
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 25*se_m_lick_mvl/mxv
	.byte		BEND  , c_v+11
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_m_lick:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_lick_pri	@ Priority
	.byte	se_m_lick_rev	@ Reverb.

	.word	se_m_lick_grp

	.word	se_m_lick_1

	.end
