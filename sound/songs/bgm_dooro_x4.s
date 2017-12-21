	.include "MPlayDef.s"

	.equ	bgm_dooro_x4_grp, voicegroup_867A1D4
	.equ	bgm_dooro_x4_pri, 0
	.equ	bgm_dooro_x4_rev, reverb_set+50
	.equ	bgm_dooro_x4_mvl, 127
	.equ	bgm_dooro_x4_key, 0
	.equ	bgm_dooro_x4_tbs, 1
	.equ	bgm_dooro_x4_exg, 0
	.equ	bgm_dooro_x4_cmp, 1

	.section .rodata
	.global	bgm_dooro_x4
	.align	2

@********************** Track  1 **********************@

bgm_dooro_x4_1:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte	TEMPO , 124*bgm_dooro_x4_tbs/2
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W96
	.byte	W96
bgm_dooro_x4_1_B1:
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gs3 , v116
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W36
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N48   , Ds3 
	.byte	W72
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W36
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
	.byte		N48   , Gn3 
	.byte	W72
bgm_dooro_x4_1_000:
	.byte		N30   , Gs3 , v116
	.byte	W36
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W18
	.byte		        Gs3 
	.byte	W18
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x4_1_000
	.byte		N30   , Gs3 , v116
	.byte	W36
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		N09   , Cs4 
	.byte	W12
	.byte		N48   
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		VOICE , 56
	.byte		N30   , As4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W18
	.byte		        Gs4 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
	.byte		N32   , Fs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W18
	.byte		        Gs4 
	.byte	W18
	.byte		        Fs4 
	.byte	W12
	.byte		N92   
	.byte	W30
	.byte		VOL   , 75*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 70*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        57*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        48*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        37*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        21*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        11*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N92   , Fn4 
	.byte	W30
	.byte		VOL   , 75*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 70*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        57*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        48*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        37*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        21*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        11*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N66   , Ds4 
	.byte	W24
	.byte		VOL   , 73*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        39*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        25*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        7*bgm_dooro_x4_mvl/mxv
	.byte	W12
bgm_dooro_x4_1_001:
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N12   , Gs3 , v116
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N66   , Ds4 
	.byte	W24
	.byte		VOL   , 73*bgm_dooro_x4_mvl/mxv
	.byte		MOD   , 5
	.byte	W05
	.byte		VOL   , 68*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        39*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        25*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        7*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte	PEND
bgm_dooro_x4_1_002:
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gs3 , v116
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N66   , Bn3 
	.byte	W24
	.byte		VOL   , 73*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        39*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        25*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        7*bgm_dooro_x4_mvl/mxv
	.byte	W12
	.byte	PEND
bgm_dooro_x4_1_003:
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N12   , Gs3 , v116
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N66   , Bn3 
	.byte	W24
	.byte		VOL   , 73*bgm_dooro_x4_mvl/mxv
	.byte		MOD   , 5
	.byte	W05
	.byte		VOL   , 68*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        39*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        25*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        7*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte	PEND
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N66   , Ds4 
	.byte	W24
	.byte		VOL   , 73*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        39*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        25*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        7*bgm_dooro_x4_mvl/mxv
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro_x4_1_001
	.byte	PATT
	 .word	bgm_dooro_x4_1_002
	.byte	PATT
	 .word	bgm_dooro_x4_1_003
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , As3 , v116
	.byte	W18
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N09   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N30   , Ds3 
	.byte	W12
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        70*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        17*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N09   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N92   
	.byte	W09
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        70*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dooro_x4_mvl/mxv
	.byte	W24
	.byte		        65*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        71*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W15
	.byte		N90   , As3 
	.byte	W44
	.byte	W01
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        64*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        45*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        36*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        24*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        9*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_dooro_x4_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_dooro_x4_2:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte		VOICE , 58
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Cs1 , v127
	.byte	W05
	.byte		VOL   , 58*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        55*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        53*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        52*bgm_dooro_x4_mvl/mxv
	.byte	W12
	.byte		        53*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        56*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        59*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        62*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        66*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        78*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N56   , Ds1 
	.byte	W18
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        78*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        62*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        41*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        23*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
bgm_dooro_x4_2_B1:
	.byte		VOICE , 58
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Gs1 , v127
	.byte	W24
	.byte		N32   , Ds1 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        55*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        1*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N21   , Ds1 
	.byte	W24
bgm_dooro_x4_2_000:
	.byte		N12   , Ds1 , v127
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N32   , As1 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        55*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        1*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PEND
	.byte		        Gs1 
	.byte	W24
	.byte		N32   , Ds1 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        55*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        1*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N21   , Ds1 
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro_x4_2_000
bgm_dooro_x4_2_001:
	.byte		N12   , Cs2 , v127
	.byte	W24
	.byte		N32   , Gs1 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        55*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        1*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N12   , Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x4_2_001
	.byte		N12   , Gs1 , v127
	.byte	W24
	.byte		N30   , Ds1 
	.byte	W36
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N15   , As1 
	.byte	W18
	.byte		        Gs1 
	.byte	W18
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N42   , Fn1 
	.byte	W30
	.byte		VOL   , 69*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        62*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        47*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        30*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        20*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W48
	.byte		N12   , Ds3 , v108
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte	W48
	.byte		        Cs3 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte	W48
	.byte		VOICE , 56
	.byte		N44   , Cs4 , v092
	.byte	W18
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 75*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        46*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        39*bgm_dooro_x4_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N92   
	.byte	W30
	.byte		VOL   , 75*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 70*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        57*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        48*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        37*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        21*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        11*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 73
	.byte	W48
	.byte		PAN   , c_v-16
	.byte		N12   , Ds4 , v088
	.byte	W18
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N72   , Gs4 
	.byte	W24
bgm_dooro_x4_2_002:
	.byte		MOD   , 5
	.byte	W18
	.byte		VOL   , 73*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        62*bgm_dooro_x4_mvl/mxv
	.byte	W02
	.byte		        57*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        53*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        44*bgm_dooro_x4_mvl/mxv
	.byte	W04
	.byte		        34*bgm_dooro_x4_mvl/mxv
	.byte	W02
	.byte		        28*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        17*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        11*bgm_dooro_x4_mvl/mxv
	.byte	W04
	.byte		        3*bgm_dooro_x4_mvl/mxv
	.byte		MOD   , 0
	.byte	W48
	.byte	PEND
	.byte	W48
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , En4 , v088
	.byte	W18
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N72   , Gs4 
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro_x4_2_002
	.byte	W96
	.byte	W48
	.byte		VOICE , 58
	.byte		VOL   , 58*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Ds1 , v127
	.byte	W03
	.byte		VOL   , 48*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        66*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        70*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        75*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dooro_x4_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_dooro_x4_3:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N06   , Cs2 , v092
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Ds2 , v088
	.byte	W12
	.byte		        Ds2 , v100
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
bgm_dooro_x4_3_B1:
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W96
	.byte		        65*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N32   , Ds4 , v076
	.byte	W03
	.byte		VOL   , 60*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        58*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        71*bgm_dooro_x4_mvl/mxv
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 78*bgm_dooro_x4_mvl/mxv
	.byte	W15
	.byte		MOD   , 0
	.byte	W03
	.byte		N03   , Ds4 , v096
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W12
	.byte	W96
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte		N32   , Ds4 , v076
	.byte	W03
	.byte		VOL   , 60*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        58*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        71*bgm_dooro_x4_mvl/mxv
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 78*bgm_dooro_x4_mvl/mxv
	.byte	W15
	.byte		MOD   , 0
	.byte	W03
	.byte		N03   , Gn4 , v096
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 47
	.byte	W60
	.byte		PAN   , c_v+0
	.byte		N12   , Ds2 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N21   
	.byte	W48
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W48
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W48
	.byte		VOICE , 60
	.byte		N12   , Gs2 , v108
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N92   
	.byte	W30
	.byte		VOL   , 75*bgm_dooro_x4_mvl/mxv
	.byte	W11
	.byte		        70*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        57*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        48*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        37*bgm_dooro_x4_mvl/mxv
	.byte	W05
	.byte		        21*bgm_dooro_x4_mvl/mxv
	.byte	W07
	.byte		        11*bgm_dooro_x4_mvl/mxv
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Ds2 , v104
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
bgm_dooro_x4_3_000:
	.byte		N06   , Ds2 , v127
	.byte	W06
	.byte		        Ds2 , v104
	.byte	W06
	.byte		N12   , Ds2 , v127
	.byte	W24
	.byte		        Ds2 , v104
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Ds2 , v127
	.byte	W12
	.byte	PEND
bgm_dooro_x4_3_001:
	.byte		N12   , Fs2 , v104
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
bgm_dooro_x4_3_002:
	.byte		N06   , Fs2 , v127
	.byte	W06
	.byte		        Fs2 , v104
	.byte	W06
	.byte		N12   , Fs2 , v127
	.byte	W24
	.byte		        Fs2 , v104
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Fs2 , v127
	.byte	W12
	.byte	PEND
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Ds2 , v104
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro_x4_3_000
	.byte	PATT
	 .word	bgm_dooro_x4_3_001
	.byte	PATT
	 .word	bgm_dooro_x4_3_002
	.byte		N12   , Ds2 , v127
	.byte	W96
	.byte	W96
	.byte		VOICE , 47
	.byte		N06   , Ds2 , v124
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds2 , v108
	.byte	W06
	.byte		        Ds2 , v124
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds2 , v108
	.byte	W06
	.byte		        Ds2 , v124
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds2 , v108
	.byte	W06
	.byte		        Ds2 , v124
	.byte	W12
	.byte		N12   , Ds2 , v108
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	GOTO
	 .word	bgm_dooro_x4_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_dooro_x4_4:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte		VOICE , 2
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Fn4 , v036
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+49
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v+49
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Gn4 , v040
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 , v044
	.byte	W06
bgm_dooro_x4_4_B1:
	.byte		VOICE , 2
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Ds5 , v036
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+49
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
bgm_dooro_x4_4_000:
	.byte		PAN   , c_v+0
	.byte		N03   , Ds5 , v036
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+49
	.byte		N03   , As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+49
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro_x4_4_000
	.byte		VOICE , 4
	.byte		PAN   , c_v-48
	.byte		N12   , Fn4 , v048
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W12
	.byte		N44   , Fn4 
	.byte	W21
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        15*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        6*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , En4 
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W12
	.byte		N44   , En4 
	.byte	W21
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        15*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        6*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W18
	.byte		        Cn4 
	.byte	W12
	.byte		N44   , Ds4 
	.byte	W21
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        15*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        6*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N06   , As2 , v044
	.byte	W06
	.byte		        Cs3 , v048
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 , v052
	.byte	W06
	.byte		        As3 , v056
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Gs4 , v056
	.byte	W06
	.byte		        Fn4 , v048
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N30   , Gn4 , v052
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        26*bgm_dooro_x4_mvl/mxv
	.byte	W24
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , As2 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N32   , Cs4 
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        26*bgm_dooro_x4_mvl/mxv
	.byte	W24
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , As2 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cs4 , v064
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 , v056
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn5 , v048
	.byte	W06
	.byte		        Cs5 , v036
	.byte	W06
	.byte		PAN   , c_v+49
	.byte		N06   , Fn5 , v032
	.byte	W06
	.byte		        Cs5 , v028
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn5 , v024
	.byte	W06
	.byte		        Cs5 , v020
	.byte	W06
	.byte		N24   , Cn3 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W30
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W48
	.byte		N24   
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Gs4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn4 , v056
	.byte	W24
	.byte		N03   , Gs4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N24   , Bn2 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W30
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W48
	.byte		N24   
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Gs4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Bn3 , v056
	.byte	W24
	.byte		N03   , Gs4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N24   , Cn3 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Gs3 , v072
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 48*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N48   , Ds3 , v084
	.byte	W06
	.byte		VOL   , 54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N06   , Cn4 , v072
	.byte	W18
	.byte		        Gs3 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		MOD   , 0
	.byte		N24   , Bn2 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Gs3 , v072
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 48*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N48   , En3 , v084
	.byte	W06
	.byte		VOL   , 54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N06   , Gs3 , v072
	.byte	W18
	.byte		        En3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N48   , Ds3 , v052
	.byte	W24
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        42*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        29*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        10*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        4*bgm_dooro_x4_mvl/mxv
	.byte	W48
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N48   , Cn3 
	.byte	W24
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        60*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        42*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        29*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        10*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        4*bgm_dooro_x4_mvl/mxv
	.byte	W12
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N09   , Gs2 , v064
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N92   
	.byte	W09
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        70*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        68*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dooro_x4_mvl/mxv
	.byte	W24
	.byte		        65*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        71*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W15
	.byte		N90   , Gn3 
	.byte	W44
	.byte	W01
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        69*bgm_dooro_x4_mvl/mxv
	.byte	W09
	.byte		        64*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        45*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        36*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        24*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        9*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_dooro_x4_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_dooro_x4_5:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte		VOICE , 5
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N03   , Gs2 , v060
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
bgm_dooro_x4_5_B1:
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		N06   , Gs3 , v060
	.byte	W48
	.byte		N06   
	.byte	W24
bgm_dooro_x4_5_000:
	.byte	W24
	.byte		N06   , Gs3 , v060
	.byte	W48
	.byte		        Gn3 
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		        Gs3 
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro_x4_5_000
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		N12   , Cs4 , v048
	.byte	W18
	.byte		        Cn4 
	.byte	W18
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W09
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W03
	.byte		VOL   , 54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		N09   
	.byte	W03
	.byte		VOL   , 15*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        6*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W18
	.byte		        Cn4 
	.byte	W18
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W09
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W03
	.byte		VOL   , 54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		N09   
	.byte	W03
	.byte		VOL   , 15*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        6*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W09
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W03
	.byte		VOL   , 54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		N09   
	.byte	W03
	.byte		VOL   , 15*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        6*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		N06   , As2 , v028
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N30   , Ds4 , v052
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        26*bgm_dooro_x4_mvl/mxv
	.byte	W24
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Gn2 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N32   , As3 , v040
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        26*bgm_dooro_x4_mvl/mxv
	.byte	W24
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Fs2 , v052
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		N06   , Cs4 , v028
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 , v024
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 , v016
	.byte	W06
	.byte		        Fn5 , v012
	.byte	W06
	.byte		        Cs5 , v008
	.byte	W24
bgm_dooro_x4_5_001:
	.byte		PAN   , c_v+48
	.byte		N24   , Gs2 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W30
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte	W48
	.byte	PEND
	.byte		N24   
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Ds4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gs3 , v056
	.byte	W24
	.byte		N03   , Ds4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro_x4_5_001
	.byte		N24   , Gs2 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gs3 , v056
	.byte	W24
	.byte		N03   , En4 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N24   , Gs2 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Ds3 , v072
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 48*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N12   , Cn3 , v084
	.byte	W06
	.byte		VOL   , 54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		VOICE , 6
	.byte		VOL   , 58*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		N06   , Gs3 , v072
	.byte	W18
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		MOD   , 0
	.byte		N24   , Gs2 , v080
	.byte	W09
	.byte		VOL   , 65*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        51*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , En3 , v072
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Bn2 
	.byte	W24
	.byte		N03   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOL   , 48*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N12   , Bn2 , v084
	.byte	W06
	.byte		VOL   , 54*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		VOICE , 6
	.byte		VOL   , 58*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 66*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		N06   , En3 , v072
	.byte	W18
	.byte		        Bn2 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Gn2 , v052
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 60*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        42*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W03
	.byte		VOL   , 29*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        10*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        4*bgm_dooro_x4_mvl/mxv
	.byte	W48
	.byte		VOICE , 5
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Gs2 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 60*bgm_dooro_x4_mvl/mxv
	.byte	W06
	.byte		        42*bgm_dooro_x4_mvl/mxv
	.byte		N12   
	.byte	W03
	.byte		VOL   , 29*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        18*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        10*bgm_dooro_x4_mvl/mxv
	.byte	W03
	.byte		        4*bgm_dooro_x4_mvl/mxv
	.byte	W48
	.byte		VOICE , 5
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N03   , Gs2 , v072
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn2 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dooro_x4_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_dooro_x4_6:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte		VOICE , 85
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N03   , Cs3 , v064
	.byte	W36
	.byte		VOICE , 84
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 85
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		VOICE , 84
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 85
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
bgm_dooro_x4_6_B1:
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N12   , Gs2 , v064
	.byte	W18
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N18   , Ds3 , v032
	.byte	W18
	.byte		N06   , Ds3 , v064
	.byte	W18
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W18
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N42   , Ds2 
	.byte	W42
	.byte		N06   , Ds2 , v032
	.byte	W30
	.byte		N12   , Gs2 , v064
	.byte	W18
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N18   , Ds3 
	.byte	W18
	.byte		N06   , Ds3 , v032
	.byte	W18
	.byte		        Cs3 , v064
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W18
	.byte		N06   , As2 
	.byte	W06
	.byte		N42   , Gn2 
	.byte	W42
	.byte		N06   , Gn2 , v032
	.byte	W30
	.byte		N24   , Cs3 , v064
	.byte	W24
	.byte		N06   , Cs3 , v032
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W18
	.byte		        Ds3 
	.byte	W18
	.byte		        Cs3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Cs3 , v032
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , En3 
	.byte	W18
	.byte		        Ds3 
	.byte	W18
	.byte		        Cs3 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Ds3 , v032
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W18
	.byte		        Gs3 
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		N42   , Gn3 
	.byte	W42
	.byte		N06   , Gn3 , v032
	.byte	W06
	.byte		N36   , Gs3 , v064
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N32   , Ds1 , v080
	.byte	W48
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N30   , Fs1 
	.byte	W30
	.byte		N12   , Fs1 , v032
	.byte	W18
	.byte		        Cs1 , v080
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N48   , Gs1 
	.byte	W48
	.byte		N12   , Gs1 , v032
	.byte	W18
	.byte		        Cs2 , v080
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N48   , Cs1 
	.byte	W48
	.byte		N12   , Cs1 , v048
	.byte	W12
	.byte		        Cs1 , v032
	.byte	W36
bgm_dooro_x4_6_000:
	.byte		N12   , Gs1 , v080
	.byte	W36
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x4_6_000
bgm_dooro_x4_6_001:
	.byte		N12   , Bn1 , v080
	.byte	W36
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x4_6_001
	.byte	PATT
	 .word	bgm_dooro_x4_6_000
	.byte	PATT
	 .word	bgm_dooro_x4_6_000
	.byte	PATT
	 .word	bgm_dooro_x4_6_001
	.byte	PATT
	 .word	bgm_dooro_x4_6_001
	.byte		N48   , Ds1 , v080
	.byte	W48
	.byte		N12   , Ds1 , v032
	.byte	W48
	.byte	W96
	.byte		VOICE , 85
	.byte		N03   , As2 , v080
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		VOICE , 84
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 85
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		VOICE , 84
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 85
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dooro_x4_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_dooro_x4_7:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cs3 , v088
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds3 , v084
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
bgm_dooro_x4_7_B1:
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		N06   , Cn4 , v088
	.byte	W48
	.byte		N06   
	.byte	W24
bgm_dooro_x4_7_000:
	.byte	W24
	.byte		N06   , As3 , v088
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		        Cn4 
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro_x4_7_000
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
	.byte	GOTO
	 .word	bgm_dooro_x4_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_dooro_x4_8:
	.byte	KEYSH , bgm_dooro_x4_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_dooro_x4_mvl/mxv
	.byte		N06   , En1 , v104
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_dooro_x4_8_000:
	.byte		N06   , En1 , v104
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v072
	.byte	W06
	.byte		        En1 , v104
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        En1 , v052
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		        En1 , v076
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
	.byte	PEND
bgm_dooro_x4_8_B1:
bgm_dooro_x4_8_001:
	.byte		N06   , En1 , v104
	.byte		N48   , Bn2 , v084
	.byte	W36
	.byte		N06   , En1 , v104
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
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
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro_x4_8_001
	.byte		N06   , En1 , v104
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
	.byte		        En1 , v076
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v104
	.byte		N96   , Bn2 , v084
	.byte	W18
	.byte		N06   , En1 , v076
	.byte	W06
	.byte		        En1 , v104
	.byte	W12
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v104
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
bgm_dooro_x4_8_002:
	.byte		N06   , En1 , v104
	.byte	W18
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v104
	.byte	W12
	.byte		        En1 , v084
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v104
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte		N06   , En1 , v104
	.byte	W18
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v104
	.byte	W12
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v104
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v076
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro_x4_8_002
bgm_dooro_x4_8_003:
	.byte		N06   , En1 , v104
	.byte		N48   , Bn2 , v084
	.byte	W48
	.byte		N06   , En1 , v104
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x4_8_003
	.byte		N06   , En1 , v104
	.byte		N48   , Bn2 , v084
	.byte	W18
	.byte		N06   , En1 , v104
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v076
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		        En1 , v052
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte	PATT
	 .word	bgm_dooro_x4_8_001
bgm_dooro_x4_8_004:
	.byte		N06   , En1 , v104
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x4_8_001
bgm_dooro_x4_8_005:
	.byte		N06   , En1 , v104
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v076
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v076
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x4_8_001
	.byte	PATT
	 .word	bgm_dooro_x4_8_004
	.byte	PATT
	 .word	bgm_dooro_x4_8_001
	.byte	PATT
	 .word	bgm_dooro_x4_8_005
	.byte		N06   , En1 , v104
	.byte		N48   , Bn2 , v096
	.byte	W96
	.byte	W48
	.byte		N03   , En1 , v116
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v060
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		        En1 , v092
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		N06   , En1 , v104
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v072
	.byte	W06
	.byte		        En1 , v104
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v072
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro_x4_8_000
	.byte	GOTO
	 .word	bgm_dooro_x4_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_dooro_x4:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_dooro_x4_pri	@ Priority
	.byte	bgm_dooro_x4_rev	@ Reverb.

	.word	bgm_dooro_x4_grp

	.word	bgm_dooro_x4_1
	.word	bgm_dooro_x4_2
	.word	bgm_dooro_x4_3
	.word	bgm_dooro_x4_4
	.word	bgm_dooro_x4_5
	.word	bgm_dooro_x4_6
	.word	bgm_dooro_x4_7
	.word	bgm_dooro_x4_8

	.end
