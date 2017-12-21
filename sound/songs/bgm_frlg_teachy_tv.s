	.include "MPlayDef.s"

	.equ	bgm_frlg_teachy_tv_grp, voicegroup_86B2C4C
	.equ	bgm_frlg_teachy_tv_pri, 0
	.equ	bgm_frlg_teachy_tv_rev, reverb_set+50
	.equ	bgm_frlg_teachy_tv_mvl, 127
	.equ	bgm_frlg_teachy_tv_key, 0
	.equ	bgm_frlg_teachy_tv_tbs, 1
	.equ	bgm_frlg_teachy_tv_exg, 0
	.equ	bgm_frlg_teachy_tv_cmp, 1

	.section .rodata
	.global	bgm_frlg_teachy_tv
	.align	2

@********************** Track  1 **********************@

bgm_frlg_teachy_tv_1:
	.byte	KEYSH , bgm_frlg_teachy_tv_key+0
	.byte	TEMPO , 144*bgm_frlg_teachy_tv_tbs/2
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 59*bgm_frlg_teachy_tv_mvl/mxv
	.byte	W24
bgm_frlg_teachy_tv_1_B1:
bgm_frlg_teachy_tv_1_000:
	.byte		N06   , Cn2 , v088
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_teachy_tv_1_000
	.byte	GOTO
	 .word	bgm_frlg_teachy_tv_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_teachy_tv_2:
	.byte	KEYSH , bgm_frlg_teachy_tv_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_frlg_teachy_tv_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
bgm_frlg_teachy_tv_2_B1:
bgm_frlg_teachy_tv_2_000:
	.byte	W12
	.byte		N06   , En3 , v088
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_teachy_tv_2_000
	.byte	GOTO
	 .word	bgm_frlg_teachy_tv_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_teachy_tv_3:
	.byte	KEYSH , bgm_frlg_teachy_tv_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_frlg_teachy_tv_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W24
bgm_frlg_teachy_tv_3_B1:
bgm_frlg_teachy_tv_3_000:
	.byte		N06   , Cn2 , v048
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_teachy_tv_3_000
	.byte	GOTO
	 .word	bgm_frlg_teachy_tv_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_teachy_tv_4:
	.byte	KEYSH , bgm_frlg_teachy_tv_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*bgm_frlg_teachy_tv_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cn4 , v120
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 
	.byte	W12
bgm_frlg_teachy_tv_4_B1:
	.byte		PAN   , c_v+0
	.byte		TIE   , Cn4 , v064
	.byte	W24
	.byte		BEND  , c_v+9
	.byte	W09
	.byte		        c_v-10
	.byte	W09
	.byte		        c_v+0
	.byte	W54
	.byte		        c_v+9
	.byte	W24
	.byte		        c_v-8
	.byte	W24
	.byte		        c_v+0
	.byte	W48
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_frlg_teachy_tv_4_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_teachy_tv:
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_teachy_tv_pri	@ Priority
	.byte	bgm_frlg_teachy_tv_rev	@ Reverb.

	.word	bgm_frlg_teachy_tv_grp

	.word	bgm_frlg_teachy_tv_1
	.word	bgm_frlg_teachy_tv_2
	.word	bgm_frlg_teachy_tv_3
	.word	bgm_frlg_teachy_tv_4

	.end
