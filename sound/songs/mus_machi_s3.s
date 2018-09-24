	.include "MPlayDef.s"

	.equ	mus_machi_s3_grp, voicegroup032
	.equ	mus_machi_s3_pri, 0
	.equ	mus_machi_s3_rev, reverb_set+50
	.equ	mus_machi_s3_mvl, 127
	.equ	mus_machi_s3_key, 0
	.equ	mus_machi_s3_tbs, 1
	.equ	mus_machi_s3_exg, 0
	.equ	mus_machi_s3_cmp, 1

	.section .rodata
	.global	mus_machi_s3
	.align	2

@********************** Track  1 **********************@

mus_machi_s3_1:
	.byte	KEYSH , mus_machi_s3_key+0
	.byte	TEMPO , 128*mus_machi_s3_tbs/2
	.byte		VOICE , 73
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		LFOS  , 36
	.byte		PAN   , c_v-5
	.byte		N08   , Fn4 , v112
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		        Gn3 
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N72   , Cn4 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s3_mvl/mxv
	.byte		MOD   , 7
	.byte	W08
	.byte		VOL   , 70*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		        63*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		        55*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		        45*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        36*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        26*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        13*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W24
mus_machi_s3_1_B1:
mus_machi_s3_1_000:
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , Fn3 , v112
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N16   , Cn4 
	.byte	W08
	.byte		VOL   , 68*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        49*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		        80*mus_machi_s3_mvl/mxv
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W16
	.byte		        Fn4 
	.byte	W08
	.byte	PEND
mus_machi_s3_1_001:
	.byte		N32   , Gn4 , v112
	.byte	W16
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N44   , Fn4 
	.byte	W20
	.byte		VOL   , 72*mus_machi_s3_mvl/mxv
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 62*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        52*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        39*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        24*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        8*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W12
	.byte	PEND
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N32   , Gn4 
	.byte	W16
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N20   , Fn4 
	.byte	W08
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W04
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N84   , Cn4 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 70*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		        63*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		        55*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		        45*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        36*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        26*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        13*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , As3 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N16   , Gn3 
	.byte	W08
	.byte		VOL   , 68*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        49*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		        80*mus_machi_s3_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		N44   , Cn4 
	.byte	W16
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 72*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        62*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        52*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        39*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        24*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        8*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , Dn4 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N16   , As3 
	.byte	W08
	.byte		VOL   , 68*mus_machi_s3_mvl/mxv
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 49*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W16
	.byte		        Fn4 
	.byte	W08
	.byte		N84   , En4 
	.byte	W24
	.byte		VOL   , 75*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 70*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		        63*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		        55*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		        45*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        36*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        26*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        13*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W12
	.byte	PATT
	 .word	mus_machi_s3_1_000
	.byte	PATT
	 .word	mus_machi_s3_1_001
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N36   , Gn4 , v112
	.byte	W16
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W08
	.byte		VOL   , 68*mus_machi_s3_mvl/mxv
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 49*mus_machi_s3_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte	W04
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , En4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N84   , An4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 72*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        62*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        52*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        39*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        24*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		        8*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , As4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        As4 
	.byte	W16
	.byte		N16   , Dn4 
	.byte	W08
	.byte		VOL   , 68*mus_machi_s3_mvl/mxv
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 49*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte		N08   , As4 
	.byte	W08
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W08
	.byte		VOL   , 68*mus_machi_s3_mvl/mxv
	.byte		MOD   , 7
	.byte	W04
	.byte		VOL   , 49*mus_machi_s3_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , An3 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		N68   , Cn4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W32
	.byte		        0
	.byte	W04
	.byte		N08   
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		N84   , En4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s3_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_machi_s3_2:
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte	KEYSH , mus_machi_s3_key+0
	.byte		VOICE , 35
	.byte		PAN   , c_v+7
	.byte		N04   , Fn1 , v100
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Cn2 
	.byte	W16
	.byte		        Fn1 
	.byte	W08
	.byte		N16   
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Dn1 
	.byte	W16
	.byte		N08   , En1 
	.byte	W08
mus_machi_s3_2_B1:
	.byte		N36   , Fn1 , v100
	.byte	W40
	.byte		N08   
	.byte	W48
	.byte		N08   
	.byte	W08
	.byte		N04   , As1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Dn2 
	.byte	W16
	.byte		        As1 
	.byte	W08
	.byte		N16   
	.byte	W40
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N36   , As1 
	.byte	W40
	.byte		N08   
	.byte	W48
	.byte		N08   
	.byte	W08
	.byte		N04   , Fn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W16
	.byte		N04   , Fn1 
	.byte	W08
	.byte		N16   
	.byte	W40
	.byte		N08   , An1 
	.byte	W08
	.byte		        Gn1 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An1 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        An1 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , As1 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        As1 
	.byte	W16
	.byte		        Dn2 
	.byte	W08
	.byte		N16   , Cn2 
	.byte	W16
	.byte		N08   , As1 
	.byte	W08
	.byte		N12   , Cn2 
	.byte	W16
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		VOICE , 35
	.byte		N36   , Fn1 
	.byte	W40
	.byte		N08   
	.byte	W48
	.byte		N08   
	.byte	W08
	.byte		N04   , As1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Dn2 
	.byte	W16
	.byte		        As1 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N08   , Fn1 
	.byte	W08
	.byte		N36   , As1 
	.byte	W40
	.byte		N08   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N04   , Gn1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W16
	.byte		N04   , Fn1 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Gn1 
	.byte	W16
	.byte		N08   , An1 
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		        Gn1 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   , As1 
	.byte	W08
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		        Fn1 
	.byte	W08
	.byte		N36   , Cn2 
	.byte	W40
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N08   
	.byte	W24
	.byte		        Cn1 
	.byte	W08
	.byte		N16   , Dn1 
	.byte	W16
	.byte		N08   , En1 
	.byte	W08
	.byte	GOTO
	 .word	mus_machi_s3_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_machi_s3_3:
	.byte	KEYSH , mus_machi_s3_key+0
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte	W96
	.byte		PAN   , c_v-8
	.byte	W64
	.byte		VOICE , 1
	.byte		N08   , Cn2 , v088
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
mus_machi_s3_3_B1:
mus_machi_s3_3_000:
	.byte		N16   , Fn2 , v088
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_machi_s3_3_001:
	.byte		N04   , As2 , v088
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_machi_s3_3_002:
	.byte		N16   , As2 , v088
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N08   , As2 , v096
	.byte	W08
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , As2 
	.byte	W08
	.byte	PEND
mus_machi_s3_3_003:
	.byte		N16   , An2 , v088
	.byte	W16
	.byte		N04   , Fn2 
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N04   , An2 
	.byte	W08
	.byte	PEND
	.byte		N08   , As2 
	.byte	W16
	.byte		        An2 
	.byte	W08
	.byte		        As2 
	.byte	W16
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N08   , Dn3 , v096
	.byte	W08
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , As2 
	.byte	W08
	.byte		        Cn3 , v088
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        An2 
	.byte	W16
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N08   , As2 
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W16
	.byte		        Gn2 
	.byte	W08
	.byte		        As2 
	.byte	W16
	.byte		N16   , Dn3 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        En3 
	.byte	W16
	.byte		        Dn3 
	.byte	W08
	.byte		N12   , Cn3 
	.byte	W16
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        As3 , v096
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte	PATT
	 .word	mus_machi_s3_3_000
	.byte	PATT
	 .word	mus_machi_s3_3_001
	.byte	PATT
	 .word	mus_machi_s3_3_002
	.byte	PATT
	 .word	mus_machi_s3_3_003
	.byte		N08   , As2 , v088
	.byte	W16
	.byte		        An2 
	.byte	W08
	.byte		        As2 
	.byte	W16
	.byte		N16   , Dn3 
	.byte	W24
	.byte		N08   , Gn2 
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , As2 
	.byte	W08
	.byte		        An2 
	.byte	W16
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W16
	.byte		        En3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W48
	.byte		        Cn3 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W24
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte	GOTO
	 .word	mus_machi_s3_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_machi_s3_4:
	.byte	KEYSH , mus_machi_s3_key+0
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte		PAN   , c_v+48
	.byte	W96
	.byte	W64
	.byte		VOICE , 7
	.byte		N04   , Gn2 , v052
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , As2 
	.byte	W08
mus_machi_s3_4_B1:
mus_machi_s3_4_000:
	.byte		N24   , Cn3 , v052
	.byte	W24
	.byte		N04   , Fn3 
	.byte	W16
	.byte		        Cn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte	PEND
mus_machi_s3_4_001:
	.byte		N04   , Fn3 , v052
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		        Fn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Fn3 
	.byte	W08
	.byte	PEND
mus_machi_s3_4_002:
	.byte		N24   , Cs4 , v052
	.byte	W24
	.byte		N04   , Fn3 
	.byte	W16
	.byte		N20   , Cn4 
	.byte	W24
	.byte		N32   , As3 
	.byte	W32
	.byte	PEND
mus_machi_s3_4_003:
	.byte		N04   , Fn3 , v052
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		        Fn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Fn3 
	.byte	W08
	.byte	PEND
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N24   , As3 
	.byte	W48
	.byte		N04   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N24   , Cn4 
	.byte	W48
	.byte		N04   , As3 , v044
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W16
	.byte		N16   , As2 
	.byte	W24
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		N08   , En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte	PATT
	 .word	mus_machi_s3_4_000
	.byte	PATT
	 .word	mus_machi_s3_4_001
	.byte	PATT
	 .word	mus_machi_s3_4_002
	.byte	PATT
	 .word	mus_machi_s3_4_003
	.byte		N08   , Gn4 , v052
	.byte	W16
	.byte		        Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W16
	.byte		N16   , As3 
	.byte	W56
	.byte		N08   , Fn4 
	.byte	W16
	.byte		N04   , An3 
	.byte	W08
	.byte		N08   , En4 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W48
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N24   , Cn4 
	.byte	W48
	.byte		N04   , En4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , As2 
	.byte	W08
	.byte	GOTO
	 .word	mus_machi_s3_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_machi_s3_5:
	.byte	KEYSH , mus_machi_s3_key+0
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte		PAN   , c_v-1
	.byte	W96
	.byte	W64
	.byte		VOICE , 8
	.byte		N04   , En2 , v052
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
mus_machi_s3_5_B1:
mus_machi_s3_5_000:
	.byte		N24   , An2 , v052
	.byte	W24
	.byte		N04   , Cn3 
	.byte	W16
	.byte		        An2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N04   , An2 
	.byte	W08
	.byte	PEND
mus_machi_s3_5_001:
	.byte		N04   , Dn3 , v052
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Fn3 
	.byte	W16
	.byte		        Dn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte	PEND
mus_machi_s3_5_002:
	.byte		N24   , As3 , v052
	.byte	W24
	.byte		N04   , Cs3 
	.byte	W16
	.byte		N20   , An3 
	.byte	W24
	.byte		N32   , Fn3 
	.byte	W32
	.byte	PEND
mus_machi_s3_5_003:
	.byte		N04   , Cn3 , v052
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Fn3 
	.byte	W16
	.byte		        Cn3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte	PEND
	.byte		        As3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N24   , Gn3 
	.byte	W48
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N24   , An3 
	.byte	W48
	.byte		N04   , Fn3 , v044
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		N16   , Fn2 
	.byte	W24
	.byte		N04   , As3 
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		        Gn3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En3 
	.byte	W16
	.byte		        Gn3 
	.byte	W08
	.byte		N08   , Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte	PATT
	 .word	mus_machi_s3_5_000
	.byte	PATT
	 .word	mus_machi_s3_5_001
	.byte	PATT
	 .word	mus_machi_s3_5_002
	.byte	PATT
	 .word	mus_machi_s3_5_003
	.byte		N08   , Dn4 , v052
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N16   , Gn3 
	.byte	W56
	.byte		N08   , Dn4 
	.byte	W16
	.byte		N04   , Fn3 
	.byte	W08
	.byte		N08   , Cn4 
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W48
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N24   , Gn3 
	.byte	W48
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte	GOTO
	 .word	mus_machi_s3_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_machi_s3_6:
	.byte	KEYSH , mus_machi_s3_key+0
	.byte		LFOS  , 36
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte	W96
	.byte	W96
mus_machi_s3_6_B1:
	.byte		VOICE , 74
	.byte	W96
	.byte	W96
	.byte		N32   , Cs5 , v048
	.byte	W16
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N20   , Cn5 
	.byte	W08
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W04
	.byte		N08   , As4 
	.byte	W08
	.byte		        Cn5 
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		N84   , An4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 60*mus_machi_s3_mvl/mxv
	.byte	W24
	.byte		        40*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , As2 
	.byte	W16
	.byte		        An2 
	.byte	W08
	.byte		        As2 
	.byte	W16
	.byte		N16   , Gn2 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        An2 
	.byte	W16
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        An2 
	.byte	W16
	.byte		N32   , Cn3 
	.byte	W24
	.byte		VOL   , 60*mus_machi_s3_mvl/mxv
	.byte	W32
	.byte		VOICE , 74
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , As4 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        As4 
	.byte	W16
	.byte		N16   , Fn4 
	.byte	W08
	.byte		MOD   , 7
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N08   , Dn5 
	.byte	W08
	.byte		        En5 
	.byte	W16
	.byte		        Dn5 
	.byte	W08
mus_machi_s3_6_000:
	.byte		N84   , Cn5 , v048
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 60*mus_machi_s3_mvl/mxv
	.byte	W24
	.byte		        40*mus_machi_s3_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte	PEND
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		N36   , As4 
	.byte	W16
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N16   , An4 
	.byte	W08
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W04
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W16
	.byte		N08   , As4 
	.byte	W08
	.byte	PATT
	 .word	mus_machi_s3_6_000
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte		N08   , As3 , v052
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N16   , Dn3 
	.byte	W24
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N16   , Fn3 
	.byte	W24
	.byte		VOICE , 74
	.byte		N08   , Dn4 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		N68   , Fn4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W32
	.byte		        0
	.byte	W04
	.byte		N08   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N84   , Gn4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s3_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_machi_s3_7:
	.byte	KEYSH , mus_machi_s3_key+0
	.byte		VOICE , 127
	.byte		VOL   , 75*mus_machi_s3_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N08   , Gs4 , v052
	.byte	W24
	.byte		VOICE , 126
	.byte		N10   , Gs4 , v040
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W48
	.byte		N08   
	.byte	W24
	.byte		VOICE , 126
	.byte		N10   , Gs4 , v040
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W24
	.byte		VOICE , 126
	.byte		N10   , Gs4 , v040
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   
	.byte	W08
mus_machi_s3_7_B1:
	.byte		VOICE , 125
	.byte		N08   , Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Fs4 , v052
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Fs4 , v052
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
mus_machi_s3_7_000:
	.byte		N08   , Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Fs4 , v052
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Fs4 , v052
	.byte	W08
	.byte		        Gs4 , v020
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s3_7_000
	.byte	PATT
	 .word	mus_machi_s3_7_000
	.byte	PATT
	 .word	mus_machi_s3_7_000
	.byte	PATT
	 .word	mus_machi_s3_7_000
	.byte	PATT
	 .word	mus_machi_s3_7_000
	.byte	PATT
	 .word	mus_machi_s3_7_000
	.byte		VOICE , 127
	.byte		N08   , Gs4 , v052
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
mus_machi_s3_7_001:
	.byte		N08   , Gs4 , v052
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		VOICE , 126
	.byte		N08   , Gs4 , v040
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   
	.byte	W08
	.byte	PEND
mus_machi_s3_7_002:
	.byte		N08   , Gs4 , v052
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s3_7_001
	.byte		N08   , Gs4 , v052
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W08
	.byte		VOICE , 126
	.byte		N08   , Gs4 , v040
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte		VOICE , 126
	.byte		N08   
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   
	.byte	W08
	.byte		VOICE , 126
	.byte		N08   
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte		VOICE , 126
	.byte		N08   
	.byte	W16
	.byte		VOICE , 127
	.byte		N08   , Gs4 , v052
	.byte	W24
	.byte		        Gs4 , v040
	.byte	W08
	.byte	PATT
	 .word	mus_machi_s3_7_002
	.byte		N08   , Gs4 , v052
	.byte	W08
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte		        Gs4 , v052
	.byte	W16
	.byte		        Gs4 , v040
	.byte	W08
	.byte	GOTO
	 .word	mus_machi_s3_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_machi_s3_8:
	.byte		VOL   , 80*mus_machi_s3_mvl/mxv
	.byte	KEYSH , mus_machi_s3_key+0
	.byte		VOICE , 0
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		N04   , Dn3 , v064
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		        En1 
	.byte		N04   , En3 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		N04   , Dn3 , v064
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		        En1 
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N08   , En1 , v116
	.byte		N04   , Dn3 , v064
	.byte	W08
mus_machi_s3_8_B1:
mus_machi_s3_8_000:
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		N04   , Dn3 , v064
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		        En1 
	.byte		N04   , En3 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte	PEND
mus_machi_s3_8_001:
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		N04   , Dn3 , v064
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		        En1 
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s3_8_000
	.byte	PATT
	 .word	mus_machi_s3_8_001
mus_machi_s3_8_002:
	.byte		N08   , Cn1 , v116
	.byte	W16
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		        En3 
	.byte	W16
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		N08   , En1 , v116
	.byte	W08
	.byte		N04   , En3 , v064
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s3_8_002
	.byte	PATT
	 .word	mus_machi_s3_8_002
	.byte	PATT
	 .word	mus_machi_s3_8_002
mus_machi_s3_8_003:
	.byte		N08   , Cn1 , v116
	.byte	W16
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		N08   , En1 , v116
	.byte	W08
	.byte		N04   , En3 , v064
	.byte	W08
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		N08   , En1 , v116
	.byte	W16
	.byte		N04   , Dn3 , v064
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
mus_machi_s3_8_004:
	.byte		N08   , Cn1 , v116
	.byte	W16
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		N08   , En1 , v116
	.byte	W08
	.byte		N04   , En3 , v064
	.byte	W08
	.byte		N08   , Cn1 , v116
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   , Dn3 , v064
	.byte	W08
	.byte		N08   , En1 , v116
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s3_8_003
	.byte	PATT
	 .word	mus_machi_s3_8_004
	.byte		N08   , En1 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W16
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 
	.byte	W08
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		N08   
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		N08   
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte	PATT
	 .word	mus_machi_s3_8_003
	.byte	PATT
	 .word	mus_machi_s3_8_004
	.byte	GOTO
	 .word	mus_machi_s3_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_machi_s3:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_machi_s3_pri	@ Priority
	.byte	mus_machi_s3_rev	@ Reverb.

	.word	mus_machi_s3_grp

	.word	mus_machi_s3_1
	.word	mus_machi_s3_2
	.word	mus_machi_s3_3
	.word	mus_machi_s3_4
	.word	mus_machi_s3_5
	.word	mus_machi_s3_6
	.word	mus_machi_s3_7
	.word	mus_machi_s3_8

	.end
