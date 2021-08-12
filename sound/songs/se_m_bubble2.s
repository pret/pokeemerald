	.include "MPlayDef.s"

	.equ	se_m_bubble2_grp, voicegroup128
	.equ	se_m_bubble2_pri, 4
	.equ	se_m_bubble2_rev, reverb_set+50
	.equ	se_m_bubble2_mvl, 127
	.equ	se_m_bubble2_key, 0
	.equ	se_m_bubble2_tbs, 1
	.equ	se_m_bubble2_exg, 0
	.equ	se_m_bubble2_cmp, 1

	.section .rodata
	.global	se_m_bubble2
	.align	2

@********************** Track  1 **********************@

se_m_bubble2_1:
	.byte	KEYSH , se_m_bubble2_key+0
	.byte	TEMPO , 220*se_m_bubble2_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 110*se_m_bubble2_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		N09   , Gn4 , v127
	.byte	W02
	.byte		BEND  , c_v+31
	.byte	W02
	.byte		        c_v-34
	.byte	W17
	.byte	FINE

@********************** Track  2 **********************@

se_m_bubble2_2:
	.byte	KEYSH , se_m_bubble2_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_m_bubble2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Cn4 , v044
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_m_bubble2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_bubble2_pri	@ Priority
	.byte	se_m_bubble2_rev	@ Reverb.

	.word	se_m_bubble2_grp

	.word	se_m_bubble2_1
	.word	se_m_bubble2_2

	.end
