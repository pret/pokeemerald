	.include "MPlayDef.s"

	.equ	se_a_grp, voicegroup128
	.equ	se_a_pri, 4
	.equ	se_a_rev, reverb_set+50
	.equ	se_a_mvl, 127
	.equ	se_a_key, 0
	.equ	se_a_tbs, 1
	.equ	se_a_exg, 0
	.equ	se_a_cmp, 1

	.section .rodata
	.global	se_a
	.align	2

@********************** Track  1 **********************@

se_a_1:
	.byte	KEYSH , se_a_key+0
	.byte	TEMPO , 240*se_a_tbs/2
	.byte		VOICE , 122
	.byte		BENDR , 12
	.byte		VOL   , 95*se_a_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N72   , Cn3 , v127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_a:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_a_pri	@ Priority
	.byte	se_a_rev	@ Reverb.

	.word	se_a_grp

	.word	se_a_1

	.end
