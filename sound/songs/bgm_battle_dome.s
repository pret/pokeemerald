	.include "MPlayDef.s"

	.equ	bgm_battle_dome_grp, voicegroup_8698054
	.equ	bgm_battle_dome_pri, 0
	.equ	bgm_battle_dome_rev, reverb_set+50
	.equ	bgm_battle_dome_mvl, 127
	.equ	bgm_battle_dome_key, 0
	.equ	bgm_battle_dome_tbs, 1
	.equ	bgm_battle_dome_exg, 0
	.equ	bgm_battle_dome_cmp, 1

	.section .rodata
	.global	bgm_battle_dome
	.align	2

@********************** Track  1 **********************@

bgm_battle_dome_1:
	.byte	KEYSH , bgm_battle_dome_key+0
	.byte	TEMPO , 144*bgm_battle_dome_tbs/2
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_battle_dome_mvl/mxv
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
bgm_battle_dome_1_000:
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
bgm_battle_dome_1_B1:
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
bgm_battle_dome_1_001:
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
	 .word	bgm_battle_dome_1_000
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
	 .word	bgm_battle_dome_1_001
	.byte	PATT
	 .word	bgm_battle_dome_1_000
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
	.byte	GOTO
	 .word	bgm_battle_dome_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle_dome_2:
	.byte	KEYSH , bgm_battle_dome_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 38*bgm_battle_dome_mvl/mxv
	.byte		PAN   , c_v+63
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
bgm_battle_dome_2_000:
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
bgm_battle_dome_2_001:
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
	 .word	bgm_battle_dome_2_001
bgm_battle_dome_2_B1:
bgm_battle_dome_2_002:
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
	 .word	bgm_battle_dome_2_000
	.byte	PATT
	 .word	bgm_battle_dome_2_001
	.byte	PATT
	 .word	bgm_battle_dome_2_001
	.byte	PATT
	 .word	bgm_battle_dome_2_002
	.byte	PATT
	 .word	bgm_battle_dome_2_000
	.byte	PATT
	 .word	bgm_battle_dome_2_001
	.byte	PATT
	 .word	bgm_battle_dome_2_001
	.byte	GOTO
	 .word	bgm_battle_dome_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle_dome_3:
	.byte	KEYSH , bgm_battle_dome_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 56*bgm_battle_dome_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v064
	.byte	W12
	.byte	W96
	.byte	W96
bgm_battle_dome_3_B1:
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
	.byte	GOTO
	 .word	bgm_battle_dome_3_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle_dome:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle_dome_pri	@ Priority
	.byte	bgm_battle_dome_rev	@ Reverb.

	.word	bgm_battle_dome_grp

	.word	bgm_battle_dome_1
	.word	bgm_battle_dome_2
	.word	bgm_battle_dome_3

	.end
