	.include "MPlayDef.s"

	.equ	mus_ajito_grp, voicegroup_868BE74
	.equ	mus_ajito_pri, 0
	.equ	mus_ajito_rev, reverb_set+50
	.equ	mus_ajito_mvl, 127
	.equ	mus_ajito_key, 0
	.equ	mus_ajito_tbs, 1
	.equ	mus_ajito_exg, 0
	.equ	mus_ajito_cmp, 1

	.section .rodata
	.global	mus_ajito
	.align	2

@********************** Track  1 **********************@

mus_ajito_1:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_1_B1:
	.byte	TEMPO , 118*mus_ajito_tbs/2
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_ajito_mvl/mxv
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		VOICE , 126
	.byte		N09   , Gn5 , v100
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		N09   , Gn5 
	.byte	W12
mus_ajito_1_000:
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		VOICE , 126
	.byte		N09   , Gn5 , v100
	.byte	W12
	.byte		VOICE , 127
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		N09   , Gn5 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	PATT
	 .word	mus_ajito_1_000
	.byte	GOTO
	 .word	mus_ajito_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_ajito_2:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_2_B1:
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*mus_ajito_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 2
	.byte	W96
mus_ajito_2_000:
	.byte	W72
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte	PEND
	.byte		TIE   , Ds5 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte	W96
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		N03   , Gn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		TIE   , Ds5 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W12
	.byte		        Gn5 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte		VOICE , 17
	.byte		N18   , Fn5 
	.byte	W18
	.byte		TIE   , Cn5 
	.byte	W78
	.byte	W48
	.byte		EOT   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N18   , Dn5 
	.byte	W18
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N11   , Gs4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W54
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N96   , Ds5 
	.byte	W96
	.byte		N06   , Gn5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte	W96
	.byte	PATT
	 .word	mus_ajito_2_000
	.byte		N36   , Ds5 , v112
	.byte	W36
	.byte	W03
	.byte		N03   , En5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		N15   , Gn5 
	.byte	W15
	.byte		N03   , Fs5 
	.byte	W03
	.byte		N15   , Gn5 
	.byte	W15
	.byte		N03   , Fs5 
	.byte	W03
	.byte		N60   , Gn5 
	.byte	W12
	.byte	W48
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte	GOTO
	 .word	mus_ajito_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_ajito_3:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_3_B1:
	.byte		VOICE , 36
	.byte		LFOS  , 44
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 84*mus_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Cn1 , v112
	.byte	W18
	.byte		N03   , Cn1 , v088
	.byte	W18
	.byte		N12   , Bn1 , v124
	.byte	W06
	.byte		BEND  , c_v+32
	.byte	W06
	.byte		        c_v+0
	.byte	W48
mus_ajito_3_000:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Cn1 , v088
	.byte	W24
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 35
	.byte	W12
	.byte		N06   , Gn1 , v092
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte	PEND
mus_ajito_3_001:
	.byte		VOICE , 36
	.byte		BEND  , c_v+0
	.byte		N12   , Cn1 , v112
	.byte	W18
	.byte		N03   , Cn1 , v088
	.byte	W18
	.byte		N12   , Bn1 , v124
	.byte	W06
	.byte		BEND  , c_v+32
	.byte	W06
	.byte		        c_v+0
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_ajito_3_000
	.byte	PATT
	 .word	mus_ajito_3_001
	.byte	PATT
	 .word	mus_ajito_3_000
	.byte	PATT
	 .word	mus_ajito_3_001
	.byte	PATT
	 .word	mus_ajito_3_000
	.byte	PATT
	 .word	mus_ajito_3_001
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Cn1 , v088
	.byte	W24
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   , Fn2 , v112
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
mus_ajito_3_002:
	.byte		VOICE , 36
	.byte		BEND  , c_v+0
	.byte		N12   , Fn1 , v112
	.byte	W18
	.byte		N03   , Fn1 , v088
	.byte	W18
	.byte		N12   , En2 , v124
	.byte	W06
	.byte		BEND  , c_v+32
	.byte	W06
	.byte		        c_v+0
	.byte	W48
	.byte	PEND
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N12   , Fn1 , v088
	.byte	W24
	.byte		N03   , Fn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 35
	.byte	W12
	.byte		N06   , Cn2 , v092
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte	PATT
	 .word	mus_ajito_3_002
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N12   , Fn1 , v088
	.byte	W24
	.byte		N03   , Fn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W12
	.byte		        Fn1 , v076
	.byte	W06
	.byte		N12   , En2 , v124
	.byte	W06
	.byte		BEND  , c_v+35
	.byte	W06
	.byte		        c_v+0
	.byte	W12
	.byte	PATT
	 .word	mus_ajito_3_001
	.byte	PATT
	 .word	mus_ajito_3_000
	.byte	PATT
	 .word	mus_ajito_3_001
	.byte	PATT
	 .word	mus_ajito_3_000
	.byte	PATT
	 .word	mus_ajito_3_001
	.byte	PATT
	 .word	mus_ajito_3_000
	.byte	GOTO
	 .word	mus_ajito_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_ajito_4:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_4_B1:
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_ajito_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 2
	.byte	W96
mus_ajito_4_000:
	.byte	W72
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte	PEND
	.byte		TIE   , Cn5 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte	W96
	.byte	W60
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		TIE   , Cn5 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte		N18   
	.byte	W18
	.byte		N84   , Gs4 
	.byte	W78
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , As4 
	.byte	W18
	.byte		N06   , Gs4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W30
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N48   , Cn5 
	.byte	W54
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte	W96
	.byte	PATT
	 .word	mus_ajito_4_000
	.byte		N96   , Cn5 , v112
	.byte	W96
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte	GOTO
	 .word	mus_ajito_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_ajito_5:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_5_B1:
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 2
	.byte		VOL   , 42*mus_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		MOD   , 30
	.byte		BEND  , c_v+0
	.byte		N03   , Bn1 , v092
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W06
	.byte		N06   , Cn2 , v127
	.byte	W06
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N06   , Bn1 , v092
	.byte	W06
	.byte		N03   , Cn2 , v084
	.byte	W06
	.byte		N06   , Cn2 , v096
	.byte	W06
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N02   , Cn2 , v112
	.byte	W04
	.byte		        Cn2 , v084
	.byte	W04
	.byte		        Cn2 , v096
	.byte	W04
	.byte		N06   , Bn1 , v120
	.byte	W06
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N06   , Cn2 , v096
	.byte	W06
	.byte		N03   , Cn2 , v084
	.byte	W06
	.byte		N06   , Bn1 , v096
	.byte	W06
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , Cn2 , v096
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W06
	.byte		N06   , Cn2 , v116
	.byte	W06
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		        Ds2 , v112
	.byte	W06
	.byte		        Ds2 , v076
	.byte	W06
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		N03   , Ds2 , v080
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N48   , Gn2 , v112
	.byte	W15
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v-7
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-13
	.byte	W05
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-23
	.byte	W04
	.byte		        c_v-29
	.byte	W02
	.byte		        c_v-38
	.byte	W03
	.byte		        c_v-47
	.byte	W03
	.byte		        c_v-62
	.byte	W04
	.byte		MOD   , 2
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
	.byte	W03
	.byte		VOL   , 31*mus_ajito_mvl/mxv
	.byte	W92
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_ajito_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_ajito_6:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_6_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v-61
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 2
	.byte		VOL   , 37*mus_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
mus_ajito_6_000:
	.byte	W72
	.byte		N03   , An1 , v112
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte	PEND
	.byte		TIE   , As2 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		VOICE , 84
	.byte		N03   , Dn2 , v092
	.byte	W06
	.byte		        Ds2 , v084
	.byte	W06
	.byte		N06   , Ds2 , v127
	.byte	W06
	.byte		N03   , Ds2 , v080
	.byte	W06
	.byte		N06   , Dn2 , v092
	.byte	W06
	.byte		N03   , Ds2 , v084
	.byte	W06
	.byte		N06   , Ds2 , v096
	.byte	W06
	.byte		N03   , Ds2 , v080
	.byte	W06
	.byte		N02   , Ds2 , v112
	.byte	W04
	.byte		        Ds2 , v084
	.byte	W04
	.byte		        Ds2 , v096
	.byte	W04
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		N03   , Ds2 , v080
	.byte	W06
	.byte		N06   , Ds2 , v096
	.byte	W06
	.byte		N03   , Ds2 , v084
	.byte	W06
	.byte		N06   , Dn2 , v096
	.byte	W06
	.byte		N03   , Ds2 , v080
	.byte	W06
	.byte		VOICE , 80
	.byte		N03   , Ds2 , v096
	.byte	W06
	.byte		        Ds2 , v084
	.byte	W06
	.byte		N06   , Ds2 , v116
	.byte	W06
	.byte		N03   , Ds2 , v080
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v076
	.byte	W06
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		N03   , Gn2 , v080
	.byte	W06
	.byte		N24   , Cn3 , v112
	.byte	W24
	.byte		N03   , An1 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		N36   , As2 
	.byte	W36
	.byte	W03
	.byte		N03   , Cn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N36   , Ds3 
	.byte	W36
	.byte	W03
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N48   , As3 
	.byte	W48
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		TIE   , As2 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte	W96
	.byte	PATT
	 .word	mus_ajito_6_000
	.byte		TIE   , As2 , v112
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte	GOTO
	 .word	mus_ajito_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_ajito_7:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_7_B1:
	.byte		VOICE , 81
	.byte		PAN   , c_v+63
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 2
	.byte		VOL   , 37*mus_ajito_mvl/mxv
	.byte	W96
mus_ajito_7_000:
	.byte	W72
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte	PEND
	.byte		TIE   , Ds3 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   , Cn1 , v088
	.byte	W18
	.byte		N12   , Bn1 , v124
	.byte	W60
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Cn1 , v088
	.byte	W24
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , Gn1 , v092
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N36   , Ds3 
	.byte	W36
	.byte	W03
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N36   , As3 
	.byte	W36
	.byte	W03
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		TIE   , Ds3 
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte	W96
	.byte	PATT
	 .word	mus_ajito_7_000
	.byte		TIE   , Ds3 , v112
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte	GOTO
	 .word	mus_ajito_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_ajito_8:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_8_B1:
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*mus_ajito_mvl/mxv
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v068
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        Cn1 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
mus_ajito_8_000:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        En1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v068
	.byte	W06
	.byte		        En1 , v104
	.byte	W12
	.byte		        Cn1 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
mus_ajito_8_001:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v068
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        Cn1 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_ajito_8_000
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		        Cn1 , v068
	.byte	W06
	.byte		        En1 , v092
	.byte	W12
	.byte		        Cn1 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
mus_ajito_8_002:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        En1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v068
	.byte	W06
	.byte		        En1 , v104
	.byte	W09
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_ajito_8_001
	.byte	PATT
	 .word	mus_ajito_8_000
	.byte	PATT
	 .word	mus_ajito_8_001
	.byte	PATT
	 .word	mus_ajito_8_000
	.byte	PATT
	 .word	mus_ajito_8_001
	.byte	PATT
	 .word	mus_ajito_8_000
	.byte	PATT
	 .word	mus_ajito_8_001
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        En1 , v112
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v064
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v068
	.byte	W06
	.byte		        Dn1 , v084
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte	PATT
	 .word	mus_ajito_8_001
	.byte	PATT
	 .word	mus_ajito_8_000
	.byte	PATT
	 .word	mus_ajito_8_001
	.byte	PATT
	 .word	mus_ajito_8_002
	.byte	PATT
	 .word	mus_ajito_8_001
	.byte	PATT
	 .word	mus_ajito_8_000
	.byte	GOTO
	 .word	mus_ajito_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_ajito_9:
	.byte	KEYSH , mus_ajito_key+0
mus_ajito_9_B1:
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 2
	.byte		VOL   , 42*mus_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N12   , Cn1 , v112
	.byte	W18
	.byte		N03   , Cn1 , v088
	.byte	W18
	.byte		N12   , Bn1 , v124
	.byte	W60
	.byte		N06   , Cn1 , v112
	.byte	W03
	.byte		VOICE , 82
	.byte	W09
	.byte		N12   , Cn1 , v088
	.byte	W24
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , Gn1 , v092
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
mus_ajito_9_000:
	.byte		N12   , Cn1 , v112
	.byte	W18
	.byte		N03   , Cn1 , v088
	.byte	W18
	.byte		N12   , Bn1 , v124
	.byte	W60
	.byte	PEND
mus_ajito_9_001:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Cn1 , v088
	.byte	W24
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , Gn1 , v092
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
	.byte	PEND
	.byte		VOICE , 83
	.byte		VOL   , 32*mus_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W06
	.byte		N06   , Cn3 , v127
	.byte	W06
	.byte		N03   , Cn3 , v080
	.byte	W06
	.byte		N06   , Bn2 , v092
	.byte	W06
	.byte		N03   , Cn3 , v084
	.byte	W06
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		N03   , Cn3 , v080
	.byte	W06
	.byte		N02   , Cn3 , v112
	.byte	W04
	.byte		        Cn3 , v084
	.byte	W04
	.byte		        Cn3 , v096
	.byte	W04
	.byte		N06   , Bn2 , v120
	.byte	W06
	.byte		N03   , Cn3 , v080
	.byte	W06
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		N03   , Cn3 , v084
	.byte	W06
	.byte		N06   , Bn2 , v096
	.byte	W06
	.byte		N03   , Cn3 , v080
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , Cn3 , v096
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W06
	.byte		N06   , Cn3 , v116
	.byte	W06
	.byte		N03   , Cn3 , v080
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v076
	.byte	W06
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		N03   , Ds3 , v080
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N48   , Gn3 , v112
	.byte	W15
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v-7
	.byte	W03
	.byte		        c_v-10
	.byte	W04
	.byte		        c_v-13
	.byte	W05
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-23
	.byte	W04
	.byte		        c_v-29
	.byte	W02
	.byte		        c_v-38
	.byte	W03
	.byte		        c_v-47
	.byte	W03
	.byte		        c_v-62
	.byte	W04
	.byte		VOICE , 82
	.byte		VOL   , 43*mus_ajito_mvl/mxv
	.byte		BEND  , c_v+3
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   , Cn1 , v088
	.byte	W18
	.byte		N12   , Bn1 , v124
	.byte	W60
	.byte	PATT
	 .word	mus_ajito_9_001
	.byte	PATT
	 .word	mus_ajito_9_000
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N12   , Cn1 , v088
	.byte	W24
	.byte		N03   , Cn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   , Fn2 , v112
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
mus_ajito_9_002:
	.byte		N12   , Fn1 , v112
	.byte	W18
	.byte		N03   , Fn1 , v088
	.byte	W18
	.byte		N12   , En2 , v124
	.byte	W60
	.byte	PEND
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N12   , Fn1 , v088
	.byte	W24
	.byte		N03   , Fn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , Cn2 , v092
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte	PATT
	 .word	mus_ajito_9_002
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N12   , Fn1 , v088
	.byte	W24
	.byte		N03   , Fn2 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W12
	.byte		        Fn1 , v076
	.byte	W06
	.byte		N12   , En2 , v124
	.byte	W24
	.byte	PATT
	 .word	mus_ajito_9_000
	.byte	PATT
	 .word	mus_ajito_9_001
	.byte	PATT
	 .word	mus_ajito_9_000
	.byte	PATT
	 .word	mus_ajito_9_001
	.byte	PATT
	 .word	mus_ajito_9_000
	.byte	PATT
	 .word	mus_ajito_9_001
	.byte	GOTO
	 .word	mus_ajito_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_ajito:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_ajito_pri	@ Priority
	.byte	mus_ajito_rev	@ Reverb.

	.word	mus_ajito_grp

	.word	mus_ajito_1
	.word	mus_ajito_2
	.word	mus_ajito_3
	.word	mus_ajito_4
	.word	mus_ajito_5
	.word	mus_ajito_6
	.word	mus_ajito_7
	.word	mus_ajito_8
	.word	mus_ajito_9

	.end
