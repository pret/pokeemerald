	.include "MPlayDef.s"

	.equ	bgm_frlg_game_explanation_start_grp, voicegroup_86B1824
	.equ	bgm_frlg_game_explanation_start_pri, 0
	.equ	bgm_frlg_game_explanation_start_rev, reverb_set+50
	.equ	bgm_frlg_game_explanation_start_mvl, 127
	.equ	bgm_frlg_game_explanation_start_key, 0
	.equ	bgm_frlg_game_explanation_start_tbs, 1
	.equ	bgm_frlg_game_explanation_start_exg, 0
	.equ	bgm_frlg_game_explanation_start_cmp, 1

	.section .rodata
	.global	bgm_frlg_game_explanation_start
	.align	2

@********************** Track  1 **********************@

bgm_frlg_game_explanation_start_1:
	.byte	KEYSH , bgm_frlg_game_explanation_start_key+0
	.byte	TEMPO , 120*bgm_frlg_game_explanation_start_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 85*bgm_frlg_game_explanation_start_mvl/mxv
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
bgm_frlg_game_explanation_start_1_B1:
bgm_frlg_game_explanation_start_1_000:
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
bgm_frlg_game_explanation_start_1_001:
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v120
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_game_explanation_start_1_000
	.byte	PATT
	 .word	bgm_frlg_game_explanation_start_1_001
	.byte	GOTO
	 .word	bgm_frlg_game_explanation_start_1_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_game_explanation_start:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_game_explanation_start_pri	@ Priority
	.byte	bgm_frlg_game_explanation_start_rev	@ Reverb.

	.word	bgm_frlg_game_explanation_start_grp

	.word	bgm_frlg_game_explanation_start_1

	.end
