	.include "MPlayDef.s"

	.equ	se_w077_grp, voicegroup128
	.equ	se_w077_pri, 4
	.equ	se_w077_rev, reverb_set+50
	.equ	se_w077_mvl, 127
	.equ	se_w077_key, 0
	.equ	se_w077_tbs, 1
	.equ	se_w077_exg, 0
	.equ	se_w077_cmp, 1

	.section .rodata
	.global	se_w077
	.align	2

@********************** Track  1 **********************@

se_w077_1:
	.byte	KEYSH , se_w077_key+0
	.byte	TEMPO , 150*se_w077_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		VOL   , 55*se_w077_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N01   , Cn6 , v100
	.byte	W01
	.byte		VOL   , 110*se_w077_mvl/mxv
	.byte	W01
	.byte		VOICE , 36
	.byte		VOL   , 55*se_w077_mvl/mxv
	.byte		N02   , Gn6 , v080
	.byte	W01
	.byte		VOL   , 110*se_w077_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+20
	.byte		N01   , Gn6 , v024
	.byte	W03
	.byte		        Gn6 , v016
	.byte	W02
	.byte		PAN   , c_v-21
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_w077:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w077_pri	@ Priority
	.byte	se_w077_rev	@ Reverb.

	.word	se_w077_grp

	.word	se_w077_1

	.end
