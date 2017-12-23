	.include "MPlayDef.s"

	.equ	se_t_ame_e_grp, voicegroup_869D6F4
	.equ	se_t_ame_e_pri, 2
	.equ	se_t_ame_e_rev, reverb_set+50
	.equ	se_t_ame_e_mvl, 127
	.equ	se_t_ame_e_key, 0
	.equ	se_t_ame_e_tbs, 1
	.equ	se_t_ame_e_exg, 0
	.equ	se_t_ame_e_cmp, 1

	.section .rodata
	.global	se_t_ame_e
	.align	2

@********************** Track  1 **********************@

se_t_ame_e_1:
	.byte	KEYSH , se_t_ame_e_key+0
	.byte	TEMPO , 220*se_t_ame_e_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*se_t_ame_e_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Gn3 , v060
	.byte	W03
	.byte		VOL   , 76*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        74*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        72*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        68*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        64*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        58*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        50*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        44*se_t_ame_e_mvl/mxv
	.byte		N24   
	.byte	W03
	.byte		VOL   , 38*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        34*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        27*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        20*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        15*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        10*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte		        6*se_t_ame_e_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_t_ame_e:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_t_ame_e_pri	@ Priority
	.byte	se_t_ame_e_rev	@ Reverb.

	.word	se_t_ame_e_grp

	.word	se_t_ame_e_1

	.end
