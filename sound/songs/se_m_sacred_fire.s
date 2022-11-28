	.include "MPlayDef.s"

	.equ	se_m_sacred_fire_grp, voicegroup128
	.equ	se_m_sacred_fire_pri, 4
	.equ	se_m_sacred_fire_rev, reverb_set+50
	.equ	se_m_sacred_fire_mvl, 127
	.equ	se_m_sacred_fire_key, 0
	.equ	se_m_sacred_fire_tbs, 1
	.equ	se_m_sacred_fire_exg, 0
	.equ	se_m_sacred_fire_cmp, 1

	.section .rodata
	.global	se_m_sacred_fire
	.align	2

@********************** Track  1 **********************@

se_m_sacred_fire_1:
	.byte	KEYSH , se_m_sacred_fire_key+0
	.byte	TEMPO , 150*se_m_sacred_fire_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		VOL   , 110*se_m_sacred_fire_mvl/mxv
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+0
	.byte		N04   , Cn3 , v127
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N18   , Gn4
	.byte	W02
	.byte		PAN   , c_v-5
	.byte	W01
	.byte		VOL   , 98*se_m_sacred_fire_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 83*se_m_sacred_fire_mvl/mxv
	.byte		BEND  , c_v+6
	.byte	W02
	.byte		PAN   , c_v+5
	.byte	W01
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		VOL   , 63*se_m_sacred_fire_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		BEND  , c_v+13
	.byte	W02
	.byte		VOL   , 44*se_m_sacred_fire_mvl/mxv
	.byte		PAN   , c_v-5
	.byte	W02
	.byte		VOL   , 28*se_m_sacred_fire_mvl/mxv
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		VOL   , 12*se_m_sacred_fire_mvl/mxv
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_m_sacred_fire_2:
	.byte	KEYSH , se_m_sacred_fire_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_sacred_fire_mvl/mxv
	.byte		N01   , Gn2 , v032
	.byte	W02
	.byte		N01
	.byte	W02
	.byte		N18
	.byte	W03
	.byte		VOL   , 98*se_m_sacred_fire_mvl/mxv
	.byte	W03
	.byte		        83*se_m_sacred_fire_mvl/mxv
	.byte	W04
	.byte		        63*se_m_sacred_fire_mvl/mxv
	.byte	W04
	.byte		        44*se_m_sacred_fire_mvl/mxv
	.byte	W02
	.byte		        28*se_m_sacred_fire_mvl/mxv
	.byte	W02
	.byte		        12*se_m_sacred_fire_mvl/mxv
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_m_sacred_fire:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_sacred_fire_pri	@ Priority
	.byte	se_m_sacred_fire_rev	@ Reverb.

	.word	se_m_sacred_fire_grp

	.word	se_m_sacred_fire_1
	.word	se_m_sacred_fire_2

	.end
