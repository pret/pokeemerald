	.include "MPlayDef.s"

	.equ	mus_rg_seibetu_grp, voicegroup182
	.equ	mus_rg_seibetu_pri, 0
	.equ	mus_rg_seibetu_rev, reverb_set+50
	.equ	mus_rg_seibetu_mvl, 127
	.equ	mus_rg_seibetu_key, 0
	.equ	mus_rg_seibetu_tbs, 1
	.equ	mus_rg_seibetu_exg, 0
	.equ	mus_rg_seibetu_cmp, 1

	.section .rodata
	.global	mus_rg_seibetu
	.align	2

@********************** Track  1 **********************@

mus_rg_seibetu_1:
	.byte	KEYSH , mus_rg_seibetu_key+0
	.byte	TEMPO , 120*mus_rg_seibetu_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+28
	.byte		VOL   , 67*mus_rg_seibetu_mvl/mxv
	.byte	W24
	.byte		N06   , Gn3 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_seibetu_2:
	.byte	KEYSH , mus_rg_seibetu_key+0
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 81*mus_rg_seibetu_mvl/mxv
	.byte	W24
	.byte		N06   , Bn3 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_seibetu_3:
	.byte	KEYSH , mus_rg_seibetu_key+0
	.byte		VOICE , 58
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 88*mus_rg_seibetu_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs1 , v120
	.byte	W48
	.byte	W48
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_seibetu_4:
	.byte	KEYSH , mus_rg_seibetu_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-24
	.byte		VOL   , 67*mus_rg_seibetu_mvl/mxv
	.byte	W24
	.byte		N06   , Bn2 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_seibetu_5:
	.byte	KEYSH , mus_rg_seibetu_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 86*mus_rg_seibetu_mvl/mxv
	.byte		PAN   , c_v+2
	.byte	W24
	.byte		N15   , Gn2 , v120
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_seibetu_6:
	.byte	KEYSH , mus_rg_seibetu_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*mus_rg_seibetu_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs1 , v120
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W24
	.byte	W48
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_seibetu_7:
	.byte	KEYSH , mus_rg_seibetu_key+0
	.byte		VOICE , 0
	.byte		VOL   , 86*mus_rg_seibetu_mvl/mxv
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

mus_rg_seibetu:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_seibetu_pri	@ Priority
	.byte	mus_rg_seibetu_rev	@ Reverb.

	.word	mus_rg_seibetu_grp

	.word	mus_rg_seibetu_1
	.word	mus_rg_seibetu_2
	.word	mus_rg_seibetu_3
	.word	mus_rg_seibetu_4
	.word	mus_rg_seibetu_5
	.word	mus_rg_seibetu_6
	.word	mus_rg_seibetu_7

	.end
