	.include "MPlayDef.s"

	.equ	se_m_bubble_grp, voicegroup128
	.equ	se_m_bubble_pri, 4
	.equ	se_m_bubble_rev, 0
	.equ	se_m_bubble_mvl, 127
	.equ	se_m_bubble_key, 0
	.equ	se_m_bubble_tbs, 1
	.equ	se_m_bubble_exg, 0
	.equ	se_m_bubble_cmp, 1

	.section .rodata
	.global	se_m_bubble
	.align	2

@********************** Track  1 **********************@

se_m_bubble_1:
	.byte	KEYSH , se_m_bubble_key+0
	.byte	TEMPO , 220*se_m_bubble_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 95*se_m_bubble_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N09   , Cn3 , v127
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		        c_v+16
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		        c_v+48
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte		N03   , En3
	.byte	W15
	.byte	FINE

@******************************************************@
	.align	2

se_m_bubble:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_bubble_pri	@ Priority
	.byte	se_m_bubble_rev	@ Reverb.

	.word	se_m_bubble_grp

	.word	se_m_bubble_1

	.end
