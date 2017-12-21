	.include "MPlayDef.s"

	.equ	bgm_machupi_grp, voicegroup_868D674
	.equ	bgm_machupi_pri, 0
	.equ	bgm_machupi_rev, reverb_set+50
	.equ	bgm_machupi_mvl, 127
	.equ	bgm_machupi_key, 0
	.equ	bgm_machupi_tbs, 1
	.equ	bgm_machupi_exg, 0
	.equ	bgm_machupi_cmp, 1

	.section .rodata
	.global	bgm_machupi
	.align	2

@********************** Track  1 **********************@

bgm_machupi_1:
	.byte	KEYSH , bgm_machupi_key+0
	.byte	TEMPO , 102*bgm_machupi_tbs/2
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		VOL   , 57*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        c_v-32
	.byte		N03   , Cn5 , v112
	.byte	W03
	.byte		        Cn5 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        Cn5 , v032
	.byte	W03
	.byte		        As4 , v112
	.byte	W03
	.byte		        As4 , v032
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v032
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v032
	.byte	W03
	.byte		        As4 , v112
	.byte	W03
	.byte		        As4 , v032
	.byte	W03
	.byte		N01   , Fn4 , v112
	.byte	W04
	.byte		N02   , Dn4 
	.byte	W04
	.byte		        As3 , v084
	.byte	W04
	.byte		N01   , Fn3 , v080
	.byte	W04
	.byte		        As3 , v084
	.byte	W04
	.byte		N02   , Dn4 , v088
	.byte	W04
	.byte		N01   , As4 , v112
	.byte	W04
	.byte		N02   , Fn4 , v092
	.byte	W04
	.byte		        Dn4 , v088
	.byte	W04
	.byte		N01   , As3 
	.byte	W04
	.byte		N02   , Dn4 , v092
	.byte	W04
	.byte		        Fn4 , v112
	.byte	W04
	.byte		PAN   , c_v-2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_machupi_1_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 73
	.byte		VOL   , 69*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v+24
	.byte	W72
	.byte		N03   , Gn3 , v044
	.byte	W03
	.byte		        Gs3 , v048
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        As3 , v072
	.byte	W03
	.byte		        Bn3 , v080
	.byte	W03
	.byte		        Cn4 , v092
	.byte	W03
	.byte		        Cs4 , v104
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N36   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N48   , An3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        1
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N48   , Ds4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOICE , 60
	.byte		MOD   , 0
	.byte		VOL   , 42*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v+25
	.byte		N04   , As2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N21   , Fs3 
	.byte	W21
	.byte		N03   , Gn3 
	.byte	W03
	.byte		N15   , Gs3 
	.byte	W15
	.byte		N03   
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N06   , En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		N18   , Dn3 
	.byte	W18
	.byte		N03   , Ds3 , v080
	.byte	W03
	.byte		        En3 , v088
	.byte	W03
	.byte		N24   , Fn3 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N21   , En3 
	.byte	W21
	.byte		N03   , Fn3 
	.byte	W03
	.byte		N15   , Fs3 
	.byte	W15
	.byte		N03   
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N24   , Ds3 
	.byte	W30
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N03   , En3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N03   , Fn3 , v080
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N24   , Ds3 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W96
	.byte		VOICE , 47
	.byte	W72
	.byte		N01   , As2 
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N10   , As1 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_machupi_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_machupi_2:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 28*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v084
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v096
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v096
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte		        Fn4 , v120
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
bgm_machupi_2_000:
	.byte		N03   , Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v084
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v104
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v120
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte	PEND
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v084
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		VOICE , 126
	.byte		N06   , Gs4 , v096
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v124
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte		        Fn4 , v120
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte	PATT
	 .word	bgm_machupi_2_000
	.byte		N03   , Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		VOICE , 126
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		VOICE , 127
	.byte		N06   , Gs4 , v084
	.byte	W06
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		VOICE , 126
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		VOICE , 127
	.byte		N06   , Gs4 , v096
	.byte	W06
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v124
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte		        Fn4 , v120
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
bgm_machupi_2_001:
	.byte		PAN   , c_v-63
	.byte		N03   , Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte	PEND
bgm_machupi_2_002:
	.byte		N03   , Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v124
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte		        Fn4 , v120
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte	PEND
bgm_machupi_2_003:
	.byte		N03   , Fn4 , v096
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_machupi_2_002
bgm_machupi_2_B1:
bgm_machupi_2_004:
	.byte		N03   , Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v084
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte		        Fn4 , v120
	.byte	W06
	.byte		        Fn4 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte	PATT
	 .word	bgm_machupi_2_003
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte	PATT
	 .word	bgm_machupi_2_004
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte	PATT
	 .word	bgm_machupi_2_003
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte		PAN   , c_v+0
	.byte		N01   , Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v080
	.byte	W08
	.byte		N01   
	.byte	W56
bgm_machupi_2_005:
	.byte		N01   , Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        Fn4 , v112
	.byte	W08
	.byte		        Fn4 , v080
	.byte	W08
	.byte		N01   
	.byte	W56
	.byte	PEND
	.byte	PATT
	 .word	bgm_machupi_2_005
	.byte	W96
	.byte		VOL   , 40*bgm_machupi_mvl/mxv
	.byte		N03   , Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
bgm_machupi_2_006:
	.byte		N03   , Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v104
	.byte	W03
	.byte		        Fn4 , v072
	.byte	W03
	.byte		        Fn4 , v084
	.byte	W03
	.byte		        Fn4 , v060
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte	PEND
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte		        Fn4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v076
	.byte	W06
	.byte	PATT
	 .word	bgm_machupi_2_006
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_machupi_2_001
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte	PATT
	 .word	bgm_machupi_2_004
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte	PATT
	 .word	bgm_machupi_2_004
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte	PATT
	 .word	bgm_machupi_2_004
	.byte	PATT
	 .word	bgm_machupi_2_002
	.byte	GOTO
	 .word	bgm_machupi_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_machupi_3:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 80*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v+19
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W90
	.byte		N06   , Ds1 , v120
	.byte	W06
	.byte		N24   , As1 
	.byte	W12
	.byte		MOD   , 8
	.byte		BEND  , c_v+2
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N03   , Ds1 , v036
	.byte	W12
	.byte		        Dn1 , v120
	.byte	W03
	.byte		        Dn1 , v036
	.byte	W03
	.byte		N06   , Ds1 , v120
	.byte	W06
	.byte		N03   , Ds1 , v036
	.byte	W36
	.byte		N06   , As1 , v120
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N24   , Bn1 
	.byte	W12
	.byte		MOD   , 8
	.byte		BEND  , c_v+2
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   , En1 , v036
	.byte	W12
	.byte		        Ds1 , v120
	.byte	W03
	.byte		        Ds1 , v036
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W42
	.byte		        Ds1 
	.byte	W06
	.byte		N18   , As1 
	.byte	W18
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N06   , As0 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N24   , As1 
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		MOD   , 8
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W06
bgm_machupi_3_B1:
	.byte		MOD   , 0
	.byte		VOL   , 76*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 , v120
	.byte	W18
	.byte		N06   , As1 
	.byte	W18
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		N18   , Ds1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , En1 
	.byte	W18
	.byte		N06   , Bn1 
	.byte	W18
	.byte		        En2 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
bgm_machupi_3_000:
	.byte		N06   , Ds1 , v120
	.byte	W18
	.byte		        As1 
	.byte	W18
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		N18   , Ds1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
	.byte		        Ds1 
	.byte	W18
	.byte		        As1 
	.byte	W18
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N18   , En1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 
	.byte	W18
	.byte		N06   , As1 
	.byte	W18
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		N18   , Ds1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , En1 
	.byte	W18
	.byte		N06   , Bn1 
	.byte	W18
	.byte		        En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte	PATT
	 .word	bgm_machupi_3_000
	.byte		N06   , Ds1 , v120
	.byte	W18
	.byte		        As1 
	.byte	W18
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N48   , Bn0 
	.byte	W36
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N24   , Cs1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N48   , As0 
	.byte	W36
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte	W18
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N24   , As1 
	.byte	W12
	.byte		BEND  , c_v-3
	.byte	W12
	.byte		        c_v+0
	.byte		N48   , An0 
	.byte	W36
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N24   , Bn0 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N40   , Gs0 
	.byte	W40
	.byte		N04   , Ds1 
	.byte	W08
	.byte		N24   , Gs1 
	.byte	W24
	.byte		N12   , Ds2 
	.byte	W03
	.byte		BEND  , c_v+7
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N18   , Bn0 
	.byte	W18
	.byte		N06   , Ds1 
	.byte	W18
	.byte		        Fs1 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		N18   , Bn0 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Ds1 
	.byte	W12
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N18   , As0 
	.byte	W18
	.byte		N06   , Dn1 
	.byte	W18
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N06   , As0 
	.byte	W06
	.byte		        An1 
	.byte	W03
	.byte		BEND  , c_v+7
	.byte	W03
	.byte		        c_v+0
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
	.byte		N06   , An0 
	.byte	W18
	.byte		        Cs1 
	.byte	W18
	.byte		        En1 
	.byte	W12
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N18   , An0 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N12   , Cs1 
	.byte	W03
	.byte		BEND  , c_v+7
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , An0 
	.byte	W12
	.byte		N06   , Gs0 
	.byte	W18
	.byte		        Cn1 
	.byte	W18
	.byte		        Ds1 
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W06
	.byte		N18   , Gs0 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   , Gs0 
	.byte	W12
	.byte	W96
	.byte	W96
bgm_machupi_3_001:
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		        c_v+2
	.byte	W06
	.byte		        c_v+0
	.byte	W78
	.byte	PEND
	.byte	PATT
	 .word	bgm_machupi_3_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_machupi_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_machupi_4:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 35*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		VOL   , 25*bgm_machupi_mvl/mxv
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		VOL   , 33*bgm_machupi_mvl/mxv
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte		N03   , Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		VOL   , 44*bgm_machupi_mvl/mxv
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		VOL   , 48*bgm_machupi_mvl/mxv
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		VOL   , 53*bgm_machupi_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		VOL   , 57*bgm_machupi_mvl/mxv
	.byte		N04   , Dn3 
	.byte	W04
	.byte		N02   , As2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N02   , As2 
	.byte	W04
	.byte		VOL   , 60*bgm_machupi_mvl/mxv
	.byte		N04   , Fn3 
	.byte	W04
	.byte		N02   , Dn3 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		N02   , As2 
	.byte	W04
	.byte		VOL   , 60*bgm_machupi_mvl/mxv
	.byte		N03   , Fn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		VOL   , 53*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v+27
	.byte		N09   , As3 , v127
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		N04   , En3 , v120
	.byte	W06
	.byte		N01   , Ds3 , v092
	.byte	W03
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N03   , Cs3 , v096
	.byte	W03
	.byte		N09   , Ds3 , v124
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , As2 , v120
	.byte		N01   , Fs3 
	.byte	W06
	.byte		        Cs3 , v112
	.byte		N01   , As3 
	.byte	W03
	.byte		N03   , Dn3 
	.byte		N03   , As3 
	.byte	W03
	.byte		N09   , Bn3 , v127
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v028
	.byte	W03
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v024
	.byte	W03
	.byte		N01   , En3 , v048
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v052
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		N04   , Fs3 , v120
	.byte	W06
	.byte		N01   , Fn3 , v092
	.byte	W03
	.byte		        En3 , v088
	.byte	W09
	.byte		N04   , Cs4 , v127
	.byte	W06
	.byte		N01   , Cs4 , v088
	.byte	W03
	.byte		N03   , Cs4 , v040
	.byte	W03
	.byte		N01   , Bn3 , v124
	.byte	W03
	.byte		N03   , Bn3 , v044
	.byte	W03
	.byte		N01   , Bn3 , v088
	.byte	W06
bgm_machupi_4_000:
	.byte		N09   , As3 , v127
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W03
	.byte		N03   , Ds3 , v048
	.byte	W03
	.byte		N04   , Gs3 , v112
	.byte	W06
	.byte		N01   , Fs3 , v124
	.byte	W03
	.byte		        En3 , v120
	.byte	W06
	.byte		N03   , Cn3 , v096
	.byte	W03
	.byte		N09   , Cs3 , v124
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
bgm_machupi_4_001:
	.byte		N09   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		N06   , Ds3 , v124
	.byte	W06
	.byte		N01   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W03
	.byte		N03   , Ds3 , v096
	.byte	W03
	.byte		N09   , En3 , v124
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N04   , Dn3 , v127
	.byte	W06
	.byte		N03   , En3 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte	PEND
bgm_machupi_4_B1:
bgm_machupi_4_002:
	.byte		N09   , As3 , v127
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		N04   , En3 , v120
	.byte	W06
	.byte		N01   , Ds3 , v092
	.byte	W03
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N03   , Cs3 , v096
	.byte	W03
	.byte		N09   , Ds3 , v124
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , As2 , v120
	.byte		N01   , Fs3 
	.byte	W06
	.byte		        Cs3 , v112
	.byte		N01   , As3 
	.byte	W03
	.byte		N03   , Dn3 
	.byte		N03   , As3 
	.byte	W03
	.byte	PEND
	.byte		N09   , Bn3 , v127
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v028
	.byte	W03
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v024
	.byte	W03
	.byte		N01   , En3 , v048
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v052
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		N04   , Fs3 , v120
	.byte	W06
	.byte		N01   , Fn3 , v092
	.byte	W03
	.byte		        En3 , v088
	.byte	W09
	.byte		N04   , En3 , v127
	.byte		N04   , Cs4 
	.byte	W06
	.byte		N01   , En3 , v088
	.byte		N01   , Cs4 
	.byte	W03
	.byte		N03   , Cs4 , v040
	.byte	W03
	.byte		N01   , Cs3 , v124
	.byte		N01   , Bn3 
	.byte	W03
	.byte		N03   , Bn3 , v044
	.byte	W03
	.byte		N01   , Cs3 , v088
	.byte		N01   , Bn3 
	.byte	W06
	.byte	PATT
	 .word	bgm_machupi_4_000
	.byte	PATT
	 .word	bgm_machupi_4_001
	.byte	PATT
	 .word	bgm_machupi_4_002
	.byte		N09   , Bn3 , v127
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v028
	.byte	W03
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v024
	.byte	W03
	.byte		N01   , En3 , v048
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v052
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		N04   , Ds3 , v120
	.byte	W06
	.byte		N01   , En3 , v092
	.byte	W03
	.byte		        Fn3 , v088
	.byte	W09
	.byte		N04   , Cs4 , v127
	.byte	W06
	.byte		N01   , Cs4 , v088
	.byte	W03
	.byte		N03   , Cs4 , v040
	.byte	W03
	.byte		N01   , Bn3 , v124
	.byte	W03
	.byte		N03   , Bn3 , v044
	.byte	W03
	.byte		N01   , Bn3 , v088
	.byte	W06
	.byte		N09   , As3 , v127
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		N04   , Gs3 , v112
	.byte	W06
	.byte		N01   , Fs3 , v124
	.byte	W03
	.byte		        En3 , v120
	.byte	W06
	.byte		N03   , Cn3 , v096
	.byte	W03
	.byte		N09   , Cs3 , v124
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	bgm_machupi_4_001
	.byte		N06   , Bn3 , v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , Dn3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N01   , As2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N01   , As2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N01   , Bn2 
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N01   , Bn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		N01   , As2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N01   , As2 
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , As3 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		BEND  , c_v+4
	.byte		N08   , As3 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N04   , Gs3 
	.byte	W04
	.byte		N02   , Fs3 , v068
	.byte	W04
	.byte		        Fn3 , v112
	.byte	W04
	.byte		N04   , Dn3 
	.byte	W04
	.byte		N02   , Bn2 , v076
	.byte	W04
	.byte		        As2 , v112
	.byte	W04
	.byte		PAN   , c_v+27
	.byte		N09   , As3 , v127
	.byte	W12
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		N04   , En3 , v120
	.byte	W06
	.byte		N01   , Ds3 , v092
	.byte	W03
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N03   , Cs3 , v096
	.byte	W03
	.byte		N09   , Ds3 , v124
	.byte	W12
	.byte		N01   , As2 , v120
	.byte		N01   , Fs3 
	.byte	W06
	.byte		        Cs3 , v112
	.byte		N01   , As3 
	.byte	W03
	.byte		N03   , Dn3 
	.byte		N03   , As3 
	.byte	W03
bgm_machupi_4_003:
	.byte		N09   , Bn3 , v127
	.byte	W12
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v028
	.byte	W03
	.byte		N01   , En3 , v112
	.byte	W03
	.byte		N03   , En3 , v024
	.byte	W03
	.byte		N01   , En3 , v048
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v052
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		N04   , Fs3 , v120
	.byte	W06
	.byte		N01   , Fn3 , v092
	.byte	W03
	.byte		        En3 , v088
	.byte	W09
	.byte		N04   , Cs4 , v127
	.byte	W06
	.byte		N01   , Cs4 , v088
	.byte	W03
	.byte		N03   , Cs4 , v040
	.byte	W03
	.byte		N01   , Bn3 , v124
	.byte	W03
	.byte		N03   , Bn3 , v044
	.byte	W03
	.byte		N01   , Bn3 , v088
	.byte	W06
	.byte	PEND
	.byte		N09   , As3 , v127
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W03
	.byte		N03   , Ds3 , v048
	.byte	W03
	.byte		N04   , Gs3 , v112
	.byte	W06
	.byte		N01   , Fs3 , v124
	.byte	W03
	.byte		        En3 , v120
	.byte	W06
	.byte		N03   , Cn3 , v096
	.byte	W03
	.byte		N09   , Cs3 , v124
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W09
	.byte		N01   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	bgm_machupi_4_001
	.byte		N09   , As3 , v127
	.byte	W12
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v048
	.byte	W06
	.byte		N04   , En3 , v120
	.byte	W06
	.byte		N01   , Ds3 , v092
	.byte	W03
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N03   , Cs3 , v096
	.byte	W03
	.byte		N09   , Ds3 , v124
	.byte	W12
	.byte		N01   , As2 , v120
	.byte		N01   , Fs3 
	.byte	W06
	.byte		        Cs3 , v112
	.byte		N01   , As3 
	.byte	W03
	.byte		N03   , Dn3 
	.byte		N03   , As3 
	.byte	W03
	.byte	PATT
	 .word	bgm_machupi_4_003
	.byte		N06   , Ds3 , v127
	.byte		N09   , As3 
	.byte	W12
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W03
	.byte		N03   , Ds3 , v048
	.byte	W03
	.byte		N04   , Gs3 , v112
	.byte	W06
	.byte		N01   , Fs3 , v124
	.byte	W03
	.byte		        En3 , v120
	.byte	W06
	.byte		N03   , Cn3 , v096
	.byte	W03
	.byte		N09   , Cs3 , v124
	.byte	W12
	.byte		N01   , Dn3 , v120
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N09   , Ds3 , v127
	.byte	W12
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v028
	.byte	W03
	.byte		N01   , Ds3 , v112
	.byte	W03
	.byte		N03   , Ds3 , v024
	.byte	W03
	.byte		N01   , Ds3 , v048
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Ds3 , v052
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W06
	.byte		N06   , Ds3 , v124
	.byte	W06
	.byte		N01   , Ds3 , v096
	.byte	W06
	.byte		        Ds3 , v120
	.byte	W03
	.byte		N03   , Ds3 , v096
	.byte	W03
	.byte		N09   , En3 , v124
	.byte	W12
	.byte		N04   , Dn3 , v127
	.byte	W06
	.byte		N03   , En3 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte	GOTO
	 .word	bgm_machupi_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_machupi_5:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		VOL   , 60*bgm_machupi_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v-25
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W90
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		VOL   , 53*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fs2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		N04   , Gn2 , v120
	.byte	W06
	.byte		N01   , Fs2 , v092
	.byte	W06
	.byte		        Fn2 , v088
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , Fs2 , v124
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte		N06   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Gs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W06
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N04   , As2 , v120
	.byte	W06
	.byte		N01   , An2 , v092
	.byte	W06
	.byte		        Gs2 , v088
	.byte	W06
	.byte		N04   , En3 , v127
	.byte	W06
	.byte		N01   , En3 , v088
	.byte	W06
	.byte		        Cs3 , v124
	.byte	W06
	.byte		        Cs3 , v088
	.byte	W06
bgm_machupi_5_000:
	.byte		N06   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		N04   , As2 , v112
	.byte	W06
	.byte		N01   , Gs2 , v124
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , En2 , v124
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fn2 , v120
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
bgm_machupi_5_001:
	.byte		N06   , Fs2 , v127
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		N06   , Gs2 , v124
	.byte	W06
	.byte		N01   , Gs2 , v096
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W03
	.byte		N03   , Fn2 , v096
	.byte	W03
	.byte		N09   , Gs2 , v124
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N04   , Gs2 , v127
	.byte	W06
	.byte		N03   , Gs2 , v060
	.byte	W06
	.byte	PEND
bgm_machupi_5_B1:
bgm_machupi_5_002:
	.byte		N06   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		N04   , Gn2 , v120
	.byte	W06
	.byte		N01   , Fs2 , v092
	.byte	W06
	.byte		        Fn2 , v088
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , Fs2 , v124
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W18
	.byte	PEND
	.byte		N06   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Gs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W06
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N04   , As2 , v120
	.byte	W06
	.byte		N01   , An2 , v092
	.byte	W06
	.byte		        Gs2 , v088
	.byte	W30
	.byte	PATT
	 .word	bgm_machupi_5_000
	.byte	PATT
	 .word	bgm_machupi_5_001
	.byte	PATT
	 .word	bgm_machupi_5_002
	.byte		N06   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Gs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W06
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N04   , Gn2 , v120
	.byte	W06
	.byte		N01   , Gs2 , v092
	.byte	W06
	.byte		        An2 , v088
	.byte	W06
	.byte		N04   , En3 , v127
	.byte	W06
	.byte		N01   , En3 , v088
	.byte	W06
	.byte		        Cs3 , v124
	.byte	W06
	.byte		        Cs3 , v088
	.byte	W06
	.byte		N06   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		N04   , As2 , v112
	.byte	W06
	.byte		N01   , Gs2 , v124
	.byte	W06
	.byte		        Gn2 , v120
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , En2 , v124
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fn2 , v120
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	bgm_machupi_5_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		N01   , Dn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N01   , Dn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		N01   , Ds2 
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N01   , Ds2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N01   , Dn2 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N01   , Dn2 
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		BEND  , c_v+4
	.byte		N08   , Dn3 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N04   , As2 
	.byte	W06
	.byte		N02   , Gs2 , v068
	.byte	W02
	.byte		        Fs2 , v112
	.byte	W04
	.byte		N04   , Fn2 
	.byte	W06
	.byte		N02   , Ds2 , v076
	.byte	W02
	.byte		        Dn2 , v112
	.byte	W04
bgm_machupi_5_003:
	.byte		N06   , Ds3 , v127
	.byte	W12
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		N04   , Gn2 , v120
	.byte	W06
	.byte		N01   , Fs2 , v092
	.byte	W06
	.byte		        Fn2 , v088
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , Fs2 , v124
	.byte	W24
	.byte	PEND
bgm_machupi_5_004:
	.byte		N06   , Ds3 , v127
	.byte	W12
	.byte		N01   , Gs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W06
	.byte		        Gs2 , v052
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N04   , As2 , v120
	.byte	W06
	.byte		N01   , An2 , v092
	.byte	W06
	.byte		        Gs2 , v088
	.byte	W06
	.byte		N04   , En3 , v127
	.byte	W06
	.byte		N01   , En3 , v088
	.byte	W06
	.byte		        Cs3 , v124
	.byte	W06
	.byte		        Cs3 , v088
	.byte	W06
	.byte	PEND
	.byte		N06   , Ds3 , v127
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		N04   , As2 , v112
	.byte	W06
	.byte		N01   , Gs2 , v124
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , En2 , v124
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W09
	.byte		N01   , Fn2 , v120
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	bgm_machupi_5_001
	.byte	PATT
	 .word	bgm_machupi_5_003
	.byte	PATT
	 .word	bgm_machupi_5_004
	.byte	W12
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		N04   , As2 , v112
	.byte	W06
	.byte		N01   , Gs2 , v124
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , En2 , v124
	.byte	W12
	.byte		N01   , Fn2 , v120
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Fs2 , v127
	.byte	W12
	.byte		N01   , Fs2 , v112
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v052
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W06
	.byte		N06   , Gs2 , v124
	.byte	W06
	.byte		N01   , Gs2 , v096
	.byte	W06
	.byte		        Gs2 , v120
	.byte	W03
	.byte		N03   , Fn2 , v096
	.byte	W03
	.byte		N09   , Gs2 , v124
	.byte	W12
	.byte		N04   , Gs2 , v127
	.byte	W06
	.byte		N03   , Gs2 , v060
	.byte	W06
	.byte	GOTO
	 .word	bgm_machupi_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_machupi_6:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+16
	.byte		VOL   , 40*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		VOL   , 25*bgm_machupi_mvl/mxv
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Dn5 , v112
	.byte	W03
	.byte		        Dn5 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Dn5 , v112
	.byte	W03
	.byte		        Dn5 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        As4 , v112
	.byte	W03
	.byte		        As4 , v032
	.byte	W03
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		VOL   , 33*bgm_machupi_mvl/mxv
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W03
	.byte		        Fn4 , v032
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        Cn5 , v032
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v032
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        Cn5 , v032
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v032
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		        Fn5 , v112
	.byte	W03
	.byte		        Fn5 , v032
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v032
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		VOL   , 44*bgm_machupi_mvl/mxv
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W03
	.byte		        Ds5 , v032
	.byte	W03
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Fs4 , v032
	.byte	W03
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W03
	.byte		        Ds5 , v032
	.byte	W03
	.byte		VOL   , 48*bgm_machupi_mvl/mxv
	.byte		N06   , Cn5 , v112
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Cn5 , v032
	.byte	W03
	.byte		VOL   , 53*bgm_machupi_mvl/mxv
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Dn4 , v032
	.byte	W03
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		N03   , As4 
	.byte	W03
	.byte		        As4 , v032
	.byte	W03
	.byte		VOL   , 57*bgm_machupi_mvl/mxv
	.byte		N04   , Fn4 , v112
	.byte	W04
	.byte		N02   , Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N02   , Dn4 
	.byte	W04
	.byte		VOL   , 60*bgm_machupi_mvl/mxv
	.byte		N04   , As4 
	.byte	W04
	.byte		N02   , Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N04   , As3 
	.byte	W04
	.byte		N02   , Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		VOL   , 70*bgm_machupi_mvl/mxv
	.byte		N06   , As4 , v088
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_machupi_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 31*bgm_machupi_mvl/mxv
	.byte	W06
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v060
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Fs3 
	.byte		N03   , Ds4 , v060
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Ds3 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        Fn3 , v112
	.byte	W03
	.byte		        Fn3 , v060
	.byte	W03
	.byte		PAN   , c_v-62
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		        Fn3 
	.byte		N03   , Dn4 , v060
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        En3 , v112
	.byte	W03
	.byte		        En3 , v060
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        En3 
	.byte		N03   , Cs4 , v060
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Cs3 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v060
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W03
	.byte		        Cn3 , v060
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v060
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v060
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Cn3 , v112
	.byte	W03
	.byte		        Cn3 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		PAN   , c_v-62
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 57*bgm_machupi_mvl/mxv
	.byte		N04   , Ds4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 2
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W30
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W30
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N03   , Cs4 , v076
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N24   , Ds4 , v112
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		MOD   , 0
	.byte		N04   , Fn4 
	.byte	W18
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W12
	.byte		        Fs4 
	.byte	W18
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W12
	.byte		        Fn4 
	.byte	W18
	.byte		N04   
	.byte	W18
	.byte		N04   
	.byte	W12
	.byte		        As4 
	.byte	W24
	.byte		VOICE , 24
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		VOICE , 24
	.byte		VOL   , 78*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , As3 
	.byte	W06
	.byte		BEND  , c_v-7
	.byte	W06
	.byte		        c_v+0
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , As3 , v036
	.byte	W12
	.byte		        As3 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W03
	.byte		BEND  , c_v+6
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N36   , En3 
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		        c_v+0
	.byte	W09
	.byte		MOD   , 4
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		N06   , En3 , v036
	.byte	W30
	.byte		N04   , Gs2 , v112
	.byte	W04
	.byte		N02   , Bn2 , v084
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N04   , Bn2 , v116
	.byte	W04
	.byte		N02   , En3 , v092
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		N12   , As3 , v112
	.byte	W06
	.byte		BEND  , c_v-7
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N04   , Ds2 
	.byte	W04
	.byte		N02   , Fs2 , v084
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		N04   , Ds3 , v116
	.byte	W04
	.byte		N02   , Fs3 , v092
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N48   , As3 
	.byte	W06
	.byte		BEND  , c_v-7
	.byte	W06
	.byte		        c_v+0
	.byte	W24
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , As3 , v036
	.byte	W44
	.byte	W01
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , En3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        En3 
	.byte	W06
	.byte		        Cn3 
	.byte	W03
	.byte		N09   , Cs3 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W06
	.byte		        Dn3 , v084
	.byte	W06
	.byte		N09   , Ds2 , v127
	.byte	W12
	.byte		N01   , Ds2 , v112
	.byte	W03
	.byte		N03   , Ds2 , v028
	.byte	W03
	.byte		N01   , Ds2 , v112
	.byte	W03
	.byte		N03   , Ds2 , v024
	.byte	W03
	.byte		N01   , Ds2 , v048
	.byte	W06
	.byte		        Ds2 , v120
	.byte	W06
	.byte		        Ds2 , v112
	.byte	W06
	.byte		        Ds2 , v052
	.byte	W06
	.byte		        Ds2 , v120
	.byte	W06
	.byte		N06   , Ds2 , v124
	.byte	W06
	.byte		N01   , Ds2 , v096
	.byte	W06
	.byte		        Ds2 , v120
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , En2 , v124
	.byte	W12
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte	GOTO
	 .word	bgm_machupi_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_machupi_7:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 50
	.byte		XCMD  , xIECV , 24
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-63
	.byte		VOL   , 15*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W78
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		        Cs3 , v092
	.byte	W06
	.byte		        Dn3 , v100
	.byte	W06
	.byte		VOL   , 15*bgm_machupi_mvl/mxv
	.byte		N96   , Ds3 
	.byte	W24
	.byte		VOL   , 16*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		MOD   , 3
	.byte		VOL   , 17*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 20*bgm_machupi_mvl/mxv
	.byte	W18
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 23*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Cs3 , v112
	.byte	W24
	.byte		VOL   , 26*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		MOD   , 3
	.byte		VOL   , 28*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 30*bgm_machupi_mvl/mxv
	.byte	W18
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 33*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Bn2 
	.byte	W12
	.byte		VOL   , 34*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		        36*bgm_machupi_mvl/mxv
	.byte	W15
	.byte		        38*bgm_machupi_mvl/mxv
	.byte	W09
	.byte		MOD   , 3
	.byte		VOL   , 39*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		        40*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 44*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		        45*bgm_machupi_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v-21
	.byte	W06
	.byte		VOL   , 49*bgm_machupi_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 49*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Fn2 
	.byte	W24
	.byte		VOL   , 54*bgm_machupi_mvl/mxv
	.byte		MOD   , 6
	.byte		N24   
	.byte	W24
	.byte		VOL   , 57*bgm_machupi_mvl/mxv
	.byte		MOD   , 1
	.byte		N24   , As1 
	.byte	W24
	.byte		VOL   , 48*bgm_machupi_mvl/mxv
	.byte		N24   , Dn2 
	.byte	W02
	.byte		VOL   , 50*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        53*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        59*bgm_machupi_mvl/mxv
	.byte	W04
	.byte		        64*bgm_machupi_mvl/mxv
	.byte	W02
	.byte		        68*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        73*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        77*bgm_machupi_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*bgm_machupi_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N48   , Ds4 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        1
	.byte		N03   , Dn4 , v056
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 , v052
	.byte	W03
	.byte		        Bn3 
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte	W72
	.byte		VOL   , 35*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W06
bgm_machupi_7_B1:
	.byte		VOL   , 35*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		BEND  , c_v+2
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
bgm_machupi_7_000:
	.byte		N06   , As4 , v112
	.byte	W48
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v+63
	.byte		N06   , As4 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N48   , Ds3 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        1
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Cs3 , v080
	.byte	W03
	.byte		        Cn3 , v056
	.byte	W03
	.byte		        Bn2 , v052
	.byte	W03
	.byte		BEND  , c_v+2
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		        Fs5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        As4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W36
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte	PATT
	 .word	bgm_machupi_7_000
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W03
	.byte		N54   , Ds4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 8
	.byte	W21
	.byte		        1
	.byte	W03
	.byte		VOL   , 40*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v-62
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        c_v-62
	.byte		VOL   , 23*bgm_machupi_mvl/mxv
	.byte		N03   , Ds5 
	.byte	W06
	.byte		        Bn3 
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte		        Ds5 , v112
	.byte	W03
	.byte		        Ds5 , v060
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v060
	.byte	W03
	.byte		        As4 , v112
	.byte	W03
	.byte		        As4 , v060
	.byte		N03   , Ds5 , v112
	.byte	W03
	.byte		        Fs4 
	.byte		N03   , Ds5 , v060
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        As4 , v112
	.byte	W03
	.byte		        As4 , v060
	.byte	W03
	.byte		        Ds5 , v112
	.byte	W03
	.byte		        Ds5 , v060
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte		        Dn5 , v112
	.byte	W03
	.byte		        Dn5 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		        Dn5 , v112
	.byte	W03
	.byte		        Dn5 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v060
	.byte	W03
	.byte		        An4 , v112
	.byte	W03
	.byte		        An4 , v060
	.byte		N03   , Dn5 , v112
	.byte	W03
	.byte		        Fn4 
	.byte		N03   , Dn5 , v060
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        An4 , v112
	.byte	W03
	.byte		        An4 , v060
	.byte	W03
	.byte		        Dn5 , v112
	.byte	W03
	.byte		        Dn5 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		        Cs5 , v112
	.byte	W03
	.byte		        Cs5 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Cs5 , v112
	.byte	W03
	.byte		        Cs5 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        En4 , v112
	.byte	W03
	.byte		        En4 , v060
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v060
	.byte		N03   , Cs5 , v112
	.byte	W03
	.byte		        En4 
	.byte		N03   , Cs5 , v060
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v060
	.byte	W03
	.byte		        Cs5 , v112
	.byte	W03
	.byte		        Cs5 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v060
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		        Gn4 , v060
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v060
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W03
	.byte		        Bn4 , v112
	.byte	W03
	.byte		        Bn4 , v060
	.byte	W03
	.byte	W96
	.byte	W96
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Ds2 , v112
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N48   , Ds3 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        1
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Cs3 , v080
	.byte	W03
	.byte		        Cn3 , v056
	.byte	W03
	.byte		        Bn2 , v052
	.byte	W15
	.byte		PAN   , c_v-61
	.byte	W96
	.byte	GOTO
	 .word	bgm_machupi_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_machupi_8:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 50
	.byte		XCMD  , xIECV , 24
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 15*bgm_machupi_mvl/mxv
	.byte	W78
	.byte		N06   , As3 , v080
	.byte	W06
	.byte		        An3 , v092
	.byte	W06
	.byte		        Gs3 , v100
	.byte	W06
	.byte		VOL   , 15*bgm_machupi_mvl/mxv
	.byte		N96   , Gn3 
	.byte	W24
	.byte		VOL   , 16*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		        17*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		        20*bgm_machupi_mvl/mxv
	.byte	W18
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		VOL   , 23*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Fn3 , v112
	.byte	W24
	.byte		VOL   , 26*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		        28*bgm_machupi_mvl/mxv
	.byte	W24
	.byte		        30*bgm_machupi_mvl/mxv
	.byte	W18
	.byte		BEND  , c_v-5
	.byte	W06
	.byte		VOL   , 33*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Ds3 
	.byte	W12
	.byte		VOL   , 34*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		        36*bgm_machupi_mvl/mxv
	.byte	W15
	.byte		        38*bgm_machupi_mvl/mxv
	.byte	W09
	.byte		        39*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		        40*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		        44*bgm_machupi_mvl/mxv
	.byte	W12
	.byte		        45*bgm_machupi_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v-21
	.byte	W06
	.byte		VOL   , 49*bgm_machupi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Gs2 
	.byte	W24
	.byte		VOL   , 55*bgm_machupi_mvl/mxv
	.byte		N24   , As2 
	.byte	W24
	.byte		VOL   , 59*bgm_machupi_mvl/mxv
	.byte		N24   , Fn2 
	.byte	W24
	.byte		VOL   , 48*bgm_machupi_mvl/mxv
	.byte		N24   , Gs2 
	.byte	W02
	.byte		VOL   , 50*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        53*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        59*bgm_machupi_mvl/mxv
	.byte	W04
	.byte		        64*bgm_machupi_mvl/mxv
	.byte	W02
	.byte		        68*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        73*bgm_machupi_mvl/mxv
	.byte	W03
	.byte		        77*bgm_machupi_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOL   , 39*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W06
bgm_machupi_8_B1:
	.byte		VOICE , 81
	.byte		VOL   , 40*bgm_machupi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
bgm_machupi_8_000:
	.byte		N06   , As4 , v112
	.byte	W48
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte	PEND
	.byte		N06   , As4 
	.byte	W72
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		VOICE , 83
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W06
	.byte		        Fs5 , v064
	.byte	W03
	.byte		        Bn4 , v112
	.byte	W03
	.byte		        As4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W36
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte	PATT
	 .word	bgm_machupi_8_000
	.byte		N06   , As4 , v112
	.byte	W96
	.byte		VOICE , 81
	.byte		VOL   , 40*bgm_machupi_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+63
	.byte		VOL   , 26*bgm_machupi_mvl/mxv
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W03
	.byte		        Fs3 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Fs3 
	.byte		N03   , Ds4 , v060
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v060
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        Fn3 , v112
	.byte	W03
	.byte		        Fn3 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		        Fn3 
	.byte		N03   , Dn4 , v060
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        An3 , v112
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v060
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        En3 , v112
	.byte	W03
	.byte		        En3 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        En3 
	.byte		N03   , Cs4 , v060
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v060
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v060
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v060
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W03
	.byte		        Cn3 , v060
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v060
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v060
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W03
	.byte		        Cn3 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v060
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v060
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v060
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        Cn4 , v060
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte	W96
	.byte	W72
	.byte		PAN   , c_v-61
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		N06   , Bn2 , v112
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N48   , As3 
	.byte	W48
	.byte		N06   , As3 , v036
	.byte	W12
	.byte		        As3 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N36   , En3 
	.byte	W36
	.byte		N06   , En3 , v036
	.byte	W30
	.byte		N04   , Gs2 , v112
	.byte	W04
	.byte		N02   , Bn2 , v084
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N04   , Bn2 , v116
	.byte	W04
	.byte		N02   , En3 , v092
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N04   , Ds2 
	.byte	W04
	.byte		N02   , Fs2 , v084
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		N04   , Ds3 , v116
	.byte	W04
	.byte		N02   , Fs3 , v092
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N48   , As3 
	.byte	W48
	.byte		N06   , As3 , v036
	.byte	W44
	.byte	W01
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , En3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        En3 
	.byte	W06
	.byte		        Cn3 
	.byte	W03
	.byte		N09   , Cs3 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W06
	.byte		        Dn3 , v084
	.byte	W06
	.byte		N09   , Ds2 , v127
	.byte	W12
	.byte		N01   , Ds2 , v112
	.byte	W03
	.byte		N03   , Ds2 , v028
	.byte	W03
	.byte		N01   , Ds2 , v112
	.byte	W03
	.byte		N03   , Ds2 , v024
	.byte	W03
	.byte		N01   , Ds2 , v048
	.byte	W06
	.byte		        Ds2 , v120
	.byte	W06
	.byte		        Ds2 , v112
	.byte	W06
	.byte		        Ds2 , v052
	.byte	W06
	.byte		        Ds2 , v120
	.byte	W06
	.byte		N06   , Ds2 , v124
	.byte	W06
	.byte		N01   , Ds2 , v096
	.byte	W06
	.byte		        Ds2 , v120
	.byte	W03
	.byte		N03   , Ds2 , v096
	.byte	W03
	.byte		N09   , En2 , v124
	.byte	W12
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte	GOTO
	 .word	bgm_machupi_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_machupi_9:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 60*bgm_machupi_mvl/mxv
	.byte		N06   , Cn1 , v112
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte		        Dn1 , v092
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W42
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
bgm_machupi_9_000:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W18
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_machupi_9_000
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cn1 , v072
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N03   , Dn3 , v108
	.byte	W03
	.byte		        Dn3 , v064
	.byte	W03
	.byte		        Dn3 , v080
	.byte	W03
	.byte		        Dn3 , v068
	.byte	W03
	.byte		        Dn3 , v096
	.byte	W03
	.byte		        Dn3 , v072
	.byte	W03
	.byte		        Dn3 , v120
	.byte	W03
	.byte		        Dn3 , v096
	.byte	W03
bgm_machupi_9_B1:
bgm_machupi_9_001:
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte	PEND
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 , v072
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
bgm_machupi_9_002:
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N03   , Dn3 , v108
	.byte	W03
	.byte		        Dn3 , v064
	.byte	W03
	.byte		        Dn3 , v080
	.byte	W03
	.byte		        Dn3 , v068
	.byte	W03
	.byte		        Dn3 , v096
	.byte	W03
	.byte		        Dn3 , v072
	.byte	W03
	.byte		        Dn3 , v120
	.byte	W06
	.byte	PEND
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
bgm_machupi_9_003:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PEND
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 , v072
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PATT
	 .word	bgm_machupi_9_002
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N04   , En1 
	.byte	W08
	.byte		        En1 , v076
	.byte	W08
	.byte		        En1 , v060
	.byte	W08
	.byte		        En1 , v036
	.byte	W08
	.byte		        En1 , v024
	.byte	W08
	.byte		        En1 , v004
	.byte	W08
	.byte	W48
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v076
	.byte	W08
	.byte		        En1 , v060
	.byte	W08
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        En1 , v056
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
	.byte	W48
	.byte		N04   , En1 , v112
	.byte	W08
	.byte		        En1 , v076
	.byte	W08
	.byte		        En1 , v060
	.byte	W08
	.byte		        En1 , v036
	.byte	W08
	.byte		        En1 , v024
	.byte	W08
	.byte		        En1 , v004
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v080
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En1 , v112
	.byte	W08
	.byte		        En1 , v076
	.byte	W08
	.byte		        En1 , v060
	.byte	W08
	.byte		N03   , En1 , v112
	.byte	W03
	.byte		        En1 , v052
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N24   , An2 
	.byte	W48
	.byte	PATT
	 .word	bgm_machupi_9_001
	.byte	PATT
	 .word	bgm_machupi_9_003
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 , v096
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PATT
	 .word	bgm_machupi_9_001
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PATT
	 .word	bgm_machupi_9_001
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Cn1 , v096
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	GOTO
	 .word	bgm_machupi_9_B1
	.byte	FINE

@********************** Track 10 **********************@

bgm_machupi_10:
	.byte	KEYSH , bgm_machupi_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 24
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 29*bgm_machupi_mvl/mxv
	.byte		BENDR , 12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		MOD   , 1
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N48   , As4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        1
	.byte		N03   , An4 , v056
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 , v052
	.byte	W03
	.byte		        Fs4 
	.byte	W15
	.byte	W96
bgm_machupi_10_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		MOD   , 1
	.byte		N06   , As2 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        1
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 , v048
	.byte	W15
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W24
	.byte		MOD   , 13
	.byte	W12
	.byte		        1
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W18
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W18
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N12   , As4 
	.byte	W12
	.byte		N03   , An4 
	.byte	W03
	.byte		N54   , As4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 13
	.byte	W21
	.byte		        1
	.byte	W03
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        1
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		N48   , Dn3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        1
	.byte		N04   , En3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N24   , En3 
	.byte	W24
	.byte		N36   , Ds3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        1
	.byte		N03   , En3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N48   , Gs3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        1
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
	.byte	W96
	.byte	W96
	.byte		N06   , As2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 11
	.byte	W24
	.byte		        1
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 , v048
	.byte	W15
	.byte	W96
	.byte	GOTO
	 .word	bgm_machupi_10_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_machupi:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_machupi_pri	@ Priority
	.byte	bgm_machupi_rev	@ Reverb.

	.word	bgm_machupi_grp

	.word	bgm_machupi_1
	.word	bgm_machupi_2
	.word	bgm_machupi_3
	.word	bgm_machupi_4
	.word	bgm_machupi_5
	.word	bgm_machupi_6
	.word	bgm_machupi_7
	.word	bgm_machupi_8
	.word	bgm_machupi_9
	.word	bgm_machupi_10

	.end
