	.include "MPlayDef.s"

	.equ	mus_machi_s2_grp, voicegroup015
	.equ	mus_machi_s2_pri, 0
	.equ	mus_machi_s2_rev, reverb_set+50
	.equ	mus_machi_s2_mvl, 127
	.equ	mus_machi_s2_key, 0
	.equ	mus_machi_s2_tbs, 1
	.equ	mus_machi_s2_exg, 0
	.equ	mus_machi_s2_cmp, 1

	.section .rodata
	.global	mus_machi_s2
	.align	2

@********************** Track  1 **********************@

mus_machi_s2_1:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte	TEMPO , 126*mus_machi_s2_tbs/2
	.byte		VOICE , 56
	.byte		XCMD  , xIECV , 13
	.byte		        xIECL , 10
	.byte		LFOS  , 40
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , Ds4 , v088
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N18   , Gn4 
	.byte	W18
	.byte		        Gs4 
	.byte	W18
	.byte		N12   , As4 
	.byte	W12
mus_machi_s2_1_B1:
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		N12   , Gs4 , v088
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N42   , Fn4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W09
	.byte		VOL   , 70*mus_machi_s2_mvl/mxv
	.byte	W05
	.byte		        55*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        30*mus_machi_s2_mvl/mxv
	.byte	W05
	.byte		        6*mus_machi_s2_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W18
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Fn4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N32   , Gn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 70*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        60*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        42*mus_machi_s2_mvl/mxv
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N36   , Ds4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 70*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        59*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        50*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        34*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        11*mus_machi_s2_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		N12   , Cn5 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N42   , Gs4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W09
	.byte		VOL   , 70*mus_machi_s2_mvl/mxv
	.byte	W05
	.byte		        55*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        30*mus_machi_s2_mvl/mxv
	.byte	W05
	.byte		        6*mus_machi_s2_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W18
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Cn5 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N32   , As4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		VOL   , 70*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        60*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        42*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        80*mus_machi_s2_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N36   , Cs5 
	.byte	W15
	.byte		MOD   , 4
	.byte	W03
	.byte		VOL   , 71*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        59*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        48*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        42*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 31*mus_machi_s2_mvl/mxv
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		N18   , Gs3 , v092
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N12   , Ds2 , v100
	.byte	W18
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N12   , Cn4 , v092
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		PAN   , c_v-7
	.byte		N18   , Cn4 
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N12   , Fn2 , v100
	.byte	W18
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , An3 , v092
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-7
	.byte		N18   , As3 
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N12   , Fn2 , v100
	.byte	W18
	.byte		N24   , As2 
	.byte	W24
	.byte		PAN   , c_v-8
	.byte		N12   , Fn3 , v092
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		VOICE , 73
	.byte		PAN   , c_v+0
	.byte		N54   , Ds5 , v112
	.byte	W15
	.byte		MOD   , 4
	.byte	W36
	.byte	W03
	.byte		        0
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N54   , Fn5 
	.byte	W18
	.byte		MOD   , 4
	.byte	W36
	.byte		        0
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N54   , Cs5 
	.byte	W18
	.byte		MOD   , 4
	.byte	W36
	.byte		        0
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N18   , Cs5 
	.byte	W18
	.byte		        Cn5 
	.byte	W18
	.byte		N12   , As4 
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s2_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_machi_s2_2:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte		VOICE , 35
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		PAN   , c_v+15
	.byte		BEND  , c_v+0
	.byte		N18   , Gn1 , v127
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        As1 
	.byte	W18
	.byte		        Gs1 
	.byte	W18
	.byte		N12   , Gn1 
	.byte	W12
mus_machi_s2_2_B1:
mus_machi_s2_2_000:
	.byte		N12   , Gs1 , v127
	.byte	W24
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W24
	.byte		N24   , Ds1 
	.byte	W24
	.byte	PEND
mus_machi_s2_2_001:
	.byte		N24   , Fn1 , v127
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		N06   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	PEND
	.byte		        As1 
	.byte	W24
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Cs2 
	.byte	W24
	.byte		N24   , Gs1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	mus_machi_s2_2_000
	.byte	PATT
	 .word	mus_machi_s2_2_001
	.byte		N12   , As1 , v127
	.byte	W24
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Gs1 
	.byte	W24
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N92   , Ds1 
	.byte	W72
	.byte	W03
	.byte		VOL   , 73*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        66*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        56*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        47*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        27*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        80*mus_machi_s2_mvl/mxv
	.byte		N12   , Gs1 
	.byte	W18
	.byte		        Cn2 
	.byte	W18
	.byte		        Ds2 
	.byte	W12
	.byte		N48   , Gs1 
	.byte	W48
	.byte		N12   , Fn1 
	.byte	W18
	.byte		        An1 
	.byte	W18
	.byte		        Cn2 
	.byte	W12
	.byte		N48   , Fn1 
	.byte	W48
	.byte		N12   , As1 
	.byte	W18
	.byte		        Fn1 
	.byte	W18
	.byte		        As1 
	.byte	W12
	.byte		N48   , As0 
	.byte	W48
	.byte		N18   
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W12
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		N12   , Gs1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Cn2 , v096
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        Ds1 , v096
	.byte	W06
	.byte		N12   , Gs1 , v127
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        An1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Fn1 , v096
	.byte	W06
	.byte		N12   , An1 , v127
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W18
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N48   , Ds1 
	.byte	W48
	.byte		N18   
	.byte	W18
	.byte		        Fn1 
	.byte	W18
	.byte		N12   , Gn1 
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s2_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_machi_s2_3:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v-17
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte	W48
	.byte		N18   , Ds2 , v084
	.byte	W18
	.byte		        Fn2 
	.byte	W18
	.byte		N12   , Gn2 , v100
	.byte	W12
mus_machi_s2_3_B1:
	.byte		N48   , Gs2 , v100
	.byte	W48
	.byte		        Gn2 
	.byte	W48
	.byte		N24   , Fn2 , v084
	.byte	W24
	.byte		        Cn2 , v100
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Gs2 , v076
	.byte	W12
	.byte		        Cs3 , v100
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N48   , As2 
	.byte	W48
	.byte		        Gs2 
	.byte	W48
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , Ds2 , v088
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Gn2 , v100
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N18   , Cs3 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N18   , Cn3 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N36   , As2 
	.byte	W36
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		PAN   , c_v-8
	.byte		N12   , Cn4 , v120
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N54   , Ds4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N54   , Fn4 
	.byte	W60
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N54   , Cs4 
	.byte	W60
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N12   , Ds2 , v088
	.byte	W18
	.byte		N06   , Ds2 , v100
	.byte	W18
	.byte		N36   , Cn3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , Cn3 
	.byte	W36
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , As2 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N36   , Fn2 , v080
	.byte	W36
	.byte		N24   , Cs2 , v084
	.byte	W24
	.byte		N48   , Gs2 , v100
	.byte	W24
	.byte		VOL   , 77*mus_machi_s2_mvl/mxv
	.byte	W05
	.byte		        69*mus_machi_s2_mvl/mxv
	.byte	W07
	.byte		        63*mus_machi_s2_mvl/mxv
	.byte	W05
	.byte		        56*mus_machi_s2_mvl/mxv
	.byte	W07
	.byte		        80*mus_machi_s2_mvl/mxv
	.byte		N18   , As2 
	.byte	W18
	.byte		        Gs2 
	.byte	W18
	.byte		N12   , Gn2 
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s2_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_machi_s2_4:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte		LFOS  , 40
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 68*mus_machi_s2_mvl/mxv
	.byte	W48
	.byte		VOICE , 25
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Gn2 , v060
	.byte	W06
	.byte		N09   , As2 
	.byte	W09
	.byte		BEND  , c_v+22
	.byte	W03
	.byte		        c_v+0
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
mus_machi_s2_4_B1:
	.byte		VOICE , 27
	.byte		N42   , Ds2 , v060
	.byte	W42
	.byte		VOICE , 25
	.byte		N03   , Ds3 
	.byte	W06
	.byte		VOICE , 27
	.byte		N42   , Ds2 
	.byte	W42
	.byte		VOICE , 25
	.byte		N03   , Ds3 
	.byte	W06
mus_machi_s2_4_000:
	.byte		VOICE , 27
	.byte		N24   , Fn2 , v060
	.byte	W24
	.byte		VOICE , 25
	.byte		N06   , Gs3 , v076
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		VOICE , 27
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
	.byte		N42   
	.byte	W42
	.byte		VOICE , 25
	.byte		N03   , Fn3 
	.byte	W06
	.byte		VOICE , 27
	.byte		N42   , Fn2 
	.byte	W42
	.byte		VOICE , 25
	.byte		N03   , Fn3 
	.byte	W06
	.byte		VOICE , 27
	.byte		N24   , Gn2 
	.byte	W24
	.byte		VOICE , 25
	.byte		N06   , As3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		VOICE , 27
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N36   , Ds2 
	.byte	W42
	.byte		VOICE , 25
	.byte		N03   , Ds3 
	.byte	W06
	.byte		VOICE , 27
	.byte		N42   , Ds2 
	.byte	W42
	.byte		VOICE , 25
	.byte		N03   , Ds3 
	.byte	W06
	.byte	PATT
	 .word	mus_machi_s2_4_000
	.byte		N42   , Fn2 , v060
	.byte	W42
	.byte		VOICE , 25
	.byte		N03   , Fn3 
	.byte	W18
	.byte		VOICE , 27
	.byte		N12   
	.byte	W24
	.byte		        Cn3 
	.byte	W12
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N24   , As2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		VOICE , 25
	.byte		N18   , Gs2 , v064
	.byte	W18
	.byte		N03   , Gs2 , v076
	.byte	W18
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Gs2 , v076
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W09
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		        c_v+0
	.byte		N06   , Gs2 , v060
	.byte	W12
	.byte		N18   , An2 , v064
	.byte	W18
	.byte		N03   , An2 , v076
	.byte	W18
	.byte		N06   , An2 , v064
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , An2 , v076
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W09
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		        c_v+0
	.byte		N06   , An2 , v064
	.byte	W12
	.byte		N18   , As2 
	.byte	W18
	.byte		N03   , As2 , v076
	.byte	W18
	.byte		N06   , Cs3 , v064
	.byte	W12
	.byte		N09   , As2 
	.byte	W12
	.byte		N06   , As2 , v076
	.byte	W12
	.byte		N12   , Cn3 , v064
	.byte	W09
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		        c_v+0
	.byte		N06   , Cs3 
	.byte	W12
	.byte		N18   , Ds3 
	.byte	W18
	.byte		N03   , Ds3 , v076
	.byte	W18
	.byte		N06   , Ds3 , v064
	.byte	W12
	.byte		VOICE , 27
	.byte		N12   , As2 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N12   , Ds2 
	.byte	W12
	.byte		VOICE , 25
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Cn3 , v076
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   , Cn3 , v064
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Cn3 , v076
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		VOICE , 27
	.byte		N18   , Ds2 , v064
	.byte	W18
	.byte		VOICE , 25
	.byte		N06   , Cn3 
	.byte	W06
	.byte		VOICE , 25
	.byte		N06   , Cn3 , v068
	.byte	W06
	.byte		N03   , Cn3 , v076
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   , Cn3 , v064
	.byte	W12
	.byte		N03   , An2 
	.byte	W06
	.byte		        An2 , v076
	.byte	W06
	.byte		        Cn3 
	.byte	W12
	.byte		VOICE , 27
	.byte		N18   , Fn2 , v064
	.byte	W18
	.byte		VOICE , 25
	.byte		N06   , An2 
	.byte	W06
	.byte		VOICE , 27
	.byte		N30   , Fn2 
	.byte	W30
	.byte		VOICE , 25
	.byte		N06   , Fn3 , v076
	.byte	W12
	.byte		        Cs3 , v064
	.byte	W06
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W12
	.byte		VOICE , 27
	.byte		N12   , Fn2 , v064
	.byte	W12
	.byte		        Cs3 , v076
	.byte	W12
	.byte		N48   , Ds3 , v064
	.byte	W48
	.byte		N18   , Gn3 
	.byte	W18
	.byte		        Fn3 
	.byte	W18
	.byte		N12   , Ds3 
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s2_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_machi_s2_5:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte	W48
	.byte		VOICE , 24
	.byte		VOL   , 72*mus_machi_s2_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+0
	.byte		N06   , As2 , v048
	.byte	W06
	.byte		N09   , Ds3 , v060
	.byte	W09
	.byte		BEND  , c_v+22
	.byte	W03
	.byte		        c_v+0
	.byte		N06   , Gn3 , v048
	.byte	W06
	.byte		N03   , As2 , v060
	.byte	W06
	.byte		BEND  , c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
mus_machi_s2_5_B1:
	.byte		VOICE , 26
	.byte		N12   , Gs2 , v064
	.byte	W09
	.byte		BEND  , c_v+24
	.byte	W03
	.byte		VOICE , 24
	.byte		BEND  , c_v+0
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		VOICE , 26
	.byte		BEND  , c_v-26
	.byte		N12   , Gs3 , v052
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N03   , Gs3 , v064
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		VOICE , 26
	.byte		BEND  , c_v-24
	.byte		N12   , Gn3 , v052
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N03   , Gn3 , v064
	.byte	W06
	.byte		N06   , Gs2 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		BEND  , c_v-24
	.byte		N12   , Fn3 , v060
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N06   , Cn4 , v076
	.byte	W06
	.byte		        Gs3 , v060
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Fn3 , v064
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , As2 
	.byte	W09
	.byte		BEND  , c_v+24
	.byte	W03
	.byte		VOICE , 24
	.byte		BEND  , c_v+0
	.byte		N06   , As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		VOICE , 26
	.byte		BEND  , c_v-23
	.byte		N12   , As3 , v052
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N03   , As3 , v064
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		VOICE , 26
	.byte		BEND  , c_v-23
	.byte		N12   , Gs3 , v052
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N03   , Gs3 , v064
	.byte	W06
	.byte		N06   , As2 , v080
	.byte	W12
	.byte		VOICE , 26
	.byte		BEND  , c_v-21
	.byte		N12   , Ds3 , v064
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N06   , Ds4 , v080
	.byte	W06
	.byte		        As3 , v064
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds4 , v080
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , As3 , v064
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		VOICE , 26
	.byte		N06   , Gs2 , v048
	.byte	W06
	.byte		        Ds3 , v060
	.byte	W06
	.byte		VOICE , 24
	.byte		N06   , Gs3 , v068
	.byte	W12
	.byte		        Ds3 , v076
	.byte	W06
	.byte		VOICE , 26
	.byte		BEND  , c_v-23
	.byte		N12   , Gs3 , v052
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N03   , Gs3 , v068
	.byte	W06
	.byte		N06   , Ds3 , v044
	.byte	W12
	.byte		        Gn3 , v064
	.byte	W12
	.byte		        Ds3 , v076
	.byte	W06
	.byte		VOICE , 26
	.byte		BEND  , c_v-21
	.byte		N12   , Gn3 , v052
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N03   , Gn3 , v068
	.byte	W06
	.byte		N06   , Gs2 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Fn3 , v060
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N06   , Cn4 , v076
	.byte	W06
	.byte		        Gs3 , v060
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Fn3 , v064
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		VOICE , 24
	.byte		N06   , As2 , v048
	.byte	W06
	.byte		        Fn3 , v060
	.byte	W06
	.byte		        As3 , v068
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W06
	.byte		VOICE , 26
	.byte		BEND  , c_v-23
	.byte		N12   , As3 , v052
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N03   , As3 , v068
	.byte	W06
	.byte		N06   , Fn3 , v052
	.byte	W12
	.byte		VOICE , 26
	.byte		BEND  , c_v-23
	.byte		N12   , Gs3 , v064
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		VOICE , 24
	.byte		N06   , Cn3 , v052
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Fn3 , v060
	.byte	W09
	.byte		BEND  , c_v-20
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		N44   , As3 , v052
	.byte	W03
	.byte		BEND  , c_v-17
	.byte	W03
	.byte		        c_v+0
	.byte	W36
	.byte	W03
	.byte		N24   , Ds3 , v048
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		VOICE , 26
	.byte		N18   , Ds3 , v064
	.byte	W18
	.byte		VOICE , 24
	.byte		N03   , Ds3 , v076
	.byte	W18
	.byte		N06   , Ds3 , v064
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Ds3 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Gs2 
	.byte	W09
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		VOICE , 24
	.byte		BEND  , c_v+0
	.byte		N06   , Ds3 , v060
	.byte	W12
	.byte		VOICE , 26
	.byte		N18   , Fn3 , v064
	.byte	W18
	.byte		VOICE , 24
	.byte		N03   , Fn3 , v076
	.byte	W18
	.byte		N06   , Fn3 , v064
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Fn3 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Cn3 
	.byte	W09
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		VOICE , 24
	.byte		BEND  , c_v+0
	.byte		N06   , Fn3 , v064
	.byte	W12
	.byte		VOICE , 26
	.byte		N18   , Cs3 
	.byte	W18
	.byte		VOICE , 24
	.byte		N03   , Cs3 , v076
	.byte	W18
	.byte		N06   , Fn3 , v064
	.byte	W12
	.byte		N09   , Cs3 
	.byte	W12
	.byte		N06   , Cs3 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Ds3 , v064
	.byte	W09
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		VOICE , 24
	.byte		BEND  , c_v+0
	.byte		N06   , Fn3 
	.byte	W12
	.byte		VOICE , 26
	.byte		N18   , Gs3 
	.byte	W18
	.byte		VOICE , 24
	.byte		N03   , Gs3 , v076
	.byte	W18
	.byte		N06   , Gs3 , v064
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		VOICE , 24
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Ds3 , v076
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   , Ds3 , v064
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Ds3 , v076
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Ds3 , v076
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W06
	.byte		        Fn3 , v068
	.byte	W06
	.byte		N03   , Fn3 , v076
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   , Fn3 , v064
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Cn3 , v076
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Cn3 , v064
	.byte	W06
	.byte		        Fn3 , v076
	.byte	W06
	.byte		        Cn3 , v064
	.byte	W06
	.byte		VOICE , 26
	.byte		N12   , Cs3 
	.byte	W09
	.byte		BEND  , c_v+14
	.byte	W03
	.byte		VOICE , 24
	.byte		BEND  , c_v+0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Cs3 , v080
	.byte	W06
	.byte		N06   , Fn3 , v064
	.byte	W06
	.byte		        As3 , v076
	.byte	W12
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Cs3 
	.byte	W12
	.byte		        As3 , v076
	.byte	W12
	.byte		VOICE , 26
	.byte		N12   , As2 , v064
	.byte	W09
	.byte		BEND  , c_v+23
	.byte	W03
	.byte		        c_v+0
	.byte		N12   , Fn3 , v076
	.byte	W09
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		N44   , Gs3 , v064
	.byte	W44
	.byte	W01
	.byte		N18   , As3 
	.byte	W18
	.byte		        Gs3 
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s2_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_machi_s2_6:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte		LFOS  , 40
	.byte		PAN   , c_v+0
	.byte	W96
mus_machi_s2_6_B1:
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 74
	.byte		N42   , Gs4 , v040
	.byte	W12
	.byte		MOD   , 4
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N03   , Dn5 
	.byte	W03
	.byte		N42   , Ds5 
	.byte	W15
	.byte		MOD   , 4
	.byte	W30
	.byte		N03   , As4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , Cn5 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W24
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N32   
	.byte	W12
	.byte		MOD   , 4
	.byte	W21
	.byte		        0
	.byte	W03
	.byte		N06   
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W18
	.byte		VOL   , 71*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        59*mus_machi_s2_mvl/mxv
	.byte	W06
	.byte		        48*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        42*mus_machi_s2_mvl/mxv
	.byte	W03
	.byte		        31*mus_machi_s2_mvl/mxv
	.byte	W12
	.byte		        80*mus_machi_s2_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 81
	.byte		N36   , Ds2 , v064
	.byte	W48
	.byte		        Gn2 
	.byte	W48
	.byte		N32   , Gs2 
	.byte	W36
	.byte		VOICE , 74
	.byte		N54   , Cn5 , v040
	.byte	W24
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W09
	.byte		MOD   , 4
	.byte	W15
	.byte		        0
	.byte		N12   , An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N54   , As4 
	.byte	W18
	.byte		MOD   , 4
	.byte	W36
	.byte		        0
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N18   , Gn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N12   , Ds4 
	.byte	W12
	.byte	GOTO
	 .word	mus_machi_s2_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_machi_s2_7:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte		PAN   , c_v-48
	.byte	W96
mus_machi_s2_7_B1:
	.byte		VOICE , 127
	.byte		VOL   , 75*mus_machi_s2_mvl/mxv
	.byte		N06   , Gs4 , v040
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N09   , Gs4 , v052
	.byte	W12
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N09   , Gs4 , v052
	.byte	W12
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
mus_machi_s2_7_000:
	.byte		N06   , Gs4 , v040
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N09   , Gs4 , v052
	.byte	W12
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N09   , Gs4 , v052
	.byte	W12
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s2_7_000
	.byte	PATT
	 .word	mus_machi_s2_7_000
	.byte	PATT
	 .word	mus_machi_s2_7_000
	.byte	PATT
	 .word	mus_machi_s2_7_000
	.byte	PATT
	 .word	mus_machi_s2_7_000
mus_machi_s2_7_001:
	.byte		VOICE , 126
	.byte		N06   , Gn4 , v052
	.byte	W96
	.byte	PEND
	.byte		VOICE , 127
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
mus_machi_s2_7_002:
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
mus_machi_s2_7_003:
	.byte		N06   , Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs4 , v052
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s2_7_002
	.byte	PATT
	 .word	mus_machi_s2_7_003
	.byte	PATT
	 .word	mus_machi_s2_7_002
	.byte	PATT
	 .word	mus_machi_s2_7_003
	.byte	PATT
	 .word	mus_machi_s2_7_001
	.byte	GOTO
	 .word	mus_machi_s2_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_machi_s2_8:
	.byte	KEYSH , mus_machi_s2_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_machi_s2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Dn1 , v092
	.byte	W06
	.byte		        Dn1 , v116
	.byte	W06
mus_machi_s2_8_B1:
mus_machi_s2_8_000:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PEND
mus_machi_s2_8_001:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s2_8_000
	.byte	PATT
	 .word	mus_machi_s2_8_001
	.byte	PATT
	 .word	mus_machi_s2_8_000
	.byte	PATT
	 .word	mus_machi_s2_8_001
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W84
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Fs2 , v072
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
mus_machi_s2_8_002:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_machi_s2_8_002
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W06
	.byte		        Dn3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En3 , v056
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W48
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 , v116
	.byte	W12
	.byte		        Dn1 , v092
	.byte	W06
	.byte		        Dn1 , v116
	.byte	W06
	.byte	GOTO
	 .word	mus_machi_s2_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_machi_s2:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_machi_s2_pri	@ Priority
	.byte	mus_machi_s2_rev	@ Reverb.

	.word	mus_machi_s2_grp

	.word	mus_machi_s2_1
	.word	mus_machi_s2_2
	.word	mus_machi_s2_3
	.word	mus_machi_s2_4
	.word	mus_machi_s2_5
	.word	mus_machi_s2_6
	.word	mus_machi_s2_7
	.word	mus_machi_s2_8

	.end
