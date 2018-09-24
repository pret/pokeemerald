	.include "MPlayDef.s"

	.equ	mus_battle20_grp, voicegroup119
	.equ	mus_battle20_pri, 1
	.equ	mus_battle20_rev, reverb_set+50
	.equ	mus_battle20_mvl, 127
	.equ	mus_battle20_key, 0
	.equ	mus_battle20_tbs, 1
	.equ	mus_battle20_exg, 0
	.equ	mus_battle20_cmp, 1

	.section .rodata
	.global	mus_battle20
	.align	2

@********************** Track  1 **********************@

mus_battle20_1:
	.byte	KEYSH , mus_battle20_key+0
	.byte	TEMPO , 198*mus_battle20_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v+15
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		N06   , Cn5 , v076
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
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 17
	.byte		N12   , Gn3 , v080
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		        Gs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W36
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		        Gs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v+6
	.byte		N12   , Cn4 
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn4 , v088
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Gn4 
	.byte	W24
mus_battle20_1_B1:
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		N36   , Cn3 , v096
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N96   , Cs4 
	.byte	W96
	.byte		N48   
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		N36   , Cn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N72   , Cs4 
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N48   , Cs4 
	.byte	W48
	.byte		        Ds4 
	.byte	W48
	.byte		N36   , Cn4 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N92   , Cn4 
	.byte	W48
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        24*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        80*mus_battle20_mvl/mxv
	.byte		N48   , En2 
	.byte	W48
	.byte		N36   , Fn2 
	.byte	W36
	.byte		N12   , An2 
	.byte	W12
	.byte		N36   , As2 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N36   , Cn3 
	.byte	W36
	.byte		        Gn2 
	.byte	W36
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N96   , En2 
	.byte	W96
	.byte		N48   
	.byte	W48
	.byte		        Fn2 
	.byte	W48
	.byte		N36   , As2 
	.byte	W36
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N72   , Cn3 
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte		N96   , En3 
	.byte	W96
	.byte		N84   , Cn3 
	.byte	W84
	.byte		N12   , En3 
	.byte	W12
	.byte		N96   , Fn3 
	.byte	W96
	.byte		N72   
	.byte	W72
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N84   , En3 
	.byte	W84
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N72   , Gn3 
	.byte	W72
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N96   , As3 
	.byte	W96
	.byte		N72   , Fn3 
	.byte	W72
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N96   , Gn3 
	.byte	W96
	.byte		VOICE , 48
	.byte		N84   , Cn4 
	.byte	W84
	.byte		N12   , En4 
	.byte	W12
	.byte		N96   , Fn4 
	.byte	W96
	.byte		N72   
	.byte	W72
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N96   , En4 
	.byte	W96
	.byte		N48   , Cn5 
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        Cn2 
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		        Cs2 
	.byte	W48
	.byte		VOICE , 47
	.byte		PAN   , c_v-32
	.byte		N12   , Cn2 , v092
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v+6
	.byte		N12   , As3 , v096
	.byte	W12
	.byte		TIE   , Cn4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Cn3 , v076
	.byte	W96
	.byte	W48
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        24*mus_battle20_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 60
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N96   , Fn2 , v096
	.byte	W96
	.byte		        As2 
	.byte	W96
	.byte		        Gn2 
	.byte	W96
mus_battle20_1_000:
	.byte		N92   , En2 , v096
	.byte	W48
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        24*mus_battle20_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		        80*mus_battle20_mvl/mxv
	.byte		N96   , Fn2 
	.byte	W96
	.byte		        As2 
	.byte	W96
	.byte		        Gn2 
	.byte	W96
	.byte	PATT
	 .word	mus_battle20_1_000
	.byte		VOICE , 17
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v+15
	.byte		N12   , Gn3 , v088
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		        En3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , As2 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		        En3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Gs3 
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v+6
	.byte		N48   , Cn4 , v096
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte	GOTO
	 .word	mus_battle20_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_battle20_2:
	.byte	KEYSH , mus_battle20_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 20
	.byte		PAN   , c_v-14
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		N06   , Gn5 , v064
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		VOICE , 17
	.byte		N12   , Cn4 , v088
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W36
	.byte		        Ds4 
	.byte	W36
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W36
	.byte		N24   , Gs4 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N12   , Cn5 
	.byte	W36
	.byte		        Ds5 
	.byte	W36
	.byte		        Cs5 
	.byte	W24
	.byte		        Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W24
	.byte		        Ds5 
	.byte	W36
	.byte		N24   , Cs5 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W36
	.byte		        Ds5 
	.byte	W36
	.byte		        Cs5 
	.byte	W24
	.byte		        Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W24
	.byte		        Ds5 
	.byte	W36
	.byte		N24   , Gn5 , v076
	.byte	W24
mus_battle20_2_B1:
	.byte		VOICE , 60
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Cn4 , v100
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N72   , Gs4 
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte		VOICE , 56
	.byte		N48   , Cn4 , v104
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N42   , As3 
	.byte	W21
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N72   , Gs4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N36   , As4 
	.byte	W36
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N60   , Gn4 
	.byte	W30
	.byte		MOD   , 7
	.byte	W30
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N92   , En4 
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        24*mus_battle20_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , As2 
	.byte	W48
	.byte		        Dn3 
	.byte	W48
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N72   , En3 
	.byte	W72
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N96   , Gn3 
	.byte	W96
	.byte		N48   , As2 
	.byte	W48
	.byte		        Dn3 
	.byte	W48
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N72   , En4 
	.byte	W72
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N92   , Cn5 
	.byte	W54
	.byte		VOL   , 73*mus_battle20_mvl/mxv
	.byte	W09
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        59*mus_battle20_mvl/mxv
	.byte	W09
	.byte		        50*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        40*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        26*mus_battle20_mvl/mxv
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N36   , Cn4 , v100
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte		N36   , Dn4 
	.byte	W36
mus_battle20_2_000:
	.byte		N36   , Fn4 , v100
	.byte	W36
	.byte		N24   , As4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	PEND
	.byte		N48   , En4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		N36   
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N60   , As4 
	.byte	W60
	.byte	PATT
	 .word	mus_battle20_2_000
	.byte		N36   , En4 , v100
	.byte	W36
	.byte		N60   , Cn4 
	.byte	W60
	.byte		VOICE , 1
	.byte		N36   , Cn5 , v104
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N36   , Fn5 
	.byte	W36
	.byte		N24   , As4 
	.byte	W24
	.byte		N36   , Dn5 
	.byte	W36
	.byte		        Fn5 
	.byte	W36
	.byte		N24   , As5 
	.byte	W24
	.byte		N12   , An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N36   , En5 
	.byte	W36
	.byte		        Cn5 
	.byte	W36
	.byte		N24   , Gn5 
	.byte	W24
	.byte		N36   , Cn6 
	.byte	W36
	.byte		        Cs6 
	.byte	W36
	.byte		N24   , Cn4 , v108
	.byte	W24
	.byte		N36   , Gn5 , v104
	.byte	W36
	.byte		        Gs5 
	.byte	W36
	.byte		N24   , Cs4 , v108
	.byte	W24
	.byte		N36   , Cn5 , v104
	.byte	W36
	.byte		        Cs5 
	.byte	W36
	.byte		N24   , Cn3 , v108
	.byte	W24
	.byte		N36   , Gn4 , v104
	.byte	W36
	.byte		        Gs4 
	.byte	W36
	.byte		N24   , Cs3 , v108
	.byte	W24
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N96   , Cn3 , v104
	.byte	W96
mus_battle20_2_001:
	.byte		N84   , Cn2 , v104
	.byte	W84
	.byte		N12   , Cn3 
	.byte	W12
	.byte	PEND
	.byte		N96   , Cs3 
	.byte	W96
	.byte		N84   , Cs2 
	.byte	W84
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N96   , Cn3 
	.byte	W96
	.byte	PATT
	 .word	mus_battle20_2_001
	.byte		N96   , As2 , v104
	.byte	W96
	.byte		        Dn3 
	.byte	W96
	.byte		        Fn3 
	.byte	W96
	.byte		N84   , As3 
	.byte	W84
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		TIE   , En4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , En3 , v096
	.byte	W96
	.byte	W48
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        24*mus_battle20_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 60
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Cn3 , v100
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N48   , As3 
	.byte	W48
	.byte		        An3 
	.byte	W48
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N92   , Gn3 
	.byte	W48
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        24*mus_battle20_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		N24   , Cn3 , v104
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W15
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N48   , Dn4 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , En4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N92   , Cn4 
	.byte	W32
	.byte	W01
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        24*mus_battle20_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 17
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		N12   , Cn4 , v096
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		        Cn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		N12   , Cn5 , v092
	.byte	W36
	.byte		        Cs5 
	.byte	W36
	.byte		        Cn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W36
	.byte		        Cs5 
	.byte	W36
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W36
	.byte		        Cs5 
	.byte	W36
	.byte		N24   , As4 
	.byte	W24
	.byte	GOTO
	 .word	mus_battle20_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_battle20_3:
	.byte	KEYSH , mus_battle20_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N96   , Cn1 , v108
	.byte	W96
	.byte		N60   , Cs1 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
mus_battle20_3_000:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
mus_battle20_3_001:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_3_000
	.byte	PATT
	 .word	mus_battle20_3_001
	.byte	PATT
	 .word	mus_battle20_3_000
	.byte	PATT
	 .word	mus_battle20_3_001
	.byte	PATT
	 .word	mus_battle20_3_000
	.byte	PATT
	 .word	mus_battle20_3_001
mus_battle20_3_B1:
mus_battle20_3_002:
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
mus_battle20_3_003:
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
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle20_3_002
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
	 .word	mus_battle20_3_003
	.byte	PATT
	 .word	mus_battle20_3_003
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
mus_battle20_3_004:
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
	 .word	mus_battle20_3_004
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_004
	.byte	PATT
	 .word	mus_battle20_3_004
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
mus_battle20_3_005:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
mus_battle20_3_006:
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
	.byte	PATT
	 .word	mus_battle20_3_006
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle20_3_006
	.byte	PATT
	 .word	mus_battle20_3_005
	.byte	PATT
	 .word	mus_battle20_3_005
	.byte	PATT
	 .word	mus_battle20_3_006
	.byte	PATT
	 .word	mus_battle20_3_006
	.byte	PATT
	 .word	mus_battle20_3_005
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_003
	.byte	PATT
	 .word	mus_battle20_3_003
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_004
	.byte	PATT
	 .word	mus_battle20_3_004
	.byte	PATT
	 .word	mus_battle20_3_004
	.byte	PATT
	 .word	mus_battle20_3_004
mus_battle20_3_007:
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_3_007
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte		N12   , Cn1 , v108
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
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
mus_battle20_3_008:
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
	 .word	mus_battle20_3_008
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_008
	.byte	PATT
	 .word	mus_battle20_3_008
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_002
	.byte	PATT
	 .word	mus_battle20_3_000
	.byte	PATT
	 .word	mus_battle20_3_001
	.byte	PATT
	 .word	mus_battle20_3_000
	.byte	PATT
	 .word	mus_battle20_3_001
	.byte	PATT
	 .word	mus_battle20_3_000
	.byte	PATT
	 .word	mus_battle20_3_001
	.byte	PATT
	 .word	mus_battle20_3_000
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	GOTO
	 .word	mus_battle20_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_battle20_4:
	.byte	KEYSH , mus_battle20_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 20
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		N24   , Gs3 , v052
	.byte	W24
mus_battle20_4_000:
	.byte		N12   , Gn3 , v052
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PEND
	.byte		        Gn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle20_4_000
	.byte		N12   , Gn3 , v052
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
mus_battle20_4_B1:
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
	.byte	W60
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		N03   , Gn1 , v060
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
mus_battle20_4_001:
	.byte		N03   , Gn1 , v060
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_battle20_4_002:
	.byte		N03   , Fn1 , v060
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_battle20_4_003:
	.byte		N03   , As1 , v060
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_4_001
	.byte	PATT
	 .word	mus_battle20_4_001
	.byte	PATT
	 .word	mus_battle20_4_002
	.byte	PATT
	 .word	mus_battle20_4_003
	.byte	PATT
	 .word	mus_battle20_4_001
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
	.byte		VOICE , 80
	.byte		N96   , Fn2 , v060
	.byte	W96
	.byte		        As2 
	.byte	W96
	.byte		        Dn3 
	.byte	W96
	.byte		N84   , Fn3 
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte		TIE   , Gn3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	W96
	.byte	W96
	.byte		VOICE , 4
	.byte		PAN   , c_v-48
	.byte		N12   , Fn4 , v040
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
mus_battle20_4_004:
	.byte		N12   , Fn4 , v040
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
mus_battle20_4_005:
	.byte		N12   , En4 , v040
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_4_005
	.byte	PATT
	 .word	mus_battle20_4_004
	.byte		N12   , Fn4 , v032
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 , v020
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		VOICE , 6
	.byte		PAN   , c_v+0
	.byte		N48   , Cn3 , v052
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Cn2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Gn2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Cs2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Cn3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Cn2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Gn2 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Cs3 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		VOICE , 6
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N12   , Gn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W36
	.byte		        Gn3 
	.byte	W24
	.byte		        En4 
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W36
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W36
	.byte		N24   , Fn4 
	.byte	W24
	.byte	GOTO
	 .word	mus_battle20_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_battle20_5:
	.byte	KEYSH , mus_battle20_key+0
	.byte		VOICE , 4
	.byte		LFOS  , 20
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		N06   , Gn3 , v060
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v+1
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+50
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+1
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		N12   , Gn4 , v052
	.byte	W36
	.byte		        As4 
	.byte	W36
	.byte		        Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		        As4 
	.byte	W36
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W36
	.byte		        As4 
	.byte	W36
	.byte		        Gs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W24
	.byte		        As4 
	.byte	W36
	.byte		N24   , Cs5 
	.byte	W24
mus_battle20_5_B1:
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
	.byte		VOICE , 6
	.byte		PAN   , c_v+0
	.byte		N96   , Cn3 , v060
	.byte	W48
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N48   , Gn2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N72   , Gn3 
	.byte	W36
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N24   , En4 
	.byte	W24
	.byte		N92   , Gn4 
	.byte	W36
	.byte	W03
	.byte		MOD   , 6
	.byte	W15
	.byte		VOL   , 73*mus_battle20_mvl/mxv
	.byte	W09
	.byte		        66*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        59*mus_battle20_mvl/mxv
	.byte	W09
	.byte		        50*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        40*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        26*mus_battle20_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		N03   , Gn2 , v072
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
mus_battle20_5_000:
	.byte		N03   , Gn2 , v072
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_battle20_5_001:
	.byte		N03   , Fn2 , v072
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_battle20_5_002:
	.byte		N03   , As2 , v072
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N21   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_5_000
	.byte	PATT
	 .word	mus_battle20_5_000
	.byte	PATT
	 .word	mus_battle20_5_001
	.byte	PATT
	 .word	mus_battle20_5_002
	.byte	PATT
	 .word	mus_battle20_5_000
	.byte		VOICE , 4
	.byte		N36   , Cn4 , v072
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N36   , Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N36   , Cn3 
	.byte	W36
	.byte		        Cs3 
	.byte	W36
	.byte		N24   , Cn1 
	.byte	W24
	.byte		N36   , Gn2 
	.byte	W36
	.byte		        Gs2 
	.byte	W36
	.byte		N24   , Cs1 
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v-49
	.byte		N12   , As1 , v060
	.byte	W12
	.byte		VOICE , 85
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Dn2 
	.byte	W12
	.byte		VOICE , 85
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Fn2 
	.byte	W12
	.byte		VOICE , 85
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , As2 
	.byte	W12
	.byte		VOICE , 85
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		VOICE , 85
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
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		N12   , En2 
	.byte	W12
	.byte		VOICE , 85
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
	.byte		VOL   , 75*mus_battle20_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 71*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        66*mus_battle20_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 60*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        53*mus_battle20_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 45*mus_battle20_mvl/mxv
	.byte	W06
	.byte		        35*mus_battle20_mvl/mxv
	.byte		N09   
	.byte	W06
	.byte		VOL   , 24*mus_battle20_mvl/mxv
	.byte	W06
	.byte		VOICE , 5
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W06
	.byte		N12   , Fn4 , v032
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
mus_battle20_5_003:
	.byte	W06
	.byte		N12   , Fn4 , v032
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte	PEND
mus_battle20_5_004:
	.byte	W06
	.byte		N12   , En4 , v032
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_5_004
	.byte	PATT
	 .word	mus_battle20_5_003
	.byte	W06
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte	W06
	.byte		        En4 , v012
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 7
	.byte		PAN   , c_v-48
	.byte		N12   , Gn3 , v052
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
	.byte	GOTO
	 .word	mus_battle20_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_battle20_6:
	.byte	KEYSH , mus_battle20_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte	W24
	.byte		N06   , Cn2 , v080
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W30
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_battle20_6_B1:
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
	.byte		VOICE , 90
	.byte		N96   , Fn1 , v080
	.byte	W96
	.byte		        As1 
	.byte	W96
	.byte		        Dn2 
	.byte	W96
	.byte		N84   , Fn2 
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
	 .word	mus_battle20_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_battle20_7:
	.byte	KEYSH , mus_battle20_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte	W96
	.byte	W84
	.byte		N12   , Dn1 , v112
	.byte	W12
mus_battle20_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
mus_battle20_7_B1:
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W72
	.byte	W24
	.byte		N12   
	.byte	W72
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W72
	.byte	W24
	.byte		N12   
	.byte	W72
	.byte	PATT
	 .word	mus_battle20_7_000
mus_battle20_7_001:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_001
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
mus_battle20_7_002:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	W24
	.byte		N48   , An2 , v100
	.byte	W48
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_001
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_000
	.byte	PATT
	 .word	mus_battle20_7_002
	.byte	GOTO
	 .word	mus_battle20_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_battle20_8:
	.byte	KEYSH , mus_battle20_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_battle20_mvl/mxv
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		PAN   , c_v-32
	.byte		N12   , An1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N12   
	.byte	W24
mus_battle20_8_000:
	.byte		PAN   , c_v+0
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	PEND
mus_battle20_8_001:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_8_001
mus_battle20_8_002:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte		        An1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
mus_battle20_8_B1:
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
mus_battle20_8_003:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		VOICE , 46
	.byte		N12   , Cn2 , v127
	.byte	W24
	.byte	PEND
mus_battle20_8_004:
	.byte		VOICE , 47
	.byte	W12
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		        An1 
	.byte	W24
	.byte		VOICE , 46
	.byte		N12   , Cn2 , v127
	.byte	W24
	.byte	PEND
	.byte		VOICE , 47
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	PATT
	 .word	mus_battle20_8_002
	.byte	PATT
	 .word	mus_battle20_8_003
	.byte	PATT
	 .word	mus_battle20_8_004
	.byte		VOICE , 47
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte		        An1 
	.byte	W12
mus_battle20_8_005:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
mus_battle20_8_006:
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_8_006
	.byte	PATT
	 .word	mus_battle20_8_006
mus_battle20_8_007:
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        An1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_8_006
	.byte	PATT
	 .word	mus_battle20_8_006
	.byte	PATT
	 .word	mus_battle20_8_006
	.byte	PATT
	 .word	mus_battle20_8_006
	.byte	PATT
	 .word	mus_battle20_8_006
	.byte	PATT
	 .word	mus_battle20_8_007
	.byte	PATT
	 .word	mus_battle20_8_006
	.byte	PATT
	 .word	mus_battle20_8_006
mus_battle20_8_008:
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_battle20_8_008
	.byte	PATT
	 .word	mus_battle20_8_008
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte	MEMACC, mem_set, 0x00, 117
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		N12   , Gn2 , v088
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , En2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		N06   , En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PATT
	 .word	mus_battle20_8_000
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte		N09   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte		N12   
	.byte	W96
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_002
	.byte	PATT
	 .word	mus_battle20_8_005
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte	PATT
	 .word	mus_battle20_8_001
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	GOTO
	 .word	mus_battle20_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_battle20:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_battle20_pri	@ Priority
	.byte	mus_battle20_rev	@ Reverb.

	.word	mus_battle20_grp

	.word	mus_battle20_1
	.word	mus_battle20_2
	.word	mus_battle20_3
	.word	mus_battle20_4
	.word	mus_battle20_5
	.word	mus_battle20_6
	.word	mus_battle20_7
	.word	mus_battle20_8

	.end
