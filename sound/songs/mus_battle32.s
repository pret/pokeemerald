	.include "MPlayDef.s"

	.equ	mus_battle32_grp, voicegroup_869B0B4
	.equ	mus_battle32_pri, 1
	.equ	mus_battle32_rev, reverb_set+50
	.equ	mus_battle32_mvl, 127
	.equ	mus_battle32_key, 0
	.equ	mus_battle32_tbs, 1
	.equ	mus_battle32_exg, 0
	.equ	mus_battle32_cmp, 1

	.section .rodata
	.global	mus_battle32
	.align	2

@********************** Track  1 **********************@

mus_battle32_1:
	.byte	KEYSH , mus_battle32_key+0
	.byte	TEMPO , 196*mus_battle32_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte		LFOS  , 18
	.byte		PAN   , c_v-10
	.byte		N06   , Cn5 , v092
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
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
	.byte		VOICE , 56
	.byte		PAN   , c_v+10
	.byte		N12   , Gn3 , v104
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
	.byte		VOICE , 60
	.byte		PAN   , c_v-16
	.byte		N48   , Cn4 , v100
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
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
mus_battle32_1_B1:
	.byte		PAN   , c_v+10
	.byte		N48   , Gn3 , v100
	.byte	W48
	.byte		N42   , Fn3 
	.byte	W42
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N12   , Cn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		N60   , Gn3 
	.byte	W60
	.byte		PAN   , c_v+16
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		N24   , As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N72   , Gn3 
	.byte	W72
	.byte		N24   , En3 
	.byte	W24
	.byte		N92   , Cn4 
	.byte	W96
	.byte		N48   , Dn4 
	.byte	W12
	.byte		PAN   , c_v+20
	.byte	W36
	.byte		N48   , Cn4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		N72   , En4 
	.byte	W72
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N92   , Cn4 
	.byte	W96
	.byte		VOICE , 1
	.byte		PAN   , c_v+10
	.byte		N36   , Cn3 , v108
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W36
	.byte		N12   , Cn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		N12   , As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		N60   , Gn3 
	.byte	W56
	.byte	W01
	.byte		VOICE , 56
	.byte	W03
	.byte		N48   , Dn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N72   , Gn3 
	.byte	W36
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N24   , En3 
	.byte	W24
	.byte		N56   , Cn4 , v104
	.byte	W30
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 76*mus_battle32_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle32_mvl/mxv
	.byte	W06
	.byte		        64*mus_battle32_mvl/mxv
	.byte	W03
	.byte		        49*mus_battle32_mvl/mxv
	.byte	W03
	.byte		        33*mus_battle32_mvl/mxv
	.byte	W03
	.byte		        17*mus_battle32_mvl/mxv
	.byte	W03
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte	W03
	.byte		PAN   , c_v+20
	.byte		N12   , Gn3 , v092
	.byte	W03
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte	W09
	.byte		N12   , Cn4 
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		N72   , En4 
	.byte	W72
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N92   , Gn4 
	.byte	W96
	.byte		VOICE , 1
	.byte		N36   , Gn3 , v108
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N36   , An3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
	.byte		TIE   , Gn3 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte		PAN   , c_v+10
	.byte		TIE   , Cn3 , v100
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N96   , Cs3 
	.byte	W96
	.byte		        Ds3 
	.byte	W96
	.byte		TIE   , Cn3 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N96   , Cs3 
	.byte	W96
	.byte		        Ds3 
	.byte	W96
	.byte		TIE   , As2 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 48
	.byte		PAN   , c_v+20
	.byte		N96   , Gn2 
	.byte	W96
	.byte		N48   , Fn2 
	.byte	W48
	.byte		        Gn2 
	.byte	W48
	.byte		N96   , Cn2 
	.byte	W96
	.byte		        Gn2 
	.byte	W96
	.byte		        Gs2 
	.byte	W96
	.byte		N48   , Fn2 
	.byte	W48
	.byte		        Gs2 
	.byte	W48
	.byte		N96   , Gn2 
	.byte	W96
	.byte		        Cn3 
	.byte	W96
	.byte	GOTO
	 .word	mus_battle32_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_battle32_2:
	.byte	KEYSH , mus_battle32_key+0
	.byte		VOICE , 1
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte		LFOS  , 18
	.byte		PAN   , c_v+10
	.byte		N06   , Gn5 , v080
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		N12   , Cn4 , v104
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
	.byte		VOICE , 45
	.byte		PAN   , c_v+0
	.byte		N12   , Cn5 , v108
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
	.byte		N24   , Ds5 
	.byte	W24
mus_battle32_2_B1:
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		N48   , Cn4 , v100
	.byte	W48
	.byte		        As3 
	.byte	W48
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N72   , En4 
	.byte	W72
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		N60   , Cn4 
	.byte	W60
	.byte		PAN   , c_v+0
	.byte		N48   , As4 
	.byte	W48
	.byte		        An4 
	.byte	W48
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N72   , En4 
	.byte	W72
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N92   , Gn4 
	.byte	W96
	.byte		N48   , As4 
	.byte	W12
	.byte		PAN   , c_v+2
	.byte	W36
	.byte		N48   , An4 
	.byte	W48
	.byte		N24   , As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		N72   , En5 
	.byte	W72
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N92   , Cn5 
	.byte	W96
	.byte		VOICE , 56
	.byte		PAN   , c_v+1
	.byte		N48   , Cn4 , v104
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N36   , Dn4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N72   , En4 
	.byte	W36
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		N60   , Cn4 
	.byte	W24
	.byte	W03
	.byte		MOD   , 6
	.byte	W32
	.byte	W01
	.byte		        0
	.byte		N48   , As4 , v108
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , An4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N72   , En4 
	.byte	W36
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N56   , Gn4 
	.byte	W30
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 76*mus_battle32_mvl/mxv
	.byte	W06
	.byte		        71*mus_battle32_mvl/mxv
	.byte	W06
	.byte		        64*mus_battle32_mvl/mxv
	.byte	W03
	.byte		        49*mus_battle32_mvl/mxv
	.byte	W03
	.byte		        33*mus_battle32_mvl/mxv
	.byte	W03
	.byte		        17*mus_battle32_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOICE , 48
	.byte		PAN   , c_v+2
	.byte		N12   , Gn4 , v092
	.byte	W03
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte	W09
	.byte		N12   , Cn5 
	.byte	W24
	.byte		N48   , As4 
	.byte	W48
	.byte		        An4 
	.byte	W48
	.byte		N24   , As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		N72   , En5 
	.byte	W72
	.byte		N24   , Cn5 
	.byte	W24
	.byte		N92   , Gn5 
	.byte	W96
	.byte		VOICE , 1
	.byte		N36   , Cn3 , v108
	.byte	W36
	.byte		        As2 
	.byte	W36
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N36   , Dn3 
	.byte	W36
	.byte		        As2 
	.byte	W36
	.byte		N24   , Dn3 
	.byte	W24
	.byte		TIE   , Cn3 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		N72   , Cn4 , v100
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N96   , Cs4 
	.byte	W96
	.byte		        Ds4 
	.byte	W96
	.byte		TIE   , Fn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 48
	.byte		PAN   , c_v+2
	.byte		N96   , Cn3 
	.byte	W96
	.byte		N42   , As2 
	.byte	W42
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N48   , Dn3 
	.byte	W48
	.byte		N96   , Gn2 
	.byte	W96
	.byte		        Cn3 
	.byte	W96
	.byte		        Cs3 
	.byte	W96
	.byte		N48   , As2 
	.byte	W48
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , En3 
	.byte	W12
	.byte		N96   , Cn3 
	.byte	W96
	.byte		        En3 
	.byte	W96
	.byte	GOTO
	 .word	mus_battle32_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_battle32_3:
	.byte	KEYSH , mus_battle32_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Cn2 , v108
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		N12   , As1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
mus_battle32_3_000:
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
mus_battle32_3_001:
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
	 .word	mus_battle32_3_000
	.byte	PATT
	 .word	mus_battle32_3_001
	.byte	PATT
	 .word	mus_battle32_3_000
	.byte	PATT
	 .word	mus_battle32_3_001
	.byte	PATT
	 .word	mus_battle32_3_000
	.byte	PATT
	 .word	mus_battle32_3_001
mus_battle32_3_B1:
mus_battle32_3_002:
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
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
mus_battle32_3_003:
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
mus_battle32_3_004:
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
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_3_002
mus_battle32_3_005:
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
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_002
mus_battle32_3_006:
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
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte		N12   , Cn1 , v108
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_004
	.byte	PATT
	 .word	mus_battle32_3_002
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
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_005
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
mus_battle32_3_007:
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
mus_battle32_3_008:
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
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_007
	.byte	PATT
	 .word	mus_battle32_3_008
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_007
	.byte	PATT
	 .word	mus_battle32_3_008
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_003
	.byte	PATT
	 .word	mus_battle32_3_002
	.byte	PATT
	 .word	mus_battle32_3_006
	.byte	GOTO
	 .word	mus_battle32_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_battle32_4:
	.byte	KEYSH , mus_battle32_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 18
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		PAN   , c_v-48
	.byte	W12
	.byte		N06   , Cn6 , v052
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Cn6 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Cn6 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Cn2 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Cs2 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Cn3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		MOD   , 6
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
	.byte		MOD   , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 4
	.byte		PAN   , c_v-48
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v040
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
	.byte		N24   
	.byte	W24
mus_battle32_4_B1:
	.byte		VOICE , 84
	.byte		PAN   , c_v+0
	.byte		N12   , En4 , v040
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W24
	.byte	W60
	.byte		        Gn4 , v052
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N36   , En5 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Cn5 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W24
	.byte		N60   , Cn5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W36
mus_battle32_4_000:
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		N48   , As3 , v060
	.byte	W48
	.byte		        An3 
	.byte	W48
	.byte	PEND
mus_battle32_4_001:
	.byte		N24   , Gn3 , v060
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte	PEND
mus_battle32_4_002:
	.byte		N72   , En3 , v060
	.byte	W72
	.byte		N24   , Cn3 
	.byte	W24
	.byte	PEND
mus_battle32_4_003:
	.byte		N60   , Gn3 , v060
	.byte	W60
	.byte		VOICE , 6
	.byte		N12   , En3 , v072
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
	.byte		        As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v-47
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v-49
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		PAN   , c_v+51
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		VOICE , 84
	.byte		PAN   , c_v+0
	.byte		N12   , Cn5 , v040
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N36   , En5 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N36   , Cn5 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W24
	.byte		N60   , Cn5 
	.byte	W24
	.byte	W03
	.byte		MOD   , 6
	.byte	W32
	.byte	W01
	.byte	PATT
	 .word	mus_battle32_4_000
	.byte	PATT
	 .word	mus_battle32_4_001
	.byte	PATT
	 .word	mus_battle32_4_002
	.byte	PATT
	 .word	mus_battle32_4_003
	.byte		N12   , Fn2 , v072
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		PAN   , c_v-47
	.byte		N12   , An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-49
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+51
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 84
	.byte		N72   , Cn2 
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N96   , Cs2 
	.byte	W96
	.byte		        Ds2 
	.byte	W96
	.byte		TIE   , Cn2 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N96   , Cs2 
	.byte	W96
	.byte		        Ds2 
	.byte	W96
	.byte		TIE   , Cn2 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N96   , Cs2 
	.byte	W96
	.byte		        Ds2 
	.byte	W96
	.byte		TIE   , Fn2 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 86
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
mus_battle32_4_004:
	.byte		N12   , Fn2 , v072
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
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_4_004
	.byte	PATT
	 .word	mus_battle32_4_004
	.byte		VOICE , 6
	.byte		N12   , Gn3 , v060
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		VOICE , 7
	.byte		PAN   , c_v+0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
mus_battle32_4_005:
	.byte		PAN   , c_v+0
	.byte		N12   , Gn3 , v060
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
	.byte		VOICE , 6
	.byte		PAN   , c_v+0
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOICE , 7
	.byte		PAN   , c_v+0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-47
	.byte		N12   , En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PATT
	 .word	mus_battle32_4_005
	.byte	GOTO
	 .word	mus_battle32_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_battle32_5:
	.byte	KEYSH , mus_battle32_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 18
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte		PAN   , c_v+46
	.byte		BEND  , c_v-2
	.byte		N06   , Gn3 , v052
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v-47
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Gn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cs3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N42   , Cn4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Gn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cn5 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cs4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOICE , 5
	.byte		PAN   , c_v+48
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v040
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		        En3 
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		        Gn2 
	.byte	W24
	.byte		        Gn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
mus_battle32_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W36
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		N12   , En3 , v060
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
	.byte	W36
	.byte		VOICE , 82
	.byte		N12   
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
	.byte		VOICE , 80
	.byte		BEND  , c_v-2
	.byte		N09   , As3 , v072
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		VOICE , 5
	.byte		N09   , Cn2 , v060
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
mus_battle32_5_000:
	.byte		VOICE , 4
	.byte		N09   , Cn4 , v060
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte	PEND
mus_battle32_5_001:
	.byte		N09   , Cn4 , v060
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte	PEND
	.byte		VOICE , 5
	.byte		N09   , Cs2 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N32   
	.byte	W36
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte	PATT
	 .word	mus_battle32_5_000
	.byte	PATT
	 .word	mus_battle32_5_001
	.byte	GOTO
	 .word	mus_battle32_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_battle32_6:
	.byte	KEYSH , mus_battle32_key+0
	.byte		VOICE , 90
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte	W24
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 81
	.byte		N48   , Cn3 , v064
	.byte	W48
	.byte		        Cn2 
	.byte	W48
	.byte		        Gn2 
	.byte	W48
	.byte		        Cs2 
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte		        Cn2 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
	.byte		        Ds2 
	.byte	W48
mus_battle32_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_battle32_6_000:
	.byte		N48   , Fn4 , v064
	.byte	W48
	.byte		        En4 
	.byte	W48
	.byte	PEND
mus_battle32_6_001:
	.byte		N24   , Fn4 , v064
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte	PEND
	.byte		N72   , Cn5 
	.byte	W72
	.byte		N24   , An4 
	.byte	W24
	.byte		N96   , Gn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte	PATT
	 .word	mus_battle32_6_000
	.byte	PATT
	 .word	mus_battle32_6_001
	.byte		N72   , Cn5 , v064
	.byte	W72
	.byte		N24   , En4 
	.byte	W24
	.byte		N92   , Cn5 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N72   , Cn1 
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N96   , Cs1 
	.byte	W96
	.byte		        Ds1 
	.byte	W96
	.byte		TIE   , Cn1 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N96   , Cs1 
	.byte	W96
	.byte		        Ds1 
	.byte	W96
	.byte		        Cn1 
	.byte	W96
	.byte		N72   , Gn2 
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N96   , Gs2 
	.byte	W96
	.byte		        As2 
	.byte	W96
	.byte		TIE   , Fn3 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_battle32_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_battle32_7:
	.byte	KEYSH , mus_battle32_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W84
	.byte		N12   , Dn1 , v112
	.byte	W12
mus_battle32_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
mus_battle32_7_001:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_battle32_7_B1:
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_001
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_001
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_000
	.byte	PATT
	 .word	mus_battle32_7_001
	.byte	GOTO
	 .word	mus_battle32_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_battle32_8:
	.byte	KEYSH , mus_battle32_key+0
	.byte		VOICE , 47
	.byte		VOL   , 80*mus_battle32_mvl/mxv
	.byte		PAN   , c_v-10
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte		        Gn1 
	.byte	W12
	.byte	W12
	.byte		        Cn2 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		        Gn1 
	.byte	W24
mus_battle32_8_000:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_000
mus_battle32_8_B1:
mus_battle32_8_001:
	.byte		N12   , Cn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_000
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
	.byte	PATT
	 .word	mus_battle32_8_001
mus_battle32_8_002:
	.byte		N12   , Cn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle32_8_002
	.byte	PATT
	 .word	mus_battle32_8_002
	.byte	PATT
	 .word	mus_battle32_8_002
	.byte	PATT
	 .word	mus_battle32_8_002
	.byte	PATT
	 .word	mus_battle32_8_002
	.byte	W24
	.byte		N12   , Cn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	GOTO
	 .word	mus_battle32_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_battle32:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_battle32_pri	@ Priority
	.byte	mus_battle32_rev	@ Reverb.

	.word	mus_battle32_grp

	.word	mus_battle32_1
	.word	mus_battle32_2
	.word	mus_battle32_3
	.word	mus_battle32_4
	.word	mus_battle32_5
	.word	mus_battle32_6
	.word	mus_battle32_7
	.word	mus_battle32_8

	.end
