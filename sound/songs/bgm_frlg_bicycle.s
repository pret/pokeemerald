	.include "MPlayDef.s"

	.equ	bgm_frlg_bicycle_grp, voicegroup_86A4204
	.equ	bgm_frlg_bicycle_pri, 0
	.equ	bgm_frlg_bicycle_rev, reverb_set+50
	.equ	bgm_frlg_bicycle_mvl, 127
	.equ	bgm_frlg_bicycle_key, 0
	.equ	bgm_frlg_bicycle_tbs, 1
	.equ	bgm_frlg_bicycle_exg, 0
	.equ	bgm_frlg_bicycle_cmp, 1

	.section .rodata
	.global	bgm_frlg_bicycle
	.align	2

@********************** Track  1 **********************@

bgm_frlg_bicycle_1:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte	TEMPO , 134*bgm_frlg_bicycle_tbs/2
	.byte		VOICE , 21
	.byte		PAN   , c_v+24
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte		VOL   , 52*bgm_frlg_bicycle_mvl/mxv
	.byte		N12   , Cn3 , v127
	.byte	W12
bgm_frlg_bicycle_1_B1:
	.byte		VOL   , 52*bgm_frlg_bicycle_mvl/mxv
	.byte		N24   , Fn3 , v127
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N60   , As3 
	.byte	W09
	.byte		MOD   , 6
	.byte	W48
	.byte	W03
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N60   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N36   
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		MOD   , 6
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		VOL   , 52*bgm_frlg_bicycle_mvl/mxv
	.byte		N96   , Cn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 44*bgm_frlg_bicycle_mvl/mxv
	.byte	W15
	.byte		        38*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		        34*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        26*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        20*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        11*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        52*bgm_frlg_bicycle_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		VOL   , 44*bgm_frlg_bicycle_mvl/mxv
	.byte		N72   
	.byte	W15
	.byte		VOL   , 38*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		        34*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        26*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        20*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        11*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_bicycle_1_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_bicycle_2:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*bgm_frlg_bicycle_mvl/mxv
	.byte		LFOS  , 36
	.byte		BENDR , 12
	.byte		BEND  , c_v+0
	.byte		N12   , Fn4 , v100
	.byte	W12
bgm_frlg_bicycle_2_B1:
	.byte		VOICE , 1
	.byte		VOL   , 90*bgm_frlg_bicycle_mvl/mxv
	.byte		N24   , An4 , v076
	.byte	W09
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , As4 , v084
	.byte	W09
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Cn5 , v088
	.byte	W09
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fn5 , v064
	.byte	W09
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , En5 , v076
	.byte	W12
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Dn5 , v080
	.byte	W06
	.byte		        En5 , v084
	.byte	W06
	.byte		VOL   , 90*bgm_frlg_bicycle_mvl/mxv
	.byte		N60   , Dn5 , v092
	.byte	W12
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_bicycle_mvl/mxv
	.byte	W24
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , As4 , v100
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 , v072
	.byte	W12
	.byte		N06   , Dn5 , v084
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
	.byte		VOL   , 90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Fn5 , v072
	.byte	W12
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte		N12   , Dn5 , v100
	.byte	W12
	.byte		VOL   , 90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Cn5 
	.byte	W09
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N32   , Ds5 
	.byte	W09
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		        56*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte	W09
	.byte		VOICE , 73
	.byte		VOL   , 90*bgm_frlg_bicycle_mvl/mxv
	.byte		N03   , En5 , v064
	.byte	W03
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N60   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		VOL   , 85*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        74*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        61*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 56*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        51*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N56   , Cn5 
	.byte	W09
	.byte		MOD   , 6
	.byte	W06
	.byte		VOL   , 85*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        79*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        74*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        61*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		VOICE , 21
	.byte		MOD   , 0
	.byte		VOL   , 56*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        51*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        90*bgm_frlg_bicycle_mvl/mxv
	.byte		N24   , Fn4 , v112
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W48
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N96   , En4 
	.byte	W96
	.byte		VOICE , 1
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte		N36   , As4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 74*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N03   , As4 
	.byte	W03
	.byte		        Cn5 , v076
	.byte	W03
	.byte		N06   , As4 , v064
	.byte	W06
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		VOL   , 79*bgm_frlg_bicycle_mvl/mxv
	.byte		N36   , An4 , v108
	.byte	W12
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 74*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_bicycle_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , An4 , v100
	.byte	W12
	.byte		        As4 , v112
	.byte	W12
	.byte		        An4 , v100
	.byte	W12
	.byte		        Gn4 , v104
	.byte	W12
	.byte		        Fn4 , v100
	.byte	W12
	.byte		        As4 , v112
	.byte	W12
	.byte		        An4 , v100
	.byte	W12
	.byte		        Gn4 , v104
	.byte	W12
	.byte		        As4 , v096
	.byte	W12
	.byte		N24   , Cn5 , v104
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Dn5 , v100
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		N24   , Cn5 , v104
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , As4 , v100
	.byte	W12
	.byte		N36   , An4 , v104
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		VOICE , 17
	.byte		MOD   , 0
	.byte		VOL   , 85*bgm_frlg_bicycle_mvl/mxv
	.byte		N03   , As4 , v096
	.byte	W03
	.byte		        Cn5 , v100
	.byte	W03
	.byte		        Dn5 , v104
	.byte	W03
	.byte		        En5 , v112
	.byte	W03
	.byte		N12   , Fn5 , v127
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N03   , As4 , v120
	.byte	W03
	.byte		        Cn5 , v084
	.byte	W03
	.byte		N12   , As4 , v080
	.byte	W12
	.byte		        An4 , v127
	.byte	W12
	.byte		N16   , Dn5 
	.byte	W16
	.byte		        Cn5 
	.byte	W16
	.byte		        As4 
	.byte	W16
	.byte		        En5 
	.byte	W16
	.byte		        Dn5 
	.byte	W16
	.byte		        Cn5 
	.byte	W16
	.byte		        Fn5 
	.byte	W16
	.byte		        En5 
	.byte	W16
	.byte		        Dn5 
	.byte	W16
	.byte		        Gn5 
	.byte	W16
	.byte		        An5 
	.byte	W16
	.byte		        Fn5 
	.byte	W16
	.byte		N72   , Gn5 
	.byte	W09
	.byte		MOD   , 7
	.byte	W60
	.byte	W03
	.byte		        0
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N96   , En5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		        6
	.byte	W60
	.byte	GOTO
	 .word	bgm_frlg_bicycle_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_bicycle_3:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte		VOL   , 49*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
bgm_frlg_bicycle_3_B1:
	.byte		N12   , Fn1 , v127
	.byte	W12
	.byte		N06   , An1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		N03   , Cn2 , v068
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		        An1 , v120
	.byte	W06
	.byte		N12   , Gn1 , v127
	.byte	W12
	.byte		N03   , En1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N14   , Dn1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cn2 , v127
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		N06   , As1 , v127
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 , v120
	.byte	W06
	.byte		N12   , Cn1 , v127
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 , v120
	.byte	W06
	.byte		N12   , Fn1 , v127
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        An1 , v120
	.byte	W06
	.byte		        As1 , v127
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		N03   , As1 , v120
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		N06   , Fn1 , v127
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		        Bn1 , v120
	.byte	W06
	.byte		        Cn2 , v127
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
	.byte		N03   , Dn2 , v120
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , Dn2 , v127
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N12   , Cn2 , v120
	.byte	W12
	.byte		N06   , En2 , v127
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   , Dn2 , v120
	.byte	W12
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As2 , v120
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        As1 , v127
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_bicycle_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_bicycle_4:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte		PAN   , c_v+28
	.byte		VOL   , 47*bgm_frlg_bicycle_mvl/mxv
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte	W12
bgm_frlg_bicycle_4_B1:
	.byte		VOL   , 47*bgm_frlg_bicycle_mvl/mxv
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
	.byte		VOICE , 56
	.byte		PAN   , c_v-32
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte		N08   , Fn3 , v120
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 56*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 56*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte		PAN   , c_v-33
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 56*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Fn4 , v084
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		MOD   , 6
	.byte		N03   , Dn4 , v072
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		N04   , Gn3 , v120
	.byte	W08
	.byte		N08   , En3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N72   , Cn4 
	.byte	W09
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 56*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        50*bgm_frlg_bicycle_mvl/mxv
	.byte	W15
	.byte		        45*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		        39*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_frlg_bicycle_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N96   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 56*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        51*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        39*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_bicycle_mvl/mxv
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_bicycle_4_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_bicycle_5:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_frlg_bicycle_mvl/mxv
	.byte		N12   , Fn4 , v100
	.byte	W12
bgm_frlg_bicycle_5_B1:
	.byte		VOICE , 83
	.byte		VOL   , 45*bgm_frlg_bicycle_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , An4 , v100
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , As4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Cn5 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Fn5 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N36   , En5 , v076
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N06   , Dn5 , v104
	.byte	W06
	.byte		        En5 , v088
	.byte	W06
	.byte		N60   , Dn5 , v104
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W12
	.byte		        Fn5 , v076
	.byte	W12
	.byte		        En5 , v080
	.byte	W12
	.byte		N06   , Dn5 , v100
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
	.byte		MOD   , 0
	.byte		N36   , Fn5 , v100
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Cn5 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N32   , Ds5 
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte	W09
	.byte		N03   , En5 , v064
	.byte	W03
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N60   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte	W12
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N56   , Cn5 , v056
	.byte	W09
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte	W12
	.byte		N24   , Fn5 , v127
	.byte	W24
	.byte		N12   , An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        As4 , v120
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N48   , Gn5 
	.byte	W48
	.byte		N06   , Gn5 , v127
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N96   , En5 
	.byte	W96
	.byte		N36   , As4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N03   , As4 
	.byte	W03
	.byte		        Cn5 , v084
	.byte	W03
	.byte		N06   , As4 , v076
	.byte	W06
	.byte		N12   , An4 , v127
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , As4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N03   , As4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N03   , As4 , v120
	.byte	W03
	.byte		        Cn5 , v084
	.byte	W03
	.byte		N12   , As4 , v080
	.byte	W12
	.byte		        An4 , v127
	.byte	W12
	.byte		VOICE , 85
	.byte		VOL   , 45*bgm_frlg_bicycle_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N08   , As2 , v120
	.byte	W08
	.byte		N04   , Fn2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W36
	.byte		        6
	.byte	W12
	.byte		        0
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		        6
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		N72   , Gn3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 38*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_bicycle_mvl/mxv
	.byte	W15
	.byte		        22*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 17*bgm_frlg_bicycle_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W12
	.byte		VOL   , 11*bgm_frlg_bicycle_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOL   , 45*bgm_frlg_bicycle_mvl/mxv
	.byte		N96   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 38*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        34*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        28*bgm_frlg_bicycle_mvl/mxv
	.byte	W15
	.byte		        22*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		        17*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        11*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_bicycle_5_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_bicycle_6:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte		VOICE , 80
	.byte		PAN   , c_v+63
	.byte		VOL   , 28*bgm_frlg_bicycle_mvl/mxv
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte	W12
bgm_frlg_bicycle_6_B1:
	.byte		VOL   , 45*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		N04   , An2 , v120
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N12   
	.byte	W24
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Gn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	W12
	.byte		N04   , As2 
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N10   
	.byte	W24
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N08   
	.byte	W24
	.byte		N04   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N04   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	W12
	.byte		N04   , An2 
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N10   
	.byte	W24
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Cn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		VOICE , 84
	.byte		VOL   , 45*bgm_frlg_bicycle_mvl/mxv
	.byte		N03   , An1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		N60   , Dn2 
	.byte	W60
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N06   , En2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N60   , Cn2 
	.byte	W60
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N36   , Fn2 
	.byte	W36
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		VOL   , 45*bgm_frlg_bicycle_mvl/mxv
	.byte		N07   , Cn3 
	.byte	W12
	.byte		N10   , Gn2 , v064
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N01   , Cn3 , v120
	.byte	W03
	.byte		N09   
	.byte	W09
	.byte		N06   , Dn3 , v064
	.byte	W12
	.byte		N10   , Gn2 
	.byte	W12
	.byte		N12   , As2 , v120
	.byte	W12
	.byte		N10   , Cn3 , v088
	.byte	W12
	.byte		N09   , Cn3 , v120
	.byte	W12
	.byte		N10   , Cn3 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , Cn3 , v127
	.byte	W03
	.byte		N06   
	.byte	W09
	.byte		N10   , Cn3 , v060
	.byte	W12
	.byte		        Cn3 , v088
	.byte	W12
	.byte		N09   , Cn3 , v120
	.byte	W12
	.byte		N10   , Cn3 , v088
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn2 , v120
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N36   , Cn3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	W48
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N04   , Gn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N24   , En3 
	.byte	W24
	.byte	W48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , As3 , v088
	.byte	W03
	.byte		        An3 , v084
	.byte	W03
	.byte		        Gn3 , v080
	.byte	W12
	.byte		N04   , Cn3 , v120
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte	W72
	.byte		N06   , As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N96   , Cn4 
	.byte	W24
	.byte		VOL   , 34*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        29*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        22*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		        15*bgm_frlg_bicycle_mvl/mxv
	.byte	W15
	.byte		        11*bgm_frlg_bicycle_mvl/mxv
	.byte	W09
	.byte		        6*bgm_frlg_bicycle_mvl/mxv
	.byte	W15
	.byte	GOTO
	 .word	bgm_frlg_bicycle_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_bicycle_7:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte		PAN   , c_v-64
	.byte		VOL   , 28*bgm_frlg_bicycle_mvl/mxv
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte	W12
bgm_frlg_bicycle_7_B1:
	.byte		VOICE , 13
	.byte		VOL   , 28*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		N04   , Fn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N12   
	.byte	W24
	.byte		N04   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	W12
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N10   , Dn3 
	.byte	W24
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Gn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N02   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	W12
	.byte		N02   , En3 
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N08   
	.byte	W24
	.byte		N04   , As3 
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N04   , En3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	W12
	.byte		N04   , Fn3 
	.byte	W06
	.byte		N01   
	.byte	W18
	.byte		N10   
	.byte	W24
	.byte		N04   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N04   , Ds3 
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		VOICE , 48
	.byte	W03
	.byte		N03   , En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		VOL   , 26*bgm_frlg_bicycle_mvl/mxv
	.byte		N60   , As2 
	.byte	W60
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N60   , An2 
	.byte	W60
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N06   , As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 41*bgm_frlg_bicycle_mvl/mxv
	.byte		N09   , Fn3 
	.byte	W12
	.byte		N06   , Fn3 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , Fn3 , v120
	.byte	W03
	.byte		N09   
	.byte	W09
	.byte		N06   , Fn3 , v064
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N06   , Fs3 , v120
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		N09   , En3 , v120
	.byte	W12
	.byte		N06   , En3 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , En3 , v120
	.byte	W03
	.byte		N06   
	.byte	W09
	.byte		        En3 , v060
	.byte	W09
	.byte		VOL   , 33*bgm_frlg_bicycle_mvl/mxv
	.byte	W03
	.byte		N03   , En3 , v096
	.byte	W03
	.byte		VOICE , 17
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N60   , Dn5 , v120
	.byte	W12
	.byte		MOD   , 4
	.byte	W48
	.byte		        0
	.byte		N03   , Ds5 , v080
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		N12   , As5 , v120
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N24   , An5 , v108
	.byte	W24
	.byte		N03   , Gs5 , v120
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		N32   , Dn5 , v088
	.byte	W32
	.byte	W01
	.byte		N03   , Ds5 , v120
	.byte	W03
	.byte		N36   , En5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N24   , Fn5 
	.byte	W24
	.byte		N12   , An5 
	.byte	W12
	.byte		N03   , Gn5 , v112
	.byte	W03
	.byte		        An5 , v088
	.byte	W03
	.byte		N06   , Gn5 , v072
	.byte	W06
	.byte		N12   , Fn5 , v120
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		VOICE , 80
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N24   , As3 
	.byte	W72
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N24   , As3 
	.byte	W24
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Dn3 , v064
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        As2 
	.byte	W12
	.byte		N04   , Gn3 , v120
	.byte	W08
	.byte		N08   , En3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte	W72
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N96   , En5 
	.byte	W48
	.byte		VOL   , 22*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        17*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		        11*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
	.byte		        6*bgm_frlg_bicycle_mvl/mxv
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_bicycle_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_frlg_bicycle_8:
	.byte	KEYSH , bgm_frlg_bicycle_key+0
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*bgm_frlg_bicycle_mvl/mxv
	.byte	W12
bgm_frlg_bicycle_8_B1:
	.byte		VOICE , 0
	.byte	W12
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		VOL   , 41*bgm_frlg_bicycle_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
bgm_frlg_bicycle_8_000:
	.byte	W12
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_frlg_bicycle_8_001:
	.byte	W12
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_frlg_bicycle_8_002:
	.byte	W12
	.byte		N12   , Gs4 , v052
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_000
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_000
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_000
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_002
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_000
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	PATT
	 .word	bgm_frlg_bicycle_8_001
	.byte	GOTO
	 .word	bgm_frlg_bicycle_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_bicycle:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_bicycle_pri	@ Priority
	.byte	bgm_frlg_bicycle_rev	@ Reverb.

	.word	bgm_frlg_bicycle_grp

	.word	bgm_frlg_bicycle_1
	.word	bgm_frlg_bicycle_2
	.word	bgm_frlg_bicycle_3
	.word	bgm_frlg_bicycle_4
	.word	bgm_frlg_bicycle_5
	.word	bgm_frlg_bicycle_6
	.word	bgm_frlg_bicycle_7
	.word	bgm_frlg_bicycle_8

	.end
