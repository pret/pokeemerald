	.include "MPlayDef.s"

	.equ	mus_b_tube_grp, voicegroup112
	.equ	mus_b_tube_pri, 0
	.equ	mus_b_tube_rev, reverb_set+50
	.equ	mus_b_tube_mvl, 127
	.equ	mus_b_tube_key, 0
	.equ	mus_b_tube_tbs, 1
	.equ	mus_b_tube_exg, 0
	.equ	mus_b_tube_cmp, 1

	.section .rodata
	.global	mus_b_tube
	.align	2

@********************** Track  1 **********************@

mus_b_tube_1:
	.byte	KEYSH , mus_b_tube_key+0
	.byte	TEMPO , 120*mus_b_tube_tbs/2
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+14
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W72
mus_b_tube_1_B1:
	.byte	W24
	.byte		N16   , En2 , v112
	.byte	W16
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N40   , An2 
	.byte	W40
	.byte		N32   , En3 
	.byte	W32
	.byte		N40   , Gs2 
	.byte	W40
	.byte		N32   , En3 
	.byte	W32
	.byte		N40   , Gn2 
	.byte	W40
	.byte		N32   , En3 
	.byte	W32
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N40   , Fn2 
	.byte	W40
	.byte		N32   , Dn3 
	.byte	W32
	.byte		N40   , En2 
	.byte	W40
	.byte		N32   , Cn3 
	.byte	W32
	.byte		N40   , Ds2 
	.byte	W40
	.byte		N32   , Cn3 
	.byte	W32
	.byte		N40   , En2 
	.byte	W40
	.byte		N56   , Bn2 
	.byte	W32
	.byte	W72
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , En3 
	.byte	W32
	.byte		N16   , En2 
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , An2 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N04   , En3 
	.byte	W24
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , Gs2 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16   , Fs2 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N04   , Fs3 
	.byte	W16
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N04   , An3 
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N24   , En2 
	.byte	W24
	.byte		N16   , En3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Ds2 
	.byte	W16
	.byte		N04   , Ds3 
	.byte	W24
	.byte		N08   , An2 
	.byte	W08
	.byte		N04   , An3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N16   , En2 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte	W24
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
mus_b_tube_1_000:
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W08
	.byte	PEND
	.byte	W24
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte	W16
	.byte		        Fs3 
	.byte	W24
	.byte		N08   , An2 
	.byte	W08
	.byte		N04   , An3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte	PATT
	 .word	mus_b_tube_1_000
	.byte	W16
	.byte		N04   , Fs3 , v112
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W16
	.byte		N04   , An3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		N04   , Fn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N04   , Gs3 
	.byte	W16
	.byte		N08   , Bn2 
	.byte	W08
	.byte		N72   , Gn3 , v064
	.byte	W72
	.byte		        Fs3 
	.byte	W72
	.byte		        Fn3 
	.byte	W72
	.byte		        En3 
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		N08   , En2 , v112
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , En3 
	.byte	W08
	.byte		N04   , En4 , v080
	.byte	W16
	.byte		N08   , En3 , v096
	.byte	W08
	.byte	GOTO
	 .word	mus_b_tube_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_b_tube_2:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 38
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*mus_b_tube_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+0
	.byte		N72   , En2 , v096
	.byte	W48
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		        c_v-13
	.byte	W04
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-24
	.byte	W04
	.byte		        c_v-30
	.byte	W02
	.byte		        c_v-45
	.byte	W04
	.byte		        c_v-57
	.byte	W02
	.byte		        c_v-63
	.byte	W04
mus_b_tube_2_B1:
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+0
	.byte		N72   , En1 , v096
	.byte	W48
	.byte		VOL   , 81*mus_b_tube_mvl/mxv
	.byte		MOD   , 127
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		VOL   , 70*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+15
	.byte	W04
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+36
	.byte	W04
	.byte		VOL   , 50*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+58
	.byte	W04
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+63
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		        90*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W16
	.byte		N04   , En2 , v092
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte		BEND  , c_v+1
	.byte		N16   , Ds2 
	.byte	W08
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte		N04   , En2 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N16   , Bn2 
	.byte	W08
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N04   , En2 
	.byte	W02
	.byte		VOL   , 89*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N04   , En2 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N40   , Dn2 
	.byte	W24
	.byte		VOL   , 81*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        71*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        68*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        58*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        55*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        51*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 91*mus_b_tube_mvl/mxv
	.byte		N16   
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N24   , Fn2 
	.byte	W16
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N40   , En2 
	.byte	W24
	.byte		VOL   , 81*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        71*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        68*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        58*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        55*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        51*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 91*mus_b_tube_mvl/mxv
	.byte		N16   , Cn2 
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N24   , Ds2 
	.byte	W16
	.byte		MOD   , 8
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		MOD   , 0
	.byte		N24   , An1 
	.byte	W24
	.byte		N16   , Cn2 
	.byte	W16
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N48   , En2 
	.byte	W24
	.byte		VOL   , 81*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 70*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		        63*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        59*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		        55*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        47*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		        44*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        38*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		        92*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte	W72
	.byte	W16
	.byte		N04   , En3 , v072
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W08
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W08
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N16   , En3 
	.byte	W08
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte		N04   , Ds3 
	.byte	W08
	.byte		BEND  , c_v+1
	.byte		N16   , En3 
	.byte	W08
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte		N04   , Ds3 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N02   , Fn3 
	.byte	W02
	.byte		N36   , Fs3 
	.byte	W22
	.byte		VOL   , 81*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        71*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        68*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        58*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        55*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        51*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 91*mus_b_tube_mvl/mxv
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , En3 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W16
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N02   , Fn3 
	.byte	W02
	.byte		N36   , En3 
	.byte	W22
	.byte		VOL   , 81*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        71*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        68*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        58*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        55*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        51*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W08
	.byte		VOL   , 91*mus_b_tube_mvl/mxv
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , En3 
	.byte	W08
	.byte		N24   , Ds3 
	.byte	W16
	.byte		MOD   , 8
	.byte	W08
	.byte		        0
	.byte		N24   , An2 
	.byte	W24
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N48   , Gs3 
	.byte	W24
	.byte		VOL   , 85*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 81*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        79*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        75*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        74*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        71*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        67*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        56*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        53*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        46*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        42*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        92*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		BEND  , c_v+0
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		        c_v+0
	.byte	W24
	.byte		N16   , An1 , v064
	.byte	W16
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N08   , Fs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N08   , Dn2 
	.byte	W08
	.byte	W24
	.byte		N16   , An1 
	.byte	W16
	.byte		N08   , An2 
	.byte	W08
	.byte		N16   , Fs2 
	.byte	W16
	.byte		N08   , Ds2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W08
	.byte	W72
	.byte	GOTO
	 .word	mus_b_tube_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_b_tube_3:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 82*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N72   , En2 , v112
	.byte	W36
	.byte		MOD   , 10
	.byte	W12
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		        c_v-13
	.byte	W04
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-24
	.byte	W04
	.byte		        c_v-30
	.byte	W02
	.byte		        c_v-45
	.byte	W04
	.byte		        c_v-57
	.byte	W02
	.byte		        c_v-63
	.byte	W04
mus_b_tube_3_B1:
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N72   , En1 , v112
	.byte	W48
	.byte		MOD   , 10
	.byte	W24
	.byte		        0
	.byte		N40   , An1 
	.byte	W24
	.byte		MOD   , 10
	.byte	W24
	.byte		        0
	.byte		N24   , En1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N40   , Gs1 
	.byte	W24
	.byte		MOD   , 10
	.byte	W24
	.byte		        0
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N16   , Gn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N16   , En2 
	.byte	W04
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		        c_v-16
	.byte	W02
	.byte		MOD   , 10
	.byte		BEND  , c_v-28
	.byte	W02
	.byte		        c_v-37
	.byte	W02
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-53
	.byte	W02
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N08   , En1 
	.byte	W08
	.byte		N24   , Fs1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N16   , Dn2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N16   , Dn1 
	.byte	W16
	.byte		N08   , En1 
	.byte	W08
	.byte		N40   , Fn1 
	.byte	W24
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N24   , Dn1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N40   , En1 
	.byte	W24
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N24   , Cn1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N40   , Ds1 
	.byte	W24
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N24   , Cn1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N40   , En1 
	.byte	W24
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		N24   , An1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 10
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		        c_v-12
	.byte	W02
	.byte		        c_v-19
	.byte	W02
	.byte		        c_v-27
	.byte	W02
	.byte		        c_v-39
	.byte	W02
	.byte		        c_v-43
	.byte	W02
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N24   , En1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N16   
	.byte	W16
	.byte		N08   , Gs1 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N24   , An1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N16   , Cn2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , An1 
	.byte	W08
	.byte		N16   , Gs1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W32
	.byte		N24   , En1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		N16   , Gn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N24   , Fs1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N16   , Dn2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Cn2 
	.byte	W08
	.byte		N16   , Dn1 
	.byte	W16
	.byte		N08   , En1 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N16   , Fn1 
	.byte	W16
	.byte		        Dn2 
	.byte	W08
	.byte		MOD   , 10
	.byte		BEND  , c_v-9
	.byte	W02
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-26
	.byte	W02
	.byte		        c_v-39
	.byte	W02
	.byte		MOD   , 0
	.byte		BEND  , c_v-48
	.byte	W02
	.byte		        c_v-53
	.byte	W04
	.byte		        c_v+0
	.byte	W10
	.byte		        c_v+0
	.byte		N24   , Dn1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N24   , En1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N16   , Cn2 
	.byte	W16
	.byte		N04   , Fs1 
	.byte	W08
	.byte		N24   , Cn1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N16   , Ds1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W32
	.byte		N24   , Cn1 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N40   , En1 
	.byte	W24
	.byte		MOD   , 10
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-10
	.byte	W02
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-20
	.byte	W02
	.byte		        c_v-22
	.byte	W02
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N16   , Bn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Gs1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N06   , En1 
	.byte	W24
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N06   , Gs1 
	.byte	W08
	.byte		        An1 
	.byte	W16
	.byte		N08   , En1 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N16   , An1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Ds1 
	.byte	W24
	.byte		N08   , Ds2 
	.byte	W24
	.byte		        Cn2 
	.byte	W08
mus_b_tube_3_000:
	.byte		N08   , Dn2 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Dn2 
	.byte	W08
	.byte	PEND
	.byte		N16   , An1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W24
	.byte		N08   , Fs2 
	.byte	W16
	.byte		N04   , An2 
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N04   , Fn2 
	.byte	W16
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N72   , As1 
	.byte	W72
	.byte		        An1 
	.byte	W72
	.byte		        Gs1 
	.byte	W72
	.byte		BEND  , c_v+0
	.byte		N48   , Gn1 
	.byte	W48
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 10
	.byte		BEND  , c_v-10
	.byte	W02
	.byte		        c_v-15
	.byte	W02
	.byte		        c_v-25
	.byte	W02
	.byte		        c_v-42
	.byte	W02
	.byte		        c_v-50
	.byte	W04
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N40   , An1 
	.byte	W24
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte	PATT
	 .word	mus_b_tube_3_000
	.byte		N40   , An1 , v112
	.byte	W24
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N08   , Cn2 
	.byte	W08
	.byte	PATT
	 .word	mus_b_tube_3_000
	.byte		N08   , En2 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , En1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , Gs2 
	.byte	W16
	.byte		N08   , Gs1 
	.byte	W08
	.byte	GOTO
	 .word	mus_b_tube_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_b_tube_4:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 53
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 71*mus_b_tube_mvl/mxv
	.byte		PAN   , c_v+5
	.byte	W72
mus_b_tube_4_B1:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W24
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		PAN   , c_v+8
	.byte		N08   , En3 , v096
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N48   , Cn4 
	.byte	W04
	.byte		BEND  , c_v-5
	.byte	W04
	.byte		        c_v+0
	.byte	W04
	.byte		        c_v+0
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N48   , Gs3 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W04
	.byte		        c_v+0
	.byte	W04
	.byte		        c_v+0
	.byte	W04
	.byte		        c_v+0
	.byte	W12
	.byte		MOD   , 8
	.byte	W04
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        49*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		N08   , Bn3 , v100
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N48   , Gs3 
	.byte	W12
	.byte		BEND  , c_v-6
	.byte	W08
	.byte		        c_v+0
	.byte	W04
	.byte		MOD   , 5
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 10
	.byte	W04
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        49*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		PAN   , c_v+5
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte		N08   , Fn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N40   , Cn4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		MOD   , 5
	.byte	W12
	.byte		        11
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        49*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        75*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W04
	.byte		N04   , En4 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N48   , Gs3 
	.byte	W12
	.byte		MOD   , 5
	.byte		BEND  , c_v-5
	.byte	W04
	.byte		        c_v+0
	.byte	W20
	.byte		MOD   , 10
	.byte	W04
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        49*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N48   , Fn3 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		MOD   , 5
	.byte	W24
	.byte		        10
	.byte	W04
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        49*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 10
	.byte	W04
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        49*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte		N04   , En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N16   , Fn3 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W14
	.byte		N04   , En3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N16   , Fn3 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W14
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N16   , Fn3 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W14
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N56   , En3 
	.byte	W20
	.byte		MOD   , 5
	.byte	W24
	.byte		        10
	.byte	W04
	.byte		VOL   , 62*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        49*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 75*mus_b_tube_mvl/mxv
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	GOTO
	 .word	mus_b_tube_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_b_tube_5:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v-17
	.byte		VOL   , 60*mus_b_tube_mvl/mxv
	.byte	W72
mus_b_tube_5_B1:
	.byte	W72
	.byte	W40
	.byte		N32   , Cn3 , v112
	.byte	W32
	.byte	W40
	.byte		N32   
	.byte	W32
	.byte	W40
	.byte		N32   
	.byte	W32
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte	W40
	.byte		N32   
	.byte	W32
	.byte	W40
	.byte		N32   
	.byte	W32
	.byte	W40
	.byte		N32   
	.byte	W32
	.byte	W40
	.byte		N08   , Gs2 
	.byte	W08
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		N48   , En2 
	.byte	W48
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W56
	.byte	W16
	.byte		N04   
	.byte	W40
	.byte		N04   
	.byte	W16
	.byte	W72
	.byte	W16
	.byte		        En3 
	.byte	W32
	.byte		N04   
	.byte	W24
	.byte	W16
	.byte		        An2 
	.byte	W32
	.byte		        Dn3 
	.byte	W24
	.byte	W40
	.byte		        Cn3 
	.byte	W24
	.byte		        En2 
	.byte	W08
	.byte	W16
	.byte		        Cn3 
	.byte	W32
	.byte		        Ds3 
	.byte	W24
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W16
	.byte		        Cn3 
	.byte	W32
	.byte		        Fs3 
	.byte	W24
	.byte	W72
	.byte	W16
	.byte		        Cn3 
	.byte	W40
	.byte		        Ds3 
	.byte	W16
	.byte	W16
	.byte		        Bn2 
	.byte	W32
	.byte		        Dn3 
	.byte	W24
	.byte		N72   , Cs3 , v064
	.byte	W48
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N72   , Cn3 
	.byte	W48
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N72   , Bn2 
	.byte	W48
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N72   , As2 
	.byte	W48
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W48
	.byte		N04   , Dn4 , v080
	.byte	W16
	.byte		N08   , Dn3 , v096
	.byte	W08
	.byte	GOTO
	 .word	mus_b_tube_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_b_tube_6:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v-8
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W72
mus_b_tube_6_B1:
	.byte	W48
	.byte		PAN   , c_v+42
	.byte		VOL   , 29*mus_b_tube_mvl/mxv
	.byte		N16   , En2 , v040
	.byte	W16
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N40   , An2 
	.byte	W40
	.byte		N32   , En3 
	.byte	W08
	.byte	W24
	.byte		N40   , Gs2 
	.byte	W40
	.byte		N32   , En3 
	.byte	W08
	.byte	W24
	.byte		N40   , Gn2 
	.byte	W40
	.byte		N32   , En3 
	.byte	W08
	.byte	W24
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N40   , Fn2 
	.byte	W40
	.byte		N32   , Dn3 
	.byte	W08
	.byte	W24
	.byte		N40   , En2 
	.byte	W40
	.byte		N32   , Cn3 
	.byte	W08
	.byte	W24
	.byte		N40   , Ds2 
	.byte	W40
	.byte		N32   , Cn3 
	.byte	W08
	.byte	W24
	.byte		N40   , En2 
	.byte	W40
	.byte		N56   , Bn2 
	.byte	W08
	.byte	W72
	.byte	W24
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , En3 
	.byte	W32
	.byte		N16   , En2 
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N08   , An2 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N04   , En3 
	.byte	W24
	.byte		N16   , Gs2 
	.byte	W08
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , Gs2 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16   , Fs2 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N04   , Fs3 
	.byte	W16
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N04   , An3 
	.byte	W16
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N24   , En2 
	.byte	W24
	.byte		N16   , En3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Ds2 
	.byte	W16
	.byte		N04   , Ds3 
	.byte	W24
	.byte		N08   , An2 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N04   , An3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N16   , En2 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		VOICE , 17
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+1
	.byte		N08   , En4 , v080
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W04
	.byte		BEND  , c_v-5
	.byte	W04
	.byte		        c_v+0
	.byte	W16
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        29*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        25*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 16*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		        11*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N48   , Gs4 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W04
	.byte		        c_v+0
	.byte	W10
	.byte		VOL   , 29*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        25*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        24*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 19*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        16*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        14*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , An4 
	.byte	W08
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte		N48   , Gs4 
	.byte	W12
	.byte		BEND  , c_v-6
	.byte	W08
	.byte		        c_v+0
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        29*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        28*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        25*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        24*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        16*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        14*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N40   , Cn5 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W20
	.byte		VOL   , 30*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        24*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        16*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		N04   , En5 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N04   , An4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N48   , Gs4 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte	W04
	.byte		        c_v+0
	.byte	W08
	.byte		VOL   , 30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        29*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        25*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        16*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        14*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        11*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N08   , Fs4 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N48   , Fn4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W20
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        29*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        25*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        19*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        16*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        14*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        11*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N16   , Fn4 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W14
	.byte		N04   , En4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N16   , Fn4 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W14
	.byte		N04   , En4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Gn4 
	.byte	W08
	.byte		BEND  , c_v-5
	.byte		N16   , Fn4 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W14
	.byte		N04   , En4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N56   , En4 
	.byte	W32
	.byte		VOL   , 30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        29*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        25*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        24*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		MOD   , 6
	.byte		VOL   , 20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        14*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		        32*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		VOICE , 1
	.byte	W24
	.byte		N16   , An2 , v040
	.byte	W16
	.byte		N08   , Cn3 
	.byte	W08
	.byte		PAN   , c_v+37
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W32
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N08   , Ds3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N08   , Fn3 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N08   , En3 
	.byte	W08
	.byte	GOTO
	 .word	mus_b_tube_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_b_tube_7:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v+1
	.byte	W72
mus_b_tube_7_B1:
	.byte		VOICE , 82
	.byte		MOD   , 2
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W16
	.byte		N04   , En2 , v040
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En2 
	.byte	W08
	.byte		N40   , Dn2 
	.byte	W12
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte		MOD   , 7
	.byte	W28
	.byte		        2
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N08   , En2 
	.byte	W08
	.byte		N24   , Fn2 
	.byte	W06
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , Fn2 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N40   , En2 
	.byte	W06
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W28
	.byte		        2
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Cn2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , En2 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N24   , Ds2 
	.byte	W06
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte		N24   , An1 
	.byte	W06
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte		N16   , Cn2 
	.byte	W04
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N48   , En2 
	.byte	W06
	.byte		VOL   , 31*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W36
	.byte		        2
	.byte	W24
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W72
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N40   , Fs3 
	.byte	W06
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W28
	.byte		        2
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Dn3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N08   , En3 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W06
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		N40   , En3 
	.byte	W06
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W28
	.byte		        2
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Cn3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N08   , En3 
	.byte	W08
	.byte		N24   , Ds3 
	.byte	W06
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte		N24   , An2 
	.byte	W06
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte		N16   , Ds3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N48   , Gs3 
	.byte	W06
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W36
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 2
	.byte	W24
	.byte		PAN   , c_v-64
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		VOICE , 81
	.byte		BEND  , c_v+0
	.byte		N72   , As2 , v064
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        5*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , An2 
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        5*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Gs2 
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        5*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Gn2 
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        5*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		N16   , An2 , v052
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , Cn3 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N16   , Ds3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , Fs3 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W06
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W10
	.byte		N08   , Fn3 
	.byte	W04
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		N16   , Gs3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , Dn3 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte	W24
	.byte		N16   , An2 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , An3 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N16   , Fs3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , Ds3 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N08   , Bn2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , Dn3 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		N16   , Gs3 
	.byte	W04
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W12
	.byte		N08   , Fn3 
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W72
	.byte	GOTO
	 .word	mus_b_tube_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_b_tube_8:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 52
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte		N72   , En2 , v072
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W28
	.byte		MOD   , 10
	.byte	W12
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		        c_v-13
	.byte	W04
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-24
	.byte	W04
	.byte		        c_v-30
	.byte	W02
	.byte		        c_v-45
	.byte	W04
	.byte		        c_v-57
	.byte	W02
	.byte		        c_v-63
	.byte	W04
mus_b_tube_8_B1:
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte		N72   , En1 , v072
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W40
	.byte		MOD   , 10
	.byte	W24
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N40   , An1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W24
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N40   , Gs1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W24
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , En2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		N04   , An1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Gn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , En2 
	.byte	W04
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		        c_v-16
	.byte	W02
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte		BEND  , c_v-28
	.byte	W02
	.byte		        c_v-37
	.byte	W02
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-53
	.byte	W02
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N08   , En1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , Fs1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   , Dn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Dn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W08
	.byte		N08   , En1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N40   , Fn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , Dn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N40   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , Cn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N40   , Ds1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , Cn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N40   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , An1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , En2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		        c_v-12
	.byte	W02
	.byte		        c_v-19
	.byte	W02
	.byte		        c_v-27
	.byte	W02
	.byte		        c_v-39
	.byte	W02
	.byte		        c_v-43
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N24   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N16   
	.byte	W16
	.byte		N08   , Gs1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , An1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Cn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , An1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Gs1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W32
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		N04   , An1 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Gn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , En2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fs1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   , Dn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Cn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Dn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W08
	.byte		N08   , En1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N16   , Fn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W08
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		N16   , Dn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte		BEND  , c_v-9
	.byte	W02
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-26
	.byte	W02
	.byte		        c_v-39
	.byte	W02
	.byte		MOD   , 0
	.byte		BEND  , c_v-48
	.byte	W02
	.byte		        c_v-53
	.byte	W04
	.byte		        c_v+0
	.byte	W10
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Dn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   , Cn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , Cn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   , Ds1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W32
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N24   , Cn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W04
	.byte		MOD   , 10
	.byte	W12
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N40   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		        c_v-4
	.byte	W02
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-10
	.byte	W02
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-20
	.byte	W02
	.byte		        c_v-22
	.byte	W02
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N08   , Dn1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Bn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Gs1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , An1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N06   , En1 
	.byte	W24
	.byte		N08   , Fs2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Ds2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Dn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Bn1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Fn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Bn1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Fn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N06   , Gs1 
	.byte	W08
	.byte		        An1 
	.byte	W16
	.byte		N08   , En1 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Ds2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N08   , Dn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Fn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Bn1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Fn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , An1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N04   , Ds1 
	.byte	W24
	.byte		N08   , Ds2 
	.byte	W24
	.byte		        Cn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N08   , Dn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Bn1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Fn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Dn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , An1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte	W24
	.byte		N08   , Fs2 
	.byte	W16
	.byte		N04   , An2 
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N08   , Dn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W08
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N04   , Fn2 
	.byte	W16
	.byte		N08   , Dn2 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte		N72   , En3 , v092
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        5*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Ds3 , v064
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        5*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Dn3 
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        9*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        5*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N72   , Cs3 
	.byte	W48
	.byte		VOL   , 35*mus_b_tube_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 32*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        23*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        18*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v-10
	.byte	W02
	.byte		VOL   , 15*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W02
	.byte		VOL   , 12*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v-25
	.byte	W02
	.byte		VOL   , 9*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v-42
	.byte	W02
	.byte		VOL   , 5*mus_b_tube_mvl/mxv
	.byte		BEND  , c_v-50
	.byte	W02
	.byte		VOL   , 1*mus_b_tube_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_tube_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N40   , An1 , v072
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte		N08   , Fs2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Ds2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Cn2 
	.byte	W08
mus_b_tube_8_000:
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N08   , Dn2 , v072
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Fn1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Bn1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Fn2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , Dn2 
	.byte	W08
	.byte	PEND
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N40   , An1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W16
	.byte		MOD   , 10
	.byte	W16
	.byte		        0
	.byte		N08   , Fs2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , Ds2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W08
	.byte	PATT
	 .word	mus_b_tube_8_000
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N08   , En2 , v072
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N16   , En1 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte		MOD   , 10
	.byte	W08
	.byte		        0
	.byte		N08   , En2 
	.byte	W08
	.byte		VOL   , 37*mus_b_tube_mvl/mxv
	.byte		N04   , Gs2 
	.byte	W08
	.byte		VOL   , 25*mus_b_tube_mvl/mxv
	.byte	W08
	.byte		N08   , Gs1 
	.byte	W08
	.byte	GOTO
	 .word	mus_b_tube_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_b_tube_9:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 0
	.byte		VOL   , 88*mus_b_tube_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
mus_b_tube_9_B1:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W24
	.byte		N04   , En1 , v112
	.byte	W08
	.byte		        Cn1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		        En1 
	.byte	W08
mus_b_tube_9_000:
	.byte		N04   , Cn1 , v112
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		        En1 
	.byte	W24
	.byte	PEND
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_9_000
	.byte	GOTO
	 .word	mus_b_tube_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_b_tube_10:
	.byte	KEYSH , mus_b_tube_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*mus_b_tube_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
mus_b_tube_10_B1:
	.byte		N02   , Cn5 , v048
	.byte	W08
	.byte		        Cn5 , v032
	.byte	W08
	.byte		        Cn5 , v044
	.byte	W08
	.byte		        Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v032
	.byte	W08
	.byte		VOICE , 126
	.byte		N24   , Gn5 
	.byte	W24
mus_b_tube_10_000:
	.byte		VOICE , 127
	.byte		N02   , Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte		        Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte		        Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte	PEND
mus_b_tube_10_001:
	.byte		N02   , Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte		        Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte		        Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte		N02   , Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte		VOICE , 126
	.byte		N24   , Gn5 , v032
	.byte	W24
	.byte		VOICE , 127
	.byte	W24
	.byte	PATT
	 .word	mus_b_tube_10_001
mus_b_tube_10_002:
	.byte		N02   , Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte		        Cn5 , v048
	.byte	W16
	.byte		        Cn5 , v024
	.byte	W08
	.byte		VOICE , 126
	.byte		N24   , Gn5 , v032
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte		VOICE , 127
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	mus_b_tube_10_001
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	PATT
	 .word	mus_b_tube_10_002
	.byte	PATT
	 .word	mus_b_tube_10_000
	.byte	GOTO
	 .word	mus_b_tube_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_b_tube:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_b_tube_pri	@ Priority
	.byte	mus_b_tube_rev	@ Reverb.

	.word	mus_b_tube_grp

	.word	mus_b_tube_1
	.word	mus_b_tube_2
	.word	mus_b_tube_3
	.word	mus_b_tube_4
	.word	mus_b_tube_5
	.word	mus_b_tube_6
	.word	mus_b_tube_7
	.word	mus_b_tube_8
	.word	mus_b_tube_9
	.word	mus_b_tube_10

	.end
