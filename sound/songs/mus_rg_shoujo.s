	.include "MPlayDef.s"

	.equ	mus_rg_shoujo_grp, voicegroup143
	.equ	mus_rg_shoujo_pri, 0
	.equ	mus_rg_shoujo_rev, reverb_set+50
	.equ	mus_rg_shoujo_mvl, 127
	.equ	mus_rg_shoujo_key, 0
	.equ	mus_rg_shoujo_tbs, 1
	.equ	mus_rg_shoujo_exg, 0
	.equ	mus_rg_shoujo_cmp, 1

	.section .rodata
	.global	mus_rg_shoujo
	.align	2

@********************** Track  1 **********************@

mus_rg_shoujo_1:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte	TEMPO , 174*mus_rg_shoujo_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 51*mus_rg_shoujo_mvl/mxv
	.byte		PAN   , c_v-29
	.byte		N18   , En4 , v104
	.byte	W12
	.byte	W24
	.byte		N03   , Cn4 , v127
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
mus_rg_shoujo_1_B1:
mus_rg_shoujo_1_000:
	.byte		N03   , Gn3 , v127
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		N03   , Fs3 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , An3 , v120
	.byte	W12
	.byte	PATT
	 .word	mus_rg_shoujo_1_000
	.byte		N03   , Fn3 , v127
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_shoujo_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_shoujo_2:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_rg_shoujo_mvl/mxv
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N72   , Gn5 
	.byte	W72
mus_rg_shoujo_2_B1:
	.byte		VOICE , 24
	.byte		N12   , Gn4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W09
	.byte		N01   
	.byte	W03
	.byte		N24   , Bn4 , v127
	.byte	W06
	.byte		MOD   , 2
	.byte	W18
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W12
	.byte		N12   , Bn4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Gn4 , v096
	.byte	W12
	.byte		N12   , An4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Gn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , En4 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , En4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W09
	.byte		N01   
	.byte	W03
	.byte		N24   , An4 , v127
	.byte	W06
	.byte		MOD   , 2
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 , v096
	.byte	W12
	.byte		N12   , Fn4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N01   , En4 , v120
	.byte	W12
	.byte		N12   , En4 , v127
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Bn3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 3
	.byte	W06
	.byte		        0
	.byte		N03   , Fn4 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_shoujo_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_shoujo_3:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte		PAN   , c_v-40
	.byte	W12
	.byte	W36
	.byte		N03   , An4 , v104
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
mus_rg_shoujo_3_B1:
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte		N84   , En4 , v120
	.byte	W09
	.byte		VOL   , 11*mus_rg_shoujo_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_shoujo_mvl/mxv
	.byte	W09
	.byte		        22*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        39*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte		N84   , Ds4 
	.byte	W09
	.byte		VOL   , 11*mus_rg_shoujo_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_shoujo_mvl/mxv
	.byte	W09
	.byte		        22*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        39*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte		N84   , En4 
	.byte	W09
	.byte		VOL   , 11*mus_rg_shoujo_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_shoujo_mvl/mxv
	.byte	W09
	.byte		        22*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        39*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte		N84   , Dn4 
	.byte	W09
	.byte		VOL   , 11*mus_rg_shoujo_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_shoujo_mvl/mxv
	.byte	W09
	.byte		        22*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte		        39*mus_rg_shoujo_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_shoujo_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_shoujo_4:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 80
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 45*mus_rg_shoujo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W72
mus_rg_shoujo_4_B1:
	.byte		N06   , Cn2 , v127
	.byte	W24
	.byte		N24   , En1 , v120
	.byte	W24
	.byte		N06   , Cn2 , v127
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N15   , Gn1 , v120
	.byte	W12
	.byte		N06   , Cn2 , v127
	.byte	W24
	.byte		N24   , En1 
	.byte	W24
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N24   , En1 
	.byte	W24
	.byte		N06   , Cn2 , v120
	.byte	W24
	.byte		N24   , Dn1 , v127
	.byte	W24
	.byte		N06   , Cn2 
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_shoujo_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_shoujo_5:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 46*mus_rg_shoujo_mvl/mxv
	.byte		PAN   , c_v+47
	.byte		BEND  , c_v+1
	.byte		N12   , Gn4 , v104
	.byte	W12
	.byte		N72   , Gn5 
	.byte	W72
mus_rg_shoujo_5_B1:
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+0
	.byte		N03   , Cn3 , v120
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
mus_rg_shoujo_5_000:
	.byte		N03   , Cn3 , v127
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_shoujo_5_000
	.byte	GOTO
	 .word	mus_rg_shoujo_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_shoujo_6:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_rg_shoujo_mvl/mxv
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N72   , Gn5 
	.byte	W24
	.byte		VOL   , 41*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        36*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        31*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        25*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        20*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        14*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        9*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        7*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        5*mus_rg_shoujo_mvl/mxv
	.byte	W03
	.byte		        2*mus_rg_shoujo_mvl/mxv
	.byte	W03
mus_rg_shoujo_6_B1:
	.byte		VOL   , 0*mus_rg_shoujo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_shoujo_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_shoujo_7:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 28*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte	W72
mus_rg_shoujo_7_B1:
mus_rg_shoujo_7_000:
	.byte		N12   , Cn4 , v120
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N12   , En4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte	PEND
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Gn3 
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Cn4 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_shoujo_7_000
	.byte		N12   , Cn4 , v120
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Bn3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Gn3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Gn3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N01   , Bn3 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_shoujo_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_shoujo_8:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-1
	.byte		VOL   , 51*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte	W72
mus_rg_shoujo_8_B1:
mus_rg_shoujo_8_000:
	.byte		N03   , Cn5 , v104
	.byte	W24
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W36
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte	PEND
	.byte		        Cn5 , v112
	.byte	W24
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v076
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte	PATT
	 .word	mus_rg_shoujo_8_000
	.byte		N03   , Cn5 , v112
	.byte	W24
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v044
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_shoujo_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_shoujo_9:
	.byte	KEYSH , mus_rg_shoujo_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+2
	.byte		VOL   , 38*mus_rg_shoujo_mvl/mxv
	.byte	W12
	.byte	W72
mus_rg_shoujo_9_B1:
	.byte	W48
	.byte		N24   , Ds5 , v096
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N24   
	.byte	W48
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_shoujo_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_shoujo:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_shoujo_pri	@ Priority
	.byte	mus_rg_shoujo_rev	@ Reverb.

	.word	mus_rg_shoujo_grp

	.word	mus_rg_shoujo_1
	.word	mus_rg_shoujo_2
	.word	mus_rg_shoujo_3
	.word	mus_rg_shoujo_4
	.word	mus_rg_shoujo_5
	.word	mus_rg_shoujo_6
	.word	mus_rg_shoujo_7
	.word	mus_rg_shoujo_8
	.word	mus_rg_shoujo_9

	.end
