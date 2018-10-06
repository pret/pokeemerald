	.include "MPlayDef.s"

	.equ	se_n_grp, voicegroup128
	.equ	se_n_pri, 4
	.equ	se_n_rev, reverb_set+50
	.equ	se_n_mvl, 127
	.equ	se_n_key, 0
	.equ	se_n_tbs, 1
	.equ	se_n_exg, 0
	.equ	se_n_cmp, 1

	.section .rodata
	.global	se_n
	.align	2

@********************** Track  1 **********************@

se_n_1:
	.byte	KEYSH , se_n_key+0
	.byte	TEMPO , 240*se_n_tbs/2
	.byte		VOICE , 127
	.byte		BENDR , 12
	.byte		VOL   , 127*se_n_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N72   , Cn3 , v127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_n:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_n_pri	@ Priority
	.byte	se_n_rev	@ Reverb.

	.word	se_n_grp

	.word	se_n_1

	.end
