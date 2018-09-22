	.include "MPlayDef.s"

	.equ	mus_kachi5_grp, voicegroup029
	.equ	mus_kachi5_pri, 0
	.equ	mus_kachi5_rev, reverb_set+50
	.equ	mus_kachi5_mvl, 127
	.equ	mus_kachi5_key, 0
	.equ	mus_kachi5_tbs, 1
	.equ	mus_kachi5_exg, 0
	.equ	mus_kachi5_cmp, 1

	.section .rodata
	.global	mus_kachi5
	.align	2

@********************** Track  1 **********************@

mus_kachi5_1:
	.byte	KEYSH , mus_kachi5_key+0
	.byte	TEMPO , 140*mus_kachi5_tbs/2
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N04   , Fn3 , v112
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N48   , Fn4 
	.byte	W20
	.byte		MOD   , 6
	.byte	W28
	.byte		        0
	.byte		N24   , Cs4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W16
	.byte		        0
	.byte		N04   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N48   , Gs4 
	.byte	W20
	.byte		MOD   , 6
	.byte	W28
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W16
	.byte		        0
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		N08   , An4 
	.byte	W08
	.byte		N96   , As4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 60
	.byte		PAN   , c_v-16
	.byte		N04   , As2 , v096
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W48
mus_kachi5_1_B1:
	.byte		VOICE , 56
	.byte		PAN   , c_v-1
	.byte		N36   , Fn4 , v112
	.byte	W16
	.byte		MOD   , 6
	.byte	W20
	.byte		        0
	.byte	W04
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W04
	.byte		        0
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N60   , Fn3 
	.byte	W20
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 63*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        53*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        36*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        16*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W04
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N36   , As3 
	.byte	W16
	.byte		MOD   , 6
	.byte	W20
	.byte		        0
	.byte	W04
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N92   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W28
	.byte		VOL   , 68*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        60*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        50*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        39*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        27*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        13*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W04
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N40   , Fn4 
	.byte	W16
	.byte		MOD   , 6
	.byte	W20
	.byte		        0
	.byte	W04
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W04
	.byte		        0
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		BEND  , c_v-16
	.byte		N08   , Cn5 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N60   , An4 
	.byte	W20
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 63*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        53*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        36*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        16*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W04
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N40   , Gn4 
	.byte	W16
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N08   , An4 
	.byte	W08
	.byte		N16   , As4 
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N16   , As4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		BEND  , c_v-16
	.byte		N08   , Dn5 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N56   , Cn5 
	.byte	W24
	.byte		MOD   , 6
	.byte	W08
	.byte		VOL   , 70*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        62*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        52*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        34*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        13*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W04
	.byte		VOICE , 60
	.byte	W04
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N40   , Dn3 
	.byte	W40
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N48   , As2 
	.byte	W20
	.byte		MOD   , 6
	.byte	W28
	.byte		        0
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N40   , Gn3 
	.byte	W40
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Gn2 
	.byte	W08
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N48   , Cn3 
	.byte	W24
	.byte		VOL   , 73*mus_kachi5_mvl/mxv
	.byte		MOD   , 6
	.byte	W08
	.byte		VOL   , 66*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        53*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        30*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 48
	.byte	W04
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N40   , As3 
	.byte	W40
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N40   , Cn4 
	.byte	W40
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N48   , Fn3 
	.byte	W64
	.byte		PAN   , c_v+8
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W16
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N08   , Fn3 
	.byte	W16
	.byte		        Gn3 
	.byte	W08
	.byte		N24   , An3 
	.byte	W24
	.byte	GOTO
	 .word	mus_kachi5_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_kachi5_2:
	.byte	KEYSH , mus_kachi5_key+0
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N04   , Cn3 , v092
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		PAN   , c_v+8
	.byte		N48   , An3 
	.byte	W20
	.byte		MOD   , 6
	.byte	W28
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W08
	.byte		MOD   , 6
	.byte	W16
	.byte		        0
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N48   , Cn4 
	.byte	W20
	.byte		MOD   , 6
	.byte	W28
	.byte		        0
	.byte		N24   , Ds3 
	.byte	W08
	.byte		MOD   , 6
	.byte	W16
	.byte		        0
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N96   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W72
	.byte		N12   , Dn4 , v112
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 60
	.byte		PAN   , c_v+16
	.byte		N04   , Fn2 , v096
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W48
mus_kachi5_2_B1:
	.byte	W96
	.byte		VOICE , 73
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N04   , Dn5 , v080
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Dn5 
	.byte	W16
	.byte		N04   
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Dn5 
	.byte	W16
	.byte		VOICE , 56
	.byte		PAN   , c_v+8
	.byte		N08   , Fn3 , v092
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , An3 
	.byte	W08
	.byte		N36   , Gn3 
	.byte	W16
	.byte		MOD   , 6
	.byte	W20
	.byte		        0
	.byte	W04
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , As3 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N92   , An3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W28
	.byte		VOL   , 68*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        60*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        50*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        39*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        27*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        13*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W04
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte	W96
	.byte		VOICE , 73
	.byte		PAN   , c_v+16
	.byte		N04   , Dn5 , v080
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Dn5 
	.byte	W16
	.byte		N04   
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Dn5 
	.byte	W16
	.byte		VOICE , 56
	.byte		PAN   , c_v+8
	.byte		N08   , Cn4 , v092
	.byte	W08
	.byte		N16   , As3 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , An3 
	.byte	W08
	.byte		N40   , As3 
	.byte	W16
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N56   , Fn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W08
	.byte		VOL   , 70*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        62*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        52*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        34*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        13*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W40
	.byte		VOICE , 45
	.byte		PAN   , c_v-10
	.byte	W16
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		        As4 
	.byte	W40
	.byte		        Fn4 
	.byte	W08
	.byte		        As4 
	.byte	W24
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		        Dn5 
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		        Dn5 
	.byte	W16
	.byte		        Cn5 
	.byte	W08
	.byte		        As4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		        Ds5 
	.byte	W40
	.byte		        As4 
	.byte	W08
	.byte		        Ds5 
	.byte	W24
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Cn5 
	.byte	W16
	.byte		        Fn4 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte	W48
	.byte		VOICE , 60
	.byte		VOL   , 35*mus_kachi5_mvl/mxv
	.byte		N48   , Fn2 
	.byte	W08
	.byte		VOL   , 42*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        55*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte	W04
	.byte		VOL   , 66*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        80*mus_kachi5_mvl/mxv
	.byte	W16
	.byte		MOD   , 0
	.byte		N08   , Fs2 , v080
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N48   , Dn3 
	.byte	W16
	.byte		MOD   , 6
	.byte	W04
	.byte		VOL   , 75*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        72*mus_kachi5_mvl/mxv
	.byte	W08
	.byte		        65*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        47*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		        28*mus_kachi5_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W16
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		N08   , Dn4 , v112
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		MOD   , 0
	.byte	W08
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N24   , Ds4 
	.byte	W08
	.byte		MOD   , 6
	.byte	W16
	.byte	GOTO
	 .word	mus_kachi5_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_kachi5_3:
	.byte	KEYSH , mus_kachi5_key+0
	.byte	W12
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_kachi5_3_B1:
	.byte		VOICE , 48
	.byte		PAN   , c_v-10
	.byte		N12   , Dn3 , v080
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N04   , As2 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N12   , Fn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Gn3 , v092
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N12   , Dn3 , v080
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N04   , As2 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N20   , Fn3 
	.byte	W24
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N12   , Gn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , Fn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Gn3 , v092
	.byte	W08
	.byte		        An3 
	.byte	W48
	.byte	W96
	.byte		VOICE , 56
	.byte		PAN   , c_v+7
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		N08   , Dn4 , v112
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   , Fn4 , v080
	.byte	W04
	.byte		        Dn4 , v072
	.byte	W04
	.byte		        As3 , v060
	.byte	W04
	.byte		        Fs3 , v052
	.byte	W04
	.byte		VOICE , 14
	.byte	W24
	.byte		N24   , Gn4 , v076
	.byte	W40
	.byte		N08   , As3 , v068
	.byte	W08
	.byte		N24   , Ds4 , v076
	.byte	W24
	.byte		VOICE , 56
	.byte		N04   , Fn3 , v112
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Fn3 
	.byte	W24
	.byte		N04   
	.byte	W04
	.byte		        Bn3 , v080
	.byte	W04
	.byte		N08   , Cn4 , v112
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N04   , Ds4 , v080
	.byte	W04
	.byte		        Cn4 , v072
	.byte	W04
	.byte		        An3 , v060
	.byte	W04
	.byte		        Fn3 , v052
	.byte	W04
	.byte		VOICE , 14
	.byte		PAN   , c_v-6
	.byte		N36   , Fn4 , v100
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        Ds4 
	.byte	W48
	.byte		N12   , Fs4 
	.byte	W16
	.byte		N08   , Ds4 , v080
	.byte	W08
	.byte		N24   , Fs4 , v100
	.byte	W24
	.byte		N36   , Fn4 
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_kachi5_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_kachi5_4:
	.byte	KEYSH , mus_kachi5_key+0
	.byte	W12
	.byte		VOICE , 7
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		BEND  , c_v-2
	.byte	W24
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N08   , An3 , v052
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        As5 
	.byte	W04
	.byte		        Dn6 
	.byte	W08
	.byte		        Dn6 , v032
	.byte	W16
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		N04   , As2 , v052
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOICE , 80
	.byte		N12   
	.byte	W48
mus_kachi5_4_B1:
	.byte		VOICE , 80
	.byte		N12   , As2 , v052
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N04   , Fn2 
	.byte	W08
	.byte		N08   , As2 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   , An2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N08   , An2 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , As2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , Cn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Ds3 
	.byte	W08
	.byte		        Fn3 
	.byte	W16
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N12   , As2 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N04   , Fn2 
	.byte	W08
	.byte		N08   , As2 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   , An2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N08   , An2 
	.byte	W16
	.byte		N20   , Dn3 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , Cn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Ds3 
	.byte	W08
	.byte		        Fn3 
	.byte	W16
	.byte		VOICE , 12
	.byte		PAN   , c_v+0
	.byte		N08   , Fn3 , v032
	.byte	W08
	.byte		N16   , Fn4 , v040
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N40   , Dn4 
	.byte	W40
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N48   , As3 
	.byte	W64
	.byte		N08   
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N40   , Gn4 
	.byte	W40
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N48   , Cn4 
	.byte	W96
	.byte		VOICE , 7
	.byte		N08   , As5 , v052
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        As5 
	.byte	W08
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N08   , An2 
	.byte	W16
	.byte		        As2 
	.byte	W08
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , Ds3 
	.byte	W24
	.byte	GOTO
	 .word	mus_kachi5_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_kachi5_5:
	.byte	KEYSH , mus_kachi5_key+0
	.byte	W12
	.byte		VOICE , 8
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v+48
	.byte	W08
	.byte		N08   , An3 , v020
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        As5 
	.byte	W20
	.byte		VOICE , 84
	.byte		N04   , Fn2 , v052
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOICE , 82
	.byte		N12   
	.byte	W48
mus_kachi5_5_B1:
	.byte		VOICE , 82
	.byte		N12   , Fn2 , v052
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N08   , Fn2 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N08   , Fn2 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , Gn2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , An2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W16
	.byte		N24   , As2 
	.byte	W24
	.byte		N08   , An2 
	.byte	W08
	.byte		N12   , Fn2 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N08   , Fn2 
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   , Fs2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		N08   , Fs2 
	.byte	W16
	.byte		N20   , An2 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , As2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , An2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W48
	.byte	W96
	.byte		VOICE , 87
	.byte		N04   , Dn3 , v060
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Dn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N08   , As3 
	.byte	W16
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Cn4 , v032
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte	W96
	.byte		        Cn3 , v060
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N08   , An3 
	.byte	W16
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N04   , An3 , v032
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte	W08
	.byte		VOICE , 8
	.byte		N08   , As5 , v020
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		VOICE , 82
	.byte		N08   , Fn2 , v080
	.byte	W16
	.byte		        Gn2 
	.byte	W08
	.byte		N24   , An2 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        As2 
	.byte	W08
	.byte		N24   , Cn3 
	.byte	W24
	.byte	GOTO
	 .word	mus_kachi5_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_kachi5_6:
	.byte	KEYSH , mus_kachi5_key+0
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W24
	.byte		N24   , Fn1 , v080
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		N12   , As1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W48
mus_kachi5_6_B1:
	.byte		N12   , As1 , v080
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , An1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N12   , Gn1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N20   , As1 
	.byte	W24
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N12   , Fn1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		        Cn2 
	.byte	W16
	.byte		N20   , Fn1 
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , As1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N20   , An1 
	.byte	W24
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N12   , Gn1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N20   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N12   , Fn1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N20   , Gn1 
	.byte	W24
	.byte		N08   , An1 
	.byte	W08
	.byte		N12   , As1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		N08   , As1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , As1 
	.byte	W24
	.byte		        Fs1 
	.byte	W24
	.byte		N08   , As1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		N08   , Gn1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Ds1 
	.byte	W16
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N24   , Fn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		N12   , As1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N20   , Fn1 
	.byte	W24
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N12   , Ds1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N20   , Fs1 
	.byte	W24
	.byte		N08   , Gs1 
	.byte	W08
	.byte		N12   , As1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N20   , Fn2 
	.byte	W24
	.byte		N04   , As1 
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W16
	.byte		        As1 
	.byte	W08
	.byte		N20   , An1 
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Gn1 
	.byte	W08
	.byte		N24   , Fn1 
	.byte	W24
	.byte	GOTO
	 .word	mus_kachi5_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_kachi5_7:
	.byte	KEYSH , mus_kachi5_key+0
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-9
	.byte		N08   , Fn1 , v120
	.byte	W08
	.byte		        Fn1 , v112
	.byte	W08
	.byte		        Fn1 , v120
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N04   , Fn1 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   , Fn1 , v120
	.byte	W08
	.byte		        Fn1 , v112
	.byte	W08
	.byte		        Fn1 , v120
	.byte	W08
	.byte		N24   , Cs2 , v127
	.byte	W24
	.byte		N08   , Gs1 , v120
	.byte	W08
	.byte		        Gs1 , v112
	.byte	W08
	.byte		        Gs1 , v120
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N04   , Gs1 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   , Gs1 , v120
	.byte	W08
	.byte		        Gs1 , v112
	.byte	W08
	.byte		        Gs1 , v120
	.byte	W08
	.byte		N24   , Cn2 , v127
	.byte	W24
	.byte		N12   , As1 
	.byte	W12
	.byte		        Fn1 , v120
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 , v127
	.byte	W24
	.byte		N08   , As1 , v120
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   
	.byte	W48
mus_kachi5_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 47
	.byte		N12   , As1 , v120
	.byte	W24
	.byte		N05   , As1 , v100
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N12   , As1 , v120
	.byte	W16
	.byte		N14   , Fn1 , v100
	.byte	W24
	.byte		N05   , As1 , v120
	.byte	W08
	.byte		N12   
	.byte	W24
	.byte		N05   , As1 , v100
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N12   , As1 , v120
	.byte	W16
	.byte		N14   , Fs1 , v100
	.byte	W24
	.byte		N05   , As1 , v120
	.byte	W08
	.byte		N12   , Gn1 
	.byte	W24
	.byte		N05   , Gn1 , v100
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N06   , Gn1 , v120
	.byte	W16
	.byte		N17   , As1 , v100
	.byte	W24
	.byte		N05   , Gn1 , v120
	.byte	W08
	.byte		N12   , Fn1 
	.byte	W24
	.byte		N05   , Fn1 , v100
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N12   , Fn1 , v120
	.byte	W16
	.byte		N14   , An1 , v100
	.byte	W24
	.byte		N05   , Fn1 , v120
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N08   , Cn2 , v127
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , An1 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N12   , Fn1 
	.byte	W24
	.byte	GOTO
	 .word	mus_kachi5_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_kachi5_8:
	.byte		VOL   , 80*mus_kachi5_mvl/mxv
	.byte	KEYSH , mus_kachi5_key+0
	.byte	W12
	.byte		VOICE , 0
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N48   , Bn2 , v092
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte		N48   
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte		N48   
	.byte	W96
	.byte		N96   
	.byte	W72
	.byte		N04   , En1 , v112
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
mus_kachi5_8_B1:
mus_kachi5_8_000:
	.byte		N04   , En1 , v112
	.byte		N96   , Bn2 , v092
	.byte	W16
	.byte		N04   , En1 , v080
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte	PEND
mus_kachi5_8_001:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte	PEND
mus_kachi5_8_002:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_kachi5_8_001
	.byte	PATT
	 .word	mus_kachi5_8_000
	.byte	PATT
	 .word	mus_kachi5_8_001
	.byte	PATT
	 .word	mus_kachi5_8_002
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W48
	.byte		N96   , Bn2 , v092
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N04   , En1 , v112
	.byte		N48   , Bn2 , v092
	.byte	W24
	.byte		N04   , En1 , v096
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v096
	.byte	W04
	.byte		        En1 , v080
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W24
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v096
	.byte	W04
	.byte		        En1 , v080
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W24
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		N08   , En1 , v112
	.byte	W24
	.byte		N48   , Bn2 , v092
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	GOTO
	 .word	mus_kachi5_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_kachi5:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_kachi5_pri	@ Priority
	.byte	mus_kachi5_rev	@ Reverb.

	.word	mus_kachi5_grp

	.word	mus_kachi5_1
	.word	mus_kachi5_2
	.word	mus_kachi5_3
	.word	mus_kachi5_4
	.word	mus_kachi5_5
	.word	mus_kachi5_6
	.word	mus_kachi5_7
	.word	mus_kachi5_8

	.end
