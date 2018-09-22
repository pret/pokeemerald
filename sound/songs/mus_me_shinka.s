	.include "MPlayDef.s"

	.equ	mus_me_shinka_grp, voicegroup026
	.equ	mus_me_shinka_pri, 0
	.equ	mus_me_shinka_rev, reverb_set+50
	.equ	mus_me_shinka_mvl, 127
	.equ	mus_me_shinka_key, 0
	.equ	mus_me_shinka_tbs, 1
	.equ	mus_me_shinka_exg, 0
	.equ	mus_me_shinka_cmp, 1

	.section .rodata
	.global	mus_me_shinka
	.align	2

@********************** Track  1 **********************@

mus_me_shinka_1:
	.byte	KEYSH , mus_me_shinka_key+0
	.byte	TEMPO , 120*mus_me_shinka_tbs/2
	.byte		VOICE , 47
	.byte		VOL   , 80*mus_me_shinka_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N24   , Dn2 , v127
	.byte	W48
	.byte	FINE

@********************** Track  2 **********************@

mus_me_shinka_2:
	.byte	KEYSH , mus_me_shinka_key+0
	.byte		VOICE , 80
	.byte		VOL   , 80*mus_me_shinka_mvl/mxv
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v080
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W30
	.byte	FINE

@********************** Track  3 **********************@

mus_me_shinka_3:
	.byte	KEYSH , mus_me_shinka_key+0
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*mus_me_shinka_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W06
	.byte		N06   , Gn4 , v032
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W24
	.byte	FINE

@********************** Track  4 **********************@

mus_me_shinka_4:
	.byte	KEYSH , mus_me_shinka_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_me_shinka_mvl/mxv
	.byte		PAN   , c_v+23
	.byte		N48   , Bn2 , v100
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

mus_me_shinka:
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_me_shinka_pri	@ Priority
	.byte	mus_me_shinka_rev	@ Reverb.

	.word	mus_me_shinka_grp

	.word	mus_me_shinka_1
	.word	mus_me_shinka_2
	.word	mus_me_shinka_3
	.word	mus_me_shinka_4

	.end
