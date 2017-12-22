	.include "MPlayDef.s"

	.equ	mus_battle27_grp, voicegroup_869A454
	.equ	mus_battle27_pri, 1
	.equ	mus_battle27_rev, reverb_set+50
	.equ	mus_battle27_mvl, 127
	.equ	mus_battle27_key, 0
	.equ	mus_battle27_tbs, 1
	.equ	mus_battle27_exg, 0
	.equ	mus_battle27_cmp, 1

	.section .rodata
	.global	mus_battle27
	.align	2

@********************** Track  1 **********************@

mus_battle27_1:
	.byte	KEYSH , mus_battle27_key+0
	.byte	TEMPO , 196*mus_battle27_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		LFOS  , 18
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 , v108
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		VOICE , 60
	.byte		PAN   , c_v+10
	.byte		N12   , Gn3 , v092
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N24   , Bn3 
	.byte	W24
mus_battle27_1_000:
	.byte		VOICE , 56
	.byte		N12   , Gn4 , v092
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W24
	.byte	PEND
mus_battle27_1_001:
	.byte		N12   , Gs4 , v092
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W24
	.byte	PEND
mus_battle27_1_002:
	.byte		N12   , Gn4 , v092
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W24
	.byte	PEND
	.byte		        Gs4 
	.byte	W36
	.byte		        As4 
	.byte	W36
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
mus_battle27_1_003:
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		N12   , Cn3 , v092
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte	PEND
mus_battle27_1_B1:
	.byte		N12   , Fn3 , v092
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
mus_battle27_1_004:
	.byte		VOICE , 56
	.byte		N48   , Fn3 , v092
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte	PEND
	.byte		        0
	.byte		N36   , Dn4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		VOICE , 48
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_1_004
	.byte		MOD   , 0
	.byte		N36   , Dn4 , v092
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		VOICE , 60
	.byte		N36   , Cn4 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W24
	.byte		N36   , En4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N36   , As3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N36   , Dn4 
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W24
	.byte		N96   , En4 
	.byte	W96
mus_battle27_1_005:
	.byte		N72   , Cn4 , v092
	.byte	W72
	.byte		N24   , Gn3 
	.byte	W24
	.byte	PEND
	.byte		N60   , En4 
	.byte	W30
	.byte		VOL   , 76*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        72*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        61*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        49*mus_battle27_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W24
	.byte		VOICE , 48
	.byte		N48   , As3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		N24   , As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte	PATT
	 .word	mus_battle27_1_005
	.byte		N60   , En4 , v092
	.byte	W21
	.byte		VOL   , 76*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        73*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        68*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        59*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        30*mus_battle27_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		VOICE , 60
	.byte		N60   , Gs4 
	.byte	W60
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N60   , Cn4 
	.byte	W96
	.byte	W48
	.byte		N48   , En4 
	.byte	W48
	.byte		VOICE , 48
	.byte		N12   , Gn2 
	.byte	W36
	.byte		        Cn2 
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		        Gs2 
	.byte	W36
	.byte		        Fn2 
	.byte	W36
	.byte		        Gs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W36
	.byte		        Cn2 
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		        Gs2 
	.byte	W36
	.byte		        Fn2 
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte	PATT
	 .word	mus_battle27_1_000
	.byte	PATT
	 .word	mus_battle27_1_001
	.byte	PATT
	 .word	mus_battle27_1_002
	.byte		N12   , Gs4 , v092
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_1_003
	.byte	GOTO
	 .word	mus_battle27_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_battle27_2:
	.byte	KEYSH , mus_battle27_key+0
	.byte		VOICE , 46
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		LFOS  , 18
	.byte		PAN   , c_v-16
	.byte		N06   , Gn5 , v100
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v+17
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		VOICE , 60
	.byte		PAN   , c_v-10
	.byte		N12   , Cn4 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Fn4 
	.byte	W24
mus_battle27_2_000:
	.byte		VOICE , 56
	.byte		N12   , Cn5 , v100
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		        Cn5 
	.byte	W24
	.byte	PEND
mus_battle27_2_001:
	.byte		N12   , Cs5 , v100
	.byte	W36
	.byte		        Ds5 
	.byte	W36
	.byte		        Cs5 
	.byte	W24
	.byte	PEND
mus_battle27_2_002:
	.byte		N12   , Cn5 , v100
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		        Cn5 
	.byte	W24
	.byte	PEND
mus_battle27_2_003:
	.byte		N12   , Cs5 , v100
	.byte	W36
	.byte		        Ds5 
	.byte	W36
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte	PEND
mus_battle27_2_004:
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N36   , Cn4 , v100
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N36   , Dn4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W09
	.byte	PEND
mus_battle27_2_B1:
	.byte		MOD   , 0
	.byte		N12   , Fn4 , v100
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
mus_battle27_2_005:
	.byte		N48   , As3 , v100
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Dn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte	PEND
	.byte		        0
	.byte		N36   , Fn4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N24   , An4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N36   , Cn4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N36   , Dn4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W15
	.byte		MOD   , 5
	.byte	W09
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W09
	.byte		MOD   , 5
	.byte	W15
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_2_005
	.byte		MOD   , 0
	.byte		N36   , Fn4 , v100
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        0
	.byte		N24   , As4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		VOICE , 48
	.byte		N72   , En4 , v096
	.byte	W72
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N96   , Gn4 
	.byte	W48
	.byte		VOL   , 76*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        72*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        66*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        57*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        39*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        20*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        80*mus_battle27_mvl/mxv
	.byte		N72   , Dn4 
	.byte	W72
	.byte		N24   , As3 
	.byte	W24
	.byte		N96   , Fn4 
	.byte	W48
	.byte		VOL   , 76*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        72*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        66*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        57*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        39*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        20*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        80*mus_battle27_mvl/mxv
	.byte		N72   , En4 
	.byte	W72
	.byte		N24   , Cn4 
	.byte	W24
	.byte		TIE   , Gn4 
	.byte	W96
	.byte	W48
	.byte		VOL   , 76*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        72*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        66*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        57*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        39*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        20*mus_battle27_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte	W60
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		N12   , Gn4 , v100
	.byte	W12
	.byte		        An4 
	.byte	W24
	.byte		N96   , As4 
	.byte	W48
	.byte		VOL   , 76*mus_battle27_mvl/mxv
	.byte		MOD   , 5
	.byte	W09
	.byte		VOL   , 72*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        66*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        57*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        39*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        20*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        80*mus_battle27_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N72   , En4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 5
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N60   , Gn4 
	.byte	W21
	.byte		VOL   , 76*mus_battle27_mvl/mxv
	.byte	W09
	.byte		        73*mus_battle27_mvl/mxv
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 68*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        59*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        30*mus_battle27_mvl/mxv
	.byte	W06
	.byte		        80*mus_battle27_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   
	.byte	W12
	.byte		        Cn5 
	.byte	W24
	.byte		VOICE , 48
	.byte		N84   , Cs5 
	.byte	W84
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N60   , Gs4 
	.byte	W60
	.byte		N12   , As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W48
	.byte		        Cn5 
	.byte	W48
	.byte		PAN   , c_v-10
	.byte		N12   , Cn3 
	.byte	W36
	.byte		        Gn2 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W36
	.byte		        Ds3 
	.byte	W36
	.byte		        Cs3 
	.byte	W24
	.byte		        Cn3 
	.byte	W36
	.byte		        Gn2 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W36
	.byte		        Ds3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
	.byte	PATT
	 .word	mus_battle27_2_000
	.byte	PATT
	 .word	mus_battle27_2_001
	.byte	PATT
	 .word	mus_battle27_2_002
	.byte	PATT
	 .word	mus_battle27_2_003
	.byte	PATT
	 .word	mus_battle27_2_004
	.byte	GOTO
	 .word	mus_battle27_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_battle27_3:
	.byte	KEYSH , mus_battle27_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		N96   , Gn0 , v108
	.byte	W96
	.byte		N48   , As0 
	.byte	W48
	.byte		        Bn0 
	.byte	W48
mus_battle27_3_000:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
mus_battle27_3_001:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle27_3_000
	.byte	PATT
	 .word	mus_battle27_3_001
	.byte	PATT
	 .word	mus_battle27_3_000
	.byte	PATT
	 .word	mus_battle27_3_001
	.byte	PATT
	 .word	mus_battle27_3_000
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
mus_battle27_3_002:
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
mus_battle27_3_B1:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
mus_battle27_3_003:
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
mus_battle27_3_004:
	.byte		N12   , As0 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_3_003
	.byte	PATT
	 .word	mus_battle27_3_004
	.byte		N12   , En1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte		N12   , Dn1 , v108
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
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
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
mus_battle27_3_005:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        En1 
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
	.byte		        En1 
	.byte	W36
	.byte	PATT
	 .word	mus_battle27_3_005
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An1 
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
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        As1 
	.byte	W12
mus_battle27_3_006:
	.byte		N12   , Gn1 , v108
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle27_3_006
mus_battle27_3_007:
	.byte		N12   , Gs1 , v108
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle27_3_007
	.byte	PATT
	 .word	mus_battle27_3_006
	.byte		N12   , Gn1 , v108
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_3_002
	.byte	GOTO
	 .word	mus_battle27_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_battle27_4:
	.byte	KEYSH , mus_battle27_key+0
	.byte		VOICE , 4
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		LFOS  , 18
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte	W18
	.byte		PAN   , c_v+48
	.byte		N06   , Cn6 , v052
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-47
	.byte		N06   
	.byte	W06
	.byte	W18
	.byte		PAN   , c_v+48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v+50
	.byte		N06   
	.byte	W24
	.byte		PAN   , c_v-47
	.byte		N06   
	.byte	W06
	.byte	W36
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		N12   , Gn2 , v060
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W36
	.byte		        Gs2 
	.byte	W36
	.byte		        Cs3 
	.byte	W24
	.byte		        Cn3 
	.byte	W36
	.byte		        Gn2 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W36
	.byte		        Gs2 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
mus_battle27_4_000:
	.byte		N12   , Cn4 , v060
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		        Cn4 
	.byte	W24
	.byte	PEND
	.byte		        Cs4 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		        Cs4 
	.byte	W24
	.byte	PATT
	 .word	mus_battle27_4_000
	.byte		N12   , Cs4 , v060
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Fn4 
	.byte	W24
mus_battle27_4_001:
	.byte		VOICE , 80
	.byte		PAN   , c_v+48
	.byte		N12   , Gn2 , v060
	.byte	W24
	.byte		N36   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
mus_battle27_4_B1:
mus_battle27_4_002:
	.byte		N12   , Gn2 , v060
	.byte	W24
	.byte		N36   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte		        As2 
	.byte	W24
	.byte		N36   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N36   , An2 
	.byte	W48
	.byte		N24   , Fn2 
	.byte	W24
	.byte	PATT
	 .word	mus_battle27_4_002
	.byte		N12   , Gn2 , v060
	.byte	W24
	.byte		N36   
	.byte	W48
	.byte		N12   , An2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N24   
	.byte	W48
	.byte		        Dn3 
	.byte	W24
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N72   , En2 
	.byte	W72
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N60   , Gn2 
	.byte	W72
	.byte		N12   , Cn4 
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Fn4 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N48   , En5 
	.byte	W18
	.byte		MOD   , 5
	.byte	W30
	.byte		        0
	.byte	W48
	.byte	W60
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		N60   , Fn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		N36   , Cn4 , v072
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N36   , En4 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
mus_battle27_4_003:
	.byte		N12   , Cn4 , v072
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PEND
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_4_003
	.byte		N12   , Cn4 , v072
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle27_4_001
	.byte	GOTO
	 .word	mus_battle27_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_battle27_5:
	.byte	KEYSH , mus_battle27_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn3 , v064
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		N12   , Gn5 , v048
	.byte	W96
mus_battle27_5_B1:
	.byte		PAN   , c_v-48
	.byte	W96
	.byte		N48   , Dn3 , v064
	.byte	W48
	.byte		        Fn3 
	.byte	W48
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N60   , Fn3 
	.byte	W60
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N24   , Dn3 
	.byte	W48
	.byte		        Fn3 
	.byte	W24
	.byte	W24
	.byte		N12   , As3 
	.byte	W72
	.byte		PAN   , c_v+0
	.byte	W96
	.byte		N72   , Gn2 
	.byte	W72
	.byte		N24   , An2 
	.byte	W24
	.byte		N96   , As2 
	.byte	W96
	.byte		N72   , Dn3 
	.byte	W72
	.byte		N24   , As2 
	.byte	W24
	.byte		N72   , Cn3 
	.byte	W72
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N96   , Cn3 
	.byte	W96
	.byte		N36   , En3 
	.byte	W36
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N66   , Cn3 
	.byte	W84
	.byte		PAN   , c_v-48
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
mus_battle27_5_000:
	.byte		N24   , En3 , v064
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte	PEND
	.byte		        En3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W24
	.byte		N24   , Cs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte	PATT
	 .word	mus_battle27_5_000
	.byte		N48   , Gn3 , v064
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	GOTO
	 .word	mus_battle27_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_battle27_6:
	.byte	KEYSH , mus_battle27_key+0
	.byte		VOL   , 80*mus_battle27_mvl/mxv
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
mus_battle27_6_B1:
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
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		VOICE , 5
	.byte		PAN   , c_v-32
	.byte		N36   , Cn4 , v032
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W12
	.byte	W12
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W12
	.byte	W12
	.byte		N36   , En4 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W12
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	W96
	.byte	GOTO
	 .word	mus_battle27_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_battle27_7:
	.byte	KEYSH , mus_battle27_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte	W96
	.byte	W72
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
mus_battle27_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
mus_battle27_7_B1:
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
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
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	PATT
	 .word	mus_battle27_7_000
	.byte	GOTO
	 .word	mus_battle27_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_battle27_8:
	.byte	KEYSH , mus_battle27_key+0
	.byte		VOICE , 47
	.byte		VOL   , 80*mus_battle27_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W96
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W48
mus_battle27_8_000:
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
mus_battle27_8_B1:
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte		N12   , Cn2 , v112
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	PATT
	 .word	mus_battle27_8_000
	.byte	GOTO
	 .word	mus_battle27_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_battle27:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_battle27_pri	@ Priority
	.byte	mus_battle27_rev	@ Reverb.

	.word	mus_battle27_grp

	.word	mus_battle27_1
	.word	mus_battle27_2
	.word	mus_battle27_3
	.word	mus_battle27_4
	.word	mus_battle27_5
	.word	mus_battle27_6
	.word	mus_battle27_7
	.word	mus_battle27_8

	.end
