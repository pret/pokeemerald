	.include "MPlayDef.s"

	.equ	se_i_grp, voicegroup128
	.equ	se_i_pri, 4
	.equ	se_i_rev, reverb_set+50
	.equ	se_i_mvl, 127
	.equ	se_i_key, 0
	.equ	se_i_tbs, 1
	.equ	se_i_exg, 0
	.equ	se_i_cmp, 1

	.section .rodata
	.global	se_i
	.align	2

@********************** Track  1 **********************@

se_i_1:
	.byte	KEYSH , se_i_key+0
	.byte	TEMPO , 240*se_i_tbs/2
	.byte		VOICE , 123
	.byte		BENDR , 12
	.byte		VOL   , 120*se_i_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N72   , Cn3 , v127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_i:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_i_pri	@ Priority
	.byte	se_i_rev	@ Reverb.

	.word	se_i_grp

	.word	se_i_1

	.end
