	.include "MPlayDef.s"

	.equ	se_m_sacred_fire2_grp, voicegroup_rs_sfx_2
	.equ	se_m_sacred_fire2_pri, 4
	.equ	se_m_sacred_fire2_rev, reverb_set+50
	.equ	se_m_sacred_fire2_mvl, 127
	.equ	se_m_sacred_fire2_key, 0
	.equ	se_m_sacred_fire2_tbs, 1
	.equ	se_m_sacred_fire2_exg, 0
	.equ	se_m_sacred_fire2_cmp, 1

	.section .rodata
	.global	se_m_sacred_fire2
	.align	2

@********************** Track  1 **********************@

se_m_sacred_fire2_1:
	.byte	KEYSH , se_m_sacred_fire2_key+0
	.byte	TEMPO , 150*se_m_sacred_fire2_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		VOL   , 22*se_m_sacred_fire2_mvl/mxv
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+0
	.byte		N96   , Gn3 , v127
	.byte	W01
	.byte		VOL   , 49*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		        71*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 95*se_m_sacred_fire2_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		VOL   , 110*se_m_sacred_fire2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		VOL   , 97*se_m_sacred_fire2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+7
	.byte	W03
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 84*se_m_sacred_fire2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		VOL   , 76*se_m_sacred_fire2_mvl/mxv
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		PAN   , c_v-2
	.byte		BEND  , c_v-46
	.byte	W03
	.byte		VOL   , 84*se_m_sacred_fire2_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 92*se_m_sacred_fire2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-5
	.byte	W01
	.byte		BEND  , c_v-32
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 86*se_m_sacred_fire2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+5
	.byte	W02
	.byte		BEND  , c_v-18
	.byte	W01
	.byte		VOL   , 78*se_m_sacred_fire2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		        c_v-5
	.byte	W02
	.byte		VOL   , 71*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-2
	.byte	W03
	.byte		        c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte		VOL   , 78*se_m_sacred_fire2_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-5
	.byte	W02
	.byte		VOL   , 86*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		        c_v+5
	.byte	W02
	.byte		VOL   , 90*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v-2
	.byte	W01
	.byte		VOL   , 80*se_m_sacred_fire2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+5
	.byte	W03
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 86*se_m_sacred_fire2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-5
	.byte	W03
	.byte		        c_v+0
	.byte		VOL   , 83*se_m_sacred_fire2_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+5
	.byte		VOL   , 63*se_m_sacred_fire2_mvl/mxv
	.byte	W03
	.byte		        37*se_m_sacred_fire2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		        c_v-5
	.byte		VOL   , 13*se_m_sacred_fire2_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-2
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_sacred_fire2_2:
	.byte	KEYSH , se_m_sacred_fire2_key+0
	.byte		VOICE , 27
	.byte		VOL   , 22*se_m_sacred_fire2_mvl/mxv
	.byte		N96   , Gn2 , v032
	.byte	W01
	.byte		VOL   , 49*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		        71*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		        95*se_m_sacred_fire2_mvl/mxv
	.byte	W01
	.byte		        110*se_m_sacred_fire2_mvl/mxv
	.byte	W05
	.byte		        97*se_m_sacred_fire2_mvl/mxv
	.byte	W15
	.byte	W24
	.byte	W24
	.byte	W09
	.byte		        83*se_m_sacred_fire2_mvl/mxv
	.byte	W03
	.byte		        63*se_m_sacred_fire2_mvl/mxv
	.byte	W03
	.byte		        37*se_m_sacred_fire2_mvl/mxv
	.byte	W03
	.byte		        13*se_m_sacred_fire2_mvl/mxv
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_sacred_fire2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_sacred_fire2_pri	@ Priority
	.byte	se_m_sacred_fire2_rev	@ Reverb.

	.word	se_m_sacred_fire2_grp

	.word	se_m_sacred_fire2_1
	.word	se_m_sacred_fire2_2

	.end
