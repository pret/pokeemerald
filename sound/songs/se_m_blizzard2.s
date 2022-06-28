	.include "MPlayDef.s"

	.equ	se_m_blizzard2_grp, voicegroup128
	.equ	se_m_blizzard2_pri, 4
	.equ	se_m_blizzard2_rev, 0
	.equ	se_m_blizzard2_mvl, 127
	.equ	se_m_blizzard2_key, 0
	.equ	se_m_blizzard2_tbs, 1
	.equ	se_m_blizzard2_exg, 0
	.equ	se_m_blizzard2_cmp, 1

	.section .rodata
	.global	se_m_blizzard2
	.align	2

@********************** Track  1 **********************@

se_m_blizzard2_1:
	.byte	KEYSH , se_m_blizzard2_key+0
	.byte	TEMPO , 150*se_m_blizzard2_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_blizzard2_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Gn3 , v108
	.byte	W02
	.byte		PAN   , c_v-19
	.byte	W04
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 97*se_m_blizzard2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		VOL   , 84*se_m_blizzard2_mvl/mxv
	.byte	W03
	.byte		        76*se_m_blizzard2_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		VOL   , 55*se_m_blizzard2_mvl/mxv
	.byte		PAN   , c_v-8
	.byte	W02
	.byte		VOL   , 39*se_m_blizzard2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 25*se_m_blizzard2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		VOL   , 13*se_m_blizzard2_mvl/mxv
	.byte	W03
	.byte		        7*se_m_blizzard2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_m_blizzard2:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_blizzard2_pri	@ Priority
	.byte	se_m_blizzard2_rev	@ Reverb.

	.word	se_m_blizzard2_grp

	.word	se_m_blizzard2_1

	.end
