	.include "MPlayDef.s"

	.equ	bgm_dooro_x1_grp, voicegroup_8677138
	.equ	bgm_dooro_x1_pri, 0
	.equ	bgm_dooro_x1_rev, reverb_set+50
	.equ	bgm_dooro_x1_mvl, 127
	.equ	bgm_dooro_x1_key, 0
	.equ	bgm_dooro_x1_tbs, 1
	.equ	bgm_dooro_x1_exg, 0
	.equ	bgm_dooro_x1_cmp, 1

	.section .rodata
	.global	bgm_dooro_x1
	.align	2

@********************** Track  1 **********************@

bgm_dooro_x1_1:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte	TEMPO , 132*bgm_dooro_x1_tbs/2
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte	W12
bgm_dooro_x1_1_B1:
	.byte		VOICE , 60
	.byte		PAN   , c_v-24
	.byte		N12   , Fs2 , v072
	.byte	W18
	.byte		VOICE , 58
	.byte		N06   , Cs2 , v076
	.byte	W18
	.byte		VOICE , 60
	.byte		N12   , Fs2 , v072
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		VOICE , 60
	.byte		N12   , Fs2 
	.byte	W18
	.byte		VOICE , 58
	.byte		N06   , Cs2 , v076
	.byte	W18
	.byte		VOICE , 60
	.byte		N12   , Fs2 , v072
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        As3 , v076
	.byte	W18
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N24   
	.byte	W36
	.byte		VOICE , 48
	.byte		N09   , As3 , v072
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , As3 
	.byte	W12
	.byte		N30   , Gs3 
	.byte	W36
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N44   , Fn3 
	.byte	W24
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        46*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte		N12   , Ds3 , v076
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W36
	.byte		VOICE , 48
	.byte		N09   , Fs4 , v068
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N30   , Fs4 
	.byte	W36
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N42   , Fn4 
	.byte	W30
	.byte		VOL   , 75*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        63*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        25*bgm_dooro_x1_mvl/mxv
	.byte	W09
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte		N12   , As3 , v076
	.byte	W18
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		PAN   , c_v+25
	.byte		N12   , As3 
	.byte	W18
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N21   , Fn3 
	.byte	W12
	.byte		VOL   , 73*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        65*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N21   , Fs3 
	.byte	W12
	.byte		VOL   , 73*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        65*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N21   , Gs3 
	.byte	W12
	.byte		VOL   , 73*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        65*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N21   , Fn3 
	.byte	W12
	.byte		VOL   , 73*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        65*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N12   , Fs3 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N24   , Ds3 
	.byte	W24
	.byte		PAN   , c_v+25
	.byte		N12   , Fs3 
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N24   , Ds3 
	.byte	W24
	.byte		VOICE , 58
	.byte		N03   , Cs2 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		VOICE , 60
	.byte		N06   , Gs2 , v088
	.byte	W12
	.byte		VOICE , 58
	.byte		N03   , Cs2 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N12   , Gs3 , v100
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		VOICE , 46
	.byte		PAN   , c_v-24
	.byte		N06   , Fs3 , v056
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 , v060
	.byte	W06
	.byte		        As3 , v064
	.byte	W06
	.byte		        Fs4 , v052
	.byte	W06
	.byte		        As4 , v056
	.byte	W06
	.byte		        Cs5 , v060
	.byte	W06
	.byte		        As4 , v064
	.byte	W06
	.byte		        Fs5 , v076
	.byte	W06
	.byte		        Fn5 , v072
	.byte	W06
	.byte		        Cs5 , v068
	.byte	W06
	.byte		        As4 , v064
	.byte	W06
	.byte		        Fs4 , v060
	.byte	W06
	.byte		        Fn4 , v056
	.byte	W06
	.byte		        Cs4 , v052
	.byte	W06
	.byte		        As3 , v048
	.byte	W06
	.byte		        Fn3 , v056
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 , v060
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        Fn4 , v052
	.byte	W06
	.byte		        Gs4 , v056
	.byte	W06
	.byte		        Cs5 , v060
	.byte	W06
	.byte		        Gs4 , v064
	.byte	W06
	.byte		        Fn5 , v076
	.byte	W06
	.byte		        Ds5 , v072
	.byte	W06
	.byte		        Cs5 , v068
	.byte	W06
	.byte		        Gs4 , v064
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		        Ds4 , v056
	.byte	W06
	.byte		        Cs4 , v052
	.byte	W06
	.byte		        Gs3 , v048
	.byte	W06
	.byte		        En3 , v056
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 , v060
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        En4 , v052
	.byte	W06
	.byte		        Gs4 , v056
	.byte	W06
	.byte		        Cs5 , v060
	.byte	W06
	.byte		        Gs4 , v064
	.byte	W06
	.byte		        En5 , v076
	.byte	W06
	.byte		        Ds5 , v072
	.byte	W06
	.byte		        Cs5 , v068
	.byte	W06
	.byte		        Gs4 , v064
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		        Ds4 , v056
	.byte	W06
	.byte		        Cs4 , v052
	.byte	W06
	.byte		        Gs3 , v048
	.byte	W06
	.byte		        Ds3 , v056
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 , v060
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Ds4 , v052
	.byte	W06
	.byte		        Fs4 , v056
	.byte	W06
	.byte		        Bn4 , v060
	.byte	W06
	.byte		        Fs4 , v064
	.byte	W06
	.byte		        Ds5 , v076
	.byte	W06
	.byte		        Cs5 , v072
	.byte	W06
	.byte		        Bn4 , v068
	.byte	W06
	.byte		        Fs4 , v064
	.byte	W06
	.byte		        Ds4 , v060
	.byte	W06
	.byte		        Cs4 , v056
	.byte	W06
	.byte		        Bn3 , v052
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_dooro_x1_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_dooro_x1_2:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte		LFOS  , 28
	.byte	W12
bgm_dooro_x1_2_B1:
	.byte		VOICE , 60
	.byte		N24   , Fs3 , v108
	.byte	W30
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N21   , Fs4 
	.byte	W24
	.byte		N09   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOL   , 77*bgm_dooro_x1_mvl/mxv
	.byte		N90   , Gs3 
	.byte	W05
	.byte		VOL   , 70*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        63*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        59*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        64*bgm_dooro_x1_mvl/mxv
	.byte	W01
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 68*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        71*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        73*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        77*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        78*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W30
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N21   , Fs4 
	.byte	W24
	.byte		N09   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOL   , 77*bgm_dooro_x1_mvl/mxv
	.byte		N90   , Gs4 
	.byte	W05
	.byte		VOL   , 70*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        63*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        59*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        64*bgm_dooro_x1_mvl/mxv
	.byte	W01
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 68*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        71*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        73*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        77*bgm_dooro_x1_mvl/mxv
	.byte	W05
	.byte		        78*bgm_dooro_x1_mvl/mxv
	.byte	W07
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte	W06
	.byte		VOICE , 56
	.byte		N12   , As4 
	.byte	W18
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N24   
	.byte	W09
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N30   , Fn4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N36   , Cs4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W21
	.byte		        0
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W18
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W09
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W12
	.byte		N09   , Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N30   , As4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N42   , Gs4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W24
	.byte	W03
	.byte		        0
	.byte	W06
	.byte		N12   , As4 
	.byte	W18
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N24   
	.byte	W09
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N30   , Fn4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W09
	.byte		        0
	.byte		N24   , Gs4 
	.byte	W09
	.byte		MOD   , 4
	.byte	W15
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W18
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W09
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N30   , Fn4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W18
	.byte		        0
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N44   , Gs4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte	W03
	.byte		VOICE , 60
	.byte		N12   , As3 
	.byte	W18
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N30   , Cs4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W15
	.byte		        0
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N32   , Gs3 
	.byte	W36
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N42   , Cs3 
	.byte	W15
	.byte		MOD   , 4
	.byte	W24
	.byte	W03
	.byte		        0
	.byte	W06
	.byte		N12   , As3 
	.byte	W18
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N30   , Cs4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W15
	.byte		        0
	.byte	W06
	.byte		N09   , Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N32   , Ds4 
	.byte	W36
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N44   , Bn3 
	.byte	W15
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte	W03
	.byte		VOICE , 56
	.byte		N12   
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N32   , Dn4 
	.byte	W12
	.byte		MOD   , 3
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N09   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N36   , Cs4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W21
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N42   , As3 
	.byte	W12
	.byte		MOD   , 3
	.byte	W30
	.byte		        0
	.byte	W06
	.byte		N09   , Gs3 
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
	.byte		N68   , Bn3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W44
	.byte	W01
	.byte		        0
	.byte	W03
	.byte		N12   , Cs4 
	.byte	W18
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N68   , Fn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W44
	.byte	W01
	.byte		        0
	.byte	W03
	.byte	GOTO
	 .word	bgm_dooro_x1_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_dooro_x1_3:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte	W12
bgm_dooro_x1_3_B1:
	.byte	W96
	.byte		VOICE , 14
	.byte		PAN   , c_v+8
	.byte		N18   , Cs4 , v056
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W48
	.byte	W96
	.byte		N18   , Fn4 
	.byte	W18
	.byte		        Ds4 
	.byte	W18
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W48
	.byte	W96
	.byte		VOICE , 58
	.byte		PAN   , c_v+24
	.byte		N03   , Cs2 , v060
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
	.byte	W24
	.byte		VOICE , 60
	.byte		N24   , Cs3 , v064
	.byte	W03
	.byte		VOL   , 64*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        67*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        70*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        73*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W09
	.byte		N12   , Bn2 
	.byte	W18
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N24   , Ds3 
	.byte	W72
	.byte		VOICE , 58
	.byte		N03   , Cs2 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		VOICE , 60
	.byte		N06   , Cs3 , v064
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W24
	.byte	W96
	.byte		VOICE , 46
	.byte		PAN   , c_v-24
	.byte		N06   , Cs3 , v076
	.byte	W06
	.byte		        Fn3 , v056
	.byte	W06
	.byte		        Gs3 , v060
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 , v068
	.byte	W06
	.byte		        Gs4 , v072
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs3 , v076
	.byte	W06
	.byte		        Cs4 , v056
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 , v060
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Gs4 , v068
	.byte	W06
	.byte		        Cs5 , v072
	.byte	W06
	.byte		        Gs5 , v076
	.byte	W06
	.byte		VOICE , 60
	.byte		PAN   , c_v+24
	.byte		N12   , Ds3 , v064
	.byte	W18
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N24   , Bn2 
	.byte	W36
	.byte		VOICE , 48
	.byte		PAN   , c_v-24
	.byte		N09   , Bn3 , v068
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N30   , Cs4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N44   , Fn4 
	.byte	W24
	.byte	W03
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        59*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        43*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W48
	.byte		VOICE , 14
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N18   , Gs3 , v072
	.byte	W18
	.byte		        Fn4 , v056
	.byte	W18
	.byte		N12   , Cs4 , v072
	.byte	W12
	.byte		N36   , En4 
	.byte	W60
	.byte		VOICE , 48
	.byte		PAN   , c_v-24
	.byte		N09   , En4 , v052
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N32   , Bn4 
	.byte	W36
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N44   , Fs4 
	.byte	W48
	.byte	W24
	.byte		VOICE , 14
	.byte		PAN   , c_v-16
	.byte		N48   , Fs4 , v072
	.byte	W60
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N36   , Fs4 
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte		VOICE , 48
	.byte		PAN   , c_v-24
	.byte		N09   , Cs3 
	.byte	W18
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N68   , Gs3 
	.byte	W72
	.byte		N12   
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
	.byte		N68   , Bn3 
	.byte	W72
	.byte	GOTO
	 .word	bgm_dooro_x1_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_dooro_x1_4:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte		LFOS  , 28
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte	W12
bgm_dooro_x1_4_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v+48
	.byte		N12   , Cs3 , v052
	.byte	W24
	.byte		N06   , As2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Gs2 
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W24
	.byte		N06   , As2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W24
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
bgm_dooro_x1_4_000:
	.byte		N12   , Fs4 , v052
	.byte	W18
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N30   
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N09   , Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte	PEND
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		VOICE , 4
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		VOICE , 80
	.byte		N12   , Bn3 
	.byte	W18
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N30   , Ds4 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N09   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro_x1_4_000
	.byte		N03   , Gs2 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W18
	.byte		N15   , Fn3 
	.byte	W18
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W18
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N30   , Bn3 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N09   , Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		VOL   , 61*bgm_dooro_x1_mvl/mxv
	.byte		N48   , Fn3 , v060
	.byte	W09
	.byte		VOL   , 63*bgm_dooro_x1_mvl/mxv
	.byte	W09
	.byte		        66*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W12
	.byte		N12   , Fs3 , v052
	.byte	W24
	.byte		N06   , As2 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , As2 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W24
	.byte		N06   , Gs2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte		N06   , Gs2 
	.byte	W12
	.byte		N12   , En3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Gs2 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N12   , Ds3 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W36
	.byte		N12   , Dn3 , v040
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N32   , Fs3 
	.byte	W12
	.byte		MOD   , 3
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N09   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N36   , As3 
	.byte	W15
	.byte		MOD   , 3
	.byte	W21
	.byte		        0
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N42   , Fs3 
	.byte	W12
	.byte		MOD   , 3
	.byte	W30
	.byte		        0
	.byte	W06
	.byte		N03   , Gs2 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		VOL   , 63*bgm_dooro_x1_mvl/mxv
	.byte		N36   , Cs3 , v060
	.byte	W09
	.byte		VOL   , 66*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W09
	.byte	GOTO
	 .word	bgm_dooro_x1_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_dooro_x1_5:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte	W12
bgm_dooro_x1_5_B1:
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , As2 , v052
	.byte	W24
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N12   , As2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W24
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N12   , As2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W24
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W24
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
bgm_dooro_x1_5_000:
	.byte		N12   , Cs4 , v052
	.byte	W18
	.byte		N03   , As3 
	.byte	W06
	.byte		N30   
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N09   , As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte	PEND
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		VOICE , 5
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		VOICE , 82
	.byte		N12   , Fs3 
	.byte	W18
	.byte		N03   , As3 
	.byte	W06
	.byte		N30   , Bn3 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N09   , Fs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W18
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N24   , Cs3 
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro_x1_5_000
	.byte		N03   , Fn2 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W18
	.byte		N15   , Cs3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W18
	.byte		N03   , As3 
	.byte	W06
	.byte		N30   , Fs3 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        35*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N09   , Fs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOL   , 61*bgm_dooro_x1_mvl/mxv
	.byte		N12   , Cs3 , v060
	.byte	W09
	.byte		VOL   , 63*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		VOICE , 83
	.byte		N12   
	.byte	W06
	.byte		VOL   , 66*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Cs3 , v052
	.byte	W24
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   , En2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W24
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W24
	.byte		N36   , Ds3 
	.byte	W36
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v-3
	.byte		N12   , Dn3 , v020
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		VOICE , 82
	.byte		N09   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , Fs2 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		VOL   , 63*bgm_dooro_x1_mvl/mxv
	.byte		N36   , Bn2 , v060
	.byte	W09
	.byte		VOL   , 66*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W09
	.byte	GOTO
	 .word	bgm_dooro_x1_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_dooro_x1_6:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte	W12
bgm_dooro_x1_6_B1:
bgm_dooro_x1_6_000:
	.byte		N12   , Fs1 , v080
	.byte	W24
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte	PEND
	.byte		        Cs1 
	.byte	W24
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro_x1_6_000
	.byte		N12   , Cs1 , v080
	.byte	W24
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W24
	.byte		N24   , Gs1 
	.byte	W24
	.byte		N12   , Fn1 
	.byte	W12
bgm_dooro_x1_6_001:
	.byte		N03   , Fs1 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W18
	.byte		        Cs2 
	.byte	W18
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N15   , Gs1 
	.byte	W18
	.byte		N12   , Cs1 
	.byte	W12
bgm_dooro_x1_6_002:
	.byte		N03   , Ds1 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W18
	.byte		N15   , Bn1 
	.byte	W18
	.byte		N12   , Ds1 
	.byte	W12
	.byte	PEND
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N24   , Cs1 
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro_x1_6_001
	.byte		N03   , Fn1 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W18
	.byte		N15   , Gs1 
	.byte	W18
	.byte		N12   , Cs1 
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro_x1_6_002
	.byte		N03   , Cs1 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W48
	.byte	PATT
	 .word	bgm_dooro_x1_6_000
	.byte		N12   , Fn1 , v080
	.byte	W24
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W18
	.byte		        Fs1 
	.byte	W18
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N12   , En1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W24
	.byte		N36   , Bn1 
	.byte	W36
	.byte		N18   , Fs2 
	.byte	W18
	.byte		        Fn2 
	.byte	W18
	.byte		N12   , En2 
	.byte	W12
	.byte		N18   , Dn2 
	.byte	W18
	.byte		        Cs2 
	.byte	W18
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W18
	.byte		        Gs1 
	.byte	W18
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N18   , As1 
	.byte	W18
	.byte		        Gs1 
	.byte	W18
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N03   , Cs1 
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
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N03   , Cs1 
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
	.byte	W12
	.byte		N36   , Gs1 
	.byte	W36
	.byte	GOTO
	 .word	bgm_dooro_x1_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_dooro_x1_7:
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v-8
	.byte		N06   , Bn1 , v108
	.byte	W12
bgm_dooro_x1_7_B1:
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte		N12   , Fs2 , v124
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
bgm_dooro_x1_7_000:
	.byte		N12   , Cs2 , v124
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte		        Fs2 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro_x1_7_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		PAN   , c_v-24
	.byte		N12   , Fs4 , v052
	.byte	W36
	.byte		N09   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N32   , Fn4 
	.byte	W36
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W36
	.byte		N09   
	.byte	W60
	.byte	W60
	.byte		VOICE , 47
	.byte		PAN   , c_v-8
	.byte		N03   , Bn1 , v092
	.byte	W03
	.byte		        Bn1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Bn1 , v084
	.byte	W03
	.byte		        Bn1 , v088
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Bn1 , v092
	.byte	W03
	.byte		        Bn1 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Bn1 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Bn1 , v104
	.byte	W03
	.byte		N24   , Fs2 , v124
	.byte	W84
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N24   , Fs2 , v124
	.byte	W96
	.byte		        Cs2 
	.byte	W36
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , Cs2 , v124
	.byte	W36
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , Cs2 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs2 , v124
	.byte	W12
	.byte		N03   , Cs2 , v092
	.byte	W03
	.byte		        Cs2 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Cs2 , v084
	.byte	W03
	.byte		        Cs2 , v088
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Cs2 , v092
	.byte	W03
	.byte		        Cs2 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Cs2 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Cs2 , v104
	.byte	W03
	.byte	GOTO
	 .word	bgm_dooro_x1_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_dooro_x1_8:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte	W12
bgm_dooro_x1_8_B1:
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte		N48   , Bn2 , v092
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		VOL   , 40*bgm_dooro_x1_mvl/mxv
	.byte		N36   , An2 , v064
	.byte	W06
	.byte		VOL   , 47*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        52*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        59*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        73*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        76*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		N96   , Bn2 , v092
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N60   
	.byte	W60
	.byte		VOL   , 40*bgm_dooro_x1_mvl/mxv
	.byte		N36   , An2 , v064
	.byte	W06
	.byte		VOL   , 47*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte		        52*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        59*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        73*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        76*bgm_dooro_x1_mvl/mxv
	.byte	W03
	.byte		        80*bgm_dooro_x1_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_dooro_x1_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_dooro_x1_9:
	.byte	KEYSH , bgm_dooro_x1_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_dooro_x1_mvl/mxv
	.byte	W12
bgm_dooro_x1_9_B1:
bgm_dooro_x1_9_000:
	.byte	W18
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x1_9_000
	.byte	PATT
	 .word	bgm_dooro_x1_9_000
	.byte	PATT
	 .word	bgm_dooro_x1_9_000
bgm_dooro_x1_9_001:
	.byte		N06   , En1 , v080
	.byte	W18
	.byte		        En1 , v056
	.byte	W06
	.byte		        En1 , v116
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v056
	.byte	W06
	.byte		        En1 , v060
	.byte	W12
	.byte		        En1 , v116
	.byte	W12
	.byte		        En1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
bgm_dooro_x1_9_002:
	.byte		N06   , En1 , v080
	.byte	W18
	.byte		        En1 , v056
	.byte	W06
	.byte		        En1 , v116
	.byte	W12
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v056
	.byte	W06
	.byte		        En1 , v060
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v116
	.byte	W12
	.byte		        En1 , v080
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x1_9_001
	.byte	PATT
	 .word	bgm_dooro_x1_9_002
	.byte	PATT
	 .word	bgm_dooro_x1_9_001
	.byte	PATT
	 .word	bgm_dooro_x1_9_002
	.byte	PATT
	 .word	bgm_dooro_x1_9_001
	.byte		N06   , En1 , v080
	.byte	W18
	.byte		        En1 , v056
	.byte	W06
	.byte		        En1 , v116
	.byte	W12
	.byte		        En1 , v060
	.byte	W06
	.byte		        En1 , v056
	.byte	W06
	.byte		        En1 , v116
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_dooro_x1_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_dooro_x1:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_dooro_x1_pri	@ Priority
	.byte	bgm_dooro_x1_rev	@ Reverb.

	.word	bgm_dooro_x1_grp

	.word	bgm_dooro_x1_1
	.word	bgm_dooro_x1_2
	.word	bgm_dooro_x1_3
	.word	bgm_dooro_x1_4
	.word	bgm_dooro_x1_5
	.word	bgm_dooro_x1_6
	.word	bgm_dooro_x1_7
	.word	bgm_dooro_x1_8
	.word	bgm_dooro_x1_9

	.end
