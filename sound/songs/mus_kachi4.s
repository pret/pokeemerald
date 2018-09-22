	.include "MPlayDef.s"

	.equ	mus_kachi4_grp, voicegroup070
	.equ	mus_kachi4_pri, 0
	.equ	mus_kachi4_rev, reverb_set+50
	.equ	mus_kachi4_mvl, 127
	.equ	mus_kachi4_key, 0
	.equ	mus_kachi4_tbs, 1
	.equ	mus_kachi4_exg, 0
	.equ	mus_kachi4_cmp, 1

	.section .rodata
	.global	mus_kachi4
	.align	2

@********************** Track  1 **********************@

mus_kachi4_1:
	.byte	KEYSH , mus_kachi4_key+0
	.byte	TEMPO , 142*mus_kachi4_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 44*mus_kachi4_mvl/mxv
	.byte	W08
	.byte	W08
	.byte	W96
	.byte	W96
mus_kachi4_1_B1:
	.byte		VOICE , 127
	.byte		N04   , En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v092
	.byte	W12
	.byte		VOICE , 127
	.byte		N04   , En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		N04   , En5 , v080
	.byte	W04
	.byte		VOICE , 127
	.byte	W02
	.byte		N04   
	.byte	W06
mus_kachi4_1_000:
	.byte		N04   , En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		VOICE , 127
	.byte		N04   , En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        En5 , v096
	.byte	W04
	.byte		        En5 , v064
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		N04   , En5 , v080
	.byte	W04
	.byte		VOICE , 127
	.byte	W02
	.byte		N04   
	.byte	W06
	.byte	PEND
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v092
	.byte	W12
	.byte		VOICE , 127
	.byte		N04   , En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        En5 , v096
	.byte	W12
	.byte		        En5 , v080
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 126
	.byte		N12   , Gn5 , v096
	.byte	W12
	.byte		N04   , En5 , v080
	.byte	W04
	.byte		VOICE , 127
	.byte	W02
	.byte		N04   
	.byte	W06
	.byte	PATT
	 .word	mus_kachi4_1_000
	.byte	GOTO
	 .word	mus_kachi4_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_kachi4_2:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 82*mus_kachi4_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W08
	.byte	W08
	.byte	W48
	.byte	W02
	.byte		N22   , Fn3 , v112
	.byte	W22
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        Ds4 , v096
	.byte	W24
mus_kachi4_2_B1:
	.byte		VOICE , 24
	.byte		VOL   , 48*mus_kachi4_mvl/mxv
	.byte	W02
	.byte		N44   , Fn4 , v112
	.byte	W48
	.byte		N04   , An4 
	.byte	W04
	.byte		N08   , An4 , v036
	.byte	W08
	.byte		N04   , Gn4 , v112
	.byte	W04
	.byte		N08   , Gn4 , v036
	.byte	W08
	.byte		N04   , Fn4 , v112
	.byte	W04
	.byte		N08   , Fn4 , v036
	.byte	W08
	.byte		N04   , Gn4 , v112
	.byte	W04
	.byte		N08   , Gn4 , v036
	.byte	W06
	.byte	W02
	.byte		N32   , Dn4 , v112
	.byte	W32
	.byte	W02
	.byte		N04   , Gn4 
	.byte	W04
	.byte		N08   , Gn4 , v036
	.byte	W10
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte		N04   , An4 
	.byte	W04
	.byte		N08   , An4 , v036
	.byte	W08
	.byte		N04   , Gn4 , v112
	.byte	W04
	.byte		N08   , Gn4 , v036
	.byte	W06
	.byte	W02
	.byte		N44   , Fn4 , v112
	.byte	W48
	.byte		N10   , An4 
	.byte	W12
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N10   , Cn4 
	.byte	W10
	.byte	W02
	.byte		N04   , Bn3 
	.byte	W04
	.byte		N08   , Bn3 , v036
	.byte	W08
	.byte		N04   , Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v036
	.byte	W02
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v036
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W04
	.byte		N22   , Gn4 , v112
	.byte	W22
	.byte		N04   , Fn4 
	.byte	W04
	.byte		N08   , Fn4 , v036
	.byte	W10
	.byte		N04   , Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v036
	.byte	W06
	.byte	GOTO
	 .word	mus_kachi4_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_kachi4_3:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 85*mus_kachi4_mvl/mxv
	.byte		PAN   , c_v+14
	.byte	W08
	.byte	W08
	.byte		N06   , Cn4 , v120
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N04   , Gn4 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Gs4 , v096
	.byte	W24
mus_kachi4_3_B1:
	.byte		VOICE , 24
	.byte		VOL   , 63*mus_kachi4_mvl/mxv
	.byte		N48   , An4 , v112
	.byte	W48
	.byte		N04   , Dn5 
	.byte	W04
	.byte		N08   , Dn5 , v036
	.byte	W08
	.byte		N04   , Cn5 , v112
	.byte	W04
	.byte		N08   , Cn5 , v036
	.byte	W08
	.byte		N04   , Bn4 , v112
	.byte	W04
	.byte		N08   , Bn4 , v036
	.byte	W08
	.byte		N04   , Cn5 , v112
	.byte	W04
	.byte		N08   , Cn5 , v036
	.byte	W08
	.byte		N36   , Gn4 , v112
	.byte	W36
	.byte		N04   , Bn4 
	.byte	W04
	.byte		N08   , Bn4 , v036
	.byte	W08
	.byte		N24   , Gn5 , v112
	.byte	W24
	.byte		N04   , Fn5 
	.byte	W04
	.byte		N08   , Fn5 , v036
	.byte	W08
	.byte		N04   , En5 , v112
	.byte	W04
	.byte		N08   , En5 , v036
	.byte	W08
	.byte		N48   , An4 , v112
	.byte	W48
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N04   , Gn4 
	.byte	W04
	.byte		N08   , Gn4 , v036
	.byte	W08
	.byte		N04   , Dn4 , v112
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W04
	.byte		        Bn4 , v036
	.byte	W04
	.byte		        Gn4 , v112
	.byte	W04
	.byte		        Gn4 , v036
	.byte	W04
	.byte		        Bn4 , v112
	.byte	W04
	.byte		        Bn4 , v036
	.byte	W04
	.byte		N24   , Dn5 , v112
	.byte	W24
	.byte		N04   , Cn5 
	.byte	W04
	.byte		N08   , Cn5 , v036
	.byte	W08
	.byte		N04   , Bn4 , v112
	.byte	W04
	.byte		N08   , Bn4 , v036
	.byte	W08
	.byte	GOTO
	 .word	mus_kachi4_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_kachi4_4:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 88*mus_kachi4_mvl/mxv
	.byte	W08
	.byte		N02   , Fn2 , v108
	.byte	W04
	.byte		        Fn2 , v092
	.byte	W04
	.byte	W02
	.byte		N04   , Fn2 , v112
	.byte	W36
	.byte	W02
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        Fs1 
	.byte	W24
mus_kachi4_4_B1:
	.byte		VOICE , 48
	.byte		VOL   , 35*mus_kachi4_mvl/mxv
	.byte		N72   , Cn3 , v112
	.byte	W72
	.byte		N08   , An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N72   , Bn2 
	.byte	W72
	.byte		N08   , Gn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		N72   , Fn2 
	.byte	W72
	.byte		N08   , Dn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N72   , Bn2 
	.byte	W72
	.byte		N08   , Gn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte	GOTO
	 .word	mus_kachi4_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_kachi4_5:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 41*mus_kachi4_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W08
	.byte	W08
	.byte		N06   , Cn3 , v096
	.byte	W12
	.byte		        An2 , v112
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N48   , Fn3 
	.byte	W48
	.byte		N24   , As3 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
mus_kachi4_5_B1:
mus_kachi4_5_000:
	.byte	W12
	.byte		N04   , An3 , v112
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		        As3 
	.byte	W12
	.byte	PEND
mus_kachi4_5_001:
	.byte	W12
	.byte		N04   , Bn3 , v112
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		        As3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kachi4_5_000
	.byte	PATT
	 .word	mus_kachi4_5_001
	.byte	GOTO
	 .word	mus_kachi4_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_kachi4_6:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 58*mus_kachi4_mvl/mxv
	.byte	W02
	.byte		        55*mus_kachi4_mvl/mxv
	.byte	W06
	.byte	W08
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N48   , Fn1 
	.byte	W48
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N04   , Gn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		        Fs1 
	.byte	W24
mus_kachi4_6_B1:
mus_kachi4_6_000:
	.byte		N04   , Fn1 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		N04   
	.byte	W12
	.byte	PATT
	 .word	mus_kachi4_6_000
	.byte		N04   , Gn1 , v112
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte	GOTO
	 .word	mus_kachi4_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_kachi4_7:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		VOICE , 0
	.byte		VOL   , 65*mus_kachi4_mvl/mxv
	.byte	W08
	.byte	W08
	.byte		N48   , An2 , v112
	.byte	W96
	.byte	W96
mus_kachi4_7_B1:
mus_kachi4_7_000:
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W36
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte	PATT
	 .word	mus_kachi4_7_000
	.byte		N04   , Dn1 , v088
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W12
	.byte	GOTO
	 .word	mus_kachi4_7_B1
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

mus_kachi4_8:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 41*mus_kachi4_mvl/mxv
	.byte		PAN   , c_v-64
	.byte	W08
	.byte	W08
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N48   , Cn5 
	.byte	W48
	.byte		N24   , Fs5 
	.byte	W24
	.byte	W96
mus_kachi4_8_B1:
mus_kachi4_8_000:
	.byte	W12
	.byte		N04   , Cn3 , v112
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		        Cs3 
	.byte	W12
	.byte	PEND
mus_kachi4_8_001:
	.byte	W12
	.byte		N04   , Dn3 , v112
	.byte	W06
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		        Cs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_kachi4_8_000
	.byte	PATT
	 .word	mus_kachi4_8_001
	.byte	GOTO
	 .word	mus_kachi4_8_B1
	.byte	W96
	.byte	FINE

@********************** Track  9 **********************@

mus_kachi4_9:
	.byte	KEYSH , mus_kachi4_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 37*mus_kachi4_mvl/mxv
	.byte	W03
	.byte		VOICE , 46
	.byte	W05
	.byte	W08
	.byte		PAN   , c_v-40
	.byte		N04   , Fn4 , v112
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Fn5 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		PAN   , c_v+43
	.byte		N04   , Fn6 
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Fn5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v-40
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Fn5 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Cn6 
	.byte	W04
	.byte		PAN   , c_v+38
	.byte		N04   , Fs6 
	.byte	W04
	.byte		        Cs6 
	.byte	W04
	.byte		        As5 
	.byte	W04
	.byte		PAN   , c_v-7
	.byte		N04   , Fs5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v-38
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v-24
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Dn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		PAN   , c_v+43
	.byte		N04   , Gn6 
	.byte	W04
	.byte		        Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		PAN   , c_v+13
	.byte		N04   , Dn6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		PAN   , c_v-8
	.byte		N04   , Cn6 
	.byte	W04
	.byte		        Gs5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		N04   , Gs5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
mus_kachi4_9_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_kachi4_9_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_kachi4:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_kachi4_pri	@ Priority
	.byte	mus_kachi4_rev	@ Reverb.

	.word	mus_kachi4_grp

	.word	mus_kachi4_1
	.word	mus_kachi4_2
	.word	mus_kachi4_3
	.word	mus_kachi4_4
	.word	mus_kachi4_5
	.word	mus_kachi4_6
	.word	mus_kachi4_7
	.word	mus_kachi4_8
	.word	mus_kachi4_9

	.end
