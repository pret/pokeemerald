	.include "MPlayDef.s"

	.equ	mus_vs_front_grp, voicegroup115
	.equ	mus_vs_front_pri, 1
	.equ	mus_vs_front_rev, reverb_set+50
	.equ	mus_vs_front_mvl, 127
	.equ	mus_vs_front_key, 0
	.equ	mus_vs_front_tbs, 1
	.equ	mus_vs_front_exg, 0
	.equ	mus_vs_front_cmp, 1

	.section .rodata
	.global	mus_vs_front
	.align	2

@********************** Track  1 **********************@

mus_vs_front_1:
	.byte	KEYSH , mus_vs_front_key+0
	.byte	TEMPO , 190*mus_vs_front_tbs/2
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		VOL   , 78*mus_vs_front_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 87*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+13
	.byte	W12
	.byte	W72
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		VOL   , 59*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N24   , Cs5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		MOD   , 0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		MOD   , 0
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		MOD   , 0
	.byte		N24   , Gs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+12
	.byte		MOD   , 0
	.byte		N03   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		MOD   , 5
	.byte		N03   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
mus_vs_front_1_B1:
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+16
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An4 , v032
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An4 , v016
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte		VOL   , 79*mus_vs_front_mvl/mxv
	.byte		N02   , An4 , v088
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An4 , v032
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An4 , v016
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte		N02   , Gs4 , v088
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , Gs4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Bn4 , v064
	.byte	W12
	.byte		MOD   , 5
	.byte		N06   , Bn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , Bn4 , v032
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Bn4 , v016
	.byte	W12
	.byte		MOD   , 5
	.byte		N06   , Bn3 
	.byte	W12
	.byte		MOD   , 0
	.byte	W36
	.byte		        5
	.byte	W12
	.byte		        0
	.byte	W36
	.byte		        5
	.byte	W12
	.byte		        0
	.byte	W90
	.byte		        5
	.byte	W06
	.byte		        0
	.byte	W90
	.byte		        5
	.byte	W06
	.byte		        0
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 24
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		N06   , En4 , v104
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W22
	.byte		PAN   , c_v+4
	.byte	W02
	.byte		N36   , Cs5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		PAN   , c_v+24
	.byte		MOD   , 0
	.byte		N24   , En5 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte		MOD   , 9
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 48
	.byte		N06   , En4 , v108
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N24   , Gs4 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N48   , Ds4 
	.byte	W12
	.byte		VOL   , 65*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        64*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        60*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        50*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        68*mus_vs_front_mvl/mxv
	.byte	W72
	.byte		VOICE , 24
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v-12
	.byte	W12
	.byte		N06   , Ds4 , v104
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W22
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		N36   , Bn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte		MOD   , 9
	.byte	W12
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , Ds4 , v108
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N48   , Gs4 
	.byte	W12
	.byte		VOL   , 64*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        60*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        57*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        55*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        49*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        68*mus_vs_front_mvl/mxv
	.byte	W72
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , En5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		VOICE , 48
	.byte		VOL   , 54*mus_vs_front_mvl/mxv
	.byte		N48   , Dn5 
	.byte	W48
	.byte		        Cs5 
	.byte	W48
	.byte		        Cn5 
	.byte	W48
	.byte		        Bn4 
	.byte	W48
	.byte		N24   , Dn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
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
	.byte	W72
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		N06   , An4 , v116
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte		N06   , En5 
	.byte	W18
	.byte		N03   , An4 
	.byte	W06
	.byte		N72   
	.byte	W24
	.byte		VOL   , 53*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        52*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        51*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        47*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		N24   , En5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N72   , Bn4 
	.byte	W24
	.byte		VOL   , 53*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        51*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        50*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        44*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        42*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte	W78
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N72   
	.byte	W24
	.byte		VOL   , 52*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        49*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        36*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		N06   , En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N48   , En5 
	.byte	W24
	.byte		VOL   , 50*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        36*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte	W24
	.byte	W72
	.byte		N08   , An4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		N06   , En5 
	.byte	W18
	.byte		N03   , An4 
	.byte	W06
	.byte		N72   
	.byte	W72
	.byte		PAN   , c_v-22
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N08   , An4 , v116
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N06   , En5 
	.byte	W18
	.byte		N03   , An4 
	.byte	W06
	.byte		N72   
	.byte	W72
	.byte		PAN   , c_v-22
	.byte		N12   , Fs3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte	W96
	.byte	W72
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+13
	.byte		N03   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_vs_front_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_vs_front_2:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_vs_front_mvl/mxv
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		VOICE , 56
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
mus_vs_front_2_B1:
	.byte		VOL   , 80*mus_vs_front_mvl/mxv
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        En4 , v064
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        En4 , v032
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        En4 , v016
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
	.byte		        c_v-32
	.byte		VOL   , 80*mus_vs_front_mvl/mxv
	.byte		N02   , En4 , v088
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N06   , En4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , En4 , v064
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        En4 , v032
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        En4 , v016
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte		N02   , En4 , v088
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gs4 , v064
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gs4 , v016
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte		VOICE , 46
	.byte		VOL   , 50*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N04   , Bn3 , v112
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Bn5 
	.byte	W03
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		N04   , Cs6 
	.byte	W04
	.byte		        Ds6 
	.byte	W04
	.byte		PAN   , c_v+31
	.byte		N04   , Fs6 
	.byte	W04
	.byte		        Ds6 
	.byte	W04
	.byte		        Cs6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Ds5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		N04   , An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		VOICE , 48
	.byte		VOL   , 59*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W12
	.byte		N36   , En4 , v116
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 49*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 60*mus_vs_front_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 49*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 60*mus_vs_front_mvl/mxv
	.byte		N12   , An4 
	.byte	W24
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N96   , Gs4 
	.byte	W48
	.byte		VOL   , 55*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        37*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        36*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        60*mus_vs_front_mvl/mxv
	.byte		N96   , En4 
	.byte	W48
	.byte		VOL   , 55*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        37*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        36*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        60*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N36   
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        60*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fs4 
	.byte	W24
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W24
	.byte		N36   , Bn4 
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 37*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		VOICE , 60
	.byte		PAN   , c_v+7
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		N12   , En4 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 60*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		N12   , En4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        En4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 60*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        En4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Cs4 
	.byte	W12
	.byte	W12
	.byte		N36   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 60*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		N12   , En4 
	.byte	W24
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N96   , Gs4 
	.byte	W36
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 60*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        58*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        55*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        54*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        50*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        46*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        68*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W72
	.byte		VOL   , 59*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v-25
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
mus_vs_front_2_000:
	.byte	W12
	.byte		N12   , Cs3 , v112
	.byte	W36
	.byte		        Bn2 
	.byte	W24
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PEND
mus_vs_front_2_001:
	.byte		MOD   , 0
	.byte		N12   , Cs3 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        Dn3 
	.byte	W24
	.byte		N24   , Bn2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_2_001
	.byte	PATT
	 .word	mus_vs_front_2_000
mus_vs_front_2_002:
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N36   , Fs2 
	.byte	W24
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Ds3 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_2_002
	.byte		N12   , Bn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Cn3 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_2_001
	.byte	W12
	.byte		N12   , Cs3 , v112
	.byte	W36
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Bn2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , An4 
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		PAN   , c_v+4
	.byte		VOL   , 59*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W24
	.byte		VOL   , 49*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        60*mus_vs_front_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		N36   , En4 
	.byte	W24
	.byte		VOL   , 49*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        60*mus_vs_front_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W24
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N96   , En4 
	.byte	W48
	.byte		VOL   , 55*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        37*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        36*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        60*mus_vs_front_mvl/mxv
	.byte		N96   , Cn4 
	.byte	W48
	.byte		VOL   , 55*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        53*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        48*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        37*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        36*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        60*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N36   
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        60*mus_vs_front_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W24
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W24
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        37*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		VOICE , 60
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 47*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 47*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte	W12
	.byte		N36   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 47*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 
	.byte	W24
	.byte		N96   , Dn5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 53*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        51*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        49*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        47*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        45*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        29*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte	W48
	.byte		N06   , Gn3 , v092
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N48   , Gn3 
	.byte	W24
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N48   
	.byte	W48
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N04   , An4 , v088
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W32
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N48   
	.byte	W24
	.byte		VOL   , 51*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        46*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        36*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        30*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 24
	.byte		PAN   , c_v-30
	.byte		VOL   , 63*mus_vs_front_mvl/mxv
	.byte		N08   , Bn3 , v084
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		PAN   , c_v+16
	.byte		N08   , As3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		PAN   , c_v-28
	.byte		N08   , An3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		PAN   , c_v+16
	.byte		N08   , Gs3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		PAN   , c_v-30
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		PAN   , c_v+16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		PAN   , c_v-27
	.byte		N08   , Fn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		VOICE , 56
	.byte		PAN   , c_v-32
	.byte		VOL   , 78*mus_vs_front_mvl/mxv
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	GOTO
	 .word	mus_vs_front_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_vs_front_3:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte	W12
	.byte	W96
	.byte		VOICE , 33
	.byte		PAN   , c_v+0
	.byte		N08   , Fs1 , v096
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		VOICE , 33
	.byte		PAN   , c_v-1
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
mus_vs_front_3_B1:
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v127
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v127
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v127
	.byte	W12
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v127
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
mus_vs_front_3_000:
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 , v127
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_3_000
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		N24   , En2 
	.byte	W24
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		N24   , Gn2 , v127
	.byte	W24
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
mus_vs_front_3_001:
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte	PEND
mus_vs_front_3_002:
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_3_001
	.byte	PATT
	 .word	mus_vs_front_3_002
	.byte	PATT
	 .word	mus_vs_front_3_001
	.byte	PATT
	 .word	mus_vs_front_3_002
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
mus_vs_front_3_003:
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte	PEND
	.byte		N12   
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
mus_vs_front_3_004:
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
mus_vs_front_3_005:
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_3_004
	.byte	PATT
	 .word	mus_vs_front_3_005
	.byte	PATT
	 .word	mus_vs_front_3_004
	.byte	PATT
	 .word	mus_vs_front_3_005
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
mus_vs_front_3_006:
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn0 , v112
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn0 
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_3_006
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Bn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
mus_vs_front_3_007:
	.byte		N12   , Gs1 , v112
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
mus_vs_front_3_008:
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_3_007
	.byte	PATT
	 .word	mus_vs_front_3_008
	.byte	PATT
	 .word	mus_vs_front_3_003
mus_vs_front_3_009:
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_3_003
	.byte	PATT
	 .word	mus_vs_front_3_009
	.byte	PATT
	 .word	mus_vs_front_3_003
	.byte	PATT
	 .word	mus_vs_front_3_009
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , As0 , v112
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , As0 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , As0 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , As0 
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , An0 
	.byte	W12
	.byte		        An1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , An0 
	.byte	W12
	.byte		        An1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , An0 
	.byte	W12
	.byte		        An1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , An0 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   , Gs0 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Gs0 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Gs0 
	.byte	W12
	.byte		        Gs1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Gs0 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		VOL   , 85*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 70*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        85*mus_vs_front_mvl/mxv
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte	W96
mus_vs_front_3_010:
	.byte		N12   , Fn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte	PEND
mus_vs_front_3_011:
	.byte		N12   , Fn2 , v112
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte	PEND
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		        Bn0 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N06   , Cs3 , v080
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , An1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_3_010
	.byte	PATT
	 .word	mus_vs_front_3_011
	.byte		N12   , Fs1 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        An1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte		N08   , Fs1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte	GOTO
	 .word	mus_vs_front_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_vs_front_4:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-20
	.byte		VOL   , 69*mus_vs_front_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		N08   , En2 , v104
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N23   , Bn1 , v112
	.byte	W24
	.byte		N08   , En2 , v104
	.byte	W08
	.byte		        En2 , v064
	.byte	W08
	.byte		        En2 , v068
	.byte	W08
	.byte		        En2 , v056
	.byte	W08
	.byte		        En2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		VOICE , 1
	.byte		PAN   , c_v-33
	.byte		BEND  , c_v+0
	.byte		N08   , Bn3 , v072
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N03   , En4 , v080
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
mus_vs_front_4_B1:
	.byte		VOICE , 38
	.byte		VOL   , 89*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		N12   , An1 , v127
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gs1 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Bn1 , v127
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn2 , v040
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Ds2 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Bn1 , v127
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N36   , Ds2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gs1 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Bn1 , v127
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn2 , v040
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cn2 , v052
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Ds2 , v127
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Fn2 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		VOICE , 60
	.byte		VOL   , 79*mus_vs_front_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , En3 , v064
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N12   , En3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v-24
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , En4 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , En4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	W12
	.byte		N12   , En4 
	.byte	W24
	.byte		        Bn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn4 , v100
	.byte	W12
	.byte		        Gs4 , v108
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		        Bn4 , v108
	.byte	W12
	.byte		        Gs5 , v100
	.byte	W12
	.byte		VOICE , 46
	.byte		PAN   , c_v-32
	.byte		VOL   , 38*mus_vs_front_mvl/mxv
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N03   , Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v-17
	.byte		N03   , Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , En4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N03   , Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-33
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		VOL   , 66*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W72
	.byte		VOICE , 60
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        Fs2 
	.byte	W24
	.byte		N24   , An2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N12   , Gs2 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        An2 
	.byte	W24
	.byte		N24   , Fs2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 66*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
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
	.byte		VOICE , 4
	.byte		VOL   , 37*mus_vs_front_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		PAN   , c_v+24
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		PAN   , c_v-33
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		PAN   , c_v+23
	.byte		N08   , En4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N06   , Gn4 , v068
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v-22
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N12   , Cn4 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		VOL   , 46*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Gn4 , v108
	.byte	W12
	.byte		        En5 , v096
	.byte	W12
	.byte		VOICE , 46
	.byte		PAN   , c_v-32
	.byte		VOL   , 42*mus_vs_front_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N03   , Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-17
	.byte		N03   , Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+15
	.byte		N03   , Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 47
	.byte		VOL   , 78*mus_vs_front_mvl/mxv
	.byte		N08   , Gn2 
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v060
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn2 , v112
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v060
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		VOICE , 60
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W48
	.byte		N06   , An3 , v096
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N72   , Cn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        41*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        29*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N48   , Bn3 
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 44*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W48
	.byte	W96
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte	W48
	.byte		N06   
	.byte	W18
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N72   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Ds4 
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , En4 
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		N04   , Cs4 , v100
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W32
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N48   
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn3 , v096
	.byte	W18
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W18
	.byte		N03   , An3 
	.byte	W06
	.byte		N48   , Fn4 
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W48
	.byte		VOICE , 48
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W18
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W18
	.byte		N03   , An3 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W24
	.byte		VOL   , 48*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        39*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        35*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        32*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		N48   , Cn5 , v112
	.byte	W48
	.byte		N96   , Dn5 
	.byte	W48
	.byte		VOL   , 52*mus_vs_front_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 50*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        46*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        43*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        40*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        38*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        31*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        13*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        12*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-20
	.byte		VOL   , 68*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W96
	.byte	GOTO
	 .word	mus_vs_front_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_vs_front_5:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 87
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W12
	.byte	W96
mus_vs_front_5_000:
	.byte		N05   , Fs1 , v112
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte	PEND
	.byte		        Dn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
mus_vs_front_5_B1:
mus_vs_front_5_001:
	.byte		N03   , An1 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_vs_front_5_002:
	.byte		N03   , An1 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Bn1 
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N09   , Cn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_5_001
	.byte		N03   , An1 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N09   , Dn2 
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N09   , As1 
	.byte	W12
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		BEND  , c_v+1
	.byte		N03   , An1 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_5_002
	.byte	PATT
	 .word	mus_vs_front_5_001
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , An1 , v127
	.byte	W12
	.byte		BEND  , c_v+1
	.byte		N03   , An1 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N09   , Dn2 
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N09   , As1 
	.byte	W12
	.byte		N05   , En1 
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , En2 
	.byte	W24
	.byte		N05   , En1 
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , Fn2 
	.byte	W24
	.byte		N05   , En1 
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , Fs2 
	.byte	W24
	.byte		N05   , En1 
	.byte	W12
	.byte		N05   
	.byte	W12
	.byte		N21   , Gn2 
	.byte	W24
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , En2 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , Fn2 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , Fs2 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , Gn2 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , Gs2 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , An2 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , As2 
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , Bn2 
	.byte	W12
mus_vs_front_5_003:
	.byte		N09   , En1 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte	PEND
mus_vs_front_5_004:
	.byte		N09   , En2 , v112
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_5_003
	.byte	PATT
	 .word	mus_vs_front_5_004
	.byte	PATT
	 .word	mus_vs_front_5_003
	.byte	PATT
	 .word	mus_vs_front_5_004
	.byte		N09   , Dn1 , v112
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N09   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N09   , Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N09   , Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
mus_vs_front_5_005:
	.byte		N09   , Cn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte	PEND
	.byte		N09   
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
mus_vs_front_5_006:
	.byte		N09   , Cs1 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
mus_vs_front_5_007:
	.byte		N09   , Cs1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N03   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N09   , Bn0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_5_006
	.byte	PATT
	 .word	mus_vs_front_5_007
	.byte	PATT
	 .word	mus_vs_front_5_006
	.byte	PATT
	 .word	mus_vs_front_5_007
	.byte		N09   , Cs1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N09   , As0 
	.byte	W12
mus_vs_front_5_008:
	.byte		N09   , Bn0 , v112
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N09   , As0 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_5_008
	.byte		N09   , Cs1 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
mus_vs_front_5_009:
	.byte		N09   , Gs1 , v112
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
mus_vs_front_5_010:
	.byte		N09   , En1 , v112
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_5_009
	.byte	PATT
	 .word	mus_vs_front_5_010
	.byte	PATT
	 .word	mus_vs_front_5_005
mus_vs_front_5_011:
	.byte		N09   , Cn2 , v112
	.byte	W12
	.byte		N03   , Cn1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_5_005
	.byte	PATT
	 .word	mus_vs_front_5_011
	.byte	PATT
	 .word	mus_vs_front_5_005
	.byte	PATT
	 .word	mus_vs_front_5_011
	.byte		N09   , As0 , v112
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N09   , As1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N09   , An0 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N03   , An1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N09   , An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N03   , An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N09   , Gs0 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N03   , Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte	W96
mus_vs_front_5_012:
	.byte		N09   , Fn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte	PEND
mus_vs_front_5_013:
	.byte		N09   , Fn2 , v112
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte	PEND
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N09   , Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N09   , En1 
	.byte	W12
	.byte		        Bn0 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N03   , Cs3 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N09   , An1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_5_012
	.byte	PATT
	 .word	mus_vs_front_5_013
	.byte		N09   , Fs1 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N09   , Fs2 
	.byte	W12
	.byte		        An1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_5_000
	.byte		N05   , Dn1 , v112
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte	GOTO
	 .word	mus_vs_front_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_vs_front_6:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 80*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+20
	.byte		N04   , Bn2 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   , En2 
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        En2 , v084
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		        En2 , v112
	.byte	W08
	.byte		        En2 , v084
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		        En2 , v124
	.byte	W08
	.byte		        En2 , v092
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	W96
	.byte	W96
mus_vs_front_6_B1:
	.byte		VOL   , 90*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+19
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        An1 
	.byte	W84
	.byte		N12   
	.byte	W96
mus_vs_front_6_000:
	.byte		N12   , An1 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte		N12   
	.byte	W96
	.byte		N12   
	.byte	W96
	.byte		N12   
	.byte	W96
	.byte	PATT
	 .word	mus_vs_front_6_000
	.byte		N12   , An1 , v112
	.byte	W96
	.byte		PAN   , c_v-32
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+25
	.byte		N24   , En2 
	.byte	W24
	.byte		PAN   , c_v-31
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+25
	.byte		N24   , Fn2 
	.byte	W24
	.byte		PAN   , c_v-31
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+28
	.byte		N24   , Fs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N08   , En1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		PAN   , c_v+25
	.byte		N24   , Gn2 , v127
	.byte	W24
	.byte		N06   , En2 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N08   , Ds2 
	.byte	W08
	.byte		        Bn1 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		        Bn1 , v084
	.byte	W08
	.byte		        Bn1 , v080
	.byte	W08
	.byte		PAN   , c_v+27
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		        Bn1 , v084
	.byte	W08
	.byte		        Bn1 , v080
	.byte	W08
	.byte		PAN   , c_v-16
	.byte		N08   , Bn1 , v124
	.byte	W08
	.byte		        Bn1 , v092
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		VOL   , 82*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+20
	.byte		N12   , En2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-14
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
mus_vs_front_6_001:
	.byte		PAN   , c_v+20
	.byte		N12   , En2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
mus_vs_front_6_002:
	.byte	W12
	.byte		N12   , En2 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-13
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_6_001
	.byte	PATT
	 .word	mus_vs_front_6_002
	.byte		PAN   , c_v+19
	.byte		N12   , Dn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        An1 
	.byte	W24
mus_vs_front_6_003:
	.byte		N12   , Cs2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N12   , Gs1 
	.byte	W24
	.byte		PAN   , c_v+23
	.byte		N12   , Cn2 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		        Bn1 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-12
	.byte		N12   , Fs1 
	.byte	W24
	.byte		PAN   , c_v+23
	.byte		VOL   , 82*mus_vs_front_mvl/mxv
	.byte		N12   , Gs2 
	.byte	W36
	.byte		        Cs2 
	.byte	W48
	.byte		N06   , Gs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N36   
	.byte	W36
	.byte		        Gs2 
	.byte	W36
	.byte		        Cs2 
	.byte	W48
	.byte		N06   , Gs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
mus_vs_front_6_004:
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
	.byte		N36   , Gs2 
	.byte	W36
	.byte		N48   , Cs2 
	.byte	W48
	.byte		N06   , Gs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_vs_front_6_004
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N48   , Gs2 
	.byte	W48
	.byte		N06   , Gs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N36   , Fs2 
	.byte	W36
	.byte		N48   , Bn1 
	.byte	W48
	.byte		N06   , Bn1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N06   , Bn1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		        Bn1 
	.byte	W24
	.byte		        Fs2 
	.byte	W48
	.byte		N06   , Fs2 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_6_003
	.byte	W12
	.byte		N12   , Cs2 , v112
	.byte	W36
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v+23
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        c_v+16
	.byte		VOL   , 79*mus_vs_front_mvl/mxv
	.byte		N12   , Cn2 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v096
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
mus_vs_front_6_005:
	.byte		N12   , Cn2 , v108
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
mus_vs_front_6_006:
	.byte	W12
	.byte		N12   , Cn2 , v108
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_6_005
	.byte	PATT
	 .word	mus_vs_front_6_006
	.byte		N12   , As1 , v100
	.byte	W36
	.byte		        As1 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        An1 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        Gs1 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		        Gn1 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N08   , Gn2 , v064
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v116
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gn2 , v064
	.byte	W08
	.byte		        Gn2 , v032
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Dn2 , v116
	.byte	W08
	.byte		        Gn2 , v084
	.byte	W08
	.byte		N08   
	.byte	W08
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
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_vs_front_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_vs_front_7:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v-64
	.byte	W12
	.byte	W96
mus_vs_front_7_000:
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte	PEND
mus_vs_front_7_001:
	.byte		N24   , Gn4 , v112
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte	PEND
mus_vs_front_7_B1:
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W24
	.byte		N12   , Fn2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W24
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N36   , Cn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W24
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N36   , En3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W24
	.byte		N24   , Bn2 
	.byte	W48
	.byte		        Cn3 
	.byte	W24
	.byte	W24
	.byte		        Cs3 
	.byte	W48
	.byte		        Dn3 
	.byte	W24
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W12
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W36
	.byte		N12   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N12   , Cs4 
	.byte	W24
	.byte		N24   , En4 
	.byte	W24
	.byte		N96   , Bn3 
	.byte	W96
	.byte		        Gs3 
	.byte	W96
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N12   , An3 
	.byte	W24
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W24
	.byte		N36   , En4 
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , En3 
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Gs3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , En3 
	.byte	W36
	.byte		N12   , Gs3 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        An3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W36
	.byte		N12   , Gs3 
	.byte	W24
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N96   , Cs4 
	.byte	W36
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 28*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        8*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        6*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        4*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        2*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        2*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+0
	.byte	W84
	.byte		N06   , Gs3 , v092
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte		N36   , Gs4 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        45*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Cs5 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 9
	.byte	W12
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Bn3 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W72
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W24
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 9
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N48   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W24
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W48
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v-64
	.byte		N12   , Cs4 , v112
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N36   , En3 
	.byte	W36
	.byte		N12   , Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N12   , An3 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N96   , Gn3 
	.byte	W96
	.byte		        En3 
	.byte	W96
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N12   , Fn3 
	.byte	W24
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        En4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N12   , En4 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Fn4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N12   , En4 
	.byte	W24
	.byte		N96   , Gn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 31*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        18*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        13*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N06   , Cn5 
	.byte	W18
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N72   
	.byte	W24
	.byte		VOL   , 30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        29*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        23*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        13*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        12*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		N24   , Cn5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		VOICE , 85
	.byte		N24   , Gn2 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		VOICE , 80
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W18
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N72   
	.byte	W24
	.byte		VOL   , 29*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        23*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        12*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N48   , Cs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        29*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        18*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		VOICE , 85
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N02   , En3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W08
	.byte		N02   , Dn3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte	W12
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N06   , Cn5 
	.byte	W18
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N36   
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		N06   , Cn5 
	.byte	W18
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N36   
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_7_000
	.byte	PATT
	 .word	mus_vs_front_7_001
	.byte	GOTO
	 .word	mus_vs_front_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_vs_front_8:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 35*mus_vs_front_mvl/mxv
	.byte	W12
	.byte	W96
	.byte		VOICE , 83
	.byte		PAN   , c_v-64
	.byte		VOL   , 56*mus_vs_front_mvl/mxv
	.byte		N04   , Cn1 , v112
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Fs1 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Cn2 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Cs1 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , Gn1 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Cs2 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Dn1 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Gs1 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , Dn2 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Ds1 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , An1 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Ds2 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , En1 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , As1 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , En2 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Fn1 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , Bn1 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Fn2 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Fs1 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Cn2 
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , Fs2 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Gn1 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Cs2 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N04   , Gn2 
	.byte	W08
mus_vs_front_8_B1:
	.byte		VOICE , 83
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        Gs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N36   , Ds3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte	W24
	.byte		N24   , Gs2 
	.byte	W48
	.byte		        An2 
	.byte	W24
	.byte	W24
	.byte		        As2 
	.byte	W48
	.byte		        Bn2 
	.byte	W24
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W12
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N12   , Cs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N36   , Ds4 
	.byte	W36
	.byte		N12   , En4 
	.byte	W24
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N96   , En4 
	.byte	W96
	.byte		        Bn3 
	.byte	W96
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N12   , Cs4 
	.byte	W24
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , En4 
	.byte	W24
	.byte		N36   , Gs4 
	.byte	W36
mus_vs_front_8_000:
	.byte		N12   , Bn3 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N12   , Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte	PATT
	 .word	mus_vs_front_8_000
	.byte	W12
	.byte		N36   , Gs3 , v112
	.byte	W36
	.byte		N12   , Bn3 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Cn4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N96   , En4 
	.byte	W36
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 29*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        23*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        13*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        9*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        8*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        5*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        2*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W96
	.byte		N12   , Gs2 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
mus_vs_front_8_001:
	.byte	W12
	.byte		N12   , Gs2 , v112
	.byte	W36
	.byte		        Fs2 
	.byte	W24
	.byte		N24   , An2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PEND
mus_vs_front_8_002:
	.byte		MOD   , 0
	.byte		N12   , Gs2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        An2 
	.byte	W24
	.byte		N24   , Fs2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_8_002
	.byte	PATT
	 .word	mus_vs_front_8_001
mus_vs_front_8_003:
	.byte		MOD   , 0
	.byte		N12   , Fs2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N36   , Ds2 
	.byte	W24
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_8_003
	.byte		N12   , Fs2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Gn2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_8_002
	.byte	W12
	.byte		N12   , Gs2 , v112
	.byte	W36
	.byte		N24   , An2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Fs2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		MOD   , 9
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N48   , Bn4 
	.byte	W48
	.byte		        As4 
	.byte	W48
	.byte		        An4 
	.byte	W48
	.byte		        Gs4 
	.byte	W48
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N12   , An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W24
	.byte		N24   , En4 
	.byte	W24
	.byte		N96   , Cn4 
	.byte	W96
	.byte		        Gn3 
	.byte	W96
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N12   , An3 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W24
	.byte		N36   , En4 
	.byte	W36
mus_vs_front_8_004:
	.byte		N12   , Gn4 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	W12
	.byte		N36   , Ds4 
	.byte	W36
	.byte		N12   , Gn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	PATT
	 .word	mus_vs_front_8_004
	.byte	W12
	.byte		N36   , En4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Gs4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W01
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N12   
	.byte	W24
	.byte		N96   , Bn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 30*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        29*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        27*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        20*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        16*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        13*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        12*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        11*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        10*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W24
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N12   , An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		VOICE , 82
	.byte		N24   , Dn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N48   
	.byte	W48
	.byte		VOICE , 83
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		VOICE , 82
	.byte		N02   , An2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W08
	.byte		N02   , Gn2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 22*mus_vs_front_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOICE , 83
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W36
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W18
	.byte		N03   , An3 
	.byte	W06
	.byte		N72   
	.byte	W12
	.byte		VOL   , 31*mus_vs_front_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 30*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        29*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        28*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        25*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        24*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        22*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        13*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        12*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        10*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        8*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        7*mus_vs_front_mvl/mxv
	.byte	W10
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_vs_front_mvl/mxv
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W36
	.byte		        Fs3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W18
	.byte		N03   , An3 
	.byte	W06
	.byte		N48   
	.byte	W12
	.byte		VOL   , 28*mus_vs_front_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 26*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        23*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        21*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        19*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        17*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        15*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        14*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        12*mus_vs_front_mvl/mxv
	.byte	W02
	.byte		        10*mus_vs_front_mvl/mxv
	.byte	W04
	.byte		        7*mus_vs_front_mvl/mxv
	.byte	W06
	.byte		        34*mus_vs_front_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_vs_front_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_vs_front_9:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 0
	.byte		VOL   , 79*mus_vs_front_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte		N24   , An2 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		N06   , Cn1 
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        En2 , v127
	.byte	W24
	.byte		N08   , Dn2 , v096
	.byte	W08
	.byte		        Dn2 , v092
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 , v092
	.byte	W08
	.byte		N24   , Cn3 , v124
	.byte	W24
mus_vs_front_9_B1:
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N24   , An2 , v112
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        En2 , v127
	.byte	W24
mus_vs_front_9_000:
	.byte		N06   , Cn1 , v112
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
mus_vs_front_9_001:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte		        Cn1 
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W36
	.byte	PATT
	 .word	mus_vs_front_9_001
	.byte	PATT
	 .word	mus_vs_front_9_000
	.byte	PATT
	 .word	mus_vs_front_9_001
	.byte		N06   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_9_001
	.byte	PATT
	 .word	mus_vs_front_9_001
	.byte		N06   , Cn1 , v112
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		N24   , Cn3 , v127
	.byte	W24
	.byte	GOTO
	 .word	mus_vs_front_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_vs_front_10:
	.byte	KEYSH , mus_vs_front_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 45*mus_vs_front_mvl/mxv
	.byte	W12
	.byte	W96
mus_vs_front_10_000:
	.byte		N02   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_10_000
mus_vs_front_10_B1:
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
mus_vs_front_10_001:
	.byte		N02   , Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte	PATT
	 .word	mus_vs_front_10_001
	.byte		VOL   , 55*mus_vs_front_mvl/mxv
	.byte		N02   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte		VOL   , 44*mus_vs_front_mvl/mxv
	.byte		N02   , Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v016
	.byte	W12
	.byte	PATT
	 .word	mus_vs_front_10_000
	.byte	GOTO
	 .word	mus_vs_front_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_vs_front:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_vs_front_pri	@ Priority
	.byte	mus_vs_front_rev	@ Reverb.

	.word	mus_vs_front_grp

	.word	mus_vs_front_1
	.word	mus_vs_front_2
	.word	mus_vs_front_3
	.word	mus_vs_front_4
	.word	mus_vs_front_5
	.word	mus_vs_front_6
	.word	mus_vs_front_7
	.word	mus_vs_front_8
	.word	mus_vs_front_9
	.word	mus_vs_front_10

	.end
