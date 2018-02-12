	.include "MPlayDef.s"

	.equ	mus_b_arena_grp, voicegroup_8695B7C
	.equ	mus_b_arena_pri, 0
	.equ	mus_b_arena_rev, reverb_set+50
	.equ	mus_b_arena_mvl, 127
	.equ	mus_b_arena_key, 0
	.equ	mus_b_arena_tbs, 1
	.equ	mus_b_arena_exg, 0
	.equ	mus_b_arena_cmp, 1

	.section .rodata
	.global	mus_b_arena
	.align	2

@********************** Track  1 **********************@

mus_b_arena_1:
	.byte	KEYSH , mus_b_arena_key+0
	.byte	TEMPO , 128*mus_b_arena_tbs/2
	.byte		VOICE , 107
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W06
	.byte	W24
	.byte		N24   , Dn3 , v100
	.byte	W24
	.byte		N16   
	.byte	W18
	.byte		N14   
	.byte	W15
	.byte		N14   
	.byte	W15
	.byte		N12   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N48   , An2 
	.byte	W72
	.byte	W72
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N48   , Cn2 
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N01   , Dn3 , v032
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Dn3 , v036
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		        Dn3 , v052
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Dn3 , v060
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        Dn3 , v072
	.byte	W06
	.byte		        Dn3 , v076
	.byte	W06
	.byte		        Dn3 , v084
	.byte	W06
	.byte		        Dn3 , v088
	.byte	W06
	.byte		        Dn3 , v100
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v127
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Dn3 , v124
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn3 , v100
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W60
	.byte		BEND  , c_v+0
	.byte		N04   , As3 , v064
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        Fn1 
	.byte	W04
	.byte		        Dn1 
	.byte	W04
	.byte		        Cn1 , v096
	.byte	W04
	.byte		        Fn1 
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		N03   , An3 , v100
	.byte	W06
	.byte		N01   , An3 , v084
	.byte	W06
	.byte		N08   , An3 , v100
	.byte	W78
	.byte		N01   , Gn1 
	.byte	W03
	.byte		N01   
	.byte	W03
mus_b_arena_1_B1:
	.byte		BEND  , c_v+0
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W36
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N36   , Dn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn1 
	.byte	W03
	.byte		N01   
	.byte	W03
mus_b_arena_1_000:
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W48
	.byte	PEND
	.byte	W90
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	mus_b_arena_1_000
mus_b_arena_1_001:
	.byte	W36
	.byte		N06   , Fn2 , v100
	.byte	W12
	.byte		N36   , Dn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn1 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_b_arena_1_000
	.byte	W90
	.byte		N01   , Fn2 , v100
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Gn2 
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W48
	.byte	W36
	.byte		N06   , As2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn1 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Gn1 
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W36
	.byte		N03   , Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N36   , Gn1 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N36   , Dn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Gn1 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	mus_b_arena_1_000
	.byte	PATT
	 .word	mus_b_arena_1_001
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N36   , Gn1 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn1 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Gn1 
	.byte	W03
	.byte		N21   
	.byte	W36
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	GOTO
	 .word	mus_b_arena_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_b_arena_2:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 77
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W06
	.byte		MOD   , 0
	.byte		TIE   , Gn3 , v088
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte		VOL   , 62*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 58*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        53*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        48*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        46*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        42*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        40*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        34*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        31*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        28*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        24*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        21*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        19*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        17*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        13*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        11*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        10*mus_b_arena_mvl/mxv
	.byte	W10
	.byte	W02
	.byte		        11*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        12*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        17*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        21*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        24*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        28*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        33*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        38*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        40*mus_b_arena_mvl/mxv
	.byte	W01
	.byte		        43*mus_b_arena_mvl/mxv
	.byte	W03
	.byte		        51*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        57*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        60*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        64*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        68*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		        56*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        49*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        45*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		N36   , Cn3 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Dn3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Cn3 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+8
	.byte		N72   , As2 
	.byte	W03
	.byte		BEND  , c_v+4
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte	W12
	.byte	W12
	.byte		MOD   , 5
	.byte	W04
	.byte		BEND  , c_v-4
	.byte	W04
	.byte		        c_v-8
	.byte	W04
	.byte		        c_v-16
	.byte	W12
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   
	.byte	W09
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W09
	.byte		        68*mus_b_arena_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N18   , Dn3 
	.byte	W06
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , As3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Cn4 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		TIE   , Dn4 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+9
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		MOD   , 5
	.byte	W24
	.byte	W12
	.byte		BEND  , c_v-10
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v+0
	.byte	W30
	.byte		VOL   , 50*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        41*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		VOL   , 36*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        30*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte	W02
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 33*mus_b_arena_mvl/mxv
	.byte	W84
	.byte	W96
	.byte	W96
mus_b_arena_2_B1:
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
	.byte	GOTO
	 .word	mus_b_arena_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_b_arena_3:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 92
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 69*mus_b_arena_mvl/mxv
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
	.byte	W84
	.byte		N12   , Dn1 , v064
	.byte	W12
mus_b_arena_3_B1:
	.byte		N06   , Gn1 , v064
	.byte	W24
	.byte		N24   
	.byte	W48
	.byte		        Dn1 
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W24
	.byte		N24   
	.byte	W36
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N36   , Gn1 
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N24   , Ds1 
	.byte	W36
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N24   , As1 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W36
	.byte		        As1 
	.byte	W12
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte		N36   , Gn1 
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N36   , Gn1 
	.byte	W48
mus_b_arena_3_000:
	.byte		N24   , Gn1 , v064
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte	PEND
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , As1 
	.byte	W24
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte	PATT
	 .word	mus_b_arena_3_000
	.byte		N36   , Gn1 , v064
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W24
	.byte	GOTO
	 .word	mus_b_arena_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_b_arena_4:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 3
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		        c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 46
	.byte		N04   , Dn4 , v064
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Gn1 
	.byte	W04
	.byte		        Fn1 , v096
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N03   , Dn4 , v100
	.byte	W06
	.byte		N01   , Dn4 , v084
	.byte	W06
	.byte		N08   , Dn4 , v100
	.byte	W84
mus_b_arena_4_B1:
	.byte		VOICE , 107
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
	.byte	GOTO
	 .word	mus_b_arena_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_b_arena_5:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 77
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte	W06
	.byte		MOD   , 0
	.byte		BEND  , c_v+1
	.byte		TIE   , Gn3 , v040
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+1
	.byte	W12
	.byte		VOL   , 62*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 58*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        53*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        48*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        46*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        42*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        40*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        37*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        34*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        31*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        28*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        24*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        21*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        19*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        17*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        13*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        12*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        11*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        10*mus_b_arena_mvl/mxv
	.byte	W10
	.byte	W02
	.byte		        11*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        12*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        17*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        21*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        24*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        28*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        33*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        38*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        40*mus_b_arena_mvl/mxv
	.byte	W01
	.byte		        43*mus_b_arena_mvl/mxv
	.byte	W03
	.byte		        51*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        57*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        60*mus_b_arena_mvl/mxv
	.byte	W02
	.byte		        64*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		        68*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		        56*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        49*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        45*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        34*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		N36   , Cn3 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Dn3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Cn3 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+8
	.byte		N72   , As2 
	.byte	W03
	.byte		BEND  , c_v+4
	.byte	W03
	.byte		        c_v+1
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte	W12
	.byte	W12
	.byte		MOD   , 5
	.byte	W04
	.byte		BEND  , c_v-3
	.byte	W04
	.byte		        c_v-7
	.byte	W04
	.byte		        c_v-14
	.byte	W12
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N18   
	.byte	W09
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W09
	.byte		        68*mus_b_arena_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N18   , Dn3 
	.byte	W06
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , As3 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Cn4 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 68*mus_b_arena_mvl/mxv
	.byte		MOD   , 0
	.byte		TIE   , Dn4 
	.byte	W12
	.byte		VOL   , 56*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+9
	.byte	W03
	.byte		        c_v+1
	.byte	W09
	.byte		MOD   , 5
	.byte	W24
	.byte	W12
	.byte		BEND  , c_v-10
	.byte	W03
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+1
	.byte	W24
	.byte		VOL   , 50*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        41*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		        c_v+1
	.byte	W09
	.byte		VOL   , 36*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        30*mus_b_arena_mvl/mxv
	.byte	W06
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte	W02
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 33*mus_b_arena_mvl/mxv
	.byte	W84
	.byte		PAN   , c_v-30
	.byte		BEND  , c_v+1
	.byte	W72
	.byte		VOICE , 3
	.byte	W24
	.byte		N03   , Dn2 , v100
	.byte	W06
	.byte		N01   , Dn2 , v084
	.byte	W06
	.byte		N08   , Dn2 , v100
	.byte	W80
	.byte	W02
	.byte		BEND  , c_v+1
	.byte	W02
mus_b_arena_5_B1:
	.byte		BEND  , c_v+0
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
	.byte	GOTO
	 .word	mus_b_arena_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_b_arena_6:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 3
	.byte		VOL   , 41*mus_b_arena_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+15
	.byte	W06
	.byte	W24
	.byte		N24   , Dn4 , v100
	.byte	W24
	.byte		N16   
	.byte	W18
	.byte		N14   
	.byte	W15
	.byte		N14   
	.byte	W15
	.byte		N12   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N48   , An3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W24
	.byte	W72
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N48   , Cn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N01   , Dn4 , v032
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        Dn4 , v052
	.byte	W06
	.byte		        Dn4 , v056
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Dn4 , v060
	.byte	W06
	.byte		        Dn4 , v064
	.byte	W06
	.byte		        Dn4 , v072
	.byte	W06
	.byte		        Dn4 , v076
	.byte	W06
	.byte		        Dn4 , v084
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v127
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Dn4 , v124
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W60
	.byte		N04   , As4 , v064
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		N03   , An4 , v100
	.byte	W06
	.byte		N01   , An4 , v084
	.byte	W06
	.byte		N08   , An4 , v100
	.byte	W78
	.byte		N01   , Gn2 
	.byte	W03
	.byte		N01   
	.byte	W03
mus_b_arena_6_B1:
	.byte		N03   , Gn2 , v100
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W36
	.byte		N06   , Cn2 
	.byte	W12
	.byte		N24   , Dn2 
	.byte	W36
	.byte		N06   , As2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn2 
	.byte	W03
	.byte		N01   
	.byte	W03
mus_b_arena_6_000:
	.byte		N03   , Gn2 , v100
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W48
	.byte	PEND
	.byte	W90
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	mus_b_arena_6_000
mus_b_arena_6_001:
	.byte	W36
	.byte		N06   , As2 , v100
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn2 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_b_arena_6_000
	.byte	W90
	.byte		N01   , As2 , v100
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Cn3 
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W48
	.byte	W36
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N36   , Cn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn2 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Gn2 
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W36
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N06   , As2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	mus_b_arena_6_000
	.byte	PATT
	 .word	mus_b_arena_6_001
	.byte		N03   , Gn2 , v100
	.byte	W03
	.byte		N44   
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W36
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N01   , Fn2 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Gn2 
	.byte	W03
	.byte		N21   
	.byte	W36
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	GOTO
	 .word	mus_b_arena_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_b_arena_7:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		PAN   , c_v-61
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
	.byte	W72
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Dn4 , v048
	.byte	W12
	.byte		        Fn4 
	.byte	W12
mus_b_arena_7_B1:
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N72   , Gn4 , v048
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W48
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N24   , As4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N48   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W03
	.byte		MOD   , 4
	.byte	W09
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N84   , Dn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W60
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N32   , Dn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N72   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W48
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N24   , As4 
	.byte	W24
	.byte		N36   , Cn5 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N60   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W36
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		N32   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N96   , Cn5 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W72
	.byte		MOD   , 0
	.byte	W24
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N60   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W36
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte	W24
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N24   , As4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N36   , Cn5 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N60   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W36
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W24
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_b_arena_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_b_arena_8:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 19*mus_b_arena_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 81
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		PAN   , c_v-61
	.byte	W24
	.byte		BEND  , c_v+1
	.byte		N04   , As4 , v040
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte		N03   , An4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N08   
	.byte	W12
	.byte		VOICE , 87
	.byte		PAN   , c_v+0
	.byte	W48
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Dn4 , v048
	.byte	W12
	.byte		        Fn4 
	.byte	W12
mus_b_arena_8_B1:
	.byte		MOD   , 1
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N72   , Gn4 , v048
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W48
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , As4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N48   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , Fn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N84   , Dn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W60
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N36   , Dn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N32   , Dn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N72   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W48
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , As4 
	.byte	W24
	.byte		N36   , Cn5 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W03
	.byte		MOD   , 1
	.byte	W09
	.byte		N60   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W36
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , As4 
	.byte	W12
	.byte		N32   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N96   , Cn5 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W72
	.byte		MOD   , 1
	.byte	W24
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N24   , As4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N60   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W36
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W12
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , As4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		MOD   , 1
	.byte	W24
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N24   , As4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		N36   , Cn5 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N60   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W36
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , Dn4 
	.byte	W24
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		VOL   , 45*mus_b_arena_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_b_arena_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 22*mus_b_arena_mvl/mxv
	.byte	W12
	.byte		        45*mus_b_arena_mvl/mxv
	.byte		MOD   , 1
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_b_arena_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_b_arena_9:
	.byte	KEYSH , mus_b_arena_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_b_arena_mvl/mxv
	.byte		N06   , Ds5 , v100
	.byte	W06
	.byte		N24   , Bn4 , v056
	.byte		N24   , Ds5 , v127
	.byte	W96
	.byte	W90
	.byte		N06   , Ds4 , v064
	.byte	W06
	.byte		N24   , Ds4 , v112
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W90
	.byte		N06   , Ds5 , v100
	.byte	W06
	.byte		N24   , Ds5 , v127
	.byte	W36
	.byte		N06   , Ds4 , v064
	.byte		N36   , Bn4 , v100
	.byte	W06
	.byte		N30   , Ds4 
	.byte	W54
	.byte	W96
	.byte	W96
mus_b_arena_9_B1:
mus_b_arena_9_000:
	.byte		N24   , Fn1 , v064
	.byte		N24   , Ds5 , v100
	.byte	W24
	.byte		        Fn1 , v064
	.byte		N24   , Ds5 , v100
	.byte	W24
	.byte		        Bn4 , v048
	.byte	W24
	.byte		        Fn1 , v064
	.byte		N24   , Ds5 , v112
	.byte	W24
	.byte	PEND
	.byte		        Fn1 , v064
	.byte		N24   , Dn2 
	.byte		N24   , Ds5 , v100
	.byte	W48
	.byte		N48   , Cn1 , v127
	.byte		N24   , En4 , v100
	.byte	W48
	.byte	PATT
	 .word	mus_b_arena_9_000
mus_b_arena_9_001:
	.byte		N24   , Fn1 , v064
	.byte		N24   , Dn2 
	.byte		N24   , Ds5 , v100
	.byte	W48
	.byte		N48   , Cn1 , v127
	.byte		N24   , Ds4 , v100
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_b_arena_9_000
mus_b_arena_9_002:
	.byte		N24   , Fn1 , v064
	.byte		N24   , Dn2 
	.byte		N24   , Ds5 , v100
	.byte	W42
	.byte		N01   , En4 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N48   , Cn1 , v127
	.byte		N24   , En4 , v100
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_b_arena_9_000
mus_b_arena_9_003:
	.byte		N24   , Fn1 , v064
	.byte		N24   , Dn2 
	.byte		N24   , Ds5 , v100
	.byte	W48
	.byte		N44   , Cn1 , v127
	.byte		N24   , Ds4 , v100
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_b_arena_9_000
	.byte	PATT
	 .word	mus_b_arena_9_002
	.byte	PATT
	 .word	mus_b_arena_9_000
	.byte	PATT
	 .word	mus_b_arena_9_001
	.byte	PATT
	 .word	mus_b_arena_9_000
	.byte	PATT
	 .word	mus_b_arena_9_002
	.byte		N24   , Fn1 , v064
	.byte		N24   , Ds5 , v100
	.byte	W24
	.byte		        Fn1 , v064
	.byte		N18   , Ds5 , v100
	.byte	W24
	.byte		N24   , Bn4 , v048
	.byte	W24
	.byte		        Fn1 , v064
	.byte		N24   , Ds5 , v112
	.byte	W24
	.byte	PATT
	 .word	mus_b_arena_9_003
	.byte	GOTO
	 .word	mus_b_arena_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_b_arena:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_b_arena_pri	@ Priority
	.byte	mus_b_arena_rev	@ Reverb.

	.word	mus_b_arena_grp

	.word	mus_b_arena_1
	.word	mus_b_arena_2
	.word	mus_b_arena_3
	.word	mus_b_arena_4
	.word	mus_b_arena_5
	.word	mus_b_arena_6
	.word	mus_b_arena_7
	.word	mus_b_arena_8
	.word	mus_b_arena_9

	.end
