	.include "MPlayDef.s"

	.equ	mus_me_pointget_grp, voicegroup103
	.equ	mus_me_pointget_pri, 5
	.equ	mus_me_pointget_rev, reverb_set+50
	.equ	mus_me_pointget_mvl, 127
	.equ	mus_me_pointget_key, 0
	.equ	mus_me_pointget_tbs, 1
	.equ	mus_me_pointget_exg, 0
	.equ	mus_me_pointget_cmp, 1

	.section .rodata
	.global	mus_me_pointget
	.align	2

@********************** Track  1 **********************@

mus_me_pointget_1:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte	TEMPO , 122*mus_me_pointget_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*mus_me_pointget_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		N04   , Bn3 , v100
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Bn4 
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte	TEMPO , 118*mus_me_pointget_tbs/2
	.byte		MOD   , 4
	.byte		N32   , En5 
	.byte	W12
	.byte		VOL   , 79*mus_me_pointget_mvl/mxv
	.byte	W03
	.byte	TEMPO , 114*mus_me_pointget_tbs/2
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        56*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte	TEMPO , 106*mus_me_pointget_tbs/2
	.byte		        90*mus_me_pointget_mvl/mxv
	.byte		N02   , En4 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		MOD   , 4
	.byte		N06   
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

mus_me_pointget_2:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 45*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , Bn4 , v100
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , En4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , Fs4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , En4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , Fs4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , Bn4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , En4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , Fs4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , Bn4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , Fs5 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , Ds5 
	.byte	W08
	.byte		MOD   , 4
	.byte		PAN   , c_v-32
	.byte		N04   , Bn4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , En4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , Fs4 
	.byte	W08
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N04   , Bn4 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   , An4 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   , Fs4 
	.byte	W08
	.byte		MOD   , 3
	.byte		PAN   , c_v-32
	.byte	W24
	.byte	FINE

@********************** Track  3 **********************@

mus_me_pointget_3:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 87
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 71*mus_me_pointget_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N02   , Fs1 , v100
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N48   , Bn1 
	.byte	W12
	.byte		VOL   , 61*mus_me_pointget_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 52*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		        42*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		        71*mus_me_pointget_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , An1 
	.byte	W12
	.byte		VOL   , 60*mus_me_pointget_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 71*mus_me_pointget_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , Fs1 
	.byte	W12
	.byte		VOL   , 60*mus_me_pointget_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 71*mus_me_pointget_mvl/mxv
	.byte		MOD   , 1
	.byte		N36   , En1 
	.byte	W12
	.byte		VOL   , 60*mus_me_pointget_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 50*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		        71*mus_me_pointget_mvl/mxv
	.byte		MOD   , 1
	.byte		N02   , Gs1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , En1 
	.byte	W24
	.byte	FINE

@********************** Track  4 **********************@

mus_me_pointget_4:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+48
	.byte		VOL   , 68*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		N04   , En3 , v100
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        En4 
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		MOD   , 4
	.byte		N32   , Bn4 
	.byte	W12
	.byte		VOL   , 56*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        34*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        66*mus_me_pointget_mvl/mxv
	.byte		N02   , Bn3 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		MOD   , 4
	.byte		N06   
	.byte	W24
	.byte	FINE

@********************** Track  5 **********************@

mus_me_pointget_5:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 79*mus_me_pointget_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N02   , Bn1 , v100
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	W96
	.byte		N32   , En2 
	.byte	W36
	.byte		N02   , Gs2 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , En1 
	.byte	W24
	.byte	FINE

@********************** Track  6 **********************@

mus_me_pointget_6:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 51
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_me_pointget_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W12
	.byte	W12
	.byte		N04   , Fs3 , v088
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 22*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		MOD   , 1
	.byte		VOL   , 45*mus_me_pointget_mvl/mxv
	.byte		N24   , Fs3 , v084
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 22*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		MOD   , 1
	.byte		VOL   , 45*mus_me_pointget_mvl/mxv
	.byte		N32   , Gs2 , v088
	.byte	W12
	.byte		VOL   , 34*mus_me_pointget_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        11*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        45*mus_me_pointget_mvl/mxv
	.byte		MOD   , 1
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , Gs2 , v100
	.byte	W24
	.byte	FINE

@********************** Track  7 **********************@

mus_me_pointget_7:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_me_pointget_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N04   , Bn3 , v100
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W08
	.byte		VOL   , 28*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 25*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		        21*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		        15*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		VOL   , 34*mus_me_pointget_mvl/mxv
	.byte		N24   , Bn3 , v096
	.byte	W08
	.byte		VOL   , 30*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 26*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		        21*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		        14*mus_me_pointget_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		VOL   , 34*mus_me_pointget_mvl/mxv
	.byte		N32   , En3 , v100
	.byte	W12
	.byte		VOL   , 22*mus_me_pointget_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 17*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        11*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        6*mus_me_pointget_mvl/mxv
	.byte	W06
	.byte		        34*mus_me_pointget_mvl/mxv
	.byte		MOD   , 1
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   
	.byte	W24
	.byte	FINE

@********************** Track  8 **********************@

mus_me_pointget_8:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 86*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte	W12
	.byte		N48   , An2 , v100
	.byte	W48
	.byte		N24   , En2 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	FINE

@********************** Track  9 **********************@

mus_me_pointget_9:
	.byte	KEYSH , mus_me_pointget_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_me_pointget_mvl/mxv
	.byte	W12
	.byte		N01   , An3 , v064
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		        An3 , v096
	.byte	W12
	.byte		        An3 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        An3 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N02   , Cn5 
	.byte	W04
	.byte		N01   , An3 , v048
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W02
	.byte		        An3 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N02   , Cn5 , v080
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

mus_me_pointget:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_pointget_pri	@ Priority
	.byte	mus_me_pointget_rev	@ Reverb.

	.word	mus_me_pointget_grp

	.word	mus_me_pointget_1
	.word	mus_me_pointget_2
	.word	mus_me_pointget_3
	.word	mus_me_pointget_4
	.word	mus_me_pointget_5
	.word	mus_me_pointget_6
	.word	mus_me_pointget_7
	.word	mus_me_pointget_8
	.word	mus_me_pointget_9

	.end
