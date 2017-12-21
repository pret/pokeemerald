	.include "MPlayDef.s"

	.equ	bgm_frlg_gamecorner_grp, voicegroup_86A15B8
	.equ	bgm_frlg_gamecorner_pri, 0
	.equ	bgm_frlg_gamecorner_rev, reverb_set+50
	.equ	bgm_frlg_gamecorner_mvl, 127
	.equ	bgm_frlg_gamecorner_key, 0
	.equ	bgm_frlg_gamecorner_tbs, 1
	.equ	bgm_frlg_gamecorner_exg, 0
	.equ	bgm_frlg_gamecorner_cmp, 1

	.section .rodata
	.global	bgm_frlg_gamecorner
	.align	2

@********************** Track  1 **********************@

bgm_frlg_gamecorner_1:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte	TEMPO , 146*bgm_frlg_gamecorner_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
bgm_frlg_gamecorner_1_B1:
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N36   , As3 , v080
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        50*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W96
	.byte		N24   , Dn3 , v072
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , As3 
	.byte	W12
	.byte		N48   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        49*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
bgm_frlg_gamecorner_1_000:
	.byte		MOD   , 0
	.byte		N36   , An3 , v072
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
	.byte		MOD   , 0
	.byte		N48   , Gn3 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        51*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N48   , En3 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        51*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N48   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        51*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N36   , En4 
	.byte	W15
	.byte		MOD   , 7
	.byte	W21
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N48   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        50*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W12
	.byte		N48   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        48*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_gamecorner_1_000
	.byte		MOD   , 0
	.byte		N48   , Gn3 , v072
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        48*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   , En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N24   , En3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N48   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        50*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N60   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        49*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        44*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 38*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        50*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   , En4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N18   , Fn3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N60   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        49*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        63*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N60   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        49*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        63*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        49*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   , En4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N48   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        49*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_1_B1
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_frlg_gamecorner_mvl/mxv
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_gamecorner_2:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N06   , Fn3 , v120
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
bgm_frlg_gamecorner_2_B1:
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N36   , Dn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W60
	.byte		N06   , Cn3 , v120
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Fn3 , v127
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
bgm_frlg_gamecorner_2_000:
	.byte		MOD   , 0
	.byte		N12   , Dn4 , v127
	.byte	W12
	.byte		N84   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        72*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        62*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N36   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
bgm_frlg_gamecorner_2_001:
	.byte		MOD   , 0
	.byte		N96   , As3 , v127
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        72*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        62*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
bgm_frlg_gamecorner_2_002:
	.byte		MOD   , 0
	.byte		N12   , En4 , v127
	.byte	W12
	.byte		N84   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        72*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        62*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		        90*bgm_frlg_gamecorner_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W09
	.byte		VOL   , 68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N96   , Cn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 85*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        72*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        62*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        90*bgm_frlg_gamecorner_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_gamecorner_2_000
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Fn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_gamecorner_2_001
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gn3 , v127
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte	PATT
	 .word	bgm_frlg_gamecorner_2_002
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Gn4 , v127
	.byte	W12
	.byte		VOL   , 79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W09
	.byte		VOL   , 68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        90*bgm_frlg_gamecorner_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N60   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        73*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_gamecorner_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
bgm_frlg_gamecorner_2_003:
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N60   , Fn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        73*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		N18   , An4 , v120
	.byte	W18
	.byte		N06   , As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N03   , As4 , v092
	.byte	W03
	.byte		        An4 , v080
	.byte	W03
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N60   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        73*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 68*bgm_frlg_gamecorner_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_gamecorner_2_003
	.byte		N24   , Gn4 , v127
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N96   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 83*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        79*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        72*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        68*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        61*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte		        56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_2_B1
	.byte		MOD   , 0
	.byte		VOL   , 90*bgm_frlg_gamecorner_mvl/mxv
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_gamecorner_3:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 44*bgm_frlg_gamecorner_mvl/mxv
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
bgm_frlg_gamecorner_3_B1:
	.byte		N36   , Dn3 , v127
	.byte	W36
	.byte		N12   , Cn3 , v120
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        An2 , v127
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W48
	.byte		VOICE , 80
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		VOL   , 28*bgm_frlg_gamecorner_mvl/mxv
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An2 
	.byte	W12
bgm_frlg_gamecorner_3_000:
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , En2 
	.byte	W12
	.byte	PEND
bgm_frlg_gamecorner_3_001:
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cn3 
	.byte	W12
	.byte	PEND
bgm_frlg_gamecorner_3_002:
	.byte		PAN   , c_v-64
	.byte		N06   , En2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte	PEND
bgm_frlg_gamecorner_3_003:
	.byte		PAN   , c_v-64
	.byte		N06   , En2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-64
	.byte		N06   , En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        Dn2 , v120
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , En2 
	.byte	W12
bgm_frlg_gamecorner_3_004:
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v-64
	.byte		N06   , En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , As2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , As2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
bgm_frlg_gamecorner_3_005:
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_000
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_001
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_002
	.byte		PAN   , c_v-64
	.byte		N06   , En2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , En2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N06   , Cn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_003
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_005
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_004
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_003
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_005
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_004
	.byte	PATT
	 .word	bgm_frlg_gamecorner_3_000
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_gamecorner_4:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_frlg_gamecorner_mvl/mxv
	.byte	W24
bgm_frlg_gamecorner_4_B1:
	.byte		N36   , Dn2 , v120
	.byte	W36
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W60
	.byte		N06   , As1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
bgm_frlg_gamecorner_4_000:
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte	PEND
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , An1 , v120
	.byte	W12
	.byte		N06   , Bn2 , v096
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v100
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
bgm_frlg_gamecorner_4_001:
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Gn3 , v096
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte	PEND
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_gamecorner_4_000
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , An1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_gamecorner_4_001
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cs3 , v096
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		N06   , As3 , v088
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , As1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N06   , Gn3 , v096
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , An1 , v120
	.byte	W12
	.byte		N06   , An3 , v096
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , An1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , As3 , v096
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , An3 , v096
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Cn4 , v064
	.byte	W06
	.byte		        Cn4 , v028
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , As2 , v096
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		N06   , Gn3 , v096
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		N06   , As3 , v096
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		N12   , Ds1 , v120
	.byte	W12
	.byte		N06   , Gn3 , v096
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , An3 , v096
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Gn3 , v096
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		N06   , Fn3 , v096
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_gamecorner_5:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*bgm_frlg_gamecorner_mvl/mxv
	.byte	W24
bgm_frlg_gamecorner_5_B1:
	.byte		VOICE , 73
	.byte	W96
	.byte	W12
	.byte		N06   , Cn5 , v127
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Dn5 , v120
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cn5 , v096
	.byte	W03
	.byte		        Dn5 , v076
	.byte	W03
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Dn5 , v060
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 , v032
	.byte	W03
	.byte	W96
	.byte		VOL   , 31*bgm_frlg_gamecorner_mvl/mxv
	.byte		N06   , Cn5 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	W96
	.byte	W12
	.byte		N06   , Cn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cn6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		N03   , Cn6 
	.byte	W03
	.byte		        Cs6 , v060
	.byte	W03
	.byte		        Cn6 , v120
	.byte	W03
	.byte		        Cs6 , v064
	.byte	W03
	.byte		        Cn6 , v120
	.byte	W03
	.byte		        Cs6 , v060
	.byte	W03
	.byte		        Cn6 , v120
	.byte	W03
	.byte		        Cs6 , v060
	.byte	W03
	.byte		        Cn6 , v092
	.byte	W03
	.byte		        Cs6 , v040
	.byte	W03
	.byte		        Cn6 , v064
	.byte	W03
	.byte		        Cs6 , v028
	.byte	W03
	.byte		        Cn6 , v064
	.byte	W03
	.byte		        Cs6 , v028
	.byte	W03
	.byte		        Cn6 , v060
	.byte	W03
	.byte		        Cs6 , v032
	.byte	W03
	.byte	W96
	.byte		N06   , An5 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte	W96
	.byte		VOICE , 73
	.byte		N06   , Cn6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		N12   , Cn6 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte	W96
	.byte		VOICE , 14
	.byte		VOL   , 45*bgm_frlg_gamecorner_mvl/mxv
	.byte	W24
	.byte		N24   , En5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte	W96
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Gn5 
	.byte	W96
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Gn5 
	.byte	W48
	.byte		        Cn5 
	.byte	W48
	.byte		VOICE , 14
	.byte		N24   , Fn5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Fn5 
	.byte	W48
	.byte		VOICE , 73
	.byte		VOL   , 29*bgm_frlg_gamecorner_mvl/mxv
	.byte		N03   , Fs5 
	.byte	W03
	.byte		N09   , Fn5 
	.byte	W09
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N06   , An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N06   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Fn5 , v096
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Fn5 , v088
	.byte	W03
	.byte		        Gn5 , v064
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Gn5 , v048
	.byte	W03
	.byte		        Fn5 , v056
	.byte	W03
	.byte		        Gn5 , v032
	.byte	W03
	.byte		VOICE , 14
	.byte		VOL   , 45*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   , En5 , v120
	.byte	W48
	.byte		        Cn5 
	.byte	W48
	.byte		VOL   , 45*bgm_frlg_gamecorner_mvl/mxv
	.byte		N24   , Fn5 
	.byte	W48
	.byte		        Cn5 
	.byte	W48
	.byte		        Gn5 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        As5 
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		        Cn6 
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_gamecorner_6:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 49*bgm_frlg_gamecorner_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W24
bgm_frlg_gamecorner_6_B1:
	.byte		N12   , Dn2 , v120
	.byte	W24
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v080
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W96
	.byte		        Fn1 
	.byte	W96
	.byte		PAN   , c_v+32
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , An1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Gn1 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Fn1 
	.byte	W96
	.byte		PAN   , c_v+32
	.byte		N12   , Gn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cn2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Gn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cn2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Gn1 
	.byte	W96
	.byte	W96
	.byte		        Cn2 
	.byte	W96
	.byte		N24   
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Gn1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Gn1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Fn1 
	.byte	W72
	.byte		PAN   , c_v-32
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cn2 
	.byte	W96
	.byte		N24   
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		N24   , Fn1 
	.byte	W48
	.byte		PAN   , c_v+32
	.byte		N24   , As1 
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-32
	.byte		N24   
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+32
	.byte		N24   , Fn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Cn2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Fn2 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cn2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   , Fn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cn2 
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	W48
	.byte		        Fn1 
	.byte	W48
	.byte	W48
	.byte		PAN   , c_v+32
	.byte		N12   , Gn2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Cn2 
	.byte	W24
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_gamecorner_7:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte		VOICE , 0
	.byte		VOL   , 74*bgm_frlg_gamecorner_mvl/mxv
	.byte	W24
bgm_frlg_gamecorner_7_B1:
	.byte		N48   , Cs2 , v120
	.byte	W48
	.byte		        An2 
	.byte	W48
	.byte		        Gn2 
	.byte	W96
	.byte		        An2 
	.byte	W96
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte		N12   
	.byte	W96
	.byte		N48   , An2 
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	W96
	.byte		        Gn2 
	.byte	W96
	.byte		N24   , An2 
	.byte	W96
	.byte		        Gn2 
	.byte	W48
	.byte		        Cs2 
	.byte	W48
	.byte		        Bn2 
	.byte	W96
	.byte		N48   , Cs2 
	.byte	W96
	.byte		N24   , An2 
	.byte	W96
	.byte		N48   , Bn2 
	.byte	W48
	.byte		        Cs2 
	.byte	W48
	.byte	W72
	.byte		N24   , An2 
	.byte	W24
	.byte		N48   , Cs2 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        An2 
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte		        Bn2 
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_7_B1
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

bgm_frlg_gamecorner_8:
	.byte	KEYSH , bgm_frlg_gamecorner_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 41*bgm_frlg_gamecorner_mvl/mxv
	.byte	W24
bgm_frlg_gamecorner_8_B1:
	.byte		N01   , Gn3 , v120
	.byte	W36
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W60
	.byte		        Gn3 , v064
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		        Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
bgm_frlg_gamecorner_8_000:
	.byte		N01   , Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W12
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v052
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte	PEND
bgm_frlg_gamecorner_8_001:
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v044
	.byte	W03
	.byte		        Gn3 , v100
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_000
bgm_frlg_gamecorner_8_002:
	.byte		N01   , Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_000
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_000
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_002
bgm_frlg_gamecorner_8_003:
	.byte		N01   , Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte	PEND
bgm_frlg_gamecorner_8_004:
	.byte		N01   , Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v108
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte	PEND
bgm_frlg_gamecorner_8_005:
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		        Gn3 , v056
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Gn3 , v108
	.byte	W12
	.byte		        Gn3 , v084
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte	PEND
	.byte		N01   
	.byte	W12
	.byte		        Gn3 , v048
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v108
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_000
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_002
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_000
	.byte		N01   , Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v096
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        Gn3 , v048
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_000
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_001
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_000
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_002
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_002
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_003
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_004
	.byte	PATT
	 .word	bgm_frlg_gamecorner_8_005
	.byte	GOTO
	 .word	bgm_frlg_gamecorner_8_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_gamecorner:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_gamecorner_pri	@ Priority
	.byte	bgm_frlg_gamecorner_rev	@ Reverb.

	.word	bgm_frlg_gamecorner_grp

	.word	bgm_frlg_gamecorner_1
	.word	bgm_frlg_gamecorner_2
	.word	bgm_frlg_gamecorner_3
	.word	bgm_frlg_gamecorner_4
	.word	bgm_frlg_gamecorner_5
	.word	bgm_frlg_gamecorner_6
	.word	bgm_frlg_gamecorner_7
	.word	bgm_frlg_gamecorner_8

	.end
