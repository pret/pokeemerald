	.include "MPlayDef.s"

	.equ	se_w011_grp, voicegroup_869D6F4
	.equ	se_w011_pri, 4
	.equ	se_w011_rev, reverb_set+50
	.equ	se_w011_mvl, 127
	.equ	se_w011_key, 0
	.equ	se_w011_tbs, 1
	.equ	se_w011_exg, 0
	.equ	se_w011_cmp, 1

	.section .rodata
	.global	se_w011
	.align	2

@********************** Track  1 **********************@

se_w011_1:
	.byte	KEYSH , se_w011_key+0
	.byte	TEMPO , 220*se_w011_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+4
	.byte		VOL   , 42*se_w011_mvl/mxv
	.byte		BEND  , c_v+39
	.byte		N06   , Cn5 , v084
	.byte	W01
	.byte		VOL   , 55*se_w011_mvl/mxv
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		VOL   , 71*se_w011_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		VOL   , 86*se_w011_mvl/mxv
	.byte		BEND  , c_v-18
	.byte	W01
	.byte		VOL   , 110*se_w011_mvl/mxv
	.byte		BEND  , c_v-50
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		VOICE , 8
	.byte		PAN   , c_v-11
	.byte		BEND  , c_v+0
	.byte		N06   , Gn4 , v120
	.byte	W02
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v-13
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-26
	.byte	W01
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v-46
	.byte	W01
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v-54
	.byte	W09
	.byte	FINE

@********************** Track  2 **********************@

se_w011_2:
	.byte	KEYSH , se_w011_key+0
	.byte		VOICE , 27
	.byte		VOL   , 110*se_w011_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn2 , v040
	.byte	W10
	.byte		N02   , Gn2 
	.byte	W14
	.byte	FINE

@******************************************************@
	.align	2

se_w011:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w011_pri	@ Priority
	.byte	se_w011_rev	@ Reverb.

	.word	se_w011_grp

	.word	se_w011_1
	.word	se_w011_2

	.end
