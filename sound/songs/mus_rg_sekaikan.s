	.include "MPlayDef.s"

	.equ	mus_rg_sekaikan_grp, voicegroup182
	.equ	mus_rg_sekaikan_pri, 0
	.equ	mus_rg_sekaikan_rev, reverb_set+50
	.equ	mus_rg_sekaikan_mvl, 127
	.equ	mus_rg_sekaikan_key, 0
	.equ	mus_rg_sekaikan_tbs, 1
	.equ	mus_rg_sekaikan_exg, 0
	.equ	mus_rg_sekaikan_cmp, 1

	.section .rodata
	.global	mus_rg_sekaikan
	.align	2

@********************** Track  1 **********************@

mus_rg_sekaikan_1:
	.byte	KEYSH , mus_rg_sekaikan_key+0
mus_rg_sekaikan_1_B1:
	.byte	TEMPO , 120*mus_rg_sekaikan_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+23
	.byte		VOL   , 67*mus_rg_sekaikan_mvl/mxv
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
	 .word	mus_rg_sekaikan_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_sekaikan_2:
	.byte	KEYSH , mus_rg_sekaikan_key+0
mus_rg_sekaikan_2_B1:
	.byte		VOICE , 58
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 88*mus_rg_sekaikan_mvl/mxv
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
mus_rg_sekaikan_2_000:
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
	 .word	mus_rg_sekaikan_2_000
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
	 .word	mus_rg_sekaikan_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_sekaikan_3:
	.byte	KEYSH , mus_rg_sekaikan_key+0
mus_rg_sekaikan_3_B1:
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-16
	.byte		VOL   , 70*mus_rg_sekaikan_mvl/mxv
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
	 .word	mus_rg_sekaikan_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_sekaikan_4:
	.byte	KEYSH , mus_rg_sekaikan_key+0
mus_rg_sekaikan_4_B1:
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 86*mus_rg_sekaikan_mvl/mxv
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
	 .word	mus_rg_sekaikan_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_sekaikan_5:
	.byte	KEYSH , mus_rg_sekaikan_key+0
mus_rg_sekaikan_5_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*mus_rg_sekaikan_mvl/mxv
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
mus_rg_sekaikan_5_000:
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
	 .word	mus_rg_sekaikan_5_000
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
	 .word	mus_rg_sekaikan_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_sekaikan_6:
	.byte	KEYSH , mus_rg_sekaikan_key+0
mus_rg_sekaikan_6_B1:
	.byte		VOICE , 0
	.byte		VOL   , 85*mus_rg_sekaikan_mvl/mxv
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
mus_rg_sekaikan_6_000:
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
	 .word	mus_rg_sekaikan_6_000
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
	 .word	mus_rg_sekaikan_6_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_sekaikan:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_sekaikan_pri	@ Priority
	.byte	mus_rg_sekaikan_rev	@ Reverb.

	.word	mus_rg_sekaikan_grp

	.word	mus_rg_sekaikan_1
	.word	mus_rg_sekaikan_2
	.word	mus_rg_sekaikan_3
	.word	mus_rg_sekaikan_4
	.word	mus_rg_sekaikan_5
	.word	mus_rg_sekaikan_6

	.end
