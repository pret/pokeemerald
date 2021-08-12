	.include "MPlayDef.s"

	.equ	se_m_rock_throw_grp, voicegroup128
	.equ	se_m_rock_throw_pri, 4
	.equ	se_m_rock_throw_rev, reverb_set+50
	.equ	se_m_rock_throw_mvl, 127
	.equ	se_m_rock_throw_key, 0
	.equ	se_m_rock_throw_tbs, 1
	.equ	se_m_rock_throw_exg, 0
	.equ	se_m_rock_throw_cmp, 1

	.section .rodata
	.global	se_m_rock_throw
	.align	2

@********************** Track  1 **********************@

se_m_rock_throw_1:
	.byte	KEYSH , se_m_rock_throw_key+0
	.byte	TEMPO , 150*se_m_rock_throw_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*se_m_rock_throw_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , En3 , v127
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-34
	.byte	W03
	.byte		PAN   , c_v+7
	.byte		N03   , Gn3 , v100
	.byte	W03
	.byte		PAN   , c_v-15
	.byte		BEND  , c_v+4
	.byte		N06   , En3 , v127
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v-13
	.byte	W03
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v+0
	.byte		N06   , Cn3 , v084
	.byte	W06
	.byte		BEND  , c_v-20
	.byte		N06   , En3 , v068
	.byte	W03
	.byte		BEND  , c_v-41
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_m_rock_throw:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_rock_throw_pri	@ Priority
	.byte	se_m_rock_throw_rev	@ Reverb.

	.word	se_m_rock_throw_grp

	.word	se_m_rock_throw_1

	.end
