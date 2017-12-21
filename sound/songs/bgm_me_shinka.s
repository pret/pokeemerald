	.include "MPlayDef.s"

	.equ	bgm_me_shinka_grp, voicegroup_867B3A4
	.equ	bgm_me_shinka_pri, 0
	.equ	bgm_me_shinka_rev, reverb_set+50
	.equ	bgm_me_shinka_mvl, 127
	.equ	bgm_me_shinka_key, 0
	.equ	bgm_me_shinka_tbs, 1
	.equ	bgm_me_shinka_exg, 0
	.equ	bgm_me_shinka_cmp, 1

	.section .rodata
	.global	bgm_me_shinka
	.align	2

@********************** Track  1 **********************@

bgm_me_shinka_1:
	.byte	KEYSH , bgm_me_shinka_key+0
	.byte	TEMPO , 120*bgm_me_shinka_tbs/2
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_me_shinka_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N24   , Dn2 , v127
	.byte	W48
	.byte	FINE

@********************** Track  2 **********************@

bgm_me_shinka_2:
	.byte	KEYSH , bgm_me_shinka_key+0
	.byte		VOICE , 80
	.byte		VOL   , 80*bgm_me_shinka_mvl/mxv
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

bgm_me_shinka_3:
	.byte	KEYSH , bgm_me_shinka_key+0
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_me_shinka_mvl/mxv
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

bgm_me_shinka_4:
	.byte	KEYSH , bgm_me_shinka_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_me_shinka_mvl/mxv
	.byte		PAN   , c_v+23
	.byte		N48   , Bn2 , v100
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

bgm_me_shinka:
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_me_shinka_pri	@ Priority
	.byte	bgm_me_shinka_rev	@ Reverb.

	.word	bgm_me_shinka_grp

	.word	bgm_me_shinka_1
	.word	bgm_me_shinka_2
	.word	bgm_me_shinka_3
	.word	bgm_me_shinka_4

	.end
