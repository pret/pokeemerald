	.include "MPlayDef.s"

	.equ	mus_naminori_grp, voicegroup_8678F80
	.equ	mus_naminori_pri, 0
	.equ	mus_naminori_rev, reverb_set+50
	.equ	mus_naminori_mvl, 127
	.equ	mus_naminori_key, 0
	.equ	mus_naminori_tbs, 1
	.equ	mus_naminori_exg, 0
	.equ	mus_naminori_cmp, 1

	.section .rodata
	.global	mus_naminori
	.align	2

@********************** Track  1 **********************@

mus_naminori_1:
	.byte	KEYSH , mus_naminori_key+0
	.byte	TEMPO , 82*mus_naminori_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 40
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cs4 , v104
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
mus_naminori_1_B1:
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N18   , Fn4 , v104
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N18   , Fn4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		VOICE , 73
	.byte		N15   , Gs4 , v112
	.byte	W06
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N18   , Fn4 
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N15   , Gs4 
	.byte	W09
	.byte		MOD   , 5
	.byte	W06
	.byte		        0
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W09
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		TIE   , Fn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        70*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        64*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        57*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        52*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        45*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        18*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        7*mus_naminori_mvl/mxv
	.byte	W07
	.byte		EOT   
	.byte		VOL   , 1*mus_naminori_mvl/mxv
	.byte		MOD   , 0
	.byte	W36
	.byte		VOICE , 73
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N06   , As4 , v072
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N12   , Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N32   , Cs5 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte		MOD   , 5
	.byte	W05
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 60
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N18   , Cn3 , v116
	.byte	W18
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N18   , Ds3 
	.byte	W18
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N60   , Fn3 
	.byte	W30
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        52*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        42*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        31*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        21*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N18   
	.byte	W18
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N60   , Fs3 
	.byte	W30
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        52*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        42*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        31*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        21*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W07
	.byte		VOICE , 73
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N15   , As4 , v112
	.byte	W06
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N15   , Gs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N15   , Fs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   , Gs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		        0
	.byte		N15   , As4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N15   , Gs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		        0
	.byte		N12   , Cs5 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		        0
	.byte		N36   , Cn5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOICE , 48
	.byte	W12
	.byte		MOD   , 0
	.byte		N18   , Fn4 , v104
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
mus_naminori_1_000:
	.byte		N18   , Fn4 , v104
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte	PEND
	.byte		N18   , As4 
	.byte	W18
	.byte		N06   , An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N06   , As4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N30   , Gs4 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        66*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        53*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        36*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N18   , Fn4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte	PATT
	 .word	mus_naminori_1_000
	.byte		N18   , As4 , v104
	.byte	W18
	.byte		N06   , An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N18   , Ds5 
	.byte	W18
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N32   , Cn5 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        66*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        53*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        36*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 73
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N54   , Cs5 , v120
	.byte	W21
	.byte		MOD   , 5
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N54   , Cs5 
	.byte	W21
	.byte		MOD   , 5
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N32   , Fn5 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W03
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 59*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        44*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N32   , Cs5 
	.byte	W09
	.byte		MOD   , 5
	.byte	W09
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        27*mus_naminori_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte	GOTO
	 .word	mus_naminori_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_naminori_2:
	.byte	KEYSH , mus_naminori_key+0
	.byte	W36
mus_naminori_2_B1:
	.byte		VOICE , 58
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Cs1 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N36   , Bn0 
	.byte	W36
	.byte		N24   , As0 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , An0 
	.byte	W24
	.byte		N12   , Fs0 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N36   , Bn0 
	.byte	W36
	.byte		VOL   , 77*mus_naminori_mvl/mxv
	.byte		N32   , As0 
	.byte	W05
	.byte		VOL   , 74*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        68*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        56*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        43*mus_naminori_mvl/mxv
	.byte		N36   , Fs0 
	.byte	W05
	.byte		VOL   , 53*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        65*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W19
mus_naminori_2_000:
	.byte		N24   , Cs1 , v127
	.byte	W24
	.byte		N06   , Gs0 
	.byte	W12
	.byte		N36   , Cs1 
	.byte	W36
	.byte	PEND
mus_naminori_2_001:
	.byte		N24   , Bn0 , v127
	.byte	W24
	.byte		N06   , Gs0 
	.byte	W12
	.byte		N36   , Bn0 
	.byte	W36
	.byte	PEND
	.byte		N24   , As0 
	.byte	W24
	.byte		N06   , Fs0 
	.byte	W12
	.byte		N12   , As0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N12   , Cs1 
	.byte	W12
	.byte	PATT
	 .word	mus_naminori_2_000
	.byte	PATT
	 .word	mus_naminori_2_001
	.byte		N24   , As0 , v127
	.byte	W24
	.byte		N06   , Fs0 
	.byte	W12
	.byte		N24   , As0 
	.byte	W24
	.byte		N12   , Gs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N18   , Cs1 
	.byte	W18
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N48   , Gs1 
	.byte	W24
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        58*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        42*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        31*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W12
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N32   , Cs2 
	.byte	W12
	.byte		VOL   , 76*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        58*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        38*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N48   , Dn2 
	.byte	W24
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        58*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        42*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        31*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W12
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N66   , Ds2 
	.byte	W30
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        62*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        55*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        41*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        35*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        15*mus_naminori_mvl/mxv
	.byte	W07
mus_naminori_2_002:
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N32   , Fs2 , v112
	.byte	W18
	.byte		VOL   , 66*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N32   , Fn2 
	.byte	W18
	.byte		VOL   , 66*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N32   , Ds2 
	.byte	W18
	.byte		VOL   , 66*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N32   , Cs2 
	.byte	W18
	.byte		VOL   , 66*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W06
	.byte	PATT
	 .word	mus_naminori_2_002
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N32   , Ds2 , v112
	.byte	W36
	.byte		N12   , Gs0 , v127
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
mus_naminori_2_003:
	.byte		N24   , Cs1 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_naminori_2_003
	.byte		N24   , As0 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N24   , Gs0 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N24   , Cs1 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W15
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   , Gs0 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W15
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N21   , Cs1 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   , An0 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W15
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   , As0 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W15
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N36   , Fn0 
	.byte	W06
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        52*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        73*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W06
	.byte		N21   , Fn1 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N21   , Fs1 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N09   
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N21   , Cs1 
	.byte	W09
	.byte		VOL   , 61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        25*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N09   
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N32   , Fs1 
	.byte	W06
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        63*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        46*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        36*mus_naminori_mvl/mxv
	.byte	W12
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N32   , Gs1 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        59*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        44*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N32   , Cs1 
	.byte	W18
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        27*mus_naminori_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	mus_naminori_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_naminori_3:
	.byte	KEYSH , mus_naminori_key+0
	.byte	W36
mus_naminori_3_B1:
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte	W72
	.byte	W48
	.byte		VOICE , 48
	.byte		VOL   , 56*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N24   , An4 , v072
	.byte	W02
	.byte		VOL   , 60*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        65*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        68*mus_naminori_mvl/mxv
	.byte	W04
	.byte		        71*mus_naminori_mvl/mxv
	.byte	W02
	.byte		        77*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        51*mus_naminori_mvl/mxv
	.byte		N36   , Cs5 , v064
	.byte	W02
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        56*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        59*mus_naminori_mvl/mxv
	.byte	W04
	.byte		        62*mus_naminori_mvl/mxv
	.byte	W02
	.byte		        66*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        70*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        77*mus_naminori_mvl/mxv
	.byte	W04
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W12
	.byte		        57*mus_naminori_mvl/mxv
	.byte		N36   , Bn4 
	.byte	W02
	.byte		VOL   , 59*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        62*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        64*mus_naminori_mvl/mxv
	.byte	W04
	.byte		        65*mus_naminori_mvl/mxv
	.byte	W02
	.byte		        70*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        76*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W16
	.byte		        77*mus_naminori_mvl/mxv
	.byte		N36   , As4 
	.byte	W05
	.byte		VOL   , 74*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        68*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        56*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        17*mus_naminori_mvl/mxv
	.byte	W36
	.byte		VOICE , 45
	.byte		VOL   , 78*mus_naminori_mvl/mxv
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOICE , 48
	.byte		N12   , Cs3 , v092
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 , v104
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N18   , Fn4 
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N15   , Gs4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N32   , Fn4 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W07
	.byte		VOICE , 45
	.byte	W12
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N06   , Gs3 , v064
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		VOICE , 45
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte	W72
	.byte	W72
	.byte		VOICE , 60
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte		N36   , Fs3 , v072
	.byte	W06
	.byte		VOL   , 60*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W18
	.byte		N36   , Fn3 , v076
	.byte	W36
	.byte		        Ds3 , v080
	.byte	W36
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		VOL   , 45*mus_naminori_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W06
	.byte		VOL   , 50*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        68*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W12
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N32   
	.byte	W21
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        41*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        27*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N18   , Cs4 
	.byte	W18
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N06   , As3 
	.byte	W12
	.byte		N32   , Gs3 
	.byte	W18
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N36   , As2 , v076
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		N32   , Cs3 
	.byte	W18
	.byte		VOL   , 74*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N32   , Fs3 
	.byte	W06
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        63*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        46*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N30   , Fn3 
	.byte	W06
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        57*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        37*mus_naminori_mvl/mxv
	.byte	W18
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cs4 , v104
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte	GOTO
	 .word	mus_naminori_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_naminori_4:
	.byte	KEYSH , mus_naminori_key+0
	.byte	W36
mus_naminori_4_B1:
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N24   , Gs3 , v060
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , As3 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N36   , Fn3 
	.byte	W36
	.byte		VOL   , 77*mus_naminori_mvl/mxv
	.byte		N32   , Fs3 
	.byte	W05
	.byte		VOL   , 74*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        68*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        56*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Fs3 , v040
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 1
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 , v040
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
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		VOICE , 80
	.byte		N12   , An3 , v048
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N32   , Fn3 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W07
	.byte		VOICE , 88
	.byte		PAN   , c_v-48
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N36   , Ds4 , v036
	.byte	W12
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N36   , Gs4 
	.byte	W12
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   , Cs4 
	.byte	W12
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W12
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N36   , Dn4 
	.byte	W12
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N36   , Fn4 
	.byte	W12
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W12
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N36   , As4 
	.byte	W12
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 45
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Fs3 , v064
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N36   , Cs4 , v032
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		VOICE , 83
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N32   
	.byte	W18
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N32   
	.byte	W18
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N32   , Fn3 
	.byte	W18
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 80
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Fs3 , v048
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N32   
	.byte	W06
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        63*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        46*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        49*mus_naminori_mvl/mxv
	.byte		N36   , Cs3 , v060
	.byte	W06
	.byte		VOL   , 55*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        62*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        75*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W12
	.byte		N32   , Cs4 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        59*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        44*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N32   , Fn3 
	.byte	W18
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        27*mus_naminori_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	mus_naminori_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_naminori_5:
	.byte	KEYSH , mus_naminori_key+0
	.byte	W36
mus_naminori_5_B1:
	.byte		VOICE , 84
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		N24   , Fn3 , v060
	.byte	W24
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 87
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		N24   
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 87
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 77*mus_naminori_mvl/mxv
	.byte		N32   
	.byte	W05
	.byte		VOL   , 74*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        68*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        56*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        47*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 17*mus_naminori_mvl/mxv
	.byte	W03
	.byte		        80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-2
	.byte		N12   , Fs3 , v024
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W09
	.byte	W03
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W09
	.byte	W03
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W09
	.byte	W03
	.byte		        Fs3 
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W09
	.byte	W03
	.byte		        An3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 2
	.byte		N06   , Fs2 , v032
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W03
	.byte	W03
	.byte		        Fn4 , v028
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
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W03
	.byte	W03
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W03
	.byte	W03
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W03
	.byte	W03
	.byte		VOICE , 82
	.byte		N12   , An3 , v032
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N32   , Fn3 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W04
	.byte		VOICE , 89
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+0
	.byte		N12   , Gs3 , v036
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 89
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 89
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W12
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 89
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Gs3 
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 89
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 67*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 89
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N24   , As3 
	.byte	W12
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		VOICE , 90
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        26*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 11*mus_naminori_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v-4
	.byte	W72
	.byte	W72
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , As3 , v032
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Gs3 
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Fs3 
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		BEND  , c_v+0
	.byte		N12   , Gs2 , v060
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
mus_naminori_5_000:
	.byte		N12   , Cs3 , v060
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_naminori_5_000
	.byte		N12   , Fn3 , v060
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		VOICE , 84
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte		N09   
	.byte	W06
	.byte		VOL   , 40*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 84
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N24   , An2 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte		N09   
	.byte	W06
	.byte		VOL   , 40*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 84
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte		N09   
	.byte	W06
	.byte		VOL   , 40*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Cs3 , v048
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , An3 
	.byte	W06
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 86
	.byte		VOL   , 63*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 46*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte		N09   
	.byte	W05
	.byte		VOL   , 33*mus_naminori_mvl/mxv
	.byte	W07
	.byte		VOICE , 82
	.byte		VOL   , 49*mus_naminori_mvl/mxv
	.byte		N12   , An2 , v060
	.byte	W06
	.byte		VOL   , 55*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 86
	.byte		VOL   , 62*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W05
	.byte		VOL   , 75*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Gs3 
	.byte	W12
	.byte		VOICE , 86
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 59*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        44*mus_naminori_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 29*mus_naminori_mvl/mxv
	.byte	W06
	.byte		VOICE , 82
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		N12   , Cs3 , v056
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   , Cs3 , v060
	.byte	W06
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte		N09   
	.byte	W06
	.byte		VOL   , 27*mus_naminori_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	mus_naminori_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_naminori_6:
	.byte	KEYSH , mus_naminori_key+0
	.byte		LFOS  , 40
	.byte	W36
mus_naminori_6_B1:
	.byte		VOICE , 46
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N06   , Cs4 , v088
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
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Cs4 
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
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cs4 , v092
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N06   , Cs5 , v096
	.byte	W24
	.byte		        Ds5 , v088
	.byte	W06
	.byte		        Ds5 , v056
	.byte	W06
	.byte		        Fn5 , v088
	.byte	W06
	.byte		        Fn5 , v056
	.byte	W06
	.byte		        Fs5 , v088
	.byte	W06
	.byte		        Fs5 , v056
	.byte	W06
	.byte	W36
	.byte		        Cs4 , v088
	.byte	W06
	.byte		        Cs4 , v056
	.byte	W06
	.byte		        Gs4 , v088
	.byte	W06
	.byte		        Gs4 , v056
	.byte	W06
	.byte		        Cs5 , v088
	.byte	W06
	.byte		        Cs5 , v056
	.byte	W06
	.byte	W36
	.byte		        Bn3 , v088
	.byte	W06
	.byte		        Bn3 , v056
	.byte	W06
	.byte		        Gs4 , v088
	.byte	W06
	.byte		        Gs4 , v056
	.byte	W06
	.byte		        Bn4 , v088
	.byte	W06
	.byte		        Bn4 , v056
	.byte	W06
	.byte	W36
	.byte		        As3 , v088
	.byte	W06
	.byte		        As3 , v056
	.byte	W06
	.byte		        Fs4 , v088
	.byte	W06
	.byte		        Fs4 , v056
	.byte	W06
	.byte		        As4 , v088
	.byte	W06
	.byte		        As4 , v056
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 54*mus_naminori_mvl/mxv
	.byte		N36   , Fs2 , v064
	.byte	W05
	.byte		VOL   , 58*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        65*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        77*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W12
	.byte		        54*mus_naminori_mvl/mxv
	.byte		N36   , An2 
	.byte	W05
	.byte		VOL   , 58*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        65*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        77*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W12
	.byte		N72   , Gs2 
	.byte	W30
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        70*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        66*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        57*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        45*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        35*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        22*mus_naminori_mvl/mxv
	.byte	W07
	.byte	W36
	.byte		        50*mus_naminori_mvl/mxv
	.byte		N36   
	.byte	W06
	.byte		VOL   , 58*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        60*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        65*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        71*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        80*mus_naminori_mvl/mxv
	.byte	W07
	.byte		N24   , As2 
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N18   , Fs2 
	.byte	W18
	.byte		N06   , Cs3 , v072
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N32   , Cs3 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        61*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W07
	.byte	W72
	.byte		VOICE , 73
	.byte		VOL   , 80*mus_naminori_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N18   , Cs5 , v060
	.byte	W09
	.byte		MOD   , 8
	.byte	W09
	.byte		        0
	.byte		N06   , Gs4 , v068
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Gs5 , v024
	.byte	W06
	.byte		        Fn5 , v068
	.byte	W06
	.byte		        Fn5 , v024
	.byte	W06
	.byte	W72
	.byte		N18   , Ds5 , v060
	.byte	W09
	.byte		MOD   , 8
	.byte	W09
	.byte		        0
	.byte		N06   , As4 , v068
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N06   , As5 
	.byte	W06
	.byte		        As5 , v024
	.byte	W06
	.byte		        Fs5 , v068
	.byte	W06
	.byte		        Fs5 , v024
	.byte	W06
	.byte	W72
	.byte	W72
	.byte	W36
	.byte		VOICE , 48
	.byte		VOL   , 34*mus_naminori_mvl/mxv
	.byte		PAN   , c_v-17
	.byte		N36   , Gs3 , v076
	.byte	W06
	.byte		VOL   , 47*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        56*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        63*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        76*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N36   , As3 
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		VOICE , 46
	.byte		N06   , Gs2 , v092
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
mus_naminori_6_000:
	.byte		N06   , An2 , v092
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	PEND
mus_naminori_6_001:
	.byte		N06   , As2 , v092
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte	PEND
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte	PATT
	 .word	mus_naminori_6_000
	.byte	PATT
	 .word	mus_naminori_6_001
	.byte		N06   , Cn3 , v092
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		VOICE , 48
	.byte		N06   , Fs3 , v052
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fs4 
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
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N32   , Fs4 , v064
	.byte	W06
	.byte		VOL   , 71*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        63*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        46*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        40*mus_naminori_mvl/mxv
	.byte	W05
	.byte		        33*mus_naminori_mvl/mxv
	.byte	W07
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N32   , Fn4 
	.byte	W12
	.byte		VOL   , 73*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        59*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        44*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        29*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        80*mus_naminori_mvl/mxv
	.byte		N32   , Gs2 
	.byte	W18
	.byte		VOL   , 70*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        49*mus_naminori_mvl/mxv
	.byte	W06
	.byte		        27*mus_naminori_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	mus_naminori_6_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_naminori:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_naminori_pri	@ Priority
	.byte	mus_naminori_rev	@ Reverb.

	.word	mus_naminori_grp

	.word	mus_naminori_1
	.word	mus_naminori_2
	.word	mus_naminori_3
	.word	mus_naminori_4
	.word	mus_naminori_5
	.word	mus_naminori_6

	.end
