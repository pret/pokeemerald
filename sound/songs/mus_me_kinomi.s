	.include "MPlayDef.s"

	.equ	mus_me_kinomi_grp, voicegroup_8677B28
	.equ	mus_me_kinomi_pri, 5
	.equ	mus_me_kinomi_rev, reverb_set+50
	.equ	mus_me_kinomi_mvl, 127
	.equ	mus_me_kinomi_key, 0
	.equ	mus_me_kinomi_tbs, 1
	.equ	mus_me_kinomi_exg, 0
	.equ	mus_me_kinomi_cmp, 1

	.section .rodata
	.global	mus_me_kinomi
	.align	2

@********************** Track  1 **********************@

mus_me_kinomi_1:
	.byte	KEYSH , mus_me_kinomi_key+0
	.byte	W12
	.byte	TEMPO , 140*mus_me_kinomi_tbs/2
	.byte		VOICE , 13
	.byte		PAN   , c_v-10
	.byte		VOL   , 90*mus_me_kinomi_mvl/mxv
	.byte		N04   , Fn4 , v092
	.byte	W04
	.byte		        Fn4 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Cn4 , v092
	.byte	W04
	.byte		        Cn4 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Cn5 , v092
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cn5 
	.byte	W08
	.byte		        Fn5 
	.byte	W04
	.byte		        Fn5 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W36
	.byte	FINE

@********************** Track  2 **********************@

mus_me_kinomi_2:
	.byte	KEYSH , mus_me_kinomi_key+0
	.byte	W12
	.byte		VOICE , 13
	.byte		PAN   , c_v+31
	.byte		VOL   , 90*mus_me_kinomi_mvl/mxv
	.byte	W24
	.byte		N04   , Gn4 , v092
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		N16   , An4 
	.byte	W48
	.byte	FINE

@********************** Track  3 **********************@

mus_me_kinomi_3:
	.byte	KEYSH , mus_me_kinomi_key+0
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 90*mus_me_kinomi_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   , Fn3 , v080
	.byte	W24
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W48
	.byte	FINE

@********************** Track  4 **********************@

mus_me_kinomi_4:
	.byte	KEYSH , mus_me_kinomi_key+0
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 90*mus_me_kinomi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , An2 , v080
	.byte	W24
	.byte		N04   , As2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N16   , An2 
	.byte	W48
	.byte	FINE

@********************** Track  5 **********************@

mus_me_kinomi_5:
	.byte	KEYSH , mus_me_kinomi_key+0
	.byte	W12
	.byte		VOICE , 100
	.byte		VOL   , 90*mus_me_kinomi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , Cn5 , v060
	.byte	W08
	.byte		PAN   , c_v-49
	.byte		N04   , Cn5 , v020
	.byte	W16
	.byte		VOICE , 101
	.byte		PAN   , c_v-1
	.byte		N04   , As3 , v060
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		PAN   , c_v+50
	.byte		N04   , Gn3 , v020
	.byte	W08
	.byte		VOICE , 100
	.byte		PAN   , c_v+0
	.byte		N04   , An3 , v060
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , An3 , v020
	.byte	W16
	.byte		VOICE , 101
	.byte		PAN   , c_v+0
	.byte		N04   , An3 , v060
	.byte	W08
	.byte		PAN   , c_v+50
	.byte		N04   , An3 , v020
	.byte	W16
	.byte	FINE

@******************************************************@
	.align	2

mus_me_kinomi:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_kinomi_pri	@ Priority
	.byte	mus_me_kinomi_rev	@ Reverb.

	.word	mus_me_kinomi_grp

	.word	mus_me_kinomi_1
	.word	mus_me_kinomi_2
	.word	mus_me_kinomi_3
	.word	mus_me_kinomi_4
	.word	mus_me_kinomi_5

	.end
