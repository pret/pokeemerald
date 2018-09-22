	.include "MPlayDef.s"

	.equ	mus_me_bachi_grp, voicegroup012
	.equ	mus_me_bachi_pri, 5
	.equ	mus_me_bachi_rev, reverb_set+50
	.equ	mus_me_bachi_mvl, 127
	.equ	mus_me_bachi_key, 0
	.equ	mus_me_bachi_tbs, 1
	.equ	mus_me_bachi_exg, 0
	.equ	mus_me_bachi_cmp, 1

	.section .rodata
	.global	mus_me_bachi
	.align	2

@********************** Track  1 **********************@

mus_me_bachi_1:
	.byte	KEYSH , mus_me_bachi_key+0
	.byte	W12
	.byte	TEMPO , 144*mus_me_bachi_tbs/2
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 90*mus_me_bachi_mvl/mxv
	.byte		PAN   , c_v+47
	.byte		N09   , Fn4 , v060
	.byte	W18
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N24   
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N06   , Fn3 , v072
	.byte	W06
	.byte		        As2 , v060
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 , v072
	.byte	W06
	.byte		        Fn3 , v060
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+47
	.byte		N09   , Gn4 , v056
	.byte	W18
	.byte		N03   , En4 , v060
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 , v072
	.byte	W06
	.byte		        Cn3 , v060
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        Gn3 , v060
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v-47
	.byte		N48   , An4 
	.byte	W05
	.byte		VOL   , 76*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		        65*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        68*mus_me_bachi_mvl/mxv
	.byte	W01
	.byte		MOD   , 6
	.byte	W04
	.byte		VOL   , 71*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        75*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        77*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte	W01
	.byte		VOL   , 80*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        84*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        87*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		        90*mus_me_bachi_mvl/mxv
	.byte		MOD   , 0
	.byte		N09   
	.byte	W48
	.byte	FINE

@********************** Track  2 **********************@

mus_me_bachi_2:
	.byte	KEYSH , mus_me_bachi_key+0
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_me_bachi_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		N09   , As4 , v116
	.byte	W18
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N44   
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		VOL   , 78*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        63*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        38*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        14*mus_me_bachi_mvl/mxv
	.byte	W03
	.byte		        0*mus_me_bachi_mvl/mxv
	.byte	W03
	.byte		        90*mus_me_bachi_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , An4 , v100
	.byte	W03
	.byte		N06   , As4 , v116
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N09   , Cn5 
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N44   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 78*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        63*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        38*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        14*mus_me_bachi_mvl/mxv
	.byte	W03
	.byte		        0*mus_me_bachi_mvl/mxv
	.byte	W03
	.byte		        90*mus_me_bachi_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Bn4 , v100
	.byte	W03
	.byte		N24   , Cn5 , v116
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N48   , Dn5 
	.byte	W05
	.byte		VOL   , 76*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		        65*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        68*mus_me_bachi_mvl/mxv
	.byte	W01
	.byte		MOD   , 6
	.byte	W04
	.byte		VOL   , 71*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        75*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        77*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte	W01
	.byte		VOL   , 80*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        84*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        87*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		        90*mus_me_bachi_mvl/mxv
	.byte		MOD   , 0
	.byte		N09   
	.byte	W48
	.byte	FINE

@********************** Track  3 **********************@

mus_me_bachi_3:
	.byte	KEYSH , mus_me_bachi_key+0
	.byte	W12
	.byte		VOICE , 88
	.byte		VOL   , 90*mus_me_bachi_mvl/mxv
	.byte		N09   , As1 , v080
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N18   , Dn2 
	.byte	W18
	.byte		        Cn2 
	.byte	W18
	.byte		N12   , As1 
	.byte	W12
	.byte		N09   , Cn2 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N18   , En2 
	.byte	W18
	.byte		        Dn2 
	.byte	W18
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N09   , Dn2 
	.byte	W48
	.byte	FINE

@********************** Track  4 **********************@

mus_me_bachi_4:
	.byte	KEYSH , mus_me_bachi_key+0
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 90*mus_me_bachi_mvl/mxv
	.byte		PAN   , c_v-13
	.byte		N06   , As1 , v127
	.byte	W36
	.byte		        As1 , v100
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        As1 , v127
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W36
	.byte		        Cn2 , v100
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W48
	.byte	FINE

@********************** Track  5 **********************@

mus_me_bachi_5:
	.byte	KEYSH , mus_me_bachi_key+0
	.byte	W12
	.byte		VOICE , 83
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 90*mus_me_bachi_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v+0
	.byte		N09   , Dn4 , v060
	.byte	W18
	.byte		N03   , As3 
	.byte	W06
	.byte		N24   
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v-2
	.byte		N06   , Fn3 , v052
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , As2 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Dn3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , As3 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v+0
	.byte		N09   , En4 , v060
	.byte	W18
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v-2
	.byte		N06   , Gn3 , v052
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Cn3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , En3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , En3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		VOICE , 83
	.byte		BEND  , c_v+0
	.byte		N48   , Fs4 , v060
	.byte	W05
	.byte		VOL   , 76*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		        65*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        68*mus_me_bachi_mvl/mxv
	.byte	W01
	.byte		MOD   , 6
	.byte	W04
	.byte		VOL   , 71*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        75*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        77*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte	W01
	.byte		VOL   , 80*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        84*mus_me_bachi_mvl/mxv
	.byte	W05
	.byte		        87*mus_me_bachi_mvl/mxv
	.byte	W04
	.byte		        90*mus_me_bachi_mvl/mxv
	.byte		MOD   , 0
	.byte		N09   
	.byte	W48
	.byte	FINE

@********************** Track  6 **********************@

mus_me_bachi_6:
	.byte	KEYSH , mus_me_bachi_key+0
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 90*mus_me_bachi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W68
	.byte	W01
	.byte		N03   , En4 , v080
	.byte	W03
	.byte		N06   , Fn4 , v100
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	W68
	.byte	W01
	.byte		N03   , Fs4 , v080
	.byte	W03
	.byte		N24   , Gn4 , v100
	.byte	W24
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_me_bachi_7:
	.byte	KEYSH , mus_me_bachi_key+0
	.byte	W12
	.byte		VOICE , 0
	.byte		VOL   , 90*mus_me_bachi_mvl/mxv
	.byte		N06   , En1 , v096
	.byte		N24   , Bn2 , v100
	.byte	W18
	.byte		N06   , En1 , v096
	.byte	W06
	.byte		        En1 , v120
	.byte	W12
	.byte		N03   , En1 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , En1 , v084
	.byte	W03
	.byte		        En1 , v080
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
	.byte		N06   , En1 , v096
	.byte		N24   , Bn2 , v100
	.byte	W18
	.byte		N06   , En1 , v096
	.byte	W06
	.byte		        En1 , v120
	.byte	W12
	.byte		N03   , En1 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , En1 , v084
	.byte	W03
	.byte		        En1 , v080
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
	.byte		N06   , En1 , v096
	.byte		N24   , Bn2 , v100
	.byte	W18
	.byte		N06   , En1 , v096
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v120
	.byte		N24   , Bn2 , v100
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

mus_me_bachi:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_bachi_pri	@ Priority
	.byte	mus_me_bachi_rev	@ Reverb.

	.word	mus_me_bachi_grp

	.word	mus_me_bachi_1
	.word	mus_me_bachi_2
	.word	mus_me_bachi_3
	.word	mus_me_bachi_4
	.word	mus_me_bachi_5
	.word	mus_me_bachi_6
	.word	mus_me_bachi_7

	.end
