	.include "MPlayDef.s"

	.equ	bgm_kachi3_grp, voicegroup_867AB70
	.equ	bgm_kachi3_pri, 0
	.equ	bgm_kachi3_rev, reverb_set+50
	.equ	bgm_kachi3_mvl, 127
	.equ	bgm_kachi3_key, 0
	.equ	bgm_kachi3_tbs, 1
	.equ	bgm_kachi3_exg, 0
	.equ	bgm_kachi3_cmp, 1

	.section .rodata
	.global	bgm_kachi3
	.align	2

@********************** Track  1 **********************@

bgm_kachi3_1:
	.byte	KEYSH , bgm_kachi3_key+0
	.byte	W09
	.byte	TEMPO , 138*bgm_kachi3_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 26
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		N32   , As3 , v112
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N32   , Ds4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N03   , As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOL   , 69*bgm_kachi3_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W04
	.byte		VOL   , 65*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		MOD   , 3
	.byte	W04
	.byte		VOL   , 52*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        43*bgm_kachi3_mvl/mxv
	.byte	W10
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		VOL   , 58*bgm_kachi3_mvl/mxv
	.byte		N92   , As4 , v120
	.byte	W09
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        71*bgm_kachi3_mvl/mxv
	.byte		MOD   , 3
	.byte	W06
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        75*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        66*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        56*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        45*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        21*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        17*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        5*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
bgm_kachi3_1_000:
	.byte		VOICE , 73
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		N06   , Ds5 , v100
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte	PEND
bgm_kachi3_1_B1:
	.byte		N06   , Cn5 , v100
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N24   
	.byte	W09
	.byte		MOD   , 5
	.byte	W15
	.byte		        0
	.byte		N06   , Ds5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W36
	.byte		VOICE , 60
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W06
bgm_kachi3_1_001:
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte	PEND
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	PATT
	 .word	bgm_kachi3_1_001
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W48
	.byte		VOICE , 56
	.byte		BEND  , c_v-9
	.byte		N36   , As3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W15
	.byte		MOD   , 4
	.byte	W18
	.byte		        0
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		BEND  , c_v-9
	.byte		TIE   , Ds4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W44
	.byte	W01
bgm_kachi3_1_002:
	.byte		MOD   , 4
	.byte	W48
	.byte		VOL   , 71*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        57*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        47*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        31*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        18*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        6*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte	PEND
	.byte		EOT   , Ds4 
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		N36   , Cn4 , v112
	.byte	W18
	.byte		MOD   , 4
	.byte	W18
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		TIE   , Fn4 
	.byte	W48
	.byte	PATT
	 .word	bgm_kachi3_1_002
	.byte		EOT   , Fn4 
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		BEND  , c_v-11
	.byte		N36   , Gs3 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W15
	.byte		MOD   , 4
	.byte	W18
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		BEND  , c_v-15
	.byte		N92   , Dn4 
	.byte	W03
	.byte		BEND  , c_v-11
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v+0
	.byte	W24
	.byte	W03
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 71*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        57*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        47*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        31*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        18*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        6*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		BEND  , c_v-20
	.byte		N24   , Gn4 
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 62*bgm_kachi3_mvl/mxv
	.byte		MOD   , 0
	.byte		N80   , Ds4 
	.byte	W09
	.byte		VOL   , 65*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        71*bgm_kachi3_mvl/mxv
	.byte		MOD   , 4
	.byte	W09
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W36
	.byte		MOD   , 0
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N92   , As3 
	.byte	W30
	.byte		MOD   , 4
	.byte	W18
	.byte		VOL   , 71*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        57*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        47*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        31*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        18*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        6*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		N36   , As4 , v096
	.byte	W36
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		TIE   , Ds5 
	.byte	W48
bgm_kachi3_1_003:
	.byte	W36
	.byte	W03
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        72*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        16*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte		EOT   , Ds5 
	.byte		VOL   , 5*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N36   , Cn5 , v096
	.byte	W36
	.byte		N06   , An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		TIE   , Fn5 
	.byte	W48
	.byte	PATT
	 .word	bgm_kachi3_1_003
	.byte		EOT   , Fn5 
	.byte		VOL   , 5*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N36   , Gs4 , v096
	.byte	W36
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N90   , Dn5 
	.byte	W48
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        72*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N24   , As4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N84   , Ds5 
	.byte	W84
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N90   , Ds5 
	.byte	W48
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        72*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte	PATT
	 .word	bgm_kachi3_1_000
	.byte	GOTO
	 .word	bgm_kachi3_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_kachi3_2:
	.byte	KEYSH , bgm_kachi3_key+0
	.byte	W09
	.byte		VOICE , 56
	.byte		LFOS  , 26
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N32   , Gn3 , v084
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N32   , As3 
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		VOL   , 69*bgm_kachi3_mvl/mxv
	.byte		N32   , Ds4 , v104
	.byte	W04
	.byte		VOL   , 65*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		MOD   , 3
	.byte	W04
	.byte		VOL   , 52*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        43*bgm_kachi3_mvl/mxv
	.byte	W10
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , As3 , v092
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOL   , 58*bgm_kachi3_mvl/mxv
	.byte		N92   , Fn4 , v104
	.byte	W09
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        71*bgm_kachi3_mvl/mxv
	.byte		MOD   , 3
	.byte	W06
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        75*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        66*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        56*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        45*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        21*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        17*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        5*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
bgm_kachi3_2_000:
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N09   , Ds3 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v+31
	.byte		N06   , Ds4 , v060
	.byte	W12
	.byte		        Gn4 , v072
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N09   , Dn3 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v+32
	.byte		N06   , Dn4 , v060
	.byte	W12
	.byte		        Fn4 , v072
	.byte	W24
	.byte	PEND
bgm_kachi3_2_B1:
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N09   , Cn3 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v+31
	.byte		N06   , Cn4 , v060
	.byte	W12
	.byte		        Ds4 , v072
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N09   , Dn3 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v+32
	.byte		N06   , As3 , v060
	.byte	W12
	.byte		        Dn4 , v072
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N09   , Ds3 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v+31
	.byte		N06   , Ds4 , v060
	.byte	W12
	.byte		        Gn4 , v072
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N09   , Dn3 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v+32
	.byte		N06   , Dn4 , v060
	.byte	W12
	.byte		        Fn4 , v072
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N09   , Cn3 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v+31
	.byte		N06   , Cn4 , v072
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gn3 
	.byte	W48
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte		PAN   , c_v+9
	.byte		N06   , Gn3 , v100
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Gn2 
	.byte	W48
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v-32
	.byte		N03   , As4 , v076
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N03   , Gs4 , v036
	.byte	W03
	.byte		        Gn4 , v024
	.byte	W03
	.byte		        Ds4 , v008
	.byte	W12
	.byte		VOICE , 60
	.byte		VOL   , 53*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N36   , Gn3 , v092
	.byte	W06
	.byte		VOL   , 59*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        73*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        77*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N48   , As3 
	.byte	W18
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        63*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        57*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        63*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        70*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N44   , An3 
	.byte	W24
	.byte		VOL   , 74*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        65*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        37*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        25*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        13*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N03   , Cn5 , v076
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N03   , As4 , v036
	.byte	W03
	.byte		        An4 , v024
	.byte	W03
	.byte		        Fn4 , v008
	.byte	W12
	.byte		VOICE , 60
	.byte		VOL   , 53*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N36   , An3 , v092
	.byte	W06
	.byte		VOL   , 59*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        73*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        77*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N44   , Cn4 
	.byte	W24
	.byte		VOL   , 74*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        65*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        37*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        25*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        13*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W24
	.byte		VOICE , 56
	.byte		PAN   , c_v-32
	.byte		N12   , Fn4 , v064
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N03   , As4 , v076
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N03   , Gs4 , v036
	.byte	W03
	.byte		        Fn4 , v024
	.byte	W03
	.byte		        Dn4 , v008
	.byte	W12
	.byte		VOICE , 60
	.byte		PAN   , c_v+16
	.byte		N36   , Fn3 , v092
	.byte	W36
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N44   , As3 
	.byte	W24
	.byte		VOL   , 74*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        65*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        37*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        25*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        13*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N03   , As3 , v076
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Gs3 , v032
	.byte	W03
	.byte		        Ds3 , v020
	.byte	W03
	.byte		        As2 , v012
	.byte	W06
	.byte		VOICE , 60
	.byte		PAN   , c_v+16
	.byte		N03   , As2 , v092
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N32   , Gn3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N44   , Dn3 
	.byte	W32
	.byte	W01
	.byte		VOL   , 74*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        45*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        25*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        9*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N08   , As2 , v112
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		VOICE , 60
	.byte		PAN   , c_v+16
	.byte		N96   , Gn3 , v080
	.byte	W12
	.byte		VOL   , 77*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        70*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        57*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        45*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N96   
	.byte	W08
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        44*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        48*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        53*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        76*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte		N96   , An3 
	.byte	W12
	.byte		VOL   , 77*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        70*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        57*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        45*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N96   
	.byte	W08
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        44*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        48*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        53*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        76*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte		N96   , As3 
	.byte	W12
	.byte		VOL   , 77*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        70*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        57*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        45*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		N96   , As3 , v092
	.byte	W05
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        44*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        48*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        53*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        76*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W23
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_kachi3_2_000
	.byte	GOTO
	 .word	bgm_kachi3_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_kachi3_3:
	.byte	KEYSH , bgm_kachi3_key+0
	.byte	W09
	.byte		VOICE , 90
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		N04   , Ds3 , v040
	.byte	W04
	.byte		        Gn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W05
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		        Gn5 
	.byte	W05
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W05
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		        Gn5 
	.byte	W05
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W05
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		        Gn5 
	.byte	W05
	.byte		        Dn6 
	.byte	W04
	.byte		        As5 
	.byte	W05
	.byte		        Fn5 
	.byte	W05
	.byte		        Dn5 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Fn3 
	.byte	W05
	.byte		        Dn3 
	.byte	W05
	.byte		        As2 
	.byte	W04
	.byte		        Dn3 
	.byte	W05
	.byte		        Fn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Dn4 
	.byte	W05
	.byte		        Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W05
	.byte		        Dn5 
	.byte	W05
	.byte		        Fn5 
	.byte	W05
	.byte		        As5 
	.byte	W05
	.byte		VOICE , 81
	.byte		N06   , Ds2 
	.byte	W48
	.byte		        Dn2 
	.byte	W48
bgm_kachi3_3_B1:
	.byte		N06   , Cn2 , v040
	.byte	W48
	.byte		        As1 
	.byte	W48
bgm_kachi3_3_000:
	.byte		N06   , Ds2 , v040
	.byte	W48
	.byte		        Dn2 
	.byte	W48
	.byte	PEND
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn2 , v064
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W48
bgm_kachi3_3_001:
	.byte		N06   , Ds1 , v080
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte		        Gs1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	PATT
	 .word	bgm_kachi3_3_001
	.byte		N06   , Gs1 , v080
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W48
	.byte		N12   , Ds1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		VOICE , 89
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N12   
	.byte	W18
	.byte		N18   , Ds2 
	.byte	W18
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		VOICE , 89
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N18   , Cn2 
	.byte	W18
	.byte		        Fn1 
	.byte	W18
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        As1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		VOICE , 89
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Fn1 
	.byte	W18
	.byte		        Ds1 
	.byte	W18
	.byte		N12   , Dn1 
	.byte	W12
	.byte		VOICE , 81
	.byte		N12   , Ds1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N48   , As1 
	.byte	W48
	.byte		N12   
	.byte	W18
	.byte		        Cn2 
	.byte	W18
	.byte		        Dn2 
	.byte	W12
	.byte		TIE   , Ds2 , v040
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Fn2 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , As1 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 89
	.byte		N06   , Ds2 , v080
	.byte	W12
	.byte		VOICE , 81
	.byte		N06   
	.byte	W24
	.byte		VOICE , 89
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N06   
	.byte	W18
	.byte		N12   , Gs2 
	.byte	W18
	.byte		N06   , Ds2 
	.byte	W12
	.byte		VOICE , 89
	.byte		N06   
	.byte	W12
	.byte		VOICE , 81
	.byte		N06   
	.byte	W24
	.byte		VOICE , 89
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 81
	.byte		N06   
	.byte	W18
	.byte		N12   , Gn2 
	.byte	W18
	.byte		N06   , Ds2 
	.byte	W12
	.byte	PATT
	 .word	bgm_kachi3_3_000
	.byte	GOTO
	 .word	bgm_kachi3_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_kachi3_4:
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte	KEYSH , bgm_kachi3_key+0
	.byte		N24   , Cn3 , v064
	.byte	W09
	.byte		VOICE , 84
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		N32   , Ds2 , v080
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 , v028
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 , v080
	.byte	W12
	.byte		        Ds2 , v028
	.byte	W12
	.byte		N06   , Ds2 , v080
	.byte	W06
	.byte		        Ds2 , v028
	.byte	W06
	.byte		VOL   , 69*bgm_kachi3_mvl/mxv
	.byte		N48   , Ds2 , v080
	.byte	W04
	.byte		VOL   , 65*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        52*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        43*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        37*bgm_kachi3_mvl/mxv
	.byte	W10
	.byte		        41*bgm_kachi3_mvl/mxv
	.byte	W05
	.byte		N96   , Dn2 
	.byte	W02
	.byte		VOL   , 45*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        52*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        66*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        74*bgm_kachi3_mvl/mxv
	.byte	W07
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W24
	.byte	W01
	.byte		        75*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        66*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        56*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        45*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        21*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        17*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        5*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte	W96
bgm_kachi3_4_B1:
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte	W96
	.byte		VOICE , 83
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		N06   , Ds6 , v032
	.byte	W12
	.byte		        Dn6 
	.byte	W12
	.byte		        Cn6 
	.byte	W24
	.byte		        Dn6 
	.byte	W12
	.byte		        Cn6 
	.byte	W12
	.byte		        As5 
	.byte	W24
	.byte		        Cn6 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W48
	.byte		VOICE , 80
	.byte		N12   , Ds3 , v052
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , As3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Dn3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , As3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Cn3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Gs3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , As2 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		N24   , Fn3 , v072
	.byte	W06
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        69*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        75*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v-49
	.byte		N06   , Ds5 , v040
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W48
	.byte		VOICE , 84
	.byte		PAN   , c_v+0
	.byte		N24   , As2 , v060
	.byte	W15
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        29*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Ds3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Gn3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W15
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        29*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Fn3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , An3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W15
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        29*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Fn3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , As3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		BEND  , c_v-13
	.byte		N12   , As3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , Ds3 
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 , v064
	.byte	W18
	.byte		        Ds3 
	.byte	W18
	.byte		        Dn3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 51*bgm_kachi3_mvl/mxv
	.byte		N96   , Dn3 , v068
	.byte	W12
	.byte		VOL   , 54*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        58*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        65*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        71*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        76*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W18
	.byte		N06   , Gs3 , v060
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		VOICE , 83
	.byte		N06   , Gs3 , v052
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		VOICE , 84
	.byte		N06   , Gn3 , v060
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		VOICE , 83
	.byte		N06   , Gn3 , v052
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		XCMD  , xIECV , 0
	.byte		        xIECL , 8
	.byte		N06   , Gn5 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	GOTO
	 .word	bgm_kachi3_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_kachi3_5:
	.byte	KEYSH , bgm_kachi3_key+0
	.byte	W09
	.byte		VOICE , 82
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v+5
	.byte	W04
	.byte		N04   , Ds3 , v024
	.byte	W05
	.byte		        Gn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		        Gn5 
	.byte	W04
	.byte		        Ds3 
	.byte	W05
	.byte		        Gn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		        Gn5 
	.byte	W04
	.byte		        Ds3 
	.byte	W05
	.byte		        Gn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W05
	.byte		        Gn4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		        Gn5 
	.byte	W04
	.byte		        Dn6 
	.byte	W05
	.byte		        As5 
	.byte	W05
	.byte		        Fn5 
	.byte	W05
	.byte		        Dn5 
	.byte	W05
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W05
	.byte		        Dn4 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Fn3 
	.byte	W05
	.byte		        Dn3 
	.byte	W04
	.byte		        As2 
	.byte	W05
	.byte		        Dn3 
	.byte	W05
	.byte		        Fn3 
	.byte	W05
	.byte		        As3 
	.byte	W05
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Dn5 
	.byte	W05
	.byte		        Fn5 
	.byte	W05
	.byte		        As5 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W90
bgm_kachi3_5_B1:
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		        xIECV , 8
	.byte		        xIECL , 8
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		N12   , As2 , v052
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Gn3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , As2 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Fn3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Gs2 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Ds3 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N12   , Fn2 
	.byte	W06
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        59*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		N24   , Dn3 , v072
	.byte	W06
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        69*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        75*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		VOICE , 86
	.byte		PAN   , c_v+48
	.byte		N06   , Gn4 , v040
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W48
	.byte		VOICE , 85
	.byte		PAN   , c_v+0
	.byte		N24   , Gn2 , v060
	.byte	W15
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        29*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , As2 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Ds3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N24   , An2 
	.byte	W15
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        29*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Cn3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , An2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Fn3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , An2 
	.byte	W12
	.byte		N24   , As2 
	.byte	W15
	.byte		VOL   , 70*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        51*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        29*bgm_kachi3_mvl/mxv
	.byte	W15
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Dn3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		BEND  , c_v-20
	.byte		N18   , Fn3 
	.byte	W03
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		BEND  , c_v-13
	.byte		N12   , Gn3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , As2 
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W18
	.byte		        Cn3 
	.byte	W18
	.byte		        As2 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 51*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N12   , As2 , v068
	.byte	W12
	.byte		VOICE , 87
	.byte		VOL   , 54*bgm_kachi3_mvl/mxv
	.byte		N12   
	.byte	W09
	.byte		VOL   , 58*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W06
	.byte		VOL   , 62*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W03
	.byte		VOL   , 65*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte		N12   
	.byte	W09
	.byte		VOL   , 71*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W09
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 85
	.byte		N06   , Ds3 , v060
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		VOICE , 86
	.byte		N06   , Ds3 , v036
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		VOICE , 85
	.byte		N06   , Ds3 , v060
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As2 , v036
	.byte	W06
	.byte		VOICE , 86
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		XCMD  , xIECV , 0
	.byte		        xIECL , 8
	.byte		N06   , Ds5 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	GOTO
	 .word	bgm_kachi3_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_kachi3_6:
	.byte	KEYSH , bgm_kachi3_key+0
	.byte	W09
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte	W48
	.byte		BEND  , c_v+2
	.byte	W48
	.byte		        c_v+0
	.byte	W96
	.byte	W48
bgm_kachi3_6_000:
	.byte		VOICE , 60
	.byte		PAN   , c_v+9
	.byte		N09   , As2 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		N06   , As3 , v048
	.byte	W12
	.byte		        Ds4 , v060
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+9
	.byte		N09   , As2 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		N06   , As3 , v048
	.byte	W12
	.byte		        Dn4 , v060
	.byte	W24
	.byte	PEND
bgm_kachi3_6_B1:
	.byte		VOICE , 60
	.byte		PAN   , c_v+9
	.byte		N09   , Gs2 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		N06   , Gs3 , v048
	.byte	W12
	.byte		        Cn4 , v060
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+9
	.byte		N09   , As2 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		N06   , Fn3 , v068
	.byte	W12
	.byte		        As3 , v060
	.byte	W24
	.byte	PATT
	 .word	bgm_kachi3_6_000
	.byte		VOICE , 60
	.byte		PAN   , c_v+9
	.byte		N09   , Gs2 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		N06   , Gs3 , v060
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        Ds3 , v060
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v+32
	.byte		N03   , Gn4 , v076
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N03   , Fn4 , v036
	.byte	W03
	.byte		        Ds4 , v024
	.byte	W03
	.byte		        As3 , v008
	.byte	W12
	.byte	W96
	.byte	W36
	.byte		PAN   , c_v+0
	.byte		N06   , Fn4 , v076
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N03   , Gn4 , v036
	.byte	W03
	.byte		        Fn4 , v024
	.byte	W03
	.byte		        Cn4 , v008
	.byte	W12
	.byte	W96
	.byte	W24
	.byte		N12   , Dn4 , v064
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N03   , Fn4 , v076
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N03   , Dn4 , v036
	.byte	W03
	.byte		        As3 , v024
	.byte	W03
	.byte		        Fn3 , v008
	.byte	W12
	.byte	W96
	.byte	W06
	.byte		        Gn3 , v076
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Fn3 , v032
	.byte	W03
	.byte		        As2 , v020
	.byte	W03
	.byte		        Gn2 , v012
	.byte	W66
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		PAN   , c_v-16
	.byte		N16   , Gn4 , v080
	.byte	W16
	.byte		        Fn4 
	.byte	W16
	.byte		        Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        Ds4 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N92   , Fn3 
	.byte	W36
	.byte	W03
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        72*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        16*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        5*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte		N16   , Fn4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		        Fn4 
	.byte	W16
	.byte		        Ds4 
	.byte	W16
	.byte		        Fn4 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		N92   , Dn4 
	.byte	W36
	.byte	W03
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        72*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        16*bgm_kachi3_mvl/mxv
	.byte	W03
	.byte		        5*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N84   , Gs4 
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte		N90   , Gn4 
	.byte	W48
	.byte		VOL   , 76*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        72*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W09
	.byte		        62*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        50*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        40*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		        28*bgm_kachi3_mvl/mxv
	.byte	W06
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N09   , As2 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		N06   , As3 , v048
	.byte	W12
	.byte		        Ds4 , v060
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v-1
	.byte		N09   , As2 , v100
	.byte	W12
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		N06   , As3 , v048
	.byte	W12
	.byte		        Dn4 , v060
	.byte	W24
	.byte	GOTO
	 .word	bgm_kachi3_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_kachi3_7:
	.byte	KEYSH , bgm_kachi3_key+0
	.byte	W09
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N12   , As1 , v120
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W36
	.byte		N06   , As1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W36
	.byte		N06   , As1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W84
	.byte		        Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W96
bgm_kachi3_7_B1:
	.byte		N12   , Cn2 , v120
	.byte	W84
	.byte		        Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W96
	.byte		        Cn2 
	.byte	W36
	.byte		        Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W48
bgm_kachi3_7_000:
	.byte		N12   , Ds2 , v120
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte	PEND
	.byte		        Cn2 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte	PATT
	 .word	bgm_kachi3_7_000
	.byte		N12   , Cn2 , v120
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Ds2 
	.byte	W48
	.byte		N12   
	.byte	W96
	.byte		N06   , As1 , v108
	.byte	W06
	.byte		        As1 , v092
	.byte	W06
	.byte		        As1 , v108
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N12   , Ds2 
	.byte	W18
	.byte		        As1 
	.byte	W12
	.byte		        Cn2 , v120
	.byte	W96
	.byte		N06   , Cn2 , v108
	.byte	W06
	.byte		        Cn2 , v092
	.byte	W06
	.byte		        Cn2 , v108
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N12   , Fn2 
	.byte	W18
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 , v120
	.byte	W96
	.byte		N06   , As1 , v108
	.byte	W06
	.byte		        As1 , v092
	.byte	W06
	.byte		        As1 , v108
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N12   , Fn2 
	.byte	W18
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 , v120
	.byte	W36
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N12   
	.byte	W18
	.byte		        Cn2 
	.byte	W18
	.byte		        Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W96
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N96   , As2 , v092
	.byte	W08
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        44*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        48*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        53*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        76*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte	W96
	.byte		N96   , Cn3 
	.byte	W08
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        44*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        48*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        53*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        76*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte	W96
	.byte		N96   , Fn3 , v100
	.byte	W08
	.byte		VOL   , 64*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        44*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        48*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        53*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        60*bgm_kachi3_mvl/mxv
	.byte	W12
	.byte		        68*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        76*bgm_kachi3_mvl/mxv
	.byte	W08
	.byte		        80*bgm_kachi3_mvl/mxv
	.byte	W20
	.byte		VOICE , 47
	.byte		PAN   , c_v-8
	.byte		N12   , Ds2 , v120
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		        As1 
	.byte	W18
	.byte		        Ds2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		        As1 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        Ds2 
	.byte	W96
	.byte	GOTO
	 .word	bgm_kachi3_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_kachi3_8:
	.byte	KEYSH , bgm_kachi3_key+0
	.byte	W09
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_kachi3_mvl/mxv
	.byte		N48   , Bn2 , v104
	.byte	W48
	.byte		N36   , Bn2 , v092
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N48   , Bn2 , v104
	.byte	W48
	.byte		N96   
	.byte	W96
	.byte	W96
bgm_kachi3_8_B1:
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N06   , En1 , v108
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte		N96   , Bn2 
	.byte	W12
	.byte		N06   , En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v108
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v112
	.byte	W24
	.byte		N03   
	.byte	W03
	.byte		        En1 , v092
	.byte	W03
	.byte		N06   , En1 , v076
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v112
	.byte		N48   , Bn2 
	.byte	W24
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W18
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
bgm_kachi3_8_000:
	.byte		N06   , En1 , v112
	.byte	W24
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W18
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte	PEND
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte	PATT
	 .word	bgm_kachi3_8_000
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v112
	.byte	W18
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v056
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v068
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v104
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        En1 , v088
	.byte	W06
	.byte		        En1 , v052
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		N96   , Bn2 , v112
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W48
	.byte		N06   , En1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	W96
	.byte	GOTO
	 .word	bgm_kachi3_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_kachi3:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_kachi3_pri	@ Priority
	.byte	bgm_kachi3_rev	@ Reverb.

	.word	bgm_kachi3_grp

	.word	bgm_kachi3_1
	.word	bgm_kachi3_2
	.word	bgm_kachi3_3
	.word	bgm_kachi3_4
	.word	bgm_kachi3_5
	.word	bgm_kachi3_6
	.word	bgm_kachi3_7
	.word	bgm_kachi3_8

	.end
