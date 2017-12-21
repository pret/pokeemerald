	.include "MPlayDef.s"

	.equ	bgm_me_wasure_grp, voicegroup_8677B28
	.equ	bgm_me_wasure_pri, 5
	.equ	bgm_me_wasure_rev, reverb_set+50
	.equ	bgm_me_wasure_mvl, 127
	.equ	bgm_me_wasure_key, 0
	.equ	bgm_me_wasure_tbs, 1
	.equ	bgm_me_wasure_exg, 0
	.equ	bgm_me_wasure_cmp, 1

	.section .rodata
	.global	bgm_me_wasure
	.align	2

@********************** Track  1 **********************@

bgm_me_wasure_1:
	.byte	KEYSH , bgm_me_wasure_key+0
	.byte	TEMPO , 150*bgm_me_wasure_tbs/2
	.byte	W12
	.byte		VOICE , 13
	.byte		VOL   , 90*bgm_me_wasure_mvl/mxv
	.byte		N06   , En3 , v068
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Ds5 , v088
	.byte	W09
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , En5 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte	W03
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

bgm_me_wasure_2:
	.byte	KEYSH , bgm_me_wasure_key+0
	.byte	W12
	.byte		VOICE , 13
	.byte		VOL   , 90*bgm_me_wasure_mvl/mxv
	.byte	W03
	.byte		N06   , Gs3 , v068
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W03
	.byte	W03
	.byte		N12   , En5 , v088
	.byte	W09
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , En5 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  3 **********************@

bgm_me_wasure_3:
	.byte	KEYSH , bgm_me_wasure_key+0
	.byte	W12
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		VOICE , 13
	.byte		VOL   , 90*bgm_me_wasure_mvl/mxv
	.byte		PAN   , c_v-48
	.byte	W12
	.byte		N12   , En5 , v012
	.byte	W09
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , En5 
	.byte	W12
	.byte		N12   
	.byte	W15
	.byte	W24
	.byte	FINE

@********************** Track  4 **********************@

bgm_me_wasure_4:
	.byte	KEYSH , bgm_me_wasure_key+0
	.byte	W12
	.byte		BEND  , c_v-2
	.byte	W24
	.byte		VOICE , 13
	.byte		VOL   , 90*bgm_me_wasure_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W24
	.byte		N12   , En5 , v012
	.byte	W09
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , En5 
	.byte	W12
	.byte		N12   
	.byte	W03
	.byte	W24
	.byte	FINE

@********************** Track  5 **********************@

bgm_me_wasure_5:
	.byte	KEYSH , bgm_me_wasure_key+0
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 90*bgm_me_wasure_mvl/mxv
	.byte	W21
	.byte		N12   , En2 , v072
	.byte	W03
	.byte	W56
	.byte	W01
	.byte		        En3 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte	W03
	.byte	W24
	.byte	FINE

@********************** Track  6 **********************@

bgm_me_wasure_6:
	.byte	KEYSH , bgm_me_wasure_key+0
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte	W12
	.byte		VOICE , 85
	.byte		VOL   , 90*bgm_me_wasure_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W24
	.byte		N12   , En2 , v052
	.byte	W60
	.byte		        En3 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

bgm_me_wasure:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_me_wasure_pri	@ Priority
	.byte	bgm_me_wasure_rev	@ Reverb.

	.word	bgm_me_wasure_grp

	.word	bgm_me_wasure_1
	.word	bgm_me_wasure_2
	.word	bgm_me_wasure_3
	.word	bgm_me_wasure_4
	.word	bgm_me_wasure_5
	.word	bgm_me_wasure_6

	.end
