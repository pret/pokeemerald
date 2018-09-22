	.include "MPlayDef.s"

	.equ	se_toy_c1_grp, voicegroup128
	.equ	se_toy_c1_pri, 4
	.equ	se_toy_c1_rev, reverb_set+50
	.equ	se_toy_c1_mvl, 127
	.equ	se_toy_c1_key, 0
	.equ	se_toy_c1_tbs, 1
	.equ	se_toy_c1_exg, 0
	.equ	se_toy_c1_cmp, 1

	.section .rodata
	.global	se_toy_c1
	.align	2

@********************** Track  1 **********************@

se_toy_c1_1:
	.byte	KEYSH , se_toy_c1_key+0
	.byte	TEMPO , 150*se_toy_c1_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_toy_c1_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Cn6 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Cn6 , v040
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_toy_c1_2:
	.byte	KEYSH , se_toy_c1_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_toy_c1_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Gn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Gn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_toy_c1:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_toy_c1_pri	@ Priority
	.byte	se_toy_c1_rev	@ Reverb.

	.word	se_toy_c1_grp

	.word	se_toy_c1_1
	.word	se_toy_c1_2

	.end
