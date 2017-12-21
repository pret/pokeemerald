	.include "MPlayDef.s"

	.equ	bgm_battle31_grp, voicegroup_869A82C
	.equ	bgm_battle31_pri, 1
	.equ	bgm_battle31_rev, reverb_set+50
	.equ	bgm_battle31_mvl, 127
	.equ	bgm_battle31_key, 0
	.equ	bgm_battle31_tbs, 1
	.equ	bgm_battle31_exg, 0
	.equ	bgm_battle31_cmp, 1

	.section .rodata
	.global	bgm_battle31
	.align	2

@********************** Track  1 **********************@

bgm_battle31_1:
	.byte	KEYSH , bgm_battle31_key+0
	.byte	TEMPO , 200*bgm_battle31_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , As4 , v092
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+13
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v+24
	.byte		N06   , As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+13
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v-12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N06   , As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		VOICE , 48
	.byte		PAN   , c_v-14
	.byte		N12   , Cs4 , v100
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v+6
	.byte		N12   , Fn4 , v096
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
bgm_battle31_1_000:
	.byte		N12   , Fn4 , v096
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Fs4 
	.byte	W24
	.byte	PEND
bgm_battle31_1_001:
	.byte		N12   , Fn4 , v096
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
bgm_battle31_1_002:
	.byte		N12   , Fn4 , v096
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , An4 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_1_001
	.byte	PATT
	 .word	bgm_battle31_1_000
	.byte	PATT
	 .word	bgm_battle31_1_001
	.byte	PATT
	 .word	bgm_battle31_1_002
bgm_battle31_1_B1:
	.byte		VOICE , 48
	.byte		N36   , As3 , v096
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
bgm_battle31_1_003:
	.byte		N36   , Dn3 , v096
	.byte	W36
	.byte		        Ds3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
	.byte	PEND
bgm_battle31_1_004:
	.byte		N12   , Bn2 , v096
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_1_004
	.byte		N36   , As3 , v096
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_1_003
	.byte	PATT
	 .word	bgm_battle31_1_004
	.byte	PATT
	 .word	bgm_battle31_1_004
	.byte		VOICE , 21
	.byte		N12   , Dn4 , v088
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   
	.byte	W24
bgm_battle31_1_005:
	.byte		N12   , Ds4 , v088
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
	.byte		N12   , Fn4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_1_005
	.byte		N12   , Dn4 , v088
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_1_005
	.byte		N12   , Fn4 , v088
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W48
	.byte		VOICE , 38
	.byte		N96   , As1 , v100
	.byte	W96
bgm_battle31_1_006:
	.byte	W12
	.byte		N12   , As1 , v100
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte		N96   , As1 
	.byte	W96
	.byte	PATT
	 .word	bgm_battle31_1_006
	.byte		N96   , As1 , v100
	.byte	W96
	.byte	W12
	.byte		VOICE , 48
	.byte		N12   , As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N48   , Dn2 
	.byte	W48
	.byte		        Ds2 
	.byte	W48
	.byte		        Fn2 
	.byte	W48
	.byte		        Fs2 
	.byte	W48
	.byte		N96   , Gs2 
	.byte	W96
bgm_battle31_1_007:
	.byte	W12
	.byte		N12   , Gs2 , v100
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
	.byte		N96   , Gs2 
	.byte	W96
	.byte	PATT
	 .word	bgm_battle31_1_007
	.byte		N96   , Gs2 , v100
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W48
	.byte		        An2 
	.byte	W48
bgm_battle31_1_008:
	.byte		N48   , As2 , v100
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_1_008
	.byte		N48   , Cn3 , v100
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		VOICE , 46
	.byte		PAN   , c_v+6
	.byte		N12   , As3 , v088
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
bgm_battle31_1_009:
	.byte		N12   , As3 , v088
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
bgm_battle31_1_010:
	.byte		N12   , As3 , v088
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_1_009
bgm_battle31_1_011:
	.byte		N12   , Cs4 , v088
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte	PEND
bgm_battle31_1_012:
	.byte		N12   , Cs4 , v088
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_1_011
	.byte	PATT
	 .word	bgm_battle31_1_012
	.byte	PATT
	 .word	bgm_battle31_1_010
	.byte	PATT
	 .word	bgm_battle31_1_009
	.byte	PATT
	 .word	bgm_battle31_1_010
	.byte	PATT
	 .word	bgm_battle31_1_009
	.byte	PATT
	 .word	bgm_battle31_1_010
	.byte	PATT
	 .word	bgm_battle31_1_009
	.byte	PATT
	 .word	bgm_battle31_1_010
	.byte	PATT
	 .word	bgm_battle31_1_009
	.byte	PATT
	 .word	bgm_battle31_1_011
	.byte	PATT
	 .word	bgm_battle31_1_012
	.byte	PATT
	 .word	bgm_battle31_1_011
	.byte	PATT
	 .word	bgm_battle31_1_012
	.byte	PATT
	 .word	bgm_battle31_1_011
	.byte	PATT
	 .word	bgm_battle31_1_012
	.byte	PATT
	 .word	bgm_battle31_1_011
	.byte	PATT
	 .word	bgm_battle31_1_012
	.byte	PATT
	 .word	bgm_battle31_1_011
	.byte	PATT
	 .word	bgm_battle31_1_012
	.byte	PATT
	 .word	bgm_battle31_1_011
	.byte	PATT
	 .word	bgm_battle31_1_012
	.byte		VOICE , 21
	.byte		N12   , Fn3 , v092
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
bgm_battle31_1_013:
	.byte		N12   , Fn3 , v092
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte	PEND
bgm_battle31_1_014:
	.byte		N12   , Fn3 , v092
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_1_014
	.byte	PATT
	 .word	bgm_battle31_1_013
	.byte	PATT
	 .word	bgm_battle31_1_014
	.byte		N12   , Fn3 , v092
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N48   , An3 
	.byte	W48
	.byte		TIE   , Fn4 
	.byte	W96
	.byte		VOL   , 76*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        71*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        66*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        62*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        56*bgm_battle31_mvl/mxv
	.byte	W09
	.byte		        50*bgm_battle31_mvl/mxv
	.byte	W09
	.byte		        42*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        31*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        18*bgm_battle31_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		TIE   , As2 , v088
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_battle31_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle31_2:
	.byte	KEYSH , bgm_battle31_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 22
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		N06   , Fn5 , v060
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		VOICE , 48
	.byte		PAN   , c_v-1
	.byte		N12   , As3 , v096
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , As3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
bgm_battle31_2_000:
	.byte		N12   , Fn5 , v080
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Fs5 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_2_000
	.byte		N12   , Fn5 , v080
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs5 
	.byte	W24
bgm_battle31_2_B1:
	.byte		VOICE , 17
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N36   , Fn4 , v108
	.byte	W36
	.byte		N72   , As3 
	.byte	W60
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N96   , Fs4 
	.byte	W96
	.byte		        Ds4 
	.byte	W96
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N72   , As3 
	.byte	W60
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N96   , Bn4 
	.byte	W96
	.byte		        Ds5 
	.byte	W96
	.byte		TIE   , Dn5 
	.byte	W96
	.byte	W96
bgm_battle31_2_001:
	.byte		VOL   , 74*bgm_battle31_mvl/mxv
	.byte	W18
	.byte		        69*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        65*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        60*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        57*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        53*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        48*bgm_battle31_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte	W12
	.byte		        43*bgm_battle31_mvl/mxv
	.byte	W18
	.byte		        37*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        27*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        19*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        10*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		EOT   , Dn5 
	.byte	W12
	.byte		VOICE , 21
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N12   , As4 , v080
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		N12   , Cs5 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N12   , As4 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N48   , Cs5 
	.byte	W48
	.byte		VOICE , 48
	.byte		N36   , Dn3 , v100
	.byte	W36
	.byte		        As2 
	.byte	W36
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N36   , Ds3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N60   , Fs3 
	.byte	W60
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N96   , Fn3 
	.byte	W96
	.byte		N36   , Dn3 
	.byte	W36
	.byte		        As2 
	.byte	W36
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N36   , Ds3 
	.byte	W36
	.byte		        Fs3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N48   , Fs2 
	.byte	W48
	.byte		        Gs2 
	.byte	W48
	.byte		        As2 
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte		N96   , Cs3 
	.byte	W96
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N96   , Cs3 
	.byte	W96
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N96   , Cs3 
	.byte	W96
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N48   , Cs3 
	.byte	W48
	.byte		        Dn3 
	.byte	W48
bgm_battle31_2_002:
	.byte		N48   , Ds3 , v100
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_2_002
	.byte		N48   , Fn3 , v100
	.byte	W48
	.byte		        Fs3 
	.byte	W48
	.byte		VOICE , 14
	.byte		PAN   , c_v-1
	.byte		TIE   , Gs4 , v056
	.byte	W96
	.byte	W84
	.byte		EOT   
	.byte		N12   , An4 
	.byte	W12
	.byte		TIE   , As4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 58
	.byte		N36   , As3 , v072
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Fn3 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , Bn3 
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Cs4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N60   , Dn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N92   , As3 
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 77*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        74*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        68*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        62*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        57*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        45*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        34*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        22*bgm_battle31_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		N36   , Fn3 
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , As3 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , Bn3 
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Cs4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N60   , As3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
bgm_battle31_2_003:
	.byte		N92   , Cs4 , v072
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 77*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        74*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        68*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        62*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        57*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        45*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        34*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        22*bgm_battle31_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte	PEND
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		N36   
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Gs3 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
bgm_battle31_2_004:
	.byte		MOD   , 0
	.byte		N36   , Dn4 , v072
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , En4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte	PEND
	.byte		        0
	.byte		N60   , Fn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle31_2_003
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		N36   , Gs3 , v072
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , Cs4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte	PATT
	 .word	bgm_battle31_2_004
	.byte		MOD   , 0
	.byte		N60   , Fn4 , v072
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N92   , Gs4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 77*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        74*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        68*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        62*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        57*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        45*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        34*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        22*bgm_battle31_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		N96   , Cs3 , v100
	.byte	W96
	.byte		        Fn3 
	.byte	W96
	.byte		        Gs3 
	.byte	W96
	.byte		        Bn3 
	.byte	W96
	.byte		VOICE , 21
	.byte		N12   , Fn4 , v088
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
bgm_battle31_2_005:
	.byte		N12   , Fn4 , v088
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Fs4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_2_005
	.byte		N12   , Fn4 , v088
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_2_005
	.byte		N12   , Fn4 , v088
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N48   , An4 
	.byte	W48
	.byte		TIE   , As4 
	.byte	W96
	.byte	PATT
	 .word	bgm_battle31_2_001
	.byte	W12
	.byte		VOL   , 43*bgm_battle31_mvl/mxv
	.byte	W18
	.byte		        37*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        27*bgm_battle31_mvl/mxv
	.byte	W15
	.byte		        19*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        10*bgm_battle31_mvl/mxv
	.byte	W24
	.byte		EOT   , As4 
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle31_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle31_3:
	.byte	KEYSH , bgm_battle31_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		N12   , As1 , v108
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Fn1 
	.byte	W12
	.byte		N48   , As0 
	.byte	W48
	.byte		        Bn0 
	.byte	W48
bgm_battle31_3_000:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
bgm_battle31_3_001:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_3_000
bgm_battle31_3_002:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_001
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_002
bgm_battle31_3_B1:
bgm_battle31_3_003:
	.byte		N12   , As0 , v108
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
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_3_003
bgm_battle31_3_004:
	.byte		N12   , Bn0 , v108
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_3_004
	.byte	PATT
	 .word	bgm_battle31_3_003
	.byte	PATT
	 .word	bgm_battle31_3_003
	.byte	PATT
	 .word	bgm_battle31_3_004
	.byte	PATT
	 .word	bgm_battle31_3_004
bgm_battle31_3_005:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
bgm_battle31_3_006:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
bgm_battle31_3_007:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_3_006
	.byte	PATT
	 .word	bgm_battle31_3_005
	.byte	PATT
	 .word	bgm_battle31_3_006
	.byte	PATT
	 .word	bgm_battle31_3_007
	.byte	PATT
	 .word	bgm_battle31_3_006
	.byte	PATT
	 .word	bgm_battle31_3_003
	.byte	PATT
	 .word	bgm_battle31_3_003
	.byte	PATT
	 .word	bgm_battle31_3_003
	.byte	PATT
	 .word	bgm_battle31_3_003
	.byte	PATT
	 .word	bgm_battle31_3_003
	.byte		N12   , As0 , v108
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
	.byte		        Fs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
bgm_battle31_3_008:
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
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_008
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_001
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_002
bgm_battle31_3_009:
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
bgm_battle31_3_010:
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_3_009
bgm_battle31_3_011:
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_001
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_002
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_001
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_002
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_010
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_011
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_010
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_011
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_010
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_011
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_010
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_011
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte	PATT
	 .word	bgm_battle31_3_010
	.byte	PATT
	 .word	bgm_battle31_3_009
	.byte		N12   , Cs1 , v108
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_001
	.byte	PATT
	 .word	bgm_battle31_3_000
	.byte	PATT
	 .word	bgm_battle31_3_002
	.byte	GOTO
	 .word	bgm_battle31_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle31_4:
	.byte	KEYSH , bgm_battle31_key+0
	.byte		VOICE , 80
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		LFOS  , 22
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		PAN   , c_v-48
	.byte	W18
	.byte		N06   , As5 , v052
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		N12   , As3 , v060
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , As3 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
bgm_battle31_4_B1:
	.byte		MOD   , 0
	.byte	W96
	.byte	W60
	.byte		VOICE , 80
	.byte		PAN   , c_v+48
	.byte		N12   , As3 , v060
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		TIE   , Bn3 
	.byte	W60
	.byte		MOD   , 3
	.byte	W36
bgm_battle31_4_000:
	.byte		VOL   , 76*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        71*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        66*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        62*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        53*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        45*bgm_battle31_mvl/mxv
	.byte	W12
	.byte		        32*bgm_battle31_mvl/mxv
	.byte	W09
	.byte		        22*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		        10*bgm_battle31_mvl/mxv
	.byte	W09
	.byte	PEND
	.byte		EOT   , Bn3 
	.byte		MOD   , 0
	.byte	W48
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N36   , As2 , v052
	.byte	W36
	.byte		N60   , Fn2 
	.byte	W12
	.byte	W48
	.byte		PAN   , c_v-48
	.byte	W12
	.byte		N12   , As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		TIE   , Bn3 
	.byte	W60
	.byte		MOD   , 3
	.byte	W36
	.byte	PATT
	 .word	bgm_battle31_4_000
	.byte		EOT   , Bn3 
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		N12   , As3 , v052
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , As3 
	.byte	W24
bgm_battle31_4_001:
	.byte		N12   , Bn3 , v052
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte	PEND
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_4_001
	.byte		N12   , As3 , v052
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , As3 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_4_001
	.byte		N12   , Cs4 , v052
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N48   , Cs4 
	.byte	W48
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N12   , As3 , v060
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		        As4 
	.byte	W24
bgm_battle31_4_002:
	.byte		N12   , Bn4 , v060
	.byte	W72
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte	PEND
	.byte		        As4 
	.byte	W96
	.byte	W96
	.byte		        As3 
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		        As4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_4_002
	.byte		N12   , As4 , v060
	.byte	W96
	.byte	W96
bgm_battle31_4_003:
	.byte		N12   , Cs4 , v060
	.byte	W36
	.byte		        Gs4 
	.byte	W36
	.byte		        Cs5 
	.byte	W24
	.byte	PEND
bgm_battle31_4_004:
	.byte		N12   , Dn5 , v060
	.byte	W72
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte	PEND
	.byte		        Cs5 
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_battle31_4_003
	.byte	PATT
	 .word	bgm_battle31_4_004
	.byte		N12   , Cs5 , v060
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
	.byte		VOICE , 4
	.byte		PAN   , c_v-2
	.byte		N12   , Fn2 
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
bgm_battle31_4_005:
	.byte		N12   , Fn2 , v060
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Fs2 
	.byte	W24
	.byte	PEND
bgm_battle31_4_006:
	.byte		N12   , Fn2 , v060
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
bgm_battle31_4_007:
	.byte		N12   , Fn2 , v060
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_4_006
	.byte	PATT
	 .word	bgm_battle31_4_005
	.byte	PATT
	 .word	bgm_battle31_4_006
	.byte	PATT
	 .word	bgm_battle31_4_007
	.byte		VOICE , 5
	.byte		PAN   , c_v+48
	.byte		N12   , As2 , v052
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
bgm_battle31_4_008:
	.byte		N12   , As2 , v052
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte	PEND
bgm_battle31_4_009:
	.byte		N12   , As2 , v052
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_4_009
	.byte	PATT
	 .word	bgm_battle31_4_008
	.byte	PATT
	 .word	bgm_battle31_4_009
	.byte		N12   , As2 , v052
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   , Bn2 , v048
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		N12   , As2 , v052
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   , As2 , v048
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 5
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		N12   , Fn2 , v052
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   , Fn2 , v048
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 5
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		N12   , Ds2 , v052
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   , Ds2 , v048
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 5
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		N12   , Dn2 , v052
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   , Dn2 , v048
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 5
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle31_4_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle31_5:
	.byte	KEYSH , bgm_battle31_key+0
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		LFOS  , 22
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N06   , As2 , v052
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle31_5_B1:
	.byte		PAN   , c_v+48
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		N12   , Fs4 , v040
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 3
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Bn4 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 3
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , As4 
	.byte	W12
	.byte		VOICE , 83
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
	.byte		N12   
	.byte	W12
	.byte		VOL   , 74*bgm_battle31_mvl/mxv
	.byte		MOD   , 3
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W09
	.byte		VOL   , 65*bgm_battle31_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		VOL   , 60*bgm_battle31_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W03
	.byte		VOL   , 57*bgm_battle31_mvl/mxv
	.byte	W09
	.byte		N12   
	.byte	W06
	.byte		VOL   , 53*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W09
	.byte		VOL   , 48*bgm_battle31_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		VOL   , 43*bgm_battle31_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		VOL   , 37*bgm_battle31_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W09
	.byte		VOL   , 27*bgm_battle31_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		VOL   , 19*bgm_battle31_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 10*bgm_battle31_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte	W36
	.byte		N12   , As3 
	.byte	W36
	.byte		        Fn4 
	.byte	W24
bgm_battle31_5_000:
	.byte	W12
	.byte		N12   , As4 , v040
	.byte	W24
	.byte		        Bn4 
	.byte	W60
	.byte	PEND
bgm_battle31_5_001:
	.byte	W12
	.byte		N12   , As4 , v040
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W60
	.byte	PEND
	.byte	W96
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		        Fn4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_5_000
	.byte	PATT
	 .word	bgm_battle31_5_001
	.byte	W96
bgm_battle31_5_002:
	.byte	W36
	.byte		N12   , Cs4 , v040
	.byte	W36
	.byte		        Gs4 
	.byte	W24
	.byte	PEND
bgm_battle31_5_003:
	.byte	W12
	.byte		N12   , Cs5 , v040
	.byte	W24
	.byte		        Dn5 
	.byte	W60
	.byte	PEND
bgm_battle31_5_004:
	.byte	W12
	.byte		N12   , Cs5 , v040
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W60
	.byte	PEND
	.byte	W96
	.byte	PATT
	 .word	bgm_battle31_5_002
	.byte	PATT
	 .word	bgm_battle31_5_003
	.byte	PATT
	 .word	bgm_battle31_5_004
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
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		N12   , Gs2 , v072
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 4
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Bn2 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 5
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Cs3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 5
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 5
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 4
	.byte		PAN   , c_v-48
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v052
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
bgm_battle31_5_005:
	.byte		N12   , Cs4 , v052
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte	PEND
bgm_battle31_5_006:
	.byte		N12   , Cs4 , v052
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N24   , Dn4 
	.byte	W24
	.byte	PATT
	 .word	bgm_battle31_5_006
	.byte	PATT
	 .word	bgm_battle31_5_005
	.byte	PATT
	 .word	bgm_battle31_5_006
	.byte		N12   , Cs4 , v052
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W48
	.byte		MOD   , 0
	.byte		N96   , As3 
	.byte	W48
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		N96   , Fn3 
	.byte	W48
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		N96   , Ds3 
	.byte	W48
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte		N96   , Dn3 
	.byte	W48
	.byte		MOD   , 5
	.byte	W48
	.byte	GOTO
	 .word	bgm_battle31_5_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle31_6:
	.byte	KEYSH , bgm_battle31_key+0
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte	W96
	.byte	W72
	.byte		VOICE , 84
	.byte		N24   , An3 , v064
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle31_6_B1:
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
	.byte		VOICE , 84
	.byte		N96   , Fn2 , v080
	.byte	W96
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N96   , Fn2 
	.byte	W96
	.byte	W96
	.byte		VOICE , 81
	.byte		N12   , Dn3 , v064
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 84
	.byte		N48   , Cs2 , v080
	.byte	W48
	.byte		        Dn2 
	.byte	W48
bgm_battle31_6_000:
	.byte		N48   , Ds2 , v080
	.byte	W48
	.byte		        En2 
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_6_000
	.byte		N48   , Fn2 , v080
	.byte	W48
	.byte		        Fs2 
	.byte	W48
	.byte	W12
	.byte		VOICE , 81
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
bgm_battle31_6_001:
	.byte		N12   , As1 , v080
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
bgm_battle31_6_002:
	.byte		N12   , As1 , v080
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte	PEND
bgm_battle31_6_003:
	.byte		N12   , As1 , v080
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
bgm_battle31_6_004:
	.byte		N12   , Cs2 , v080
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
bgm_battle31_6_005:
	.byte		N12   , Cs2 , v080
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_6_004
bgm_battle31_6_006:
	.byte		N12   , Cs2 , v080
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_6_002
	.byte	PATT
	 .word	bgm_battle31_6_001
	.byte	PATT
	 .word	bgm_battle31_6_002
	.byte	PATT
	 .word	bgm_battle31_6_003
	.byte	PATT
	 .word	bgm_battle31_6_002
	.byte	PATT
	 .word	bgm_battle31_6_001
	.byte	PATT
	 .word	bgm_battle31_6_002
	.byte	PATT
	 .word	bgm_battle31_6_003
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_005
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_006
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_005
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_006
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_005
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_006
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_005
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_006
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte	PATT
	 .word	bgm_battle31_6_005
	.byte	PATT
	 .word	bgm_battle31_6_004
	.byte		N12   , Cs2 , v080
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle31_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_battle31_7:
	.byte	KEYSH , bgm_battle31_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte	W96
	.byte	W72
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle31_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
bgm_battle31_7_001:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
bgm_battle31_7_B1:
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_001
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
bgm_battle31_7_002:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte		N96   , An2 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_battle31_7_002
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_001
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_001
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_001
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_001
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_001
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
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
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_000
	.byte	PATT
	 .word	bgm_battle31_7_001
	.byte	GOTO
	 .word	bgm_battle31_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_battle31_8:
	.byte	KEYSH , bgm_battle31_key+0
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_battle31_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N48   , Cn2 , v112
	.byte	W96
	.byte		N12   , Cn2 , v124
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W48
bgm_battle31_8_000:
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PEND
bgm_battle31_8_001:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_8_000
bgm_battle31_8_002:
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
bgm_battle31_8_B1:
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte		N12   , Cn2 , v108
	.byte	W48
	.byte		        Cn2 , v112
	.byte	W48
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_002
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
bgm_battle31_8_003:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_003
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	PATT
	 .word	bgm_battle31_8_000
	.byte	PATT
	 .word	bgm_battle31_8_001
	.byte	GOTO
	 .word	bgm_battle31_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle31:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle31_pri	@ Priority
	.byte	bgm_battle31_rev	@ Reverb.

	.word	bgm_battle31_grp

	.word	bgm_battle31_1
	.word	bgm_battle31_2
	.word	bgm_battle31_3
	.word	bgm_battle31_4
	.word	bgm_battle31_5
	.word	bgm_battle31_6
	.word	bgm_battle31_7
	.word	bgm_battle31_8

	.end
