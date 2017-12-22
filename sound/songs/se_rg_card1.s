	.include "MPlayDef.s"

	.equ	se_rg_card1_grp, voicegroup_86A0154
	.equ	se_rg_card1_pri, 5
	.equ	se_rg_card1_rev, reverb_set+50
	.equ	se_rg_card1_mvl, 127
	.equ	se_rg_card1_key, 0
	.equ	se_rg_card1_tbs, 1
	.equ	se_rg_card1_exg, 0
	.equ	se_rg_card1_cmp, 1

	.section .rodata
	.global	se_rg_card1
	.align	2

@********************** Track  1 **********************@

se_rg_card1_1:
	.byte	KEYSH , se_rg_card1_key+0
	.byte	TEMPO , 182*se_rg_card1_tbs/2
	.byte		VOICE , 125
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*se_rg_card1_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N01   , Cn4 , v127
	.byte	W03
	.byte		VOICE , 124
	.byte		N01   , Cn5 , v064
	.byte	W21
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_rg_card1:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_card1_pri	@ Priority
	.byte	se_rg_card1_rev	@ Reverb.

	.word	se_rg_card1_grp

	.word	se_rg_card1_1

	.end
