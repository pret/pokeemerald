	.include "MPlayDef.s"

	.equ	se_e_grp, voicegroup128
	.equ	se_e_pri, 4
	.equ	se_e_rev, reverb_set+50
	.equ	se_e_mvl, 127
	.equ	se_e_key, 0
	.equ	se_e_tbs, 1
	.equ	se_e_exg, 0
	.equ	se_e_cmp, 1

	.section .rodata
	.global	se_e
	.align	2

@********************** Track  1 **********************@

se_e_1:
	.byte	KEYSH , se_e_key+0
	.byte	TEMPO , 240*se_e_tbs/2
	.byte		VOICE , 125
	.byte		BENDR , 12
	.byte		VOL   , 120*se_e_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N72   , Cn3 , v127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_e:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_e_pri	@ Priority
	.byte	se_e_rev	@ Reverb.

	.word	se_e_grp

	.word	se_e_1

	.end
