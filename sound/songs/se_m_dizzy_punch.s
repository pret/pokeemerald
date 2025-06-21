	.include "MPlayDef.s"

	.equ	se_m_dizzy_punch_grp, voicegroup_rs_sfx_2
	.equ	se_m_dizzy_punch_pri, 4
	.equ	se_m_dizzy_punch_rev, reverb_set+50
	.equ	se_m_dizzy_punch_mvl, 127
	.equ	se_m_dizzy_punch_key, 0
	.equ	se_m_dizzy_punch_tbs, 1
	.equ	se_m_dizzy_punch_exg, 0
	.equ	se_m_dizzy_punch_cmp, 1

	.section .rodata
	.global	se_m_dizzy_punch
	.align	2

@********************** Track  1 **********************@

se_m_dizzy_punch_1:
	.byte	KEYSH , se_m_dizzy_punch_key+0
	.byte	TEMPO , 150*se_m_dizzy_punch_tbs/2
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 5*se_m_dizzy_punch_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N07   , Bn5 , v080
	.byte	W01
	.byte		VOL   , 55*se_m_dizzy_punch_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		VOL   , 67*se_m_dizzy_punch_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 90*se_m_dizzy_punch_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v-14
	.byte	W02
	.byte		VOL   , 4*se_m_dizzy_punch_mvl/mxv
	.byte		PAN   , c_v-22
	.byte		BEND  , c_v-23
	.byte	W01
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v+0
	.byte		N04   , Cn6
	.byte	W01
	.byte		VOL   , 66*se_m_dizzy_punch_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		VOL   , 90*se_m_dizzy_punch_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		VOL   , 4*se_m_dizzy_punch_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		BEND  , c_v+5
	.byte	W14
	.byte		VOL   , 90*se_m_dizzy_punch_mvl/mxv
	.byte	FINE

@******************************************************@
	.align	2

se_m_dizzy_punch:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_dizzy_punch_pri	@ Priority
	.byte	se_m_dizzy_punch_rev	@ Reverb.

	.word	se_m_dizzy_punch_grp

	.word	se_m_dizzy_punch_1

	.end
