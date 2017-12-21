	.include "MPlayDef.s"

	.equ	bgm_dooro_x3_grp, voicegroup_8678428
	.equ	bgm_dooro_x3_pri, 0
	.equ	bgm_dooro_x3_rev, reverb_set+50
	.equ	bgm_dooro_x3_mvl, 127
	.equ	bgm_dooro_x3_key, 0
	.equ	bgm_dooro_x3_tbs, 1
	.equ	bgm_dooro_x3_exg, 0
	.equ	bgm_dooro_x3_cmp, 1

	.section .rodata
	.global	bgm_dooro_x3
	.align	2

@********************** Track  1 **********************@

bgm_dooro_x3_1:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_1_B1:
	.byte	TEMPO , 134*bgm_dooro_x3_tbs/2
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N88   , An1 , v080
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N72   , Gn1 
	.byte	W80
	.byte		VOICE , 83
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOICE , 81
	.byte		N96   
	.byte	W96
	.byte		N88   , Fn1 
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N88   , En1 
	.byte	W96
	.byte		N96   
	.byte	W96
bgm_dooro_x3_1_000:
	.byte		N12   , An1 , v080
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_1_000
bgm_dooro_x3_1_001:
	.byte		N12   , Gn1 , v080
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_1_001
bgm_dooro_x3_1_002:
	.byte		N12   , Fn1 , v080
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_1_002
	.byte		N12   , En1 , v080
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		N16   , Bn1 
	.byte	W16
	.byte		        En1 
	.byte	W16
	.byte		        Gs1 
	.byte	W16
bgm_dooro_x3_1_003:
	.byte		VOICE , 83
	.byte		N36   , An1 , v080
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N28   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
bgm_dooro_x3_1_004:
	.byte		N36   , Gs1 , v080
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		VOICE , 81
	.byte		N12   
	.byte	W16
	.byte		        En2 
	.byte	W16
	.byte		N16   , Cs2 
	.byte	W16
	.byte	PEND
bgm_dooro_x3_1_005:
	.byte		VOICE , 83
	.byte		N36   , Gn1 , v080
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N28   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
bgm_dooro_x3_1_006:
	.byte		N36   , Fs1 , v080
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		VOICE , 81
	.byte		N12   
	.byte	W16
	.byte		        Dn2 
	.byte	W16
	.byte		N16   , Bn1 
	.byte	W16
	.byte	PEND
bgm_dooro_x3_1_007:
	.byte		VOICE , 83
	.byte		N36   , Fn1 , v080
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N28   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
bgm_dooro_x3_1_008:
	.byte		N36   , En1 , v080
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		VOICE , 81
	.byte		N12   
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		N16   , An1 
	.byte	W16
	.byte	PEND
	.byte		VOICE , 83
	.byte		N36   , Fs1 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		VOICE , 81
	.byte		N12   , An1 
	.byte	W16
	.byte		        Gs1 
	.byte	W16
	.byte		N16   , Fs1 
	.byte	W16
	.byte		VOICE , 83
	.byte		N36   , En1 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		VOICE , 81
	.byte		N12   
	.byte	W16
	.byte		        Fs1 
	.byte	W16
	.byte		N16   , Gs1 
	.byte	W16
	.byte	PATT
	 .word	bgm_dooro_x3_1_003
	.byte	PATT
	 .word	bgm_dooro_x3_1_004
	.byte	PATT
	 .word	bgm_dooro_x3_1_005
	.byte	PATT
	 .word	bgm_dooro_x3_1_006
	.byte	PATT
	 .word	bgm_dooro_x3_1_007
	.byte	PATT
	 .word	bgm_dooro_x3_1_008
	.byte		VOICE , 83
	.byte		N28   , En2 , v080
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N32   
	.byte	W32
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N48   , En2 
	.byte	W48
	.byte		VOICE , 81
	.byte		N12   , En1 
	.byte	W16
	.byte		        Fs1 
	.byte	W16
	.byte		N16   , Gs1 
	.byte	W16
	.byte	GOTO
	 .word	bgm_dooro_x3_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_dooro_x3_2:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_2_B1:
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v-9
	.byte	W24
	.byte		N24   , En4 , v096
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N44   , Gn3 
	.byte	W18
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 73*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Bn3 
	.byte	W16
	.byte		        Cs4 
	.byte	W16
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N32   , Bn3 
	.byte	W18
	.byte		VOL   , 73*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N36   , An3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N80   , An3 
	.byte	W24
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W02
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 63*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        57*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        41*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        35*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        24*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        18*bgm_dooro_x3_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 13*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        8*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        2*bgm_dooro_x3_mvl/mxv
	.byte	W02
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N12   , Fn3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		N44   , Bn3 
	.byte	W18
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 73*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		N92   , Bn3 
	.byte	W24
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W02
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 63*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        57*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        58*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        65*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        75*bgm_dooro_x3_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 77*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte	W07
	.byte		VOICE , 56
	.byte	W24
	.byte		N24   , En4 , v108
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N20   , Bn3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W08
	.byte		        0
	.byte	W04
	.byte		N20   , Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W08
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte	W04
	.byte		TIE   , Bn3 
	.byte	W48
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        63*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        57*bgm_dooro_x3_mvl/mxv
	.byte	W04
bgm_dooro_x3_2_000:
	.byte	W01
	.byte		VOL   , 52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        41*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        35*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        24*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        18*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        13*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        8*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        2*bgm_dooro_x3_mvl/mxv
	.byte	W02
	.byte	PEND
	.byte		EOT   , Bn3 
	.byte		MOD   , 0
	.byte	W08
	.byte		VOICE , 46
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v-23
	.byte		N04   , Gn3 , v044
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Gn5 
	.byte	W24
	.byte		VOICE , 56
	.byte		PAN   , c_v-10
	.byte		N24   , Fn4 , v108
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N20   , En4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W08
	.byte		        0
	.byte	W04
	.byte		N20   , Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte	W04
	.byte		TIE   , En4 
	.byte	W48
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        63*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        57*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte	PATT
	 .word	bgm_dooro_x3_2_000
	.byte		EOT   , En4 
	.byte		MOD   , 0
	.byte	W08
	.byte		VOICE , 46
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N04   , Bn3 , v044
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Gs5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		VOICE , 56
	.byte		PAN   , c_v-9
	.byte		N28   , An3 , v108
	.byte	W15
	.byte		MOD   , 5
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N12   , An4 
	.byte	W16
	.byte		        Gs4 
	.byte	W16
	.byte		N16   , An4 
	.byte	W16
	.byte		N84   , En4 
	.byte	W36
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 71*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        62*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        29*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        13*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        6*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N28   
	.byte	W15
	.byte		MOD   , 5
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N12   , Gn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N84   , Dn4 
	.byte	W36
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 71*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        62*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        29*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        13*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        6*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N28   , Fn4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N12   , Fn4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N28   , An4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N44   , En4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        43*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        34*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        13*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N28   , Fs4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N12   , Dn5 
	.byte	W16
	.byte		        Cs5 
	.byte	W16
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , En5 
	.byte	W15
	.byte		MOD   , 5
	.byte	W01
	.byte		N12   , Dn5 
	.byte	W14
	.byte		MOD   , 0
	.byte	W02
	.byte		N08   , Cs5 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N44   , Bn4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        43*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        34*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        13*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N28   , An3 , v096
	.byte	W15
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N12   , An4 
	.byte	W16
	.byte		        Gs4 
	.byte	W16
	.byte		N16   , An4 
	.byte	W16
	.byte		N84   , En4 
	.byte	W36
	.byte		MOD   , 3
	.byte	W24
	.byte	W03
	.byte		VOL   , 78*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        60*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N28   
	.byte	W15
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N12   , Gn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N88   , Fs4 
	.byte	W36
	.byte		MOD   , 3
	.byte	W24
	.byte	W03
	.byte		VOL   , 78*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        60*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N28   , Fn4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N12   , An4 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		N16   , An4 
	.byte	W16
	.byte		N28   , Cs5 
	.byte	W15
	.byte		MOD   , 3
	.byte	W15
	.byte		        0
	.byte	W02
	.byte		N08   , Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		N44   , An4 
	.byte	W15
	.byte		MOD   , 3
	.byte	W09
	.byte		VOL   , 78*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        60*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N32   , Bn4 
	.byte	W32
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		N12   , An4 
	.byte	W16
	.byte		        Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N28   , Bn4 
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		VOL   , 77*bgm_dooro_x3_mvl/mxv
	.byte		N44   , Dn5 
	.byte	W06
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		MOD   , 3
	.byte		VOL   , 72*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        75*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        78*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W03
	.byte	GOTO
	 .word	bgm_dooro_x3_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_dooro_x3_3:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_3_B1:
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Cs3 , v052
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N16   
	.byte	W16
	.byte		VOICE , 82
	.byte	W08
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W16
	.byte		        An2 
	.byte	W16
	.byte		        Gn2 
	.byte	W16
	.byte		N24   , Bn2 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N28   , Gn2 
	.byte	W36
	.byte		        An2 
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N16   
	.byte	W16
	.byte		VOICE , 82
	.byte	W08
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Cn3 
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		        An2 
	.byte	W16
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W04
	.byte		N12   
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		        Gs2 , v060
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 7
	.byte		PAN   , c_v+1
	.byte		BEND  , c_v-4
	.byte	W04
	.byte		N08   , An2 , v032
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W04
	.byte	W04
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W04
	.byte	W04
	.byte		        Gn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W04
	.byte	W04
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W04
	.byte	W04
	.byte		        Fn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W04
	.byte	W04
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        An2 
	.byte	W04
	.byte	W04
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W04
	.byte	W04
	.byte		        Gs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N04   , Gs2 
	.byte	W04
	.byte		VOICE , 82
	.byte		PAN   , c_v+47
	.byte		N16   , En2 , v056
	.byte	W16
	.byte		        Gs2 
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		BEND  , c_v+0
	.byte		N12   , Cs3 , v044
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W04
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W08
	.byte		PAN   , c_v+0
	.byte	W08
	.byte		VOICE , 5
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		BEND  , c_v-4
	.byte		N08   , Gs4 , v032
	.byte	W08
	.byte		BEND  , c_v-2
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N04   , En5 
	.byte	W04
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+0
	.byte		N12   , Cs3 , v044
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N12   , An2 , v048
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		N08   , Cs3 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N24   , An2 
	.byte	W04
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W08
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte	W08
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		BEND  , c_v-4
	.byte		N08   , Fs4 , v032
	.byte	W08
	.byte		BEND  , c_v-2
	.byte		N08   , An4 
	.byte	W08
	.byte		N04   , Dn5 
	.byte	W04
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+0
	.byte		N12   , An2 , v044
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N12   , An2 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   , An2 , v056
	.byte	W04
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W08
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte	W08
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		BEND  , c_v-4
	.byte		N08   , En4 , v032
	.byte	W08
	.byte		BEND  , c_v-2
	.byte		N08   , An4 
	.byte	W08
	.byte		N04   , Cs5 
	.byte	W04
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+0
	.byte		N12   , Fs3 , v064
	.byte	W12
	.byte		VOICE , 84
	.byte		N16   
	.byte	W08
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N04   , En3 
	.byte	W04
	.byte		VOICE , 82
	.byte	W04
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		        Gs3 
	.byte	W16
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N12   , Gs3 
	.byte	W12
	.byte		VOICE , 84
	.byte		N16   
	.byte	W08
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		VOICE , 82
	.byte		VOL   , 36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N12   , An3 , v044
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Cs3 , v056
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N12   , Cs3 , v044
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N12   , An2 
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		N08   , Cs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N12   , An3 , v056
	.byte	W16
	.byte		        Fs3 
	.byte	W16
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N12   , An2 , v044
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N08   
	.byte	W08
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N12   , An2 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N08   , An2 , v024
	.byte	W08
	.byte		N04   , An2 , v044
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W08
	.byte		N12   , Cs3 
	.byte	W16
	.byte		        An2 
	.byte	W16
	.byte		N16   , En2 
	.byte	W16
	.byte		N12   , An2 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N16   
	.byte	W24
	.byte		VOICE , 82
	.byte		N12   , Gs2 
	.byte	W12
	.byte		VOICE , 84
	.byte		N12   
	.byte	W12
	.byte		N16   
	.byte	W16
	.byte		VOICE , 82
	.byte	W08
	.byte		N12   , Dn3 , v060
	.byte	W16
	.byte		        Cs3 
	.byte	W16
	.byte		N16   , Bn2 
	.byte	W16
	.byte	GOTO
	 .word	bgm_dooro_x3_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_dooro_x3_4:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_4_B1:
	.byte		VOICE , 80
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v-48
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N88   , En3 , v052
	.byte	W96
	.byte		N72   
	.byte	W72
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W16
	.byte		        Cs3 
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		N24   , Dn3 
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N28   , Bn2 
	.byte	W36
	.byte		        Cs3 
	.byte	W36
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N88   , Cn3 
	.byte	W96
	.byte		N48   
	.byte	W48
	.byte		N12   , Fn3 
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		        Dn3 
	.byte	W16
	.byte		N44   , En3 
	.byte	W48
	.byte		N12   , Bn2 
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N96   , Bn2 , v060
	.byte	W96
	.byte		VOICE , 6
	.byte		PAN   , c_v+0
	.byte		N08   , An2 , v056
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N16   , Gs2 , v064
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		        Dn3 
	.byte	W16
	.byte		N32   , En3 , v052
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N32   , En3 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W04
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W08
	.byte		VOICE , 4
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , Gs4 , v056
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N32   , En3 , v052
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N12   , Dn3 , v060
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N24   , Dn3 , v056
	.byte	W04
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		VOICE , 4
	.byte		PAN   , c_v+1
	.byte	W08
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N32   , Dn3 , v052
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N32   , Cs3 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   , Cs3 , v056
	.byte	W04
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        45*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte	W08
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , En4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N28   , An3 , v064
	.byte	W20
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		N16   , An3 
	.byte	W16
	.byte		N28   , Bn3 
	.byte	W20
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		        Cs4 
	.byte	W16
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N32   , Cs4 , v052
	.byte	W40
	.byte		N04   , En3 
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N32   , En3 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N12   , En3 , v064
	.byte	W16
	.byte		        Gs3 
	.byte	W16
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N32   , En3 , v052
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N12   , Dn3 
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		N08   , Fs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N12   , Dn4 , v064
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N32   , Dn3 , v052
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        36*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N08   , An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N08   , Cs3 , v024
	.byte	W08
	.byte		N04   , Cs3 , v052
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N12   , En3 , v056
	.byte	W16
	.byte		        Cs3 
	.byte	W16
	.byte		N16   , An2 
	.byte	W16
	.byte		N24   , Bn2 , v052
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N40   
	.byte	W48
	.byte		N40   
	.byte	W48
	.byte		N12   , Fs3 , v068
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		N16   , Dn3 
	.byte	W16
	.byte	GOTO
	 .word	bgm_dooro_x3_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_dooro_x3_5:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_5_B1:
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N96   , An2 , v092
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	GOTO
	 .word	bgm_dooro_x3_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_dooro_x3_6:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_6_B1:
	.byte		VOICE , 46
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
bgm_dooro_x3_6_000:
	.byte		N04   , An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_6_000
	.byte	PATT
	 .word	bgm_dooro_x3_6_000
bgm_dooro_x3_6_001:
	.byte		N04   , An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_6_001
	.byte		N04   , An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v052
	.byte	W04
	.byte		        An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W04
	.byte		        Gs4 , v052
	.byte	W04
	.byte		        An4 , v064
	.byte	W04
	.byte		        An4 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        En5 , v064
	.byte	W04
	.byte		        En5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v052
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v052
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W04
	.byte		        Gs4 , v052
	.byte	W04
	.byte	W96
	.byte	W96
	.byte		VOICE , 56
	.byte	W24
	.byte		PAN   , c_v+10
	.byte		N04   , Gn4 , v088
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Dn5 
	.byte	W16
	.byte		        Cs5 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N68   , Bn4 
	.byte	W28
	.byte		MOD   , 6
	.byte	W05
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        56*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        44*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        32*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        19*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        6*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        0*bgm_dooro_x3_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N08   , Dn2 , v124
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W04
	.byte		        Bn1 
	.byte	W04
	.byte		N12   , Fn2 
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		VOICE , 56
	.byte		PAN   , c_v+10
	.byte		N04   , An4 , v088
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Bn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		        Fs4 
	.byte	W16
	.byte		N48   , Gs4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W06
	.byte		VOL   , 73*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        56*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        44*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        32*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		MOD   , 0
	.byte		N08   , Bn1 , v092
	.byte	W16
	.byte		        Bn1 , v100
	.byte	W08
	.byte		PAN   , c_v+0
	.byte	W08
	.byte		N08   , Bn1 , v112
	.byte	W16
	.byte		N12   , En2 , v124
	.byte	W96
	.byte	W48
	.byte		VOICE , 24
	.byte		N04   , Gs3 , v032
	.byte	W08
	.byte		        Cs4 , v048
	.byte	W08
	.byte		        En4 , v060
	.byte	W16
	.byte		VOICE , 47
	.byte		N08   , Cs2 , v116
	.byte	W08
	.byte		        Cs2 , v092
	.byte	W08
	.byte		N12   , En2 , v124
	.byte	W96
	.byte	W48
	.byte		VOICE , 24
	.byte		N04   , Fs3 , v036
	.byte	W08
	.byte		        An3 , v048
	.byte	W08
	.byte		        Dn4 , v060
	.byte	W16
	.byte		VOICE , 47
	.byte		N08   , Dn2 , v124
	.byte	W08
	.byte		        Dn2 , v112
	.byte	W08
	.byte		N12   , Fn2 , v124
	.byte	W96
	.byte	W48
	.byte		VOICE , 24
	.byte		N04   , En3 , v032
	.byte	W08
	.byte		        An3 , v048
	.byte	W08
	.byte		        Cs4 , v060
	.byte	W16
	.byte		VOICE , 47
	.byte		N08   , Cs2 , v116
	.byte	W08
	.byte		        Cs2 , v108
	.byte	W08
	.byte		N12   , Fs2 , v124
	.byte	W80
	.byte		N08   , Cs2 , v116
	.byte	W08
	.byte		        Cs2 , v108
	.byte	W08
	.byte		N12   , En2 , v124
	.byte	W48
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N12   , En2 
	.byte	W48
	.byte		VOICE , 60
	.byte		N12   , Cs4 , v068
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N12   , Gs3 
	.byte	W16
	.byte		N16   , An3 
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		N24   , Gs3 
	.byte	W32
	.byte		VOICE , 47
	.byte		N08   , Cs2 , v124
	.byte	W16
	.byte		N12   , En2 
	.byte	W48
	.byte		VOICE , 60
	.byte		N12   , Bn3 , v068
	.byte	W16
	.byte		        Cs4 
	.byte	W16
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N12   , Dn4 
	.byte	W16
	.byte		        Cs4 
	.byte	W16
	.byte		N16   , An3 
	.byte	W16
	.byte		N24   , Dn3 
	.byte	W24
	.byte		VOICE , 47
	.byte	W08
	.byte		N08   , Dn2 , v124
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N12   , Fn2 
	.byte	W48
	.byte		VOICE , 60
	.byte		N12   , Fn3 , v068
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N28   , An3 
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N32   , En3 
	.byte	W32
	.byte		VOICE , 47
	.byte		N08   , Fs2 , v124
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		N12   , En2 
	.byte	W48
	.byte		N12   
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N12   , En2 
	.byte	W56
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        En2 , v108
	.byte	W08
	.byte		        Bn1 , v096
	.byte	W08
	.byte		        En2 , v108
	.byte	W08
	.byte		        Bn1 , v124
	.byte	W08
	.byte	GOTO
	 .word	bgm_dooro_x3_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_dooro_x3_7:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_7_B1:
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , En2 , v124
	.byte	W96
	.byte	W96
	.byte		VOICE , 56
	.byte		PAN   , c_v+10
	.byte		N12   , Gn3 , v084
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		N84   , Dn4 
	.byte	W24
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		MOD   , 6
	.byte	W05
	.byte		VOL   , 76*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        61*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        56*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte	W02
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        44*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        35*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        22*bgm_dooro_x3_mvl/mxv
	.byte	W07
	.byte		        15*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        6*bgm_dooro_x3_mvl/mxv
	.byte	W08
	.byte		        0*bgm_dooro_x3_mvl/mxv
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v+1
	.byte		MOD   , 0
	.byte		N12   , Bn1 , v120
	.byte	W24
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		        Dn2 , v096
	.byte	W08
	.byte		N04   , Bn1 , v092
	.byte	W04
	.byte		        Dn2 , v096
	.byte	W04
	.byte		N12   , Fn2 , v124
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v+10
	.byte		N12   , An3 , v084
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		N72   , Cn4 
	.byte	W32
	.byte		MOD   , 6
	.byte	W08
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        34*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        21*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        8*bgm_dooro_x3_mvl/mxv
	.byte	W19
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		MOD   , 0
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , Cn2 , v096
	.byte	W04
	.byte		        Cn2 , v092
	.byte	W04
	.byte		N08   , En2 , v124
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v+10
	.byte		N12   , Gs4 , v084
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		        Fs4 
	.byte	W16
	.byte		N72   , Gs4 
	.byte	W36
	.byte		VOL   , 77*bgm_dooro_x3_mvl/mxv
	.byte		MOD   , 6
	.byte	W05
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        42*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        30*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        18*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        6*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N08   , Bn1 , v124
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N16   , En2 
	.byte	W64
	.byte		VOICE , 48
	.byte		PAN   , c_v-10
	.byte		N08   , An2 , v068
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N96   
	.byte	W05
	.byte		VOL   , 71*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W01
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        56*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        58*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        60*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        63*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        65*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        67*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        70*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        72*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        76*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        78*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N96   , Cn3 
	.byte	W42
	.byte		VOL   , 78*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        75*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        64*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        57*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        50*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        47*bgm_dooro_x3_mvl/mxv
	.byte	W09
	.byte		N96   , An2 
	.byte	W15
	.byte		VOL   , 52*bgm_dooro_x3_mvl/mxv
	.byte	W01
	.byte		        51*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        56*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        58*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        60*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        63*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        65*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        67*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        70*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        72*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        76*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        78*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte		N24   , En2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N12   , Gs2 , v088
	.byte	W16
	.byte		        Bn2 
	.byte	W16
	.byte		        Fs3 
	.byte	W16
	.byte		N48   , Gs3 
	.byte	W48
	.byte	W72
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N24   , An3 , v068
	.byte	W24
	.byte		VOL   , 50*bgm_dooro_x3_mvl/mxv
	.byte		N44   , Gs3 
	.byte	W03
	.byte		VOL   , 52*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        54*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        55*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        58*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        60*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        63*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        69*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        77*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte	W09
	.byte		N12   , An3 
	.byte	W16
	.byte		        Gs3 
	.byte	W16
	.byte		N16   , An3 
	.byte	W16
	.byte		VOL   , 42*bgm_dooro_x3_mvl/mxv
	.byte		N68   , Gn3 
	.byte	W05
	.byte		VOL   , 47*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        53*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        59*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        65*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        77*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte	W08
	.byte		        75*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        71*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        64*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        52*bgm_dooro_x3_mvl/mxv
	.byte	W05
	.byte		        37*bgm_dooro_x3_mvl/mxv
	.byte	W09
	.byte		        56*bgm_dooro_x3_mvl/mxv
	.byte		N24   , En3 
	.byte	W04
	.byte		VOL   , 66*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        73*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        80*bgm_dooro_x3_mvl/mxv
	.byte	W12
	.byte		N12   , An3 
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N44   , An3 
	.byte	W24
	.byte		VOL   , 68*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        60*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        55*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        44*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        31*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		        19*bgm_dooro_x3_mvl/mxv
	.byte	W04
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N28   
	.byte	W32
	.byte		N08   , Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N12   , An3 
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		N16   , An3 
	.byte	W16
	.byte		N28   , Cs4 
	.byte	W32
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N44   , An3 
	.byte	W18
	.byte		VOL   , 74*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dooro_x3_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        43*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        34*bgm_dooro_x3_mvl/mxv
	.byte	W03
	.byte		        13*bgm_dooro_x3_mvl/mxv
	.byte	W09
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		PAN   , c_v-10
	.byte		N28   , Dn3 , v076
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		        En3 
	.byte	W16
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N28   , En3 
	.byte	W32
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N08   , Bn2 , v064
	.byte	W08
	.byte		        Cs3 , v068
	.byte	W08
	.byte		        Dn3 , v072
	.byte	W08
	.byte		        En3 , v080
	.byte	W08
	.byte		        Fs3 , v084
	.byte	W08
	.byte		        Gs3 , v092
	.byte	W08
	.byte	W96
	.byte	W24
	.byte		VOICE , 46
	.byte		PAN   , c_v-32
	.byte		N04   , Gs5 , v060
	.byte	W04
	.byte		        Gs5 , v044
	.byte	W04
	.byte		        An5 , v060
	.byte	W04
	.byte		        An5 , v044
	.byte	W04
	.byte		        Gs5 , v060
	.byte	W04
	.byte		        Gs5 , v044
	.byte	W04
	.byte		        Fs5 , v068
	.byte	W04
	.byte		        Fs5 , v044
	.byte	W04
	.byte		        Cs5 , v056
	.byte	W04
	.byte		        Cs5 , v044
	.byte	W04
	.byte		        En5 , v068
	.byte	W04
	.byte		        En5 , v044
	.byte	W04
	.byte		        Gs4 , v056
	.byte	W04
	.byte		        Gs4 , v044
	.byte	W04
	.byte		        Cs5 , v068
	.byte	W04
	.byte		        Cs5 , v044
	.byte	W04
	.byte		        En4 , v056
	.byte	W04
	.byte		        En4 , v044
	.byte	W04
	.byte		N08   , En5 , v068
	.byte	W08
	.byte		        En5 , v044
	.byte	W24
	.byte		N04   , En5 , v056
	.byte	W04
	.byte		        En5 , v044
	.byte	W04
	.byte		        Fs5 , v056
	.byte	W04
	.byte		        Fs5 , v044
	.byte	W04
	.byte		N08   , Gn5 , v056
	.byte	W08
	.byte		        Gn5 , v044
	.byte	W08
	.byte		        An5 , v056
	.byte	W08
	.byte		        An5 , v044
	.byte	W08
	.byte		        Gn5 , v056
	.byte	W08
	.byte		        Gn5 , v044
	.byte	W08
	.byte		        Fs5 , v056
	.byte	W08
	.byte		        Fs5 , v044
	.byte	W16
	.byte		N04   , Fs5 , v060
	.byte	W04
	.byte		        Fs5 , v044
	.byte	W04
	.byte		        Gs5 , v060
	.byte	W04
	.byte		        Gs5 , v044
	.byte	W04
	.byte		        Fs5 , v060
	.byte	W04
	.byte		        Fs5 , v044
	.byte	W04
	.byte		        An5 , v068
	.byte	W04
	.byte		        An5 , v044
	.byte	W04
	.byte		        Fs5 , v056
	.byte	W04
	.byte		        Fs5 , v044
	.byte	W04
	.byte		        Gs5 , v068
	.byte	W04
	.byte		        Gs5 , v044
	.byte	W04
	.byte		        Fs5 , v056
	.byte	W04
	.byte		        Fs5 , v044
	.byte	W04
	.byte		        Dn5 , v068
	.byte	W04
	.byte		        Dn5 , v044
	.byte	W04
	.byte		        An4 , v056
	.byte	W04
	.byte		        An4 , v044
	.byte	W04
	.byte		N08   , Fn5 , v068
	.byte	W08
	.byte		        Fn5 , v044
	.byte	W16
	.byte		VOICE , 48
	.byte		PAN   , c_v+32
	.byte		N04   , An5 , v036
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        An5 
	.byte	W16
	.byte		        Fn5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		N08   , An3 , v052
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        An5 
	.byte	W08
	.byte		        Cs6 
	.byte	W08
	.byte		VOICE , 48
	.byte		PAN   , c_v+9
	.byte		N32   , En3 , v072
	.byte	W32
	.byte		N08   , Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N12   , Fs3 
	.byte	W16
	.byte		        Gs3 
	.byte	W16
	.byte		        Fs3 
	.byte	W16
	.byte		N28   , Gs3 
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N44   , Bn3 
	.byte	W48
	.byte	GOTO
	 .word	bgm_dooro_x3_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_dooro_x3_8:
	.byte	KEYSH , bgm_dooro_x3_key+0
bgm_dooro_x3_8_B1:
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_dooro_x3_mvl/mxv
	.byte		N04   , En1 , v096
	.byte	W24
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
bgm_dooro_x3_8_000:
	.byte		N04   , En1 , v096
	.byte	W24
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
bgm_dooro_x3_8_001:
	.byte		N04   , En1 , v096
	.byte	W24
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_8_000
	.byte	PATT
	 .word	bgm_dooro_x3_8_001
	.byte	PATT
	 .word	bgm_dooro_x3_8_000
	.byte	PATT
	 .word	bgm_dooro_x3_8_001
	.byte	PATT
	 .word	bgm_dooro_x3_8_000
	.byte	PATT
	 .word	bgm_dooro_x3_8_001
	.byte	PATT
	 .word	bgm_dooro_x3_8_000
	.byte	PATT
	 .word	bgm_dooro_x3_8_001
	.byte	PATT
	 .word	bgm_dooro_x3_8_000
	.byte	PATT
	 .word	bgm_dooro_x3_8_001
	.byte	PATT
	 .word	bgm_dooro_x3_8_000
	.byte		N04   , En1 , v096
	.byte	W08
	.byte		        En1 , v068
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v048
	.byte	W04
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v068
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v048
	.byte	W04
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		        En1 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v076
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
bgm_dooro_x3_8_002:
	.byte		N04   , En1 , v068
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v072
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v072
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_8_002
	.byte	PATT
	 .word	bgm_dooro_x3_8_002
	.byte	PATT
	 .word	bgm_dooro_x3_8_002
	.byte	PATT
	 .word	bgm_dooro_x3_8_002
	.byte	PATT
	 .word	bgm_dooro_x3_8_002
	.byte	PATT
	 .word	bgm_dooro_x3_8_002
	.byte		N04   , En1 , v112
	.byte	W48
	.byte		        En1 , v100
	.byte	W04
	.byte		        En1 , v064
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v072
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v076
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v080
	.byte	W04
	.byte		        En1 , v084
	.byte	W04
	.byte		        En1 , v088
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
bgm_dooro_x3_8_003:
	.byte		N04   , En1 , v068
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v072
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v072
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
bgm_dooro_x3_8_004:
	.byte		N04   , En1 , v068
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v116
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_8_003
	.byte	PATT
	 .word	bgm_dooro_x3_8_004
	.byte	PATT
	 .word	bgm_dooro_x3_8_003
	.byte		N04   , En1 , v068
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v072
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v072
	.byte	W08
	.byte		N04   
	.byte	W08
bgm_dooro_x3_8_005:
	.byte	W48
	.byte		N04   , En1 , v072
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v072
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro_x3_8_005
	.byte	GOTO
	 .word	bgm_dooro_x3_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_dooro_x3:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_dooro_x3_pri	@ Priority
	.byte	bgm_dooro_x3_rev	@ Reverb.

	.word	bgm_dooro_x3_grp

	.word	bgm_dooro_x3_1
	.word	bgm_dooro_x3_2
	.word	bgm_dooro_x3_3
	.word	bgm_dooro_x3_4
	.word	bgm_dooro_x3_5
	.word	bgm_dooro_x3_6
	.word	bgm_dooro_x3_7
	.word	bgm_dooro_x3_8

	.end
