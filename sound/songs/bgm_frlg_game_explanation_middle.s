	.include "MPlayDef.s"

	.equ	bgm_frlg_game_explanation_middle_grp, voicegroup_86B1824
	.equ	bgm_frlg_game_explanation_middle_pri, 0
	.equ	bgm_frlg_game_explanation_middle_rev, reverb_set+50
	.equ	bgm_frlg_game_explanation_middle_mvl, 127
	.equ	bgm_frlg_game_explanation_middle_key, 0
	.equ	bgm_frlg_game_explanation_middle_tbs, 1
	.equ	bgm_frlg_game_explanation_middle_exg, 0
	.equ	bgm_frlg_game_explanation_middle_cmp, 1

	.section .rodata
	.global	bgm_frlg_game_explanation_middle
	.align	2

@********************** Track  1 **********************@

bgm_frlg_game_explanation_middle_1:
	.byte	KEYSH , bgm_frlg_game_explanation_middle_key+0
bgm_frlg_game_explanation_middle_1_B1:
	.byte	TEMPO , 120*bgm_frlg_game_explanation_middle_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+23
	.byte		VOL   , 67*bgm_frlg_game_explanation_middle_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		N06   , Gn3 , v120
	.byte	W96
	.byte	W72
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_game_explanation_middle_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_game_explanation_middle_2:
	.byte	KEYSH , bgm_frlg_game_explanation_middle_key+0
bgm_frlg_game_explanation_middle_2_B1:
	.byte		VOICE , 58
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 88*bgm_frlg_game_explanation_middle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gn1 , v120
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N24   , Fs1 
	.byte	W24
bgm_frlg_game_explanation_middle_2_000:
	.byte		N12   , Gn1 , v120
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte	PEND
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_game_explanation_middle_2_000
	.byte		N06   , Gn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_game_explanation_middle_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_game_explanation_middle_3:
	.byte	KEYSH , bgm_frlg_game_explanation_middle_key+0
bgm_frlg_game_explanation_middle_3_B1:
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-16
	.byte		VOL   , 70*bgm_frlg_game_explanation_middle_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		N06   , Bn2 , v120
	.byte	W96
	.byte	W72
	.byte		N24   , As2 
	.byte	W24
	.byte		N06   , Bn2 
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_game_explanation_middle_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_game_explanation_middle_4:
	.byte	KEYSH , bgm_frlg_game_explanation_middle_key+0
bgm_frlg_game_explanation_middle_4_B1:
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 86*bgm_frlg_game_explanation_middle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gn2 , v120
	.byte	W96
	.byte	W96
	.byte		N12   
	.byte	W96
	.byte	W96
	.byte		N12   
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_game_explanation_middle_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_game_explanation_middle_5:
	.byte	KEYSH , bgm_frlg_game_explanation_middle_key+0
bgm_frlg_game_explanation_middle_5_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*bgm_frlg_game_explanation_middle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gn1 , v120
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N24   , Fs1 
	.byte	W24
bgm_frlg_game_explanation_middle_5_000:
	.byte		N12   , Gn1 , v120
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte	PEND
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_game_explanation_middle_5_000
	.byte		N06   , Gn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_game_explanation_middle_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_game_explanation_middle_6:
	.byte	KEYSH , bgm_frlg_game_explanation_middle_key+0
bgm_frlg_game_explanation_middle_6_B1:
	.byte		VOICE , 0
	.byte		VOL   , 85*bgm_frlg_game_explanation_middle_mvl/mxv
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
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
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
bgm_frlg_game_explanation_middle_6_000:
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
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
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
	.byte	PATT
	 .word	bgm_frlg_game_explanation_middle_6_000
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
	.byte	GOTO
	 .word	bgm_frlg_game_explanation_middle_6_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_game_explanation_middle:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_game_explanation_middle_pri	@ Priority
	.byte	bgm_frlg_game_explanation_middle_rev	@ Reverb.

	.word	bgm_frlg_game_explanation_middle_grp

	.word	bgm_frlg_game_explanation_middle_1
	.word	bgm_frlg_game_explanation_middle_2
	.word	bgm_frlg_game_explanation_middle_3
	.word	bgm_frlg_game_explanation_middle_4
	.word	bgm_frlg_game_explanation_middle_5
	.word	bgm_frlg_game_explanation_middle_6

	.end
