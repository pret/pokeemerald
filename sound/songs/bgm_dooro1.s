	.include "MPlayDef.s"

	.equ	bgm_dooro1_grp, voicegroup_8677528
	.equ	bgm_dooro1_pri, 0
	.equ	bgm_dooro1_rev, reverb_set+50
	.equ	bgm_dooro1_mvl, 127
	.equ	bgm_dooro1_key, 0
	.equ	bgm_dooro1_tbs, 1
	.equ	bgm_dooro1_exg, 0
	.equ	bgm_dooro1_cmp, 1

	.section .rodata
	.global	bgm_dooro1
	.align	2

@********************** Track  1 **********************@

bgm_dooro1_1:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte	TEMPO , 114*bgm_dooro1_tbs/2
	.byte		VOICE , 73
	.byte		LFOS  , 32
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N06   , An4 , v100
	.byte	W06
	.byte		        Bn4 
	.byte	W06
bgm_dooro1_1_B1:
	.byte		PAN   , c_v+8
	.byte		N06   , An4 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
bgm_dooro1_1_000:
	.byte		N06   , Gn4 , v100
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte	PEND
bgm_dooro1_1_001:
	.byte		N72   , An4 , v100
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		VOL   , 71*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        63*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		        49*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	PEND
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W36
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro1_1_000
	.byte	PATT
	 .word	bgm_dooro1_1_001
	.byte		N06   , An4 , v100
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W36
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
bgm_dooro1_1_002:
	.byte		MOD   , 0
	.byte		N06   , An4 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N36   , An4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W21
	.byte		        0
	.byte	W12
	.byte	PEND
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro1_1_002
	.byte		N06   , Bn4 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Fs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N36   , Dn5 
	.byte	W15
	.byte		MOD   , 4
	.byte	W21
	.byte		        0
	.byte	W12
	.byte		N36   
	.byte	W18
	.byte		MOD   , 4
	.byte	W18
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N24   , As4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W09
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N78   , Cs5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 78*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        56*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        45*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        34*bgm_dooro1_mvl/mxv
	.byte	W05
	.byte		MOD   , 0
	.byte	W01
	.byte		VOL   , 23*bgm_dooro1_mvl/mxv
	.byte	W04
	.byte		        78*bgm_dooro1_mvl/mxv
	.byte	W01
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_dooro1_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_dooro1_2:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
bgm_dooro1_2_B1:
	.byte		VOICE , 35
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N12   , Dn1 , v120
	.byte	W42
	.byte		N06   , An1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W36
	.byte		        An1 
	.byte	W12
bgm_dooro1_2_000:
	.byte		N12   , En1 , v120
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		BEND  , c_v-32
	.byte		N09   , En2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_dooro1_2_001:
	.byte		N12   , An1 , v120
	.byte	W42
	.byte		N06   , En1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W36
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
bgm_dooro1_2_002:
	.byte		N12   , An1 , v120
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        En1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W24
	.byte		BEND  , c_v-31
	.byte		N06   , En2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N12   , An1 
	.byte	W12
	.byte	PEND
	.byte		        Dn1 
	.byte	W42
	.byte		N06   , An1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W36
	.byte		        An1 
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro1_2_000
	.byte	PATT
	 .word	bgm_dooro1_2_001
	.byte	PATT
	 .word	bgm_dooro1_2_002
bgm_dooro1_2_003:
	.byte		N12   , Gn1 , v120
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
bgm_dooro1_2_004:
	.byte		N12   , Fs1 , v120
	.byte	W18
	.byte		N06   , An1 
	.byte	W06
	.byte		BEND  , c_v-32
	.byte		N12   , Dn2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		BEND  , c_v-31
	.byte		N12   , Dn2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N12   , Fs1 
	.byte	W12
	.byte	PEND
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		BEND  , c_v-15
	.byte		N12   , En2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , An1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		BEND  , c_v-32
	.byte		N12   , En1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro1_2_003
	.byte	PATT
	 .word	bgm_dooro1_2_004
	.byte		N15   , Fn1 , v120
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		BEND  , c_v-31
	.byte		N36   , Dn2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W32
	.byte	W01
	.byte		N12   , As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        An1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		BEND  , c_v-32
	.byte		N72   , En2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W18
	.byte		VOL   , 79*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v-32
	.byte	W03
	.byte		VOL   , 74*bgm_dooro1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		VOL   , 63*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        54*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        44*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        34*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        18*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        10*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        1*bgm_dooro1_mvl/mxv
	.byte	W01
	.byte	GOTO
	 .word	bgm_dooro1_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_dooro1_3:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte		LFOS  , 28
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte	W12
bgm_dooro1_3_B1:
	.byte		VOICE , 4
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+4
	.byte		N06   , Fs3 , v052
	.byte	W36
	.byte		N06   
	.byte	W60
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
bgm_dooro1_3_000:
	.byte	W48
	.byte		N24   , En3 , v052
	.byte	W12
	.byte		VOL   , 59*bgm_dooro1_mvl/mxv
	.byte	W05
	.byte		        23*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        0*bgm_dooro1_mvl/mxv
	.byte	W24
	.byte	PEND
bgm_dooro1_3_001:
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N03   , An3 , v052
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W18
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W48
	.byte	PEND
	.byte		        Fs3 
	.byte	W36
	.byte		N06   
	.byte	W60
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro1_3_000
	.byte	PATT
	 .word	bgm_dooro1_3_001
	.byte		VOICE , 5
	.byte		PAN   , c_v-49
	.byte		N06   , Bn3 , v052
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		VOICE , 4
	.byte		N21   , Gn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W21
	.byte		VOICE , 5
	.byte		PAN   , c_v-48
	.byte		N06   , An3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		VOICE , 4
	.byte		N21   , Dn4 
	.byte	W24
	.byte		        Dn3 
	.byte	W21
	.byte	W96
	.byte		VOICE , 81
	.byte		N06   , Dn5 , v040
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 4
	.byte		N12   
	.byte	W12
	.byte		N15   
	.byte	W15
	.byte		MOD   , 0
	.byte	W09
	.byte		VOICE , 5
	.byte		PAN   , c_v-48
	.byte		N06   , Bn3 , v052
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		VOICE , 4
	.byte		N21   , Gn4 
	.byte	W24
	.byte		        Bn4 
	.byte	W21
	.byte		VOICE , 5
	.byte		PAN   , c_v-48
	.byte		N06   , An3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		VOICE , 4
	.byte		N21   , Dn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W21
	.byte		VOICE , 81
	.byte		N12   , Fn4 
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 81
	.byte		N12   , En4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   
	.byte	W12
	.byte		MOD   , 4
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 79*bgm_dooro1_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        58*bgm_dooro1_mvl/mxv
	.byte		N18   
	.byte	W07
	.byte		VOL   , 47*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        37*bgm_dooro1_mvl/mxv
	.byte	W05
	.byte		MOD   , 0
	.byte	W01
	.byte		VOL   , 27*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        16*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        6*bgm_dooro1_mvl/mxv
	.byte	W04
	.byte	GOTO
	 .word	bgm_dooro1_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_dooro1_4:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte	W12
bgm_dooro1_4_B1:
	.byte		VOICE , 5
	.byte		PAN   , c_v-48
	.byte		N06   , An3 , v052
	.byte	W36
	.byte		N06   
	.byte	W60
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
bgm_dooro1_4_000:
	.byte		N06   , Cs3 , v052
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 59*bgm_dooro1_mvl/mxv
	.byte	W05
	.byte		        23*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        0*bgm_dooro1_mvl/mxv
	.byte	W24
	.byte	PEND
bgm_dooro1_4_001:
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N03   , Cs4 , v052
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W18
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W48
	.byte	PEND
	.byte		        An3 
	.byte	W36
	.byte		N06   
	.byte	W60
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro1_4_000
	.byte	PATT
	 .word	bgm_dooro1_4_001
	.byte		VOICE , 8
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 , v052
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 6
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOICE , 8
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 6
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
bgm_dooro1_4_002:
	.byte		VOICE , 8
	.byte		N06   , Fs3 , v052
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		VOICE , 6
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		VOICE , 8
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		VOICE , 6
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	PEND
	.byte		        Gn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		VOICE , 8
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 6
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOICE , 8
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 6
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro1_4_002
	.byte		VOICE , 5
	.byte		PAN   , c_v-48
	.byte		N06   , As3 , v060
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W15
	.byte		VOL   , 68*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		        52*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		        40*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		VOICE , 7
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N12   , Fn5 , v072
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fn5 , v048
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , As5 , v072
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , As5 , v048
	.byte	W12
	.byte		VOICE , 5
	.byte		PAN   , c_v-48
	.byte		N06   , An3 , v060
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W15
	.byte		VOL   , 68*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		        52*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		        40*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		VOICE , 7
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N12   , En5 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , En5 , v044
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , An5 , v060
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , An5 , v044
	.byte	W12
	.byte	GOTO
	 .word	bgm_dooro1_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_dooro1_5:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte	W12
bgm_dooro1_5_B1:
	.byte		VOICE , 24
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Dn3 , v048
	.byte	W12
	.byte		        An2 
	.byte	W24
	.byte		        Fs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W24
	.byte		N24   , Dn3 , v060
	.byte	W24
bgm_dooro1_5_000:
	.byte		N06   , En3 , v048
	.byte	W12
	.byte		        Bn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W24
	.byte		N24   , En3 , v060
	.byte	W24
	.byte	PEND
bgm_dooro1_5_001:
	.byte		N03   , An2 , v056
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N36   , En4 
	.byte	W36
	.byte	W03
	.byte		N03   , An3 
	.byte	W03
	.byte		N44   , Dn4 
	.byte	W44
	.byte	W01
	.byte	PEND
bgm_dooro1_5_002:
	.byte		N03   , An3 , v056
	.byte	W03
	.byte		N44   , Cs4 
	.byte	W44
	.byte	W01
	.byte		N12   , An2 , v084
	.byte	W24
	.byte		N06   , En3 , v056
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte	PEND
	.byte		N06   , Dn3 , v048
	.byte	W12
	.byte		        An2 
	.byte	W24
	.byte		        Fs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W24
	.byte		N24   , Dn3 , v060
	.byte	W24
	.byte	PATT
	 .word	bgm_dooro1_5_000
	.byte	PATT
	 .word	bgm_dooro1_5_001
	.byte	PATT
	 .word	bgm_dooro1_5_002
	.byte	W48
	.byte		VOICE , 24
	.byte		N03   , Dn4 , v044
	.byte	W03
	.byte		N21   , Bn4 , v052
	.byte	W21
	.byte		N03   , Dn3 , v044
	.byte	W03
	.byte		N21   , Bn3 , v052
	.byte	W21
	.byte	W48
	.byte		N03   , An3 , v044
	.byte	W03
	.byte		N21   , Fs4 , v052
	.byte	W21
	.byte		N03   , An2 , v044
	.byte	W03
	.byte		N21   , Fs3 , v052
	.byte	W21
	.byte		VOICE , 48
	.byte		VOL   , 79*bgm_dooro1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Bn2 , v108
	.byte	W06
	.byte		VOL   , 64*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        49*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        32*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        35*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        39*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        43*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        47*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        51*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        59*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        62*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        67*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        71*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        78*bgm_dooro1_mvl/mxv
	.byte	W02
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N48   , Cs3 
	.byte	W24
	.byte		VOL   , 73*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        66*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        60*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        43*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte	W48
	.byte		VOICE , 24
	.byte		PAN   , c_v+32
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N03   , Dn4 , v044
	.byte	W03
	.byte		N21   , Bn4 , v052
	.byte	W21
	.byte		N03   , Gn4 , v044
	.byte	W03
	.byte		N21   , Dn5 , v052
	.byte	W21
	.byte	W48
	.byte		N03   , An3 , v044
	.byte	W03
	.byte		N21   , Fs4 , v052
	.byte	W21
	.byte		N03   , Dn4 , v044
	.byte	W03
	.byte		N21   , An4 , v052
	.byte	W21
	.byte		VOICE , 48
	.byte		VOL   , 79*bgm_dooro1_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , As2 , v108
	.byte	W06
	.byte		VOL   , 74*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        63*bgm_dooro1_mvl/mxv
	.byte	W05
	.byte		        53*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        57*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        60*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        62*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        64*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        67*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        69*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        71*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        74*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        76*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        78*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		        72*bgm_dooro1_mvl/mxv
	.byte		N96   , An2 
	.byte	W06
	.byte		VOL   , 63*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        54*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        42*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        39*bgm_dooro1_mvl/mxv
	.byte	W03
	.byte		        42*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        48*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        55*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        61*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        68*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        74*bgm_dooro1_mvl/mxv
	.byte	W05
	.byte		        74*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        59*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        44*bgm_dooro1_mvl/mxv
	.byte	W07
	.byte		        28*bgm_dooro1_mvl/mxv
	.byte	W06
	.byte		        13*bgm_dooro1_mvl/mxv
	.byte	W08
	.byte	GOTO
	 .word	bgm_dooro1_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_dooro1_6:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte		LFOS  , 28
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte	W12
bgm_dooro1_6_B1:
	.byte		VOICE , 74
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
bgm_dooro1_6_000:
	.byte		N48   , Cs5 , v032
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 70*bgm_dooro1_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 70*bgm_dooro1_mvl/mxv
	.byte	W12
	.byte	PEND
bgm_dooro1_6_001:
	.byte		MOD   , 0
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte		N03   , Cs5 , v032
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W24
	.byte		        An4 
	.byte	W48
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_dooro1_6_000
	.byte	PATT
	 .word	bgm_dooro1_6_001
	.byte	W96
	.byte	W48
	.byte		N06   , Dn5 , v032
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N48   , Gn5 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N24   , En5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N06   , En5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N36   , En5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W24
	.byte	W03
	.byte		        0
	.byte	W09
	.byte	W96
	.byte	W96
	.byte		N36   , As5 
	.byte	W18
	.byte		MOD   , 4
	.byte	W18
	.byte		        0
	.byte		N12   , An5 
	.byte	W12
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N78   , An5 
	.byte	W24
	.byte		MOD   , 4
	.byte	W54
	.byte		        0
	.byte	W18
	.byte	GOTO
	 .word	bgm_dooro1_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_dooro1_7:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte		VOL   , 68*bgm_dooro1_mvl/mxv
	.byte	W12
bgm_dooro1_7_B1:
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_dooro1_7_000:
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro1_7_000
	.byte	PATT
	 .word	bgm_dooro1_7_000
	.byte		N06   , Gs4 , v040
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v040
	.byte	W12
	.byte		        Gs4 , v032
	.byte	W12
	.byte		        Gs4 , v040
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	bgm_dooro1_7_000
	.byte	PATT
	 .word	bgm_dooro1_7_000
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W36
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W36
	.byte		        Gs4 , v032
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W24
	.byte	GOTO
	 .word	bgm_dooro1_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_dooro1_8:
	.byte	KEYSH , bgm_dooro1_key+0
	.byte		VOL   , 80*bgm_dooro1_mvl/mxv
	.byte	W12
bgm_dooro1_8_B1:
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		N06   , En3 , v060
	.byte	W24
	.byte		        Fs2 , v064
	.byte	W18
	.byte		        Dn3 , v068
	.byte	W06
	.byte		        En3 , v060
	.byte	W24
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W06
	.byte		N06   
	.byte	W06
bgm_dooro1_8_000:
	.byte		N06   , En3 , v060
	.byte	W24
	.byte		        Fs2 , v064
	.byte	W24
	.byte		        En3 , v060
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
bgm_dooro1_8_001:
	.byte		N06   , En3 , v060
	.byte	W24
	.byte		        Fs2 , v064
	.byte	W18
	.byte		        Dn3 , v068
	.byte	W06
	.byte		        En3 , v060
	.byte	W24
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro1_8_000
	.byte	PATT
	 .word	bgm_dooro1_8_001
	.byte	PATT
	 .word	bgm_dooro1_8_000
	.byte	PATT
	 .word	bgm_dooro1_8_001
	.byte		N06   , En3 , v060
	.byte	W24
	.byte		        Fs2 , v064
	.byte	W24
	.byte		        En3 , v060
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
bgm_dooro1_8_002:
	.byte		N06   , Cn1 , v112
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte		N06   
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W09
	.byte		BEND  , c_v+61
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_dooro1_8_002
bgm_dooro1_8_003:
	.byte		N06   , Cn1 , v112
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_dooro1_8_002
	.byte	PATT
	 .word	bgm_dooro1_8_003
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		PAN   , c_v+47
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v040
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W24
	.byte	GOTO
	 .word	bgm_dooro1_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_dooro1:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_dooro1_pri	@ Priority
	.byte	bgm_dooro1_rev	@ Reverb.

	.word	bgm_dooro1_grp

	.word	bgm_dooro1_1
	.word	bgm_dooro1_2
	.word	bgm_dooro1_3
	.word	bgm_dooro1_4
	.word	bgm_dooro1_5
	.word	bgm_dooro1_6
	.word	bgm_dooro1_7
	.word	bgm_dooro1_8

	.end
