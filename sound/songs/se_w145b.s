	.include "MPlayDef.s"

	.equ	se_w145b_grp, voicegroup128
	.equ	se_w145b_pri, 4
	.equ	se_w145b_rev, reverb_set+50
	.equ	se_w145b_mvl, 127
	.equ	se_w145b_key, 0
	.equ	se_w145b_tbs, 1
	.equ	se_w145b_exg, 0
	.equ	se_w145b_cmp, 1

	.section .rodata
	.global	se_w145b
	.align	2

@********************** Track  1 **********************@

se_w145b_1:
	.byte	KEYSH , se_w145b_key+0
	.byte	TEMPO , 220*se_w145b_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 110*se_w145b_mvl/mxv
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

se_w145b_2:
	.byte	KEYSH , se_w145b_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_w145b_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Cn4 , v044
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_w145b:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w145b_pri	@ Priority
	.byte	se_w145b_rev	@ Reverb.

	.word	se_w145b_grp

	.word	se_w145b_1
	.word	se_w145b_2

	.end
