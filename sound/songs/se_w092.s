	.include "MPlayDef.s"

	.equ	se_w092_grp, voicegroup128
	.equ	se_w092_pri, 4
	.equ	se_w092_rev, reverb_set+50
	.equ	se_w092_mvl, 127
	.equ	se_w092_key, 0
	.equ	se_w092_tbs, 1
	.equ	se_w092_exg, 0
	.equ	se_w092_cmp, 1

	.section .rodata
	.global	se_w092
	.align	2

@********************** Track  1 **********************@

se_w092_1:
	.byte	KEYSH , se_w092_key+0
	.byte	TEMPO , 150*se_w092_tbs/2
	.byte		VOICE , 31
	.byte		VOL   , 110*se_w092_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Dn2 , v127
	.byte	W01
	.byte		BEND  , c_v+32
	.byte	W01
	.byte		VOICE , 23
	.byte		BEND  , c_v+0
	.byte		N02   , Gn1 , v112
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Cn2 
	.byte	W02
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		N01   
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		N01   , Cn3 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v-16
	.byte		N01   , Dn2 
	.byte	W02
	.byte		VOICE , 23
	.byte		PAN   , c_v+0
	.byte		N01   , Cn2 
	.byte	W01
	.byte		VOICE , 31
	.byte		PAN   , c_v+16
	.byte		N01   , Dn2 , v096
	.byte	W01
	.byte		VOICE , 23
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+16
	.byte		N01   , Cn3 
	.byte	W02
	.byte		PAN   , c_v+8
	.byte		N01   , Cn2 
	.byte	W08
	.byte	FINE

@******************************************************@
	.align	2

se_w092:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w092_pri	@ Priority
	.byte	se_w092_rev	@ Reverb.

	.word	se_w092_grp

	.word	se_w092_1

	.end
