	.include "MPlayDef.s"

	.equ	se_t_koame_grp, voicegroup128
	.equ	se_t_koame_pri, 2
	.equ	se_t_koame_rev, reverb_set+50
	.equ	se_t_koame_mvl, 127
	.equ	se_t_koame_key, 0
	.equ	se_t_koame_tbs, 1
	.equ	se_t_koame_exg, 0
	.equ	se_t_koame_cmp, 1

	.section .rodata
	.global	se_t_koame
	.align	2

@********************** Track  1 **********************@

se_t_koame_1:
	.byte	KEYSH , se_t_koame_key+0
	.byte	TEMPO , 220*se_t_koame_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 15*se_t_koame_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Bn3 , v052
	.byte	W03
	.byte		VOL   , 27*se_t_koame_mvl/mxv
	.byte	W03
	.byte		        39*se_t_koame_mvl/mxv
	.byte	W03
	.byte		        44*se_t_koame_mvl/mxv
	.byte	W03
	.byte		        52*se_t_koame_mvl/mxv
	.byte	W03
	.byte		        59*se_t_koame_mvl/mxv
	.byte	W03
	.byte		        68*se_t_koame_mvl/mxv
	.byte	W03
	.byte		        80*se_t_koame_mvl/mxv
	.byte	W03
se_t_koame_1_B1:
	.byte		N60   , Bn3 , v052
	.byte	W24
	.byte	W24
	.byte	W12
	.byte	GOTO
	 .word	se_t_koame_1_B1
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_t_koame:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_t_koame_pri	@ Priority
	.byte	se_t_koame_rev	@ Reverb.

	.word	se_t_koame_grp

	.word	se_t_koame_1

	.end
