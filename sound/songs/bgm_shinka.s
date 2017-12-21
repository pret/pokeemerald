	.include "MPlayDef.s"

	.equ	bgm_shinka_grp, voicegroup_867B3A4
	.equ	bgm_shinka_pri, 0
	.equ	bgm_shinka_rev, reverb_set+50
	.equ	bgm_shinka_mvl, 127
	.equ	bgm_shinka_key, 0
	.equ	bgm_shinka_tbs, 1
	.equ	bgm_shinka_exg, 0
	.equ	bgm_shinka_cmp, 1

	.section .rodata
	.global	bgm_shinka
	.align	2

@********************** Track  1 **********************@

bgm_shinka_1:
	.byte	KEYSH , bgm_shinka_key+0
	.byte	TEMPO , 120*bgm_shinka_tbs/2
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_shinka_mvl/mxv
	.byte		N06   , Gn3 , v080
	.byte	W24
	.byte		        Gn3 , v056
	.byte	W24
	.byte		        Gn3 , v060
	.byte	W24
	.byte		        Gn3 , v064
	.byte	W24
bgm_shinka_1_000:
	.byte		N06   , Gn3 , v068
	.byte	W24
	.byte		        Gn3 , v072
	.byte	W24
	.byte		        Gn3 , v076
	.byte	W24
	.byte		N24   , An3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
bgm_shinka_1_001:
	.byte		MOD   , 0
	.byte		N06   , Gn3 , v080
	.byte	W24
	.byte		        Gn3 , v056
	.byte	W24
	.byte		        Gn3 , v060
	.byte	W24
	.byte		        Gn3 , v064
	.byte	W24
	.byte	PEND
bgm_shinka_1_002:
	.byte		N06   , Gn3 , v068
	.byte	W24
	.byte		        Gn3 , v072
	.byte	W24
	.byte		        Gn3 , v076
	.byte	W24
	.byte		N24   , Bn3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_1_001
	.byte	PATT
	 .word	bgm_shinka_1_000
	.byte	PATT
	 .word	bgm_shinka_1_001
	.byte	PATT
	 .word	bgm_shinka_1_002
bgm_shinka_1_B1:
bgm_shinka_1_003:
	.byte		MOD   , 0
	.byte		N06   , An3 , v080
	.byte	W24
	.byte		        An3 , v056
	.byte	W24
	.byte		        An3 , v060
	.byte	W24
	.byte		        An3 , v064
	.byte	W24
	.byte	PEND
bgm_shinka_1_004:
	.byte		N06   , An3 , v068
	.byte	W24
	.byte		        An3 , v072
	.byte	W24
	.byte		        An3 , v076
	.byte	W24
	.byte		N24   , Bn3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_1_003
bgm_shinka_1_005:
	.byte		N06   , An3 , v068
	.byte	W24
	.byte		        An3 , v072
	.byte	W24
	.byte		        An3 , v076
	.byte	W24
	.byte		N24   , Cs4 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_1_003
	.byte	PATT
	 .word	bgm_shinka_1_004
	.byte	PATT
	 .word	bgm_shinka_1_003
	.byte	PATT
	 .word	bgm_shinka_1_005
	.byte	GOTO
	 .word	bgm_shinka_1_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

bgm_shinka_2:
	.byte	KEYSH , bgm_shinka_key+0
	.byte		VOICE , 60
	.byte		PAN   , c_v+16
	.byte		VOL   , 80*bgm_shinka_mvl/mxv
	.byte		N06   , Cn3 , v080
	.byte	W24
	.byte		        Dn3 , v056
	.byte	W24
	.byte		        Cn3 , v060
	.byte	W24
	.byte		        Dn3 , v064
	.byte	W24
bgm_shinka_2_000:
	.byte		N06   , Cn3 , v068
	.byte	W24
	.byte		        Dn3 , v072
	.byte	W24
	.byte		        Cn3 , v076
	.byte	W24
	.byte		N24   , Dn3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
bgm_shinka_2_001:
	.byte		MOD   , 0
	.byte		N06   , Cn3 , v080
	.byte	W24
	.byte		        Dn3 , v056
	.byte	W24
	.byte		        Cn3 , v060
	.byte	W24
	.byte		        Dn3 , v064
	.byte	W24
	.byte	PEND
bgm_shinka_2_002:
	.byte		N06   , Cn3 , v068
	.byte	W24
	.byte		        Dn3 , v072
	.byte	W24
	.byte		        Cn3 , v076
	.byte	W24
	.byte		N24   , Fs3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_2_001
	.byte	PATT
	 .word	bgm_shinka_2_000
	.byte	PATT
	 .word	bgm_shinka_2_001
	.byte	PATT
	 .word	bgm_shinka_2_002
bgm_shinka_2_B1:
bgm_shinka_2_003:
	.byte		MOD   , 0
	.byte		N06   , Dn3 , v080
	.byte	W24
	.byte		        En3 , v056
	.byte	W24
	.byte		        Dn3 , v060
	.byte	W24
	.byte		        En3 , v064
	.byte	W24
	.byte	PEND
bgm_shinka_2_004:
	.byte		N06   , Dn3 , v068
	.byte	W24
	.byte		        En3 , v072
	.byte	W24
	.byte		        Dn3 , v076
	.byte	W24
	.byte		N24   , En3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_2_003
bgm_shinka_2_005:
	.byte		N06   , Dn3 , v068
	.byte	W24
	.byte		        En3 , v072
	.byte	W24
	.byte		        Dn3 , v076
	.byte	W24
	.byte		N24   , Gs3 , v080
	.byte	W09
	.byte		MOD   , 6
	.byte	W15
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_2_003
	.byte	PATT
	 .word	bgm_shinka_2_004
	.byte	PATT
	 .word	bgm_shinka_2_003
	.byte	PATT
	 .word	bgm_shinka_2_005
	.byte	GOTO
	 .word	bgm_shinka_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

bgm_shinka_3:
	.byte	KEYSH , bgm_shinka_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_shinka_mvl/mxv
	.byte		N06   , Cn1 , v080
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
bgm_shinka_3_000:
	.byte		N06   , Cn1 , v080
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte	PEND
	.byte		N06   , Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte	PATT
	 .word	bgm_shinka_3_000
bgm_shinka_3_001:
	.byte		N03   , Cn2 , v080
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_3_001
	.byte	PATT
	 .word	bgm_shinka_3_001
	.byte	PATT
	 .word	bgm_shinka_3_001
bgm_shinka_3_B1:
bgm_shinka_3_002:
	.byte		N03   , Dn2 , v080
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_3_002
	.byte	PATT
	 .word	bgm_shinka_3_002
	.byte	PATT
	 .word	bgm_shinka_3_002
	.byte	PATT
	 .word	bgm_shinka_3_002
	.byte	PATT
	 .word	bgm_shinka_3_002
	.byte	PATT
	 .word	bgm_shinka_3_002
	.byte	PATT
	 .word	bgm_shinka_3_002
	.byte	GOTO
	 .word	bgm_shinka_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_shinka_4:
	.byte	KEYSH , bgm_shinka_key+0
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_shinka_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v108
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v108
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
bgm_shinka_4_000:
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_shinka_4_001:
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		        Dn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W24
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v108
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_4_000
	.byte	PATT
	 .word	bgm_shinka_4_001
bgm_shinka_4_B1:
bgm_shinka_4_002:
	.byte		N12   , Dn2 , v112
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_shinka_4_003:
	.byte		N12   , Dn2 , v112
	.byte	W24
	.byte		        En2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W24
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v108
	.byte	W06
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_4_002
bgm_shinka_4_004:
	.byte		N15   , Dn2 , v112
	.byte	W24
	.byte		N12   , En2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W24
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v108
	.byte	W06
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_4_002
	.byte	PATT
	 .word	bgm_shinka_4_004
	.byte	PATT
	 .word	bgm_shinka_4_002
	.byte	PATT
	 .word	bgm_shinka_4_003
	.byte	GOTO
	 .word	bgm_shinka_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_shinka_5:
	.byte	KEYSH , bgm_shinka_key+0
	.byte		VOICE , 83
	.byte		PAN   , c_v-47
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_shinka_mvl/mxv
	.byte		N06   , Cn3 , v056
	.byte	W24
	.byte		        Dn3 , v032
	.byte	W24
	.byte		        Cn3 , v036
	.byte	W24
	.byte		        Dn3 , v040
	.byte	W24
bgm_shinka_5_000:
	.byte		N06   , Cn3 , v044
	.byte	W24
	.byte		        Dn3 , v048
	.byte	W24
	.byte		        Cn3 , v052
	.byte	W24
	.byte		N24   , Dn3 , v056
	.byte	W24
	.byte	PEND
bgm_shinka_5_001:
	.byte		N06   , Cn3 , v056
	.byte	W24
	.byte		        Dn3 , v032
	.byte	W24
	.byte		        Cn3 , v036
	.byte	W24
	.byte		        Dn3 , v040
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_5_000
	.byte	PATT
	 .word	bgm_shinka_5_001
	.byte	PATT
	 .word	bgm_shinka_5_000
	.byte	PATT
	 .word	bgm_shinka_5_001
	.byte	PATT
	 .word	bgm_shinka_5_000
bgm_shinka_5_B1:
bgm_shinka_5_002:
	.byte		N06   , Dn3 , v056
	.byte	W24
	.byte		        En3 , v032
	.byte	W24
	.byte		        Dn3 , v036
	.byte	W24
	.byte		        En3 , v040
	.byte	W24
	.byte	PEND
bgm_shinka_5_003:
	.byte		N06   , Dn3 , v044
	.byte	W24
	.byte		        En3 , v048
	.byte	W24
	.byte		        Dn3 , v052
	.byte	W24
	.byte		N24   , En3 , v056
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_5_002
	.byte	PATT
	 .word	bgm_shinka_5_003
	.byte	PATT
	 .word	bgm_shinka_5_002
	.byte	PATT
	 .word	bgm_shinka_5_003
	.byte	PATT
	 .word	bgm_shinka_5_002
	.byte	PATT
	 .word	bgm_shinka_5_003
	.byte	GOTO
	 .word	bgm_shinka_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_shinka_6:
	.byte	KEYSH , bgm_shinka_key+0
	.byte		VOICE , 84
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*bgm_shinka_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , An2 , v056
	.byte	W24
	.byte		        Bn2 , v032
	.byte	W24
	.byte		        An2 , v036
	.byte	W24
	.byte		        Bn2 , v040
	.byte	W24
bgm_shinka_6_000:
	.byte		N06   , An2 , v044
	.byte	W24
	.byte		        Bn2 , v048
	.byte	W24
	.byte		        An2 , v052
	.byte	W24
	.byte		N24   , Bn2 , v056
	.byte	W24
	.byte	PEND
bgm_shinka_6_001:
	.byte		N06   , An2 , v056
	.byte	W24
	.byte		        Bn2 , v032
	.byte	W24
	.byte		        An2 , v036
	.byte	W24
	.byte		        Bn2 , v040
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_6_000
	.byte	PATT
	 .word	bgm_shinka_6_001
	.byte	PATT
	 .word	bgm_shinka_6_000
	.byte	PATT
	 .word	bgm_shinka_6_001
	.byte	PATT
	 .word	bgm_shinka_6_000
bgm_shinka_6_B1:
bgm_shinka_6_002:
	.byte		N06   , Bn2 , v056
	.byte	W24
	.byte		        Cs3 , v032
	.byte	W24
	.byte		        Bn2 , v036
	.byte	W24
	.byte		        Cs3 , v040
	.byte	W24
	.byte	PEND
bgm_shinka_6_003:
	.byte		N06   , Bn2 , v044
	.byte	W24
	.byte		        Cs3 , v048
	.byte	W24
	.byte		        Bn2 , v052
	.byte	W24
	.byte		N24   , Cs3 , v056
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_shinka_6_002
	.byte	PATT
	 .word	bgm_shinka_6_003
	.byte	PATT
	 .word	bgm_shinka_6_002
	.byte	PATT
	 .word	bgm_shinka_6_003
	.byte	PATT
	 .word	bgm_shinka_6_002
	.byte	PATT
	 .word	bgm_shinka_6_003
	.byte	GOTO
	 .word	bgm_shinka_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_shinka_7:
	.byte		VOL   , 80*bgm_shinka_mvl/mxv
	.byte	KEYSH , bgm_shinka_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		N06   , En1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		        En1 , v076
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v100
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		N06   
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v080
	.byte	W12
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v116
	.byte	W03
	.byte		        En1 , v120
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        En1 , v100
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v096
	.byte	W12
	.byte		N03   , En1 , v127
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v116
	.byte	W03
	.byte		        En1 , v120
	.byte	W03
bgm_shinka_7_000:
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
bgm_shinka_7_001:
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v104
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
	.byte		        En1 , v112
	.byte	W03
	.byte		        En1 , v116
	.byte	W03
	.byte		        En1 , v120
	.byte	W03
	.byte	PEND
bgm_shinka_7_B1:
	.byte	PATT
	 .word	bgm_shinka_7_000
	.byte	PATT
	 .word	bgm_shinka_7_001
	.byte	PATT
	 .word	bgm_shinka_7_000
	.byte	PATT
	 .word	bgm_shinka_7_001
	.byte	PATT
	 .word	bgm_shinka_7_000
	.byte	PATT
	 .word	bgm_shinka_7_001
	.byte	PATT
	 .word	bgm_shinka_7_000
	.byte	PATT
	 .word	bgm_shinka_7_001
	.byte	GOTO
	 .word	bgm_shinka_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_shinka:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_shinka_pri	@ Priority
	.byte	bgm_shinka_rev	@ Reverb.

	.word	bgm_shinka_grp

	.word	bgm_shinka_1
	.word	bgm_shinka_2
	.word	bgm_shinka_3
	.word	bgm_shinka_4
	.word	bgm_shinka_5
	.word	bgm_shinka_6
	.word	bgm_shinka_7

	.end
