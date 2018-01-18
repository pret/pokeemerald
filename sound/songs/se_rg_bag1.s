	.include "MPlayDef.s"

	.equ	se_rg_bag1_grp, voicegroup_86A0154
	.equ	se_rg_bag1_pri, 5
	.equ	se_rg_bag1_rev, reverb_set+50
	.equ	se_rg_bag1_mvl, 127
	.equ	se_rg_bag1_key, 0
	.equ	se_rg_bag1_tbs, 1
	.equ	se_rg_bag1_exg, 0
	.equ	se_rg_bag1_cmp, 1

	.section .rodata
	.global	se_rg_bag1
	.align	2

@********************** Track  1 **********************@

se_rg_bag1_1:
	.byte	KEYSH , se_rg_bag1_key+0
	.byte	TEMPO , 310*se_rg_bag1_tbs/2
	.byte		VOICE , 10
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 127*se_rg_bag1_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N01   , Cs4 , v072
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_rg_bag1_2:
	.byte		VOL   , 127*se_rg_bag1_mvl/mxv
	.byte	KEYSH , se_rg_bag1_key+0
	.byte		VOICE , 124
	.byte		N01   , Cs5 , v072
	.byte	W01
	.byte		        Ds5 , v104
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_rg_bag1:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_bag1_pri	@ Priority
	.byte	se_rg_bag1_rev	@ Reverb.

	.word	se_rg_bag1_grp

	.word	se_rg_bag1_1
	.word	se_rg_bag1_2

	.end
