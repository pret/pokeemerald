	.include "MPlayDef.s"

	.equ	se_pc_on_grp, voicegroup_869D0F4
	.equ	se_pc_on_pri, 5
	.equ	se_pc_on_rev, reverb_set+50
	.equ	se_pc_on_mvl, 127
	.equ	se_pc_on_key, 0
	.equ	se_pc_on_tbs, 1
	.equ	se_pc_on_exg, 0
	.equ	se_pc_on_cmp, 1

	.section .rodata
	.global	se_pc_on
	.align	2

@********************** Track  1 **********************@

se_pc_on_1:
	.byte	KEYSH , se_pc_on_key+0
	.byte	TEMPO , 144*se_pc_on_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_pc_on_mvl/mxv
	.byte		BEND  , c_v-11
	.byte		N12   , Cn6 , v112
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N04   , Cn5 , v080
	.byte	W03
	.byte	W01
	.byte		        Cn4 
	.byte	W02
	.byte	W02
	.byte		        Gn4 
	.byte	W01
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte	W02
	.byte		        Cn4 
	.byte	W01
	.byte	W03
	.byte		        Cn6 , v100
	.byte	W03
	.byte	W01
	.byte		        Cn4 , v080
	.byte	W02
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_pc_on:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pc_on_pri	@ Priority
	.byte	se_pc_on_rev	@ Reverb.

	.word	se_pc_on_grp

	.word	se_pc_on_1

	.end
