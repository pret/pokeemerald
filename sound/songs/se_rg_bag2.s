	.include "MPlayDef.s"

	.equ	se_rg_bag2_grp, voicegroup_86A0154
	.equ	se_rg_bag2_pri, 5
	.equ	se_rg_bag2_rev, reverb_set+50
	.equ	se_rg_bag2_mvl, 127
	.equ	se_rg_bag2_key, 0
	.equ	se_rg_bag2_tbs, 1
	.equ	se_rg_bag2_exg, 0
	.equ	se_rg_bag2_cmp, 1

	.section .rodata
	.global	se_rg_bag2
	.align	2

@********************** Track  1 **********************@

se_rg_bag2_1:
	.byte	KEYSH , se_rg_bag2_key+0
	.byte	TEMPO , 422*se_rg_bag2_tbs/2
	.byte		VOICE , 80
	.byte		VOL   , 64*se_rg_bag2_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Dn4 , v084
	.byte	W02
	.byte		BEND  , c_v+17
	.byte		N03   , Fs4 , v080
	.byte	W01
	.byte		BEND  , c_v-40
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_rg_bag2_2:
	.byte	KEYSH , se_rg_bag2_key+0
	.byte		VOICE , 2
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 127*se_rg_bag2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N04   , En3 , v127
	.byte	W03
	.byte	W01
	.byte		VOICE , 2
	.byte		N02   , Bn3 
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_rg_bag2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_bag2_pri	@ Priority
	.byte	se_rg_bag2_rev	@ Reverb.

	.word	se_rg_bag2_grp

	.word	se_rg_bag2_1
	.word	se_rg_bag2_2

	.end
