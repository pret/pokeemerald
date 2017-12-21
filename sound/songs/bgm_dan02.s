	.include "MPlayDef.s"

	.equ	bgm_dan02_grp, voicegroup_867C5A4
	.equ	bgm_dan02_pri, 0
	.equ	bgm_dan02_rev, reverb_set+50
	.equ	bgm_dan02_mvl, 127
	.equ	bgm_dan02_key, 0
	.equ	bgm_dan02_tbs, 1
	.equ	bgm_dan02_exg, 0
	.equ	bgm_dan02_cmp, 1

	.section .rodata
	.global	bgm_dan02
	.align	2

@********************** Track  1 **********************@

bgm_dan02_1:
	.byte	KEYSH , bgm_dan02_key+0
	.byte	TEMPO , 100*bgm_dan02_tbs/2
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		LFOS  , 40
	.byte	W36
bgm_dan02_1_B1:
	.byte		VOICE , 17
	.byte		N56   , As4 , v108
	.byte	W24
	.byte		MOD   , 9
	.byte	W32
	.byte	W01
	.byte		        0
	.byte	W03
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N56   , As4 
	.byte	W24
	.byte		MOD   , 9
	.byte	W32
	.byte	W01
	.byte		        0
	.byte	W03
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N09   , Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N56   , Cn5 
	.byte	W24
	.byte		MOD   , 9
	.byte	W12
	.byte		VOL   , 72*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        65*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        51*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        24*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 14
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N24   , Cn4 , v092
	.byte	W24
	.byte		        An3 
	.byte	W60
	.byte		VOICE , 17
	.byte		N56   , Ds5 , v108
	.byte	W24
	.byte		MOD   , 9
	.byte	W32
	.byte	W01
	.byte		        0
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N56   , Gs4 
	.byte	W24
	.byte		MOD   , 9
	.byte	W32
	.byte	W01
	.byte		        0
	.byte	W03
	.byte		N12   , Ds5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N09   , Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N56   , Cs5 
	.byte	W24
	.byte		MOD   , 9
	.byte	W12
	.byte		VOL   , 72*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        65*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        51*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        24*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 14
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N24   , Cs4 , v092
	.byte	W24
	.byte		        As3 
	.byte	W28
	.byte		VOL   , 72*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		        54*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		        60*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		        67*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		        72*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		        77*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W04
	.byte		VOICE , 1
	.byte		N12   , Cs4 , v100
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cs4 , v072
	.byte	W12
	.byte		PAN   , c_v+17
	.byte		N12   , Cs4 , v056
	.byte	W12
	.byte		PAN   , c_v-31
	.byte		N12   , Cs4 , v032
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , An3 , v100
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gs3 , v072
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Gs3 , v056
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N12   , Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn4 , v100
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cn4 , v072
	.byte	W12
	.byte		PAN   , c_v+17
	.byte		N12   , Cn4 , v056
	.byte	W12
	.byte		PAN   , c_v-31
	.byte		N12   , Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cs4 , v100
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cs4 , v072
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cs4 , v056
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Fn4 , v100
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Fn4 , v072
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gs4 , v100
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gs4 , v072
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cs5 , v100
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Cn5 , v072
	.byte	W12
	.byte		PAN   , c_v+17
	.byte		N12   , Cn5 , v056
	.byte	W12
	.byte		PAN   , c_v-31
	.byte		N12   , Cn5 , v032
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn5 , v020
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N12   , Cn5 , v012
	.byte	W24
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		N03   , Gn4 , v108
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N36   , Bn4 
	.byte	W18
	.byte		MOD   , 9
	.byte	W18
	.byte		        0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N44   , Gs4 
	.byte	W18
	.byte		MOD   , 9
	.byte	W24
	.byte	W03
	.byte		        0
	.byte	W09
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W18
	.byte		        As4 
	.byte	W18
	.byte		        Bn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dan02_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_dan02_2:
	.byte	KEYSH , bgm_dan02_key+0
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W36
bgm_dan02_2_B1:
	.byte		VOICE , 90
	.byte		PAN   , c_v+10
	.byte		N06   , Fs2 , v100
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N21   , Fn4 , v072
	.byte	W12
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W15
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N06   , Fs2 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N21   , Fn4 , v072
	.byte	W09
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N36   , Fs2 , v100
	.byte	W06
	.byte		VOL   , 64*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        73*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        78*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N21   , Ds4 , v072
	.byte	W12
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W15
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N06   , Fs2 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N21   , Ds4 , v072
	.byte	W09
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N36   , Fs2 , v100
	.byte	W06
	.byte		VOL   , 64*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        73*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        78*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N21   , Cn4 , v072
	.byte	W12
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W15
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N06   , Fn2 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N21   , Cn4 , v072
	.byte	W09
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N36   , Fn2 , v100
	.byte	W06
	.byte		VOL   , 64*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        73*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        78*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N18   , As3 , v072
	.byte	W06
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W32
	.byte	W01
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N06   , Cs3 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N18   , As3 , v072
	.byte	W06
	.byte		VOL   , 73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        61*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dan02_mvl/mxv
	.byte	W09
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N36   , Cs3 , v100
	.byte	W36
	.byte	W48
	.byte		VOL   , 42*bgm_dan02_mvl/mxv
	.byte		N48   
	.byte	W06
	.byte		VOL   , 47*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        56*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        65*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        70*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        75*bgm_dan02_mvl/mxv
	.byte	W09
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W09
	.byte		N96   , Cn3 
	.byte	W24
	.byte		VOL   , 74*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        56*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        53*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N96   , As2 
	.byte	W24
	.byte		VOL   , 74*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        56*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        53*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N96   , Gs2 
	.byte	W24
	.byte		VOL   , 74*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        56*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        45*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        53*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        45*bgm_dan02_mvl/mxv
	.byte		N80   , Bn2 
	.byte	W06
	.byte		VOL   , 49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        53*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W09
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W36
	.byte	W03
	.byte		N09   
	.byte	W12
	.byte		VOL   , 45*bgm_dan02_mvl/mxv
	.byte		N80   , Dn3 
	.byte	W06
	.byte		VOL   , 49*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        53*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W09
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W36
	.byte	W03
	.byte		N09   
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N42   
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        Cs2 
	.byte	W18
	.byte		        Ds2 
	.byte	W18
	.byte		        Fn2 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dan02_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_dan02_3:
	.byte	KEYSH , bgm_dan02_key+0
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte	W36
bgm_dan02_3_B1:
	.byte		VOICE , 47
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+0
	.byte		N12   , Fs2 , v127
	.byte	W12
	.byte		        Fs2 , v116
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W48
	.byte		        Fs2 , v127
	.byte	W24
	.byte		        Fs2 , v116
	.byte	W12
	.byte		        Fs2 , v127
	.byte	W12
	.byte		        Fs2 , v116
	.byte	W72
	.byte		        Fs2 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		        Fs2 , v116
	.byte	W12
	.byte		        Fn2 , v127
	.byte	W12
	.byte		        Fn2 , v116
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W48
	.byte		        Fn2 , v127
	.byte	W24
	.byte		        Fn2 , v116
	.byte	W12
	.byte		        Cs2 , v127
	.byte	W12
	.byte		        Cs2 , v116
	.byte	W72
	.byte		        Cs2 , v127
	.byte	W12
	.byte		        Cs2 , v120
	.byte	W12
	.byte		N12   
	.byte	W48
	.byte		N03   , Fn2 , v100
	.byte	W03
	.byte		        Fn2 , v092
	.byte	W03
	.byte		        Fn2 , v096
	.byte	W03
	.byte		        Fn2 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fn2 , v104
	.byte	W03
	.byte		        Fn2 , v108
	.byte	W03
	.byte		        Fn2 , v112
	.byte	W03
	.byte		        Fn2 , v116
	.byte	W03
	.byte		        Fn2 , v120
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fn2 , v124
	.byte	W03
	.byte		N24   , Fs2 , v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W60
	.byte		N06   , Bn1 , v116
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , Dn2 , v127
	.byte	W60
	.byte		N06   , Dn2 , v116
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , Cs2 , v127
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W60
	.byte	GOTO
	 .word	bgm_dan02_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_dan02_4:
	.byte	KEYSH , bgm_dan02_key+0
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte	W36
bgm_dan02_4_B1:
	.byte		VOICE , 7
	.byte		PAN   , c_v-47
	.byte		N06   , As3 , v048
	.byte	W12
	.byte		        Fs4 , v052
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        As3 , v048
	.byte	W12
	.byte		        Fs4 , v052
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , An3 , v048
	.byte	W12
	.byte		        Ds4 , v052
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        An3 , v048
	.byte	W12
	.byte		        Ds4 , v052
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Cn4 , v048
	.byte	W12
	.byte		        Fn4 , v052
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cn4 , v048
	.byte	W12
	.byte		        Fn4 , v052
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Cs4 , v048
	.byte	W12
	.byte		        Fn4 , v052
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Fn4 , v048
	.byte	W12
	.byte		        Ds4 , v052
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W36
	.byte		VOICE , 46
	.byte		PAN   , c_v-13
	.byte		N06   , Fs3 , v060
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        Cs4 , v068
	.byte	W06
	.byte		        Ds4 , v072
	.byte	W06
	.byte		        Fs4 , v076
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		        Cs5 , v084
	.byte	W06
	.byte		        Ds5 , v088
	.byte	W06
	.byte		        An5 , v092
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Ds5 , v084
	.byte	W06
	.byte		        Cs5 , v080
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        Fs4 , v072
	.byte	W06
	.byte		        Cs4 , v068
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Fn3 , v060
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        Cn4 , v068
	.byte	W06
	.byte		        Ds4 , v072
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Gs4 , v080
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Ds5 , v088
	.byte	W06
	.byte		        Gs5 , v092
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 , v084
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Gs4 , v076
	.byte	W06
	.byte		        Fn4 , v072
	.byte	W06
	.byte		        Cn4 , v068
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Cs3 , v060
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        As3 , v068
	.byte	W06
	.byte		        Cs4 , v072
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Gs4 , v080
	.byte	W06
	.byte		        As4 , v084
	.byte	W06
	.byte		        Cs5 , v088
	.byte	W06
	.byte		        Fn5 , v092
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 , v084
	.byte	W06
	.byte		        Gs4 , v080
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Cs4 , v072
	.byte	W06
	.byte		        As3 , v068
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        Ds3 , v060
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Gs3 , v068
	.byte	W06
	.byte		        Cn4 , v072
	.byte	W06
	.byte		        Ds4 , v076
	.byte	W06
	.byte		        Gn4 , v080
	.byte	W06
	.byte		        Gs4 , v084
	.byte	W06
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Gs5 , v092
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Ds5 , v084
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Gs4 , v076
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        Ds4 , v068
	.byte	W06
	.byte		        Cn4 , v064
	.byte	W06
	.byte		VOICE , 7
	.byte		PAN   , c_v-47
	.byte		N06   , Fs4 , v052
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W18
	.byte		        Gs4 
	.byte	W18
	.byte		        Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W24
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N04   , Cs4 , v032
	.byte	W04
	.byte		        Fs3 
	.byte	W05
	.byte		        Cs3 
	.byte	W05
	.byte		        Gs3 
	.byte	W05
	.byte		        Fs4 
	.byte	W05
	.byte		        Cs3 , v040
	.byte	W04
	.byte		        Gs3 
	.byte	W05
	.byte		        Cs4 
	.byte	W05
	.byte		        Gs4 , v052
	.byte	W05
	.byte		        Cs5 
	.byte	W05
	.byte		N12   , Gs4 
	.byte	W18
	.byte		        Fs4 
	.byte	W18
	.byte		        Fn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Gs3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dan02_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_dan02_5:
	.byte	KEYSH , bgm_dan02_key+0
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte	W36
bgm_dan02_5_B1:
	.byte		VOICE , 8
	.byte		PAN   , c_v+49
	.byte		N06   , Fs3 , v048
	.byte	W12
	.byte		        Cs4 , v052
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W12
	.byte		        Cs4 , v052
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Fs3 , v048
	.byte	W12
	.byte		        Cn4 , v052
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , An2 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W12
	.byte		        Cn4 , v052
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Gs3 , v048
	.byte	W12
	.byte		        Cn4 , v052
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Gs3 , v048
	.byte	W12
	.byte		        Cn4 , v052
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , As3 , v048
	.byte	W12
	.byte		        Cs4 , v052
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cs4 , v048
	.byte	W12
	.byte		        Cs4 , v052
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N36   , Cs3 
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W24
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W24
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W08
	.byte		N04   , Gs3 , v032
	.byte	W05
	.byte		        Gs2 
	.byte	W05
	.byte		        Fs3 
	.byte	W04
	.byte		        Bn3 
	.byte	W05
	.byte		        Gs4 
	.byte	W05
	.byte		        Fs3 , v040
	.byte	W05
	.byte		        Bn3 
	.byte	W05
	.byte		        Fs4 , v052
	.byte	W04
	.byte		        Bn4 
	.byte	W08
	.byte		N12   , Fn4 
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W18
	.byte		        Fs3 
	.byte	W18
	.byte		        Fn3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dan02_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_dan02_6:
	.byte	KEYSH , bgm_dan02_key+0
	.byte	W36
bgm_dan02_6_B1:
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte		N06   , Fs1 , v064
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte		N06   
	.byte	W12
bgm_dan02_6_000:
	.byte		N06   , Fs1 , v064
	.byte	W12
	.byte		N06   
	.byte	W48
	.byte		N36   
	.byte	W36
	.byte	PEND
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	bgm_dan02_6_000
	.byte		N06   , Fn1 , v064
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W48
	.byte		N36   
	.byte	W36
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W48
	.byte		N36   
	.byte	W36
	.byte	W48
	.byte		VOL   , 40*bgm_dan02_mvl/mxv
	.byte		N48   
	.byte	W18
	.byte		VOL   , 62*bgm_dan02_mvl/mxv
	.byte	W18
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W12
	.byte		N96   , Cn2 
	.byte	W24
	.byte		VOL   , 62*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        40*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N96   , As1 
	.byte	W24
	.byte		VOL   , 62*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        40*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N96   , Gs1 
	.byte	W24
	.byte		VOL   , 62*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        40*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W24
	.byte		        40*bgm_dan02_mvl/mxv
	.byte		N80   , Bn1 
	.byte	W15
	.byte		VOL   , 59*bgm_dan02_mvl/mxv
	.byte	W21
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W48
	.byte		N09   
	.byte	W12
	.byte		VOL   , 40*bgm_dan02_mvl/mxv
	.byte		N80   , Dn2 
	.byte	W15
	.byte		VOL   , 59*bgm_dan02_mvl/mxv
	.byte	W21
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W48
	.byte		N09   
	.byte	W12
	.byte		N12   , Cs2 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N42   
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W18
	.byte		        Ds1 
	.byte	W18
	.byte		        Fn1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dan02_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_dan02_7:
	.byte	KEYSH , bgm_dan02_key+0
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte	W36
bgm_dan02_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		VOICE , 0
	.byte		VOL   , 40*bgm_dan02_mvl/mxv
	.byte		N36   , An2 , v064
	.byte	W06
	.byte		VOL   , 47*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        52*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        59*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W48
	.byte		VOICE , 60
	.byte		VOL   , 49*bgm_dan02_mvl/mxv
	.byte		N48   , Gs2 , v096
	.byte	W06
	.byte		VOL   , 54*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        65*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        70*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		N36   , As2 
	.byte	W36
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N84   , Ds3 
	.byte	W56
	.byte	W01
	.byte		VOL   , 78*bgm_dan02_mvl/mxv
	.byte	W09
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W09
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dan02_mvl/mxv
	.byte	W15
	.byte		        80*bgm_dan02_mvl/mxv
	.byte		N09   , Gs2 , v100
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N32   , Gs2 
	.byte	W18
	.byte		VOL   , 68*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        30*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		VOICE , 14
	.byte		VOL   , 80*bgm_dan02_mvl/mxv
	.byte		N12   , Ds4 , v112
	.byte	W12
	.byte		N36   , Dn4 
	.byte	W60
	.byte		VOICE , 60
	.byte		VOL   , 55*bgm_dan02_mvl/mxv
	.byte		N36   , Bn2 , v100
	.byte	W06
	.byte		VOL   , 60*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        66*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        71*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W18
	.byte		        Cs3 
	.byte	W18
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W18
	.byte		        Ds3 
	.byte	W18
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W18
	.byte		        As2 
	.byte	W18
	.byte		        Gs2 
	.byte	W12
	.byte	GOTO
	 .word	bgm_dan02_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_dan02_8:
	.byte	KEYSH , bgm_dan02_key+0
	.byte		VOICE , 0
	.byte		VOL   , 40*bgm_dan02_mvl/mxv
	.byte		N36   , An2 , v064
	.byte	W06
	.byte		VOL   , 47*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        52*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        59*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W06
bgm_dan02_8_B1:
bgm_dan02_8_000:
	.byte		N06   , En1 , v092
	.byte		N72   , Bn2 , v064
	.byte	W12
	.byte		N06   , En1 , v092
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N03   , En1 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v080
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W06
	.byte		        Fs2 , v056
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte	PEND
bgm_dan02_8_001:
	.byte		N06   , En1 , v092
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        En1 , v100
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		        En1 , v080
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v100
	.byte		N06   , Dn3 , v064
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v112
	.byte		N06   , Fs2 , v088
	.byte	W03
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte		N06   , Fs2 , v072
	.byte	W03
	.byte		N03   , En1 , v064
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
bgm_dan02_8_002:
	.byte		N06   , En1 , v092
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N03   , En1 , v052
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v080
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W06
	.byte		        Fs2 , v056
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_dan02_8_001
	.byte	PATT
	 .word	bgm_dan02_8_000
	.byte	PATT
	 .word	bgm_dan02_8_001
	.byte	PATT
	 .word	bgm_dan02_8_002
	.byte		N06   , En1 , v092
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        En1 , v100
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		        En1 , v080
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v100
	.byte		N06   , Dn3 , v064
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        En1 , v064
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
	.byte		N96   , Bn2 , v112
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		VOL   , 40*bgm_dan02_mvl/mxv
	.byte		N36   , An2 , v064
	.byte	W06
	.byte		VOL   , 47*bgm_dan02_mvl/mxv
	.byte	W06
	.byte		        52*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        59*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        73*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        76*bgm_dan02_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dan02_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_dan02_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_dan02:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_dan02_pri	@ Priority
	.byte	bgm_dan02_rev	@ Reverb.

	.word	bgm_dan02_grp

	.word	bgm_dan02_1
	.word	bgm_dan02_2
	.word	bgm_dan02_3
	.word	bgm_dan02_4
	.word	bgm_dan02_5
	.word	bgm_dan02_6
	.word	bgm_dan02_7
	.word	bgm_dan02_8

	.end
