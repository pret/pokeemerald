	.include "MPlayDef.s"

	.equ	se_o_grp, voicegroup128
	.equ	se_o_pri, 4
	.equ	se_o_rev, reverb_set+50
	.equ	se_o_mvl, 127
	.equ	se_o_key, 0
	.equ	se_o_tbs, 1
	.equ	se_o_exg, 0
	.equ	se_o_cmp, 1

	.section .rodata
	.global	se_o
	.align	2

@********************** Track  1 **********************@

se_o_1:
	.byte	KEYSH , se_o_key+0
	.byte	TEMPO , 240*se_o_tbs/2
	.byte		VOICE , 126
	.byte		BENDR , 12
	.byte		VOL   , 120*se_o_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N72   , Cn3 , v127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_o:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_o_pri	@ Priority
	.byte	se_o_rev	@ Reverb.

	.word	se_o_grp

	.word	se_o_1

	.end
