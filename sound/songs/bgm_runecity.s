	.include "MPlayDef.s"

	.equ	bgm_runecity_grp, voicegroup_869107C
	.equ	bgm_runecity_pri, 0
	.equ	bgm_runecity_rev, reverb_set+50
	.equ	bgm_runecity_mvl, 127
	.equ	bgm_runecity_key, 0
	.equ	bgm_runecity_tbs, 1
	.equ	bgm_runecity_exg, 0
	.equ	bgm_runecity_cmp, 1

	.section .rodata
	.global	bgm_runecity
	.align	2

@********************** Track  1 **********************@

bgm_runecity_1:
	.byte	KEYSH , bgm_runecity_key+0
	.byte	TEMPO , 136*bgm_runecity_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 47*bgm_runecity_mvl/mxv
	.byte	W12
bgm_runecity_1_B1:
bgm_runecity_1_000:
	.byte		N02   , Gn5 , v112
	.byte	W16
	.byte		        Gn5 , v072
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W24
	.byte		N02   
	.byte	W24
	.byte	PEND
bgm_runecity_1_001:
	.byte		N02   , Gn5 , v112
	.byte	W16
	.byte		        Gn5 , v064
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W04
	.byte		        Gn5 , v064
	.byte	W04
	.byte		N02   
	.byte	W08
	.byte		        Gn5 , v096
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v072
	.byte	W08
	.byte		        Gn5 , v084
	.byte	W08
	.byte	PEND
bgm_runecity_1_002:
	.byte		N02   , Gn5 , v112
	.byte	W16
	.byte		        Gn5 , v072
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W16
	.byte		        Gn5 , v064
	.byte	W24
	.byte		        Gn5 , v060
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_002
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_000
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	PATT
	 .word	bgm_runecity_1_001
	.byte	GOTO
	 .word	bgm_runecity_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_runecity_2:
	.byte	KEYSH , bgm_runecity_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte	W02
	.byte		N04   , Fs4 , v112
	.byte	W04
	.byte		        Gs4 
	.byte	W02
	.byte		        As4 
	.byte	W04
bgm_runecity_2_B1:
	.byte		VOICE , 73
	.byte		N48   , Bn4 , v112
	.byte	W48
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N02   , Bn4 
	.byte	W02
	.byte		        As4 
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
bgm_runecity_2_000:
	.byte		N60   , Gs4 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        30*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        25*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        16*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        9*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte		N04   , En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte	PEND
	.byte		N48   , An4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        30*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        25*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        16*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        9*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W12
	.byte		        An4 , v112
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , An4 , v032
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Gs4 , v112
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		N08   , Fs4 , v112
	.byte	W08
	.byte		N16   , Gs4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N40   , Bn4 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte		N08   , As4 
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N02   , Bn4 
	.byte	W02
	.byte		        As4 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte	PATT
	 .word	bgm_runecity_2_000
	.byte		N48   , An4 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        30*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        25*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        20*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        15*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W12
	.byte		        An4 , v112
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte		VOICE , 58
	.byte		VOL   , 42*bgm_runecity_mvl/mxv
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N02   , Fn4 , v112
	.byte	W02
	.byte		N44   , Fs4 
	.byte	W22
	.byte		MOD   , 6
	.byte		VOL   , 37*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        34*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        29*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        24*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        18*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        13*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 43*bgm_runecity_mvl/mxv
	.byte		N02   , Dn5 , v072
	.byte	W02
	.byte		N12   , Cs5 , v076
	.byte	W12
	.byte		N02   , Cn5 , v064
	.byte	W02
	.byte		N04   , Bn4 , v068
	.byte	W08
	.byte		N48   , Fs4 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 37*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        34*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        29*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        24*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        18*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        13*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 43*bgm_runecity_mvl/mxv
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N40   , Fs4 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte	W16
	.byte		        0
	.byte		N04   , En4 
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		N16   , Ds4 , v112
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N16   , En4 , v112
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		N16   , En4 , v112
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		N40   , En4 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        33*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        26*bgm_runecity_mvl/mxv
	.byte	W08
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W04
	.byte		        En4 , v032
	.byte	W12
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte	W08
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N02   
	.byte	W02
	.byte		N14   , Dn4 
	.byte	W14
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N08   , Bn4 , v088
	.byte	W08
	.byte		N02   , As4 , v084
	.byte	W02
	.byte		        An4 , v080
	.byte	W02
	.byte		        Gs4 , v076
	.byte	W02
	.byte		        Gn4 
	.byte	W02
	.byte		N08   , Fs4 , v088
	.byte	W08
	.byte		N40   , Dn4 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W16
	.byte		        0
	.byte		N04   , En4 
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		N02   , Cs4 , v112
	.byte	W02
	.byte		N22   , Dn4 
	.byte	W22
	.byte		N24   , Cs4 
	.byte	W08
	.byte		VOL   , 40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 37*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        34*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        29*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		VOICE , 1
	.byte		MOD   , 0
	.byte		VOL   , 41*bgm_runecity_mvl/mxv
	.byte		N12   , As3 
	.byte	W12
	.byte		VOL   , 62*bgm_runecity_mvl/mxv
	.byte		N04   , Dn4 , v080
	.byte	W04
	.byte		        En4 , v092
	.byte	W04
	.byte		        Fn4 , v096
	.byte	W04
	.byte	W02
	.byte		N36   , Fs4 , v112
	.byte	W36
	.byte	W02
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N02   , Cs5 
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W08
	.byte	W02
	.byte		N44   , Fs4 
	.byte	W44
	.byte	W02
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte	W02
	.byte		N36   , Fs4 
	.byte	W36
	.byte	W02
	.byte		N04   , En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte	W02
	.byte		N16   , En4 
	.byte	W14
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W16
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte	W02
	.byte		N36   , Gn4 
	.byte	W36
	.byte	W02
	.byte		N04   , An4 
	.byte	W08
	.byte		        Gn4 
	.byte	W16
	.byte		N08   , En4 
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , As4 
	.byte	W08
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N04   , Dn5 
	.byte	W08
	.byte	W02
	.byte		N40   , Cs5 
	.byte	W36
	.byte	W02
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W08
	.byte		N02   , An4 
	.byte	W02
	.byte		N22   , As4 
	.byte	W22
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N04   , Bn4 
	.byte	W02
	.byte		VOICE , 17
	.byte	W02
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		VOL   , 57*bgm_runecity_mvl/mxv
	.byte		N56   , Fs4 
	.byte	W56
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N56   , An4 , v112
	.byte	W56
	.byte		N04   
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N40   , Cn5 
	.byte	W48
	.byte		N04   
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		        Bn4 , v112
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W04
	.byte		        An4 , v112
	.byte	W04
	.byte		        An4 , v032
	.byte	W04
	.byte		N16   , Bn4 , v112
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		N56   , Gn4 
	.byte	W56
	.byte		N04   , An4 
	.byte	W04
	.byte		        An4 , v032
	.byte	W04
	.byte		        Gn4 , v112
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N48   , Dn5 , v112
	.byte	W48
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N48   , En4 , v112
	.byte	W48
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N16   , Cs4 , v112
	.byte	W16
	.byte		N04   , En3 
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 59*bgm_runecity_mvl/mxv
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		N56   , Fs4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W32
	.byte		        0
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N56   , An4 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W32
	.byte		        0
	.byte		N04   
	.byte	W04
	.byte		        An4 , v032
	.byte	W04
	.byte		        Bn4 , v112
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W04
	.byte		N40   , Cn5 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N04   
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		        Dn5 , v112
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		        En5 , v112
	.byte	W04
	.byte		        En5 , v032
	.byte	W04
	.byte		N24   , Fs5 , v112
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		N40   , Gn5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte		N04   , An5 
	.byte	W04
	.byte		        An5 , v032
	.byte	W04
	.byte		        Gn5 , v112
	.byte	W04
	.byte		        Gn5 , v032
	.byte	W04
	.byte		        Fs5 , v112
	.byte	W04
	.byte		        Fs5 , v032
	.byte	W04
	.byte		        En5 , v112
	.byte	W04
	.byte		        En5 , v032
	.byte	W04
	.byte		        Dn5 , v112
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		N40   , Fs5 , v112
	.byte	W16
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N04   , Dn5 
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W12
	.byte		        Fs5 , v112
	.byte	W04
	.byte		        Fs5 , v032
	.byte	W04
	.byte		N40   , En5 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W16
	.byte		        0
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W04
	.byte		        En5 , v112
	.byte	W04
	.byte		        En5 , v032
	.byte	W12
	.byte		        Bn4 , v112
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W04
	.byte		N16   , Cs4 , v112
	.byte	W16
	.byte		N04   , An3 
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N16   , Dn4 , v112
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		N16   , En4 , v112
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		N16   , Fs4 , v112
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		N16   , Gs4 , v112
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		N16   , As4 , v112
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte	GOTO
	 .word	bgm_runecity_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_runecity_3:
	.byte	KEYSH , bgm_runecity_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 46*bgm_runecity_mvl/mxv
	.byte	W12
bgm_runecity_3_B1:
	.byte	W72
	.byte	W72
	.byte	W48
	.byte		N16   , En5 , v112
	.byte	W24
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W48
	.byte		N16   
	.byte	W24
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
	.byte	W72
	.byte	GOTO
	 .word	bgm_runecity_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_runecity_4:
	.byte	KEYSH , bgm_runecity_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 37*bgm_runecity_mvl/mxv
	.byte	W12
bgm_runecity_4_B1:
bgm_runecity_4_000:
	.byte		N02   , Fs2 , v112
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte	PEND
bgm_runecity_4_001:
	.byte		N02   , Fs2 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte	PEND
bgm_runecity_4_002:
	.byte		N02   , Fs2 , v112
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte	PEND
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N24   , En3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte	PATT
	 .word	bgm_runecity_4_000
	.byte	PATT
	 .word	bgm_runecity_4_001
	.byte	PATT
	 .word	bgm_runecity_4_002
	.byte		N02   , Fs2 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W48
	.byte		N02   , Fs2 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   , Cs3 
	.byte	W24
	.byte		        Cn3 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
bgm_runecity_4_003:
	.byte		N16   , Bn2 , v112
	.byte	W16
	.byte		N02   , Gs2 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N02   , En2 
	.byte	W08
	.byte		N24   , Bn2 
	.byte	W24
	.byte	PEND
	.byte		N02   , Gn2 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   , An2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		        Fn2 
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N04   , Cs2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N04   , Cs2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N08   , As2 
	.byte	W08
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		N02   , Fs2 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Fs2 
	.byte	W16
	.byte		N04   , Cs3 
	.byte	W24
	.byte		        Bn2 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Fs2 
	.byte	W16
	.byte		N04   , Cn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte	PATT
	 .word	bgm_runecity_4_003
	.byte		N02   , Gn2 , v112
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W24
	.byte		        As2 
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W16
	.byte		N02   , Gn2 
	.byte	W08
	.byte		N16   , Fs2 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W08
	.byte		N04   , As2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N08   , En3 
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N02   , An2 
	.byte	W16
	.byte		N04   , An3 
	.byte	W24
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , An3 
	.byte	W16
	.byte		N02   , An2 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		N04   , En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W08
	.byte		N08   , En3 
	.byte	W16
	.byte		N02   , Cs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W16
	.byte		N04   , En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N02   , An2 
	.byte	W08
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N02   , As2 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N02   , Fs2 
	.byte	W16
	.byte		N04   , An2 
	.byte	W24
	.byte		        Gs2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N02   , Fn2 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W24
	.byte		        En2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , Cs2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N08   , Gn2 
	.byte	W08
	.byte		N04   , En2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		N02   , Fs3 
	.byte	W16
	.byte		N04   , An3 
	.byte	W24
	.byte		        Gs3 
	.byte	W08
	.byte		N08   , An3 
	.byte	W16
	.byte		N02   , Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , Gn3 
	.byte	W16
	.byte		N02   , En3 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N16   , Ds4 
	.byte	W16
	.byte		N02   , Fs3 
	.byte	W08
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N02   , Fs3 
	.byte	W08
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N02   , Bn2 
	.byte	W16
	.byte		N04   , As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N02   , As2 
	.byte	W16
	.byte		N04   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N08   , As3 
	.byte	W08
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N08   , As3 
	.byte	W08
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte	GOTO
	 .word	bgm_runecity_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_runecity_5:
	.byte	KEYSH , bgm_runecity_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*bgm_runecity_mvl/mxv
	.byte	W12
bgm_runecity_5_B1:
bgm_runecity_5_000:
	.byte		N02   , Bn2 , v112
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		N02   , Bn2 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W08
	.byte	PEND
bgm_runecity_5_001:
	.byte		N02   , Bn2 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte	PEND
bgm_runecity_5_002:
	.byte		N02   , Bn2 , v112
	.byte	W16
	.byte		N04   , An3 
	.byte	W24
	.byte		N02   , Bn2 
	.byte	W08
	.byte		N08   , An3 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W08
	.byte	PEND
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte	PATT
	 .word	bgm_runecity_5_000
	.byte	PATT
	 .word	bgm_runecity_5_001
	.byte	PATT
	 .word	bgm_runecity_5_002
	.byte		N02   , Bn2 , v112
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N24   , Bn3 
	.byte	W48
	.byte		N02   , Dn3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W16
	.byte		N02   , Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W16
	.byte		N02   , Cs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W08
	.byte		N24   , En3 
	.byte	W24
	.byte		N02   , Dn3 
	.byte	W16
	.byte		N04   , En3 
	.byte	W24
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , En3 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N02   , An2 
	.byte	W08
	.byte		        Gs2 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N08   , As2 
	.byte	W08
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W08
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W08
	.byte		N04   , As2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N02   , Fs3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W08
	.byte		N08   , Bn3 
	.byte	W16
	.byte		N02   , Fs3 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   , As3 
	.byte	W24
	.byte		        Gs3 
	.byte	W08
	.byte		N08   , As3 
	.byte	W16
	.byte		N02   , Fs3 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   , An3 
	.byte	W24
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N02   , En3 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N02   , En3 
	.byte	W08
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N02   , En3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , Gn3 
	.byte	W16
	.byte		N02   , En3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N04   , En3 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N08   , As3 
	.byte	W08
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , Dn4 
	.byte	W16
	.byte		N02   , Fs3 
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W16
	.byte		N02   , An3 
	.byte	W08
	.byte		        Gn3 
	.byte	W16
	.byte		N04   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N02   , Ds3 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N02   , Ds3 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N02   , Cs3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W24
	.byte		        An3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N02   , An2 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N02   , Gs2 
	.byte	W16
	.byte		N04   , En3 
	.byte	W24
	.byte		        Bn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W08
	.byte		N04   , An2 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N08   , En3 
	.byte	W08
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N02   , Dn4 
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W16
	.byte		N02   , Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N04   , En4 
	.byte	W24
	.byte		        Ds4 
	.byte	W08
	.byte		N08   , En4 
	.byte	W16
	.byte		N02   , Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W16
	.byte		N04   , En4 
	.byte	W24
	.byte		        Ds4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N02   , Ds4 
	.byte	W08
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N02   , Fn3 
	.byte	W16
	.byte		N04   , Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		N02   , Cs3 
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N08   , Dn4 
	.byte	W06
	.byte		N04   , Bn3 
	.byte	W10
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , En4 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , En4 
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte	GOTO
	 .word	bgm_runecity_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_runecity_6:
	.byte	KEYSH , bgm_runecity_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 59*bgm_runecity_mvl/mxv
	.byte	W12
bgm_runecity_6_B1:
	.byte	W72
bgm_runecity_6_000:
	.byte	W24
	.byte		N04   , Fs2 , v112
	.byte	W04
	.byte		        Fs2 , v060
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W24
	.byte	PEND
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	PATT
	 .word	bgm_runecity_6_000
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
	.byte	W72
	.byte	W72
	.byte	GOTO
	 .word	bgm_runecity_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_runecity_7:
	.byte	KEYSH , bgm_runecity_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 58*bgm_runecity_mvl/mxv
	.byte		N04   , Gs1 , v112
	.byte	W06
	.byte		        Bn1 
	.byte	W02
	.byte		        Cs2 
	.byte	W04
bgm_runecity_7_B1:
	.byte		N16   , Bn1 , v112
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W24
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        Bn2 
	.byte	W24
	.byte		N04   , Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N04   , Bn1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
bgm_runecity_7_000:
	.byte		N16   , Bn1 , v112
	.byte	W16
	.byte		N04   , Cs3 
	.byte	W24
	.byte		N08   , Bn1 
	.byte	W08
	.byte		        Cs3 
	.byte	W24
	.byte	PEND
	.byte		N04   , Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N04   , Bn1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N16   , Bn1 
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W24
	.byte		        Bn1 
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W24
	.byte		N04   , Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W24
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte	PATT
	 .word	bgm_runecity_7_000
	.byte		N16   , Bn1 , v112
	.byte	W16
	.byte		N02   , Fs1 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N16   , Bn1 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W24
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W16
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N16   , As1 
	.byte	W16
	.byte		N02   , As2 
	.byte	W24
	.byte		N04   , As1 
	.byte	W08
	.byte		N08   , As2 
	.byte	W16
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N02   , An2 
	.byte	W24
	.byte		N04   , An1 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N02   , En2 
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		N16   , Gs1 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        An1 
	.byte	W16
	.byte		N08   , Gs1 
	.byte	W08
	.byte		N16   , Gn1 
	.byte	W16
	.byte		N04   , Fs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		        En2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N16   , Fs1 
	.byte	W16
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N02   
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W16
	.byte		N02   , Dn2 
	.byte	W24
	.byte		N04   , Fn1 
	.byte	W32
	.byte		N16   , Fs1 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N04   , As1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Fs2 
	.byte	W16
	.byte		        As2 
	.byte	W08
	.byte		N16   , Bn1 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W24
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N02   , Dn2 
	.byte	W08
	.byte		N16   , As1 
	.byte	W16
	.byte		N02   , As2 
	.byte	W08
	.byte		N04   , As1 
	.byte	W16
	.byte		N02   , As2 
	.byte	W08
	.byte		N08   , As1 
	.byte	W08
	.byte		N04   , Bn1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W40
	.byte		N04   
	.byte	W32
	.byte		N16   , Gs1 
	.byte	W24
	.byte		        Bn1 
	.byte	W16
	.byte		N02   , Gs1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N04   , Gs1 
	.byte	W08
	.byte		N16   , Gn1 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N02   , Bn1 
	.byte	W16
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N16   , Fs1 
	.byte	W16
	.byte		N02   , Bn1 
	.byte	W08
	.byte		N16   , Fs1 
	.byte	W16
	.byte		N02   , Bn1 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W16
	.byte		N02   , Fn2 
	.byte	W08
	.byte		N04   , Fn1 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N16   , Fs1 
	.byte	W24
	.byte		        En1 
	.byte	W16
	.byte		N04   , Fs1 
	.byte	W08
	.byte		N12   , Cs1 
	.byte	W16
	.byte		N08   , Cs2 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N02   , An1 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N04   , An1 
	.byte	W16
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N16   , Cs2 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N08   , Cs2 
	.byte	W08
	.byte		N16   , Cn2 
	.byte	W16
	.byte		N02   , An1 
	.byte	W08
	.byte		N04   , Cn2 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N04   , Cn2 
	.byte	W16
	.byte		N08   , An1 
	.byte	W08
	.byte		N16   , Bn1 
	.byte	W24
	.byte		        Cs2 
	.byte	W16
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N16   , As1 
	.byte	W16
	.byte		N04   , Gn1 
	.byte	W24
	.byte		        As1 
	.byte	W08
	.byte		N02   , Gn2 
	.byte	W16
	.byte		N08   , As1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N02   , Dn2 
	.byte	W24
	.byte		N04   , An1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N16   , Gs1 
	.byte	W40
	.byte		N04   
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N02   , Bn1 
	.byte	W08
	.byte		N16   , Gn1 
	.byte	W16
	.byte		N02   , An1 
	.byte	W08
	.byte		N16   , En1 
	.byte	W16
	.byte		N08   , Cs2 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N02   , An2 
	.byte	W24
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N06   
	.byte	W08
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N16   , Cs2 
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		        Dn2 
	.byte	W16
	.byte		        Bn1 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		N08   , Cs2 
	.byte	W08
	.byte		N16   , Cn2 
	.byte	W40
	.byte		N04   
	.byte	W32
	.byte		N16   , Bn1 
	.byte	W16
	.byte		N04   , Fs1 
	.byte	W08
	.byte		N16   , Cs2 
	.byte	W16
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N16   , Ds2 
	.byte	W16
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N16   , As1 
	.byte	W16
	.byte		N02   , Gn2 
	.byte	W08
	.byte		N04   , As1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Bn1 
	.byte	W08
	.byte		N04   , As1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   , Cs2 
	.byte	W08
	.byte		N16   , Gs1 
	.byte	W16
	.byte		N04   , Bn1 
	.byte	W08
	.byte		        Dn2 
	.byte	W16
	.byte		        Bn1 
	.byte	W08
	.byte		N16   , Gs1 
	.byte	W16
	.byte		N02   , Bn1 
	.byte	W08
	.byte		N16   , An1 
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N02   , An2 
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		N16   , Fs1 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N04   , Fs1 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N06   , Fs1 
	.byte	W08
	.byte		N04   , En1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte	GOTO
	 .word	bgm_runecity_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_runecity_8:
	.byte	KEYSH , bgm_runecity_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte		PAN   , c_v-19
	.byte		N04   , Bn3 , v112
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
bgm_runecity_8_B1:
	.byte		VOICE , 73
	.byte		N48   , Dn4 , v112
	.byte	W48
	.byte		N10   , Bn3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N60   , En4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        30*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        25*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        16*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        9*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte		N04   , As3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		N48   , Cs4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        30*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        25*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        16*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        9*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte		N04   , Dn4 
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W24
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N40   , Dn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W16
	.byte		        0
	.byte		N08   , Cs4 
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , Bn3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N40   , En4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        40*bgm_runecity_mvl/mxv
	.byte		N08   , Dn4 
	.byte	W04
	.byte		VOL   , 30*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        25*bgm_runecity_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W04
	.byte		VOL   , 16*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        9*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_runecity_mvl/mxv
	.byte		N04   , An3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		N40   , Cs4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        40*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        30*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        25*bgm_runecity_mvl/mxv
	.byte	W04
	.byte		        45*bgm_runecity_mvl/mxv
	.byte		MOD   , 0
	.byte		N08   , Bn3 
	.byte	W08
	.byte		MOD   , 0
	.byte		N04   , Dn4 
	.byte	W16
	.byte		        Cs4 
	.byte	W08
	.byte	W24
	.byte		N24   , Dn4 
	.byte	W24
	.byte		VOICE , 13
	.byte		VOL   , 39*bgm_runecity_mvl/mxv
	.byte		N08   , Fn3 , v088
	.byte	W08
	.byte		N04   , Bn3 , v096
	.byte	W08
	.byte		        Dn4 , v104
	.byte	W08
	.byte	W02
	.byte		N02   , Fs4 , v048
	.byte	W02
	.byte		N04   , Bn3 
	.byte	W04
	.byte		        Fs4 , v052
	.byte	W04
	.byte		        Bn3 , v056
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Bn3 , v060
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        Bn3 , v068
	.byte	W04
	.byte		        Fs4 , v072
	.byte	W04
	.byte		        Bn3 , v080
	.byte	W04
	.byte		        Fs4 , v084
	.byte	W04
	.byte		        Bn3 , v092
	.byte	W04
	.byte		        Fs4 , v096
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Fs4 , v104
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Fs4 , v108
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        As3 , v108
	.byte	W04
	.byte		        Fs4 , v104
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs4 , v096
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs4 , v092
	.byte	W04
	.byte		        As3 , v088
	.byte	W04
	.byte		        Fs4 , v084
	.byte	W04
	.byte		        As3 , v080
	.byte	W04
	.byte		        Fs4 , v076
	.byte	W04
	.byte		        As3 , v068
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        As3 , v060
	.byte	W04
	.byte		        Fs4 , v056
	.byte	W04
	.byte		        As3 , v048
	.byte	W04
	.byte		        Fs4 , v044
	.byte	W04
	.byte		        As3 , v036
	.byte	W04
	.byte		        Fs4 , v048
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs4 , v052
	.byte	W04
	.byte		        An3 , v056
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An3 , v060
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        An3 , v068
	.byte	W04
	.byte		        Fs4 , v072
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		        Fs4 , v084
	.byte	W04
	.byte		        An3 , v092
	.byte	W04
	.byte		        Fs4 , v096
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs4 , v104
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs4 , v108
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gs3 , v108
	.byte	W04
	.byte		        En4 , v104
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        En4 , v096
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        En4 , v092
	.byte	W04
	.byte		        Gs3 , v088
	.byte	W04
	.byte		        En4 , v084
	.byte	W04
	.byte		        Gs3 , v080
	.byte	W04
	.byte		        En4 , v076
	.byte	W04
	.byte		        Gs3 , v068
	.byte	W04
	.byte		        En4 , v064
	.byte	W04
	.byte		        Gs3 , v060
	.byte	W04
	.byte		        En4 , v056
	.byte	W04
	.byte		        Gs3 , v048
	.byte	W04
	.byte		        En4 , v044
	.byte	W04
	.byte		        Gs3 , v036
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En4 , v052
	.byte	W04
	.byte		        Gn3 , v056
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gn3 , v060
	.byte	W04
	.byte		        En4 , v064
	.byte	W04
	.byte		        Gn3 , v068
	.byte	W04
	.byte		        En4 , v072
	.byte	W04
	.byte		        Gn3 , v080
	.byte	W04
	.byte		        En4 , v084
	.byte	W04
	.byte		        Gn3 , v092
	.byte	W04
	.byte		        En4 , v096
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En4 , v104
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        En4 , v108
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 , v108
	.byte	W04
	.byte		        Dn4 , v104
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 , v096
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 , v092
	.byte	W04
	.byte		        An3 , v088
	.byte	W04
	.byte		        Dn4 , v084
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		        Dn4 , v076
	.byte	W04
	.byte		        An3 , v068
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        An3 , v060
	.byte	W04
	.byte		        Dn4 , v056
	.byte	W04
	.byte		        An3 , v048
	.byte	W04
	.byte		        Dn4 , v044
	.byte	W04
	.byte		        An3 , v036
	.byte	W04
	.byte		        Dn4 , v048
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Dn4 , v052
	.byte	W04
	.byte		        Gs3 , v056
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gs3 , v060
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        Gs3 , v068
	.byte	W04
	.byte		        Dn4 , v072
	.byte	W04
	.byte		        Gs3 , v080
	.byte	W04
	.byte		        Dn4 , v084
	.byte	W04
	.byte		        Gs3 , v092
	.byte	W04
	.byte		        Dn4 , v096
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Dn4 , v104
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Dn4 , v108
	.byte	W04
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        As3 , v108
	.byte	W04
	.byte		        Fs4 , v104
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs4 , v096
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs4 , v092
	.byte	W04
	.byte		        As3 , v088
	.byte	W04
	.byte		        Fs4 , v084
	.byte	W04
	.byte		        As3 , v080
	.byte	W04
	.byte		        Fs4 , v076
	.byte	W04
	.byte		        As3 , v068
	.byte	W04
	.byte		VOICE , 1
	.byte		N04   , Fs4 , v064
	.byte	W04
	.byte		        As3 , v060
	.byte	W04
	.byte		        Fs4 , v056
	.byte	W04
	.byte		        As3 , v048
	.byte	W04
	.byte		        Fs4 , v044
	.byte	W04
	.byte		        As3 , v036
	.byte	W04
	.byte		VOL   , 44*bgm_runecity_mvl/mxv
	.byte		N16   , Bn3 , v112
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N02   , Bn4 
	.byte	W10
	.byte		N04   , Dn3 
	.byte	W06
	.byte		        Fs4 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , As3 
	.byte	W08
	.byte		N06   , Dn3 
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N14   , An3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W32
	.byte		        Bn3 
	.byte	W16
	.byte		        Gs3 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N02   , En3 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N16   , Dn4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        Bn2 
	.byte	W16
	.byte		        As2 
	.byte	W08
	.byte		        Dn3 
	.byte	W16
	.byte		        Bn2 
	.byte	W08
	.byte		        Bn3 
	.byte	W16
	.byte		        Fs3 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W08
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N02   , Fn4 
	.byte	W02
	.byte		N22   , Fs4 
	.byte	W22
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , As4 
	.byte	W12
	.byte		VOICE , 17
	.byte	W12
	.byte		N04   , An4 
	.byte	W10
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W16
	.byte		N04   , Gn4 
	.byte	W08
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W08
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N16   , En4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N40   , Bn3 
	.byte	W40
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , Gn3 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W06
	.byte		N56   , Dn4 
	.byte	W02
	.byte	W56
	.byte		N04   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N20   , Cs4 
	.byte	W20
	.byte		N04   , Dn4 
	.byte	W04
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N40   , An3 
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N40   , Dn5 
	.byte	W40
	.byte		N04   , An4 
	.byte	W16
	.byte		        Dn5 
	.byte	W08
	.byte		N40   , Bn4 
	.byte	W40
	.byte		N04   , An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W16
	.byte		        Bn4 
	.byte	W08
	.byte		N16   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N16   
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte	GOTO
	 .word	bgm_runecity_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_runecity:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_runecity_pri	@ Priority
	.byte	bgm_runecity_rev	@ Reverb.

	.word	bgm_runecity_grp

	.word	bgm_runecity_1
	.word	bgm_runecity_2
	.word	bgm_runecity_3
	.word	bgm_runecity_4
	.word	bgm_runecity_5
	.word	bgm_runecity_6
	.word	bgm_runecity_7
	.word	bgm_runecity_8

	.end
