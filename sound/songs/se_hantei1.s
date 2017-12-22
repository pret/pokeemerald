	.include "MPlayDef.s"

	.equ	se_hantei1_grp, voicegroup_86A0154
	.equ	se_hantei1_pri, 5
	.equ	se_hantei1_rev, reverb_set+50
	.equ	se_hantei1_mvl, 127
	.equ	se_hantei1_key, 0
	.equ	se_hantei1_tbs, 1
	.equ	se_hantei1_exg, 0
	.equ	se_hantei1_cmp, 1

	.section .rodata
	.global	se_hantei1
	.align	2

@********************** Track  1 **********************@

se_hantei1_1:
	.byte	KEYSH , se_hantei1_key+0
	.byte	TEMPO , 92*se_hantei1_tbs/2
	.byte		VOICE , 116
	.byte		VOL   , 127*se_hantei1_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		N32   , Fn3 , v127
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

se_hantei1_2:
	.byte	KEYSH , se_hantei1_key+0
	.byte		VOICE , 117
	.byte		VOL   , 127*se_hantei1_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+1
	.byte		N32   , An3 , v100
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_hantei1:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hantei1_pri	@ Priority
	.byte	se_hantei1_rev	@ Reverb.

	.word	se_hantei1_grp

	.word	se_hantei1_1
	.word	se_hantei1_2

	.end
