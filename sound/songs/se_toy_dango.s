	.include "MPlayDef.s"

	.equ	se_toy_dango_grp, voicegroup128
	.equ	se_toy_dango_pri, 4
	.equ	se_toy_dango_rev, reverb_set+50
	.equ	se_toy_dango_mvl, 127
	.equ	se_toy_dango_key, 0
	.equ	se_toy_dango_tbs, 1
	.equ	se_toy_dango_exg, 0
	.equ	se_toy_dango_cmp, 1

	.section .rodata
	.global	se_toy_dango
	.align	2

@********************** Track  1 **********************@

se_toy_dango_1:
	.byte	KEYSH , se_toy_dango_key+0
	.byte	TEMPO , 150*se_toy_dango_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_toy_dango_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn4 , v112
	.byte	W01
	.byte		VOICE , 26
	.byte	W01
	.byte		N01   , Fn4 , v127
	.byte	W01
	.byte	W01
	.byte		VOICE , 36
	.byte	W02
	.byte		N01   , Cn3 , v056
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_toy_dango:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_toy_dango_pri	@ Priority
	.byte	se_toy_dango_rev	@ Reverb.

	.word	se_toy_dango_grp

	.word	se_toy_dango_1

	.end
