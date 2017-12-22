	.include "MPlayDef.s"

	.equ	se_rg_shop_grp, voicegroup_86A0154
	.equ	se_rg_shop_pri, 5
	.equ	se_rg_shop_rev, reverb_set+50
	.equ	se_rg_shop_mvl, 127
	.equ	se_rg_shop_key, 0
	.equ	se_rg_shop_tbs, 1
	.equ	se_rg_shop_exg, 0
	.equ	se_rg_shop_cmp, 1

	.section .rodata
	.global	se_rg_shop
	.align	2

@********************** Track  1 **********************@

se_rg_shop_1:
	.byte	KEYSH , se_rg_shop_key+0
	.byte	TEMPO , 124*se_rg_shop_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 80*se_rg_shop_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N30   , Cn3 , v120
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_rg_shop:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_shop_pri	@ Priority
	.byte	se_rg_shop_rev	@ Reverb.

	.word	se_rg_shop_grp

	.word	se_rg_shop_1

	.end
