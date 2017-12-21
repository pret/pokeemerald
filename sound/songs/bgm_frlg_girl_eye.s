	.include "MPlayDef.s"

	.equ	bgm_frlg_girl_eye_grp, voicegroup_86A4BF4
	.equ	bgm_frlg_girl_eye_pri, 0
	.equ	bgm_frlg_girl_eye_rev, reverb_set+50
	.equ	bgm_frlg_girl_eye_mvl, 127
	.equ	bgm_frlg_girl_eye_key, 0
	.equ	bgm_frlg_girl_eye_tbs, 1
	.equ	bgm_frlg_girl_eye_exg, 0
	.equ	bgm_frlg_girl_eye_cmp, 1

	.section .rodata
	.global	bgm_frlg_girl_eye
	.align	2

@********************** Track  1 **********************@

bgm_frlg_girl_eye_1:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte	TEMPO , 174*bgm_frlg_girl_eye_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 51*bgm_frlg_girl_eye_mvl/mxv
	.byte		PAN   , c_v-29
	.byte		N18   , En4 , v104
	.byte	W12
	.byte	W24
	.byte		N03   , Cn4 , v127
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
bgm_frlg_girl_eye_1_B1:
bgm_frlg_girl_eye_1_000:
	.byte		N03   , Gn3 , v127
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		N03   , Fs3 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , An3 , v120
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_girl_eye_1_000
	.byte		N03   , Fn3 , v127
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_girl_eye_2:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*bgm_frlg_girl_eye_mvl/mxv
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N72   , Gn5 
	.byte	W72
bgm_frlg_girl_eye_2_B1:
	.byte		VOICE , 24
	.byte		N12   , Gn4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W09
	.byte		N01   
	.byte	W03
	.byte		N24   , Bn4 , v127
	.byte	W06
	.byte		MOD   , 2
	.byte	W18
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W12
	.byte		N12   , Bn4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Gn4 , v096
	.byte	W12
	.byte		N12   , An4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Gn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , En4 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , En4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W09
	.byte		N01   
	.byte	W03
	.byte		N24   , An4 , v127
	.byte	W06
	.byte		MOD   , 2
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W12
	.byte		N12   , Fn4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , En4 , v120
	.byte	W12
	.byte		N12   , En4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Bn3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Fn4 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_girl_eye_3:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte		PAN   , c_v-40
	.byte	W12
	.byte	W36
	.byte		N03   , An4 , v104
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
bgm_frlg_girl_eye_3_B1:
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte		N84   , En4 , v120
	.byte	W09
	.byte		VOL   , 11*bgm_frlg_girl_eye_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_girl_eye_mvl/mxv
	.byte	W09
	.byte		        22*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        39*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte		N84   , Ds4 
	.byte	W09
	.byte		VOL   , 11*bgm_frlg_girl_eye_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_girl_eye_mvl/mxv
	.byte	W09
	.byte		        22*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        39*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte		N84   , En4 
	.byte	W09
	.byte		VOL   , 11*bgm_frlg_girl_eye_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_girl_eye_mvl/mxv
	.byte	W09
	.byte		        22*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        39*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte		N84   , Dn4 
	.byte	W09
	.byte		VOL   , 11*bgm_frlg_girl_eye_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_girl_eye_mvl/mxv
	.byte	W09
	.byte		        22*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte		        39*bgm_frlg_girl_eye_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_girl_eye_4:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 80
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 45*bgm_frlg_girl_eye_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W72
bgm_frlg_girl_eye_4_B1:
	.byte		N06   , Cn2 , v127
	.byte	W24
	.byte		N24   , En1 , v120
	.byte	W24
	.byte		N06   , Cn2 , v127
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N15   , Gn1 , v120
	.byte	W12
	.byte		N06   , Cn2 , v127
	.byte	W24
	.byte		N24   , En1 
	.byte	W24
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N24   , En1 
	.byte	W24
	.byte		N06   , Cn2 , v120
	.byte	W24
	.byte		N24   , Dn1 , v127
	.byte	W24
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_girl_eye_5:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 46*bgm_frlg_girl_eye_mvl/mxv
	.byte		PAN   , c_v+47
	.byte		BEND  , c_v+1
	.byte		N12   , Gn4 , v104
	.byte	W12
	.byte		N72   , Gn5 
	.byte	W72
bgm_frlg_girl_eye_5_B1:
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+0
	.byte		N03   , Cn3 , v120
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
bgm_frlg_girl_eye_5_000:
	.byte		N03   , Cn3 , v127
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_girl_eye_5_000
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_girl_eye_6:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*bgm_frlg_girl_eye_mvl/mxv
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N72   , Gn5 
	.byte	W24
	.byte		VOL   , 41*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        38*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        36*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        34*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        31*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        29*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        25*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        22*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        20*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        17*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        14*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        12*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        9*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        7*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        5*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
	.byte		        2*bgm_frlg_girl_eye_mvl/mxv
	.byte	W03
bgm_frlg_girl_eye_6_B1:
	.byte		VOL   , 0*bgm_frlg_girl_eye_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_girl_eye_7:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 28*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte	W72
bgm_frlg_girl_eye_7_B1:
bgm_frlg_girl_eye_7_000:
	.byte		N12   , Cn4 , v120
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte	PEND
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Gn3 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_girl_eye_7_000
	.byte		N12   , Cn4 , v120
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Bn3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Gn3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Gn3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Bn3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_frlg_girl_eye_8:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 51*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte	W72
bgm_frlg_girl_eye_8_B1:
bgm_frlg_girl_eye_8_000:
	.byte		N03   , Cn5 , v104
	.byte	W24
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W36
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v112
	.byte	W24
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v076
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_girl_eye_8_000
	.byte		N03   , Cn5 , v112
	.byte	W24
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_frlg_girl_eye_9:
	.byte	KEYSH , bgm_frlg_girl_eye_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+2
	.byte		VOL   , 38*bgm_frlg_girl_eye_mvl/mxv
	.byte	W12
	.byte	W72
bgm_frlg_girl_eye_9_B1:
	.byte	W48
	.byte		N24   , Ds5 , v096
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N24   
	.byte	W48
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_girl_eye_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_girl_eye:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_girl_eye_pri	@ Priority
	.byte	bgm_frlg_girl_eye_rev	@ Reverb.

	.word	bgm_frlg_girl_eye_grp

	.word	bgm_frlg_girl_eye_1
	.word	bgm_frlg_girl_eye_2
	.word	bgm_frlg_girl_eye_3
	.word	bgm_frlg_girl_eye_4
	.word	bgm_frlg_girl_eye_5
	.word	bgm_frlg_girl_eye_6
	.word	bgm_frlg_girl_eye_7
	.word	bgm_frlg_girl_eye_8
	.word	bgm_frlg_girl_eye_9

	.end
