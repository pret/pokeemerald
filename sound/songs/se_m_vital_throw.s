	.include "MPlayDef.s"

	.equ	se_m_vital_throw_grp, voicegroup128
	.equ	se_m_vital_throw_pri, 4
	.equ	se_m_vital_throw_rev, reverb_set+50
	.equ	se_m_vital_throw_mvl, 127
	.equ	se_m_vital_throw_key, 0
	.equ	se_m_vital_throw_tbs, 1
	.equ	se_m_vital_throw_exg, 0
	.equ	se_m_vital_throw_cmp, 1

	.section .rodata
	.global	se_m_vital_throw
	.align	2

@********************** Track  1 **********************@

se_m_vital_throw_1:
	.byte	KEYSH , se_m_vital_throw_key+0
	.byte	TEMPO , 220*se_m_vital_throw_tbs/2
	.byte		VOICE , 22
	.byte		VOL   , 110*se_m_vital_throw_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+46
	.byte		N09   , Cn3 , v127
	.byte	W03
	.byte		VOL   , 104*se_m_vital_throw_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+23
	.byte	W03
	.byte		VOL   , 93*se_m_vital_throw_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		VOICE , 21
	.byte		VOL   , 110*se_m_vital_throw_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Gn4
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Cn5
	.byte	W09
	.byte	FINE

@********************** Track  2 **********************@

se_m_vital_throw_2:
	.byte	KEYSH , se_m_vital_throw_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_m_vital_throw_mvl/mxv
	.byte	W09
	.byte		PAN   , c_v+8
	.byte		N03   , Cn3 , v052
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N03
	.byte	W09
	.byte	FINE

@******************************************************@
	.align	2

se_m_vital_throw:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_vital_throw_pri	@ Priority
	.byte	se_m_vital_throw_rev	@ Reverb.

	.word	se_m_vital_throw_grp

	.word	se_m_vital_throw_1
	.word	se_m_vital_throw_2

	.end
