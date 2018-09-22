	.include "MPlayDef.s"

	.equ	mus_me_tore_eye_grp, voicegroup105
	.equ	mus_me_tore_eye_pri, 5
	.equ	mus_me_tore_eye_rev, reverb_set+50
	.equ	mus_me_tore_eye_mvl, 127
	.equ	mus_me_tore_eye_key, 0
	.equ	mus_me_tore_eye_tbs, 1
	.equ	mus_me_tore_eye_exg, 0
	.equ	mus_me_tore_eye_cmp, 1

	.section .rodata
	.global	mus_me_tore_eye
	.align	2

@********************** Track  1 **********************@

mus_me_tore_eye_1:
	.byte	KEYSH , mus_me_tore_eye_key+0
	.byte	TEMPO , 96*mus_me_tore_eye_tbs/2
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*mus_me_tore_eye_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		N02   , Fs5 , v100
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		        Gs5 
	.byte	W02
	.byte		N04   , An5 
	.byte	W06
	.byte	W02
	.byte		N01   , Dn6 
	.byte	W04
	.byte		N04   , An5 
	.byte	W04
	.byte		N02   , Dn6 
	.byte	W04
	.byte		        En6 
	.byte	W04
	.byte		N04   , Fs6 
	.byte	W04
	.byte		        Fs6 , v052
	.byte	W02
	.byte	W02
	.byte		        Fs6 , v016
	.byte	W22
	.byte	FINE

@********************** Track  2 **********************@

mus_me_tore_eye_2:
	.byte	KEYSH , mus_me_tore_eye_key+0
	.byte		VOICE , 82
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_me_tore_eye_mvl/mxv
	.byte	W12
	.byte		N02   , An3 , v100
	.byte	W02
	.byte		        Fs3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Dn3 
	.byte	W06
	.byte	W02
	.byte		N01   , An2 
	.byte	W04
	.byte		N02   , Fs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W02
	.byte		MOD   , 8
	.byte	W02
	.byte		N02   
	.byte	W04
	.byte		        Dn2 , v096
	.byte	W04
	.byte		        Dn2 , v032
	.byte	W02
	.byte	W24
	.byte		MOD   , 1
	.byte	FINE

@********************** Track  3 **********************@

mus_me_tore_eye_3:
	.byte	KEYSH , mus_me_tore_eye_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 51
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 34*mus_me_tore_eye_mvl/mxv
	.byte		MOD   , 4
	.byte		PAN   , c_v-62
	.byte	W12
	.byte		N02   , Cs4 , v100
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		N04   , Gn4 
	.byte	W06
	.byte	W02
	.byte		N01   , An4 
	.byte	W04
	.byte		N04   , Fs4 
	.byte	W04
	.byte		N02   , Dn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		N04   , An4 , v096
	.byte	W04
	.byte		        An4 , v052
	.byte	W02
	.byte	W02
	.byte		        An4 , v016
	.byte	W22
	.byte	FINE

@********************** Track  4 **********************@

mus_me_tore_eye_4:
	.byte	KEYSH , mus_me_tore_eye_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 34*mus_me_tore_eye_mvl/mxv
	.byte		MOD   , 2
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N02   , Fs4 , v100
	.byte	W02
	.byte		        Gn4 
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		N04   , An4 
	.byte	W06
	.byte	W02
	.byte		N01   , Dn5 
	.byte	W04
	.byte		N04   , An4 
	.byte	W04
	.byte		N02   , Dn5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		N04   , Fs5 
	.byte	W04
	.byte		        Fs5 , v052
	.byte	W02
	.byte	W02
	.byte		        Fs5 , v016
	.byte	W22
	.byte	FINE

@********************** Track  5 **********************@

mus_me_tore_eye_5:
	.byte	KEYSH , mus_me_tore_eye_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 86*mus_me_tore_eye_mvl/mxv
	.byte	W12
	.byte	W06
	.byte		N04   , En3 , v100
	.byte	W06
	.byte	W02
	.byte		N02   , Dn3 
	.byte	W04
	.byte		N04   , Bn4 , v048
	.byte	W04
	.byte		        Gs2 , v060
	.byte	W04
	.byte		        Gs2 , v040
	.byte	W04
	.byte		        Fs2 , v068
	.byte	W04
	.byte		N02   , Fs2 , v044
	.byte	W02
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

mus_me_tore_eye:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_tore_eye_pri	@ Priority
	.byte	mus_me_tore_eye_rev	@ Reverb.

	.word	mus_me_tore_eye_grp

	.word	mus_me_tore_eye_1
	.word	mus_me_tore_eye_2
	.word	mus_me_tore_eye_3
	.word	mus_me_tore_eye_4
	.word	mus_me_tore_eye_5

	.end
