	.include "MPlayDef.s"

	.equ	bgm_me_b_small_grp, voicegroup_8677B28
	.equ	bgm_me_b_small_pri, 5
	.equ	bgm_me_b_small_rev, reverb_set+50
	.equ	bgm_me_b_small_mvl, 127
	.equ	bgm_me_b_small_key, 0
	.equ	bgm_me_b_small_tbs, 1
	.equ	bgm_me_b_small_exg, 0
	.equ	bgm_me_b_small_cmp, 1

	.section .rodata
	.global	bgm_me_b_small
	.align	2

@********************** Track  1 **********************@

bgm_me_b_small_1:
	.byte	KEYSH , bgm_me_b_small_key+0
	.byte	TEMPO , 144*bgm_me_b_small_tbs/2
	.byte	W09
	.byte		VOICE , 56
	.byte		VOL   , 90*bgm_me_b_small_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		N03   , Cs3 , v084
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W03
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

bgm_me_b_small_2:
	.byte	KEYSH , bgm_me_b_small_key+0
	.byte	W24
	.byte		VOICE , 60
	.byte		VOL   , 90*bgm_me_b_small_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Fs2 , v080
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  3 **********************@

bgm_me_b_small_3:
	.byte	KEYSH , bgm_me_b_small_key+0
	.byte	W24
	.byte		VOICE , 47
	.byte		VOL   , 90*bgm_me_b_small_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W48
	.byte		N03   , Ds2 , v120
	.byte	W03
	.byte		        Ds2 , v092
	.byte	W03
	.byte		        Ds2 , v096
	.byte	W03
	.byte		        Ds2 , v100
	.byte	W03
	.byte		N06   , Ds2 , v108
	.byte	W06
	.byte		        Ds2 , v116
	.byte	W06
	.byte		N24   , Fs2 , v120
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  4 **********************@

bgm_me_b_small_4:
	.byte	KEYSH , bgm_me_b_small_key+0
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte	W24
	.byte		VOICE , 90
	.byte		VOL   , 90*bgm_me_b_small_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Fs5 , v040
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  5 **********************@

bgm_me_b_small_5:
	.byte	KEYSH , bgm_me_b_small_key+0
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		VOICE , 83
	.byte		VOL   , 90*bgm_me_b_small_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N06   , Fs3 , v052
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W03
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  6 **********************@

bgm_me_b_small_6:
	.byte	KEYSH , bgm_me_b_small_key+0
	.byte	W24
	.byte		VOICE , 88
	.byte		VOL   , 90*bgm_me_b_small_mvl/mxv
	.byte		N12   , Fs1 , v080
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  7 **********************@

bgm_me_b_small_7:
	.byte	KEYSH , bgm_me_b_small_key+0
	.byte	W24
	.byte		VOICE , 0
	.byte		VOL   , 90*bgm_me_b_small_mvl/mxv
	.byte		N06   , En1 , v100
	.byte		N72   , Bn2 , v092
	.byte	W24
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		        En1 , v084
	.byte	W03
	.byte		        En1 , v092
	.byte	W03
	.byte		N06   , En1 , v096
	.byte	W06
	.byte		        En1 , v108
	.byte	W06
	.byte		N09   , En1 , v100
	.byte		N24   , Bn2 , v092
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

bgm_me_b_small:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_me_b_small_pri	@ Priority
	.byte	bgm_me_b_small_rev	@ Reverb.

	.word	bgm_me_b_small_grp

	.word	bgm_me_b_small_1
	.word	bgm_me_b_small_2
	.word	bgm_me_b_small_3
	.word	bgm_me_b_small_4
	.word	bgm_me_b_small_5
	.word	bgm_me_b_small_6
	.word	bgm_me_b_small_7

	.end
