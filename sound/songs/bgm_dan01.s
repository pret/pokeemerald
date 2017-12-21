	.include "MPlayDef.s"

	.equ	bgm_dan01_grp, voicegroup_86793C4
	.equ	bgm_dan01_pri, 0
	.equ	bgm_dan01_rev, reverb_set+50
	.equ	bgm_dan01_mvl, 127
	.equ	bgm_dan01_key, 0
	.equ	bgm_dan01_tbs, 1
	.equ	bgm_dan01_exg, 1
	.equ	bgm_dan01_cmp, 1

	.section .rodata
	.global	bgm_dan01
	.align	2

@********************** Track  1 **********************@

bgm_dan01_1:
	.byte	KEYSH , bgm_dan01_key+0
	.byte	TEMPO , 130*bgm_dan01_tbs/2
	.byte		VOICE , 45
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		PAN   , c_v-9
	.byte		N06   , Dn4 , v080
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
bgm_dan01_1_000:
	.byte		N06   , Dn5 , v080
	.byte	W60
	.byte		        Cs5 
	.byte	W12
	.byte	PEND
	.byte		        As4 
	.byte	W72
bgm_dan01_1_B1:
bgm_dan01_1_001:
	.byte		N06   , Dn3 , v080
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        As4 
	.byte	W36
	.byte	PEND
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_001
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_001
	.byte	W72
bgm_dan01_1_002:
	.byte		N06   , Ds3 , v080
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W36
	.byte	PEND
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_002
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_002
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_002
	.byte	W72
bgm_dan01_1_003:
	.byte		N06   , Dn3 , v080
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As4 
	.byte	W36
	.byte	PEND
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_003
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_003
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_1_003
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W36
	.byte		N06   , Dn4 , v080
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte	PATT
	 .word	bgm_dan01_1_000
	.byte		N06   , As4 , v080
	.byte	W72
	.byte	GOTO
	 .word	bgm_dan01_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_dan01_2:
	.byte	KEYSH , bgm_dan01_key+0
	.byte	W36
	.byte		VOICE , 1
	.byte	W72
bgm_dan01_2_000:
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W12
	.byte		N06   , Dn2 , v056
	.byte	W12
	.byte		        Dn2 , v064
	.byte	W12
	.byte		        Dn2 , v072
	.byte	W12
	.byte		        Dn2 , v088
	.byte	W12
	.byte		        Dn2 , v096
	.byte	W12
	.byte	PEND
bgm_dan01_2_B1:
	.byte		N36   , Dn2 , v116
	.byte	W36
	.byte		N06   , Dn2 , v112
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		TIE   , Dn1 , v120
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		TIE   , Dn1 , v120
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte	W24
	.byte		N36   , As1 
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		TIE   , Ds1 , v112
	.byte	W72
	.byte	W36
	.byte		EOT   
	.byte		N06   , Ds2 , v088
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N44   , Ds3 , v088, gtp1
	.byte	W60
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		TIE   , Bn2 
	.byte	W72
	.byte	W68
	.byte	W01
	.byte		EOT   
	.byte	W03
	.byte	W60
	.byte		N06   , Ds2 , v112
	.byte	W12
	.byte		TIE   , Ds1 , v124
	.byte	W72
	.byte	W72
	.byte		EOT   
bgm_dan01_2_001:
	.byte	W12
	.byte		N06   , Dn2 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_2_001
	.byte		TIE   , Dn1 , v124
	.byte	W72
	.byte	W72
	.byte		EOT   
	.byte	W60
	.byte		N06   , Dn5 , v064
	.byte	W12
	.byte		TIE   
	.byte	W72
	.byte	W72
	.byte		EOT   
	.byte	W72
	.byte		VOICE , 48
	.byte		VOL   , 36*bgm_dan01_mvl/mxv
	.byte		MOD   , 9
	.byte		TIE   , Fs1 , v096
	.byte	W05
	.byte		VOL   , 40*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        42*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        46*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        48*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        53*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        57*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        60*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        64*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        68*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        74*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        77*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        78*bgm_dan01_mvl/mxv
	.byte	W36
	.byte		        80*bgm_dan01_mvl/mxv
	.byte	W24
	.byte		        77*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        76*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        75*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        69*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        66*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        61*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        57*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        53*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        46*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        38*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        32*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        21*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        10*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        1*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		EOT   
	.byte		VOICE , 1
	.byte		MOD   , 0
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_2_000
	.byte	GOTO
	 .word	bgm_dan01_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_dan01_3:
	.byte	KEYSH , bgm_dan01_key+0
	.byte		VOICE , 73
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N06   , Dn4 , v100
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
bgm_dan01_3_000:
	.byte		N44   , Dn5 , v100, gtp1
	.byte	W15
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 70*bgm_dan01_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dan01_mvl/mxv
	.byte	W06
	.byte		        40*bgm_dan01_mvl/mxv
	.byte	W06
	.byte		        27*bgm_dan01_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 78*bgm_dan01_mvl/mxv
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte	PEND
bgm_dan01_3_001:
	.byte		N68   , As4 , v100, gtp1
	.byte	W24
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		MOD   , 8
	.byte	W05
	.byte		VOL   , 65*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        61*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        51*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        44*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        34*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        23*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        3*bgm_dan01_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W03
	.byte	PEND
bgm_dan01_3_B1:
bgm_dan01_3_002:
	.byte		VOICE , 48
	.byte		VOL   , 35*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 41*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 42*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 47*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 49*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 55*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 58*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 63*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 68*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 74*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 78*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte	PEND
bgm_dan01_3_003:
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		        Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		        Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		        Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		        Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 71*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 69*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 66*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 64*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 61*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 59*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte	PEND
bgm_dan01_3_004:
	.byte		VOL   , 56*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 54*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 48*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 45*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 40*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 38*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 35*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 32*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 30*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 26*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 24*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 20*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte	PEND
bgm_dan01_3_005:
	.byte		VOL   , 16*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 12*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 7*bgm_dan01_mvl/mxv
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W02
	.byte		VOL   , 3*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Dn6 , v048
	.byte	W03
	.byte		        As5 , v040
	.byte	W03
	.byte		VOL   , 1*bgm_dan01_mvl/mxv
	.byte	W48
	.byte	PEND
	.byte	W72
	.byte	W72
	.byte		        35*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 41*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 42*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 47*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 49*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 55*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 58*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 63*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 68*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 74*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 78*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 71*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 69*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 66*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 64*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 61*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 59*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 56*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 54*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 48*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 45*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 40*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 38*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 35*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 32*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 30*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 26*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 24*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 20*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 16*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 12*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 7*bgm_dan01_mvl/mxv
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W02
	.byte		VOL   , 3*bgm_dan01_mvl/mxv
	.byte	W01
	.byte		N03   , Ds6 , v048
	.byte	W03
	.byte		        Gn5 , v040
	.byte	W03
	.byte		VOL   , 1*bgm_dan01_mvl/mxv
	.byte	W48
	.byte		VOICE , 73
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		N06   , Dn6 , v056
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        Dn6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        Dn6 
	.byte	W36
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		        Cs6 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        Cs6 
	.byte	W24
	.byte		        Dn6 
	.byte	W06
	.byte		        Ds6 
	.byte	W06
	.byte		        As5 
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_3_002
	.byte	PATT
	 .word	bgm_dan01_3_003
	.byte	PATT
	 .word	bgm_dan01_3_004
	.byte	PATT
	 .word	bgm_dan01_3_005
	.byte	W36
	.byte		VOICE , 73
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		N06   , Dn4 , v100
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte	PATT
	 .word	bgm_dan01_3_000
	.byte	PATT
	 .word	bgm_dan01_3_001
	.byte	GOTO
	 .word	bgm_dan01_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_dan01_4:
	.byte	KEYSH , bgm_dan01_key+0
	.byte	W36
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		PAN   , c_v-47
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W72
	.byte	W72
bgm_dan01_4_B1:
	.byte		VOICE , 80
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		        4
	.byte		N72   , Dn4 , v060
	.byte	W06
	.byte		VOL   , 65*bgm_dan01_mvl/mxv
	.byte	W06
	.byte		        51*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        56*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        58*bgm_dan01_mvl/mxv
	.byte		MOD   , 12
	.byte	W05
	.byte		VOL   , 62*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        65*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        70*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        76*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        80*bgm_dan01_mvl/mxv
	.byte	W19
	.byte		MOD   , 0
	.byte		TIE   , Ds4 , v056
	.byte	W40
	.byte	W01
	.byte		VOL   , 76*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        75*bgm_dan01_mvl/mxv
	.byte		MOD   , 12
	.byte	W05
	.byte		VOL   , 70*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        69*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        66*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        61*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        58*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        54*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        49*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        47*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        42*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        37*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        32*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        26*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        17*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        8*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        1*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W72
	.byte	W72
	.byte		VOICE , 80
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W72
	.byte	W12
	.byte		        Bn3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
bgm_dan01_4_000:
	.byte	W12
	.byte		N06   , As3 , v056
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_4_000
	.byte		N06   , As3 , v056
	.byte	W72
bgm_dan01_4_001:
	.byte	W36
	.byte		N06   , Dn3 , v060
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PEND
bgm_dan01_4_002:
	.byte		N06   , As4 , v060
	.byte	W12
	.byte		        Dn4 , v040
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn4 , v020
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte	PEND
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_4_001
	.byte	PATT
	 .word	bgm_dan01_4_002
	.byte	W72
	.byte	W36
	.byte		VOICE , 4
	.byte		N06   , Dn2 , v068
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 , v020
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte	W72
	.byte	W72
	.byte	GOTO
	 .word	bgm_dan01_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_dan01_5:
	.byte	KEYSH , bgm_dan01_key+0
	.byte	W36
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W72
	.byte	W72
bgm_dan01_5_B1:
	.byte		VOICE , 82
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		        5
	.byte		N12   , As3 , v060
	.byte	W06
	.byte		VOL   , 65*bgm_dan01_mvl/mxv
	.byte	W06
	.byte		VOICE , 6
	.byte		VOL   , 51*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 56*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        58*bgm_dan01_mvl/mxv
	.byte		MOD   , 12
	.byte		N12   
	.byte	W05
	.byte		VOL   , 62*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        65*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 70*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        76*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		N12   , Bn3 , v056
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   , Bn3 , v060
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W05
	.byte		VOL   , 76*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        75*bgm_dan01_mvl/mxv
	.byte		MOD   , 12
	.byte		N12   
	.byte	W05
	.byte		VOL   , 70*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        69*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 66*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        61*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 58*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        54*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 49*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        47*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 42*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        37*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 32*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        26*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 17*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        8*bgm_dan01_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 1*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W72
	.byte	W72
	.byte		VOICE , 82
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W12
	.byte		N06   , Gn4 , v056
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W72
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
bgm_dan01_5_000:
	.byte	W12
	.byte		N06   , Fs3 , v056
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_5_000
	.byte		N06   , Fs3 , v056
	.byte	W72
bgm_dan01_5_001:
	.byte	W42
	.byte		N06   , Dn3 , v060
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte	PEND
bgm_dan01_5_002:
	.byte	W06
	.byte		N06   , As4 , v060
	.byte	W12
	.byte		        Dn4 , v040
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn4 , v020
	.byte	W12
	.byte		        As4 
	.byte	W18
	.byte	PEND
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_5_001
	.byte	PATT
	 .word	bgm_dan01_5_002
	.byte	W72
	.byte	W36
	.byte		VOICE , 5
	.byte	W06
	.byte		N06   , Dn2 , v068
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 , v020
	.byte	W12
	.byte		        As3 
	.byte	W18
	.byte	W72
	.byte	W72
	.byte	GOTO
	 .word	bgm_dan01_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_dan01_6:
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	KEYSH , bgm_dan01_key+0
	.byte	W36
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , Dn2 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
bgm_dan01_6_B1:
bgm_dan01_6_000:
	.byte	W12
	.byte		N06   , Dn3 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W72
bgm_dan01_6_001:
	.byte	W12
	.byte		N06   , Dn2 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_001
	.byte		N06   , Dn2 , v064
	.byte	W72
bgm_dan01_6_002:
	.byte	W12
	.byte		N06   , Ds2 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_002
	.byte		N06   , Ds2 , v064
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_002
	.byte		N06   , Ds2 , v064
	.byte	W72
	.byte	W12
	.byte		        Ds3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_000
	.byte		N06   , Dn3 , v064
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_000
	.byte		N06   , Dn3 , v064
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_001
	.byte		N06   , Dn2 , v064
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_001
	.byte		N06   , Dn2 , v064
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_001
	.byte		N06   , Dn2 , v064
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_6_001
	.byte		N06   , Dn2 , v064
	.byte	W72
	.byte		VOICE , 81
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	GOTO
	 .word	bgm_dan01_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_dan01_7:
	.byte	KEYSH , bgm_dan01_key+0
	.byte	W36
	.byte		PAN   , c_v+10
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W72
bgm_dan01_7_000:
	.byte	W12
	.byte		N06   , As2 , v036
	.byte	W12
	.byte		        As2 , v040
	.byte	W12
	.byte		        As2 , v048
	.byte	W12
	.byte		        As2 , v056
	.byte	W12
	.byte		        As2 , v060
	.byte	W12
	.byte	PEND
bgm_dan01_7_B1:
	.byte		N36   , As2 , v064
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N36   , As1 
	.byte	W36
	.byte		VOICE , 48
	.byte		PAN   , c_v+32
	.byte		N06   , Dn2 , v088
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N44   , Dn3 , v088, gtp1
	.byte	W60
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		TIE   , As2 
	.byte	W42
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	W06
	.byte		        77*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        70*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        66*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        62*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        55*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        50*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        44*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        38*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        30*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        23*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        12*bgm_dan01_mvl/mxv
	.byte	W07
	.byte		        5*bgm_dan01_mvl/mxv
	.byte	W05
	.byte		        1*bgm_dan01_mvl/mxv
	.byte	W16
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 1
	.byte		PAN   , c_v+10
	.byte		N36   , Dn2 , v120
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte		TIE   , Gn1 
	.byte	W72
	.byte	W36
	.byte		EOT   
	.byte		N06   , Bn1 , v084
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N44   , Bn2 , v084, gtp1
	.byte	W60
	.byte		N06   , Bn2 , v080
	.byte	W12
	.byte		TIE   , Gn2 , v084
	.byte	W72
	.byte	W68
	.byte	W01
	.byte		EOT   
	.byte	W03
	.byte	W72
	.byte	W72
	.byte	W72
bgm_dan01_7_001:
	.byte	W12
	.byte		N06   , As2 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_7_001
	.byte		TIE   , As1 , v120
	.byte	W72
	.byte	W72
	.byte		EOT   
	.byte	W60
	.byte		N06   , Fs5 , v064
	.byte	W12
	.byte		TIE   
	.byte	W72
	.byte	W72
	.byte		EOT   
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_7_000
	.byte	GOTO
	 .word	bgm_dan01_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_dan01_8:
	.byte	KEYSH , bgm_dan01_key+0
	.byte	W36
	.byte		VOICE , 127
	.byte		VOL   , 75*bgm_dan01_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N11   , Gs4 , v040
	.byte	W60
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W72
bgm_dan01_8_B1:
bgm_dan01_8_000:
	.byte		N11   , Gs4 , v040
	.byte	W60
	.byte		N11   
	.byte	W12
	.byte	PEND
	.byte		N11   
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	PATT
	 .word	bgm_dan01_8_000
	.byte		N11   , Gs4 , v040
	.byte	W72
	.byte	GOTO
	 .word	bgm_dan01_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_dan01_9:
	.byte		VOL   , 80*bgm_dan01_mvl/mxv
	.byte	KEYSH , bgm_dan01_key+0
	.byte	W36
	.byte		VOICE , 0
	.byte	W72
	.byte	W72
bgm_dan01_9_B1:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W60
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W60
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W60
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W60
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W60
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W60
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W60
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W60
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W72
	.byte	W72
	.byte	GOTO
	 .word	bgm_dan01_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_dan01:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_dan01_pri	@ Priority
	.byte	bgm_dan01_rev	@ Reverb.

	.word	bgm_dan01_grp

	.word	bgm_dan01_1
	.word	bgm_dan01_2
	.word	bgm_dan01_3
	.word	bgm_dan01_4
	.word	bgm_dan01_5
	.word	bgm_dan01_6
	.word	bgm_dan01_7
	.word	bgm_dan01_8
	.word	bgm_dan01_9

	.end
