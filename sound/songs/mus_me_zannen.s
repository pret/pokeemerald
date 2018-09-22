	.include "MPlayDef.s"

	.equ	mus_me_zannen_grp, voicegroup012
	.equ	mus_me_zannen_pri, 5
	.equ	mus_me_zannen_rev, reverb_set+50
	.equ	mus_me_zannen_mvl, 127
	.equ	mus_me_zannen_key, 0
	.equ	mus_me_zannen_tbs, 1
	.equ	mus_me_zannen_exg, 0
	.equ	mus_me_zannen_cmp, 1

	.section .rodata
	.global	mus_me_zannen
	.align	2

@********************** Track  1 **********************@

mus_me_zannen_1:
	.byte	KEYSH , mus_me_zannen_key+0
	.byte	TEMPO , 180*mus_me_zannen_tbs/2
	.byte		VOL   , 90*mus_me_zannen_mvl/mxv
	.byte	W09
	.byte		VOICE , 73
	.byte		PAN   , c_v+1
	.byte		N06   , Dn3 , v088
	.byte	W06
	.byte		        Dn4 
	.byte	W09
	.byte		N03   , As4 
	.byte	W03
	.byte		N09   , Bn4 
	.byte	W09
	.byte		        Bn3 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N09   , An4 
	.byte	W09
	.byte		        An3 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W03
	.byte		N09   , Fs4 
	.byte	W09
	.byte		        Fs3 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W03
	.byte		N60   , Dn4 
	.byte	W09
	.byte		MOD   , 32
	.byte	W21
	.byte		VOL   , 85*mus_me_zannen_mvl/mxv
	.byte	W06
	.byte		        79*mus_me_zannen_mvl/mxv
	.byte	W06
	.byte		        73*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        62*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        45*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        31*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        14*mus_me_zannen_mvl/mxv
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

mus_me_zannen_2:
	.byte	KEYSH , mus_me_zannen_key+0
	.byte		VOL   , 90*mus_me_zannen_mvl/mxv
	.byte	W09
	.byte		VOICE , 73
	.byte		PAN   , c_v+20
	.byte	W03
	.byte		N06   , An3 , v088
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	W03
	.byte		N09   
	.byte	W09
	.byte		        An3 
	.byte	W12
	.byte	W03
	.byte		        Gn4 
	.byte	W09
	.byte		        Gn3 
	.byte	W15
	.byte		        En4 
	.byte	W09
	.byte		        En3 
	.byte	W12
	.byte		N60   , An3 
	.byte	W12
	.byte		MOD   , 32
	.byte	W21
	.byte		VOL   , 85*mus_me_zannen_mvl/mxv
	.byte	W06
	.byte		        79*mus_me_zannen_mvl/mxv
	.byte	W06
	.byte		        73*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        62*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        45*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        31*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        14*mus_me_zannen_mvl/mxv
	.byte	W12
	.byte	FINE

@********************** Track  3 **********************@

mus_me_zannen_3:
	.byte	KEYSH , mus_me_zannen_key+0
	.byte	W24
	.byte		VOICE , 2
	.byte		VOL   , 90*mus_me_zannen_mvl/mxv
	.byte		N09   , Dn2 , v112
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N60   , Dn2 
	.byte	W32
	.byte	W01
	.byte		VOL   , 85*mus_me_zannen_mvl/mxv
	.byte	W06
	.byte		        79*mus_me_zannen_mvl/mxv
	.byte	W06
	.byte		        73*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte	W03
	.byte		        62*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        45*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        31*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		        14*mus_me_zannen_mvl/mxv
	.byte	W12
	.byte	FINE

@********************** Track  4 **********************@

mus_me_zannen_4:
	.byte	KEYSH , mus_me_zannen_key+0
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte	W24
	.byte		VOICE , 90
	.byte		VOL   , 90*mus_me_zannen_mvl/mxv
	.byte		PAN   , c_v-48
	.byte	W03
	.byte		N06   , Bn5 , v052
	.byte	W21
	.byte	W03
	.byte		        An5 
	.byte	W24
	.byte		        Fs5 
	.byte	W24
	.byte		        Dn5 
	.byte	W44
	.byte	W01
	.byte	W24
	.byte	FINE

@********************** Track  5 **********************@

mus_me_zannen_5:
	.byte	KEYSH , mus_me_zannen_key+0
	.byte	W24
	.byte		VOICE , 0
	.byte		VOL   , 90*mus_me_zannen_mvl/mxv
	.byte	W03
	.byte		N03   , En3 , v064
	.byte	W21
	.byte	W03
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W21
	.byte		N03   
	.byte	W03
	.byte		        Dn3 
	.byte	W44
	.byte	W01
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

mus_me_zannen:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_zannen_pri	@ Priority
	.byte	mus_me_zannen_rev	@ Reverb.

	.word	mus_me_zannen_grp

	.word	mus_me_zannen_1
	.word	mus_me_zannen_2
	.word	mus_me_zannen_3
	.word	mus_me_zannen_4
	.word	mus_me_zannen_5

	.end
