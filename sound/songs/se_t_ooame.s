	.include "MPlayDef.s"

	.equ	se_t_ooame_grp, voicegroup_869D6F4
	.equ	se_t_ooame_pri, 2
	.equ	se_t_ooame_rev, reverb_set+50
	.equ	se_t_ooame_mvl, 127
	.equ	se_t_ooame_key, 0
	.equ	se_t_ooame_tbs, 1
	.equ	se_t_ooame_exg, 0
	.equ	se_t_ooame_cmp, 1

	.section .rodata
	.global	se_t_ooame
	.align	2

@********************** Track  1 **********************@

se_t_ooame_1:
	.byte	KEYSH , se_t_ooame_key+0
	.byte	TEMPO , 220*se_t_ooame_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 18*se_t_ooame_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Cn3 , v060
	.byte	W03
	.byte		VOL   , 33*se_t_ooame_mvl/mxv
	.byte	W03
	.byte		        48*se_t_ooame_mvl/mxv
	.byte	W03
	.byte		        55*se_t_ooame_mvl/mxv
	.byte	W03
	.byte		        65*se_t_ooame_mvl/mxv
	.byte	W03
	.byte		        74*se_t_ooame_mvl/mxv
	.byte	W03
	.byte		        85*se_t_ooame_mvl/mxv
	.byte	W03
	.byte		        100*se_t_ooame_mvl/mxv
	.byte	W03
se_t_ooame_1_B1:
	.byte		N36   , Cn3 , v060
	.byte	W24
	.byte	W12
	.byte	GOTO
	 .word	se_t_ooame_1_B1
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_t_ooame:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_t_ooame_pri	@ Priority
	.byte	se_t_ooame_rev	@ Reverb.

	.word	se_t_ooame_grp

	.word	se_t_ooame_1

	.end
