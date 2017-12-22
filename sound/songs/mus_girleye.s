	.include "MPlayDef.s"

	.equ	mus_girleye_grp, voicegroup_8683648
	.equ	mus_girleye_pri, 0
	.equ	mus_girleye_rev, reverb_set+50
	.equ	mus_girleye_mvl, 127
	.equ	mus_girleye_key, 0
	.equ	mus_girleye_tbs, 1
	.equ	mus_girleye_exg, 0
	.equ	mus_girleye_cmp, 1

	.section .rodata
	.global	mus_girleye
	.align	2

@********************** Track  1 **********************@

mus_girleye_1:
	.byte	KEYSH , mus_girleye_key+0
	.byte	TEMPO , 90*mus_girleye_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 63*mus_girleye_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		N42   , Ds4 
	.byte	W42
	.byte		PAN   , c_v+0
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
mus_girleye_1_B1:
	.byte		PAN   , c_v-39
	.byte	W06
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		        As3 , v032
	.byte	W12
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W18
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Ds4 , v112
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W12
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W18
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Ds4 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W18
	.byte		        Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Ds4 , v032
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        As3 , v112
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	GOTO
	 .word	mus_girleye_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_girleye_2:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_girleye_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
mus_girleye_2_B1:
	.byte		N03   , Fs5 , v072
	.byte	W03
	.byte		        Gn5 , v080
	.byte	W03
	.byte		        Gs5 , v092
	.byte	W03
	.byte		        An5 , v096
	.byte	W03
	.byte		N36   , As5 , v112
	.byte	W03
	.byte		VOL   , 31*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        32*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        38*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        40*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        45*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        52*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        56*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        53*mus_girleye_mvl/mxv
	.byte	W01
	.byte		        59*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        54*mus_girleye_mvl/mxv
	.byte	W01
	.byte		        63*mus_girleye_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_girleye_mvl/mxv
	.byte		N06   , As5 , v032
	.byte	W06
	.byte		        As5 , v112
	.byte	W06
	.byte		N03   , As5 , v032
	.byte	W03
	.byte		        En6 , v112
	.byte	W03
	.byte		N06   , Ds6 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N03   , An5 , v084
	.byte	W03
	.byte		        As5 
	.byte	W03
	.byte		N06   , Gs5 , v112
	.byte	W06
	.byte		N48   , Gn5 
	.byte	W06
	.byte		VOL   , 29*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        30*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        31*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        31*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        35*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 37*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        40*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        45*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        53*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        57*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        61*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        64*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        66*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_girleye_mvl/mxv
	.byte		N06   , Gn5 , v032
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		N03   , Gn5 , v032
	.byte	W03
	.byte		        En6 , v112
	.byte	W03
	.byte		N06   , Ds6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N03   , Fs5 , v088
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		N06   , Fn5 , v112
	.byte	W06
	.byte	W06
	.byte		N03   , As5 
	.byte	W03
	.byte		VOL   , 43*mus_girleye_mvl/mxv
	.byte		N03   , Cn6 
	.byte	W03
	.byte		VOL   , 39*mus_girleye_mvl/mxv
	.byte		N36   , Cs6 
	.byte	W02
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        29*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 27*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        26*mus_girleye_mvl/mxv
	.byte	W07
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        36*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        40*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        54*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        53*mus_girleye_mvl/mxv
	.byte	W01
	.byte		        63*mus_girleye_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_girleye_mvl/mxv
	.byte		N06   , Cs6 , v032
	.byte	W06
	.byte		        Cs6 , v112
	.byte	W06
	.byte		        Cs6 , v032
	.byte	W06
	.byte		        Ds6 , v112
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Cs6 , v032
	.byte	W06
	.byte		        Fn5 , v112
	.byte	W06
	.byte		N03   , As5 , v084
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte		N36   , Cn6 , v112
	.byte	W02
	.byte		VOL   , 37*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        40*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        44*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        47*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        49*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        53*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        56*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 59*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        60*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        62*mus_girleye_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_girleye_mvl/mxv
	.byte		N06   , Cs6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		N09   , As5 
	.byte	W09
	.byte		N03   , Dn6 , v084
	.byte	W03
	.byte		N06   , Ds6 , v112
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte	GOTO
	 .word	mus_girleye_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_girleye_3:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 35
	.byte		PAN   , c_v+0
	.byte		VOL   , 72*mus_girleye_mvl/mxv
	.byte		BENDR , 12
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		        c_v-7
	.byte		N24   , Ds2 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		        c_v-64
	.byte	W12
mus_girleye_3_B1:
	.byte		BEND  , c_v+0
	.byte		N06   , Gs1 , v112
	.byte	W06
	.byte		        Gs1 , v032
	.byte	W12
	.byte		        Gs1 , v112
	.byte	W06
	.byte		N18   , Ds2 
	.byte	W18
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W03
	.byte		        Ds2 , v032
	.byte	W03
	.byte		N12   , Gs1 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Ds2 , v032
	.byte	W06
	.byte		        Gs1 , v112
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gs1 , v032
	.byte	W12
	.byte		        Gs1 , v112
	.byte	W06
	.byte		N18   , Ds2 
	.byte	W18
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W03
	.byte		        Ds2 , v032
	.byte	W03
	.byte		N12   , Gs1 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        As1 , v032
	.byte	W12
	.byte		        As1 , v112
	.byte	W06
	.byte		N18   , Fn2 
	.byte	W18
	.byte		N03   , As1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W03
	.byte		        Fn2 , v032
	.byte	W03
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Ds2 , v032
	.byte	W12
	.byte		        Ds2 , v112
	.byte	W06
	.byte		N18   , As2 
	.byte	W18
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N06   
	.byte	W08
	.byte		N03   , As2 
	.byte	W04
	.byte		N12   , As1 
	.byte		N03   , As2 , v032
	.byte	W12
	.byte		N06   , Ds2 , v112
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte	GOTO
	 .word	mus_girleye_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_girleye_4:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 51*mus_girleye_mvl/mxv
	.byte	W24
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , As2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
mus_girleye_4_B1:
	.byte	W48
	.byte		VOICE , 1
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_girleye_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_girleye_5:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		VOL   , 27*mus_girleye_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W96
mus_girleye_5_B1:
	.byte		N03   , Fs4 , v072
	.byte	W03
	.byte		        Gn4 , v080
	.byte	W03
	.byte		        Gs4 , v092
	.byte	W03
	.byte		        An4 , v096
	.byte	W03
	.byte		N36   , As4 , v104
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , As4 , v032
	.byte	W06
	.byte		        As4 , v100
	.byte	W06
	.byte		N03   , As4 , v032
	.byte	W03
	.byte		        En5 , v080
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        As4 , v096
	.byte	W06
	.byte		        Gs4 , v100
	.byte	W06
	.byte		N03   , An4 , v084
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N06   , Gs4 , v096
	.byte	W06
	.byte		N48   , Gn4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Gn4 , v032
	.byte	W06
	.byte		        Gn4 , v096
	.byte	W06
	.byte		N03   , Gn4 , v032
	.byte	W03
	.byte		        En5 , v080
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Gn4 , v096
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Fs4 , v088
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fn4 , v096
	.byte	W06
	.byte	W06
	.byte		N03   , As4 , v092
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N36   , Cs5 , v096
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cs5 , v032
	.byte	W06
	.byte		        Cs5 , v096
	.byte	W06
	.byte		        Cs5 , v032
	.byte	W06
	.byte		        Ds5 , v080
	.byte	W06
	.byte		        Cs5 , v096
	.byte	W06
	.byte		        Cs5 , v032
	.byte	W06
	.byte		        Fn4 , v096
	.byte	W06
	.byte		N03   , As4 , v084
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N36   , Cn5 , v096
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cs5 , v100
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		N09   , As4 
	.byte	W09
	.byte		N03   , Dn5 , v080
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_girleye_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_girleye_6:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 48
	.byte		PAN   , c_v+32
	.byte		LFOS  , 44
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		VOL   , 33*mus_girleye_mvl/mxv
	.byte		N66   , Ds5 
	.byte	W02
	.byte		VOL   , 26*mus_girleye_mvl/mxv
	.byte	W01
	.byte		        29*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        24*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        21*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        19*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        13*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        13*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        15*mus_girleye_mvl/mxv
	.byte	W01
	.byte		        15*mus_girleye_mvl/mxv
	.byte	W05
	.byte		        17*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        18*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        19*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        21*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        24*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        26*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        27*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        30*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        31*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 34*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        36*mus_girleye_mvl/mxv
	.byte	W10
	.byte		MOD   , 0
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Cn5 , v096
	.byte	W03
	.byte		        As4 , v092
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 , v088
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 , v080
	.byte	W03
	.byte		        Cs4 , v072
	.byte	W03
mus_girleye_6_B1:
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte		N03   , As3 , v088
	.byte	W03
	.byte		        Cn4 , v100
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		VOL   , 27*mus_girleye_mvl/mxv
	.byte		N48   , Ds4 
	.byte	W02
	.byte		VOL   , 24*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        21*mus_girleye_mvl/mxv
	.byte	W08
	.byte		        22*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        24*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        25*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        28*mus_girleye_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 31*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        36*mus_girleye_mvl/mxv
	.byte	W16
	.byte		MOD   , 0
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOL   , 27*mus_girleye_mvl/mxv
	.byte		N60   , Cn4 
	.byte	W02
	.byte		VOL   , 24*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        21*mus_girleye_mvl/mxv
	.byte	W08
	.byte		        22*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        24*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        25*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        28*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        31*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        36*mus_girleye_mvl/mxv
	.byte	W07
	.byte		MOD   , 5
	.byte	W21
	.byte		        0
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		VOL   , 27*mus_girleye_mvl/mxv
	.byte		N60   , Cs4 
	.byte	W02
	.byte		VOL   , 24*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        21*mus_girleye_mvl/mxv
	.byte	W08
	.byte		        22*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        24*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        25*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        28*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        31*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        36*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N18   , An3 
	.byte	W18
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	GOTO
	 .word	mus_girleye_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_girleye_7:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 1
	.byte		VOL   , 53*mus_girleye_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Ds5 , v120
	.byte	W06
	.byte		N66   , Ds6 , v127
	.byte	W90
mus_girleye_7_B1:
	.byte		VOICE , 82
	.byte	W12
	.byte		N06   , Cn3 , v112
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	W12
	.byte		        Bn2 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	W12
	.byte		        Cs3 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	W12
	.byte		        Gn3 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds3 
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        As2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	GOTO
	 .word	mus_girleye_7_B1
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

mus_girleye_8:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 12
	.byte		VOL   , 28*mus_girleye_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		N06   , Ds5 , v080
	.byte	W06
	.byte		VOL   , 28*mus_girleye_mvl/mxv
	.byte		N66   , Ds6 , v108
	.byte	W02
	.byte		VOL   , 26*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        24*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        23*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        22*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        22*mus_girleye_mvl/mxv
	.byte	W07
	.byte		        24*mus_girleye_mvl/mxv
	.byte	W06
	.byte		        26*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        27*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        29*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        32*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        34*mus_girleye_mvl/mxv
	.byte	W03
	.byte		MOD   , 5
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte	W05
	.byte		        37*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        39*mus_girleye_mvl/mxv
	.byte	W04
	.byte		        40*mus_girleye_mvl/mxv
	.byte	W02
	.byte		        41*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        43*mus_girleye_mvl/mxv
	.byte	W03
	.byte		        44*mus_girleye_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte	W24
mus_girleye_8_B1:
	.byte		VOL   , 36*mus_girleye_mvl/mxv
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte	W12
	.byte		        Dn3 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	W12
	.byte		        Fn3 
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	W12
	.byte		        As3 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte	GOTO
	 .word	mus_girleye_8_B1
	.byte	W96
	.byte	FINE

@********************** Track  9 **********************@

mus_girleye_9:
	.byte	KEYSH , mus_girleye_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 33*mus_girleye_mvl/mxv
	.byte	W48
	.byte		N01   , An4 , v112
	.byte	W06
	.byte		        An4 , v064
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        An4 , v112
	.byte	W03
	.byte		        An4 , v072
	.byte	W03
	.byte		        An4 , v080
	.byte	W03
	.byte		        An4 , v064
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        An4 , v076
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        An4 , v112
	.byte	W03
mus_girleye_9_B1:
mus_girleye_9_000:
	.byte		N01   , An4 , v112
	.byte	W06
	.byte		        An4 , v048
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        An4 , v044
	.byte	W06
	.byte		N02   , Gs3 , v112
	.byte	W03
	.byte		N03   , Fn4 , v064
	.byte	W03
	.byte		N01   , An4 , v048
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        An4 , v044
	.byte	W06
	.byte		        An4 , v072
	.byte	W06
	.byte		        An4 , v048
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		        An4 , v044
	.byte	W06
	.byte		        An4 , v108
	.byte	W06
	.byte		        An4 , v048
	.byte	W06
	.byte		        An4 , v112
	.byte	W03
	.byte		        An4 , v076
	.byte	W03
	.byte		        An4 , v096
	.byte	W03
	.byte		        An4 , v076
	.byte	W03
	.byte	PEND
mus_girleye_9_001:
	.byte		N01   , An4 , v112
	.byte	W06
	.byte		        An4 , v048
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        An4 , v044
	.byte	W06
	.byte		N02   , Gs3 , v112
	.byte	W03
	.byte		N03   , Fn4 , v064
	.byte	W03
	.byte		N01   , An4 , v048
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        An4 , v044
	.byte	W06
	.byte		        An4 , v072
	.byte	W06
	.byte		        An4 , v048
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		        An4 , v044
	.byte	W06
	.byte		        An4 , v112
	.byte	W03
	.byte		        An4 , v068
	.byte	W03
	.byte		        An4 , v088
	.byte	W03
	.byte		        An4 , v064
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        An4 , v076
	.byte	W03
	.byte		        An4 , v088
	.byte	W03
	.byte		        An4 , v112
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_girleye_9_000
	.byte	PATT
	 .word	mus_girleye_9_001
	.byte	GOTO
	 .word	mus_girleye_9_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_girleye:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_girleye_pri	@ Priority
	.byte	mus_girleye_rev	@ Reverb.

	.word	mus_girleye_grp

	.word	mus_girleye_1
	.word	mus_girleye_2
	.word	mus_girleye_3
	.word	mus_girleye_4
	.word	mus_girleye_5
	.word	mus_girleye_6
	.word	mus_girleye_7
	.word	mus_girleye_8
	.word	mus_girleye_9

	.end
