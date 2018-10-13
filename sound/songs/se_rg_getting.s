	.include "MPlayDef.s"

	.equ	se_rg_getting_grp, voicegroup129
	.equ	se_rg_getting_pri, 5
	.equ	se_rg_getting_rev, reverb_set+50
	.equ	se_rg_getting_mvl, 127
	.equ	se_rg_getting_key, 0
	.equ	se_rg_getting_tbs, 1
	.equ	se_rg_getting_exg, 0
	.equ	se_rg_getting_cmp, 1

	.section .rodata
	.global	se_rg_getting
	.align	2

@********************** Track  1 **********************@

se_rg_getting_1:
	.byte	KEYSH , se_rg_getting_key+0
	.byte	TEMPO , 310*se_rg_getting_tbs/2
	.byte		VOICE , 3
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_rg_getting_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Bn3 , v120
	.byte	W03
	.byte	W03
	.byte	W02
	.byte		        En4 , v127
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_rg_getting_2:
	.byte	KEYSH , se_rg_getting_key+0
	.byte		VOICE , 126
	.byte		VOL   , 100*se_rg_getting_mvl/mxv
	.byte	W03
	.byte	W01
	.byte		N01   , Cn2 , v120
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_rg_getting:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_getting_pri	@ Priority
	.byte	se_rg_getting_rev	@ Reverb.

	.word	se_rg_getting_grp

	.word	se_rg_getting_1
	.word	se_rg_getting_2

	.end
