	.include "MPlayDef.s"

	.equ	bgm_me_battle_points_grp, voicegroup_869557C
	.equ	bgm_me_battle_points_pri, 5
	.equ	bgm_me_battle_points_rev, reverb_set+50
	.equ	bgm_me_battle_points_mvl, 127
	.equ	bgm_me_battle_points_key, 0
	.equ	bgm_me_battle_points_tbs, 1
	.equ	bgm_me_battle_points_exg, 0
	.equ	bgm_me_battle_points_cmp, 1

	.section .rodata
	.global	bgm_me_battle_points
	.align	2

@********************** Track  1 **********************@

bgm_me_battle_points_1:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte	TEMPO , 122*bgm_me_battle_points_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*bgm_me_battle_points_mvl/mxv
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
	.byte	TEMPO , 118*bgm_me_battle_points_tbs/2
	.byte		MOD   , 4
	.byte		N32   , En5 
	.byte	W12
	.byte		VOL   , 79*bgm_me_battle_points_mvl/mxv
	.byte	W03
	.byte	TEMPO , 114*bgm_me_battle_points_tbs/2
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        56*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte	TEMPO , 106*bgm_me_battle_points_tbs/2
	.byte		        90*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_2:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 45*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_3:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 87
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 71*bgm_me_battle_points_mvl/mxv
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
	.byte		VOL   , 61*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 52*bgm_me_battle_points_mvl/mxv
	.byte	W12
	.byte		        42*bgm_me_battle_points_mvl/mxv
	.byte	W12
	.byte		        71*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , An1 
	.byte	W12
	.byte		VOL   , 60*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 71*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , Fs1 
	.byte	W12
	.byte		VOL   , 60*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 71*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 1
	.byte		N36   , En1 
	.byte	W12
	.byte		VOL   , 60*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 50*bgm_me_battle_points_mvl/mxv
	.byte	W12
	.byte		        71*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_4:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+48
	.byte		VOL   , 68*bgm_me_battle_points_mvl/mxv
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
	.byte		VOL   , 56*bgm_me_battle_points_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        34*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        66*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_5:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 79*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_6:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 51
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_me_battle_points_mvl/mxv
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
	.byte		VOL   , 22*bgm_me_battle_points_mvl/mxv
	.byte	W12
	.byte		MOD   , 1
	.byte		VOL   , 45*bgm_me_battle_points_mvl/mxv
	.byte		N24   , Fs3 , v084
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 22*bgm_me_battle_points_mvl/mxv
	.byte	W12
	.byte		MOD   , 1
	.byte		VOL   , 45*bgm_me_battle_points_mvl/mxv
	.byte		N32   , Gs2 , v088
	.byte	W12
	.byte		VOL   , 34*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        11*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        45*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_7:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*bgm_me_battle_points_mvl/mxv
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
	.byte		VOL   , 28*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 25*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		        21*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		        15*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		VOL   , 34*bgm_me_battle_points_mvl/mxv
	.byte		N24   , Bn3 , v096
	.byte	W08
	.byte		VOL   , 30*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 26*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		        21*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		        14*bgm_me_battle_points_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		VOL   , 34*bgm_me_battle_points_mvl/mxv
	.byte		N32   , En3 , v100
	.byte	W12
	.byte		VOL   , 22*bgm_me_battle_points_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 17*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        11*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        6*bgm_me_battle_points_mvl/mxv
	.byte	W06
	.byte		        34*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_8:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 86*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points_9:
	.byte	KEYSH , bgm_me_battle_points_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*bgm_me_battle_points_mvl/mxv
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

bgm_me_battle_points:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_me_battle_points_pri	@ Priority
	.byte	bgm_me_battle_points_rev	@ Reverb.

	.word	bgm_me_battle_points_grp

	.word	bgm_me_battle_points_1
	.word	bgm_me_battle_points_2
	.word	bgm_me_battle_points_3
	.word	bgm_me_battle_points_4
	.word	bgm_me_battle_points_5
	.word	bgm_me_battle_points_6
	.word	bgm_me_battle_points_7
	.word	bgm_me_battle_points_8
	.word	bgm_me_battle_points_9

	.end
