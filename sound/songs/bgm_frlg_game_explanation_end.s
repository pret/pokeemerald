	.include "MPlayDef.s"

	.equ	bgm_frlg_game_explanation_end_grp, voicegroup_86B1824
	.equ	bgm_frlg_game_explanation_end_pri, 0
	.equ	bgm_frlg_game_explanation_end_rev, reverb_set+50
	.equ	bgm_frlg_game_explanation_end_mvl, 127
	.equ	bgm_frlg_game_explanation_end_key, 0
	.equ	bgm_frlg_game_explanation_end_tbs, 1
	.equ	bgm_frlg_game_explanation_end_exg, 0
	.equ	bgm_frlg_game_explanation_end_cmp, 1

	.section .rodata
	.global	bgm_frlg_game_explanation_end
	.align	2

@********************** Track  1 **********************@

bgm_frlg_game_explanation_end_1:
	.byte	KEYSH , bgm_frlg_game_explanation_end_key+0
	.byte	TEMPO , 120*bgm_frlg_game_explanation_end_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+28
	.byte		VOL   , 67*bgm_frlg_game_explanation_end_mvl/mxv
	.byte	W24
	.byte		N06   , Gn3 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_game_explanation_end_2:
	.byte	KEYSH , bgm_frlg_game_explanation_end_key+0
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 81*bgm_frlg_game_explanation_end_mvl/mxv
	.byte	W24
	.byte		N06   , Bn3 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_game_explanation_end_3:
	.byte	KEYSH , bgm_frlg_game_explanation_end_key+0
	.byte		VOICE , 58
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 88*bgm_frlg_game_explanation_end_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs1 , v120
	.byte	W48
	.byte	W48
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_game_explanation_end_4:
	.byte	KEYSH , bgm_frlg_game_explanation_end_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-24
	.byte		VOL   , 67*bgm_frlg_game_explanation_end_mvl/mxv
	.byte	W24
	.byte		N06   , Bn2 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_game_explanation_end_5:
	.byte	KEYSH , bgm_frlg_game_explanation_end_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 86*bgm_frlg_game_explanation_end_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W24
	.byte		N15   , Gn2 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_game_explanation_end_6:
	.byte	KEYSH , bgm_frlg_game_explanation_end_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*bgm_frlg_game_explanation_end_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs1 , v120
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_game_explanation_end_7:
	.byte	KEYSH , bgm_frlg_game_explanation_end_key+0
	.byte		VOICE , 0
	.byte		VOL   , 86*bgm_frlg_game_explanation_end_mvl/mxv
	.byte		N03   , En1 , v120
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
	.byte		N06   , En1 , v120
	.byte		N48   , An2 , v096
	.byte	W24
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_game_explanation_end:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_game_explanation_end_pri	@ Priority
	.byte	bgm_frlg_game_explanation_end_rev	@ Reverb.

	.word	bgm_frlg_game_explanation_end_grp

	.word	bgm_frlg_game_explanation_end_1
	.word	bgm_frlg_game_explanation_end_2
	.word	bgm_frlg_game_explanation_end_3
	.word	bgm_frlg_game_explanation_end_4
	.word	bgm_frlg_game_explanation_end_5
	.word	bgm_frlg_game_explanation_end_6
	.word	bgm_frlg_game_explanation_end_7

	.end
