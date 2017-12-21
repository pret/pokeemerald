	.include "MPlayDef.s"

	.equ	bgm_battle_pyramid_summit_grp, voicegroup_8696A70
	.equ	bgm_battle_pyramid_summit_pri, 0
	.equ	bgm_battle_pyramid_summit_rev, reverb_set+50
	.equ	bgm_battle_pyramid_summit_mvl, 127
	.equ	bgm_battle_pyramid_summit_key, 0
	.equ	bgm_battle_pyramid_summit_tbs, 1
	.equ	bgm_battle_pyramid_summit_exg, 0
	.equ	bgm_battle_pyramid_summit_cmp, 1

	.section .rodata
	.global	bgm_battle_pyramid_summit
	.align	2

@********************** Track  1 **********************@

bgm_battle_pyramid_summit_1:
	.byte	KEYSH , bgm_battle_pyramid_summit_key+0
bgm_battle_pyramid_summit_1_B1:
	.byte	TEMPO , 90*bgm_battle_pyramid_summit_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 76*bgm_battle_pyramid_summit_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N06   , Cn3 , v048
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_pyramid_summit_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle_pyramid_summit_2:
	.byte	KEYSH , bgm_battle_pyramid_summit_key+0
bgm_battle_pyramid_summit_2_B1:
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 25*bgm_battle_pyramid_summit_mvl/mxv
	.byte		TIE   , Cn3 , v040
	.byte	W02
	.byte		VOL   , 26*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W10
	.byte		        27*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        28*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        29*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        30*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        31*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        32*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        35*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        41*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        44*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        45*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        49*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        51*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        55*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        61*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        66*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        69*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        70*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        74*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        75*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        76*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        77*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
bgm_battle_pyramid_summit_2_000:
	.byte		VOL   , 25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        26*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W10
	.byte		        27*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        28*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        29*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        30*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        31*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        32*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        35*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        41*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        44*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        45*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        49*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        51*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        55*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        61*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        66*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        69*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        70*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        74*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte		        75*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        76*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W02
	.byte		        77*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_pyramid_summit_2_000
	.byte	PATT
	 .word	bgm_battle_pyramid_summit_2_000
	.byte		EOT   , Cn3 
	.byte	GOTO
	 .word	bgm_battle_pyramid_summit_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle_pyramid_summit_3:
	.byte	KEYSH , bgm_battle_pyramid_summit_key+0
bgm_battle_pyramid_summit_3_B1:
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 37*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N06   , Cn1 , v068
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn3 , v032
	.byte	W12
bgm_battle_pyramid_summit_3_000:
	.byte		N06   , Cn1 , v068
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn3 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_pyramid_summit_3_000
	.byte	PATT
	 .word	bgm_battle_pyramid_summit_3_000
	.byte	GOTO
	 .word	bgm_battle_pyramid_summit_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle_pyramid_summit_4:
	.byte	KEYSH , bgm_battle_pyramid_summit_key+0
bgm_battle_pyramid_summit_4_B1:
	.byte		VOICE , 53
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 50*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N96   , En3 , v044
	.byte	W12
	.byte		VOL   , 37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        32*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        18*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        12*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        7*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        3*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        50*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N96   , Fn3 
	.byte	W12
	.byte		VOL   , 37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        32*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        18*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        12*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        7*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        3*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        50*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N96   , En3 
	.byte	W12
	.byte		VOL   , 37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        32*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        18*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        12*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        7*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        3*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        50*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N96   , Ds3 
	.byte	W12
	.byte		VOL   , 37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        32*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        18*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        12*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        7*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        3*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle_pyramid_summit_4_B1
	.byte		VOL   , 0*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle_pyramid_summit_5:
	.byte	KEYSH , bgm_battle_pyramid_summit_key+0
bgm_battle_pyramid_summit_5_B1:
	.byte		VOICE , 14
	.byte		PAN   , c_v-32
	.byte		VOL   , 75*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N18   , As4 , v020
	.byte	W18
	.byte		N42   , En4 , v048
	.byte	W18
	.byte		VOL   , 62*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        50*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+23
	.byte		N24   , Cn4 
	.byte	W12
	.byte		VOL   , 31*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N30   , Cn5 
	.byte	W12
	.byte		VOL   , 75*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N42   , Fn4 
	.byte	W18
	.byte		VOL   , 62*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        50*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-24
	.byte		N24   , Cn4 
	.byte	W12
	.byte		VOL   , 31*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 50*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N30   , Cn5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 75*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        62*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N36   , En4 
	.byte	W18
	.byte		VOL   , 50*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        38*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        37*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N30   , Cn4 
	.byte	W06
	.byte		PAN   , c_v+23
	.byte	W12
	.byte		VOL   , 31*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N30   , Cn5 
	.byte	W12
	.byte	W06
	.byte		VOL   , 37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		        62*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N30   , Ds4 
	.byte	W18
	.byte		VOL   , 50*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte		        38*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N24   , Cn4 
	.byte	W06
	.byte		VOL   , 37*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-24
	.byte	W12
	.byte		VOL   , 31*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N24   , As4 
	.byte	W06
	.byte		VOL   , 25*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 50*bgm_battle_pyramid_summit_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle_pyramid_summit_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle_pyramid_summit_6:
	.byte	KEYSH , bgm_battle_pyramid_summit_key+0
bgm_battle_pyramid_summit_6_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 25*bgm_battle_pyramid_summit_mvl/mxv
	.byte		N06   , Cn3 , v048
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_pyramid_summit_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

bgm_battle_pyramid_summit_7:
	.byte	KEYSH , bgm_battle_pyramid_summit_key+0
bgm_battle_pyramid_summit_7_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 25*bgm_battle_pyramid_summit_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , Cn4 , v048
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        Fn6 
	.byte	W06
	.byte		        Gs6 
	.byte	W06
	.byte		        Fn6 
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        Fs6 
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_pyramid_summit_7_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle_pyramid_summit:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle_pyramid_summit_pri	@ Priority
	.byte	bgm_battle_pyramid_summit_rev	@ Reverb.

	.word	bgm_battle_pyramid_summit_grp

	.word	bgm_battle_pyramid_summit_1
	.word	bgm_battle_pyramid_summit_2
	.word	bgm_battle_pyramid_summit_3
	.word	bgm_battle_pyramid_summit_4
	.word	bgm_battle_pyramid_summit_5
	.word	bgm_battle_pyramid_summit_6
	.word	bgm_battle_pyramid_summit_7

	.end
