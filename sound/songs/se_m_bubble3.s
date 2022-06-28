	.include "MPlayDef.s"

	.equ	se_m_bubble3_grp, voicegroup128
	.equ	se_m_bubble3_pri, 4
	.equ	se_m_bubble3_rev, 0
	.equ	se_m_bubble3_mvl, 127
	.equ	se_m_bubble3_key, 0
	.equ	se_m_bubble3_tbs, 1
	.equ	se_m_bubble3_exg, 0
	.equ	se_m_bubble3_cmp, 1

	.section .rodata
	.global	se_m_bubble3
	.align	2

@********************** Track  1 **********************@

se_m_bubble3_1:
	.byte	KEYSH , se_m_bubble3_key+0
	.byte	TEMPO , 220*se_m_bubble3_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 95*se_m_bubble3_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , Gn2 , v127
	.byte	W06
	.byte		PAN   , c_v-17
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+16
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+25
	.byte	W01
	.byte		        c_v+31
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte	W03
	.byte		N06
	.byte	W03
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+13
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_m_bubble3:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_bubble3_pri	@ Priority
	.byte	se_m_bubble3_rev	@ Reverb.

	.word	se_m_bubble3_grp

	.word	se_m_bubble3_1

	.end
