	.include "MPlayDef.s"

	.equ	bgm_battle33_grp, voicegroup_869B4F8
	.equ	bgm_battle33_pri, 1
	.equ	bgm_battle33_rev, reverb_set+50
	.equ	bgm_battle33_mvl, 127
	.equ	bgm_battle33_key, 0
	.equ	bgm_battle33_tbs, 1
	.equ	bgm_battle33_exg, 0
	.equ	bgm_battle33_cmp, 1

	.section .rodata
	.global	bgm_battle33
	.align	2

@********************** Track  1 **********************@

bgm_battle33_1:
	.byte	KEYSH , bgm_battle33_key+0
	.byte	TEMPO , 212*bgm_battle33_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 16
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N06   , Ds4 , v096
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v+40
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		PAN   , c_v+24
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		PAN   , c_v+12
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v+7
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+4
	.byte		N06   , En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		PAN   , c_v-4
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		PAN   , c_v-14
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v-18
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		PAN   , c_v-26
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		PAN   , c_v-39
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W03
	.byte		PAN   , c_v-47
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		PAN   , c_v+10
	.byte		N12   , Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
bgm_battle33_1_000:
	.byte		N12   , Gn3 , v096
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte	PEND
	.byte		N12   
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
bgm_battle33_1_001:
	.byte		N12   , Cn4 , v096
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_1_000
	.byte	PATT
	 .word	bgm_battle33_1_001
	.byte		N12   , Ds4 , v096
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		N24   , Gn4 
	.byte	W24
bgm_battle33_1_B1:
	.byte		VOICE , 60
	.byte		PAN   , c_v+10
	.byte		MOD   , 0
	.byte		N84   , En3 , v096
	.byte	W84
	.byte		N12   , Cn3 
	.byte	W12
bgm_battle33_1_002:
	.byte		N24   , En2 , v096
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte	PEND
bgm_battle33_1_003:
	.byte		N84   , As3 , v096
	.byte	W84
	.byte		N12   , An3 
	.byte	W12
	.byte	PEND
bgm_battle33_1_004:
	.byte		N12   , As3 , v096
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , As3 
	.byte	W15
	.byte		VOL   , 74*bgm_battle33_mvl/mxv
	.byte	W03
	.byte		        61*bgm_battle33_mvl/mxv
	.byte	W03
	.byte		        40*bgm_battle33_mvl/mxv
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte	PEND
	.byte		VOICE , 60
	.byte		N84   , En3 
	.byte	W84
	.byte		N12   , Cn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_1_002
	.byte	PATT
	 .word	bgm_battle33_1_003
	.byte	PATT
	 .word	bgm_battle33_1_004
	.byte		VOICE , 1
	.byte		N36   , En3 , v096
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        Ds3 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte		VOICE , 48
	.byte		PAN   , c_v+20
	.byte		N48   , Gn4 , v088
	.byte	W48
	.byte		        Fn4 
	.byte	W48
	.byte		        Ds4 
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte		TIE   , Cn4 , v096
	.byte	W84
	.byte	W03
	.byte		VOL   , 74*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        68*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        65*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        58*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        53*bgm_battle33_mvl/mxv
	.byte	W15
	.byte		        48*bgm_battle33_mvl/mxv
	.byte	W36
	.byte	W03
	.byte	W32
	.byte	W01
	.byte		        53*bgm_battle33_mvl/mxv
	.byte	W15
	.byte		        58*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        63*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        68*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        77*bgm_battle33_mvl/mxv
	.byte	W06
	.byte	W06
	.byte		        80*bgm_battle33_mvl/mxv
	.byte	W90
	.byte		EOT   
	.byte		VOICE , 60
	.byte		PAN   , c_v+11
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
bgm_battle33_1_005:
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N24   , Gs3 
	.byte	W24
	.byte	PEND
bgm_battle33_1_006:
	.byte		N12   , Gn3 , v096
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte	PEND
bgm_battle33_1_007:
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_1_006
	.byte	PATT
	 .word	bgm_battle33_1_005
	.byte	PATT
	 .word	bgm_battle33_1_006
	.byte	PATT
	 .word	bgm_battle33_1_007
	.byte		VOICE , 56
	.byte		N24   , Gs3 , v096
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+20
	.byte		N24   , En5 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v+11
	.byte		TIE   , Ds5 
	.byte	W96
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   
bgm_battle33_1_008:
	.byte		MOD   , 0
	.byte		TIE   , Fn3 , v096
	.byte	W96
	.byte	PEND
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   
	.byte		MOD   , 0
	.byte		TIE   , Dn3 
	.byte	W96
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   
	.byte	PATT
	 .word	bgm_battle33_1_008
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   , Fn3 
	.byte	GOTO
	 .word	bgm_battle33_1_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle33_2:
	.byte	KEYSH , bgm_battle33_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 16
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Gn5 , v076
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , As5 
	.byte	W12
bgm_battle33_2_000:
	.byte		N12   , Cn4 , v100
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
	.byte	PEND
	.byte		N12   , Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle33_2_000
	.byte		N12   , Ds4 , v100
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		N24   , Fs4 
	.byte	W24
bgm_battle33_2_001:
	.byte		N12   , Cn5 , v100
	.byte	W36
	.byte		        Cs5 
	.byte	W36
	.byte		N24   , Ds5 
	.byte	W24
	.byte	PEND
	.byte		N12   , Gn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W36
	.byte		N24   , As4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle33_2_001
	.byte		N12   , Ds5 , v100
	.byte	W36
	.byte		        Fn5 
	.byte	W36
	.byte		N24   , Gn5 
	.byte	W24
bgm_battle33_2_B1:
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N84   , Cn4 , v100
	.byte	W84
	.byte		N12   , Gn3 
	.byte	W12
bgm_battle33_2_002:
	.byte		N12   , Cn4 , v100
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	PEND
bgm_battle33_2_003:
	.byte		N84   , Fs4 , v100
	.byte	W84
	.byte		N12   , Fn4 
	.byte	W12
	.byte	PEND
bgm_battle33_2_004:
	.byte		N12   , Fs4 , v100
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N72   , Fs4 
	.byte	W72
	.byte	PEND
	.byte		N84   , Cn4 
	.byte	W84
	.byte		N12   , Gn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_2_002
	.byte	PATT
	 .word	bgm_battle33_2_003
	.byte	PATT
	 .word	bgm_battle33_2_004
	.byte		VOICE , 73
	.byte		N36   , Gn3 , v112
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Gs3 
	.byte	W15
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , As3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		TIE   , Gs3 
	.byte	W42
	.byte		MOD   , 5
	.byte	W36
	.byte		        6
	.byte	W18
	.byte	W15
	.byte		VOL   , 75*bgm_battle33_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W09
	.byte		VOL   , 69*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        63*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 56*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        47*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        35*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        22*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        9*bgm_battle33_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , As3 , v100
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N36   , Gn3 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		TIE   , Fn3 
	.byte	W48
	.byte	W03
	.byte		MOD   , 6
	.byte	W44
	.byte	W01
	.byte	W48
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		VOL   , 48*bgm_battle33_mvl/mxv
	.byte		TIE   , En4 
	.byte	W32
	.byte	W01
	.byte		VOL   , 53*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 58*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        63*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        68*bgm_battle33_mvl/mxv
	.byte	W06
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 71*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        77*bgm_battle33_mvl/mxv
	.byte	W06
	.byte	W06
	.byte		        80*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		MOD   , 7
	.byte	W30
	.byte		        8
	.byte	W48
	.byte		EOT   
	.byte		VOICE , 60
	.byte		MOD   , 0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
bgm_battle33_2_005:
	.byte		N12   , Gn3 , v100
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs3 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte	PEND
bgm_battle33_2_006:
	.byte		N12   , Cn4 , v100
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
	.byte	PEND
bgm_battle33_2_007:
	.byte		N12   , Ds4 , v100
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N24   , Fs4 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_2_006
	.byte	PATT
	 .word	bgm_battle33_2_005
	.byte	PATT
	 .word	bgm_battle33_2_006
	.byte	PATT
	 .word	bgm_battle33_2_007
	.byte		VOICE , 48
	.byte		N24   , Cs4 , v100
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N24   , En5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        As5 
	.byte	W24
	.byte		        An5 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		TIE   , Gs5 
	.byte	W96
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   
bgm_battle33_2_008:
	.byte		MOD   , 0
	.byte		TIE   , As3 , v100
	.byte	W96
	.byte	PEND
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   
	.byte		MOD   , 0
	.byte		TIE   , Gn3 
	.byte	W96
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   
	.byte	PATT
	 .word	bgm_battle33_2_008
	.byte		MOD   , 5
	.byte	W96
	.byte		EOT   , As3 
	.byte	GOTO
	 .word	bgm_battle33_2_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle33_3:
	.byte	KEYSH , bgm_battle33_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		N12   , Cn2 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
bgm_battle33_3_000:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
bgm_battle33_3_001:
	.byte		N12   , Fn1 , v108
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_3_000
	.byte	PATT
	 .word	bgm_battle33_3_001
	.byte	PATT
	 .word	bgm_battle33_3_000
	.byte	PATT
	 .word	bgm_battle33_3_001
	.byte	PATT
	 .word	bgm_battle33_3_000
	.byte		N12   , Fn1 , v108
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
bgm_battle33_3_B1:
bgm_battle33_3_002:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
bgm_battle33_3_003:
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
bgm_battle33_3_004:
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_3_002
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_3_003
	.byte	PATT
	 .word	bgm_battle33_3_003
	.byte	PATT
	 .word	bgm_battle33_3_002
	.byte	PATT
	 .word	bgm_battle33_3_002
	.byte	PATT
	 .word	bgm_battle33_3_003
	.byte	PATT
	 .word	bgm_battle33_3_003
bgm_battle33_3_005:
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_3_005
bgm_battle33_3_006:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_3_006
	.byte		N12   , Cn2 , v108
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
bgm_battle33_3_007:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Cs1 
	.byte	W36
	.byte		N24   , Ds1 
	.byte	W24
	.byte	PEND
bgm_battle33_3_008:
	.byte		N12   , Gn0 , v108
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs0 
	.byte	W36
	.byte		N24   , Cs1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_3_007
	.byte	PATT
	 .word	bgm_battle33_3_008
	.byte	PATT
	 .word	bgm_battle33_3_007
	.byte	PATT
	 .word	bgm_battle33_3_008
	.byte	PATT
	 .word	bgm_battle33_3_007
	.byte		N12   , Gn0 , v108
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W24
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W24
bgm_battle33_3_009:
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PEND
bgm_battle33_3_010:
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_3_009
	.byte	PATT
	 .word	bgm_battle33_3_010
bgm_battle33_3_011:
	.byte		N12   , En1 , v108
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	PEND
bgm_battle33_3_012:
	.byte		N12   , En1 , v108
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_3_011
	.byte	PATT
	 .word	bgm_battle33_3_012
	.byte		N24   , An1 , v108
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        An0 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Gn0 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Fn0 
	.byte	W24
	.byte		N12   , Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_3_002
	.byte	PATT
	 .word	bgm_battle33_3_002
	.byte	PATT
	 .word	bgm_battle33_3_003
	.byte	PATT
	 .word	bgm_battle33_3_003
	.byte	PATT
	 .word	bgm_battle33_3_002
	.byte	PATT
	 .word	bgm_battle33_3_002
	.byte	PATT
	 .word	bgm_battle33_3_003
	.byte	PATT
	 .word	bgm_battle33_3_004
	.byte	GOTO
	 .word	bgm_battle33_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle33_4:
	.byte	KEYSH , bgm_battle33_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 16
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N06   , Cn5 , v060
	.byte	W18
	.byte		PAN   , c_v+50
	.byte		N06   , Cs5 
	.byte	W06
	.byte		PAN   , c_v-47
	.byte		N06   , Cn5 
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-47
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v+48
	.byte		N06   , Cs5 
	.byte	W06
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		N12   , Cn3 
	.byte	W36
	.byte		        Cs3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W36
	.byte		        Gs2 
	.byte	W36
	.byte		N24   , As2 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W36
	.byte		        Cs3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte	W24
	.byte		VOICE , 80
	.byte		PAN   , c_v-49
	.byte		N12   , Gn4 , v052
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Gs4 , v052
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cs3 , v060
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N24   , As4 , v052
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fn2 , v060
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Fn4 , v052
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fs2 , v060
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N24   , Gn4 , v052
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gn2 , v060
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Gs4 , v052
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gs2 , v060
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N24   , As4 , v052
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , As2 , v060
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Cn5 , v052
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Bn2 , v060
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N24   , Bn4 , v052
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
bgm_battle33_4_B1:
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		N12   , Fs2 , v060
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte		        Fs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v-47
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		N48   , Ds3 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		TIE   , Cn3 
	.byte	W84
	.byte	W03
	.byte		VOL   , 74*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        68*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        65*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        58*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        53*bgm_battle33_mvl/mxv
	.byte	W15
	.byte		        48*bgm_battle33_mvl/mxv
	.byte	W36
	.byte	W03
	.byte		EOT   
	.byte		VOICE , 85
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W09
	.byte		VOL   , 53*bgm_battle33_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		VOL   , 58*bgm_battle33_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 63*bgm_battle33_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 68*bgm_battle33_mvl/mxv
	.byte		N12   
	.byte	W09
	.byte		VOL   , 71*bgm_battle33_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W06
	.byte		VOL   , 77*bgm_battle33_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs2 
	.byte	W36
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N36   , Gs2 
	.byte	W36
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs2 
	.byte	W36
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   , Cn5 , v040
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Cs5 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		VOICE , 80
	.byte		N24   , Cs3 , v060
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		N24   , An4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		TIE   , Gs4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , As2 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Gn2 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , As2 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_battle33_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle33_5:
	.byte	KEYSH , bgm_battle33_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 16
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-2
	.byte		N06   , Gn3 , v060
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+48
	.byte		N12   , Gn3 , v052
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
bgm_battle33_5_B1:
	.byte		MOD   , 0
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 83
	.byte		VOL   , 48*bgm_battle33_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		TIE   , En3 , v060
	.byte	W32
	.byte	W01
	.byte		VOL   , 53*bgm_battle33_mvl/mxv
	.byte	W15
	.byte		        58*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        63*bgm_battle33_mvl/mxv
	.byte	W12
	.byte		        68*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle33_mvl/mxv
	.byte	W09
	.byte		        77*bgm_battle33_mvl/mxv
	.byte	W06
	.byte	W06
	.byte		        80*bgm_battle33_mvl/mxv
	.byte	W90
	.byte		EOT   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 84
	.byte	W06
	.byte		N12   , Cn5 , v032
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W18
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Cs5 
	.byte	W18
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W18
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N06   , Fs5 
	.byte	W06
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
	.byte	GOTO
	 .word	bgm_battle33_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle33_6:
	.byte	KEYSH , bgm_battle33_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte	W48
	.byte		N06   , Gn2 , v080
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle33_6_B1:
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
	.byte	GOTO
	 .word	bgm_battle33_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_battle33_7:
	.byte	KEYSH , bgm_battle33_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+1
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte	W96
	.byte	W96
bgm_battle33_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle33_7_B1:
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
bgm_battle33_7_001:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle33_7_002:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_002
	.byte	PATT
	 .word	bgm_battle33_7_002
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_002
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_001
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_001
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_001
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_001
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_001
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	PATT
	 .word	bgm_battle33_7_000
	.byte	W12
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle33_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_battle33_8:
	.byte	KEYSH , bgm_battle33_key+0
	.byte		PAN   , c_v-10
	.byte		VOL   , 80*bgm_battle33_mvl/mxv
	.byte		N12   , Gn2 , v100
	.byte	W03
	.byte		VOICE , 47
	.byte	W09
	.byte		N12   , En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
bgm_battle33_8_000:
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_battle33_8_001:
	.byte		N12   , Gn2 , v100
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_battle33_8_002:
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte		        Gn2 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_8_000
	.byte	PATT
	 .word	bgm_battle33_8_001
	.byte	PATT
	 .word	bgm_battle33_8_002
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W36
bgm_battle33_8_B1:
bgm_battle33_8_003:
	.byte		N12   , Gn2 , v100
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
bgm_battle33_8_004:
	.byte		N12   , Gn2 , v100
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_8_003
bgm_battle33_8_005:
	.byte		N12   , Gn2 , v100
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_005
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_005
bgm_battle33_8_006:
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_8_006
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Fn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_005
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        En2 
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		N12   
	.byte	W24
bgm_battle33_8_007:
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_8_007
	.byte		N12   , Gn2 , v100
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Gn2 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W48
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte		N12   , Gn2 , v100
	.byte	W72
	.byte		N12   
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	W24
	.byte		N12   
	.byte	W72
bgm_battle33_8_008:
	.byte		N12   , Gn2 , v100
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle33_8_008
	.byte	PATT
	 .word	bgm_battle33_8_008
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_004
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_005
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_004
	.byte	PATT
	 .word	bgm_battle33_8_003
	.byte	PATT
	 .word	bgm_battle33_8_005
	.byte	GOTO
	 .word	bgm_battle33_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle33:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle33_pri	@ Priority
	.byte	bgm_battle33_rev	@ Reverb.

	.word	bgm_battle33_grp

	.word	bgm_battle33_1
	.word	bgm_battle33_2
	.word	bgm_battle33_3
	.word	bgm_battle33_4
	.word	bgm_battle33_5
	.word	bgm_battle33_6
	.word	bgm_battle33_7
	.word	bgm_battle33_8

	.end
