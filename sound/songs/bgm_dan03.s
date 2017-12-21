	.include "MPlayDef.s"

	.equ	bgm_dan03_grp, voicegroup_867E314
	.equ	bgm_dan03_pri, 0
	.equ	bgm_dan03_rev, reverb_set+50
	.equ	bgm_dan03_mvl, 127
	.equ	bgm_dan03_key, 0
	.equ	bgm_dan03_tbs, 1
	.equ	bgm_dan03_exg, 0
	.equ	bgm_dan03_cmp, 1

	.section .rodata
	.global	bgm_dan03
	.align	2

@********************** Track  1 **********************@

bgm_dan03_1:
	.byte	KEYSH , bgm_dan03_key+0
	.byte	TEMPO , 100*bgm_dan03_tbs/2
	.byte	W24
bgm_dan03_1_B1:
	.byte		VOICE , 46
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		N08   , Ds4 , v096
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		N72   , As4 
	.byte	W96
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		N72   , An4 
	.byte	W96
	.byte		VOICE , 14
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W48
	.byte		VOICE , 46
	.byte		N08   , As3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 , v068
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 , v072
	.byte	W08
	.byte		        Cs5 , v076
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 , v080
	.byte	W08
	.byte		        Cs5 , v084
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 , v088
	.byte	W08
	.byte		        Cs5 , v092
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 , v096
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Cn6 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Ds4 , v084
	.byte	W08
	.byte		        An4 , v076
	.byte	W08
	.byte		        Ds4 , v064
	.byte	W08
	.byte		        Fs4 , v052
	.byte	W08
	.byte		        An4 , v044
	.byte	W08
	.byte		        Fs4 , v032
	.byte	W08
	.byte		        Ds4 , v024
	.byte	W08
	.byte		        An4 , v016
	.byte	W08
	.byte		VOICE , 48
	.byte		N04   , Fs3 , v068
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		N44   , As4 
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	GOTO
	 .word	bgm_dan03_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_dan03_2:
	.byte	KEYSH , bgm_dan03_key+0
	.byte	W24
bgm_dan03_2_B1:
	.byte		VOICE , 58
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		N84   , Ds1 , v127
	.byte	W84
	.byte		N12   , As1 
	.byte	W12
	.byte		N44   , Ds1 
	.byte	W48
	.byte		N16   , Gn1 
	.byte	W16
	.byte		        Fn1 
	.byte	W16
	.byte		        Gn1 
	.byte	W16
	.byte		N84   , An1 
	.byte	W84
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N44   , An1 
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		        Gn1 
	.byte	W16
	.byte		        An1 
	.byte	W16
	.byte		N12   , Gs1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N24   , Cn2 
	.byte	W24
	.byte		TIE   , Cs2 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N16   
	.byte	W16
	.byte		        Bn1 
	.byte	W16
	.byte		        Gs1 
	.byte	W16
	.byte		N92   , Gn1 
	.byte	W96
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N44   , As1 
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		        Gs1 
	.byte	W16
	.byte		        Fn1 
	.byte	W16
	.byte	GOTO
	 .word	bgm_dan03_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_dan03_3:
	.byte	KEYSH , bgm_dan03_key+0
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+18
	.byte		N04   , As3 , v068
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
bgm_dan03_3_B1:
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+18
	.byte		TIE   , Dn5 , v068
	.byte	W24
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		VOL   , 75*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        71*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        66*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        61*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        57*bgm_dan03_mvl/mxv
	.byte	W16
bgm_dan03_3_000:
	.byte		VOL   , 52*bgm_dan03_mvl/mxv
	.byte	W16
	.byte		        57*bgm_dan03_mvl/mxv
	.byte	W16
	.byte		        62*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        67*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        69*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        73*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        74*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        80*bgm_dan03_mvl/mxv
	.byte	W16
	.byte	PEND
	.byte		EOT   , Dn5 
	.byte		TIE   , Cs5 , v068
	.byte	W32
	.byte		VOL   , 75*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        71*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        66*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        61*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        57*bgm_dan03_mvl/mxv
	.byte	W16
	.byte	PATT
	 .word	bgm_dan03_3_000
	.byte		EOT   , Cs5 
	.byte		N12   , Gs4 , v088
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W48
bgm_dan03_3_001:
	.byte		TIE   , As4 , v068
	.byte	W32
	.byte		VOL   , 75*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        71*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        66*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        61*bgm_dan03_mvl/mxv
	.byte	W12
	.byte		        57*bgm_dan03_mvl/mxv
	.byte	W16
	.byte	PEND
	.byte	PATT
	 .word	bgm_dan03_3_000
	.byte		EOT   , As4 
	.byte	PATT
	 .word	bgm_dan03_3_001
	.byte	PATT
	 .word	bgm_dan03_3_000
	.byte		EOT   , As4 
bgm_dan03_3_002:
	.byte		N12   , Ds4 , v088
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte		N12   
	.byte	W96
	.byte	PATT
	 .word	bgm_dan03_3_002
	.byte		N12   , Ds4 , v088
	.byte	W96
	.byte		        Dn4 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Cs4 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Cn4 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N44   , Ds4 
	.byte	W48
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N04   , As3 , v068
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte	GOTO
	 .word	bgm_dan03_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_dan03_4:
	.byte	KEYSH , bgm_dan03_key+0
	.byte		BENDR , 38
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte	W24
bgm_dan03_4_B1:
	.byte		VOICE , 80
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N92   , As3 , v060
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 76*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        70*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        64*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        55*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        44*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		        27*bgm_dan03_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte		VOICE , 4
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N06   , Ds6 , v052
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N92   , An3 , v060
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 76*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        70*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        64*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        55*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        44*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		        27*bgm_dan03_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte		VOICE , 4
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N06   , Ds6 , v052
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N06   , Cn4 , v060
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn4 , v040
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn4 , v052
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn4 , v060
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		VOICE , 4
	.byte		PAN   , c_v-1
	.byte		N06   , Ds6 , v052
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Cs6 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N06   , As5 , v040
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N06   , En5 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N06   , Cs6 , v032
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N06   , Gs5 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N08   , As4 
	.byte	W08
	.byte		N06   , As5 , v020
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Cs6 , v012
	.byte	W16
	.byte	W48
	.byte		VOICE , 80
	.byte		VOL   , 44*bgm_dan03_mvl/mxv
	.byte		N48   , Gs3 , v072
	.byte	W08
	.byte		VOL   , 50*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        59*bgm_dan03_mvl/mxv
	.byte		MOD   , 7
	.byte	W08
	.byte		VOL   , 68*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        73*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        80*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N96   , Gn3 , v060
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 76*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        70*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        64*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        55*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        44*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		        27*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan03_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn3 , v040
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gn3 , v052
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gn3 , v060
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gn3 , v072
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N12   , As3 , v060
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W96
	.byte		        Cn4 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W96
	.byte		        Gs3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Gn3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Fs3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N06   , As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte	GOTO
	 .word	bgm_dan03_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_dan03_5:
	.byte	KEYSH , bgm_dan03_key+0
	.byte		BENDR , 38
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte	W24
bgm_dan03_5_B1:
	.byte		VOICE , 82
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N12   , Gn3 , v060
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 76*bgm_dan03_mvl/mxv
	.byte		N12   
	.byte	W09
	.byte		VOL   , 70*bgm_dan03_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W06
	.byte		VOL   , 64*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W03
	.byte		VOL   , 55*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        44*bgm_dan03_mvl/mxv
	.byte		N09   
	.byte	W06
	.byte		VOL   , 27*bgm_dan03_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte		VOICE , 5
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		N06   , Dn6 , v052
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		N04   , Dn6 
	.byte	W04
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		N12   , Ds3 , v060
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 76*bgm_dan03_mvl/mxv
	.byte		N12   
	.byte	W09
	.byte		VOL   , 70*bgm_dan03_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W06
	.byte		VOL   , 64*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W03
	.byte		VOL   , 55*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        44*bgm_dan03_mvl/mxv
	.byte		N09   
	.byte	W06
	.byte		VOL   , 27*bgm_dan03_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte		VOICE , 5
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		N06   , Cs6 , v052
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		N04   , Cs6 
	.byte	W04
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		N06   , Gs3 , v060
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs3 , v040
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs3 , v052
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs3 , v060
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		N06   , Cn6 , v052
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Cn6 
	.byte	W04
	.byte		PAN   , c_v+48
	.byte	W04
	.byte		N06   , As5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Cs6 , v040
	.byte	W08
	.byte		        Gs5 
	.byte	W04
	.byte		PAN   , c_v-1
	.byte	W04
	.byte		N06   , As4 
	.byte	W04
	.byte		PAN   , c_v+48
	.byte	W04
	.byte		N06   , As5 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		N06   , En5 
	.byte	W04
	.byte		PAN   , c_v+48
	.byte	W04
	.byte		N06   , Cs6 , v020
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        As5 , v012
	.byte	W12
	.byte	W48
	.byte		VOICE , 82
	.byte		VOL   , 44*bgm_dan03_mvl/mxv
	.byte		N12   , En3 , v072
	.byte	W08
	.byte		VOL   , 50*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		VOICE , 83
	.byte		N12   
	.byte	W04
	.byte		VOL   , 59*bgm_dan03_mvl/mxv
	.byte		MOD   , 7
	.byte	W08
	.byte		VOL   , 68*bgm_dan03_mvl/mxv
	.byte		N12   
	.byte	W08
	.byte		VOL   , 73*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		N12   
	.byte	W04
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , En3 , v060
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		VOL   , 76*bgm_dan03_mvl/mxv
	.byte		N12   
	.byte	W09
	.byte		VOL   , 70*bgm_dan03_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W06
	.byte		VOL   , 64*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W03
	.byte		VOL   , 55*bgm_dan03_mvl/mxv
	.byte	W09
	.byte		        44*bgm_dan03_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 27*bgm_dan03_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , En3 , v040
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        En3 , v052
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        En3 , v060
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        En3 , v072
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N12   , Gn3 , v060
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W96
	.byte		        Gs3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W96
	.byte		        Fn3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , En3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Ds3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N06   , Fn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte	GOTO
	 .word	bgm_dan03_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_dan03_6:
	.byte	KEYSH , bgm_dan03_key+0
	.byte	W24
bgm_dan03_6_B1:
	.byte		VOICE , 46
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+12
	.byte		BEND  , c_v+0
	.byte		N08   , As3 , v088
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Ds3 , v096
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N48   , As3 
	.byte	W48
	.byte		N08   , An3 , v088
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Cs3 , v096
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N48   , An3 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		VOICE , 60
	.byte		VOL   , 45*bgm_dan03_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , As2 , v108
	.byte	W08
	.byte		VOL   , 52*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        61*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        69*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        74*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		        80*bgm_dan03_mvl/mxv
	.byte	W08
	.byte		N12   , As2 , v072
	.byte	W24
	.byte		        As2 , v084
	.byte	W24
	.byte		        As2 , v096
	.byte	W24
	.byte		N24   , As2 , v108
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W36
	.byte		VOICE , 46
	.byte		BEND  , c_v-5
	.byte		N08   , Ds5 , v052
	.byte	W08
	.byte		        Dn5 , v056
	.byte	W08
	.byte		        Gn4 , v072
	.byte	W08
	.byte		        Ds4 , v084
	.byte	W08
	.byte		        Cn4 , v072
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        Ds4 , v052
	.byte	W08
	.byte		N04   , Dn4 , v040
	.byte	W04
	.byte		VOICE , 60
	.byte		BEND  , c_v+0
	.byte		N12   , Fn2 , v108
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W36
	.byte		VOICE , 46
	.byte		BEND  , c_v-5
	.byte		N08   , Ds5 , v052
	.byte	W08
	.byte		        Dn5 , v060
	.byte	W08
	.byte		        Cn5 , v072
	.byte	W08
	.byte		        Gs4 , v084
	.byte	W08
	.byte		        Fn4 , v072
	.byte	W08
	.byte		        Gn4 , v060
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W08
	.byte		N04   , Gn4 , v040
	.byte	W04
	.byte		VOICE , 60
	.byte		BEND  , c_v+0
	.byte		N12   , Bn2 , v108
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , As2 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , An2 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	W96
	.byte	GOTO
	 .word	bgm_dan03_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_dan03_7:
	.byte	KEYSH , bgm_dan03_key+0
	.byte		PAN   , c_v-8
	.byte	W24
bgm_dan03_7_B1:
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W80
	.byte		N08   , An1 , v120
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , Gs1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        Gn1 , v112
	.byte	W08
	.byte		N12   , Gs1 , v120
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte	W96
	.byte	W32
	.byte		N08   , Cs2 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   , Cs2 , v127
	.byte	W16
	.byte		        Bn1 
	.byte	W16
	.byte		        Gs1 
	.byte	W16
	.byte		N15   , Gn1 
	.byte	W96
	.byte	W96
	.byte		N12   , Cn2 
	.byte	W32
	.byte		N08   , Cn2 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , Cn2 , v127
	.byte	W32
	.byte		N08   , Cn2 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , Cn2 , v127
	.byte	W96
	.byte		        Fn1 
	.byte	W32
	.byte		N08   , Fn1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , Fn1 , v127
	.byte	W32
	.byte		N08   , Fn1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , Fn1 , v127
	.byte	W96
	.byte		        Bn1 
	.byte	W32
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , Bn1 , v127
	.byte	W32
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , As1 , v127
	.byte	W32
	.byte		N08   , As1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , As1 , v127
	.byte	W32
	.byte		N08   , As1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , An1 , v127
	.byte	W32
	.byte		N08   , An1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , An1 , v127
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        An1 , v112
	.byte	W08
	.byte		N24   , As1 , v127
	.byte	W48
	.byte		N24   
	.byte	W48
	.byte	GOTO
	 .word	bgm_dan03_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_dan03_8:
	.byte	KEYSH , bgm_dan03_key+0
	.byte	W24
bgm_dan03_8_B1:
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte		N84   , Ds1 , v052
	.byte	W84
	.byte		N12   , As1 
	.byte	W12
	.byte		N44   , Ds1 
	.byte	W48
	.byte		N16   , Gn1 
	.byte	W16
	.byte		        Fn1 
	.byte	W16
	.byte		        Gn1 
	.byte	W16
	.byte		N84   , An1 
	.byte	W84
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N44   , An1 
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		        Gn1 
	.byte	W16
	.byte		        An1 
	.byte	W16
	.byte		N12   , Gs1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N24   , Cn2 
	.byte	W24
	.byte		TIE   , Cs2 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N16   
	.byte	W16
	.byte		        Bn1 
	.byte	W16
	.byte		        Gs1 
	.byte	W16
	.byte		N92   , Gn1 
	.byte	W96
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		VOICE , 88
	.byte		N12   , Cn2 , v080
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W96
	.byte		        Fn1 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W96
	.byte		        Bn1 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , As1 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , An1 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOICE , 81
	.byte		N44   , As1 , v052
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		        Gs1 
	.byte	W16
	.byte		        Fn1 
	.byte	W16
	.byte	GOTO
	 .word	bgm_dan03_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_dan03_9:
	.byte	KEYSH , bgm_dan03_key+0
	.byte	W24
bgm_dan03_9_B1:
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_dan03_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W64
	.byte		        39*bgm_dan03_mvl/mxv
	.byte		N32   , An2 , v064
	.byte	W04
	.byte		VOL   , 44*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		        49*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		        54*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		        59*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		        65*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		        72*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dan03_mvl/mxv
	.byte	W04
	.byte		N96   , Bn2 , v100
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_dan03_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_dan03:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_dan03_pri	@ Priority
	.byte	bgm_dan03_rev	@ Reverb.

	.word	bgm_dan03_grp

	.word	bgm_dan03_1
	.word	bgm_dan03_2
	.word	bgm_dan03_3
	.word	bgm_dan03_4
	.word	bgm_dan03_5
	.word	bgm_dan03_6
	.word	bgm_dan03_7
	.word	bgm_dan03_8
	.word	bgm_dan03_9

	.end
