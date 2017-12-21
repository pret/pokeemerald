	.include "MPlayDef.s"

	.equ	bgm_hideri_grp, voicegroup_8690A7C
	.equ	bgm_hideri_pri, 0
	.equ	bgm_hideri_rev, reverb_set+50
	.equ	bgm_hideri_mvl, 127
	.equ	bgm_hideri_key, 0
	.equ	bgm_hideri_tbs, 1
	.equ	bgm_hideri_exg, 0
	.equ	bgm_hideri_cmp, 1

	.section .rodata
	.global	bgm_hideri
	.align	2

@********************** Track  1 **********************@

bgm_hideri_1:
	.byte	KEYSH , bgm_hideri_key+0
bgm_hideri_1_B1:
	.byte	TEMPO , 78*bgm_hideri_tbs/2
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 39*bgm_hideri_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N03   , Ds6 , v112
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Ds6 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
bgm_hideri_1_000:
	.byte		N03   , Ds6 , v096
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Ds6 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte	PEND
bgm_hideri_1_001:
	.byte		N03   , Fn6 , v096
	.byte	W12
	.byte		        Gs5 , v064
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_1_001
	.byte	PATT
	 .word	bgm_hideri_1_000
	.byte	PATT
	 .word	bgm_hideri_1_000
	.byte	PATT
	 .word	bgm_hideri_1_001
	.byte	PATT
	 .word	bgm_hideri_1_001
bgm_hideri_1_002:
	.byte		N03   , Ds6 , v096
	.byte	W09
	.byte		        Ds6 , v064
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        An5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Ds6 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        An5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_1_002
bgm_hideri_1_003:
	.byte		N03   , Fn6 , v096
	.byte	W09
	.byte		        Fn6 , v064
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fn6 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_1_003
	.byte	PATT
	 .word	bgm_hideri_1_002
	.byte	PATT
	 .word	bgm_hideri_1_002
	.byte	PATT
	 .word	bgm_hideri_1_003
	.byte	PATT
	 .word	bgm_hideri_1_003
	.byte	GOTO
	 .word	bgm_hideri_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_hideri_2:
	.byte	KEYSH , bgm_hideri_key+0
bgm_hideri_2_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 39*bgm_hideri_mvl/mxv
	.byte		N03   , Ds6 , v112
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Ds6 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
bgm_hideri_2_000:
	.byte		N03   , Ds6 , v096
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Ds6 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte	PEND
bgm_hideri_2_001:
	.byte		N03   , Fn6 , v096
	.byte	W12
	.byte		        Gs5 , v064
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_2_001
	.byte		BEND  , c_v-2
	.byte		N03   , Ds6 , v096
	.byte	W12
	.byte		        Fs5 , v064
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Ds6 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte	PATT
	 .word	bgm_hideri_2_000
	.byte	PATT
	 .word	bgm_hideri_2_001
	.byte	PATT
	 .word	bgm_hideri_2_001
bgm_hideri_2_002:
	.byte		N03   , Ds6 , v096
	.byte	W09
	.byte		        Ds6 , v064
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        An5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Ds6 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        An5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_2_002
bgm_hideri_2_003:
	.byte		N03   , Fn6 , v096
	.byte	W09
	.byte		        Fn6 , v064
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fn6 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_2_003
bgm_hideri_2_004:
	.byte	W02
	.byte		N03   , Ds6 , v096
	.byte	W09
	.byte		        Ds6 , v064
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        An5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Ds6 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        An5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fs5 
	.byte	W09
	.byte		N03   
	.byte	W01
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_2_004
	.byte	W02
	.byte		N03   , Fn6 , v096
	.byte	W09
	.byte		        Fn6 , v064
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fn6 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W01
	.byte	W02
	.byte		        Fn6 , v096
	.byte	W09
	.byte		        Fn6 , v064
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Fn6 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Bn5 
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		        Gs5 
	.byte	W10
	.byte	GOTO
	 .word	bgm_hideri_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_hideri_3:
	.byte	KEYSH , bgm_hideri_key+0
bgm_hideri_3_B1:
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*bgm_hideri_mvl/mxv
	.byte		N92   , Dn1 , v064
	.byte	W48
	.byte		MOD   , 6
	.byte	W24
	.byte		        6
	.byte	W20
	.byte		N02   , Cn1 
	.byte	W02
	.byte		        Cs1 
	.byte	W02
bgm_hideri_3_000:
	.byte		MOD   , 0
	.byte		N92   , Dn1 , v064
	.byte	W48
	.byte		MOD   , 6
	.byte	W24
	.byte		        6
	.byte	W20
	.byte		        0
	.byte		N04   , Ds1 
	.byte	W04
	.byte	PEND
bgm_hideri_3_001:
	.byte		MOD   , 0
	.byte		N92   , En1 , v064
	.byte	W48
	.byte		MOD   , 6
	.byte	W24
	.byte		        6
	.byte	W20
	.byte		        0
	.byte		N02   , Fs1 
	.byte	W02
	.byte		        Fn1 
	.byte	W02
	.byte	PEND
bgm_hideri_3_002:
	.byte		MOD   , 0
	.byte		N44   , En1 , v064
	.byte	W24
	.byte		MOD   , 6
	.byte	W20
	.byte		        0
	.byte		N02   , Dn1 
	.byte	W02
	.byte		        Ds1 
	.byte	W02
	.byte		MOD   , 0
	.byte		N48   , En1 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte	PEND
bgm_hideri_3_003:
	.byte		MOD   , 0
	.byte		N92   , Dn1 , v064
	.byte	W48
	.byte		MOD   , 6
	.byte	W24
	.byte		        6
	.byte	W20
	.byte		N02   , Cn1 
	.byte	W02
	.byte		        Cs1 
	.byte	W02
	.byte	PEND
	.byte	PATT
	 .word	bgm_hideri_3_000
	.byte	PATT
	 .word	bgm_hideri_3_001
	.byte	PATT
	 .word	bgm_hideri_3_002
	.byte	PATT
	 .word	bgm_hideri_3_003
	.byte	PATT
	 .word	bgm_hideri_3_000
	.byte	PATT
	 .word	bgm_hideri_3_001
	.byte	PATT
	 .word	bgm_hideri_3_002
	.byte	PATT
	 .word	bgm_hideri_3_003
	.byte	PATT
	 .word	bgm_hideri_3_000
	.byte	PATT
	 .word	bgm_hideri_3_001
	.byte	PATT
	 .word	bgm_hideri_3_002
	.byte	GOTO
	 .word	bgm_hideri_3_B1
	.byte		MOD   , 0
	.byte	FINE

@******************************************************@
	.align	2

bgm_hideri:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_hideri_pri	@ Priority
	.byte	bgm_hideri_rev	@ Reverb.

	.word	bgm_hideri_grp

	.word	bgm_hideri_1
	.word	bgm_hideri_2
	.word	bgm_hideri_3

	.end
