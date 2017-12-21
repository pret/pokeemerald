	.include "MPlayDef.s"

	.equ	bgm_battle_dome_tournament_grp, voicegroup_8698054
	.equ	bgm_battle_dome_tournament_pri, 0
	.equ	bgm_battle_dome_tournament_rev, reverb_set+50
	.equ	bgm_battle_dome_tournament_mvl, 127
	.equ	bgm_battle_dome_tournament_key, 0
	.equ	bgm_battle_dome_tournament_tbs, 1
	.equ	bgm_battle_dome_tournament_exg, 0
	.equ	bgm_battle_dome_tournament_cmp, 1

	.section .rodata
	.global	bgm_battle_dome_tournament
	.align	2

@********************** Track  1 **********************@

bgm_battle_dome_tournament_1:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte	TEMPO , 144*bgm_battle_dome_tournament_tbs/2
	.byte		VOICE , 29
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_dome_tournament_1_000:
	.byte	W84
	.byte		N03   , Fn3 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
bgm_battle_dome_tournament_1_B1:
	.byte		N12   , Ds2 , v088
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W48
	.byte	W84
	.byte		N03   , Ds3 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds2 , v088
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs2 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_dome_tournament_1_000
	.byte		VOL   , 68*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Ds2 , v076
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W12
	.byte		VOL   , 58*bgm_battle_dome_tournament_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 51*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        33*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W24
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v-6
	.byte	W12
	.byte		VOL   , 62*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		VOL   , 58*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        54*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        48*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        41*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W02
	.byte		VOL   , 36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        26*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        21*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-12
	.byte	W02
	.byte		VOL   , 8*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        5*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        1*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Ds2 , v088
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs2 
	.byte	W12
	.byte	W96
	.byte		BEND  , c_v+0
	.byte		N06   , Fn2 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-2
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W15
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W09
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		N03   , Cn4 , v068
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W06
	.byte		N03   , Cn4 , v048
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 , v040
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 , v028
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        An2 , v024
	.byte	W03
	.byte		N01   , Gn2 , v088
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cn3 , v076
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn2 , v088
	.byte	W06
	.byte		        Gn2 , v076
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   , Gn4 , v048
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 , v040
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Gn3 , v036
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W03
	.byte		        Fn3 , v028
	.byte	W03
	.byte		        En3 , v024
	.byte	W03
	.byte		        Cn3 , v084
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N01   , Cn3 , v088
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , En3 , v068
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cn3 , v088
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , Gn3 , v068
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		N10   , Fn2 , v088
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
	.byte		N10   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
bgm_battle_dome_tournament_1_001:
	.byte		N10   , Fn2 , v088
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
	.byte		N10   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
	.byte	PEND
	.byte		N10   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   , En2 
	.byte	W04
	.byte		        Fn2 
	.byte	W32
	.byte		N10   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
	.byte	PATT
	 .word	bgm_battle_dome_tournament_1_001
	.byte		PAN   , c_v+16
	.byte		N09   , Cn4 , v052
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N03   , Cn4 , v048
	.byte	W12
	.byte		N06   , Gn2 , v092
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N09   , Bn2 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N18   , Fs2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Cn4 , v048
	.byte	W06
	.byte		MOD   , 6
	.byte		N06   , Bn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Gn2 , v092
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N09   , Bn2 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N12   , Fs2 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_1_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle_dome_tournament_2:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 29
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 77*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_dome_tournament_2_B1:
	.byte	W96
	.byte		VOICE , 29
	.byte		VOL   , 17*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		VOL   , 17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v-5
	.byte		N12   , Fn5 , v036
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N12   , Cn5 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gs4 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N12   , Ds4 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N12   , As3 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Fn3 
	.byte	W12
	.byte		VOL   , 17*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W48
	.byte		VOL   , 55*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W02
	.byte		VOL   , 48*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        39*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 29*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        22*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        14*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        7*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        2*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        1*bgm_battle_dome_tournament_mvl/mxv
	.byte	W24
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte	W12
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v-5
	.byte		N12   , Fn4 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N12   , Cn5 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gs5 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+0
	.byte		N12   , Ds4 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N12   , As3 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N12   , Fn3 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N84   , As4 
	.byte	W03
	.byte		VOL   , 41*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        76*bgm_battle_dome_tournament_mvl/mxv
	.byte	W06
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W12
	.byte		        c_v+0
	.byte	W36
	.byte		VOL   , 55*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 51*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W04
	.byte		VOL   , 44*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		VOL   , 39*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W04
	.byte		VOL   , 29*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-19
	.byte	W02
	.byte		VOL   , 19*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-23
	.byte	W04
	.byte		VOL   , 11*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-26
	.byte	W02
	.byte		VOL   , 1*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-30
	.byte	W04
	.byte		VOL   , 68*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-31
	.byte	W24
	.byte		        c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 30
	.byte	W36
	.byte		N12   , Cn4 , v048
	.byte	W12
	.byte		MOD   , 5
	.byte	W06
	.byte		N01   , Cn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W06
	.byte		N01   , Cn3 
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N60   , Gs3 
	.byte	W24
	.byte		MOD   , 3
	.byte	W12
	.byte		VOL   , 59*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        54*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        51*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        42*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        31*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        24*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte		N03   , En4 
	.byte	W06
	.byte		N12   
	.byte	W90
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
	 .word	bgm_battle_dome_tournament_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle_dome_tournament_3:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 87
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_dome_tournament_3_000:
	.byte	W84
	.byte		N03   , Fn2 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte	PEND
bgm_battle_dome_tournament_3_B1:
	.byte		N12   , Ds1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W48
	.byte	W96
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_dome_tournament_3_000
	.byte		N12   , Ds1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 58*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        51*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        40*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N10   , Fn1 
	.byte	W05
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		VOL   , 75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W12
	.byte		        33*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N07   , As2 
	.byte	W01
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        63*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W21
	.byte		VOL   , 33*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N07   , Gs2 
	.byte	W01
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        63*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOL   , 33*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N07   , Gn2 
	.byte	W01
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        63*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOL   , 33*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N07   , Fs2 
	.byte	W01
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        63*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOL   , 33*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N07   , Fn2 
	.byte	W01
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        63*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOL   , 33*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N07   , En2 
	.byte	W01
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        63*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOL   , 75*bgm_battle_dome_tournament_mvl/mxv
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W12
	.byte	W96
	.byte		        Fn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N24   , Gs1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N03   , Fn1 
	.byte		N01   , Fn2 
	.byte	W06
	.byte		N09   , Fn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W03
	.byte		N09   , As1 
	.byte	W09
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N15   , Fn1 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N24   , Gs1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N03   , Fn1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W03
	.byte		N09   , Cs2 
	.byte	W09
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W06
	.byte		N06   , En1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N15   , Cn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v080
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W06
	.byte		        Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v080
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v080
	.byte	W06
	.byte		N10   , Fn1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        Gs1 , v080
	.byte	W06
	.byte		N10   , Fn1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N06   , Fn1 , v104
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Fs1 , v104
	.byte	W06
	.byte		        Gn1 , v080
	.byte	W06
	.byte		N10   , Fn1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v080
	.byte	W06
	.byte		        Ds1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		N10   , Fn1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        Gs1 , v080
	.byte	W06
	.byte		N10   , Fn1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   , En1 
	.byte	W04
	.byte		        Fn1 
	.byte	W08
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N06   , En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N06   , As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		MOD   , 6
	.byte		N04   , Gs1 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , En1 
	.byte	W04
	.byte		N08   , Cs1 
	.byte	W08
	.byte		N03   , Cn1 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		N09   , Cn1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , Ds1 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N18   
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		MOD   , 6
	.byte		N03   , Cs1 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , En1 
	.byte	W12
	.byte		N09   , Ds1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_3_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle_dome_tournament_4:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 62
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 87*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v-18
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_dome_tournament_4_B1:
	.byte		VOICE , 62
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		        c_v+0
	.byte	W24
	.byte		VOICE , 29
	.byte		N48   , Cs2 , v072
	.byte	W24
	.byte		PAN   , c_v-12
	.byte	W02
	.byte		        c_v-8
	.byte	W04
	.byte		        c_v-5
	.byte	W02
	.byte		        c_v-1
	.byte	W04
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+6
	.byte	W04
	.byte		        c_v+7
	.byte	W02
	.byte		        c_v+11
	.byte	W04
	.byte		MOD   , 3
	.byte		PAN   , c_v+16
	.byte		N48   , Ds2 , v060
	.byte	W02
	.byte		PAN   , c_v+22
	.byte	W04
	.byte		        c_v+23
	.byte	W02
	.byte		        c_v+28
	.byte	W04
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+37
	.byte	W04
	.byte		        c_v+43
	.byte	W02
	.byte		        c_v+48
	.byte	W04
	.byte		VOL   , 90*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        87*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        85*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        82*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        78*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        73*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        70*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        65*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        61*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        60*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        55*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        53*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        53*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        47*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        43*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-19
	.byte		VOL   , 90*bgm_battle_dome_tournament_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		VOICE , 29
	.byte		PAN   , c_v-19
	.byte		BEND  , c_v+0
	.byte	W36
	.byte		N12   , Fn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N01   , Fn2 , v080
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , Ds3 , v060
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N01   , Fn2 , v080
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N60   , Cs3 , v060
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		MOD   , 5
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		VOL   , 84*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        70*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        65*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        60*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		VOL   , 54*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        50*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		VOL   , 43*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        90*bgm_battle_dome_tournament_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W36
	.byte		N12   , Fn3 , v056
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N01   , Fn2 , v080
	.byte	W06
	.byte		MOD   , 0
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , Ds3 , v056
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		N01   , Fn2 , v112
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		N01   , Fn2 , v080
	.byte	W12
	.byte		        Fn2 , v076
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N60   , Cs3 , v056
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		MOD   , 3
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		VOL   , 84*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        70*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        65*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        60*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        54*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        50*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        43*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        90*bgm_battle_dome_tournament_mvl/mxv
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 17
	.byte		PAN   , c_v+9
	.byte	W18
	.byte		N03   , Ds4 , v032
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N24   , Fn4 , v060
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N03   , Fn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		N15   , Fn4 
	.byte	W09
	.byte		MOD   , 4
	.byte	W06
	.byte		        0
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N15   , Gs4 
	.byte	W06
	.byte		MOD   , 4
	.byte	W09
	.byte		        0
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle_dome_tournament_5:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 30
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v-24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , Fn2 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
bgm_battle_dome_tournament_5_B1:
	.byte		VOICE , 62
	.byte		N12   , Ds1 , v080
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W24
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		        c_v+0
	.byte	W24
	.byte		N48   , Gs1 , v072
	.byte	W24
	.byte		PAN   , c_v-16
	.byte	W02
	.byte		        c_v-12
	.byte	W06
	.byte		        c_v-9
	.byte	W04
	.byte		        c_v-7
	.byte	W02
	.byte		        c_v-3
	.byte	W04
	.byte		        c_v-1
	.byte	W02
	.byte		        c_v+2
	.byte	W04
	.byte		        c_v+6
	.byte		N48   , As1 , v080
	.byte	W02
	.byte		PAN   , c_v+11
	.byte	W04
	.byte		        c_v+16
	.byte	W02
	.byte		        c_v+20
	.byte	W04
	.byte		        c_v+23
	.byte	W02
	.byte		        c_v+26
	.byte	W04
	.byte		        c_v+29
	.byte	W02
	.byte		        c_v+32
	.byte	W04
	.byte		        c_v+36
	.byte		VOL   , 90*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        87*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        85*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        82*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        78*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        73*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        70*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        65*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        61*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        60*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        55*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        53*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        53*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        47*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        43*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-24
	.byte		VOL   , 90*bgm_battle_dome_tournament_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		VOICE , 29
	.byte		PAN   , c_v-34
	.byte	W36
	.byte		N12   , Cn3 , v060
	.byte	W24
	.byte		N01   , Cn2 , v084
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , As2 , v060
	.byte	W12
	.byte	W18
	.byte		N01   , Cn2 , v080
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N60   , Gs2 , v060
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-2
	.byte	W12
	.byte		VOL   , 78*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 71*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        65*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        58*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        53*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		VOL   , 48*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        42*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		VOL   , 34*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        90*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W36
	.byte		N12   , Cn3 , v056
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N01   , Cn2 , v080
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , As2 , v056
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte	W06
	.byte		N01   , Cn2 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		        Cn2 , v076
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N60   , Gs2 , v056
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		VOL   , 84*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        75*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        70*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        65*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        60*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        54*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        50*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        43*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		VOICE , 29
	.byte		VOL   , 90*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v-20
	.byte		N03   , Cn3 , v060
	.byte	W06
	.byte		N12   
	.byte	W66
	.byte		N01   , Cn2 , v068
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	W72
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		VOICE , 17
	.byte	W24
	.byte		N24   , Gs3 , v060
	.byte	W48
	.byte		PAN   , c_v+24
	.byte		N24   , As3 
	.byte	W24
	.byte	W24
	.byte		PAN   , c_v-21
	.byte		N24   , Fn3 
	.byte	W48
	.byte		PAN   , c_v+23
	.byte		N24   , Gs3 
	.byte	W24
	.byte	W24
	.byte		PAN   , c_v-21
	.byte		N03   , Cn4 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N15   , Cn4 
	.byte	W36
	.byte	W03
	.byte		PAN   , c_v+22
	.byte		N24   , As3 
	.byte	W24
	.byte	W24
	.byte		PAN   , c_v-22
	.byte		N03   , Fn3 
	.byte	W03
	.byte		N06   , En3 
	.byte	W06
	.byte		N15   , Fn3 
	.byte	W36
	.byte	W03
	.byte		PAN   , c_v+23
	.byte		N24   , Cn4 
	.byte	W24
	.byte		PAN   , c_v-22
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle_dome_tournament_6:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 84
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , Fn2 , v084
	.byte	W06
	.byte		N03   
	.byte	W06
bgm_battle_dome_tournament_6_B1:
	.byte		N12   , Ds1 , v084
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W48
	.byte	W84
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W12
	.byte	W84
	.byte		N03   , Fn2 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 68*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W12
	.byte		VOL   , 58*bgm_battle_dome_tournament_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 51*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        33*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W24
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v-6
	.byte	W12
	.byte		VOL   , 62*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		VOL   , 58*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        54*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        48*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        41*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W02
	.byte		VOL   , 36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        26*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        21*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-12
	.byte	W02
	.byte		VOL   , 8*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        5*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        1*bgm_battle_dome_tournament_mvl/mxv
	.byte	W04
	.byte		        68*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 , v084
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W12
	.byte	W96
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W30
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-2
	.byte	W12
	.byte		        c_v-4
	.byte	W12
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-11
	.byte	W06
	.byte		        c_v+0
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W15
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W09
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W30
	.byte		N03   , Cn3 , v072
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W06
	.byte		N03   , Cn3 , v044
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Dn2 , v040
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Bn1 , v036
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N01   , Gn1 , v080
	.byte	W06
	.byte		        Gn1 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N01   , Gn1 , v080
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   , En2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   , Gn3 , v048
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        As2 , v040
	.byte	W03
	.byte		        An2 , v044
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		        Gn2 , v032
	.byte	W03
	.byte		        Fs2 , v028
	.byte	W03
	.byte		        Fn2 , v024
	.byte	W03
	.byte		        En2 , v020
	.byte	W03
	.byte		        Cn2 , v080
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , En2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N04   
	.byte	W06
bgm_battle_dome_tournament_6_000:
	.byte		N10   , Fn1 , v080
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
	.byte		N10   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_dome_tournament_6_000
	.byte		N10   , Fn1 , v080
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   , En1 
	.byte	W04
	.byte		        Fn1 
	.byte	W32
	.byte		N10   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W32
	.byte	PATT
	 .word	bgm_battle_dome_tournament_6_000
	.byte		N09   , Cn3 , v080
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N03   
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N09   , Bn1 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Cn3 
	.byte	W06
	.byte		MOD   , 6
	.byte		N06   , Bn2 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N09   , Bn1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N12   , Fs1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_6_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  7 **********************@

bgm_battle_dome_tournament_7:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle_dome_tournament_7_000:
	.byte	W84
	.byte		N03   , Fn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
bgm_battle_dome_tournament_7_B1:
	.byte		N12   , Ds1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W24
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W48
	.byte	W84
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_dome_tournament_7_000
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 , v112
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W18
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		MOD   , 6
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N48   , Cs2 
	.byte	W48
	.byte		        Ds2 
	.byte	W24
	.byte		VOL   , 39*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        38*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        34*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        33*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        32*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        31*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        31*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        30*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        28*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        27*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        26*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        22*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        21*bgm_battle_dome_tournament_mvl/mxv
	.byte	W01
	.byte		        20*bgm_battle_dome_tournament_mvl/mxv
	.byte	W03
	.byte		        45*bgm_battle_dome_tournament_mvl/mxv
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Gs1 
	.byte	W12
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N60   , Cs3 
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		MOD   , 5
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		VOL   , 40*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        35*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        32*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        30*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        25*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		VOL   , 21*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        17*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        14*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		VOL   , 11*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        10*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Fn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N60   , Cs3 
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		MOD   , 3
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		VOL   , 39*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        36*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        33*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        30*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        27*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        24*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        22*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        18*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        15*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        13*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		        12*bgm_battle_dome_tournament_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_battle_dome_tournament_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N10   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   , En1 
	.byte	W04
	.byte		        Fn1 
	.byte	W08
	.byte		N03   , Fn3 
	.byte	W03
	.byte		N06   , En3 
	.byte	W06
	.byte		N15   , Fn3 
	.byte	W15
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N15   , Gs3 
	.byte	W15
	.byte		N10   , Fn1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		N24   , As3 
	.byte	W24
	.byte		N09   , Cn3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N03   
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N09   , Bn1 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N06   , Cn3 
	.byte	W06
	.byte		MOD   , 6
	.byte		N06   , Bn2 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Cn3 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N09   , Bn1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N12   , Fs1 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_7_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  8 **********************@

bgm_battle_dome_tournament_8:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_battle_dome_tournament_mvl/mxv
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Ds1 , v064
	.byte	W12
	.byte		        Ds1 , v036
	.byte	W12
	.byte		        Ds1 , v028
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Ds1 , v064
	.byte	W12
	.byte		        Ds1 , v036
	.byte	W12
	.byte		        Ds1 , v028
	.byte	W12
bgm_battle_dome_tournament_8_000:
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Ds1 , v064
	.byte	W12
	.byte		        Ds1 , v036
	.byte	W12
	.byte		        Ds1 , v028
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte		        Cn1 
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N36   , Cs2 , v068
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Ds1 , v064
	.byte	W12
	.byte		        Ds1 , v112
	.byte		N12   , An2 , v072
	.byte	W06
	.byte		N06   , Dn1 , v112
	.byte	W06
bgm_battle_dome_tournament_8_B1:
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fn1 
	.byte		N24   , Gn2 , v084
	.byte	W24
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Ds1 , v064
	.byte		N06   , Cn2 , v112
	.byte	W12
	.byte		        Ds1 , v036
	.byte		N06   , Bn1 , v112
	.byte	W12
	.byte		        Ds1 , v028
	.byte		N06   , Gn1 , v112
	.byte	W12
bgm_battle_dome_tournament_8_001:
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Ds1 , v064
	.byte	W12
	.byte		        Ds1 , v036
	.byte	W12
	.byte		        Ds1 , v028
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_dome_tournament_8_000
	.byte		N06   , Cn1 , v112
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte		N06   , Dn1 
	.byte		N12   , Gn1 
	.byte		N24   , An2 , v072
	.byte	W12
	.byte		N12   , Fn1 , v112
	.byte	W09
	.byte		N03   , Dn1 , v072
	.byte	W03
	.byte		N06   , Dn1 , v112
	.byte		N06   , Ds1 
	.byte		N24   , Cs2 , v076
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte		N06   , Ds1 , v064
	.byte		N12   , Fn1 , v112
	.byte	W12
	.byte		N06   , Ds1 , v036
	.byte	W12
	.byte		        Dn1 , v112
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Ds1 , v064
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N06   , Ds1 , v036
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N06   , Ds1 , v028
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_dome_tournament_8_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_8_000
	.byte		N06   , Cn1 , v112
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte		N06   , Dn1 
	.byte		N12   , Gn1 
	.byte		N12   , Cs2 , v076
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte		N12   , An2 , v088
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte		N24   , Gn2 , v084
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte		N24   , An2 , v084
	.byte	W18
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W18
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W18
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W18
	.byte		        Dn1 
	.byte		N18   , An2 , v080
	.byte	W06
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte		N12   , En2 , v088
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte		N06   , Fn1 
	.byte		N24   , Cs2 , v084
	.byte	W18
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N12   , Cn2 
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		N06   
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En2 , v064
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , Cs2 , v064
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N12   , An2 , v076
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte		N24   , En2 , v084
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        Dn2 , v064
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , An1 
	.byte	W03
	.byte		        An1 , v064
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Gn1 , v064
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte		N12   , En2 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte		N12   , En2 , v088
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , Cs2 , v064
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N12   , An2 , v080
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte		N24   , En2 , v076
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        Dn2 , v064
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , An1 
	.byte	W03
	.byte		        An1 , v064
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Gn1 , v064
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte		N12   , En2 , v084
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N04   
	.byte		N24   , An2 , v096
	.byte	W12
	.byte		N04   , Cn1 , v112
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte		N24   , Cs2 , v080
	.byte	W24
	.byte		N04   , Cn1 , v112
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte		N24   , An2 , v076
	.byte	W24
	.byte		N04   , Cn1 , v112
	.byte		N24   , Cs2 , v080
	.byte	W12
	.byte		N04   , Cn1 , v112
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte		N24   , Gn2 , v080
	.byte	W24
	.byte		N04   , Cn1 , v112
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte		N24   , An2 , v076
	.byte	W06
	.byte		N06   , Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		N04   , Cn1 , v112
	.byte		N24   , Cs2 , v088
	.byte	W12
	.byte		N04   , Cn1 , v112
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte		N24   , An2 , v084
	.byte	W48
	.byte		N04   , Dn1 , v112
	.byte		N24   , Cs2 , v076
	.byte	W24
	.byte		N04   , Cn1 , v112
	.byte		N24   , Cs2 , v088
	.byte	W12
	.byte		N04   , Cn1 , v112
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte	W24
	.byte		N06   , Cn1 
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Bn1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W18
	.byte		N06   
	.byte		N06   , Fn1 
	.byte	W24
	.byte		N12   , Dn1 
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Dn1 , v064
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Dn1 , v036
	.byte		N12   , Ds1 
	.byte	W06
	.byte		N18   , Fn1 , v112
	.byte	W06
	.byte		N12   , Dn1 , v016
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Fn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Bn1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N24   , An1 
	.byte	W24
	.byte		N06   , Cn1 
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N18   , Dn1 
	.byte		N18   , Ds1 
	.byte		N18   , En2 , v080
	.byte	W18
	.byte		        Dn1 , v112
	.byte		N18   , An2 , v092
	.byte	W18
	.byte		N12   , Dn1 , v112
	.byte		N12   , Cs2 , v092
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_battle_dome_tournament_9:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*bgm_battle_dome_tournament_mvl/mxv
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
bgm_battle_dome_tournament_9_000:
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W24
	.byte	PEND
bgm_battle_dome_tournament_9_001:
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
bgm_battle_dome_tournament_9_B1:
bgm_battle_dome_tournament_9_002:
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_000
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_002
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_000
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_002
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_000
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	W96
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_001
bgm_battle_dome_tournament_9_003:
	.byte		N01   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_003
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_003
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_003
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_003
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_003
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_003
	.byte	PATT
	 .word	bgm_battle_dome_tournament_9_003
	.byte	GOTO
	 .word	bgm_battle_dome_tournament_9_B1
	.byte	FINE

@********************** Track 10 **********************@

bgm_battle_dome_tournament_10:
	.byte	KEYSH , bgm_battle_dome_tournament_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_battle_dome_tournament_mvl/mxv
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte	W96
	.byte	W96
bgm_battle_dome_tournament_10_B1:
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   
	.byte	W12
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
	 .word	bgm_battle_dome_tournament_10_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle_dome_tournament:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle_dome_tournament_pri	@ Priority
	.byte	bgm_battle_dome_tournament_rev	@ Reverb.

	.word	bgm_battle_dome_tournament_grp

	.word	bgm_battle_dome_tournament_1
	.word	bgm_battle_dome_tournament_2
	.word	bgm_battle_dome_tournament_3
	.word	bgm_battle_dome_tournament_4
	.word	bgm_battle_dome_tournament_5
	.word	bgm_battle_dome_tournament_6
	.word	bgm_battle_dome_tournament_7
	.word	bgm_battle_dome_tournament_8
	.word	bgm_battle_dome_tournament_9
	.word	bgm_battle_dome_tournament_10

	.end
