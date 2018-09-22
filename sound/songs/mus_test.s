	.include "MPlayDef.s"

	.equ	mus_test_grp, voicegroup043
	.equ	mus_test_pri, 0
	.equ	mus_test_rev, reverb_set+50
	.equ	mus_test_mvl, 127
	.equ	mus_test_key, 0
	.equ	mus_test_tbs, 1
	.equ	mus_test_exg, 0
	.equ	mus_test_cmp, 1

	.section .rodata
	.global	mus_test
	.align	2

@********************** Track  1 **********************@

mus_test_1:
	.byte	KEYSH , mus_test_key+0
	.byte	TEMPO , 128*mus_test_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 14*mus_test_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N48   , Ds4 , v112
	.byte	W04
	.byte		VOL   , 22*mus_test_mvl/mxv
	.byte	W04
	.byte		        34*mus_test_mvl/mxv
	.byte	W04
	.byte		        44*mus_test_mvl/mxv
	.byte	W04
	.byte		        55*mus_test_mvl/mxv
	.byte	W04
	.byte		        64*mus_test_mvl/mxv
	.byte	W04
	.byte		        72*mus_test_mvl/mxv
	.byte	W04
	.byte		        76*mus_test_mvl/mxv
	.byte	W04
	.byte		        82*mus_test_mvl/mxv
	.byte	W04
	.byte		        74*mus_test_mvl/mxv
	.byte	W12
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
mus_test_1_B1:
	.byte		N04   , Bn3 , v072
	.byte	W04
	.byte		N12   , Cn4 , v080
	.byte	W12
	.byte		N08   , Cn4 , v032
	.byte	W08
	.byte		N16   , Cn4 , v080
	.byte	W16
	.byte		N08   , Gs4 , v064
	.byte	W08
	.byte		        Cn4 , v080
	.byte	W08
	.byte		        Cn4 , v032
	.byte	W16
	.byte		N16   , Cs4 , v096
	.byte	W16
	.byte		N08   , Cs4 , v032
	.byte	W08
	.byte		N16   , Cs4 , v096
	.byte	W16
	.byte		N08   , Gs4 , v064
	.byte	W08
	.byte		        Cs4 , v096
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W16
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N08   , Dn4 , v032
	.byte	W08
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N08   , Gs4 , v064
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Dn4 , v032
	.byte	W16
	.byte		VOL   , 35*mus_test_mvl/mxv
	.byte		N40   , Ds4 , v112
	.byte	W04
	.byte		VOL   , 37*mus_test_mvl/mxv
	.byte	W04
	.byte		        37*mus_test_mvl/mxv
	.byte	W04
	.byte		        42*mus_test_mvl/mxv
	.byte	W04
	.byte		        49*mus_test_mvl/mxv
	.byte	W04
	.byte		        59*mus_test_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 67*mus_test_mvl/mxv
	.byte	W04
	.byte		        76*mus_test_mvl/mxv
	.byte	W04
	.byte		        74*mus_test_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , Gs4 , v064
	.byte	W08
	.byte		        Gn4 , v076
	.byte	W08
	.byte		        Fn4 , v064
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		VOL   , 37*mus_test_mvl/mxv
	.byte		N40   , Fn4 , v100
	.byte	W08
	.byte		VOL   , 42*mus_test_mvl/mxv
	.byte	W04
	.byte		        50*mus_test_mvl/mxv
	.byte	W04
	.byte		        58*mus_test_mvl/mxv
	.byte	W04
	.byte		        64*mus_test_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 72*mus_test_mvl/mxv
	.byte	W04
	.byte		        79*mus_test_mvl/mxv
	.byte	W04
	.byte		        74*mus_test_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , Gn4 , v076
	.byte	W08
	.byte		        Gs4 , v072
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W16
	.byte		VOL   , 44*mus_test_mvl/mxv
	.byte		N24   , Ds4 , v096
	.byte	W04
	.byte		VOL   , 52*mus_test_mvl/mxv
	.byte	W04
	.byte		        64*mus_test_mvl/mxv
	.byte	W04
	.byte		        73*mus_test_mvl/mxv
	.byte	W04
	.byte		        75*mus_test_mvl/mxv
	.byte	W08
	.byte		N24   , Gn4 , v084
	.byte	W24
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W16
	.byte		VOL   , 37*mus_test_mvl/mxv
	.byte		N40   , Ds4 , v112
	.byte	W04
	.byte		VOL   , 42*mus_test_mvl/mxv
	.byte	W04
	.byte		        50*mus_test_mvl/mxv
	.byte	W04
	.byte		        55*mus_test_mvl/mxv
	.byte	W04
	.byte		        63*mus_test_mvl/mxv
	.byte	W04
	.byte		        72*mus_test_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 75*mus_test_mvl/mxv
	.byte	W16
	.byte		MOD   , 0
	.byte		N08   , Fn4 , v068
	.byte	W08
	.byte		        Ds4 , v072
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 , v064
	.byte	W08
	.byte		VOL   , 70*mus_test_mvl/mxv
	.byte		N40   , Cn4 , v096
	.byte	W04
	.byte		VOL   , 76*mus_test_mvl/mxv
	.byte	W04
	.byte		        82*mus_test_mvl/mxv
	.byte	W04
	.byte		        84*mus_test_mvl/mxv
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 79*mus_test_mvl/mxv
	.byte	W04
	.byte		        71*mus_test_mvl/mxv
	.byte	W04
	.byte		        61*mus_test_mvl/mxv
	.byte	W04
	.byte		        55*mus_test_mvl/mxv
	.byte	W04
	.byte		        75*mus_test_mvl/mxv
	.byte		N08   , Cn4 , v032
	.byte	W08
	.byte		MOD   , 0
	.byte		N16   , Fn4 , v072
	.byte	W16
	.byte		N08   , Fn4 , v032
	.byte	W08
	.byte		VOL   , 47*mus_test_mvl/mxv
	.byte		N48   , Ds4 , v112
	.byte	W04
	.byte		VOL   , 49*mus_test_mvl/mxv
	.byte	W04
	.byte		        50*mus_test_mvl/mxv
	.byte	W04
	.byte		        52*mus_test_mvl/mxv
	.byte	W04
	.byte		        56*mus_test_mvl/mxv
	.byte	W04
	.byte		        62*mus_test_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 68*mus_test_mvl/mxv
	.byte	W04
	.byte		        75*mus_test_mvl/mxv
	.byte	W04
	.byte		        85*mus_test_mvl/mxv
	.byte	W04
	.byte		        88*mus_test_mvl/mxv
	.byte	W04
	.byte		        75*mus_test_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , Cs4 , v096
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W08
	.byte		        Cn4 , v088
	.byte	W08
	.byte		VOL   , 37*mus_test_mvl/mxv
	.byte		N48   , Gs3 , v084
	.byte	W04
	.byte		VOL   , 42*mus_test_mvl/mxv
	.byte	W04
	.byte		        44*mus_test_mvl/mxv
	.byte	W04
	.byte		        46*mus_test_mvl/mxv
	.byte	W04
	.byte		        49*mus_test_mvl/mxv
	.byte	W04
	.byte		        50*mus_test_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 56*mus_test_mvl/mxv
	.byte	W04
	.byte		        61*mus_test_mvl/mxv
	.byte	W04
	.byte		        66*mus_test_mvl/mxv
	.byte	W04
	.byte		        76*mus_test_mvl/mxv
	.byte	W04
	.byte		        75*mus_test_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , Fn3 
	.byte	W08
	.byte		        Fn3 , v032
	.byte	W08
	.byte		        Gs3 , v084
	.byte	W08
	.byte		VOL   , 42*mus_test_mvl/mxv
	.byte		N48   , Cn4 , v112
	.byte	W08
	.byte		VOL   , 47*mus_test_mvl/mxv
	.byte	W04
	.byte		        52*mus_test_mvl/mxv
	.byte	W04
	.byte		        56*mus_test_mvl/mxv
	.byte	W04
	.byte		        63*mus_test_mvl/mxv
	.byte	W04
	.byte		        73*mus_test_mvl/mxv
	.byte		MOD   , 4
	.byte	W04
	.byte		VOL   , 78*mus_test_mvl/mxv
	.byte	W04
	.byte		        84*mus_test_mvl/mxv
	.byte	W04
	.byte		        75*mus_test_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		N08   , Cs4 , v080
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W08
	.byte		        Cn4 , v084
	.byte	W08
	.byte		VOL   , 39*mus_test_mvl/mxv
	.byte		N48   , As3 , v096
	.byte	W04
	.byte		VOL   , 39*mus_test_mvl/mxv
	.byte	W08
	.byte		        42*mus_test_mvl/mxv
	.byte	W04
	.byte		        44*mus_test_mvl/mxv
	.byte	W04
	.byte		        50*mus_test_mvl/mxv
	.byte	W04
	.byte		        55*mus_test_mvl/mxv
	.byte		MOD   , 4
	.byte	W04
	.byte		VOL   , 62*mus_test_mvl/mxv
	.byte	W04
	.byte		        68*mus_test_mvl/mxv
	.byte	W04
	.byte		        78*mus_test_mvl/mxv
	.byte	W04
	.byte		        74*mus_test_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , As3 , v032
	.byte	W24
	.byte	GOTO
	 .word	mus_test_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_test_2:
	.byte	KEYSH , mus_test_key+0
	.byte		VOICE , 73
	.byte		VOL   , 14*mus_test_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N48   , As4 , v064
	.byte	W04
	.byte		VOL   , 22*mus_test_mvl/mxv
	.byte	W04
	.byte		        33*mus_test_mvl/mxv
	.byte	W04
	.byte		        40*mus_test_mvl/mxv
	.byte	W04
	.byte		        52*mus_test_mvl/mxv
	.byte	W04
	.byte		        70*mus_test_mvl/mxv
	.byte	W04
	.byte		        79*mus_test_mvl/mxv
	.byte	W04
	.byte		        71*mus_test_mvl/mxv
	.byte	W20
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
mus_test_2_B1:
	.byte		N04   , Gs4 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds5 
	.byte	W04
	.byte		N20   , Cs5 
	.byte	W20
	.byte		N08   , Cs5 , v028
	.byte	W24
mus_test_2_000:
	.byte		N04   , As4 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn5 
	.byte	W04
	.byte		N20   , As4 
	.byte	W20
	.byte		N08   , As4 , v028
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_test_2_000
	.byte		N04   , An4 , v064
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		N08   , Fn5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		VOL   , 50*mus_test_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W04
	.byte		VOL   , 56*mus_test_mvl/mxv
	.byte		N04   , Ds5 
	.byte	W04
	.byte		VOL   , 59*mus_test_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W04
	.byte		VOL   , 64*mus_test_mvl/mxv
	.byte		N04   , Ds5 
	.byte	W04
	.byte		VOL   , 66*mus_test_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W04
	.byte		VOL   , 69*mus_test_mvl/mxv
	.byte		N04   , Ds5 
	.byte	W04
	.byte		VOL   , 73*mus_test_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W04
	.byte		VOL   , 76*mus_test_mvl/mxv
	.byte		N04   , Ds5 
	.byte	W04
	.byte		VOL   , 79*mus_test_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W04
	.byte		VOL   , 81*mus_test_mvl/mxv
	.byte		N04   , Ds5 
	.byte	W04
	.byte		VOL   , 85*mus_test_mvl/mxv
	.byte		N04   , Cs5 
	.byte	W04
	.byte		VOL   , 88*mus_test_mvl/mxv
	.byte		N04   , Ds5 
	.byte	W04
	.byte		VOL   , 71*mus_test_mvl/mxv
	.byte		N08   , Gs5 
	.byte	W08
	.byte		        Gs5 , v028
	.byte	W08
	.byte		        Fn5 , v060
	.byte	W08
	.byte		VOL   , 50*mus_test_mvl/mxv
	.byte		N04   , Gs4 
	.byte	W04
	.byte		VOL   , 56*mus_test_mvl/mxv
	.byte		N04   , As4 
	.byte	W04
	.byte		VOL   , 59*mus_test_mvl/mxv
	.byte		N04   , Gs4 
	.byte	W04
	.byte		VOL   , 64*mus_test_mvl/mxv
	.byte		N04   , As4 
	.byte	W04
	.byte		VOL   , 66*mus_test_mvl/mxv
	.byte		N04   , Gs4 
	.byte	W04
	.byte		VOL   , 69*mus_test_mvl/mxv
	.byte		N04   , As4 
	.byte	W04
	.byte		VOL   , 73*mus_test_mvl/mxv
	.byte		N04   , Gs4 
	.byte	W04
	.byte		VOL   , 76*mus_test_mvl/mxv
	.byte		N04   , As4 
	.byte	W04
	.byte		VOL   , 79*mus_test_mvl/mxv
	.byte		N04   , Gs4 
	.byte	W04
	.byte		VOL   , 81*mus_test_mvl/mxv
	.byte		N04   , As4 
	.byte	W04
	.byte		VOL   , 85*mus_test_mvl/mxv
	.byte		N04   , Gs4 
	.byte	W04
	.byte		VOL   , 88*mus_test_mvl/mxv
	.byte		N04   , As4 
	.byte	W04
	.byte		VOL   , 70*mus_test_mvl/mxv
	.byte		N08   , Fn5 
	.byte	W08
	.byte		        Fn5 , v028
	.byte	W08
	.byte		        Cs5 , v064
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Ds4 , v060
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N24   , As3 
	.byte	W24
	.byte		N08   , Gn3 , v064
	.byte	W08
	.byte		        Gn3 , v028
	.byte	W08
	.byte		        Ds3 , v060
	.byte	W08
	.byte	GOTO
	 .word	mus_test_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_test_3:
	.byte	KEYSH , mus_test_key+0
	.byte		VOICE , 1
	.byte		VOL   , 74*mus_test_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N48   , Cs3 , v080
	.byte	W48
	.byte		N08   , Gn2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
mus_test_3_B1:
	.byte		N24   , Ds3 , v080
	.byte	W24
	.byte		N08   , Gs2 
	.byte	W08
	.byte		        Gs2 , v028
	.byte	W08
	.byte		        Gs3 , v080
	.byte	W08
	.byte		N04   , Ds3 
	.byte	W04
	.byte		N08   , Ds3 , v028
	.byte	W20
	.byte		N24   , Ds3 , v080
	.byte	W24
	.byte		N08   , As2 
	.byte	W08
	.byte		        As2 , v028
	.byte	W08
	.byte		        As3 , v080
	.byte	W08
	.byte		N04   , Ds3 
	.byte	W04
	.byte		N08   , Ds3 , v028
	.byte	W20
	.byte		N24   , Ds3 , v080
	.byte	W24
	.byte		N08   , Bn2 
	.byte	W08
	.byte		        Bn2 , v028
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		N04   , Ds3 
	.byte	W04
	.byte		N08   , Ds3 , v028
	.byte	W20
	.byte		N24   , Ds3 , v080
	.byte	W24
	.byte		N08   , Cn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N40   , Gs3 
	.byte	W40
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		        Gs3 , v028
	.byte	W16
	.byte		N40   , Gn3 , v080
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Gn3 , v028
	.byte	W16
	.byte		N40   , Gn3 , v080
	.byte	W40
	.byte		N04   , Fn3 
	.byte	W08
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Gn3 , v028
	.byte	W16
	.byte		N24   , Fn3 , v080
	.byte	W24
	.byte		N08   , Ds3 
	.byte	W08
	.byte		        Ds3 , v028
	.byte	W08
	.byte		        Cs3 , v080
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn3 , v028
	.byte	W08
	.byte		        An2 , v080
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn3 , v028
	.byte	W08
	.byte		        Fn3 , v080
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gs3 , v028
	.byte	W08
	.byte		        Cs3 , v080
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Cs4 , v028
	.byte	W16
	.byte		        Gs2 , v080
	.byte	W08
	.byte		        Gs2 , v028
	.byte	W08
	.byte		        Cs3 , v080
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fn3 , v028
	.byte	W08
	.byte		        As2 , v080
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        As3 , v028
	.byte	W16
	.byte		        Ds3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N08   , Fn2 
	.byte	W08
	.byte		        Fn2 , v028
	.byte	W08
	.byte		        Ds2 , v080
	.byte	W08
	.byte		N24   , Cs3 
	.byte	W24
	.byte	GOTO
	 .word	mus_test_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_test_4:
	.byte	KEYSH , mus_test_key+0
	.byte		VOICE , 58
	.byte		VOL   , 5*mus_test_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Ds1 , v064
	.byte	W04
	.byte		VOL   , 31*mus_test_mvl/mxv
	.byte	W04
	.byte		        47*mus_test_mvl/mxv
	.byte	W04
	.byte		        57*mus_test_mvl/mxv
	.byte	W04
	.byte		        61*mus_test_mvl/mxv
	.byte	W04
	.byte		        67*mus_test_mvl/mxv
	.byte	W04
	.byte		        71*mus_test_mvl/mxv
	.byte	W04
	.byte		        73*mus_test_mvl/mxv
	.byte	W04
	.byte		        79*mus_test_mvl/mxv
	.byte	W04
	.byte		        81*mus_test_mvl/mxv
	.byte	W04
	.byte		        94*mus_test_mvl/mxv
	.byte	W08
	.byte		N08   , Fn1 , v072
	.byte	W08
	.byte		        As1 , v064
	.byte	W08
	.byte		        Gn1 
	.byte	W08
mus_test_4_B1:
	.byte		N24   , Gs1 , v072
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        Gs2 , v064
	.byte	W08
	.byte		        Gs2 , v032
	.byte	W08
	.byte		        Ds2 , v064
	.byte	W08
	.byte		N24   , Gs1 , v076
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        As2 , v064
	.byte	W08
	.byte		        As2 , v032
	.byte	W08
	.byte		        Ds2 , v064
	.byte	W08
	.byte		N24   , Gs1 , v072
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        Bn2 , v064
	.byte	W08
	.byte		        Bn2 , v032
	.byte	W08
	.byte		        Ds2 , v064
	.byte	W08
	.byte		N24   , Gs1 , v072
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        Cn3 , v064
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N24   , Cs1 , v072
	.byte	W24
	.byte		N08   , Gs1 , v064
	.byte	W08
	.byte		        Gs1 , v032
	.byte	W08
	.byte		        Gs2 , v064
	.byte	W08
	.byte		N24   , Cs2 
	.byte	W24
	.byte		        Cs1 , v072
	.byte	W24
	.byte		N08   , Gn1 , v064
	.byte	W08
	.byte		        Gn1 , v032
	.byte	W08
	.byte		        As2 , v064
	.byte	W08
	.byte		N24   , Ds2 
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		N08   , Cn2 , v064
	.byte	W08
	.byte		        Cn2 , v032
	.byte	W08
	.byte		        As2 , v064
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N24   , Fn1 , v072
	.byte	W24
	.byte		N08   , Cn2 , v064
	.byte	W08
	.byte		        Cn2 , v032
	.byte	W16
	.byte		        Fn2 , v064
	.byte	W08
	.byte		        Fn2 , v032
	.byte	W08
	.byte		        Cn2 , v064
	.byte	W08
	.byte		N24   , Cs1 , v072
	.byte	W24
	.byte		N08   , Gs1 , v064
	.byte	W08
	.byte		        Gs1 , v032
	.byte	W08
	.byte		        Fn2 , v064
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cs3 , v032
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		N24   , As1 , v068
	.byte	W24
	.byte		N08   , Fn1 , v064
	.byte	W08
	.byte		        Fn1 , v032
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs2 , v032
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		N40   , Ds1 , v072
	.byte	W40
	.byte		N08   , As1 , v064
	.byte	W08
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N40   , Ds1 , v072
	.byte	W40
	.byte		N08   , As1 , v064
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W08
	.byte		        Gn2 , v064
	.byte	W08
	.byte	GOTO
	 .word	mus_test_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_test_5:
	.byte	KEYSH , mus_test_key+0
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*mus_test_mvl/mxv
	.byte		N48   , Ds1 , v064
	.byte	W48
	.byte		N08   , Fn1 , v072
	.byte	W08
	.byte		        As1 , v064
	.byte	W08
	.byte		        Gn1 
	.byte	W08
mus_test_5_B1:
	.byte		N24   , Gs1 , v072
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        Gs2 , v064
	.byte	W08
	.byte		        Gs2 , v032
	.byte	W08
	.byte		        Ds2 , v064
	.byte	W08
	.byte		N24   , Gs1 , v076
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        As2 , v064
	.byte	W08
	.byte		        As2 , v032
	.byte	W08
	.byte		        Ds2 , v064
	.byte	W08
	.byte		N24   , Gs1 , v072
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        Bn2 , v064
	.byte	W08
	.byte		        Bn2 , v032
	.byte	W08
	.byte		        Ds2 , v064
	.byte	W08
	.byte		N24   , Gs1 , v072
	.byte	W24
	.byte		N08   , Ds2 , v064
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W16
	.byte		        Cn3 , v064
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N24   , Cs1 , v072
	.byte	W24
	.byte		N08   , Gs1 , v064
	.byte	W08
	.byte		        Gs1 , v032
	.byte	W08
	.byte		        Gs2 , v064
	.byte	W08
	.byte		N24   , Cs2 
	.byte	W24
	.byte		        Cs1 , v072
	.byte	W24
	.byte		N08   , Gn1 , v064
	.byte	W08
	.byte		        Gn1 , v032
	.byte	W08
	.byte		        As2 , v064
	.byte	W08
	.byte		N24   , Ds2 
	.byte	W24
	.byte		        Cn1 , v072
	.byte	W24
	.byte		N08   , Cn2 , v064
	.byte	W08
	.byte		        Cn2 , v032
	.byte	W08
	.byte		        As2 , v064
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N24   , Fn1 , v072
	.byte	W24
	.byte		N08   , Cn2 , v064
	.byte	W08
	.byte		        Cn2 , v032
	.byte	W16
	.byte		        Fn2 , v064
	.byte	W08
	.byte		        Fn2 , v032
	.byte	W08
	.byte		        Cn2 , v064
	.byte	W08
	.byte		N24   , Cs1 , v072
	.byte	W24
	.byte		N08   , Gs1 , v064
	.byte	W08
	.byte		        Gs1 , v032
	.byte	W08
	.byte		        Fn2 , v064
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cs3 , v032
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		N24   , As1 , v068
	.byte	W24
	.byte		N08   , Fn1 , v064
	.byte	W08
	.byte		        Fn1 , v032
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Gs2 , v032
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		N40   , Ds1 , v072
	.byte	W40
	.byte		N08   , As1 , v064
	.byte	W08
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N40   , Ds1 , v072
	.byte	W40
	.byte		N08   , As1 , v064
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds2 , v032
	.byte	W08
	.byte		        Gn2 , v064
	.byte	W08
	.byte	GOTO
	 .word	mus_test_5_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_test:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_test_pri	@ Priority
	.byte	mus_test_rev	@ Reverb.

	.word	mus_test_grp

	.word	mus_test_1
	.word	mus_test_2
	.word	mus_test_3
	.word	mus_test_4
	.word	mus_test_5

	.end
