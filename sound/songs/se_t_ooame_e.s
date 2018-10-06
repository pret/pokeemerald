	.include "MPlayDef.s"

	.equ	se_t_ooame_e_grp, voicegroup128
	.equ	se_t_ooame_e_pri, 2
	.equ	se_t_ooame_e_rev, reverb_set+50
	.equ	se_t_ooame_e_mvl, 127
	.equ	se_t_ooame_e_key, 0
	.equ	se_t_ooame_e_tbs, 1
	.equ	se_t_ooame_e_exg, 0
	.equ	se_t_ooame_e_cmp, 1

	.section .rodata
	.global	se_t_ooame_e
	.align	2

@********************** Track  1 **********************@

se_t_ooame_e_1:
	.byte	KEYSH , se_t_ooame_e_key+0
	.byte	TEMPO , 220*se_t_ooame_e_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*se_t_ooame_e_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Cn3 , v060
	.byte	W03
	.byte		VOL   , 96*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        93*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        90*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        85*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        81*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        73*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        62*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        55*se_t_ooame_e_mvl/mxv
	.byte		N24   
	.byte	W03
	.byte		VOL   , 48*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        42*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        33*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        25*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        18*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        12*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte		        7*se_t_ooame_e_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_t_ooame_e:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_t_ooame_e_pri	@ Priority
	.byte	se_t_ooame_e_rev	@ Reverb.

	.word	se_t_ooame_e_grp

	.word	se_t_ooame_e_1

	.end
