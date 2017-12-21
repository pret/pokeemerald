	.include "MPlayDef.s"

	.equ	bgm_battle_factory_grp, voicegroup_8698C54
	.equ	bgm_battle_factory_pri, 0
	.equ	bgm_battle_factory_rev, reverb_set+50
	.equ	bgm_battle_factory_mvl, 127
	.equ	bgm_battle_factory_key, 0
	.equ	bgm_battle_factory_tbs, 1
	.equ	bgm_battle_factory_exg, 0
	.equ	bgm_battle_factory_cmp, 1

	.section .rodata
	.global	bgm_battle_factory
	.align	2

@********************** Track  1 **********************@

bgm_battle_factory_1:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte	TEMPO , 144*bgm_battle_factory_tbs/2
	.byte		VOICE , 29
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*bgm_battle_factory_mvl/mxv
	.byte	W72
	.byte	W96
bgm_battle_factory_1_B1:
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
	.byte		VOICE , 29
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+0
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		N06   , En2 
	.byte	W01
	.byte		PAN   , c_v+32
	.byte	W05
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W01
	.byte		PAN   , c_v-32
	.byte	W05
	.byte		N06   , Dn2 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W01
	.byte		PAN   , c_v+31
	.byte	W05
	.byte		N06   , Bn2 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+63
	.byte		N24   , Dn2 
	.byte	W03
	.byte		BEND  , c_v+38
	.byte	W03
	.byte		        c_v+26
	.byte	W02
	.byte		        c_v+0
	.byte	W04
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-63
	.byte	W03
	.byte		        c_v+0
	.byte	W96
	.byte	W96
	.byte		VOICE , 12
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-18
	.byte		N05   , Fn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		        Cn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		VOL   , 56*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N05   , Dn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		BEND  , c_v+2
	.byte		N05   , En3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		VOL   , 62*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Gn3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N05   , En3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		BEND  , c_v+1
	.byte		N05   , Fs3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte		PAN   , c_v-23
	.byte		N06   , Gs3 
	.byte	W18
	.byte		        En3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W15
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N24   , An3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W18
	.byte		        En3 
	.byte	W06
	.byte		N48   , Fs3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        28*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        15*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte		VOICE , 14
	.byte		PAN   , c_v+18
	.byte		VOL   , 75*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		N84   , Gs3 , v120
	.byte	W36
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		        c_v+16
	.byte	W04
	.byte		        c_v+12
	.byte	W02
	.byte		        c_v+9
	.byte	W04
	.byte		        c_v+6
	.byte	W02
	.byte		        c_v+2
	.byte	W04
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v-7
	.byte		VOL   , 70*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		VOL   , 59*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-14
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-18
	.byte		VOL   , 44*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		VOL   , 32*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-29
	.byte		VOL   , 22*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-37
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		VOL   , 79*bgm_battle_factory_mvl/mxv
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle_factory_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle_factory_2:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		VOICE , 4
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 100*bgm_battle_factory_mvl/mxv
	.byte		N01   , En2 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 5
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
bgm_battle_factory_2_B1:
	.byte		N04   , Gn2 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 1
	.byte		N04   , En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 3
	.byte	W06
	.byte		N04   , En3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 2
	.byte		N01   , En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
bgm_battle_factory_2_000:
	.byte		VOICE , 4
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
bgm_battle_factory_2_001:
	.byte		VOICE , 5
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
bgm_battle_factory_2_002:
	.byte		VOICE , 1
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
bgm_battle_factory_2_003:
	.byte		VOICE , 3
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 2
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
bgm_battle_factory_2_004:
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 3
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_2_002
	.byte	PATT
	 .word	bgm_battle_factory_2_001
bgm_battle_factory_2_005:
	.byte		VOICE , 4
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 39
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
bgm_battle_factory_2_006:
	.byte		VOICE , 87
	.byte		N01   , En1 , v048
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_2_002
	.byte	PATT
	 .word	bgm_battle_factory_2_002
	.byte		VOICE , 3
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 2
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 87
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 2
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 3
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
bgm_battle_factory_2_007:
	.byte		VOICE , 1
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 39
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_2_001
	.byte	PATT
	 .word	bgm_battle_factory_2_000
	.byte		VOICE , 4
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 87
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 5
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 39
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 2
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	PATT
	 .word	bgm_battle_factory_2_007
	.byte	PATT
	 .word	bgm_battle_factory_2_003
	.byte	PATT
	 .word	bgm_battle_factory_2_004
	.byte	PATT
	 .word	bgm_battle_factory_2_002
	.byte	PATT
	 .word	bgm_battle_factory_2_001
	.byte	PATT
	 .word	bgm_battle_factory_2_005
	.byte	PATT
	 .word	bgm_battle_factory_2_006
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 39
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N04   , En1 , v032
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PATT
	 .word	bgm_battle_factory_2_002
	.byte		VOICE , 3
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 2
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 87
	.byte		BEND  , c_v+0
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N72   , Bn3 , v052
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        32
	.byte	W24
	.byte		        64
	.byte	W01
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v+3
	.byte	W01
	.byte		        c_v+6
	.byte	W01
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+13
	.byte	W01
	.byte		        c_v+17
	.byte	W01
	.byte		        c_v+22
	.byte	W01
	.byte		        c_v+25
	.byte	W01
	.byte		        c_v+31
	.byte	W02
	.byte		MOD   , 127
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		        c_v+43
	.byte	W01
	.byte		        c_v+52
	.byte	W01
	.byte		        c_v+59
	.byte	W01
	.byte		        c_v+62
	.byte	W02
	.byte		        c_v+63
	.byte	W06
	.byte		VOICE , 39
	.byte		BEND  , c_v+3
	.byte		N01   , En1 , v048
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOICE , 4
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 6
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 7
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 8
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 39
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 9
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 10
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_factory_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle_factory_3:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 88*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W96
bgm_battle_factory_3_B1:
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 , v056
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   , En4 , v060
	.byte	W18
	.byte		PAN   , c_v+32
	.byte	W18
	.byte		N04   , En4 , v052
	.byte	W06
	.byte		VOICE , 38
	.byte	W24
	.byte		PAN   , c_v-53
	.byte		N01   , En1 , v076
	.byte	W01
	.byte		        Fn1 
	.byte	W01
	.byte		        Fs1 , v080
	.byte	W01
	.byte		        Gn1 
	.byte	W01
	.byte		        Gs1 
	.byte	W02
	.byte		PAN   , c_v-53
	.byte		N01   , An1 , v084
	.byte	W01
	.byte		PAN   , c_v-49
	.byte		N01   , As1 
	.byte	W01
	.byte		PAN   , c_v-42
	.byte		N01   , Bn1 
	.byte	W01
	.byte		PAN   , c_v-34
	.byte		N01   , Cn2 , v088
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		N01   , Cs2 
	.byte	W02
	.byte		PAN   , c_v-27
	.byte		N01   , Dn2 
	.byte	W01
	.byte		PAN   , c_v-20
	.byte		N01   , Ds2 
	.byte	W01
	.byte		PAN   , c_v-16
	.byte		N01   , En2 , v092
	.byte	W01
	.byte		PAN   , c_v-9
	.byte		N01   , Fn2 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Fs2 
	.byte	W02
	.byte		PAN   , c_v+7
	.byte		N01   , Gn2 , v096
	.byte	W01
	.byte		PAN   , c_v+12
	.byte		N01   , Gs2 
	.byte	W01
	.byte		PAN   , c_v+16
	.byte		N01   , An2 
	.byte	W01
	.byte		PAN   , c_v+23
	.byte		N01   , As2 
	.byte	W01
	.byte		PAN   , c_v+40
	.byte		N01   , Bn2 , v112
	.byte	W02
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
	.byte		VOICE , 47
	.byte		PAN   , c_v+16
	.byte	W12
	.byte		N06   , En4 , v048
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N24   , En3 , v060
	.byte	W96
	.byte		PAN   , c_v+15
	.byte		N06   , En4 , v048
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   
	.byte	W06
	.byte		        Bn3 , v056
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v+32
	.byte		N06   , Bn3 , v052
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N24   , En3 , v060
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		VOICE , 35
	.byte		PAN   , c_v-32
	.byte		VOL   , 64*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N01   , En1 , v064
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N01   , Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N01   , Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N04   , Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   , Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 38
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N04   , Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   , Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		MOD   , 127
	.byte		VOL   , 81*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+63
	.byte		N48   , Dn2 , v088
	.byte	W02
	.byte		BEND  , c_v+62
	.byte	W01
	.byte		        c_v+60
	.byte	W01
	.byte		        c_v+57
	.byte	W02
	.byte		        c_v+53
	.byte	W01
	.byte		        c_v+46
	.byte	W01
	.byte		PAN   , c_v-27
	.byte	W01
	.byte		        c_v-24
	.byte	W01
	.byte		        c_v-17
	.byte		BEND  , c_v+43
	.byte	W02
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v+41
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+35
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+32
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+27
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W02
	.byte		BEND  , c_v+25
	.byte	W01
	.byte		PAN   , c_v+13
	.byte		BEND  , c_v+22
	.byte	W01
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		PAN   , c_v+18
	.byte		BEND  , c_v+14
	.byte	W01
	.byte		PAN   , c_v+24
	.byte		BEND  , c_v+11
	.byte	W02
	.byte		        c_v+6
	.byte	W01
	.byte		PAN   , c_v+29
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-10
	.byte	W01
	.byte		VOL   , 81*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+38
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		VOL   , 75*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+41
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		VOL   , 71*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+44
	.byte		BEND  , c_v-28
	.byte	W01
	.byte		VOL   , 66*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		VOL   , 65*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-40
	.byte	W01
	.byte		VOL   , 59*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-50
	.byte	W02
	.byte		VOL   , 57*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-54
	.byte	W01
	.byte		VOL   , 52*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-60
	.byte	W01
	.byte		VOL   , 48*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-63
	.byte	W01
	.byte		VOL   , 44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        40*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        33*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        31*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        27*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte	W02
	.byte		MOD   , 0
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 38
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		VOL   , 69*bgm_battle_factory_mvl/mxv
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		BEND  , c_v+1
	.byte		N06   , En1 , v080
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , En1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte	W06
	.byte		N06   , En2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		VOL   , 100*bgm_battle_factory_mvl/mxv
	.byte		N04   , Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N48   , Fs3 , v100
	.byte	W12
	.byte		MOD   , 8
	.byte	W06
	.byte		        18
	.byte	W06
	.byte		        127
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-23
	.byte	W01
	.byte		        c_v-25
	.byte	W01
	.byte		VOL   , 87*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-30
	.byte	W01
	.byte		VOL   , 81*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-33
	.byte	W02
	.byte		VOL   , 79*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W01
	.byte		VOL   , 70*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-41
	.byte	W01
	.byte		VOL   , 59*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-45
	.byte	W01
	.byte		VOL   , 55*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-49
	.byte	W01
	.byte		VOL   , 47*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-54
	.byte	W02
	.byte		VOL   , 41*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-57
	.byte	W01
	.byte		VOL   , 32*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-60
	.byte	W01
	.byte		VOL   , 26*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-64
	.byte	W01
	.byte		VOL   , 21*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        75*bgm_battle_factory_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 56
	.byte		VOL   , 100*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N04   , En3 , v084
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N04   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N04   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N04   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_factory_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle_factory_4:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-18
	.byte	W72
	.byte	W96
bgm_battle_factory_4_B1:
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
	.byte		VOICE , 73
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-24
	.byte		VOL   , 25*bgm_battle_factory_mvl/mxv
	.byte		N02   , Ds6 , v112
	.byte	W02
	.byte		N22   , Dn6 
	.byte	W22
	.byte		N06   , Cn6 
	.byte	W16
	.byte		        As5 
	.byte	W08
	.byte		N24   , An5 
	.byte	W24
	.byte		N06   , Gn5 
	.byte	W16
	.byte		        As5 
	.byte	W08
	.byte		N24   , Gn5 
	.byte	W24
	.byte		N02   , Ds5 
	.byte	W02
	.byte		N44   , Dn5 
	.byte	W68
	.byte	W02
	.byte	W96
	.byte	W96
	.byte		VOICE , 47
	.byte		VOL   , 100*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-21
	.byte		N06   , En2 , v096
	.byte	W24
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En2 
	.byte	W24
	.byte		N06   
	.byte	W36
	.byte		        Bn1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle_factory_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle_factory_5:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 23*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-64
	.byte	W24
	.byte		N01   , En2 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+62
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v+63
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N01   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
bgm_battle_factory_5_B1:
	.byte		PAN   , c_v-64
	.byte		N01   , En1 , v112
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N01   , Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 92
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+3
	.byte		N18   , En1 , v127
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+12
	.byte	W01
	.byte		        c_v+18
	.byte	W01
	.byte		        c_v+23
	.byte	W01
	.byte		        c_v+26
	.byte	W01
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+34
	.byte	W01
	.byte		        c_v+39
	.byte	W01
	.byte		        c_v+44
	.byte	W01
	.byte		        c_v+53
	.byte	W01
	.byte		        c_v+60
	.byte	W01
	.byte		        c_v+63
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		VOICE , 80
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W18
	.byte		N01   , Cs4 , v048
	.byte	W01
	.byte		        Dn4 
	.byte	W01
	.byte		        En4 
	.byte	W01
	.byte		        Fn4 
	.byte	W01
	.byte		        Fs4 
	.byte	W02
	.byte		N28   , Gn4 , v112
	.byte	W28
	.byte		PAN   , c_v+63
	.byte		N01   , Gs4 , v048
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte		        As4 
	.byte	W01
	.byte		        Bn4 
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Cs5 
	.byte	W02
	.byte		N14   , Dn5 , v112
	.byte	W14
	.byte		PAN   , c_v-64
	.byte		N01   , Cs5 , v048
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Bn4 
	.byte	W02
	.byte		        As4 
	.byte	W01
	.byte		        An4 
	.byte	W01
	.byte		        Gs4 
	.byte	W01
	.byte		        Gn4 
	.byte	W01
	.byte		        Fs4 
	.byte	W02
	.byte		N21   , Fn4 , v112
	.byte	W12
	.byte	W09
	.byte		PAN   , c_v+63
	.byte		N01   , En4 , v048
	.byte	W01
	.byte		        Ds4 
	.byte	W02
	.byte		N48   , Dn4 , v112
	.byte	W60
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		VOICE , 93
	.byte		PAN   , c_v+63
	.byte		VOL   , 25*bgm_battle_factory_mvl/mxv
	.byte		N03   , En4 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 92
	.byte		N03   , En4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 80
	.byte		N03   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N03   , Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 25*bgm_battle_factory_mvl/mxv
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 93
	.byte		PAN   , c_v-64
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		N32   , Bn4 
	.byte	W32
	.byte		PAN   , c_v+63
	.byte		N01   , As4 , v064
	.byte	W01
	.byte		        An4 
	.byte	W01
	.byte		        Gs4 
	.byte	W02
	.byte		N30   , Gn4 
	.byte	W30
	.byte	W01
	.byte		PAN   , c_v-64
	.byte		N01   , Fs4 
	.byte	W01
	.byte		        Fn4 
	.byte	W01
	.byte		        En4 
	.byte	W01
	.byte		        Ds4 
	.byte	W02
	.byte		N20   , Dn4 
	.byte	W20
	.byte		PAN   , c_v+63
	.byte		N01   , Ds4 
	.byte	W01
	.byte		        En4 
	.byte	W01
	.byte		        Fn4 
	.byte	W02
	.byte		N24   , Fs4 , v112
	.byte	W24
	.byte	W03
	.byte		PAN   , c_v-64
	.byte		N01   , Gn4 , v064
	.byte	W01
	.byte		        Gs4 
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte		        As4 
	.byte	W01
	.byte		        Bn4 
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Cs5 
	.byte	W02
	.byte		N32   , Dn5 , v112
	.byte	W32
	.byte	W01
	.byte		PAN   , c_v+63
	.byte		N01   , Cs5 , v064
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		N18   , Bn4 , v112
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Cn5 , v064
	.byte	W01
	.byte		        Cs5 
	.byte	W01
	.byte		        Dn5 
	.byte	W01
	.byte		        Ds5 
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		N48   , Fn5 , v112
	.byte	W48
	.byte		VOICE , 80
	.byte		VOL   , 25*bgm_battle_factory_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 93
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W24
	.byte	W24
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		N03   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+62
	.byte		N03   , En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		VOL   , 25*bgm_battle_factory_mvl/mxv
	.byte		N03   , En4 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v-64
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		VOICE , 92
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		N36   , Bn2 
	.byte	W24
	.byte		MOD   , 32
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N36   , En3 
	.byte	W24
	.byte		MOD   , 32
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N36   , Ds4 
	.byte	W24
	.byte		MOD   , 32
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N36   , Bn3 
	.byte	W24
	.byte		MOD   , 32
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N24   , Gs3 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N48   , Fn4 
	.byte	W36
	.byte		MOD   , 32
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		VOICE , 93
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		PAN   , c_v-64
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N01   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v+63
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v+62
	.byte		N03   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v-64
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v+63
	.byte		N03   , En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 91
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N03   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 92
	.byte		N32   , Bn2 
	.byte	W12
	.byte		MOD   , 32
	.byte	W20
	.byte		        0
	.byte		PAN   , c_v+63
	.byte		N01   , As2 , v064
	.byte	W01
	.byte		        An2 
	.byte	W01
	.byte		        Gs2 
	.byte	W02
	.byte		N30   , Gn2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W19
	.byte		        0
	.byte		PAN   , c_v-64
	.byte		N01   , Fs2 , v064
	.byte	W01
	.byte		        Fn2 
	.byte	W01
	.byte		        En2 
	.byte	W01
	.byte		        Ds2 
	.byte	W02
	.byte		N20   , Dn2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W08
	.byte		        0
	.byte		PAN   , c_v+63
	.byte		N01   , Ds2 , v064
	.byte	W01
	.byte		        En2 
	.byte	W01
	.byte		        Fn2 
	.byte	W02
	.byte		N28   , Fs2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W16
	.byte		        0
	.byte		PAN   , c_v-64
	.byte		N01   , Gn2 , v064
	.byte	W02
	.byte		        Gs2 
	.byte	W01
	.byte		        An2 
	.byte	W01
	.byte		        As2 
	.byte	W01
	.byte		        Bn2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		N28   , Cs3 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W16
	.byte		        0
	.byte		PAN   , c_v+63
	.byte		N01   , Cn3 , v064
	.byte	W02
	.byte		        Bn2 
	.byte	W01
	.byte		        As2 
	.byte	W01
	.byte		        An2 
	.byte	W01
	.byte		        Gs2 
	.byte	W01
	.byte		        Gn2 
	.byte	W02
	.byte		N21   , Fs2 , v112
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v-64
	.byte	W09
	.byte		N01   , Fn2 , v064
	.byte	W01
	.byte		        En2 
	.byte	W02
	.byte		N48   , Ds2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W36
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte		VOICE , 80
	.byte		N03   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N09   
	.byte	W12
	.byte		N03   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		VOICE , 91
	.byte		PAN   , c_v+62
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 93
	.byte		PAN   , c_v-64
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N03   , Bn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		VOICE , 91
	.byte		N03   , Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , Fs4 , v048
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , Bn4 
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-64
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , Ds4 
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , An4 
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W24
	.byte	W03
	.byte		VOICE , 80
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W16
	.byte		N05   
	.byte	W12
	.byte		        An3 , v064
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        An3 , v064
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        An3 , v064
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W08
	.byte		VOICE , 92
	.byte		PAN   , c_v-63
	.byte	W04
	.byte		N05   , An3 , v064
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Bn3 , v064
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Bn3 , v064
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Bn3 , v064
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W08
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N05   , Bn3 , v064
	.byte	W12
	.byte		        An3 , v112
	.byte	W12
	.byte		        Cn4 , v064
	.byte	W12
	.byte		        An3 , v112
	.byte	W12
	.byte		        Cn4 , v064
	.byte	W12
	.byte		        An3 , v112
	.byte	W12
	.byte		        Cn4 , v064
	.byte	W12
	.byte		        An3 , v112
	.byte	W08
	.byte		PAN   , c_v-63
	.byte	W04
	.byte		N05   , Cn4 , v064
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Dn4 , v064
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Dn4 , v064
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Dn4 , v064
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W08
	.byte		VOL   , 25*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte		N04   , Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W78
bgm_battle_factory_5_000:
	.byte		VOL   , 24*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte		VOICE , 80
	.byte		N03   , As1 , v112
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 91
	.byte		PAN   , c_v+63
	.byte		N09   
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_5_000
	.byte		N03   , Bn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N07   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   
	.byte	W36
	.byte		VOICE , 91
	.byte	W24
	.byte		N04   , En2 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_factory_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle_factory_6:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N01   , En2 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		VOICE , 83
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N01   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
bgm_battle_factory_6_B1:
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N04   , Gn2 , v112
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		VOL   , 62*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v-2
	.byte		N18   , En1 , v127
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		        c_v+9
	.byte	W02
	.byte		        c_v+12
	.byte	W01
	.byte		        c_v+18
	.byte	W01
	.byte		        c_v+23
	.byte	W01
	.byte		        c_v+26
	.byte	W01
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+34
	.byte	W01
	.byte		        c_v+39
	.byte	W01
	.byte		        c_v+44
	.byte	W01
	.byte		        c_v+53
	.byte	W01
	.byte		        c_v+60
	.byte	W01
	.byte		        c_v+63
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N01   , Cs4 , v064
	.byte	W01
	.byte		        Dn4 
	.byte	W01
	.byte		        En4 , v076
	.byte	W01
	.byte		        Fn4 
	.byte	W01
	.byte		        Fs4 , v084
	.byte	W02
	.byte		VOICE , 81
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N28   , Gn4 , v112
	.byte	W28
	.byte		N01   , Gs4 , v048
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte		        As4 
	.byte	W01
	.byte		        Bn4 
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Cs5 
	.byte	W02
	.byte		N14   , Dn5 , v112
	.byte	W14
	.byte		N01   , Cs5 , v048
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Bn4 
	.byte	W02
	.byte		        As4 
	.byte	W01
	.byte		        An4 
	.byte	W01
	.byte		        Gs4 
	.byte	W01
	.byte		        Gn4 
	.byte	W01
	.byte		        Fs4 
	.byte	W02
	.byte		N21   , Fn4 , v112
	.byte	W21
	.byte		N01   , En4 , v048
	.byte	W01
	.byte		        Ds4 
	.byte	W02
	.byte		N48   , Dn4 , v112
	.byte	W12
	.byte	W48
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 82
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v+63
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N03   , En4 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		N03   , En4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v-64
	.byte		N03   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 83
	.byte		VOL   , 62*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N32   , Bn4 
	.byte	W32
	.byte		N01   , As4 , v064
	.byte	W01
	.byte		        An4 
	.byte	W01
	.byte		        Gs4 
	.byte	W02
	.byte		N30   , Gn4 
	.byte	W30
	.byte	W01
	.byte		N01   , Fs4 
	.byte	W01
	.byte		        Fn4 
	.byte	W01
	.byte		        En4 
	.byte	W01
	.byte		        Ds4 
	.byte	W02
	.byte		N20   , Dn4 
	.byte	W20
	.byte		N01   , Ds4 
	.byte	W01
	.byte		        En4 
	.byte	W01
	.byte		        Fn4 
	.byte	W02
	.byte		N24   , Fs4 , v112
	.byte	W24
	.byte	W03
	.byte		N01   , Gn4 , v064
	.byte	W01
	.byte		        Gs4 
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte		        As4 
	.byte	W01
	.byte		        Bn4 
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Cs5 
	.byte	W02
	.byte		N32   , Dn5 , v112
	.byte	W32
	.byte	W01
	.byte		N01   , Cs5 , v064
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		N18   , Bn4 , v112
	.byte	W18
	.byte		N01   , Cn5 , v064
	.byte	W01
	.byte		        Cs5 
	.byte	W01
	.byte		        Dn5 
	.byte	W01
	.byte		        Ds5 
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		N48   , Fn5 , v112
	.byte	W48
	.byte		VOICE , 81
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 49*bgm_battle_factory_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W60
	.byte		VOL   , 62*bgm_battle_factory_mvl/mxv
	.byte		N03   , En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		N03   , En4 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v-64
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*bgm_battle_factory_mvl/mxv
	.byte		N36   , Bn2 
	.byte	W24
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , En3 
	.byte	W24
	.byte		MOD   , 32
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N36   , Ds4 
	.byte	W24
	.byte		MOD   , 32
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N36   , Bn3 
	.byte	W24
	.byte		MOD   , 32
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 49*bgm_battle_factory_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N48   , Fn4 
	.byte	W36
	.byte		MOD   , 32
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		VOL   , 49*bgm_battle_factory_mvl/mxv
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 82
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		VOICE , 84
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W54
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N01   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v-64
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v+63
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N03   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v-64
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v+63
	.byte		N03   , En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v-64
	.byte		N03   , En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N32   , Bn2 
	.byte	W12
	.byte		MOD   , 32
	.byte	W20
	.byte		        0
	.byte		N01   , As2 , v064
	.byte	W01
	.byte		        An2 
	.byte	W01
	.byte		        Gs2 
	.byte	W02
	.byte		N30   , Gn2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W19
	.byte		        0
	.byte		N01   , Fs2 , v064
	.byte	W01
	.byte		        Fn2 
	.byte	W01
	.byte		        En2 
	.byte	W01
	.byte		        Ds2 
	.byte	W02
	.byte		N20   , Dn2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W08
	.byte		        0
	.byte		N01   , Ds2 , v064
	.byte	W01
	.byte		        En2 
	.byte	W01
	.byte		        Fn2 
	.byte	W02
	.byte		N28   , Fs2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W16
	.byte		        0
	.byte		N01   , Gn2 , v064
	.byte	W02
	.byte		        Gs2 
	.byte	W01
	.byte		        An2 
	.byte	W01
	.byte		        As2 
	.byte	W01
	.byte		        Bn2 
	.byte	W01
	.byte		        Cn3 
	.byte	W02
	.byte		N28   , Cs3 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W16
	.byte		        0
	.byte		N01   , Cn3 , v064
	.byte	W02
	.byte		        Bn2 
	.byte	W01
	.byte		        As2 
	.byte	W01
	.byte		        An2 
	.byte	W01
	.byte		        Gs2 
	.byte	W01
	.byte		        Gn2 , v068
	.byte	W02
	.byte		N21   , Fs2 , v112
	.byte	W12
	.byte		MOD   , 0
	.byte	W09
	.byte		N01   , Fn2 , v064
	.byte	W01
	.byte		        En2 
	.byte	W02
	.byte		N48   , Ds2 , v112
	.byte	W12
	.byte		MOD   , 32
	.byte	W36
	.byte		VOL   , 49*bgm_battle_factory_mvl/mxv
	.byte		MOD   , 0
	.byte	W48
	.byte		VOICE , 81
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		N03   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 82
	.byte		N09   
	.byte	W12
	.byte		N03   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 83
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		VOICE , 82
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 84
	.byte		PAN   , c_v-64
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		N03   , Bn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v-64
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		N03   , Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , Fs4 
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , Bn4 
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , Ds4 
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 12*bgm_battle_factory_mvl/mxv
	.byte		N96   , An4 
	.byte	W01
	.byte		VOL   , 14*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        17*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        24*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        29*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        35*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		        49*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        44*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		        37*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 32
	.byte	W12
	.byte		VOL   , 31*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		MOD   , 64
	.byte	W03
	.byte		VOL   , 29*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        25*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        19*bgm_battle_factory_mvl/mxv
	.byte	W01
	.byte		MOD   , 127
	.byte	W03
	.byte		VOL   , 15*bgm_battle_factory_mvl/mxv
	.byte	W02
	.byte		        11*bgm_battle_factory_mvl/mxv
	.byte	W04
	.byte		        6*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        1*bgm_battle_factory_mvl/mxv
	.byte	W03
	.byte		        50*bgm_battle_factory_mvl/mxv
	.byte		MOD   , 0
	.byte		N01   , En3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		N06   , En1 , v080
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		N05   , Dn3 , v112
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N05   , An2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte	W04
	.byte		N05   , An3 
	.byte	W08
	.byte		        Bn2 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		VOICE , 83
	.byte		N05   , En3 
	.byte	W16
	.byte		        Bn3 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N05   , Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N05   , Bn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		        Bn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W16
	.byte		        Bn3 
	.byte	W08
	.byte		VOICE , 82
	.byte		N05   , Fn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N05   , Cn3 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte	W04
	.byte		N05   , Cn4 
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		        En3 
	.byte	W16
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N05   , Dn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N05   , Dn4 
	.byte	W08
	.byte		        En3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		PAN   , c_v-62
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		N04   , Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N04   , Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N04   , Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N04   , Bn1 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		PAN   , c_v-61
	.byte		N04   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	W96
	.byte		VOICE , 81
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v-62
	.byte		N09   
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		VOICE , 82
	.byte		PAN   , c_v-62
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOICE , 81
	.byte		VOL   , 37*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		N09   
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v-62
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 62*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N01   , Dn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte		N01   , Dn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W30
	.byte		VOICE , 82
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N04   , En2 
	.byte	W06
	.byte		        En3 
	.byte	W10
	.byte		PAN   , c_v-62
	.byte	W02
	.byte		N04   , En2 
	.byte	W06
	.byte		        En3 
	.byte	W10
	.byte		PAN   , c_v+63
	.byte	W02
	.byte		N04   , En2 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N04   , En2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W05
	.byte		N04   , En2 
	.byte	W06
	.byte	GOTO
	 .word	bgm_battle_factory_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_battle_factory_7:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*bgm_battle_factory_mvl/mxv
	.byte		N03   , Fs2 , v068
	.byte	W12
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Fs2 , v068
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Fs2 , v068
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W12
	.byte		        Fs2 , v040
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v040
	.byte	W06
	.byte		        Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v028
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v024
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , Fs2 , v068
	.byte	W06
bgm_battle_factory_7_B1:
	.byte		N06   , Cn1 , v112
	.byte		N06   , Ds1 , v056
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N06   , Ds1 , v056
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Ds1 , v056
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Ds1 , v056
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Ds1 , v056
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N01   , Gs1 , v056
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		N01   , Gs1 , v060
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		N01   , Gs1 , v064
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		N01   , Gs1 , v064
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		N06   , Cn1 , v112
	.byte		N06   , Ds1 , v056
	.byte		N01   , Gs1 , v068
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		N01   , Gs1 , v072
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		N01   , Gs1 , v076
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		N01   , Gs1 , v088
	.byte		N03   , Fs2 , v020
	.byte	W03
bgm_battle_factory_7_000:
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Ds1 , v060
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Ds1 , v060
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Ds1 , v060
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte		N06   , Gs4 , v028
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N06   , Gs4 , v016
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N12   , An4 , v024
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte		N06   , Gs4 , v028
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N06   , Gs4 , v016
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N12   , An4 , v024
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte		N06   , Gs4 , v028
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N06   , Gs4 , v016
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N12   , An4 , v024
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte		N06   , Gs4 , v028
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N06   , Gs4 , v016
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte		N12   , An4 , v024
	.byte	W03
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N06   , Ds1 , v072
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N06   , Ds1 , v072
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N06   , Ds1 , v072
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N06   , Ds1 , v072
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , Ds1 , v072
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
bgm_battle_factory_7_001:
	.byte		N12   , Cn1 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_7_001
	.byte	W72
	.byte		N03   , En1 , v100
	.byte	W03
	.byte		        En1 , v044
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v040
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N04   , En1 
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W01
	.byte		N04   , En1 , v080
	.byte	W02
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N04   , En1 
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W02
	.byte		N04   , En1 , v080
	.byte	W01
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W01
	.byte		N04   , En1 , v112
	.byte	W02
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N04   , En1 
	.byte		N03   , Fs2 , v068
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W01
	.byte		N04   , En1 , v080
	.byte	W02
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N12   , Cn1 , v112
	.byte		N03   , En1 , v100
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        En1 , v044
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        En1 , v044
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        En1 , v044
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        En1 , v044
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        En1 , v044
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte		        En1 , v040
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        En1 
	.byte		N03   , Fs2 , v020
	.byte	W03
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W15
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W15
	.byte		N06   , Cn1 , v112
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		        Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W15
	.byte		N12   , Cn1 , v112
	.byte		N06   , En1 
	.byte		N03   , Fs2 , v056
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N03   , Fs2 , v040
	.byte	W03
	.byte		        Fs2 , v020
	.byte	W03
	.byte	PATT
	 .word	bgm_battle_factory_7_000
	.byte	GOTO
	 .word	bgm_battle_factory_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_battle_factory_8:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 47*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		        c_v-64
	.byte	W24
	.byte		        c_v+63
	.byte	W24
	.byte		        c_v-64
	.byte	W24
	.byte		        c_v+63
	.byte	W24
	.byte		        c_v-64
	.byte	W24
bgm_battle_factory_8_B1:
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		        c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
bgm_battle_factory_8_000:
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte	PEND
bgm_battle_factory_8_001:
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W03
	.byte		N01   
	.byte	W15
	.byte	PEND
bgm_battle_factory_8_002:
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W03
	.byte		        En3 , v032
	.byte	W03
	.byte		N01   
	.byte	W18
	.byte	PEND
bgm_battle_factory_8_003:
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W03
	.byte		        En3 , v032
	.byte	W03
	.byte		        En3 , v048
	.byte	W03
	.byte		        En3 , v032
	.byte	W15
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_8_000
	.byte	PATT
	 .word	bgm_battle_factory_8_001
	.byte	PATT
	 .word	bgm_battle_factory_8_002
	.byte	PATT
	 .word	bgm_battle_factory_8_003
	.byte	PATT
	 .word	bgm_battle_factory_8_000
	.byte	PATT
	 .word	bgm_battle_factory_8_001
	.byte	PATT
	 .word	bgm_battle_factory_8_002
	.byte	PATT
	 .word	bgm_battle_factory_8_003
	.byte	PATT
	 .word	bgm_battle_factory_8_000
	.byte	PATT
	 .word	bgm_battle_factory_8_001
	.byte	PATT
	 .word	bgm_battle_factory_8_002
	.byte	PATT
	 .word	bgm_battle_factory_8_003
	.byte	PATT
	 .word	bgm_battle_factory_8_000
	.byte	PATT
	 .word	bgm_battle_factory_8_001
	.byte	PATT
	 .word	bgm_battle_factory_8_002
	.byte	PATT
	 .word	bgm_battle_factory_8_003
	.byte	PATT
	 .word	bgm_battle_factory_8_000
	.byte	PATT
	 .word	bgm_battle_factory_8_001
	.byte		PAN   , c_v-64
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , En3 , v064
	.byte	W06
	.byte		        En3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N01   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		        Fn3 , v048
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W15
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
bgm_battle_factory_8_004:
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte	PEND
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
bgm_battle_factory_8_005:
	.byte		N01   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W18
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W18
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W18
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_8_005
	.byte	W96
	.byte	W96
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		        Fn3 , v096
	.byte	W03
	.byte		        Fn3 , v036
	.byte	W03
	.byte		        Fn3 , v080
	.byte	W03
	.byte		        Fn3 , v056
	.byte	W15
	.byte	PATT
	 .word	bgm_battle_factory_8_004
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N01   
	.byte	W15
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N01   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N01   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N01   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N01   , Fn3 , v064
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N01   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N01   , Fn3 , v064
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W18
	.byte	PATT
	 .word	bgm_battle_factory_8_004
	.byte	GOTO
	 .word	bgm_battle_factory_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_battle_factory_9:
	.byte	KEYSH , bgm_battle_factory_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-64
	.byte	W24
	.byte		        c_v+63
	.byte	W24
	.byte		        c_v-64
	.byte	W24
	.byte		        c_v+63
	.byte	W24
	.byte		        c_v-64
	.byte	W24
	.byte		        c_v+63
	.byte	W24
bgm_battle_factory_9_B1:
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle_factory_9_000:
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte		PAN   , c_v+63
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle_factory_9_001:
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte	PEND
bgm_battle_factory_9_002:
	.byte		PAN   , c_v+63
	.byte		VOL   , 50*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		N12   , Cn5 , v064
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte		PAN   , c_v+63
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 66*bgm_battle_factory_mvl/mxv
	.byte	W12
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_factory_9_001
	.byte	PATT
	 .word	bgm_battle_factory_9_002
	.byte	PATT
	 .word	bgm_battle_factory_9_000
bgm_battle_factory_9_003:
	.byte	W12
	.byte		N12   , Gn5 , v064
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle_factory_9_003
	.byte	PATT
	 .word	bgm_battle_factory_9_003
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N12   , Gn5 , v064
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Gn5 , v096
	.byte	W12
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	PATT
	 .word	bgm_battle_factory_9_000
	.byte	GOTO
	 .word	bgm_battle_factory_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle_factory:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle_factory_pri	@ Priority
	.byte	bgm_battle_factory_rev	@ Reverb.

	.word	bgm_battle_factory_grp

	.word	bgm_battle_factory_1
	.word	bgm_battle_factory_2
	.word	bgm_battle_factory_3
	.word	bgm_battle_factory_4
	.word	bgm_battle_factory_5
	.word	bgm_battle_factory_6
	.word	bgm_battle_factory_7
	.word	bgm_battle_factory_8
	.word	bgm_battle_factory_9

	.end
