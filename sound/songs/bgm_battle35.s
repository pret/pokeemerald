	.include "MPlayDef.s"

	.equ	bgm_battle35_grp, voicegroup_869C2F0
	.equ	bgm_battle35_pri, 1
	.equ	bgm_battle35_rev, reverb_set+50
	.equ	bgm_battle35_mvl, 127
	.equ	bgm_battle35_key, 0
	.equ	bgm_battle35_tbs, 1
	.equ	bgm_battle35_exg, 0
	.equ	bgm_battle35_cmp, 1

	.section .rodata
	.global	bgm_battle35
	.align	2

@********************** Track  1 **********************@

bgm_battle35_1:
	.byte	KEYSH , bgm_battle35_key+0
	.byte	TEMPO , 196*bgm_battle35_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 16
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+0
	.byte		N06   , Fn4 , v108
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		VOICE , 60
	.byte		PAN   , c_v+10
	.byte		N12   , An2 , v096
	.byte	W36
	.byte		        Fn2 
	.byte	W36
	.byte		        An2 
	.byte	W24
	.byte		        Cn3 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		        Fn3 
	.byte	W24
	.byte		        An2 
	.byte	W36
	.byte		        Fn2 
	.byte	W36
	.byte		        An2 
	.byte	W24
	.byte		        Cn3 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
	.byte		VOICE , 48
	.byte		N12   
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		        An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		        Fn4 
	.byte	W24
	.byte		        An3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		        An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		N24   , Gn4 
	.byte	W24
bgm_battle35_1_B1:
	.byte		VOICE , 48
	.byte		N36   , An2 , v096
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N48   , Ds3 
	.byte	W48
	.byte		        Ds2 
	.byte	W48
	.byte		        Ds3 
	.byte	W48
	.byte		N24   , As2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N48   , Ds3 
	.byte	W48
	.byte		        Fn3 
	.byte	W48
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
bgm_battle35_1_000:
	.byte		N24   , Ds4 , v096
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_1_000
	.byte		N12   , Cn3 , v096
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		VOICE , 56
	.byte		N36   , Fn4 , v108
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N24   , An4 
	.byte	W24
	.byte	W12
	.byte		N36   
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , As4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		N12   , As2 , v096
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
bgm_battle35_1_001:
	.byte		N12   , Ds3 , v096
	.byte	W48
	.byte		N48   , Fs3 
	.byte	W48
	.byte	PEND
	.byte		N12   , As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_1_001
	.byte		VOICE , 56
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v-2
	.byte		N24   , As3 , v072
	.byte	W24
	.byte		PAN   , c_v+25
	.byte		N24   , Fn3 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v+8
	.byte		N24   , Gs3 
	.byte	W12
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v-7
	.byte		N24   , Fn3 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N24   , Gs3 
	.byte	W24
	.byte		PAN   , c_v-24
	.byte		N24   , Ds3 
	.byte	W12
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v-24
	.byte		N24   , Fn3 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v-7
	.byte		N24   , Gs3 
	.byte	W12
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v+8
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v+24
	.byte		N12   , As3 
	.byte	W12
	.byte		PAN   , c_v+10
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		BEND  , c_v+0
	.byte		N96   , Fn3 , v100
	.byte	W96
	.byte		N72   , Fn2 
	.byte	W72
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N96   , Gs2 
	.byte	W96
	.byte		N36   , Ds3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N96   , Dn3 
	.byte	W96
	.byte		N72   , Gn2 
	.byte	W72
	.byte		N24   , As2 
	.byte	W24
	.byte		N48   , Cn3 
	.byte	W48
	.byte		        As2 
	.byte	W48
	.byte		        Gs2 
	.byte	W48
	.byte		        Ds2 , v096
	.byte	W48
	.byte	GOTO
	 .word	bgm_battle35_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle35_2:
	.byte	KEYSH , bgm_battle35_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 16
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N06   , Cn5 , v060
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		N12   , Cn3 , v112
	.byte	W36
	.byte		        An2 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        An3 
	.byte	W24
	.byte		        Cn3 
	.byte	W36
	.byte		        An2 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		        Cn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		        An4 
	.byte	W24
	.byte		        Cn4 
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		        Cn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
bgm_battle35_2_B1:
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		N36   , Cn4 , v100
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , As4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		TIE   , Ds4 
	.byte	W96
	.byte	W32
	.byte	W01
	.byte		VOL   , 77*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        74*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        67*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        62*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        56*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        47*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        39*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte	W03
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		N36   , Dn4 
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		N24   , As4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N48   , Ds4 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        Ds4 
	.byte	W48
	.byte		VOICE , 56
	.byte		N24   , Fn4 , v112
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N48   , As3 
	.byte	W21
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte		VOICE , 46
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N24   , Fn4 , v092
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N48   , As3 
	.byte	W48
bgm_battle35_2_000:
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		N24   , Gn4 , v112
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N48   , Cn4 
	.byte	W21
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte	PEND
	.byte		VOICE , 46
	.byte		MOD   , 0
	.byte		PAN   , c_v-48
	.byte		N24   , Gn4 , v092
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Ds4 
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N48   , Cn4 
	.byte	W48
	.byte	PATT
	 .word	bgm_battle35_2_000
	.byte		VOICE , 46
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		N24   , Gn4 , v092
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Ds4 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N48   , Cn4 
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		N36   , An4 , v108
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , As4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W24
	.byte	W12
	.byte		N36   
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 60
	.byte		MOD   , 0
	.byte		N48   , As2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
bgm_battle35_2_001:
	.byte		MOD   , 0
	.byte		N72   , Fn3 , v108
	.byte	W36
	.byte	W03
	.byte		MOD   , 6
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
bgm_battle35_2_002:
	.byte		MOD   , 0
	.byte		N48   , Fs3 , v108
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , An3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_2_001
	.byte	PATT
	 .word	bgm_battle35_2_002
	.byte		MOD   , 0
	.byte		N72   , Fn3 , v108
	.byte	W36
	.byte	W03
	.byte		MOD   , 6
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N48   , Ds3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , An2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		TIE   , As3 
	.byte	W72
	.byte		MOD   , 4
	.byte	W24
	.byte	W06
	.byte		        5
	.byte	W03
	.byte		VOL   , 76*bgm_battle35_mvl/mxv
	.byte	W15
	.byte		        73*bgm_battle35_mvl/mxv
	.byte	W15
	.byte		MOD   , 6
	.byte		VOL   , 69*bgm_battle35_mvl/mxv
	.byte	W12
	.byte		        66*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        62*bgm_battle35_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 57*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        46*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        40*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        28*bgm_battle35_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		VOL   , 64*bgm_battle35_mvl/mxv
	.byte		TIE   , As4 , v092
	.byte	W09
	.byte		VOL   , 62*bgm_battle35_mvl/mxv
	.byte	W12
	.byte		        60*bgm_battle35_mvl/mxv
	.byte	W12
	.byte		        58*bgm_battle35_mvl/mxv
	.byte	W12
	.byte		        60*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        62*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        66*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        69*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        74*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        76*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        80*bgm_battle35_mvl/mxv
	.byte	W36
	.byte	W03
	.byte		EOT   
	.byte		N48   , Bn3 , v108
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v-32
	.byte		N24   , As3 , v100
	.byte	W24
	.byte		PAN   , c_v-23
	.byte		N24   , Fn3 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v-8
	.byte		N24   , Gs3 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v+8
	.byte		N24   , Fn3 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Gs3 
	.byte	W24
	.byte		PAN   , c_v+23
	.byte		N24   , Ds3 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v+23
	.byte		N24   , Fn3 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v+8
	.byte		N24   , Gs3 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , As3 
	.byte	W24
	.byte		PAN   , c_v-8
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v-25
	.byte		N24   , As3 
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		TIE   , Cn4 , v108
	.byte	W96
bgm_battle35_2_003:
	.byte		MOD   , 7
	.byte	W36
	.byte		VOL   , 75*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        67*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        62*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        55*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        49*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        42*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        35*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        27*bgm_battle35_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte		EOT   , Cn4 
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		TIE   , Fn3 , v108
	.byte	W96
	.byte	PATT
	 .word	bgm_battle35_2_003
	.byte		EOT   , Fn3 
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		N96   , Cn4 , v108
	.byte	W48
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte		N72   , Cn3 
	.byte	W36
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N96   , Ds3 
	.byte	W48
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte		N36   , Cn4 
	.byte	W18
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N36   , As3 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N96   , As3 
	.byte	W48
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte		N72   , Dn3 
	.byte	W36
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		TIE   , Ds3 
	.byte	W60
	.byte	W03
	.byte		MOD   , 5
	.byte	W32
	.byte	W01
	.byte		VOL   , 76*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		MOD   , 6
	.byte		VOL   , 74*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        71*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        69*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        64*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        60*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 56*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        51*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        45*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        40*bgm_battle35_mvl/mxv
	.byte	W09
	.byte		        31*bgm_battle35_mvl/mxv
	.byte	W06
	.byte		        18*bgm_battle35_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W03
	.byte	GOTO
	 .word	bgm_battle35_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle35_3:
	.byte	KEYSH , bgm_battle35_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N96   , Cn2 , v108
	.byte	W96
	.byte		N48   , As1 
	.byte	W48
	.byte		N24   , Gn1 
	.byte	W24
	.byte		        En1 
	.byte	W24
bgm_battle35_3_000:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
bgm_battle35_3_001:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_3_000
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_3_000
	.byte	PATT
	 .word	bgm_battle35_3_001
	.byte	PATT
	 .word	bgm_battle35_3_000
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
bgm_battle35_3_B1:
bgm_battle35_3_002:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
bgm_battle35_3_003:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
bgm_battle35_3_004:
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
bgm_battle35_3_005:
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
bgm_battle35_3_006:
	.byte		N12   , Fn1 , v108
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_3_006
	.byte	PATT
	 .word	bgm_battle35_3_004
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
bgm_battle35_3_007:
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
bgm_battle35_3_008:
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_3_007
	.byte	PATT
	 .word	bgm_battle35_3_008
	.byte		N12   , Fn1 , v108
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
bgm_battle35_3_009:
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
bgm_battle35_3_010:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_3_009
	.byte	PATT
	 .word	bgm_battle35_3_010
	.byte	PATT
	 .word	bgm_battle35_3_010
	.byte	PATT
	 .word	bgm_battle35_3_010
	.byte	PATT
	 .word	bgm_battle35_3_010
	.byte	PATT
	 .word	bgm_battle35_3_009
	.byte	PATT
	 .word	bgm_battle35_3_009
	.byte	PATT
	 .word	bgm_battle35_3_009
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
	.byte		        Bn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_3_009
	.byte	PATT
	 .word	bgm_battle35_3_009
	.byte	PATT
	 .word	bgm_battle35_3_009
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_3_002
	.byte	PATT
	 .word	bgm_battle35_3_002
	.byte	PATT
	 .word	bgm_battle35_3_007
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_3_002
	.byte	PATT
	 .word	bgm_battle35_3_003
	.byte	PATT
	 .word	bgm_battle35_3_004
	.byte	PATT
	 .word	bgm_battle35_3_005
	.byte	PATT
	 .word	bgm_battle35_3_006
	.byte	PATT
	 .word	bgm_battle35_3_006
	.byte	PATT
	 .word	bgm_battle35_3_004
	.byte		N12   , Ds1 , v108
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle35_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle35_4:
	.byte	KEYSH , bgm_battle35_key+0
	.byte		VOICE , 4
	.byte		LFOS  , 16
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		PAN   , c_v+48
	.byte	W18
	.byte		N06   , Cn6 , v052
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
	.byte	W72
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		N24   , Fn3 , v060
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W36
	.byte		        An2 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        An3 
	.byte	W24
	.byte		VOICE , 82
	.byte		N12   , Fn3 
	.byte	W36
	.byte		        An2 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W24
bgm_battle35_4_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N36   , Fn3 , v060
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		TIE   , As3 
	.byte	W56
	.byte	W01
	.byte		MOD   , 4
	.byte	W36
	.byte	W03
	.byte		        5
	.byte	W30
	.byte		        6
	.byte	W30
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N48   , As2 
	.byte	W48
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		N48   , Gs2 
	.byte	W48
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N48   , Cn3 
	.byte	W48
	.byte		        Gs2 
	.byte	W48
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		VOICE , 4
	.byte		N12   , As2 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W24
	.byte	W96
bgm_battle35_4_000:
	.byte	W12
	.byte		N12   , Cn3 , v060
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
	.byte	W60
	.byte		        As2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_4_000
	.byte	W36
	.byte		VOICE , 80
	.byte		N24   , Cn3 , v060
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 , v072
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 84
	.byte		N12   , Fn2 , v052
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
bgm_battle35_4_001:
	.byte		N12   , Gs2 , v052
	.byte	W48
	.byte		N48   , Bn2 
	.byte	W48
	.byte	PEND
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_4_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 4
	.byte		PAN   , c_v-48
	.byte		N03   , Cn5 , v052
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        As4 
	.byte	W12
	.byte		        Ds5 
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N03   , Cn5 , v040
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        As4 
	.byte	W12
	.byte		        Ds5 
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		N48   , Gs2 , v060
	.byte	W48
	.byte	GOTO
	 .word	bgm_battle35_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle35_5:
	.byte	KEYSH , bgm_battle35_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 16
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N06   , Cn3 , v052
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		VOICE , 86
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 , v032
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N12   , En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N24   
	.byte	W06
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N72   , Dn5 
	.byte	W36
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte	W24
bgm_battle35_5_B1:
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
	.byte		VOICE , 5
	.byte		N12   , Cn2 , v052
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
bgm_battle35_5_000:
	.byte		N12   , As1 , v052
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_5_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_battle35_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle35_6:
	.byte	KEYSH , bgm_battle35_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte		BEND  , c_v-2
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
bgm_battle35_6_B1:
	.byte		PAN   , c_v+48
	.byte		N12   , Cn2 , v064
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
bgm_battle35_6_000:
	.byte		N12   , Ds2 , v064
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_6_000
bgm_battle35_6_001:
	.byte		N12   , Fn2 , v064
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_6_001
	.byte	PATT
	 .word	bgm_battle35_6_000
	.byte	PATT
	 .word	bgm_battle35_6_000
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
	 .word	bgm_battle35_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_battle35_7:
	.byte	KEYSH , bgm_battle35_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte	W96
	.byte	W72
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle35_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
bgm_battle35_7_B1:
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
bgm_battle35_7_001:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_001
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_001
	.byte		N12   , Dn1 , v112
	.byte	W24
	.byte		N12   
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_7_001
	.byte	PATT
	 .word	bgm_battle35_7_000
bgm_battle35_7_002:
	.byte	W36
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_002
	.byte	PATT
	 .word	bgm_battle35_7_001
	.byte	PATT
	 .word	bgm_battle35_7_002
	.byte	PATT
	 .word	bgm_battle35_7_001
	.byte	PATT
	 .word	bgm_battle35_7_000
bgm_battle35_7_003:
	.byte	W12
	.byte		N12   , Dn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_003
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_003
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_003
	.byte		N96   , An2 , v096
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_000
	.byte	PATT
	 .word	bgm_battle35_7_001
	.byte	GOTO
	 .word	bgm_battle35_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_battle35_8:
	.byte	KEYSH , bgm_battle35_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v-8
	.byte		VOL   , 80*bgm_battle35_mvl/mxv
	.byte	W96
	.byte	W96
bgm_battle35_8_000:
	.byte		N12   , Cn2 , v124
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_8_000
	.byte	PATT
	 .word	bgm_battle35_8_000
	.byte	PATT
	 .word	bgm_battle35_8_000
	.byte	PATT
	 .word	bgm_battle35_8_000
	.byte	PATT
	 .word	bgm_battle35_8_000
	.byte	PATT
	 .word	bgm_battle35_8_000
	.byte	PATT
	 .word	bgm_battle35_8_000
bgm_battle35_8_B1:
bgm_battle35_8_001:
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	W12
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PATT
	 .word	bgm_battle35_8_001
bgm_battle35_8_002:
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_002
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_002
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
bgm_battle35_8_003:
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_003
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_003
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_003
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	PATT
	 .word	bgm_battle35_8_001
	.byte	GOTO
	 .word	bgm_battle35_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle35:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle35_pri	@ Priority
	.byte	bgm_battle35_rev	@ Reverb.

	.word	bgm_battle35_grp

	.word	bgm_battle35_1
	.word	bgm_battle35_2
	.word	bgm_battle35_3
	.word	bgm_battle35_4
	.word	bgm_battle35_5
	.word	bgm_battle35_6
	.word	bgm_battle35_7
	.word	bgm_battle35_8

	.end
