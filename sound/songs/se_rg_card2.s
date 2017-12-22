	.include "MPlayDef.s"

	.equ	se_rg_card2_grp, voicegroup_86A0154
	.equ	se_rg_card2_pri, 5
	.equ	se_rg_card2_rev, reverb_set+50
	.equ	se_rg_card2_mvl, 127
	.equ	se_rg_card2_key, 0
	.equ	se_rg_card2_tbs, 1
	.equ	se_rg_card2_exg, 0
	.equ	se_rg_card2_cmp, 1

	.section .rodata
	.global	se_rg_card2
	.align	2

@********************** Track  1 **********************@

se_rg_card2_1:
	.byte	KEYSH , se_rg_card2_key+0
	.byte	TEMPO , 182*se_rg_card2_tbs/2
	.byte		VOICE , 125
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 16*se_rg_card2_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N24   , Gn5 , v088
	.byte	W03
	.byte		VOL   , 32*se_rg_card2_mvl/mxv
	.byte	W03
	.byte		        48*se_rg_card2_mvl/mxv
	.byte	W03
	.byte		        64*se_rg_card2_mvl/mxv
	.byte	W03
	.byte		        80*se_rg_card2_mvl/mxv
	.byte	W03
	.byte		        96*se_rg_card2_mvl/mxv
	.byte	W03
	.byte		        112*se_rg_card2_mvl/mxv
	.byte	W03
	.byte		        127*se_rg_card2_mvl/mxv
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_rg_card2:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_card2_pri	@ Priority
	.byte	se_rg_card2_rev	@ Reverb.

	.word	se_rg_card2_grp

	.word	se_rg_card2_1

	.end
